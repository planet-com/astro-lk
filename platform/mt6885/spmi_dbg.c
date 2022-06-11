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
/*
 * MTK SPMI Driver
 *
 * Copyright 2018 MediaTek Co.,Ltd.
 *
 * DESCRIPTION:
 *     This file provides API for other drivers to access PMIC registers
 *
 */
#include <pmif.h>
#include <spmi.h>
#include <spmi_sw.h>
#include <pmif_sw.h>
#include <mt6315_upmu_hw.h>

#if !SPMI_NO_PMIC

#if (SPMI_CTP)
#define sprintf FormatString
#endif

enum pmif_dbg_regs {
	PMIF_INIT_DONE,
	PMIF_INF_BUSY_STA,
	PMIF_OTHER_BUSY_STA_0,
	PMIF_OTHER_BUSY_STA_1,
	PMIF_IRQ_EVENT_EN_0,
	PMIF_IRQ_FLAG_0,
	PMIF_IRQ_CLR_0,
	PMIF_IRQ_EVENT_EN_1,
	PMIF_IRQ_FLAG_1,
	PMIF_IRQ_CLR_1,
	PMIF_IRQ_EVENT_EN_2,
	PMIF_IRQ_FLAG_2,
	PMIF_IRQ_CLR_2,
	PMIF_IRQ_EVENT_EN_3,
	PMIF_IRQ_FLAG_3,
	PMIF_IRQ_CLR_3,
	PMIF_IRQ_EVENT_EN_4,
	PMIF_IRQ_FLAG_4,
	PMIF_IRQ_CLR_4,
	PMIF_WDT_EVENT_EN_0,
	PMIF_WDT_FLAG_0,
	PMIF_WDT_EVENT_EN_1,
	PMIF_WDT_FLAG_1,
	PMIF_MONITOR_CTRL,
	PMIF_MONITOR_TARGET_CHAN_0,
	PMIF_MONITOR_TARGET_CHAN_1,
	PMIF_MONITOR_TARGET_CHAN_2,
	PMIF_MONITOR_TARGET_CHAN_3,
	PMIF_MONITOR_TARGET_CHAN_4,
	PMIF_MONITOR_TARGET_CHAN_5,
	PMIF_MONITOR_TARGET_CHAN_6,
	PMIF_MONITOR_TARGET_CHAN_7,
	PMIF_MONITOR_TARGET_WRITE,
	PMIF_MONITOR_TARGET_ADDR_0,
	PMIF_MONITOR_TARGET_ADDR_1,
	PMIF_MONITOR_TARGET_ADDR_2,
	PMIF_MONITOR_TARGET_ADDR_3,
	PMIF_MONITOR_TARGET_ADDR_4,
	PMIF_MONITOR_TARGET_ADDR_5,
	PMIF_MONITOR_TARGET_ADDR_6,
	PMIF_MONITOR_TARGET_ADDR_7,
	PMIF_MONITOR_TARGET_WDATA_0,
	PMIF_MONITOR_TARGET_WDATA_1,
	PMIF_MONITOR_TARGET_WDATA_2,
	PMIF_MONITOR_TARGET_WDATA_3,
	PMIF_MONITOR_TARGET_WDATA_4,
	PMIF_MONITOR_TARGET_WDATA_5,
	PMIF_MONITOR_TARGET_WDATA_6,
	PMIF_MONITOR_TARGET_WDATA_7,
	PMIF_MONITOR_STA,
	PMIF_MONITOR_RECORD_0_0,
	PMIF_MONITOR_RECORD_0_1,
	PMIF_MONITOR_RECORD_0_2,
	PMIF_MONITOR_RECORD_0_3,
	PMIF_MONITOR_RECORD_0_4,
	PMIF_MONITOR_RECORD_1_0,
	PMIF_MONITOR_RECORD_1_1,
	PMIF_MONITOR_RECORD_1_2,
	PMIF_MONITOR_RECORD_1_3,
	PMIF_MONITOR_RECORD_1_4,
	PMIF_MONITOR_RECORD_2_0,
	PMIF_MONITOR_RECORD_2_1,
	PMIF_MONITOR_RECORD_2_2,
	PMIF_MONITOR_RECORD_2_3,
	PMIF_MONITOR_RECORD_2_4,
	PMIF_MONITOR_RECORD_3_0,
	PMIF_MONITOR_RECORD_3_1,
	PMIF_MONITOR_RECORD_3_2,
	PMIF_MONITOR_RECORD_3_3,
	PMIF_MONITOR_RECORD_3_4,
	PMIF_MONITOR_RECORD_4_0,
	PMIF_MONITOR_RECORD_4_1,
	PMIF_MONITOR_RECORD_4_2,
	PMIF_MONITOR_RECORD_4_3,
	PMIF_MONITOR_RECORD_4_4,
	PMIF_MONITOR_RECORD_5_0,
	PMIF_MONITOR_RECORD_5_1,
	PMIF_MONITOR_RECORD_5_2,
	PMIF_MONITOR_RECORD_5_3,
	PMIF_MONITOR_RECORD_5_4,
	PMIF_MONITOR_RECORD_6_0,
	PMIF_MONITOR_RECORD_6_1,
	PMIF_MONITOR_RECORD_6_2,
	PMIF_MONITOR_RECORD_6_3,
	PMIF_MONITOR_RECORD_6_4,
	PMIF_MONITOR_RECORD_7_0,
	PMIF_MONITOR_RECORD_7_1,
	PMIF_MONITOR_RECORD_7_2,
	PMIF_MONITOR_RECORD_7_3,
	PMIF_MONITOR_RECORD_7_4,
	PMIF_MONITOR_RECORD_8_0,
	PMIF_MONITOR_RECORD_8_1,
	PMIF_MONITOR_RECORD_8_2,
	PMIF_MONITOR_RECORD_8_3,
	PMIF_MONITOR_RECORD_8_4,
	PMIF_MONITOR_RECORD_9_0,
	PMIF_MONITOR_RECORD_9_1,
	PMIF_MONITOR_RECORD_9_2,
	PMIF_MONITOR_RECORD_9_3,
	PMIF_MONITOR_RECORD_9_4,
	PMIF_MONITOR_RECORD_10_0,
	PMIF_MONITOR_RECORD_10_1,
	PMIF_MONITOR_RECORD_10_2,
	PMIF_MONITOR_RECORD_10_3,
	PMIF_MONITOR_RECORD_10_4,
	PMIF_MONITOR_RECORD_11_0,
	PMIF_MONITOR_RECORD_11_1,
	PMIF_MONITOR_RECORD_11_2,
	PMIF_MONITOR_RECORD_11_3,
	PMIF_MONITOR_RECORD_11_4,
	PMIF_MONITOR_RECORD_12_0,
	PMIF_MONITOR_RECORD_12_1,
	PMIF_MONITOR_RECORD_12_2,
	PMIF_MONITOR_RECORD_12_3,
	PMIF_MONITOR_RECORD_12_4,
	PMIF_MONITOR_RECORD_13_0,
	PMIF_MONITOR_RECORD_13_1,
	PMIF_MONITOR_RECORD_13_2,
	PMIF_MONITOR_RECORD_13_3,
	PMIF_MONITOR_RECORD_13_4,
	PMIF_MONITOR_RECORD_14_0,
	PMIF_MONITOR_RECORD_14_1,
	PMIF_MONITOR_RECORD_14_2,
	PMIF_MONITOR_RECORD_14_3,
	PMIF_MONITOR_RECORD_14_4,
	PMIF_MONITOR_RECORD_15_0,
	PMIF_MONITOR_RECORD_15_1,
	PMIF_MONITOR_RECORD_15_2,
	PMIF_MONITOR_RECORD_15_3,
	PMIF_MONITOR_RECORD_15_4,
	PMIF_MONITOR_RECORD_16_0,
	PMIF_MONITOR_RECORD_16_1,
	PMIF_MONITOR_RECORD_16_2,
	PMIF_MONITOR_RECORD_16_3,
	PMIF_MONITOR_RECORD_16_4,
	PMIF_MONITOR_RECORD_17_0,
	PMIF_MONITOR_RECORD_17_1,
	PMIF_MONITOR_RECORD_17_2,
	PMIF_MONITOR_RECORD_17_3,
	PMIF_MONITOR_RECORD_17_4,
	PMIF_MONITOR_RECORD_18_0,
	PMIF_MONITOR_RECORD_18_1,
	PMIF_MONITOR_RECORD_18_2,
	PMIF_MONITOR_RECORD_18_3,
	PMIF_MONITOR_RECORD_18_4,
	PMIF_MONITOR_RECORD_19_0,
	PMIF_MONITOR_RECORD_19_1,
	PMIF_MONITOR_RECORD_19_2,
	PMIF_MONITOR_RECORD_19_3,
	PMIF_MONITOR_RECORD_19_4,
	PMIF_MONITOR_RECORD_20_0,
	PMIF_MONITOR_RECORD_20_1,
	PMIF_MONITOR_RECORD_20_2,
	PMIF_MONITOR_RECORD_20_3,
	PMIF_MONITOR_RECORD_20_4,
	PMIF_MONITOR_RECORD_21_0,
	PMIF_MONITOR_RECORD_21_1,
	PMIF_MONITOR_RECORD_21_2,
	PMIF_MONITOR_RECORD_21_3,
	PMIF_MONITOR_RECORD_21_4,
	PMIF_MONITOR_RECORD_22_0,
	PMIF_MONITOR_RECORD_22_1,
	PMIF_MONITOR_RECORD_22_2,
	PMIF_MONITOR_RECORD_22_3,
	PMIF_MONITOR_RECORD_22_4,
	PMIF_MONITOR_RECORD_23_0,
	PMIF_MONITOR_RECORD_23_1,
	PMIF_MONITOR_RECORD_23_2,
	PMIF_MONITOR_RECORD_23_3,
	PMIF_MONITOR_RECORD_23_4,
	PMIF_MONITOR_RECORD_24_0,
	PMIF_MONITOR_RECORD_24_1,
	PMIF_MONITOR_RECORD_24_2,
	PMIF_MONITOR_RECORD_24_3,
	PMIF_MONITOR_RECORD_24_4,
	PMIF_MONITOR_RECORD_25_0,
	PMIF_MONITOR_RECORD_25_1,
	PMIF_MONITOR_RECORD_25_2,
	PMIF_MONITOR_RECORD_25_3,
	PMIF_MONITOR_RECORD_25_4,
	PMIF_MONITOR_RECORD_26_0,
	PMIF_MONITOR_RECORD_26_1,
	PMIF_MONITOR_RECORD_26_2,
	PMIF_MONITOR_RECORD_26_3,
	PMIF_MONITOR_RECORD_26_4,
	PMIF_MONITOR_RECORD_27_0,
	PMIF_MONITOR_RECORD_27_1,
	PMIF_MONITOR_RECORD_27_2,
	PMIF_MONITOR_RECORD_27_3,
	PMIF_MONITOR_RECORD_27_4,
	PMIF_MONITOR_RECORD_28_0,
	PMIF_MONITOR_RECORD_28_1,
	PMIF_MONITOR_RECORD_28_2,
	PMIF_MONITOR_RECORD_28_3,
	PMIF_MONITOR_RECORD_28_4,
	PMIF_MONITOR_RECORD_29_0,
	PMIF_MONITOR_RECORD_29_1,
	PMIF_MONITOR_RECORD_29_2,
	PMIF_MONITOR_RECORD_29_3,
	PMIF_MONITOR_RECORD_29_4,
	PMIF_MONITOR_RECORD_30_0,
	PMIF_MONITOR_RECORD_30_1,
	PMIF_MONITOR_RECORD_30_2,
	PMIF_MONITOR_RECORD_30_3,
	PMIF_MONITOR_RECORD_30_4,
	PMIF_MONITOR_RECORD_31_0,
	PMIF_MONITOR_RECORD_31_1,
	PMIF_MONITOR_RECORD_31_2,
	PMIF_MONITOR_RECORD_31_3,
	PMIF_MONITOR_RECORD_31_4,
	PMIF_DEBUG_CTRL,
	PMIF_RESERVED_0,
	PMIF_SWINF_0_ACC,
	PMIF_SWINF_0_WDATA_31_0,
	PMIF_SWINF_0_WDATA_63_32,
	PMIF_SWINF_0_RDATA_31_0,
	PMIF_SWINF_0_RDATA_63_32,
	PMIF_SWINF_0_VLD_CLR,
	PMIF_SWINF_0_STA,
	PMIF_SWINF_1_ACC,
	PMIF_SWINF_1_WDATA_31_0,
	PMIF_SWINF_1_WDATA_63_32,
	PMIF_SWINF_1_RDATA_31_0,
	PMIF_SWINF_1_RDATA_63_32,
	PMIF_SWINF_1_VLD_CLR,
	PMIF_SWINF_1_STA,
	PMIF_SWINF_2_ACC,
	PMIF_SWINF_2_WDATA_31_0,
	PMIF_SWINF_2_WDATA_63_32,
	PMIF_SWINF_2_RDATA_31_0,
	PMIF_SWINF_2_RDATA_63_32,
	PMIF_SWINF_2_VLD_CLR,
	PMIF_SWINF_2_STA,
	PMIF_SWINF_3_ACC,
	PMIF_SWINF_3_WDATA_31_0,
	PMIF_SWINF_3_WDATA_63_32,
	PMIF_SWINF_3_RDATA_31_0,
	PMIF_SWINF_3_RDATA_63_32,
	PMIF_SWINF_3_VLD_CLR,
	PMIF_SWINF_3_STA,
};

