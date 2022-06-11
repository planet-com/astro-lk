/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2020. All rights reserved.
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


#include <platform/spm.h>
#include <platform/mt_gpt.h>

int spm_mtcmos_ctrl_md1(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off MD1" */
		/* TINFO="Set bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_SET, MD1_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1) & MD1_PROT_STEP1_0_ACK_MASK) != 
MD1_PROT_STEP1_0_ACK_MASK) {
		}
#endif
		/* TINFO="Set bus protect - step2 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_SET, MD1_PROT_STEP2_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_STA1) & MD1_PROT_STEP2_0_ACK_MASK) != 
MD1_PROT_STEP2_0_ACK_MASK) {
		}
#endif
		/* TINFO="Set PWR_ON = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~PWR_ON);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MD1_PWR_STA_MASK = 0" */
		while (spm_read(PWR_STATUS) & MD1_PWR_STA_MASK) {
				/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug
. */
		}
#endif
		/* TINFO="MD_EXT_BUCK_ISO_CON[0]=1"*/
		spm_write(MD_EXT_BUCK_ISO_CON, spm_read(MD_EXT_BUCK_ISO_CON) | (0x1 << 0));
		/* TINFO="MD_EXT_BUCK_ISO_CON[1]=1"*/
		spm_write(MD_EXT_BUCK_ISO_CON, spm_read(MD_EXT_BUCK_ISO_CON) | (0x1 << 1));
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Finish to turn off MD1" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on MD1" */
		/* TINFO="MD_EXT_BUCK_ISO_CON[0]=0"*/
		spm_write(MD_EXT_BUCK_ISO_CON, spm_read(MD_EXT_BUCK_ISO_CON) & ~(0x1 << 0));
		/* TINFO="MD_EXT_BUCK_ISO_CON[1]=0"*/
		spm_write(MD_EXT_BUCK_ISO_CON, spm_read(MD_EXT_BUCK_ISO_CON) & ~(0x1 << 1));
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) | PWR_RST_B);
		/* TINFO="Set PWR_ON = 1" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) | PWR_ON);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MD1_PWR_STA_MASK = 1" */
		while ((spm_read(PWR_STATUS) & MD1_PWR_STA_MASK) != MD1_PWR_STA_MASK) {
				/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug
. */
		}
#endif
		/* TINFO="Release bus protect - step2 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_INFRA_VDNR_CLR, MD1_PROT_STEP2_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Release bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_CLR, MD1_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Finish to turn on MD1" */
	}
	return err;
}

int spm_mtcmos_ctrl_mfg0(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off MFG0" */
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) | MFG0_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG0_SRAM_PDN_ACK = 1" */
		while ((spm_read(MFG0_PWR_CON) & MFG0_SRAM_PDN_ACK) != MFG0_SRAM_PDN_ACK) {
				/* Need f_fmfg_core_ck for SRAM PDN delay IP. */
		}
#endif
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) | PWR_ISO);
		/* TINFO="Set PWR_CLK_DIS = 1" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) | PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 0" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & MFG0_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & MFG0_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Finish to turn off MFG0" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on MFG0" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & MFG0_PWR_STA_MASK) != MFG0_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & MFG0_PWR_STA_MASK) != MFG0_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(MFG0_PWR_CON, spm_read(MFG0_PWR_CON) & ~(0x1 << 8));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG0_SRAM_PDN_ACK_BIT0 = 0" */
		while (spm_read(MFG0_PWR_CON) & MFG0_SRAM_PDN_ACK_BIT0) {
				/* Need f_fmfg_core_ck for SRAM PDN delay IP. */
		}
#endif
		/* TINFO="Finish to turn on MFG0" */
	}
	return err;
}

int spm_mtcmos_ctrl_mfg1(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off MFG1" */
		/* TINFO="Set bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_1_SET, MFG1_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1_1) & MFG1_PROT_STEP1_0_ACK_MASK) != MFG1_PROT_STEP1_0_ACK_MASK) {
		}
#endif
		/* TINFO="Set bus protect - step1 : 1" */
		spm_write(INFRA_TOPAXI_PROTECTEN_2_SET, MFG1_PROT_STEP1_1_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1_2) & MFG1_PROT_STEP1_1_ACK_MASK) != MFG1_PROT_STEP1_1_ACK_MASK) {
		}
