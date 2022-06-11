#ifndef BUILD_LK
#include <linux/string.h>
#endif
#include "lcm_drv.h"

#ifdef BUILD_LK
#include <platform/upmu_common.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h>
#include <platform/mt_pmic.h>
#include <string.h>

#elif defined(BUILD_UBOOT)
#include <asm/arch/mt_gpio.h>
#else
#include <linux/regulator/mediatek/mtk_regulator.h>  //modify for kernel-4.4

#endif

#ifdef BUILD_LK
#include <stdio.h>
#include <string.h>

#else
#include <linux/string.h>
#include <linux/kernel.h>
#endif

//#include <linux/gpio.h>
#define _LCM_DEBUG_

//#include <cust_gpio_usage.h>

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#ifdef BUILD_LK
#define LCD_DEBUG(fmt)  dprintf(CRITICAL, fmt)
#else
#define LCD_DEBUG(fmt, args...)  pr_debug("[KERNEL/LCM]"fmt, ##args)
#endif

#define LCM_DSI_CMD_MODE	0

#define GPIO_8912T_RST 				(GPIO29 | 0x80000000)
#define GPIO_8912T_EN_18V 			(GPIO18 | 0x80000000)
//#define GPIO_HDMI_PWREN             (GPIO126 | 0x80000000)

#define GPIO_LCM_MIPI_EN            (GPIO97 | 0x80000000)
#define GPIO_LCM_MIPI_SEL           (GPIO96 | 0x80000000)

//#define GPIO_FUSB301A_VBUS          (GPIO34 | 0x80000000)
#define GPIO_HDMI_HPD_DET         (GPIO98 | 0x80000000)
#define GPIO_USBL_ID_DET          (GPIO94 | 0x80000000)
// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------

static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    								(lcm_util.set_reset_pin((v)))
#define SET_GPIO_OUT(gpio_num,val)    						(lcm_util.set_gpio_out((gpio_num),(val)))


#define UDELAY(n) 											(lcm_util.udelay(n))
#define MDELAY(n) 											(lcm_util.mdelay(n))

#define  MIPI_Lane  4
#ifdef BUILD_LK
enum
{
	H_act = 0,
	V_act,
	H_tol,
	V_tol,
	H_bp,
	H_sync,
	V_sync,
	V_bp
};

/************config fwvga for G109************/
#if 0

#if 1
#define FRAME_WIDTH  										(854)
#define FRAME_HEIGHT 										(480)

#define HSYNC_PULSE_WIDTH           96 
#define HSYNC_BACK_PORCH            48
#define HSYNC_FRONT_PORCH           16
#define VSYNC_PULSE_WIDTH           2
#define VSYNC_BACK_PORCH            33
#define VSYNC_FRONT_PORCH           10

#define MIPI_CLK 99

#else
#define FRAME_WIDTH  										(848)
#define FRAME_HEIGHT 										(480)

#define HSYNC_PULSE_WIDTH       112
#define HSYNC_BACK_PORCH        112
#define HSYNC_FRONT_PORCH       16
#define VSYNC_PULSE_WIDTH       8
#define VSYNC_BACK_PORCH        23
#define VSYNC_FRONT_PORCH       6

#define MIPI_CLK 102
#endif

#else  //1080P
#define FRAME_WIDTH  										(1280)
#define FRAME_HEIGHT 										(720)

#define HSYNC_PULSE_WIDTH           40 
#define HSYNC_BACK_PORCH            220
#define HSYNC_FRONT_PORCH           110
#define VSYNC_PULSE_WIDTH           5
#define VSYNC_BACK_PORCH            20
#define VSYNC_FRONT_PORCH           5

#define MIPI_CLK 223 //445 //101 //153	
#endif
/**********************************************/

static int MIPI_Timing[] =
//  H_act	    V_act	 H_total V_total H_BP	 H_sync  V_sync		V_BP
   // {1280,  	800,	 1450,	 832,	 80,	 10,	 2,  		12};// 1080P  Vesa Timing
	//{1280,  	720,	 1530,	 732,	 80,	 20,	 2,  		8};// 720P  Vesa Timing
	{FRAME_WIDTH,  	FRAME_HEIGHT,	 (FRAME_WIDTH+HSYNC_PULSE_WIDTH+HSYNC_BACK_PORCH+HSYNC_FRONT_PORCH),	 (FRAME_HEIGHT+VSYNC_PULSE_WIDTH+VSYNC_BACK_PORCH+VSYNC_FRONT_PORCH),	 HSYNC_BACK_PORCH,	 HSYNC_PULSE_WIDTH,	 VSYNC_PULSE_WIDTH, VSYNC_BACK_PORCH};// 1080P  Vesa Timing

	//{1024,	600,   1344,     635,    140,    20,	 3,         20}; //add by jiang
	//{1280,  	800,	 1530,	 832,	 80,	 10,	 2,         12};
	
	//  H_act	V_act	 H_total V_total H_BP	 H_sync  V_sync		V_BP                     
 //   {1920,  	1080,	 2200,	 1125,	 148,	 44,	 5,  		36};// 1080P  Vesa Timing

