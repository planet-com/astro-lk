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

#include <platform/mt_typedefs.h>
#include <platform/mt_pmic.h>
#include <platform/mt_pmic_dlpt.h>
#include <platform/mt_gpt.h>
#include <platform/boot_mode.h>
#include <platform/mt_gpio.h>
#include <printf.h>
#include <platform/upmu_common.h>
#ifdef MTK_CHARGER_NEW_ARCH
#include <mtk_charger.h>
#include <mtk_battery.h>
#endif
#include <libfdt.h>

/* CNT_SEL = 1/2/4/8 times; PRD_SEL = 6/8/10/12 ms */
#define IMP_CNT_SEL 0
#define IMP_PRD_SEL 0

static unsigned short cnt_table[4] = {1, 2, 4, 8};
static unsigned short prd_table[4] = {6, 8, 10, 12};

/*****************************************************************************
 *  Extern Variable
 ****************************************************************************/
int imix_r = 170;

/*****************************************************************************
 *  Global Variable
 ****************************************************************************/
static unsigned int count_time_out_adc_imp = 30;
static unsigned int vbat_r_val;

/*****************************************************************************
 *  DLPT service
 ****************************************************************************/
static void ptim_timeout_dump(void)
{
	/* AUXADC IMP register dump */
	dprintf(CRITICAL, "AUXADC_IMP_EN=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_EN));
	dprintf(CRITICAL, "AUXADC_IMPEDANCE_IRQ_STATUS=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_IRQ_STATUS));
	dprintf(CRITICAL, "AUXADC_IMPEDANCE_CHSEL=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_CHSEL));
	dprintf(CRITICAL, "AUXADC_IMP_CNT_SEL=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_CNT_SEL));
	dprintf(CRITICAL, "AUXADC_IMP_PRD_SEL=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_PRD_SEL));
	dprintf(CRITICAL, "AUXADC_IMP_START=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_START));
	dprintf(CRITICAL, "AUXADC_IMP_STATE=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_STATE));
	dprintf(CRITICAL, "AUXADC_IMP_COUNT=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_COUNT));
	dprintf(CRITICAL, "AUXADC_IMP_FGADC_R_S=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_FGADC_R_S));
	dprintf(CRITICAL, "FGADC_AUXADC_IMP_R_DONE_S=0x%x\n",
		pmic_get_register_value(PMIC_FGADC_AUXADC_IMP_R_DONE_S));
	dprintf(CRITICAL, "AUXADC_ADC_RDY_IMP=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_ADC_RDY_IMP));
	dprintf(CRITICAL, "AUXADC_ADC_OUT_IMP=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_ADC_OUT_IMP));
	dprintf(CRITICAL, "AUXADC_ADC_RDY_IMP_AVG=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_ADC_RDY_IMP_AVG));
	dprintf(CRITICAL, "AUXADC_ADC_OUT_IMP_AVG=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_ADC_OUT_IMP_AVG));
	dprintf(CRITICAL, "AUXADC_ADC_BUSY_IN_IMP=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_ADC_BUSY_IN_IMP));
	dprintf(CRITICAL, "AUXADC_IMP_CK_SW_MODE=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_CK_SW_MODE));
	dprintf(CRITICAL, "AUXADC_IMP_CK_SW_EN=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_IMP_CK_SW_EN));

	/* AUXADC CLK/RST register dump */
	dprintf(CRITICAL, "RG_AUXADC_26M_CK_PDN_HWEN=0x%x\n",
		pmic_get_register_value(PMIC_RG_AUXADC_26M_CK_PDN_HWEN));
	dprintf(CRITICAL, "RG_AUXADC_26M_CK_PDN=0x%x\n",
		pmic_get_register_value(PMIC_RG_AUXADC_26M_CK_PDN));
	dprintf(CRITICAL, "RG_AUXADC_CK_PDN_HWEN=0x%x\n",
		pmic_get_register_value(PMIC_RG_AUXADC_CK_PDN_HWEN));
	dprintf(CRITICAL, "RG_AUXADC_CK_PDN=0x%x\n",
		pmic_get_register_value(PMIC_RG_AUXADC_CK_PDN));
	dprintf(CRITICAL, "RG_AUXADC_RNG_CK_PDN_HWEN=0x%x\n",
		pmic_get_register_value(PMIC_RG_AUXADC_RNG_CK_PDN_HWEN));
	dprintf(CRITICAL, "RG_AUXADC_RNG_CK_PDN=0x%x\n",
		pmic_get_register_value(PMIC_RG_AUXADC_RNG_CK_PDN));
	dprintf(CRITICAL, "RG_AUXADC_1M_CK_PDN=0x%x\n",
		pmic_get_register_value(PMIC_RG_AUXADC_1M_CK_PDN));
	dprintf(CRITICAL, "RG_AUXADC_32K_CK_PDN=0x%x\n",
		pmic_get_register_value(PMIC_RG_AUXADC_32K_CK_PDN));
	dprintf(CRITICAL, "RG_HK_INTRP_CK_PDN_HWEN=0x%x\n",
		pmic_get_register_value(PMIC_RG_HK_INTRP_CK_PDN_HWEN));
	dprintf(CRITICAL, "RG_HK_INTRP_CK_PDN=0x%x\n",
		pmic_get_register_value(PMIC_RG_HK_INTRP_CK_PDN));
	dprintf(CRITICAL, "AUXADC_CK_AON=0x%x\n",
		pmic_get_register_value(PMIC_AUXADC_CK_AON));
	dprintf(CRITICAL, "RG_HK_STRUP_AUXADC_RSTB_SEL=0x%x\n",
		pmic_get_register_value(PMIC_RG_HK_STRUP_AUXADC_RSTB_SEL));
	dprintf(CRITICAL, "RG_HK_STRUP_AUXADC_RSTB_SW=0x%x\n",
		pmic_get_register_value(PMIC_RG_HK_STRUP_AUXADC_RSTB_SW));
}

void do_ptim(unsigned int *bat, signed int *cur)
{
	unsigned int vbat_reg;
	unsigned int count_adc_imp = 0;

	/* start setting */
	pmic_set_register_value(PMIC_AUXADC_IMP_EN, 1);

	/* wait IMPEDANCE to start measurement */
	mdelay(cnt_table[IMP_CNT_SEL] * prd_table[IMP_PRD_SEL]);

	/* polling IRQ status */
	while (pmic_get_register_value(PMIC_AUXADC_IMPEDANCE_IRQ_STATUS) == 0) {
		if (count_adc_imp > count_time_out_adc_imp) {
			dprintf(CRITICAL, "do_ptim over %d times/ms\n",
				count_time_out_adc_imp);
			ptim_timeout_dump();
			break;
		}
		count_adc_imp++;
		mdelay(1);
	}
	vbat_reg = pmic_get_register_value(PMIC_AUXADC_ADC_OUT_IMP);

	/* stop setting */
	pmic_set_register_value(PMIC_AUXADC_IMP_EN, 0);

	/* V = (reg_val * r_val / 10 * 18000) >> resolution */
	if (count_adc_imp <= count_time_out_adc_imp)
		*bat = (vbat_reg * vbat_r_val * 1800) >> 15;
	else {
		if (is_isense_supported() && is_power_path_supported())
			*bat = pmic_get_auxadc_value(AUXADC_LIST_ISENSE) * 10;
		else
			*bat = pmic_get_auxadc_value(AUXADC_LIST_BATADC) * 10;
	}

	gauge_read_IM_current((void *)cur);

	dprintf(INFO, "[do_ptim] bat %d cur %d in %dms\n",
		*bat, *cur, count_adc_imp);
}

void do_ptim_gauge(unsigned int *bat, signed int *cur)
{
	unsigned int ptim_bat_vol = 0;
	signed int ptim_R_curr = 0;
	unsigned int volt[5] = {0};
	int curr[5] = {0};
	int i, j;
	int arraySize = sizeof(volt)/sizeof(volt[0]);

	for (i = 0; i < arraySize; i++) {
		do_ptim(&ptim_bat_vol, &ptim_R_curr);

		/* insertion sort */
		for (j = i; j > 0; j--) {
			if (ptim_bat_vol < volt[j - 1])
				volt[j] = volt[j - 1];
			else
				break;
		}
		volt[j] = ptim_bat_vol;

		/* insertion sort */
		for (j = i; j > 0; j--) {
			if (ptim_R_curr < curr[j - 1])
				curr[j] = curr[j - 1];
			else
				break;
		}
		curr[j] = ptim_R_curr;
	}

	*bat = volt[arraySize >> 1];
	*cur = curr[arraySize >> 1];
	dprintf(CRITICAL, "%s, %d(%d, %d, %d, %d, %d), %d(%d, %d, %d, %d, %d)\n",
		__func__, *bat, volt[0], volt[1], volt[2], volt[3], volt[4],
		*cur, curr[0], curr[1], curr[2], curr[3], curr[4]);
}

static void enable_dummy_load(unsigned int en)
{
	if (en == 1) {
		/* enable isink step */
		pmic_set_register_value(PMIC_ISINK_CH0_STEP, 0x7);
		pmic_set_register_value(PMIC_ISINK_CH1_STEP, 0x7);

		/* enable isink */
		pmic_set_register_value(PMIC_ISINK_CH0_BIAS_EN, 0x1);
		pmic_set_register_value(PMIC_ISINK_CH1_BIAS_EN, 0x1);
		pmic_set_register_value(PMIC_ISINK_CH0_EN, 0x1);
		pmic_set_register_value(PMIC_ISINK_CH1_EN, 0x1);
		/*PMICLOG("[enable dummy load]\n"); */
	} else {
		/* disable isink */
		pmic_set_register_value(PMIC_ISINK_CH0_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH1_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH0_BIAS_EN, 0);
		pmic_set_register_value(PMIC_ISINK_CH1_BIAS_EN, 0);
		/*PMICLOG("[disable dummy load]\n"); */
	}
}

static int get_rac_val(void)
{
	unsigned int ptim_bat_vol = 0;
	signed int ptim_R_curr = 0;
	int volt_1, volt_2;
	int curr_1, curr_2;
	int rac_cal = 0;
	int ret = 0;
	bool retry_state = false;
	int retry_count = 0;

	do {
		/* Trigger ADC PTIM mode to get VBAT and current */
		do_ptim(&ptim_bat_vol, &ptim_R_curr);
		volt_1 = ptim_bat_vol;
		curr_1 = ptim_R_curr;

		/* enable dummy load */
		enable_dummy_load(1);
		mdelay(2);
		/* Wait */

		/* Trigger ADC PTIM mode again to get new VBAT and current */
		do_ptim(&ptim_bat_vol, &ptim_R_curr);
		volt_2 = ptim_bat_vol;
		curr_2 = ptim_R_curr;

		/* disable dummy load */
		enable_dummy_load(0);
		mdelay(2);

		/* Calculate Rac */
		if ((curr_2 - curr_1) >= 700 && (curr_2 - curr_1) <= 1200
		    && (volt_1 - volt_2) >= 40 && (volt_1 - volt_2) <= 2000) {
			/*40.0mA */
			rac_cal = ((volt_1 - volt_2) * 1000) / (curr_2 - curr_1);	/*m-ohm */

			if (rac_cal < 0)
				ret = (rac_cal - (rac_cal * 2)) * 1;
			else
				ret = rac_cal * 1;
			if (ret < 50) {
				ret = -1;
				dprintf(CRITICAL, "[Calculate Rac] bypass due to Rac < 50mOhm\n");
			}
		} else {
			ret = -1;
			dprintf(CRITICAL, "[Calculate Rac] bypass due to c_diff < 70mA\n");
		}

		dprintf(INFO, "v1=%d,v2=%d,c1=%d,c2=%d,rac_cal=%d,ret=%d,retry=%d,v_diff=%d,c_diff=%d\n",
			volt_1, volt_2, curr_1, curr_2, rac_cal, ret,
			retry_count, (volt_1 - volt_2), (curr_2 - curr_1));

		retry_count++;

		if ((retry_count < 3) && (ret == -1))
			retry_state = true;
		else
			retry_state = false;

	} while (retry_state == true);

	return ret;
}

void set_fdt_pmic_imix_r(void *fdt)
{
    int offset = 0, ret = 0;

    offset = fdt_node_offset_by_compatible(fdt, -1,
					   "mediatek,pmic-auxadc");
    if (offset < 0) {
        dprintf(CRITICAL, "pmic-auxadc node not found, ret=%d\n", offset);
        return;
    }
    offset = fdt_subnode_offset(fdt, offset, "imix_r");
    if (offset < 0) {
        dprintf(CRITICAL, "imix_r node not found, ret=%d\n", offset);
        return;
    }
    ret = fdt_setprop_u32(fdt, offset, "val", imix_r);
    if (ret) {
        dprintf(CRITICAL, "imix_r setprop failed, ret=%d\n", ret);
        return;
    }
}


void get_dlpt_imix_r(void)
{
	int rac_val[5], rac_val_sum = 0;
	int i;
	int validcnt = 0;
	int min = 1000, max = 0;

	/* if fast meta mode detected, skip DLPT to speed up */
	if ((g_boot_mode == META_BOOT) && !mt_get_gpio_in(g_boot_arg->fast_meta_gpio))
		return;
#ifdef MTK_CHARGER_NEW_ARCH
	if(is_disable_charger())
		return;
	charger_enable_charging(false);
	charger_enable_power_path(false);
	mdelay(50);
#endif

	for (i = 0; i < 5; i++) {
		rac_val[i] = get_rac_val();
		if (rac_val[i] <= min && rac_val[i] != -1)
			min = rac_val[i];
		if (rac_val[i] >= max)
			max = rac_val[i];
		if (rac_val[i] != -1) {
			rac_val_sum += rac_val[i];
			validcnt++;
		}
	}

	if (validcnt >= 4) {
		rac_val_sum = rac_val_sum - min - max;
		imix_r = rac_val_sum / (validcnt - 2);
	} else if (validcnt != 0) {
		imix_r = rac_val_sum / validcnt;
	}

	dprintf(CRITICAL, "[dlpt_R] rac_val:%d,%d,%d,%d,%d [%d:%d:%d], imix_r:%d\n",
		rac_val[0], rac_val[1], rac_val[2], rac_val[3], rac_val[4],
		min, max, validcnt, imix_r);

#ifdef MTK_CHARGER_NEW_ARCH
	charger_enable_power_path(true);
	check_bat_protect_status();
	charger_enable_charging(true);
#endif
	return;
}

void pmic_dlpt_init(void)
{
	vbat_r_val = pmic_get_auxadc_r_val(AUXADC_LIST_BATADC);
	/* initial setting */
	if (is_isense_supported() && is_power_path_supported()) {
		/* For PMIC which supports ISENSE */
		pmic_set_register_value(PMIC_AUXADC_SOURCE_LBAT_SEL, 1);
		pmic_set_register_value(PMIC_AUXADC_IMPEDANCE_CHSEL, 1);
	} else {
		/* For PMIC which do not support ISENSE */
		pmic_set_register_value(PMIC_AUXADC_SOURCE_LBAT_SEL, 0);
		pmic_set_register_value(PMIC_AUXADC_IMPEDANCE_CHSEL, 0);
	}

	pmic_set_register_value(PMIC_AUXADC_IMP_CNT_SEL, IMP_CNT_SEL);
	pmic_set_register_value(PMIC_AUXADC_IMP_PRD_SEL, IMP_PRD_SEL);
}
