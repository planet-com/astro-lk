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

#if !SPMI_NO_PMIC

#if (SPMI_CTP)
#define sprintf FormatString
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)    (sizeof (x) / sizeof (x[0]))
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
	PMIF_MONITOR_TARGET_SLVID_0,
	PMIF_MONITOR_TARGET_SLVID_1,
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
	[PMIF_IRQ_EVENT_EN_0] =                 0x0420,
	[PMIF_IRQ_FLAG_0] =                     0x0428,
	[PMIF_IRQ_CLR_0] =                      0x042C,
	[PMIF_IRQ_EVENT_EN_1] =                 0x0430,
	[PMIF_IRQ_FLAG_1] =                     0x0438,
	[PMIF_IRQ_CLR_1] =                      0x043C,
	[PMIF_IRQ_EVENT_EN_2] =                 0x0440,
	[PMIF_IRQ_FLAG_2] =                     0x0448,
	[PMIF_IRQ_CLR_2] =                      0x044C,
	[PMIF_IRQ_EVENT_EN_3] =                 0x0450,
	[PMIF_IRQ_FLAG_3] =                     0x0458,
	[PMIF_IRQ_CLR_3] =                      0x045C,
	[PMIF_IRQ_EVENT_EN_4] =                 0x0460,
	[PMIF_IRQ_FLAG_4] =                     0x0468,
	[PMIF_IRQ_CLR_4] =                      0x046C,
	[PMIF_WDT_EVENT_EN_0] =			0x0474,
	[PMIF_WDT_FLAG_0] =			0x0478,
	[PMIF_WDT_EVENT_EN_1] =			0x047C,
	[PMIF_WDT_FLAG_1] =			0x0480,
	[PMIF_MONITOR_CTRL] =			0x0484,
	[PMIF_MONITOR_TARGET_CHAN_0] =		0x0488,
	[PMIF_MONITOR_TARGET_CHAN_1] =		0x048C,
	[PMIF_MONITOR_TARGET_CHAN_2] =		0x0490,
	[PMIF_MONITOR_TARGET_CHAN_3] =		0x0494,
	[PMIF_MONITOR_TARGET_CHAN_4] =		0x0498,
	[PMIF_MONITOR_TARGET_CHAN_5] =		0x049C,
	[PMIF_MONITOR_TARGET_CHAN_6] =		0x04A0,
	[PMIF_MONITOR_TARGET_CHAN_7] =		0x04A4,
	[PMIF_MONITOR_TARGET_WRITE] =		0x04A8,
	[PMIF_MONITOR_TARGET_SLVID_0] =		0x04AC,
	[PMIF_MONITOR_TARGET_SLVID_1] =		0x04B0,
	[PMIF_MONITOR_TARGET_ADDR_0] =		0x04B4,
	[PMIF_MONITOR_TARGET_ADDR_1] =		0x04B8,
	[PMIF_MONITOR_TARGET_ADDR_2] =		0x04BC,
	[PMIF_MONITOR_TARGET_ADDR_3] =		0x04C0,
	[PMIF_MONITOR_TARGET_ADDR_4] =		0x04C4,
	[PMIF_MONITOR_TARGET_ADDR_5] =		0x04C8,
	[PMIF_MONITOR_TARGET_ADDR_6] =		0x04CC,
	[PMIF_MONITOR_TARGET_ADDR_7] =		0x04D0,
	[PMIF_MONITOR_TARGET_WDATA_0] =		0x04D4,
	[PMIF_MONITOR_TARGET_WDATA_1] =		0x04D8,
	[PMIF_MONITOR_TARGET_WDATA_2] =		0x04DC,
	[PMIF_MONITOR_TARGET_WDATA_3] =		0x04E0,
	[PMIF_MONITOR_TARGET_WDATA_4] =		0x04E4,
	[PMIF_MONITOR_TARGET_WDATA_5] =		0x04E8,
	[PMIF_MONITOR_TARGET_WDATA_6] =		0x04EC,
	[PMIF_MONITOR_TARGET_WDATA_7] =		0x04F0,
	[PMIF_MONITOR_STA] =			0x04F4,
	[PMIF_MONITOR_RECORD_0_0] =		0x04F8,
	[PMIF_MONITOR_RECORD_0_1] =		0x04FC,
	[PMIF_MONITOR_RECORD_0_2] =		0x0500,
	[PMIF_MONITOR_RECORD_0_3] =		0x0504,
	[PMIF_MONITOR_RECORD_0_4] =		0x0508,
	[PMIF_MONITOR_RECORD_1_0] =		0x050C,
	[PMIF_MONITOR_RECORD_1_1] =		0x0510,
	[PMIF_MONITOR_RECORD_1_2] =		0x0514,
	[PMIF_MONITOR_RECORD_1_3] =		0x0518,
	[PMIF_MONITOR_RECORD_1_4] =		0x051C,
	[PMIF_MONITOR_RECORD_2_0] =		0x0520,
	[PMIF_MONITOR_RECORD_2_1] =		0x0524,
	[PMIF_MONITOR_RECORD_2_2] =		0x0528,
	[PMIF_MONITOR_RECORD_2_3] =		0x052C,
	[PMIF_MONITOR_RECORD_2_4] =		0x0530,
	[PMIF_MONITOR_RECORD_3_0] =		0x0534,
	[PMIF_MONITOR_RECORD_3_1] =		0x0538,
	[PMIF_MONITOR_RECORD_3_2] =		0x053C,
	[PMIF_MONITOR_RECORD_3_3] =		0x0540,
	[PMIF_MONITOR_RECORD_3_4] =		0x0544,
	[PMIF_MONITOR_RECORD_4_0] =		0x0548,
	[PMIF_MONITOR_RECORD_4_1] =		0x054C,
	[PMIF_MONITOR_RECORD_4_2] =		0x0550,
	[PMIF_MONITOR_RECORD_4_3] =		0x0554,
	[PMIF_MONITOR_RECORD_4_4] =		0x0558,
	[PMIF_MONITOR_RECORD_5_0] =		0x055C,
	[PMIF_MONITOR_RECORD_5_1] =		0x0560,
	[PMIF_MONITOR_RECORD_5_2] =		0x0564,
	[PMIF_MONITOR_RECORD_5_3] =		0x0568,
	[PMIF_MONITOR_RECORD_5_4] =		0x056C,
	[PMIF_MONITOR_RECORD_6_0] =		0x0570,
	[PMIF_MONITOR_RECORD_6_1] =		0x0574,
	[PMIF_MONITOR_RECORD_6_2] =		0x0578,
	[PMIF_MONITOR_RECORD_6_3] =		0x057C,
	[PMIF_MONITOR_RECORD_6_4] =		0x0580,
	[PMIF_MONITOR_RECORD_7_0] =		0x0584,
	[PMIF_MONITOR_RECORD_7_1] =		0x0588,
	[PMIF_MONITOR_RECORD_7_2] =		0x058C,
	[PMIF_MONITOR_RECORD_7_3] =		0x0590,
	[PMIF_MONITOR_RECORD_7_4] =		0x0594,
	[PMIF_MONITOR_RECORD_8_0] =		0x0598,
	[PMIF_MONITOR_RECORD_8_1] =		0x059C,
	[PMIF_MONITOR_RECORD_8_2] =		0x05A0,
	[PMIF_MONITOR_RECORD_8_3] =		0x05A4,
	[PMIF_MONITOR_RECORD_8_4] =		0x05A8,
	[PMIF_MONITOR_RECORD_9_0] =		0x05AC,
	[PMIF_MONITOR_RECORD_9_1] =		0x05B0,
	[PMIF_MONITOR_RECORD_9_2] =		0x05B4,
	[PMIF_MONITOR_RECORD_9_3] =		0x05B8,
	[PMIF_MONITOR_RECORD_9_4] =		0x05BC,
	[PMIF_MONITOR_RECORD_10_0] =		0x05C0,
	[PMIF_MONITOR_RECORD_10_1] =		0x05C4,
	[PMIF_MONITOR_RECORD_10_2] =		0x05C8,
	[PMIF_MONITOR_RECORD_10_3] =		0x05CC,
	[PMIF_MONITOR_RECORD_10_4] =		0x05D0,
	[PMIF_MONITOR_RECORD_11_0] =		0x05D4,
	[PMIF_MONITOR_RECORD_11_1] =		0x05D8,
	[PMIF_MONITOR_RECORD_11_2] =		0x05DC,
	[PMIF_MONITOR_RECORD_11_3] =		0x05E0,
	[PMIF_MONITOR_RECORD_11_4] =		0x05E4,
	[PMIF_MONITOR_RECORD_12_0] =		0x05E8,
	[PMIF_MONITOR_RECORD_12_1] =		0x05EC,
	[PMIF_MONITOR_RECORD_12_2] =		0x05F0,
	[PMIF_MONITOR_RECORD_12_3] =		0x05F4,
	[PMIF_MONITOR_RECORD_12_4] =		0x05F8,
	[PMIF_MONITOR_RECORD_13_0] =		0x05FC,
	[PMIF_MONITOR_RECORD_13_1] =		0x0600,
	[PMIF_MONITOR_RECORD_13_2] =		0x0604,
	[PMIF_MONITOR_RECORD_13_3] =		0x0608,
	[PMIF_MONITOR_RECORD_13_4] =		0x060C,
	[PMIF_MONITOR_RECORD_14_0] =		0x0610,
	[PMIF_MONITOR_RECORD_14_1] =		0x0614,
	[PMIF_MONITOR_RECORD_14_2] =		0x0618,
	[PMIF_MONITOR_RECORD_14_3] =		0x061C,
	[PMIF_MONITOR_RECORD_14_4] =		0x0620,
	[PMIF_MONITOR_RECORD_15_0] =		0x0624,
	[PMIF_MONITOR_RECORD_15_1] =		0x0628,
	[PMIF_MONITOR_RECORD_15_2] =		0x062C,
	[PMIF_MONITOR_RECORD_15_3] =		0x0630,
	[PMIF_MONITOR_RECORD_15_4] =		0x0634,
	[PMIF_MONITOR_RECORD_16_0] =		0x0638,
	[PMIF_MONITOR_RECORD_16_1] =		0x063C,
	[PMIF_MONITOR_RECORD_16_2] =		0x0640,
	[PMIF_MONITOR_RECORD_16_3] =		0x0644,
	[PMIF_MONITOR_RECORD_16_4] =		0x0648,
	[PMIF_MONITOR_RECORD_17_0] =		0x064C,
	[PMIF_MONITOR_RECORD_17_1] =		0x0650,
	[PMIF_MONITOR_RECORD_17_2] =		0x0654,
	[PMIF_MONITOR_RECORD_17_3] =		0x0658,
	[PMIF_MONITOR_RECORD_17_4] =		0x065C,
	[PMIF_MONITOR_RECORD_18_0] =		0x0660,
	[PMIF_MONITOR_RECORD_18_1] =		0x0664,
	[PMIF_MONITOR_RECORD_18_2] =		0x0668,
	[PMIF_MONITOR_RECORD_18_3] =		0x066C,
	[PMIF_MONITOR_RECORD_18_4] =		0x0670,
	[PMIF_MONITOR_RECORD_19_0] =		0x0674,
	[PMIF_MONITOR_RECORD_19_1] =		0x0678,
	[PMIF_MONITOR_RECORD_19_2] =		0x067C,
	[PMIF_MONITOR_RECORD_19_3] =		0x0680,
	[PMIF_MONITOR_RECORD_19_4] =		0x0684,
	[PMIF_MONITOR_RECORD_20_0] =		0x0688,
	[PMIF_MONITOR_RECORD_20_1] =		0x068C,
	[PMIF_MONITOR_RECORD_20_2] =		0x0690,
	[PMIF_MONITOR_RECORD_20_3] =		0x0694,
	[PMIF_MONITOR_RECORD_20_4] =		0x0698,
	[PMIF_MONITOR_RECORD_21_0] =		0x069C,
	[PMIF_MONITOR_RECORD_21_1] =		0x06A0,
	[PMIF_MONITOR_RECORD_21_2] =		0x06A4,
	[PMIF_MONITOR_RECORD_21_3] =		0x06A8,
	[PMIF_MONITOR_RECORD_21_4] =		0x06AC,
	[PMIF_MONITOR_RECORD_22_0] =		0x06B0,
	[PMIF_MONITOR_RECORD_22_1] =		0x06B4,
	[PMIF_MONITOR_RECORD_22_2] =		0x06B8,
	[PMIF_MONITOR_RECORD_22_3] =		0x06BC,
	[PMIF_MONITOR_RECORD_22_4] =		0x06C0,
	[PMIF_MONITOR_RECORD_23_0] =		0x06C4,
	[PMIF_MONITOR_RECORD_23_1] =		0x06C8,
	[PMIF_MONITOR_RECORD_23_2] =		0x06CC,
	[PMIF_MONITOR_RECORD_23_3] =		0x06D0,
	[PMIF_MONITOR_RECORD_23_4] =		0x06D4,
	[PMIF_MONITOR_RECORD_24_0] =		0x06D8,
	[PMIF_MONITOR_RECORD_24_1] =		0x06DC,
	[PMIF_MONITOR_RECORD_24_2] =		0x06E0,
	[PMIF_MONITOR_RECORD_24_3] =		0x06E4,
	[PMIF_MONITOR_RECORD_24_4] =		0x06E8,
	[PMIF_MONITOR_RECORD_25_0] =		0x06EC,
	[PMIF_MONITOR_RECORD_25_1] =		0x06F0,
	[PMIF_MONITOR_RECORD_25_2] =		0x06F4,
	[PMIF_MONITOR_RECORD_25_3] =		0x06F8,
	[PMIF_MONITOR_RECORD_25_4] =		0x06FC,
	[PMIF_MONITOR_RECORD_26_0] =		0x0700,
	[PMIF_MONITOR_RECORD_26_1] =		0x0704,
	[PMIF_MONITOR_RECORD_26_2] =		0x0708,
	[PMIF_MONITOR_RECORD_26_3] =		0x070C,
	[PMIF_MONITOR_RECORD_26_4] =		0x0710,
	[PMIF_MONITOR_RECORD_27_0] =		0x0714,
	[PMIF_MONITOR_RECORD_27_1] =		0x0718,
	[PMIF_MONITOR_RECORD_27_2] =		0x071C,
	[PMIF_MONITOR_RECORD_27_3] =		0x0720,
	[PMIF_MONITOR_RECORD_27_4] =		0x0724,
	[PMIF_MONITOR_RECORD_28_0] =		0x0728,
	[PMIF_MONITOR_RECORD_28_1] =		0x072C,
	[PMIF_MONITOR_RECORD_28_2] =		0x0730,
	[PMIF_MONITOR_RECORD_28_3] =		0x0734,
	[PMIF_MONITOR_RECORD_28_4] =		0x0738,
	[PMIF_MONITOR_RECORD_29_0] =		0x073C,
	[PMIF_MONITOR_RECORD_29_1] =		0x0740,
	[PMIF_MONITOR_RECORD_29_2] =		0x0744,
	[PMIF_MONITOR_RECORD_29_3] =		0x0748,
	[PMIF_MONITOR_RECORD_29_4] =		0x074C,
	[PMIF_MONITOR_RECORD_30_0] =		0x0750,
	[PMIF_MONITOR_RECORD_30_1] =		0x0754,
	[PMIF_MONITOR_RECORD_30_2] =		0x0758,
	[PMIF_MONITOR_RECORD_30_3] =		0x075C,
	[PMIF_MONITOR_RECORD_30_4] =		0x0760,
	[PMIF_MONITOR_RECORD_31_0] =		0x0764,
	[PMIF_MONITOR_RECORD_31_1] =		0x0768,
	[PMIF_MONITOR_RECORD_31_2] =		0x076C,
	[PMIF_MONITOR_RECORD_31_3] =		0x0770,
	[PMIF_MONITOR_RECORD_31_4] =		0x0774,
	[PMIF_DEBUG_CTRL] =			0x0778,
	[PMIF_RESERVED_0] =			0x0780,
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