static int mt6xxx_pmif_dbg_regs[] = {
	[PMIF_INIT_DONE] =			0x0000,
	[PMIF_INF_BUSY_STA] =			0x0018,
	[PMIF_OTHER_BUSY_STA_0] =		0x001C,
	[PMIF_OTHER_BUSY_STA_1] =		0x0020,
	[PMIF_IRQ_EVENT_EN_0] =                 0x0418,
	[PMIF_IRQ_FLAG_0] =                     0x0420,
	[PMIF_IRQ_CLR_0] =                      0x0424,
	[PMIF_IRQ_EVENT_EN_1] =                 0x0428,
	[PMIF_IRQ_FLAG_1] =                     0x0430,
	[PMIF_IRQ_CLR_1] =                      0x0434,
	[PMIF_IRQ_EVENT_EN_2] =                 0x0438,
	[PMIF_IRQ_FLAG_2] =                     0x0440,
	[PMIF_IRQ_CLR_2] =                      0x0444,
	[PMIF_IRQ_EVENT_EN_3] =                 0x0448,
	[PMIF_IRQ_FLAG_3] =                     0x0450,
	[PMIF_IRQ_CLR_3] =                      0x0454,
	[PMIF_IRQ_EVENT_EN_4] =                 0x0458,
	[PMIF_IRQ_FLAG_4] =                     0x0460,
	[PMIF_IRQ_CLR_4] =                      0x0464,
	[PMIF_WDT_EVENT_EN_0] =			0x046C,
	[PMIF_WDT_FLAG_0] =			0x0470,
	[PMIF_WDT_EVENT_EN_1] =         	0x0474,
	[PMIF_WDT_FLAG_1] =			0x0478,
	[PMIF_MONITOR_CTRL] =           	0x047C,
	[PMIF_MONITOR_TARGET_CHAN_0] =  	0x0480,
	[PMIF_MONITOR_TARGET_CHAN_1] =  	0x0484,
	[PMIF_MONITOR_TARGET_CHAN_2] =  	0x0488,
	[PMIF_MONITOR_TARGET_CHAN_3] =  	0x048C,
	[PMIF_MONITOR_TARGET_CHAN_4] =  	0x0490,
	[PMIF_MONITOR_TARGET_CHAN_5] =  	0x0494,
	[PMIF_MONITOR_TARGET_CHAN_6] =  	0x0498,
	[PMIF_MONITOR_TARGET_CHAN_7] =  	0x049C,
	[PMIF_MONITOR_TARGET_WRITE] =   	0x04A0,
	[PMIF_MONITOR_TARGET_ADDR_0] =  	0x04A4,
	[PMIF_MONITOR_TARGET_ADDR_1] =  	0x04A8,
	[PMIF_MONITOR_TARGET_ADDR_2] =  	0x04AC,
	[PMIF_MONITOR_TARGET_ADDR_3] =  	0x04B0,
	[PMIF_MONITOR_TARGET_ADDR_4] =  	0x04B4,
	[PMIF_MONITOR_TARGET_ADDR_5] =  	0x04B8,
	[PMIF_MONITOR_TARGET_ADDR_6] =  	0x04BC,
	[PMIF_MONITOR_TARGET_ADDR_7] =  	0x04C0,
	[PMIF_MONITOR_TARGET_WDATA_0] = 	0x04C4,
	[PMIF_MONITOR_TARGET_WDATA_1] = 	0x04C8,
	[PMIF_MONITOR_TARGET_WDATA_2] = 	0x04CC,
	[PMIF_MONITOR_TARGET_WDATA_3] = 	0x04D0,
	[PMIF_MONITOR_TARGET_WDATA_4] = 	0x04D4,
	[PMIF_MONITOR_TARGET_WDATA_5] = 	0x04D8,
	[PMIF_MONITOR_TARGET_WDATA_6] = 	0x04DC,
	[PMIF_MONITOR_TARGET_WDATA_7] = 	0x04E0,
	[PMIF_MONITOR_STA] =            	0x04E4,
	[PMIF_MONITOR_RECORD_0_0] =     	0x04E8,
	[PMIF_MONITOR_RECORD_0_1] =     	0x04EC,
	[PMIF_MONITOR_RECORD_0_2] =     	0x04F0,
	[PMIF_MONITOR_RECORD_0_3] =     	0x04F4,
	[PMIF_MONITOR_RECORD_0_4] =     	0x04F8,
	[PMIF_MONITOR_RECORD_1_0] =     	0x04FC,
	[PMIF_MONITOR_RECORD_1_1] =     	0x0500,
	[PMIF_MONITOR_RECORD_1_2] =     	0x0504,
	[PMIF_MONITOR_RECORD_1_3] =     	0x0508,
	[PMIF_MONITOR_RECORD_1_4] =     	0x050C,
	[PMIF_MONITOR_RECORD_2_0] =     	0x0510,
	[PMIF_MONITOR_RECORD_2_1] =     	0x0514,
	[PMIF_MONITOR_RECORD_2_2] =     	0x0518,
	[PMIF_MONITOR_RECORD_2_3] =     	0x051C,
	[PMIF_MONITOR_RECORD_2_4] =     	0x0520,
	[PMIF_MONITOR_RECORD_3_0] =     	0x0524,
	[PMIF_MONITOR_RECORD_3_1] =     	0x0528,
	[PMIF_MONITOR_RECORD_3_2] =     	0x052C,
	[PMIF_MONITOR_RECORD_3_3] =     	0x0530,
	[PMIF_MONITOR_RECORD_3_4] =     	0x0534,
	[PMIF_MONITOR_RECORD_4_0] =     	0x0538,
	[PMIF_MONITOR_RECORD_4_1] =     	0x053C,
	[PMIF_MONITOR_RECORD_4_2] =     	0x0540,
	[PMIF_MONITOR_RECORD_4_3] =     	0x0544,
	[PMIF_MONITOR_RECORD_4_4] =     	0x0548,
	[PMIF_MONITOR_RECORD_5_0] =     	0x054C,
	[PMIF_MONITOR_RECORD_5_1] =     	0x0550,
	[PMIF_MONITOR_RECORD_5_2] =     	0x0554,
	[PMIF_MONITOR_RECORD_5_3] =     	0x0558,
	[PMIF_MONITOR_RECORD_5_4] =     	0x055C,
	[PMIF_MONITOR_RECORD_6_0] =     	0x0560,
	[PMIF_MONITOR_RECORD_6_1] =     	0x0564,
	[PMIF_MONITOR_RECORD_6_2] =     	0x0568,
	[PMIF_MONITOR_RECORD_6_3] =     	0x056C,
	[PMIF_MONITOR_RECORD_6_4] =     	0x0570,
	[PMIF_MONITOR_RECORD_7_0] =     	0x0574,
	[PMIF_MONITOR_RECORD_7_1] =     	0x0578,
	[PMIF_MONITOR_RECORD_7_2] =     	0x057C,
	[PMIF_MONITOR_RECORD_7_3] =     	0x0580,
	[PMIF_MONITOR_RECORD_7_4] =		0x0584,
	[PMIF_MONITOR_RECORD_8_0] =	     	0x0588,
	[PMIF_MONITOR_RECORD_8_1] =     	0x058C,
	[PMIF_MONITOR_RECORD_8_2] =     	0x0590,
	[PMIF_MONITOR_RECORD_8_3] =     	0x0594,
	[PMIF_MONITOR_RECORD_8_4] =     	0x0598,
	[PMIF_MONITOR_RECORD_9_0] =     	0x059C,
	[PMIF_MONITOR_RECORD_9_1] =     	0x05A0,
	[PMIF_MONITOR_RECORD_9_2] =     	0x05A4,
	[PMIF_MONITOR_RECORD_9_3] =     	0x05A8,
	[PMIF_MONITOR_RECORD_9_4] =     	0x05AC,
	[PMIF_MONITOR_RECORD_10_0] =    	0x05B0,
	[PMIF_MONITOR_RECORD_10_1] =    	0x05B4,
	[PMIF_MONITOR_RECORD_10_2] =    	0x05B8,
	[PMIF_MONITOR_RECORD_10_3] =    	0x05BC,
	[PMIF_MONITOR_RECORD_10_4] =    	0x05C0,
	[PMIF_MONITOR_RECORD_11_0] =    	0x05C4,
	[PMIF_MONITOR_RECORD_11_1] =    	0x05C8,
	[PMIF_MONITOR_RECORD_11_2] =    	0x05CC,
	[PMIF_MONITOR_RECORD_11_3] =    	0x05D0,
	[PMIF_MONITOR_RECORD_11_4] =    	0x05D4,
	[PMIF_MONITOR_RECORD_12_0] =    	0x05D8,
	[PMIF_MONITOR_RECORD_12_1] =    	0x05DC,
	[PMIF_MONITOR_RECORD_12_2] =    	0x05E0,
	[PMIF_MONITOR_RECORD_12_3] =    	0x05E4,
	[PMIF_MONITOR_RECORD_12_4] =    	0x05E8,
	[PMIF_MONITOR_RECORD_13_0] =    	0x05EC,
	[PMIF_MONITOR_RECORD_13_1] =    	0x05F0,
	[PMIF_MONITOR_RECORD_13_2] =    	0x05F4,
	[PMIF_MONITOR_RECORD_13_3] =    	0x05F8,
	[PMIF_MONITOR_RECORD_13_4] =    	0x05FC,
	[PMIF_MONITOR_RECORD_14_0] =    	0x0600,
	[PMIF_MONITOR_RECORD_14_1] =    	0x0604,
	[PMIF_MONITOR_RECORD_14_2] =    	0x0608,
	[PMIF_MONITOR_RECORD_14_3] =    	0x060C,
	[PMIF_MONITOR_RECORD_14_4] =    	0x0610,
	[PMIF_MONITOR_RECORD_15_0] =    	0x0614,
	[PMIF_MONITOR_RECORD_15_1] =    	0x0618,
	[PMIF_MONITOR_RECORD_15_2] =    	0x061C,
	[PMIF_MONITOR_RECORD_15_3] =    	0x0620,
	[PMIF_MONITOR_RECORD_15_4] =    	0x0624,
	[PMIF_MONITOR_RECORD_16_0] =    	0x0628,
	[PMIF_MONITOR_RECORD_16_1] =    	0x062C,
	[PMIF_MONITOR_RECORD_16_2] =    	0x0630,
	[PMIF_MONITOR_RECORD_16_3] =    	0x0634,
	[PMIF_MONITOR_RECORD_16_4] =    	0x0638,
	[PMIF_MONITOR_RECORD_17_0] =    	0x063C,
	[PMIF_MONITOR_RECORD_17_1] =    	0x0640,
	[PMIF_MONITOR_RECORD_17_2] =    	0x0644,
	[PMIF_MONITOR_RECORD_17_3] =    	0x0648,
	[PMIF_MONITOR_RECORD_17_4] =    	0x064C,
	[PMIF_MONITOR_RECORD_18_0] =    	0x0650,
	[PMIF_MONITOR_RECORD_18_1] =    	0x0654,
	[PMIF_MONITOR_RECORD_18_2] =    	0x0658,
	[PMIF_MONITOR_RECORD_18_3] =    	0x065C,
	[PMIF_MONITOR_RECORD_18_4] =    	0x0660,
	[PMIF_MONITOR_RECORD_19_0] =    	0x0664,
	[PMIF_MONITOR_RECORD_19_1] =    	0x0668,
	[PMIF_MONITOR_RECORD_19_2] =    	0x066C,
	[PMIF_MONITOR_RECORD_19_3] =    	0x0670,
	[PMIF_MONITOR_RECORD_19_4] =    	0x0674,
	[PMIF_MONITOR_RECORD_20_0] =    	0x0678,
	[PMIF_MONITOR_RECORD_20_1] =    	0x067C,
	[PMIF_MONITOR_RECORD_20_2] =    	0x0680,
	[PMIF_MONITOR_RECORD_20_3] =    	0x0684,
	[PMIF_MONITOR_RECORD_20_4] =    	0x0688,
	[PMIF_MONITOR_RECORD_21_0] =    	0x068C,
	[PMIF_MONITOR_RECORD_21_1] =    	0x0690,
	[PMIF_MONITOR_RECORD_21_2] =    	0x0694,
	[PMIF_MONITOR_RECORD_21_3] =    	0x0698,
	[PMIF_MONITOR_RECORD_21_4] =    	0x069C,
	[PMIF_MONITOR_RECORD_22_0] =    	0x06A0,
	[PMIF_MONITOR_RECORD_22_1] =    	0x06A4,
	[PMIF_MONITOR_RECORD_22_2] =    	0x06A8,
	[PMIF_MONITOR_RECORD_22_3] =    	0x06AC,
	[PMIF_MONITOR_RECORD_22_4] =    	0x06B0,
	[PMIF_MONITOR_RECORD_23_0] =    	0x06B4,
	[PMIF_MONITOR_RECORD_23_1] =    	0x06B8,
	[PMIF_MONITOR_RECORD_23_2] =    	0x06BC,
	[PMIF_MONITOR_RECORD_23_3] =    	0x06C0,
	[PMIF_MONITOR_RECORD_23_4] =    	0x06C4,
	[PMIF_MONITOR_RECORD_24_0] =    	0x06C8,
	[PMIF_MONITOR_RECORD_24_1] =    	0x06CC,
	[PMIF_MONITOR_RECORD_24_2] =    	0x06D0,
	[PMIF_MONITOR_RECORD_24_3] =    	0x06D4,
	[PMIF_MONITOR_RECORD_24_4] =    	0x06D8,
	[PMIF_MONITOR_RECORD_25_0] =    	0x06DC,
	[PMIF_MONITOR_RECORD_25_1] =    	0x06E0,
	[PMIF_MONITOR_RECORD_25_2] =    	0x06E4,
	[PMIF_MONITOR_RECORD_25_3] =    	0x06E8,
	[PMIF_MONITOR_RECORD_25_4] =    	0x06EC,
	[PMIF_MONITOR_RECORD_26_0] =    	0x06F0,
	[PMIF_MONITOR_RECORD_26_1] =    	0x06F4,
	[PMIF_MONITOR_RECORD_26_2] =    	0x06F8,
	[PMIF_MONITOR_RECORD_26_3] =    	0x06FC,
	[PMIF_MONITOR_RECORD_26_4] =    	0x0700,
	[PMIF_MONITOR_RECORD_27_0] =    	0x0704,
	[PMIF_MONITOR_RECORD_27_1] =    	0x0708,
	[PMIF_MONITOR_RECORD_27_2] =    	0x070C,
	[PMIF_MONITOR_RECORD_27_3] =    	0x0710,
	[PMIF_MONITOR_RECORD_27_4] =    	0x0714,
	[PMIF_MONITOR_RECORD_28_0] =    	0x0718,
	[PMIF_MONITOR_RECORD_28_1] =    	0x071C,
	[PMIF_MONITOR_RECORD_28_2] =    	0x0720,
	[PMIF_MONITOR_RECORD_28_3] =    	0x0724,
	[PMIF_MONITOR_RECORD_28_4] =    	0x0728,
	[PMIF_MONITOR_RECORD_29_0] =    	0x072C,
	[PMIF_MONITOR_RECORD_29_1] =    	0x0730,
	[PMIF_MONITOR_RECORD_29_2] =    	0x0734,
	[PMIF_MONITOR_RECORD_29_3] =    	0x0738,
	[PMIF_MONITOR_RECORD_29_4] =    	0x073C,
	[PMIF_MONITOR_RECORD_30_0] =    	0x0740,
	[PMIF_MONITOR_RECORD_30_1] =    	0x0744,
	[PMIF_MONITOR_RECORD_30_2] =    	0x0748,
	[PMIF_MONITOR_RECORD_30_3] =    	0x074C,
	[PMIF_MONITOR_RECORD_30_4] =    	0x0750,
	[PMIF_MONITOR_RECORD_31_0] =    	0x0754,
	[PMIF_MONITOR_RECORD_31_1] =    	0x0758,
	[PMIF_MONITOR_RECORD_31_2] =    	0x075C,
	[PMIF_MONITOR_RECORD_31_3] =    	0x0760,
	[PMIF_MONITOR_RECORD_31_4] =    	0x0764,
	[PMIF_DEBUG_CTRL] =			0x0768,
	[PMIF_RESERVED_0] =			0x0770,
	[PMIF_SWINF_0_ACC] =			0x0C00,
	[PMIF_SWINF_0_WDATA_31_0] =		0x0C04,
	[PMIF_SWINF_0_WDATA_63_32] =		0x0C08,
	[PMIF_SWINF_0_RDATA_31_0] =		0x0C14,
	[PMIF_SWINF_0_RDATA_63_32] =		0x0C18,
	[PMIF_SWINF_0_VLD_CLR] =		0x0C24,
	[PMIF_SWINF_0_STA] =			0x0C28,
	[PMIF_SWINF_1_ACC] =			0x0C40,
	[PMIF_SWINF_1_WDATA_31_0] =		0x0C44,
	[PMIF_SWINF_1_WDATA_63_32] =		0x0C48,
	[PMIF_SWINF_1_RDATA_31_0] =		0x0C54,
	[PMIF_SWINF_1_RDATA_63_32] =		0x0C58,
	[PMIF_SWINF_1_VLD_CLR] =		0x0C64,
	[PMIF_SWINF_1_STA] =			0x0C68,
	[PMIF_SWINF_2_ACC] =			0x0C80,
	[PMIF_SWINF_2_WDATA_31_0] =		0x0C84,
	[PMIF_SWINF_2_WDATA_63_32] =		0x0C88,
	[PMIF_SWINF_2_RDATA_31_0] =		0x0C94,
	[PMIF_SWINF_2_RDATA_63_32] =		0x0C98,
	[PMIF_SWINF_2_VLD_CLR] =		0x0CA4,
	[PMIF_SWINF_2_STA] =			0x0CA8,
	[PMIF_SWINF_3_ACC] =			0x0CC0,
	[PMIF_SWINF_3_WDATA_31_0] =		0x0CC4,
	[PMIF_SWINF_3_WDATA_63_32] =		0x0CC8,
	[PMIF_SWINF_3_RDATA_31_0] =		0x0CD4,
	[PMIF_SWINF_3_RDATA_63_32] =		0x0CD8,
	[PMIF_SWINF_3_VLD_CLR] =		0x0CE4,
	[PMIF_SWINF_3_STA] =			0x0CE8,
};
#if SPMI_KERNEL
static unsigned char spmi_pmif_log_buf[1280];
#endif

