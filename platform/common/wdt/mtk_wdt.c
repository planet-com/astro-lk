/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2015. All rights reserved.
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

#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include "mtk_wdt.h"
#include <platform/boot_mode.h>
#include <platform/mt_gpt.h>
#include <platform/mt_pmic.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/upmu_common.h>
#include <debug.h>
#include <lk_builtin_dtb.h>
#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#endif
#include "log_store_lk.h"

#define WDTTAG                "[WDT] "
#define WDTLOG(fmt, arg...)   dprintf(INFO, WDTTAG fmt, ##arg)
#define WDTCRI(fmt, arg...)   dprintf(CRITICAL,WDTTAG fmt, ##arg)
#define WDTMSG(fmt, arg...)   dprintf(INFO, fmt, ##arg)
#define WDTERR(fmt, arg...)   dprintf(INFO, WDTTAG "%5d: "fmt, __LINE__, ##arg)
#define TOPRGU_DTS_NAME       "/toprgu@10007000"
#define TOPRGU_DT_NODE_PROP_NAME  "apwdt_en"
#if ENABLE_WDT_MODULE

static unsigned int timeout;
static unsigned int is_rgu_trigger_rst;
static unsigned char rgu_restart_reason = MTK_WDT_NONRST2_BOOT_MASK;

#define WDT_CLR_IRQ	0

static void mtk_wdt_clear_restart_reason(unsigned char mask)
{
	u32 tmp;

	tmp = DRV_Reg32(MTK_WDT_NONRST_REG2);
	tmp &= ~mask;
	DRV_WriteReg32(MTK_WDT_NONRST_REG2, tmp);
}

static unsigned char mtk_wdt_get_restart_reason(void)
{
	u32 tmp;

	tmp = DRV_Reg32(MTK_WDT_NONRST_REG2) & MTK_WDT_NONRST2_BOOT_MASK;
	mtk_wdt_clear_restart_reason(MTK_WDT_NONRST2_BOOT_MASK);
	return tmp;
}

unsigned char mtk_wdt_restart_reason()
{
	if (rgu_restart_reason == MTK_WDT_NONRST2_BOOT_MASK)
		rgu_restart_reason = mtk_wdt_get_restart_reason();
	return rgu_restart_reason;
}

void mtk_wdt_disable(void)
{
	u32 tmp;

	tmp = DRV_Reg32(MTK_WDT_MODE);
	tmp &= ~MTK_WDT_MODE_ENABLE;       /* disable watchdog */
	tmp |= (MTK_WDT_MODE_KEY);         /* need key then write is allowed */
	DRV_WriteReg32(MTK_WDT_MODE, tmp);
}

void mtk_wdt_doe_setup(void)
{
	int apwdt_en = 1;
	int len = 0, offset = 0;
	unsigned int *data = NULL;
	void *wdt_fdt = get_lk_overlayed_dtb();

	offset = fdt_path_offset(wdt_fdt, TOPRGU_DTS_NAME);
	WDTLOG("[WDT] Found " TOPRGU_DTS_NAME " at offset %d\n", offset);
	if (offset < 0) {
		WDTERR("[WDT] Failed to find " TOPRGU_DTS_NAME " in dtb\n");
		apwdt_en = 1;
	} else {
		data = (unsigned int *)fdt_getprop(wdt_fdt, offset, TOPRGU_DT_NODE_PROP_NAME, &len);
		if (len <= 0 || !data) {
			WDTERR("[WDT] Fail to found property " TOPRGU_DT_NODE_PROP_NAME "\n");
			apwdt_en = 1;
		} else
			apwdt_en = fdt32_to_cpu(*(unsigned int *)data);
	}

	if (apwdt_en == 0) {
		/* disable wdt timeout */
		mtk_wdt_disable();
		/* disable all reset source's reset and irq mode */
		DRV_WriteReg32(MTK_WDT_REQ_MODE, MTK_WDT_REQ_MODE_KEY);
		DRV_WriteReg32(MTK_WDT_REQ_IRQ_EN, MTK_WDT_REQ_IRQ_KEY);
		WDTLOG("apwdt is disabled by doe\n");
	} else {
		WDTLOG("keep original wdt settings\n");
	}
}