/* spmi & pmif debug mechanism */
void spmi_dump_pmif_busy_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int offset = 0, tmp_dat = 0;
	unsigned int start = 0, end = 0;

	start = arb->dbgregs[PMIF_INF_BUSY_STA];
	end = arb->dbgregs[PMIF_OTHER_BUSY_STA_1];

	PMIF_CRI("");
	for (offset = start; offset <= end; offset += 4) {
		tmp_dat = DRV_Reg32(arb->base + offset);
		PMIF_CRIL("(0x%x)=0x%x ", offset, tmp_dat);
	}
	PMIF_CRIL("\n");
	spmi_dump_pmif_swinf_reg(mstid);
}

void spmi_dump_pmif_swinf_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int swinf = 0, step = 0, offset = 0, tmp_dat = 0;
	unsigned int cmd = 0, is_write = 0, slvid = 0, bytecnt = 0, addr = 0;
	unsigned int wd_31_0 = 0, rd_31_0 = 0;
	unsigned int err = 0, sbusy = 0, done = 0, qfillcnt = 0, qfreecnt = 0;
	unsigned int qempty = 0, qfull = 0, req = 0, fsm = 0, en = 0;

	step = arb->dbgregs[PMIF_SWINF_1_ACC] - arb->dbgregs[PMIF_SWINF_0_ACC];
	for (swinf = 0; swinf < 4; swinf++) {
		offset = arb->dbgregs[PMIF_SWINF_0_ACC] + swinf * step;
		tmp_dat = DRV_Reg32(arb->base + offset);
		cmd = (tmp_dat & (0x3 << 30)) >> 30;
		is_write = (tmp_dat & (0x1 << 29)) >> 29;
		slvid = (tmp_dat & (0xf << 24)) >> 24;
		bytecnt = (tmp_dat & (0xf << 16)) >> 16;
		addr = (tmp_dat & (0xffff << 0)) >> 0;

		offset = arb->dbgregs[PMIF_SWINF_0_WDATA_31_0] + swinf * step;
		wd_31_0 = DRV_Reg32(arb->base + offset);

		offset = arb->dbgregs[PMIF_SWINF_0_RDATA_31_0] + swinf * step;
		rd_31_0 = DRV_Reg32(arb->base + offset);

		offset = arb->dbgregs[PMIF_SWINF_0_STA] + swinf * step;
		tmp_dat = DRV_Reg32(arb->base + offset);
		err = (tmp_dat & (0x1 << 18)) >> 18;
		sbusy = (tmp_dat & (0x1 << 17)) >> 17;
		done = (tmp_dat & (0x1 << 15)) >> 15;
		qfillcnt = (tmp_dat & (0xf << 11)) >> 11;
		qfreecnt = (tmp_dat & (0xf << 7)) >> 7;
		qempty = (tmp_dat & (0x1 << 6)) >> 6;
		qfull = (tmp_dat & (0x1 << 5)) >> 5;
		req = (tmp_dat & (0x1 << 4)) >> 4;
		fsm = (tmp_dat & (0x7 << 1)) >> 1;
		en = (tmp_dat & (0x1 << 0)) >> 0;

		PMIF_CRI("[swinf:%d, cmd:0x%x, is_write:%d, slvid:%d ",
			swinf, cmd, is_write, slvid);
		if (is_write) {
			PMIF_CRIL("bytecnt:%d (write addr 0x%x=0x%x)]\n",
				bytecnt, addr, wd_31_0);
		} else {
			PMIF_CRIL("bytecnt:%d (read addr 0x%x=0x%x)]\n",
				bytecnt, addr, rd_31_0);
		}
		PMIF_CRI("[err:%d, sbusy:%d, done:%d, qfillcnt:%d ",
			err, sbusy, done, qfillcnt);
		PMIF_CRIL("qfreecnt:%d, qempty:%d, qfull:%d, req:%d ",
			qfreecnt, qempty, qfull, req);
		PMIF_CRIL("fsm:%d, en:%d]\n", fsm, en);
	}
}

