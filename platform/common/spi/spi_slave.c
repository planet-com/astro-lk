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

#include "spi.h"
#include "spi_slave.h"
#include <platform/mt_gpio.h>
#include <malloc.h>
#include <bits.h>
#include <libfdt.h>
#include <lk_builtin_dtb.h>
#include <kernel/mutex.h>
/*
 * SPI command description.
 */
#define CMD_PWOFF			0x02 /* Power Off */
#define CMD_PWON			0x04 /* Power On */
#define CMD_RS				0x06 /* Read Status */
#define CMD_WS				0x08 /* Write Status */
#define CMD_CR				0x0a /* Config Read */
#define CMD_CW				0x0c /* Config Write */
#define CMD_RD				0x81 /* Read Data */
#define CMD_WD				0x0e /* Write Data */
#define CMD_CT				0x10 /* Config Type */
/*
 * SPI slave status register (to master).
 */
#define SLV_ON				BIT(0)
#define SR_CFG_SUCCESS			BIT(1)
#define SR_TXRX_FIFO_RDY		BIT(2)
#define SR_RD_ERR			BIT(3)
#define SR_WR_ERR			BIT(4)
#define SR_RDWR_FINISH			BIT(5)
#define SR_TIMEOUT_ERR			BIT(6)
#define SR_CMD_ERR			BIT(7)
#define CONFIG_READY  ((SR_CFG_SUCCESS | SR_TXRX_FIFO_RDY))
/*
 * hardware limit for once transfter.
 */
#define MTK_SPI_BUFSIZ                  32
#define MAX_SPI_XFER_SIZE_ONCE		(64 * 1024 - 1)
#define MAX_SPI_TRY_CNT			(5)

#define SPI_READ		     true
#define SPI_WRITE		     false
#define SPI_READ_STA_ERR_RET	(1)

/*
 * spi slave config
 */
#define IOCFG_BASE_ADDR       0x00005000
#define DRV_CFG0              (IOCFG_BASE_ADDR + 0x0)
#define SPIS_SLVO_MASK        (0x7 << 21)
#define SPISLV_BASE_ADDR      0x00002000
#define SPISLV_CTRL           (SPISLV_BASE_ADDR + 0x0)
#define EARLY_TRANS_MASK      (0x1 << 16)

static int spi_bus_num;

/* specific SPI data */
struct mtk_spi_slave_data {
	u32 tx_speed_hz;
	u32 rx_speed_hz;
	u8 slave_drive_strength;
	u8 high_speed_tick_delay;
	u8 low_speed_tick_delay;
	u8 high_speed_early_trans;
	u8 low_speed_early_trans;
	/* mutex for SPI Slave IO */
	struct mutex spislv_mutex;
};

static struct mtk_spi_slave_data slv_data = {
	.tx_speed_hz = SPI_TX_LOW_SPEED_HZ,
	.rx_speed_hz = SPI_RX_LOW_SPEED_HZ,
	.slave_drive_strength = 0,
	.high_speed_tick_delay = 0,
	.low_speed_tick_delay = 0,
	.high_speed_early_trans = 0,
	.low_speed_early_trans = 0,
};

struct mtk_spi_bus_config spislv_chip_info = {
	.spi_mode = 0,
	.tick_delay = 0,
};

static u8 cmd_trans_type_4byte_single[2] = {CMD_CT, 0x04};
static u8 tx_cmd_read_sta[2] = {CMD_RS, 0x00};
static u8 rx_cmd_read_sta[2] = {0x00, 0x00};
static struct spi_transfer CT_TRANSFER = {0};
static struct spi_transfer RS_TRANSFER = {0};

