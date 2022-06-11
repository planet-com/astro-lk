/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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

#ifndef __MTK_DCM_AUTOGEN_H__
#define __MTK_DCM_AUTOGEN_H__

#include <mtk_dcm.h>
//#include <mt_reg_base.h>

/* Base */
#define INFRACFG_AO_BASE 0x10001000
#define INFRACFG_AO_MEM_BASE 0x10002000
#define INFRA_AO_BCRM_BASE 0x10022000
#define EMI_BASE 0x10219000
#define SUB_EMI_BASE 0x1021d000
#define CHN0_EMI_BASE 0x10235000
#define DRAMC_CH0_TOP5_BASE 0x10238000
#define CHN1_EMI_BASE 0x10245000
#define DRAMC_CH1_TOP5_BASE 0x10248000
#define CHN2_EMI_BASE 0x10255000
#define DRAMC_CH2_TOP5_BASE 0x10258000
#define CHN3_EMI_BASE 0x10265000
#define DRAMC_CH3_TOP5_BASE 0x10268000
#define SUB_INFRACFG_AO_MEM_BASE 0x1030e000
#define SSPM_BASE 0x10400000
#define AUDIO_BASE 0x11210000
#define MP_CPUSYS_TOP_BASE 0xc538000
#define CPCCFG_REG_BASE 0xc53a800

