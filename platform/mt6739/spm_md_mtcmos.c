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


#include <platform/spm.h>

int spm_mtcmos_ctrl_md1(int state)
{
	int err = 0;

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off MD1" */
		/* TINFO="Set bus protect" */
		spm_write(INFRA_TOPAXI_PROTECTEN_SET, MD1_PROT_BIT_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA0) & MD1_PROT_BIT_ACK_MASK) != MD1_PROT_BIT_ACK_MASK) {
			/*  */
			/*  */
		}
#endif
		/* TINFO="Set bus protect" */
		spm_write(INFRA_TOPAXI_PROTECTEN_1_SET, MD1_PROT_BIT_2ND_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA0_1) & MD1_PROT_BIT_ACK_2ND_MASK) !=
			MD1_PROT_BIT_ACK_2ND_MASK) {
			/*  */
			/*  */
		}
#endif
		/* TINFO="MD_EXTRA_PWR_CON[0]=1"*/
		spm_write(MD_EXTRA_PWR_CON, spm_read(MD_EXTRA_PWR_CON) | (0x1 << 0));
		/* TINFO="Set MD_PWR_CLK_DIS = 1" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) | MD_PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 1" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) | PWR_ISO);
		/* TINFO="MD_SRAM_ISO_CON[0]=0"*/
		spm_write(MD_SRAM_ISO_CON, spm_read(MD_SRAM_ISO_CON) & ~(0x1 << 0));
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) | MD1_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
#endif
		/* TINFO="Set PWR_ON = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 0 and PWR_STATUS_2ND = 0" */
		while ((spm_read(PWR_STATUS) & MD1_PWR_STA_MASK)
		       || (spm_read(PWR_STATUS_2ND) & MD1_PWR_STA_MASK)) {
		/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug. */
		}
#endif
    /* TINFO="Set PWR_RST_B = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Finish to turn off MD1" */
	} else {    /* STA_POWER_ON */
		/* TINFO="Start to turn on MD1" */
		/* TINFO="Set PWR_RST_B = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~PWR_RST_B);
		/* TINFO="Set PWR_ON = 1" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & MD1_PWR_STA_MASK) != MD1_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & MD1_PWR_STA_MASK) != MD1_PWR_STA_MASK)) {
		/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug. */
				/*	*/
				/*	*/
		}
#endif
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~(0x1 << 6));
		/* TINFO="MD_SRAM_ISO_CON[0]=1"*/
		spm_write(MD_SRAM_ISO_CON, spm_read(MD_SRAM_ISO_CON) | (0x1 << 0));
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set MD_PWR_CLK_DIS = 0" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) & ~MD_PWR_CLK_DIS);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(MD1_PWR_CON, spm_read(MD1_PWR_CON) | PWR_RST_B);
		/* TINFO="MD_EXTRA_PWR_CON[0]=0"*/
		spm_write(MD_EXTRA_PWR_CON, spm_read(MD_EXTRA_PWR_CON) & ~(0x1 << 0));
		/* TINFO="Release bus protect" */
		spm_write(INFRA_TOPAXI_PROTECTEN_1_CLR, MD1_PROT_BIT_2ND_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Release bus protect" */
		spm_write(INFRA_TOPAXI_PROTECTEN_CLR, MD1_PROT_BIT_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		udelay(250);
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Finish to turn on MD1" */
	}
	return err;
}

int spm_mtcmos_ctrl_dis(int state)
{
	int err = 0;

	if (state == STA_POWER_DOWN) {
		/* TINFO="Start to turn off DIS" */
		/* TINFO="Set bus protect" */
		spm_write(INFRA_TOPAXI_PROTECTEN_SET, DIS_PROT_BIT_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		while ((spm_read(INFRA_TOPAXI_PROTECTEN_STA1) & DIS_PROT_BIT_ACK_MASK) != DIS_PROT_BIT_ACK_MASK) {
			/*	*/
			/*	*/
		}
#endif
		/* TINFO="Set SRAM_PDN = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | DIS_SRAM_PDN);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until DIS_SRAM_PDN_ACK = 1" */
		while ((spm_read(DIS_PWR_CON) & DIS_SRAM_PDN_ACK) != DIS_SRAM_PDN_ACK) {
		/* Need hf_fmm_ck for SRAM PDN delay IP. */
		/*  */
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
		/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug. */
		/*	*/
		/*	*/
		}
#endif
		/* TINFO="Finish to turn off DIS" */
	} else {    /* STA_POWER_ON */
		if (((spm_read(PWR_STATUS) & DIS_PWR_STA_MASK) == DIS_PWR_STA_MASK)
		& ((spm_read(PWR_STATUS_2ND) & DIS_PWR_STA_MASK) == DIS_PWR_STA_MASK))
			return err;
		/* TINFO="Start to turn on DIS" */
		/* TINFO="Set PWR_ON = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | PWR_ON);
		/* TINFO="Set PWR_ON_2ND = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | PWR_ON_2ND);
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until PWR_STATUS = 1 and PWR_STATUS_2ND = 1" */
		while (((spm_read(PWR_STATUS) & DIS_PWR_STA_MASK) != DIS_PWR_STA_MASK)
		       || ((spm_read(PWR_STATUS_2ND) & DIS_PWR_STA_MASK) != DIS_PWR_STA_MASK)) {
		/* No logic between pwr_on and pwr_ack. Print SRAM / MTCMOS control and PWR_ACK for debug. */
		/*	*/
		/*	*/
		}
#endif
		/* TINFO="Set PWR_CLK_DIS = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~PWR_CLK_DIS);
		/* TINFO="Set PWR_ISO = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~PWR_ISO);
		/* TINFO="Set PWR_RST_B = 1" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) | PWR_RST_B);
		/* TINFO="Set SRAM_PDN = 0" */
		spm_write(DIS_PWR_CON, spm_read(DIS_PWR_CON) & ~(0x1 << 5));
#ifndef IGNORE_MTCMOS_CHECK
		/* TINFO="Wait until DIS_SRAM_PDN_ACK_BIT0 = 0" */
		while (spm_read(DIS_PWR_CON) & DIS_SRAM_PDN_ACK_BIT0) {
			/* Need hf_fmm_ck for SRAM PDN delay IP. */
			/*	*/
			/*	*/
		}

#endif
		/* TINFO="Release bus protect" */
		spm_write(INFRA_TOPAXI_PROTECTEN_CLR, DIS_PROT_BIT_MASK);
#ifndef IGNORE_MTCMOS_CHECK
		/* Note that this protect ack check after releasing protect has been ignored */
#endif
		/* TINFO="Finish to turn on DIS" */
	}
	return err;
}

