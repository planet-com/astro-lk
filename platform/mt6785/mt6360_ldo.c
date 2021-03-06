/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part,
* shall be strictly prohibited.
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
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY
* ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY
* THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL
* ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
* RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*/

#include <platform/mt_typedefs.h>
#include <platform/errno.h>
#include <platform/mt_i2c.h>
#include <printf.h>
#include <debug.h>
#include <string.h>

#define CRC8_TABLE_SIZE	(256)
static u8 crc8_table[CRC8_TABLE_SIZE];

struct mt6360_ldo_info {
	struct mt_i2c_t i2c;
	int i2c_log_level;
};

static struct mt6360_ldo_info g_mli = {
	.i2c = {
		.id = I2C5,
		.addr = 0x64,
		.mode = HS_MODE,
		.speed = 400,
		.pushpull = true,
	},
	.i2c_log_level = INFO,
};

/* ldo info */
#define mt6360_decl(_name)\
{ \
	.name = #_name, \
	.enable_reg = mt6360_##_name##_enable_reg, \
	.enable_mask = 0x1, \
	.enable_shift = 6, \
}

#define mt6360_ldo1_enable_reg	0x17
#define mt6360_ldo2_enable_reg	0x11
#define mt6360_ldo3_enable_reg	0x5
#define mt6360_ldo5_enable_reg	0xB
#define mt6360_ldo6_enable_reg	0x37
#define mt6360_ldo7_enable_reg	0x31

struct mt6360_ldo {
	const char *name;
	unsigned short enable_reg;
	unsigned short enable_mask;
	unsigned short enable_shift;
};

static struct mt6360_ldo mt6360_ldos[] = {
	mt6360_decl(ldo1),
	mt6360_decl(ldo2),
	mt6360_decl(ldo3),
	mt6360_decl(ldo5),
	mt6360_decl(ldo6),
	mt6360_decl(ldo7)
};

static void crc8_populate_msb(u8 table[CRC8_TABLE_SIZE], u8 polynomial)
{
	int i, j;
	const u8 msbit = 0x80;
	u8 t = msbit;

	table[0] = 0;

	for (i = 1; i < CRC8_TABLE_SIZE; i *= 2) {
		t = (t << 1) ^ (t & msbit ? polynomial : 0);
		for (j = 0; j < i; j++)
			table[i+j] = table[j]^t;
	}
}

static u8 crc8(const u8 table[CRC8_TABLE_SIZE], u8 *pdata, size_t nbytes, u8 crc)
{
	while (nbytes-- > 0)
		crc = table[(crc ^ *pdata++) & 0xff];

	return crc;
}

/* ========================= */
/* I2C operations */
/* ========================= */
static int mt6360_ldo_write_byte(struct mt6360_ldo_info *mpi, u8 addr, u8 data)
{
	struct mt_i2c_t *i2c = &mpi->i2c;
	int ret = I2C_OK;
	int len = 1;
	u8 chunk[8] = {0};

	if ((addr & 0xc0) != 0) {
		dprintf(CRITICAL, "%s: not support addr [%x]\n", __func__, addr);
		return -EINVAL;
	}
	chunk[0] = (i2c->addr & 0x7f) << 1;
	chunk[1] = (addr & 0x3f)| ((len - 1) << 6);
	memcpy(chunk + 2, &data, len);
	chunk[2+len] = crc8(crc8_table, chunk, 2+len, 0);
	ret = i2c_write(i2c, chunk+1, len+3);
	if (ret != I2C_OK)
		dprintf(CRITICAL,
			"%s: I2CW[0x%02X] = 0x%02X failed, ret = %d\n",
			__func__, addr, data, ret);
	else
		dprintf(mpi->i2c_log_level, "%s: I2CW[0x%02X] = 0x%02X\n",
			__func__, addr, data);
	return ret;
}

static int mt6360_ldo_read_byte(struct mt6360_ldo_info *mpi, u8 addr, u8 *data)
{
	struct mt_i2c_t *i2c = &mpi->i2c;
	int ret = I2C_OK;
	int len = 1;
	u8 chunk[8] = {0};
	u8 temp[2] = {0};

	chunk[0] = ((i2c->addr & 0x7f) << 1) + 1;
	chunk[1] = (addr & 0x3f) | ((len - 1) << 6);
	temp[0] = chunk[1];
	ret = i2c_write_read(i2c, &temp[0], 1, len + 1);
	if (ret != I2C_OK) {
		dprintf(CRITICAL, "%s: I2CR[0x%02X] failed, ret = %d\n",
			__func__, addr, ret);
		return ret;
	}
	chunk[2] = temp[0];
	chunk[3] = temp[1];
	chunk[7] = crc8(crc8_table, chunk, 2 + len, 0);
	if (chunk[2+len] != chunk[7]) {
		dprintf(CRITICAL, "%s: crc check fail\n", __func__);
		return -EINVAL;
	}
	dprintf(mpi->i2c_log_level, "%s: I2CR[0x%02X] = 0x%02X\n",
		__func__, addr, chunk[2]);
	memcpy(data, chunk+2, len);
	return ret;
}

/* ========================= */
/* GLOBAL operations */
/* ========================= */
int mt6360_ldo_read_interface(u8 addr, u8 *data, u8 mask, u8 shift)
{
	int ret = 0;
	u8 rdata = 0;

	ret = mt6360_ldo_read_byte(&g_mli, addr, &rdata);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: fail, addr = 0x%x, ret = %d\n",
			   __func__, addr, ret);
		return ret;
	}
	rdata &= (mask << shift);
	*data = (rdata >> shift);
	return 0;
}

int mt6360_ldo_config_interface(u8 addr, u8 data, u8 mask, u8 shift)
{
	int ret = 0;
	u8 org = 0;

	ret = mt6360_ldo_read_byte(&g_mli, addr, &org);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: fail, addr = 0x%x, ret = %d\n",
			   __func__, addr, ret);
		return ret;
	}
	org &= ~(mask << shift);
	org |= (data << shift);
	return mt6360_ldo_write_byte(&g_mli, addr, org);
}

void mt6360_ldo_enable(u8 ldo_num, bool en)
{
	dprintf(CRITICAL, "%s: %s_en(%d)\n", __func__, mt6360_ldos[ldo_num].name, en);
	if (en)
		mt6360_ldo_config_interface(mt6360_ldos[ldo_num].enable_reg,
			0x1,
			mt6360_ldos[ldo_num].enable_mask,
			mt6360_ldos[ldo_num].enable_shift);
	else
		mt6360_ldo_config_interface(mt6360_ldos[ldo_num].enable_reg,
			0x0,
			mt6360_ldos[ldo_num].enable_mask,
			mt6360_ldos[ldo_num].enable_shift);
}

int mt6360_ldo_i2c_probe(void)
{
	dprintf(CRITICAL, "%s: ++\n", __func__);
	crc8_populate_msb(crc8_table, 0x7);
	dprintf(CRITICAL, "%s: --\n", __func__);
	return 0;
}
