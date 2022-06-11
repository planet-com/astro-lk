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
#include <string.h>
#ifndef MACH_FPGA
#include <lcm_pmic.h>
#endif
#elif defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
#include <mach/mt_pm_ldo.h>
#include <platform/mt_typedefs.h>
#include <debug.h>
#include <string.h>
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
#include <mt6360_ldo.h>

#define FRAME_WIDTH		(1200)
#define FRAME_HEIGHT		(2000)
#define GPIO_OUT_ONE		1
#define GPIO_OUT_ZERO		0

#define REGFLAG_DELAY		0xFFFC
#define REGFLAG_UDELAY		0xFFFB
#define REGFLAG_END_OF_TABLE	0xFFFD
#define REGFLAG_RESET_LOW	0xFFFE
#define REGFLAG_RESET_HIGH	0xFFFF

#define LCM_ID_HX83102P 0x00000083

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/*
GPIO44       LCM_RST */
#ifdef GPIO_LCM_RST
#define GPIO_LCD_RST		GPIO_LCM_RST
#else
#define GPIO_LCD_RST 		(GPIO44 | 0x80000000)
#endif

/* GPIO22       LED_EN */
#ifdef GPIO_LCM_BL_EN
#define GPIO_LCD_BL_EN		GPIO_LCM_BL_EN
#else
#define GPIO_LCD_BL_EN 		(GPIO22 | 0x80000000)
#endif

/* GPIO23       ENP */
#ifdef GPIO_LCM_BIAS_ENP_PIN
#define GPIO_LCD_BIAS_ENP	GPIO_LCM_BIAS_ENP_PIN
#else
#define GPIO_LCD_BIAS_ENP 	(GPIO23 | 0x80000000)
#endif

/* GPIO202       ENN */
#ifdef GPIO_LCM_BIAS_ENN_PIN
#define GPIO_LCD_BIAS_ENN	GPIO_LCM_BIAS_ENN_PIN
#else
#define GPIO_LCD_BIAS_ENN 	(GPIO202 | 0x80000000)
#endif

static void lcm_set_gpio_output(unsigned int GPIO, unsigned int output)
{
	if (GPIO == 0xFFFFFFFF) {
		printf("[LK/LCM] GPIO error =  %ud\n", GPIO);
		return;
	}
#ifdef BUILD_LK
	mt_set_gpio_mode(GPIO, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO, (output > 0) ? GPIO_OUT_ONE : GPIO_OUT_ZERO);
#endif
}

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[64];
};

static struct LCM_setting_table lcm_suspend_setting[] = {
	{0x28, 0, {} },
	{REGFLAG_DELAY, 50, {} },
	{0x10, 0, {} },
	{REGFLAG_DELAY, 150, {} },
};