#endif
		/* TINFO="Set bus protect - step2 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_SET, MFG1_PROT_STEP2_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1) & MFG1_PROT_STEP2_0_ACK_MASK) != MFG1_PROT_STEP2_0_ACK_MASK) {
		}
#endif
		/* TINFO="Set bus protect - step2 : 1" */
		spm_write(INFRA_TOPAXI_PROTECTEN_2_SET, MFG1_PROT_STEP2_1_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1_2) & MFG1_PROT_STEP2_1_ACK_MASK) != MFG1_PROT_STEP2_1_ACK_MASK) {
		}
#endif
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) | MFG1_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG1_SRAM_PDN_ACK = 1" */
		while ((spm_read(MFG1_PWR_CON) & MFG1_SRAM_PDN_ACK) != MFG1_SRAM_PDN_ACK) {
				/*  */
		}
#endif
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) | PWR_ISO);
		/* TINFO="Set PWR_CLK_DIS = 1" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) | PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 0" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & MFG1_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & MFG1_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Finish to turn off MFG1" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on MFG1" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & MFG1_PWR_STA_MASK) != MFG1_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & MFG1_PWR_STA_MASK) != MFG1_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(MFG1_PWR_CON, spm_read(MFG1_PWR_CON) & ~(0x1 << 8));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG1_SRAM_PDN_ACK_BIT0 = 0" */
		while (spm_read(MFG1_PWR_CON) & MFG1_SRAM_PDN_ACK_BIT0) {
				/*  */
		}
#endif
		/* TINFO="Release bus protect - step2 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_CLR, MFG1_PROT_STEP2_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Release bus protect - step2 : 1" */
		spm_write(INFRA_TOPAXI_PROTECTEN_2_CLR, MFG1_PROT_STEP2_1_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Release bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_1_CLR, MFG1_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Release bus protect - step1 : 1" */
		spm_write(INFRA_TOPAXI_PROTECTEN_2_CLR, MFG1_PROT_STEP1_1_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Finish to turn on MFG1" */
	}
	return err;
}

int spm_mtcmos_ctrl_mfg2(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off MFG2" */
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) | MFG2_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG2_SRAM_PDN_ACK = 1" */
		while ((spm_read(MFG2_PWR_CON) & MFG2_SRAM_PDN_ACK) != MFG2_SRAM_PDN_ACK) {
				/*  */
		}
#endif
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) | PWR_ISO);
		/* TINFO="Set PWR_CLK_DIS = 1" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) | PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 0" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & MFG2_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & MFG2_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Finish to turn off MFG2" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on MFG2" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & MFG2_PWR_STA_MASK) != MFG2_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & MFG2_PWR_STA_MASK) != MFG2_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(MFG2_PWR_CON, spm_read(MFG2_PWR_CON) & ~(0x1 << 8));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG2_SRAM_PDN_ACK_BIT0 = 0" */
		while (spm_read(MFG2_PWR_CON) & MFG2_SRAM_PDN_ACK_BIT0) {
				/*  */
		}
#endif
		/* TINFO="Finish to turn on MFG2" */
	}
	return err;
}

int spm_mtcmos_ctrl_mfg3(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off MFG3" */
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) | MFG3_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG3_SRAM_PDN_ACK = 1" */
		while ((spm_read(MFG3_PWR_CON) & MFG3_SRAM_PDN_ACK) != MFG3_SRAM_PDN_ACK) {
				/*  */
		}
#endif
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) | PWR_ISO);
		/* TINFO="Set PWR_CLK_DIS = 1" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) | PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 0" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & MFG3_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & MFG3_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Finish to turn off MFG3" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on MFG3" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & MFG3_PWR_STA_MASK) != MFG3_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & MFG3_PWR_STA_MASK) != MFG3_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(MFG3_PWR_CON, spm_read(MFG3_PWR_CON) & ~(0x1 << 8));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG3_SRAM_PDN_ACK_BIT0 = 0" */
		while (spm_read(MFG3_PWR_CON) & MFG3_SRAM_PDN_ACK_BIT0) {
				/*  */
		}
#endif
		/* TINFO="Finish to turn on MFG3" */
	}
	return err;
}

