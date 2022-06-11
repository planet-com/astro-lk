#ifndef __MT6315_SPMI_H_
#define __MT6315_SPMI_H_

#include <printf.h>

#define MT6315TAG	"[MT6315]"
#define MT6315_ERR(fmt, arg...) pal_log_err(MT6315TAG fmt, ##arg)
#define MT6315_WARN(fmt, arg...) pal_log_warn(MT6315TAG fmt, ##arg)
#define MT6315_INFO(fmt, arg...) pal_log_info(MT6315TAG fmt, ##arg)
#define MT6315_DBG(fmt, arg...) pal_log_debug(MT6315TAG fmt, ##arg)

#define MT6315_SWCID_H_CODE	0x15
#define MT6315_SWCID_L_E1_CODE	0x10
#define MT6315_SWCID_L_E2_CODE	0x20
#define MT6315_SWCID_L_E3_CODE	0x30

/* MT6315 power device index */
enum {
	MT6315_S3,
	MT6315_MAX,
};

enum {
	MT6315_TYPE_A,
	MT6315_TYPE_B,
	MT6315_TYPE_C,
};

struct mt6315_chip {
	uint8_t power_idx;
	uint8_t master_idx;
	uint8_t slave_addr;
	uint8_t type;
	struct spmi_device *spmi_dev;
};

extern int mt6315_write_field_byte(struct spmi_device *dev, unsigned int addr,
		unsigned char val, unsigned short mask, unsigned short shift);
extern struct mt6315_chip *mt6315_find_chip(int pidx);
extern void mt6315_all_seq_off(unsigned char en_seq_off);
extern int mt6315_spmi_probe(void);

#endif /* __MT6315_SPMI_H_ */
