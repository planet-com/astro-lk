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

static const unsigned int BL_MIN_LEVEL = 20;
static LCM_UTIL_FUNCS lcm_util;

#define SET_RESET_PIN(v)	(lcm_util.set_reset_pin((v)))
#define MDELAY(n)		(lcm_util.mdelay(n))
#define UDELAY(n)		(lcm_util.udelay(n))


#define dsi_set_cmdq_V22(cmdq, cmd, count, ppara, force_update) \
		lcm_util.dsi_set_cmdq_V22(cmdq, cmd, count, ppara, force_update)
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

#define FRAME_WIDTH										(720)
#define FRAME_HEIGHT									(1520)

#define LCM_PHYSICAL_WIDTH									(64800)
#define LCM_PHYSICAL_HEIGHT									(129600)


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

	dprintf(0,
		"[LCM][i2c write] %s: ch:%u,addr:0x%x,mod:%d,speed:%d,reg:0x%x,val:0x%x\n",
		__func__, tps65132_i2c.id, tps65132_i2c.addr, tps65132_i2c.mode,
		tps65132_i2c.speed, addr, value);
	return ret_code;
}

/* i2c control end */

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[64];
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	{ 0xFF, 0x03, {0x98, 0x81, 0x00} },
	{0x28, 0, {} },
	{REGFLAG_DELAY, 20, {} },
	{0x10, 0, {} },
	{REGFLAG_DELAY, 120, {} }
};

static struct LCM_setting_table init_setting_cmd[] = {
	{ 0xFF, 0x03, {0x98, 0x81, 0x03} },
};

