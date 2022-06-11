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
#ifndef __SPMI_SW_H__
#define __SPMI_SW_H__

#define SPMI_PRELOADER		0
#define SPMI_LK			1
#define SPMI_KERNEL		0
#define SPMI_CTP		0

/* SW ENV define */
#define SPMI_DEBUG		0
#define SPMI_EXTADDR_SUPPORT	0
#define SPMI_MONITOR_SUPPORT	0
#if defined MTK_5G_B_MT6360_MT6315
#define SPMI_RCS_SUPPORT	0
#else
#define SPMI_RCS_SUPPORT	0
#endif
/* for evb or fpga used */
#define MT63xx_EVB		1

/* For BringUp. if BringUp doesn't had PMIC, need open this */
#if (SPMI_PRELOADER)
	#if CFG_FPGA_PLATFORM
		#define SPMI_NO_PMIC	1
	#else
		#define SPMI_NO_PMIC	0
		#define SPMI_TIMEOUT	0
	#endif
#elif (SPMI_LK)
	#if defined(MACH_FPGA)
		#define SPMI_NO_PMIC	1
	#else
		#define SPMI_NO_PMIC	0
		#define SPMI_TIMEOUT	0
	#endif
#elif (SPMI_CTP)
	#if defined(CONFIG_MTK_FPGA)
		#define SPMI_NO_PMIC	1
	#else
		#define SPMI_NO_PMIC	0
		#define SPMI_TIMEOUT	0
	#endif
#else
	#define SPMI_NO_PMIC		1
	#define SPMI_TIMEOUT		0
#endif

/* SW ENV header define */
#if (SPMI_PRELOADER)
	#include <sync_write.h>
	#include <typedefs.h>
	#include <gpio.h>
	#include <mt6853.h>
	#include <pll.h>
	#include <pal_log.h>
#elif (SPMI_LK)
	#include <debug.h>
	#include <platform/mt_typedefs.h>
	#include <platform/mt_reg_base.h>
	#include <platform/mt_gpt.h>
	#include <platform/mt_irq.h>
	#include <sys/types.h>
	#include <platform/sync_write.h>
	#include <platform/upmu_hw.h>
	#include <pal_log.h>
#elif (SPMI_KERNEL)
#elif (SPMI_CTP)
	#include <sync_write.h>
	#include <typedefs.h>
	#include <reg_base.H>
	#include <driver_api.h>
	#include <common.h>
	#include <kallsyms.h>
#else
	### Compile error, check SW ENV define
#endif

