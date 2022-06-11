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
 * MTK SPMI Common Driver
 *
 * Copyright 2018 MediaTek Co.,Ltd.
 *
 * DESCRIPTION:
 *     This file provides API for other drivers to access PMIC registers
 *
 */

#include <pmif.h>
#include <spmi.h>
#include <pmif_sw.h>
#include <spmi_sw.h>

#if SPMI_NO_PMIC
int spmi_ext_register_readl(struct spmi_device *dev, unsigned int addr,
		unsigned char *buf, unsigned short len)
{
	SPMI_INFO("%s do Nothing.\n", __func__);
	return 0;
}
int spmi_ext_register_writel(struct spmi_device *dev, unsigned int addr,
		const unsigned char *buf, unsigned short len)
{
	SPMI_INFO("%s do Nothing.\n", __func__);
	return 0;
}
int spmi_ext_register_readl_field(struct spmi_device *dev, unsigned int addr,
	unsigned char *buf, unsigned short len,
	unsigned short mask, unsigned short shift)
{
	SPMI_INFO("%s do Nothing.\n", __func__);
	return 0;
}
int spmi_ext_register_writel_field(struct spmi_device *dev, unsigned int addr,
	const unsigned char *buf, unsigned short len,
	unsigned short mask, unsigned short shift)
{
	SPMI_INFO("%s do Nothing.\n", __func__);
	return 0;
}
#else /* #ifdef SPMI_NO_PMIC */
int spmi_register_zero_write(struct spmi_device *dev, unsigned int addr,
		unsigned char data)
{
	return dev->pmif_arb->write_cmd(dev->pmif_arb, SPMI_CMD_ZERO_WRITE,
					dev->slvid, addr, &data, 1);
}

int spmi_register_read(struct spmi_device *dev, unsigned int addr,
		unsigned char *buf)
{
	return dev->pmif_arb->read_cmd(dev->pmif_arb, SPMI_CMD_READ,
					dev->slvid, addr, buf, 1);
}

int spmi_register_write(struct spmi_device *dev, unsigned int addr,
		unsigned char data)
{
	return dev->pmif_arb->write_cmd(dev->pmif_arb, SPMI_CMD_WRITE,
					dev->slvid, addr, &data, 1);
}

int spmi_ext_register_read(struct spmi_device *dev, unsigned int addr,
		unsigned char *buf, unsigned short len)
{
	return dev->pmif_arb->read_cmd(dev->pmif_arb, SPMI_CMD_EXT_READ,
					dev->slvid, addr, buf, len);
}

int spmi_ext_register_write(struct spmi_device *dev, unsigned int addr,
		const unsigned char *buf, unsigned short len)
{
	return dev->pmif_arb->write_cmd(dev->pmif_arb, SPMI_CMD_EXT_WRITE,
					dev->slvid, addr, buf, len);
}

int spmi_ext_register_readl(struct spmi_device *dev, unsigned int addr,
		unsigned char *buf, unsigned short len)
{
	return dev->pmif_arb->read_cmd(dev->pmif_arb, SPMI_CMD_EXT_READL,
					dev->slvid, addr, buf, len);
}

int spmi_ext_register_writel(struct spmi_device *dev, unsigned int addr,
		const unsigned char *buf, unsigned short len)
{
	return dev->pmif_arb->write_cmd(dev->pmif_arb, SPMI_CMD_EXT_WRITEL,
					dev->slvid, addr, buf, len);
}

int spmi_ext_register_readl_field(struct spmi_device *dev, unsigned int addr,
	unsigned char *buf, unsigned short len,
	unsigned short mask, unsigned short shift)
{
	unsigned int ret = 0;
	unsigned char rdata = 0;

	if (len > 1)
		return -2;

	ret = dev->pmif_arb->read_cmd(dev->pmif_arb, SPMI_CMD_EXT_READL,
					dev->slvid, addr, &rdata, len);
	if (ret != 0)
		return ret;

	*buf = (rdata >> shift) & mask;

	return 0;
}

int spmi_ext_register_writel_field(struct spmi_device *dev, unsigned int addr,
	const unsigned char *buf, unsigned short len,
	unsigned short mask, unsigned short shift)
{
	unsigned char data = 0x0;
	unsigned int ret = 0;

	if (len > 1)
		return -2;

	ret = spmi_ext_register_readl(dev, addr, &data, 1);
	if (ret != 0)
		return ret;

	data = data & ~(mask << shift);
	data |= (*buf << shift);
	return dev->pmif_arb->write_cmd(dev->pmif_arb, SPMI_CMD_EXT_WRITEL,
					dev->slvid, addr, &data, len);
}
#endif /* endif SPMI_NO_PMIC */
