#include <platform/errno.h>
#include <platform/mt6315-spmi.h>
#include <platform/mt6315_upmu_hw.h>
#include <platform/spmi.h>
#include <platform/spmi_sw.h>
#include <stdint.h>

/* Enable dump all register */
#define MT6315_DEBUG		0

#define DECL_CHIP(_pidx, _mid, _type, _saddr)\
{					\
	.power_idx = _pidx,		\
	.master_idx = _mid,		\
	.slave_addr = _saddr,		\
	.type = _type,			\
	.spmi_dev = NULL,		\
}

static struct mt6315_chip mt6315_chip[MT6315_MAX] = {
	DECL_CHIP(MT6315_S6, SPMI_MASTER_0, MT6315_TYPE_A, SPMI_SLAVE_6),
	DECL_CHIP(MT6315_S7, SPMI_MASTER_0, MT6315_TYPE_B, SPMI_SLAVE_7),
	DECL_CHIP(MT6315_S3, SPMI_MASTER_0, MT6315_TYPE_C, SPMI_SLAVE_3),
};

#if MT6315_DEBUG
static void mt6315_dump_register(int pidx)
{
	int addr = 0;
	uint8_t val = 0;
	struct mt6315_chip *chip;

	if (pidx >= MT6315_MAX)
		return;

	chip = &mt6315_chip[pidx];
	if (!chip->spmi_dev)
		return;

	for (addr = 0; addr <= MT6315_BUCK_TOP_4PHASE_ELR_29; addr++) {
		spmi_ext_register_readl(chip->spmi_dev, addr, &val, 1);
		MT6315_INFO("[0x%x]=0x%x ", addr, val);
	}
}
#endif

struct mt6315_chip *mt6315_find_chip(int pidx)
{
	int i;

	for (i = 0; i < MT6315_MAX; i++) {
		if (mt6315_chip[i].power_idx == pidx)
			return &mt6315_chip[i];
	}
	return NULL;
}

#if !SPMI_NO_PMIC
static int mt6315_check_cid(void)
{
	int pidx = 0, ret = 0;
	struct mt6315_chip *chip;
	struct spmi_device *dev;
	uint8_t val = 0;

	for (pidx = 0; pidx < MT6315_MAX; pidx++) {
		chip = &mt6315_chip[pidx];
		dev = get_spmi_device(chip->master_idx,
					mt6315_chip[pidx].slave_addr);
		if (!dev) {
			MT6315_ERR("%s fail(%d).\n", __func__, pidx);
			return -ENODEV;
		}
		chip->spmi_dev = dev;
		ret = spmi_ext_register_readl_field(dev,
						    MT6315_PMIC_SWCID_H_ADDR,
						    &val, 1,
						    MT6315_PMIC_SWCID_H_MASK,
						    MT6315_PMIC_SWCID_H_SHIFT);
		if (ret != 0 ||
		    val != MT6315_SWCID_H_CODE) {
			MT6315_ERR("%s ret=%d val=%d\n", __func__, ret, val);
			return -EIO;
		}
	}

	return 0;
}
#else
static int mt6315_check_cid(void)
{
	return -ENODEV;
}
#endif

void mt6315_all_seq_off(unsigned char en_seq_off)
{
	int pidx = 0;
	struct mt6315_chip *chip;

	for (pidx = 0; pidx < MT6315_MAX; pidx++) {
		chip = &mt6315_chip[pidx];
		if (!chip->spmi_dev)
			return;
		mt6315_write_field_byte(chip->spmi_dev,
				MT6315_PMIC_TMA_KEY_H_ADDR, 0x9C,
				MT6315_PMIC_TMA_KEY_H_MASK,
				MT6315_PMIC_TMA_KEY_H_SHIFT);
		mt6315_write_field_byte(chip->spmi_dev,
				MT6315_PMIC_TMA_KEY_ADDR, 0xEA,
				MT6315_PMIC_TMA_KEY_MASK,
				MT6315_PMIC_TMA_KEY_SHIFT);
		mt6315_write_field_byte(chip->spmi_dev,
				MT6315_PMIC_RG_TOP2_RSV2_ADDR,
				en_seq_off, 0x1, 0);
		mt6315_write_field_byte(chip->spmi_dev,
				MT6315_PMIC_TMA_KEY_ADDR, 0,
				MT6315_PMIC_TMA_KEY_MASK,
				MT6315_PMIC_TMA_KEY_SHIFT);
		mt6315_write_field_byte(chip->spmi_dev,
				MT6315_PMIC_TMA_KEY_H_ADDR, 0,
				MT6315_PMIC_TMA_KEY_H_MASK,
				MT6315_PMIC_TMA_KEY_H_SHIFT);
		MT6315_INFO("S%d set seq off=%d\n"
			    , chip->slave_addr, en_seq_off);
	}
	return;
}

int mt6315_write_field_byte(struct spmi_device *dev, unsigned int addr,
		unsigned char val, unsigned short mask, unsigned short shift) {
#if SPMI_NO_PMIC
	return -ENODEV;
#else
	return spmi_ext_register_writel_field(dev, addr, &val, 1, mask, shift);
#endif
}

int mt6315_spmi_probe(void)
{
	int ret = 0;

	ret = mt6315_check_cid();
	if (ret < 0)
		return ret;

	MT6315_INFO("%s done\n", __func__);

	return 0;
}
