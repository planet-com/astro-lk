/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2021. All rights reserved.
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

#pragma once

#include <debug.h>
#include <stdlib.h>
#include <string.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_gpio.h>
#include <platform/sync_write.h>
#include <sys/types.h>
#include <debug.h>

#define MTK_SPI_ROUNDUP_DIV(a, b) (((a) + ((b)-1)) / (b))

/* #define SPI_EARLY_PORTING */
#define BUS_COUNT 8

enum {
	SPI_HZ = 109000000,
	MTK_FIFO_DEPTH = 32,
	MTK_PACKET_SIZE = 1024,
	MTK_TXRX_TIMEOUT_US = 10*1000*1000,
	MTK_ARBITRARY_VALUE = 0xdadadada
};

enum {
	MTK_SPI_IDLE = 0,
	MTK_SPI_PAUSE_IDLE = 1
};

enum {
	MTK_SPI_BUSY_STATUS = 0x01,
	MTK_SPI_PAUSE_FINISH_INT_STATUS = 3
};

/* SPI_CFG0_REG */
enum {
	SPI_CFG0_CS_HOLD_OFFSET = 0,
	SPI_CFG0_CS_SETUP_OFFSET = 16,
};

/*SPI_CFG1_REG*/
enum {
	SPI_CFG1_CS_IDLE_SHIFT = 0,
	SPI_CFG1_PACKET_LOOP_SHIFT = 8,
	SPI_CFG1_PACKET_LENGTH_SHIFT = 16,
	SPI_CFG1_GET_TICK_DLY_SHIFT = 29,

	SPI_CFG1_CS_IDLE_MASK = 0xff << SPI_CFG1_CS_IDLE_SHIFT,
	SPI_CFG1_PACKET_LOOP_MASK = 0xff << SPI_CFG1_PACKET_LOOP_SHIFT,
	SPI_CFG1_PACKET_LENGTH_MASK = 0x3ff << SPI_CFG1_PACKET_LENGTH_SHIFT,
	SPI_CFG1_GET_TICK_DLY_MASK = 0x7 << SPI_CFG1_GET_TICK_DLY_SHIFT,
};

/*SPI_CFG2_REG*/
enum {
	SPI_CFG2_SCK_HIGH_OFFSET = 0,
	SPI_CFG2_SCK_LOW_OFFSET = 16,
};

enum {
	SPI_CMD_ACT_SHIFT = 0,
	SPI_CMD_RESUME_SHIFT = 1,
	SPI_CMD_RST_SHIFT = 2,
	SPI_CMD_PAUSE_EN_SHIFT = 4,
	SPI_CMD_DEASSERT_SHIFT = 5,
	SPI_CMD_SAMPLE_SEL_SHIFT = 6,
	SPI_CMD_CS_POL_SHIFT = 7,
	SPI_CMD_CPHA_SHIFT = 8,
	SPI_CMD_CPOL_SHIFT = 9,
	SPI_CMD_RX_DMA_SHIFT = 10,
	SPI_CMD_TX_DMA_SHIFT = 11,
	SPI_CMD_TXMSBF_SHIFT = 12,
	SPI_CMD_RXMSBF_SHIFT = 13,
	SPI_CMD_RX_ENDIAN_SHIFT = 14,
	SPI_CMD_TX_ENDIAN_SHIFT = 15,
	SPI_CMD_FINISH_IE_SHIFT = 16,
	SPI_CMD_PAUSE_IE_SHIFT = 17,

	SPI_CMD_ACT_EN = 1 << SPI_CMD_ACT_SHIFT,
	SPI_CMD_RESUME_EN = 1 << SPI_CMD_RESUME_SHIFT,
	SPI_CMD_RST_EN = 1 << SPI_CMD_RST_SHIFT,
	SPI_CMD_PAUSE_EN = 1 << SPI_CMD_PAUSE_EN_SHIFT,
	SPI_CMD_DEASSERT_EN = 1 << SPI_CMD_DEASSERT_SHIFT,
	SPI_CMD_CPHA_EN = 1 << SPI_CMD_CPHA_SHIFT,
	SPI_CMD_CPOL_EN = 1 << SPI_CMD_CPOL_SHIFT,
	SPI_CMD_RX_DMA_EN = 1 << SPI_CMD_RX_DMA_SHIFT,
	SPI_CMD_TX_DMA_EN = 1 << SPI_CMD_TX_DMA_SHIFT,
	SPI_CMD_TXMSBF_EN = 1 << SPI_CMD_TXMSBF_SHIFT,
	SPI_CMD_RXMSBF_EN = 1 << SPI_CMD_RXMSBF_SHIFT,
	SPI_CMD_RX_ENDIAN_EN = 1 << SPI_CMD_RX_ENDIAN_SHIFT,
	SPI_CMD_TX_ENDIAN_EN = 1 << SPI_CMD_TX_ENDIAN_SHIFT,
	SPI_CMD_FINISH_IE_EN = 1 << SPI_CMD_FINISH_IE_SHIFT,
	SPI_CMD_PAUSE_IE_EN = 1 << SPI_CMD_PAUSE_IE_SHIFT,
};

/* SPI peripheral register map. */
struct mtk_spi_regs {
	unsigned int spi_cfg0_reg;
	unsigned int spi_cfg1_reg;
	unsigned int spi_tx_src_reg;
	unsigned int spi_rx_dst_reg;
	unsigned int spi_tx_data_reg;
	unsigned int spi_rx_data_reg;
	unsigned int spi_cmd_reg;
	unsigned int spi_status0_reg;
	unsigned int spi_status1_reg;
	unsigned int spi_pad_sel_reg;
	unsigned int spi_cfg2_reg;
	unsigned int spi_tx_src_reg_64;
	unsigned int spi_rx_dst_reg_64;
};

struct mtk_spi_bus {
	struct mtk_spi_regs *reg_addr;
	uint32_t state;
	uint32_t spi_bus_fdt_offset;
	uint32_t pad_select;
};

struct mtk_spi_bus_config {
#define    SPI_CPHA	0x01
#define    SPI_CPOL	0x02
	u32 spi_mode;
	u32 tick_delay;
};

struct spi_transfer {
	void		*tx_buf;
	void		*rx_buf;
	u32		len;
	u32		speed_hz;
	u32		cs_change;
	u32		tick_delay;
};

extern void mdelay(unsigned long usec);
void mtk_spi_init(int bus_num, struct mtk_spi_bus_config *spi_config);
int init_spi_bus_from_dt(const char *compatible,
				struct mtk_spi_bus_config *config);
int spi_sync(int bus_num, struct spi_transfer *transfer);
