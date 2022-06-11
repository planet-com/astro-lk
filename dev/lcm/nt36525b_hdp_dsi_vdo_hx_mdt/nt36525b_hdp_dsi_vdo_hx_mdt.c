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

#define LOG_TAG	"LCM"

#ifdef BUILD_LK
	#include <platform/upmu_common.h>
	#include <platform/upmu_hw.h>
	#include <platform/mt_gpio.h>
	#include <platform/mt_i2c.h>
	#include <platform/mt_pmic.h>
	#include <string.h>
//	#include <platform/gpio_const.h> /*lcm power is provided by i2c*/
#else
	#include <linux/string.h>
	#include <linux/kernel.h>
	#include <linux/module.h>
	#include <linux/fs.h>
	#include <linux/init.h>
	#include <linux/platform_device.h>
//	#include <mt-plat/mtk_gpio_core.h>
//	#include "mt-plat/upmu_common.h"
//	#include "mt-plat/mtk_gpio.h"
	#include "disp_dts_gpio.h"
	#include <linux/i2c.h> /*lcm power is provided by i2c*/
#endif

#include "lcm_drv.h"

// ---------------------------------------------------------------------------
//  Define Print Log Level
// ---------------------------------------------------------------------------
#ifdef BUILD_LK
	#define LCM_LOGI(string, args...)   dprintf(1, "[LK/"LOG_TAG"]"string, ##args)
	#define LCM_LOGD(string, args...)   dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
	#define LCM_LOGE(string, args...)   dprintf(0, "[LK/"LOG_TAG"]"string, ##args)
#else
	#define LCM_LOGI(fmt, args...)      pr_notice("[KERNEL/"LOG_TAG"]"fmt, ##args)
	#define LCM_LOGD(fmt, args...)      pr_debug("[KERNEL/"LOG_TAG"]"fmt, ##args)
	#define LCM_LOGE(fmt, args...)      pr_err("[KERNEL/"LOG_TAG"]"fmt, ##args)
#endif

// ---------------------------------------------------------------------------
//  Extern Constants
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  Extern Functions
// ---------------------------------------------------------------------------
extern int IMM_GetOneChannelValue(int dwChannel, int data[4], int* rawdata); /* ADC function for multiple LCM drivers */
/* LCM id voltage is 0.8V */
#define LCM_ID_MAX_VOLTAGE   950
#define LCM_ID_MIN_VOLTAGE   650
#define AUXADC_LCM_VOLTAGE_CHANNEL     2

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------
#define LCM_DSI_CMD_MODE                0
#define FRAME_WIDTH                     (720)
#define FRAME_HEIGHT                    (1600)
#define PHYSICAL_WIDTH					(67930)
#define PHYSICAL_HEIGHT					(150960)
#define REGFLAG_PORT_SWAP               0xFFFA
#define REGFLAG_DELAY                   0xFFFC
#define REGFLAG_UDELAY                  0xFFFB
#define REGFLAG_END_OF_TABLE            0xFFFD

#ifndef GPIO_LCM_RST
	#define GPIO_LCM_RST                (GPIO70 | 0x80000000)
#endif

#ifndef GPIO_LCD_BIAS_ENP_PIN
	#define GPIO_LCD_BIAS_ENP_PIN       (GPIO69 | 0x80000000)
#endif
#ifndef GPIO_LCD_BIAS_ENN_PIN
	#define GPIO_LCD_BIAS_ENN_PIN       (GPIO17 | 0x80000000)
#endif

// ---------------------------------------------------------------------------
//  LCM power is provided by I2C
// ---------------------------------------------------------------------------
/* Define -------------------------------------------------------------------*/
#define I2C_I2C_LCD_BIAS_CHANNEL 2  //for I2C channel 2
#define DCDC_I2C_BUSNUM  I2C_I2C_LCD_BIAS_CHANNEL//for I2C channel 6
#define DCDC_I2C_ID_NAME "ocp2131"
#define DCDC_I2C_ADDR 0x3E

struct OCP2131_SETTING_TABLE {
	unsigned char cmd;
	unsigned char data;
};

static struct OCP2131_SETTING_TABLE ocp2131_cmd_data[4] = {
	{ 0x00, 0x14 },
	{ 0x01, 0x14 },
	{ 0x03, 0x03 },
	{ 0xff, 0x80 }
};

