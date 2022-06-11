#include <arch/arm/mmu.h>
#include <debug.h>
#include <dev/aee_platform_debug.h>
#include <libfdt.h>
#ifdef MTK_SMC_ID_MGMT
#include <mtk_secure_api.h>
#endif
#include <arch/ops.h>
#include <platform/boot_mode.h>
#include <platform/mt_typedefs.h>
#include <platform/plat_atf_dbg_info.h>
#include <sys/types.h>

#ifdef MBLOCK_LIB_SUPPORT
#include <mblock.h>
#endif

/* default support ATF, define an empty function in ARMv7 chip family */
#pragma weak atf_log_init

#ifndef MTK_SMC_ID_MGMT
#define MTK_SIP_LK_DUMP_ATF_LOG_INFO_AARCH32	0x8200010A
#endif

#define ATF_CRASH_MAGIC_NO			0xdead1abf
#define ATF_LAST_LOG_MAGIC_NO			0x41544641
#define ATF_DUMP_DONE_MAGIC_NO			0xd07ed07e
#define ATF_SMC_UNK				0xffffffff


/* each 8 bytes, support 16 types */
#define ATF_OP_ID_GET_FOOTPRINT_BUF_INFO  (0x0)
#define MAX_FOOTPRINT_TYPE_STRING_SIZE 8
#define MAX_SUPPORTED_FOOTPRINT_TYPE 16
#define MAX_CORE_COUNT 32
#define FOOTPRINT_MAGIC_NUM 0xCA7FF007

#define ATF_RET_SUCCESS 0
#define ATF_RET_UNKNOWN -1

struct footprint_header {
	uint32_t size;
	uint32_t magic;
};

struct footprint_package{
	struct footprint_header header;
	/* 4 bytes alignment */
	uint8_t name_string[MAX_FOOTPRINT_TYPE_STRING_SIZE];	/* 8 */
	uint32_t footprint[MAX_CORE_COUNT];				/* 16*/
};

#define INFO_LOG(fmt, args...) do {dprintf(INFO, fmt, ##args);} while (0)
#define ALWAYS_LOG(fmt, args...) do {dprintf(ALWAYS, fmt, ##args);} while (0)

extern BOOT_ARGUMENT *g_boot_arg;

static u64 atf_ramdump_addr;
static u32 atf_ramdump_size;

static uint32_t atf_log_buf_addr;
static uint32_t atf_log_buf_size;
static uint32_t atf_crash_flag_addr;

static uintptr_t atf_footprint_addr;
static uint32_t atf_footprint_buf_size;

static void get_atf_ramdump_memory(void)
{
#if (defined(MTK_SMC_ID_MGMT) && !defined(MTK_DIS_ATF_RAM_DUMP))
	uint32_t address_hi, address_lo;

		address_hi = mt_secure_call_ret3(MTK_SIP_RAM_DUMP_ADDR, 0, 0, 0, 0,
			&address_lo, &atf_ramdump_size);

		ALWAYS_LOG("atf ram dump address hi:0x%x, adress lo:0x%x, size: %x\n",
					address_hi, address_lo, atf_ramdump_size);
		atf_ramdump_addr = (((u64)address_hi & 0xFFFFFFFF) << 32) |
						((u64)address_lo & 0xFFFFFFFF);

		ALWAYS_LOG("atf ram dump address:0x%llx, size: %x\n",
					atf_ramdump_addr, atf_ramdump_size);

#else
	atf_ramdump_size = 0;
	atf_ramdump_addr = 0;
	ALWAYS_LOG("Do not support atf-ramdump-memory, atf_ramdump_addr=0x%llx!\n",
					atf_ramdump_addr);
#endif
}

static uint32_t save_atf_log(u64 offset, int *len, CALLBACK dev_write)
{
	uint32_t datasize = 0;
#ifdef MTK_3LEVEL_PAGETABLE
	/* ATF log is located in DRAM, we must allocate it first */
	arch_mmu_map(ROUNDDOWN((uint64_t)atf_log_buf_addr, PAGE_SIZE), ROUNDDOWN((uint32_t)atf_log_buf_addr, PAGE_SIZE),
				MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, ROUNDUP(atf_log_buf_size, PAGE_SIZE));
#endif
	*len = atf_log_buf_size;
	datasize = dev_write((void *)atf_log_buf_addr, *len);
	/* Clear ATF crash flag */
	*(uint32_t *)atf_crash_flag_addr = ATF_DUMP_DONE_MAGIC_NO;
	arch_clean_cache_range((addr_t)atf_crash_flag_addr, sizeof(uint32_t));

	dprintf(INFO, "ATF: dev_write:%u, atf_log_buf_addr:0x%x, atf_log_buf_size:%u, crash_flag:0x%x\n", datasize, atf_log_buf_addr, atf_log_buf_size, *(uint32_t *)atf_crash_flag_addr);
	return datasize;
}

