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
#include <malloc.h>
#include <libfdt.h>

static struct mtk_spi_bus *spi_bus[BUS_COUNT] = { NULL };
static int spi_bus_num = -1;

static const struct mtk_spi_bus_config spi_default_config = {
	.spi_mode = 0,
	.tick_delay = 0,
};

static void mtk_spi_dump_register(int bus_num)
{
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	dprintf(SPEW, "spi_cfg0_reg:0x%x\n", DRV_Reg32(&regs->spi_cfg0_reg));
	dprintf(SPEW, "spi_cfg1_reg:0x%x\n", DRV_Reg32(&regs->spi_cfg1_reg));
	dprintf(SPEW, "spi_tx_src_reg:0x%x\n",
			DRV_Reg32(&regs->spi_tx_src_reg));
	dprintf(SPEW, "spi_rx_dst_reg:0x%x\n",
			DRV_Reg32(&regs->spi_rx_dst_reg));
	dprintf(SPEW, "spi_cmd_reg:0x%x\n", DRV_Reg32(&regs->spi_cmd_reg));
	dprintf(SPEW, "spi_sta1_reg:0x%x\n", DRV_Reg32(&regs->spi_status1_reg));
}

static void mtk_spi_reset(int bus_num)
{
	int reg_val;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	reg_val = DRV_Reg32(&regs->spi_cmd_reg);
	reg_val |= 1 << SPI_CMD_RST_SHIFT;
	mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);

	reg_val = DRV_Reg32(&regs->spi_cmd_reg);
	reg_val &= ~(1 << SPI_CMD_RST_SHIFT);
	mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);
	spi_bus[bus_num]->state = MTK_SPI_IDLE;
}

static void mtk_spi_set_cs(int bus_num, bool enable)
{
	u32 reg_val;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	reg_val = DRV_Reg32(&regs->spi_cmd_reg);
	if (!enable) {
		reg_val |= 1 << SPI_CMD_PAUSE_EN_SHIFT;
		mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);
		spi_bus[bus_num]->state = MTK_SPI_PAUSE_IDLE;
	} else {
		reg_val &= ~(1 << SPI_CMD_PAUSE_EN_SHIFT);
		mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);
		mtk_spi_reset(bus_num);
		spi_bus[bus_num]->state = MTK_SPI_IDLE;
	}
}

static void mtk_spi_enable_transfer(int bus_num)
{
	int reg_val;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	if (spi_bus[bus_num]->state == MTK_SPI_IDLE) {
		reg_val = DRV_Reg32(&regs->spi_cmd_reg);
		reg_val |= 1 << SPI_CMD_ACT_SHIFT;
		mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);
	} else if (spi_bus[bus_num]->state == MTK_SPI_PAUSE_IDLE) {
		reg_val = DRV_Reg32(&regs->spi_cmd_reg);
		reg_val |= 1 << SPI_CMD_RESUME_SHIFT;
		mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);
	}
}

static void mtk_spi_packet(int bus_num, int size)
{
	int reg_val, packet_len, packet_loop;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	packet_len = size < MTK_PACKET_SIZE ? size : MTK_PACKET_SIZE;
	packet_loop = MTK_SPI_ROUNDUP_DIV(size, packet_len);

	reg_val = DRV_Reg32(&regs->spi_cfg1_reg);
	reg_val &= ~(SPI_CFG1_PACKET_LENGTH_MASK | SPI_CFG1_PACKET_LOOP_MASK);
	reg_val |= ((packet_len - 1) << SPI_CFG1_PACKET_LENGTH_SHIFT) |
		((packet_loop - 1) << SPI_CFG1_PACKET_LOOP_SHIFT);
	mt_reg_sync_writel(reg_val, &regs->spi_cfg1_reg);
}

static int mtk_spi_polling(int bus_num)
{
	int i;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	/*
	*spi sw should wait for status1 register to idle before polling
	* status0 register for rx/tx finish.
	*/
	i = 0;
	while ((DRV_Reg32(&regs->spi_status1_reg) &
				MTK_SPI_BUSY_STATUS) == 0) {
		i++;
		udelay(1);
		if (i > MTK_TXRX_TIMEOUT_US) {
			dprintf(CRITICAL, "Timeout for spi status1 reg.\n");
			goto error;
		}
	}
	i = 0;
	while ((DRV_Reg32(&regs->spi_status0_reg) &
		MTK_SPI_PAUSE_FINISH_INT_STATUS) == 0) {
		i++;
		udelay(1);
		if (i > MTK_TXRX_TIMEOUT_US) {
			dprintf(CRITICAL, "Timeout for spi status0 reg.\n");
			goto error;
		}
	}

	return 0;

error:
	return -1;
}