static int spislv_sync_sub(u32 addr, void *val, u32 len, bool is_read)
{
	int ret = 0, i = 0;
	struct spi_transfer x[3];/* CW/CR, WD/RD, WS */
	void *local_buf = NULL;
	u8 mtk_spi_buffer[MTK_SPI_BUFSIZ];
	u8 cmd_write_sta[2] = {CMD_WS, 0xff};
	u8 status = 0;
	u32 retry = 0;
	u8 cmd_config[9] = {0};

	memset(x, 0, sizeof(x));
	/* CR or CW */
	if (is_read)
		cmd_config[0] = CMD_CR;
	else
		cmd_config[0] = CMD_CW;

	for (i = 0; i < 4; i++) {
		cmd_config[1 + i] = (addr & (0xff << (i * 8))) >> (i * 8);
		cmd_config[5 + i] = ((len - 1) & (0xff << (i * 8))) >> (i * 8);
	}

	x[0].tx_buf	= cmd_config;
	x[0].len	= ARRAY_SIZE(cmd_config);
	x[0].speed_hz	= slv_data.tx_speed_hz;
	x[0].cs_change = 1;
	x[0].tick_delay = spislv_chip_info.tick_delay;
	ret = spi_sync(spi_bus_num, x);
	if (ret)
		goto tail;

	/* RS */
	rx_cmd_read_sta[1] = 0;
	RS_TRANSFER.tick_delay = spislv_chip_info.tick_delay;
	ret = spi_sync(spi_bus_num, &RS_TRANSFER);
	if (ret)
		goto tail;

	status = rx_cmd_read_sta[1];
	/* ignore status for set early transfer bit */
	if (addr == SPISLV_CTRL && !is_read)
			status = 0x6;
	if ((status & CONFIG_READY) != CONFIG_READY) {
		dprintf(CRITICAL, "SPI config %s but status error: 0x%x, latched by %dHZ, err addr: 0x%x\n",
				is_read ? "read" : "write", status, slv_data.rx_speed_hz, addr);
		ret = SPI_READ_STA_ERR_RET;
		goto tail;
	}

	/* RD or WD */
	if (len > MTK_SPI_BUFSIZ - 1) {
		local_buf = malloc(len + 1);
		if (!local_buf) {
			dprintf(CRITICAL, "[spislv]local buf malloc fail\n");
			goto tail;
		}
	} else {
		local_buf = mtk_spi_buffer;
		memset(local_buf, 0, MTK_SPI_BUFSIZ);
	}

	if (is_read) {
		*((u8 *)local_buf) = CMD_RD;
		x[1].tx_buf = local_buf;
		x[1].rx_buf = local_buf;
		x[1].speed_hz = slv_data.rx_speed_hz;
	} else {
		*((u8 *)local_buf) = CMD_WD;
		memcpy((u8 *)local_buf + 1, val, len);
		x[1].tx_buf = local_buf;
		x[1].speed_hz = slv_data.tx_speed_hz;
	}
	x[1].len = len + 1;
	x[1].cs_change = 1;
	x[1].tick_delay = spislv_chip_info.tick_delay;
	ret = spi_sync(spi_bus_num, x+1);
	if (ret)
		goto tail;

	/* RS */
	rx_cmd_read_sta[1] = 0;
	RS_TRANSFER.tick_delay = spislv_chip_info.tick_delay;
	ret = spi_sync(spi_bus_num, &RS_TRANSFER);
	if (ret)
		goto tail;

	status = rx_cmd_read_sta[1];
	/* ignore status for set early transfer bit */
	if (addr == SPISLV_CTRL && !is_read)
		status = 0x26;

	if (((status & SR_RD_ERR) == SR_RD_ERR) ||
		((status & SR_WR_ERR) == SR_WR_ERR) ||
		((status & SR_TIMEOUT_ERR) == SR_TIMEOUT_ERR)) {
		dprintf(CRITICAL, "SPI %s error, status: 0x%x, latched by %dHZ, err addr: 0x%x\n",
				is_read ? "read" : "write", status, slv_data.rx_speed_hz, addr);
		/* WS */
		x[2].tx_buf	= cmd_write_sta;
		x[2].len	= ARRAY_SIZE(cmd_write_sta);
		x[2].speed_hz	= slv_data.tx_speed_hz;
		x[2].cs_change  = 1;
		x[2].tick_delay = spislv_chip_info.tick_delay;
		ret = spi_sync(spi_bus_num, x+2);
		if (ret)
			goto tail;

		ret = SPI_READ_STA_ERR_RET;
	} else {
		while (((status & SR_RDWR_FINISH) != SR_RDWR_FINISH)) {
			dprintf(CRITICAL, "SPI %s not finish, status: 0x%x, latched by %dHZ, err addr: 0x%x, polling: %d\n",
				is_read ? "read" : "write",
				status, slv_data.rx_speed_hz, addr, retry);
			if (retry++ >= MAX_SPI_TRY_CNT) {
				ret = SPI_READ_STA_ERR_RET;
				goto tail;
			}
			mdelay(1);

			/* RS */
			rx_cmd_read_sta[1] = 0;
			RS_TRANSFER.tick_delay = spislv_chip_info.tick_delay;
			ret = spi_sync(spi_bus_num, &RS_TRANSFER);
			if (ret)
				goto tail;
			status = rx_cmd_read_sta[1];
		}
	}

tail:
	/* Only for successful read */
	if (is_read && !ret)
		memcpy(val, ((u8 *)x[1].rx_buf + 1), len);

	if (local_buf != mtk_spi_buffer)
		free(local_buf);
	return ret;
}