static struct LCM_setting_table init_setting_vdo[] = {
	{REGFLAG_DELAY, 150, {} },
	{0xB9, 0x03, {0x83, 0x10, 0x2E} },
	{0xE9, 0x01, {0xCD} },
	{0xBB, 0x01, {0x01} },
	{0xE9, 0x01, {0x00} },
	{0xD1, 0x04, {0x67, 0x0C, 0xFF, 0x05} },
	{0xB1, 0x11, {0x10, 0xFA, 0xAF, 0xAF, 0x2B, 0x2B, 0xB2, 0x57, 0x4D, 0x36,
                      0x36, 0x36, 0x36, 0x22, 0x21, 0x15, 0x00} },
	{0xB2, 0x10, {0x00, 0xB0, 0x47, 0xD0, 0x00, 0x2C, 0x50, 0x2C, 0x00, 0x00,
                      0x00, 0x00, 0x15, 0x20, 0xD7, 0x00} },
	{0xB4, 0x10, {0x70, 0x60, 0x01, 0x01, 0x80, 0x67, 0x00, 0x00, 0x01, 0x9B,
                      0x01, 0x58, 0x00, 0xFF, 0x00, 0xFF} },
	{0xBF, 0x03, {0xFC, 0x85, 0x80} },
	{0xD2, 0x02, {0x2B, 0x2B} },
	{0xD3, 0x2B, {0x00, 0x00, 0x00, 0x00, 0x78, 0x04, 0x00, 0x04, 0x00, 0x27,
                      0x00, 0x64, 0x4F, 0x2D, 0x2D, 0x00, 0x00, 0x32, 0x10, 0x27,
                      0x00, 0x27, 0x32, 0x10, 0x23, 0x00, 0x23, 0x32, 0x18, 0x03,
                      0x08, 0x03, 0x00, 0x00, 0x20, 0x30, 0x01, 0x55, 0x21, 0x2E,
                      0x01, 0x55, 0x0F} },
	{0xE0, 0x2E, {0x00, 0x05, 0x0E, 0x15, 0x1C, 0x30, 0x46, 0x4D, 0x53, 0x4F,
                      0x68, 0x6D, 0x73, 0x82, 0x80, 0x89, 0x92, 0xA6, 0xA6, 0x52,
                      0x5A, 0x65, 0x70, 0x00, 0x05, 0x0E, 0x15, 0x1C, 0x30, 0x46,
                      0x4D, 0x53, 0x4F, 0x68, 0x6D, 0x73, 0x82, 0x80, 0x89, 0x92,
                      0xA6, 0xA6, 0x52, 0x5A, 0x65, 0x70} },
	{0xBD, 0x01, {0x01} },
	{0xB1, 0x04, {0x01, 0x9B, 0x01, 0x31} },
	{0xCB, 0x0A, {0xF4, 0x36, 0x12, 0x16, 0xC0, 0x28, 0x6C, 0x85, 0x3F, 0x04} },
	{0xD3, 0x0B, {0x01, 0x00, 0xBC, 0x00, 0x00, 0x11, 0x10, 0x00, 0x0E, 0x00,
                      0x01} },
	{0xBD, 0x01, {0x02} },
	{0xB4, 0x06, {0x4E, 0x00, 0x33, 0x11, 0x33, 0x88} },
	{0xBF, 0x03, {0xF2, 0x00, 0x02} },
	{0xBD, 0x01, {0x00} },
	{0xC0, 0x0E, {0x23, 0x23, 0x22, 0x11, 0xA2, 0x17, 0x00, 0x80, 0x00, 0x00,
                      0x08, 0x00, 0x63, 0x63} },
	{0xC6, 0x01, {0xF9} },
	{0xC7, 0x01, {0x30} },
	{0xC8, 0x08, {0x00, 0x04, 0x04, 0x00, 0x00, 0x85, 0x43, 0xFF} },
	{0xD0, 0x03, {0x07, 0x04, 0x05} },
	{0xD5, 0x2C, {0x18, 0x18, 0x18, 0x18, 0x1A, 0x1A, 0x1A, 0x1A, 0x1B, 0x1B,
                      0x1B, 0x1B, 0x24, 0x24, 0x24, 0x24, 0x07, 0x06, 0x07, 0x06,
                      0x05, 0x04, 0x05, 0x04, 0x03, 0x02, 0x03, 0x02, 0x01, 0x00,
                      0x01, 0x00, 0x21, 0x20, 0x21, 0x20, 0x18, 0x18, 0x18, 0x18,
                      0x18, 0x18, 0x18, 0x18} },
	{0xE7, 0x17, {0x12, 0x13, 0x02, 0x02, 0x49, 0x49, 0x0E, 0x0E, 0x0F, 0x1A,
                      0x1D, 0x74, 0x28, 0x74, 0x01, 0x07, 0x00, 0x00, 0x00, 0x00,
                      0x17, 0x00, 0x68} },
	{0xBD, 0x01, {0x01} },
	{0xE7, 0x07, {0x02, 0x38, 0x01, 0x93, 0x0D, 0xDA, 0x0E} },
	{0xBD, 0x01, {0x02} },
	{0xE7, 0x1C, {0xFF, 0x01, 0xFF, 0x01, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00,
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                      0x00, 0x00, 0x00, 0x00, 0x81, 0x00, 0x02, 0x40} },
	{0xBD, 0x01, {0x00} },
	{0xBA, 0x08, {0x70, 0x03, 0xA8, 0x83, 0xF2, 0x80, 0xC0, 0x0D} },
	{0xBD, 0x01, {0x02} },
	{0xD8, 0x0C, {0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
                      0xF0, 0x00} },
	{0xBD, 0x01, {0x03} },
	{0xD8, 0x18, {0xAA, 0xAA, 0xAA, 0xAA, 0xA0, 0x00, 0xAA, 0xAA, 0xAA, 0xAA,
                      0xA0, 0x00, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x55, 0x55,
                      0x55, 0x55, 0x50, 0x00} },
	{0xBD, 0x01, {0x00} },
	{0xE1, 0x02, {0x01, 0x06} },
	{0xCC, 0x01, {0x02} },
	{0xBD, 0x01, {0x03} },
	{0xB2, 0x01, {0x80} },
	{0xBD, 0x01, {0x00} },
	/*{0xCF, 0x01, {0xFF} },*/
	{0x11, 0, {} },
	{REGFLAG_DELAY, 60, {} },
	{0xB2, 0x10, {0x00, 0xB0, 0x47, 0xD0, 0x00, 0x2C, 0x50, 0x2C, 0x00, 0x00,
                      0x00, 0x00, 0x15, 0x20, 0xD7, 0x00} },
	{0x51, 0x02, {0x07, 0xB8} },
	{0x53, 0x01, {0x2c} },
	{0xc9, 0x04, {0x00, 0x0d, 0xf0, 0x00} },
	/*R51, 0x00, 0x00*/
	/*R53, 0x2C*/
	/*RC9, 0x00, 0x0D, 0xF0, 0x00*/
	{REGFLAG_DELAY, 120, {} },
	{0x29, 0, {} },
	{REGFLAG_DELAY, 20, {} },
};

