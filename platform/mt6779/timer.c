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

#include <sys/types.h>
#include <debug.h>
#include <err.h>
#include <reg.h>
#include <platform/timer.h>

#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_gpt.h>
#include <platform/mt_irq.h>

#include <kernel/thread.h>

static time_t system_time = 0;
static volatile time_t ticks = 0;
static time_t tick_interval;

static platform_timer_callback time_callback;
static void *callback_arg;

#define AP_PERI_GLOBALCON_PDN0 (PERICFG_BASE+0x10)

#ifdef MACH_FPGA
#define TIMER_TICK_RATE 6000000
#else
#define TIMER_TICK_RATE 32768
#endif

static enum handler_return timer_irq(void *arg)
{
	ticks += tick_interval;
	return time_callback(callback_arg, ticks);
}

void lk_scheduler(void)
{
	//static enum handler_return ret;

	/* ack GPT5 irq */
	/* configure gpt5 to use 13MHZ clock during irq ack.
        * Reason: In 32K domain, the de-assert signal to GIC might delay several clocks. So
        *         there must have delay between ack GTP5 irq and ack GIC irq. Ohterwise the
        *         irq will come twice at one tick point.
        *         Switching to 13M, ack gpt5 irq flow speeds up to avoid problem.
        */
	DRV_WriteReg32(GPT5_CLK_REG , 0x00);
	DRV_WriteReg32(GPT_IRQACK_REG, 0x10);
	DRV_WriteReg32(GPT5_CON_REG, GPT_CLEAR);
	DRV_WriteReg32(GPT5_CON_REG, GPT_DISABLE);
	DRV_WriteReg32(GPT5_CLK_REG , 0x10);

	timer_irq(0);

	/*
	 * CAUTION! The de-assert signal to GIC might delay serveral clocks.
	 * Here must have enough delay to make sure the GPT signal had arrived GIC.
	 */
	/* ack GIC irq */
	mt_irq_ack(MT_GPT_IRQ_ID);

	/* enable GPT5 */
	DRV_WriteReg32(GPT5_CON_REG, GPT_ENABLE|GPT_MODE4_ONE_SHOT);

}

status_t platform_set_periodic_timer(platform_timer_callback callback, void *arg, time_t interval)
{
	time_callback = callback;
	tick_interval = interval;
	callback_arg  = arg;

	DRV_WriteReg32(GPT_IRQEN_REG, 0);
	DRV_WriteReg32(GPT_IRQACK_REG, 0x3f);

	mt_irq_set_sens(MT_GPT_IRQ_ID, MT65xx_LEVEL_SENSITIVE);
	mt_irq_set_polarity(MT_GPT_IRQ_ID, MT65xx_POLARITY_LOW);

	DRV_WriteReg32(GPT5_CON_REG, 0x02);
	DRV_WriteReg32(GPT_IRQACK_REG, 0x10);
	DRV_WriteReg32(GPT5_CLK_REG , 0x10);

	DRV_WriteReg32(GPT5_COMPARE_REG, TIMER_TICK_RATE*interval/1000);
	DRV_WriteReg32(GPT_IRQEN_REG, 0x10);

	mt_irq_unmask(MT_GPT_IRQ_ID);

	DRV_WriteReg32(GPT5_CON_REG, GPT_ENABLE|GPT_MODE4_ONE_SHOT);

	return NO_ERROR;
}

time_t current_time(void)
{
	return ticks;
}

static void gpt_power_on (bool bPowerOn)
{
	if (!bPowerOn) {
		DRV_SetReg32(AP_PERI_GLOBALCON_PDN0, 1<<13);
	} else {
		DRV_ClrReg32(AP_PERI_GLOBALCON_PDN0, 1<<13);
	}
}

void platform_early_init_timer(void)
{
	//dprintf(SPEW, "platform_early_init_timer\n");

	gpt_power_on(1);
}

