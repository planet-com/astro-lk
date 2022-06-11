/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part.
 *
 * MediaTek Inc. (C) 2015. All rights reserved.
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
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

#define LOG_TAG "LCM"

#ifndef BUILD_LK
#  include <linux/string.h>
#  include <linux/kernel.h>
#endif

#include "lcm_drv.h"
#include "lcm_util.h"

#ifdef MTK_ROUND_CORNER_SUPPORT
#include "data_hw_roundedpattern.h"
#endif

#ifdef BUILD_LK
#  include <platform/upmu_common.h>
#  include <platform/mt_gpio.h>
#  include <platform/mt_i2c.h>
#  include <platform/mt_pmic.h>
#  include <string.h>
#  ifndef MACH_FPGA
#    include <lcm_pmic.h>
#  endif
#elif defined(BUILD_UBOOT)
#  include <asm/arch/mt_gpio.h>
#else
#  include <mach/mt_pm_ldo.h>
#  include <mach/mt_gpio.h>
#endif

#include <platform/mt_i2c.h>
#include <libfdt.h>

#ifdef BUILD_LK
#  define LCM_LOGI(string, args...)  dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
#  define LCM_LOGD(string, args...)  dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
#else
#  define LCM_LOGI(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#  define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
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
#  include <linux/kernel.h>
#  include <linux/module.h>
#  include <linux/fs.h>
#  include <linux/slab.h>
#  include <linux/init.h>
#  include <linux/list.h>
#  include <linux/i2c.h>
#  include <linux/irq.h>
#  include <linux/uaccess.h>
#  include <linux/interrupt.h>
#  include <linux/io.h>
#  include <linux/platform_device.h>
#endif

#define FRAME_WIDTH			(1080)
#define FRAME_HEIGHT			(2400)

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
#define LCM_I2C_MODE    ST_MODE
#define LCM_I2C_SPEED   100

/* i2c control end */

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[64];
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	{0x28, 0, {} },
	{0x10, 0, {} },
	{REGFLAG_DELAY, 120, {} },
	{0x4F, 1, {0x01} },
	{REGFLAG_DELAY, 120, {} }
};

static struct LCM_setting_table init_setting_vdo[] = {
{0xFF, 1, {0x10} },
{0xFB, 1, {0x01} },
//DSC on
{0xC0, 1, {0x00} },
{0xC1, 16, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
{0xC2, 2, {0x00, 0x00} },

{0xFF, 1, {0x20} },
{0xFB, 1, {0x01} },
{0x01, 1, {0x66} },
{0x32, 1, {0x4D} },
{0x69, 1, {0xD1} },
{0xF2, 1, {0x64} },
{0xF4, 1, {0x64} },
{0xF6, 1, {0x64} },
{0xF9, 1, {0x64} },

{0xFF, 1, {0x26} },
{0xFB, 1, {0x01} },
{0x81, 1, {0x0E} },
{0x84, 1, {0x03} },
{0x86, 1, {0x03} },
{0x88, 1, {0x07} },

{0xFF, 1, {0x27} },
{0xFB, 1, {0x01} },
{0xE3, 1, {0x01} },
{0xE4, 1, {0xEC} },
{0xE5, 1, {0x02} },
{0xE6, 1, {0xE3} },
{0xE7, 1, {0x01} },
{0xE8, 1, {0xEC} },
{0xE9, 1, {0x02} },
{0xEA, 1, {0x22} },
{0xEB, 1, {0x03} },
{0xEC, 1, {0x32} },
{0xED, 1, {0x02} },
{0xEE, 1, {0x22} },

{0xFF, 1, {0x2A} },
{0xFB, 1, {0x01} },
{0x0C, 1, {0x04} },
{0x0F, 1, {0x01} },
{0x11, 1, {0xE0} },
{0x15, 1, {0x0E} },
{0x16, 1, {0x78} },
{0x19, 1, {0x0D} },
{0x1A, 1, {0xF4} },
{0x37, 1, {0X6E} },
{0X88, 1, {0X76} },

{0xFF, 1, {0x2C} },
{0xFB, 1, {0x01} },
{0x4D, 1, {0x1E} },
{0x4E, 1, {0x04} },
{0X4F, 1, {0X00} },
{0X9D, 1, {0X1E} },
{0X9E, 1, {0X04} },	

{0xFF, 1, {0xF0} },
{0xFB, 1, {0x01} },
{0x5A, 1, {0x00} },

{0xFF, 1, {0xE0} },
{0xFB, 1, {0x01} },
{0x25, 1, {0x02} },
{0x4E, 1, {0x02} },
{0x85, 1, {0x02} },

{0xFF, 1, {0XD0} },
{0xFB, 1, {0x01} },
{0X09, 1, {0XAD} },

{0xFF, 1, {0X20} },
{0xFB, 1, {0x01} },
{0XF8, 1, {0X64} },

{0xFF, 1, {0X2A} },
{0xFB, 1, {0x01} },
{0X1A, 1, {0XF0} },
{0x30, 1, {0x5E} },
{0x31, 1, {0xCA} },
{0x34, 1, {0xFE} },
{0x35, 1, {0x35} },
{0x36, 1, {0xA2} },
{0x37, 1, {0xF8} },
{0x38, 1, {0x37} },
{0x39, 1, {0xA0} },
{0x3A, 1, {0x5E} },
{0x53, 1, {0xD7} },
{0x88, 1, {0x72} },
{0x88, 1, {0x72} },

{0xFF, 1, {0x24} },
{0xFB, 1, {0x01} },
{0xC6, 1, {0xC0} },

{0xFF, 1, {0xE0} },
{0xFB, 1, {0x01} },
{0x25, 1, {0x00} },
{0x4E, 1, {0x02} },
{0x35, 1, {0x82} },

{0xFF, 1, {0xC0} },
{0xFB, 1, {0x01} },
{0x9C, 1, {0x11} },
{0x9D, 1, {0x11} },
/* 60HZ VESA DSC */
{0xFF, 1, {0x25} },
{0xFB, 1, {0x01} },
{0x18, 1, {0x22} },

/* CCMRUN */
{0xFF, 1, {0x10} },
{0xFB, 1, {0x01} },
{0XC0, 1, {0x00} },
{0x51, 1, {0x00} },
{0x35, 1, {0x00} },
{0x53, 1, {0x24} },
{0x55, 1, {0x00} },
{0xFF, 1, {0x10} },
{0x11, 0, {} },
#ifndef LCM_SET_DISPLAY_ON_DELAY
{REGFLAG_DELAY, 120, {} },
/* Display On*/
{0x29, 0, {} },
#endif
};

#ifdef LCM_SET_DISPLAY_ON_DELAY
/* to reduce init time, we move 120ms delay to lcm_set_display_on() !! */
static struct LCM_setting_table set_display_on[] = {
	{0xE9, 0x01, {0xC2} },
	{0xB0, 0x01, {0x01} },
	{0xE9, 0x01, {0x00} },