static struct LCM_setting_table bl_level[] = {
	/* {0x51, 2, {0x07, 0x87} }, */
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

	params->dsi.vertical_sync_active = 8;
	params->dsi.vertical_backporch = 38;
	params->dsi.vertical_frontporch = 80;
	/* params->dsi.vertical_frontporch_for_low_power = 750; */
	params->dsi.vertical_active_line = FRAME_HEIGHT;

	params->dsi.horizontal_sync_active = 8;
	params->dsi.horizontal_backporch = 28;
	params->dsi.horizontal_frontporch = 36;
	params->dsi.horizontal_active_pixel = FRAME_WIDTH;
	/* params->dsi.ssc_disable = 1; */
#ifndef MACH_FPGA
	/* this value must be in MTK suggested table */
	params->dsi.PLL_CLOCK = 522;
#else
	params->dsi.pll_div1 = 0;
	params->dsi.pll_div2 = 0;
	params->dsi.fbk_div = 0x1;
#endif
	params->dsi.CLK_HS_POST = 36;
	params->dsi.clk_lp_per_line_enable = 0;
	params->dsi.esd_check_enable = 0;
	params->dsi.customization_esd_check_enable = 0;
	params->dsi.lcm_esd_check_table[0].cmd = 0x0a;
	params->dsi.lcm_esd_check_table[0].count = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9c;
}

#ifdef BUILD_LK
#ifndef MACH_FPGA
#define I2C_KTZ8864A_PMU_CHANNEL 5
#define I2C_KTZ8864A_PMU_SLAVE_7_BIT_ADDR 0x11

static int KTZ8864A_read_byte (kal_uint8 addr, kal_uint8 *dataBuffer)
{
	kal_uint32 ret = I2C_OK;
	kal_uint16 len;
	struct mt_i2c_t KTZ8864A_i2c;
	*dataBuffer = addr;

	KTZ8864A_i2c.id = I2C_KTZ8864A_PMU_CHANNEL;
	KTZ8864A_i2c.addr = I2C_KTZ8864A_PMU_SLAVE_7_BIT_ADDR;
	KTZ8864A_i2c.mode = ST_MODE;
	KTZ8864A_i2c.speed = 100;
	len = 1;

	ret = i2c_write_read(&KTZ8864A_i2c, dataBuffer, len, len);
	if (I2C_OK != ret)
	LCM_LOGI("[lk/lcm] %s: i2c_read  failed! ret: %d\n", __func__, ret);

	return ret;
}

static int KTZ8864A_write_byte(kal_uint8 addr, kal_uint8 value)
{
	kal_uint32 ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;
	struct mt_i2c_t KTZ8864A_i2c;

	write_data[0] = addr;
	write_data[1] = value;

	KTZ8864A_i2c.id = I2C_KTZ8864A_PMU_CHANNEL;
	KTZ8864A_i2c.addr = I2C_KTZ8864A_PMU_SLAVE_7_BIT_ADDR;
	KTZ8864A_i2c.mode = ST_MODE;
	KTZ8864A_i2c.speed = 100;
	len = 2;

	ret_code = i2c_write(&KTZ8864A_i2c, write_data, len);

	return ret_code;
}