static void mtk_wdt_clear_all(void)
{
#if WDT_CLR_IRQ
	DRV_WriteReg32(MTK_WDT_IRQ_CLR, MTK_WDT_IRQ_CLR_MASK |
			 MTK_WDT_IRQ_CLR_KEY);
#else
	return;
#endif
}

void __attribute__((weak)) pwrap_disable(void)
{
	WDTCRI("pwrap do nothing\n");
}

static void mtk_wdt_reset(char bypass_power_key)
{
	WDTCRI("%s\n", __func__);

	/* Watchdog Rest */
	unsigned int wdt_mode_val = 0, nonrst2 = 0;

	mtk_wdt_clear_all();

	DRV_WriteReg32(MTK_WDT_RESTART, MTK_WDT_RESTART_KEY);

	/*set latch register to 0 before sw reset*/
	/* DRV_WriteReg32(MTK_WDT_LATCH_CTL, (MTK_WDT_LENGTH_CTL_KEY | 0x0)); */

	wdt_mode_val = DRV_Reg32(MTK_WDT_MODE);
	/*
	 * MTK_WDT_MODE_AUTO_RESTART is replaced by MTK_WDT_NONRST2_BYPASS_PWR_KEY
	 * of NONRST_REG2 for common kernel projects and two stage timeout design
	 */
	nonrst2 = DRV_Reg32(MTK_WDT_NONRST_REG2);

	/* clear autorestart bit: autoretart: 1, bypass power key, 0: not bypass power key */
	nonrst2 &= ~MTK_WDT_NONRST2_BYPASS_PWR_KEY;

	/* make sure WDT mode is hw reboot mode, can not config isr mode  */
	wdt_mode_val &= (~(MTK_WDT_MODE_IRQ | MTK_WDT_MODE_DUAL_MODE | MTK_WDT_MODE_EXTRA_CNT));

	wdt_mode_val = wdt_mode_val | MTK_WDT_MODE_KEY | MTK_WDT_MODE_EXTEN;

	/* bypass power key reboot. We using auto_restart bit as bypass power key flag */
	if (bypass_power_key)
		nonrst2 |= MTK_WDT_NONRST2_BYPASS_PWR_KEY;

	DRV_WriteReg32(MTK_WDT_MODE, wdt_mode_val);
	DRV_WriteReg32(MTK_WDT_NONRST_REG2, nonrst2);

	if (!DRV_Reg32(MTK_WDT_STATUS)) {
		unsigned int latch_ctrl2 = DRV_Reg32(MTK_WDT_LATCH_CTL2);

		latch_ctrl2 &= ~MTK_WDT_LATCH_CTL2_DFD_EN;
		latch_ctrl2 |= MTK_WDT_LATCH_CTL2_KEY;
		DRV_WriteReg32(MTK_WDT_LATCH_CTL2, latch_ctrl2);
	}

	gpt_busy_wait_us(100);

	WDTCRI("%s: MODE: 0x%x\n", __func__, DRV_Reg32(MTK_WDT_MODE));
	WDTCRI("%s: SW reset happen!\n", __func__);
	WDTCRI("%s disable pwrap before wdt\n",  __func__);
	pwrap_disable();
	DRV_WriteReg32(MTK_WDT_SWRST, MTK_WDT_SWRST_KEY);
}

unsigned int mtk_wdt_check_status(void)
{
	unsigned int status;

	status = DRV_Reg32(MTK_WDT_STATUS);

	return status;
}