static uint32_t save_atf_footprint(u64 offset, int *len, CALLBACK dev_write)
{
	uint32_t datasize = 0;
	uint32_t i = 0;
	uint64_t footprint_map_addr;
	uint64_t footprint_map_size;
	uint64_t temp_offset;
	uint32_t local_strlen = 0;
	int n = 0;

	char *ptr_footprint_buf_start = 0;
	/* for pointer of footprint buffer address */
	char *ptr_footprint_buf_pointer = 0;
	struct footprint_package *ptr_fp_pkg, *ptr_next_fp_pkg;

	/* allocate temp buffer to parcking footprint data */
	ptr_footprint_buf_start = malloc(atf_footprint_buf_size);

	if (!ptr_footprint_buf_start) {
		dprintf(CRITICAL, "%s : malloc failure for size 0x%x\n", __func__, atf_footprint_buf_size);
		return datasize;
	}

	if (atf_footprint_addr > 0) {
		ptr_fp_pkg = (struct footprint_package *)(intptr_t)atf_footprint_addr;

		/* round down */
		temp_offset = (uint64_t)(atf_footprint_addr & (PAGE_SIZE -1));
		if (temp_offset > 0)
			footprint_map_addr = (atf_footprint_addr - temp_offset); /* round down */
		else
			footprint_map_addr = atf_footprint_addr;

		/* round up */
		temp_offset = (atf_footprint_buf_size & (PAGE_SIZE -1));
		if (temp_offset > 0)
			footprint_map_size = (atf_footprint_buf_size - temp_offset) + PAGE_SIZE;
		else
			footprint_map_size = atf_footprint_buf_size;

#ifdef MTK_3LEVEL_PAGETABLE
		/* ATF log is located in DRAM, we must allocate it first */
		arch_mmu_map(footprint_map_addr, footprint_map_addr,
			MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
			footprint_map_size);
#endif
		/* clean whole buffer */
		memset((void *)ptr_footprint_buf_start,
				0x0,
				atf_footprint_buf_size);

		/* traverse footprint_package*/
		ptr_footprint_buf_pointer = ptr_footprint_buf_start;
		while (ptr_fp_pkg->header.magic == FOOTPRINT_MAGIC_NUM) {
			/* cast to void * for byte count */
			ptr_next_fp_pkg = (struct footprint_package *)
				((void *)ptr_fp_pkg + ptr_fp_pkg->header.size);

			/* format the value to buffer */
			local_strlen = strlen((char *)&ptr_fp_pkg->name_string[0]);
			if (local_strlen > 0 &&
				local_strlen < MAX_FOOTPRINT_TYPE_STRING_SIZE) {
				n = sprintf(ptr_footprint_buf_pointer,	"%s:",
						&ptr_fp_pkg->name_string[0]);
				if (n < 0) {
					dprintf(CRITICAL, "ATF: sprintf unknown ERROR.\n");
				}
				/* string and = */
				ptr_footprint_buf_pointer += strlen(ptr_footprint_buf_pointer);
				/* traverse footprint value*/
				i = 0;
				while ((uint32_t)&ptr_fp_pkg->footprint[i] < (uint32_t)ptr_next_fp_pkg) {
					/* print comma */
					if ((uint32_t)&ptr_fp_pkg->footprint[i+1] < (uint32_t)ptr_next_fp_pkg) {
						n = sprintf(ptr_footprint_buf_pointer, "[%d]=0x%8x,", i,
								ptr_fp_pkg->footprint[i]);
						if (n < 0) {
							dprintf(CRITICAL, "ATF: sprintf unknown ERROR.\n");
						}
					} else {
						n = sprintf(ptr_footprint_buf_pointer, "[%d]=0x%8x\n", i,
								ptr_fp_pkg->footprint[i]);
						if (n < 0) {
							dprintf(CRITICAL, "ATF: sprintf unknown ERROR.\n");
						}
					}
					/* int and ,*/
					ptr_footprint_buf_pointer += strlen(ptr_footprint_buf_pointer);
					i++;
				}
			} /* if (0< local_strlen < MAX_FOOTPRINT_TYPE_STRING_SIZE) */

			/* point to next footprint_package*/
			ptr_fp_pkg = ptr_next_fp_pkg;
		} /* while (ptr_fp_pkg->header.magic == FOOTPRINT_MAGIC_NUM) */

		/* flush and invalidate memory */
		arch_sync_cache_range((addr_t)ptr_footprint_buf_start, atf_footprint_buf_size);

		/* scratch whole memory and write it into db file */
		*len = atf_footprint_buf_size;
		datasize = dev_write((void *)ptr_footprint_buf_start, *len);
		dprintf(CRITICAL, "ATF: footprint dev_write:%u\n", datasize);
	} /* End of if (atf_footprint_addr > 0) { */

	/* free memory */
	free(ptr_footprint_buf_start);

	return datasize;
}

