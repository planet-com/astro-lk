/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*/
#include <malloc.h>
#include <dev/aee_platform_debug.h>
#include <arch/arm/mmu.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/mtk_wdt.h>
#include <platform/platform_debug.h>
#include "log_store_lk.h"
#include <plat_debug_interface.h>
#include <spm_common.h>
#include <reg.h>
#include <libfdt.h>
#include <debug.h>
#include <err.h>
#ifdef MTK_TINYSYS_SSPM_SUPPORT
#include <platform/mt_sspm.h>
#include <arch/arm/mmu.h>
#include <platform/timer.h>
#endif
#ifdef MTK_TINYSYS_SCP_SUPPORT
#include <lib/zlib.h>
#include <mt_scp.h>
#include <mt_scp_excep.h>
#endif
#ifdef MTK_AUDIODSP_SUPPORT
#include <mt_adsp.h>
#endif
#include <mtk_mcdi.h>
#ifdef MTK_SMC_ID_MGMT
#include "mtk_secure_api.h"
#endif
#ifdef MTK_TINYSYS_MCUPM_SUPPORT
#include <platform/mt_mcupm.h>
#include <platform/mt_mcupm_excep.h>
#endif

#ifdef MTK_AB_OTA_UPDATER
#include <mt_boot.h>
#endif
#include <plat_sram_flag.h>
#include <ram_console.h>
#ifdef MTK_DPM_SUPPORT
#include <platform/mt_dpm.h>
#endif


int plt_get_cluster_id(unsigned int cpu_id, unsigned int *core_id_in_cluster)
{
	if (core_id_in_cluster == NULL)
		return -1;

	*core_id_in_cluster = (cpu_id % 4);
	return (cpu_id / 4);
}

unsigned long plt_get_cpu_power_status_at_wdt(void)
{
	unsigned long bitmask = 0xff, ret;

	ret = readl(SLEEP_BASE + cfg_pc_latch.spm_pwr_sts);
	bitmask = (ret & 0x3FC00000) >> 22;

	return bitmask;
}

static bool dfd_valid = false;
static bool check_dfd_valid(u32* data)
{
        if (data != NULL) {
                /*
                 * 0x0 = 16'hAA55
                 * 0x4 = 16'h0F0F
                 * 0x8 = 32’h1683-0000
                 */
                if ((((data[0] & 0xffff0000) >> 16) == 0xAA55)
                        && (((data[1] & 0xffff0000) >> 16) == 0x0F0F)
                        && data[2] == 0x16830000)
                        dfd_valid = true;
        }

        return dfd_valid;
}

void reset_snoop_filter_ctrl(void)
{
#ifdef MTK_SMC_ID_MGMT
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_RESET_SNOOP_FILTER_MAGIC, 0, 0, 0);
#else
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_RESET_SNOOP_FILTER_MAGIC, 0, 0);
#endif
}

static void setup_snoop_filter_ram_ctrl(void)
{
#ifdef MTK_SMC_ID_MGMT
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_SETUP_SNOOP_FILTER_MAGIC, 0,	0, 0);
#else
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_SETUP_SNOOP_FILTER_MAGIC, 0, 0);
#endif
}

static void return_snoop_filter_ram_ctrl(void)
{
#ifdef MTK_SMC_ID_MGMT
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_RETURN_SNOOP_FILTER_MAGIC, 0, 0, 0);
#else
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_DFD_RETURN_SNOOP_FILTER_MAGIC, 0, 0);
#endif
}

static void circular_buffer_lock(void)
{
#ifdef MTK_SMC_ID_MGMT
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_CIRCULAR_BUFFER_LOCK, 0, 0, 0);
#else
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_CIRCULAR_BUFFER_LOCK, 0, 0);
#endif
}

static void circular_buffer_unlock(void)
{
#ifdef MTK_SMC_ID_MGMT
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_CIRCULAR_BUFFER_UNLOCK, 0, 0, 0);
#else
	mt_secure_call(MTK_SIP_LK_PLAT_DEBUG, PLAT_MTK_CIRCULAR_BUFFER_UNLOCK, 0, 0);
#endif
}

unsigned int plt_get_dfd_dump_type(void)
{
	return DFD_DUMP_TO_DRAM;
}

static unsigned int save_cpu_bus_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	int ret;
	unsigned int datasize = 0;

	/* Save latch buffer */
	ret = latch_get((void **)&buf, len);
	if (ret && (buf != NULL)) {
		if (*len > 0)
			datasize = dev_write(buf, *len);
		latch_put((void **)&buf);
	}

	/* Save systracker buffer */
	ret = systracker_get((void **)&buf, len, 64);
	if (ret && (buf != NULL)) {
		if (*len > 0)
			datasize += dev_write(buf, *len);
		systracker_put((void **)&buf);
	}

	/* Save etb buffer */
	ret = etb_get((void **)&buf, len);
	if (buf != NULL) {
		if (*len > 0)
			datasize += dev_write(buf, *len);
		etb_put((void **)&buf);
	}

	return datasize;
}

static unsigned int save_dfd_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	int ret;
	unsigned int datasize = 0;

	/* Save dfd buffer */
	ret = dfd_get((void **)&buf, len);

	if (buf != NULL) {
		if (*len > 0)
			datasize = dev_write(buf, *len);
		dfd_put((void **)&buf);
	}

	return datasize;
}

#ifdef MTK_PICACHU_SUPPORT
extern BOOT_ARGUMENT *g_boot_arg; //from platform.c

