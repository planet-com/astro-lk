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

#ifdef MTK_ROUND_CORNER_SUPPORT
#include "data_hw_roundedpattern.h"
#endif


#ifdef BUILD_LK
#include <platform/upmu_common.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>
#include <debug.h>
#ifndef MACH_FPGA
#include <lcm_pmic.h>
#endif
#elif defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
#include <mach/mt_pm_ldo.h>
#include <mach/mt_gpio.h>
#endif

#ifdef BUILD_LK
#define LCM_LOGI(string, args...)  dprintf(CRITICAL, "[LK/"LOG_TAG"]"string, ##args)
#define LCM_LOGD(string, args...)  dprintf(INFO, "[LK/"LOG_TAG"]"string, ##args)
#else
#define LCM_LOGI(fmt, args...)  pr_notice("[KERNEL/"LOG_TAG"]"fmt, ##args)
#define LCM_LOGD(fmt, args...)  pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif

#define LCM_ID_NT36672C_JDI (0x01) // TO DO

static const unsigned int BL_MIN_LEVEL = 20;
static LCM_UTIL_FUNCS lcm_util;

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))
#define MDELAY(n)       (lcm_util.mdelay(n))
#define UDELAY(n)       (lcm_util.udelay(n))


/* --------------------------------------------------------------------------- */
/* Local Functions */
/* --------------------------------------------------------------------------- */

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) \
    lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) \
        lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd) lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums) \
        lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd) \
      lcm_util.dsi_dcs_read_lcm_reg(cmd)
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
/* #include <linux/jiffies.h> */
/* #include <linux/delay.h> */
#include <linux/uaccess.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#endif

/* Local Constants */
/* --------------------------------------------------------------------------- */
#define LCM_DSI_CMD_MODE		0
#define FRAME_WIDTH			1080
#define FRAME_HEIGHT			2400

// 0: 60HZCLK + DSC OFF; 1:60HZCLK + DSC ON; 2:90HZCLK + DSC ON
#define DSC_ENABLE				2


#ifndef MACH_FPGA
#define GPIO_65132_EN GPIO_LCD_BIAS_ENP_PIN
#endif

#define REGFLAG_DELAY       0xFFFC
#define REGFLAG_UDELAY  0xFFFB
#define REGFLAG_END_OF_TABLE    0xFFFD
#define REGFLAG_RESET_LOW   0xFFFE
#define REGFLAG_RESET_HIGH  0xFFFF

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

static struct LCM_setting_table init_setting[] = {

	{0xFF,1,{0x25}},
	{0xFB,1,{0x01}},
#if (DSC_ENABLE == 2)
	{0x18,1,{0x20}},  //90HZ CLK
#else
	{0x18,1,{0x21}}, // 60HZ CLK
#if (DSC_ENABLE == 1)
	{0x20,1,{0x00}},
#endif
#endif

	{0xFF,1,{0x10}},
	{0xFB,1,{0x01}},
	{0x35,1,{0x00}},
#if !DSC_ENABLE
	{0xC0,1,{0x00}}, //DSC OFF
#else
	{0xC1,16,{0x89,0x28,0x00,0x14,0x02,0x00,0x02,0x0E,0x01,0xE8,0x00,0x07,0x05,0x0E,0x05,0x16}},
	{0xC2,2,{0x10,0xF0}},
	{0xC0,1,{0x03}}, // DSC ON
#endif
	{0x18,1,{0x21}},

	{0x11,0,{}},
	{REGFLAG_DELAY, 140, {}},
	{0x29,0,{}},
	{REGFLAG_DELAY, 40, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};

#ifdef LCM_SET_DISPLAY_ON_DELAY
/* to reduce init time, we move 120ms delay to lcm_set_display_on() !! */
static struct LCM_setting_table set_display_on[] = {
	{0x29, 0, {} },
};
#endif

static struct LCM_setting_table bl_level[] = {
	{0x51, 1, {0xFF} },
	{REGFLAG_END_OF_TABLE, 0x00, {} }
};

static void push_table(struct LCM_setting_table *table, 
				unsigned int count, 
				unsigned char force_update){
	unsigned int i;

	for (i = 0; i < count; i++) {
		unsigned cmd;
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
				dsi_set_cmdq_V2(cmd, 
							table[i].count, 
							table[i].para_list, 
							force_update);
				break;
		}
	}
}