/* Register Definition */
#define MP_CPUSYS_TOP_CPU_PLLDIV_CFG0 (MP_CPUSYS_TOP_BASE + 0x22a0)
#define MP_CPUSYS_TOP_CPU_PLLDIV_CFG1 (MP_CPUSYS_TOP_BASE + 0x22a4)
#define MP_CPUSYS_TOP_CPU_PLLDIV_CFG2 (MP_CPUSYS_TOP_BASE + 0x22a8)
#define MP_CPUSYS_TOP_CPU_PLLDIV_CFG3 (MP_CPUSYS_TOP_BASE + 0x22ac)
#define MP_CPUSYS_TOP_CPU_PLLDIV_CFG4 (MP_CPUSYS_TOP_BASE + 0x22b0)
#define MP_CPUSYS_TOP_BUS_PLLDIV_CFG (MP_CPUSYS_TOP_BASE + 0x22e0)
#define MP_CPUSYS_TOP_MCSIC_DCM0 (MP_CPUSYS_TOP_BASE + 0x2440)
#define MP_CPUSYS_TOP_MP_ADB_DCM_CFG0 (MP_CPUSYS_TOP_BASE + 0x2500)
#define MP_CPUSYS_TOP_MP_ADB_DCM_CFG4 (MP_CPUSYS_TOP_BASE + 0x2510)
#define MP_CPUSYS_TOP_MP_MISC_DCM_CFG0 (MP_CPUSYS_TOP_BASE + 0x2518)
#define MP_CPUSYS_TOP_MCUSYS_DCM_CFG0 (MP_CPUSYS_TOP_BASE + 0x25c0)
#define CPCCFG_REG_EMI_WFIFO (CPCCFG_REG_BASE + 0x100)
#define MP_CPUSYS_TOP_MP0_DCM_CFG0 (MP_CPUSYS_TOP_BASE + 0x4880)
#define MP_CPUSYS_TOP_MP0_DCM_CFG7 (MP_CPUSYS_TOP_BASE + 0x489c)
#define INFRA_EMI_DCM_CFG0 (INFRACFG_AO_MEM_BASE + 0x28)
#define INFRA_EMI_DCM_CFG1 (INFRACFG_AO_MEM_BASE + 0x2c)
#define INFRA_EMI_DCM_CFG2 (INFRACFG_AO_MEM_BASE + 0x30)
#define TOP_CK_ANCHOR_CFG (INFRACFG_AO_MEM_BASE + 0x38)
#define INFRA_EMI_IDLE_BIT_EN_0 (INFRACFG_AO_MEM_BASE + 0x100)
#define INFRA_EMI_IDLE_BIT_EN_1 (INFRACFG_AO_MEM_BASE + 0x104)
#define INFRA_EMI_IDLE_BIT_EN_2 (INFRACFG_AO_MEM_BASE + 0x108)
#define INFRA_EMI_IDLE_BIT_EN_3 (INFRACFG_AO_MEM_BASE + 0x10c)
#define INFRA_EMI_M0M1_IDLE_BIT_EN_0 (INFRACFG_AO_MEM_BASE + 0x110)
#define INFRA_EMI_M0M1_IDLE_BIT_EN_1 (INFRACFG_AO_MEM_BASE + 0x114)
#define INFRA_EMI_M0M1_IDLE_BIT_EN_2 (INFRACFG_AO_MEM_BASE + 0x118)
#define INFRA_EMI_M0M1_IDLE_BIT_EN_3 (INFRACFG_AO_MEM_BASE + 0x11c)
#define INFRA_EMI_M2M5_IDLE_BIT_EN_0 (INFRACFG_AO_MEM_BASE + 0x120)
#define INFRA_EMI_M2M5_IDLE_BIT_EN_1 (INFRACFG_AO_MEM_BASE + 0x124)
#define INFRA_EMI_M2M5_IDLE_BIT_EN_2 (INFRACFG_AO_MEM_BASE + 0x128)
#define INFRA_EMI_M2M5_IDLE_BIT_EN_3 (INFRACFG_AO_MEM_BASE + 0x12c)
#define INFRA_EMI_M3_IDLE_BIT_EN_0 (INFRACFG_AO_MEM_BASE + 0x130)
#define INFRA_EMI_M3_IDLE_BIT_EN_1 (INFRACFG_AO_MEM_BASE + 0x134)
#define INFRA_EMI_M3_IDLE_BIT_EN_2 (INFRACFG_AO_MEM_BASE + 0x138)
#define INFRA_EMI_M3_IDLE_BIT_EN_3 (INFRACFG_AO_MEM_BASE + 0x13c)
#define INFRA_EMI_M4_IDLE_BIT_EN_0 (INFRACFG_AO_MEM_BASE + 0x140)
#define INFRA_EMI_M4_IDLE_BIT_EN_1 (INFRACFG_AO_MEM_BASE + 0x144)
#define INFRA_EMI_M4_IDLE_BIT_EN_2 (INFRACFG_AO_MEM_BASE + 0x148)
#define INFRA_EMI_M4_IDLE_BIT_EN_3 (INFRACFG_AO_MEM_BASE + 0x14c)
#define INFRA_EMI_M6M7_IDLE_BIT_EN_0 (INFRACFG_AO_MEM_BASE + 0x150)
#define INFRA_EMI_M6M7_IDLE_BIT_EN_1 (INFRACFG_AO_MEM_BASE + 0x154)
#define INFRA_EMI_M6M7_IDLE_BIT_EN_2 (INFRACFG_AO_MEM_BASE + 0x158)
#define INFRA_EMI_M6M7_IDLE_BIT_EN_3 (INFRACFG_AO_MEM_BASE + 0x15c)
#define INFRA_EMI_SRAM_IDLE_BIT_EN_0 (INFRACFG_AO_MEM_BASE + 0x160)
#define INFRA_EMI_SRAM_IDLE_BIT_EN_1 (INFRACFG_AO_MEM_BASE + 0x164)
#define INFRA_EMI_SRAM_IDLE_BIT_EN_2 (INFRACFG_AO_MEM_BASE + 0x168)
#define INFRA_EMI_SRAM_IDLE_BIT_EN_3 (INFRACFG_AO_MEM_BASE + 0x16c)
#define VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_0 (INFRA_AO_BCRM_BASE + 0x38)
#define VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_1 (INFRA_AO_BCRM_BASE + 0x3c)
#define VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_2 (INFRA_AO_BCRM_BASE + 0x40)
#define VDNR_DCM_TOP_INFRA_PAR_BUS_u_INFRA_PAR_BUS_CTRL_13 (INFRA_AO_BCRM_BASE + 0x6c)
#define EMI_CONM (EMI_BASE + 0x60)
#define EMI_CONN (EMI_BASE + 0x68)
#define EMI_THRO_CTRL0 (EMI_BASE + 0x830)
#define SUB_EMI_EMI_CONM (SUB_EMI_BASE + 0x60)
#define SUB_EMI_EMI_CONN (SUB_EMI_BASE + 0x68)
#define SUB_EMI_EMI_THRO_CTRL0 (SUB_EMI_BASE + 0x830)
#define CHN0_EMI_CHN_EMI_CONB (CHN0_EMI_BASE + 0x8)
#define DRAMC_CH0_TOP5_MISC_CG_CTRL0 (DRAMC_CH0_TOP5_BASE + 0x4ec)
#define DRAMC_CH0_TOP5_MISC_CG_CTRL2 (DRAMC_CH0_TOP5_BASE + 0x4f4)
#define DRAMC_CH0_TOP5_MISC_DQSG_RETRY1 (DRAMC_CH0_TOP5_BASE + 0x524)
#define DRAMC_CH0_TOP5_MISC_APB (DRAMC_CH0_TOP5_BASE + 0x560)
#define DRAMC_CH0_TOP5_MISC_CTRL2 (DRAMC_CH0_TOP5_BASE + 0x644)
#define CHN1_EMI_CHN_EMI_CONB (CHN1_EMI_BASE + 0x8)
#define DRAMC_CH1_TOP5_MISC_CG_CTRL0 (DRAMC_CH1_TOP5_BASE + 0x4ec)
#define DRAMC_CH1_TOP5_MISC_CG_CTRL2 (DRAMC_CH1_TOP5_BASE + 0x4f4)
#define DRAMC_CH1_TOP5_MISC_DQSG_RETRY1 (DRAMC_CH1_TOP5_BASE + 0x524)
#define DRAMC_CH1_TOP5_MISC_APB (DRAMC_CH1_TOP5_BASE + 0x560)
#define DRAMC_CH1_TOP5_MISC_CTRL2 (DRAMC_CH1_TOP5_BASE + 0x644)
#define CHN2_EMI_CHN_EMI_CONB (CHN2_EMI_BASE + 0x8)
#define DRAMC_CH2_TOP5_MISC_CG_CTRL0 (DRAMC_CH2_TOP5_BASE + 0x4ec)
#define DRAMC_CH2_TOP5_MISC_CG_CTRL2 (DRAMC_CH2_TOP5_BASE + 0x4f4)
#define DRAMC_CH2_TOP5_MISC_DQSG_RETRY1 (DRAMC_CH2_TOP5_BASE + 0x524)
#define DRAMC_CH2_TOP5_MISC_APB (DRAMC_CH2_TOP5_BASE + 0x560)
#define DRAMC_CH2_TOP5_MISC_CTRL2 (DRAMC_CH2_TOP5_BASE + 0x644)
#define CHN3_EMI_CHN_EMI_CONB (CHN3_EMI_BASE + 0x8)
#define DRAMC_CH3_TOP5_MISC_CG_CTRL0 (DRAMC_CH3_TOP5_BASE + 0x4ec)
#define DRAMC_CH3_TOP5_MISC_CG_CTRL2 (DRAMC_CH3_TOP5_BASE + 0x4f4)
#define DRAMC_CH3_TOP5_MISC_DQSG_RETRY1 (DRAMC_CH3_TOP5_BASE + 0x524)
#define DRAMC_CH3_TOP5_MISC_APB (DRAMC_CH3_TOP5_BASE + 0x560)
#define DRAMC_CH3_TOP5_MISC_CTRL2 (DRAMC_CH3_TOP5_BASE + 0x644)
#define SUB_INFRA_EMI_IDLE_BIT_EN_0 (SUB_INFRACFG_AO_MEM_BASE + 0x20)
#define SUB_INFRA_EMI_IDLE_BIT_EN_1 (SUB_INFRACFG_AO_MEM_BASE + 0x24)
#define SUB_INFRA_EMI_DCM_CFG0 (SUB_INFRACFG_AO_MEM_BASE + 0x28)
#define SUB_INFRA_EMI_DCM_CFG1 (SUB_INFRACFG_AO_MEM_BASE + 0x2c)
#define SUB_INFRA_EMI_DCM_CFG2 (SUB_INFRACFG_AO_MEM_BASE + 0x30)
#define SUB_INFRA_EMI_M0M1_IDLE_BIT_EN_0 (SUB_INFRACFG_AO_MEM_BASE + 0x210)
#define SUB_INFRA_EMI_M0M1_IDLE_BIT_EN_1 (SUB_INFRACFG_AO_MEM_BASE + 0x214)
#define SUB_INFRA_EMI_M2M5_IDLE_BIT_EN_0 (SUB_INFRACFG_AO_MEM_BASE + 0x218)
#define SUB_INFRA_EMI_M2M5_IDLE_BIT_EN_1 (SUB_INFRACFG_AO_MEM_BASE + 0x21c)
#define SUB_INFRA_EMI_M3_IDLE_BIT_EN_0 (SUB_INFRACFG_AO_MEM_BASE + 0x220)
#define SUB_INFRA_EMI_M3_IDLE_BIT_EN_1 (SUB_INFRACFG_AO_MEM_BASE + 0x224)
#define SUB_INFRA_EMI_M4_IDLE_BIT_EN_0 (SUB_INFRACFG_AO_MEM_BASE + 0x228)
#define SUB_INFRA_EMI_M4_IDLE_BIT_EN_1 (SUB_INFRACFG_AO_MEM_BASE + 0x22c)
#define SUB_INFRA_EMI_M6M7_IDLE_BIT_EN_0 (SUB_INFRACFG_AO_MEM_BASE + 0x230)
#define SUB_INFRA_EMI_M6M7_IDLE_BIT_EN_1 (SUB_INFRACFG_AO_MEM_BASE + 0x234)
#define SUB_INFRA_EMI_VPU_IDLE_BIT_EN_0 (SUB_INFRACFG_AO_MEM_BASE + 0x238)
#define SUB_INFRA_EMI_VPU_IDLE_BIT_EN_1 (SUB_INFRACFG_AO_MEM_BASE + 0x23c)
#define SSPM_MCLK_DIV (SSPM_BASE + 0x43004)
#define SSPM_DCM_CTRL (SSPM_BASE + 0x43008)
#define AUDIO_TOP_CON0 (AUDIO_BASE + 0x0)
#define INFRA_BUS_DCM_CTRL (INFRACFG_AO_BASE + 0x70)
#define PERI_BUS_DCM_CTRL (INFRACFG_AO_BASE + 0x74)
#define P2P_RX_CLK_ON (INFRACFG_AO_BASE + 0xa0)
#define MODULE_SW_CG_2_SET (INFRACFG_AO_BASE + 0xa4)
#define MODULE_SW_CG_2_CLR (INFRACFG_AO_BASE + 0xa8)
#define INFRA_AXIMEM_IDLE_BIT_EN_0 (INFRACFG_AO_BASE + 0xa30)

