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
#ifndef __SPMI_H__
#define __SPMI_H__
#define SPMI_GROUP_ID			0xB

/* Maximum slave identifier */
#define SPMI_MAX_SLAVE_ID		16

/* SPMI Commands */
#define SPMI_CMD_EXT_WRITE		0x00
#define SPMI_CMD_RESET			0x10
#define SPMI_CMD_SLEEP			0x11
#define SPMI_CMD_SHUTDOWN		0x12
#define SPMI_CMD_WAKEUP			0x13
#define SPMI_CMD_AUTHENTICATE		0x14
#define SPMI_CMD_MSTR_READ		0x15
#define SPMI_CMD_MSTR_WRITE		0x16
#define SPMI_CMD_TRANSFER_BUS_OWNERSHIP	0x1A
#define SPMI_CMD_DDB_MASTER_READ	0x1B
#define SPMI_CMD_DDB_SLAVE_READ		0x1C
#define SPMI_CMD_EXT_READ		0x20
#define SPMI_CMD_EXT_WRITEL		0x30
#define SPMI_CMD_EXT_READL		0x38
#define SPMI_CMD_WRITE			0x40
#define SPMI_CMD_READ			0x60
#define SPMI_CMD_ZERO_WRITE		0x80

/* enum marco for cmd/channel */
enum spmi_master
{
	SPMI_MASTER_0 = 0,
	SPMI_MASTER_1,
	SPMI_MASTER_P_1,
	SPMI_MASTER_MAX
};

enum spmi_slave
{
	SPMI_SLAVE_0 = 0,
	SPMI_SLAVE_1,
	SPMI_SLAVE_2,
	SPMI_SLAVE_3,
	SPMI_SLAVE_4,
	SPMI_SLAVE_5,
	SPMI_SLAVE_6,
	SPMI_SLAVE_7,
	SPMI_SLAVE_8,
	SPMI_SLAVE_9,
	SPMI_SLAVE_10,
	SPMI_SLAVE_11,
	SPMI_SLAVE_12,
	SPMI_SLAVE_13,
	SPMI_SLAVE_14,
	SPMI_SLAVE_15
};

enum slv_type
{
	BUCK_CPU,
	BUCK_GPU,
	BUCK_MD,
	BUCK_RF,
	MAIN_PMIC,
	BUCK_VPU,
	SUB_PMIC,
	SLV_TYPE_MAX
};

enum slv_type_id
{
	BUCK_RF_ID = 1,
	BUCK_MD_ID = 3,
	MAIN_PMIC_ID = 5,
	BUCK_CPU_ID = 6,
	BUCK_GPU_ID = 7,
	BUCK_VPU_ID,
	SUB_PMIC_ID = 10,
	SLV_TYPE_ID_MAX
};

struct spmi_device {
	int slvid;
	int grpiden;
	enum slv_type type;
	enum slv_type_id type_id;
	int mstid;
	unsigned short hwcid_addr;
	unsigned char hwcid_val;
	unsigned short swcid_addr;
	unsigned char swcid_val;
	struct pmif *pmif_arb;
};

/* external API */
int spmi_register_zero_write(struct spmi_device *dev,
	unsigned int addr, unsigned char data);
int spmi_register_read(struct spmi_device *dev,
	unsigned int addr, unsigned char *buf);
int spmi_register_write(struct spmi_device *dev,
	unsigned int addr, unsigned char data);
int spmi_ext_register_read(struct spmi_device *dev,
	unsigned int addr, unsigned char *buf, unsigned short len);
int spmi_ext_register_write(struct spmi_device *dev,
	unsigned int addr, const unsigned char *buf, unsigned short len);
int spmi_ext_register_readl(struct spmi_device *dev, unsigned int addr,
		unsigned char *buf, unsigned short len);
int spmi_ext_register_writel(struct spmi_device *dev, unsigned int addr,
		const unsigned char *buf, unsigned short len);
int spmi_ext_register_readl_field(struct spmi_device *dev, unsigned int addr,
	unsigned char *buf, unsigned short len, unsigned short mask,
	unsigned short shift);
int spmi_ext_register_writel_field(struct spmi_device *dev, unsigned int addr,
	const unsigned char *buf, unsigned short len, unsigned short mask,
	unsigned short shift);

#endif /*__SPMI_H__*/
