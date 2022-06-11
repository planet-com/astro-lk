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
/******************************************************************************
 * MTK PMIC Wrapper Driver
 *
 * Copyright 2018 MediaTek Co.,Ltd.
 *
 * DESCRIPTION:
 *     This file provides API for other drivers to access PMIC registers
 *
 ******************************************************************************/

#include <mt_pmic_wrap_init.h>
#if (PMIC_WRAP_PRELOADER)
#elif (PMIC_WRAP_LK)
#elif (PMIC_WRAP_KERNEL)
#elif (PMIC_WRAP_CTP)
#include <gpio.h>
#include <upmu_hw.h>
#else
### Compile error, check SW ENV define
#endif

/************* marco    ******************************************************/
#if (PMIC_WRAP_PRELOADER)
#elif (PMIC_WRAP_LK)
#elif (PMIC_WRAP_KERNEL)
#elif (PMIC_WRAP_SCP)
#elif (PMIC_WRAP_CTP)
#else
### Compile error, check SW ENV define
#endif

#ifdef PMIC_WRAP_NO_PMIC
#if !(PMIC_WRAP_KERNEL)
signed int pwrap_wacs2(unsigned int write, unsigned int adr,
	unsigned int wdata, unsigned int *rdata)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_read(unsigned int adr, unsigned int *rdata)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_write(unsigned int adr, unsigned int wdata)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}
#endif
signed int pwrap_wacs2_read(unsigned int  adr, unsigned int *rdata)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}

/* Provide PMIC write API */
signed int pwrap_wacs2_write(unsigned int  adr, unsigned int  wdata)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_read_nochk(unsigned int adr, unsigned int *rdata)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_write_nochk(unsigned int adr, unsigned int wdata)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}

/*
 * pmic_wrap init, init wrap interface
 */
signed int pwrap_init(void)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_init_preloader(void)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}

signed int pwrap_init_lk(void)
{
	PWRAPLOG("PMIC_WRAP do Nothing.\n");
	return 0;
}
#else /* #ifdef PMIC_WRAP_NO_PMIC */
/*********************start ---internal API***********************************/
static int _pwrap_timeout_ns(unsigned long long start_time_ns,
	unsigned long long timeout_time_ns);
static unsigned long long _pwrap_get_current_time(void);
static unsigned long long _pwrap_time2ns(unsigned long long time_us);
static signed int _pwrap_wacs2_nochk(unsigned int write, unsigned int adr,
	unsigned int wdata, unsigned int *rdata);
static signed int _pwrap_swinf_acc_nochk(unsigned int swinf_no, unsigned int cmd,
	unsigned int write, unsigned int pmifid, unsigned int slvid, unsigned int addr, unsigned int bytecnt,
	unsigned int wdata, unsigned int *rdata);
static signed int _pwrap_swinf_acc(unsigned int swinf_no, unsigned int cmd,
	unsigned int write, unsigned int pmifid, unsigned int slvid, unsigned int addr, unsigned int bytecnt,
	unsigned int wdata, unsigned int *rdata);
/*********************test API************************************************/
static inline void pwrap_dump_ap_register(void);
static unsigned int pwrap_write_test(void);
static unsigned int pwrap_read_test(void);
static signed int pwrap_reset_pattern(void);
signed int pwrap_wacs2_read(unsigned int  adr, unsigned int *rdata);
signed int pwrap_wacs2_write(unsigned int  adr, unsigned int  wdata);
static unsigned int si_sample_ctrl = 0;
static struct pwrap_rc_info {
	unsigned int swinf_cmd;
	unsigned int other_inf_en;
	unsigned int spi_mode_ctrl;
	unsigned int sleep_protect_ctrl;
	unsigned int dcxo_cmd_adr0;
	unsigned int dcxo_cmd_wdata0;
	unsigned int dcxo_cmd_adr1;
	unsigned int dcxo_cmd_wdata1;
	unsigned int gps_auxadc_addr;
	unsigned int gps_auxadc_cmd;
	unsigned int gps_auxadc_rdata;
};
/************* end--internal API**********************************************/
/*********************** external API for pmic_wrap user *********************/
signed int pwrap_wacs2_read(unsigned int adr, unsigned int *rdata)
{
	_pwrap_swinf_acc(PMIF_SPI_AP_SWINF_NO, DEFAULT_CMD, 0, PMIF_SPI_PMIFID,
			  DEFAULT_SLVID, adr, DEFAULT_BYTECNT, 0x0, rdata);
	return 0;
}

/* Provide PMIC write API */
signed int pwrap_wacs2_write(unsigned int adr, unsigned int wdata)
{
#ifdef CONFIG_MTK_TINYSYS_SSPM_SUPPORT
	unsigned int flag;

	flag = WRITE_CMD | (1 << WRITE_PMIC);
	pwrap_wacs2_ipi(adr, wdata, flag);
#else
	_pwrap_swinf_acc(PMIF_SPI_AP_SWINF_NO, DEFAULT_CMD, 1, PMIF_SPI_PMIFID,
			DEFAULT_SLVID, adr, DEFAULT_BYTECNT, wdata, 0x0);
#endif
	return 0;
}

signed int pwrap_read(unsigned int adr, unsigned int *rdata)
{
	return _pwrap_swinf_acc(PMIF_SPI_AP_SWINF_NO, DEFAULT_CMD, 0, PMIF_SPI_PMIFID,
			DEFAULT_SLVID, adr, DEFAULT_BYTECNT, 0x0, rdata);
}