/* --------------------------------------------------------------------------- */
/* LCM Driver Implementations */
/* --------------------------------------------------------------------------- */

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util) {
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params) {
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;
	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

#if (LCM_DSI_CMD_MODE)
	params->dsi.mode = CMD_MODE;
#else
	params->dsi.mode = SYNC_PULSE_VDO_MODE;
#endif

	/* DSI */
	/* Command mode setting */
	params->dsi.LANE_NUM				= LCM_FOUR_LANE;
	//The following defined the fomat for data coming from LCD engine.
	params->dsi.data_format.color_order 	= LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   	= LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     	= LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      		= LCM_DSI_FORMAT_RGB888;
	/* Highly depends on LCD driver capability. */
	params->dsi.packet_size = 256;
	params->dsi.PS = LCM_PACKED_PS_24BIT_RGB888;

	/* video mode timing */
#if (DSC_ENABLE == 2)// DSC ON + 90HZ CLK
	params->dsi.vertical_sync_active				= 10;
	params->dsi.vertical_backporch					= 54;
	params->dsi.vertical_frontporch					= 1286; //default 60HZ
	params->dsi.vertical_frontporch_for_low_power	= 2600;
	params->dsi.vertical_active_line					= FRAME_HEIGHT;

	params->dsi.horizontal_sync_active				= 16;
	params->dsi.horizontal_backporch				= 156;
	params->dsi.horizontal_frontporch				= 172;
	params->dsi.horizontal_active_pixel				= FRAME_WIDTH;
	params->dsi.ssc_disable						= 1;

#if (LCM_DSI_CMD_MODE)
	params->dsi.PLL_CLOCK						= 500; //this value must be in MTK suggested table
#else
	params->dsi.PLL_CLOCK						= 540; //this value must be in MTK suggested table
#endif

#else

#if (DSC_ENABLE == 1)// DSC ON + 60HZ CLK
	params->dsi.vertical_sync_active				= 10;
	params->dsi.vertical_backporch					= 54;
	params->dsi.vertical_frontporch					= 1286; //default 60HZ
	params->dsi.vertical_active_line					= FRAME_HEIGHT;

	params->dsi.horizontal_sync_active				= 16;
	params->dsi.horizontal_backporch				= 156;
	params->dsi.horizontal_frontporch				= 172;
	params->dsi.horizontal_active_pixel				= FRAME_WIDTH;
	params->dsi.ssc_disable						= 1;

#if (LCM_DSI_CMD_MODE)
	params->dsi.PLL_CLOCK						= 500; //this value must be in MTK suggested table
#else
	params->dsi.data_rate						= 540; //this value must be in MTK suggested table
#endif

#else// DSC OFF + 60HZ CLK
	params->dsi.vertical_sync_active				= 10;
	params->dsi.vertical_backporch					= 54;
	params->dsi.vertical_frontporch					= 36;
	params->dsi.vertical_frontporch_for_low_power	= 750;
	params->dsi.vertical_active_line					= FRAME_HEIGHT;

	params->dsi.horizontal_sync_active				= 16;
	params->dsi.horizontal_backporch				= 50;
	params->dsi.horizontal_frontporch				= 102;
	params->dsi.horizontal_active_pixel				= FRAME_WIDTH;
	params->dsi.ssc_disable						= 1;

#if (LCM_DSI_CMD_MODE)
	params->dsi.PLL_CLOCK						= 480;	/* this value must be in MTK suggested table */
#else
	params->dsi.PLL_CLOCK						= 610;	/* this value must be in MTK suggested table */
#endif

#endif
#endif
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 1;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0A;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9C;

#ifdef MTK_ROUND_CORNER_SUPPORT
	params->round_corner_params.round_corner_en = 1;
	params->round_corner_params.full_content = 0;
	params->round_corner_params.h = ROUND_CORNER_H_TOP;
	params->round_corner_params.h_bot = ROUND_CORNER_H_BOT;
	params->round_corner_params.tp_size = sizeof(top_rc_pattern);
	params->round_corner_params.lt_addr = (void *)top_rc_pattern;
#endif

#if DSC_ENABLE
	params->dsi.dsc_enable = 1;
	params->dsi.dsc_params.ver = 17;
	params->dsi.dsc_params.slice_mode = 1;
	params->dsi.dsc_params.rgb_swap = 0;
	params->dsi.dsc_params.dsc_cfg = 34;
	params->dsi.dsc_params.rct_on = 1;
	params->dsi.dsc_params.bit_per_channel = 8;
	params->dsi.dsc_params.dsc_line_buf_depth = 9;
	params->dsi.dsc_params.bp_enable = 1;
	params->dsi.dsc_params.bit_per_pixel = 128; 
	params->dsi.dsc_params.pic_height = 2400;
	params->dsi.dsc_params.pic_width = 1080;
	params->dsi.dsc_params.slice_height = 20;
	params->dsi.dsc_params.slice_width = 540;
	params->dsi.dsc_params.chunk_size = 540;
	params->dsi.dsc_params.xmit_delay = 512;
	params->dsi.dsc_params.dec_delay = 526;
	params->dsi.dsc_params.scale_value = 32;
	params->dsi.dsc_params.increment_interval = 488;
	params->dsi.dsc_params.decrement_interval = 7;
	params->dsi.dsc_params.line_bpg_offset = 12;
	params->dsi.dsc_params.nfl_bpg_offset = 1294;
	params->dsi.dsc_params.slice_bpg_offset = 1302;
	params->dsi.dsc_params.initial_offset = 6144;
	params->dsi.dsc_params.final_offset = 4336;
	params->dsi.dsc_params.flatness_minqp = 3;
	params->dsi.dsc_params.flatness_maxqp = 12;
	params->dsi.dsc_params.rc_model_size = 8192;
	params->dsi.dsc_params.rc_edge_factor = 6;
	params->dsi.dsc_params.rc_quant_incr_limit0 = 11;
	params->dsi.dsc_params.rc_quant_incr_limit1 = 11;
	params->dsi.dsc_params.rc_tgt_offset_hi = 3;
	params->dsi.dsc_params.rc_tgt_offset_lo = 3;
#endif
}