	{0x29, 0, {} },
	{REGFLAG_DELAY, 50, {} },
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

	params->dsi.mode = SYNC_PULSE_VDO_MODE;
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

	params->dsi.vertical_sync_active = 20;
	params->dsi.vertical_backporch = 20;
	params->dsi.vertical_frontporch = 100;
	/* params->dsi.vertical_frontporch_for_low_power = 750; */
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 22;
	params->dsi.horizontal_backporch = 22;
	params->dsi.horizontal_frontporch = 165;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	/* params->dsi.ssc_disable = 1; */
#ifndef MACH_FPGA
	/* this value must be in MTK suggested table */
	params->dsi.PLL_CLOCK = 635;
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
#endif
	params->dsi.data_rate = 1270;
	params->dsi.CLK_HS_POST = 36;
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 0;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9c;

#ifdef MTK_ROUND_CORNER_SUPPORT
	params->round_corner_params.round_corner_en = 0;
	params->round_corner_params.full_content = 0;
	params->round_corner_params.h = ROUND_CORNER_H_TOP;
	params->round_corner_params.h_bot = ROUND_CORNER_H_BOT;
	params->round_corner_params.tp_size = sizeof(top_rc_pattern);
	params->round_corner_params.lt_addr = (void *)top_rc_pattern;
#endif
}


static int i2c_w8(int bus, uint8_t flags, uint16_t address, uint8_t reg, uint8_t val)
{
	int ret;
	struct mt_i2c_t i2c;
	uint8_t data[4];

	memset(&i2c, 0x0, sizeof(i2c));
	i2c.id = bus;
	i2c.addr = address;
	i2c.mode = ST_MODE;
	i2c.speed = 100;
	i2c.dma_en = 0;
	data[0] = reg;
	data[1] = val;
	ret = i2c_write(&i2c, data, 2);
	return ret;
}

static void lcm_init_power(void)
{
		SET_RESET_PIN(0);
		MDELAY(100);
	if (lcm_util.set_gpio_lcd_enp_bias) {
		lcm_util.set_gpio_lcd_enp_bias(1);
		i2c_w8(0x06, 0, 0x3e, 0x00, 0x0f);
		i2c_w8(0x06, 0, 0x3e, 0x01, 0x0f);

		LCM_LOGI("[zsq] -----lcm_init_power------\n");

	}
	else
		LCM_LOGI("[zsq] set_gpio_lcd_enp_bias not defined\n");
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

	/* we need to wait 150ms after lcm init to set display on */
	timeout_tick = gpt4_time2tick_ms(150);

	while (!gpt4_timeout_tick(lcm_init_tick, timeout_tick)) {
		i++;
		if (i % 1000 == 0) {
			LCM_LOGI("error:lcm_init_tick=%u,cur_tick=%u\n",
				__func__, lcm_init_tick,
				gpt4_get_current_tick());
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
	LCM_LOGI("%s,nt36672c backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

static void lcm_setbacklight(unsigned int level)
{
	LCM_LOGI("%s,nt36672c backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

LCM_DRIVER nt36672c_fhdp_dsi_vdo_90hz_shenchao_lcm_drv = {
	.name = "nt36672c_fhdp_dsi_vdo_90hz_shenchao_lcm_drv",
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

