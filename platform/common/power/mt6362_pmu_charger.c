/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part,
* shall be strictly prohibited.
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
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY
* ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY
* THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL
* ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO RECEIVER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
* RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*/

#include <platform/mt_typedefs.h>
#include <platform/errno.h>
#include <platform/spmi.h>
#include <platform/spmi_sw.h>
#include <printf.h>
#include <debug.h>
#include <platform/timer.h>
#include "mt6362_pmu_charger.h"
#include "mtk_charger_intf.h"

#define MT6362_PMU_CHARGER_LK_DRV_VERSION "1.0.1_MTK"

#define MT6362_LOG_LVL			(INFO)

#define U32_MAX 0xFFFFFFFF

/* Register Table */
#define MT6362_REG_DEV_INFO		(0x00)
#define MT6362_REG_TM_PASCODE1		(0x07)
#define MT6362_REG_CHG_TOP1		(0x20)
#define MT6362_REG_CHG_TOP2		(0x21)
#define MT6362_REG_CHG_AICR		(0x22)
#define MT6362_REG_CHG_MIVR		(0x23)
#define MT6362_REG_CHG_PREC		(0x24)
#define MT6362_REG_CHG_VCHG		(0x25)
#define MT6362_REG_CHG_ICHG		(0x26)
#define MT6362_REG_CHG_EOC		(0x28)
#define MT6362_REG_CHG_WDT		(0x2A)
#define MT6362_REG_CHG_STAT		(0x34)
#define MT6362_REG_CHG_DUMMY0		(0x35)
#define MT6362_REG_CHG_HD_BUCK5		(0x40)
#define MT6362_REG_ADCCFG1		(0xA4)
#define MT6362_REG_ADCCFG3		(0xA6)
#define MT6362_REG_ADCEN1		(0xA7)
#define MT6362_CHRPT_BASEADDR		(0xAA)
#define MT6362_REG_ADC_IRQ		(0xD5)

/* Mask & Shift */
/* 0x20 */
#define MT6362_MASK_CHG_BUCK_EN		BIT(1)
#define MT6362_MASK_CHG_EN		BIT(0)
/* 0x21 */
#define MT6362_MASK_SEL_CLK_FREQ	(0xC0)
#define MT6362_SHFT_SEL_CLK_FREQ	(6)
/* 0x22 */
#define MT6362_MASK_ILIM_EN		BIT(7)
#define MT6362_MASK_AICR		(0x7F)
#define MT6362_SHFT_AICR		(0)
/* 0x23 */
#define MT6362_MASK_MIVR		(0x7F)
#define MT6362_SHFT_MIVR		(0)
/* 0x24 */
#define MT6362_MASK_IPREC		(0x1F)
#define MT6362_SHFT_IPREC		(0)
/* 0x25 */
#define MT6362_MASK_CV			(0x7F)
#define MT6362_SHFT_CV			(0)
/* 0x26 */
#define MT6362_MASK_CC			(0x3F)
#define MT6362_SHFT_CC			(0)
/* 0x28 */
#define MT6362_MASK_IEOC		(0xF0)
#define MT6362_SHFT_IEOC		(4)
/* 0x2A */
#define MT6362_MASK_WDT_EN		BIT(3)
/* 0x34 */
#define MT6362_MASK_IC_STAT		(0x0F)
#define MT6362_SHFT_IC_STAT		(0)
/* 0x35 */
#define MT6362_MASK_COMP_CLAMP		(0x03)
#define MT6362_SHFT_COMP_CLAMP		(0)
/* 0x40 */
#define MT6362_MASK_BUCK_RAMPOFT	(0xC0)
#define MT6362_SHFT_BUCK_RAMPOFT	(6)
/* 0xA6 */
#define MT6362_SHFT_ADC_ONESHOT_SEL	(4)
#define MT6362_SHFT_ADC_DONE_IRQ_SEL	(0)
/* 0xD5 */
#define MT6362_MASK_ADC_DONEI		BIT(4)