static unsigned int save_picachu_log(u64 offset, int *len, CALLBACK dev_write)
{
	void *buf = NULL;
	unsigned int datasize = 0;
	unsigned int start = 0;
	unsigned int size = 0;
	int ret,i;
	mblock_info_t *mblock_info = NULL;
	reserved_t * p_reserved = NULL;
	char * ptr;

	mblock_info = &g_boot_arg->mblock_info;
	if (g_boot_arg == NULL || mblock_info == NULL) {
		return 0;
	}

	p_reserved = mblock_query_reserved(mblock_info,"PICACHU",0);
	if (p_reserved != NULL) {
		start = (unsigned int)p_reserved->start;
		size = (unsigned int)p_reserved->size;
		if (size < SECTION_SIZE) {
			ret = arch_mmu_map(start, start,
				MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
				SECTION_SIZE);
		} else {
			ret = arch_mmu_map(start, start,
				MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
				SECTION_SIZE * ((size/SECTION_SIZE) + 1));
		}
		if (ret == NO_ERROR)
			buf = (void *)start;
	}

	if (buf) {
		/*  force dump 512 KB */
		ptr = start;
		for (i = 0; i < 0x80000; i++) {
			ptr[i] = ptr[i] + 0x43;
		}
		*len = 0x80000;
		datasize = dev_write(buf, *len);
	}

	return datasize;
}
#endif

void platform_clear_all_on_mux(void)
{
	/* clear rg_mcu_pwr_iso_dis */
	writel(readl(MCU_ALL_PWR_ON_CTRL) & ~(1 << 2), MCU_ALL_PWR_ON_CTRL);
	dsb();

	/* clear rg_mcu_pwr_on */
	writel(readl(MCU_ALL_PWR_ON_CTRL) & ~(1 << 1), MCU_ALL_PWR_ON_CTRL);
	dsb();
}

/* SPM Debug Features */
static unsigned int spm_wdt_latch_regs[] = {
	SLEEP_BASE + 0x800, /* PCM_WDT_LATCH_0 */
	SLEEP_BASE + 0x804, /* PCM_WDT_LATCH_1 */
	SLEEP_BASE + 0x808, /* PCM_WDT_LATCH_2 */
	SLEEP_BASE + 0x80C, /* PCM_WDT_LATCH_3 */
	SLEEP_BASE + 0x810, /* PCM_WDT_LATCH_4 */
	SLEEP_BASE + 0x814, /* PCM_WDT_LATCH_5 */
	SLEEP_BASE + 0x818, /* PCM_WDT_LATCH_6 */
	SLEEP_BASE + 0x81C, /* PCM_WDT_LATCH_7 */
	SLEEP_BASE + 0x820, /* PCM_WDT_LATCH_8 */
	SLEEP_BASE + 0x824, /* PCM_WDT_LATCH_9 */
	SLEEP_BASE + 0x828, /* PCM_WDT_LATCH_10 */
	SLEEP_BASE + 0x82C, /* PCM_WDT_LATCH_11 */
	SLEEP_BASE + 0x830, /* PCM_WDT_LATCH_12 */
	SLEEP_BASE + 0x834, /* PCM_WDT_LATCH_13 */
	SLEEP_BASE + 0x838, /* PCM_WDT_LATCH_14 */
	SLEEP_BASE + 0x83C, /* PCM_WDT_LATCH_15 */
	SLEEP_BASE + 0x840, /* PCM_WDT_LATCH_16 */
	SLEEP_BASE + 0x844, /* PCM_WDT_LATCH_17 */
	SLEEP_BASE + 0x848, /* PCM_WDT_LATCH_18 */
	SLEEP_BASE + 0x8A0, /* DRAMC_GATING_ERR_LATCH_CH0_0 */
	SLEEP_BASE + 0x8A4, /* DRAMC_GATING_ERR_LATCH_CH0_1 */
	SLEEP_BASE + 0x8A8, /* DRAMC_GATING_ERR_LATCH_CH0_2 */
	SLEEP_BASE + 0x8AC, /* DRAMC_GATING_ERR_LATCH_CH0_3 */
	SLEEP_BASE + 0x8B0, /* DRAMC_GATING_ERR_LATCH_CH0_4 */
	SLEEP_BASE + 0x8B4, /* DRAMC_GATING_ERR_LATCH_CH0_5 */
	SLEEP_BASE + 0x8B8, /* DRAMC_GATING_ERR_LATCH_CH0_6 */
	SLEEP_BASE + 0x780, /* SYS_TIMER_LATCH_L_00 */
	SLEEP_BASE + 0x784, /* SYS_TIMER_LATCH_H_00 */
	SLEEP_BASE + 0x788, /* SYS_TIMER_LATCH_L_01 */
	SLEEP_BASE + 0x78C, /* SYS_TIMER_LATCH_H_01 */
	SLEEP_BASE + 0x790, /* SYS_TIMER_LATCH_L_02 */
	SLEEP_BASE + 0x794, /* SYS_TIMER_LATCH_H_02 */
	SLEEP_BASE + 0x798, /* SYS_TIMER_LATCH_L_03 */
	SLEEP_BASE + 0x79C, /* SYS_TIMER_LATCH_H_03 */
	SLEEP_BASE + 0x7A0, /* SYS_TIMER_LATCH_L_04 */
	SLEEP_BASE + 0x7A4, /* SYS_TIMER_LATCH_H_04 */
	SLEEP_BASE + 0x7A8, /* SYS_TIMER_LATCH_L_05 */
	SLEEP_BASE + 0x7AC, /* SYS_TIMER_LATCH_H_05 */
	SLEEP_BASE + 0x7B0, /* SYS_TIMER_LATCH_L_06 */
	SLEEP_BASE + 0x7B4, /* SYS_TIMER_LATCH_H_06 */
	SLEEP_BASE + 0x7B8, /* SYS_TIMER_LATCH_L_07 */
	SLEEP_BASE + 0x7BC, /* SYS_TIMER_LATCH_H_07 */
	SLEEP_BASE + 0x7C0, /* SYS_TIMER_LATCH_L_08 */
	SLEEP_BASE + 0x7C4, /* SYS_TIMER_LATCH_H_08 */
	SLEEP_BASE + 0x7C8, /* SYS_TIMER_LATCH_L_09 */
	SLEEP_BASE + 0x7CC, /* SYS_TIMER_LATCH_H_09 */
	SLEEP_BASE + 0x7D0, /* SYS_TIMER_LATCH_L_10 */
	SLEEP_BASE + 0x7D4, /* SYS_TIMER_LATCH_H_10 */
	SLEEP_BASE + 0x7D8, /* SYS_TIMER_LATCH_L_11 */
	SLEEP_BASE + 0x7DC, /* SYS_TIMER_LATCH_H_11 */
	SLEEP_BASE + 0x7E0, /* SYS_TIMER_LATCH_L_12 */
	SLEEP_BASE + 0x7E4, /* SYS_TIMER_LATCH_H_12 */
	SLEEP_BASE + 0x7E8, /* SYS_TIMER_LATCH_L_13 */
	SLEEP_BASE + 0x7EC, /* SYS_TIMER_LATCH_H_13 */
	SLEEP_BASE + 0x7F0, /* SYS_TIMER_LATCH_L_14 */
	SLEEP_BASE + 0x7F4, /* SYS_TIMER_LATCH_H_14 */
	SLEEP_BASE + 0x7F8, /* SYS_TIMER_LATCH_L_15 */
	SLEEP_BASE + 0x7FC, /* SYS_TIMER_LATCH_H_15 */
	SLEEP_BASE + 0x914, /* SPM_ACK_CHK_SWINT_0 */
	SLEEP_BASE + 0x934, /* SPM_ACK_CHK_SWINT_1 */
	SLEEP_BASE + 0x954, /* SPM_ACK_CHK_SWINT_2 */
	SLEEP_BASE + 0x974, /* SPM_ACK_CHK_SWINT_3 */
};