static int i2c_w8(int bus, 
				uint8_t flags, 
				uint16_t address, 
				uint8_t reg, 
				uint8_t val){
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

static void lcm_init_power(void){
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

static void lcm_suspend_power(void){
}

static void lcm_resume_power(void){
}

#ifdef LCM_SET_DISPLAY_ON_DELAY
static U32 lcm_init_tick = 0;
static int is_display_on = 0;
#endif

static void lcm_init(void){
	SET_RESET_PIN(0);

	MDELAY(15);
	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(10);

	SET_RESET_PIN(1);
	MDELAY(10);

	push_table(init_setting, 
		sizeof(init_setting) / sizeof(struct LCM_setting_table), 
		1);

#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_init_tick = gpt4_get_current_tick();
	is_display_on = 0;
#endif
}

#ifdef LCM_SET_DISPLAY_ON_DELAY
static int lcm_set_display_on(void){
	U32 timeout_tick, i = 0;

	if (is_display_on)
		return 0;

	/* we need to wait 120ms after lcm init to set display on */
	timeout_tick = gpt4_time2tick_ms(120);

	while(!gpt4_timeout_tick(lcm_init_tick, timeout_tick)) {
		i++;
		if (i % 1000 == 0) {
			LCM_LOGI("nt36672c %s error: i=%u,lcm_init_tick=%u,cur_tick=%u\n", __func__,
				i, lcm_init_tick, gpt4_get_current_tick());
		}
	}

	push_table(set_display_on, 
		sizeof(set_display_on) / sizeof(struct LCM_setting_table), 
		1);

	is_display_on = 1;
	return 0;
}
#endif

static void lcm_suspend(void){
	int ret;

	push_table(lcm_suspend_setting, 
		sizeof(lcm_suspend_setting) / sizeof(struct LCM_setting_table), 
		1);
#ifndef MACH_FPGA
	/* enable AVDD & AVEE */
	/* 0x12--default value; bit3--Vneg; bit6--Vpos; */
	/*ret = RT5081_write_byte(0xB1, 0x12);*/
	ret = PMU_REG_MASK(0xB1, (0<<3) | (0<<6), (1<<3) | (1<<6));
	if (ret < 0)
		LCM_LOGI("nt36672c--cmd=%0x--i2c write error----\n", 0xB1);
	else
		LCM_LOGI("nt36672c--cmd=%0x--i2c write success----\n", 0xB1);

	MDELAY(5);

#endif
	SET_RESET_PIN(0);
	MDELAY(10);
}

static void lcm_resume(void){
	lcm_init();
}

#if (LCM_DSI_CMD_MODE)
static void lcm_update(unsigned int x, 
						unsigned int y, 
						unsigned int width, 
						unsigned int height){
	unsigned int x0 = x;
	unsigned int y0 = y;
	unsigned int x1 = x0 + width - 1;
	unsigned int y1 = y0 + height - 1;

	unsigned char x0_MSB = ((x0 >> 8) & 0xFF);
	unsigned char x0_LSB = (x0 & 0xFF);
	unsigned char x1_MSB = ((x1 >> 8) & 0xFF);
	unsigned char x1_LSB = (x1 & 0xFF);
	unsigned char y0_MSB = ((y0 >> 8) & 0xFF);
	unsigned char y0_LSB = (y0 & 0xFF);
	unsigned char y1_MSB = ((y1 >> 8) & 0xFF);
	unsigned char y1_LSB = (y1 & 0xFF);

	unsigned int data_array[16];

#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_set_display_on();
#endif

	data_array[0] = 0x00053902;
	data_array[1] = (x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x00053902;
	data_array[1] = (y1_MSB << 24) | (y0_LSB << 16) | (y0_MSB << 8) | 0x2b;
	data_array[2] = (y1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x002c3909;
	dsi_set_cmdq(data_array, 1, 0);
}
#else /* not LCM_DSI_CMD_MODE */

static void lcm_update(unsigned int x, 
						unsigned int y, 
						unsigned int width, 
						unsigned int height){
#ifdef LCM_SET_DISPLAY_ON_DELAY
	lcm_set_display_on();
#endif
}
#endif

static unsigned int lcm_compare_id(void){
#if 0
	unsigned int id = 0;
	unsigned char buffer[2];
	unsigned int array[16];

	LCM_LOGI("%S: enter\n", __func__);

	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
	MDELAY(10);

	array[0] = 0x00013700;	/* read id return two byte,version and id */
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xDA, buffer, 1);
	id = buffer[0];     /* we only need ID */

	LCM_LOGI("%s,nt3672C_id_jdi=0x%08x\n", __func__, id);

	if (id == LCM_ID_NT36672C_JDI)
		return 1;
	else
		return 0;
#endif
	return 1;
}

/* return TRUE: need recovery */
/* return FALSE: No need recovery */
static unsigned int lcm_esd_check(void)
{
#ifndef BUILD_LK
	char buffer[3];
	int array[4];

	array[0] = 0x00013700;
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0x0A, buffer, 1);

	if (buffer[0] != 0x9C) {
		LCM_LOGI("[LCM ERROR] [0x0A]=0x%02x\n", buffer[0]);
		return TRUE;
	}
	LCM_LOGI("[LCM NORMAL] [0x0A]=0x%02x\n", buffer[0]);
	return FALSE;
#else
	return FALSE;
#endif
}

static void lcm_setbacklight(unsigned int level){
	LCM_LOGI("%s,nt36672c backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level,
		sizeof(bl_level) / sizeof(struct LCM_setting_table),
		1);
}


LCM_DRIVER nt36682c_fhdp_hx_dsi_vdo_dphy_lcm_drv = {
	.name          	 	= "nt36682c_fhdp_hx_dsi_vdo_dphy_lcm_drv",
	.set_util_funcs 	= lcm_set_util_funcs,
	.get_params     	= lcm_get_params,
	.init           		= lcm_init,/*tianma init fun.*/
	.suspend        	= lcm_suspend,
	.resume         	= lcm_resume,
	.compare_id     	= lcm_compare_id,
	.esd_check		=lcm_esd_check,
	.init_power		= lcm_init_power,
	.resume_power 	= lcm_resume_power,
	.suspend_power	= lcm_suspend_power,
	.set_backlight 	= lcm_setbacklight,
	.update			= lcm_update,
};