/* Engineer Spec */
/* uA */
#define MT6362_AICR_MIN		50
#define MT6362_AICR_MAX		3225
#define MT6362_AICR_STEP	25
/* uV */
#define MT6362_MIVR_MIN		3900
#define MT6362_MIVR_MAX		13400
#define MT6362_MIVR_STEP	100
/* uV */
#define MT6362_VPREC_MIN	2600
#define MT6362_VPREC_MAX	3300
#define MT6362_VPREC_STEP	100
/* uA */
#define MT6362_IPREC_MIN	50
#define MT6362_IPREC_MAX	1600
#define MT6362_IPREC_STEP	50
/* uV */
#define MT6362_CV_MIN		3900
#define MT6362_CV_MAX		4710
#define MT6362_CV_STEP		10
/* uA */
#define MT6362_CC_MIN		0
#define MT6362_CC_MAX		3150
#define MT6362_CC_STEP		50
/* uA */
#define MT6362_IEOC_MIN		50
#define MT6362_IEOC_MAX		800
#define MT6362_IEOC_STEP	50

/* for reset PD adapter */
#define TCPC_V10_REG_ROLE_CTRL		(0x41A)
#define MT6362_REG_SYSCTRL1		(0x48F)
#define MT6362_MASK_SHIPPING_OFF	BIT(5)

/* ================= */
/* Internal variable */
/* ================= */
struct mt6362_chg_data {
	struct mtk_charger_info mchr_info;
	struct spmi_device *sdev;
	u32 last_access_addr;
	u32 last_access_tick;
	u8 vid;
	u32 iprec;
	u32 ichg;
	u32 ichg_dis_chg;
	u32 aicr;
	u32 mivr;
	u32 cv;
};

enum mt6362_clk_freq {
	MT6362_CLK_FREQ_1500K,
	MT6362_CLK_FREQ_1000K,
	MT6362_CLK_FREQ_750K,
	MT6362_CLK_FREQ_MAX,
};

enum mt6362_ic_stat {
	MT6362_STAT_HZ = 0x0,
	MT6362_STAT_READY = 0x1,
	MT6362_STAT_TRI_CHG = 0x2,
	MT6362_STAT_PRE_CHG = 0x3,
	MT6362_STAT_FAST_CHG = 0x4,
	MT6362_STAT_EOC_CHG = 0x5,
	MT6362_STAT_BACKGND_CHG = 0x6,
	MT6362_STAT_CHG_DONE = 0x7,
	MT6362_STAT_CHG_FAULT = 0x8,
	MT6362_STAT_OTG = 0xf,
};

static const char *mt6362_ic_stat_list[] = {
	"hz/sleep", "ready", "trickle_chg", "pre_chg", "fast_chg",
	"ieoc_chg", "backgnd_chg", "chg_done", "chg_fault", "otg",
};

/* ========================= */
/* SPMI operations */
/* ========================= */
static int mt6362_write_byte(struct mt6362_chg_data *cdata, u32 addr, u8 data)
{
	struct spmi_device *sdev = cdata->sdev;
	int ret;

	ret = spmi_ext_register_writel(sdev, addr, &data, 1);
	if (ret < 0)
		dprintf(CRITICAL, "%s: fail, addr:0x%02X, data:0x%02X\n",
			__func__, addr, data);
	else {
		dprintf(MT6362_LOG_LVL, "%s: addr:0x%02X, data:0x%02X\n",
			__func__, addr, data);
		cdata->last_access_addr = addr;
		cdata->last_access_tick = gpt4_get_current_tick();
	}
	return ret;
}