#define DVFSRC_DUMP	(DVFSRC_BASE + 0xBF0)
#define DVFSRC_SIZE	0x100
#define DVFSRC_LAST_L	(DVFSRC_BASE + 0xAE8)
#define DVFSRC_SRAM_DUMP (0x0011BBD0)
#define DVFSRC_SRAM_SIZE 0x10

/* need to check aee_db_file_info[] @ app/mt_boot/aee/KEDump.c */
#define SPM_DATA_BUF_LENGTH (4096)

static int spm_dump_data(char *buf, int *wp)
{
	unsigned int i;
	unsigned val;
#ifdef SPM_FW_USE_PARTITION
	char part_name[16] = "spmfw";

#ifdef MTK_AB_OTA_UPDATER
	get_AB_OTA_name((void *)&part_name, sizeof(part_name));
#endif /* MTK_AB_OTA_UPDATER */
#endif /* SPM_FW_USE_PARTITION */

	if (buf == NULL || wp == NULL)
		return -1;

	for (i = 0; i < (sizeof(spm_wdt_latch_regs)/sizeof(unsigned int)); i++) {
		val = readl(spm_wdt_latch_regs[i]);
		*wp += sprintf(buf + *wp,
				"SPM regs(0x%x) = 0x%x\n",
				spm_wdt_latch_regs[i], val);
	}

#ifdef SPM_FW_USE_PARTITION
	get_spmfw_version(part_name, "spmfw", buf, wp);
#endif /* SPM_FW_USE_PARTITION */
	val = readl(DVFSRC_LAST_L);
	*wp += sprintf(buf + *wp,
		"DVFSRC(0x%x) = 0x%08x\n", DVFSRC_LAST_L, val);
	for (i = 0; i < DVFSRC_SIZE; i += 4) {
		val = readl(DVFSRC_DUMP + i);
		*wp += sprintf(buf + *wp,
				"DVFSRC(0x%x) = 0x%08x\n", DVFSRC_DUMP + i, val);
	}
	for (i = 0; i < DVFSRC_SRAM_SIZE; i += 4) {
		val = readl(DVFSRC_SRAM_DUMP + i);
		*wp += sprintf(buf + *wp,
			"DVFSRC(0x%x) = 0x%08x\n", DVFSRC_SRAM_DUMP + i, val);
	}

	if (*wp > SPM_DATA_BUF_LENGTH) {
		dprintf(CRITICAL, "[spm] out of range: 0x%x > SPM_DATA_BUF_LENGTH(0x%x)\n", *wp, SPM_DATA_BUF_LENGTH);
		assert(0);
	}

	return 1;
}

int spm_data_get(void **data, int *len)
{
	int ret;

	*len = 0;
	*data = malloc(SPM_DATA_BUF_LENGTH);
	if (*data == NULL)
		return 0;

	ret = spm_dump_data(*data, len);
	if (ret < 0 || *len > SPM_DATA_BUF_LENGTH) {
		*len = (*len > SPM_DATA_BUF_LENGTH) ? SPM_DATA_BUF_LENGTH : *len;
		return ret;
	}

	return 1;
}

void spm_data_put(void **data)
{
	free(*data);
}

static unsigned int save_spm_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	/* Save SPM buffer */
	spm_data_get((void **)&buf, len);
	if (buf != NULL) {
		if (*len > 0)
			datasize = dev_write(buf, *len);
		spm_data_put((void **)&buf);
	}

	return datasize;
}

