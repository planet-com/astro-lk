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

#ifdef MTK_ROUND_CORNER_SUPPORT
#include "data_hw_roundedpattern.h"
#endif

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

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))
#define MDELAY(n)       (lcm_util.mdelay(n))
#define UDELAY(n)       (lcm_util.udelay(n))

extern U32 gpt4_time2tick_ms(U32 time_ms);

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

#define FRAME_WIDTH                                     (1080)
#define FRAME_HEIGHT                                    (2280)
#define HFP (24)
#define HSA (20)
#define HBP (20)
#define VFP (80)
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
#define LCM_ID_NT36672A (0x72)

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
	{REGFLAG_DELAY, 20, {} },
	{0x10, 0, {} },
	{REGFLAG_DELAY, 120, {} }
};

static struct LCM_setting_table init_setting_vdo[] = {
	{0XFF,1,{0X10}},
	{0XFB,1,{0X01}},
	{0XBB,1,{0X13}},

	{0XFF,1,{0X20}},
	{0XFB,1,{0X01}},
	{0X0E,1,{0XB0}},
	{0X0F,1,{0XAE}},
	{0X62,1,{0XAA}},
	{0X6D,1,{0X44}},
	{0X78,1,{0X01}},
	{0X95,1,{0X87}},
	{0X96,1,{0X87}},
	{0X89,1,{0X17}},
	{0X8A,1,{0X17}},
	{0X8B,1,{0X17}},
	{0X8C,1,{0X17}},
	{0X8D,1,{0X17}},
	{0X8E,1,{0X17}},

	{0XFF,1,{0X24}},
	{0XFB,1,{0X01}},
	{0X00,1,{0X1C}},
	{0X01,1,{0X1C}},
	{0X02,1,{0X1C}},
	{0X03,1,{0X1C}},
	{0X04,1,{0X20}},
	{0X05,1,{0X0D}},
	{0X06,1,{0X09}},
	{0X07,1,{0X0A}},
	{0X08,1,{0X1E}},
	{0X09,1,{0X0D}},
	{0X0A,1,{0X0D}},
	{0X0B,1,{0X25}},
	{0X0C,1,{0X24}},
	{0X0D,1,{0X01}},
	{0X0E,1,{0X04}},
	{0X0F,1,{0X04}},
	{0X10,1,{0X03}},
	{0X11,1,{0X03}},
	{0X12,1,{0X14}},
	{0X13,1,{0X14}},
	{0X14,1,{0X12}},
	{0X15,1,{0X12}},
	{0X16,1,{0X10}},
	{0X17,1,{0X1C}},
	{0X18,1,{0X1C}},
	{0X19,1,{0X1C}},
	{0X1A,1,{0X1C}},
	{0X1B,1,{0X20}},
	{0X1C,1,{0X0D}},
	{0X1D,1,{0X09}},
	{0X1E,1,{0X0A}},
	{0X1F,1,{0X1E}},
	{0X20,1,{0X0D}},
	{0X21,1,{0X0D}},
	{0X22,1,{0X25}},
	{0X23,1,{0X24}},
	{0X24,1,{0X01}},
	{0X25,1,{0X04}},
	{0X26,1,{0X04}},
	{0X27,1,{0X03}},
	{0X28,1,{0X03}},
	{0X29,1,{0X14}},
	{0X2A,1,{0X14}},
	{0X2B,1,{0X12}},
	{0X2D,1,{0X12}},
	{0X2F,1,{0X10}},
	{0X31,1,{0X02}},
	{0X32,1,{0X03}},
	{0X33,1,{0X04}},
	{0X34,1,{0X02}},
	{0X37,1,{0X09}},
	{0X38,1,{0X88}},
	{0X39,1,{0X88}},
	{0X3F,1,{0X88}},
	{0X41,1,{0X02}},
	{0X42,1,{0X03}},
	{0X4C,1,{0X10}},
	{0X4D,1,{0X10}},
	{0X61,1,{0XE8}},
	{0X72,1,{0X00}},
	{0X73,1,{0X00}},
	{0X74,1,{0X00}},
	{0X75,1,{0X00}},
	{0X79,1,{0X23}},
	{0X7A,1,{0X0B}},
	{0X7B,1,{0X99}},
	{0X7C,1,{0X80}},
	{0X7D,1,{0X09}},
	{0X80,1,{0X42}},
	{0X82,1,{0X13}},
	{0X83,1,{0X22}},
	{0X84,1,{0X31}},
	{0X85,1,{0X00}},
	{0X86,1,{0X00}},
	{0X87,1,{0X00}},
	{0X88,1,{0X13}},
	{0X89,1,{0X22}},
	{0X8A,1,{0X31}},
	{0X8B,1,{0X00}},
	{0X8C,1,{0X00}},
	{0X8D,1,{0X00}},
	{0X8E,1,{0XF4}},
	{0X8F,1,{0X01}},
	{0X90,1,{0X80}},
	{0X92,1,{0X8D}},
	{0X93,1,{0X70}},
	{0X94,1,{0X0C}},
	{0X99,1,{0X30}},
	{0XA0,1,{0X30}},