static int mt6362_read_byte(struct mt6362_chg_data *cdata, u32 addr, u8 *data)
{
	struct spmi_device *sdev = cdata->sdev;
	u32 avail_access_tick, current_tick, rest_tick;
	int ret;

	if (addr == cdata->last_access_addr) {
		avail_access_tick =
			cdata->last_access_tick + gpt4_time2tick_us(3);
		current_tick = gpt4_get_current_tick();
		if (avail_access_tick > current_tick) {
			rest_tick = avail_access_tick - current_tick;
			udelay(gpt4_tick2time_us(rest_tick));
		}
	}

	ret = spmi_ext_register_readl(sdev, addr, data, 1);
	if (ret < 0)
		dprintf(CRITICAL, "%s: fail, addr:0x%02X\n", __func__, addr);
	else
		dprintf(MT6362_LOG_LVL, "%s: addr:0x%02X, data:0x%02X\n",
			__func__, addr, *data);
	return ret;
}

static inline int mt6362_block_read(struct mt6362_chg_data *cdata,
				    u32 addr, u8 *data, int len)
{
	int i, ret;

	for (i = 0; i < len; i++) {
		ret = mt6362_read_byte(cdata, addr + i, data + i);
		if (ret < 0)
			return ret;
	}
	return ret;
}

static inline int mt6362_block_write(struct mt6362_chg_data *cdata,
				     u32 addr, u8 *data, int len)
{
	int i, ret;

	for (i = 0; i < len; i++) {
		ret = mt6362_write_byte(cdata, addr, *(data + i));
		if (ret < 0)
			return ret;
	}
	return ret;
}

static int mt6362_update_bits(struct mt6362_chg_data *cdata,
			      u32 addr, u8 mask, u8 data)
{
	int ret;
	u8 org = 0;

	ret = mt6362_read_byte(cdata, addr, &org);
	if (ret < 0)
		return ret;
	org &= ~mask;
	org |= (data & mask);
	return mt6362_write_byte(cdata, addr, org);
}

static inline int mt6362_set_bits(struct mt6362_chg_data *cdata,
				  u32 addr, u8 mask)
{
	return mt6362_update_bits(cdata, addr, mask, mask);
}

static inline int mt6362_clr_bits(struct mt6362_chg_data *cdata, u32 addr, u8 mask)
{
	return mt6362_update_bits(cdata, addr, mask, 0);
}

static inline u32 mt6362_map_reg_sel(u32 data, u32 min, u32 max, u32 step)
{
	u32 target = 0, max_sel;

	if (data >= min) {
		target = (data - min) / step;
		max_sel = (max - min) / step;
		if (target > max_sel)
			target = max_sel;
	}
	return target;
}

static inline u32 mt6362_map_real_val(u32 sel, u32 min, u32 max, u32 step)
{
	u32 target = 0;

	target = min + (sel * step);
	if (target > max)
		target = max;
	return target;
}

/* ================== */
/* internal functions */
/* ================== */
#define MT6362_VENDOR_ID			(0x70)
static bool mt6362_is_hw_exist(struct mt6362_chg_data *cdata)
{
	int ret;
	u8 regval = 0, vid, rev_id;

	ret = mt6362_read_byte(cdata, MT6362_REG_DEV_INFO, &regval);
	if (ret < 0)
		return false;
	vid = regval & 0xF0;
	rev_id = regval & 0x0F;
	if (vid != MT6362_VENDOR_ID) {
		dprintf(CRITICAL, "%s: vid is not match(%d)\n", __func__, vid);
		return false;
	}
	dprintf(CRITICAL, "%s: rev_id = %d\n", __func__, rev_id);

	cdata->mchr_info.device_id = rev_id;
	cdata->vid = vid;
	return true;
}

static int mt6362_enable_hidden_mode(struct mt6362_chg_data *cdata, bool en)
{
	return mt6362_write_byte(cdata, MT6362_REG_TM_PASCODE1,
				 en ? 0x69 : 0);
}

static int mt6362_enable_ilim(struct mt6362_chg_data *cdata, bool en)
{
	dprintf(MT6362_LOG_LVL, "%s: en = %d\n", __func__, en);
	return (en ? mt6362_set_bits : mt6362_clr_bits)
		(cdata, MT6362_REG_CHG_AICR, MT6362_MASK_ILIM_EN);
}