/* SRAM for SPM */
#define SPM_SRAM_ADDRESS 0x10021000
#define SPM_SRAM_LENGTH  0x1000 /* 4K bytes */

static int plat_spm_sram_get(void **data, int *len)
{
        *data = (void *)SPM_SRAM_ADDRESS;
        *len  = SPM_SRAM_LENGTH;
        return 1;
}

static unsigned int save_spm_sram_data(u64 offset, int *len, CALLBACK dev_write)
{
        char *buf = NULL;
        unsigned int datasize = 0;

        if (plat_spm_sram_get((void **)&buf, len)) {
                datasize = dev_write(buf, *len);
        }

        return datasize;
}

/* FOR DRAMC data and DRAM Calibration Log
*
* This area is applied for DRAM related debug.
*/
/* DRAMC data */
static int plat_dram_debug_get(void **data, int *len)
{
	sram_plat_dbg_info_addr_size(data, len);
	return 1;
}


static unsigned int save_dram_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	if (plat_dram_debug_get((void **)&buf, len))
		datasize = dev_write(buf, *len);

	return datasize;
}

#ifdef MTK_TINYSYS_SSPM_SUPPORT
static unsigned int save_sspm_coredump(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int datasize = 0;
	int retry = SSPM_COREDUP_RETRY;

	if (!(*(unsigned int *)SSPM_BACKUP)) {
		return 0;
	}

	do {
		buf = *(unsigned int **)(SSPM_DM_ADDR);
		*len = *(int *)SSPM_DM_SZ;
		if (*len > 0) {
			datasize = dev_write(buf, *len);
			break;
		} else {
			udelay(100);
		}
	} while ( --retry);

	buf = *(unsigned int **)(SSPM_RM_ADDR);
	*len = *(int *)SSPM_RM_SZ;
	if (*len > 0) {
		datasize += dev_write(buf, *len);
	}

	return datasize;
}

static unsigned int save_sspm_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	char owner[3] = {'P', 'S', 'L'};      /* Platform, SSPM, SSPM_LAST_LOG */
	unsigned int addr = 0, dispatch = 0;
	unsigned int axi_status;
	unsigned int ahb_status, ahb_addr_m0, ahb_addr_m1, ahb_addr_m2;
	unsigned int datasize = 0, tbufl, tbufh, r, i, j;
	int length = 0;

	buf = malloc(SSPM_DATA_BUF_SZ);
	if (!buf) {
		return 0;
	}

	axi_status  = DRV_Reg32(SSPM_AXI_STATUS);
	ahb_status  = DRV_Reg32(SSPM_AHB_STATUS);
	ahb_addr_m0 = DRV_Reg32(SSPM_AHB_M0_ADDR);
	ahb_addr_m1 = DRV_Reg32(SSPM_AHB_M1_ADDR);
	ahb_addr_m2 = DRV_Reg32(SSPM_AHB_M2_ADDR);

	/* Set Auto-dispatch rule according by AHB_STATUS[13,10,5,4]. */
	if ( (ahb_status & (BIT(13) | BIT(10) | BIT(5) | BIT(4)) ) == 0x0 )
	{
		/* Bus hang issue. */
		if (ahb_status & BIT(2))        /* Master = M0 */
			addr = ahb_addr_m0;
		else if (ahb_status & BIT(3))   /* Master = M1 */
			addr = ahb_addr_m1;
		else if ((ahb_status & BIT(17)) == 0)  /* Master M2 trans is pending. */
			addr = ahb_addr_m2;

		if (((addr >= SYSRAM_START) && (addr < SYSRAM_END)) ||
		    ((addr >= DRAM_START) && (addr < DRAM_END)))
			dispatch = TO_PLATFORM;
		else
			dispatch = TO_SSPM_OWN;
	}
	else
		dispatch = TO_SSPM_LAST_LOG;

	memset(buf, 0, SSPM_DATA_BUF_SZ);
	length += snprintf(buf + length, SSPM_DATA_BUF_SZ - length,
			"STATUS: 0x%x\n"
			"M0: 0x%x\n"
			"M1: 0x%x\n"
			"M2: 0x%x\n"
			"SP: 0x%x\n"
			"LR: 0x%x\n"
			"PC: 0x%x\n"
			"AXI_STATUS: 0x%x\n"
			"Dispatch: %c\n",
			ahb_status, ahb_addr_m0, ahb_addr_m1, ahb_addr_m2,
			DRV_Reg32(SSPM_SP), DRV_Reg32(SSPM_LR),
			DRV_Reg32(SSPM_PC),
			axi_status,
			owner[dispatch]);

	r = DRV_Reg32(SSPM_TBUF_WPTR);
	length += snprintf(buf + length, (SSPM_DATA_BUF_SZ-1) - length, "\nTBUF_WPTR=%u\n", r);

	for (i = 0, j = r; i < 16; ++i, j = (j-1) & 0xF) {
		DRV_WriteReg32(SSPM_DBG_SEL, j);
		tbufl = DRV_Reg32(SSPM_TBUFL);
		tbufh = DRV_Reg32(SSPM_TBUFH);
		length += snprintf(buf + length, (SSPM_DATA_BUF_SZ-1) - length,
				"%u: TBUF[%u] _H=0x%x  _L=0x%x\n", i, j, tbufh, tbufl);
	}

	*len = length;

	if (*len > 0) {
		datasize = dev_write(buf, (*len > SSPM_DATA_BUF_SZ ? SSPM_DATA_BUF_SZ : *len));
	}

	free(buf);

	return datasize;
}

