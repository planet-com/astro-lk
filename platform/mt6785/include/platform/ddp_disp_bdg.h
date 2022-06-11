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

#ifndef _DDP_DISP_BDG_H_
#define _DDP_DISP_BDG_H_
#include "spi_slave.h"
#include "ddp_hal.h"
#include "ddp_info.h"
#include "lcm_drv.h"
#define CONFIG_MTK_BDG_DSC
//#define _VDO_120FPS_
#define _CMD_120FPS_
#ifdef _VDO_120FPS_	 //for vdo mode 120Hz
#define _N36672C_
#define RXTX_RATIO		(230)
#endif
#ifdef _CMD_120FPS_	 //for cmd mode 120Hz
#define _BDG_CMD_MODE_
#define RXTX_RATIO		(300)
#endif
#define HW_NUM			(1)

enum DISP_BDG_ENUM {
	DISP_BDG_DSI0 = 0,
	DISP_BDG_DSI1,
	DISP_BDG_DSIDUAL,
	DISP_BDG_NUM
};

enum MIPI_TX_PAD_VALUE {
	PAD_D2P = 0,
	PAD_D2N,
	PAD_D0P,
	PAD_D0N,
	PAD_CKP,
	PAD_CKN,
	PAD_D1P,
	PAD_D1N,
	PAD_D3P,
	PAD_D3N,
	PAD_MAX_NUM
};

#define	TX_DCS_SHORT_PACKET_ID_0			(0x05)
#define	TX_DCS_SHORT_PACKET_ID_1			(0x15)
#define	TX_DCS_LONG_PACKET_ID				(0x39)
#define	TX_DCS_READ_PACKET_ID				(0x06)
#define	TX_GERNERIC_SHORT_PACKET_ID_1			(0x13)
#define	TX_GERNERIC_SHORT_PACKET_ID_2			(0x23)
#define	TX_GERNERIC_LONG_PACKET_ID			(0x29)
#define	TX_GERNERIC_READ_LONG_PACKET_ID			(0x14)

#define REG_FLAG_ESCAPE_ID				(0x00)
#define REG_FLAG_DELAY_MS_V3				(0xFF)

int bdg_tx_init(enum DISP_BDG_ENUM module,
		   disp_ddp_path_config *config, void *cmdq);
int bdg_tx_deinit(enum DISP_BDG_ENUM module, void *cmdq);
int bdg_common_init(enum DISP_BDG_ENUM module,
			disp_ddp_path_config *config, void *cmdq);
int mipi_dsi_rx_mac_init(enum DISP_BDG_ENUM module,
			disp_ddp_path_config *config, void *cmdq);
void bdg_tx_pull_lcm_reset_pin(void);
void bdg_tx_set_lcm_reset_pin(unsigned int value);
void bdg_tx_pull_6382_reset_pin(void);
void bdg_tx_set_6382_reset_pin(unsigned int value);
void bdg_tx_set_test_pattern(void);
int bdg_tx_set_mode(enum DISP_BDG_ENUM module,
				void *cmdq, unsigned int mode);

int bdg_tx_start(enum DISP_BDG_ENUM module, void *cmdq);
int bdg_tx_stop(enum DISP_BDG_ENUM module, void *cmdq);
int bdg_tx_wait_for_idle(enum DISP_BDG_ENUM module);
int bdg_dsi_dump_reg(enum DISP_BDG_ENUM module, unsigned int level);

unsigned int get_ap_data_rate(void);
unsigned int get_bdg_data_rate(void);
int set_bdg_data_rate(unsigned int data_rate);
unsigned int get_bdg_line_cycle(void);
unsigned int get_dsc_state(void);
int check_stopstate(void *cmdq);
unsigned int get_mt6382_init(void);
unsigned int get_bdg_tx_mode(void);

unsigned int mtk_spi_read(u32 addr);
int mtk_spi_write(u32 addr, unsigned int regval);
int mtk_spi_mask_write(u32 addr, u32 msk, u32 value);

#endif

