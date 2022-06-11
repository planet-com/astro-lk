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

#ifndef __MTK_WDT_H__
#define __MTK_WDT_H__

#define ENABLE_WDT_MODULE       (1) // Module switch

/*
 * NO_WDT is defined in rules.mk if DEVELOP_STAGE is set
 * as FPGA.
 */
#ifndef NO_WDT
	#define WDT_ENABLED
#endif

#define MTK_WDT_BASE            TOPRGU_BASE

#define MTK_WDT_MODE            (MTK_WDT_BASE+0x0000)
#define MTK_WDT_IRQ_CLR         (MTK_WDT_MODE)
#define MTK_WDT_LENGTH          (MTK_WDT_BASE+0x0004)
#define MTK_WDT_RESTART         (MTK_WDT_BASE+0x0008)
#define MTK_WDT_STATUS          (MTK_WDT_BASE+0x000C)
#define MTK_WDT_INTERVAL        (MTK_WDT_BASE+0x0010)
#define MTK_WDT_SWRST           (MTK_WDT_BASE+0x0014)
#define MTK_WDT_SWSYSRST        (MTK_WDT_BASE+0x0018)
#define MTK_WDT_NONRST_REG      (MTK_WDT_BASE+0x0020)
#define MTK_WDT_NONRST_REG2     (MTK_WDT_BASE+0x0024)
#define MTK_WDT_REQ_MODE        (MTK_WDT_BASE+0x0030)
#define MTK_WDT_REQ_IRQ_EN      (MTK_WDT_BASE+0x0034)
#define MTK_WDT_EXT_REQ_CON     (MTK_WDT_BASE+0x0038)
#define MTK_WDT_DEBUG_CTL       (MTK_WDT_BASE+0x0040)
#define MTK_WDT_LATCH_CTL       (MTK_WDT_BASE+0x0044)
#define MTK_WDT_LATCH_CTL2      (MTK_WDT_BASE+0x0048)
#define MTK_WDT_SYSDBG_DEG_EN1  (MTK_WDT_BASE+0x0088)
#define MTK_WDT_SYSDBG_DEG_EN2  (MTK_WDT_BASE+0x008C)

/*WDT_MODE*/
#define MTK_WDT_MODE_KEYMASK        (0xff00)
#define MTK_WDT_MODE_KEY            (0x22000000)

#define MTK_WDT_MODE_DUAL_MODE      (0x0040)
#define MTK_WDT_MODE_IRQ_LEVEL_EN   (0x0020)
/*
 * MTK_WDT_MODE_AUTO_RESTART is replaced by MTK_WDT_NONRST2_BYPASS_PWR_KEY
 * of NONRST_REG2 for common kernel projects and two stage timeout design
 */
#define MTK_WDT_MODE_EXTRA_CNT      (0x0010)
#define MTK_WDT_MODE_IRQ            (0x0008)
#define MTK_WDT_MODE_EXTEN          (0x0004)
#define MTK_WDT_MODE_EXT_POL        (0x0002)
#define MTK_WDT_MODE_ENABLE         (0x0001)

/*WDT_IRQ_CLR*/
#define MTK_WDT_IRQ_CLR_KEY        (0x23000000)
#define MTK_WDT_IRQ_CLR_MASK       (0x1FF)
/* clear WDT_STATUS [4~0] */
#define MTK_WDT_IRQ_CLR_EXTB       (1 << 0)
/* clear WDT_STATUS [17~16] */
#define MTK_WDT_IRQ_CLR_EXT        (1 << 1)
/* clear WDT_STATUS [28] */
#define MTK_WDT_IRQ_CLR_SEJ        (1 << 2)
/* clear WDT_STATUS [29] */
#define MTK_WDT_IRQ_CLR_IRQ_STS    (1 << 3)
/* clear WDT_STATUS [30] */
#define MTK_WDT_IRQ_CLR_SW_WDT     (1 << 4)
/* clear WDT_STATUS [31] */
#define MTK_WDT_IRQ_CLR_WDT_STS    (1 << 5)
/* clear event_b to SPM */
#define MTK_WDT_IRQ_CLR_WAKE_UP    (1 << 6)
/* deassert wdt irq */
#define MTK_WDT_IRQ_CLR_DEASSERT   (1 << 7)
#define MTK_WDT_IRQ_CLR_DEBUGSYS   (1 << 8)