static void spi_prepare_transfer(int bus_num, struct spi_transfer *transfer)
{
	uint32_t div, sck_ticks, cs_ticks, reg_val;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;
	u32 speed_hz = transfer->speed_hz;

	if (speed_hz < (SPI_HZ / 2))
		div = MTK_SPI_ROUNDUP_DIV(SPI_HZ, speed_hz);
	else
		div = 1;

	sck_ticks = MTK_SPI_ROUNDUP_DIV(div, 2);
	cs_ticks = sck_ticks * 2;

	/* set the timing */
	mt_reg_sync_writel(((cs_ticks - 1) << SPI_CFG0_CS_HOLD_OFFSET) |
		((cs_ticks - 1) << SPI_CFG0_CS_SETUP_OFFSET),
		&regs->spi_cfg0_reg);

	mt_reg_sync_writel(((sck_ticks - 1) << SPI_CFG2_SCK_HIGH_OFFSET) |
		((sck_ticks - 1) << SPI_CFG2_SCK_LOW_OFFSET),
		&regs->spi_cfg2_reg);

	reg_val = DRV_Reg32(&regs->spi_cfg1_reg);
	reg_val &= ~SPI_CFG1_CS_IDLE_MASK;
	reg_val |= (cs_ticks - 1) << SPI_CFG1_CS_IDLE_SHIFT;
	mt_reg_sync_writel(reg_val, &regs->spi_cfg1_reg);

	/* tick delay */
	reg_val = DRV_Reg32(&regs->spi_cfg1_reg);
	reg_val |= (transfer->tick_delay << SPI_CFG1_GET_TICK_DLY_SHIFT);
	mt_reg_sync_writel(reg_val, &regs->spi_cfg1_reg);

}

static int mtk_spi_fifo_transfer(int bus_num, unsigned char *rx_buf,
		unsigned char *tx_buf, int size)
{
	int i, reg_val = 0, word_count, ret, remaind;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	if (!size || size > MTK_FIFO_DEPTH)
		return -1;

	mtk_spi_packet(bus_num, size);

	remaind = size & 0x03;

	if (rx_buf && !tx_buf) {
		word_count = size >> 2;
		if (remaind)
			word_count++;
		for (i = 0; i < word_count; i++)
			mt_reg_sync_writel(MTK_ARBITRARY_VALUE,
					&regs->spi_tx_data_reg);
	}

	if (tx_buf) {
		reg_val = 0;
		for (i = 0; i < size - remaind; i++) {
			reg_val |= *(tx_buf + i) << ((i & 0x03) << 3);
			if ((i & 0x03) == 3) {
				mt_reg_sync_writel(reg_val,
						&regs->spi_tx_data_reg);
				reg_val = 0;
			}
	}

		if (remaind) {
			reg_val = 0;
			for (i = 0; i < remaind; i++) {
				reg_val |= *(tx_buf + size - remaind + i)
							<< ((i & 0x03) << 3);
			}
			mt_reg_sync_writel(reg_val, &regs->spi_tx_data_reg);
		}
	}

	mtk_spi_enable_transfer(bus_num);
	ret = mtk_spi_polling(bus_num);

	if (!ret && rx_buf) {
		for (i = 0; i < size; i++) {
			if ((i & 0x03) == 0)
				reg_val = DRV_Reg32(&regs->spi_rx_data_reg);
			*(rx_buf + i) = (reg_val >> ((i & 0x03) << 3)) & 0xff;
		}
	}

	return ret;
}

static int mtk_spi_dma_transfer(int bus_num, unsigned char *rx_buf,
		unsigned char *tx_buf, int size)
{
	int i, reg_val;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	if (!rx_buf && tx_buf) {
		reg_val = DRV_Reg32(&regs->spi_cmd_reg);
		reg_val |= 1 << SPI_CMD_TX_DMA_SHIFT;
		mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);
	} else {
		reg_val = DRV_Reg32(&regs->spi_cmd_reg);
		reg_val |= (1 << SPI_CMD_RX_DMA_SHIFT) |
			(1 << SPI_CMD_TX_DMA_SHIFT);
		mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);
	}

	if (tx_buf) {
		arch_clean_cache_range((addr_t)tx_buf, size);
		mt_reg_sync_writel(tx_buf, &regs->spi_tx_src_reg);
	}

	if (rx_buf) {
		arch_clean_cache_range((addr_t)rx_buf, size);
		mt_reg_sync_writel(rx_buf, &regs->spi_rx_dst_reg);
	}

	mtk_spi_packet(bus_num, size);

	mtk_spi_enable_transfer(bus_num);

	if (mtk_spi_polling(bus_num))
		goto error;

	reg_val = DRV_Reg32(&regs->spi_cmd_reg);
	reg_val &= ~(1 << SPI_CMD_RX_DMA_SHIFT | 1 << SPI_CMD_TX_DMA_SHIFT);
	mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);

	if (rx_buf)
		arch_clean_invalidate_cache_range((addr_t)rx_buf, size);
	return 0;