static int KTZ8864A_REG_MASK (kal_uint8 addr, kal_uint8 val, kal_uint8 mask)
{
	kal_uint8 KTZ8864A_reg = 0;
	kal_uint32 ret = 0;

	ret = KTZ8864A_read_byte(addr, &KTZ8864A_reg);

	KTZ8864A_reg &= ~mask;
	KTZ8864A_reg |= val;

	ret = KTZ8864A_write_byte(addr, KTZ8864A_reg);
	LCM_LOGI("[lk/lcm] addr=%02x----reg=%02x--\n", addr, KTZ8864A_reg);

	return ret;
}
#endif
#endif


/* turn on gate ic & control voltage to 5.5V */
static void lcm_init_power(void)
{
	int ret = 0;

	LCM_LOGD("[lk/lcm] %s\n", __func__);

	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);

	/* VPT_PMU */
	mt6360_ldo_enable(MT6360_LDO2, 1);
	mt6360_ldo_config_interface(0x11, 1, 1, 9);
	MDELAY(5);
#ifdef BUILD_LK
	/* Set AVDD*/
	/* 5.8V --- 4.0V+36*0.05V */
	ret = KTZ8864A_REG_MASK(0x0d, 0x24, (0x3F << 0));
	if (ret < 0)
		LCM_LOGI("[lk/lcm] ktz8864a--set AVDD--cmd=%0x--i2c write error----\n", 0x0d);
	else
		LCM_LOGI("[lk/lcm] ktz8864a--set AVDD--cmd=%0x--i2c write success----\n", 0x0d);

	/* Set AVEE */
	/* (-5.8V) --- (-4.0V)+36*(-0.05V) */
	ret = KTZ8864A_REG_MASK(0x0e, 0x24, (0x3F << 0));
	if (ret < 0)
		LCM_LOGI("[lk/lcm] ktz8864a--set AVEE--cmd=%0x--i2c write error----\n", 0x0e);
	else
		LCM_LOGI("[lk/lcm] ktz8864a--set AVEE--cmd=%0x--i2c write success----\n", 0x0e);

	/* Enable AVDD discharge*/
	ret = KTZ8864A_REG_MASK(0x09, 0x9c, 0x9d);
	if (ret < 0)
		LCM_LOGI("[lk/lcm] ktz8864a--enable--cmd=%0x--i2c write error----\n", 0x09);
	else
		LCM_LOGI("[lk/lcm] ktz8864a--enable--cmd=%0x--i2c write success----\n", 0x09);

	lcm_set_gpio_output(GPIO_LCD_BIAS_ENP, GPIO_OUT_ONE);
	MDELAY(5);

	/* Enable AVEE discharge*/
	ret = KTZ8864A_REG_MASK(0x09, 0x02, 0x02);
	if (ret < 0)
		LCM_LOGI("[lk/lcm] ktz8864a--enable--cmd=%0x--i2c write error----\n", 0x09);
	else
		LCM_LOGI("[lk/lcm] ktz8864a--enable--cmd=%0x--i2c write success----\n", 0x09);

	lcm_set_gpio_output(GPIO_LCD_BIAS_ENN, GPIO_OUT_ONE);
	MDELAY(13);

	/* After 6ms reset HLH */
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(2);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ZERO);
	MDELAY(16);
	lcm_set_gpio_output(GPIO_LCD_RST, GPIO_OUT_ONE);
	MDELAY(50);
#endif
}

#ifdef LCM_SET_DISPLAY_ON_DELAY
static U32 lcm_init_tick = 0;
static int is_display_on = 0;
#endif

