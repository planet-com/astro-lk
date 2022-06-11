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
#ifndef __PMIF_SW_H__
#define __PMIF_SW_H__

#define PMIF_PRELOADER		0
#define PMIF_LK			1
#define PMIF_KERNEL		0
#define PMIF_CTP		0

/* SW ENV define */
#define PMIF_DEBUG		0

/* Read/write byte limitation, by project */
#define PMIF_BYTECNT_MAX	1
#define PMIF_SRCLKEN_RC_EN	0

/* For BringUp. if BringUp doesn't had PMIC, need open this */
#if (PMIF_PRELOADER)
	#if CFG_FPGA_PLATFORM
		#define PMIF_NO_PMIC	1
	#else
		#define PMIF_NO_PMIC	0
		#define PMIF_TIMEOUT	0
	#endif
	#define PMIF_NORMAL_BOOT        1
#elif (PMIF_LK)
	#if defined(MACH_FPGA)
		#define PMIF_NO_PMIC	1
	#else
		#define PMIF_NO_PMIC	0
		#define PMIF_TIMEOUT	0
	#endif
	#define PMIF_NORMAL_BOOT        1
#elif (PMIF_CTP)
	#if defined(CONFIG_MTK_FPGA)
		#define PMIF_NO_PMIC	1
	#else
		#define PMIF_NO_PMIC	0
		#define PMIF_TIMEOUT	0
	#endif
	#define PMIF_NORMAL_BOOT        0
#else
	#define PMIF_NO_PMIC		1
	#define PMIF_TIMEOUT		0
#endif

/* SW ENV header define */
#if (PMIF_PRELOADER)
	#include <sync_write.h>
	#include <typedefs.h>
	#include <gpio.h>
	#include <mt6853.h>
	#include <pll.h>
	#include <pal_log.h>
	#define INIT_CRITICAL()
	#define ENTER_CRITICAL()
	#define EXIT_CRITICAL()
#elif (PMIF_LK)
	#include <debug.h>
	#include <platform/mt_typedefs.h>
	#include <platform/mt_reg_base.h>
	#include <platform/mt_gpt.h>
	#include <platform/mt_irq.h>
	#include <sys/types.h>
	#include <platform/sync_write.h>
	#include <platform/upmu_hw.h>
	#include <pal_log.h>
	#include <kernel/thread.h>
	#include <string.h>
	#define INIT_CRITICAL()
	#define ENTER_CRITICAL() enter_critical_section();
	#define EXIT_CRITICAL() exit_critical_section();
#elif (PMIF_KERNEL)
#elif (PMIF_CTP)
	#include <sync_write.h>
	#include <typedefs.h>
	#include <reg_base.H>
	#include <driver_api.h>
	#define INIT_CRITICAL()
	#define ENTER_CRITICAL()
	#define EXIT_CRITICAL()
#else
	### Compile error, check SW ENV define
#endif