/* spmi & pmif debug mechanism */
void spmi_dump_pmif_busy_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int i = 0, offset = 0, tmp_dat = 0;
	unsigned int start = 0, end = 0;

	start = arb->dbgregs[PMIF_INF_BUSY_STA]/4;
	end = arb->dbgregs[PMIF_OTHER_BUSY_STA_1]/4;

	PMIF_CRI("");
	for (i = start; i <= end; i++) {
		offset = arb->dbgregs[PMIF_INF_BUSY_STA] + (i * 4);
		tmp_dat = DRV_Reg32(arb->base + offset);
		PMIF_CRIL("(0x%x)=0x%x ", offset, tmp_dat);

		if (i == 0)
			continue;
	}
	PMIF_CRIL("\r\n");
	spmi_dump_pmif_swinf_reg(mstid);
}
void spmi_dump_pmif_swinf_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int i = 0, offset = 0, j = 0, tmp_dat = 0;
	unsigned int swinf[4] = {0}, cmd[4] = {0}, rw[4] = {0};
	unsigned int slvid[4] = {0}, bytecnt[4] = {0}, adr[4] = {0};
#if 0
	unsigned int wd_31_0[4] = {0}, wd_63_32[4] = {0};
	unsigned int rd_31_0[4] = {0}, rd_63_32[4] = {0};