signed int pwrap_write(unsigned int adr, unsigned int wdata)
{
	return _pwrap_swinf_acc(PMIF_SPI_AP_SWINF_NO, DEFAULT_CMD, 1, PMIF_SPI_PMIFID,
			DEFAULT_SLVID, adr, DEFAULT_BYTECNT, wdata, 0x0);
}
/******************************************************************************
 * wrapper timeout
 *****************************************************************************/
/* use the same API name with kernel driver
 * however,the timeout API in uboot use tick instead of ns
 */
#ifdef PWRAP_TIMEOUT
static unsigned long long _pwrap_get_current_time(void)
{
	return gpt4_get_current_tick();
}

static int _pwrap_timeout_ns(unsigned long long start_time_ns,
	unsigned long long timeout_time_ns)
{
	return gpt4_timeout_tick(start_time_ns, timeout_time_ns);
}

static unsigned long long _pwrap_time2ns(unsigned long long time_us)
{
	return gpt4_time2tick_us(time_us);
}

#else
static unsigned long long _pwrap_get_current_time(void)
{
	return 0;
}

static int _pwrap_timeout_ns(unsigned long long start_time_ns,
	unsigned long long elapse_time)
{
	return 0;
}

static unsigned long long _pwrap_time2ns(unsigned long long time_us)
{
	return 0;
}

#endif /* #ifdef PWRAP_TIMEOUT */

/* ##################################################################### */
/* define macro and inline function (for do while loop) */
/* ##################################################################### */
typedef unsigned int(*loop_condition_fp) (unsigned int);  /* define a function pointer */

static inline unsigned int wait_for_fsm_idle(unsigned int x)
{
	return GET_SWINF_2_FSM(x) != WACS_FSM_IDLE;
}

static inline unsigned int wait_for_fsm_vldclr(unsigned int x)
{
	return GET_SWINF_2_FSM(x) != WACS_FSM_WFVLDCLR;
}

static inline unsigned int wait_for_sync(unsigned int x)
{
	return GET_SYNC_IDLE2(x) != WACS_SYNC_IDLE;
}

static inline unsigned int wait_for_idle_and_sync(unsigned int x)
{
	return (GET_WACS2_FSM(x) != WACS_FSM_IDLE) ||
		(GET_SYNC_IDLE2(x) != WACS_SYNC_IDLE);
}

static inline unsigned int wait_for_wrap_idle(unsigned int x)
{
	return (GET_WRAP_FSM(x) != 0x0) || (GET_WRAP_CH_DLE_RESTCNT(x) != 0x0);
}

static inline unsigned int wait_for_wrap_state_idle(unsigned int x)
{
	return GET_WRAP_AG_DLE_RESTCNT(x) != 0;
}

static inline unsigned int wait_for_man_idle_and_noreq(unsigned int x)
{
	return (GET_MAN_REQ(x) != MAN_FSM_NO_REQ) ||
		(GET_MAN_FSM(x) != MAN_FSM_IDLE);
}

static inline unsigned int wait_for_man_vldclr(unsigned int x)
{
	return GET_MAN_FSM(x) != MAN_FSM_WFVLDCLR;
}

static inline unsigned int wait_for_cipher_ready(unsigned int x)
{
	return x != 3;
}

static inline unsigned int wait_for_stdupd_idle(unsigned int x)
{
	return GET_STAUPD_FSM(x) != 0x0;
}

/**************used at _pwrap_wacs2_nochk*************************************/
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
static inline unsigned int wait_for_state_ready_init(loop_condition_fp fp,
	unsigned int timeout_us, void *wacs_register, unsigned int *read_reg)
#else
static inline unsigned int wait_for_state_ready_init(loop_condition_fp fp,
	unsigned int timeout_us, unsigned int *wacs_register,
	unsigned int *read_reg)
#endif
{
	unsigned long long start_time_ns = 0, timeout_ns = 0;
	unsigned int reg_rdata = 0x0;

	start_time_ns = _pwrap_get_current_time();
	timeout_ns = _pwrap_time2ns(timeout_us);

	do {
		if (_pwrap_timeout_ns(start_time_ns, timeout_ns)) {
			PWRAPERR("ready_init timeout\n");
			pwrap_dump_ap_register();
			return E_PWR_WAIT_IDLE_TIMEOUT;
		}
		reg_rdata = WRAP_RD32(wacs_register);
	} while (fp(reg_rdata));

	if (read_reg)
		*read_reg = reg_rdata;

	return 0;
}

#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
static inline unsigned int wait_for_state_idle(loop_condition_fp fp,
	unsigned int timeout_us, void *wacs_register,
	void *wacs_vldclr_register, unsigned int *read_reg)
#else
static inline unsigned int wait_for_state_idle(loop_condition_fp fp,
	unsigned int timeout_us, unsigned int *wacs_register,
	unsigned int *wacs_vldclr_register, unsigned int *read_reg)
