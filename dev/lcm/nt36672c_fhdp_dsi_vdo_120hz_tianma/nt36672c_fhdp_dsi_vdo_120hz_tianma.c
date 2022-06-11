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
#  include <linux/string.h>
#  include <linux/kernel.h>
#endif

#include "lcm_drv.h"
#include "lcm_util.h"


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
//#define FRAME_HEIGHT			(2280)
#define FRAME_HEIGHT			(2340)

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
static struct LCM_setting_table init_setting_cmd[] = {
	{0xFF, 1, {0x10} },
	{0xFB, 1, {0x01} },
	{0x3B, 5, {0x03,0x0A,0x0A,0x04,0x04} },
	{0XB0, 1, {0X00} },
	{0xC1, 16, {0x89,0x28,0x00,0x14,0x02,0x00,0x02,0x0E,0x01,0xE8,0x00,0x07,0x05,0x0E,0x05,0x16}},
	{0xC2, 2, {0x1B,0xA0} },
	{0xFF, 1, {0x20} },
	{0xFB, 1, {0x01} },
	{0X01, 1, {0X66} },
	{0x06, 1, {0x3C} },
	{0x07, 1, {0x28} },
	{0x69, 1, {0xEA} },
	{0x95, 1, {0xD1} },
	{0x96, 1, {0xD1} },
	{0XF2, 1, {0X64} },
	{0XF4, 1, {0X64} },
	{0XF6, 1, {0X64} },
	{0XF8, 1, {0X64} },
	{0xFF, 1, {0x24} },
	{0xFB, 1, {0x01} },
	{0x00, 1, {0x01} },
	{0x01, 1, {0x0C} },
	{0x02, 1, {0x0B} },
	{0x03, 1, {0x0B} },
	{0x04, 1, {0x2C} },
	{0x05, 1, {0x2D} },
	{0x06, 1, {0x2E} },
	{0x07, 1, {0x2F} },
	{0x08, 1, {0x30} },
	{0x09, 1, {0x0F} },
	{0x0A, 1, {0x10} },
	{0x0B, 1, {0x24} },
	{0x0C, 1, {0x24} },
	{0x0D, 1, {0x18} },
	{0x0E, 1, {0x16} },
	{0x0F, 1, {0x14} },
	{0x10, 1, {0x17} },
	{0x11, 1, {0x15} },
	{0x12, 1, {0x13} },
	{0x13, 1, {0x24} },
	{0x14, 1, {0x00} },
	{0x15, 1, {0x00} },
	{0x16, 1, {0x00} },
	{0x17, 1, {0x20} },
	{0x18, 1, {0x01} },
	{0x19, 1, {0x0C} },
	{0x1A, 1, {0x0B} },
	{0x1B, 1, {0x0B} },
	{0x1C, 1, {0x2C} },
	{0x1D, 1, {0x2D} },
	{0x1E, 1, {0x2E} },
	{0x1F, 1, {0x2F} },
	{0x20, 1, {0x30} },
	{0x21, 1, {0x0F} },
	{0x22, 1, {0x10} },
	{0x23, 1, {0x24} },
	{0x24, 1, {0x24} },
	{0x25, 1, {0x18} },
	{0x26, 1, {0x16} },
	{0x27, 1, {0x14} },
	{0x28, 1, {0x17} },
	{0x29, 1, {0x15} },
	{0x2A, 1, {0x13} },
	{0x2B, 1, {0x24} },
	{0x2D, 1, {0x00} },
	{0x2F, 1, {0x00} },
	{0x30, 1, {0x00} },
	{0x31, 1, {0x20} },
	{0x32, 1, {0x00} },
	{0x34, 1, {0x10} },
	{0x35, 1, {0x3C} },
	{0x36, 1, {0x14} },
	{0x4D, 1, {0x02} },
	{0x4E, 1, {0x3A} },
	{0x4F, 1, {0x3A} },
	{0x53, 1, {0x3A} },
	{0x79, 1, {0x11} },
	{0x7A, 1, {0x82} },
	{0x7B, 1, {0x8F} },
	{0x82, 1, {0x13} },
	{0x83, 1, {0x22} },
	{0x84, 1, {0x31} },
	{0x85, 1, {0x00} },
	{0x86, 1, {0x00} },
	{0x87, 1, {0x00} },
	{0x90, 1, {0x13} },
	{0x91, 1, {0x22} },
	{0x92, 1, {0x31} },
	{0x93, 1, {0x00} },
	{0x94, 1, {0x00} },
	{0x95, 1, {0x00} },
	{0x9C, 1, {0xF4} },
	{0x9D, 1, {0x01} },
	{0xD9, 1, {0x80} },
	{0xA0, 1, {0x0F} },
	{0xA2, 1, {0x0F} },
	{0xA3, 1, {0x02} },
	{0xC9, 1, {0x0C} },
	{0xD1, 1, {0x34} },
	{0xE9, 1, {0x02} },
	{0xFF, 1, {0x25} },
	{0xFB, 1, {0x01} },
	{0x66, 1, {0x5D} },
	{0x68, 1, {0x50} },
	{0x69, 1, {0x60} },
	{0x6B, 1, {0x00} },