error:
	return -1;

}

int spi_sync(int bus_num, struct spi_transfer *transfer)
{
	int ret, min_size;
	u8 *tx_buf = (u8 *)transfer->tx_buf;
	u8 *rx_buf = (u8 *)transfer->rx_buf;
	u32 size     = transfer->len;

	spi_prepare_transfer(bus_num, transfer);

	while (size) {
		min_size = size < MTK_PACKET_SIZE ? size : MTK_PACKET_SIZE;

		if (size > MTK_FIFO_DEPTH)
			ret = mtk_spi_dma_transfer(bus_num, rx_buf, tx_buf,
								min_size);
		else
			ret = mtk_spi_fifo_transfer(bus_num, rx_buf, tx_buf,
								min_size);

		if (ret) {
			mtk_spi_reset(bus_num);
			return ret;
		}

		size -= min_size;
		if (rx_buf)
			rx_buf += min_size;
		if (tx_buf)
			tx_buf += min_size;
	}

	if (transfer->cs_change)
		mtk_spi_set_cs(bus_num, 1);
	else
		mtk_spi_set_cs(bus_num, 0);

	return ret;
}

static void spi_loopback_test(int bus_num)
{
	u32 index, status, err_count = 0;
	struct spi_transfer transfer;
	u32 length = 400;

	dprintf(CRITICAL, "spi_loopback_test entry\n");

	transfer.tx_buf = (void *)malloc(length);
	transfer.rx_buf = (void *)malloc(length);
	transfer.speed_hz = 10000;
	transfer.cs_change = 1;
	transfer.len    = 30;

	for (index = 0; index < transfer.len; index++) {
		((u8 *)transfer.tx_buf)[index] = index % 255;
		((u8 *)transfer.rx_buf)[index] = 0;
	}
	status = spi_sync(bus_num, &transfer);
	if (status)
		dprintf(CRITICAL, "spi transfer err: %d\n", status);
	while (transfer.len--) {
		if (((u8 *)transfer.tx_buf)[transfer.len] !=
				((u8 *)transfer.rx_buf)[transfer.len]) {
			dprintf(CRITICAL, "spi pio data compare err: tx: %d rx: %d\n",
					((u8 *)transfer.tx_buf)[transfer.len],
			((u8 *)transfer.rx_buf)[transfer.len]);
			err_count++;
		}
	}
	dprintf(CRITICAL, "----SPI PIO MODE test done, err count is %d----\n",
								err_count);


	err_count = 0;
	transfer.len    = length;
	for (index = 0; index < transfer.len; index++) {
		((u8 *)transfer.tx_buf)[index] = index % 255;
		((u8 *)transfer.rx_buf)[index] = 0;
	}
	status = spi_sync(bus_num, &transfer);
	if (status)
		dprintf(CRITICAL, "spi transfer err: %d\n", status);

	while (transfer.len--) {
		if (((u8 *)transfer.tx_buf)[transfer.len] !=
				((u8 *)transfer.rx_buf)[transfer.len]) {
			dprintf(CRITICAL, "spi dma data compare err: tx: %d rx: %d\n",
					((u8 *)transfer.tx_buf)[transfer.len],
			((u8 *)transfer.rx_buf)[transfer.len]);
			err_count++;
		}
	}
	dprintf(CRITICAL, "----SPI DMA MODE test done, err count is %d----\n",
								err_count);

	free((void *)transfer.tx_buf);
	free((void *)transfer.rx_buf);

	dprintf(CRITICAL, "spi_loopback_test done\n");
}