static int spislv_sync(u32 addr, void *val, u32 len, bool is_read)
{
	int ret = 0;
	u32 addr_local = addr;
	void *val_local = val;
	u32 len_local = len;
	u32 try = 0;

	mutex_acquire(&slv_data.spislv_mutex);
	if (len_local < MAX_SPI_XFER_SIZE_ONCE)
		goto transfer_drect;

	while (len_local > MAX_SPI_XFER_SIZE_ONCE) {
		ret = spislv_sync_sub(addr_local, val_local, MAX_SPI_XFER_SIZE_ONCE, is_read);
		while (ret) {
			dprintf(CRITICAL, "spi slave error, addr: 0x%x, ret(%d), retry: %d\n",
					addr_local, ret, try);
			if (try++ == MAX_SPI_TRY_CNT)
				goto tail;
			ret = spislv_sync_sub(addr_local, val_local,
					MAX_SPI_XFER_SIZE_ONCE, is_read);
		}
		addr_local = addr_local + MAX_SPI_XFER_SIZE_ONCE;
		val_local = (u8 *)val_local + MAX_SPI_XFER_SIZE_ONCE;
		len_local = len_local - MAX_SPI_XFER_SIZE_ONCE;
	}
transfer_drect:
	try = 0;
	ret = spislv_sync_sub(addr_local, val_local, len_local, is_read);
	while (ret) {
		dprintf(CRITICAL, "spi slave error, addr: 0x%x, ret(%d), retry: %d\n",
				addr_local, ret, try);
		if (try++ == MAX_SPI_TRY_CNT)
			goto tail;
		ret = spislv_sync_sub(addr_local, val_local, len_local, is_read);
	}
tail:
	mutex_release(&slv_data.spislv_mutex);
	return ret;
}

static u8 tick_window_early_0[8];
static u8 tick_window_early_0_len;
static u8 tick_window_early_1[8];
static u8 tick_window_early_1_len;
static u8 spislv_select_tick_delay(u8 *tick_delay_window, u8 win_len)
{
	u8 index = 0,  win_start = 0, tick_delay = 0;

	for (index = 0; index < 8; index ++) {
		if (tick_delay_window[index] == 1) {
			win_start = index;
			break;
		}
	}

	if (win_len % 2)
		tick_delay = win_start + (win_len-1)/2;
	else
		tick_delay = win_start + win_len/2;

	if (tick_delay_window[tick_delay] == 1)
		return tick_delay;
	else
		return win_start;
}

static u32 spislv_test(u32 tx_speed_hz, u32 rx_speed_hz, u32 tick_delay)
{
	int i, ret = 0;
	u32 addr = 0x00002000;
	u32 len = 4;
	u8 cmd_config[] = {
		CMD_CR, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};
	u8 tx_cmd_read_sta[2] = {CMD_RS, 0x00};
	u8 rx_cmd_read_sta[2] = {0};
	u8 read_status;
	struct spi_transfer x[2];

	memset(x, 0, sizeof(x));
	for (i = 0; i < 4; i++) {
		cmd_config[1 + i] = (addr & (0xff << (i * 8))) >> (i * 8);
		cmd_config[5 + i] = ((len - 1) & (0xff << (i * 8))) >> (i * 8);
	}
	x[0].tx_buf	= cmd_config;
	x[0].len	= ARRAY_SIZE(cmd_config);
	x[0].speed_hz	= tx_speed_hz;
	x[0].cs_change = 1;
	x[0].tick_delay = tick_delay;
	ret = spi_sync(spi_bus_num, x);
	if (ret)
		goto tail;

	x[1].tx_buf	= tx_cmd_read_sta;
	x[1].rx_buf	= rx_cmd_read_sta;
	x[1].len	= ARRAY_SIZE(tx_cmd_read_sta);
	x[1].speed_hz	= rx_speed_hz;
	x[1].cs_change = 1;
	x[1].tick_delay = tick_delay;
	ret = spi_sync(spi_bus_num, x+1);
	if (ret)
		goto tail;
	read_status = rx_cmd_read_sta[1];
	if ((read_status & CONFIG_READY) != CONFIG_READY)
		return 0;
	else
		return 1;
tail:
	if (ret)
		dprintf(CRITICAL, "error: spi sync err: %d\n", ret);

	return 0;
}

