/*
 * Copyright (c) 2015-2020 MICROTRUST Incorporated
 * All rights reserved
 *
 * This file and software is confidential and proprietary to MICROTRUST Inc.
 * Unauthorized copying of this file and software is strictly prohibited.
 * You MUST NOT disclose this file and software unless you get a license
 * agreement from MICROTRUST Incorporated.
 */

#include <arch/arm/mmu.h>
#include <debug.h>
#include <dev/aee_platform_debug.h>
#include <libfdt.h>
#ifdef MTK_SMC_ID_MGMT
#include <mtk_secure_api.h>
#endif
#include <platform/boot_mode.h>
#include <platform/mt_typedefs.h>
#include <plat_teei_dbg_info.h>
#include <sys/types.h>

#ifdef MICROTRUST_TEE_DUMP_SUPPORT
static int get_teei_info(u64 *addr, u32 *size)
{
	u64 buf_addr = 0;
	u32 buf_size = 0;
	u32 ret = 0;
	uint32_t smc_id = ARCH32_TEEI_LOG_BUF_INFO;
	if ((addr == NULL) || (size == NULL)) {
		return -1;
	}
#ifdef MTK_SMC_ID_MGMT
	ret = mt_secure_call_ret3(smc_id, 0, 0, 0, 0, &buf_addr, &buf_size);
#else
	__asm__ volatile("mov r0, %[smcid]\n"
			"smc #0x0\n"
			"mov %[ret], r0\n"
			"mov %[addr], r1\n"
			"mov %[size], r2\n"
			:[ret]"=r"(ret), [addr]"=r"(buf_addr),
			[size]"=r"(buf_size):[smcid]"r"(smc_id):"cc",
			"r0", "r1", "r2", "r3");
#endif

	/*dprintf(INFO, "[microtrust][%s][%d] TEE: buffer addr:%llx,
	 * tee_log_buf_size:%x\n", __func__, __LINE__,  buf_addr, buf_size);*/
	*addr = buf_addr;
	*size = buf_size;
	return ret;
}

static uint32_t save_teei_log(u64 offset, int *len, CALLBACK dev_write)
{
	uint32_t datasize = 0;
	uint64_t teei_log_buf_addr = 0;
	uint32_t teei_log_buf_size = 0;
	int ret;

	ret = get_teei_info(&teei_log_buf_addr, &teei_log_buf_size);
	if ((ret != 0) || (teei_log_buf_addr == 0))
		return 0;
#ifdef MTK_3LEVEL_PAGETABLE
	arch_mmu_map(ROUNDDOWN((uint64_t)teei_log_buf_addr, PAGE_SIZE),
		     ROUNDDOWN((uint32_t)teei_log_buf_addr, PAGE_SIZE),
		     MMU_MEMORY_TYPE_NORMAL_WRITE_BACK |
			 MMU_MEMORY_AP_P_RW_U_NA,
		     ROUNDUP(teei_log_buf_size, PAGE_SIZE));
#endif
	*len = teei_log_buf_size;
	datasize = dev_write((void *)teei_log_buf_addr, *len);
	/*dprintf(INFO, "[microtrust][%s][%d] TEE: dev_write:0x%x,
	 * teei_log_buf_addr:0x%llx, teei_log_buf_size:0x%x\n", __func__,
	 * __LINE__, datasize, teei_log_buf_addr, teei_log_buf_size);*/
	return datasize;
}

void teei_log_init(void)
{
	plat_teei_log_get = save_teei_log;
}
#endif