static void mtk_wdt_mode_config(BOOL dual_mode_en,
				    BOOL irq,
				    BOOL ext_en,
				    BOOL ext_pol,
				    BOOL wdt_en)
{
	unsigned int tmp;

	mtk_wdt_clear_all();

	WDTLOG(" mtk_wdt_mode LK config  mode value=%x\n", DRV_Reg32(MTK_WDT_MODE));
	tmp = DRV_Reg32(MTK_WDT_MODE);
	tmp |= MTK_WDT_MODE_KEY | MTK_WDT_MODE_EXTRA_CNT;

	/* Bit 0 : Whether enable watchdog or not */
	if (wdt_en == TRUE)
		tmp |= MTK_WDT_MODE_ENABLE;
	else
		tmp &= ~MTK_WDT_MODE_ENABLE;

	/* Bit 1 : Configure extern reset signal polarity. */
	if (ext_pol == TRUE)
		tmp |= MTK_WDT_MODE_EXT_POL;
	else
		tmp &= ~MTK_WDT_MODE_EXT_POL;

	/* Bit 2 : Whether enable external reset signal */
	if (ext_en == TRUE)
		tmp |= MTK_WDT_MODE_EXTEN;
	else
		tmp &= ~MTK_WDT_MODE_EXTEN;

	/* Bit 3 : Whether generating interrupt instead of reset signal */
	if (irq == TRUE)
		tmp |= MTK_WDT_MODE_IRQ;
	else
		tmp &= ~MTK_WDT_MODE_IRQ;

	/* Bit 6 : Whether enable debug module reset */
	if (dual_mode_en == TRUE)
		tmp |= MTK_WDT_MODE_DUAL_MODE;
	else
		tmp &= ~MTK_WDT_MODE_DUAL_MODE;

	DRV_WriteReg32(MTK_WDT_MODE, tmp);

	/*
	 * MTK_WDT_MODE_AUTO_RESTART is replaced by MTK_WDT_NONRST2_BYPASS_PWR_KEY
	 * of NONRST_REG2 for common kernel projects and two stage timeout design
	 */
	DRV_WriteReg32(MTK_WDT_NONRST_REG2, DRV_Reg32(MTK_WDT_NONRST_REG2) |
			 MTK_WDT_NONRST2_BYPASS_PWR_KEY);

	/* dual_mode(1); //always dual mode */
	/* mdelay(100); */
	WDTLOG(" mtk_wdt_mode_config LK  mode value=%x, tmp:%x\n", DRV_Reg32(MTK_WDT_MODE), tmp);

}


#if 0
static void mtk_wdt_mode_config(BOOL debug_en,
				BOOL irq,
				BOOL ext_en,
				BOOL ext_pol,
				BOOL wdt_en)
{
	unsigned short tmp;

	tmp = DRV_Reg32(MTK_WDT_MODE);
	tmp |= MTK_WDT_MODE_KEY;

	/* Bit 0 : Whether enable watchdog or not */
	if (wdt_en == TRUE)
		tmp |= MTK_WDT_MODE_ENABLE;
	else
		tmp &= ~MTK_WDT_MODE_ENABLE;

	/* Bit 1 : Configure extern reset signal polarity. */
	if (ext_pol == TRUE)
		tmp |= MTK_WDT_MODE_EXT_POL;
	else
		tmp &= ~MTK_WDT_MODE_EXT_POL;

	/* Bit 2 : Whether enable external reset signal */
	if (ext_en == TRUE)
		tmp |= MTK_WDT_MODE_EXTEN;
	else
		tmp &= ~MTK_WDT_MODE_EXTEN;

	/* Bit 3 : Whether generating interrupt instead of reset signal */
	if (irq == TRUE)
		tmp |= MTK_WDT_MODE_IRQ;
	else
		tmp &= ~MTK_WDT_MODE_IRQ;

	/* Bit 6 : Whether enable debug module reset */
	if (debug_en == TRUE)
		tmp |= MTK_WDT_MODE_DEBUG_EN;
	else
		tmp &= ~MTK_WDT_MODE_DEBUG_EN;

	DRV_WriteReg32(MTK_WDT_MODE, tmp);
}
#endif
void mtk_wdt_set_time_out_value(UINT32 value)
{
	/*
	* TimeOut = BitField 15:5
	* Key      = BitField  4:0 = 0x08
	*/

	/* sec * 32768 / 512 = sec * 64 = sec * 1 << 6 */
	timeout = (unsigned int)(value * (1 << 6));
	timeout = timeout << 5;
	DRV_WriteReg32(MTK_WDT_LENGTH, (timeout | MTK_WDT_LENGTH_KEY));
}

void mtk_wdt_restart(void)
{
	/* Reset WatchDogTimer's counting value to time out value */
	/* ie., keepalive() */

	DRV_WriteReg32(MTK_WDT_RESTART, MTK_WDT_RESTART_KEY);
}

static void mtk_wdt_sw_reset(void)
{
	WDTLOG("WDT SW RESET\n");
	/* DRV_WriteReg32 (0x70025000, 0x2201); */
	/* DRV_WriteReg32 (0x70025008, 0x1971); */
	/* DRV_WriteReg32 (0x7002501C, 0x1209); */
	mtk_wdt_reset(1);/* NOTE here, this reset will cause by pass power key */

	/* system will reset */

	while (1) {
		WDTLOG("SW reset fail ...\n");
	};
}