	{0XB3,1,{0X02}},
	{0XB4,1,{0X00}},
	{0XDC,1,{0X64}},
	{0XDD,1,{0X03}},
	{0XDF,1,{0X46}},
	{0XE0,1,{0X46}},
	{0XE1,1,{0X22}},
	{0XE2,1,{0X24}},
	{0XE3,1,{0X09}},
	{0XE4,1,{0X09}},
	{0XEB,1,{0X0B}},

	{0XFF,1,{0X25}},
	{0XFB,1,{0X01}},
	{0X21,1,{0X19}},
	{0X22,1,{0X19}},
	{0X24,1,{0X8D}},
	{0X25,1,{0X8D}},
	{0X30,1,{0X35}},
	{0X38,1,{0X35}},
	{0X3F,1,{0X20}},
	{0X40,1,{0X00}},
	{0X4B,1,{0X20}},
	{0X4C,1,{0X00}},
	{0X58,1,{0X22}},
	{0X59,1,{0X04}},
	{0X5A,1,{0X09}},
	{0X5B,1,{0X09}},
	{0X5C,1,{0X25}},
	{0X5E,1,{0XFF}},
	{0X5F,1,{0X28}},
	{0X66,1,{0XD8}},
	{0X67,1,{0X2B}},
	{0X68,1,{0X58}},
	{0X6B,1,{0X00}},
	{0X6C,1,{0X6D}},
	{0X77,1,{0X72}},
	//ENB_PWRONOFF_ADD_PULSE_ON:1->0
	{0XBF,1,{0X00}},
	{0XC3,1,{0X01}},

	{0XFF,1,{0X26}},
	{0XFB,1,{0X01}},
	{0X00,1,{0XA0}},
	{0X06,1,{0XFF}},
	{0X12,1,{0X72}},
	{0X19,1,{0X00}},
	{0X1A,1,{0X00}},
	{0X1C,1,{0XAF}},
	{0X1D,1,{0XFF}},
	{0X1E,1,{0X83}},
	{0X98,1,{0XF1}},
	{0XA9,1,{0X11}},
	{0XAA,1,{0X11}},
	{0XAE,1,{0X8A}},

	{0XFF,1,{0X27}},
	{0XFB,1,{0X01}},
	{0X13,1,{0X00}},
	{0X1E,1,{0X14}},
	{0X22,1,{0X00}},

