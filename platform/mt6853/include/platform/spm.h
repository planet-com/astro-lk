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

#ifndef _MT_SPM_
#define _MT_SPM_

#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>

#define SPM_BASE		SLEEP_BASE
/**************************************
 * Define and Declare
 **************************************/

#define SPM_REG(offset)		(SPM_BASE + offset)


#define POWERON_CONFIG_EN	SPM_REG(0x000)
#define PWR_STATUS		SPM_REG(0x16C)
#define PWR_STATUS_2ND		SPM_REG(0x170)
#define OTHER_PWR_STATUS	SPM_REG(0x178)	/* for MT6853 VPU only */

#define MD1_PWR_CON		SPM_REG(0x300)
#define MFG0_PWR_CON		SPM_REG(0x308)
#define MFG1_PWR_CON		SPM_REG(0x30C)
#define MFG2_PWR_CON		SPM_REG(0x310)
#define MFG3_PWR_CON		SPM_REG(0x314)
#define MFG5_PWR_CON		SPM_REG(0x31C)
#define DIS_PWR_CON		SPM_REG(0x350)
#define ADSP_PWR_CON		SPM_REG(0x358)

#define MD_EXT_BUCK_ISO_CON	SPM_REG(0x398)

#define INFRACFG_REG(offset)		(INFRACFG_AO_BASE + offset)
/* for MT6853 DISP/MDP MTCMOS on/off APIs  */
#define INFRA_TOPAXI_PROTECTEN				INFRACFG_REG(0x0220)
#define INFRA_TOPAXI_PROTECTEN_SET			INFRACFG_REG(0x02A0)
#define INFRA_TOPAXI_PROTECTEN_CLR			INFRACFG_REG(0x02A4)
#define INFRA_TOPAXI_PROTECTEN_STA0			INFRACFG_REG(0x0224)
#define INFRA_TOPAXI_PROTECTEN_STA1			INFRACFG_REG(0x0228)

#define INFRA_TOPAXI_PROTECTEN_1			INFRACFG_REG(0x0250)
#define INFRA_TOPAXI_PROTECTEN_1_SET			INFRACFG_REG(0x02A8)
#define INFRA_TOPAXI_PROTECTEN_1_CLR			INFRACFG_REG(0x02AC)
#define INFRA_TOPAXI_PROTECTEN_STA0_1			INFRACFG_REG(0x0254)
#define INFRA_TOPAXI_PROTECTEN_STA1_1			INFRACFG_REG(0x0258)

#define INFRA_TOPAXI_PROTECTEN_MCU			INFRACFG_REG(0x02C0)
#define INFRA_TOPAXI_PROTECTEN_MCU_STA0			INFRACFG_REG(0x02E0)
#define INFRA_TOPAXI_PROTECTEN_MCU_STA1			INFRACFG_REG(0x02E4)
#define INFRA_TOPAXI_PROTECTEN_MCU_SET			INFRACFG_REG(0x02C4)
#define INFRA_TOPAXI_PROTECTEN_MCU_CLR			INFRACFG_REG(0x02C8)

#define INFRA_TOPAXI_PROTECTEN_MM			INFRACFG_REG(0x02D0)
#define INFRA_TOPAXI_PROTECTEN_MM_SET			INFRACFG_REG(0x02D4)
#define INFRA_TOPAXI_PROTECTEN_MM_CLR			INFRACFG_REG(0x02D8)
#define INFRA_TOPAXI_PROTECTEN_MM_STA0			INFRACFG_REG(0x02E8)
#define INFRA_TOPAXI_PROTECTEN_MM_STA1			INFRACFG_REG(0x02EC)

#define INFRA_TOPAXI_PROTECTEN_2			INFRACFG_REG(0x0710)
#define INFRA_TOPAXI_PROTECTEN_2_SET			INFRACFG_REG(0x0714)
#define INFRA_TOPAXI_PROTECTEN_2_CLR			INFRACFG_REG(0x0718)
#define INFRA_TOPAXI_PROTECTEN_STA0_2			INFRACFG_REG(0x0720)
#define INFRA_TOPAXI_PROTECTEN_STA1_2			INFRACFG_REG(0x0724)