#endif
	unsigned int wd_31_0[4] = {0}, rd_31_0[4] = {0};
	unsigned int err[4] = {0}, sbusy[4] = {0}, done[4] = {0};
	unsigned int qfillcnt[4] = {0}, qfreecnt[4] = {0}, qempty[4] = {0};
	unsigned int qfull[4] = {0}, req[4] = {0}, fsm[4] = {0}, en[4] = {0};

	for (i = 0; i < 4; i++) {
		offset = arb->dbgregs[PMIF_SWINF_0_ACC] + (i * 0x40);
		tmp_dat = DRV_Reg32(arb->base + offset);
		swinf[j] = i;
		cmd[j] = (tmp_dat & (0x3 << 30)) >> 30;
		rw[j] = (tmp_dat & (0x1 << 29)) >> 29;
		slvid[j] = (tmp_dat & (0xf << 24)) >> 24;
		bytecnt[j] = (tmp_dat & (0xf << 16)) >> 16;
		adr[j] = (tmp_dat & (0xffff << 0)) >> 0;
		j += 1;
	}
	j = 0;
	for (i = 0; i < 4; i++) {
		offset = arb->dbgregs[PMIF_SWINF_0_WDATA_31_0] + (i * 0x40);
		tmp_dat = DRV_Reg32(arb->base + offset);
		wd_31_0[j] = tmp_dat;
		j += 1;
	}
	j = 0;
	for (i = 0; i < 4; i++) {
		offset = arb->dbgregs[PMIF_SWINF_0_RDATA_31_0] + (i * 0x40);
		tmp_dat = DRV_Reg32(arb->base + offset);
		rd_31_0[j] = tmp_dat;
		j += 1;
	}
	j = 0;
	for (i = 0; i < 4; i++) {
		offset = arb->dbgregs[PMIF_SWINF_0_STA] + (i * 0x40);
		tmp_dat = DRV_Reg32(arb->base + offset);
		err[j] = (tmp_dat & (0x1 << 18)) >> 18;
		sbusy[j] = (tmp_dat & (0x1 << 17)) >> 17;
		done[j] = (tmp_dat & (0x1 << 15)) >> 15;
		qfillcnt[j] = (tmp_dat & (0xf << 11)) >> 11;
		qfreecnt[j] = (tmp_dat & (0xf << 7)) >> 7;
		qempty[j] = (tmp_dat & (0x1 << 6)) >> 6;
		qfull[j] = (tmp_dat & (0x1 << 5)) >> 5;
		req[j] = (tmp_dat & (0x1 << 4)) >> 4;
		fsm[j] = (tmp_dat & (0x7 << 1)) >> 1;
		en[j] = (tmp_dat & (0x1 << 0)) >> 0;
		j += 1;
	}
	for (i = 0; i < 4; i++) {
		if (rw[i] == 0) {
			PMIF_CRI("[swinf:%d, cmd:0x%x, rw:0x%x, slvid:%d ",
				swinf[i], cmd[i], rw[i], slvid[i]);
			PMIF_CRIL("bytecnt:%d (read adr 0x%04x=0x%x)]\r\n",
				bytecnt[i], adr[i], rd_31_0[i]);
			PMIF_CRI("[err:%d, sbusy:%d, done:%d, qfillcnt:%d ",
				err[i], sbusy[i], done[i], qfillcnt[i]);
			PMIF_CRIL("qfreecnt:%d, qempty:%d, qfull:%d, req:%d ",
				qfreecnt[i], qempty[i], qfull[i], req[i]);
			PMIF_CRIL("fsm:%d, en:%d]\r\n", fsm[i], en[i]);
		} else {
			PMIF_CRI("[swinf:%d, cmd:0x%x, rw:0x%x, slvid:%d ",
				swinf[i], cmd[i], rw[i], slvid[i]);
			PMIF_CRIL("bytecnt:%d (write adr 0x%04x=0x%x)]\r\n",
				bytecnt[i], adr[i], wd_31_0[i]);
			PMIF_CRI("[err:%d, sbusy:%d, done:%d, qfillcnt:%d ",
				err[i], sbusy[i], done[i], qfillcnt[i]);
			PMIF_CRIL("qfreecnt:%d, qempty:%d, qfull:%d, req:%d ",
				qfreecnt[i], qempty[i], qfull[i], req[i]);
			PMIF_CRIL("fsm:%d, en:%d]\r\n", fsm[i], en[i]);
		}
	}
}

