#ifndef _H_MT_SPI_SLAVE_H_
#define _H_MT_SPI_SLAVE_H_
#include <platform/mt_typedefs.h>
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
void spi_slave_probe(void);
int spislv_init(void);
int spislv_switch_speed_hz(u32 tx_speed_hz, u32 rx_speed_hz);

int spislv_read(u32 addr, void *val, u32 len);
int spislv_read_register(u32 addr, u32 *val);

/*
 * NOTE: multi threads cann't write the same addr concurrently when using belowing APIs.
 */
int spislv_write(u32 addr, void *val, u32 len);
int spislv_write_register(u32 addr, u32 val);
int spislv_write_register_mask(u32 addr, u32 val, u32 msk);
#endif /*_H_MT_SPI_SLAVE_H_*/
