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

#include <spmi.h>
#include <pmif.h>
#include <pmif_sw.h>
#include <spmi_sw.h>
#include <mt6315_upmu_hw.h>

u32 mt6xxx_spmi_regs[] = {
	[SPMI_OP_ST_CTRL] =		0x0000,
	[SPMI_GRP_ID_EN] =		0x0004,
	[SPMI_OP_ST_STA] =		0x0008,
	[SPMI_MST_SAMPL] =		0x000c,
	[SPMI_MST_REQ_EN] =		0x0010,
#if SPMI_RCS_SUPPORT
	[SPMI_MST_RCS_CTRL] =		0x0014,
	[SPMI_MST_IRQ] =		0x0018,
	[SPMI_SLV_3_0_EINT] =		0x0020,
	[SPMI_SLV_7_4_EINT] =		0x0024,
	[SPMI_SLV_B_8_EINT] =		0x0028,
	[SPMI_SLV_F_C_EINT] =		0x002c,
	[SPMI_TIA] =			0x0030,
#endif /* #if SPMI_RCS_SUPPORT */
	[SPMI_REC_CTRL] =		0x0040,
	[SPMI_REC0] =			0x0044,
	[SPMI_REC1] =			0x0048,
	[SPMI_REC2] =			0x004c,
	[SPMI_REC3] =			0x0050,
	[SPMI_REC4] =			0x0054,
#if SPMI_RCS_SUPPORT
	[SPMI_DEC_DBG] =		0x00f8,
#endif
	[SPMI_MST_DBG] =		0x00fc,
};

static struct pmif *pmif_spmi_arb_ctrl[4];
#if MT63xx_EVB
struct spmi_device spmi_dev[] = {
	{
		.slvid = SPMI_SLAVE_6,
		.grpiden = 0x800,
		.type = BUCK_CPU,
		.type_id = BUCK_CPU_ID,
		.pmif_arb = NULL,
	},	{
		.slvid = SPMI_SLAVE_7,
		.grpiden = 0x800,
		.type = BUCK_GPU,
		.type_id = BUCK_GPU_ID,
		.pmif_arb = NULL,
	},	{
		.slvid = SPMI_SLAVE_3,
		.grpiden = 0x800,
		.type = BUCK_MD,
		.type_id = BUCK_MD_ID,
		.pmif_arb = NULL,
	},
};
#else
struct spmi_device spmi_dev[] = {
	{
		.slvid = SPMI_SLAVE_10,
		.grpiden = 0x100,
		.type = BUCK_CPU,
		.type_id = BUCK_CPU_ID,
		.pmif_arb = NULL,
	},	{
		.slvid = SPMI_SLAVE_11,
		.grpiden = 0x100,
		.type = BUCK_GPU,
		.type_id = BUCK_GPU_ID,
		.pmif_arb = NULL,
	},	{
		.slvid = SPMI_SLAVE_12,
		.grpiden = 0x100,
		.type = BUCK_MD,
		.type_id = BUCK_MD_ID,
		.pmif_arb = NULL,
	},
};
#endif
unsigned char spmi_device_cnt;

/* spmi internal API declaration */
static int spmi_ctrl_op_st(int mstid, unsigned int grpiden,
	unsigned int sid, unsigned int cmd);
static int spmi_read_check(struct spmi_device *dev);

#if SPMI_NO_PMIC
int spmi_init(struct pmif *pmif_arb)
{
	SPMI_INFO("do Nothing.\n");
	return 0;
}

#else /* #ifdef SPMI_NO_PMIC */
/*
 * Function : mtk_spmi_readl()
 * Description : mtk spmi controller read api
 * Parameter :
 * Return :
 */
u32 spmi_readl(int mstid, enum spmi_regs reg)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);

	return DRV_Reg32(arb->spmimst_base + arb->spmimst_regs[reg]);
}

/*
 * Function : mtk_spmi_writel()
 * Description : mtk spmi controller write api
 * Parameter :
 * Return :
 */
void spmi_writel(int mstid, enum spmi_regs reg, unsigned int val)
{
	struct pmif *arb = get_pmif_controller(PMIF_SPMI, mstid);

	DRV_WriteReg32(arb->spmimst_base + arb->spmimst_regs[reg], val);
}