void spmi_dump_pmif_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int offset = 0, tmp_dat = 0;
	unsigned int start = 0, end = 0;
	int i = 0;

	start = arb->dbgregs[PMIF_INIT_DONE];
	end = arb->dbgregs[PMIF_RESERVED_0];

	PMIF_CRI("");
	for (offset = start; offset <= end; offset += 4) {
		tmp_dat = DRV_Reg32(arb->base + offset);
		PMIF_CRIL("(0x%x)=0x%x ", offset, tmp_dat);
		i++;
		if (i % 8 == 0)
			PMIF_CRIL("\n[PMIF] ");
	}
	PMIF_CRIL("\n");
	spmi_dump_pmif_swinf_reg(mstid);
}

void spmi_dump_pmif_record_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int i = 0, step = 0, offset = 0, tmp_dat = 0;
	unsigned int chan = 0, cmd = 0, is_write = 0, slvid = 0, bytecnt = 0, addr = 0;
	unsigned int wd_31_0 = 0;

	step = arb->dbgregs[PMIF_MONITOR_RECORD_1_0] - arb->dbgregs[PMIF_MONITOR_RECORD_0_0];

	for (i = 0; i < 32; i++) {
		offset = arb->dbgregs[PMIF_MONITOR_RECORD_0_0] + i * step;
		tmp_dat = DRV_Reg32(arb->base + offset);
		chan = (tmp_dat & (0xf8 << 27)) >> 27;
		cmd = (tmp_dat & (0x3 << 25)) >> 25;
		is_write = (tmp_dat & (0x1 << 24)) >> 24;
		slvid = (tmp_dat & (0xf << 20)) >> 20;
		bytecnt = (tmp_dat & (0xf << 16)) >> 16;
		addr = (tmp_dat & (0xffff << 0)) >> 0;

		offset = arb->dbgregs[PMIF_MONITOR_RECORD_0_1] + i * step;
		wd_31_0 = DRV_Reg32(arb->base + offset);

		PMIF_CRI("[swinf:%d, cmd:0x%x, rw:0x%x, slvid:%d, ",
			chan, cmd, is_write, slvid);
		PMIF_CRIL("bytecnt:%d, (addr 0x%x=0x%x)]\n",
			bytecnt, addr, wd_31_0);
	}
	/* logging mode no need to clear record */
}