static struct LCM_setting_table init_setting_vdo[] = {
	{ 0xFF, 0x03, {0x98, 0x81, 0x01} },
	{ 0x00, 0x01, {0x48} },
	{ 0x01, 0x01, {0x34} },
	{ 0x02, 0x01, {0x35} },
	{ 0x03, 0x01, {0x5E} },
	{ 0x08, 0x01, {0x86} },
	{ 0x09, 0x01, {0x01} },
	{ 0x0a, 0x01, {0x73} },
	{ 0x0b, 0x01, {0x00} },
	{ 0x0c, 0x01, {0x35} },
	{ 0x0d, 0x01, {0x35} },
	{ 0x0e, 0x01, {0x05} },
	{ 0x0f, 0x01, {0x05} },
	{ 0x28, 0x01, {0x48} },
	{ 0x29, 0x01, {0x86} },
	{ 0x2A, 0x01, {0x48} },
	{ 0x2B, 0x01, {0x86} },
	{ 0x31, 0x01, {0x07} },
	{ 0x32, 0x01, {0x23} },
	{ 0x33, 0x01, {0x00} },
	{ 0x34, 0x01, {0x0B} },
	{ 0x35, 0x01, {0x09} },
	{ 0x36, 0x01, {0x02} },
	{ 0x37, 0x01, {0x15} },
	{ 0x38, 0x01, {0x17} },
	{ 0x39, 0x01, {0x11} },
	{ 0x3A, 0x01, {0x13} },
	{ 0x3B, 0x01, {0x22} },
	{ 0x3C, 0x01, {0x01} },
	{ 0x3D, 0x01, {0x07} },
	{ 0x3E, 0x01, {0x07} },
	{ 0x3F, 0x01, {0x07} },
	{ 0x40, 0x01, {0x07} },
	{ 0x41, 0x01, {0x07} },
	{ 0x42, 0x01, {0x07} },
	{ 0x43, 0x01, {0x07} },
	{ 0x44, 0x01, {0x07} },
	{ 0x45, 0x01, {0x07} },
	{ 0x46, 0x01, {0x07} },
	{ 0x47, 0x01, {0x07} },
	{ 0x48, 0x01, {0x23} },
	{ 0x49, 0x01, {0x00} },
	{ 0x4A, 0x01, {0x0A} },
	{ 0x4B, 0x01, {0x08} },
	{ 0x4C, 0x01, {0x02} },
	{ 0x4D, 0x01, {0x14} },
	{ 0x4E, 0x01, {0x16} },
	{ 0x4F, 0x01, {0x10} },
	{ 0x50, 0x01, {0x12} },
	{ 0x51, 0x01, {0x22} },
	{ 0x52, 0x01, {0x01} },
	{ 0x53, 0x01, {0x07} },
	{ 0x54, 0x01, {0x07} },
	{ 0x55, 0x01, {0x07} },
	{ 0x56, 0x01, {0x07} },
	{ 0x57, 0x01, {0x07} },
	{ 0x58, 0x01, {0x07} },
	{ 0x59, 0x01, {0x07} },
	{ 0x5a, 0x01, {0x07} },
	{ 0x5b, 0x01, {0x07} },
	{ 0x5c, 0x01, {0x07} },
	{ 0x61, 0x01, {0x07} },
	{ 0x62, 0x01, {0x23} },
	{ 0x63, 0x01, {0x00} },
	{ 0x64, 0x01, {0x08} },
	{ 0x65, 0x01, {0x0A} },
	{ 0x66, 0x01, {0x02} },
	{ 0x67, 0x01, {0x12} },
	{ 0x68, 0x01, {0x10} },
	{ 0x69, 0x01, {0x16} },
	{ 0x6a, 0x01, {0x14} },
	{ 0x6b, 0x01, {0x22} },
	{ 0x6c, 0x01, {0x01} },
	{ 0x6d, 0x01, {0x07} },
	{ 0x6e, 0x01, {0x07} },
	{ 0x6f, 0x01, {0x07} },
	{ 0x70, 0x01, {0x07} },
	{ 0x71, 0x01, {0x07} },
	{ 0x72, 0x01, {0x07} },
	{ 0x73, 0x01, {0x07} },
	{ 0x74, 0x01, {0x07} },
	{ 0x75, 0x01, {0x07} },
	{ 0x76, 0x01, {0x07} },
	{ 0x77, 0x01, {0x07} },
	{ 0x78, 0x01, {0x23} },
	{ 0x79, 0x01, {0x00} },
	{ 0x7a, 0x01, {0x09} },
	{ 0x7b, 0x01, {0x0B} },
	{ 0x7c, 0x01, {0x02} },
	{ 0x7d, 0x01, {0x13} },
	{ 0x7e, 0x01, {0x11} },
	{ 0x7f, 0x01, {0x17} },
	{ 0x80, 0x01, {0x15} },
	{ 0x81, 0x01, {0x22} },
	{ 0x82, 0x01, {0x01} },
	{ 0x83, 0x01, {0x07} },
	{ 0x84, 0x01, {0x07} },
	{ 0x85, 0x01, {0x07} },
	{ 0x86, 0x01, {0x07} },
	{ 0x87, 0x01, {0x07} },
	{ 0x88, 0x01, {0x07} },
	{ 0x89, 0x01, {0x07} },
	{ 0x8a, 0x01, {0x07} },
	{ 0x8b, 0x01, {0x07} },
	{ 0x8c, 0x01, {0x07} },
	{ 0xd0, 0x01, {0x01} },
	{ 0xd1, 0x01, {0x00} },
	{ 0xe2, 0x01, {0x00} },
	{ 0xe6, 0x01, {0x22} },
	{ 0xe7, 0x01, {0x54} },
	{ 0xB0, 0x01, {0x33} },
	{ 0xB1, 0x01, {0x33} },
	{ 0xB2, 0x01, {0x00} },
	{ 0xE7, 0x01, {0x54} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x02} },
	{ 0x40, 0x01, {0x52} },
	{ 0x4B, 0x01, {0x5A} },
	{ 0x4D, 0x01, {0x4E} },
	{ 0x1A, 0x01, {0x48} },
	{ 0x4E, 0x01, {0x00} },
	{ 0x1A, 0x01, {0x48} },
	{ 0x70, 0x01, {0x34} },
	{ 0x73, 0x01, {0x0A} },
	{ 0x79, 0x01, {0x06} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x05} },
	{ 0x03, 0x01, {0x01} },
	{ 0x04, 0x01, {0x43} },
	{ 0x58, 0x01, {0x63} },
	{ 0x63, 0x01, {0x88} },
	{ 0x64, 0x01, {0x88} },
	{ 0x68, 0x01, {0x65} },
	{ 0x69, 0x01, {0x7F} },
	{ 0x6A, 0x01, {0xC9} },
	{ 0x6B, 0x01, {0xCF} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x06} },
	{ 0x11, 0x01, {0x03} },
	{ 0x13, 0x01, {0x15} },
	{ 0x14, 0x01, {0x41} },
	{ 0x15, 0x01, {0xc2} },
	{ 0x16, 0x01, {0x40} },
	{ 0x17, 0x01, {0x48} },
	{ 0x18, 0x01, {0x3B} },
	{ 0xD6, 0x01, {0x85} },
	{ 0x27, 0x01, {0x20} },
	{ 0x28, 0x01, {0x20} },
	{ 0x2E, 0x01, {0x01} },
	{ 0xC0, 0x01, {0xF7} },
	{ 0xC1, 0x01, {0x02} },
	{ 0xC2, 0x01, {0x04} },
	{ 0x48, 0x01, {0x0F} },
	{ 0x4D, 0x01, {0x80} },
	{ 0x4E, 0x01, {0x40} },
	{ 0x7C, 0x01, {0x40} },
	{ 0x94, 0x01, {0x00} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x07} },
	{ 0x0F, 0x01, {0x02} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x08} },
	{ 0xE0, 0x27, {0x00, 0x24, 0x3C, 0x51, 0x74, 0x40,
			0x97, 0xB6, 0xDE, 0x03, 0x55, 0x42, 0x7A,
			0xAF, 0xE4, 0xAA, 0x1B, 0x5E, 0x88, 0xBB,
			0xFE, 0xE6, 0x1C, 0x5E, 0x93, 0x03, 0xEC} },
	{ 0xE1, 0x27, {0x00, 0x24, 0x3C, 0x51, 0x74, 0x40,
			0x97, 0xB6, 0xDE, 0x03, 0x55, 0x42, 0x7A,
			0xAF, 0xE4, 0xAA, 0x1B, 0x5E, 0x88, 0xBB,
			0xFE, 0xE6, 0x1C, 0x5E, 0x93, 0x03, 0xEC} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x0E} },
	{ 0x00, 0x01, {0xA0} },
	{ 0x13, 0x01, {0x05} },
	{ 0x11, 0x01, {0x90} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x06} },
	{ 0xD5, 0x01, {0x34} },
	{ 0x58, 0x01, {0xBD} },
	{ 0x94, 0x01, {0x01} },
	{ 0x13, 0x01, {0x4A} },
	{ 0x14, 0x01, {0x2F} },
	{ 0x15, 0x01, {0x0E} },
	{ 0x16, 0x01, {0x2F} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x00} },
	{ 0x11, 0x00, {} },
	{ REGFLAG_DELAY, 120, {} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x02} },
	{ 0x47, 0x01, {0x00} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x06} },
	{ 0xD5, 0x01, {0x30} },
	{ 0x58, 0x01, {0xD5} },
	{ 0x94, 0x01, {0x01} },
	{ 0x17, 0x01, {0xFF} },
	{ 0x18, 0x01, {0x00} },
	{ 0xFF, 0x03, {0x98, 0x81, 0x00} },
	{ 0x29, 0x00, {} },
	{ REGFLAG_DELAY, 20, {} },
	{ 0x35, 0x01, {0x00} }
};