#endif
{
	unsigned long long start_time_ns = 0, timeout_ns = 0;
	unsigned int reg_rdata;

	start_time_ns = _pwrap_get_current_time();
	timeout_ns = _pwrap_time2ns(timeout_us);

	do {
		if (_pwrap_timeout_ns(start_time_ns, timeout_ns)) {
			PWRAPERR("state_idle timeout\n");
			pwrap_dump_ap_register();
			return E_PWR_WAIT_IDLE_TIMEOUT;
		}
		reg_rdata = WRAP_RD32(wacs_register);
		if (GET_SWINF_2_INIT_DONE(reg_rdata) != WACS_INIT_DONE) {
			PWRAPERR("init isn't finished\n");
			pwrap_dump_ap_register();
			return E_PWR_NOT_INIT_DONE;
		}
		switch (GET_SWINF_2_FSM(reg_rdata)) {
			case WACS_FSM_WFVLDCLR:
				WRAP_WR32(wacs_vldclr_register, 1);
				PWRAPERR("WACS_FSM = VLDCLR\n");
				break;
			case WACS_FSM_WFDLE:
				PWRAPERR("WACS_FSM = WFDLE\n");
				break;
			case WACS_FSM_REQ:
				PWRAPERR("WACS_FSM = REQ\n");
				break;
			default:
				break;
		}
	} while (fp(reg_rdata));
	if (read_reg)
		*read_reg = reg_rdata;

	return 0;
}

/**************used at pwrap_wacs2********************************************/
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
static inline unsigned int wait_for_state_ready(loop_condition_fp fp,
	unsigned int timeout_us, void *wacs_register, unsigned int *read_reg)
#else
static inline unsigned int wait_for_state_ready(loop_condition_fp fp,
	unsigned int timeout_us, unsigned int *wacs_register,
	unsigned int *read_reg)
#endif
{
	unsigned long long start_time_ns = 0, timeout_ns = 0;
	unsigned int reg_rdata;

	start_time_ns = _pwrap_get_current_time();
	timeout_ns = _pwrap_time2ns(timeout_us);

	do {
		if (_pwrap_timeout_ns(start_time_ns, timeout_ns)) {
			PWRAPERR("state_ready timeout\n");
			pwrap_dump_ap_register();
			return E_PWR_WAIT_IDLE_TIMEOUT;
		}
		reg_rdata = WRAP_RD32(wacs_register);
		if (GET_SWINF_2_INIT_DONE(reg_rdata) != WACS_INIT_DONE) {
			PWRAPERR("init isn't finished\n");
			pwrap_dump_ap_register();
			return E_PWR_NOT_INIT_DONE;
		}
	} while (fp(reg_rdata));
	if (read_reg)
		*read_reg = reg_rdata;

	return 0;
}

/*********************internal API for pwrap_init***************************/

signed int pwrap_read_nochk(unsigned int adr, unsigned int *rdata)
{
	return _pwrap_swinf_acc_nochk(PMIF_SPI_AP_SWINF_NO, DEFAULT_CMD, 0, PMIF_SPI_PMIFID,
						DEFAULT_SLVID, adr, DEFAULT_BYTECNT, 0x0, rdata);
}

signed int pwrap_write_nochk(unsigned int adr, unsigned int wdata)
{
	return _pwrap_swinf_acc_nochk(PMIF_SPI_AP_SWINF_NO, DEFAULT_CMD, 1, PMIF_SPI_PMIFID,
						DEFAULT_SLVID, adr, DEFAULT_BYTECNT, wdata, 0x0);
}

signed int _pwrap_swinf_acc(unsigned int swinf_no, unsigned int cmd,
	unsigned int write, unsigned int pmifid, unsigned int slvid, unsigned int addr, unsigned int bytecnt,
	unsigned int wdata, unsigned int *rdata)
{
	unsigned int reg_rdata = 0x0;
	unsigned int wacs_write = 0x0;
	unsigned int wacs_adr = 0x0;
	unsigned int wacs_cmd = 0x0;
	unsigned int return_value = 0x0;

	/* Check argument validation */
	if ((swinf_no & ~(0x3)) != 0)
		return E_PWR_INVALID_SWINF;
	if ((cmd & ~(0x3)) != 0)
		return E_PWR_INVALID_CMD;
	if ((write & ~(0x1)) != 0)
		return E_PWR_INVALID_RW;
	if ((pmifid & ~(0x1)) != 0)
		return E_PWR_INVALID_PMIFID;
	if ((slvid & ~(0xf)) != 0)
		return E_PWR_INVALID_SLVID;
	if ((addr & ~(0xffff)) != 0)
		return E_PWR_INVALID_ADDR;
	if ((bytecnt & ~(0x1)) != 0)
		return E_PWR_INVALID_BYTECNT;
	if ((wdata & ~(0xffff)) != 0)
		return E_PWR_INVALID_WDAT;

	enter_critical_section();

	/* Check whether INIT_DONE is set */
	if (pmifid == 0)
		reg_rdata = WRAP_RD32(PMIF_SPI_PMIF_SWINF_0_STA + 0x40 * swinf_no);

	if (GET_SWINF_2_INIT_DONE(reg_rdata) != 0x1) {
		exit_critical_section();
		return E_PWR_NOT_INIT_DONE;
	}

	/* Wait for Software Interface FSM state to be IDLE */
	while (GET_SWINF_2_FSM(reg_rdata) != 0x0) {
		if (pmifid == 0)
			reg_rdata = WRAP_RD32(PMIF_SPI_PMIF_SWINF_0_STA + 0x40 * swinf_no);
	}

	/* Set the write data */
	if (write == 1) {
		if(pmifid == 0)
			WRAP_WR32(PMIF_SPI_PMIF_SWINF_0_WDATA_31_0 + 0x40 * swinf_no, wdata);
	}

	/* Send the command */
	if (pmifid == 0)
		WRAP_WR32(PMIF_SPI_PMIF_SWINF_0_ACC + 0x40 * swinf_no,
			  (cmd << 30) | (write << 29) | (slvid << 24) | (bytecnt << 16) | addr);

	if (write == 0) {
		/* Wait for Software Interface FSM to be WFVLDCLR, read the data and clear the valid flag */
		do {
			if (pmifid == 0)
				reg_rdata = WRAP_RD32(PMIF_SPI_PMIF_SWINF_0_STA + 0x40 * swinf_no);
		} while (GET_SWINF_2_FSM(reg_rdata) != 0x6);

		if (pmifid == 0)
			*rdata = WRAP_RD32(PMIF_SPI_PMIF_SWINF_0_RDATA_31_0 + 0x40 * swinf_no);

		if (pmifid == 0)
			WRAP_WR32(PMIF_SPI_PMIF_SWINF_0_VLD_CLR + 0x40 * swinf_no, 0x1);
	}

	exit_critical_section();

	return 0;
}

