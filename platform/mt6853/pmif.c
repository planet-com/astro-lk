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
 * MTK PMIF Driver
 *
 * Copyright 2019 MediaTek Co.,Ltd.
 *
 * DESCRIPTION:
 *     This file provides API for other drivers to access PMIC registers
 *
 */

#include <pmif.h>
#include <spmi.h>
#include <pmif_sw.h>
#include <spmi_sw.h>

#define GET_SWINF_0_FSM(x)	((x>>1)  & 0x00000007)
#define GET_PMIF_INIT_DONE(x)	((x>>15) & 0x00000001)
#define TIMEOUT_WAIT_IDLE	(1000000) /* ap latency concern 1ms */

static int pmif_spmi_read_cmd(struct pmif *arb, unsigned char opc,
		unsigned char sid, unsigned short addr, unsigned char *buf,
		unsigned short len);
static int pmif_spmi_write_cmd(struct pmif *arb, unsigned char opc,
	unsigned char sid, unsigned short addr, const unsigned char *buf,
	unsigned short len);
#if PMIF_NO_PMIC
static int pmif_spmi_read_cmd(struct pmif *arb, unsigned char opc,
		unsigned char sid, unsigned short addr, unsigned char *buf,
		unsigned short len)
{
	PMIF_INFO("do Nothing.\n");
	return 0;
}

static int pmif_spmi_write_cmd(struct pmif *arb, unsigned char opc,
	unsigned char sid, unsigned short addr, const unsigned char *buf,
	unsigned short len)
{
	PMIF_INFO("do Nothing.\n");
	return 0;
}

/* init interface */
int pmif_spmi_init(int mstid)
{
	PMIF_INFO("do Nothing.\n");
	return 0;
}
#else /* #if PMIF_NO_PMIC */
/* pmif internal API declaration */
#if PMIF_TIMEOUT
static unsigned long long pmif_get_current_time(void);
static int pmif_timeout_ns(unsigned long long start_time_ns,
	unsigned long long timeout_time_ns);
static unsigned long long pmif_time2ns(unsigned long long time_us);
#endif