/* DEBUG MARCO */
#define PMIFTAG		"[PMIF] "
#if (PMIF_PRELOADER)
	#if PMIF_DEBUG
		#define PMIF_CRI(fmt, arg...) pal_log_err(PMIFTAG fmt, ##arg)
		#define PMIF_CRIL(fmt, arg...) pal_log_err(fmt, ##arg)
		#define PMIF_ERR(fmt, arg...) \
			pal_log_err(PMIFTAG "%d: "fmt, __LINE__, ##arg)
		#define PMIF_WARN(fmt, arg...) pal_log_warn(PMIFTAG fmt, ##arg)
		#define PMIF_INFO(fmt, arg...) pal_log_info(PMIFTAG fmt, ##arg)
		#define PMIF_DBG(fmt, arg...) pal_log_debug(PMIFTAG fmt, ##arg)
	#else
		#define PMIF_CRI(fmt, arg...) pal_log_err(PMIFTAG fmt, ##arg)
		#define PMIF_CRIL(fmt, arg...) pal_log_err(fmt, ##arg)
		#define PMIF_ERR(fmt, arg...) pal_log_err(PMIFTAG fmt, ##arg)
		#define PMIF_WARN(fmt, arg...) pal_log_info(PMIFTAG fmt, ##arg)
		#define PMIF_INFO(fmt, arg...) do { } while(0)
		#define PMIF_DBG(fmt, arg...) do { } while(0)
	#endif
#elif (PMIF_LK)
	#if PMIF_DEBUG
		#define PMIF_CRI(fmt, arg...) pal_log_err(PMIFTAG fmt, ##arg)
		#define PMIF_CRIL(fmt, arg...) pal_log_err(fmt, ##arg)
		#define PMIF_ERR(fmt, arg...) \
			pal_log_err(PMIFTAG "%d: "fmt, __LINE__, ##arg)
		#define PMIF_WARN(fmt, arg...) pal_log_warn(PMIFTAG fmt, ##arg)
		#define PMIF_INFO(fmt, arg...) pal_log_info(PMIFTAG fmt, ##arg)
		#define PMIF_DBG(fmt, arg...) pal_log_debug(PMIFTAG fmt, ##arg)
	#else
		#define PMIF_CRI(fmt, arg...) pal_log_err(PMIFTAG fmt, ##arg)
		#define PMIF_CRIL(fmt, arg...) pal_log_err(fmt, ##arg)
		#define PMIF_ERR(fmt, arg...) pal_log_err(PMIFTAG fmt, ##arg)
		#define PMIF_WARN(fmt, arg...) pal_log_info(PMIFTAG fmt, ##arg)
		#define PMIF_INFO(fmt, arg...) do { } while(0)
		#define PMIF_DBG(fmt, arg...) do { } while(0)
	#endif
#elif (PMIF_KERNEL)
#elif (PMIF_CTP)
	#ifdef PMIF_DEBUG
		#define PMIF_CRI(fmt, arg...) dbg_print(PMIFTAG fmt, ##arg)
		#define PMIF_CRIL(fmt, arg...) dbg_print(fmt, ##arg)
		#define PMIF_ERR(fmt, arg...) \
			dbg_print(PMIFTAG "%d: "fmt, __LINE__, ##arg)
		#define PMIF_WARN(fmt, arg...) dbg_print(PMIFTAG fmt, ##arg)
		#define PMIF_INFO(fmt, arg...) dbg_print(PMIFTAG fmt, ##arg)
		#define PMIF_DBG(fmt, arg...) dbg_print(PMIFTAG fmt, ##arg)
	#else
		#define PMIF_CRI(fmt, arg...) dbg_print(PMIFTAG fmt, ##arg)
		#define PMIF_CRIL(fmt, arg...) dbg_print(fmt, ##arg)
		#define PMIF_ERR(fmt, arg...) dbg_print(PMIFTAG fmt, ##arg)
		#define PMIF_WARN(fmt, arg...) dbg_print(PMIFTAG fmt, ##arg)
		#define PMIF_INFO(fmt, arg...) do { } while(0)
		#define PMIF_DBG(fmt, arg...) do { } while(0)
	#endif /* end of #ifdef PMIF_DEBUG */
#else
	### Compile error, check SW ENV define
#endif

/* macro for SWINF_FSM */
#define SWINF_FSM_IDLE		(0x00)
#define SWINF_FSM_REQ		(0x02)
#define SWINF_FSM_WFDLE		(0x04)
#define SWINF_FSM_WFVLDCLR	(0x06)
#define SWINF_INIT_DONE		(0x01)
/* indicate which number SW channel start, by project */
#define PMIF_SWINF_0_CHAN_NO	4
#define PMIF_SWINF_0_CHAN_NO_P	1
/* MD: 0, security domain: 1, AP: 2 */
#define PMIF_AP_SWINF_NO	2
/* 0: SPI, 1: SPMI */
#define PMIF_PMIFID		1
#define PMIF_PMIFID_2		2

#ifndef EIO
#define	EIO 5		/* I/O error */
#endif
#ifndef EBUSY
#define EBUSY	16  /* Device or resource busy */
#endif
#ifndef ENODEV
#define	ENODEV	19	/* No such device */
#endif
#ifndef EINVAL
#define EINVAL	22  /* Invalid argument */
#endif
#ifndef EOPNOTSUPP
#define EOPNOTSUPP	95  /* Operation not supported on transport endpoint */
#endif
#ifndef ETIMEDOUT
#define ETIMEDOUT	110 /* Connection timed out */
#endif

extern int spmi_pmif_dbg_init(struct pmif *arb);
#endif /*__PMIF_SW_H__*/