/*non auto-gen base big core*/
#define DEIMOS_CPU4_BASE		(0x0C532000)
#define DEIMOS_CPU5_BASE		(0x0C532800)
#define DEIMOS_CPU6_BASE		(0x0C533000)
#define DEIMOS_CPU7_BASE		(0x0C533800)

#define CPU4_STALL_DCM_CONF		(DEIMOS_CPU4_BASE + 0x230)
#define CPU5_STALL_DCM_CONF		(DEIMOS_CPU5_BASE + 0x230)
#define CPU6_STALL_DCM_CONF		(DEIMOS_CPU6_BASE + 0x230)
#define CPU7_STALL_DCM_CONF		(DEIMOS_CPU7_BASE + 0x230)

/* INFRACFG_AO */
bool dcm_infracfg_ao_aximem_bus_dcm_is_on(void);
void dcm_infracfg_ao_aximem_bus_dcm(int on);
bool dcm_infracfg_ao_infra_bus_dcm_is_on(void);
void dcm_infracfg_ao_infra_bus_dcm(int on);
bool dcm_infracfg_ao_infra_conn_bus_dcm_is_on(void);
void dcm_infracfg_ao_infra_conn_bus_dcm(int on);
bool dcm_infracfg_ao_infra_rx_p2p_dcm_is_on(void);
void dcm_infracfg_ao_infra_rx_p2p_dcm(int on);
bool dcm_infracfg_ao_mts_bus_dcm_is_on(void);
void dcm_infracfg_ao_mts_bus_dcm(int on);
bool dcm_infracfg_ao_peri_bus_dcm_is_on(void);
void dcm_infracfg_ao_peri_bus_dcm(int on);
bool dcm_infracfg_ao_peri_module_dcm_is_on(void);
void dcm_infracfg_ao_peri_module_dcm(int on);
/* INFRACFG_AO_MEM */
bool dcm_infracfg_ao_mem_dcm_emi_group_is_on(void);
void dcm_infracfg_ao_mem_dcm_emi_group(int on);
/* INFRA_AO_BCRM */
bool dcm_infra_ao_bcrm_infra_bus_dcm_is_on(void);
void dcm_infra_ao_bcrm_infra_bus_dcm(int on);
bool dcm_infra_ao_bcrm_peri_bus_dcm_is_on(void);
void dcm_infra_ao_bcrm_peri_bus_dcm(int on);
/* EMI */
bool dcm_emi_emi_dcm_is_on(void);
void dcm_emi_emi_dcm(int on);
/* SUB_EMI */
bool dcm_sub_emi_emi_dcm_is_on(void);
void dcm_sub_emi_emi_dcm(int on);
/* CHN0_EMI */
bool dcm_chn0_emi_chn_emi_dcm_is_on(void);
void dcm_chn0_emi_chn_emi_dcm(int on);
/* DRAMC_CH0_TOP5 */
bool dcm_dramc_ch0_top5_ddrphy_is_on(void);
void dcm_dramc_ch0_top5_ddrphy(int on);
/* CHN1_EMI */
bool dcm_chn1_emi_chn_emi_dcm_is_on(void);
void dcm_chn1_emi_chn_emi_dcm(int on);
/* DRAMC_CH1_TOP5 */
bool dcm_dramc_ch1_top5_ddrphy_is_on(void);
void dcm_dramc_ch1_top5_ddrphy(int on);
/* CHN2_EMI */
bool dcm_chn2_emi_chn_emi_dcm_is_on(void);
void dcm_chn2_emi_chn_emi_dcm(int on);
/* DRAMC_CH2_TOP5 */
bool dcm_dramc_ch2_top5_ddrphy_is_on(void);
void dcm_dramc_ch2_top5_ddrphy(int on);
/* CHN3_EMI */
bool dcm_chn3_emi_chn_emi_dcm_is_on(void);
void dcm_chn3_emi_chn_emi_dcm(int on);
/* DRAMC_CH3_TOP5 */
bool dcm_dramc_ch3_top5_ddrphy_is_on(void);
void dcm_dramc_ch3_top5_ddrphy(int on);
/* SUB_INFRACFG_AO_MEM */
bool dcm_sub_infracfg_ao_mem_dcm_emi_group_is_on(void);
void dcm_sub_infracfg_ao_mem_dcm_emi_group(int on);
/* SSPM */
bool dcm_sspm_sspm_dcm_is_on(void);
void dcm_sspm_sspm_dcm(int on);
/* AUDIO */
bool dcm_audio_aud_mas_ahb_ck_dcm_is_on(void);
void dcm_audio_aud_mas_ahb_ck_dcm(int on);
/* MP_CPUSYS_TOP */
bool dcm_mp_cpusys_top_adb_dcm_is_on(void);
void dcm_mp_cpusys_top_adb_dcm(int on);
bool dcm_mp_cpusys_top_apb_dcm_is_on(void);
void dcm_mp_cpusys_top_apb_dcm(int on);
bool dcm_mp_cpusys_top_bus_pll_div_dcm_is_on(void);
void dcm_mp_cpusys_top_bus_pll_div_dcm(int on);
bool dcm_mp_cpusys_top_core_stall_dcm_is_on(void);
void dcm_mp_cpusys_top_core_stall_dcm(int on);
bool dcm_mp_cpusys_top_cpubiu_dcm_is_on(void);
void dcm_mp_cpusys_top_cpubiu_dcm(int on);
bool dcm_mp_cpusys_top_cpu_pll_div_0_dcm_is_on(void);
void dcm_mp_cpusys_top_cpu_pll_div_0_dcm(int on);
bool dcm_mp_cpusys_top_cpu_pll_div_1_dcm_is_on(void);
void dcm_mp_cpusys_top_cpu_pll_div_1_dcm(int on);
bool dcm_mp_cpusys_top_cpu_pll_div_2_dcm_is_on(void);
void dcm_mp_cpusys_top_cpu_pll_div_2_dcm(int on);
bool dcm_mp_cpusys_top_cpu_pll_div_3_dcm_is_on(void);
void dcm_mp_cpusys_top_cpu_pll_div_3_dcm(int on);
bool dcm_mp_cpusys_top_cpu_pll_div_4_dcm_is_on(void);
void dcm_mp_cpusys_top_cpu_pll_div_4_dcm(int on);
bool dcm_mp_cpusys_top_fcm_stall_dcm_is_on(void);
void dcm_mp_cpusys_top_fcm_stall_dcm(int on);
bool dcm_mp_cpusys_top_last_cor_idle_dcm_is_on(void);
void dcm_mp_cpusys_top_last_cor_idle_dcm(int on);
bool dcm_mp_cpusys_top_misc_dcm_is_on(void);
void dcm_mp_cpusys_top_misc_dcm(int on);
bool dcm_mp_cpusys_top_mp0_qdcm_is_on(void);
void dcm_mp_cpusys_top_mp0_qdcm(int on);
/* CPCCFG_REG */
bool dcm_cpccfg_reg_emi_wfifo_is_on(void);
void dcm_cpccfg_reg_emi_wfifo(int on);

#endif