int spm_mtcmos_ctrl_mfg5(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off MFG5" */
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) | MFG5_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG5_SRAM_PDN_ACK = 1" */
		while ((spm_read(MFG5_PWR_CON) & MFG5_SRAM_PDN_ACK) != MFG5_SRAM_PDN_ACK) {
				/*  */
		}
#endif
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) | PWR_ISO);
		/* TINFO="Set PWR_CLK_DIS = 1" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) | PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 0" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & MFG5_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & MFG5_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Finish to turn off MFG5" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on MFG5" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & MFG5_PWR_STA_MASK) != MFG5_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & MFG5_PWR_STA_MASK) != MFG5_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. \\nPrint SRAM / MTCMOS control and\n PWR_ACK for debug. */
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(MFG5_PWR_CON, spm_read(MFG5_PWR_CON) & ~(0x1 << 8));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until MFG5_SRAM_PDN_ACK_BIT0 = 0" */
		while (spm_read(MFG5_PWR_CON) & MFG5_SRAM_PDN_ACK_BIT0) {
				/*  */
		}
#endif
		/* TINFO="Finish to turn on MFG5" */
	}
	return err;
}

int spm_mtcmos_ctrl_dis(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off DIS" */
		/* TINFO="Set bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_MM_SET, DIS_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_MM_STA1) & DIS_PROT_STEP1_0_ACK_MASK) != 
DIS_PROT_STEP1_0_ACK_MASK) {
		}
#endif
		/* TINFO="Set bus protect - step2 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_SET, DIS_PROT_STEP2_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1) & DIS_PROT_STEP2_0_ACK_MASK) != 
DIS_PROT_STEP2_0_ACK_MASK) {
		}
#endif
		/* TINFO="Set bus protect - step2 : 1" */
		spm_write(INFRA_TOPAXI_PROTECTEN_MM_SET, DIS_PROT_STEP2_1_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_MM_STA1) & DIS_PROT_STEP2_1_ACK_MASK) != 
DIS_PROT_STEP2_1_ACK_MASK) {
		}
#endif
		/* TINFO="Set bus protect - step2 : 2" */
		spm_write(INFRA_TOPAXI_PROTECTEN_MM_2_SET, DIS_PROT_STEP2_2_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_MM_2_STA1) & DIS_PROT_STEP2_2_ACK_MASK) != 
DIS_PROT_STEP2_2_ACK_MASK) {
		}
#endif
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | DIS_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until DIS_SRAM_PDN_ACK = 1" */
		while ((spm_read(DIS_PWR_CON) & DIS_SRAM_PDN_ACK) != DIS_SRAM_PDN_ACK) {
				/* Need hf_fmm_ck for SRAM PDN delay IP. */
		}
#endif
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | PWR_ISO);
		/* TINFO="Set PWR_CLK_DIS = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & DIS_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & DIS_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug
. */
		}
#endif
		/* TINFO="Finish to turn off DIS" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on DIS" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & DIS_PWR_STA_MASK) != DIS_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & DIS_PWR_STA_MASK) != DIS_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug
. */
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~(0x1 << 8));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until DIS_SRAM_PDN_ACK_BIT0 = 0" */
		while (spm_read(DIS_PWR_CON) & DIS_SRAM_PDN_ACK_BIT0) {
				/* Need hf_fmm_ck for SRAM PDN delay IP. */
		}
#endif
		/* TINFO="Release bus protect - step2 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_CLR, DIS_PROT_STEP2_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Release bus protect - step2 : 1" */
		spm_write(INFRA_TOPAXI_PROTECTEN_MM_CLR, DIS_PROT_STEP2_1_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Release bus protect - step2 : 2" */
		spm_write(INFRA_TOPAXI_PROTECTEN_MM_2_CLR, DIS_PROT_STEP2_2_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Release bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_MM_CLR, DIS_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Finish to turn on DIS" */
	}
	return err;
}