static int mt6362_set_cv(struct mt6362_chg_data *cdata, u32 uV)
{
	u8 sel;

	dprintf(MT6362_LOG_LVL, "%s: cv = %d\n", __func__, uV);
	sel = mt6362_map_reg_sel(uV, MT6362_CV_MIN, MT6362_CV_MAX,
				 MT6362_CV_STEP);
	return mt6362_update_bits(cdata,
				  MT6362_REG_CHG_VCHG,
				  MT6362_MASK_CV,
				  sel << MT6362_SHFT_CV);
}

static int mt6362_get_charging_status(struct mt6362_chg_data *cdata,
				      enum mt6362_ic_stat *ic_stat)
{
	int ret;
	u8 regval = 0;

	ret = mt6362_read_byte(cdata, MT6362_REG_CHG_STAT, &regval);
	if (ret < 0)
		return ret;
	*ic_stat = (regval & MT6362_MASK_IC_STAT) >> MT6362_SHFT_IC_STAT;
	return ret;
}

static int mt6362_get_mivr(struct mt6362_chg_data *cdata, u32 *mivr)
{
	int ret;
	u8 regval = 0;

	ret = mt6362_read_byte(cdata, MT6362_REG_CHG_MIVR, &regval);
	if (ret < 0)
		return ret;
	regval = (regval & MT6362_MASK_MIVR) >> MT6362_SHFT_MIVR;
	*mivr = mt6362_map_real_val(regval, MT6362_MIVR_MIN, MT6362_MIVR_MAX,
				    MT6362_MIVR_STEP);
	return 0;
}

static int mt6362_get_ieoc(struct mt6362_chg_data *cdata, u32 *ieoc)
{
	int ret;
	u8 regval = 0;

	ret = mt6362_read_byte(cdata, MT6362_REG_CHG_EOC, &regval);
	if (ret < 0)
		return ret;
	regval = (regval & MT6362_MASK_IEOC) >> MT6362_SHFT_IEOC;
	*ieoc = mt6362_map_real_val(regval, MT6362_IEOC_MIN, MT6362_IEOC_MAX,
				    MT6362_IEOC_STEP);
	return 0;
}

static int mt6362_is_charging_enable(struct mt6362_chg_data *cdata, bool *en)
{
	int ret;
	u8 regval = 0;

	ret = mt6362_read_byte(cdata, MT6362_REG_CHG_TOP1, &regval);
	if (ret < 0)
		return ret;
	*en = (regval & MT6362_MASK_CHG_EN) ? true : false;
	return 0;
}

/* =========================================================== */
/* The following is implementation for interface of mt_charger */
/* =========================================================== */
static int mt_charger_set_ichg(struct mtk_charger_info *mchr_info, u32 ichg)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	int ret;
	u8 sel;

	dprintf(MT6362_LOG_LVL, "%s: ichg = %d\n", __func__, ichg);
	/* mapping datasheet define */
	if (ichg < 300)
		return -EINVAL;
	sel = mt6362_map_reg_sel(ichg, MT6362_CC_MIN, MT6362_CC_MAX,
				 MT6362_CC_STEP);
	ret = mt6362_update_bits(cdata,
				 MT6362_REG_CHG_ICHG,
				 MT6362_MASK_CC,
				 sel << MT6362_SHFT_CC);
	if (ret < 0)
		dprintf(CRITICAL, "%s: fail\n", __func__);
	else
		cdata->ichg = ichg;
	return ret;
}