static unsigned int save_sspm_xfile(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int *sspm_info = NULL;
	unsigned int datasize = 0;
	int ret;

	/* Get the information stored in *SSPM_INFO by preloader
	    struct sspm_info_t {
	        unsigned int sspm_dm_ofs;
	        unsigned int sspm_dm_sz;
	        unsigned int rd_ofs;
	        unsigned int rd_sz;
	        unsigned int xfile_addr;
	        unsigned int xfile_sz;
	    };
	*/

#ifdef MTK_3LEVEL_PAGETABLE
	ret = arch_mmu_map(ROUNDDOWN(*(uint64_t *)(SSPM_INFO), SECTION_SIZE),
			ROUNDDOWN(*(uint32_t *)(SSPM_INFO), SECTION_SIZE),
			MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
			SECTION_SIZE);

	if (ret) {
		dprintf(CRITICAL, "kedump: mmu map to 0x%llx fail(%d), SSPM dump might fail.\n",
		(unsigned long long)ROUNDDOWN(*(uint64_t *)(SSPM_INFO), SECTION_SIZE), ret);
		return 0;
	}
#endif

	sspm_info = *(unsigned int **)(SSPM_INFO);
	buf = *(unsigned int **)(sspm_info + 4);
	*len = *(int *)(sspm_info + 5);
	dprintf(CRITICAL, "sspm buf 0x%x, len:0x%x\n", *buf, *len);

	if (*len > 0) {
		datasize = dev_write(buf, *len);
	}

	return datasize;
}

static unsigned int save_sspm_last_log(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int datasize = 0;

	buf = *(unsigned int **)(SSPM_LASTK_ADDR);
	*len = *(int *)SSPM_LASTK_SZ;
	if (*len > 0) {
		datasize = dev_write( buf, *len);
	}

	return datasize;
}
#endif /* #ifdef MTK_TINYSYS_SSPM_SUPPORT */

#ifdef MTK_TINYSYS_SCP_SUPPORT
#define SCP_EE_SIZE 0xE0000  //896 KB
static unsigned int save_scp_coredump(u64 offset, int *len, CALLBACK dev_write)
{
	int memory_dump_size;
	unsigned char *output = malloc(SCP_EE_SIZE + 0x20000);  // extra buffer 128 KB

	if (!output) {
		return 0;
	}

	memory_dump_size = scp_crash_dump(output);

	if ((memory_dump_size > SCP_EE_SIZE) || (memory_dump_size <= Z_NEED_DICT)) {
		dprintf(CRITICAL, "SCP memory_dump_size ERR %d\n", memory_dump_size);
		memory_dump_size = 0;
	} else
		memory_dump_size = dev_write(output, memory_dump_size);

	free(output);

	return memory_dump_size;
}
#endif

#ifdef MTK_AUDIODSP_SUPPORT
#if defined(ADSP_B_ITCM_BASE) && defined(ADSP_B_DTCM_BASE)
#define ADSP_EE_SIZE (ADSP_A_ITCM_SIZE + ADSP_A_DTCM_SIZE + ADSP_B_ITCM_SIZE + ADSP_B_ITCM_SIZE)
#else
#define ADSP_EE_SIZE (ADSP_A_ITCM_SIZE + ADSP_A_DTCM_SIZE) //0x11000 = 68KB
#endif
static int adsp_crash_dump(void *crash_buffer)
{
	unsigned int offset = 0;

	/* all TCM enable clock and release cpu reset */
	switch_adsp_power(true, false);
	adsp_sw_reset();

	memcpy((void *)crash_buffer,
			(void *)(ADSP_A_ITCM_BASE), (ADSP_A_ITCM_SIZE));
	offset += ADSP_A_ITCM_SIZE;
	memcpy((void *)(crash_buffer + offset),
			(void *)(ADSP_A_DTCM_BASE), (ADSP_A_DTCM_SIZE));
	offset += ADSP_A_DTCM_SIZE;

#if defined(ADSP_B_ITCM_BASE) && defined(ADSP_B_DTCM_BASE)
	memcpy((void *)(crash_buffer + offset),
			(void *)(ADSP_B_ITCM_BASE), (ADSP_B_ITCM_SIZE));
	offset += ADSP_B_ITCM_SIZE;
	memcpy((void *)(crash_buffer + offset),
			(void *)(ADSP_B_DTCM_BASE), (ADSP_B_DTCM_SIZE));
	offset += ADSP_B_DTCM_SIZE;
#endif

	return offset;
}
static unsigned int save_adsp_coredump(u64 offset, int *len, CALLBACK dev_write)
{
	int memory_dump_size;

	unsigned char *output = malloc(ADSP_EE_SIZE);
	if (!output) {
		return 0;
	}
	memory_dump_size = adsp_crash_dump(output);

	if (memory_dump_size > ADSP_EE_SIZE) {
		dprintf(CRITICAL, "adsp memory_dump_size ERR %d\n", memory_dump_size);
		memory_dump_size = 0;
	} else
		memory_dump_size = dev_write(output, memory_dump_size);
	free(output);
	return memory_dump_size;
}
#endif

/* SRAM for Hybrid CPU DVFS */
#define HVFS_SRAM_ADDRESS 0x0011bc00
#define HVFS_SRAM_LENGTH  0x1400	/* 5K bytes */
static int plat_hvfs_data_get(void **data, int *len)
{
	*data = (void *)HVFS_SRAM_ADDRESS;
	*len = HVFS_SRAM_LENGTH;
	return 1;
}