	{0x71, 1, {0x6D} },
	{0x77, 1, {0x60} },
	{0x79, 1, {0x40} },
	{0x7E, 1, {0x25} },
	{0x81, 1, {0x04} },
	{0x84, 1, {0x34} },
	{0x85, 1, {0x15} },
	{0x8E, 1, {0x10} },
	{0xC2, 1, {0xD2} },
	{0xD6, 1, {0x80} },
	{0xD7, 1, {0x02} },
	{0xDA, 1, {0x00} },
	{0xDD, 1, {0x02} },
	{0xE0, 1, {0x00} },
	{0xEF, 1, {0x00} },
	{0xF1, 1, {0x04} },
	{0xFF, 1, {0x26} },
	{0xFB, 1, {0x01} },
	{0x03, 1, {0x00} },
	{0x04, 1, {0x7C} },
	{0x08, 1, {0x21} },
	{0x15, 1, {0x01} },
	{0x74, 1, {0xAF} },
	{0x81, 1, {0x0F} },
	{0x83, 1, {0x04} },
	{0x85, 1, {0x01} },
	{0x87, 1, {0x01} },
	{0x88, 1, {0x03} },
	{0x8A, 1, {0x1A} },
	{0x8B, 1, {0x11} },
	{0x8C, 1, {0x24} },
	{0x8E, 1, {0x42} },
	{0x8F, 1, {0x11} },
	{0x90, 1, {0x11} },
	{0x91, 1, {0x11} },
	{0x9A, 1, {0x80} },
	{0x9B, 1, {0x42} },
	{0x9C, 1, {0x00} },
	{0x9D, 1, {0x00} },
	{0x9E, 1, {0x00} },
	{0xFF, 1, {0x27} },
	{0xFB, 1, {0x01} },
	{0x20, 1, {0x81} },
	{0x21, 1, {0x82} },
	{0x25, 1, {0x81} },
	{0x26, 1, {0xAB} },
	{0x6E, 1, {0x01} },
	{0x6F, 1, {0x00} },
	{0x70, 1, {0x00} },
	{0x71, 1, {0x00} },
	{0x72, 1, {0x00} },
	{0x73, 1, {0x04} },
	{0x74, 1, {0x21} },
	{0x75, 1, {0x03} },
	{0x76, 1, {0x00} },
	{0x77, 1, {0x00} },
	{0x7D, 1, {0x09} },
	{0x7E, 1, {0x25} },
	{0x80, 1, {0x24} },
	{0x82, 1, {0x09} },
	{0x83, 1, {0x25} },
	{0x88, 1, {0x01} },
	{0x89, 1, {0x10} },
	{0xB7, 1, {0x04} },
	{0xFF, 1, {0x2A} },
	{0xFB, 1, {0x01} },
	{0x01, 1, {0x00} },
	{0x05, 1, {0x00} },
	{0x06, 1, {0x07} },
	{0x08, 1, {0x0E} },
	{0x0A, 1, {0x04} },
	{0x0B, 1, {0x01} },
	{0x0C, 1, {0x09} },
	{0x11, 1, {0xEA} },
	{0x15, 1, {0x07} },
	{0x16, 1, {0xC3} },
	{0x1A, 1, {0x40} },
	{0x1B, 1, {0x0A} },
	{0x1D, 1, {0x0A} },
	{0x1E, 1, {0x42} },
	{0x1F, 1, {0x42} },
	{0x20, 1, {0x42} },
	{0x28, 1, {0x08} },
	{0x37, 1, {0x70} },
	{0xFF, 1, {0xD0} },
	{0xFB, 1, {0x01} },
	{0xB0, 1, {0x00} },
	{0xFF, 1, {0x20} },
	{0xFB, 1, {0x01} },
	{0x01, 1, {0x66} },
	{0xF2, 1, {0x64} },
	{0xF4, 1, {0x64} },
	{0xF6, 1, {0x64} },
	{0xF8, 1, {0x64} },
	{0xFF, 1, {0x24} },
	{0xFB, 1, {0x01} },
	{0xC9, 1, {0x00} },
	{0xFF, 1, {0xE0} },
	{0xFB, 1, {0x01} },
	{0x25, 1, {0x02} },
	{0x4E, 1, {0x02} },
	{0x85, 1, {0x32} },
	{0xFF, 1, {0xF0} },
	{0xFB, 1, {0x01} },
	{0x5A, 1, {0x00} },
	{0xA0, 1, {0x08} },
	{0xFF, 1, {0xD0} },
	{0xFB, 1, {0x01} },
	{0x09, 1, {0xAD} },
	{0xFF, 1, {0x10} },
	{0x51, 1, {0xFF} },
	{0x53, 1, {0x24} },
	{0x35, 1, {0x00} },
/*
	{0xFF, 1, {0x20} },
	{0xFB, 1, {0x01} },
	{0x86, 1, {0x03} },
*/
	{0xFF, 1, {0x10} },