static int mt_charger_enable_charging(struct mtk_charger_info *mchr_info,
				      bool en)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	u32 ichg_ramp_t = 0;
	int ret;

	/* Workaround for vsys overshoot */
	if (cdata->ichg < 500) {
		dprintf(CRITICAL,
			"%s: ichg < 500mA, bypass vsys wkard\n", __func__);
		goto out;
	}
	if (!en) {
		cdata->ichg_dis_chg = cdata->ichg;
		ichg_ramp_t = (cdata->ichg - MT6362_CC_MIN) / MT6362_CC_STEP * 2;
		/* Set ichg to 500mA */
		ret = mt6362_update_bits(cdata,
					 MT6362_REG_CHG_ICHG,
					 MT6362_MASK_CC,
					 0x0A << MT6362_SHFT_CC);
		if (ret < 0) {
			dprintf(CRITICAL,
				"%s: set ichg 500mA fail\n", __func__);
			goto vsys_wkard_fail;
		}
		mdelay(ichg_ramp_t);
	} else {
		if (cdata->ichg == cdata->ichg_dis_chg) {
			ret = mt_charger_set_ichg(&cdata->mchr_info, cdata->ichg);
			if (ret < 0)
				dprintf(CRITICAL,
					"%s: recover ichg fail\n", __func__);
		}
	}
out:
	ret = (en ? mt6362_set_bits : mt6362_clr_bits)
		(cdata, MT6362_REG_CHG_TOP1, MT6362_MASK_CHG_EN);
	if (ret < 0)
		dprintf(CRITICAL, "%s: fail\n", __func__);
vsys_wkard_fail:
	return ret;
}

static int mt_charger_get_ichg(struct mtk_charger_info *mchr_info, u32 *ichg)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	int ret;
	u8 regval = 0;

	ret = mt6362_read_byte(cdata, MT6362_REG_CHG_ICHG, &regval);
	if (ret < 0)
		return ret;
	regval = (regval & MT6362_MASK_CC) >> MT6362_SHFT_CC;
	*ichg = mt6362_map_real_val(regval, MT6362_CC_MIN, MT6362_CC_MAX,
				    MT6362_CC_STEP);
	return 0;
}

static int mt_charger_set_iprec(struct mtk_charger_info *mchr_info, u32 iprec)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	u8 sel;

	dprintf(MT6362_LOG_LVL, "%s: iprec = %d\n", __func__, iprec);
	sel = mt6362_map_reg_sel(iprec,
				 MT6362_IPREC_MIN,
				 MT6362_IPREC_MAX,
				 MT6362_IPREC_STEP);
	return mt6362_update_bits(cdata,
				  MT6362_REG_CHG_PREC,
				  MT6362_MASK_IPREC,
				  sel << MT6362_SHFT_IPREC);
}

static int mt_charger_get_aicr(struct mtk_charger_info *mchr_info, u32 *aicr)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	int ret;
	u8 regval = 0;

	ret = mt6362_read_byte(cdata, MT6362_REG_CHG_AICR, &regval);
	if (ret < 0)
		return ret;
	regval = (regval & MT6362_MASK_AICR) >> MT6362_SHFT_AICR;
	*aicr = mt6362_map_real_val(regval,
				    MT6362_AICR_MIN,
				    MT6362_AICR_MAX,
				    MT6362_AICR_STEP);
	return 0;
}

static int mt_charger_set_aicr(struct mtk_charger_info *mchr_info, u32 aicr)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	u8 sel;

	dprintf(MT6362_LOG_LVL, "%s: aicr = %d\n", __func__, aicr);
	sel = mt6362_map_reg_sel(aicr, MT6362_AICR_MIN, MT6362_AICR_MAX,
				 MT6362_AICR_STEP);
	return mt6362_update_bits(cdata,
				  MT6362_REG_CHG_AICR,
				  MT6362_MASK_AICR,
				  sel << MT6362_SHFT_AICR);
}

#define MT6362_IAICR_525mA	(0x13)
static int mt6362_adc_get_process_val(struct mt6362_chg_data *cdata,
				      enum mt6362_adc_channel chan, u32 *val)
{
	int ret;
	u8 regval = 0;