#endif

#ifdef _LCM_DEBUG_
  #ifdef BUILD_LK
  #define LCM_PRINT printf
  #else
  #define LCM_PRINT printk
  #endif
#else
	#define LCM_PRINT
#endif

// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)										lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)					lcm_util.dsi_write_regs(addr, pdata, byte_nums)
#define read_reg											lcm_util.dsi_read_reg()
#define read_reg_v2(cmd, buffer, buffer_size)   			lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)    
 
// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
	LCM_PRINT("%s %d\n", __func__,__LINE__);
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}

static void lcm_get_params(LCM_PARAMS *params)
{
    printf("junTang %s %d\n", __func__,__LINE__);
  
	memset(params, 0, sizeof(LCM_PARAMS));

	params->type   = LCM_TYPE_DSI;

	params->width  = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

	params->dsi.mode   = SYNC_EVENT_VDO_MODE;//SYNC_PULSE_VDO_MODE;//SYNC_EVENT_VDO_MODE;//BURST_VDO_MODE;
	
	// DSI
	/* Command mode setting */
	params->dsi.LANE_NUM				= LCM_FOUR_LANE;
	//The following defined the fomat for data coming from LCD engine.
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

	// Highly depends on LCD driver capability.
	// Not support in MT6573
	params->dsi.packet_size = 256;

	params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;
	
	params->dsi.vertical_sync_active				= VSYNC_PULSE_WIDTH;//10
	params->dsi.vertical_backporch					= VSYNC_BACK_PORCH;//80
	params->dsi.vertical_frontporch 				= VSYNC_FRONT_PORCH;//80
	params->dsi.vertical_active_line				= FRAME_HEIGHT; //1280
	
	params->dsi.horizontal_sync_active				= HSYNC_PULSE_WIDTH;// 2
	params->dsi.horizontal_backporch				= HSYNC_BACK_PORCH;//12
	params->dsi.horizontal_frontporch				= HSYNC_FRONT_PORCH;//18
	params->dsi.horizontal_active_pixel 			= FRAME_WIDTH;//800

	//params->dsi.edp_panel = 1;
    params->dsi.PLL_CLOCK = MIPI_CLK;//223;//250;
	
	params->dsi.cont_clock = 1;
	params->dsi.ssc_disable = 1;
	params->dsi.HS_PRPR = 0x07;
    params->dsi.clk_lp_per_line_enable = 0;
}

#define LT8912B_SLAVE_ADDR_WRITE  	0x90
#define LT8912B_SLAVE_ADDR92_WRITE  0x92
#define LT8912B_SLAVE_ADDR94_WRITE  0x94

#define LT8912B_I2C_ID		I2C6
#define LT8912B_I2C_SPEED	100

static struct mt_i2c_t hdmi_8912b_i2c;

static int hdmi8912b_write_byte(kal_uint8 slave, kal_uint8 addr, kal_uint8 value) 
{
    kal_uint32 ret_code = I2C_OK;
    kal_uint8 write_data[2];
    kal_uint16 len;

    write_data[0]= addr;
    write_data[1] = value;

    hdmi_8912b_i2c.id = LT8912B_I2C_ID;
    hdmi_8912b_i2c.addr = (slave >> 1);
    hdmi_8912b_i2c.mode = HS_MODE;
    hdmi_8912b_i2c.speed = LT8912B_I2C_SPEED;
    len = 2;

    ret_code = i2c_write(&hdmi_8912b_i2c, write_data, len);

    if(I2C_OK != ret_code) {
         printf("*******hdmi 8912 write ret_code: %d **********\n", ret_code);
		 return ret_code;
    }
	printf("zhaolong====%s,%d=========addr:0x%x, value:0x%x\n", __func__, __LINE__, addr, value );
    return ret_code;
}