	{0x11, 0, {} },
	{REGFLAG_DELAY, 100, {} },
	{0x29, 0, {} },
	{REGFLAG_DELAY, 20, {} },

};
#ifdef LCM_SET_DISPLAY_ON_DELAY
/* to reduce init time, we move 120ms delay to lcm_set_display_on() !! */
static struct LCM_setting_table set_display_on[] = {
	{0x29, 0, {}},
	{REGFLAG_DELAY, 100, {} }, //Delay 100ms
};
#endif

static struct LCM_setting_table bl_level[] = {
	{0x51,2,{0x03,0xFF}},
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

	/* params->dsi.ssc_disable = 1; */
	params->dsi.vertical_sync_active = 10;
	params->dsi.vertical_backporch = 25;
	params->dsi.vertical_frontporch = 16;
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 20;
	params->dsi.horizontal_backporch = 80;
	params->dsi.horizontal_frontporch = 80;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.HS_PRPR = 10;
	params->dsi.ssc_disable = 1;
#ifndef MACH_FPGA
	params->dsi.PLL_CLOCK = 535;
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
#endif
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 0;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9c;

	params->dsi.dsc_enable = 1;
	params->dsi.dsc_params.ver = 17;
	params->dsi.dsc_params.slice_mode = 1;
	params->dsi.dsc_params.rgb_swap = 0;
	params->dsi.dsc_params.dsc_cfg = 34;
	params->dsi.dsc_params.rct_on = 1;
	params->dsi.dsc_params.bit_per_channel = 8;
	params->dsi.dsc_params.dsc_line_buf_depth = 9;
	params->dsi.dsc_params.bp_enable = 1;
	params->dsi.dsc_params.bit_per_pixel = 128;  //128
	params->dsi.dsc_params.pic_height = 2340;
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
}