	switch (chan) {
	case MT6362_ADC_VBUSDIV5:
		*val *= 6250;
		break;
	case MT6362_ADC_VSYS:
	case MT6362_ADC_VBAT:
		*val *= 1250;
		break;
	case MT6362_ADC_IBUS:
		ret = mt6362_read_byte(cdata, MT6362_REG_CHG_AICR, &regval);
		if (ret < 0)
			return ret;
		regval = (regval & MT6362_MASK_AICR) >> MT6362_SHFT_AICR;
		if (regval < MT6362_IAICR_525mA)
			*val *= 1900;
		else
			*val *= 2500;
		break;
	case MT6362_ADC_IBAT:
		*val *= 2500;
		break;
	case MT6362_ADC_CHG_VDDP:
		*val *= 1250;
		break;
	case MT6362_ADC_TEMP_JC:
		*val -= 64;
		break;
	case MT6362_ADC_VREF_TS:
	case MT6362_ADC_TS:
		*val *= 1250;
		break;
	default:
		break;
	}
	return 0;
}

static int mt_charger_get_adc(struct mtk_charger_info *mchr_info,
			      int chan, u32 *val)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	int i, ret,  max_retry_cnt = 2;
	u8 oneshot_ch, regval = 0, rpt[2] = {0};
	u16 rpt_addr;

	dprintf(MT6362_LOG_LVL, "%s\n", __func__);
	/* config onshot channel and irq reported channel */
	oneshot_ch = (chan << MT6362_SHFT_ADC_ONESHOT_SEL);
	oneshot_ch |= (chan << MT6362_SHFT_ADC_DONE_IRQ_SEL);
	ret = mt6362_write_byte(cdata, MT6362_REG_ADCCFG3, oneshot_ch);
	if (ret < 0)
		return ret;

	for (i = 0; i < max_retry_cnt; i++) {
		mdelay(1);
		/* read adc conversion done event */
		ret = mt6362_read_byte(cdata, MT6362_REG_ADC_IRQ, &regval);
		if (ret < 0)
			goto err_adc_conv;
		if (!(regval & MT6362_MASK_ADC_DONEI))
			continue;
		/* read adc report */
		rpt_addr = MT6362_CHRPT_BASEADDR + (chan - 1) * 2;
		ret = mt6362_write_byte(cdata, rpt_addr, 0);
		if (ret < 0)
			goto err_adc_conv;
		ret = mt6362_block_read(cdata, rpt_addr, rpt, 2);
		if (ret < 0)
			goto err_adc_conv;
		*val = ((rpt[0] << 8) | rpt[1]);
		mt6362_adc_get_process_val(cdata, chan, val);
		break;
	}
	if (i == max_retry_cnt) {
		dprintf(CRITICAL, "%s: reach adc retry cnt\n", __func__);
		ret = -EBUSY;
	}
	dprintf(MT6362_LOG_LVL, "%s: val = %d\n", __func__, *val);
err_adc_conv:
	mt6362_set_bits(cdata, MT6362_REG_ADC_IRQ, MT6362_MASK_ADC_DONEI);
	return ret;
}

static int mt_charger_get_vbus(struct mtk_charger_info *mchr_info, u32 *vbus)
{
	return mt_charger_get_adc(mchr_info, MT6362_ADC_VBUSDIV5, vbus);
}

static int mt_charger_set_mivr(struct mtk_charger_info *mchr_info, u32 mivr)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	u8 sel;

	dprintf(MT6362_LOG_LVL, "%s: mivr = %d\n", __func__, mivr);
	sel = mt6362_map_reg_sel(mivr, MT6362_MIVR_MIN, MT6362_MIVR_MAX,
				 MT6362_MIVR_STEP);
	return mt6362_update_bits(cdata,
				  MT6362_REG_CHG_MIVR,
				  MT6362_MASK_MIVR,
				  sel << MT6362_SHFT_MIVR);
}

static int mt_charger_enable_power_path(struct mtk_charger_info *mchr_info,
					bool en)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;

	dprintf(MT6362_LOG_LVL, "%s: en = %d\n", __func__, en);
	return (en ? mt6362_set_bits : mt6362_clr_bits)
		(cdata, MT6362_REG_CHG_TOP1, MT6362_MASK_CHG_BUCK_EN);
}