#define INFRA_TOPAXI_PROTECTEN_MM_2			INFRACFG_REG(0x0DC8)
#define INFRA_TOPAXI_PROTECTEN_MM_2_SET			INFRACFG_REG(0x0DCC)
#define INFRA_TOPAXI_PROTECTEN_MM_2_CLR			INFRACFG_REG(0x0DD0)
#define INFRA_TOPAXI_PROTECTEN_MM_2_STA0		INFRACFG_REG(0x0DD4)
#define INFRA_TOPAXI_PROTECTEN_MM_2_STA1		INFRACFG_REG(0x0DD8)

#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR		INFRACFG_REG(0x0B80)
#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_SET		INFRACFG_REG(0x0B84)
#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_CLR		INFRACFG_REG(0x0B88)
#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_STA0		INFRACFG_REG(0x0B8c)
#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_STA1		INFRACFG_REG(0x0B90)

#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_1		INFRACFG_REG(0x0BA0)
#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_1_SET		INFRACFG_REG(0x0BA4)
#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_1_CLR		INFRACFG_REG(0x0BA8)
#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_1_STA0	INFRACFG_REG(0x0BAc)
#define INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_1_STA1	INFRACFG_REG(0x0BB0)

/**************************************
 * Macro and Inline
 **************************************/
#define spm_read(addr)          DRV_Reg32(addr)
#define spm_write(addr, val)        DRV_WriteReg32(addr, val)

#define  SPM_PROJECT_CODE    0xB16

/* Define MTCMOS power control */
#define PWR_RST_B		(0x1 << 0)
#define PWR_ISO			(0x1 << 1)
#define PWR_ON			(0x1 << 2)
#define PWR_ON_2ND		(0x1 << 3)
#define PWR_CLK_DIS		(0x1 << 4)
#define SRAM_CKISO		(0x1 << 5)
#define SRAM_ISOINT_B		(0x1 << 6)
#define SLPB_CLAMP		(0x1 << 7)



/* Define MTCMOS Bus Protect Mask */
#define MD1_PROT_STEP1_0_MASK		((0x1 << 7))
#define MD1_PROT_STEP1_0_ACK_MASK	((0x1 << 7))
#define MD1_PROT_STEP2_0_MASK		((0x1 << 2) \
					|(0x1 << 12) \
					|(0x1 << 20))
#define MD1_PROT_STEP2_0_ACK_MASK	((0x1 << 2) \
					|(0x1 << 12) \
					|(0x1 << 20))

#define MFG1_PROT_STEP1_0_MASK           ((0x1 << 21))
#define MFG1_PROT_STEP1_0_ACK_MASK       ((0x1 << 21))
#define MFG1_PROT_STEP1_1_MASK           ((0x1 << 5) \
            |(0x1 << 6))
#define MFG1_PROT_STEP1_1_ACK_MASK       ((0x1 << 5) \
            |(0x1 << 6))
#define MFG1_PROT_STEP2_0_MASK           ((0x1 << 21) \
            |(0x1 << 22))
#define MFG1_PROT_STEP2_0_ACK_MASK       ((0x1 << 21) \
            |(0x1 << 22))
#define MFG1_PROT_STEP2_1_MASK           ((0x1 << 7))
#define MFG1_PROT_STEP2_1_ACK_MASK       ((0x1 << 7))

#define DIS_PROT_STEP1_0_MASK		((0x1 << 10) \
					|(0x1 << 12))
#define DIS_PROT_STEP1_0_ACK_MASK	((0x1 << 10) \
					|(0x1 << 12))
#define DIS_PROT_STEP2_0_MASK		((0x1 << 6) \
					|(0x1 << 23))
#define DIS_PROT_STEP2_0_ACK_MASK	((0x1 << 6) \
					|(0x1 << 23))
#define DIS_PROT_STEP2_1_MASK		((0x1 << 1) \
					|(0x1 << 3) \
					|(0x1 << 17) \
					|(0x1 << 25) \
					|(0x1 << 27))