/* Variable -----------------------------------------------------------------*/
#ifndef BUILD_LK
#if defined(CONFIG_MTK_LEGACY)
static struct i2c_board_info __initdata ocp2131_board_info = {I2C_BOARD_INFO(DCDC_I2C_ID_NAME, DCDC_I2C_ADDR)};
#else
static const struct of_device_id lcm_of_match[] = {
	{.compatible = "mediatek,I2C_LCD_BIAS"},
	{},
};
#endif

struct i2c_client *ocp2131_i2c_client;

/* Functions Prototype --------------------------------------------------------*/
static int ocp2131_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int ocp2131_remove(struct i2c_client *client);

/* Data Structure -------------------------------------------------------------*/
struct ocp2131_dev {
	struct i2c_client *client;
};

static const struct i2c_device_id ocp2131_id[] = {
	{ DCDC_I2C_ID_NAME, 0 },
	{ }
};

/* I2C Driver  ----------------------------------------------------------------*/
static struct i2c_driver ocp2131_iic_driver = {
	.id_table		= ocp2131_id,
	.probe			= ocp2131_probe,
	.remove			= ocp2131_remove,
	.driver			= {
		.owner			= THIS_MODULE,
		.name			= "ocp2131",
#if !defined(CONFIG_MTK_LEGACY)
		.of_match_table	= lcm_of_match,
#endif
	},
};

/* Functions ------------------------------------------------------------------*/
static int ocp2131_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	ocp2131_i2c_client  = client;
	return 0;
}

static int ocp2131_remove(struct i2c_client *client)
{
	ocp2131_i2c_client = NULL;
	i2c_unregister_device(client);
	return 0;
}

static int ocp2131_i2c_write_byte(unsigned char addr, unsigned char value)
{
	int ret = 0;
	struct i2c_client *client = ocp2131_i2c_client;
	char write_data[2]={0};
	if(client == NULL)
	{
		LCM_LOGE("ERROR!! ocp2131_i2c_client is null\n");
		return 0;
	}
	write_data[0]= addr;
	write_data[1] = value;
	ret=i2c_master_send(client, write_data, 2);
	if(ret<0)
		LCM_LOGD("ocp2131 write data fail !!\n");
	return ret ;
}

static int __init ocp2131_iic_init(void)
{
#if defined(CONFIG_MTK_LEGACY)
	i2c_register_board_info(DCDC_I2C_BUSNUM, &ocp2131_board_info, 1);
#endif
	i2c_add_driver(&ocp2131_iic_driver);
	return 0;
}

static void __exit ocp2131_iic_exit(void)
{
	i2c_del_driver(&ocp2131_iic_driver);
}

module_init(ocp2131_iic_init);
module_exit(ocp2131_iic_exit);
MODULE_AUTHOR("Xiaokuan Shi");
MODULE_DESCRIPTION("MTK OCP2131 I2C Driver");
#else
#define OCP2131_SLAVE_ADDR_WRITE  0x7C
static struct mt_i2c_t OCP2131_i2c;
static int ocp2131_i2c_write_byte(kal_uint8 addr, kal_uint8 value)
{
	kal_uint32 ret_code = I2C_OK;
	kal_uint8 write_data[2];
	kal_uint16 len;
	write_data[0]= addr;
	write_data[1] = value;
	OCP2131_i2c.id = I2C_I2C_LCD_BIAS_CHANNEL;// I2C2;
	/* Since i2c will left shift 1 bit, we need to set FAN5405 I2C address to >>1 */
	OCP2131_i2c.addr = (OCP2131_SLAVE_ADDR_WRITE >> 1);
	OCP2131_i2c.mode = ST_MODE;
	OCP2131_i2c.speed = 100;
	len = 2;
	ret_code = i2c_write(&OCP2131_i2c, write_data, len);
	printf("%s: i2c_write: addr:0x%x, value:0x%x ret_code: %d\n", __func__, addr, value, ret_code);
	return ret_code;
}
#endif

// ---------------------------------------------------------------------------
//  Local Variable
// ---------------------------------------------------------------------------
static LCM_UTIL_FUNCS lcm_util;

// ---------------------------------------------------------------------------
//  Local function
// ---------------------------------------------------------------------------
#define MDELAY(n)                       (lcm_util.mdelay(n))
#define UDELAY(n)                       (lcm_util.udelay(n))
#ifdef BUILD_LK
	#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))
#endif