static int mt_charger_reset_pumpx(struct mtk_charger_info *mchr_info, bool en)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;

	if (en)
		mt_charger_get_aicr(mchr_info, &cdata->aicr);
	return mt_charger_set_aicr(mchr_info, en ? 100 : cdata->aicr);
}

static int mt_charger_enable_wdt(struct mtk_charger_info *mchr_info, bool en)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;

	dprintf(MT6362_LOG_LVL, "%s: en = %d\n", __func__, en);
	return (en ? mt6362_set_bits : mt6362_clr_bits)
		(cdata, MT6362_REG_CHG_WDT, MT6362_MASK_WDT_EN);
}

static int mt_charger_dump_register(struct mtk_charger_info *mchr_info)
{
	struct mt6362_chg_data *cdata = (struct mt6362_chg_data *)mchr_info;
	enum mt6362_ic_stat ic_stat = MT6362_STAT_HZ;
	u32 ichg = 0, aicr = 0, mivr = 0, ieoc = 0;
	bool chg_en = 0;
	int ret;

	ret = mt_charger_get_ichg(mchr_info, &ichg);
	ret |= mt_charger_get_aicr(mchr_info, &aicr);
	ret |= mt6362_get_mivr(cdata, &mivr);
	ret |= mt6362_get_ieoc(cdata, &ieoc);
	ret |= mt6362_is_charging_enable(cdata, &chg_en);
	ret |= mt6362_get_charging_status(cdata, &ic_stat);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: fail\n", __func__);
		return ret;
	}
	dprintf(CRITICAL,
		"%s: ICHG = %dmA, AICR = %dmA, MIVR = %dmV, IEOC = %dmA\n",
		__func__, ichg, aicr, mivr, ieoc);
	dprintf(CRITICAL, "%s: CHG_EN = %d, CHG_STATUS = %s\n",
		__func__, chg_en, mt6362_ic_stat_list[ic_stat]);
	return ret;
}

static struct mtk_charger_ops mt6362_mchr_ops = {
	.dump_register = mt_charger_dump_register,
	.enable_charging = mt_charger_enable_charging,
	.get_ichg = mt_charger_get_ichg,
	.set_ichg = mt_charger_set_ichg,
	.get_aicr = mt_charger_get_aicr,
	.set_aicr = mt_charger_set_aicr,
	.get_adc = mt_charger_get_adc,
	.get_vbus = mt_charger_get_vbus,
	.set_mivr = mt_charger_set_mivr,
	.enable_power_path = mt_charger_enable_power_path,
	.reset_pumpx = mt_charger_reset_pumpx,
	.enable_wdt = mt_charger_enable_wdt,
};

/* Info of primary charger */
static struct mt6362_chg_data g_cdata = {
	.mchr_info = {
		.name = "primary_charger",
		.device_id = -1,
		.mchr_ops = &mt6362_mchr_ops,
	},
	.last_access_addr = U32_MAX,
	.last_access_tick = 0,
	.vid = 0x00,
	.iprec = 150,
	.ichg = 500,
	.ichg_dis_chg = 500,
	.aicr = 500,
	.mivr = 4500,
	.cv = 4350,
};