static signed int _pwrap_swinf_acc_nochk(unsigned int swinf_no, unsigned int cmd,
	unsigned int write, unsigned int pmifid, unsigned int slvid, unsigned int addr, unsigned int bytecnt,
	unsigned int wdata, unsigned int *rdata)
{
	unsigned int reg_rdata = 0x0;
	unsigned int wacs_write = 0x0;
	unsigned int wacs_adr = 0x0;
	unsigned int wacs_cmd = 0x0;
	unsigned int return_value = 0x0;

	/* Check argument validation */
	if ((swinf_no & ~(0x3)) != 0)
		return E_PWR_INVALID_SWINF;
	if ((cmd & ~(0x3)) != 0)
		return E_PWR_INVALID_CMD;
	if ((write & ~(0x1)) != 0)
		return E_PWR_INVALID_RW;
	if ((pmifid & ~(0x1)) != 0)
		return E_PWR_INVALID_PMIFID;
	if ((slvid & ~(0xf)) != 0)
		return E_PWR_INVALID_SLVID;
	if ((addr & ~(0xffff)) != 0)
		return E_PWR_INVALID_ADDR;
	if ((bytecnt & ~(0x1)) != 0)
		return E_PWR_INVALID_BYTECNT;
	if ((wdata & ~(0xffff)) != 0)
		return E_PWR_INVALID_WDAT;

	enter_critical_section();

	/* Wait for Software Interface FSM state to be IDLE */
	do {
		if (pmifid == 0)
			reg_rdata = WRAP_RD32(PMIF_SPI_PMIF_SWINF_0_STA + 0x40 * swinf_no);
	} while (GET_SWINF_2_FSM(reg_rdata) != 0x0);

	/* Set the write data */
	if (write == 1) {
		if(pmifid == 0)
			WRAP_WR32(PMIF_SPI_PMIF_SWINF_0_WDATA_31_0 + 0x40 * swinf_no, wdata);
	}

	/* Send the command */
	if (pmifid == 0)
		WRAP_WR32(PMIF_SPI_PMIF_SWINF_0_ACC + 0x40 * swinf_no,
			  (cmd << 30) | (write << 29) | (slvid << 24) | (bytecnt << 16) | addr);

	if (write == 0) {
		/* Wait for Software Interface FSM to be WFVLDCLR, read the data and clear the valid flag */
		do {
			if (pmifid == 0)
				reg_rdata = WRAP_RD32(PMIF_SPI_PMIF_SWINF_0_STA + 0x40 * swinf_no);
		} while (GET_SWINF_2_FSM(reg_rdata) != 0x6);

		if (pmifid == 0)
			*rdata = WRAP_RD32(PMIF_SPI_PMIF_SWINF_0_RDATA_31_0 + 0x40 * swinf_no);

		if (pmifid == 0)
			WRAP_WR32(PMIF_SPI_PMIF_SWINF_0_VLD_CLR + 0x40 * swinf_no, 0x1);
	}

	exit_critical_section();

	return 0;
}

static void __pwrap_soft_reset(void)
{
	PWRAPLOG("start reset wrapper\n");
	WRAP_WR32(INFRA_GLOBALCON_RST2_SET, 0x1);
	WRAP_WR32(INFRA_GLOBALCON_RST2_CLR, 0x1);
}

static void __pwrap_spi_clk_set(void)
{
	/* Turn off SYS, TMR and SPI clocks */
	WRAP_WR32(MODULE_SW_CG_0_SET, 0x0000000f);

	PWRAPLOG("pwrap_spictl reset ok\n");

#ifndef MACH_FPGA
	/* Set ULPOSC clock to ULPOSC1/10 */
	WRAP_WR32(CLK_CFG_8_CLR, (0x1 << 15) | (0x1 << 12) | (0x7 << 8));
	WRAP_WR32(CLK_CFG_UPDATE1, 0x1 << 2);
#endif

	/* Disable Fixed 26M Clock Control by SPM */
	PWRAPLOG("PMICW_CLOCK_CTRL:0x%x(before)\n", WRAP_RD32(PMICW_CLOCK_CTRL));
	WRAP_WR32(PMICW_CLOCK_CTRL_CLR, 0xf);
	PWRAPLOG("PMICW_CLOCK_CTRL:0x%x(after)\n", WRAP_RD32(PMICW_CLOCK_CTRL));

	/* Toggle PMIC_WRAP and pwrap_spictl reset */
	__pwrap_soft_reset();

	/* Turn on SYS, TMR and SPI clocks */
	WRAP_WR32(MODULE_SW_CG_0_CLR, 0x0000000f);
	PWRAPLOG("spi clk set ....\n");
}