static void mtk_wdt_hw_reset(void)
{
	WDTLOG("WDT_HW_Reset\n");

	/* 1. set WDT timeout 1 secs, 1*64*512/32768 = 1sec */
	mtk_wdt_set_time_out_value(1);

	/* 2. enable WDT debug reset enable, generating irq disable, ext reset disable */
	/* ext reset signal low, wdt enalbe */
	mtk_wdt_mode_config(TRUE, FALSE, FALSE, FALSE, TRUE);

	/* 3. reset the watch dog timer to the value set in WDT_LENGTH register */
	mtk_wdt_restart();

	/* 4. system will reset */
	while (1);
}

const char *mtk_wdt_get_last_stage(void)
{
	unsigned int reg;
	unsigned int last_stage;

	/* check reboot source */
	reg = DRV_Reg32(MTK_WDT_NONRST_REG2);

	last_stage = (reg >> MTK_WDT_NONRST2_LAST_STAGE_OFS) & RGU_STAGE_MASK;

	if (last_stage == RGU_STAGE_PRELOADER)
		return "rst from: pl";
	else if (last_stage == RGU_STAGE_LK)
		return "rst from: lk";
	else if (last_stage == RGU_STAGE_KERNEL)
		return "rst from: kernel";
	else if (last_stage == RGU_STAGE_DA)
		return "rst from: DA";

	return "rst from: unknown";
}

static void mtk_wdt_mark_stage(unsigned int stage)
{
	unsigned int reg = DRV_Reg32(MTK_WDT_NONRST_REG2);

	reg = (reg & ~(RGU_STAGE_MASK << MTK_WDT_NONRST2_STAGE_OFS))
		| (stage << MTK_WDT_NONRST2_STAGE_OFS);

	DRV_WriteReg32(MTK_WDT_NONRST_REG2, reg);
}

void mtk_wdt_select_eint(unsigned int ext_debugkey_io_eint)
{
	unsigned int eint = ext_debugkey_io_eint;

	eint = (eint << MTK_WDT_EXT_EINT_SHF) & MTK_WDT_EXT_EINT_MASK;
	DRV_WriteReg32(MTK_WDT_EXT_REQ_CON, eint | MTK_WDT_EXT_EINT_EN);
}

int mtk_wdt_request_en_set(int mark_bit, WD_REQ_CTL en)
{
	unsigned int tmp;

	if ((mark_bit != MTK_WDT_STATUS_SSPM_RST) &&
		(mark_bit != MTK_WDT_STATUS_SYSRST_RST) &&
		(mark_bit != MTK_WDT_STATUS_EINT_RST) &&
		(mark_bit != MTK_WDT_STATUS_SPM_THERMAL_RST))
		return -1;

	tmp = DRV_Reg32(MTK_WDT_REQ_MODE);
	tmp |= MTK_WDT_REQ_MODE_KEY;

	if (en == WD_REQ_EN) {
		tmp |= (mark_bit);
		if (mark_bit & MTK_WDT_STATUS_SYSRST_RST) {
			DRV_WriteReg32(MTK_WDT_SYSDBG_DEG_EN1,
				MTK_WDT_SYSDBG_DEG_EN1_KEY);
			DRV_WriteReg32(MTK_WDT_SYSDBG_DEG_EN2,
				MTK_WDT_SYSDBG_DEG_EN2_KEY);
		}
	} else if (en == WD_REQ_DIS) {
		tmp &= ~(mark_bit);
		if (mark_bit & MTK_WDT_STATUS_SYSRST_RST) {
			DRV_WriteReg32(MTK_WDT_SYSDBG_DEG_EN1, 0);
			DRV_WriteReg32(MTK_WDT_SYSDBG_DEG_EN2, 0);
		}
	}

	DRV_WriteReg32(MTK_WDT_REQ_MODE, tmp);
	return 0;
}

int mtk_wdt_request_mode_set(int mark_bit, WD_REQ_MODE mode)
{
	unsigned int tmp;

	if ((mark_bit != MTK_WDT_STATUS_SSPM_RST) &&
		(mark_bit != MTK_WDT_STATUS_SYSRST_RST) &&
		(mark_bit != MTK_WDT_STATUS_EINT_RST) &&
		(mark_bit != MTK_WDT_STATUS_SPM_THERMAL_RST))
		return -1;

	tmp = DRV_Reg32(MTK_WDT_REQ_IRQ_EN);
	tmp |= MTK_WDT_REQ_IRQ_KEY;

	if (mode == WD_REQ_IRQ_MODE)
		tmp |= (mark_bit);
	else if (mode == WD_REQ_RST_MODE)
		tmp &= ~(mark_bit);

	DRV_WriteReg32(MTK_WDT_REQ_IRQ_EN, tmp);
	return 0;
}