static unsigned int save_hvfs_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	if (plat_hvfs_data_get((void **)&buf, len)) {
		datasize = dev_write(buf, *len);
	}

	return datasize;
}

static int plat_log_dur_lkdump_get(void **data, int *len)
{
	*data = (void *)current_buf_addr_get();
	*len = current_buf_pl_lk_log_size_get();
	if((*data == 0) || (*len == 0)) {
		dprintf(CRITICAL, "[LK_LOG_STORE] invalid current address or log length(addr 0x%x, len 0x%x)\n", (unsigned int)*data, (unsigned int)*len);
		return 0;
	}
	dprintf(CRITICAL, "[LK_LOG_STORE] the current buf addr is 0x%x, log len is 0x%x\n", (unsigned int)*data, (unsigned int)*len);
	return 1;
}

static unsigned int save_log_dur_lkdump(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	if (plat_log_dur_lkdump_get((void **)&buf, len)) {
		datasize = dev_write(buf, *len);
	}

	return datasize;
}


static int plat_mcdi_data_get(void **data, int *len)
{
	mcdi_setup_file_info_for_kedump();
	*data = (void *)MCDI_SRAM_ADDRESS;
	*len  = MCDI_SRAM_LENGTH;
	return 1;
}

static unsigned int save_mcdi_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0;

	if (plat_mcdi_data_get((void **)&buf, len)) {
		datasize = dev_write(buf, *len);
	}

	return datasize;
}

int plt_infrasys_init(const struct lastbus_monitor *m)
{
	void *base = m->base;

	/* mt6853 has 1 dummy check point which caused timeout */
	/* let's mask it first */
	writel(0x200, base + 0x014);
	/* ok, do the normal init with max timeout */
	writel(0xffff0008, base);
	writel(0xffff000c, base);

	return 0;
}

int dfd_set_base_addr(void *fdt)
{
	int ret = 0;
	int offset;
	int cache_dump;
	u64 addr;
	unsigned int dfd_size;
	u32 addr_msb;
	unsigned int md_addr;
	unsigned long long ap_addr;
	DEF_PLAT_SRAM_FLAG *plat = NULL;

	if (!fdt)
		return -1;

	ret = mtk_ccci_get_dfd_smem_info(&ap_addr, &md_addr, &dfd_size);
	if (ret < 0)
		return ret;

	offset = fdt_path_offset(fdt, "/chosen");
	if (offset < 0)
		return offset;

	/* pass base address to kernel */
	addr = cpu_to_fdt64(ap_addr);
	ret = fdt_setprop(fdt, offset, "dfd,base_addr", &addr, sizeof(addr));
	if (ret < 0)
		return ret;

	addr_msb = cpu_to_fdt32(ap_addr);
	ret = fdt_setprop(fdt, offset, "dfd,base_addr_msb", &addr_msb, sizeof(addr_msb));
	if (ret < 0)
		return ret;

#ifdef MTK_DFD_ENABLE_CACHE_DUMP
	cache_dump = 1;
#else
	cache_dump = 0;
#endif
	cache_dump = cpu_to_fdt32(cache_dump);
	ret = fdt_setprop(fdt, offset, "dfd,cache_dump_support", &cache_dump, sizeof(cache_dump));
	if (ret < 0)
		return ret;

	/*
	 * write base address[31:1] from AP view to plat_sram_flag2[31:1]
	 * write base address[32:32] from AP view to plat_sram_flag2[0:0]
	 */
	plat = (DEF_PLAT_SRAM_FLAG *)get_dbg_info_base(PLAT_SRAM_FLAG_KEY);
	if (!plat) {
		dprintf(CRITICAL, "[dfd] error: plat == NULL\n");
		return -1;
	}
	plat->plat_sram_flag2 = (ap_addr & ~(0x1)) | ((ap_addr >> 32) & 0x1);

	dprintf(CRITICAL, "[dfd] plat->plat_sram_flag2 = 0x%lx, addr = 0x%llx, addr_msb = 0x%lx\n", plat->plat_sram_flag2,
			        addr, addr_msb);
	return ret;
}

#ifdef MTK_TINYSYS_MCUPM_SUPPORT
#define MCUPM_EE_SIZE 0x40080
static unsigned int save_mcupm_coredump(u64 offset, int *len, CALLBACK dev_write)
{
	int memory_dump_size;
	unsigned char *output = malloc(MCUPM_EE_SIZE + 0x10000);  // extra buffer 64 KB

	if (!output)
		return 0;

	/* in case the mcupm address is invalid */
	if (DRV_Reg32(PLT_RD_MAGIC) != 0xdeadbeef) {
		dprintf(CRITICAL, "[mcupm] dump failed:  invalid address pclrsp = 0x%llx, lastlog = 0x%llx\n", (uint64_t)DRV_Reg32(GPR_BASE_ADDR(21)), (uint64_t)DRV_Reg32(GPR_BASE_ADDR(8)));
		free(output);
		return 0;
	}

	dprintf(CRITICAL, "[mcupm] pclrsp = 0x%llx, lastlog = 0x%llx\n", (uint64_t)DRV_Reg32(GPR_BASE_ADDR(21)), (uint64_t)DRV_Reg32(GPR_BASE_ADDR(8)));

	memset(output, 0, MCUPM_EE_SIZE + 0x10000);
	memory_dump_size = mcupm_crash_dump(output);

	if (memory_dump_size > MCUPM_EE_SIZE) {
		dprintf(CRITICAL, "MCUPM memory_dump_size ERR %d\n", memory_dump_size);
		memory_dump_size = 0;
	} else
		memory_dump_size = dev_write(output, memory_dump_size);

	free(output);

	return memory_dump_size;
}