enum pmif_regs {
	PMIF_INIT_DONE,
	PMIF_INF_EN,
	PMIF_INF_CMD_PER_0,
	PMIF_INF_CMD_PER_1,
	PMIF_INF_CMD_PER_2,
	PMIF_INF_CMD_PER_3,
	PMIF_INF_MAX_BYTECNT_PER_0,
	PMIF_INF_MAX_BYTECNT_PER_1,
	PMIF_INF_MAX_BYTECNT_PER_2,
	PMIF_INF_MAX_BYTECNT_PER_3,
	PMIF_ARB_EN,
	PMIF_LAT_CNTER_EN,
	PMIF_LAT_LIMIT_LOADING,
	PMIF_LAT_LIMIT_0,
	PMIF_LAT_LIMIT_1,
	PMIF_LAT_LIMIT_2,
	PMIF_LAT_LIMIT_3,
	PMIF_LAT_LIMIT_4,
	PMIF_LAT_LIMIT_5,
	PMIF_LAT_LIMIT_6,
	PMIF_LAT_LIMIT_7,
	PMIF_LAT_LIMIT_8,
	PMIF_LAT_LIMIT_9,
	PMIF_CMDISSUE_EN,
	PMIF_TIMER_CTRL,
	PMIF_SPI_MODE_CTRL,
	PMIF_IRQ_EVENT_EN_0,
	PMIF_IRQ_FLAG_0,
	PMIF_IRQ_CLR_0,
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

static int mt6xxx_regs[] = {
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

static struct pmif pmif_spmi_arb[] = {
	{
		.base = (unsigned int *)PMIF_SPMI_BASE,
		.regs = mt6xxx_regs,
		.spmimst_base = (unsigned int *)SPMI_MST_BASE,
		.swinf_ch_start = PMIF_SWINF_0_CHAN_NO,
		.swinf_no = PMIF_AP_SWINF_NO,
		.write = 0x0,
		.mstid = SPMI_MASTER_0,
		.pmifid = PMIF_PMIFID,
		.read_cmd = pmif_spmi_read_cmd,
		.write_cmd = pmif_spmi_write_cmd,
		.is_pmif_init_done = is_pmif_spmi_init_done,
	},
	{
		.base = (unsigned int *)PMIF_SPMI_BASE,
		.regs = mt6xxx_regs,
		.spmimst_base = (unsigned int *)SPMI_MST_BASE,
		.swinf_ch_start = PMIF_SWINF_0_CHAN_NO,
		.swinf_no = PMIF_AP_SWINF_NO,
		.write = 0x0,
		.mstid = SPMI_MASTER_1,
		.pmifid = PMIF_PMIFID,
		.read_cmd = pmif_spmi_read_cmd,
		.write_cmd = pmif_spmi_write_cmd,
		.is_pmif_init_done = is_pmif_spmi_init_done,
	},
	{
		.base = (unsigned int *)PMIF_SPMI_P_BASE,
		.regs = mt6xxx_regs,
		.spmimst_base = (unsigned int *)SPMI_MST_P_BASE,
		.swinf_ch_start = PMIF_SWINF_0_CHAN_NO_P,
		.swinf_no = PMIF_AP_SWINF_NO,
		.write = 0x0,
		.mstid = SPMI_MASTER_P_1,
		.pmifid = PMIF_PMIFID_2,
		.read_cmd = pmif_spmi_read_cmd,
		.write_cmd = pmif_spmi_write_cmd,
		.is_pmif_init_done = is_pmif_spmi_init_done,
	},
};
/* static struct pmif pmif_spi_arb[0]; */

/* pmif timeout */
#if PMIF_TIMEOUT
static unsigned long long pmif_get_current_time(void)
{
	return gpt4_get_current_tick();
}

static int pmif_timeout_ns(unsigned long long start_time_ns,
	unsigned long long timeout_time_ns)
{
	return gpt4_timeout_tick(start_time_ns, timeout_time_ns);
}

static unsigned long long pmif_time2ns(unsigned long long time_us)
{
	return gpt4_time2tick_us(time_us);
}
#else
static unsigned long long pmif_get_current_time(void)
{
	return 0;
}
static int pmif_timeout_ns(unsigned long long start_time_ns,
	unsigned long long elapse_time)
{
	return 0;
}

static unsigned long long pmif_time2ns(unsigned long long time_us)
{
	return 0;
}
#endif
static inline unsigned int pmif_check_idle(int mstid) {
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int reg_rdata, offset = 0;
#if PMIF_TIMEOUT
	unsigned long long start_time_ns = 0, end_time_ns = 0, timeout_ns = 0;
	unsigned long time_cnt = 100000;

	start_time_ns = pmif_get_current_time();
	timeout_ns = pmif_time2ns(TIMEOUT_WAIT_IDLE);
#endif

	do {
#if PMIF_TIMEOUT
		if (pmif_timeout_ns(start_time_ns, timeout_ns)) {
			end_time_ns = pmif_get_current_time();
			PMIF_ERR("%s timeout %d %d\n", __func__, start_time_ns,
					end_time_ns - start_time_ns);
			return -ETIMEDOUT;
		}
		if ((time_cnt--) == 0) {
			PMIF_ERR("%s timeout %d %d\n", __func__, start_time_ns,
					end_time_ns - start_time_ns);
			return -ETIMEDOUT;
		}
#endif
		offset = arb->regs[PMIF_SWINF_0_STA] + (0x40 * arb->swinf_no);
		reg_rdata = DRV_Reg32(arb->base + offset);
	} while(GET_SWINF_0_FSM(reg_rdata) != SWINF_FSM_IDLE);

    return 0;
}

static inline unsigned int pmif_check_vldclr(int mstid) {
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	unsigned int reg_rdata, offset = 0;
#if PMIF_TIMEOUT
	unsigned long long start_time_ns = 0, end_time_ns = 0, timeout_ns = 0;
	unsigned long time_cnt = 100000;

	start_time_ns = pmif_get_current_time();
	timeout_ns = pmif_time2ns(TIMEOUT_WAIT_IDLE);
#endif

	do {
#if PMIF_TIMEOUT
		if (pmif_timeout_ns(start_time_ns, timeout_ns)) {
			end_time_ns = pmif_get_current_time();
			PMIF_ERR("%s timeout %d %d\n", __func__, start_time_ns,
					end_time_ns - start_time_ns);
			return -ETIMEDOUT;
		}
		if ((time_cnt--) == 0) {
			PMIF_ERR("%s timeout %d %d\n", __func__, start_time_ns,
					end_time_ns - start_time_ns);
			return -ETIMEDOUT;
		}
#endif
		offset = arb->regs[PMIF_SWINF_0_STA] + (0x40 * arb->swinf_no);
		reg_rdata = DRV_Reg32(arb->base + offset);
	} while(GET_SWINF_0_FSM(reg_rdata) != SWINF_FSM_WFVLDCLR);

    return 0;
}

static int pmif_spmi_read_cmd(struct pmif *arb, unsigned char opc,
		unsigned char sid, unsigned short addr, unsigned char *buf,
		unsigned short len)
{
	int write = 0x0;
	unsigned int ret = 0, offset = 0, data = 0;
	unsigned char bc = len - 1;

	if ((sid & ~(0xf)) != 0x0)
		return -EINVAL;

	if (len > PMIF_BYTECNT_MAX)
		return -EINVAL;

	/* Check the opcode */
	if (opc >= 0x60 && opc <= 0x7F)
		opc = PMIF_CMD_REG;
	else if (opc >= 0x20 && opc <= 0x2F)
		opc = PMIF_CMD_EXT_REG;
	else if (opc >= 0x38 && opc <= 0x3F)
		opc = PMIF_CMD_EXT_REG_LONG;
	else
		return -EINVAL;

	ENTER_CRITICAL();
	/* Wait for Software Interface FSM state to be IDLE. */
	ret = pmif_check_idle(arb->mstid);
	if(ret)
		return ret;

	/* Send the command. */
	offset = arb->regs[PMIF_SWINF_0_ACC] + (0x40 * arb->swinf_no);
	DRV_WriteReg32(arb->base + offset,
		((unsigned)opc << 30) | (write << 29) | (sid << 24) | (bc << 16) | addr);

	/* Wait for Software Interface FSM state to be WFVLDCLR,
	 *
	 * read the data and clear the valid flag.
	 */
	if(write == 0)
	{
		ret = pmif_check_vldclr(arb->mstid);
		if(ret)
			return ret;

		offset =
		arb->regs[PMIF_SWINF_0_RDATA_31_0] + (0x40 * arb->swinf_no);
		data = DRV_Reg32(arb->base + offset);
		memcpy(buf, &data, (bc & 3) + 1);
		offset =
		arb->regs[PMIF_SWINF_0_VLD_CLR] + (0x40 * arb->swinf_no);
		DRV_WriteReg32(arb->base + offset, 0x1);
	}
	EXIT_CRITICAL();

	return 0x0;
}

static int pmif_spmi_write_cmd(struct pmif *arb, unsigned char opc,
	unsigned char sid, unsigned short addr, const unsigned char *buf,
	unsigned short len)
{
	int write = 0x1;
	unsigned int ret = 0, offset = 0, data = 0;
	unsigned char bc = len - 1;

	if ((sid & ~(0xf)) != 0x0)
		return -EINVAL;

	if (len > PMIF_BYTECNT_MAX)
		return -EINVAL;

	/* Check the opcode */
	if (opc >= 0x40 && opc <= 0x5F)
		opc = PMIF_CMD_REG;
	else if (opc <= 0x0F)
		opc = PMIF_CMD_EXT_REG;
	else if (opc >= 0x30 && opc <= 0x37)
		opc = PMIF_CMD_EXT_REG_LONG;
	else if (opc >= 0x80)
		opc = PMIF_CMD_REG_0;
	else
		return -EINVAL;

	ENTER_CRITICAL();
	/* Wait for Software Interface FSM state to be IDLE. */
	ret = pmif_check_idle(arb->mstid);
	if(ret)
		return ret;

	/* Set the write data. */
	if (write == 1)
	{
		offset =
		arb->regs[PMIF_SWINF_0_WDATA_31_0] + (0x40 * arb->swinf_no);
		memcpy(&data, buf, (bc & 3) + 1);
		DRV_WriteReg32(arb->base + offset, data);
	}
	/* Send the command. */
	offset = arb->regs[PMIF_SWINF_0_ACC] + (0x40 * arb->swinf_no);
	DRV_WriteReg32(arb->base + offset,
		((unsigned)opc << 30) | (write << 29) | (sid << 24) |
		(bc << 16) | addr);
	EXIT_CRITICAL();

	return 0x0;
}

struct pmif *get_pmif_controller(int inf, int mstid)
{
	if (inf == PMIF_SPMI) {
		return &pmif_spmi_arb[mstid];
	} else if (inf == PMIF_SPI) {
		/* TBD
		 *pmif_spi_arb[mstid].base = (unsigned int *)PMIF_SPI_BASE;
		 *pmif_spi_arb[mstid].swinf_no = 0x0;
		 *pmif_spi_arb[mstid].write = 0x0;
		 *pmif_spi_arb[mstid].pmifid = 0x0;
		 *pmif_spi_arb[mstid].read_cmd = pmif_spi_read_cmd;
		 *pmif_spi_arb[mstid].write_cmd = pmif_spi_write_cmd;
		 *pmif_spi_arb[mstid].read_cmd_nochk = pmif_spi_read_cmd_nochk;
		 *pmif_spi_arb[mstid].write_cmd_nochk =
		 *		pmif_spi_write_cmd_nochk;
		 *return &pmif_spi_arb[mstid];
		 */
	}

	return 0;
}
int is_pmif_spmi_init_done(int mstid)
{
	int ret = 0;

	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);

	ret = DRV_Reg32(arb->base + arb->regs[PMIF_INIT_DONE]);
	PMIF_INFO("%s ret = %d\n", __func__, ret);
	if ((ret & 0x1) == 1)
		return 0;

	return -ENODEV;
}

int pmif_spmi_init(int mstid)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);
	int ret = 0;

	INIT_CRITICAL();

	ret = arb->is_pmif_init_done(mstid);
	if(ret) {
		PMIF_ERR("init done check fail\n");
		return -ENODEV;
	}
	spmi_pmif_dbg_init(arb);

	ret = spmi_init(arb);
	if(ret) {
		PMIF_ERR("init fail\n");
		return -ENODEV;
	}

	return 0;
}

#endif /* endif PMIF_NO_PMIC */