void spmi_dump_pmif_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int i = 0, offset = 0, tmp_dat = 0;
	unsigned int start = 0, end = 0;

	start = arb->dbgregs[PMIF_INIT_DONE]/4;
	end = arb->dbgregs[PMIF_RESERVED_0]/4;

	PMIF_CRI("");
	for (i = start; i <= end; i++) {
		offset = arb->dbgregs[PMIF_INIT_DONE] + (i * 4);
		tmp_dat = DRV_Reg32(arb->base + offset);
		PMIF_CRIL("(0x%x)=0x%x ", offset, tmp_dat);

		if (i == 0)
			continue;
		if (i % 8 == 0) {
			PMIF_CRIL("\r\n[PMIF] ");
		}
	}
	PMIF_CRIL("\r\n");
	spmi_dump_pmif_swinf_reg(mstid);
}

void spmi_dump_pmif_record_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int i = 0, offset = 0, j = 0, tmp_dat = 0;
	unsigned int chan[32] = {0}, cmd[32] = {0}, rw[32] = {0};
	unsigned int slvid[32] = {0}, bytecnt[32] = {0}, adr[32] = {0};
#if 0
	unsigned int wd_31_0[32] = {0}, wd_63_32[32] = {0};
#endif
	unsigned int wd_31_0[32] = {0};

	for (i = 0; i < 32; i++) {
		offset = arb->dbgregs[PMIF_MONITOR_RECORD_0_0] + (i * 0x14);
		tmp_dat = DRV_Reg32(arb->base + offset);
		chan[j] = (tmp_dat & (0xf8000000)) >> 27;
		cmd[j] = (tmp_dat & (0x3 << 25)) >> 25;
		rw[j] = (tmp_dat & (0x1 << 24)) >> 24;
		slvid[j] = (tmp_dat & (0xf << 20)) >> 20;
		bytecnt[j] = (tmp_dat & (0xf << 16)) >> 16;
		adr[j] = (tmp_dat & (0xffff << 0)) >> 0;
		j += 1;
	}
	j = 0;
	for (i = 0; i < 32; i++) {
		offset = arb->dbgregs[PMIF_MONITOR_RECORD_0_1] + (i * 0x14);
		tmp_dat = DRV_Reg32(arb->base + offset);
		wd_31_0[j] = tmp_dat;
		j += 1;
	}

	for (i = 0; i < 32; i++) {
		SPMI_CRI("[swinf:%d, cmd:0x%x, rw:0x%x, slvid:%d ",
			chan[i], cmd[i], rw[i], slvid[i]);
		SPMI_CRIL("bytecnt:%d (adr 0x%04x=0x%x)]\r\n",
			bytecnt[i], adr[i], wd_31_0[i]);
	}
	spmi_dump_pmif_swinf_reg(mstid);

	/* clear record data and re-enable */
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_CTRL], 0x800);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_CTRL], 0x5);
}
#if 0
void spmi_dump_pmif_record_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int i = 0, offset = 0, log_size = 0;
	unsigned int chan[32] = {0}, cmd[32] = {0}, wr[32] = {0};
	unsigned int slvid[32] = {0}, bytecnt[32] = {0}, adr[32] = {0};
	unsigned int wd_31_0[32] = {0}, wd_63_32[32] = {0};
	unsigned int j = 0, s = 0, e = 0, tmp_dat = 0;

	log_size += sprintf(spmi_pmif_log_buf, "\npmif ");
	s = arb->dbgregs[PMIF_MONITOR_RECORD_0_0];
	e = arb->dbgregs[PMIF_MONITOR_RECORD_31_0];
	for (i = 0; i < 32; i++) {
		offset = arb->dbgregs[PMIF_MONITOR_RECORD_0_0] + (i * 0x14);
		tmp_dat = DRV_Reg32(arb->base + offset);
		chan[j] = (tmp_dat & 0xf8000000) >> 27;
		cmd[j] = (tmp_dat & 0x06000000) >> 25;
		wr[j] = (tmp_dat & 0x01000000) >> 24;
		slvid[j] = (tmp_dat & 0x00f00000) >> 20;
		bytecnt[j] = (tmp_dat & 0x000f0000) >> 16;
		adr[j] = (tmp_dat & 0x0000ffff) >> 0;
		j += 1;
	}
	j = 0;
	s = arb->dbgregs[PMIF_MONITOR_RECORD_0_1];
	e = arb->dbgregs[PMIF_MONITOR_RECORD_31_1];
	for (i = 0; i < 32; i++) {
		offset = arb->dbgregs[PMIF_MONITOR_RECORD_0_1] + (i * 0x14);
		tmp_dat = DRV_Reg32(arb->base + offset);
		wd_31_0[j] = tmp_dat;
		j += 1;
	}

	for (i = 0; i < 32; i++) {
		log_size += sprintf(spmi_pmif_log_buf + log_size,
		"[ch:%d, cmd:0x%x, wr:0x%x, slvid:%d, bytecnt:%d ",
			chan[i], cmd[i], wr[i], slvid[i], bytecnt[i]);
		log_size += sprintf(spmi_pmif_log_buf + log_size,
		"addr[0x%04x]=0x%04x]", adr[i], wd_31_0[i]);
		if (i == 0)
			continue;

		if (i % 2 == 0) {
			log_size += sprintf(spmi_pmif_log_buf + log_size,
				"log_size:%d\npmif ", log_size);
		}
	}
	SPMI_CRI("\npmif %s %d\n", spmi_pmif_log_buf, log_size);
	log_size = 0;