static void _pwrap_InitStaUpd(void)
{
	/* Signature mode */
	WRAP_WR32(PMIF_SPI_PMIF_SIG_MODE, 0x1);
	WRAP_WR32(PMIF_SPI_PMIF_PMIC_SIG_VAL, 0x83);
	WRAP_WR32(PMIF_SPI_PMIF_PMIC_SIG_ADDR, PMIC_DEW_CRC_VAL_ADDR);

	/* Setup PMIC EINT */
	WRAP_WR32(PMIF_SPI_PMIF_PMIC_EINT_STA_ADDR, PMIC_CPU_INT_STA_ADDR);

	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_LATEST_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_WP_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_0_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_1_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_2_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_3_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_4_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_5_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_6_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_7_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_8_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_9_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_10_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_11_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_12_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_13_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_14_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_15_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_16_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_17_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_18_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_19_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_20_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_21_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_22_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_23_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_24_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_25_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_26_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_27_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_28_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_29_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_30_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_MD_AUXADC_RDATA_31_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_AP_ADDR << 16) + PMIC_AUXADC_ADC_OUT_MDRT_ADDR);

	/* Internal GPS AUXADC Interface */
	WRAP_WR32(PMIF_SPI_PMIF_INT_GPS_AUXADC_CMD_ADDR, (PMIC_AUXADC_RQST_DCXO_BY_GPS_ADDR << 16) + PMIC_AUXADC_RQST_CH7_BY_GPS_ADDR);
	WRAP_WR32(PMIF_SPI_PMIF_INT_GPS_AUXADC_CMD, (0x0040 << 16) + 0x0010);
	WRAP_WR32(PMIF_SPI_PMIF_INT_GPS_AUXADC_RDATA_ADDR, (PMIC_AUXADC_ADC_OUT_DCXO_BY_GPS_ADDR << 16) + PMIC_AUXADC_ADC_OUT_CH7_BY_GPS_ADDR);

	/* Status Update Period and Items */
	WRAP_WR32(PMIF_SPI_PMIF_STAUPD_CTRL, (0x5  << 4) | 0x5);

}

static unsigned int pwrap_read_test(void)
{
	unsigned int rdata = 0;
	unsigned int return_value = 0;

	/* Read Test */
	PWRAPLOG("start pwrap_read_test\n");
	return_value = pwrap_wacs2_read(PMIC_DEW_READ_TEST_ADDR, &rdata);
	PWRAPLOG("rdata=0x%x\n", rdata);
	if (rdata != DEFAULT_VALUE_READ_TEST) {
		PWRAPERR("Error: r_rdata = 0x%x, exp = 0x5aa5\n", rdata);
		PWRAPERR("Error: return_value = 0x%x\n", return_value);
		return E_PWR_READ_TEST_FAIL;
	}
	else
		PWRAPLOG("Read Test pass, return_value = 0x%x\n", return_value);

	return 0;
}
static unsigned int pwrap_write_test(void)
{
	unsigned int rdata = 0;
	unsigned int sub_return = 0;
	unsigned int sub_return1 = 0;

	/* Write test using WACS2 */
	PWRAPLOG("start pwrap_write_test\n");
	sub_return = pwrap_wacs2_write(PMIC_DEW_WRITE_TEST_ADDR,
		DEFAULT_VALUE_WRITE_TEST);
	PWRAPLOG("after pwrap_write\n");
	sub_return1 = pwrap_wacs2_read(PMIC_DEW_WRITE_TEST_ADDR, &rdata);
	PWRAPLOG("rdata=0x%x (read back)\n", rdata);
	if ((rdata != DEFAULT_VALUE_WRITE_TEST) ||
	    (sub_return != 0) || (sub_return1 != 0)) {
		PWRAPERR("Error: w_rdata = 0x%x, exp = 0xa55a\n", rdata);
		PWRAPERR("Error: sub_return = 0x%x\n", sub_return);
		PWRAPERR("Error: sub_return1 = 0x%x\n", sub_return1);
		return E_PWR_INIT_WRITE_TEST;
	}
	else
		PWRAPLOG("Write Test pass\n");

	return 0;
}
static void pwrap_ut(unsigned int ut_test)
{
	unsigned int sub_return = 0;

	switch (ut_test) {
		case 1:
			pwrap_write_test();
			break;
		case 2:
			pwrap_read_test();
			break;
		case 3:
#ifdef CONFIG_MTK_TINYSYS_SSPM_SUPPORT
			pwrap_wacs2_ipi(0x10010000 + 0xD8, 0xffffffff, (WRITE_CMD | WRITE_PMIC_WRAP));
			break;
#endif
		case 4:
			sub_return = pwrap_write_nochk(PMIC_DEW_WRITE_TEST_ADDR, 0x1234);
			sub_return = pwrap_write_nochk(PMIC_DEW_WRITE_TEST_ADDR, 0x4321);
			sub_return = pwrap_write_nochk(PMIC_DEW_WRITE_TEST_ADDR, 0xF0F0);
			if (sub_return != 0) {
				PWRAPERR("w_t_fail, sub_return=%x\n", sub_return);
			}
			break;
		default:
			PWRAPLOG("default test\n");
			break;
	}
}