static void spi_fdt_getprop_u32_array(int nodeoffset,
				const char *name, unsigned int *out_value)
{
	unsigned int i;
	unsigned int *data = NULL;
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

void mtk_spi_init(int bus_num, struct mtk_spi_bus_config *spi_config)
{
	uint32_t reg_val;
	uint16_t cpha, cpol;
	struct mtk_spi_bus_config *spi_bus_config = spi_config;
	struct mtk_spi_regs *regs = spi_bus[bus_num]->reg_addr;

	dprintf(SPEW, "mtk_spi_init entry\n");

	if (spi_bus_config == NULL)
		spi_bus_config = &spi_default_config;

	cpha = spi_bus_config->spi_mode & SPI_CPHA ? 1:0;
	cpol = spi_bus_config->spi_mode & SPI_CPOL ? 1:0;

	reg_val = DRV_Reg32(&regs->spi_cmd_reg);

	/* set spi mode */
	if (cpha)
		reg_val |= SPI_CMD_CPHA_EN;
	else
		reg_val &= ~SPI_CMD_CPHA_EN;
	if (cpol)
		reg_val |= SPI_CMD_CPOL_EN;
	else
		reg_val &= ~SPI_CMD_CPOL_EN;

	/* set the mlsbx and mlsbtx */
	reg_val &= ~SPI_CMD_TXMSBF_EN;
	reg_val &= ~SPI_CMD_RXMSBF_EN;

	/* set the tx/rx endian */
	reg_val &= ~SPI_CMD_TX_ENDIAN_EN;
	reg_val &= ~SPI_CMD_RX_ENDIAN_EN;

	/* clear pause mode */
	reg_val &= ~SPI_CMD_PAUSE_EN;

	/* set finish interrupt always disable */
	reg_val &= ~SPI_CMD_FINISH_IE_EN;

	/* set pause interrupt always disable */
	reg_val &= ~SPI_CMD_PAUSE_IE_EN;

	/* disable dma mode */
	reg_val &= ~(SPI_CMD_TX_DMA_EN | SPI_CMD_RX_DMA_EN);

	/* set deassert mode */
	reg_val &= ~SPI_CMD_DEASSERT_EN;
	mt_reg_sync_writel(reg_val, &regs->spi_cmd_reg);

	/* pad select */
	reg_val = spi_bus[bus_num]->pad_select;
	mt_reg_sync_writel(reg_val, &regs->spi_pad_sel_reg);

	/* tick delay */
	reg_val = DRV_Reg32(&regs->spi_cfg1_reg);
	reg_val |= (spi_bus_config->tick_delay << SPI_CFG1_GET_TICK_DLY_SHIFT);
	mt_reg_sync_writel(reg_val, &regs->spi_cfg1_reg);

	/* cs pull high && reset spi */
	mtk_spi_set_cs(bus_num, 1);

#ifdef SPI_EARLY_PORTING
	reg_val = 7;
	mt_reg_sync_writel(reg_val, &regs->spi_pad_sel_reg);
	spi_loopback_test(bus_num);

	reg_val = spi_bus[bus_num]->pad_select;
	mt_reg_sync_writel(reg_val, &regs->spi_pad_sel_reg);
#endif

	mtk_spi_reset(bus_num);
}


int init_spi_bus_from_dt(const char *compatible,
			struct mtk_spi_bus_config *config)
{
	uint32_t node, parent_node = 0;
	uint32_t temp_data[4];
	uint32_t pad_select = 0;
	struct mtk_spi_bus *bus = NULL;

	void *lk_drv_fdt = get_lk_overlayed_dtb();

	if (lk_drv_fdt == NULL)
		panic("lk driver fdt is NULL!\n");

	node = fdt_node_offset_by_compatible(lk_drv_fdt, -1, compatible);
	if (node > 0) {
		parent_node = fdt_parent_offset(lk_drv_fdt, node);
		if (parent_node > 0) {
			bus = malloc(sizeof(struct mtk_spi_bus));
			if (bus) {
				spi_bus_num++;
				spi_bus[spi_bus_num] = bus;
			}
			spi_fdt_getprop_u32_array(parent_node,
					"reg", temp_data);
			spi_fdt_getprop_u32_array(parent_node,
					"mediatek,pad-select", &pad_select);
			spi_bus[spi_bus_num]->reg_addr = temp_data[1];
			spi_bus[spi_bus_num]->pad_select = pad_select;
			spi_bus[spi_bus_num]->spi_bus_fdt_offset = parent_node;
			dprintf(SPEW, "reg addr : %x, pad_select : %d\n",
					spi_bus[spi_bus_num]->reg_addr,
					spi_bus[spi_bus_num]->pad_select);
		} else {
			dprintf(SPEW, "get spi slave parent node failed!\n");
			return -1;
		}
	} else {
		dprintf(SPEW, "get spi slave node failed!\n");
		return -1;
	}
	mtk_spi_init(spi_bus_num, config);

	return spi_bus_num;
}