static void spislv_autok(u32 tx_speed_hz, u32 rx_speed_hz)
{
	u32 index;
	u8 early_trans, tick_delay;

	tick_window_early_0_len = 0;
	tick_window_early_1_len = 0;

	dprintf(CRITICAL, "[spislv] write: %dHz, read: %dHz, autok window:\n",
			tx_speed_hz, rx_speed_hz);
	/* set early_trans: 0 */
	spislv_write_register(SPISLV_CTRL,
			(0x40 & (~(EARLY_TRANS_MASK))) | ((0 << 16) & (EARLY_TRANS_MASK)));

	/* scan window */
	for (index = 0; index < 8; index ++) {
		if (spislv_test(tx_speed_hz, rx_speed_hz, index)) {
			tick_window_early_0[index] = 1;
			tick_window_early_0_len ++;
		} else
			tick_window_early_0[index] = 0;
	}
	for (index = 0; index < 8; index ++) {
		dprintf(CRITICAL, "[spislv] autok: early_trans: 0, tick_delay: %d, window: %s\n",
				index, tick_window_early_0[index] == 1 ? "O" : "X");
	}
	/* set early_trans: 1 */
	spislv_write_register(SPISLV_CTRL,
			(0x40 & (~(EARLY_TRANS_MASK))) | ((1 << 16) & (EARLY_TRANS_MASK)));

	/* scan window */
	for (index = 0; index < 8; index ++) {
		if (spislv_test(SPI_TX_LOW_SPEED_HZ, SPI_RX_LOW_SPEED_HZ, index)) {
			tick_window_early_1[index] = 1;
			tick_window_early_1_len++;
		} else
			tick_window_early_1[index] = 0;
	}
	for (index = 0; index < 8; index ++) {
		dprintf(CRITICAL, "[spislv] autok: early_trans: 1, tick_delay: %d, window: %s\n",
			index, tick_window_early_1[index] == 1 ? "O" : "X");
	}

	if (tick_window_early_0_len > tick_window_early_1_len) {
		early_trans = 0;
		tick_delay = spislv_select_tick_delay
			(tick_window_early_0, tick_window_early_0_len);
	} else {
		early_trans = 1;
		tick_delay = spislv_select_tick_delay
			(tick_window_early_1, tick_window_early_1_len);
	}
	if (rx_speed_hz >= SPI_RX_MAX_SPEED_HZ) {
		slv_data.high_speed_early_trans = early_trans;
		slv_data.high_speed_tick_delay = tick_delay;
		dprintf(CRITICAL, "[spislv] autok result:  high_speed_early_trans: %d, high_speed_tick_delay: %d\n",
			slv_data.high_speed_early_trans, slv_data.high_speed_tick_delay);
	} else {
		slv_data.low_speed_early_trans = early_trans;
		slv_data.low_speed_tick_delay = tick_delay;
		dprintf(CRITICAL, "[spislv] autok  low_speed_early_trans: %d, low_speed_tick_delay: %d\n",
			slv_data.low_speed_early_trans, slv_data.low_speed_tick_delay);
	}
}

static void spislv_fdt_getprop_u32_array(void *lk_drv_fdt, int nodeoffset,
				const char *name, unsigned int *out_value)
{
	int i;
	u32 *data = NULL;
	int len = 0;

	data = (unsigned int *)fdt_getprop(lk_drv_fdt, nodeoffset, name, &len);
	if (len > 0 && data) {
		len = len / sizeof(unsigned int);
		for (i = 0; i < len; i++)
			*(out_value+i) = fdt32_to_cpu(*(data+i));
	} else
		*out_value = 0;
}

