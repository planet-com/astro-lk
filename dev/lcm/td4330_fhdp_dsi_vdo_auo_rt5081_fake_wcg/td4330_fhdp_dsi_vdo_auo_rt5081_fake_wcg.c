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

#define LOG_TAG "LCM"

#ifndef BUILD_LK
	#include <linux/string.h>
	#include <linux/kernel.h>
#endif

#include "lcm_drv.h"
#include "lcm_util.h"


#ifdef BUILD_LK
	#include <platform/upmu_common.h>
	#include <platform/mt_gpio.h>
	#include <platform/mt_i2c.h>
	#include <platform/mt_pmic.h>
	#include <platform/mt_gpt.h>
	#include <string.h>
#ifndef MACH_FPGA
	#include <lcm_pmic.h>
#endif
#elif defined(BUILD_UBOOT)
	#include <asm/arch/mt_gpio.h>
#else
	#include <mach/mt_pm_ldo.h>
	#include <mach/mt_gpio.h>
#endif

#include <platform/mt_i2c.h>
#include <libfdt.h>

#ifdef BUILD_LK
	#define LCM_LOGI(string, args...)  dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
	#define LCM_LOGD(string, args...)  dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
#else
	#define LCM_LOGI(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
	#define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif


static LCM_UTIL_FUNCS lcm_util;

#define SET_RESET_PIN(v)	(lcm_util.set_reset_pin((v)))
#define MDELAY(n)		(lcm_util.mdelay(n))
#define UDELAY(n)		(lcm_util.udelay(n))

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) \
		lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) \
		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd) lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums) \
		lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd)	lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size) \
		lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

#ifndef BUILD_LK
	#include <linux/kernel.h>
	#include <linux/module.h>
	#include <linux/fs.h>
	#include <linux/slab.h>
	#include <linux/init.h>
	#include <linux/list.h>
	#include <linux/i2c.h>
	#include <linux/irq.h>
	#include <linux/uaccess.h>
	#include <linux/interrupt.h>
	#include <linux/io.h>
	#include <linux/platform_device.h>
#endif

#define FRAME_WIDTH			(1080)
#define FRAME_HEIGHT			(2280)
#define HFP (24)
#define HSA (20)
#define HBP (20)
#define VFP (75)
#define VSA (2)
#define VBP (12)

#define REGFLAG_DELAY			0xFFFC
#define REGFLAG_UDELAY			0xFFFB
#define REGFLAG_END_OF_TABLE		0xFFFD
#define REGFLAG_RESET_LOW		0xFFFE
#define REGFLAG_RESET_HIGH		0xFFFF

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* i2c control start */
extern void *g_fdt;
#define LCM_I2C_MODE    ST_MODE
#define LCM_I2C_SPEED   100

static struct mt_i2c_t tps65132_i2c;
static int _lcm_i2c_write_bytes(kal_uint8 addr, kal_uint8 value)
{
	kal_int32 ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;
	int id, i2c_addr;

	write_data[0] = addr;
	write_data[1] = value;

	if (lcm_util_get_i2c_lcd_bias(&id, &i2c_addr) < 0)
		return -1;
	tps65132_i2c.id = (U16)id;
	tps65132_i2c.addr = (U16)i2c_addr;
	tps65132_i2c.mode = LCM_I2C_MODE;
	tps65132_i2c.speed = LCM_I2C_SPEED;
	len = 2;

	ret_code = i2c_write(&tps65132_i2c, write_data, len);
	if (ret_code<0)
		dprintf(0, "[LCM][ERROR] %s: %d\n", __func__, ret_code);

	return ret_code;
}

/* i2c control end */

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[200];
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	{0x28, 0, {} },
	{REGFLAG_DELAY, 50, {} },
	{0x10, 0, {} },
	{REGFLAG_DELAY, 150, {} },
};