static int hdmi8912b_read_bytes(kal_uint8 slave, kal_uint8 addr, kal_uint8* value, kal_uint32 size)
{
	kal_uint32 ret = I2C_OK;
	kal_uint16 len;
	kal_uint8 read_byte[12];
	
	read_byte[0] = addr;

	hdmi_8912b_i2c.id = LT8912B_I2C_ID;	/* I2C2; */
	hdmi_8912b_i2c.addr = (slave >> 1);
	hdmi_8912b_i2c.mode = HS_MODE;
	hdmi_8912b_i2c.speed = LT8912B_I2C_SPEED;

	ret = i2c_write_read(&hdmi_8912b_i2c, read_byte, 1, size);
	if (I2C_OK != ret) {
		I2CERR("read 1 bytes fails(%lx).\n", ret);
		I2CLOG("read 1 bytes ,read_byte=%x\n", read_byte[0]);
		ret = -1;
		return ret;
		//continue;
	} else {
		for(len = 0; len < size; len++){
			value[len] = read_byte[len];
		}
		printf("%s:read 1 bytes pass,addr = 0x%x value =0x%x\n",__func__,addr, read_byte[0]);
	}

	printf("###########addr: 0x%x value:0x%x form############## success!\n", addr, read_byte[0]);
	
	return ret;
} 

#if 1
void lt8912b_selftest_initial( void )
{	
	kal_uint8 data[128];
	
	hdmi8912b_read_bytes(LT8912B_SLAVE_ADDR_WRITE, 0x00, data, 2);
	printf("[LT8912B_Initial] *******LT8912B ID: 0x%x 0x%x **********\n", data[0], data[1]);

	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x08 ,0xff);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x09 ,0xff);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x0a ,0xff);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x0b ,0xff);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x0c ,0xff);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x31 ,0xa1);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x32 ,0xa1);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x33 ,0x03);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x37 ,0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x38 ,0x22);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x60 ,0x82);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x39 ,0x45);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x3b ,0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x44 ,0x31);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x55 ,0x44);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x57 ,0x01);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0x5a ,0x02);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE,0xb2 ,0x01); 

	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x72,0x12); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x73,0x04); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x74,0x01); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x75,0x19); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x76,0x00); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x77,0xd0); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x78,0x25); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x79,0x72); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x7a,0xee); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x7b,0x26); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x7c,0x28); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x7d,0x05); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x70,0x80); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x71,0x76); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x4e,0x99); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x4f,0x99); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x50,0x69); 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE,0x51,0x80);
	hdmi8912b_read_bytes(LT8912B_SLAVE_ADDR92_WRITE, 0x51, data, 1);
	printf("[LT8912B_Initial] *******LT8912B 0x51: 0x%x **********\n", data[0] );
}
#endif

static void lt8912b_read_data()
{
	kal_uint8 buf[2];

	hdmi8912b_read_bytes(LT8912B_SLAVE_ADDR_WRITE, 0x00, buf, 2);
	hdmi8912b_read_bytes(LT8912B_SLAVE_ADDR_WRITE, 0x9C, buf, 1);
	printf("[LT8912B_Initial] *******LT8912B 0x9C: 0x%x **********\n", buf[0] );
	hdmi8912b_read_bytes(LT8912B_SLAVE_ADDR_WRITE, 0x9D, buf, 1);
	printf("[LT8912B_Initial] *******LT8912B 0x9D: 0x%x **********\n", buf[0] );
	hdmi8912b_read_bytes(LT8912B_SLAVE_ADDR_WRITE, 0x9E, buf, 1);
	printf("[LT8912B_Initial] *******LT8912B 0x9E: 0x%x **********\n", buf[0] );
	hdmi8912b_read_bytes(LT8912B_SLAVE_ADDR_WRITE, 0x9F, buf, 1);
	printf("[LT8912B_Initial] *******LT8912B 0x9F: 0x%x **********\n", buf[0] );
}