#if 0
static unsigned int save_mcupm_data(u64 offset, int *len, CALLBACK dev_write)
{
	char *buf = NULL;
	unsigned int datasize = 0, tbufl, tbufh, r, i;
	int length = 0;
	unsigned int mcupm_ahb_status, mcupm_ahb_addr_m0, mcupm_ahb_addr_m1;

	return datasize; //To-Do : data will be merged into coredump

	buf = malloc(MCUPM_DATA_BUF_SZ);
	if (!buf) {
		return 0;
	}

	mcupm_ahb_status  = DRV_Reg32(MCUPM_AHB_STATUS);
	mcupm_ahb_addr_m0 = DRV_Reg32(MCUPM_AHB_M0_ADDR);
	mcupm_ahb_addr_m1 = DRV_Reg32(MCUPM_AHB_M1_ADDR);
	memset(buf, 0, MCUPM_DATA_BUF_SZ);
	length += snprintf(buf + length, (MCUPM_DATA_BUF_SZ-1) - length,
		"MCUPM_AHB_STATUS: 0x%08x\n"
		"MCUPM_AHB_M0_ADDR: 0x%x\n"
		"MCUPM_AHB_M1_ADDR: 0x%x\n"
		"MCUPM_LastPC: 0x%x\n",
		mcupm_ahb_status, mcupm_ahb_addr_m0, mcupm_ahb_addr_m1,
		DRV_Reg32(MCUPM_PC));

	r = DRV_Reg32(MCUPM_TBUF_WPTR);
	length += snprintf(buf + length, (MCUPM_DATA_BUF_SZ-1) - length, "\nTBUF_WPTR=%u\n", r);

	for (i = 0; i < 4; ++i) {
		tbufl = DRV_Reg32(MCUPM_TBUF0_L + (0x4 * i));
		tbufh = DRV_Reg32(MCUPM_TBUF0_H + (0x4 * i));
		length += snprintf(buf + length, (MCUPM_DATA_BUF_SZ-1) - length,
				"TBUF[%u] H=0x%x L=0x%x\n", i, tbufh, tbufl);
	}

	*len = length;

	if (*len > 0) {
		datasize = dev_write(buf, (*len > MCUPM_DATA_BUF_SZ ? MCUPM_DATA_BUF_SZ : *len));
	}

	free(buf);

	return datasize;
}

static unsigned int save_mcupm_xfile(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int *mcupm_info = NULL;
	unsigned int datasize = 0;
	int ret;

	return datasize; //To-Do : mt6853 do not have xfile
#ifdef MTK_3LEVEL_PAGETABLE
    ret = arch_mmu_map(ROUNDDOWN(*(uint64_t *)(MCUPM_INFO), SECTION_SIZE),
            ROUNDDOWN(*(uint32_t *)(MCUPM_INFO), SECTION_SIZE),
			MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA,
			SECTION_SIZE);

	if (ret) {
        dprintf(CRITICAL, "kedump: mmu map to 0x%llx fail(%d), MCUPM dump might fail.\n",
            (unsigned long long)ROUNDDOWN(*(uint64_t *)(MCUPM_INFO), SECTION_SIZE), ret);
		return 0;
	}
#endif

    mcupm_info = *(unsigned int **)(MCUPM_INFO);
    buf = *(unsigned int **)(mcupm_info + 4);
    *len = *(int *)(mcupm_info + 5);
    dprintf(CRITICAL, "mcupm buf 0x%x, len:0x%x\n", *buf, *len);
	if (*len > 0) {
		datasize = dev_write( buf, *len);
	}

	return datasize;
}
#endif

static unsigned int save_mcupm_last_log(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int datasize = 0;
	unsigned int src_w_pos, src_r_pos;

	/* in case the mcupm address is invalid */
	if (DRV_Reg32(PLT_RD_MAGIC) != 0xdeadbeef) {
		dprintf(CRITICAL, "[mcupm] dump failed:  invalid address pclrsp = 0x%llx, lastlog = 0x%llx\n", (uint64_t)DRV_Reg32(GPR_BASE_ADDR(21)), (uint64_t)DRV_Reg32(GPR_BASE_ADDR(8)));
		return 0;
	}

	if (DRV_Reg32(MCUPM_LASTK_ADDR) == 0xdeadbeef) {
		dprintf(CRITICAL, "[mcupm] dump failed:  mcupm disable logger\n");
		return 0;
	}

	dprintf(CRITICAL, "[mcupm] pclrsp = 0x%llx, lastlog = 0x%llx\n", (uint64_t)DRV_Reg32(GPR_BASE_ADDR(21)), (uint64_t)DRV_Reg32(GPR_BASE_ADDR(8)));

	//get logger address
	buf = (unsigned int *)(DRV_Reg32(MCUPM_LASTK_ADDR) + MCUPM_SRAM_BASE);
	*len = *(int *)MCUPM_LASTK_SZ;
	src_w_pos = *(unsigned int **)(MCUPM_LASTK_W_POS);
	src_r_pos = *(unsigned int **)(MCUPM_LASTK_R_POS);

	src_w_pos = DRV_Reg32(src_w_pos + MCUPM_SRAM_BASE);
	src_r_pos = DRV_Reg32(src_r_pos + MCUPM_SRAM_BASE);

	if (*len <= 0)
		return datasize;

	if (src_w_pos > src_r_pos)
		datasize = dev_write(buf + src_r_pos, src_w_pos - src_r_pos);
	else
	{
		datasize = dev_write(buf + src_r_pos, *len - src_r_pos);
		datasize += dev_write(buf, src_w_pos);
	}

	dprintf(CRITICAL, "[mcupm] dump last log sueecess datasize = %d\n", datasize);

	return datasize;
}
#endif  /* #ifdef MTK_TINYSYS_MCUPM_SUPPORT */