/* DEBUG MARCO */
#define SPMITAG		"[SPMI] "
#if (SPMI_PRELOADER)
	#if SPMI_DEBUG
		#define SPMI_CRI(fmt, arg...) pal_log_err(SPMITAG fmt, ##arg)
		#define SPMI_CRIL(fmt, arg...) pal_log_err(fmt, ##arg)
		#define SPMI_ERR(fmt, arg...) \
			pal_log_err(SPMITAG "%d: "fmt, __LINE__, ##arg)
		#define SPMI_WARN(fmt, arg...) pal_log_warn(SPMITAG fmt, ##arg)
		#define SPMI_INFO(fmt, arg...) pal_log_info(SPMITAG fmt, ##arg)
		#define SPMI_DBG(fmt, arg...) pal_log_debug(SPMITAG fmt, ##arg)
	#else
		#define SPMI_CRI(fmt, arg...) pal_log_err(SPMITAG fmt, ##arg)
		#define SPMI_CRIL(fmt, arg...) pal_log_err(fmt, ##arg)
		#define SPMI_ERR(fmt, arg...) \
			pal_log_err(SPMITAG "%d: "fmt, __LINE__, ##arg)
		#define SPMI_WARN(fmt, arg...) pal_log_info(SPMITAG fmt, ##arg)
		#define SPMI_INFO(fmt, arg...) do { } while(0)
		#define SPMI_DBG(fmt, arg...) do { } while(0)
	#endif
#elif (SPMI_LK)
	#if SPMI_DEBUG
		#define SPMI_CRI(fmt, arg...) pal_log_err(SPMITAG fmt, ##arg)
		#define SPMI_CRIL(fmt, arg...) pal_log_err(fmt, ##arg)
		#define SPMI_ERR(fmt, arg...) \
			pal_log_err(SPMITAG "%d: "fmt, __LINE__, ##arg)
		#define SPMI_WARN(fmt, arg...) pal_log_warn(SPMITAG fmt, ##arg)
		#define SPMI_INFO(fmt, arg...) pal_log_info(SPMITAG fmt, ##arg)
		#define SPMI_DBG(fmt, arg...) pal_log_debug(SPMITAG fmt, ##arg)
	#else
		#define SPMI_CRI(fmt, arg...) pal_log_err(SPMITAG fmt, ##arg)
		#define SPMI_CRIL(fmt, arg...) pal_log_err(fmt, ##arg)
		#define SPMI_ERR(fmt, arg...) \
			pal_log_err(SPMITAG "%d: "fmt, __LINE__, ##arg)
		#define SPMI_WARN(fmt, arg...) pal_log_info(SPMITAG fmt, ##arg)
		#define SPMI_INFO(fmt, arg...) do { } while(0)
		#define SPMI_DBG(fmt, arg...) do { } while(0)
	#endif
#elif (SPMI_KERNEL)
#elif (SPMI_CTP)
	#ifdef SPMI_DEBUG
		#define SPMI_CRI(fmt, arg...) dbg_print(SPMITAG fmt, ##arg)
		#define SPMI_CRIL(fmt, arg...) dbg_print(fmt, ##arg)
		#define SPMI_ERR(fmt, arg...) \
			dbg_print(SPMITAG "%d: "fmt, __LINE__, ##arg)
		#define SPMI_WARN(fmt, arg...) dbg_print(SPMITAG fmt, ##arg)
		#define SPMI_INFO(fmt, arg...) dbg_print(SPMITAG fmt, ##arg)
		#define SPMI_DBG(fmt, arg...) dbg_print(SPMITAG fmt, ##arg)
	#else
		#define SPMI_CRI(fmt, arg...) dbg_print(SPMITAG fmt, ##arg)
		#define SPMI_CRIL(fmt, arg...) dbg_print(fmt, ##arg)
		#define SPMI_ERR(fmt, arg...) dbg_print(SPMITAG fmt, ##arg)
		#define SPMI_WARN(fmt, arg...) dbg_print(SPMITAG fmt, ##arg)
		#define SPMI_INFO(fmt, arg...) do { } while(0)
		#define SPMI_DBG(fmt, arg...) do { } while(0)
	#endif /* end of #ifdef SPMI_DEBUG */
#else
	### Compile error, check SW ENV define
#endif

#define DEFAULT_VALUE_READ_TEST		(0x5a)
#define DEFAULT_VALUE_WRITE_TEST	(0xa5)

#define GET_REC_CMD(x)				(x & 0x00000003)
#define GET_REC_W(x)				((x>>2) & 0x00000001)
#define GET_REC_OP_ST_NACK(x)			((x>>3) & 0x00000001)
#define GET_REC_PMIF_NACK(x)			((x>>4) & 0x00000001)
#define GET_REC_PMIF_PARITY_ERR(x)		((x>>5) & 0x00000001)
#define GET_REC_PMIF_BYTE_ERR(x)		((x>>6) & 0x00000001)
#define GET_REC_PMIF_GRP_RD_ERR(x)		((x>>7) & 0x00000001)
#define GET_REC_SLVID(x)			((x>>8) & 0x0000000f)
#define GET_REC_BYTECNT(x)			((x>>12) & 0x0000000f)
#define GET_REC_ADDR(x)				((x>>16) & 0x0000ffff)

enum
{
	SPMI_OP_ST_BUSY = 1,
	SPMI_OP_ST_ACK = 0,
	SPMI_OP_ST_NACK = 1
};

enum
{
	SPMI_RCS_SR_BIT,
	SPMI_RCS_A_BIT
};

enum
{
	SPMI_RCS_MST_W = 1,
	SPMI_RCS_SLV_W = 3
};

enum
{
	SPMI_RESET = 0,
	SPMI_SLEEP,
	SPMI_SHUTDOWN,
	SPMI_WAKEUP
};

enum spmi_regs {
	SPMI_OP_ST_CTRL,
	SPMI_GRP_ID_EN,
	SPMI_OP_ST_STA,
	SPMI_MST_SAMPL,
	SPMI_MST_REQ_EN,
	/* RCS support */
#if SPMI_RCS_SUPPORT
	SPMI_RCS_CTRL,
	SPMI_SLV_3_0_EINT,
	SPMI_SLV_7_4_EINT,
	SPMI_SLV_B_8_EINT,
	SPMI_SLV_F_C_EINT,
#endif
	SPMI_REC_CTRL,
	SPMI_REC0,
	SPMI_REC1,
	SPMI_REC2,
	SPMI_REC3,
	SPMI_REC4,
#if SPMI_RCS_SUPPORT
	SPMI_REC_CMD_DEC,
	SPMI_DEC_DBG,
#endif
	SPMI_MST_DBG
};

extern int spmi_enable_group_id(int mstid, unsigned int grpiden);
extern struct spmi_device *get_spmi_device(int mstid, int slaveid);
extern u32 spmi_readl(int mstid, enum spmi_regs reg);
extern void spmi_writel(int mstid, enum spmi_regs reg, unsigned int val);
extern int spmi_init(struct pmif *pmif_arb);

/* pmif debug API declaration */
extern void spmi_dump_pmif_reg(int mstid);
extern void spmi_dump_pmif_record_reg(int mstid);
extern void spmi_dump_pmif_swinf_reg(int mstid);
extern void spmi_dump_pmif_busy_reg(int mstid);
/* spmi debug API declaration */
extern void spmi_dump_spmimst_reg(int mstid);
extern void spmi_dump_mst_record_reg(int mstid);
#endif /*__SPMI_SW_H__*/