#if 0
	for (i = 0; i <= 14; i++) {
		offset = 0xc00 + i * 4;
		reg_addr = wrp->base + offset;
		log_size += sprintf(spmi_pmif_log_buf + log_size,
		"(0x%x) = 0x%x ", offset, readl(reg_addr));
	}
	PMIF_ERR(wrp->dev, "\npmif %s %d\n", spmi_pmif_log_buf, log_size);

	if (HAS_CAP(arb->dbgcaps, PWRAP_CAP_MON_V1)) {
		pmif_writel(wrp, 0x8, PWRAP_MONITOR_CTRL_0);
		pmif_writel(wrp, 0x5, PWRAP_MONITOR_CTRL_0);
	} else if (HAS_CAP(arb->dbgcaps, PWRAP_CAP_MON_V2)) {
		pmif_writel(wrp, 0x800, PWRAP_MONITOR_CTRL_0);
		pmif_writel(wrp, 0x5, PWRAP_MONITOR_CTRL_0);
	}
#endif
}
#endif
void spmi_dump_spmimst_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int i = 0, offset = 0, tmp_dat = 0;
	unsigned int start = 0, end = 0;

	start = arb->spmimst_regs[SPMI_OP_ST_CTRL]/4;
	end = arb->spmimst_regs[SPMI_REC4]/4;

	SPMI_CRI("");
	for (i = start; i <= end; i++) {
		offset = arb->spmimst_regs[SPMI_OP_ST_CTRL] + (i * 4);
		tmp_dat = DRV_Reg32(arb->spmimst_base + offset);
		SPMI_CRIL("(0x%x)=0x%x ", offset, tmp_dat);

		if (i == 0)
			continue;
		if (i % 8 == 0) {
			SPMI_CRIL("\r\n[SPMI] ");
		}
	}