int mtk_wdt_swsysret_config(int bit, int set_value)
{
	unsigned int wdt_sys_val;

	wdt_sys_val = DRV_Reg32(MTK_WDT_SWSYSRST);
	wdt_sys_val |= MTK_WDT_SWSYS_RST_KEY;
	switch (bit) {
	case MTK_WDT_SWSYS_RST_GPU_RST:
		if (set_value == 1)
			wdt_sys_val |= MTK_WDT_SWSYS_RST_GPU_RST;
		if (set_value == 0)
			wdt_sys_val &= ~MTK_WDT_SWSYS_RST_GPU_RST;
		break;
	}
	DRV_WriteReg32(MTK_WDT_SWSYSRST, wdt_sys_val);

	return 0;
}

#ifdef MTK_ENTER_FASTBOOT_VIA_RGU
int mtk_wdt_fastboot_check(void)
{
	int is_fastboot = 0;

	if (mtk_wdt_restart_reason() == MTK_WDT_NONRST2_BOOT_BOOTLOADER)
		is_fastboot = 1;

	return is_fastboot;
}

/* set fastboot rgu bit. 1: fastboot mode. 0: non-fastboot mode */
void mtk_wdt_fastboot_set(int fastboot_en)
{
	unsigned int reg = DRV_Reg32(MTK_WDT_NONRST_REG2) &
				~(MTK_WDT_NONRST2_BOOT_MASK);

	if (fastboot_en) {
		reg = reg | MTK_WDT_NONRST2_BOOT_BOOTLOADER;
		DRV_WriteReg32(MTK_WDT_NONRST_REG2, reg);
	}
}
#endif

/**
 * For Power off and power on reset, the INTERVAL default value is 0x7FF.
 * We set Interval[1:0] to different value to distinguish different stage.
 * Enter pre-loader, we will set it to 0x0
 * Enter u-boot, we will set it to 0x1
 * Enter kernel, we will set it to 0x2
 * And the default value is 0x3 which means reset from a power off and power on reset
 */
#define POWER_OFF_ON_MAGIC  (0x3)
#define PRE_LOADER_MAGIC    (0x0)
#define U_BOOT_MAGIC        (0x1)
#define KERNEL_MAGIC        (0x2)
#define MAGIC_NUM_MASK      (0x3)
/**
 * If the reset is trigger by RGU(Time out or SW trigger), we hope the system can boot up directly;
 * we DO NOT hope we must press power key to reboot system after reset.
 * This message should tell pre-loader and u-boot, and we use Interval[2] to store this information.
 * And this information will be cleared when enter kernel.
 */
