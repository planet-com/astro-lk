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
#ifndef __MT_SSPH_H__
#define __MT_SSPH_H__

#define SSPM_CFGREG_BASE    0x10440000

#define SSPM_INFO           (SSPM_CFGREG_BASE + 0x20)
#define SSPM_BACKUP         (SSPM_CFGREG_BASE + 0x24)
#define SSPM_TBUF_WPTR      (SSPM_CFGREG_BASE + 0x4C)
#define SSPM_PC             (SSPM_CFGREG_BASE + 0x64)
#define SSPM_AHB_STATUS     (SSPM_CFGREG_BASE + 0x6C)
#define SSPM_AHB_M0_ADDR    (SSPM_CFGREG_BASE + 0x70)
#define SSPM_AHB_M1_ADDR    (SSPM_CFGREG_BASE + 0x74)
#define SSPM_AHB_M2_ADDR    (SSPM_CFGREG_BASE + 0xBC)
#define SSPM_LASTK_SZ       (SSPM_CFGREG_BASE + 0x114)
#define SSPM_LASTK_ADDR     (SSPM_CFGREG_BASE + 0x118)
#define SSPM_DATA_SZ        (SSPM_CFGREG_BASE + 0x11C)
#define SSPM_DATA_ADDR      (SSPM_CFGREG_BASE + 0x120)
#define SSPM_RM_ADDR        (SSPM_CFGREG_BASE + 0x128)
#define SSPM_RM_SZ          (SSPM_CFGREG_BASE + 0x12C)
#define SSPM_DM_ADDR        (SSPM_CFGREG_BASE + 0x130)
#define SSPM_DM_SZ          (SSPM_CFGREG_BASE + 0x134)
#define SSPM_SP             (SSPM_CFGREG_BASE + 0x14C)
#define SSPM_LR             (SSPM_CFGREG_BASE + 0x150)
#define SSPM_TBUFL          (SSPM_CFGREG_BASE + 0x154)
#define SSPM_TBUFH          (SSPM_CFGREG_BASE + 0x158)
#define SSPM_DBG_SEL        (SSPM_CFGREG_BASE + 0x15C)

#define SSPM_DATA_BUF_SZ    0x400 //same as the size of AEE_LKDUMP_SSPM_DATA
#define SSPM_COREDUP_RETRY  10

#define SYSRAM_START    0x40100000
#define SYSRAM_END      0x40120000
#define DRAM_START      0x80000000

#endif /* __MT_SSPH_H__ */