	{0XFF,1,{0XF0}},
	{0XFB,1,{0X01}},
	{0XA2,1,{0X00}},
	//gamma 2.2  20200120  MTK6.3-JACKÌá¹©
	{0xFF,1,{0x20}},
	{0xFB,1,{0x01}},
	//R(+)
	{0xB0,16,{0x00,0x08,0x00,0x09,0x00,0x2A,0x00,0x3C,0x00,0x4D,0x00,0x5C,0x00,0x6A,0x00,0x78}},
	{0xB1,16,{0x00,0x85,0x00,0xB5,0x00,0xDC,0x01,0x1E,0x01,0x4F,0x01,0x9F,0x01,0xDE,0x01,0xE1}},
	{0xB2,16,{0x02,0x25,0x02,0x6F,0x02,0xA5,0x02,0xE0,0x03,0x0A,0x03,0x39,0x03,0x49,0x03,0x58}},
	{0xB3,14,{0x03,0x6A,0x03,0x7E,0x03,0x95,0x03,0xB3,0x03,0xD0,0x03,0xD4,0x00,0x00}},
	//G(+)
	{0xB4,16,{0x00,0x08,0x00,0x09,0x00,0x2A,0x00,0x3C,0x00,0x4D,0x00,0x5C,0x00,0x6A,0x00,0x78}},
	{0xB5,16,{0x00,0x85,0x00,0xB5,0x00,0xDC,0x01,0x1E,0x01,0x4F,0x01,0x9F,0x01,0xDE,0x01,0xE1}},
	{0xB6,16,{0x02,0x25,0x02,0x6F,0x02,0xA5,0x02,0xE0,0x03,0x0A,0x03,0x39,0x03,0x49,0x03,0x58}},
	{0xB7,14,{0x03,0x6A,0x03,0x7E,0x03,0x95,0x03,0xB3,0x03,0xD0,0x03,0xD4,0x00,0x00}},
	//B(+)
	{0xB8,16,{0x00,0x08,0x00,0x09,0x00,0x2A,0x00,0x3C,0x00,0x4D,0x00,0x5C,0x00,0x6A,0x00,0x78}},
	{0xB9,16,{0x00,0x85,0x00,0xB5,0x00,0xDC,0x01,0x1E,0x01,0x4F,0x01,0x9F,0x01,0xDE,0x01,0xE1}},
	{0xBA,16,{0x02,0x25,0x02,0x6F,0x02,0xA5,0x02,0xE0,0x03,0x0A,0x03,0x39,0x03,0x49,0x03,0x58}},
	{0xBB,14,{0x03,0x6A,0x03,0x7E,0x03,0x95,0x03,0xB3,0x03,0xD0,0x03,0xD4,0x00,0x00}},
	//CMD2_Page1
	{0xFF,1,{0x21}},
	{0xFB,1,{0x01}},
	//R(-)
	{0xB0,16,{0x00,0x00,0x00,0x01,0x00,0x22,0x00,0x34,0x00,0x45,0x00,0x54,0x00,0x62,0x00,0x70}},
	{0xB1,16,{0x00,0x7D,0x00,0xAD,0x00,0xD4,0x01,0x16,0x01,0x47,0x01,0x97,0x01,0xD6,0x01,0xD9}},
	{0xB2,16,{0x02,0x1D,0x02,0x67,0x02,0x9D,0x02,0xD8,0x03,0x02,0x03,0x31,0x03,0x41,0x03,0x50}},
	{0xB3,14,{0x03,0x62,0x03,0x76,0x03,0x8D,0x03,0xAB,0x03,0xC8,0x03,0xCC,0x00,0x00}},
	//G(-)
	{0xB4,16,{0x00,0x00,0x00,0x01,0x00,0x22,0x00,0x34,0x00,0x45,0x00,0x54,0x00,0x62,0x00,0x70}},
	{0xB5,16,{0x00,0x7D,0x00,0xAD,0x00,0xD4,0x01,0x16,0x01,0x47,0x01,0x97,0x01,0xD6,0x01,0xD9}},
	{0xB6,16,{0x02,0x1D,0x02,0x67,0x02,0x9D,0x02,0xD8,0x03,0x02,0x03,0x31,0x03,0x41,0x03,0x50}},
	{0xB7,14,{0x03,0x62,0x03,0x76,0x03,0x8D,0x03,0xAB,0x03,0xC8,0x03,0xCC,0x00,0x00}},
	//B(-)
	{0xB8,16,{0x00,0x00,0x00,0x01,0x00,0x22,0x00,0x34,0x00,0x45,0x00,0x54,0x00,0x62,0x00,0x70}},
	{0xB9,16,{0x00,0x7D,0x00,0xAD,0x00,0xD4,0x01,0x16,0x01,0x47,0x01,0x97,0x01,0xD6,0x01,0xD9}},
	{0xBA,16,{0x02,0x1D,0x02,0x67,0x02,0x9D,0x02,0xD8,0x03,0x02,0x03,0x31,0x03,0x41,0x03,0x50}},
	{0xBB,14,{0x03,0x62,0x03,0x76,0x03,0x8D,0x03,0xAB,0x03,0xC8,0x03,0xCC,0x00,0x00}},
	//gamma Enhance
	{0xFF,1,{0X20}},
	{0xFB,1,{0X01}},