#ifndef BUILD_LK
#define dsi_set_cmdq_V22(cmdq, cmd, count, ppara, force_update) \
		lcm_util.dsi_set_cmdq_V22(cmdq, cmd, count, ppara, force_update)
#endif
#define dsi_set_cmdq_V2(cmd, count, ppara, force_update) \
		lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update) \
		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd) \
		lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums) \
		lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg(cmd) \
		lcm_util.dsi_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size) \
		lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)

struct LCM_setting_table {
	unsigned int cmd;
	unsigned char count;
	unsigned char para_list[120];
};

static struct LCM_setting_table lcm_initialization_setting[] = {
	{0xFF,1, {0x20}},
	{0xFB,1, {0x01}},
	{0x03,1, {0x54}},
	{0x05,1, {0xB1}},
	{0x07,1, {0x6E}},
	{0x08,1, {0xCB}},
	{0x0E,1, {0x87}},
	{0x0F,1, {0x69}},
	{0x69,1, {0xA9}},
	{0x88,1, {0x00}},
	{0x95,1, {0xD7}},
	{0x96,1, {0xD7}},
	{0xFF,1, {0x23}},
	{0xFB,1, {0x01}},
	{0x12,1, {0xB4}},
	{0x15,1, {0xE9}},
	{0x16,1, {0x0B}},
	{0xFF,1, {0x24}},
	{0xFB,1, {0x01}},
	{0x00,1, {0x05}},
	{0x01,1, {0x00}},
	{0x02,1, {0x1F}},
	{0x03,1, {0x1E}},
	{0x04,1, {0x20}},
	{0x05,1, {0x00}},
	{0x06,1, {0x00}},
	{0x07,1, {0x00}},
	{0x08,1, {0x00}},
	{0x09,1, {0x0F}},
	{0x0A,1, {0x0E}},
	{0x0B,1, {0x00}},
	{0x0C,1, {0x00}},
	{0x0D,1, {0x0D}},
	{0x0E,1, {0x0C}},
	{0x0F,1, {0x04}},
	{0x10,1, {0x00}},
	{0x11,1, {0x00}},
	{0x12,1, {0x00}},
	{0x13,1, {0x00}},
	{0x14,1, {0x00}},
	{0x15,1, {0x00}},
	{0x16,1, {0x05}},
	{0x17,1, {0x00}},
	{0x18,1, {0x1F}},
	{0x19,1, {0x1E}},
	{0x1A,1, {0x20}},
	{0x1B,1, {0x00}},
	{0x1C,1, {0x00}},
	{0x1D,1, {0x00}},
	{0x1E,1, {0x00}},
	{0x1F,1, {0x0F}},
	{0x20,1, {0x0E}},
	{0x21,1, {0x00}},
	{0x22,1, {0x00}},
	{0x23,1, {0x0D}},
	{0x24,1, {0x0C}},
	{0x25,1, {0x04}},
	{0x26,1, {0x00}},
	{0x27,1, {0x00}},
	{0x28,1, {0x00}},
	{0x29,1, {0x00}},
	{0x2A,1, {0x00}},
	{0x2B,1, {0x00}},
	{0x2F,1, {0x06}},
	{0x30,1, {0x30}},
	{0x33,1, {0x30}},
	{0x34,1, {0x06}},
	{0x37,1, {0x74}},
	{0x3A,1, {0x98}},
	{0x3B,1, {0xA6}},
	{0x3D,1, {0x52}},
	{0x4D,1, {0x12}},
	{0x4E,1, {0x34}},
	{0x51,1, {0x43}},
	{0x52,1, {0x21}},
	{0x55,1, {0x42}},
	{0x56,1, {0x34}},
	{0x5A,1, {0x98}},
	{0x5B,1, {0xA6}},
	{0x5C,1, {0x00}},
	{0x5D,1, {0x00}},
	{0x5E,1, {0x08}},
	{0x60,1, {0x80}},
	{0x61,1, {0x90}},
	{0x64,1, {0x11}},
	{0x92,1, {0xB3}},
	{0x93,1, {0x0A}},
	{0x94,1, {0x0E}},
	{0xAB,1, {0x00}},
	{0xAD,1, {0x00}},
	{0xB0,1, {0x05}},
	{0xB1,1, {0xAF}},
	{0xFF,1, {0x25}},
	{0xFB,1, {0x01}},
	{0x0A,1, {0x82}},
	{0x0B,1, {0x25}},
	{0x0C,1, {0x01}},
	{0x17,1, {0x82}},
	{0x18,1, {0x06}},
	{0x19,1, {0x0F}},
	{0xFF,1, {0x26}},
	{0xFB,1, {0x01}},
	{0x00,1, {0xA0}},
	{0xFF,1, {0x27}},
	{0xFB,1, {0x01}},
	{0x13,1, {0x00}},
	{0x15,1, {0xB4}},
	{0x1F,1, {0x55}},
	{0x26,1, {0x0F}},
	{0xC0,1, {0x18}},
	{0xC1,1, {0xF2}},
	{0xC2,1, {0x00}},
	{0xC3,1, {0x00}},
	{0xC4,1, {0xF2}},
	{0xC5,1, {0x00}},
	{0xC6,1, {0x00}},
	{0xff,1,{0xD0}},
	{0xFB,1,{0x01}},
	{0x09,1,{0xF0}},
	{0x28,1,{0x70}},
	{0x05,1,{0x07}},

