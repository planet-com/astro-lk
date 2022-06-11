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
#include <printf.h>
#include <debug.h>
#include <string.h>
#include <platform/spmi.h>
#include <platform/spmi_sw.h>
#include <mtk_subpmic.h>

#define U32_MAX 0xFFFFFFFF

#define MT6362_REG_BUCK1_SEQOFFDLY	(0x107)

struct mt6362_data {
	struct spmi_device *sdev;
	u32 last_access_addr;
	u32 last_access_tick;
};

static struct mt6362_data g_data;

static int mt6362_write_byte(struct mt6362_data *mtdata, u32 addr, u8 data)
{
	struct spmi_device *sdev = mtdata->sdev;
	int ret;

	ret = spmi_ext_register_writel(sdev, addr, &data, 1);
	if (ret < 0)
		return ret;
	mtdata->last_access_addr = addr;
	mtdata->last_access_tick = gpt4_get_current_tick();
	return 0;
}

static int mt6362_read_byte(struct mt6362_data *mtdata, u32 addr, u8 *data)
{
	struct spmi_device *sdev = mtdata->sdev;
	u32 avail_access_tick, current_tick, rest_tick;

	if (addr == mtdata->last_access_addr) {
		avail_access_tick =
			mtdata->last_access_tick + gpt4_time2tick_us(3);
		current_tick = gpt4_get_current_tick();
		if (avail_access_tick > current_tick) {
			rest_tick = avail_access_tick - current_tick;
			udelay(gpt4_tick2time_us(rest_tick));
		}
	}
	return spmi_ext_register_readl(sdev, addr, data, 1);
}

int mtk_subpmic_read_interface(u32 addr, u8 *data, u8 mask, u8 shift)
{
	int ret;
	u8 rdata = 0;

	ret = mt6362_read_byte(&g_data, addr, &rdata);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: fail(%d), addr:0x%x\n",
			__func__, ret, addr);
		return ret;
	}
	rdata &= (mask << shift);
	*data = (rdata >> shift);
	return 0;
}

int mtk_subpmic_config_interface(u32 addr, u8 data, u8 mask, u8 shift)
{
	int ret;
	u8 org = 0;

	ret = mt6362_read_byte(&g_data, addr, &org);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: fail(%d), addr:0x%x\n",
			__func__, ret, addr);
		return ret;
	}
	org &= ~(mask << shift);
	org |= (data << shift);
	return mt6362_write_byte(&g_data, addr, org);
}

int mtk_subpmic_enable_poweroff_sequence(bool en)
{
	int ret;
	unsigned int i;
	u8 seq_delay[9] = {0x24, 0x24, 0x04, 0x22, 0x00, 0x00,
			   0x00, 0x02, 0x04};

	dprintf(CRITICAL, "%s: en = %d\n", __func__, en);
	/* Set sub-pmic buck1/2/3/4/5/6&ldo7/6/4 power off seuqence */
	for (i = 0; i < ARRAY_SIZE(seq_delay); i++) {
		ret = mt6362_write_byte(&g_data,
					MT6362_REG_BUCK1_SEQOFFDLY + i,
					en ? seq_delay[i] : 0x00);
		if (ret < 0) {
			dprintf(CRITICAL,
				"%s: set seq(%d) fail\n", __func__, i);
			return ret;
		}
	}
	return ret;
}

int mtk_subpmic_init(void)
{
	int ret = 0;

	dprintf(CRITICAL, "%s\n", __func__);
	g_data.sdev = get_spmi_device(SPMI_MASTER_0, SPMI_SLAVE_9);
	if (!g_data.sdev) {
		dprintf(CRITICAL, "%s: get spmi device fail\n", __func__);
		return -ENODEV;
	}
	g_data.last_access_addr = U32_MAX;
	return ret;
}