static int spmi_ctrl_op_st(int mstid, unsigned int grpiden, unsigned int sid,
		unsigned int cmd)
{
	unsigned int rdata = 0x0;

	/* gid is 0x800 */
	spmi_writel(mstid, SPMI_GRP_ID_EN, grpiden);
#if MT63xx_EVB
	if (grpiden == (1 << SPMI_GROUP_ID))
		spmi_writel(mstid, SPMI_OP_ST_CTRL,
			(cmd << 0x4) | SPMI_GROUP_ID);
#else
	if (grpiden == 0x100)
		spmi_writel(mstid, SPMI_OP_ST_CTRL, (cmd << 0x4) | 0x8);
#endif
	else
		spmi_writel(mstid, SPMI_OP_ST_CTRL, (cmd << 0x4) | sid);

	SPMI_WARN("spmi_ctrl_op_st 0x%x\n", spmi_readl(mstid, SPMI_OP_ST_CTRL));

	do
	{
		rdata = spmi_readl(mstid, SPMI_OP_ST_STA);
		SPMI_DBG("spmi_ctrl_op_st 0x%x\n", rdata);

		if (((rdata >> 0x1) & SPMI_OP_ST_NACK) == SPMI_OP_ST_NACK) {
			spmi_dump_mst_record_reg(mstid);
			break;
		}
		}while((rdata & SPMI_OP_ST_BUSY) == SPMI_OP_ST_BUSY);

	return 0;
}

int spmi_command_reset(int mstid, struct spmi_device *dev, unsigned int grpiden)
{
#if MT63xx_EVB
	if (grpiden != (1 << SPMI_GROUP_ID))
		dev->slvid = grpiden;
#else
	if (grpiden != 0x100)
		dev->slvid = grpiden;
#endif
	return spmi_ctrl_op_st(mstid, grpiden, dev->slvid, SPMI_RESET);
}
int spmi_command_sleep(int mstid, struct spmi_device *dev, unsigned int grpiden)
{
#if MT63xx_EVB
	if (grpiden != (1 << SPMI_GROUP_ID))
		dev->slvid = grpiden;
#else
	if (grpiden != 0x100)
		dev->slvid = grpiden;
#endif
	return spmi_ctrl_op_st(mstid, grpiden, dev->slvid, SPMI_SLEEP);
}
int spmi_command_wakeup(int mstid, struct spmi_device *dev, unsigned int grpiden)
{
#if MT63xx_EVB
	if (grpiden != (1 << SPMI_GROUP_ID))
		dev->slvid = grpiden;
#else
	if (grpiden != 0x100)
		dev->slvid = grpiden;
#endif
	return spmi_ctrl_op_st(mstid, grpiden, dev->slvid, SPMI_WAKEUP);
}
int spmi_command_shutdown(int mstid, struct spmi_device *dev, unsigned int grpiden)
{
#if MT63xx_EVB
	if (grpiden != (1 << SPMI_GROUP_ID))
		dev->slvid = grpiden;
#else
	if (grpiden != 0x100)
		dev->slvid = grpiden;
#endif
	return spmi_ctrl_op_st(mstid, grpiden, dev->slvid, SPMI_SHUTDOWN);
}

static int spmi_read_check(struct spmi_device *dev)
{
	u8 rdata = 0;

	spmi_ext_register_readl(dev, MT6315_PMIC_HWCID_H_ADDR, &rdata, 1);
	if (rdata != 0x15) {
		SPMI_ERR("%s next, slvid:%d rdata = 0x%x.\n",
			__func__, dev->slvid, rdata);
		return -EIO;
	} else
		SPMI_CRI("%s done, slvid:%d\n", __func__, dev->slvid);

	spmi_ext_register_readl(dev, MT6315_PMIC_SWCID_H_ADDR, &rdata, 1);
	if (rdata != 0x15) {
		SPMI_ERR("%s next, slvid:%d rdata = 0x%x.\n",
			__func__, dev->slvid, rdata);
		return -EIO;
	} else
		SPMI_CRI("%s done, slvid:%d\n", __func__, dev->slvid);

	return 0;
}
struct spmi_device *get_spmi_device(int mstid, int slaveid)
{
	unsigned int i;

	for (i = 0; i < spmi_device_cnt; i++) {
		if (slaveid == spmi_dev[i].slvid) {
			return &spmi_dev[i];
		}
	}

	return NULL;
}

int spmi_init(struct pmif *pmif_arb)
{
	int i = 0;

	if (pmif_arb == NULL) /* null check */ {
		SPMI_ERR("arguments err\n");
		return -EINVAL;
	}

	pmif_arb->spmimst_base = (unsigned int *)SPMI_MST_BASE,
	pmif_arb->spmimst_regs = mt6xxx_spmi_regs;
	pmif_spmi_arb_ctrl[pmif_arb->mstid] = pmif_arb;
	spmi_device_cnt = sizeof(spmi_dev)/sizeof(spmi_dev[0]);

	for (i = 0; i < spmi_device_cnt; i++) {
		spmi_dev[i].pmif_arb = pmif_spmi_arb_ctrl[pmif_arb->mstid];
		spmi_read_check(&spmi_dev[i]);
	}
	SPMI_INFO("%s done\n", __func__);

	return 0;
}

#endif /* #ifdef SPMI_NO_PMIC */
