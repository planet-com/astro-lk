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

#include <platform/mt_spi.h>
#include <platform/mt_spi_slave.h>
#include <platform/mt_gpio.h>
#include <malloc.h>
#include <bits.h>
#include <libfdt.h>
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
#define MAX_SPI_TRY_CNT			(10)

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
	u32 addr;
	u32 len;
	void *buffer;
	u8 slave_drive_strength;
	u8 high_speed_tick_delay;
	u8 low_speed_tick_delay;
	u8 high_speed_early_trans;
	u8 low_speed_early_trans;
	bool is_read:1;
};

static u8 cmd_trans_type_4byte_single[2] = {CMD_CT, 0x04};
static u8 tx_cmd_read_sta[2] = {CMD_RS, 0x00};
static u8 rx_cmd_read_sta[2] = {0x00, 0x00};

static struct spi_transfer CT_TRANSFER = {0};
static struct spi_transfer RS_TRANSFER = {0};

static struct mtk_spi_slave_data slv_data = {
	.tx_speed_hz = SPI_TX_LOW_SPEED_HZ,
	.rx_speed_hz = SPI_RX_LOW_SPEED_HZ,
	.addr = 0,
	.len = 0,
	.buffer = NULL,
	.is_read = 0,
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

static int spislv_sync_sub(void)
{
	int ret = 0, i = 0;
	struct spi_transfer x[2] = {0};
	void *local_buf = NULL;
	u8 mtk_spi_buffer[MTK_SPI_BUFSIZ];
	u8 cmd_write_sta[2] = {CMD_WS, 0xff};
	u8 status = 0;
	u32 retry = 0;
	u8 cmd_config[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	/* CR or CW */
	if (slv_data.is_read)
		cmd_config[0] = CMD_CR;
	else
		cmd_config[0] = CMD_CW;

	for (i = 0; i < 4; i++) {
		cmd_config[1 + i] = (slv_data.addr & (0xff << (i * 8)))
							>> (i * 8);
		cmd_config[5 + i] = ((slv_data.len - 1) & (0xff << (i * 8)))
							>> (i * 8);
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
	if ((status & CONFIG_READY) != CONFIG_READY) {

		dprintf(CRITICAL, "SPI config %s status error: 0x%x, err addr: 0x%x\n",
				slv_data.is_read ? "read" : "write", status, slv_data.addr);
		ret = SPI_READ_STA_ERR_RET;
		goto tail;
	}

	/* RD or WD */
	if (slv_data.len > MTK_SPI_BUFSIZ - 1) {
		local_buf = malloc(slv_data.len + 1);
		if (!local_buf) {
			dprintf(CRITICAL, "[spislv]local buf malloc fail\n");
			goto tail;
		}
	} else {
		local_buf = mtk_spi_buffer;
		memset(local_buf, 0, MTK_SPI_BUFSIZ);
	}

	if (slv_data.is_read) {
		*((u8 *)local_buf) = CMD_RD;
		x[1].tx_buf = local_buf;
		x[1].rx_buf = local_buf;
		x[1].speed_hz = slv_data.rx_speed_hz;
	} else {
		*((u8 *)local_buf) = CMD_WD;
		memcpy((u8 *)local_buf + 1, slv_data.buffer, slv_data.len);
		x[1].tx_buf = local_buf;
		x[1].speed_hz = slv_data.tx_speed_hz;
	}
	x[1].len = slv_data.len + 1;
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
	if (slv_data.addr == SPISLV_CTRL)
		status = 0x26;

	if (((status & SR_RD_ERR) == SR_RD_ERR) ||
		((status & SR_WR_ERR) == SR_WR_ERR) ||
		((status & SR_TIMEOUT_ERR) == SR_TIMEOUT_ERR)) {

		dprintf(CRITICAL, "SPI %s error: 0x%x, err addr: 0x%x\n",
			slv_data.is_read ? "read" : "write", status, slv_data.addr);

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
			dprintf(CRITICAL, "SPI %s not finish: 0x%x, err addr: 0x%x, polling: %d\n",
				slv_data.is_read ? "read" : "write", status, slv_data.addr, retry);
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
	if (slv_data.is_read && !ret)
		memcpy(slv_data.buffer, ((u8 *)x[1].rx_buf + 1), slv_data.len);

	if (local_buf != mtk_spi_buffer)
		free(local_buf);
	return ret;
}

static int spislv_sync(void)
{
	int ret = 0;
	int once_addr = MAX_SPI_XFER_SIZE_ONCE / 4;
	u32 len = 0;
	u32 try = 0;

	if (slv_data.len < MAX_SPI_XFER_SIZE_ONCE)
		goto transfer_drect;

	len = slv_data.len;
	while (len > MAX_SPI_XFER_SIZE_ONCE) {
		slv_data.len = MAX_SPI_XFER_SIZE_ONCE;
		ret = spislv_sync_sub();
		while (ret) {
		dprintf(CRITICAL, "spi slave error, addr: 0x%x, ret(%d), retry: %d\n",
				slv_data.addr, ret, try);
			if (try++ == MAX_SPI_TRY_CNT)
				goto tail;
			ret = spislv_sync_sub();
		}
		slv_data.addr = slv_data.addr + once_addr;
		slv_data.buffer = (u8 *)slv_data.buffer + MAX_SPI_XFER_SIZE_ONCE;
		len = len - MAX_SPI_XFER_SIZE_ONCE;
	}

	slv_data.len = len;

transfer_drect:
	ret = spislv_sync_sub();
	while (ret) {
	dprintf(CRITICAL, "spi slave error, addr: 0x%x, ret(%d), retry: %d\n",
			slv_data.addr, ret, try);
		if (try++ == MAX_SPI_TRY_CNT)
			goto tail;
		ret = spislv_sync_sub();
	}

tail:
	/* slv_data's transfer info will not be original if split. */
	return ret;
}

int spislv_init(void)
{
	int ret = 0;

	spislv_chip_info.tick_delay = slv_data.low_speed_tick_delay;
	CT_TRANSFER.tick_delay = spislv_chip_info.tick_delay;
	ret = spi_sync(spi_bus_num, &CT_TRANSFER);

	ret = spislv_write_register_mask(SPISLV_CTRL,
					(slv_data.low_speed_early_trans << 16),
					EARLY_TRANS_MASK);
	if (slv_data.slave_drive_strength)
		ret = spislv_write_register_mask(DRV_CFG0, (0x7 << 21),
							SPIS_SLVO_MASK);
	return ret;
}

int spislv_switch_speed_hz(u32 tx_speed_hz, u32 rx_speed_hz)
{
	int ret = 0;

	slv_data.tx_speed_hz =
	(tx_speed_hz > SPI_TX_MAX_SPEED_HZ ? SPI_TX_MAX_SPEED_HZ : tx_speed_hz);
	slv_data.rx_speed_hz =
	(rx_speed_hz > SPI_RX_MAX_SPEED_HZ ? SPI_RX_MAX_SPEED_HZ : rx_speed_hz);
	RS_TRANSFER.speed_hz = slv_data.rx_speed_hz;

	if (slv_data.rx_speed_hz == SPI_RX_MAX_SPEED_HZ) {
		spislv_chip_info.tick_delay = slv_data.high_speed_tick_delay;
		ret = spislv_write_register_mask(SPISLV_CTRL,
					(slv_data.high_speed_early_trans << 16),
					EARLY_TRANS_MASK);
	} else {
		spislv_chip_info.tick_delay = slv_data.low_speed_tick_delay;
		ret = spislv_write_register_mask(SPISLV_CTRL,
					(slv_data.low_speed_early_trans << 16),
					EARLY_TRANS_MASK);
	}
	return ret;
}

int spislv_write(u32 addr, void *val, int len)
{
	slv_data.buffer = val;
	slv_data.addr = addr;
	slv_data.len = len;
	slv_data.is_read = 0;
	return spislv_sync();
}

int spislv_read(u32 addr, void *val, int len)
{
	slv_data.buffer = val;
	slv_data.addr = addr;
	slv_data.len = len;
	slv_data.is_read = 1;
	return spislv_sync();
}

int spislv_read_register(u32 addr, u32 *val)
{
	return spislv_read(addr, (u8 *)val, 4);
}

int spislv_write_register(u32 addr, u32 val)
{
	return spislv_write(addr, (u8 *)&val, 4);
}

int spislv_set_register32(u32 addr, u32 val)
{
	u32 ret = 0;
	u32 read_val;

	ret = spislv_read_register(addr, &read_val);
	if (ret)
		return ret;
	ret = spislv_write_register(addr, read_val | val);

	return ret;
}

int spislv_clr_register32(u32 addr, u32 val)
{
	u32 ret = 0;
	u32 read_val;

	ret = spislv_read_register(addr, &read_val);
	if (ret)
		return ret;
	ret = spislv_write_register(addr, read_val & (~val));
	return ret;
}

int spislv_write_register_mask(u32 addr, u32 val, u32 msk)
{
	u32 ret = 0;
	u32 read_val;

	ret = spislv_read_register(addr, &read_val);
	if (ret)
		return ret;
	ret = spislv_write_register(addr, ((read_val & (~(msk))) |
						((val) & (msk))));

	return ret;
}

static void spislv_fdt_getprop_u32_array(int nodeoffset,
				const char *name, unsigned int *out_value)
{
	u32 i;
	u32 *data = NULL;
	int len = 0;
	void *lk_drv_fdt = get_lk_overlayed_dtb();

	if (lk_drv_fdt == NULL)
		panic("lk driver fdt is NULL!\n");

	data = (unsigned int *)fdt_getprop(lk_drv_fdt, nodeoffset, name, &len);
	if (len > 0) {
		len = len / sizeof(unsigned int);
		for (i = 0; i < len; i++)
			*(out_value+i) = fdt32_to_cpu(*(data+i));
	} else
		*out_value = 0;
}

static u32 init_spislv_from_dt(const char *compatible)
{
	u32 node = 0;
	u32 *data = NULL;
	int len = 0;
	struct mtk_spi_bus *bus = NULL;
	void *lk_drv_fdt = get_lk_overlayed_dtb();

	if (lk_drv_fdt == NULL)
		panic("lk driver fdt is NULL!\n");

	node = fdt_node_offset_by_compatible(lk_drv_fdt, -1, compatible);
	if (node < 0) {
		dprintf(CRITICAL, "[spislv]fdt node err: %d\n", node);
		return node;
	}
	data = (unsigned char *)fdt_getprop(lk_drv_fdt, node,
					"slave-drive-strength", &len);
	slv_data.slave_drive_strength = *data;
	data = (unsigned char *)fdt_getprop(lk_drv_fdt, node,
					"high-speed-tick-delay", &len);
	slv_data.high_speed_tick_delay = *data;
	data = (unsigned char *)fdt_getprop(lk_drv_fdt, node,
					"low-speed-tick-delay", &len);
	slv_data.low_speed_tick_delay = *data;
	data = (unsigned char *)fdt_getprop(lk_drv_fdt, node,
					"high-speed-early-trans", &len);
	slv_data.high_speed_early_trans = *data;
	data = (unsigned char *)fdt_getprop(lk_drv_fdt, node,
					"low-speed-early-trans", &len);
	slv_data.low_speed_early_trans = *data;

	dprintf(CRITICAL, "[spislv]slave-drive-strength: %d\n",
					slv_data.slave_drive_strength);
	dprintf(CRITICAL, "[spislv]high-speed-tick-delay: %d\n",
					slv_data.high_speed_tick_delay);
	dprintf(CRITICAL, "[spislv]low-speed-tick-delay: %d\n",
					slv_data.low_speed_tick_delay);
	dprintf(CRITICAL, "[spislv]high-speed-early-trans: %d\n",
					slv_data.high_speed_early_trans);
	dprintf(CRITICAL, "[spislv]low-speed-early-trans: %d\n",
					slv_data.low_speed_early_trans);

	return 0;
}

static void init_gpio_from_dt(const char *path)
{
	u32 sub_node;
	u32 pin_mux[4];
	u32 driving;
	void *lk_drv_fdt = get_lk_overlayed_dtb();
	int node = fdt_path_offset(lk_drv_fdt, path);

	if (node > 0) {
		sub_node = fdt_first_subnode(lk_drv_fdt, node);
		if (sub_node > 0) {
			spislv_fdt_getprop_u32_array(sub_node,
				"pinmux", pin_mux);
			spislv_fdt_getprop_u32_array(sub_node,
				"drive-strength", &driving);
		}
	}
	dprintf(CRITICAL, "[spislv]pin_mux[0]: %d\n", pin_mux[0] >> 8);
	dprintf(CRITICAL, "[spislv]pin_mux[1]: %d\n", pin_mux[1] >> 8);
	dprintf(CRITICAL, "[spislv]pin_mux[2]: %d\n", pin_mux[2] >> 8);
	dprintf(CRITICAL, "[spislv]pin_mux[3]: %d\n", pin_mux[3] >> 8);
	dprintf(CRITICAL, "[spislv]drive-strength: %d\n", driving);
	mt_set_gpio_driving(pin_mux[0] >> 8, driving);
	mt_set_gpio_driving(pin_mux[1] >> 8, driving);
	mt_set_gpio_driving(pin_mux[2] >> 8, driving);
	mt_set_gpio_driving(pin_mux[3] >> 8, driving);
}

void spi_slave_probe(void)
{
	int bus_num;
	const char *spislv_compatible = "mediatek,spi_slave";

	CT_TRANSFER.tx_buf = cmd_trans_type_4byte_single;
	CT_TRANSFER.len = ARRAY_SIZE(cmd_trans_type_4byte_single);;
	CT_TRANSFER.cs_change = 1;
	CT_TRANSFER.speed_hz = slv_data.tx_speed_hz;
	RS_TRANSFER.tx_buf = tx_cmd_read_sta;
	RS_TRANSFER.rx_buf = rx_cmd_read_sta;
	RS_TRANSFER.len = ARRAY_SIZE(tx_cmd_read_sta);
	RS_TRANSFER.cs_change = 1;
	RS_TRANSFER.speed_hz = slv_data.rx_speed_hz;

	init_gpio_from_dt("/pinctrl/spislv_mode_default");
	init_spislv_from_dt(spislv_compatible);
	bus_num = init_spi_bus_from_dt(spislv_compatible, &spislv_chip_info);
	if (bus_num >= 0)
		spi_bus_num = bus_num;
	else
		dprintf(CRITICAL, "[spislv]init spi bus fail!\n");
}
