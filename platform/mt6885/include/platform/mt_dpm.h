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

#ifndef _MT_DPM_H_
#define _MT_DPM_H_

/*platform dependent address*/
#define DPM_VERSION         0x00000000  // DPM version
#define DPM_HWID            0x00006885  // DPM HWID
#define DPM_NUM             0x00000002  // DPM number
#define DPM_HEAD_SIZE       0x00000020  // DPM header size
#define DPM_DRAM_SIZE       0x00190000  // mblock_reserve requires max 100KB
#define DRAM_ADDR_MAX       0xFFFFFFFF  // max address can be remap
#define DPM_DM_OFFSET           0x8000  // 32KB
#define DPM_MAX_LEN             0x600   // dpm db cfg
#define DPM_DBG_LEN             0x48    // dpm dbg latch
#define DPM_CFG1_LEN            0x14    // dpm cfg1 latch
#define DPM_CFG2_LEN            0x8     // dpm cfg2 latch
#define DRAM_CHANNEL            0x4     // dramc AO latch
#define DDRPHY_LATCH_LEN        0x20    // ddrphy AO latch

#define DPM_PM1_SRAM_BASE        0x10900000
#define DPM_DM1_SRAM_BASE        0x10920000
#define DPM_PM2_SRAM_BASE        0x10A00000
#define DPM_DM2_SRAM_BASE        0x10A20000

#define DPM_CFG_CH0              0x10940000
#define DPM_CFG_CH1              0x10A40000

#define DPM_DBG_LATCH_CH0        0x10947380
#define DPM_DBG_LATCH_CH1        0x10A47380

#define DPM_CFG1_CH0             0x10940064
#define DPM_CFG1_CH1             0x10A40064
#define DPM_CFG2_CH0             0x1094014C
#define DPM_CFG2_CH1             0x10A4014C

#define DPM_BARGS_CH0_REG0       0x10946004
#define DPM_BARGS_CH0_REG1       0x10946008
#define DPM_BARGS_CH1_REG0       0x10A46004
#define DPM_BARGS_CH1_REG1       0x10A46008

#define DDRPHY_AO_CH0            0x10238000
#define DDRPHY_LATCH_OFFSET      0x1600
#define CHANNEL_OFFSET           0x10000

/*image name definition*/
#define DPM_PM       "dpmpm"
#define DPM_DM       "dpmdm"

int load_dpm(void);

#endif