static struct LCM_setting_table bl_level[] = {
	{ 0xFF, 0x03, {0x98, 0x81, 0x00} },
	{ 0x51, 0x02, {0x00, 0xFF} },
	{ REGFLAG_END_OF_TABLE, 0x00, {} }
};

static void push_table(void *cmdq, struct LCM_setting_table *table,
	unsigned int count, unsigned char force_update)
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
			dsi_set_cmdq_V22(cmdq, cmd, table[i].count, table[i].para_list, force_update);
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
	params->physical_width = LCM_PHYSICAL_WIDTH/1000;
	params->physical_height = LCM_PHYSICAL_HEIGHT/1000;


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

	params->dsi.vertical_sync_active = 8;
	params->dsi.vertical_backporch = 20;
	params->dsi.vertical_frontporch = 1250;
	/* params->dsi.vertical_frontporch_for_low_power = 540; */
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 8;
	params->dsi.horizontal_backporch = 10;
	params->dsi.horizontal_frontporch = 36;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	params->dsi.ssc_disable = 1;

#ifndef MACH_FPGA
	params->dsi.PLL_CLOCK = 424;	/* this value must be in MTK suggested table */
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
#endif

	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 0;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0A;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9C;

}

/* turn on gate ic & control voltage to 5.8V */
static void lcm_init_power(void)
{
	if (lcm_util.set_gpio_lcd_enp_bias) {
		lcm_util.set_gpio_lcd_enp_bias(1);
		_lcm_i2c_write_bytes(0x0, 0x12);
		_lcm_i2c_write_bytes(0x1, 0x12);
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

static void lcm_init(void)
{
	SET_RESET_PIN(0);

	SET_RESET_PIN(1);
	MDELAY(1);
	SET_RESET_PIN(0);
	MDELAY(10);

	SET_RESET_PIN(1);
	MDELAY(5);

	push_table(NULL, init_setting_vdo, sizeof(init_setting_vdo) /
		   sizeof(struct LCM_setting_table), 1);
}


static void lcm_suspend(void)
{
	push_table(NULL, lcm_suspend_setting, sizeof(lcm_suspend_setting) /
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

}

#define LCM_ID_ILI9881H (0x46)
#define LCM_VERSION_ILI9881H  (0x33)

static unsigned int lcm_compare_id(void)
{
	unsigned int id = 0, version_id = 0;
	unsigned char buffer[2];
	unsigned int array[16];
	struct LCM_setting_table switch_table_page1[] = {
		{ 0xFF, 0x03, {0x98, 0x81, 0x01} }
	};
	struct LCM_setting_table switch_table_page0[] = {
		{ 0xFF, 0x03, {0x98, 0x81, 0x00} }
	};

	SET_RESET_PIN(1);
	SET_RESET_PIN(0);
	MDELAY(1);

	SET_RESET_PIN(1);
	MDELAY(20);

	push_table(NULL, switch_table_page1, sizeof(switch_table_page1) / sizeof(struct LCM_setting_table), 1);

	array[0] = 0x00023700;	/* read id return two byte,version and id */
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0x00, buffer, 1);
	id = buffer[0];		/* we only need ID */

	read_reg_v2(0x01, buffer, 1);
	version_id = buffer[0];

	LCM_LOGI("%s,ili9881h_id=0x%08x,version_id=0x%x\n", __func__, id, version_id);
	push_table(NULL, switch_table_page0, sizeof(switch_table_page0) / sizeof(struct LCM_setting_table), 1);

	if (id == LCM_ID_ILI9881H && version_id == LCM_VERSION_ILI9881H)
		return 1;
	else
		return 0;

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

	read_reg_v2(0x53, buffer, 1);

	if (buffer[0] != 0x24) {
		LCM_LOGI("[LCM ERROR] [0x53]=0x%02x\n", buffer[0]);
		return TRUE;
	}
	LCM_LOGI("[LCM NORMAL] [0x53]=0x%02x\n", buffer[0]);
	return FALSE;
#else
	return FALSE;
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
	LCM_LOGI("%s,ili9881h backlight: level = %d\n", __func__, level);

	LCM_LOGI("%s,ili9881h backlight: get default level = %d\n", __func__, bl_level[1].para_list[0]);

	//for 12bit switch to 8bit
	bl_level[1].para_list[0] = (level&0xF0)>>4;
	bl_level[1].para_list[1] = (level&0xF)<<4;

	push_table(NULL, bl_level, sizeof(bl_level) /
		   sizeof(struct LCM_setting_table), 1);
}

LCM_DRIVER ili9881h_hdp_dsi_vdo_rt4801_lcm_drv = {
	.name = "ili9881h_hdp_dsi_vdo_rt4801_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.suspend = lcm_suspend,
	.resume = lcm_resume,
	.compare_id = lcm_compare_id,
	.init_power = lcm_init_power,
	.resume_power = lcm_resume_power,
	.suspend_power = lcm_suspend_power,
	.esd_check = lcm_esd_check,
	.set_backlight = lcm_setbacklight_cmdq,
	.ata_check = lcm_ata_check,
	.update = lcm_update,
};