#ifdef MTK_DPM_SUPPORT
static unsigned int set_dpm_header(unsigned char *buf)
{
	unsigned int version = DPM_VERSION;
	unsigned int hw_id = DPM_HWID;
	unsigned int nr_dpm = DPM_NUM;
	unsigned int nr_channel = DRAM_CHANNEL;
	unsigned int coredump_sz = DPM_DM_OFFSET;
	unsigned int lpif_sz = DPM_DBG_LEN;
	unsigned int cfg_sz = DPM_CFG1_LEN + DPM_CFG2_LEN;
	unsigned int dram_sz = DDRPHY_LATCH_LEN*DRAM_CHANNEL;
	unsigned int offset = 0;

	memcpy(buf + offset, &version, sizeof(version));
	offset += sizeof(version);
	memcpy(buf + offset, &hw_id, sizeof(hw_id));
	offset += sizeof(hw_id);
	memcpy(buf + offset, &nr_dpm, sizeof(nr_dpm));
	offset += sizeof(nr_dpm);
	memcpy(buf + offset, &nr_channel, sizeof(nr_channel));
	offset += sizeof(nr_channel);
	memcpy(buf + offset, &coredump_sz, sizeof(coredump_sz));
	offset += sizeof(coredump_sz);
	memcpy(buf + offset, &lpif_sz, sizeof(lpif_sz));
	offset += sizeof(lpif_sz);
	memcpy(buf + offset, &cfg_sz, sizeof(cfg_sz));
	offset += sizeof(cfg_sz);
	memcpy(buf + offset, &dram_sz, sizeof(dram_sz));
	offset += sizeof(dram_sz);

	return offset;
}

static unsigned int save_dpm_data(u64 offset, int *len, CALLBACK dev_write)
{
	unsigned int *buf = NULL;
	unsigned int headersize = 0;
	unsigned int datasize = 0;
	unsigned int channel_index = 0;
	unsigned char *header = malloc(DPM_HEAD_SIZE);

	if (!header) {
		return 0;
	}

	headersize += set_dpm_header(header);

	if (headersize > 0) {
		datasize += dev_write(header, headersize);
	}

	free(header);

	buf = (unsigned int *)(DPM_DM1_SRAM_BASE);
	*len = (unsigned int)(DPM_DM_OFFSET);
	datasize += dev_write(buf, *len);

	buf = (unsigned int *)(DPM_DBG_LATCH_CH0);
	*len = (unsigned int)(DPM_DBG_LEN);
	datasize += dev_write(buf, *len);

	buf = (unsigned int *)(DPM_CFG1_CH0);
	*len = (unsigned int)(DPM_CFG1_LEN);
	datasize += dev_write(buf, *len);

	buf = (unsigned int *)(DPM_CFG2_CH0);
	*len = (unsigned int)(DPM_CFG2_LEN);
	datasize += dev_write(buf, *len);

	for (channel_index = 0; channel_index < DRAM_CHANNEL; channel_index++) {
		//ddrphy RG
		buf = (unsigned int *)(DDRPHY_AO_CH0 + channel_index*CHANNEL_OFFSET + DDRPHY_LATCH_OFFSET);
		*len = (unsigned int)(DDRPHY_LATCH_LEN);
		datasize += dev_write(buf, *len);
	}

	return datasize;
}
#endif
/* platform initial function */
int platform_debug_init(void)
{
	/* function pointer assignment */
	plat_spm_data_get = save_spm_data;
	/*FIXME:  bypass dump sram data */
	//plat_spm_sram_data_get = save_spm_sram_data;
	plat_dram_get = save_dram_data;
	plat_cpu_bus_get = save_cpu_bus_data;
#ifdef MTK_TINYSYS_SSPM_SUPPORT
	plat_sspm_coredump_get = save_sspm_coredump;
	plat_sspm_data_get = save_sspm_data;
	plat_sspm_xfile_get = save_sspm_xfile;
	plat_sspm_log_get = save_sspm_last_log;
#endif
#ifdef MTK_TINYSYS_SCP_SUPPORT
	plat_scp_coredump_get = save_scp_coredump;
#endif
	plat_hvfs_get = save_hvfs_data;
	plat_dur_lkdump_get = save_log_dur_lkdump;
	plat_mcdi_get = save_mcdi_data;

	plat_dfd20_get = save_dfd_data;

#ifdef MTK_PICACHU_SUPPORT
	plat_picachu_log_get = save_picachu_log;
#endif

	dfd_op.acquire_ram_control = setup_snoop_filter_ram_ctrl;
	dfd_op.release_ram_control = return_snoop_filter_ram_ctrl;
	dfd_op.check_dfd_valid = check_dfd_valid;
	circular_buffer_op.lock = circular_buffer_lock;
	circular_buffer_op.unlock = circular_buffer_unlock;

#ifdef MTK_TINYSYS_MCUPM_SUPPORT
	plat_mcupm_coredump_get = save_mcupm_coredump;
	//plat_mcupm_data_get = save_mcupm_data;
	//plat_mcupm_xfile_get = save_mcupm_xfile;
	plat_mcupm_log_get = save_mcupm_last_log;
#endif

#ifdef MTK_AUDIODSP_SUPPORT
	plat_adsp_coredump_get = save_adsp_coredump;
#endif

#ifdef MTK_DPM_SUPPORT
	plat_dpm_data_get = save_dpm_data;
#endif


	return 1;
}