int spislv_write_param_to_dt(void *fdt)
{
	int node = 0;
	int ret = 0;
	void *kernel_fdt = fdt;
	if (kernel_fdt == NULL)
		panic("kernel_fdt fdt is NULL!\n");
	node = fdt_node_offset_by_compatible(kernel_fdt, -1, "mediatek,spi_slave");
	if (node <= 0) {
		dprintf(CRITICAL, "[spislv] spi slave dts node is not set, just skip.\n");
		return 0;
	}
	ret = fdt_setprop(kernel_fdt, node, "high-speed-tick-delay", &slv_data.high_speed_tick_delay, 1);
	if (ret) {
		dprintf(CRITICAL, "[spislv] spislv_write_param_to_dt err\n");
		return ret;
	}
	ret = fdt_setprop(kernel_fdt, node, "high-speed-early-trans", &slv_data.high_speed_early_trans, 1);
	if (ret) {
		dprintf(CRITICAL, "[spislv] spislv_write_param_to_dt err\n");
		return ret;
	}
	ret = fdt_setprop(kernel_fdt, node, "low-speed-tick-delay", &slv_data.low_speed_tick_delay, 1);
	if (ret) {
		dprintf(CRITICAL, "[spislv] spislv_write_param_to_dt err\n");
		return ret;
	}
	ret = fdt_setprop(kernel_fdt, node, "low-speed-early-trans", &slv_data.low_speed_early_trans, 1);
	if (ret) {
		dprintf(CRITICAL, "[spislv] spislv_write_param_to_dt err\n");
		return ret;
	}

	return ret;
}

int spislv_write(u32 addr, void *val, u32 len)
{
	return spislv_sync(addr, val, len, 0);
}
int spislv_read(u32 addr, void *val, u32 len)
{
	return spislv_sync(addr, val, len, 1);
}

int spislv_read_register(u32 addr, u32 *val)
{
	return spislv_read(addr, (u8 *)val, 4);
}

int spislv_write_register(u32 addr, u32 val)
{
	return spislv_write(addr, (u8 *)&val, 4);
}

int spislv_write_register_mask(u32 addr, u32 val, u32 msk)
{
	u32 ret = 0;
	u32 read_val;

	ret = spislv_read_register(addr, &read_val);
	if (ret)
		return ret;
	ret = spislv_write_register(addr, ((read_val & (~(msk))) | ((val) & (msk))));

	return ret;
}

int spislv_switch_speed_hz(u32 tx_speed_hz, u32 rx_speed_hz)
{
	int ret = 0;

	if (rx_speed_hz >= SPI_RX_MAX_SPEED_HZ) {
		spislv_autok(tx_speed_hz, rx_speed_hz);
		ret = spislv_write_register(SPISLV_CTRL, (0x40 & (~(EARLY_TRANS_MASK)))
			| ((slv_data.high_speed_early_trans << 16) & (EARLY_TRANS_MASK)));
		spislv_chip_info.tick_delay = slv_data.high_speed_tick_delay;
	} else {
		/* needn't autok low speed because did when init */
		ret = spislv_write_register(SPISLV_CTRL, (0x40 & (~(EARLY_TRANS_MASK)))
			| ((slv_data.low_speed_early_trans << 16) & (EARLY_TRANS_MASK)));
		spislv_chip_info.tick_delay = slv_data.low_speed_tick_delay;
	}

	slv_data.tx_speed_hz =
	(tx_speed_hz > SPI_TX_MAX_SPEED_HZ ? SPI_TX_MAX_SPEED_HZ : tx_speed_hz);
	slv_data.rx_speed_hz =
	(rx_speed_hz > SPI_RX_MAX_SPEED_HZ ? SPI_RX_MAX_SPEED_HZ : rx_speed_hz);
	RS_TRANSFER.speed_hz = slv_data.rx_speed_hz;

	return ret;
}

int spislv_init(void)
{
	int ret = 0;

	slv_data.tx_speed_hz = SPI_TX_LOW_SPEED_HZ;
	slv_data.rx_speed_hz = SPI_RX_LOW_SPEED_HZ;
	RS_TRANSFER.speed_hz = slv_data.rx_speed_hz;

	ret = spi_sync(spi_bus_num, &CT_TRANSFER);
	if (ret)
		return ret;
	/* autok before spi read in low speed */
	spislv_autok(SPI_TX_LOW_SPEED_HZ, SPI_RX_LOW_SPEED_HZ);
	spislv_chip_info.tick_delay = slv_data.low_speed_tick_delay;
	ret = spislv_write_register(SPISLV_CTRL,
			(0x40 & (~(EARLY_TRANS_MASK))) | ((slv_data.low_speed_early_trans << 16) & (EARLY_TRANS_MASK)));

	if (ret)
		return ret;

	ret = spislv_write_register_mask(DRV_CFG0,
			(slv_data.slave_drive_strength << 21), SPIS_SLVO_MASK);

	return ret;
}