	{0xFF,1,{0x10}},
//	{0x29, 0, 0, 0, 0, 2,{0xFB,0x01}},
//	{0x29, 0, 0, 0, 0, 2,{0x35,0x00}},//te
	{0x35, 0x1, {0x00}},

	{0x35, 0, {}},

	{0x11,0,{}},

	//DELAY120
	{REGFLAG_DELAY, 120, {} },

	{0x29,0,{}},

};

#ifdef LCM_SET_DISPLAY_ON_DELAY
/* to reduce init time, we move 120ms delay to lcm_set_display_on() !! */
static struct LCM_setting_table set_display_on[] = {
	{0x29, 0, {} }
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
	params->dsi.PLL_CLOCK = 523;
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
#endif
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 1;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x53;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x24;

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
	MDELAY(10);

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

	/* we need to wait 120ms after lcm init to set display on */
	timeout_tick = gpt4_time2tick_ms(120);

	while(!gpt4_timeout_tick(lcm_init_tick, timeout_tick)) {
		i++;
		if (i % 1000 == 0) {
			LCM_LOGI("nt36672a %s error: i=%u,lcm_init_tick=%u,cur_tick=%u\n", __func__,
				i, lcm_init_tick, gpt4_get_current_tick());
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

static void lcm_update(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_set_display_on();
#endif
}


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

	LCM_LOGI("%s, nt36672a backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		sizeof(struct LCM_setting_table), 1);
}

static void lcm_setbacklight(unsigned int level)
{
	LCM_LOGI("%s, nt36672a backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		sizeof(struct LCM_setting_table), 1);
}
static unsigned int lcm_compare_id(void)
{
	unsigned int id = 0, version_id = 0;
	unsigned char buffer[2];
	unsigned int array[16];

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);

	/* read id return two byte,version and id */
	array[0] = 0x00023700;
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xF4, buffer, 2);
	id = buffer[0];     /* we only need ID */

	read_reg_v2(0xDB, buffer, 1);
	version_id = buffer[0];

	LCM_LOGI("%s,nt36672a_id=0x%08x,version_id=0x%x\n",
		__func__, id, version_id);

	if (id == LCM_ID_NT36672A && version_id == 0x80)
		return 1;
	else
		return 0;

}


LCM_DRIVER nt36672a_fhdp_dsi_vdo_auo_rt4801_lcm_drv = {
	.name = "nt36672a_fhdp_dsi_vdo_auo_rt4801_lcm_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.init_power = lcm_init_power,
	.resume_power = lcm_resume_power,
	.suspend_power = lcm_suspend_power,
	.compare_id = lcm_compare_id,
	.set_backlight = lcm_setbacklight,
	.ata_check = lcm_ata_check,
	.update = lcm_update,
};