	{0xFF,1,{0x10}},
	{0xFB,1,{0x01}},
	{0xBA,1,{0x02}},

	{0x29, 0, {}},
	{REGFLAG_DELAY, 10, {}},

	{0x11, 0, {}},
	{REGFLAG_DELAY, 140, {}},
};

static struct LCM_setting_table lcm_deep_sleep_mode_in_setting[] = {
	// Display off sequence
	{0x28, 0, {0x00}},
	{REGFLAG_DELAY, 20, {}},
	// Sleep Mode On
	{0x10, 0, {0x00}},
	{REGFLAG_DELAY, 120, {}},
	{REGFLAG_END_OF_TABLE, 0x00, {}},
};

static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
	unsigned int i;
	for(i = 0; i < count; i++) {
		unsigned int cmd;
		cmd = table[i].cmd;
		switch (cmd) {
		case REGFLAG_DELAY :
			MDELAY(table[i].count);
			break;
		case REGFLAG_END_OF_TABLE :
			break;
		default:
			dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
		}
	}
}

// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------
static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type		= LCM_TYPE_DSI;

	params->width		= FRAME_WIDTH;
	params->height		= FRAME_HEIGHT;
	params->lcm_if		= LCM_INTERFACE_DSI0;
	params->lcm_cmd_if	= LCM_INTERFACE_DSI0;
	params->physical_width	= PHYSICAL_WIDTH/1000;
	params->physical_height	= PHYSICAL_HEIGHT/1000;

#if (LCM_DSI_CMD_MODE)
	params->dsi.mode	= CMD_MODE;
#else
	params->dsi.mode	= BURST_VDO_MODE;
#endif

	/* The following defined the fomat for data coming from LCD engine. */
	params->dsi.data_format.color_order	= LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq	= LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding		= LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format		= LCM_DSI_FORMAT_RGB888;

	/* Highly depends on LCD driver capability */
	/* video mode timing */
	params->dsi.PS				        = LCM_PACKED_PS_24BIT_RGB888;
	params->dsi.vertical_sync_active	= 2;
	params->dsi.vertical_backporch		= 234;
	params->dsi.vertical_frontporch		= 36;
	params->dsi.vertical_active_line	= FRAME_HEIGHT;
	params->dsi.horizontal_sync_active	= 4;
	params->dsi.horizontal_backporch	= 94;
	params->dsi.horizontal_frontporch	= 94;
	params->dsi.horizontal_active_pixel	= FRAME_WIDTH;
	params->dsi.LANE_NUM			    = LCM_THREE_LANE;
	params->dsi.PLL_CLOCK			    = 434; //this value must be in MTK suggested table

	params->dsi.ssc_disable                         = 1;
	params->dsi.ssc_range                           = 4;

	params->dsi.HS_TRAIL                            = 15;

	/* ESD check function */
	params->dsi.esd_check_enable					= 1;
	params->dsi.customization_esd_check_enable		= 1;
	params->dsi.clk_lp_per_line_enable				= 0;
	params->dsi.lcm_esd_check_table[0].cmd			= 0x0A;
	params->dsi.lcm_esd_check_table[0].count		= 1;
	params->dsi.lcm_esd_check_table[0].para_list[0]	= 0x9C;
}