#define IS_POWER_ON_RESET   (0x1<<2)
#define RGU_TRIGGER_RESET_MASK  (0x1<<2)
void mtk_wdt_init(void)
{
	unsigned int tmp;
	unsigned int interval_val = DRV_Reg32(MTK_WDT_INTERVAL);

	rgu_restart_reason = mtk_wdt_restart_reason();

	/* mark stage */
	mtk_wdt_mark_stage(RGU_STAGE_LK);

	mtk_wdt_mode_config(FALSE, FALSE, FALSE, FALSE, FALSE);
	WDTLOG("wdt init\n");

	/* Update interval register value and check reboot flag */
	if ((interval_val & RGU_TRIGGER_RESET_MASK) == IS_POWER_ON_RESET)
		is_rgu_trigger_rst = 0; /* Power off and power on reset */
	else
		is_rgu_trigger_rst = 1; /* RGU trigger reset */

	interval_val &= ~(RGU_TRIGGER_RESET_MASK|MAGIC_NUM_MASK);
	interval_val |= (U_BOOT_MAGIC|IS_POWER_ON_RESET);

	/* Write back INTERVAL REG */
	DRV_WriteReg32(MTK_WDT_INTERVAL, interval_val);
	/* Setting timeout 10s */
	mtk_wdt_set_time_out_value(10);

	/*set SPM_SCPSYS_rst to be enable to be disable*/
	tmp = DRV_Reg32(MTK_WDT_REQ_MODE);
	tmp |= MTK_WDT_REQ_MODE_KEY;
	tmp |= MTK_WDT_REQ_MODE_SPM_SCPSYS;
	tmp |= MTK_WDT_REQ_MODE_THERMAL;
	DRV_WriteReg32(MTK_WDT_REQ_MODE, tmp);

	/*set thermal_ctl_rst & SPM_SCPSYS_rst to be reset mode*/
	tmp = DRV_Reg32(MTK_WDT_REQ_IRQ_EN);
	tmp |= MTK_WDT_REQ_IRQ_KEY;
	tmp &= ~(MTK_WDT_REQ_IRQ_THERMAL_EN | MTK_WDT_REQ_IRQ_SPM_SCPSYS_EN);
	DRV_WriteReg32(MTK_WDT_REQ_IRQ_EN, tmp);

#ifdef WDT_ENABLED
	mtk_wdt_mode_config(TRUE, TRUE, TRUE, FALSE, TRUE);
	mtk_wdt_restart();
#endif

#if 0
	int i = 0;
	/* lk wdt test */
	while (1) {

		i++;
		mdelay(1000);
		WDTLOG("wdt test %d\n", i);
		/* Dump RGU regisers */
		WDTLOG("==== fwq Dump RGU Reg ========\n");
		WDTLOG("RGU MODE:     %x\n", DRV_Reg32(MTK_WDT_MODE));
		WDTLOG("RGU LENGTH:   %x\n", DRV_Reg32(MTK_WDT_LENGTH));
		WDTLOG("RGU STA:      %x\n", DRV_Reg32(MTK_WDT_STATUS));
		WDTLOG("RGU INTERVAL: %x\n", DRV_Reg32(MTK_WDT_INTERVAL));
		WDTLOG("RGU SWSYSRST: %x\n", DRV_Reg32(MTK_WDT_SWSYSRST));
		WDTLOG("==== Dump RGU Reg End ====\n");

		if (i < 60) {
			WDTLOG("kick lk ext\n");
			mtk_wdt_restart();
		}
	}
#endif
}

BOOL mtk_is_rgu_trigger_reset(void)
{
	if (is_rgu_trigger_rst)
		return TRUE;
	return FALSE;
}

extern BOOT_ARGUMENT *g_boot_arg;
int mtk_wdt_boot_check(void)
{
	int boot_reason;

	if (g_boot_arg->maggic_number == BOOT_ARGUMENT_MAGIC) {
		boot_reason = g_boot_arg->boot_reason;
		WDTLOG("WDT get boot reason is %d from pre-loader\n", boot_reason);

		if (boot_reason == BR_WDT) {
			return WDT_NORMAL_REBOOT;
		} else if (boot_reason == BR_WDT_BY_PASS_PWK || BR_KERNEL_PANIC == boot_reason || BR_WDT_SW == boot_reason || BR_WDT_HW == boot_reason) {
			return WDT_BY_PASS_PWK_REBOOT;
		} else {
			return WDT_NOT_WDT_REBOOT;
		}
	}

	return WDT_NOT_WDT_REBOOT;
}

void mtk_arch_reset(char mode)
{
	WDTLOG("mtk_arch_reset\n");

	mtk_wdt_reset(mode);

	while (1);
}

void mtk_arch_full_reset(void)
{
#ifdef MTK_PMIC_FULL_RESET

	/* save pl lk log to expdb before pmic full reset*/
	save_pllk_log();

	WDTCRI("mtk_arch_full_reset\n");

	/* PMIC full reset will happen (reset immediately) inside. */
	pmic_cold_reset();

	while (1);

#else

	WDTCRI("mtk_arch_full_reset: PMIC full reset is not supported.\n");

#endif
}

void wdt_check_exception(void)
{
	unsigned int reg = DRV_Reg32(MTK_WDT_NONRST_REG);

	DRV_WriteReg32(MTK_WDT_NONRST_REG, 0);
	if (((reg & (~MTK_WDT_STATUS_SWWDT_RST)) || DRV_Reg32(MTK_WDT_STATUS)) && (g_boot_mode != FASTBOOT))
		mtk_arch_full_reset();
}