/*-------------------pwrap debug---------------------*/
static inline void pwrap_dump_ap_register(void)
{
	unsigned int i = 0, offset = 0;
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
	unsigned int *reg_addr;
#else
	unsigned int reg_addr;
#endif
	unsigned int reg_value = 0;

	PWRAPCRI("dump pmif reg\n");

	for (i = 0; i <= (PMIF_REG_RANGE/4); i++) {
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
		reg_addr = (unsigned int *) (PMIF_SPI_BASE + i * 4);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%p = 0x%x\n", reg_addr, reg_value);
#else
		reg_addr = (PMIF_SPI_BASE + i * 4);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%x = 0x%x\n", reg_addr, reg_value);
#endif
	}

	for (i = 0; i <= 10; i++) {
		offset = 0xc00 + i * 4;
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
		reg_addr = (unsigned int *) (PMIF_SPI_BASE + offset);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%p = 0x%x\n", reg_addr, reg_value);
#else
		reg_addr = (PMIF_SPI_BASE + offset);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%x = 0x%x\n", reg_addr, reg_value);
#endif
	}

	for (i = 0; i <= 10; i++) {
		offset = 0xc40 + i * 4;
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
		reg_addr = (unsigned int *) (PMIF_SPI_BASE + offset);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%p = 0x%x\n", reg_addr, reg_value);
#else
		reg_addr = (PMIF_SPI_BASE + offset);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%x = 0x%x\n", reg_addr, reg_value);
#endif
	}

	for (i = 0; i <= 10; i++) {
		offset = 0xc80 + i * 4;
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
		reg_addr = (unsigned int *) (PMIF_SPI_BASE + offset);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%p = 0x%x\n", reg_addr, reg_value);
#else
		reg_addr = (PMIF_SPI_BASE + offset);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%x = 0x%x\n", reg_addr, reg_value);
#endif
	}

	PWRAPCRI("dump pmicspi_mst reg\n");

	for (i = 0; i <= (PMICSPI_MST_REG_RANGE/4); i++) {
#if (PMIC_WRAP_KERNEL) || (PMIC_WRAP_CTP)
		reg_addr = (unsigned int *) (PMICSPI_MST_BASE + i * 4);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%p = 0x%x\n", reg_addr, reg_value);
#else
		reg_addr = (PMICSPI_MST_BASE + i * 4);
		reg_value = WRAP_RD32(reg_addr);
		PWRAPCRI("addr:0x%x = 0x%x\n", reg_addr, reg_value);
#endif
	}
}

void pwrap_dump_all_register(void)
{
	pwrap_dump_ap_register();
}

static int is_pwrap_init_done(void)
{
	int ret = 0;

	ret = WRAP_RD32(PMIF_SPI_PMIF_INIT_DONE);
	PWRAPLOG("is_pwrap_init_done %d\n", ret);
	if ((ret & 0x1) == 1)
		return 0;
	return E_PWR_NOT_INIT_DONE;
}

signed int pwrap_init_lk(void)
{
	PWRAPFUC();
	if (0 == is_pwrap_init_done()) {
		PWRAPLOG("wrap_init already init, do nothing\n");
		return 0;
	}

	return 0;
}

static signed int _pwrap_reset_spislv(void)
{
	unsigned int ret = 0;
	unsigned int rdata = 0;
	unsigned int return_value = 0;
	unsigned int pmicspi_mst_dio_en_backup = 0;

	WRAP_WR32(PMICSPI_MST_SPIWRAP_EN, 0x0);
	WRAP_WR32(PMICSPI_MST_SPIMUX_SEL, 0x1);
	WRAP_WR32(PMICSPI_MST_SPIMAN_EN, 0x1);
	pmicspi_mst_dio_en_backup = WRAP_RD32(PMICSPI_MST_DIO_EN);
	WRAP_WR32(PMICSPI_MST_DIO_EN, 0x0);

	WRAP_WR32(PMICSPI_MST_SPIMAN_ACC, (0x1 << 13) | (OP_CSL  << 8));
	WRAP_WR32(PMICSPI_MST_SPIMAN_ACC, (0x1 << 13) | (OP_OUTS << 8)); //Reset the counter.
	WRAP_WR32(PMICSPI_MST_SPIMAN_ACC, (0x1 << 13) | (OP_CSH  << 8));
	WRAP_WR32(PMICSPI_MST_SPIMAN_ACC, (0x1 << 13) | (OP_OUTS << 8));
	WRAP_WR32(PMICSPI_MST_SPIMAN_ACC, (0x1 << 13) | (OP_OUTS << 8));
	WRAP_WR32(PMICSPI_MST_SPIMAN_ACC, (0x1 << 13) | (OP_OUTS << 8));
	WRAP_WR32(PMICSPI_MST_SPIMAN_ACC, (0x1 << 13) | (OP_OUTS << 8));

	/* Wait for PMIC SPI Master to be idle */
	do {
		rdata = WRAP_RD32(PMICSPI_MST_OTHER_BUSY_STA_0);
	} while (GET_PMICSPI_BUSY(rdata) != 0x0);

	WRAP_WR32(PMICSPI_MST_SPIMAN_EN, 0x0);
	WRAP_WR32(PMICSPI_MST_SPIMUX_SEL, 0x0);
	WRAP_WR32(PMICSPI_MST_SPIWRAP_EN, 0x1);
	WRAP_WR32(PMICSPI_MST_DIO_EN, pmicspi_mst_dio_en_backup);

	return 0;
}