void spmi_dump_spmimst_reg(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int offset = 0, tmp_dat = 0;
	unsigned int start = 0, end = 0;
	int i = 0;

	start = arb->spmimst_regs[SPMI_OP_ST_CTRL];
	end = arb->spmimst_regs[SPMI_REC4];

	SPMI_CRI("");
	for (offset = start; offset <= end; offset += 4) {
		tmp_dat = DRV_Reg32(arb->spmimst_base + offset);
		SPMI_CRIL("(0x%x)=0x%x ", offset, tmp_dat);
		i++;
		if (i % 8 == 0)
			SPMI_CRIL("\n[SPMI] ");
	}
#if SPMI_RCS_SUPPORT
	offset = arb->spmimst_regs[SPMI_DEC_DBG];
	tmp_dat = DRV_Reg32(arb->spmimst_base + offset);
	SPMI_CRIL("(0x%x)=0x%x ", offset, tmp_dat);
#endif
	offset = arb->spmimst_regs[SPMI_MST_DBG];
	tmp_dat = DRV_Reg32(arb->spmimst_base + offset);
	SPMI_CRIL("(0x%x)=0x%x\n", offset, tmp_dat);
}

int spmi_pmif_dbg_init(struct pmif *arb)
{
	arb->dbgregs = mt6xxx_pmif_dbg_regs;

	return 0;
}
#endif /* endif SPMI_NO_PMIC */