static uint32_t save_atf_rdump(u64 offset, int *len, CALLBACK dev_write)
{
	uint32_t datasize = 0;
	u64 local_atf_ramdump_addr;
	u64 local_atf_ramdump_size;

	local_atf_ramdump_addr = atf_ramdump_addr;
	local_atf_ramdump_size = atf_ramdump_size;
#ifdef MTK_3LEVEL_PAGETABLE
	/* ATF log is located in DRAM, we must allocate it first */
	arch_mmu_map(ROUNDDOWN((uint64_t)local_atf_ramdump_addr, PAGE_SIZE),
				ROUNDDOWN((uint32_t)local_atf_ramdump_addr, PAGE_SIZE),
				MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
				ROUNDUP(local_atf_ramdump_size, PAGE_SIZE));
#endif
	*len = local_atf_ramdump_size;
	datasize = dev_write((void *)(uint32_t)local_atf_ramdump_addr, *len);

	dprintf(CRITICAL, "ATF: dev_write:%u, local_atf_ramdump_addr:0x%llx, local_atf_ramdump_size:0x%llx\n",
			datasize, local_atf_ramdump_addr, local_atf_ramdump_size);

	return datasize;
}

void atf_log_init(void)
{
	uint32_t smc_id = 0;
	uint32_t atf_footprint_hi_addr = 0;
	uint32_t atf_footprint_low_addr = 0;

	plat_atf_log_get = NULL;
	plat_atf_crash_get = NULL;
	plat_atf_rdump_get = save_atf_rdump;
	plat_atf_footprint_log_get = NULL;//save_atf_footprint;

	/* reserve ramdump memory and pass to ATF*/
	get_atf_ramdump_memory();

#ifdef MTK_SMC_ID_MGMT
	smc_id = MTK_SIP_LK_DUMP_ATF_LOG_INFO;
	atf_log_buf_addr = mt_secure_call_ret3(smc_id, 0, 0, 0, 0,
		&atf_log_buf_size, &atf_crash_flag_addr);

	smc_id = MTK_SIP_BL_ATF_CONTROL_AARCH32;
	atf_footprint_hi_addr = mt_secure_call_ret3(smc_id, 0, 0, 0, 0,
		&atf_footprint_low_addr,
		&atf_footprint_buf_size);

	/* atf_footprint_hi_addr may return -1  */
	if (atf_footprint_hi_addr == ATF_SMC_UNK) {
		dprintf(CRITICAL, "atf_footprint_hi_addr=0x%x(ATF_SMC_UNK)\n",
			atf_footprint_hi_addr);
		atf_footprint_addr = 0;
		atf_footprint_buf_size = 0;
	} else {	/* Get footprint addr */
		atf_footprint_addr = (uintptr_t)atf_footprint_low_addr;
	}
#else
	smc_id = MTK_SIP_LK_DUMP_ATF_LOG_INFO_AARCH32;
	__asm__ volatile("mov r0, %[smcid]\n"
			"smc #0x0\n"
			"mov %[addr], r0\n"
			"mov %[size], r1\n"
			"mov %[type], r2\n"
			:[addr]"=r"(atf_log_buf_addr), [size]"=r"(atf_log_buf_size),
			[type]"=r"(atf_crash_flag_addr):[smcid]"r"(smc_id):"cc",
			"r0", "r1" ,"r2", "r3");
	atf_footprint_addr = 0;
	atf_footprint_buf_size = 0;
#endif

	if(atf_log_buf_addr == ATF_SMC_UNK) {
		dprintf(CRITICAL, "LK Dump: atf_log_init not supported\n");
	} else {
		plat_atf_rdump_get = save_atf_rdump;

#ifdef MTK_3LEVEL_PAGETABLE
		arch_mmu_map(ROUNDDOWN((uint64_t)atf_crash_flag_addr, PAGE_SIZE),
					ROUNDDOWN((uint32_t)atf_crash_flag_addr, PAGE_SIZE),
					MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
					PAGE_SIZE);
#endif
		/* backward compatible for legacy chips */
		if (atf_footprint_addr == 0)
			plat_atf_footprint_log_get = NULL;
		else
			plat_atf_footprint_log_get = save_atf_footprint;

		if(ATF_CRASH_MAGIC_NO == *(uint32_t *)atf_crash_flag_addr){
			dprintf(CRITICAL, "ATF: CRASH BUFF\n");
			plat_atf_crash_get = save_atf_log;

		} else if(ATF_LAST_LOG_MAGIC_NO == *(uint32_t *)atf_crash_flag_addr){
			dprintf(CRITICAL, "ATF: LAST BUFF\n");
			plat_atf_log_get = save_atf_log;
		} else {
			dprintf(CRITICAL, "ATF: RAW BUFF\n");
			plat_atf_raw_log_get = save_atf_log;
			/* if raw data, do not dump footprint */
			plat_atf_footprint_log_get = NULL;
		}
		dprintf(CRITICAL, "atf_log_buf_addr:0x%x, atf_log_buf_size:%u, atf_crash_flag addr:0x%x, atf_log_type:0x%x\n",
				atf_log_buf_addr, atf_log_buf_size, atf_crash_flag_addr,
				*(uint32_t *)atf_crash_flag_addr);
		dprintf(CRITICAL, "plat_atf_log_get:%p, plat_atf_crash_get:%p\n",
				plat_atf_log_get, plat_atf_crash_get);
	}
}