#define DIS_PROT_STEP2_1_ACK_MASK	((0x1 << 1) \
					|(0x1 << 3) \
					|(0x1 << 17) \
					|(0x1 << 25) \
					|(0x1 << 27))
#define DIS_PROT_STEP2_2_MASK		((0x1 << 9))
#define DIS_PROT_STEP2_2_ACK_MASK	((0x1 << 9))

#define ADSP_PROT_STEP1_0_MASK		((0x1 << 3))
#define ADSP_PROT_STEP1_0_ACK_MASK	((0x1 << 3))


/* Define MTCMOS Power Status Mask */
#define MD1_PWR_STA_MASK                 (0x1 << 0)
#define MFG0_PWR_STA_MASK                (0x1 << 2)
#define MFG1_PWR_STA_MASK                (0x1 << 3)
#define MFG2_PWR_STA_MASK                (0x1 << 4)
#define MFG3_PWR_STA_MASK                (0x1 << 5)
#define MFG5_PWR_STA_MASK                (0x1 << 7)
#define DIS_PWR_STA_MASK                 (0x1 << 20)
#define ADSP_PWR_STA_MASK                (0x1 << 22)

/* Define CPU SRAM Mask */

/* Define Non-CPU SRAM Mask */
#define MD1_SRAM_PDN                     (0x1 << 8)
#define MD1_SRAM_PDN_ACK                 (0x0 << 12)
#define MD1_SRAM_PDN_ACK_BIT0            (0x1 << 12)
#define MFG0_SRAM_PDN                    (0x1 << 8)
#define MFG0_SRAM_PDN_ACK                (0x1 << 12)
#define MFG0_SRAM_PDN_ACK_BIT0           (0x1 << 12)
#define MFG1_SRAM_PDN                    (0x1 << 8)
#define MFG1_SRAM_PDN_ACK                (0x1 << 12)
#define MFG1_SRAM_PDN_ACK_BIT0           (0x1 << 12)
#define MFG2_SRAM_PDN                    (0x1 << 8)
#define MFG2_SRAM_PDN_ACK                (0x1 << 12)
#define MFG2_SRAM_PDN_ACK_BIT0           (0x1 << 12)
#define MFG3_SRAM_PDN                    (0x1 << 8)
#define MFG3_SRAM_PDN_ACK                (0x1 << 12)
#define MFG3_SRAM_PDN_ACK_BIT0           (0x1 << 12)
#define MFG5_SRAM_PDN                    (0x1 << 8)
#define MFG5_SRAM_PDN_ACK                (0x1 << 12)
#define MFG5_SRAM_PDN_ACK_BIT0           (0x1 << 12)
#define DIS_SRAM_PDN                     (0x1 << 8)
#define DIS_SRAM_PDN_ACK                 (0x1 << 12)
#define DIS_SRAM_PDN_ACK_BIT0            (0x1 << 12)
#define ADSP_SRAM_PDN                    (0x1 << 8)
#define ADSP_SRAM_PDN_ACK                (0x1 << 12)
#define ADSP_SRAM_PDN_ACK_BIT0           (0x1 << 12)
#define ADSP_SRAM_SLEEP_B                (0x1 << 9)
#define ADSP_SRAM_SLEEP_B_ACK            (0x1 << 13)
#define ADSP_SRAM_SLEEP_B_ACK_BIT0       (0x1 << 13)

#define STA_POWER_DOWN  0
#define STA_POWER_ON    1

extern int spm_mtcmos_ctrl_md1(int state);
extern int spm_mtcmos_ctrl_mfg0(int state);
extern int spm_mtcmos_ctrl_mfg1(int state);
extern int spm_mtcmos_ctrl_mfg2(int state);
extern int spm_mtcmos_ctrl_mfg3(int state);
extern int spm_mtcmos_ctrl_mfg5(int state);
extern int spm_mtcmos_ctrl_dis(int state);
extern int spm_mtcmos_ctrl_adsp_shut_down(int state);
extern int spm_mtcmos_ctrl_adsp_dormant(int state);
#endif