/* turn on gate ic & control voltage to 5.5V */

static void lcm_init_power(void)
{
	mt_set_gpio_mode(42,GPIO_MODE_GPIO);	/*set reset pin mode*/
	mt_set_gpio_dir(42,GPIO_DIR_OUT);

	mt_set_gpio_mode(138,GPIO_MODE_GPIO);	/*TP RESET*/
	mt_set_gpio_dir(138,GPIO_DIR_OUT);

	//ktd2151_set_avdd_n_avee(55);
	/*ENP 6.0V*/
	mt_set_gpio_mode(126,GPIO_MODE_GPIO);
	mt_set_gpio_dir(126,GPIO_DIR_OUT);
	mt_set_gpio_out(126,GPIO_OUT_ONE);
	MDELAY(10);
	/*ENN -6.0V*/
	mt_set_gpio_mode(127,GPIO_MODE_GPIO);
	mt_set_gpio_dir(127,GPIO_DIR_OUT);
	mt_set_gpio_out(127,GPIO_OUT_ONE);
	MDELAY(20);

	mt_set_gpio_mode(28, GPIO_MODE_GPIO);	/*LCM_BL_EN*/
	mt_set_gpio_dir(28, GPIO_DIR_OUT);
	mt_set_gpio_out(28, GPIO_OUT_ONE);

}

static void lcm_suspend_power(void)
{
	SET_RESET_PIN(0);
	if (0) /*(lcm_util.set_gpio_lcd_enp_bias)*/
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
	MDELAY(5);
	SET_RESET_PIN(1);
	MDELAY(5);
	SET_RESET_PIN(0);
	MDELAY(5);

	SET_RESET_PIN(1);
	MDELAY(15);

	push_table(init_setting_cmd, sizeof(init_setting_cmd) /
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
#if 0
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
#endif
static void lcm_setbacklight(unsigned int level)
{
	printf("%s,td4320 backlight: level = %d\n", __func__, level);

	bl_level[0].para_list[0] = level;

	push_table(bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

static void lcm_update(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
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

static unsigned int lcm_compare_id(void)
{
	unsigned int id = 0, version_id = 0;
	unsigned char buffer[2];
	unsigned int array[16];

	/***sleep  to close driver ic  power****/
	array[0] = 0x00100500;
	dsi_set_cmdq(array, 1, 1);
	MDELAY(20);
	/*****************************/

	array[0] = 0x00013700;  /* read id return two byte,version and id */
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xDA, buffer, 1);
	id = buffer[0];

	LCM_LOGI("%s,id=0x%08x\n", __func__, id);
	//id = 0x55;
	LCM_LOGI("%s,id=0x%08x\n", __func__, id);
	if (id == 0x55) {
		//lcm_software_id = id;


		array[0] = 0xf0ff1500;
		dsi_set_cmdq(array, 1, 1);
		MDELAY(2);
		array[0] = 0x00013700;
		dsi_set_cmdq(array, 1, 1);
		MDELAY(2);

		return 1;
	}
	else
		return 0;

}
/*
static void lcm_setbacklight(unsigned int level)
{
	lm3697_set_brightness(1023);
} */
LCM_DRIVER nt36672c_fhdp_dsi_vdo_120hz_tianma_lcm_drv = {
	.name = "nt36672c_fhdp_dsi_vdo_120hz_tianma_lcm_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,
	.resume_power = lcm_resume_power,
	.suspend_power = lcm_suspend_power,
	.set_backlight = lcm_setbacklight,
	//.ata_check = lcm_ata_check,
	.update = lcm_update,
};

