/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2019. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */
#ifndef __PMIF_H__
#define __PMIF_H__

#include <platform/mt_typedefs.h>

#define PMIF_CMD_REG_0		0
#define PMIF_CMD_REG		1
#define PMIF_CMD_EXT_REG	2
#define PMIF_CMD_EXT_REG_LONG	3

struct pmif {
	void *base;
	int *regs;
	int *dbgregs;
	void *spmimst_base;
	int *spmimst_regs;
	int swinf_ch_start;
	int swinf_no;
	int write;
	int mstid;
	int pmifid;
	int (*cmd)(struct pmif *arb, unsigned int opcode);
	int (*read_cmd)(struct pmif *arb, unsigned char opc,
		unsigned char sid, unsigned short addr,
		unsigned char *buf, unsigned short len);
	int (*write_cmd)(struct pmif *arb, unsigned char opc,
		unsigned char sid, unsigned short addr,
		const unsigned char *buf, unsigned short len);
	void (*pmif_enable_clk_set)(int mstid);
	void (*pmif_force_normal_mode)(int mstid);
	void (*pmif_enable_swinf)(int mstid, unsigned int chan_no,
							unsigned int swinf_no);
	void (*pmif_enable_cmdIssue)(int mstid, BOOL en);
	void (*pmif_enable)(int mstid);
	int (*is_pmif_init_done)(int mstid);
};

enum {
	PMIF_SPMI,
	PMIF_SPI
};
/* start external API */
extern struct pmif *get_pmif_controller(int inf, int mstid);
extern int is_pmif_spmi_init_done(int mstid);
extern int pmif_spmi_init(int mstid);

#endif /*__PMIF_H__*/