static signed int _pwrap_init_reg_clock_reset(unsigned int regck_sel)
{
	unsigned int rdata;

	/* Configure SPI protocol */
	WRAP_WR32(PMICSPI_MST_EXT_CK_WRITE, 0x1);
	WRAP_WR32(PMICSPI_MST_EXT_CK_READ, 0x0);
	WRAP_WR32(PMICSPI_MST_CSHEXT_WRITE, 0x0);
	WRAP_WR32(PMICSPI_MST_CSHEXT_READ, 0x0);
	WRAP_WR32(PMICSPI_MST_CSLEXT_WRITE, 0x0);
	WRAP_WR32(PMICSPI_MST_CSLEXT_READ, 0x0100);

	/* Set Read Dummy Cycle Number (Slave Clock is 18MHz) */
	WRAP_WR32(PMICSPI_MST_RDDMY, 0x8);
	PWRAPLOG("Set Read Dummy Cycle ok\n");

	/* Wait for completion of sending the commands */
	do {
		rdata = WRAP_RD32(PMIF_SPI_PMIF_INF_BUSY_STA);
	} while ((rdata & (0x1 << PMIF_SPI_AP_SWINF_CHAN_NO)) != 0x0);

	do {
		rdata = WRAP_RD32(PMIF_SPI_PMIF_OTHER_BUSY_STA_0);
	} while (GET_CMDISSUE_BUSY(rdata) != 0x0);

	do {
		rdata = WRAP_RD32(PMICSPI_MST_OTHER_BUSY_STA_0);
	} while (GET_PMICSPI_BUSY(rdata) != 0x0);

	/* Enable DIO mode */
	WRAP_WR32(PMICSPI_MST_DIO_EN, 0x1);
	PWRAPLOG("_pwrap_init_dio ok\n");

	return 0;
}

static int _pwrap_lock_SPISLVReg(void)
{
	pwrap_write_nochk(PMIC_SPISLV_KEY_ADDR, 0x0);
	return 0;
}

static int _pwrap_unlock_SPISLVReg(void)
{
	pwrap_write_nochk(PMIC_SPISLV_KEY_ADDR, 0xbade);
	return 0;
}

static S32 _pwrap_init_sistrobe_reset(void)
{
	WRAP_WR32(PMICSPI_MST_SI_SAMPLING_CTRL, si_sample_ctrl);
	return 0;
}

signed int PMICSPIMSTDrv_Reset(void)
{
	signed int sub_return = 0;
	unsigned int rdata = 0x0;

	/* Reset SPI Slave */
	sub_return = _pwrap_reset_spislv();
	if (sub_return != 0) {
		PWRAPERR("reset_spislv fail, ret=%x\n", sub_return);
		return E_PWR_INIT_RESET_SPI;
	}
	PWRAPLOG("Reset SPISLV ok\n");

	/* Enable SPI Wrapper */
	WRAP_WR32(PMICSPI_MST_SPIWRAP_EN, 0x1);

	/* SPI Waveform Configuration. 0: Safe Mode, 1: SPISLV Clock is 18MHz */
	sub_return = _pwrap_init_reg_clock_reset(1);
	if (sub_return != 0) {
		PWRAPERR("_pwrap_init_reg_clock_reset fail, ret=%x\n", sub_return);
		return E_PWR_INIT_REG_CLOCK;
	}
	PWRAPLOG("_pwrap_init_reg_clock_reset ok\n");

	/* SPI Slave Configuration */
	PWRAPLOG("No need to init SPISLV\n");

	/* Input data calibration flow; */
	sub_return = _pwrap_init_sistrobe_reset();
	if (sub_return != 0) {
		PWRAPERR("InitSiStrobe fail, sub_return=%x\n", sub_return);
		return E_PWR_INIT_SIDLY;
	}
	PWRAPLOG("_pwrap_init_sistrobe_reset ok\n");

	/* Lock SPI Slave Registers */
	PWRAPLOG("No need to lock SPISLV\n");

	return 0;
}