/*WDT_LENGTH*/
#define MTK_WDT_LENGTH_TIME_OUT     (0xffe0)
#define MTK_WDT_LENGTH_KEYMASK      (0x001f)
#define MTK_WDT_LENGTH_KEY      (0x0008)
#define MTK_WDT_LENGTH_CTL_KEY		(0x95<<24)

/*WDT_RESTART*/
#define MTK_WDT_RESTART_KEY     (0x1971)

/*WDT_STATUS*/
#define MTK_WDT_STATUS_HWWDT_RST    (0x80000000)
#define MTK_WDT_STATUS_SWWDT_RST    (0x40000000)
#define MTK_WDT_STATUS_IRQWDT_RST   (0x20000000)
#define MTK_WDT_STATUS_DEBUGWDT_RST (0x00080000)
#define MTK_WDT_STATUS_SPMWDT_RST         (0x0002)
#define MTK_WDT_STATUS_SPM_THERMAL_RST    (0x0001)
#define MTK_WDT_STATUS_THERMAL_DIRECT_RST (1<<18)
#define MTK_WDT_STATUS_SECURITY_RST       (1<<28)
#define MTK_WDT_STATUS_EINT_RST           (1<<2)
#define MTK_WDT_STATUS_SYSRST_RST         (1<<3)
#define MTK_WDT_STATUS_DVFSP_RST          (1<<4)
#define MTK_WDT_STATUS_SSPM_RST           (1<<16)
#define MTK_WDT_STATUS_MDDBG_RST          (1<<17)

/*WDT_INTERVAL*/
#define MTK_WDT_INTERVAL_MASK       (0x0fff)

/*WDT_SWRST*/
#define MTK_WDT_SWRST_KEY       (0x1209)

/*WDT_SWSYSRST*/
#define MTK_WDT_SWSYS_RST_PWRAP_SPI_CTL_RST (0x0800)
#define MTK_WDT_SWSYS_RST_APMIXED_RST   (0x0400)
#define MTK_WDT_SWSYS_RST_MD_LITE_RST   (0x0200)
#define MTK_WDT_SWSYS_RST_INFRA_AO_RST  (0x0100)
#define MTK_WDT_SWSYS_RST_MD_RST    (0x0080)
#define MTK_WDT_SWSYS_RST_DDRPHY_RST    (0x0040)
#define MTK_WDT_SWSYS_RST_IMG_RST   (0x0020)
#define MTK_WDT_SWSYS_RST_VDEC_RST  (0x0010)
#define MTK_WDT_SWSYS_RST_VENC_RST  (0x0008)
#define MTK_WDT_SWSYS_RST_MFG_RST   (0x0004)
#define MTK_WDT_SWSYS_RST_GPU_RST   MTK_WDT_SWSYS_RST_MFG_RST
#define MTK_WDT_SWSYS_RST_DISP_RST  (0x0002)
#define MTK_WDT_SWSYS_RST_INFRA_RST (0x0001)
#define MTK_WDT_SWSYS_RST_KEY       (0x88000000)

/* Reboot source */
#define RGU_STAGE_MASK      (0x7)
#define RGU_STAGE_PRELOADER (0x1)
#define RGU_STAGE_LK        (0x2)
#define RGU_STAGE_KERNEL    (0x3)
#define RGU_STAGE_DA        (0x4)

/* WDT_NONRST_REG2 */
#define MTK_WDT_NONRST2_BYPASS_PWR_KEY	(1 << 13)
#define MTK_WDT_NONRST2_STAGE_OFS      (29) /* 31:29: 3-bits for current stage */
#define MTK_WDT_NONRST2_LAST_STAGE_OFS (26) /* 28:26: 3-bits for last stage */
/* used for DA tool to enter fastboot via setting rgu bit */
#define MTK_WDT_NONRST2_BOOT_MASK	(0xF)
#define MTK_WDT_NONRST2_BOOT_CHARGER	1
#define MTK_WDT_NONRST2_BOOT_RECOVERY	2
#define MTK_WDT_NONRST2_BOOT_BOOTLOADER	3
#define MTK_WDT_NONRST2_BOOT_DM_VERITY	4
#define MTK_WDT_NONRST2_BOOT_KPOC	5
#define MTK_WDT_NONRST2_BOOT_DDR_RSVD	6
#define MTK_WDT_NONRST2_BOOT_META	7
#define MTK_WDT_NONRST2_BOOT_RPMBPK	8