/* different platforms maybe have different gpio apis, so try all. */
extern S32 mt_set_gpio_drv(u32 pin, u32 drv)__attribute__((weak));
extern S32 mt_set_gpio_driving(u32 pin, u32 drv)__attribute__((weak));
void spi_slave_probe(void)
{
	int node = 0, sub_node = 0, len = 0;
	u8 *data = NULL;
	u32 pin_mux[4] = {0};
	u32 driving;
	const char *spislv_compatible = "mediatek,spi_slave";
	void *lk_drv_fdt = NULL;

	lk_drv_fdt = (void *)get_lk_overlayed_dtb();
	if (lk_drv_fdt == NULL)
		panic("lk driver fdt is NULL!\n");

	node = fdt_node_offset_by_compatible(lk_drv_fdt, -1, spislv_compatible);
	if (node <= 0) {
		dprintf(CRITICAL, "[spislv] spi slave dts node is not set, just skip.\n");
		return;
	}

	spi_bus_num = init_spi_bus_from_dt(spislv_compatible, &spislv_chip_info);
	if (spi_bus_num < 0){
		return;
	}

	// needn't parse tick delay or early trans from dts because autok later

	data = (u8 *)fdt_getprop(lk_drv_fdt, node, "slave-drive-strength", &len);
	if (data) {
		slv_data.slave_drive_strength = *data;
		dprintf(CRITICAL, "[spislv]slave-drive-strength: %d\n",
				slv_data.slave_drive_strength);
	} else
		dprintf(CRITICAL, "[spislv]slave-drive-strength is not set\n");

	/* parse spi master gpio driving from dts */
	node = fdt_path_offset(lk_drv_fdt, "/pinctrl/spislv_mode_default");
	if (node <= 0)
		return;

	sub_node = fdt_first_subnode(lk_drv_fdt, node);
	if (sub_node <= 0)
		return;

	spislv_fdt_getprop_u32_array(lk_drv_fdt, sub_node, "pinmux", pin_mux);
	spislv_fdt_getprop_u32_array(lk_drv_fdt, sub_node, "drive-strength", &driving);

	mt_set_gpio_drv(pin_mux[0] >> 8, driving);
	mt_set_gpio_drv(pin_mux[1] >> 8, driving);
	mt_set_gpio_drv(pin_mux[2] >> 8, driving);
	mt_set_gpio_drv(pin_mux[3] >> 8, driving);

	mt_set_gpio_driving(pin_mux[0] >> 8, driving);
	mt_set_gpio_driving(pin_mux[1] >> 8, driving);
	mt_set_gpio_driving(pin_mux[2] >> 8, driving);
	mt_set_gpio_driving(pin_mux[3] >> 8, driving);

	dprintf(CRITICAL, "[spislv]pin_mux[0]: %d\n", pin_mux[0] >> 8);
	dprintf(CRITICAL, "[spislv]pin_mux[1]: %d\n", pin_mux[1] >> 8);
	dprintf(CRITICAL, "[spislv]pin_mux[2]: %d\n", pin_mux[2] >> 8);
	dprintf(CRITICAL, "[spislv]pin_mux[3]: %d\n", pin_mux[3] >> 8);
	dprintf(CRITICAL, "[spislv]drive-strength: %d\n", driving);

	CT_TRANSFER.tx_buf = cmd_trans_type_4byte_single;
	CT_TRANSFER.len = ARRAY_SIZE(cmd_trans_type_4byte_single);;
	CT_TRANSFER.cs_change = 1;
	CT_TRANSFER.speed_hz = slv_data.tx_speed_hz;
	CT_TRANSFER.tick_delay = spislv_chip_info.tick_delay; 
	RS_TRANSFER.tx_buf = tx_cmd_read_sta;
	RS_TRANSFER.rx_buf = rx_cmd_read_sta;
	RS_TRANSFER.len = ARRAY_SIZE(tx_cmd_read_sta);
	RS_TRANSFER.cs_change = 1;
	RS_TRANSFER.speed_hz = slv_data.rx_speed_hz;

	mutex_init(&slv_data.spislv_mutex);
}