#if SPMI_RCS_SUPPORT
	offset = arb->spmimst_regs[SPMI_DEC_DBG];
	tmp_dat = DRV_Reg32(arb->spmimst_base + offset);
	SPMI_CRIL("(0x%x)=0x%x ", offset, tmp_dat);
#endif
	offset = arb->spmimst_regs[SPMI_MST_DBG];
	tmp_dat = DRV_Reg32(arb->spmimst_base + offset);
	SPMI_CRIL("(0x%x)=0x%x ", offset, tmp_dat);
	SPMI_CRIL("\r\n");
}

void spmi_dump_mst_record_reg(int mstid)
{
#if SPMI_DEBUG
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);

	SPMI_DBG("[0x%x]=0x%x [0x%x]=0x%x [0x%x]=0x%x [0x%x]=0x%x\r\n",
			arb->spmimst_regs[SPMI_OP_ST_STA],
			spmi_readl(mstid, SPMI_OP_ST_STA),
			arb->spmimst_regs[SPMI_REC0],
			spmi_readl(mstid, SPMI_REC0),
			arb->spmimst_regs[SPMI_REC1],
			spmi_readl(mstid, SPMI_REC1),
			arb->spmimst_regs[SPMI_REC2],
			spmi_readl(mstid, SPMI_REC2));
	SPMI_DBG("[0x%x]=0x%x [0x%x]=0x%x [0x%x]=0x%x\r\n",
			arb->spmimst_regs[SPMI_REC3],
			spmi_readl(mstid, SPMI_REC3),
			arb->spmimst_regs[SPMI_REC4],
			spmi_readl(mstid, SPMI_REC4),
			arb->spmimst_regs[SPMI_MST_DBG],
			spmi_readl(mstid, SPMI_MST_DBG));