static signed int _pwrap_reset_pattern(void)
{
	signed int sub_return = 0;
	struct pwrap_rc_info info;

	PWRAPLOG("pwrap_init_reset start!!!!!!!!!!!!!\n");

	/* Backup PMIC Wrap key register before reset */
	si_sample_ctrl = WRAP_RD32(PMICSPI_MST_SI_SAMPLING_CTRL);

	info.swinf_cmd = WRAP_RD32(PMIF_SPI_PMIF_SWINF_0_ACC + 0x40 * PMIF_SPI_AP_SWINF_NO);
	info.other_inf_en = WRAP_RD32(PMIF_SPI_PMIF_OTHER_INF_EN);
	info.spi_mode_ctrl = WRAP_RD32(PMIF_SPI_PMIF_SPI_MODE_CTRL);
	info.sleep_protect_ctrl = WRAP_RD32(PMIF_SPI_PMIF_SLEEP_PROTECTION_CTRL);
	info.dcxo_cmd_adr0 = WRAP_RD32(PMIF_SPI_PMIF_DCXO_CMD_ADDR_0);
	info.dcxo_cmd_wdata0 = WRAP_RD32(PMIF_SPI_PMIF_DCXO_CMD_WDATA_0);
	info.dcxo_cmd_adr1 = WRAP_RD32(PMIF_SPI_PMIF_DCXO_CMD_ADDR_1);
	info.dcxo_cmd_wdata1 = WRAP_RD32(PMIF_SPI_PMIF_DCXO_CMD_WDATA_1);
	info.gps_auxadc_addr = WRAP_RD32(PMIF_SPI_PMIF_INT_GPS_AUXADC_CMD_ADDR);
	info.gps_auxadc_cmd = WRAP_RD32(PMIF_SPI_PMIF_INT_GPS_AUXADC_CMD);
	info.gps_auxadc_rdata = WRAP_RD32(PMIF_SPI_PMIF_INT_GPS_AUXADC_RDATA_ADDR);

	PWRAPLOG("Backup pwrap key register ok\n");

	__pwrap_spi_clk_set();
	PWRAPLOG("__pwrap_spi_clk_set ok\n");

	/* Enable SWINF for AP */
	WRAP_WR32(PMIF_SPI_PMIF_INF_EN, 0x1 << PMIF_SPI_AP_SWINF_CHAN_NO);

	/* Enable arbitration for SWINF for AP */
	WRAP_WR32(PMIF_SPI_PMIF_ARB_EN, 0x1 << PMIF_SPI_AP_SWINF_CHAN_NO);

	/* Enable PMIF_SPI Command Issue */
	WRAP_WR32(PMIF_SPI_PMIF_CMDISSUE_EN, 0x1);

	/* Initialize PMIC SPI Master */
	sub_return = PMICSPIMSTDrv_Reset();
	if (sub_return != 0) {
		PWRAPERR("PMICSPIMSTDrv_Reset Failed, sub_return = %x, exp = 0\n", sub_return);
		return sub_return;
	}

	/* Status update function initialization
	* 1. Signature Checking using CRC (CRC 0 only)
	* 2. EINT update
	* 3. Read back Auxadc thermal data for GPS
	*/
	_pwrap_InitStaUpd();
	PWRAPLOG("_pwrap_InitStaUpd ok\n");

	/* Configure PMIF Timer */
	WRAP_WR32(PMIF_SPI_PMIF_TIMER_CTRL, 0x3);

	/* Enable interfaces and arbitration */
	WRAP_WR32(PMIF_SPI_PMIF_INF_EN, 0x307f | (0x1 << PMIF_SPI_MD_SWINF_CHAN_NO) |
					(0x1 << PMIF_SPI_AP_SECURE_SWINF_CHAN_NO) |
					(0x1 << PMIF_SPI_AP_SWINF_CHAN_NO));

	WRAP_WR32(PMIF_SPI_PMIF_ARB_EN, 0x707f | (0x1 << PMIF_SPI_MD_SWINF_CHAN_NO) |
					(0x1 << PMIF_SPI_AP_SECURE_SWINF_CHAN_NO) |
					(0x1 << PMIF_SPI_AP_SWINF_CHAN_NO));

	/* Set INIT_DONE */
	WRAP_WR32(PMIF_SPI_PMIF_INIT_DONE, 0x1);

#if !(MACH_FPGA)
	/* Configure MD ADC Interface */
	udelay(100);

	PWRAPLOG("write MODEM_TEMP_SHARE_CTRL start\n");
	WRAP_WR32(MODEM_TEMP_SHARE_CTRL, 0xf0);
	PWRAPLOG("write MODEM_TEMP_SHARE_CTRL ok\n");
	PWRAPLOG("MODEM_TEMP_SHARE_CTRL:%x\n", WRAP_RD32(MODEM_TEMP_SHARE_CTRL));
#endif

	/* Restore key register after reset */
	WRAP_WR32(PMIF_SPI_PMIF_SWINF_0_ACC + 0x40 * PMIF_SPI_AP_SWINF_NO, info.swinf_cmd);
	WRAP_WR32(PMIF_SPI_PMIF_DCXO_CMD_ADDR_0, info.dcxo_cmd_adr0);
	WRAP_WR32(PMIF_SPI_PMIF_DCXO_CMD_WDATA_0, info.dcxo_cmd_wdata0);
	WRAP_WR32(PMIF_SPI_PMIF_DCXO_CMD_ADDR_1, info.dcxo_cmd_adr1);
	WRAP_WR32(PMIF_SPI_PMIF_DCXO_CMD_WDATA_1, info.dcxo_cmd_wdata1);
	WRAP_WR32(PMIF_SPI_PMIF_INT_GPS_AUXADC_CMD_ADDR, info.gps_auxadc_addr);
	WRAP_WR32(PMIF_SPI_PMIF_INT_GPS_AUXADC_CMD, info.gps_auxadc_cmd);
	WRAP_WR32(PMIF_SPI_PMIF_INT_GPS_AUXADC_RDATA_ADDR, info.gps_auxadc_rdata);
	WRAP_WR32(PMIF_SPI_PMIF_SLEEP_PROTECTION_CTRL, info.sleep_protect_ctrl);
	WRAP_WR32(PMIF_SPI_PMIF_SPI_MODE_CTRL, info.spi_mode_ctrl);
	WRAP_WR32(PMIF_SPI_PMIF_OTHER_INF_EN, info.other_inf_en);

	PWRAPLOG("Restore pwrap key register ok\n");

	/* Write Test */
	sub_return = pwrap_write_test();
	if (sub_return != 0) {
		PWRAPERR("write test fail\n");
		return E_PWR_INIT_WRITE_TEST;
	}
	PWRAPLOG("pwrap_write_test ok\n");

	PWRAPLOG("pwrap_init_reset Done!!!!!!!!!\n");

	return 0;
}

static signed int pwrap_reset_pattern(void)
{
	/* SPI & WRAP Reset Pattern */
	unsigned int ret;

	ret = _pwrap_reset_pattern();
	if (ret != 0) {
		PWRAPERR("_pwrap_reset_pattern fail, ret=%x\n", ret);
		return E_PWR_INIT_RESET_SPI;
	}

	return 0;
}

void pwrap_disable(void) {
	PWRAPLOG("pmic wrap disable\n");
	WRAP_WR32(PMICSPI_MST_SPIWRAP_EN, 0x0);
	udelay(10);
}

#endif /*endif PMIC_WRAP_NO_PMIC */