static void	lt8912b_initial()
{
    printf("zhaolong=====[%s]:%d****************\n", __func__, __LINE__);
	// i2c address i2cID = 0x90
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x08, 0xff);// Register address : 0x08; 	Value : 0xff
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x09, 0x81);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x0a, 0xff);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x0b, 0x64);//
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x0c, 0xff);

	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x44, 0x31);// Close LVDS ouput
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x51, 0x1f);

	// i2c address i2cID = 0x90
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x31, 0xa1);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x32, 0xa1);//0xa1
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x33, 0x03);//0x03   // 0x03 Open HDMI Tx£» 0x00 Close HDMI Tx
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x37, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x38, 0x22);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x60, 0x82);

	// i2c address i2cID = 0x90
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x39, 0x45);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x3b, 0x00);

	// i2c address i2cID = 0x90
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x44, 0x31);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x55, 0x44);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x57, 0x01);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x5a, 0x02);

	// i2c address i2cID = 0x92
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x10, 0x01); // 0x05 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x11, 0x01); // 0x12 
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x12, 0x04);  
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x13, MIPI_Lane%0x04);  // 00 4 lane  // 01 lane // 02 2 lane //03 3 lane
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x14, 0x00);  
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x15, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x1a, 0x03);  
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x1b, 0x03);  

	// i2c address i2cID = 0x92
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x18, (u8)(MIPI_Timing[H_sync]%256)); // hwidth
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x19, (u8)(MIPI_Timing[V_sync]%256)); // vwidth
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x1c, (u8)(MIPI_Timing[H_act]%256)); // H_active[7:0]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x1d, (u8)(MIPI_Timing[H_act]/256)); // H_active[15:8]

	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x1e, 0x67); // hs/vs/de pol hdmi sel pll sel
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x2f, 0x0c); // fifo_buff_length 12

	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x34, (u8)(MIPI_Timing[H_tol]%256)); // H_total[7:0]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x35, (u8)(MIPI_Timing[H_tol]/256)); // H_total[15:8]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x36, (u8)(MIPI_Timing[V_tol]%256)); // V_total[7:0]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x37, (u8)(MIPI_Timing[V_tol]/256)); // V_total[15:8]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x38, (u8)(MIPI_Timing[V_bp]%256)); // VBP[7:0]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x39, (u8)(MIPI_Timing[V_bp]/256)); // VBP[15:8]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x3a, (u8)((MIPI_Timing[V_tol]-MIPI_Timing[V_act]-MIPI_Timing[V_bp]-MIPI_Timing[V_sync])%256)); // VFP[7:0]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x3b, (u8)((MIPI_Timing[V_tol]-MIPI_Timing[V_act]-MIPI_Timing[V_bp]-MIPI_Timing[V_sync])/256)); // VFP[15:8]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x3c, (u8)(MIPI_Timing[H_bp]%256)); // HBP[7:0]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x3d, (u8)(MIPI_Timing[H_bp]/256)); // HBP[15:8]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x3e, (u8)((MIPI_Timing[H_tol]-MIPI_Timing[H_act]-MIPI_Timing[H_bp]-MIPI_Timing[H_sync])%256)); // HFP[7:0]
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x3f, (u8)((MIPI_Timing[H_tol]-MIPI_Timing[H_act]-MIPI_Timing[H_bp]-MIPI_Timing[H_sync])/256)); // HFP[15:8]

	// i2c address i2cID = 0x92
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x4e, 0x52);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x4f, 0xde);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x50, 0xc0);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x51, 0x80);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x51, 0x00);

	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x1f, 0x5e);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x20, 0x01);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x21, 0x2c);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x22, 0x01);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x23, 0xfa);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x24, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x25, 0xc8);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x26, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x27, 0x5e);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x28, 0x01);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x29, 0x2c);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x2a, 0x01);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x2b, 0xfa);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x2c, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x2d, 0xc8);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x2e, 0x00);

	// i2c address i2cID = 0x90
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x03, 0x7f);
	mdelay(10);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x03, 0xff);

	// i2c address i2cID = 0x92
	//	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x51, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x42, 0x64);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x43, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x44, 0x04);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x45, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x46, 0x59);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x47, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x48, 0xf2);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x49, 0x06);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x4a, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x4b, 0x72);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x4c, 0x45);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x4d, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x52, 0x08);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x53, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x54, 0xb2);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x55, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x56, 0xe4);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x57, 0x0d);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x58, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x59, 0xe4);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x5a, 0x8a);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x5b, 0x00);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x5c, 0x34);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x1e, 0x4f);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x51, 0x00);

	// i2c address i2cID = 0x90
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0xB2, 0x01);
	// i2c address i2cID = 0x94
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x06, 0x08);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x07, 0xF0);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x34, 0xD2);

	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x3c, 0x41);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x3e, 0x0a);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x43, 0x46);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x44, 0x10);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x45, 0x2A); //0x19:4:3 ; 0x2A : 16:9
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR94_WRITE, 0x47, 0x00);
    
	// i2c address i2cID = 0x90
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x03, 0x7f);
	mdelay(10);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR_WRITE, 0x03, 0xff);
	hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x51, 0x80);
	MDELAY(10);
    hdmi8912b_write_byte(LT8912B_SLAVE_ADDR92_WRITE, 0x51, 0x00);
}