int spm_mtcmos_ctrl_adsp_dormant(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off ADSP" */
		/* TINFO="Set bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_2_SET, ADSP_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1_2) & ADSP_PROT_STEP1_0_ACK_MASK) != 
ADSP_PROT_STEP1_0_ACK_MASK) {
		}
#endif
		/* TINFO="Set SRAM_CKISO = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | SRAM_CKISO);
		/* TINFO="Set SRAM_ISOINT_B = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~SRAM_ISOINT_B);
		/* TINFO="Delay 1us" */
		udelay(1);
		/* TINFO="Set SRAM_SLEEP_B = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~ADSP_SRAM_SLEEP_B);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until ADSP_SRAM_SLEEP_B_ACK = 0" */
		while (spm_read(ADSP_PWR_CON) & ADSP_SRAM_SLEEP_B_ACK) {
				/* n/a */
		}
#endif
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_ISO);
		/* TINFO="Set PWR_CLK_DIS = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & ADSP_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & ADSP_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug
. */
		}
#endif
		/* TINFO="Finish to turn off ADSP" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on ADSP" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & ADSP_PWR_STA_MASK) != ADSP_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & ADSP_PWR_STA_MASK) != ADSP_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug
. */
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_SLEEP_B = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | (0x1 << 9));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until ADSP_SRAM_SLEEP_B_ACK_BIT0 = 1" */
		while ((spm_read(ADSP_PWR_CON) & ADSP_SRAM_SLEEP_B_ACK_BIT0) != ADSP_SRAM_SLEEP_B_ACK_BIT0
) {
				/* n/a */
		}
#endif
		/* TINFO="Delay 1us" */
		udelay(1);
		/* TINFO="Set SRAM_ISOINT_B = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | SRAM_ISOINT_B);
		/* TINFO="Delay 1us" */
		udelay(1);
		/* TINFO="Set SRAM_CKISO = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~SRAM_CKISO);
		/* TINFO="Release bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_2_CLR, ADSP_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Finish to turn on ADSP" */
	}
	return err;
}

int spm_mtcmos_ctrl_adsp_shut_down(int state)
{
	int err = 0;

	/* TINFO="enable SPM register control" */
	spm_write(POWERON_CONFIG_EN, (SPM_PROJECT_CODE << 16) | (0x1 << 0));

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off ADSP" */
		/* TINFO="Set bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_2_SET, ADSP_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1_2) & ADSP_PROT_STEP1_0_ACK_MASK) != 
ADSP_PROT_STEP1_0_ACK_MASK) {
		}
#endif
		/* TINFO="Set SRAM_CKISO = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | SRAM_CKISO);
		/* TINFO="Set SRAM_ISOINT_B = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~SRAM_ISOINT_B);
		/* TINFO="Delay 1us" */
		udelay(1);
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | ADSP_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until ADSP_SRAM_PDN_ACK = 1" */
		while ((spm_read(ADSP_PWR_CON) & ADSP_SRAM_PDN_ACK) != ADSP_SRAM_PDN_ACK) {
				/* Need f_f26M_aud_ck for SRAM PDN delay IP. */
		}
#endif
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_ISO);
		/* TINFO="Set PWR_CLK_DIS = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & ADSP_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & ADSP_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug
. */
		}
#endif
		/* TINFO="Finish to turn off ADSP" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on ADSP" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & ADSP_PWR_STA_MASK) != ADSP_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & ADSP_PWR_STA_MASK) != ADSP_PWR_STA_MASK)) {
				/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug
. */
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~(0x1 << 8));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until ADSP_SRAM_PDN_ACK_BIT0 = 0" */
		while (spm_read(ADSP_PWR_CON) & ADSP_SRAM_PDN_ACK_BIT0) {
				/* Need f_f26M_aud_ck for SRAM PDN delay IP. */
		}
#endif
		/* TINFO="Delay 1us" */
		udelay(1);
		/* TINFO="Set SRAM_ISOINT_B = 1" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) | SRAM_ISOINT_B);
		/* TINFO="Delay 1us" */
		udelay(1);
		/* TINFO="Set SRAM_CKISO = 0" */
		spm_write(ADSP_PWR_CON, spm_read(ADSP_PWR_CON) & ~SRAM_CKISO);
		/* TINFO="Release bus protect - step1 : 0" */
		spm_write(INFRA_TOPAXI_PROTECTEN_2_CLR, ADSP_PROT_STEP1_0_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Finish to turn on ADSP" */
	}
	return err;
}

