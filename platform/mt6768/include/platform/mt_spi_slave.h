#ifndef _H_MT_SPI_SLAVE_H_
#define _H_MT_SPI_SLAVE_H_

/*
 * Public function API for display
 */
#define SPI_TX_LOW_SPEED_HZ (6500000)
#define SPI_RX_LOW_SPEED_HZ (6500000)
#define SPI_TX_MAX_SPEED_HZ (55000000)
#define SPI_RX_MAX_SPEED_HZ (28000000)

/*
 * Public function API for user
 */
extern void spi_slave_probe(void);
extern int spislv_init(void);
extern int spislv_switch_speed_hz(u32 tx_speed_hz, u32 rx_speed_hz);

extern int spislv_write(u32 addr, void *val, int len);
extern int spislv_read(u32 addr, void *val, int len);
extern int spislv_read_register(u32 addr, u32 *val);
extern int spislv_write_register(u32 addr, u32 val);
extern int spislv_set_register32(u32 addr, u32 val);
extern int spislv_clr_register32(u32 addr, u32 val);
extern int spislv_write_register_mask(u32 addr, u32 val, u32 msk);
#endif /*_H_MT_SPI_SLAVE_H_*/