static void lcm_init(void)
{
	int ret = 0;

	LCM_LOGD("[lk/lcm] %s\n", __func__);

#ifdef BUILD_LK
	push_table(init_setting_vdo,
		sizeof(init_setting_vdo) / sizeof(struct LCM_setting_table),
		1);

	MDELAY(100);
	lcm_set_gpio_output(GPIO_LCD_BL_EN, GPIO_OUT_ONE);

	ret = KTZ8864A_REG_MASK(0x02, 0x61, 0xe9); //bl ovp 29v & exponential & enable pwn
	if (ret < 0)
		LCM_LOGI("ktz8864a----cmd=%0x--i2c write error----\n", 0x02);
	else
		LCM_LOGI("ktz8864a----cmd=%0x--i2c write success----\n", 0x02);

	ret = KTZ8864A_REG_MASK(0x15, 0xa0, 0xf8);
	if (ret < 0)
		LCM_LOGI("ktz8864a----cmd=%0x--i2c write error----\n", 0x15);
	else
		LCM_LOGI("ktz8864a----cmd=%0x--i2c write success----\n", 0x15);

	/* enable BL ic*/
	ret = KTZ8864A_REG_MASK(0x08, 0x1f, 0x1f);
	if (ret < 0)
		LCM_LOGI("ktz8864a----cmd=%0x--i2c write error----\n", 0x08);
	else
		LCM_LOGI("ktz8864a----cmd=%0x--i2c write success----\n", 0x08);
#endif

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

	/* We need to wait 150ms after lcm init to set display on */
	timeout_tick = gpt4_time2tick_ms(150);

	while (!gpt4_timeout_tick(lcm_init_tick, timeout_tick)) {
		i++;
		if (i % 1000 == 0) {
			LCM_LOGI("[lk/lcm] hx83102p %s error: i=%u,lcm_init_tick=%u,cur_tick=%u\n",
				 __func__, i, lcm_init_tick, gpt4_get_current_tick());
		}
	}

	/*
	 * push_table(set_display_on, sizeof(set_display_on) /
	 *		sizeof(struct LCM_setting_table), 1);
	 */
	is_display_on = 1;
	return 0;
}
#endif

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

	LCM_LOGI("ATA check size = 0x%x, 0x%x, 0x%x, 0x%x\n",
		 x0_MSB, x0_LSB, x1_MSB, x1_LSB);
	data_array[0] = 0x0005390A; /* HS packet */
	data_array[1] = (x1_MSB << 24) | (x0_LSB << 16) | (x0_MSB << 8) | 0x2a;
	data_array[2] = (x1_LSB);
	dsi_set_cmdq(data_array, 3, 1);

	data_array[0] = 0x00043700; /* read id return two byte, version and id */
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
	LCM_LOGI("[lk/lcm] %s, backlight: level = %d\n", __func__, level);

	if (level != 0)
		level = level * 4095 / 255;
	bl_level[0].para_list[0] = (level >> 8) & 0xF;
	bl_level[0].para_list[1] = level & 0xFF;

	push_table(bl_level, sizeof(bl_level) /
		sizeof(struct LCM_setting_table), 1);
}

static void lcm_setbacklight(unsigned int level)
{
	LCM_LOGI("[lk/lcm] %s, backlight: level = %d\n", __func__, level);

	if (level != 0)
		level = level * 4095 / 255;
	bl_level[0].para_list[0] = (level >> 8) & 0xF;
	bl_level[0].para_list[1] = level & 0xFF;

	push_table(bl_level, sizeof(bl_level) /
		sizeof(struct LCM_setting_table), 1);
}

static unsigned int lcm_compare_id(void)
{
	unsigned int id = 0;
	unsigned char buffer[1];
	unsigned int array[16];

	MDELAY(1000);

	array[0] = 0x00013700;  /* read id return 1byte */
	dsi_set_cmdq(array, 1, 1);

	read_reg_v2(0xDA, buffer, 1);
	id = buffer[0];     /* we only need ID */

	LCM_LOGI("[lk/lcm] %s, id = 0x%08x\n", __func__, id);

	if (id == LCM_ID_HX83102P)
		return 1;
	else
		return 0;

}

LCM_DRIVER hx83102p_wuxga2000_dsi_vdo_boe_lcm_drv = {
	.name = "hx83102p_wuxga2000_dsi_vdo_boe_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params = lcm_get_params,
	.init = lcm_init,
	.init_power = lcm_init_power,
	.compare_id = lcm_compare_id,
	.set_backlight = lcm_setbacklight,
	.ata_check = lcm_ata_check,
	.update = lcm_update,
};