static void lcm_init_power(void)
{
#ifdef BUILD_LK
	mt_set_gpio_mode(GPIO_LCD_BIAS_ENP_PIN, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_LCD_BIAS_ENP_PIN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCD_BIAS_ENP_PIN, GPIO_OUT_ONE);
	MDELAY(5);
	mt_set_gpio_mode(GPIO_LCD_BIAS_ENN_PIN, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_LCD_BIAS_ENN_PIN, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_LCD_BIAS_ENN_PIN, GPIO_OUT_ONE);
#else
	disp_dts_gpio_select_state(DTS_GPIO_STATE_LCD_BIAS_ENP1);
	MDELAY(5);
	disp_dts_gpio_select_state(DTS_GPIO_STATE_LCD_BIAS_ENN1);
#endif
	ocp2131_i2c_write_byte(ocp2131_cmd_data[0].cmd, ocp2131_cmd_data[0].data);
	MDELAY(1);
	ocp2131_i2c_write_byte(ocp2131_cmd_data[1].cmd, ocp2131_cmd_data[1].data);
	MDELAY(1);
	ocp2131_i2c_write_byte(ocp2131_cmd_data[2].cmd, ocp2131_cmd_data[2].data);
	MDELAY(1);
	ocp2131_i2c_write_byte(ocp2131_cmd_data[3].cmd, ocp2131_cmd_data[3].data);
	MDELAY(15);
}

static void lcm_init(void)
{
#ifdef BUILD_LK
	SET_RESET_PIN(1);
	MDELAY(10);
	SET_RESET_PIN(0);
	MDELAY(10);
	SET_RESET_PIN(1);
#else
	disp_dts_gpio_select_state(DTS_GPIO_STATE_LCM_RST_OUT1);
	MDELAY(10);
	disp_dts_gpio_select_state(DTS_GPIO_STATE_LCM_RST_OUT0);
	MDELAY(10);
	disp_dts_gpio_select_state(DTS_GPIO_STATE_LCM_RST_OUT1);
#endif
	MDELAY(15); //spec show need at least 10ms delay for lcm initial reload

	/* when phone initial , config output high, enable backlight drv chip */
	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_suspend(void)
{
	push_table(lcm_deep_sleep_mode_in_setting, sizeof(lcm_deep_sleep_mode_in_setting) / sizeof(struct LCM_setting_table), 1);
}

static void lcm_resume(void)
{
#ifndef BUILD_LK
	disp_dts_gpio_select_state(DTS_GPIO_STATE_LCM_RST_OUT1);
	MDELAY(10);
	disp_dts_gpio_select_state(DTS_GPIO_STATE_LCM_RST_OUT0);
	MDELAY(10);
	disp_dts_gpio_select_state(DTS_GPIO_STATE_LCM_RST_OUT1);
	MDELAY(15);
	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);
#endif
}

static unsigned int lcm_compare_id(void)
{
	int data[4] = {0,0,0,0};
	int res = 0;
	int rawdata = 0;
	int lcm_vol = 0;
#ifdef AUXADC_LCM_VOLTAGE_CHANNEL
	res = IMM_GetOneChannelValue(AUXADC_LCM_VOLTAGE_CHANNEL,data,&rawdata);
	if(res < 0) {
		LCM_LOGI("(%s) nt36525b_hdp_dsi_vdo_hx_mdt lcm chip id vol fail\n", __func__);
		return 0;
	}
#endif
	lcm_vol = data[0]*1000+data[1]*10;
	LCM_LOGI("(%s) nt36525b_hdp_dsi_vdo_hx_mdt lcm chip id adc raw data:%d, lcm_vol:%d\n", __func__, rawdata, lcm_vol);
	if((lcm_vol <= LCM_ID_MAX_VOLTAGE) && (lcm_vol > LCM_ID_MIN_VOLTAGE)) {
		return 1;
	} else {
		return 0;
	}
}

LCM_DRIVER nt36525b_hdp_dsi_vdo_hx_mdt_lcm_drv =
{
	.name			= "nt36525b_hdp_dsi_vdo_hx_mdt",
	.set_util_funcs	= lcm_set_util_funcs,
	.get_params	= lcm_get_params,
	.init		= lcm_init,
	.suspend	= lcm_suspend,
	.resume		= lcm_resume,
	.compare_id	= lcm_compare_id,
	.init_power	= lcm_init_power,
#ifndef BUILD_LK
	.resume_power	= lcm_resume_power,
	.suspend_power	= lcm_suspend_power,
#endif
};