/*MTK_WDT_REQ_IRQ*/
#define MTK_WDT_REQ_IRQ_KEY     (0x44000000)
#define MTK_WDT_REQ_IRQ_DEBUG_EN        (0x80000)
#define MTK_WDT_REQ_IRQ_SPM_THERMAL_EN      (0x0001)
#define MTK_WDT_REQ_IRQ_SPM_SCPSYS_EN       (0x0002)
#define MTK_WDT_REQ_IRQ_THERMAL_EN      (1<<18)

/*MTK_WDT_REQ_MODE*/
#define MTK_WDT_REQ_MODE_KEY        (0x33000000)
#define MTK_WDT_REQ_MODE_DEBUG_EN       (0x80000)
#define MTK_WDT_REQ_MODE_SPM_THERMAL        (0x0001)
#define MTK_WDT_REQ_MODE_SPM_SCPSYS     (0x0002)
#define MTK_WDT_REQ_MODE_THERMAL        (1<<18)

/*MTK_WDT_EXT_REQ_CON*/
#define MTK_WDT_EXT_EINT_SHF        (4)
#define MTK_WDT_EXT_EINT_MASK       (0xF << MTK_WDT_EXT_EINT_SHF)
#define MTK_WDT_EXT_EINT_EN         (1)

//MTK_WDT_DEBUG_CTL
#define MTK_DEBUG_CTL_KEY           (0x59000000)
#define MTK_RG_MCU_PWR_ON           (0x1000)
#define MTK_RG_MCU_PWR_ISO_DIS      (0x2000)

/*MTK_WDT_LATCH_CTL2*/
#define MTK_WDT_LATCH_CTL2_DFD_EN   (1<<17)
#define MTK_WDT_LATCH_CTL2_KEY      (0x95<<24)

#define WDT_NORMAL_REBOOT       (0x01)
#define WDT_BY_PASS_PWK_REBOOT      (0x02)
#define WDT_NOT_WDT_REBOOT      (0x00)

/*MTK_WDT_SYSDBG_DEG_EN*/
#define MTK_WDT_SYSDBG_DEG_EN1_KEY		(0x1b2a)
#define MTK_WDT_SYSDBG_DEG_EN2_KEY		(0x4f59)

typedef enum wd_swsys_reset_type {
	WD_MD_RST,
} WD_SYS_RST_TYPE;

typedef enum wk_req_en {
    WD_REQ_DIS,
    WD_REQ_EN,
} WD_REQ_CTL;

typedef enum wk_req_mode {
    WD_REQ_IRQ_MODE,
    WD_REQ_RST_MODE,
} WD_REQ_MODE;

void        mtk_wdt_doe_setup(void);
void        mtk_wdt_disable(void);
const char *mtk_wdt_get_last_stage(void);
void        mtk_wdt_restart(void);
void        mtk_wdt_select_eint(unsigned int ext_debugkey_io_eint);
int         mtk_wdt_request_en_set(int mark_bit, WD_REQ_CTL en);
int         mtk_wdt_request_mode_set(int mark_bit, WD_REQ_MODE mode);
int         mtk_wdt_swsysret_config(int bit, int set_value);
extern void mtk_wdt_init(void);
extern BOOL mtk_is_rgu_trigger_reset(void);
extern void mtk_arch_reset(char mode);
extern void mtk_arch_full_reset(void);
void        wdt_check_exception(void);
void        rgu_swsys_reset(WD_SYS_RST_TYPE reset_type);
void        rgu_release_rg_mcu_pwr_on(void);
void        rgu_release_rg_mcu_pwr_iso_dis(void);
unsigned char mtk_wdt_restart_reason();
void        mtk_wdt_set_time_out_value(UINT32 value);
#ifdef MTK_ENTER_FASTBOOT_VIA_RGU
int mtk_wdt_fastboot_check(void);
void mtk_wdt_fastboot_set(int fastboot_en);
#endif
#endif   /*__MTK_WDT_H__*/