#endif
}

void spmi_dump_slv_record_reg(struct spmi_device *dev)
{
	unsigned char rdata1 = 0, rdata2 = 0, rdata3 = 0, rdata4 = 0;
	unsigned int offset, i, j = 0;

	/* log sequence, idx 0->1->2->3->0 */
	for (offset = 0x34; offset < 0x50; offset += 4)
	{
		spmi_ext_register_readl(dev,
			(MT6315_PLT0_ID_ANA_ID + offset), &rdata1, 1);
		spmi_ext_register_readl(dev,
			(MT6315_PLT0_ID_ANA_ID + offset + 1), &rdata2, 1);
		spmi_ext_register_readl(dev,
			(MT6315_PLT0_ID_ANA_ID + offset + 2), &rdata3, 1);
		spmi_ext_register_readl(dev,
			(MT6315_PLT0_ID_ANA_ID + offset + 3), &rdata4, 1);
		if ((offset + 3) == 0x37) {
			i = (rdata4 & 0xc) >> 2;
			if (i == 0)
				SPMI_CRI("slvid:%d DBG. Last cmd idx:0x3\r\n",
					dev->slvid);
			else {
				SPMI_CRI("slvid:%d DBG. Last cmd idx:0x%x\r\n",
					dev->slvid, ((rdata4 & 0xc) >> 2) - 1);
			}

		}
		/*
		 *SPMI_CRI("[0x%x]=0x%x [0x%x]=0x%x [0x%x]=0x%x [0x%x]=0x%x ",
		 *	offset, rdata1, (offset + 1), rdata2,
		 *	(offset + 2), rdata3, (offset + 3), rdata4);
		 */

		SPMI_CRI("Idx:%d slvid:%d Type:0x%x, [0x%x]=0x%x\r\n", j,
			dev->slvid, (rdata4 & 0x3),
			(rdata2 << 0x8) | rdata1, rdata3);
		if (j <= 3)
			j++;

	}
}

int spmi_pmif_dbg_init(struct pmif *arb)
{
#if PMIF_MATCH_SUPPORT
	unsigned int int_en = 0;
#endif
	arb->dbgregs = mt6xxx_pmif_dbg_regs;
#if PMIF_MATCH_SUPPORT
	/* enable matching mode */
	PMIF_CRI("PMIF Matching Mode\n");

	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_IRQ_CLR_0], 0xffffffff);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_IRQ_CLR_1], 0xffffffff);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_IRQ_CLR_2], 0xffffffff);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_IRQ_CLR_3], 0xffffffff);

	int_en = DRV_Reg32(arb->base + arb->dbgregs[PMIF_IRQ_EVENT_EN_3]);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_IRQ_EVENT_EN_3],
		int_en | (0x1 << 7));

	/* set monitor channel, should same as ARB_EN */
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_TARGET_CHAN_0],
			0x2f5);
	/* [31:16] addr mask, ffff mean all bit check
	 * [15:0] addr, which addr been checked
	 */
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_TARGET_ADDR_0],
			0xffff03a5);
	/* [31:16] wdata mask, ffff mean all bit check
	 * [15:0] data, which data been checked
	 */
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_TARGET_WDATA_0],
			0xffff005a);
	/*
	 * BIT[0] MONITOR_TARGET_WRITE_0
	 * BIT[1] MONITOR_TARGET_WRITE_0_MASK: 0, rw all check, 1, check
	 * BIT[0] if BIT[0] = 0, only check read;otherwise only check write.
	 */
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_TARGET_WRITE],
			0x3);
	/* reset then enable */
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_CTRL], 0x800);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_CTRL], 0x405);
#else
	/* init pmif debug mechanism, hw matching mode or sw logging mode */
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_TARGET_CHAN_0],
			0x2f5);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_TARGET_ADDR_0],
			0x0);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_TARGET_WDATA_0],
			0x0);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_TARGET_WRITE],
			0x001);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_CTRL], 0x800);
	DRV_WriteReg32(arb->base + arb->dbgregs[PMIF_MONITOR_CTRL], 0x5);
#endif /* end of PMIF_MATCH_SUPPORT */
	return 0;
}
#endif /* endif SPMI_NO_PMIC */