static struct LCM_setting_table init_setting_vdo[] = {
	{0xB0, 0x1, {0x00}},
	{0xB6, 0xC, {0x30,0x6B,0x00,0x06,0x03,0x0A,0x13,0x1A,0x6C,
							  0x18,0x19,0x02}},
	{0xB7, 0x4, {0x71,0x00,0x00,0x00}},
	{0xB8, 0x7, {0x57,0x3d,0x19,0xbe,0x1e,0x0a,0x0a}},
	{0xB9, 0x7, {0x6f,0x3d,0x28,0xbe,0x3c,0x14,0x0a}},
	{0xBA, 0x7, {0xb5,0x33,0x41,0xbe,0x64,0x23,0x0a}},
	{0xBB, 0xB, {0x44,0x26,0xC3,0x1F,0x19,0x06,0x03,0xC0,0x00,
							   0x00,0x10}},
	{0xBC, 0xB, {0x32,0x4C,0xC3,0x52,0x32,0x1F,0x03,0xF2,0x00,
							   0x00,0x13}},
	{0xBD, 0xB, {0x24,0x68,0xC3,0xAA,0x3F,0x32,0x03,0xFF,0x00,
							   0x00,0x25}},
	{0xBE, 0xC, {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							   0x00,0x00,0x00}},
	{0xC0, 0xC, {0x00,0xDC,0x00,0xDC,0x13,0x08,0xE8,0x00,0x08,
							   0x00,0x03,0x78}},
	{0xC1, 0x23, {0x30,0x00,0x00,0x11,0x11,0x00,0x00,0x00,0x22,
							   0x00,0x05,0x20,0xFA,0x00,0x08,0x00,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x00}},
	{0xC2, 0x78, {0x06,0xE0,0x6E,0x01,0x03,0x00,0x02,0x00,0x00,
							    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							    0x00,0x00,0x11,0x00,0x00,0x00,0x00,0x04,0xA0,0xC9,
							    0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xEB,0x00,0x00,
							    0x01,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x00,0x00,
							    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							    0x00,0x00,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x00,
							    0x00,0x00,0xDC,0x00,0x00,0x00,0x00,0x04,0x00,0x08,
							    0xEF,0x00,0x00,0x00,0x00,0x00,0x11,0x00,0x00,0x00,
							    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							    0x00}},
	{0xC3, 0x6C, {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0xaa,0xaa,0xaa,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
	{0xC4, 0x61, {0x00,0x4c,0x00,0x3f,0x00,0x83,0x00,0x00,0x87,
				0x86,0x85,0x84,0x00,0x00,0x00,0x00,0x00,0x61,0x5d,
				0x5f,0x00,0x5e,0x60,0x62,0x00,0x00,0x00,0x02,0x00,
				0x83,0x00,0x00,0x87,0x86,0x85,0x84,0x00,0x00,0x00,
				0x00,0x00,0x61,0x5d,0x5f,0x00,0x5e,0x60,0x62,0xff,
				0xff,0xff,0xff,0xff,0xff,0x00,0x0f,0x0e,0x00,0x0f,
				0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xee,
				0x00,0x0f,0xee,0x00,0x00,0xe0,0x00,0x00,0xe0,0x0e,
				0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0xff,
				0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
	{0xC5, 0x5, {0x08,0x00,0x00,0x00,0x00}},
	{0xC6, 0x39, {0x02,0x0a,0x08,0xfc,0xff,0xff,0xff,0x00,0x00,
				0x13,0x01,0xf0,0x0c,0x06,0x01,0x43,0x43,0x43,0x00,
				0x00,0x00,0x01,0x77,0x09,0x28,0x28,0x06,0x01,0x43,
				0x43,0x43,0x00,0x00,0x00,0x01,0x61,0x00,0x00,0x00,
				0x1c,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x20,0x20,0x00,0x00}},

	//GAMMA2.2_20180522
	{0xC7, 0x4C, {0x00,0x00,0x00,0xe0,0x01,0xE9,0x02,0x7e,0x02,
				0x05,0x02,0x90,0x02,0xf6,0x02,0x40,0x02,0x5C,0x02,
				0x77,0x02,0xC8,0x02,0x1b,0x02,0x5b,0x02,0xBd,0x02,
				0x27,0x02,0xc3,0x03,0x54,0x03,0xd8,0x03,0xff,0x00,
				0x00,0x00,0xe0,0x01,0xE9,0x02,0x7e,0x02,0x05,0x02,
				0x90,0x02,0xf6,0x02,0x40,0x02,0x5C,0x02,0x77,0x02,
				0xC8,0x02,0x1b,0x02,0x5b,0x02,0xBd,0x02,0x27,0x02,
				0xc3,0x03,0x54,0x03,0xd8,0x03,0xff}},
	{0xC8, 0x41, {0x41,0x00,0xff,0xfa,0x00,0xff,0x00,0x00,0xfe,
				0xf6,0xfe,0xe9,0x00,0x00,0xff,0xf7,0xfb,0xe1,0x00,
				0x00,0x00,0x00,0x00,0xff,0x00,0x00,0xff,0xfa,0x00,
				0xff,0x00,0xfe,0xf6,0xfe,0xe9,0x00,0xff,0xf7,0xfb,
				0xe1,0x00,0x00,0x00,0x00,0xff,0x00,0xff,0xfa,0x00,
				0xff,0x00,0xfe,0xf6,0xfe,0xe9,0x00,0xff,0xf7,0xfb,
				0xe1,0x00,0x00,0x00,0x00,0xff}},
	{0xC9, 0x18, {0x00,0xff,0xfa,0x00,0xff,0x00,0x00,0xfe,0xf6,
				0xfe,0xe9,0x00,0x00,0xff,0xf7,0xfb,0xe1,0x00,0x00,
				0x00,0x00,0x00,0xff,0x00}},
	{0xCA, 0x41, {0x1c,0xfc,0xfc,0xfc,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00,0x00,0x00,0x00,0x00,0x00}},
	{0xCC, 0xA, {0x00,0x00,0x4d,0x8b,0x55,0x4d,0x8b,0xaa,0x4d,
				0x8b}},
	{0xCD, 0x1, {0x00}},
	{0xCE, 0x23, {0x5d,0x40,0x49,0x53,0x59,0x5e,0x63,0x68,0x6e,
				0x74,0x7e,0x8a,0x98,0xa8,0xbb,0xd0,0xe7,0xff,0x04,
				0x00,0x04,0x04,0x42,0x04,0x69,0x5a,0x40,0x11,0xf4,
				0x00,0x00,0x84,0xfa,0x00,0x00}},
	{0xCF, 0x6, {0x00,0x00,0x80,0x46,0x61,0x00}},
	{0xD0, 0x11, {0xf6,0x95,0x11,0xb1,0x55,0xcf,0x00,0xf6,0xd3,
				0x11,0xf0,0x01,0x12,0xcf,0x02,0x20,0x11}},
	{0xD1, 0x22, {0xd3,0xd3,0x33,0x33,0x07,0x03,0x3b,0x33,0x77,
				0x37,0x77,0x37,0x35,0x77,0x07,0x77,0xf7,0x33,0x73,
				0x07,0x33,0x33,0x03,0x33,0x1b,0x03,0x32,0x3d,0x0a,
				0x30,0x13,0x13,0x20,0x00}},
	{0xD2, 0x3, {0x00,0x00,0x07,0x00}},
	{0xD3, 0x99, {0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,
				0x57,0x00,0x00,0x32,0x00,0x00,0x1a,0x70,0x01,0x19,
				0x80,0x01,0x01,0xf0,0x02,0x00,0xe0,0x06,0xff,0xf7,
				0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,
				0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,
				0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,
				0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,
				0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,
				0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,
				0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,
				0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,
				0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,
				0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,
				0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,
				0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,0xff,0xff,0xf7,
				0xff,0xff,0xf7,0xff}},

	//And,VCOM,reference,setting,
	{0xE5, 0x4, {0x03,0x00,0x00,0x00}},
	{0xD5, 0x8, {0x02,0x42,0x02,0x42,0x02,0xdc,0x02,0xdc}},//26
	{0xD6, 0x1, {0xc0}},

	{0xD7, 0x31, {0x21,0x10,0x52,0x52,0x00,0xB6,0x04,0xFD,0x00,
							   0xB6,0x04,0xFD,0x00,0x82,0x80,0x83,0x84,0x85,0x83,
							   0x80,0x84,0x45,0x85,0x85,0x85,0x87,0x04,0x06,0x02,
							   0x04,0x04,0x07,0x10,0x0C,0x0B,0x0A,0x0A,0x07,0x06,
							   0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
	{0xDD, 0x4, {0x30,0x06,0x23,0x65}},
	{0xDE, 0xC, {0x00,0x00,0x00,0x0f,0xff,0x00,0x00,0x00,0x00,
				0x00,0x00,0x10}},
	{0xE3, 0x1, {0xff}},
	{0xE6, 0x6, {0x00,0x00,0x00,0x00,0x00,0x00}},
	{0xE7, 0xA, {0x50,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
				0x00}},
	{0xE8, 0x4, {0x00,0x01,0x23,0x00}},
	{0xEA, 0x1, {0x00}},
	{0xEB, 0x7, {0x00,0x00,0x00,0x00,0x01,0x00,0x11}},
	{0xEC, 0x3, {0x00,0x00,0x00}},
	{0xED, 0x20, {0x01,0x01,0x02,0x02,0x02,0x02,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x00,0x10,0x00,
							   0x18,0x00,0x18,0x00,0xB0,0x00,0x00,0x00,0x00,0x00,
							   0xDA,0x10,0x00}},
	{0xEE, 0x60, {0x03,0x0F,0x00,0x00,0x00,0x00,0x40,0x1F,0x00,
							   0x00,0x0F,0xF2,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,
							   0x01,0x00,0x09,0x01,0x8C,0xD8,0xEF,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x50,0x1F,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
							   0x00,0x00,0x00,0x00,0x00,0x00,0x00}},
	{0xEF, 0x8B, {0x00,0x70,0x4A,0x08,0xD0,0x00,0x00,0x00,0x00,
								0x3C,0x3C,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,
								0x4A,0x08,0xD0,0x00,0x00,0x00,0x00,0x3C,0x3C,0x3C,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x03,0x08,0xEC,0x50,0x10,0x00,0x10,
								0x00,0x0A,0x0A,0x00,0x00,0x00,0x00,0x10,0x0F,0x00,
								0x03,0x51,0x00,0x50,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x08,0xEC}},
	{0xB0, 0x1, {0x03}},

	{0xB0, 0x1, {0x04}},//Unlock,Manufacture,Command,Access,Protect,of,group,M,and,A
	{0xD6, 0x1, {0x00}},//OTP/Flash,Load,setting
	//CABC
	{0x51, 0x2, {0xff,0xf0}},
	{0x53, 0x1, {0x0c}},

	{0x55, 0x1, {0x00}},//Write_CABC
	//TE ON
	{0x35, 0x1, {0x00}},

	{0x35, 0, {}},

	{0x11, 0, {}},
#ifndef LCM_SET_DISPLAY_ON_DELAY
	{REGFLAG_DELAY, 200, {} }, //Delay 200ms

	{0x29, 0, {}},
	{REGFLAG_DELAY, 100, {} }, //Delay 100ms
#endif
};

#ifdef LCM_SET_DISPLAY_ON_DELAY
/* to reduce init time, we move 120ms delay to lcm_set_display_on() !! */
static struct LCM_setting_table set_display_on[] = {
	{0x29, 0, {}},
	{REGFLAG_DELAY, 100, {} }, //Delay 100ms
};
#endif

static struct LCM_setting_table bl_level[] = {
	{0x51, 1, {0xFF} },
	{REGFLAG_END_OF_TABLE, 0x00, {} }
};

static void push_table(struct LCM_setting_table *table, unsigned int count,
		       unsigned char force_update)
{
	unsigned int i;
	unsigned int cmd;

	for (i = 0; i < count; i++) {
		cmd = table[i].cmd;
		switch (cmd) {
		case REGFLAG_DELAY:
			if (table[i].count <= 10)
				MDELAY(table[i].count);
			else
				MDELAY(table[i].count);
			break;
		case REGFLAG_UDELAY:
			UDELAY(table[i].count);
			break;
		case REGFLAG_END_OF_TABLE:
			break;
		default:
			dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list,
					force_update);
			break;
		}
	}
}

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;

	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

	params->dsi.mode = SYNC_EVENT_VDO_MODE;
	params->dsi.switch_mode = CMD_MODE;
	params->dsi.switch_mode_enable = 0;

	/* DSI */
	/* Command mode setting */
	params->dsi.LANE_NUM = LCM_FOUR_LANE;
	/* The following defined the fomat for data coming from LCD engine. */
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format = LCM_DSI_FORMAT_RGB888;

	/* Highly depends on LCD driver capability. */
	params->dsi.packet_size = 256;
	/* video mode timing */

	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	params->dsi.vertical_sync_active = VSA;
	params->dsi.vertical_backporch = VBP;
	params->dsi.vertical_frontporch = VFP;
	params->dsi.vertical_frontporch_for_low_power = 750;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = HSA;
	params->dsi.horizontal_backporch = HBP;
	params->dsi.horizontal_frontporch = HFP;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.ssc_disable = 1;
#ifndef MACH_FPGA
	/* this value must be in MTK suggested table */
	params->dsi.PLL_CLOCK = 522;
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
#endif
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 1;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9c;
}

/* turn on gate ic & control voltage to 5.5V */
static void lcm_init_power(void)
{
	if (lcm_util.set_gpio_lcd_enp_bias) {
		lcm_util.set_gpio_lcd_enp_bias(1);
		_lcm_i2c_write_bytes(0x0, 0xf);
		_lcm_i2c_write_bytes(0x1, 0xf);
	}
	else
		LCM_LOGI("set_gpio_lcd_enp_bias not defined\n");
}

static void lcm_suspend_power(void)
{
	SET_RESET_PIN(0);
	if (lcm_util.set_gpio_lcd_enp_bias)
		lcm_util.set_gpio_lcd_enp_bias(0);
	else
		LCM_LOGI("set_gpio_lcd_enp_bias not defined\n");
}

static void lcm_resume_power(void)
{
	SET_RESET_PIN(0);
	lcm_init_power();
}

#ifdef LCM_SET_DISPLAY_ON_DELAY
static U32 lcm_init_tick = 0;
static int is_display_on = 0;
#endif

static void lcm_init(void)
{
	SET_RESET_PIN(0);

	SET_RESET_PIN(1);
	MDELAY(1);
	SET_RESET_PIN(0);
	MDELAY(10);

	SET_RESET_PIN(1);
	MDELAY(5);

	push_table(init_setting_vdo, sizeof(init_setting_vdo) /
		   sizeof(struct LCM_setting_table), 1);

#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_init_tick = gpt4_get_current_tick();
	is_display_on = 0;
#endif
}

#ifdef LCM_SET_DISPLAY_ON_DELAY
static int lcm_set_display_on(void)
{
	U32 timeout_tick, i = 0;

	if (is_display_on)
		return 0;

	/* we need to wait 200ms after lcm init to set display on */
	timeout_tick = gpt4_time2tick_ms(200);

	while (!gpt4_timeout_tick(lcm_init_tick, timeout_tick)) {
		i++;
		if (i % 1000 == 0) {
			LCM_LOGI("td4320 %s error: i=%u,lcm_init_tick=%u,cur_tick=%u\n",
				 __func__, i, lcm_init_tick, gpt4_get_current_tick());
		}
	}

	push_table(set_display_on, sizeof(set_display_on) /
		   sizeof(struct LCM_setting_table), 1);

	is_display_on = 1;
	return 0;
}
#endif

static void lcm_suspend(void)
{
	push_table(lcm_suspend_setting, sizeof(lcm_suspend_setting) /
		   sizeof(struct LCM_setting_table), 1);

	SET_RESET_PIN(0);
	MDELAY(10);
}

static void lcm_resume(void)
{
	lcm_init();
}

#if 1
static void lcm_update(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_set_display_on();
#endif
}
#else
static void lcm_update(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_set_display_on();
#endif
}
#endif

static unsigned int lcm_ata_check(unsigned char *buffer)
{
#ifndef BUILD_LK
	unsigned int ret = 0;
	unsigned int x0 = FRAME_WIDTH / 4;
	unsigned int x1 = FRAME_WIDTH * 3 / 4;

	unsigned char x0_MSB = ((x0 >> 8) & 0xFF);
	unsigned char x0_LSB = (x0 & 0xFF);
	unsigned char x1_MSB = ((x1 >> 8) & 0xFF);
	unsigned char x1_LSB = (x1 & 0xFF);

	unsigned int data_array[3];
	unsigned char read_buf[4];

	LCM_LOGI("ATA check size = 0x%x,0x%x,0x%x,0x%x\n",
		 x0_MSB, x0_LSB, x1_MSB, x1_LSB);
	data_array[0] = 0x0005390A; /* HS packet */
	data_array[1] = (x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x00043700; /* read id return two byte,version and id */
	dsi_set_cmdq(data_array, 1, 1);

	read_reg_v2(0x2A, read_buf, 4);

	if ((read_buf[0] == x0_MSB) && (read_buf[1] == x0_LSB) &&
	    (read_buf[2] == x1_MSB) && (read_buf[3] == x1_LSB))
		ret = 1;
	else
		ret = 0;

	x0 = 0;
	x1 = FRAME_WIDTH - 1;

	x0_MSB = ((x0 >> 8) & 0xFF);
	x0_LSB = (x0 & 0xFF);
	x1_MSB = ((x1 >> 8) & 0xFF);
	x1_LSB = (x1 & 0xFF);

	data_array[0] = 0x0005390A; /* HS packet */
	data_array[1] = (x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);
	return ret;
#else
	return 0;
#endif
}

static void lcm_setbacklight_cmdq(void *handle, unsigned int level)
{
	LCM_LOGI("%s,td4320 backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

static void lcm_setbacklight(unsigned int level)
{
	LCM_LOGI("%s,td4320 backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

LCM_DRIVER td4330_fhdp_dsi_vdo_auo_rt5081_fake_wcg_lcm_drv = {
	.name = "td4330_fhdp_dsi_vdo_auo_rt5081_fake_wcg_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.init_power = lcm_init_power,
	.resume_power = lcm_resume_power,
	.suspend_power = lcm_suspend_power,
	.set_backlight = lcm_setbacklight,
	.ata_check = lcm_ata_check,
	.update = lcm_update,
};