static int mt6362_chg_init_setting(struct mt6362_chg_data *cdata)
{
	int ret = 0;

	dprintf(CRITICAL, "%s\n", __func__);
	ret = mt_charger_set_aicr(&cdata->mchr_info, cdata->aicr);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: set aicr failed\n", __func__);
		return ret;
	}
	mdelay(5);
	/* Disable HW iinlimit, use SW */
	ret = mt6362_enable_ilim(cdata, false);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: disable ilim failed\n", __func__);
		return ret;
	}
	ret = mt_charger_set_iprec(&cdata->mchr_info, cdata->iprec);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: set iprec failed\n", __func__);
		return ret;
	}
	ret = mt_charger_set_ichg(&cdata->mchr_info, cdata->ichg);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: set ichg failed\n", __func__);
		return ret;
	}
	ret = mt_charger_set_mivr(&cdata->mchr_info, cdata->mivr);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: set mivr failed\n", __func__);
		return ret;
	}
	ret = mt6362_set_cv(cdata, cdata->cv);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: set cv failed\n", __func__);
		return ret;
	}
	/* Set switch frequency to 1.5->1 MHz for buck efficiency */
	ret = mt6362_update_bits(cdata,
				 MT6362_REG_CHG_TOP2,
				 MT6362_MASK_SEL_CLK_FREQ,
				 MT6362_CLK_FREQ_1000K <<
					MT6362_SHFT_SEL_CLK_FREQ);
	if (ret < 0)
		dprintf(CRITICAL, "%s: set sw freq 1M failed\n", __func__);
	ret = mt6362_enable_hidden_mode(cdata, true);
	if (ret < 0)
		return ret;
	/* Set comp diode to 1 for avoid inrush current */
	ret = mt6362_update_bits(cdata,
				 MT6362_REG_CHG_DUMMY0,
				 MT6362_MASK_COMP_CLAMP,
				 0 << MT6362_SHFT_COMP_CLAMP);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: set comp diode 1 failed\n", __func__);
		goto out;
	}
	/* Set buck_ramp offset 300->330 mV */
	/* not to enter psk mode when charging in hv and low loading */
	ret = mt6362_update_bits(cdata,
				 MT6362_REG_CHG_HD_BUCK5,
				 MT6362_MASK_BUCK_RAMPOFT,
				 0x1 << MT6362_SHFT_BUCK_RAMPOFT);
	if (ret < 0) {
		dprintf(CRITICAL,
			"%s: fail to set buck ramp offset 330 mV\n", __func__);
		goto out;
	}
out:
	mt6362_enable_hidden_mode(cdata, false);
	return ret;
}

int pd_reset_adapter(void)
{
	int ret;

	dprintf(CRITICAL, "%s: ++\n", __func__);
	/* SHIPPING off */
	ret = mt6362_set_bits(&g_cdata, MT6362_REG_SYSCTRL1,
			      MT6362_MASK_SHIPPING_OFF);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: shipping mode off fail\n", __func__);
		return ret;
	}
	/* Set CC (open, open) */
	ret = mt6362_set_bits(&g_cdata, TCPC_V10_REG_ROLE_CTRL, 0x0F);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: set cc open fail\n", __func__);
		return ret;
	}
	mdelay(300);
	/* SHIPPING on */
	ret = mt6362_clr_bits(&g_cdata, MT6362_REG_SYSCTRL1,
			      MT6362_MASK_SHIPPING_OFF);
	if (ret < 0)
		dprintf(CRITICAL, "%s: shipping mode on fail\n", __func__);
	dprintf(CRITICAL, "%s: --\n", __func__);
	return ret;
}

int mt6362_chg_probe(void)
{
	int ret = 0;

	dprintf(CRITICAL, "%s: %s\n",
		__func__, MT6362_PMU_CHARGER_LK_DRV_VERSION);
	/* get spmi device */
	g_cdata.sdev = get_spmi_device(SPMI_MASTER_1, SPMI_SLAVE_9);
	if (!g_cdata.sdev) {
		dprintf(CRITICAL, "%s: get spmi device fail\n", __func__);
		return ret;
	}
	/* check hw exist */
	if (!mt6362_is_hw_exist(&g_cdata))
		return -ENODEV;
	ret = mt6362_chg_init_setting(&g_cdata);
	if (ret < 0) {
		dprintf(CRITICAL, "%s: init setting fail\n", __func__);
		return ret;
	}
	ret = mtk_charger_set_info(&g_cdata.mchr_info);
	if (ret < 0)
		dprintf(CRITICAL, "%s: add mtk chg info list fail\n", __func__);
	return ret;
}

/*
 * Revision Note
 * 1.0.1
 * (1) fix spmi w/r need 3us delay with same register
 * (2) fix get spmi device in spmi master channel 1
 * (3) set initial setting ichg 500mA for decrease vsys overshoot delay
 *
 * 1.0.0
 * (1) Initial release
 */