static void lcm_init(void)
{
	printf(" %s %d\n", __func__,__LINE__);
	
	//mt_set_gpio_mode(GPIO_FUSB301A_VBUS, GPIO_MODE_00);
	//mt_set_gpio_dir(GPIO_FUSB301A_VBUS, GPIO_DIR_OUT);
	//mt_set_gpio_out(GPIO_FUSB301A_VBUS, GPIO_OUT_ONE);
	
    //mt_set_gpio_mode(GPIO_HDMI_PWREN, GPIO_MODE_00);
	//mt_set_gpio_dir(GPIO_HDMI_PWREN, GPIO_DIR_OUT);
	//mt_set_gpio_out(GPIO_HDMI_PWREN, GPIO_OUT_ONE);
    
	//8912T
	mt_set_gpio_mode(GPIO_8912T_EN_18V, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_8912T_EN_18V, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_8912T_EN_18V, GPIO_OUT_ONE);

	mt_set_gpio_mode(GPIO_8912T_RST, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_8912T_RST, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_8912T_RST, GPIO_OUT_ONE);

	MDELAY(50);

	//8912T
	mt_set_gpio_out(GPIO_8912T_RST, GPIO_OUT_ZERO);
	
	MDELAY(50);
	mt_set_gpio_out(GPIO_8912T_RST, GPIO_OUT_ONE);
	
	MDELAY(100);

	//lt8912b_selftest_initial();
	lt8912b_initial();
    
    lt8912b_read_data();
}

static void lcm_suspend(void)
{	
	mt_set_gpio_out(GPIO_8912T_RST, GPIO_OUT_ZERO);
	mt_set_gpio_out(GPIO_8912T_EN_18V, GPIO_OUT_ZERO);
    //mt_set_gpio_out(GPIO_HDMI_PWREN, GPIO_OUT_ZERO);
	MDELAY(10);
}

static unsigned int lcm_compare_id(void)
{
	unsigned int usbl_id_det = 0;
	unsigned int hdmi_hpd_state = 0;
	
	usbl_id_det = mt_get_gpio_in(GPIO_USBL_ID_DET);
	
	MDELAY(10);
	
	mt_set_gpio_mode(GPIO_8912T_EN_18V, GPIO_MODE_00);
	mt_set_gpio_dir(GPIO_8912T_EN_18V, GPIO_DIR_OUT);
	mt_set_gpio_out(GPIO_8912T_EN_18V, GPIO_OUT_ONE);
	
	MDELAY(50);
	
	hdmi_hpd_state = mt_get_gpio_in(GPIO_HDMI_HPD_DET);
	printf("lt8912b hdmi hpd id hdmi_hpd_state = %d, usbl_id_det = %d\n", hdmi_hpd_state, usbl_id_det);
	
	mt_set_gpio_out(GPIO_8912T_EN_18V, GPIO_OUT_ZERO);
	
	if (hdmi_hpd_state == 1){
		//LCM MIPI SETTING
		mt_set_gpio_mode(GPIO_LCM_MIPI_EN, GPIO_MODE_00);
		mt_set_gpio_dir(GPIO_LCM_MIPI_EN, GPIO_DIR_OUT);
		mt_set_gpio_out(GPIO_LCM_MIPI_EN, GPIO_OUT_ZERO);
		mt_set_gpio_mode(GPIO_LCM_MIPI_SEL, GPIO_MODE_00);
		mt_set_gpio_dir(GPIO_LCM_MIPI_SEL, GPIO_DIR_OUT);
		mt_set_gpio_out(GPIO_LCM_MIPI_SEL, GPIO_OUT_ONE);
		return 1;
	}
	else {
		return 0;
	}
}


static void lcm_resume(void)
{
	lcm_init();
}
 
LCM_DRIVER aeon_lt8912b_fwvga_dsi_vdo_lcm_drv = {
	.name = "aeon_lt8912b_fwvga_dsi_vdo_drv",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
#if (LCM_DSI_CMD_MODE)
    .update         = lcm_update,
#endif
};