void rgu_swsys_reset(WD_SYS_RST_TYPE reset_type)
{
	if (reset_type == WD_MD_RST) {
		unsigned int wdt_dbg_ctrl;

		wdt_dbg_ctrl = DRV_Reg32(MTK_WDT_SWSYSRST);
		wdt_dbg_ctrl |= MTK_WDT_SWSYS_RST_KEY;
		wdt_dbg_ctrl |= 0x80;/* 1<<7 */
		DRV_WriteReg32(MTK_WDT_SWSYSRST, wdt_dbg_ctrl);
		udelay(1000);
		wdt_dbg_ctrl = DRV_Reg32(MTK_WDT_SWSYSRST);
		wdt_dbg_ctrl |= MTK_WDT_SWSYS_RST_KEY;
		wdt_dbg_ctrl &= (~0x80);/* ~(1<<7) */
		DRV_WriteReg32(MTK_WDT_SWSYSRST, wdt_dbg_ctrl);
		dprintf(CRITICAL, "fwq rgu lk md reset\n");
	}
}

void rgu_release_rg_mcu_pwr_on(void)
{
	unsigned int wdt_dbg_ctrl;

	wdt_dbg_ctrl = DRV_Reg32(MTK_WDT_DEBUG_CTL);
	wdt_dbg_ctrl &= (~MTK_RG_MCU_PWR_ON);
	wdt_dbg_ctrl |= MTK_DEBUG_CTL_KEY;
	DRV_WriteReg32(MTK_WDT_DEBUG_CTL, wdt_dbg_ctrl);
	WDTLOG("RGU %s:MTK_WDT_DEBUG_CTL(%x)\n", __func__, wdt_dbg_ctrl);
}

void rgu_release_rg_mcu_pwr_iso_dis(void)
{
	unsigned int wdt_dbg_ctrl;

	wdt_dbg_ctrl = DRV_Reg32(MTK_WDT_DEBUG_CTL);
	wdt_dbg_ctrl &= (~MTK_RG_MCU_PWR_ISO_DIS);
	wdt_dbg_ctrl |= MTK_DEBUG_CTL_KEY;
	DRV_WriteReg32(MTK_WDT_DEBUG_CTL, wdt_dbg_ctrl);
	WDTLOG("RGU %s:MTK_WDT_DEBUG_CTL(%x)\n", __func__, wdt_dbg_ctrl);
}

#else
void mtk_wdt_init(void)
{
	WDTLOG("WDT Dummy init called\n");
}
BOOL mtk_is_rgu_trigger_reset(void)
{
	WDTLOG("Dummy mtk_is_rgu_trigger_reset called\n");
	return FALSE;
}
void mtk_arch_reset(char mode)
{
	WDTLOG("WDT Dummy arch reset called\n");
}

void mtk_arch_full_reset(void)
{
	WDTLOG("WDT Dummy arch full reset called\n");
}

void wdt_check_exception(void)
{
	WDTLOG("WDT Dummy check exception called\n");
}

int mtk_wdt_boot_check(void)
{
	WDTLOG("WDT Dummy mtk_wdt_boot_check called\n");
	return WDT_NOT_WDT_REBOOT;
}

unsigned char mtk_wdt_restart_reason()
{
	WDTLOG("WDT Dummy mtk_wdt_restart_reason called\n");
}

void mtk_wdt_disable(void)
{
	WDTLOG("WDT Dummy mtk_wdt_disable called\n");
}

const char *mtk_wdt_get_last_stage(void)
{
	return "rst from: not supported";
}

void mtk_wdt_restart(void)
{
	WDTLOG("WDT Dummy mtk_wdt_restart called\n");
}
static void mtk_wdt_sw_reset(void)
{
	WDTLOG("WDT Dummy mtk_wdt_sw_reset called\n");
}

static void mtk_wdt_hw_reset(void)
{
	WDTLOG("WDT Dummy mtk_wdt_hw_reset called\n");
}
void rgu_swsys_reset(WD_SYS_RST_TYPE reset_type)
{
	WDTLOG("WDT Dummy rgu_swsys_reset called\n");
}
void rgu_release_rg_mcu_pwr_on(void)
{
	WDTLOG("WDT Dummy %s called\n", __func__);
}
void rgu_release_rg_mcu_pwr_iso_dis(void)
{
	WDTLOG("WDT Dummy %s called\n", __func__);
}

#endif
