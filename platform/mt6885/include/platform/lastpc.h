/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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
#define DFD_REG_LENGTH              64
#define DFD_SW_V3_WA

//#define ENABLE_RETURN_STACK
#define SUPPORT_CACHE_DUMP

struct bit_pair { 
    unsigned int raw_offset;
    unsigned int bit_offset;
    unsigned int inv;
}; 

struct reg_collector { 
    struct bit_pair bit_pairs[DFD_REG_LENGTH]; 
}; 
struct little_core_spec {
	struct reg_collector spmc_power_state;
	struct reg_collector pc;
	struct reg_collector sp32;
	struct reg_collector fp32;
	struct reg_collector fp64;
	struct reg_collector sp_EL0;
	struct reg_collector sp_EL1;
	struct reg_collector sp_EL2;
	struct reg_collector sp_EL3;
	struct reg_collector elr_EL1;
	struct reg_collector elr_EL2;
	struct reg_collector elr_EL3;
	struct reg_collector raw_pc;
	struct reg_collector pc_iss;
	struct reg_collector full_pc_wr;
	struct reg_collector full_pc_ex1;
	struct reg_collector full_pc_ex2;
	struct reg_collector dfd_v35_enable;
	struct reg_collector return_Stack_pointer;
	struct reg_collector return_Stack0;
	struct reg_collector return_Stack1;
	struct reg_collector return_Stack2;
	struct reg_collector return_Stack3;
	struct reg_collector return_Stack4;
	struct reg_collector return_Stack5;
	struct reg_collector return_Stack6;
	struct reg_collector return_Stack7;
	struct reg_collector ECC_err0status_v;
	struct reg_collector ECC_err0status_ue;
	struct reg_collector ECC_err0status_er;
	struct reg_collector ECC_err0status_of;
	struct reg_collector ECC_err0status_mv;
	struct reg_collector ECC_err0status_ce;
	struct reg_collector ECC_err0status_de;
	struct reg_collector ECC_err0status_pn;
	struct reg_collector ECC_err0status_ierr;
	struct reg_collector ECC_err0status_serr;
	struct reg_collector ECC_err0misc_other_err_cnt_overflow;
	struct reg_collector ECC_err0misc_other_err_cnt;
	struct reg_collector ECC_err0misc_repeat_err_overflow;
	struct reg_collector ECC_err0misc_repeat_err_cnt;
	struct reg_collector ECC_err0misc_way;
	struct reg_collector ECC_err0misc_index;
	struct reg_collector ECC_err0misc_level_contain_error;
	struct reg_collector ECC_err0misc_indicate_icache;
	struct reg_collector ECC_err0ctrl_fault_handling_interrupt;
	struct reg_collector ECC_err0ctrl_fault_handling_int_enable;
	struct reg_collector ECC_err0ctrl_error_recovery_int_enable;
	struct reg_collector ECC_err0ctrl_error_detect_correct_enable;
};

struct big_core_spec {
	struct reg_collector edpcsr;
	struct reg_collector spmc_power_state;
	struct reg_collector i0_valid;
	struct reg_collector i0_pc;
	struct reg_collector i1_valid;
	struct reg_collector i1_pc;
	struct reg_collector last_branch;
	struct reg_collector sram_wr_ptr_0;
};

struct power_spec {
	struct reg_collector power_state;
};

struct mcusys_spec {
	struct reg_collector M0_AR_Pending_Counter;
	struct reg_collector M0_AW_Pending_Counter;
	struct reg_collector M1_AR_Pending_Counter;
	struct reg_collector M1_AW_Pending_Counter;
	struct reg_collector M2_AR_Pending_Counter;
	struct reg_collector M2_AW_Pending_Counter;
	struct reg_collector S0_AR_Pending_Counter;
	struct reg_collector S0_AW_Pending_Counter;
	struct reg_collector S1_AR_Pending_Counter;
	struct reg_collector S1_AW_Pending_Counter;
	struct reg_collector S2_AR_Pending_Counter;
	struct reg_collector S2_AW_Pending_Counter;
	struct reg_collector S3_AR_Pending_Counter;
	struct reg_collector S3_AW_Pending_Counter;
	struct reg_collector S4_AR_Pending_Counter;
	struct reg_collector S4_AW_Pending_Counter;
	struct reg_collector mp0_parity_err;
	struct reg_collector mp0_parity_index;
	struct reg_collector mp0_parity_banks;
	struct reg_collector mp0_parity_err_count;
	struct reg_collector mp1_parity_err;
	struct reg_collector mp1_parity_index;
	struct reg_collector mp1_parity_banks;
	struct reg_collector mp1_parity_err_count;
	struct reg_collector mp2_parity_err;
	struct reg_collector mp2_parity_index;
	struct reg_collector mp2_parity_banks;
	struct reg_collector dfd_v35_enable;
	struct reg_collector mp2_parity_err_count;
};

struct power_spec spmc_power_state[] = {
	{		
			.power_state = {{
			{    0, 0,0}, /* core0 power_state bit0 */
			{    0,10,0}, /* core0 power_state bit1 */
			{    0, 0,2}, /* core0 power_state bit2 */
			{    0, 0,2}, /* core0 power_state bit3 */
			{    0, 0,2}, /* core0 power_state bit4 */
			{    0, 0,2}, /* core0 power_state bit5 */
			{    0, 0,2}, /* core0 power_state bit6 */
			{    0, 0,2}, /* core0 power_state bit7 */
			{    0, 0,2}, /* core0 power_state bit8 */
			{    0, 0,2}, /* core0 power_state bit9 */
			{    0, 0,2}, /* core0 power_state bit10 */
			{    0, 0,2}, /* core0 power_state bit11 */
			{    0, 0,2}, /* core0 power_state bit12 */
			{    0, 0,2}, /* core0 power_state bit13 */
			{    0, 0,2}, /* core0 power_state bit14 */
			{    0, 0,2}, /* core0 power_state bit15 */
			{    0, 0,2}, /* core0 power_state bit16 */
			{    0, 0,2}, /* core0 power_state bit17 */
			{    0, 0,2}, /* core0 power_state bit18 */
			{    0, 0,2}, /* core0 power_state bit19 */
			{    0, 0,2}, /* core0 power_state bit20 */
			{    0, 0,2}, /* core0 power_state bit21 */
			{    0, 0,2}, /* core0 power_state bit22 */
			{    0, 0,2}, /* core0 power_state bit23 */
			{    0, 0,2}, /* core0 power_state bit24 */
			{    0, 0,2}, /* core0 power_state bit25 */
			{    0, 0,2}, /* core0 power_state bit26 */
			{    0, 0,2}, /* core0 power_state bit27 */
			{    0, 0,2}, /* core0 power_state bit28 */
			{    0, 0,2}, /* core0 power_state bit29 */
			{    0, 0,2}, /* core0 power_state bit30 */
			{    0, 0,2}, /* core0 power_state bit31 */
			{    0, 0,2}, /* core0 power_state bit32 */
			{    0, 0,2}, /* core0 power_state bit33 */
			{    0, 0,2}, /* core0 power_state bit34 */
			{    0, 0,2}, /* core0 power_state bit35 */
			{    0, 0,2}, /* core0 power_state bit36 */
			{    0, 0,2}, /* core0 power_state bit37 */
			{    0, 0,2}, /* core0 power_state bit38 */
			{    0, 0,2}, /* core0 power_state bit39 */
			{    0, 0,2}, /* core0 power_state bit40 */
			{    0, 0,2}, /* core0 power_state bit41 */
			{    0, 0,2}, /* core0 power_state bit42 */
			{    0, 0,2}, /* core0 power_state bit43 */
			{    0, 0,2}, /* core0 power_state bit44 */
			{    0, 0,2}, /* core0 power_state bit45 */
			{    0, 0,2}, /* core0 power_state bit46 */
			{    0, 0,2}, /* core0 power_state bit47 */
			{    0, 0,2}, /* core0 power_state bit48 */
			{    0, 0,2}, /* core0 power_state bit49 */
			{    0, 0,2}, /* core0 power_state bit50 */
			{    0, 0,2}, /* core0 power_state bit51 */
			{    0, 0,2}, /* core0 power_state bit52 */
			{    0, 0,2}, /* core0 power_state bit53 */
			{    0, 0,2}, /* core0 power_state bit54 */
			{    0, 0,2}, /* core0 power_state bit55 */
			{    0, 0,2}, /* core0 power_state bit56 */
			{    0, 0,2}, /* core0 power_state bit57 */
			{    0, 0,2}, /* core0 power_state bit58 */
			{    0, 0,2}, /* core0 power_state bit59 */
			{    0, 0,2}, /* core0 power_state bit60 */
			{    0, 0,2}, /* core0 power_state bit61 */
			{    0, 0,2}, /* core0 power_state bit62 */
			{    0, 0,2}, /* core0 power_state bit63 */
			}},
	},
	{	/* core 1 */
			.power_state = {{
			{    0, 1,0}, /* core1 power_state bit0 */
			{    0,11,0}, /* core1 power_state bit1 */
			{    0, 0,2}, /* core1 power_state bit2 */
			{    0, 0,2}, /* core1 power_state bit3 */
			{    0, 0,2}, /* core1 power_state bit4 */
			{    0, 0,2}, /* core1 power_state bit5 */
			{    0, 0,2}, /* core1 power_state bit6 */
			{    0, 0,2}, /* core1 power_state bit7 */
			{    0, 0,2}, /* core1 power_state bit8 */
			{    0, 0,2}, /* core1 power_state bit9 */
			{    0, 0,2}, /* core1 power_state bit10 */
			{    0, 0,2}, /* core1 power_state bit11 */
			{    0, 0,2}, /* core1 power_state bit12 */
			{    0, 0,2}, /* core1 power_state bit13 */
			{    0, 0,2}, /* core1 power_state bit14 */
			{    0, 0,2}, /* core1 power_state bit15 */
			{    0, 0,2}, /* core1 power_state bit16 */
			{    0, 0,2}, /* core1 power_state bit17 */
			{    0, 0,2}, /* core1 power_state bit18 */
			{    0, 0,2}, /* core1 power_state bit19 */
			{    0, 0,2}, /* core1 power_state bit20 */
			{    0, 0,2}, /* core1 power_state bit21 */
			{    0, 0,2}, /* core1 power_state bit22 */
			{    0, 0,2}, /* core1 power_state bit23 */
			{    0, 0,2}, /* core1 power_state bit24 */
			{    0, 0,2}, /* core1 power_state bit25 */
			{    0, 0,2}, /* core1 power_state bit26 */
			{    0, 0,2}, /* core1 power_state bit27 */
			{    0, 0,2}, /* core1 power_state bit28 */
			{    0, 0,2}, /* core1 power_state bit29 */
			{    0, 0,2}, /* core1 power_state bit30 */
			{    0, 0,2}, /* core1 power_state bit31 */
			{    0, 0,2}, /* core1 power_state bit32 */
			{    0, 0,2}, /* core1 power_state bit33 */
			{    0, 0,2}, /* core1 power_state bit34 */
			{    0, 0,2}, /* core1 power_state bit35 */
			{    0, 0,2}, /* core1 power_state bit36 */
			{    0, 0,2}, /* core1 power_state bit37 */
			{    0, 0,2}, /* core1 power_state bit38 */
			{    0, 0,2}, /* core1 power_state bit39 */
			{    0, 0,2}, /* core1 power_state bit40 */
			{    0, 0,2}, /* core1 power_state bit41 */
			{    0, 0,2}, /* core1 power_state bit42 */
			{    0, 0,2}, /* core1 power_state bit43 */
			{    0, 0,2}, /* core1 power_state bit44 */
			{    0, 0,2}, /* core1 power_state bit45 */
			{    0, 0,2}, /* core1 power_state bit46 */
			{    0, 0,2}, /* core1 power_state bit47 */
			{    0, 0,2}, /* core1 power_state bit48 */
			{    0, 0,2}, /* core1 power_state bit49 */
			{    0, 0,2}, /* core1 power_state bit50 */
			{    0, 0,2}, /* core1 power_state bit51 */
			{    0, 0,2}, /* core1 power_state bit52 */
			{    0, 0,2}, /* core1 power_state bit53 */
			{    0, 0,2}, /* core1 power_state bit54 */
			{    0, 0,2}, /* core1 power_state bit55 */
			{    0, 0,2}, /* core1 power_state bit56 */
			{    0, 0,2}, /* core1 power_state bit57 */
			{    0, 0,2}, /* core1 power_state bit58 */
			{    0, 0,2}, /* core1 power_state bit59 */
			{    0, 0,2}, /* core1 power_state bit60 */
			{    0, 0,2}, /* core1 power_state bit61 */
			{    0, 0,2}, /* core1 power_state bit62 */
			{    0, 0,2}, /* core1 power_state bit63 */
			}},
	},
	{	/* core 2 */
			.power_state = {{
			{    0, 2,0}, /* core2 power_state bit0 */
			{    0,12,0}, /* core2 power_state bit1 */
			{    0, 0,2}, /* core2 power_state bit2 */
			{    0, 0,2}, /* core2 power_state bit3 */
			{    0, 0,2}, /* core2 power_state bit4 */
			{    0, 0,2}, /* core2 power_state bit5 */
			{    0, 0,2}, /* core2 power_state bit6 */
			{    0, 0,2}, /* core2 power_state bit7 */
			{    0, 0,2}, /* core2 power_state bit8 */
			{    0, 0,2}, /* core2 power_state bit9 */
			{    0, 0,2}, /* core2 power_state bit10 */
			{    0, 0,2}, /* core2 power_state bit11 */
			{    0, 0,2}, /* core2 power_state bit12 */
			{    0, 0,2}, /* core2 power_state bit13 */
			{    0, 0,2}, /* core2 power_state bit14 */
			{    0, 0,2}, /* core2 power_state bit15 */
			{    0, 0,2}, /* core2 power_state bit16 */
			{    0, 0,2}, /* core2 power_state bit17 */
			{    0, 0,2}, /* core2 power_state bit18 */
			{    0, 0,2}, /* core2 power_state bit19 */
			{    0, 0,2}, /* core2 power_state bit20 */
			{    0, 0,2}, /* core2 power_state bit21 */
			{    0, 0,2}, /* core2 power_state bit22 */
			{    0, 0,2}, /* core2 power_state bit23 */
			{    0, 0,2}, /* core2 power_state bit24 */
			{    0, 0,2}, /* core2 power_state bit25 */
			{    0, 0,2}, /* core2 power_state bit26 */
			{    0, 0,2}, /* core2 power_state bit27 */
			{    0, 0,2}, /* core2 power_state bit28 */
			{    0, 0,2}, /* core2 power_state bit29 */
			{    0, 0,2}, /* core2 power_state bit30 */
			{    0, 0,2}, /* core2 power_state bit31 */
			{    0, 0,2}, /* core2 power_state bit32 */
			{    0, 0,2}, /* core2 power_state bit33 */
			{    0, 0,2}, /* core2 power_state bit34 */
			{    0, 0,2}, /* core2 power_state bit35 */
			{    0, 0,2}, /* core2 power_state bit36 */
			{    0, 0,2}, /* core2 power_state bit37 */
			{    0, 0,2}, /* core2 power_state bit38 */
			{    0, 0,2}, /* core2 power_state bit39 */
			{    0, 0,2}, /* core2 power_state bit40 */
			{    0, 0,2}, /* core2 power_state bit41 */
			{    0, 0,2}, /* core2 power_state bit42 */
			{    0, 0,2}, /* core2 power_state bit43 */
			{    0, 0,2}, /* core2 power_state bit44 */
			{    0, 0,2}, /* core2 power_state bit45 */
			{    0, 0,2}, /* core2 power_state bit46 */
			{    0, 0,2}, /* core2 power_state bit47 */
			{    0, 0,2}, /* core2 power_state bit48 */
			{    0, 0,2}, /* core2 power_state bit49 */
			{    0, 0,2}, /* core2 power_state bit50 */
			{    0, 0,2}, /* core2 power_state bit51 */
			{    0, 0,2}, /* core2 power_state bit52 */
			{    0, 0,2}, /* core2 power_state bit53 */
			{    0, 0,2}, /* core2 power_state bit54 */
			{    0, 0,2}, /* core2 power_state bit55 */
			{    0, 0,2}, /* core2 power_state bit56 */
			{    0, 0,2}, /* core2 power_state bit57 */
			{    0, 0,2}, /* core2 power_state bit58 */
			{    0, 0,2}, /* core2 power_state bit59 */
			{    0, 0,2}, /* core2 power_state bit60 */
			{    0, 0,2}, /* core2 power_state bit61 */
			{    0, 0,2}, /* core2 power_state bit62 */
			{    0, 0,2}, /* core2 power_state bit63 */
			}},
	},
	{	/* core 3 */
			.power_state = {{
			{    0, 3,0}, /* core3 power_state bit0 */
			{    0,13,0}, /* core3 power_state bit1 */
			{    0, 0,2}, /* core3 power_state bit2 */
			{    0, 0,2}, /* core3 power_state bit3 */
			{    0, 0,2}, /* core3 power_state bit4 */
			{    0, 0,2}, /* core3 power_state bit5 */
			{    0, 0,2}, /* core3 power_state bit6 */
			{    0, 0,2}, /* core3 power_state bit7 */
			{    0, 0,2}, /* core3 power_state bit8 */
			{    0, 0,2}, /* core3 power_state bit9 */
			{    0, 0,2}, /* core3 power_state bit10 */
			{    0, 0,2}, /* core3 power_state bit11 */
			{    0, 0,2}, /* core3 power_state bit12 */
			{    0, 0,2}, /* core3 power_state bit13 */
			{    0, 0,2}, /* core3 power_state bit14 */
			{    0, 0,2}, /* core3 power_state bit15 */
			{    0, 0,2}, /* core3 power_state bit16 */
			{    0, 0,2}, /* core3 power_state bit17 */
			{    0, 0,2}, /* core3 power_state bit18 */
			{    0, 0,2}, /* core3 power_state bit19 */
			{    0, 0,2}, /* core3 power_state bit20 */
			{    0, 0,2}, /* core3 power_state bit21 */
			{    0, 0,2}, /* core3 power_state bit22 */
			{    0, 0,2}, /* core3 power_state bit23 */
			{    0, 0,2}, /* core3 power_state bit24 */
			{    0, 0,2}, /* core3 power_state bit25 */
			{    0, 0,2}, /* core3 power_state bit26 */
			{    0, 0,2}, /* core3 power_state bit27 */
			{    0, 0,2}, /* core3 power_state bit28 */
			{    0, 0,2}, /* core3 power_state bit29 */
			{    0, 0,2}, /* core3 power_state bit30 */
			{    0, 0,2}, /* core3 power_state bit31 */
			{    0, 0,2}, /* core3 power_state bit32 */
			{    0, 0,2}, /* core3 power_state bit33 */
			{    0, 0,2}, /* core3 power_state bit34 */
			{    0, 0,2}, /* core3 power_state bit35 */
			{    0, 0,2}, /* core3 power_state bit36 */
			{    0, 0,2}, /* core3 power_state bit37 */
			{    0, 0,2}, /* core3 power_state bit38 */
			{    0, 0,2}, /* core3 power_state bit39 */
			{    0, 0,2}, /* core3 power_state bit40 */
			{    0, 0,2}, /* core3 power_state bit41 */
			{    0, 0,2}, /* core3 power_state bit42 */
			{    0, 0,2}, /* core3 power_state bit43 */
			{    0, 0,2}, /* core3 power_state bit44 */
			{    0, 0,2}, /* core3 power_state bit45 */
			{    0, 0,2}, /* core3 power_state bit46 */
			{    0, 0,2}, /* core3 power_state bit47 */
			{    0, 0,2}, /* core3 power_state bit48 */
			{    0, 0,2}, /* core3 power_state bit49 */
			{    0, 0,2}, /* core3 power_state bit50 */
			{    0, 0,2}, /* core3 power_state bit51 */
			{    0, 0,2}, /* core3 power_state bit52 */
			{    0, 0,2}, /* core3 power_state bit53 */
			{    0, 0,2}, /* core3 power_state bit54 */
			{    0, 0,2}, /* core3 power_state bit55 */
			{    0, 0,2}, /* core3 power_state bit56 */
			{    0, 0,2}, /* core3 power_state bit57 */
			{    0, 0,2}, /* core3 power_state bit58 */
			{    0, 0,2}, /* core3 power_state bit59 */
			{    0, 0,2}, /* core3 power_state bit60 */
			{    0, 0,2}, /* core3 power_state bit61 */
			{    0, 0,2}, /* core3 power_state bit62 */
			{    0, 0,2}, /* core3 power_state bit63 */
			}},
	},
	{	/* core 4 */
			.power_state = {{
			{    0,32,0}, /* core4 power_state bit0 */
			{    0,42,0}, /* core4 power_state bit1 */
			{    0, 0,2}, /* core4 power_state bit2 */
			{    0, 0,2}, /* core4 power_state bit3 */
			{    0, 0,2}, /* core4 power_state bit4 */
			{    0, 0,2}, /* core4 power_state bit5 */
			{    0, 0,2}, /* core4 power_state bit6 */
			{    0, 0,2}, /* core4 power_state bit7 */
			{    0, 0,2}, /* core4 power_state bit8 */
			{    0, 0,2}, /* core4 power_state bit9 */
			{    0, 0,2}, /* core4 power_state bit10 */
			{    0, 0,2}, /* core4 power_state bit11 */
			{    0, 0,2}, /* core4 power_state bit12 */
			{    0, 0,2}, /* core4 power_state bit13 */
			{    0, 0,2}, /* core4 power_state bit14 */
			{    0, 0,2}, /* core4 power_state bit15 */
			{    0, 0,2}, /* core4 power_state bit16 */
			{    0, 0,2}, /* core4 power_state bit17 */
			{    0, 0,2}, /* core4 power_state bit18 */
			{    0, 0,2}, /* core4 power_state bit19 */
			{    0, 0,2}, /* core4 power_state bit20 */
			{    0, 0,2}, /* core4 power_state bit21 */
			{    0, 0,2}, /* core4 power_state bit22 */
			{    0, 0,2}, /* core4 power_state bit23 */
			{    0, 0,2}, /* core4 power_state bit24 */
			{    0, 0,2}, /* core4 power_state bit25 */
			{    0, 0,2}, /* core4 power_state bit26 */
			{    0, 0,2}, /* core4 power_state bit27 */
			{    0, 0,2}, /* core4 power_state bit28 */
			{    0, 0,2}, /* core4 power_state bit29 */
			{    0, 0,2}, /* core4 power_state bit30 */
			{    0, 0,2}, /* core4 power_state bit31 */
			{    0, 0,2}, /* core4 power_state bit32 */
			{    0, 0,2}, /* core4 power_state bit33 */
			{    0, 0,2}, /* core4 power_state bit34 */
			{    0, 0,2}, /* core4 power_state bit35 */
			{    0, 0,2}, /* core4 power_state bit36 */
			{    0, 0,2}, /* core4 power_state bit37 */
			{    0, 0,2}, /* core4 power_state bit38 */
			{    0, 0,2}, /* core4 power_state bit39 */
			{    0, 0,2}, /* core4 power_state bit40 */
			{    0, 0,2}, /* core4 power_state bit41 */
			{    0, 0,2}, /* core4 power_state bit42 */
			{    0, 0,2}, /* core4 power_state bit43 */
			{    0, 0,2}, /* core4 power_state bit44 */
			{    0, 0,2}, /* core4 power_state bit45 */
			{    0, 0,2}, /* core4 power_state bit46 */
			{    0, 0,2}, /* core4 power_state bit47 */
			{    0, 0,2}, /* core4 power_state bit48 */
			{    0, 0,2}, /* core4 power_state bit49 */
			{    0, 0,2}, /* core4 power_state bit50 */
			{    0, 0,2}, /* core4 power_state bit51 */
			{    0, 0,2}, /* core4 power_state bit52 */
			{    0, 0,2}, /* core4 power_state bit53 */
			{    0, 0,2}, /* core4 power_state bit54 */
			{    0, 0,2}, /* core4 power_state bit55 */
			{    0, 0,2}, /* core4 power_state bit56 */
			{    0, 0,2}, /* core4 power_state bit57 */
			{    0, 0,2}, /* core4 power_state bit58 */
			{    0, 0,2}, /* core4 power_state bit59 */
			{    0, 0,2}, /* core4 power_state bit60 */
			{    0, 0,2}, /* core4 power_state bit61 */
			{    0, 0,2}, /* core4 power_state bit62 */
			{    0, 0,2}, /* core4 power_state bit63 */
			}},
	},
	{	/* core 5 */
			.power_state = {{
			{    0,33,0}, /* core5 power_state bit0 */
			{    0,43,0}, /* core5 power_state bit1 */
			{    0, 0,2}, /* core5 power_state bit2 */
			{    0, 0,2}, /* core5 power_state bit3 */
			{    0, 0,2}, /* core5 power_state bit4 */
			{    0, 0,2}, /* core5 power_state bit5 */
			{    0, 0,2}, /* core5 power_state bit6 */
			{    0, 0,2}, /* core5 power_state bit7 */
			{    0, 0,2}, /* core5 power_state bit8 */
			{    0, 0,2}, /* core5 power_state bit9 */
			{    0, 0,2}, /* core5 power_state bit10 */
			{    0, 0,2}, /* core5 power_state bit11 */
			{    0, 0,2}, /* core5 power_state bit12 */
			{    0, 0,2}, /* core5 power_state bit13 */
			{    0, 0,2}, /* core5 power_state bit14 */
			{    0, 0,2}, /* core5 power_state bit15 */
			{    0, 0,2}, /* core5 power_state bit16 */
			{    0, 0,2}, /* core5 power_state bit17 */
			{    0, 0,2}, /* core5 power_state bit18 */
			{    0, 0,2}, /* core5 power_state bit19 */
			{    0, 0,2}, /* core5 power_state bit20 */
			{    0, 0,2}, /* core5 power_state bit21 */
			{    0, 0,2}, /* core5 power_state bit22 */
			{    0, 0,2}, /* core5 power_state bit23 */
			{    0, 0,2}, /* core5 power_state bit24 */
			{    0, 0,2}, /* core5 power_state bit25 */
			{    0, 0,2}, /* core5 power_state bit26 */
			{    0, 0,2}, /* core5 power_state bit27 */
			{    0, 0,2}, /* core5 power_state bit28 */
			{    0, 0,2}, /* core5 power_state bit29 */
			{    0, 0,2}, /* core5 power_state bit30 */
			{    0, 0,2}, /* core5 power_state bit31 */
			{    0, 0,2}, /* core5 power_state bit32 */
			{    0, 0,2}, /* core5 power_state bit33 */
			{    0, 0,2}, /* core5 power_state bit34 */
			{    0, 0,2}, /* core5 power_state bit35 */
			{    0, 0,2}, /* core5 power_state bit36 */
			{    0, 0,2}, /* core5 power_state bit37 */
			{    0, 0,2}, /* core5 power_state bit38 */
			{    0, 0,2}, /* core5 power_state bit39 */
			{    0, 0,2}, /* core5 power_state bit40 */
			{    0, 0,2}, /* core5 power_state bit41 */
			{    0, 0,2}, /* core5 power_state bit42 */
			{    0, 0,2}, /* core5 power_state bit43 */
			{    0, 0,2}, /* core5 power_state bit44 */
			{    0, 0,2}, /* core5 power_state bit45 */
			{    0, 0,2}, /* core5 power_state bit46 */
			{    0, 0,2}, /* core5 power_state bit47 */
			{    0, 0,2}, /* core5 power_state bit48 */
			{    0, 0,2}, /* core5 power_state bit49 */
			{    0, 0,2}, /* core5 power_state bit50 */
			{    0, 0,2}, /* core5 power_state bit51 */
			{    0, 0,2}, /* core5 power_state bit52 */
			{    0, 0,2}, /* core5 power_state bit53 */
			{    0, 0,2}, /* core5 power_state bit54 */
			{    0, 0,2}, /* core5 power_state bit55 */
			{    0, 0,2}, /* core5 power_state bit56 */
			{    0, 0,2}, /* core5 power_state bit57 */
			{    0, 0,2}, /* core5 power_state bit58 */
			{    0, 0,2}, /* core5 power_state bit59 */
			{    0, 0,2}, /* core5 power_state bit60 */
			{    0, 0,2}, /* core5 power_state bit61 */
			{    0, 0,2}, /* core5 power_state bit62 */
			{    0, 0,2}, /* core5 power_state bit63 */
			}},
	},
	{	/* core 6 */
			.power_state = {{
			{    0,34,0}, /* core6 power_state bit0 */
			{    0,44,0}, /* core6 power_state bit1 */
			{    0, 0,2}, /* core6 power_state bit2 */
			{    0, 0,2}, /* core6 power_state bit3 */
			{    0, 0,2}, /* core6 power_state bit4 */
			{    0, 0,2}, /* core6 power_state bit5 */
			{    0, 0,2}, /* core6 power_state bit6 */
			{    0, 0,2}, /* core6 power_state bit7 */
			{    0, 0,2}, /* core6 power_state bit8 */
			{    0, 0,2}, /* core6 power_state bit9 */
			{    0, 0,2}, /* core6 power_state bit10 */
			{    0, 0,2}, /* core6 power_state bit11 */
			{    0, 0,2}, /* core6 power_state bit12 */
			{    0, 0,2}, /* core6 power_state bit13 */
			{    0, 0,2}, /* core6 power_state bit14 */
			{    0, 0,2}, /* core6 power_state bit15 */
			{    0, 0,2}, /* core6 power_state bit16 */
			{    0, 0,2}, /* core6 power_state bit17 */
			{    0, 0,2}, /* core6 power_state bit18 */
			{    0, 0,2}, /* core6 power_state bit19 */
			{    0, 0,2}, /* core6 power_state bit20 */
			{    0, 0,2}, /* core6 power_state bit21 */
			{    0, 0,2}, /* core6 power_state bit22 */
			{    0, 0,2}, /* core6 power_state bit23 */
			{    0, 0,2}, /* core6 power_state bit24 */
			{    0, 0,2}, /* core6 power_state bit25 */
			{    0, 0,2}, /* core6 power_state bit26 */
			{    0, 0,2}, /* core6 power_state bit27 */
			{    0, 0,2}, /* core6 power_state bit28 */
			{    0, 0,2}, /* core6 power_state bit29 */
			{    0, 0,2}, /* core6 power_state bit30 */
			{    0, 0,2}, /* core6 power_state bit31 */
			{    0, 0,2}, /* core6 power_state bit32 */
			{    0, 0,2}, /* core6 power_state bit33 */
			{    0, 0,2}, /* core6 power_state bit34 */
			{    0, 0,2}, /* core6 power_state bit35 */
			{    0, 0,2}, /* core6 power_state bit36 */
			{    0, 0,2}, /* core6 power_state bit37 */
			{    0, 0,2}, /* core6 power_state bit38 */
			{    0, 0,2}, /* core6 power_state bit39 */
			{    0, 0,2}, /* core6 power_state bit40 */
			{    0, 0,2}, /* core6 power_state bit41 */
			{    0, 0,2}, /* core6 power_state bit42 */
			{    0, 0,2}, /* core6 power_state bit43 */
			{    0, 0,2}, /* core6 power_state bit44 */
			{    0, 0,2}, /* core6 power_state bit45 */
			{    0, 0,2}, /* core6 power_state bit46 */
			{    0, 0,2}, /* core6 power_state bit47 */
			{    0, 0,2}, /* core6 power_state bit48 */
			{    0, 0,2}, /* core6 power_state bit49 */
			{    0, 0,2}, /* core6 power_state bit50 */
			{    0, 0,2}, /* core6 power_state bit51 */
			{    0, 0,2}, /* core6 power_state bit52 */
			{    0, 0,2}, /* core6 power_state bit53 */
			{    0, 0,2}, /* core6 power_state bit54 */
			{    0, 0,2}, /* core6 power_state bit55 */
			{    0, 0,2}, /* core6 power_state bit56 */
			{    0, 0,2}, /* core6 power_state bit57 */
			{    0, 0,2}, /* core6 power_state bit58 */
			{    0, 0,2}, /* core6 power_state bit59 */
			{    0, 0,2}, /* core6 power_state bit60 */
			{    0, 0,2}, /* core6 power_state bit61 */
			{    0, 0,2}, /* core6 power_state bit62 */
			{    0, 0,2}, /* core6 power_state bit63 */
			}},
	},
	{	/* core 7 */
			.power_state = {{
			{    0,35,0}, /* core7 power_state bit0 */
			{    0,45,0}, /* core7 power_state bit1 */
			{    0, 0,2}, /* core7 power_state bit2 */
			{    0, 0,2}, /* core7 power_state bit3 */
			{    0, 0,2}, /* core7 power_state bit4 */
			{    0, 0,2}, /* core7 power_state bit5 */
			{    0, 0,2}, /* core7 power_state bit6 */
			{    0, 0,2}, /* core7 power_state bit7 */
			{    0, 0,2}, /* core7 power_state bit8 */
			{    0, 0,2}, /* core7 power_state bit9 */
			{    0, 0,2}, /* core7 power_state bit10 */
			{    0, 0,2}, /* core7 power_state bit11 */
			{    0, 0,2}, /* core7 power_state bit12 */
			{    0, 0,2}, /* core7 power_state bit13 */
			{    0, 0,2}, /* core7 power_state bit14 */
			{    0, 0,2}, /* core7 power_state bit15 */
			{    0, 0,2}, /* core7 power_state bit16 */
			{    0, 0,2}, /* core7 power_state bit17 */
			{    0, 0,2}, /* core7 power_state bit18 */
			{    0, 0,2}, /* core7 power_state bit19 */
			{    0, 0,2}, /* core7 power_state bit20 */
			{    0, 0,2}, /* core7 power_state bit21 */
			{    0, 0,2}, /* core7 power_state bit22 */
			{    0, 0,2}, /* core7 power_state bit23 */
			{    0, 0,2}, /* core7 power_state bit24 */
			{    0, 0,2}, /* core7 power_state bit25 */
			{    0, 0,2}, /* core7 power_state bit26 */
			{    0, 0,2}, /* core7 power_state bit27 */
			{    0, 0,2}, /* core7 power_state bit28 */
			{    0, 0,2}, /* core7 power_state bit29 */
			{    0, 0,2}, /* core7 power_state bit30 */
			{    0, 0,2}, /* core7 power_state bit31 */
			{    0, 0,2}, /* core7 power_state bit32 */
			{    0, 0,2}, /* core7 power_state bit33 */
			{    0, 0,2}, /* core7 power_state bit34 */
			{    0, 0,2}, /* core7 power_state bit35 */
			{    0, 0,2}, /* core7 power_state bit36 */
			{    0, 0,2}, /* core7 power_state bit37 */
			{    0, 0,2}, /* core7 power_state bit38 */
			{    0, 0,2}, /* core7 power_state bit39 */
			{    0, 0,2}, /* core7 power_state bit40 */
			{    0, 0,2}, /* core7 power_state bit41 */
			{    0, 0,2}, /* core7 power_state bit42 */
			{    0, 0,2}, /* core7 power_state bit43 */
			{    0, 0,2}, /* core7 power_state bit44 */
			{    0, 0,2}, /* core7 power_state bit45 */
			{    0, 0,2}, /* core7 power_state bit46 */
			{    0, 0,2}, /* core7 power_state bit47 */
			{    0, 0,2}, /* core7 power_state bit48 */
			{    0, 0,2}, /* core7 power_state bit49 */
			{    0, 0,2}, /* core7 power_state bit50 */
			{    0, 0,2}, /* core7 power_state bit51 */
			{    0, 0,2}, /* core7 power_state bit52 */
			{    0, 0,2}, /* core7 power_state bit53 */
			{    0, 0,2}, /* core7 power_state bit54 */
			{    0, 0,2}, /* core7 power_state bit55 */
			{    0, 0,2}, /* core7 power_state bit56 */
			{    0, 0,2}, /* core7 power_state bit57 */
			{    0, 0,2}, /* core7 power_state bit58 */
			{    0, 0,2}, /* core7 power_state bit59 */
			{    0, 0,2}, /* core7 power_state bit60 */
			{    0, 0,2}, /* core7 power_state bit61 */
			{    0, 0,2}, /* core7 power_state bit62 */
			{    0, 0,2}, /* core7 power_state bit63 */
			}},
	},
}; 

struct mcusys_spec mcusys[] = {
	{		/* core 0 */ 
			.S4_AR_Pending_Counter = {{
			{ 6785, 8,1}, /* core0 S4_AR_Pending_Counter bit0 */
			{ 6783, 8,1}, /* core0 S4_AR_Pending_Counter bit1 */
			{ 6781, 8,1}, /* core0 S4_AR_Pending_Counter bit2 */
			{ 6780, 8,1}, /* core0 S4_AR_Pending_Counter bit3 */
			{ 6779, 8,1}, /* core0 S4_AR_Pending_Counter bit4 */
			{ 6782, 8,1}, /* core0 S4_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit63 */
			}},
			.S4_AW_Pending_Counter = {{
			{ 6993, 8,1}, /* core0 S4_AW_Pending_Counter bit0 */
			{ 6791, 8,1}, /* core0 S4_AW_Pending_Counter bit1 */
			{ 6793, 8,1}, /* core0 S4_AW_Pending_Counter bit2 */
			{ 6792, 8,1}, /* core0 S4_AW_Pending_Counter bit3 */
			{ 6790, 8,1}, /* core0 S4_AW_Pending_Counter bit4 */
			{ 6789, 8,1}, /* core0 S4_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit63 */
			}},
			.S3_AR_Pending_Counter = {{
			{ 7015, 8,1}, /* core0 S3_AR_Pending_Counter bit0 */
			{ 7014, 8,1}, /* core0 S3_AR_Pending_Counter bit1 */
			{ 7034, 8,1}, /* core0 S3_AR_Pending_Counter bit2 */
			{ 7012, 8,1}, /* core0 S3_AR_Pending_Counter bit3 */
			{ 7016, 8,1}, /* core0 S3_AR_Pending_Counter bit4 */
			{ 7013, 8,1}, /* core0 S3_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit63 */
			}},
			.S3_AW_Pending_Counter = {{
			{ 7009, 8,1}, /* core0 S3_AW_Pending_Counter bit0 */
			{ 7010, 8,1}, /* core0 S3_AW_Pending_Counter bit1 */
			{ 7007, 8,1}, /* core0 S3_AW_Pending_Counter bit2 */
			{ 7006, 8,1}, /* core0 S3_AW_Pending_Counter bit3 */
			{ 7005, 8,1}, /* core0 S3_AW_Pending_Counter bit4 */
			{ 7003, 8,1}, /* core0 S3_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit63 */
			}},
#if 0
			.MCU_EMI_M1_AR_Pending_Counter = {{
			{ 5139, 2,0}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit0 */
			{ 5138, 2,0}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit1 */
			{ 5136, 2,0}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit2 */
			{ 5137, 2,0}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit3 */
			{ 5135, 2,0}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit4 */
			{ 5134, 2,0}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AR_Pending_Counter bit63 */
			}},
			.MCU_EMI_M2_AR_Pending_Counter = {{
			{ 5124, 2,0}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit0 */
			{ 5120, 2,0}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit1 */
			{ 5121, 2,0}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit2 */
			{ 5273, 2,0}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit3 */
			{ 5272, 2,0}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit4 */
			{ 5123, 2,0}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AR_Pending_Counter bit63 */
			}},
			.MP_M1_AR_Pending_Counter = {{
			{ 7228, 8,1}, /* core0 MP_M1_AR_Pending_Counter bit0 */
			{ 7244, 8,1}, /* core0 MP_M1_AR_Pending_Counter bit1 */
			{ 7229, 8,1}, /* core0 MP_M1_AR_Pending_Counter bit2 */
			{ 7221, 8,1}, /* core0 MP_M1_AR_Pending_Counter bit3 */
			{ 7224, 8,1}, /* core0 MP_M1_AR_Pending_Counter bit4 */
			{ 7042, 8,1}, /* core0 MP_M1_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_M1_AR_Pending_Counter bit63 */
			}},
			.MCU_EMI_M3_AR_Pending_Counter = {{
			{ 5041, 2,0}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit0 */
			{ 5038, 2,0}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit1 */
			{ 5049, 2,0}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit2 */
			{ 5037, 2,0}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit3 */
			{ 5048, 2,0}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit4 */
			{ 5036, 2,0}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AR_Pending_Counter bit63 */
			}},
			.MCU_EMI_M4_AR_Pending_Counter = {{
			{ 5055, 2,0}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit0 */
			{ 5109, 2,0}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit1 */
			{ 5110, 2,0}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit2 */
			{ 5054, 2,0}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit3 */
			{ 5053, 2,0}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit4 */
			{ 5111, 2,0}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AR_Pending_Counter bit63 */
			}},
			.MP_M2_AR_Pending_Counter = {{
			{ 7025, 8,1}, /* core0 MP_M2_AR_Pending_Counter bit0 */
			{ 7028, 8,1}, /* core0 MP_M2_AR_Pending_Counter bit1 */
			{ 7020, 8,1}, /* core0 MP_M2_AR_Pending_Counter bit2 */
			{ 7031, 8,1}, /* core0 MP_M2_AR_Pending_Counter bit3 */
			{ 7029, 8,1}, /* core0 MP_M2_AR_Pending_Counter bit4 */
			{ 7030, 8,1}, /* core0 MP_M2_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_M2_AR_Pending_Counter bit63 */
			}},
			.MCU_EMI_M1_AW_Pending_Counter = {{
			{ 5141, 2,0}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit0 */
			{ 5028, 2,0}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit1 */
			{ 5142, 2,0}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit2 */
			{ 5271, 2,0}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit3 */
			{ 5270, 2,0}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit4 */
			{ 5029, 2,0}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_EMI_M1_AW_Pending_Counter bit63 */
			}},
			.MCU_EMI_M2_AW_Pending_Counter = {{
			{ 5130, 2,0}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit0 */
			{ 5128, 2,0}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit1 */
			{ 5131, 2,0}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit2 */
			{ 5129, 2,0}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit3 */
			{ 5030, 2,0}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit4 */
			{ 5031, 2,0}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_EMI_M2_AW_Pending_Counter bit63 */
			}},
			.MP_M1_AW_Pending_Counter = {{
			{ 7226, 8,1}, /* core0 MP_M1_AW_Pending_Counter bit0 */
			{ 7017, 8,1}, /* core0 MP_M1_AW_Pending_Counter bit1 */
			{ 7021, 8,1}, /* core0 MP_M1_AW_Pending_Counter bit2 */
			{ 7225, 8,1}, /* core0 MP_M1_AW_Pending_Counter bit3 */
			{ 7018, 8,1}, /* core0 MP_M1_AW_Pending_Counter bit4 */
			{ 7227, 8,1}, /* core0 MP_M1_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_M1_AW_Pending_Counter bit63 */
			}},
			.MCU_EMI_M3_AW_Pending_Counter = {{
			{ 5117, 2,0}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit0 */
			{ 5119, 2,0}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit1 */
			{ 5052, 2,0}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit2 */
			{ 5116, 2,0}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit3 */
			{ 5114, 2,0}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit4 */
			{ 5118, 2,0}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_EMI_M3_AW_Pending_Counter bit63 */
			}},
			.MCU_EMI_M4_AW_Pending_Counter = {{
			{ 5113, 2,0}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit0 */
			{ 5112, 2,0}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit1 */
			{ 5045, 2,0}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit2 */
			{ 5047, 2,0}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit3 */
			{ 5043, 2,0}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit4 */
			{ 5046, 2,0}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_EMI_M4_AW_Pending_Counter bit63 */
			}},
			.MP_M2_AW_Pending_Counter = {{
			{ 7038, 8,1}, /* core0 MP_M2_AW_Pending_Counter bit0 */
			{ 7036, 8,1}, /* core0 MP_M2_AW_Pending_Counter bit1 */
			{ 7033, 8,1}, /* core0 MP_M2_AW_Pending_Counter bit2 */
			{ 7037, 8,1}, /* core0 MP_M2_AW_Pending_Counter bit3 */
			{ 7040, 8,1}, /* core0 MP_M2_AW_Pending_Counter bit4 */
			{ 7011, 8,1}, /* core0 MP_M2_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_M2_AW_Pending_Counter bit63 */
			}},
			.MCU_L3GIC_AR_Pending_Counter = {{
			{ 5104, 2,0}, /* core0 MCU_L3GIC_AR_Pending_Counter bit0 */
			{ 5105, 2,0}, /* core0 MCU_L3GIC_AR_Pending_Counter bit1 */
			{ 5107, 2,0}, /* core0 MCU_L3GIC_AR_Pending_Counter bit2 */
			{ 5087, 2,0}, /* core0 MCU_L3GIC_AR_Pending_Counter bit3 */
			{ 5108, 2,0}, /* core0 MCU_L3GIC_AR_Pending_Counter bit4 */
			{ 5056, 2,0}, /* core0 MCU_L3GIC_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AR_Pending_Counter bit63 */
			}},
			.MCU_L3GIC_AW_Pending_Counter = {{
			{ 5057, 2,0}, /* core0 MCU_L3GIC_AW_Pending_Counter bit0 */
			{ 5058, 2,0}, /* core0 MCU_L3GIC_AW_Pending_Counter bit1 */
			{ 5059, 2,0}, /* core0 MCU_L3GIC_AW_Pending_Counter bit2 */
			{ 5060, 2,0}, /* core0 MCU_L3GIC_AW_Pending_Counter bit3 */
			{ 5062, 2,0}, /* core0 MCU_L3GIC_AW_Pending_Counter bit4 */
			{ 5082, 2,0}, /* core0 MCU_L3GIC_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_L3GIC_AW_Pending_Counter bit63 */
			}},
			.MP_L3GIC_AR_Pending_Counter = {{
			{ 7122, 8,1}, /* core0 MP_L3GIC_AR_Pending_Counter bit0 */
			{ 7125, 8,1}, /* core0 MP_L3GIC_AR_Pending_Counter bit1 */
			{ 7129, 8,1}, /* core0 MP_L3GIC_AR_Pending_Counter bit2 */
			{ 7130, 8,1}, /* core0 MP_L3GIC_AR_Pending_Counter bit3 */
			{ 7127, 8,1}, /* core0 MP_L3GIC_AR_Pending_Counter bit4 */
			{ 7128, 8,1}, /* core0 MP_L3GIC_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_L3GIC_AR_Pending_Counter bit63 */
			}},
			.MP_L3GIC_AW_Pending_Counter = {{
			{ 7065, 8,1}, /* core0 MP_L3GIC_AW_Pending_Counter bit0 */
			{ 7057, 8,1}, /* core0 MP_L3GIC_AW_Pending_Counter bit1 */
			{ 7133, 8,1}, /* core0 MP_L3GIC_AW_Pending_Counter bit2 */
			{ 7054, 8,1}, /* core0 MP_L3GIC_AW_Pending_Counter bit3 */
			{ 7060, 8,1}, /* core0 MP_L3GIC_AW_Pending_Counter bit4 */
			{ 7121, 8,1}, /* core0 MP_L3GIC_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_L3GIC_AW_Pending_Counter bit63 */
			}},
			.MP_AXI2to2_AR_Pending_Counter = {{
			{ 7132, 8,1}, /* core0 MP_AXI2to2_AR_Pending_Counter bit0 */
			{ 7066, 8,1}, /* core0 MP_AXI2to2_AR_Pending_Counter bit1 */
			{ 7049, 8,1}, /* core0 MP_AXI2to2_AR_Pending_Counter bit2 */
			{ 7137, 8,1}, /* core0 MP_AXI2to2_AR_Pending_Counter bit3 */
			{ 7136, 8,1}, /* core0 MP_AXI2to2_AR_Pending_Counter bit4 */
			{ 7135, 8,1}, /* core0 MP_AXI2to2_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AR_Pending_Counter bit63 */
			}},
			.MP_AXI2to2_AW_Pending_Counter = {{
			{ 7143, 8,1}, /* core0 MP_AXI2to2_AW_Pending_Counter bit0 */
			{ 7141, 8,1}, /* core0 MP_AXI2to2_AW_Pending_Counter bit1 */
			{ 7142, 8,1}, /* core0 MP_AXI2to2_AW_Pending_Counter bit2 */
			{ 7144, 8,1}, /* core0 MP_AXI2to2_AW_Pending_Counter bit3 */
			{ 7138, 8,1}, /* core0 MP_AXI2to2_AW_Pending_Counter bit4 */
			{ 7055, 8,1}, /* core0 MP_AXI2to2_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_AXI2to2_AW_Pending_Counter bit63 */
			}},
			.MCU_INFRA_M0_AR_Pending_Counter = {{
			{ 5389, 1,0}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit0 */
			{ 5396, 1,0}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit1 */
			{ 5392, 1,0}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit2 */
			{ 5391, 1,0}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit3 */
			{ 5394, 1,0}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit4 */
			{ 5393, 1,0}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AR_Pending_Counter bit63 */
			}},
			.MCU_INFRA_M0_AW_Pending_Counter = {{
			{ 5399, 1,0}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit0 */
			{ 5401, 1,0}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit1 */
			{ 5388, 1,0}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit2 */
			{ 5387, 1,0}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit3 */
			{ 5402, 1,0}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit4 */
			{ 5398, 1,0}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_INFRA_M0_AW_Pending_Counter bit63 */
			}},
			.MP_M0_AR_Pending_Counter = {{
			{ 7239, 8,1}, /* core0 MP_M0_AR_Pending_Counter bit0 */
			{ 7043, 8,1}, /* core0 MP_M0_AR_Pending_Counter bit1 */
			{ 7238, 8,1}, /* core0 MP_M0_AR_Pending_Counter bit2 */
			{ 7235, 8,1}, /* core0 MP_M0_AR_Pending_Counter bit3 */
			{ 7237, 8,1}, /* core0 MP_M0_AR_Pending_Counter bit4 */
			{ 7236, 8,1}, /* core0 MP_M0_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_M0_AR_Pending_Counter bit63 */
			}},
			.MP_M0_AW_Pending_Counter = {{
			{ 7046, 8,1}, /* core0 MP_M0_AW_Pending_Counter bit0 */
			{ 7050, 8,1}, /* core0 MP_M0_AW_Pending_Counter bit1 */
			{ 7047, 8,1}, /* core0 MP_M0_AW_Pending_Counter bit2 */
			{ 7240, 8,1}, /* core0 MP_M0_AW_Pending_Counter bit3 */
			{ 7044, 8,1}, /* core0 MP_M0_AW_Pending_Counter bit4 */
			{ 7241, 8,1}, /* core0 MP_M0_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_M0_AW_Pending_Counter bit63 */
			}},
			.MCU_ACP_AR_Pending_Counter = {{
			{ 5100, 2,0}, /* core0 MCU_ACP_AR_Pending_Counter bit0 */
			{ 5096, 2,0}, /* core0 MCU_ACP_AR_Pending_Counter bit1 */
			{ 5097, 2,0}, /* core0 MCU_ACP_AR_Pending_Counter bit2 */
			{ 5098, 2,0}, /* core0 MCU_ACP_AR_Pending_Counter bit3 */
			{ 5099, 2,0}, /* core0 MCU_ACP_AR_Pending_Counter bit4 */
			{ 5102, 2,0}, /* core0 MCU_ACP_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_ACP_AR_Pending_Counter bit63 */
			}},
			.MCU_ACP_AW_Pending_Counter = {{
			{ 5085, 2,0}, /* core0 MCU_ACP_AW_Pending_Counter bit0 */
			{ 5094, 2,0}, /* core0 MCU_ACP_AW_Pending_Counter bit1 */
			{ 5092, 2,0}, /* core0 MCU_ACP_AW_Pending_Counter bit2 */
			{ 5106, 2,0}, /* core0 MCU_ACP_AW_Pending_Counter bit3 */
			{ 5089, 2,0}, /* core0 MCU_ACP_AW_Pending_Counter bit4 */
			{ 5093, 2,0}, /* core0 MCU_ACP_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MCU_ACP_AW_Pending_Counter bit63 */
			}},
			.MP_ACP_AR_Pending_Counter = {{
			{ 6690, 8,1}, /* core0 MP_ACP_AR_Pending_Counter bit0 */
			{ 6685, 8,1}, /* core0 MP_ACP_AR_Pending_Counter bit1 */
			{ 6682, 8,1}, /* core0 MP_ACP_AR_Pending_Counter bit2 */
			{ 6684, 8,1}, /* core0 MP_ACP_AR_Pending_Counter bit3 */
			{ 6686, 8,1}, /* core0 MP_ACP_AR_Pending_Counter bit4 */
			{ 6687, 8,1}, /* core0 MP_ACP_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_ACP_AR_Pending_Counter bit63 */
			}},
			.MP_ACP_AW_Pending_Counter = {{
			{ 6697, 8,1}, /* core0 MP_ACP_AW_Pending_Counter bit0 */
			{ 6670, 8,1}, /* core0 MP_ACP_AW_Pending_Counter bit1 */
			{ 6666, 8,1}, /* core0 MP_ACP_AW_Pending_Counter bit2 */
			{ 6695, 8,1}, /* core0 MP_ACP_AW_Pending_Counter bit3 */
			{ 6694, 8,1}, /* core0 MP_ACP_AW_Pending_Counter bit4 */
			{ 6696, 8,1}, /* core0 MP_ACP_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 MP_ACP_AW_Pending_Counter bit63 */
			}},
#endif
			.dfd_v35_enable = {{
			{ 2347, 7,1}, /* core0 dfd_v35_enable bit0 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit1 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit2 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit3 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit4 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit5 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit6 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit7 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit8 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit9 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit10 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit11 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit12 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit13 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit14 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit15 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit16 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit17 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit18 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit19 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit20 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit21 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit22 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit23 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit24 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit25 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit26 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit27 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit28 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit29 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit30 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit31 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit32 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit33 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit34 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit35 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit36 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit37 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit38 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit39 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit40 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit41 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit42 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit43 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit44 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit45 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit46 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit47 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit48 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit49 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit50 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit51 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit52 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit53 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit54 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit55 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit56 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit57 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit58 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit59 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit60 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit61 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit62 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit63 */
			}},
#if 0
			.ARMdsuECCerrirq = {{
			{ 7592,29,0}, /* core0 ARMdsuECCerrirq bit0 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit1 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit2 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit3 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit4 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit5 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit6 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit7 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit8 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit9 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit10 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit11 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit12 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit13 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit14 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit15 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit16 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit17 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit18 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit19 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit20 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit21 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit22 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit23 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit24 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit25 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit26 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit27 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit28 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit29 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit30 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit31 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit32 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit33 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit34 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit35 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit36 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit37 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit38 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit39 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit40 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit41 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit42 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit43 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit44 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit45 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit46 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit47 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit48 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit49 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit50 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit51 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit52 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit53 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit54 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit55 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit56 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit57 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit58 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit59 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit60 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit61 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit62 */
			{    0, 0,2}, /* core0 ARMdsuECCerrirq bit63 */
			}},
			.ARMdsuECCfaultirq = {{
			{ 7591,29,0}, /* core0 ARMdsuECCfaultirq bit0 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit1 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit2 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit3 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit4 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit5 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit6 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit7 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit8 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit9 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit10 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit11 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit12 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit13 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit14 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit15 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit16 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit17 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit18 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit19 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit20 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit21 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit22 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit23 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit24 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit25 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit26 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit27 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit28 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit29 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit30 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit31 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit32 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit33 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit34 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit35 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit36 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit37 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit38 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit39 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit40 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit41 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit42 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit43 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit44 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit45 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit46 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit47 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit48 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit49 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit50 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit51 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit52 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit53 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit54 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit55 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit56 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit57 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit58 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit59 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit60 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit61 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit62 */
			{    0, 0,2}, /* core0 ARMdsuECCfaultirq bit63 */
			}},
			.DSUECC_err1status_v = {{
			{ 7768,29,0}, /* core0 DSUECC_err1status_v bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1status_v bit63 */
			}},
			.DSUECC_err0status_ue = {{
			{ 3776,23,0}, /* core0 DSUECC_err0status_ue bit0 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit1 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit2 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit3 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit4 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit5 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit6 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit7 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit8 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit9 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit10 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit11 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit12 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit13 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit14 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit15 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit16 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit17 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit18 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit19 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit20 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit21 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit22 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit23 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit24 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit25 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit26 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit27 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit28 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit29 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit30 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit31 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit32 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit33 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit34 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit35 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit36 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit37 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit38 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit39 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit40 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit41 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit42 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit43 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit44 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit45 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit46 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit47 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit48 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit49 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit50 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit51 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit52 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit53 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit54 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit55 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit56 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit57 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit58 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit59 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit60 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit61 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit62 */
			{    0, 0,2}, /* core0 DSUECC_err0status_ue bit63 */
			}},
			.DSUECC_err1status_of = {{
			{ 7767,29,0}, /* core0 DSUECC_err1status_of bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1status_of bit63 */
			}},
			.DSUECC_err1status_mv = {{
			{ 3777,23,0}, /* core0 DSUECC_err1status_mv bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1status_mv bit63 */
			}},
			.DSUECC_err1status_ce = {{
			{ 3779,23,0}, /* core0 DSUECC_err1status_ce bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ce bit63 */
			}},
			.DSUECC_err1status_de = {{
			{ 3778,23,0}, /* core0 DSUECC_err1status_de bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1status_de bit63 */
			}},
			.DSUECC_err1status_pn = {{
			{ 7769,29,0}, /* core0 DSUECC_err1status_pn bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1status_pn bit63 */
			}},
			.DSUECC_err1status_ierr = {{
			{ 7821,29,0}, /* core0 DSUECC_err1status_ierr bit0 */
			{ 7820,29,0}, /* core0 DSUECC_err1status_ierr bit1 */
			{ 7818,29,0}, /* core0 DSUECC_err1status_ierr bit2 */
			{ 7822,29,0}, /* core0 DSUECC_err1status_ierr bit3 */
			{ 7828,29,0}, /* core0 DSUECC_err1status_ierr bit4 */
			{ 7841,29,0}, /* core0 DSUECC_err1status_ierr bit5 */
			{ 7761,29,0}, /* core0 DSUECC_err1status_ierr bit6 */
			{ 7824,29,0}, /* core0 DSUECC_err1status_ierr bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1status_ierr bit63 */
			}},
			.DSUECC_err1status_serr = {{
			{ 7766,29,0}, /* core0 DSUECC_err1status_serr bit0 */
			{ 7760,29,0}, /* core0 DSUECC_err1status_serr bit1 */
			{ 7819,29,0}, /* core0 DSUECC_err1status_serr bit2 */
			{ 7826,29,0}, /* core0 DSUECC_err1status_serr bit3 */
			{ 7823,29,0}, /* core0 DSUECC_err1status_serr bit4 */
			{ 7827,29,0}, /* core0 DSUECC_err1status_serr bit5 */
			{ 7825,29,0}, /* core0 DSUECC_err1status_serr bit6 */
			{ 7758,29,0}, /* core0 DSUECC_err1status_serr bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1status_serr bit63 */
			}},
			.DSUECC_err1misc_sticky_overflow = {{
			{ 7842,29,0}, /* core0 DSUECC_err1misc_sticky_overflow bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_sticky_overflow bit63 */
			}},
			.DSUECC_err1misc_corrected_err_cnt = {{
			{ 7832,29,0}, /* core0 DSUECC_err1misc_corrected_err_cnt bit0 */
			{ 7831,29,0}, /* core0 DSUECC_err1misc_corrected_err_cnt bit1 */
			{ 7848,29,0}, /* core0 DSUECC_err1misc_corrected_err_cnt bit2 */
			{ 7834,29,0}, /* core0 DSUECC_err1misc_corrected_err_cnt bit3 */
			{ 7847,29,0}, /* core0 DSUECC_err1misc_corrected_err_cnt bit4 */
			{ 7844,29,0}, /* core0 DSUECC_err1misc_corrected_err_cnt bit5 */
			{ 7843,29,0}, /* core0 DSUECC_err1misc_corrected_err_cnt bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_err_cnt bit63 */
			}},
			.DSUECC_err1misc_repeat_err_overflow = {{
			{ 7839,29,0}, /* core0 DSUECC_err1misc_repeat_err_overflow bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_repeat_err_overflow bit63 */
			}},
			.DSUECC_err1misc_corrected_error_count = {{
			{ 7835,29,0}, /* core0 DSUECC_err1misc_corrected_error_count bit0 */
			{ 7833,29,0}, /* core0 DSUECC_err1misc_corrected_error_count bit1 */
			{ 7914,29,0}, /* core0 DSUECC_err1misc_corrected_error_count bit2 */
			{ 7845,29,0}, /* core0 DSUECC_err1misc_corrected_error_count bit3 */
			{ 7846,29,0}, /* core0 DSUECC_err1misc_corrected_error_count bit4 */
			{ 7840,29,0}, /* core0 DSUECC_err1misc_corrected_error_count bit5 */
			{ 7913,29,0}, /* core0 DSUECC_err1misc_corrected_error_count bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_corrected_error_count bit63 */
			}},
			.DSUECC_err1misc_way = {{
			{ 7797,29,0}, /* core0 DSUECC_err1misc_way bit0 */
			{ 7802,29,0}, /* core0 DSUECC_err1misc_way bit1 */
			{ 7796,29,0}, /* core0 DSUECC_err1misc_way bit2 */
			{ 7723,29,0}, /* core0 DSUECC_err1misc_way bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_way bit63 */
			}},
			.DSUECC_err1misc_level_contain_error = {{
			{ 3802,23,0}, /* core0 DSUECC_err1misc_level_contain_error bit0 */
			{ 3801,23,0}, /* core0 DSUECC_err1misc_level_contain_error bit1 */
			{ 3800,23,0}, /* core0 DSUECC_err1misc_level_contain_error bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_level_contain_error bit63 */
			}},
			.DSUECC_err1misc_indicate_l3cache = {{
			{ 3803,23,0}, /* core0 DSUECC_err1misc_indicate_l3cache bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1misc_indicate_l3cache bit63 */
			}},
			.DSUECC_err1ctrl_fault_handling_interrupt = {{
			{ 7778,29,0}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_interrupt bit63 */
			}},
			.DSUECC_err1ctrl_fault_handling_int_enable = {{
			{ 9305,28,0}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_fault_handling_int_enable bit63 */
			}},
			.DSUECC_err1ctrl_error_recovery_int_enable = {{
			{ 7777,29,0}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_recovery_int_enable bit63 */
			}},
			.DSUECC_err1ctrl_error_detect_correct_enable = {{
			{ 9306,28,0}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit0 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit1 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit2 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit3 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit4 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit5 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit6 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit7 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit8 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit9 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit10 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit11 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit12 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit13 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit14 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit15 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit16 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit17 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit18 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit19 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit20 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit21 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit22 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit23 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit24 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit25 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit26 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit27 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit28 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit29 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit30 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit31 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit32 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit33 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit34 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit35 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit36 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit37 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit38 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit39 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit40 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit41 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit42 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit43 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit44 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit45 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit46 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit47 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit48 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit49 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit50 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit51 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit52 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit53 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit54 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit55 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit56 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit57 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit58 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit59 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit60 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit61 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit62 */
			{    0, 0,2}, /* core0 DSUECC_err1ctrl_error_detect_correct_enable bit63 */
			}},
#endif
	},
}; 

struct little_core_spec little_core[] = {
	{		/* core 0 */ 
			.pc = {{
			{  523,34,1}, /* core0 pc bit0 */
			{  240,34,1}, /* core0 pc bit1 */
			{  102,34,1}, /* core0 pc bit2 */
			{  239,34,1}, /* core0 pc bit3 */
			{  495,34,1}, /* core0 pc bit4 */
			{  203,34,1}, /* core0 pc bit5 */
			{  431,34,1}, /* core0 pc bit6 */
			{  224,34,1}, /* core0 pc bit7 */
			{  100,34,1}, /* core0 pc bit8 */
			{  236,34,1}, /* core0 pc bit9 */
			{   96,34,1}, /* core0 pc bit10 */
			{  494,34,1}, /* core0 pc bit11 */
			{  202,34,1}, /* core0 pc bit12 */
			{  543,34,1}, /* core0 pc bit13 */
			{  223,34,1}, /* core0 pc bit14 */
			{  235,34,1}, /* core0 pc bit15 */
			{   94,34,1}, /* core0 pc bit16 */
			{  356,34,1}, /* core0 pc bit17 */
			{  207,34,1}, /* core0 pc bit18 */
			{  539,34,1}, /* core0 pc bit19 */
			{  511,34,1}, /* core0 pc bit20 */
			{   95,34,1}, /* core0 pc bit21 */
			{  522,34,1}, /* core0 pc bit22 */
			{  206,34,1}, /* core0 pc bit23 */
			{  220,34,1}, /* core0 pc bit24 */
			{  234,34,1}, /* core0 pc bit25 */
			{  355,34,1}, /* core0 pc bit26 */
			{  475,34,1}, /* core0 pc bit27 */
			{  538,34,1}, /* core0 pc bit28 */
			{  537,34,1}, /* core0 pc bit29 */
			{  536,34,1}, /* core0 pc bit30 */
			{  112,34,1}, /* core0 pc bit31 */
			{  215,34,1}, /* core0 pc bit32 */
			{  547,34,1}, /* core0 pc bit33 */
			{  230,34,1}, /* core0 pc bit34 */
			{  229,34,1}, /* core0 pc bit35 */
			{  491,34,1}, /* core0 pc bit36 */
			{  546,34,1}, /* core0 pc bit37 */
			{  423,34,1}, /* core0 pc bit38 */
			{  427,34,1}, /* core0 pc bit39 */
			{  211,34,1}, /* core0 pc bit40 */
			{  110,34,1}, /* core0 pc bit41 */
			{  367,34,1}, /* core0 pc bit42 */
			{  214,34,1}, /* core0 pc bit43 */
			{  542,34,1}, /* core0 pc bit44 */
			{  545,34,1}, /* core0 pc bit45 */
			{  426,34,1}, /* core0 pc bit46 */
			{  369,34,1}, /* core0 pc bit47 */
			{  425,34,1}, /* core0 pc bit48 */
			{  368,34,1}, /* core0 pc bit49 */
			{  430,34,1}, /* core0 pc bit50 */
			{  213,34,1}, /* core0 pc bit51 */
			{  212,34,1}, /* core0 pc bit52 */
			{  232,34,1}, /* core0 pc bit53 */
			{  535,34,1}, /* core0 pc bit54 */
			{  422,34,1}, /* core0 pc bit55 */
			{  490,34,1}, /* core0 pc bit56 */
			{  114,34,1}, /* core0 pc bit57 */
			{  415,34,1}, /* core0 pc bit58 */
			{  116,34,1}, /* core0 pc bit59 */
			{  429,34,1}, /* core0 pc bit60 */
			{  421,34,1}, /* core0 pc bit61 */
			{  420,34,1}, /* core0 pc bit62 */
			{  534,34,1}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{33132,35,1}, /* core0 sp32 bit0 */
			{33140,35,1}, /* core0 sp32 bit1 */
			{39344,35,1}, /* core0 sp32 bit2 */
			{39224,35,1}, /* core0 sp32 bit3 */
			{39343,35,1}, /* core0 sp32 bit4 */
			{33200,35,1}, /* core0 sp32 bit5 */
			{33199,35,1}, /* core0 sp32 bit6 */
			{38350,35,1}, /* core0 sp32 bit7 */
			{33128,35,1}, /* core0 sp32 bit8 */
			{33127,35,1}, /* core0 sp32 bit9 */
			{33198,35,1}, /* core0 sp32 bit10 */
			{39350,35,1}, /* core0 sp32 bit11 */
			{39240,35,1}, /* core0 sp32 bit12 */
			{39239,35,1}, /* core0 sp32 bit13 */
			{39342,35,1}, /* core0 sp32 bit14 */
			{39223,35,1}, /* core0 sp32 bit15 */
			{39349,35,1}, /* core0 sp32 bit16 */
			{39242,35,1}, /* core0 sp32 bit17 */
			{33126,35,1}, /* core0 sp32 bit18 */
			{33131,35,1}, /* core0 sp32 bit19 */
			{33125,35,1}, /* core0 sp32 bit20 */
			{33139,35,1}, /* core0 sp32 bit21 */
			{38353,35,1}, /* core0 sp32 bit22 */
			{39341,35,1}, /* core0 sp32 bit23 */
			{33138,35,1}, /* core0 sp32 bit24 */
			{33130,35,1}, /* core0 sp32 bit25 */
			{33197,35,1}, /* core0 sp32 bit26 */
			{33129,35,1}, /* core0 sp32 bit27 */
			{38356,35,1}, /* core0 sp32 bit28 */
			{38352,35,1}, /* core0 sp32 bit29 */
			{39241,35,1}, /* core0 sp32 bit30 */
			{33137,35,1}, /* core0 sp32 bit31 */
			{29541,35,1}, /* core0 sp32 bit32 */
			{29629,35,1}, /* core0 sp32 bit33 */
			{43006,35,1}, /* core0 sp32 bit34 */
			{29540,35,1}, /* core0 sp32 bit35 */
			{29628,35,1}, /* core0 sp32 bit36 */
			{29539,35,1}, /* core0 sp32 bit37 */
			{32952,35,1}, /* core0 sp32 bit38 */
			{29715,35,1}, /* core0 sp32 bit39 */
			{29713,35,1}, /* core0 sp32 bit40 */
			{32951,35,1}, /* core0 sp32 bit41 */
			{32950,35,1}, /* core0 sp32 bit42 */
			{43005,35,1}, /* core0 sp32 bit43 */
			{29712,35,1}, /* core0 sp32 bit44 */
			{29714,35,1}, /* core0 sp32 bit45 */
			{32949,35,1}, /* core0 sp32 bit46 */
			{29315,35,1}, /* core0 sp32 bit47 */
			{29317,35,1}, /* core0 sp32 bit48 */
			{29409,35,1}, /* core0 sp32 bit49 */
			{29316,35,1}, /* core0 sp32 bit50 */
			{29415,35,1}, /* core0 sp32 bit51 */
			{29414,35,1}, /* core0 sp32 bit52 */
			{29407,35,1}, /* core0 sp32 bit53 */
			{29406,35,1}, /* core0 sp32 bit54 */
			{42991,35,1}, /* core0 sp32 bit55 */
			{29411,35,1}, /* core0 sp32 bit56 */
			{29413,35,1}, /* core0 sp32 bit57 */
			{29314,35,1}, /* core0 sp32 bit58 */
			{29410,35,1}, /* core0 sp32 bit59 */
			{29412,35,1}, /* core0 sp32 bit60 */
			{42989,35,1}, /* core0 sp32 bit61 */
			{29408,35,1}, /* core0 sp32 bit62 */
			{29538,35,1}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{39308,35,1}, /* core0 fp32 bit0 */
			{39246,35,1}, /* core0 fp32 bit1 */
			{33160,35,1}, /* core0 fp32 bit2 */
			{33152,35,1}, /* core0 fp32 bit3 */
			{33159,35,1}, /* core0 fp32 bit4 */
			{33151,35,1}, /* core0 fp32 bit5 */
			{39334,35,1}, /* core0 fp32 bit6 */
			{33148,35,1}, /* core0 fp32 bit7 */
			{39332,35,1}, /* core0 fp32 bit8 */
			{32636,35,1}, /* core0 fp32 bit9 */
			{32635,35,1}, /* core0 fp32 bit10 */
			{32634,35,1}, /* core0 fp32 bit11 */
			{38329,35,1}, /* core0 fp32 bit12 */
			{39304,35,1}, /* core0 fp32 bit13 */
			{39333,35,1}, /* core0 fp32 bit14 */
			{39303,35,1}, /* core0 fp32 bit15 */
			{38346,35,1}, /* core0 fp32 bit16 */
			{32633,35,1}, /* core0 fp32 bit17 */
			{33156,35,1}, /* core0 fp32 bit18 */
			{33147,35,1}, /* core0 fp32 bit19 */
			{33155,35,1}, /* core0 fp32 bit20 */
			{33154,35,1}, /* core0 fp32 bit21 */
			{33150,35,1}, /* core0 fp32 bit22 */
			{33158,35,1}, /* core0 fp32 bit23 */
			{33149,35,1}, /* core0 fp32 bit24 */
			{39307,35,1}, /* core0 fp32 bit25 */
			{39331,35,1}, /* core0 fp32 bit26 */
			{39245,35,1}, /* core0 fp32 bit27 */
			{33146,35,1}, /* core0 fp32 bit28 */
			{33153,35,1}, /* core0 fp32 bit29 */
			{33145,35,1}, /* core0 fp32 bit30 */
			{33157,35,1}, /* core0 fp32 bit31 */
			{32928,35,1}, /* core0 fp32 bit32 */
			{29285,35,1}, /* core0 fp32 bit33 */
			{29284,35,1}, /* core0 fp32 bit34 */
			{32927,35,1}, /* core0 fp32 bit35 */
			{43000,35,1}, /* core0 fp32 bit36 */
			{32926,35,1}, /* core0 fp32 bit37 */
			{29295,35,1}, /* core0 fp32 bit38 */
			{29291,35,1}, /* core0 fp32 bit39 */
			{29287,35,1}, /* core0 fp32 bit40 */
			{42999,35,1}, /* core0 fp32 bit41 */
			{38251,35,1}, /* core0 fp32 bit42 */
			{38250,35,1}, /* core0 fp32 bit43 */
			{29294,35,1}, /* core0 fp32 bit44 */
			{29286,35,1}, /* core0 fp32 bit45 */
			{29290,35,1}, /* core0 fp32 bit46 */
			{33012,35,1}, /* core0 fp32 bit47 */
			{33011,35,1}, /* core0 fp32 bit48 */
			{33010,35,1}, /* core0 fp32 bit49 */
			{29443,35,1}, /* core0 fp32 bit50 */
			{33009,35,1}, /* core0 fp32 bit51 */
			{29447,35,1}, /* core0 fp32 bit52 */
			{29442,35,1}, /* core0 fp32 bit53 */
			{34234,35,1}, /* core0 fp32 bit54 */
			{29297,35,1}, /* core0 fp32 bit55 */
			{29446,35,1}, /* core0 fp32 bit56 */
			{29296,35,1}, /* core0 fp32 bit57 */
			{29445,35,1}, /* core0 fp32 bit58 */
			{34235,35,1}, /* core0 fp32 bit59 */
			{29444,35,1}, /* core0 fp32 bit60 */
			{29441,35,1}, /* core0 fp32 bit61 */
			{29440,35,1}, /* core0 fp32 bit62 */
			{32925,35,1}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{32660,35,1}, /* core0 fp64 bit0 */
			{32668,35,1}, /* core0 fp64 bit1 */
			{32659,35,1}, /* core0 fp64 bit2 */
			{32676,35,1}, /* core0 fp64 bit3 */
			{32658,35,1}, /* core0 fp64 bit4 */
			{32657,35,1}, /* core0 fp64 bit5 */
			{32656,35,1}, /* core0 fp64 bit6 */
			{38427,35,1}, /* core0 fp64 bit7 */
			{38488,35,1}, /* core0 fp64 bit8 */
			{32655,35,1}, /* core0 fp64 bit9 */
			{38428,35,1}, /* core0 fp64 bit10 */
			{32654,35,1}, /* core0 fp64 bit11 */
			{38423,35,1}, /* core0 fp64 bit12 */
			{32653,35,1}, /* core0 fp64 bit13 */
			{38490,35,1}, /* core0 fp64 bit14 */
			{38492,35,1}, /* core0 fp64 bit15 */
			{38487,35,1}, /* core0 fp64 bit16 */
			{38491,35,1}, /* core0 fp64 bit17 */
			{38489,35,1}, /* core0 fp64 bit18 */
			{32667,35,1}, /* core0 fp64 bit19 */
			{32666,35,1}, /* core0 fp64 bit20 */
			{32675,35,1}, /* core0 fp64 bit21 */
			{38856,35,1}, /* core0 fp64 bit22 */
			{32672,35,1}, /* core0 fp64 bit23 */
			{32671,35,1}, /* core0 fp64 bit24 */
			{38422,35,1}, /* core0 fp64 bit25 */
			{32665,35,1}, /* core0 fp64 bit26 */
			{32670,35,1}, /* core0 fp64 bit27 */
			{32674,35,1}, /* core0 fp64 bit28 */
			{38855,35,1}, /* core0 fp64 bit29 */
			{32673,35,1}, /* core0 fp64 bit30 */
			{32669,35,1}, /* core0 fp64 bit31 */
			{39065,35,1}, /* core0 fp64 bit32 */
			{38229,35,1}, /* core0 fp64 bit33 */
			{38227,35,1}, /* core0 fp64 bit34 */
			{39064,35,1}, /* core0 fp64 bit35 */
			{38224,35,1}, /* core0 fp64 bit36 */
			{38225,35,1}, /* core0 fp64 bit37 */
			{39069,35,1}, /* core0 fp64 bit38 */
			{39061,35,1}, /* core0 fp64 bit39 */
			{39063,35,1}, /* core0 fp64 bit40 */
			{38222,35,1}, /* core0 fp64 bit41 */
			{39071,35,1}, /* core0 fp64 bit42 */
			{39070,35,1}, /* core0 fp64 bit43 */
			{39060,35,1}, /* core0 fp64 bit44 */
			{38228,35,1}, /* core0 fp64 bit45 */
			{39068,35,1}, /* core0 fp64 bit46 */
			{39045,35,1}, /* core0 fp64 bit47 */
			{39044,35,1}, /* core0 fp64 bit48 */
			{39041,35,1}, /* core0 fp64 bit49 */
			{39037,35,1}, /* core0 fp64 bit50 */
			{29577,35,1}, /* core0 fp64 bit51 */
			{29576,35,1}, /* core0 fp64 bit52 */
			{39039,35,1}, /* core0 fp64 bit53 */
			{39038,35,1}, /* core0 fp64 bit54 */
			{29575,35,1}, /* core0 fp64 bit55 */
			{39036,35,1}, /* core0 fp64 bit56 */
			{39043,35,1}, /* core0 fp64 bit57 */
			{39042,35,1}, /* core0 fp64 bit58 */
			{30046,35,1}, /* core0 fp64 bit59 */
			{39040,35,1}, /* core0 fp64 bit60 */
			{29574,35,1}, /* core0 fp64 bit61 */
			{30045,35,1}, /* core0 fp64 bit62 */
			{39062,35,1}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{38539,35,1}, /* core0 sp_EL0 bit0 */
			{32816,35,1}, /* core0 sp_EL0 bit1 */
			{32808,35,1}, /* core0 sp_EL0 bit2 */
			{38533,35,1}, /* core0 sp_EL0 bit3 */
			{32740,35,1}, /* core0 sp_EL0 bit4 */
			{32807,35,1}, /* core0 sp_EL0 bit5 */
			{38531,35,1}, /* core0 sp_EL0 bit6 */
			{38538,35,1}, /* core0 sp_EL0 bit7 */
			{38540,35,1}, /* core0 sp_EL0 bit8 */
			{38882,35,1}, /* core0 sp_EL0 bit9 */
			{32739,35,1}, /* core0 sp_EL0 bit10 */
			{32806,35,1}, /* core0 sp_EL0 bit11 */
			{32815,35,1}, /* core0 sp_EL0 bit12 */
			{32814,35,1}, /* core0 sp_EL0 bit13 */
			{32805,35,1}, /* core0 sp_EL0 bit14 */
			{32738,35,1}, /* core0 sp_EL0 bit15 */
			{38532,35,1}, /* core0 sp_EL0 bit16 */
			{32737,35,1}, /* core0 sp_EL0 bit17 */
			{38537,35,1}, /* core0 sp_EL0 bit18 */
			{32813,35,1}, /* core0 sp_EL0 bit19 */
			{38884,35,1}, /* core0 sp_EL0 bit20 */
			{38881,35,1}, /* core0 sp_EL0 bit21 */
			{38878,35,1}, /* core0 sp_EL0 bit22 */
			{38448,35,1}, /* core0 sp_EL0 bit23 */
			{38880,35,1}, /* core0 sp_EL0 bit24 */
			{32744,35,1}, /* core0 sp_EL0 bit25 */
			{38877,35,1}, /* core0 sp_EL0 bit26 */
			{32743,35,1}, /* core0 sp_EL0 bit27 */
			{38879,35,1}, /* core0 sp_EL0 bit28 */
			{32742,35,1}, /* core0 sp_EL0 bit29 */
			{32741,35,1}, /* core0 sp_EL0 bit30 */
			{38883,35,1}, /* core0 sp_EL0 bit31 */
			{32202,35,1}, /* core0 sp_EL0 bit32 */
			{32204,35,1}, /* core0 sp_EL0 bit33 */
			{32201,35,1}, /* core0 sp_EL0 bit34 */
			{33365,35,1}, /* core0 sp_EL0 bit35 */
			{32203,35,1}, /* core0 sp_EL0 bit36 */
			{33366,35,1}, /* core0 sp_EL0 bit37 */
			{32388,35,1}, /* core0 sp_EL0 bit38 */
			{32384,35,1}, /* core0 sp_EL0 bit39 */
			{32387,35,1}, /* core0 sp_EL0 bit40 */
			{32383,35,1}, /* core0 sp_EL0 bit41 */
			{38812,35,1}, /* core0 sp_EL0 bit42 */
			{32382,35,1}, /* core0 sp_EL0 bit43 */
			{38811,35,1}, /* core0 sp_EL0 bit44 */
			{32386,35,1}, /* core0 sp_EL0 bit45 */
			{32381,35,1}, /* core0 sp_EL0 bit46 */
			{32212,35,1}, /* core0 sp_EL0 bit47 */
			{32211,35,1}, /* core0 sp_EL0 bit48 */
			{32454,35,1}, /* core0 sp_EL0 bit49 */
			{32218,35,1}, /* core0 sp_EL0 bit50 */
			{32217,35,1}, /* core0 sp_EL0 bit51 */
			{32453,35,1}, /* core0 sp_EL0 bit52 */
			{30043,35,1}, /* core0 sp_EL0 bit53 */
			{32452,35,1}, /* core0 sp_EL0 bit54 */
			{32451,35,1}, /* core0 sp_EL0 bit55 */
			{32220,35,1}, /* core0 sp_EL0 bit56 */
			{32222,35,1}, /* core0 sp_EL0 bit57 */
			{32221,35,1}, /* core0 sp_EL0 bit58 */
			{32219,35,1}, /* core0 sp_EL0 bit59 */
			{30044,35,1}, /* core0 sp_EL0 bit60 */
			{32216,35,1}, /* core0 sp_EL0 bit61 */
			{32215,35,1}, /* core0 sp_EL0 bit62 */
			{32385,35,1}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{38443,35,1}, /* core0 sp_EL1 bit0 */
			{38447,35,1}, /* core0 sp_EL1 bit1 */
			{32812,35,1}, /* core0 sp_EL1 bit2 */
			{32811,35,1}, /* core0 sp_EL1 bit3 */
			{38445,35,1}, /* core0 sp_EL1 bit4 */
			{38442,35,1}, /* core0 sp_EL1 bit5 */
			{38536,35,1}, /* core0 sp_EL1 bit6 */
			{38441,35,1}, /* core0 sp_EL1 bit7 */
			{38444,35,1}, /* core0 sp_EL1 bit8 */
			{32820,35,1}, /* core0 sp_EL1 bit9 */
			{38446,35,1}, /* core0 sp_EL1 bit10 */
			{38440,35,1}, /* core0 sp_EL1 bit11 */
			{38534,35,1}, /* core0 sp_EL1 bit12 */
			{32819,35,1}, /* core0 sp_EL1 bit13 */
			{38535,35,1}, /* core0 sp_EL1 bit14 */
			{32810,35,1}, /* core0 sp_EL1 bit15 */
			{32809,35,1}, /* core0 sp_EL1 bit16 */
			{38529,35,1}, /* core0 sp_EL1 bit17 */
			{38528,35,1}, /* core0 sp_EL1 bit18 */
			{32818,35,1}, /* core0 sp_EL1 bit19 */
			{38876,35,1}, /* core0 sp_EL1 bit20 */
			{32824,35,1}, /* core0 sp_EL1 bit21 */
			{32823,35,1}, /* core0 sp_EL1 bit22 */
			{38874,35,1}, /* core0 sp_EL1 bit23 */
			{38875,35,1}, /* core0 sp_EL1 bit24 */
			{38872,35,1}, /* core0 sp_EL1 bit25 */
			{32822,35,1}, /* core0 sp_EL1 bit26 */
			{32821,35,1}, /* core0 sp_EL1 bit27 */
			{38873,35,1}, /* core0 sp_EL1 bit28 */
			{32817,35,1}, /* core0 sp_EL1 bit29 */
			{38871,35,1}, /* core0 sp_EL1 bit30 */
			{38530,35,1}, /* core0 sp_EL1 bit31 */
			{32376,35,1}, /* core0 sp_EL1 bit32 */
			{32375,35,1}, /* core0 sp_EL1 bit33 */
			{32374,35,1}, /* core0 sp_EL1 bit34 */
			{32208,35,1}, /* core0 sp_EL1 bit35 */
			{30040,35,1}, /* core0 sp_EL1 bit36 */
			{32207,35,1}, /* core0 sp_EL1 bit37 */
			{39083,35,1}, /* core0 sp_EL1 bit38 */
			{39081,35,1}, /* core0 sp_EL1 bit39 */
			{39082,35,1}, /* core0 sp_EL1 bit40 */
			{33364,35,1}, /* core0 sp_EL1 bit41 */
			{38810,35,1}, /* core0 sp_EL1 bit42 */
			{29724,35,1}, /* core0 sp_EL1 bit43 */
			{38809,35,1}, /* core0 sp_EL1 bit44 */
			{39080,35,1}, /* core0 sp_EL1 bit45 */
			{29740,35,1}, /* core0 sp_EL1 bit46 */
			{32214,35,1}, /* core0 sp_EL1 bit47 */
			{32450,35,1}, /* core0 sp_EL1 bit48 */
			{32442,35,1}, /* core0 sp_EL1 bit49 */
			{32441,35,1}, /* core0 sp_EL1 bit50 */
			{32449,35,1}, /* core0 sp_EL1 bit51 */
			{32440,35,1}, /* core0 sp_EL1 bit52 */
			{32224,35,1}, /* core0 sp_EL1 bit53 */
			{32446,35,1}, /* core0 sp_EL1 bit54 */
			{32213,35,1}, /* core0 sp_EL1 bit55 */
			{32445,35,1}, /* core0 sp_EL1 bit56 */
			{32448,35,1}, /* core0 sp_EL1 bit57 */
			{32447,35,1}, /* core0 sp_EL1 bit58 */
			{32223,35,1}, /* core0 sp_EL1 bit59 */
			{32439,35,1}, /* core0 sp_EL1 bit60 */
			{32444,35,1}, /* core0 sp_EL1 bit61 */
			{32443,35,1}, /* core0 sp_EL1 bit62 */
			{32373,35,1}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{38517,35,1}, /* core0 sp_EL2 bit0 */
			{32700,35,1}, /* core0 sp_EL2 bit1 */
			{38516,35,1}, /* core0 sp_EL2 bit2 */
			{32699,35,1}, /* core0 sp_EL2 bit3 */
			{38410,35,1}, /* core0 sp_EL2 bit4 */
			{32732,35,1}, /* core0 sp_EL2 bit5 */
			{32698,35,1}, /* core0 sp_EL2 bit6 */
			{32697,35,1}, /* core0 sp_EL2 bit7 */
			{38519,35,1}, /* core0 sp_EL2 bit8 */
			{32731,35,1}, /* core0 sp_EL2 bit9 */
			{32730,35,1}, /* core0 sp_EL2 bit10 */
			{38523,35,1}, /* core0 sp_EL2 bit11 */
			{38527,35,1}, /* core0 sp_EL2 bit12 */
			{38525,35,1}, /* core0 sp_EL2 bit13 */
			{38521,35,1}, /* core0 sp_EL2 bit14 */
			{38409,35,1}, /* core0 sp_EL2 bit15 */
			{38520,35,1}, /* core0 sp_EL2 bit16 */
			{38524,35,1}, /* core0 sp_EL2 bit17 */
			{38518,35,1}, /* core0 sp_EL2 bit18 */
			{32696,35,1}, /* core0 sp_EL2 bit19 */
			{38412,35,1}, /* core0 sp_EL2 bit20 */
			{32729,35,1}, /* core0 sp_EL2 bit21 */
			{32728,35,1}, /* core0 sp_EL2 bit22 */
			{32727,35,1}, /* core0 sp_EL2 bit23 */
			{38522,35,1}, /* core0 sp_EL2 bit24 */
			{32695,35,1}, /* core0 sp_EL2 bit25 */
			{38526,35,1}, /* core0 sp_EL2 bit26 */
			{38411,35,1}, /* core0 sp_EL2 bit27 */
			{32726,35,1}, /* core0 sp_EL2 bit28 */
			{32725,35,1}, /* core0 sp_EL2 bit29 */
			{32694,35,1}, /* core0 sp_EL2 bit30 */
			{32693,35,1}, /* core0 sp_EL2 bit31 */
			{33368,35,1}, /* core0 sp_EL2 bit32 */
			{32206,35,1}, /* core0 sp_EL2 bit33 */
			{33369,35,1}, /* core0 sp_EL2 bit34 */
			{33367,35,1}, /* core0 sp_EL2 bit35 */
			{32102,35,1}, /* core0 sp_EL2 bit36 */
			{32205,35,1}, /* core0 sp_EL2 bit37 */
			{32106,35,1}, /* core0 sp_EL2 bit38 */
			{38802,35,1}, /* core0 sp_EL2 bit39 */
			{29727,35,1}, /* core0 sp_EL2 bit40 */
			{32396,35,1}, /* core0 sp_EL2 bit41 */
			{38801,35,1}, /* core0 sp_EL2 bit42 */
			{32395,35,1}, /* core0 sp_EL2 bit43 */
			{32394,35,1}, /* core0 sp_EL2 bit44 */
			{32105,35,1}, /* core0 sp_EL2 bit45 */
			{32393,35,1}, /* core0 sp_EL2 bit46 */
			{32210,35,1}, /* core0 sp_EL2 bit47 */
			{32209,35,1}, /* core0 sp_EL2 bit48 */
			{30042,35,1}, /* core0 sp_EL2 bit49 */
			{32434,35,1}, /* core0 sp_EL2 bit50 */
			{32433,35,1}, /* core0 sp_EL2 bit51 */
			{32228,35,1}, /* core0 sp_EL2 bit52 */
			{30049,35,1}, /* core0 sp_EL2 bit53 */
			{30048,35,1}, /* core0 sp_EL2 bit54 */
			{32432,35,1}, /* core0 sp_EL2 bit55 */
			{32230,35,1}, /* core0 sp_EL2 bit56 */
			{32232,35,1}, /* core0 sp_EL2 bit57 */
			{30041,35,1}, /* core0 sp_EL2 bit58 */
			{32229,35,1}, /* core0 sp_EL2 bit59 */
			{32231,35,1}, /* core0 sp_EL2 bit60 */
			{32431,35,1}, /* core0 sp_EL2 bit61 */
			{32227,35,1}, /* core0 sp_EL2 bit62 */
			{32101,35,1}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{32708,35,1}, /* core0 sp_EL3 bit0 */
			{38506,35,1}, /* core0 sp_EL3 bit1 */
			{38498,35,1}, /* core0 sp_EL3 bit2 */
			{32707,35,1}, /* core0 sp_EL3 bit3 */
			{32706,35,1}, /* core0 sp_EL3 bit4 */
			{32705,35,1}, /* core0 sp_EL3 bit5 */
			{38502,35,1}, /* core0 sp_EL3 bit6 */
			{38496,35,1}, /* core0 sp_EL3 bit7 */
			{38495,35,1}, /* core0 sp_EL3 bit8 */
			{38504,35,1}, /* core0 sp_EL3 bit9 */
			{38497,35,1}, /* core0 sp_EL3 bit10 */
			{38418,35,1}, /* core0 sp_EL3 bit11 */
			{38501,35,1}, /* core0 sp_EL3 bit12 */
			{38416,35,1}, /* core0 sp_EL3 bit13 */
			{38500,35,1}, /* core0 sp_EL3 bit14 */
			{38419,35,1}, /* core0 sp_EL3 bit15 */
			{38417,35,1}, /* core0 sp_EL3 bit16 */
			{38503,35,1}, /* core0 sp_EL3 bit17 */
			{38499,35,1}, /* core0 sp_EL3 bit18 */
			{32716,35,1}, /* core0 sp_EL3 bit19 */
			{32724,35,1}, /* core0 sp_EL3 bit20 */
			{32723,35,1}, /* core0 sp_EL3 bit21 */
			{32715,35,1}, /* core0 sp_EL3 bit22 */
			{32720,35,1}, /* core0 sp_EL3 bit23 */
			{38505,35,1}, /* core0 sp_EL3 bit24 */
			{32714,35,1}, /* core0 sp_EL3 bit25 */
			{32722,35,1}, /* core0 sp_EL3 bit26 */
			{32721,35,1}, /* core0 sp_EL3 bit27 */
			{32719,35,1}, /* core0 sp_EL3 bit28 */
			{32718,35,1}, /* core0 sp_EL3 bit29 */
			{32717,35,1}, /* core0 sp_EL3 bit30 */
			{32713,35,1}, /* core0 sp_EL3 bit31 */
			{32380,35,1}, /* core0 sp_EL3 bit32 */
			{32379,35,1}, /* core0 sp_EL3 bit33 */
			{32372,35,1}, /* core0 sp_EL3 bit34 */
			{32371,35,1}, /* core0 sp_EL3 bit35 */
			{32370,35,1}, /* core0 sp_EL3 bit36 */
			{32369,35,1}, /* core0 sp_EL3 bit37 */
			{29739,35,1}, /* core0 sp_EL3 bit38 */
			{38808,35,1}, /* core0 sp_EL3 bit39 */
			{32378,35,1}, /* core0 sp_EL3 bit40 */
			{38807,35,1}, /* core0 sp_EL3 bit41 */
			{38804,35,1}, /* core0 sp_EL3 bit42 */
			{38806,35,1}, /* core0 sp_EL3 bit43 */
			{29738,35,1}, /* core0 sp_EL3 bit44 */
			{38803,35,1}, /* core0 sp_EL3 bit45 */
			{38805,35,1}, /* core0 sp_EL3 bit46 */
			{32344,35,1}, /* core0 sp_EL3 bit47 */
			{32343,35,1}, /* core0 sp_EL3 bit48 */
			{32342,35,1}, /* core0 sp_EL3 bit49 */
			{32236,35,1}, /* core0 sp_EL3 bit50 */
			{32234,35,1}, /* core0 sp_EL3 bit51 */
			{32438,35,1}, /* core0 sp_EL3 bit52 */
			{32235,35,1}, /* core0 sp_EL3 bit53 */
			{32437,35,1}, /* core0 sp_EL3 bit54 */
			{32233,35,1}, /* core0 sp_EL3 bit55 */
			{30047,35,1}, /* core0 sp_EL3 bit56 */
			{30050,35,1}, /* core0 sp_EL3 bit57 */
			{32341,35,1}, /* core0 sp_EL3 bit58 */
			{32436,35,1}, /* core0 sp_EL3 bit59 */
			{32435,35,1}, /* core0 sp_EL3 bit60 */
			{32226,35,1}, /* core0 sp_EL3 bit61 */
			{32225,35,1}, /* core0 sp_EL3 bit62 */
			{32377,35,1}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{32542,35,1}, /* core0 elr_EL1 bit0 */
			{38888,35,1}, /* core0 elr_EL1 bit1 */
			{38892,35,1}, /* core0 elr_EL1 bit2 */
			{38894,35,1}, /* core0 elr_EL1 bit3 */
			{38896,35,1}, /* core0 elr_EL1 bit4 */
			{38543,35,1}, /* core0 elr_EL1 bit5 */
			{38893,35,1}, /* core0 elr_EL1 bit6 */
			{38891,35,1}, /* core0 elr_EL1 bit7 */
			{38895,35,1}, /* core0 elr_EL1 bit8 */
			{38544,35,1}, /* core0 elr_EL1 bit9 */
			{38886,35,1}, /* core0 elr_EL1 bit10 */
			{32541,35,1}, /* core0 elr_EL1 bit11 */
			{38890,35,1}, /* core0 elr_EL1 bit12 */
			{38542,35,1}, /* core0 elr_EL1 bit13 */
			{38885,35,1}, /* core0 elr_EL1 bit14 */
			{32540,35,1}, /* core0 elr_EL1 bit15 */
			{32539,35,1}, /* core0 elr_EL1 bit16 */
			{38887,35,1}, /* core0 elr_EL1 bit17 */
			{38889,35,1}, /* core0 elr_EL1 bit18 */
			{32800,35,1}, /* core0 elr_EL1 bit19 */
			{32804,35,1}, /* core0 elr_EL1 bit20 */
			{32796,35,1}, /* core0 elr_EL1 bit21 */
			{32799,35,1}, /* core0 elr_EL1 bit22 */
			{32798,35,1}, /* core0 elr_EL1 bit23 */
			{32795,35,1}, /* core0 elr_EL1 bit24 */
			{32803,35,1}, /* core0 elr_EL1 bit25 */
			{32794,35,1}, /* core0 elr_EL1 bit26 */
			{32802,35,1}, /* core0 elr_EL1 bit27 */
			{32797,35,1}, /* core0 elr_EL1 bit28 */
			{29781,35,1}, /* core0 elr_EL1 bit29 */
			{32793,35,1}, /* core0 elr_EL1 bit30 */
			{32801,35,1}, /* core0 elr_EL1 bit31 */
			{32392,35,1}, /* core0 elr_EL1 bit32 */
			{32368,35,1}, /* core0 elr_EL1 bit33 */
			{32391,35,1}, /* core0 elr_EL1 bit34 */
			{32390,35,1}, /* core0 elr_EL1 bit35 */
			{32389,35,1}, /* core0 elr_EL1 bit36 */
			{32367,35,1}, /* core0 elr_EL1 bit37 */
			{33346,35,1}, /* core0 elr_EL1 bit38 */
			{32104,35,1}, /* core0 elr_EL1 bit39 */
			{33345,35,1}, /* core0 elr_EL1 bit40 */
			{32400,35,1}, /* core0 elr_EL1 bit41 */
			{32399,35,1}, /* core0 elr_EL1 bit42 */
			{32398,35,1}, /* core0 elr_EL1 bit43 */
			{29737,35,1}, /* core0 elr_EL1 bit44 */
			{32103,35,1}, /* core0 elr_EL1 bit45 */
			{32397,35,1}, /* core0 elr_EL1 bit46 */
			{32346,35,1}, /* core0 elr_EL1 bit47 */
			{33361,35,1}, /* core0 elr_EL1 bit48 */
			{33360,35,1}, /* core0 elr_EL1 bit49 */
			{32238,35,1}, /* core0 elr_EL1 bit50 */
			{33362,35,1}, /* core0 elr_EL1 bit51 */
			{32340,35,1}, /* core0 elr_EL1 bit52 */
			{32350,35,1}, /* core0 elr_EL1 bit53 */
			{32240,35,1}, /* core0 elr_EL1 bit54 */
			{32237,35,1}, /* core0 elr_EL1 bit55 */
			{32349,35,1}, /* core0 elr_EL1 bit56 */
			{32345,35,1}, /* core0 elr_EL1 bit57 */
			{32348,35,1}, /* core0 elr_EL1 bit58 */
			{32239,35,1}, /* core0 elr_EL1 bit59 */
			{32347,35,1}, /* core0 elr_EL1 bit60 */
			{33363,35,1}, /* core0 elr_EL1 bit61 */
			{32339,35,1}, /* core0 elr_EL1 bit62 */
			{33347,35,1}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{38754,35,1}, /* core0 elr_EL2 bit0 */
			{29783,35,1}, /* core0 elr_EL2 bit1 */
			{29782,35,1}, /* core0 elr_EL2 bit2 */
			{38742,35,1}, /* core0 elr_EL2 bit3 */
			{38752,35,1}, /* core0 elr_EL2 bit4 */
			{38740,35,1}, /* core0 elr_EL2 bit5 */
			{38898,35,1}, /* core0 elr_EL2 bit6 */
			{38750,35,1}, /* core0 elr_EL2 bit7 */
			{38545,35,1}, /* core0 elr_EL2 bit8 */
			{38753,35,1}, /* core0 elr_EL2 bit9 */
			{38739,35,1}, /* core0 elr_EL2 bit10 */
			{38897,35,1}, /* core0 elr_EL2 bit11 */
			{38541,35,1}, /* core0 elr_EL2 bit12 */
			{38749,35,1}, /* core0 elr_EL2 bit13 */
			{38741,35,1}, /* core0 elr_EL2 bit14 */
			{38546,35,1}, /* core0 elr_EL2 bit15 */
			{38751,35,1}, /* core0 elr_EL2 bit16 */
			{38744,35,1}, /* core0 elr_EL2 bit17 */
			{38743,35,1}, /* core0 elr_EL2 bit18 */
			{38738,35,1}, /* core0 elr_EL2 bit19 */
			{32538,35,1}, /* core0 elr_EL2 bit20 */
			{38736,35,1}, /* core0 elr_EL2 bit21 */
			{38746,35,1}, /* core0 elr_EL2 bit22 */
			{38737,35,1}, /* core0 elr_EL2 bit23 */
			{32537,35,1}, /* core0 elr_EL2 bit24 */
			{38745,35,1}, /* core0 elr_EL2 bit25 */
			{38735,35,1}, /* core0 elr_EL2 bit26 */
			{29784,35,1}, /* core0 elr_EL2 bit27 */
			{38748,35,1}, /* core0 elr_EL2 bit28 */
			{32536,35,1}, /* core0 elr_EL2 bit29 */
			{32535,35,1}, /* core0 elr_EL2 bit30 */
			{38747,35,1}, /* core0 elr_EL2 bit31 */
			{32362,35,1}, /* core0 elr_EL2 bit32 */
			{32361,35,1}, /* core0 elr_EL2 bit33 */
			{32416,35,1}, /* core0 elr_EL2 bit34 */
			{32415,35,1}, /* core0 elr_EL2 bit35 */
			{33348,35,1}, /* core0 elr_EL2 bit36 */
			{32360,35,1}, /* core0 elr_EL2 bit37 */
			{32414,35,1}, /* core0 elr_EL2 bit38 */
			{32413,35,1}, /* core0 elr_EL2 bit39 */
			{32410,35,1}, /* core0 elr_EL2 bit40 */
			{32264,35,1}, /* core0 elr_EL2 bit41 */
			{32263,35,1}, /* core0 elr_EL2 bit42 */
			{32409,35,1}, /* core0 elr_EL2 bit43 */
			{32412,35,1}, /* core0 elr_EL2 bit44 */
			{32411,35,1}, /* core0 elr_EL2 bit45 */
			{29736,35,1}, /* core0 elr_EL2 bit46 */
			{32358,35,1}, /* core0 elr_EL2 bit47 */
			{32354,35,1}, /* core0 elr_EL2 bit48 */
			{33358,35,1}, /* core0 elr_EL2 bit49 */
			{32244,35,1}, /* core0 elr_EL2 bit50 */
			{32357,35,1}, /* core0 elr_EL2 bit51 */
			{32246,35,1}, /* core0 elr_EL2 bit52 */
			{32353,35,1}, /* core0 elr_EL2 bit53 */
			{32352,35,1}, /* core0 elr_EL2 bit54 */
			{32242,35,1}, /* core0 elr_EL2 bit55 */
			{32243,35,1}, /* core0 elr_EL2 bit56 */
			{32356,35,1}, /* core0 elr_EL2 bit57 */
			{33359,35,1}, /* core0 elr_EL2 bit58 */
			{32241,35,1}, /* core0 elr_EL2 bit59 */
			{32245,35,1}, /* core0 elr_EL2 bit60 */
			{32351,35,1}, /* core0 elr_EL2 bit61 */
			{32355,35,1}, /* core0 elr_EL2 bit62 */
			{32359,35,1}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{33256,35,1}, /* core0 elr_EL3 bit0 */
			{33260,35,1}, /* core0 elr_EL3 bit1 */
			{33259,35,1}, /* core0 elr_EL3 bit2 */
			{29173,35,1}, /* core0 elr_EL3 bit3 */
			{38756,35,1}, /* core0 elr_EL3 bit4 */
			{38870,35,1}, /* core0 elr_EL3 bit5 */
			{29169,35,1}, /* core0 elr_EL3 bit6 */
			{29168,35,1}, /* core0 elr_EL3 bit7 */
			{33255,35,1}, /* core0 elr_EL3 bit8 */
			{29171,35,1}, /* core0 elr_EL3 bit9 */
			{33258,35,1}, /* core0 elr_EL3 bit10 */
			{38755,35,1}, /* core0 elr_EL3 bit11 */
			{33254,35,1}, /* core0 elr_EL3 bit12 */
			{33253,35,1}, /* core0 elr_EL3 bit13 */
			{33257,35,1}, /* core0 elr_EL3 bit14 */
			{38401,35,1}, /* core0 elr_EL3 bit15 */
			{29170,35,1}, /* core0 elr_EL3 bit16 */
			{38869,35,1}, /* core0 elr_EL3 bit17 */
			{38403,35,1}, /* core0 elr_EL3 bit18 */
			{38400,35,1}, /* core0 elr_EL3 bit19 */
			{29179,35,1}, /* core0 elr_EL3 bit20 */
			{29181,35,1}, /* core0 elr_EL3 bit21 */
			{29177,35,1}, /* core0 elr_EL3 bit22 */
			{29180,35,1}, /* core0 elr_EL3 bit23 */
			{38404,35,1}, /* core0 elr_EL3 bit24 */
			{38402,35,1}, /* core0 elr_EL3 bit25 */
			{38405,35,1}, /* core0 elr_EL3 bit26 */
			{29176,35,1}, /* core0 elr_EL3 bit27 */
			{29175,35,1}, /* core0 elr_EL3 bit28 */
			{29178,35,1}, /* core0 elr_EL3 bit29 */
			{29174,35,1}, /* core0 elr_EL3 bit30 */
			{29172,35,1}, /* core0 elr_EL3 bit31 */
			{33349,35,1}, /* core0 elr_EL3 bit32 */
			{32366,35,1}, /* core0 elr_EL3 bit33 */
			{32365,35,1}, /* core0 elr_EL3 bit34 */
			{32100,35,1}, /* core0 elr_EL3 bit35 */
			{32099,35,1}, /* core0 elr_EL3 bit36 */
			{32364,35,1}, /* core0 elr_EL3 bit37 */
			{32408,35,1}, /* core0 elr_EL3 bit38 */
			{29735,35,1}, /* core0 elr_EL3 bit39 */
			{32404,35,1}, /* core0 elr_EL3 bit40 */
			{32403,35,1}, /* core0 elr_EL3 bit41 */
			{32407,35,1}, /* core0 elr_EL3 bit42 */
			{32406,35,1}, /* core0 elr_EL3 bit43 */
			{32402,35,1}, /* core0 elr_EL3 bit44 */
			{32401,35,1}, /* core0 elr_EL3 bit45 */
			{32405,35,1}, /* core0 elr_EL3 bit46 */
			{38198,35,1}, /* core0 elr_EL3 bit47 */
			{38197,35,1}, /* core0 elr_EL3 bit48 */
			{32250,35,1}, /* core0 elr_EL3 bit49 */
			{38196,35,1}, /* core0 elr_EL3 bit50 */
			{33357,35,1}, /* core0 elr_EL3 bit51 */
			{32430,35,1}, /* core0 elr_EL3 bit52 */
			{32248,35,1}, /* core0 elr_EL3 bit53 */
			{33354,35,1}, /* core0 elr_EL3 bit54 */
			{32429,35,1}, /* core0 elr_EL3 bit55 */
			{32096,35,1}, /* core0 elr_EL3 bit56 */
			{33355,35,1}, /* core0 elr_EL3 bit57 */
			{32095,35,1}, /* core0 elr_EL3 bit58 */
			{32247,35,1}, /* core0 elr_EL3 bit59 */
			{32249,35,1}, /* core0 elr_EL3 bit60 */
			{33356,35,1}, /* core0 elr_EL3 bit61 */
			{38195,35,1}, /* core0 elr_EL3 bit62 */
			{32363,35,1}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31360,35,1}, /* core0 raw_pc bit0 */
			{31359,35,1}, /* core0 raw_pc bit1 */
			{36945,35,1}, /* core0 raw_pc bit2 */
			{36947,35,1}, /* core0 raw_pc bit3 */
			{31357,35,1}, /* core0 raw_pc bit4 */
			{31358,35,1}, /* core0 raw_pc bit5 */
			{31356,35,1}, /* core0 raw_pc bit6 */
			{36950,35,1}, /* core0 raw_pc bit7 */
			{36954,35,1}, /* core0 raw_pc bit8 */
			{40774,35,1}, /* core0 raw_pc bit9 */
			{40773,35,1}, /* core0 raw_pc bit10 */
			{36949,35,1}, /* core0 raw_pc bit11 */
			{38665,35,1}, /* core0 raw_pc bit12 */
			{40776,35,1}, /* core0 raw_pc bit13 */
			{42270,35,1}, /* core0 raw_pc bit14 */
			{42269,35,1}, /* core0 raw_pc bit15 */
			{40775,35,1}, /* core0 raw_pc bit16 */
			{42601,35,1}, /* core0 raw_pc bit17 */
			{38657,35,1}, /* core0 raw_pc bit18 */
			{42600,35,1}, /* core0 raw_pc bit19 */
			{42204,35,1}, /* core0 raw_pc bit20 */
			{42268,35,1}, /* core0 raw_pc bit21 */
			{42267,35,1}, /* core0 raw_pc bit22 */
			{38664,35,1}, /* core0 raw_pc bit23 */
			{38662,35,1}, /* core0 raw_pc bit24 */
			{42599,35,1}, /* core0 raw_pc bit25 */
			{38663,35,1}, /* core0 raw_pc bit26 */
			{42203,35,1}, /* core0 raw_pc bit27 */
			{42598,35,1}, /* core0 raw_pc bit28 */
			{36951,35,1}, /* core0 raw_pc bit29 */
			{36955,35,1}, /* core0 raw_pc bit30 */
			{42208,35,1}, /* core0 raw_pc bit31 */
			{42206,35,1}, /* core0 raw_pc bit32 */
			{36896,35,1}, /* core0 raw_pc bit33 */
			{42244,35,1}, /* core0 raw_pc bit34 */
			{42212,35,1}, /* core0 raw_pc bit35 */
			{42205,35,1}, /* core0 raw_pc bit36 */
			{42207,35,1}, /* core0 raw_pc bit37 */
			{42236,35,1}, /* core0 raw_pc bit38 */
			{42243,35,1}, /* core0 raw_pc bit39 */
			{42235,35,1}, /* core0 raw_pc bit40 */
			{42234,35,1}, /* core0 raw_pc bit41 */
			{42211,35,1}, /* core0 raw_pc bit42 */
			{42242,35,1}, /* core0 raw_pc bit43 */
			{42241,35,1}, /* core0 raw_pc bit44 */
			{42233,35,1}, /* core0 raw_pc bit45 */
			{42210,35,1}, /* core0 raw_pc bit46 */
			{42209,35,1}, /* core0 raw_pc bit47 */
			{42246,35,1}, /* core0 raw_pc bit48 */
			{42245,35,1}, /* core0 raw_pc bit49 */
			{    0, 0,2}, /* core0 raw_pc bit50 */
			{    0, 0,2}, /* core0 raw_pc bit51 */
			{    0, 0,2}, /* core0 raw_pc bit52 */
			{    0, 0,2}, /* core0 raw_pc bit53 */
			{    0, 0,2}, /* core0 raw_pc bit54 */
			{    0, 0,2}, /* core0 raw_pc bit55 */
			{    0, 0,2}, /* core0 raw_pc bit56 */
			{    0, 0,2}, /* core0 raw_pc bit57 */
			{    0, 0,2}, /* core0 raw_pc bit58 */
			{    0, 0,2}, /* core0 raw_pc bit59 */
			{    0, 0,2}, /* core0 raw_pc bit60 */
			{    0, 0,2}, /* core0 raw_pc bit61 */
			{    0, 0,2}, /* core0 raw_pc bit62 */
			{    0, 0,2}, /* core0 raw_pc bit63 */
			}},
			.pc_iss = {{
			{41846,35,1}, /* core0 pc_iss bit0 */
			{41845,35,1}, /* core0 pc_iss bit1 */
			{41844,35,1}, /* core0 pc_iss bit2 */
			{36925,35,1}, /* core0 pc_iss bit3 */
			{41843,35,1}, /* core0 pc_iss bit4 */
			{41583,35,1}, /* core0 pc_iss bit5 */
			{36924,35,1}, /* core0 pc_iss bit6 */
			{41582,35,1}, /* core0 pc_iss bit7 */
			{41617,35,1}, /* core0 pc_iss bit8 */
			{38614,35,1}, /* core0 pc_iss bit9 */
			{31173,35,1}, /* core0 pc_iss bit10 */
			{31167,35,1}, /* core0 pc_iss bit11 */
			{31166,35,1}, /* core0 pc_iss bit12 */
			{41621,35,1}, /* core0 pc_iss bit13 */
			{38612,35,1}, /* core0 pc_iss bit14 */
			{41856,35,1}, /* core0 pc_iss bit15 */
			{31172,35,1}, /* core0 pc_iss bit16 */
			{41620,35,1}, /* core0 pc_iss bit17 */
			{31697,35,1}, /* core0 pc_iss bit18 */
			{41616,35,1}, /* core0 pc_iss bit19 */
			{41619,35,1}, /* core0 pc_iss bit20 */
			{41855,35,1}, /* core0 pc_iss bit21 */
			{41854,35,1}, /* core0 pc_iss bit22 */
			{41853,35,1}, /* core0 pc_iss bit23 */
			{41618,35,1}, /* core0 pc_iss bit24 */
			{41848,35,1}, /* core0 pc_iss bit25 */
			{41847,35,1}, /* core0 pc_iss bit26 */
			{41611,35,1}, /* core0 pc_iss bit27 */
			{41610,35,1}, /* core0 pc_iss bit28 */
			{31696,35,1}, /* core0 pc_iss bit29 */
			{41609,35,1}, /* core0 pc_iss bit30 */
			{41608,35,1}, /* core0 pc_iss bit31 */
			{36940,35,1}, /* core0 pc_iss bit32 */
			{41597,35,1}, /* core0 pc_iss bit33 */
			{41596,35,1}, /* core0 pc_iss bit34 */
			{36939,35,1}, /* core0 pc_iss bit35 */
			{36886,35,1}, /* core0 pc_iss bit36 */
			{31193,35,1}, /* core0 pc_iss bit37 */
			{31192,35,1}, /* core0 pc_iss bit38 */
			{36938,35,1}, /* core0 pc_iss bit39 */
			{41593,35,1}, /* core0 pc_iss bit40 */
			{41592,35,1}, /* core0 pc_iss bit41 */
			{41595,35,1}, /* core0 pc_iss bit42 */
			{38617,35,1}, /* core0 pc_iss bit43 */
			{41594,35,1}, /* core0 pc_iss bit44 */
			{38611,35,1}, /* core0 pc_iss bit45 */
			{38616,35,1}, /* core0 pc_iss bit46 */
			{38658,35,1}, /* core0 pc_iss bit47 */
			{38659,35,1}, /* core0 pc_iss bit48 */
			{31163,35,1}, /* core0 pc_iss bit49 */
			{38660,35,1}, /* core0 pc_iss bit50 */
			{42603,35,1}, /* core0 pc_iss bit51 */
			{31162,35,1}, /* core0 pc_iss bit52 */
			{42602,35,1}, /* core0 pc_iss bit53 */
			{38661,35,1}, /* core0 pc_iss bit54 */
			{42202,35,1}, /* core0 pc_iss bit55 */
			{38656,35,1}, /* core0 pc_iss bit56 */
			{42198,35,1}, /* core0 pc_iss bit57 */
			{42197,35,1}, /* core0 pc_iss bit58 */
			{42196,35,1}, /* core0 pc_iss bit59 */
			{42201,35,1}, /* core0 pc_iss bit60 */
			{42200,35,1}, /* core0 pc_iss bit61 */
			{42195,35,1}, /* core0 pc_iss bit62 */
			{42199,35,1}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31361,35,1}, /* core0 full_pc_wr bit0 */
			{    0, 0,2}, /* core0 full_pc_wr bit1 */
			{    0, 0,2}, /* core0 full_pc_wr bit2 */
			{    0, 0,2}, /* core0 full_pc_wr bit3 */
			{    0, 0,2}, /* core0 full_pc_wr bit4 */
			{    0, 0,2}, /* core0 full_pc_wr bit5 */
			{    0, 0,2}, /* core0 full_pc_wr bit6 */
			{    0, 0,2}, /* core0 full_pc_wr bit7 */
			{    0, 0,2}, /* core0 full_pc_wr bit8 */
			{    0, 0,2}, /* core0 full_pc_wr bit9 */
			{    0, 0,2}, /* core0 full_pc_wr bit10 */
			{    0, 0,2}, /* core0 full_pc_wr bit11 */
			{    0, 0,2}, /* core0 full_pc_wr bit12 */
			{    0, 0,2}, /* core0 full_pc_wr bit13 */
			{    0, 0,2}, /* core0 full_pc_wr bit14 */
			{    0, 0,2}, /* core0 full_pc_wr bit15 */
			{    0, 0,2}, /* core0 full_pc_wr bit16 */
			{    0, 0,2}, /* core0 full_pc_wr bit17 */
			{    0, 0,2}, /* core0 full_pc_wr bit18 */
			{    0, 0,2}, /* core0 full_pc_wr bit19 */
			{    0, 0,2}, /* core0 full_pc_wr bit20 */
			{    0, 0,2}, /* core0 full_pc_wr bit21 */
			{    0, 0,2}, /* core0 full_pc_wr bit22 */
			{    0, 0,2}, /* core0 full_pc_wr bit23 */
			{    0, 0,2}, /* core0 full_pc_wr bit24 */
			{    0, 0,2}, /* core0 full_pc_wr bit25 */
			{    0, 0,2}, /* core0 full_pc_wr bit26 */
			{    0, 0,2}, /* core0 full_pc_wr bit27 */
			{    0, 0,2}, /* core0 full_pc_wr bit28 */
			{    0, 0,2}, /* core0 full_pc_wr bit29 */
			{    0, 0,2}, /* core0 full_pc_wr bit30 */
			{    0, 0,2}, /* core0 full_pc_wr bit31 */
			{    0, 0,2}, /* core0 full_pc_wr bit32 */
			{    0, 0,2}, /* core0 full_pc_wr bit33 */
			{    0, 0,2}, /* core0 full_pc_wr bit34 */
			{    0, 0,2}, /* core0 full_pc_wr bit35 */
			{    0, 0,2}, /* core0 full_pc_wr bit36 */
			{    0, 0,2}, /* core0 full_pc_wr bit37 */
			{    0, 0,2}, /* core0 full_pc_wr bit38 */
			{    0, 0,2}, /* core0 full_pc_wr bit39 */
			{    0, 0,2}, /* core0 full_pc_wr bit40 */
			{    0, 0,2}, /* core0 full_pc_wr bit41 */
			{    0, 0,2}, /* core0 full_pc_wr bit42 */
			{    0, 0,2}, /* core0 full_pc_wr bit43 */
			{    0, 0,2}, /* core0 full_pc_wr bit44 */
			{    0, 0,2}, /* core0 full_pc_wr bit45 */
			{    0, 0,2}, /* core0 full_pc_wr bit46 */
			{    0, 0,2}, /* core0 full_pc_wr bit47 */
			{    0, 0,2}, /* core0 full_pc_wr bit48 */
			{    0, 0,2}, /* core0 full_pc_wr bit49 */
			{    0, 0,2}, /* core0 full_pc_wr bit50 */
			{    0, 0,2}, /* core0 full_pc_wr bit51 */
			{    0, 0,2}, /* core0 full_pc_wr bit52 */
			{    0, 0,2}, /* core0 full_pc_wr bit53 */
			{    0, 0,2}, /* core0 full_pc_wr bit54 */
			{    0, 0,2}, /* core0 full_pc_wr bit55 */
			{    0, 0,2}, /* core0 full_pc_wr bit56 */
			{    0, 0,2}, /* core0 full_pc_wr bit57 */
			{    0, 0,2}, /* core0 full_pc_wr bit58 */
			{    0, 0,2}, /* core0 full_pc_wr bit59 */
			{    0, 0,2}, /* core0 full_pc_wr bit60 */
			{    0, 0,2}, /* core0 full_pc_wr bit61 */
			{    0, 0,2}, /* core0 full_pc_wr bit62 */
			{    0, 0,2}, /* core0 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{41585,35,1}, /* core0 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{40768,35,1}, /* core0 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{27703,35,1}, /* core0 return_Stack_pointer bit0 */
			{27701,35,1}, /* core0 return_Stack_pointer bit1 */
			{14039,35,1}, /* core0 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{17696,35,1}, /* core0 return_Stack0 bit0 */
			{17695,35,1}, /* core0 return_Stack0 bit1 */
			{14923,35,1}, /* core0 return_Stack0 bit2 */
			{14929,35,1}, /* core0 return_Stack0 bit3 */
			{14928,35,1}, /* core0 return_Stack0 bit4 */
			{14931,35,1}, /* core0 return_Stack0 bit5 */
			{17596,35,1}, /* core0 return_Stack0 bit6 */
			{17595,35,1}, /* core0 return_Stack0 bit7 */
			{14922,35,1}, /* core0 return_Stack0 bit8 */
			{14919,35,1}, /* core0 return_Stack0 bit9 */
			{14920,35,1}, /* core0 return_Stack0 bit10 */
			{14911,35,1}, /* core0 return_Stack0 bit11 */
			{14921,35,1}, /* core0 return_Stack0 bit12 */
			{14925,35,1}, /* core0 return_Stack0 bit13 */
			{19268,35,1}, /* core0 return_Stack0 bit14 */
			{14924,35,1}, /* core0 return_Stack0 bit15 */
			{19252,35,1}, /* core0 return_Stack0 bit16 */
			{19251,35,1}, /* core0 return_Stack0 bit17 */
			{19266,35,1}, /* core0 return_Stack0 bit18 */
			{19265,35,1}, /* core0 return_Stack0 bit19 */
			{19267,35,1}, /* core0 return_Stack0 bit20 */
			{14930,35,1}, /* core0 return_Stack0 bit21 */
			{14932,35,1}, /* core0 return_Stack0 bit22 */
			{17694,35,1}, /* core0 return_Stack0 bit23 */
			{14994,35,1}, /* core0 return_Stack0 bit24 */
			{19364,35,1}, /* core0 return_Stack0 bit25 */
			{19538,35,1}, /* core0 return_Stack0 bit26 */
			{19537,35,1}, /* core0 return_Stack0 bit27 */
			{19540,35,1}, /* core0 return_Stack0 bit28 */
			{17616,35,1}, /* core0 return_Stack0 bit29 */
			{15000,35,1}, /* core0 return_Stack0 bit30 */
			{19539,35,1}, /* core0 return_Stack0 bit31 */
			{19363,35,1}, /* core0 return_Stack0 bit32 */
			{17615,35,1}, /* core0 return_Stack0 bit33 */
			{17614,35,1}, /* core0 return_Stack0 bit34 */
			{19534,35,1}, /* core0 return_Stack0 bit35 */
			{17620,35,1}, /* core0 return_Stack0 bit36 */
			{17619,35,1}, /* core0 return_Stack0 bit37 */
			{17618,35,1}, /* core0 return_Stack0 bit38 */
			{17688,35,1}, /* core0 return_Stack0 bit39 */
			{19533,35,1}, /* core0 return_Stack0 bit40 */
			{17687,35,1}, /* core0 return_Stack0 bit41 */
			{17617,35,1}, /* core0 return_Stack0 bit42 */
			{14996,35,1}, /* core0 return_Stack0 bit43 */
			{17686,35,1}, /* core0 return_Stack0 bit44 */
			{17685,35,1}, /* core0 return_Stack0 bit45 */
			{14935,35,1}, /* core0 return_Stack0 bit46 */
			{17613,35,1}, /* core0 return_Stack0 bit47 */
			{17693,35,1}, /* core0 return_Stack0 bit48 */
			{    0, 0,2}, /* core0 return_Stack0 bit49 */
			{    0, 0,2}, /* core0 return_Stack0 bit50 */
			{    0, 0,2}, /* core0 return_Stack0 bit51 */
			{    0, 0,2}, /* core0 return_Stack0 bit52 */
			{    0, 0,2}, /* core0 return_Stack0 bit53 */
			{    0, 0,2}, /* core0 return_Stack0 bit54 */
			{    0, 0,2}, /* core0 return_Stack0 bit55 */
			{    0, 0,2}, /* core0 return_Stack0 bit56 */
			{    0, 0,2}, /* core0 return_Stack0 bit57 */
			{    0, 0,2}, /* core0 return_Stack0 bit58 */
			{    0, 0,2}, /* core0 return_Stack0 bit59 */
			{    0, 0,2}, /* core0 return_Stack0 bit60 */
			{    0, 0,2}, /* core0 return_Stack0 bit61 */
			{    0, 0,2}, /* core0 return_Stack0 bit62 */
			{    0, 0,2}, /* core0 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{17692,35,1}, /* core0 return_Stack1 bit0 */
			{24874,35,1}, /* core0 return_Stack1 bit1 */
			{21980,35,1}, /* core0 return_Stack1 bit2 */
			{24873,35,1}, /* core0 return_Stack1 bit3 */
			{24872,35,1}, /* core0 return_Stack1 bit4 */
			{14984,35,1}, /* core0 return_Stack1 bit5 */
			{24871,35,1}, /* core0 return_Stack1 bit6 */
			{19240,35,1}, /* core0 return_Stack1 bit7 */
			{21979,35,1}, /* core0 return_Stack1 bit8 */
			{19238,35,1}, /* core0 return_Stack1 bit9 */
			{19239,35,1}, /* core0 return_Stack1 bit10 */
			{21978,35,1}, /* core0 return_Stack1 bit11 */
			{21977,35,1}, /* core0 return_Stack1 bit12 */
			{14985,35,1}, /* core0 return_Stack1 bit13 */
			{17691,35,1}, /* core0 return_Stack1 bit14 */
			{19237,35,1}, /* core0 return_Stack1 bit15 */
			{17604,35,1}, /* core0 return_Stack1 bit16 */
			{17603,35,1}, /* core0 return_Stack1 bit17 */
			{19522,35,1}, /* core0 return_Stack1 bit18 */
			{17602,35,1}, /* core0 return_Stack1 bit19 */
			{14976,35,1}, /* core0 return_Stack1 bit20 */
			{17601,35,1}, /* core0 return_Stack1 bit21 */
			{19521,35,1}, /* core0 return_Stack1 bit22 */
			{17690,35,1}, /* core0 return_Stack1 bit23 */
			{19498,35,1}, /* core0 return_Stack1 bit24 */
			{17612,35,1}, /* core0 return_Stack1 bit25 */
			{17664,35,1}, /* core0 return_Stack1 bit26 */
			{17611,35,1}, /* core0 return_Stack1 bit27 */
			{19497,35,1}, /* core0 return_Stack1 bit28 */
			{17610,35,1}, /* core0 return_Stack1 bit29 */
			{17663,35,1}, /* core0 return_Stack1 bit30 */
			{14934,35,1}, /* core0 return_Stack1 bit31 */
			{17609,35,1}, /* core0 return_Stack1 bit32 */
			{17662,35,1}, /* core0 return_Stack1 bit33 */
			{19502,35,1}, /* core0 return_Stack1 bit34 */
			{14092,35,1}, /* core0 return_Stack1 bit35 */
			{17624,35,1}, /* core0 return_Stack1 bit36 */
			{17623,35,1}, /* core0 return_Stack1 bit37 */
			{17622,35,1}, /* core0 return_Stack1 bit38 */
			{17676,35,1}, /* core0 return_Stack1 bit39 */
			{17675,35,1}, /* core0 return_Stack1 bit40 */
			{17674,35,1}, /* core0 return_Stack1 bit41 */
			{17673,35,1}, /* core0 return_Stack1 bit42 */
			{17621,35,1}, /* core0 return_Stack1 bit43 */
			{19280,35,1}, /* core0 return_Stack1 bit44 */
			{19279,35,1}, /* core0 return_Stack1 bit45 */
			{17661,35,1}, /* core0 return_Stack1 bit46 */
			{19501,35,1}, /* core0 return_Stack1 bit47 */
			{17689,35,1}, /* core0 return_Stack1 bit48 */
			{    0, 0,2}, /* core0 return_Stack1 bit49 */
			{    0, 0,2}, /* core0 return_Stack1 bit50 */
			{    0, 0,2}, /* core0 return_Stack1 bit51 */
			{    0, 0,2}, /* core0 return_Stack1 bit52 */
			{    0, 0,2}, /* core0 return_Stack1 bit53 */
			{    0, 0,2}, /* core0 return_Stack1 bit54 */
			{    0, 0,2}, /* core0 return_Stack1 bit55 */
			{    0, 0,2}, /* core0 return_Stack1 bit56 */
			{    0, 0,2}, /* core0 return_Stack1 bit57 */
			{    0, 0,2}, /* core0 return_Stack1 bit58 */
			{    0, 0,2}, /* core0 return_Stack1 bit59 */
			{    0, 0,2}, /* core0 return_Stack1 bit60 */
			{    0, 0,2}, /* core0 return_Stack1 bit61 */
			{    0, 0,2}, /* core0 return_Stack1 bit62 */
			{    0, 0,2}, /* core0 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{17700,35,1}, /* core0 return_Stack2 bit0 */
			{17699,35,1}, /* core0 return_Stack2 bit1 */
			{14901,35,1}, /* core0 return_Stack2 bit2 */
			{14933,35,1}, /* core0 return_Stack2 bit3 */
			{19264,35,1}, /* core0 return_Stack2 bit4 */
			{19236,35,1}, /* core0 return_Stack2 bit5 */
			{19263,35,1}, /* core0 return_Stack2 bit6 */
			{14907,35,1}, /* core0 return_Stack2 bit7 */
			{19228,35,1}, /* core0 return_Stack2 bit8 */
			{14902,35,1}, /* core0 return_Stack2 bit9 */
			{19235,35,1}, /* core0 return_Stack2 bit10 */
			{14904,35,1}, /* core0 return_Stack2 bit11 */
			{19227,35,1}, /* core0 return_Stack2 bit12 */
			{14915,35,1}, /* core0 return_Stack2 bit13 */
			{17698,35,1}, /* core0 return_Stack2 bit14 */
			{14905,35,1}, /* core0 return_Stack2 bit15 */
			{14916,35,1}, /* core0 return_Stack2 bit16 */
			{14914,35,1}, /* core0 return_Stack2 bit17 */
			{19276,35,1}, /* core0 return_Stack2 bit18 */
			{19275,35,1}, /* core0 return_Stack2 bit19 */
			{19274,35,1}, /* core0 return_Stack2 bit20 */
			{14981,35,1}, /* core0 return_Stack2 bit21 */
			{19273,35,1}, /* core0 return_Stack2 bit22 */
			{14982,35,1}, /* core0 return_Stack2 bit23 */
			{19362,35,1}, /* core0 return_Stack2 bit24 */
			{19361,35,1}, /* core0 return_Stack2 bit25 */
			{17660,35,1}, /* core0 return_Stack2 bit26 */
			{19492,35,1}, /* core0 return_Stack2 bit27 */
			{17656,35,1}, /* core0 return_Stack2 bit28 */
			{19491,35,1}, /* core0 return_Stack2 bit29 */
			{17655,35,1}, /* core0 return_Stack2 bit30 */
			{17654,35,1}, /* core0 return_Stack2 bit31 */
			{17653,35,1}, /* core0 return_Stack2 bit32 */
			{17659,35,1}, /* core0 return_Stack2 bit33 */
			{14993,35,1}, /* core0 return_Stack2 bit34 */
			{19496,35,1}, /* core0 return_Stack2 bit35 */
			{19494,35,1}, /* core0 return_Stack2 bit36 */
			{14088,35,1}, /* core0 return_Stack2 bit37 */
			{19493,35,1}, /* core0 return_Stack2 bit38 */
			{17672,35,1}, /* core0 return_Stack2 bit39 */
			{19495,35,1}, /* core0 return_Stack2 bit40 */
			{17671,35,1}, /* core0 return_Stack2 bit41 */
			{14091,35,1}, /* core0 return_Stack2 bit42 */
			{17670,35,1}, /* core0 return_Stack2 bit43 */
			{17669,35,1}, /* core0 return_Stack2 bit44 */
			{19859,35,1}, /* core0 return_Stack2 bit45 */
			{17658,35,1}, /* core0 return_Stack2 bit46 */
			{17657,35,1}, /* core0 return_Stack2 bit47 */
			{17697,35,1}, /* core0 return_Stack2 bit48 */
			{    0, 0,2}, /* core0 return_Stack2 bit49 */
			{    0, 0,2}, /* core0 return_Stack2 bit50 */
			{    0, 0,2}, /* core0 return_Stack2 bit51 */
			{    0, 0,2}, /* core0 return_Stack2 bit52 */
			{    0, 0,2}, /* core0 return_Stack2 bit53 */
			{    0, 0,2}, /* core0 return_Stack2 bit54 */
			{    0, 0,2}, /* core0 return_Stack2 bit55 */
			{    0, 0,2}, /* core0 return_Stack2 bit56 */
			{    0, 0,2}, /* core0 return_Stack2 bit57 */
			{    0, 0,2}, /* core0 return_Stack2 bit58 */
			{    0, 0,2}, /* core0 return_Stack2 bit59 */
			{    0, 0,2}, /* core0 return_Stack2 bit60 */
			{    0, 0,2}, /* core0 return_Stack2 bit61 */
			{    0, 0,2}, /* core0 return_Stack2 bit62 */
			{    0, 0,2}, /* core0 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{19520,35,1}, /* core0 return_Stack3 bit0 */
			{27665,35,1}, /* core0 return_Stack3 bit1 */
			{21968,35,1}, /* core0 return_Stack3 bit2 */
			{19248,35,1}, /* core0 return_Stack3 bit3 */
			{19247,35,1}, /* core0 return_Stack3 bit4 */
			{21967,35,1}, /* core0 return_Stack3 bit5 */
			{21966,35,1}, /* core0 return_Stack3 bit6 */
			{27683,35,1}, /* core0 return_Stack3 bit7 */
			{19244,35,1}, /* core0 return_Stack3 bit8 */
			{19246,35,1}, /* core0 return_Stack3 bit9 */
			{21965,35,1}, /* core0 return_Stack3 bit10 */
			{19243,35,1}, /* core0 return_Stack3 bit11 */
			{19245,35,1}, /* core0 return_Stack3 bit12 */
			{27685,35,1}, /* core0 return_Stack3 bit13 */
			{27684,35,1}, /* core0 return_Stack3 bit14 */
			{14913,35,1}, /* core0 return_Stack3 bit15 */
			{21964,35,1}, /* core0 return_Stack3 bit16 */
			{21963,35,1}, /* core0 return_Stack3 bit17 */
			{21962,35,1}, /* core0 return_Stack3 bit18 */
			{21961,35,1}, /* core0 return_Stack3 bit19 */
			{21948,35,1}, /* core0 return_Stack3 bit20 */
			{21947,35,1}, /* core0 return_Stack3 bit21 */
			{19519,35,1}, /* core0 return_Stack3 bit22 */
			{21946,35,1}, /* core0 return_Stack3 bit23 */
			{21984,35,1}, /* core0 return_Stack3 bit24 */
			{21983,35,1}, /* core0 return_Stack3 bit25 */
			{21996,35,1}, /* core0 return_Stack3 bit26 */
			{21982,35,1}, /* core0 return_Stack3 bit27 */
			{21995,35,1}, /* core0 return_Stack3 bit28 */
			{21981,35,1}, /* core0 return_Stack3 bit29 */
			{21994,35,1}, /* core0 return_Stack3 bit30 */
			{27675,35,1}, /* core0 return_Stack3 bit31 */
			{21993,35,1}, /* core0 return_Stack3 bit32 */
			{19512,35,1}, /* core0 return_Stack3 bit33 */
			{27676,35,1}, /* core0 return_Stack3 bit34 */
			{19482,35,1}, /* core0 return_Stack3 bit35 */
			{19486,35,1}, /* core0 return_Stack3 bit36 */
			{19481,35,1}, /* core0 return_Stack3 bit37 */
			{19480,35,1}, /* core0 return_Stack3 bit38 */
			{19485,35,1}, /* core0 return_Stack3 bit39 */
			{27674,35,1}, /* core0 return_Stack3 bit40 */
			{19479,35,1}, /* core0 return_Stack3 bit41 */
			{14093,35,1}, /* core0 return_Stack3 bit42 */
			{19857,35,1}, /* core0 return_Stack3 bit43 */
			{19856,35,1}, /* core0 return_Stack3 bit44 */
			{27664,35,1}, /* core0 return_Stack3 bit45 */
			{19511,35,1}, /* core0 return_Stack3 bit46 */
			{27677,35,1}, /* core0 return_Stack3 bit47 */
			{21945,35,1}, /* core0 return_Stack3 bit48 */
			{    0, 0,2}, /* core0 return_Stack3 bit49 */
			{    0, 0,2}, /* core0 return_Stack3 bit50 */
			{    0, 0,2}, /* core0 return_Stack3 bit51 */
			{    0, 0,2}, /* core0 return_Stack3 bit52 */
			{    0, 0,2}, /* core0 return_Stack3 bit53 */
			{    0, 0,2}, /* core0 return_Stack3 bit54 */
			{    0, 0,2}, /* core0 return_Stack3 bit55 */
			{    0, 0,2}, /* core0 return_Stack3 bit56 */
			{    0, 0,2}, /* core0 return_Stack3 bit57 */
			{    0, 0,2}, /* core0 return_Stack3 bit58 */
			{    0, 0,2}, /* core0 return_Stack3 bit59 */
			{    0, 0,2}, /* core0 return_Stack3 bit60 */
			{    0, 0,2}, /* core0 return_Stack3 bit61 */
			{    0, 0,2}, /* core0 return_Stack3 bit62 */
			{    0, 0,2}, /* core0 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{17704,35,1}, /* core0 return_Stack4 bit0 */
			{17703,35,1}, /* core0 return_Stack4 bit1 */
			{19230,35,1}, /* core0 return_Stack4 bit2 */
			{14986,35,1}, /* core0 return_Stack4 bit3 */
			{14983,35,1}, /* core0 return_Stack4 bit4 */
			{19242,35,1}, /* core0 return_Stack4 bit5 */
			{14987,35,1}, /* core0 return_Stack4 bit6 */
			{19232,35,1}, /* core0 return_Stack4 bit7 */
			{19241,35,1}, /* core0 return_Stack4 bit8 */
			{19229,35,1}, /* core0 return_Stack4 bit9 */
			{14906,35,1}, /* core0 return_Stack4 bit10 */
			{14903,35,1}, /* core0 return_Stack4 bit11 */
			{19231,35,1}, /* core0 return_Stack4 bit12 */
			{19234,35,1}, /* core0 return_Stack4 bit13 */
			{14917,35,1}, /* core0 return_Stack4 bit14 */
			{19233,35,1}, /* core0 return_Stack4 bit15 */
			{17608,35,1}, /* core0 return_Stack4 bit16 */
			{17607,35,1}, /* core0 return_Stack4 bit17 */
			{19278,35,1}, /* core0 return_Stack4 bit18 */
			{15002,35,1}, /* core0 return_Stack4 bit19 */
			{19277,35,1}, /* core0 return_Stack4 bit20 */
			{17606,35,1}, /* core0 return_Stack4 bit21 */
			{17605,35,1}, /* core0 return_Stack4 bit22 */
			{17702,35,1}, /* core0 return_Stack4 bit23 */
			{19360,35,1}, /* core0 return_Stack4 bit24 */
			{19359,35,1}, /* core0 return_Stack4 bit25 */
			{15001,35,1}, /* core0 return_Stack4 bit26 */
			{19536,35,1}, /* core0 return_Stack4 bit27 */
			{17648,35,1}, /* core0 return_Stack4 bit28 */
			{19535,35,1}, /* core0 return_Stack4 bit29 */
			{17647,35,1}, /* core0 return_Stack4 bit30 */
			{17646,35,1}, /* core0 return_Stack4 bit31 */
			{17645,35,1}, /* core0 return_Stack4 bit32 */
			{17652,35,1}, /* core0 return_Stack4 bit33 */
			{17651,35,1}, /* core0 return_Stack4 bit34 */
			{19532,35,1}, /* core0 return_Stack4 bit35 */
			{14087,35,1}, /* core0 return_Stack4 bit36 */
			{19530,35,1}, /* core0 return_Stack4 bit37 */
			{19869,35,1}, /* core0 return_Stack4 bit38 */
			{17708,35,1}, /* core0 return_Stack4 bit39 */
			{19531,35,1}, /* core0 return_Stack4 bit40 */
			{17707,35,1}, /* core0 return_Stack4 bit41 */
			{19529,35,1}, /* core0 return_Stack4 bit42 */
			{19862,35,1}, /* core0 return_Stack4 bit43 */
			{17706,35,1}, /* core0 return_Stack4 bit44 */
			{17705,35,1}, /* core0 return_Stack4 bit45 */
			{17650,35,1}, /* core0 return_Stack4 bit46 */
			{17649,35,1}, /* core0 return_Stack4 bit47 */
			{17701,35,1}, /* core0 return_Stack4 bit48 */
			{    0, 0,2}, /* core0 return_Stack4 bit49 */
			{    0, 0,2}, /* core0 return_Stack4 bit50 */
			{    0, 0,2}, /* core0 return_Stack4 bit51 */
			{    0, 0,2}, /* core0 return_Stack4 bit52 */
			{    0, 0,2}, /* core0 return_Stack4 bit53 */
			{    0, 0,2}, /* core0 return_Stack4 bit54 */
			{    0, 0,2}, /* core0 return_Stack4 bit55 */
			{    0, 0,2}, /* core0 return_Stack4 bit56 */
			{    0, 0,2}, /* core0 return_Stack4 bit57 */
			{    0, 0,2}, /* core0 return_Stack4 bit58 */
			{    0, 0,2}, /* core0 return_Stack4 bit59 */
			{    0, 0,2}, /* core0 return_Stack4 bit60 */
			{    0, 0,2}, /* core0 return_Stack4 bit61 */
			{    0, 0,2}, /* core0 return_Stack4 bit62 */
			{    0, 0,2}, /* core0 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{27686,35,1}, /* core0 return_Stack5 bit0 */
			{14936,35,1}, /* core0 return_Stack5 bit1 */
			{19224,35,1}, /* core0 return_Stack5 bit2 */
			{21976,35,1}, /* core0 return_Stack5 bit3 */
			{19254,35,1}, /* core0 return_Stack5 bit4 */
			{19253,35,1}, /* core0 return_Stack5 bit5 */
			{14918,35,1}, /* core0 return_Stack5 bit6 */
			{21975,35,1}, /* core0 return_Stack5 bit7 */
			{21974,35,1}, /* core0 return_Stack5 bit8 */
			{19226,35,1}, /* core0 return_Stack5 bit9 */
			{21973,35,1}, /* core0 return_Stack5 bit10 */
			{19225,35,1}, /* core0 return_Stack5 bit11 */
			{19223,35,1}, /* core0 return_Stack5 bit12 */
			{14975,35,1}, /* core0 return_Stack5 bit13 */
			{19262,35,1}, /* core0 return_Stack5 bit14 */
			{14910,35,1}, /* core0 return_Stack5 bit15 */
			{19250,35,1}, /* core0 return_Stack5 bit16 */
			{19261,35,1}, /* core0 return_Stack5 bit17 */
			{21952,35,1}, /* core0 return_Stack5 bit18 */
			{21951,35,1}, /* core0 return_Stack5 bit19 */
			{21950,35,1}, /* core0 return_Stack5 bit20 */
			{19249,35,1}, /* core0 return_Stack5 bit21 */
			{21949,35,1}, /* core0 return_Stack5 bit22 */
			{19514,35,1}, /* core0 return_Stack5 bit23 */
			{19488,35,1}, /* core0 return_Stack5 bit24 */
			{19487,35,1}, /* core0 return_Stack5 bit25 */
			{17680,35,1}, /* core0 return_Stack5 bit26 */
			{17679,35,1}, /* core0 return_Stack5 bit27 */
			{17678,35,1}, /* core0 return_Stack5 bit28 */
			{19490,35,1}, /* core0 return_Stack5 bit29 */
			{17677,35,1}, /* core0 return_Stack5 bit30 */
			{19526,35,1}, /* core0 return_Stack5 bit31 */
			{27663,35,1}, /* core0 return_Stack5 bit32 */
			{27668,35,1}, /* core0 return_Stack5 bit33 */
			{19489,35,1}, /* core0 return_Stack5 bit34 */
			{19864,35,1}, /* core0 return_Stack5 bit35 */
			{17712,35,1}, /* core0 return_Stack5 bit36 */
			{17711,35,1}, /* core0 return_Stack5 bit37 */
			{17710,35,1}, /* core0 return_Stack5 bit38 */
			{14094,35,1}, /* core0 return_Stack5 bit39 */
			{17684,35,1}, /* core0 return_Stack5 bit40 */
			{19858,35,1}, /* core0 return_Stack5 bit41 */
			{17683,35,1}, /* core0 return_Stack5 bit42 */
			{17709,35,1}, /* core0 return_Stack5 bit43 */
			{17682,35,1}, /* core0 return_Stack5 bit44 */
			{17681,35,1}, /* core0 return_Stack5 bit45 */
			{27669,35,1}, /* core0 return_Stack5 bit46 */
			{19525,35,1}, /* core0 return_Stack5 bit47 */
			{19513,35,1}, /* core0 return_Stack5 bit48 */
			{    0, 0,2}, /* core0 return_Stack5 bit49 */
			{    0, 0,2}, /* core0 return_Stack5 bit50 */
			{    0, 0,2}, /* core0 return_Stack5 bit51 */
			{    0, 0,2}, /* core0 return_Stack5 bit52 */
			{    0, 0,2}, /* core0 return_Stack5 bit53 */
			{    0, 0,2}, /* core0 return_Stack5 bit54 */
			{    0, 0,2}, /* core0 return_Stack5 bit55 */
			{    0, 0,2}, /* core0 return_Stack5 bit56 */
			{    0, 0,2}, /* core0 return_Stack5 bit57 */
			{    0, 0,2}, /* core0 return_Stack5 bit58 */
			{    0, 0,2}, /* core0 return_Stack5 bit59 */
			{    0, 0,2}, /* core0 return_Stack5 bit60 */
			{    0, 0,2}, /* core0 return_Stack5 bit61 */
			{    0, 0,2}, /* core0 return_Stack5 bit62 */
			{    0, 0,2}, /* core0 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{14977,35,1}, /* core0 return_Stack6 bit0 */
			{14979,35,1}, /* core0 return_Stack6 bit1 */
			{24870,35,1}, /* core0 return_Stack6 bit2 */
			{14927,35,1}, /* core0 return_Stack6 bit3 */
			{17354,35,1}, /* core0 return_Stack6 bit4 */
			{17353,35,1}, /* core0 return_Stack6 bit5 */
			{24869,35,1}, /* core0 return_Stack6 bit6 */
			{19222,35,1}, /* core0 return_Stack6 bit7 */
			{24868,35,1}, /* core0 return_Stack6 bit8 */
			{14908,35,1}, /* core0 return_Stack6 bit9 */
			{19221,35,1}, /* core0 return_Stack6 bit10 */
			{24867,35,1}, /* core0 return_Stack6 bit11 */
			{14909,35,1}, /* core0 return_Stack6 bit12 */
			{14926,35,1}, /* core0 return_Stack6 bit13 */
			{17600,35,1}, /* core0 return_Stack6 bit14 */
			{14912,35,1}, /* core0 return_Stack6 bit15 */
			{19260,35,1}, /* core0 return_Stack6 bit16 */
			{17599,35,1}, /* core0 return_Stack6 bit17 */
			{17598,35,1}, /* core0 return_Stack6 bit18 */
			{19259,35,1}, /* core0 return_Stack6 bit19 */
			{19272,35,1}, /* core0 return_Stack6 bit20 */
			{17597,35,1}, /* core0 return_Stack6 bit21 */
			{19271,35,1}, /* core0 return_Stack6 bit22 */
			{14980,35,1}, /* core0 return_Stack6 bit23 */
			{14991,35,1}, /* core0 return_Stack6 bit24 */
			{17668,35,1}, /* core0 return_Stack6 bit25 */
			{19508,35,1}, /* core0 return_Stack6 bit26 */
			{19504,35,1}, /* core0 return_Stack6 bit27 */
			{19503,35,1}, /* core0 return_Stack6 bit28 */
			{14992,35,1}, /* core0 return_Stack6 bit29 */
			{17667,35,1}, /* core0 return_Stack6 bit30 */
			{17666,35,1}, /* core0 return_Stack6 bit31 */
			{17665,35,1}, /* core0 return_Stack6 bit32 */
			{19500,35,1}, /* core0 return_Stack6 bit33 */
			{14089,35,1}, /* core0 return_Stack6 bit34 */
			{19868,35,1}, /* core0 return_Stack6 bit35 */
			{19476,35,1}, /* core0 return_Stack6 bit36 */
			{19475,35,1}, /* core0 return_Stack6 bit37 */
			{19478,35,1}, /* core0 return_Stack6 bit38 */
			{19524,35,1}, /* core0 return_Stack6 bit39 */
			{19477,35,1}, /* core0 return_Stack6 bit40 */
			{19506,35,1}, /* core0 return_Stack6 bit41 */
			{19865,35,1}, /* core0 return_Stack6 bit42 */
			{19505,35,1}, /* core0 return_Stack6 bit43 */
			{19863,35,1}, /* core0 return_Stack6 bit44 */
			{19523,35,1}, /* core0 return_Stack6 bit45 */
			{19507,35,1}, /* core0 return_Stack6 bit46 */
			{19499,35,1}, /* core0 return_Stack6 bit47 */
			{14978,35,1}, /* core0 return_Stack6 bit48 */
			{    0, 0,2}, /* core0 return_Stack6 bit49 */
			{    0, 0,2}, /* core0 return_Stack6 bit50 */
			{    0, 0,2}, /* core0 return_Stack6 bit51 */
			{    0, 0,2}, /* core0 return_Stack6 bit52 */
			{    0, 0,2}, /* core0 return_Stack6 bit53 */
			{    0, 0,2}, /* core0 return_Stack6 bit54 */
			{    0, 0,2}, /* core0 return_Stack6 bit55 */
			{    0, 0,2}, /* core0 return_Stack6 bit56 */
			{    0, 0,2}, /* core0 return_Stack6 bit57 */
			{    0, 0,2}, /* core0 return_Stack6 bit58 */
			{    0, 0,2}, /* core0 return_Stack6 bit59 */
			{    0, 0,2}, /* core0 return_Stack6 bit60 */
			{    0, 0,2}, /* core0 return_Stack6 bit61 */
			{    0, 0,2}, /* core0 return_Stack6 bit62 */
			{    0, 0,2}, /* core0 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{21956,35,1}, /* core0 return_Stack7 bit0 */
			{21960,35,1}, /* core0 return_Stack7 bit1 */
			{21972,35,1}, /* core0 return_Stack7 bit2 */
			{19256,35,1}, /* core0 return_Stack7 bit3 */
			{19258,35,1}, /* core0 return_Stack7 bit4 */
			{19257,35,1}, /* core0 return_Stack7 bit5 */
			{27678,35,1}, /* core0 return_Stack7 bit6 */
			{27679,35,1}, /* core0 return_Stack7 bit7 */
			{19255,35,1}, /* core0 return_Stack7 bit8 */
			{21971,35,1}, /* core0 return_Stack7 bit9 */
			{21970,35,1}, /* core0 return_Stack7 bit10 */
			{27680,35,1}, /* core0 return_Stack7 bit11 */
			{21969,35,1}, /* core0 return_Stack7 bit12 */
			{21959,35,1}, /* core0 return_Stack7 bit13 */
			{21958,35,1}, /* core0 return_Stack7 bit14 */
			{21957,35,1}, /* core0 return_Stack7 bit15 */
			{27682,35,1}, /* core0 return_Stack7 bit16 */
			{27681,35,1}, /* core0 return_Stack7 bit17 */
			{21955,35,1}, /* core0 return_Stack7 bit18 */
			{21954,35,1}, /* core0 return_Stack7 bit19 */
			{19518,35,1}, /* core0 return_Stack7 bit20 */
			{21953,35,1}, /* core0 return_Stack7 bit21 */
			{19516,35,1}, /* core0 return_Stack7 bit22 */
			{19515,35,1}, /* core0 return_Stack7 bit23 */
			{21992,35,1}, /* core0 return_Stack7 bit24 */
			{19528,35,1}, /* core0 return_Stack7 bit25 */
			{21988,35,1}, /* core0 return_Stack7 bit26 */
			{21991,35,1}, /* core0 return_Stack7 bit27 */
			{21990,35,1}, /* core0 return_Stack7 bit28 */
			{19484,35,1}, /* core0 return_Stack7 bit29 */
			{21989,35,1}, /* core0 return_Stack7 bit30 */
			{21987,35,1}, /* core0 return_Stack7 bit31 */
			{21986,35,1}, /* core0 return_Stack7 bit32 */
			{21985,35,1}, /* core0 return_Stack7 bit33 */
			{19483,35,1}, /* core0 return_Stack7 bit34 */
			{14090,35,1}, /* core0 return_Stack7 bit35 */
			{14097,35,1}, /* core0 return_Stack7 bit36 */
			{19867,35,1}, /* core0 return_Stack7 bit37 */
			{27673,35,1}, /* core0 return_Stack7 bit38 */
			{14095,35,1}, /* core0 return_Stack7 bit39 */
			{19861,35,1}, /* core0 return_Stack7 bit40 */
			{27672,35,1}, /* core0 return_Stack7 bit41 */
			{19866,35,1}, /* core0 return_Stack7 bit42 */
			{14096,35,1}, /* core0 return_Stack7 bit43 */
			{19860,35,1}, /* core0 return_Stack7 bit44 */
			{27671,35,1}, /* core0 return_Stack7 bit45 */
			{27670,35,1}, /* core0 return_Stack7 bit46 */
			{19527,35,1}, /* core0 return_Stack7 bit47 */
			{19517,35,1}, /* core0 return_Stack7 bit48 */
			{    0, 0,2}, /* core0 return_Stack7 bit49 */
			{    0, 0,2}, /* core0 return_Stack7 bit50 */
			{    0, 0,2}, /* core0 return_Stack7 bit51 */
			{    0, 0,2}, /* core0 return_Stack7 bit52 */
			{    0, 0,2}, /* core0 return_Stack7 bit53 */
			{    0, 0,2}, /* core0 return_Stack7 bit54 */
			{    0, 0,2}, /* core0 return_Stack7 bit55 */
			{    0, 0,2}, /* core0 return_Stack7 bit56 */
			{    0, 0,2}, /* core0 return_Stack7 bit57 */
			{    0, 0,2}, /* core0 return_Stack7 bit58 */
			{    0, 0,2}, /* core0 return_Stack7 bit59 */
			{    0, 0,2}, /* core0 return_Stack7 bit60 */
			{    0, 0,2}, /* core0 return_Stack7 bit61 */
			{    0, 0,2}, /* core0 return_Stack7 bit62 */
			{    0, 0,2}, /* core0 return_Stack7 bit63 */
			}},
			.ECC_err0status_v = {{
			{37289,35,1}, /* core0 ECC_err0status_v bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_v bit63 */
			}},
			.ECC_err0status_ue = {{
			{37575,35,1}, /* core0 ECC_err0status_ue bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_ue bit63 */
			}},
			.ECC_err0status_er = {{
			{37576,35,1}, /* core0 ECC_err0status_er bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_er bit63 */
			}},
			.ECC_err0status_of = {{
			{31882,35,1}, /* core0 ECC_err0status_of bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_of bit63 */
			}},
			.ECC_err0status_mv = {{
			{37291,35,1}, /* core0 ECC_err0status_mv bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_mv bit63 */
			}},
			.ECC_err0status_ce = {{
			{29902,35,1}, /* core0 ECC_err0status_ce bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_ce bit63 */
			}},
			.ECC_err0status_de = {{
			{31883,35,1}, /* core0 ECC_err0status_de bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_de bit63 */
			}},
			.ECC_err0status_pn = {{
			{37290,35,1}, /* core0 ECC_err0status_pn bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_pn bit63 */
			}},
			.ECC_err0status_ierr = {{
			{37292,35,1}, /* core0 ECC_err0status_ierr bit0 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit1 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit2 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit3 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_ierr bit63 */
			}},
			.ECC_err0status_serr = {{
			{37570,35,1}, /* core0 ECC_err0status_serr bit0 */
			{37574,35,1}, /* core0 ECC_err0status_serr bit1 */
			{37569,35,1}, /* core0 ECC_err0status_serr bit2 */
			{37573,35,1}, /* core0 ECC_err0status_serr bit3 */
			{31828,35,1}, /* core0 ECC_err0status_serr bit4 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit5 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit6 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit7 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit8 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit9 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit10 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit11 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit12 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit13 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit14 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit15 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit16 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit17 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit18 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit19 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit20 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit21 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit22 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit23 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit24 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit25 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit26 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit27 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit28 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit29 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit30 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit31 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit32 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit33 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit34 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit35 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit36 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit37 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit38 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit39 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit40 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit41 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit42 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit43 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit44 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit45 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit46 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit47 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit48 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit49 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit50 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit51 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit52 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit53 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit54 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit55 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit56 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit57 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit58 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit59 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit60 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit61 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit62 */
			{    0, 0,2}, /* core0 ECC_err0status_serr bit63 */
			}},
			.ECC_err0misc_other_err_cnt_overflow = {{
			{39790,35,1}, /* core0 ECC_err0misc_other_err_cnt_overflow bit0 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit1 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit2 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit3 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit4 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit5 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit6 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit7 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit8 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit9 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit10 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit11 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit12 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit13 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit14 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit15 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit16 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit17 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit18 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit19 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit20 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit21 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit22 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit23 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit24 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit25 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit26 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit27 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit28 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit29 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit30 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit31 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit32 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit33 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit34 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit35 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit36 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit37 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit38 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit39 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit40 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit41 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit42 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit43 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit44 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit45 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit46 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit47 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit48 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit49 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit50 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit51 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit52 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit53 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit54 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit55 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit56 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit57 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit58 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit59 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit60 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit61 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit62 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt_overflow bit63 */
			}},
			.ECC_err0misc_other_err_cnt = {{
			{34012,35,1}, /* core0 ECC_err0misc_other_err_cnt bit0 */
			{29803,35,1}, /* core0 ECC_err0misc_other_err_cnt bit1 */
			{34016,35,1}, /* core0 ECC_err0misc_other_err_cnt bit2 */
			{34015,35,1}, /* core0 ECC_err0misc_other_err_cnt bit3 */
			{34014,35,1}, /* core0 ECC_err0misc_other_err_cnt bit4 */
			{34013,35,1}, /* core0 ECC_err0misc_other_err_cnt bit5 */
			{34011,35,1}, /* core0 ECC_err0misc_other_err_cnt bit6 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit7 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit8 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit9 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit10 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit11 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit12 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit13 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit14 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit15 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit16 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit17 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit18 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit19 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit20 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit21 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit22 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit23 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit24 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit25 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit26 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit27 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit28 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit29 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit30 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit31 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit32 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit33 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit34 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit35 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit36 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit37 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit38 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit39 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit40 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit41 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit42 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit43 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit44 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit45 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit46 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit47 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit48 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit49 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit50 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit51 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit52 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit53 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit54 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit55 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit56 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit57 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit58 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit59 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit60 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit61 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit62 */
			{    0, 0,2}, /* core0 ECC_err0misc_other_err_cnt bit63 */
			}},
			.ECC_err0misc_repeat_err_overflow = {{
			{29804,35,1}, /* core0 ECC_err0misc_repeat_err_overflow bit0 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit1 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit2 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit3 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit4 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit5 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit6 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit7 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit8 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit9 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit10 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit11 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit12 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit13 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit14 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit15 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit16 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit17 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit18 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit19 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit20 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit21 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit22 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit23 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit24 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit25 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit26 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit27 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit28 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit29 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit30 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit31 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit32 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit33 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit34 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit35 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit36 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit37 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit38 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit39 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit40 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit41 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit42 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit43 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit44 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit45 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit46 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit47 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit48 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit49 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit50 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit51 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit52 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit53 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit54 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit55 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit56 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit57 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit58 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit59 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit60 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit61 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit62 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_overflow bit63 */
			}},
			.ECC_err0misc_repeat_err_cnt = {{
			{34010,35,1}, /* core0 ECC_err0misc_repeat_err_cnt bit0 */
			{39789,35,1}, /* core0 ECC_err0misc_repeat_err_cnt bit1 */
			{39788,35,1}, /* core0 ECC_err0misc_repeat_err_cnt bit2 */
			{39787,35,1}, /* core0 ECC_err0misc_repeat_err_cnt bit3 */
			{39786,35,1}, /* core0 ECC_err0misc_repeat_err_cnt bit4 */
			{39785,35,1}, /* core0 ECC_err0misc_repeat_err_cnt bit5 */
			{34009,35,1}, /* core0 ECC_err0misc_repeat_err_cnt bit6 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit7 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit8 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit9 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit10 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit11 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit12 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit13 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit14 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit15 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit16 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit17 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit18 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit19 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit20 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit21 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit22 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit23 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit24 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit25 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit26 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit27 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit28 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit29 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit30 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit31 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit32 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit33 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit34 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit35 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit36 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit37 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit38 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit39 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit40 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit41 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit42 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit43 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit44 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit45 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit46 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit47 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit48 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit49 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit50 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit51 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit52 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit53 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit54 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit55 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit56 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit57 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit58 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit59 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit60 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit61 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit62 */
			{    0, 0,2}, /* core0 ECC_err0misc_repeat_err_cnt bit63 */
			}},
			.ECC_err0misc_way = {{
			{43026,35,1}, /* core0 ECC_err0misc_way bit0 */
			{43025,35,1}, /* core0 ECC_err0misc_way bit1 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit2 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit3 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit4 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit5 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit6 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit7 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit8 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit9 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit10 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit11 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit12 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit13 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit14 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit15 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit16 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit17 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit18 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit19 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit20 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit21 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit22 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit23 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit24 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit25 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit26 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit27 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit28 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit29 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit30 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit31 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit32 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit33 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit34 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit35 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit36 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit37 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit38 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit39 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit40 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit41 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit42 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit43 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit44 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit45 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit46 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit47 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit48 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit49 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit50 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit51 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit52 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit53 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit54 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit55 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit56 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit57 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit58 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit59 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit60 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit61 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit62 */
			{    0, 0,2}, /* core0 ECC_err0misc_way bit63 */
			}},
			.ECC_err0misc_index = {{
			{37296,35,1}, /* core0 ECC_err0misc_index bit0 */
			{37754,35,1}, /* core0 ECC_err0misc_index bit1 */
			{31917,35,1}, /* core0 ECC_err0misc_index bit2 */
			{31916,35,1}, /* core0 ECC_err0misc_index bit3 */
			{43029,35,1}, /* core0 ECC_err0misc_index bit4 */
			{43028,35,1}, /* core0 ECC_err0misc_index bit5 */
			{43027,35,1}, /* core0 ECC_err0misc_index bit6 */
			{37753,35,1}, /* core0 ECC_err0misc_index bit7 */
			{43030,35,1}, /* core0 ECC_err0misc_index bit8 */
			{37295,35,1}, /* core0 ECC_err0misc_index bit9 */
			{37294,35,1}, /* core0 ECC_err0misc_index bit10 */
			{37293,35,1}, /* core0 ECC_err0misc_index bit11 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit12 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit13 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit14 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit15 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit16 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit17 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit18 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit19 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit20 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit21 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit22 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit23 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit24 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit25 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit26 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit27 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit28 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit29 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit30 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit31 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit32 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit33 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit34 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit35 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit36 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit37 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit38 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit39 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit40 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit41 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit42 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit43 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit44 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit45 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit46 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit47 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit48 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit49 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit50 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit51 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit52 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit53 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit54 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit55 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit56 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit57 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit58 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit59 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit60 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit61 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit62 */
			{    0, 0,2}, /* core0 ECC_err0misc_index bit63 */
			}},
			.ECC_err0misc_level_contain_error = {{
			{37571,35,1}, /* core0 ECC_err0misc_level_contain_error bit0 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit1 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit2 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit3 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit4 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit5 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit6 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit7 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit8 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit9 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit10 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit11 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit12 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit13 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit14 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit15 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit16 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit17 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit18 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit19 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit20 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit21 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit22 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit23 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit24 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit25 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit26 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit27 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit28 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit29 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit30 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit31 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit32 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit33 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit34 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit35 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit36 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit37 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit38 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit39 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit40 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit41 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit42 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit43 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit44 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit45 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit46 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit47 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit48 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit49 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit50 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit51 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit52 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit53 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit54 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit55 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit56 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit57 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit58 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit59 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit60 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit61 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit62 */
			{    0, 0,2}, /* core0 ECC_err0misc_level_contain_error bit63 */
			}},
			.ECC_err0misc_indicate_icache = {{
			{37572,35,1}, /* core0 ECC_err0misc_indicate_icache bit0 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit1 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit2 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit3 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit4 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit5 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit6 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit7 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit8 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit9 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit10 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit11 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit12 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit13 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit14 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit15 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit16 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit17 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit18 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit19 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit20 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit21 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit22 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit23 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit24 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit25 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit26 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit27 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit28 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit29 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit30 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit31 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit32 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit33 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit34 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit35 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit36 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit37 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit38 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit39 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit40 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit41 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit42 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit43 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit44 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit45 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit46 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit47 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit48 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit49 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit50 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit51 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit52 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit53 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit54 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit55 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit56 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit57 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit58 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit59 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit60 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit61 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit62 */
			{    0, 0,2}, /* core0 ECC_err0misc_indicate_icache bit63 */
			}},
			.ECC_err0ctrl_fault_handling_interrupt = {{
			{29905,35,1}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit0 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit1 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit2 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit3 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit4 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit5 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit6 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit7 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit8 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit9 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit10 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit11 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit12 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit13 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit14 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit15 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit16 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit17 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit18 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit19 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit20 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit21 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit22 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit23 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit24 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit25 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit26 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit27 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit28 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit29 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit30 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit31 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit32 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit33 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit34 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit35 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit36 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit37 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit38 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit39 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit40 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit41 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit42 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit43 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit44 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit45 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit46 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit47 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit48 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit49 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit50 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit51 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit52 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit53 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit54 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit55 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit56 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit57 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit58 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit59 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit60 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit61 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit62 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_interrupt bit63 */
			}},
			.ECC_err0ctrl_fault_handling_int_enable = {{
			{37512,35,1}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit0 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit1 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit2 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit3 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit4 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit5 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit6 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit7 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit8 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit9 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit10 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit11 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit12 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit13 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit14 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit15 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit16 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit17 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit18 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit19 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit20 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit21 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit22 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit23 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit24 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit25 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit26 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit27 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit28 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit29 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit30 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit31 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit32 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit33 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit34 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit35 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit36 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit37 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit38 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit39 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit40 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit41 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit42 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit43 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit44 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit45 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit46 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit47 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit48 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit49 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit50 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit51 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit52 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit53 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit54 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit55 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit56 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit57 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit58 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit59 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit60 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit61 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit62 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_fault_handling_int_enable bit63 */
			}},
			.ECC_err0ctrl_error_recovery_int_enable = {{
			{37511,35,1}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit0 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit1 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit2 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit3 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit4 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit5 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit6 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit7 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit8 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit9 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit10 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit11 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit12 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit13 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit14 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit15 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit16 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit17 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit18 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit19 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit20 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit21 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit22 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit23 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit24 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit25 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit26 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit27 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit28 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit29 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit30 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit31 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit32 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit33 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit34 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit35 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit36 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit37 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit38 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit39 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit40 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit41 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit42 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit43 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit44 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit45 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit46 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit47 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit48 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit49 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit50 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit51 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit52 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit53 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit54 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit55 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit56 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit57 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit58 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit59 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit60 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit61 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit62 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_recovery_int_enable bit63 */
			}},
			.ECC_err0ctrl_error_detect_correct_enable = {{
			{29904,35,1}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit0 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit1 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit2 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit3 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit4 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit5 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit6 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit7 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit8 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit9 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit10 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit11 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit12 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit13 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit14 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit15 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit16 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit17 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit18 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit19 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit20 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit21 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit22 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit23 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit24 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit25 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit26 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit27 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit28 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit29 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit30 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit31 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit32 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit33 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit34 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit35 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit36 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit37 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit38 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit39 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit40 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit41 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit42 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit43 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit44 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit45 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit46 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit47 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit48 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit49 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit50 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit51 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit52 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit53 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit54 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit55 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit56 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit57 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit58 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit59 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit60 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit61 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit62 */
			{    0, 0,2}, /* core0 ECC_err0ctrl_error_detect_correct_enable bit63 */
			}},
	},
	{		/* core 1 */ 
			.pc = {{
			{  523,36,1}, /* core1 pc bit0 */
			{  240,36,1}, /* core1 pc bit1 */
			{  102,36,1}, /* core1 pc bit2 */
			{  239,36,1}, /* core1 pc bit3 */
			{  495,36,1}, /* core1 pc bit4 */
			{  203,36,1}, /* core1 pc bit5 */
			{  431,36,1}, /* core1 pc bit6 */
			{  224,36,1}, /* core1 pc bit7 */
			{  100,36,1}, /* core1 pc bit8 */
			{  236,36,1}, /* core1 pc bit9 */
			{   96,36,1}, /* core1 pc bit10 */
			{  494,36,1}, /* core1 pc bit11 */
			{  202,36,1}, /* core1 pc bit12 */
			{  543,36,1}, /* core1 pc bit13 */
			{  223,36,1}, /* core1 pc bit14 */
			{  235,36,1}, /* core1 pc bit15 */
			{   94,36,1}, /* core1 pc bit16 */
			{  356,36,1}, /* core1 pc bit17 */
			{  207,36,1}, /* core1 pc bit18 */
			{  539,36,1}, /* core1 pc bit19 */
			{  511,36,1}, /* core1 pc bit20 */
			{   95,36,1}, /* core1 pc bit21 */
			{  522,36,1}, /* core1 pc bit22 */
			{  206,36,1}, /* core1 pc bit23 */
			{  220,36,1}, /* core1 pc bit24 */
			{  234,36,1}, /* core1 pc bit25 */
			{  355,36,1}, /* core1 pc bit26 */
			{  475,36,1}, /* core1 pc bit27 */
			{  538,36,1}, /* core1 pc bit28 */
			{  537,36,1}, /* core1 pc bit29 */
			{  536,36,1}, /* core1 pc bit30 */
			{  112,36,1}, /* core1 pc bit31 */
			{  215,36,1}, /* core1 pc bit32 */
			{  547,36,1}, /* core1 pc bit33 */
			{  230,36,1}, /* core1 pc bit34 */
			{  229,36,1}, /* core1 pc bit35 */
			{  491,36,1}, /* core1 pc bit36 */
			{  546,36,1}, /* core1 pc bit37 */
			{  423,36,1}, /* core1 pc bit38 */
			{  427,36,1}, /* core1 pc bit39 */
			{  211,36,1}, /* core1 pc bit40 */
			{  110,36,1}, /* core1 pc bit41 */
			{  367,36,1}, /* core1 pc bit42 */
			{  214,36,1}, /* core1 pc bit43 */
			{  542,36,1}, /* core1 pc bit44 */
			{  545,36,1}, /* core1 pc bit45 */
			{  426,36,1}, /* core1 pc bit46 */
			{  369,36,1}, /* core1 pc bit47 */
			{  425,36,1}, /* core1 pc bit48 */
			{  368,36,1}, /* core1 pc bit49 */
			{  430,36,1}, /* core1 pc bit50 */
			{  213,36,1}, /* core1 pc bit51 */
			{  212,36,1}, /* core1 pc bit52 */
			{  232,36,1}, /* core1 pc bit53 */
			{  535,36,1}, /* core1 pc bit54 */
			{  422,36,1}, /* core1 pc bit55 */
			{  490,36,1}, /* core1 pc bit56 */
			{  114,36,1}, /* core1 pc bit57 */
			{  415,36,1}, /* core1 pc bit58 */
			{  116,36,1}, /* core1 pc bit59 */
			{  429,36,1}, /* core1 pc bit60 */
			{  421,36,1}, /* core1 pc bit61 */
			{  420,36,1}, /* core1 pc bit62 */
			{  534,36,1}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{33132,37,1}, /* core1 sp32 bit0 */
			{33140,37,1}, /* core1 sp32 bit1 */
			{39344,37,1}, /* core1 sp32 bit2 */
			{39224,37,1}, /* core1 sp32 bit3 */
			{39343,37,1}, /* core1 sp32 bit4 */
			{33200,37,1}, /* core1 sp32 bit5 */
			{33199,37,1}, /* core1 sp32 bit6 */
			{38350,37,1}, /* core1 sp32 bit7 */
			{33128,37,1}, /* core1 sp32 bit8 */
			{33127,37,1}, /* core1 sp32 bit9 */
			{33198,37,1}, /* core1 sp32 bit10 */
			{39350,37,1}, /* core1 sp32 bit11 */
			{39240,37,1}, /* core1 sp32 bit12 */
			{39239,37,1}, /* core1 sp32 bit13 */
			{39342,37,1}, /* core1 sp32 bit14 */
			{39223,37,1}, /* core1 sp32 bit15 */
			{39349,37,1}, /* core1 sp32 bit16 */
			{39242,37,1}, /* core1 sp32 bit17 */
			{33126,37,1}, /* core1 sp32 bit18 */
			{33131,37,1}, /* core1 sp32 bit19 */
			{33125,37,1}, /* core1 sp32 bit20 */
			{33139,37,1}, /* core1 sp32 bit21 */
			{38353,37,1}, /* core1 sp32 bit22 */
			{39341,37,1}, /* core1 sp32 bit23 */
			{33138,37,1}, /* core1 sp32 bit24 */
			{33130,37,1}, /* core1 sp32 bit25 */
			{33197,37,1}, /* core1 sp32 bit26 */
			{33129,37,1}, /* core1 sp32 bit27 */
			{38356,37,1}, /* core1 sp32 bit28 */
			{38352,37,1}, /* core1 sp32 bit29 */
			{39241,37,1}, /* core1 sp32 bit30 */
			{33137,37,1}, /* core1 sp32 bit31 */
			{29541,37,1}, /* core1 sp32 bit32 */
			{29629,37,1}, /* core1 sp32 bit33 */
			{43006,37,1}, /* core1 sp32 bit34 */
			{29540,37,1}, /* core1 sp32 bit35 */
			{29628,37,1}, /* core1 sp32 bit36 */
			{29539,37,1}, /* core1 sp32 bit37 */
			{32952,37,1}, /* core1 sp32 bit38 */
			{29715,37,1}, /* core1 sp32 bit39 */
			{29713,37,1}, /* core1 sp32 bit40 */
			{32951,37,1}, /* core1 sp32 bit41 */
			{32950,37,1}, /* core1 sp32 bit42 */
			{43005,37,1}, /* core1 sp32 bit43 */
			{29712,37,1}, /* core1 sp32 bit44 */
			{29714,37,1}, /* core1 sp32 bit45 */
			{32949,37,1}, /* core1 sp32 bit46 */
			{29315,37,1}, /* core1 sp32 bit47 */
			{29317,37,1}, /* core1 sp32 bit48 */
			{29409,37,1}, /* core1 sp32 bit49 */
			{29316,37,1}, /* core1 sp32 bit50 */
			{29415,37,1}, /* core1 sp32 bit51 */
			{29414,37,1}, /* core1 sp32 bit52 */
			{29407,37,1}, /* core1 sp32 bit53 */
			{29406,37,1}, /* core1 sp32 bit54 */
			{42991,37,1}, /* core1 sp32 bit55 */
			{29411,37,1}, /* core1 sp32 bit56 */
			{29413,37,1}, /* core1 sp32 bit57 */
			{29314,37,1}, /* core1 sp32 bit58 */
			{29410,37,1}, /* core1 sp32 bit59 */
			{29412,37,1}, /* core1 sp32 bit60 */
			{42989,37,1}, /* core1 sp32 bit61 */
			{29408,37,1}, /* core1 sp32 bit62 */
			{29538,37,1}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{39308,37,1}, /* core1 fp32 bit0 */
			{39246,37,1}, /* core1 fp32 bit1 */
			{33160,37,1}, /* core1 fp32 bit2 */
			{33152,37,1}, /* core1 fp32 bit3 */
			{33159,37,1}, /* core1 fp32 bit4 */
			{33151,37,1}, /* core1 fp32 bit5 */
			{39334,37,1}, /* core1 fp32 bit6 */
			{33148,37,1}, /* core1 fp32 bit7 */
			{39332,37,1}, /* core1 fp32 bit8 */
			{32636,37,1}, /* core1 fp32 bit9 */
			{32635,37,1}, /* core1 fp32 bit10 */
			{32634,37,1}, /* core1 fp32 bit11 */
			{38329,37,1}, /* core1 fp32 bit12 */
			{39304,37,1}, /* core1 fp32 bit13 */
			{39333,37,1}, /* core1 fp32 bit14 */
			{39303,37,1}, /* core1 fp32 bit15 */
			{38346,37,1}, /* core1 fp32 bit16 */
			{32633,37,1}, /* core1 fp32 bit17 */
			{33156,37,1}, /* core1 fp32 bit18 */
			{33147,37,1}, /* core1 fp32 bit19 */
			{33155,37,1}, /* core1 fp32 bit20 */
			{33154,37,1}, /* core1 fp32 bit21 */
			{33150,37,1}, /* core1 fp32 bit22 */
			{33158,37,1}, /* core1 fp32 bit23 */
			{33149,37,1}, /* core1 fp32 bit24 */
			{39307,37,1}, /* core1 fp32 bit25 */
			{39331,37,1}, /* core1 fp32 bit26 */
			{39245,37,1}, /* core1 fp32 bit27 */
			{33146,37,1}, /* core1 fp32 bit28 */
			{33153,37,1}, /* core1 fp32 bit29 */
			{33145,37,1}, /* core1 fp32 bit30 */
			{33157,37,1}, /* core1 fp32 bit31 */
			{32928,37,1}, /* core1 fp32 bit32 */
			{29285,37,1}, /* core1 fp32 bit33 */
			{29284,37,1}, /* core1 fp32 bit34 */
			{32927,37,1}, /* core1 fp32 bit35 */
			{43000,37,1}, /* core1 fp32 bit36 */
			{32926,37,1}, /* core1 fp32 bit37 */
			{29295,37,1}, /* core1 fp32 bit38 */
			{29291,37,1}, /* core1 fp32 bit39 */
			{29287,37,1}, /* core1 fp32 bit40 */
			{42999,37,1}, /* core1 fp32 bit41 */
			{38251,37,1}, /* core1 fp32 bit42 */
			{38250,37,1}, /* core1 fp32 bit43 */
			{29294,37,1}, /* core1 fp32 bit44 */
			{29286,37,1}, /* core1 fp32 bit45 */
			{29290,37,1}, /* core1 fp32 bit46 */
			{33012,37,1}, /* core1 fp32 bit47 */
			{33011,37,1}, /* core1 fp32 bit48 */
			{33010,37,1}, /* core1 fp32 bit49 */
			{29443,37,1}, /* core1 fp32 bit50 */
			{33009,37,1}, /* core1 fp32 bit51 */
			{29447,37,1}, /* core1 fp32 bit52 */
			{29442,37,1}, /* core1 fp32 bit53 */
			{34234,37,1}, /* core1 fp32 bit54 */
			{29297,37,1}, /* core1 fp32 bit55 */
			{29446,37,1}, /* core1 fp32 bit56 */
			{29296,37,1}, /* core1 fp32 bit57 */
			{29445,37,1}, /* core1 fp32 bit58 */
			{34235,37,1}, /* core1 fp32 bit59 */
			{29444,37,1}, /* core1 fp32 bit60 */
			{29441,37,1}, /* core1 fp32 bit61 */
			{29440,37,1}, /* core1 fp32 bit62 */
			{32925,37,1}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{32660,37,1}, /* core1 fp64 bit0 */
			{32668,37,1}, /* core1 fp64 bit1 */
			{32659,37,1}, /* core1 fp64 bit2 */
			{32676,37,1}, /* core1 fp64 bit3 */
			{32658,37,1}, /* core1 fp64 bit4 */
			{32657,37,1}, /* core1 fp64 bit5 */
			{32656,37,1}, /* core1 fp64 bit6 */
			{38427,37,1}, /* core1 fp64 bit7 */
			{38488,37,1}, /* core1 fp64 bit8 */
			{32655,37,1}, /* core1 fp64 bit9 */
			{38428,37,1}, /* core1 fp64 bit10 */
			{32654,37,1}, /* core1 fp64 bit11 */
			{38423,37,1}, /* core1 fp64 bit12 */
			{32653,37,1}, /* core1 fp64 bit13 */
			{38490,37,1}, /* core1 fp64 bit14 */
			{38492,37,1}, /* core1 fp64 bit15 */
			{38487,37,1}, /* core1 fp64 bit16 */
			{38491,37,1}, /* core1 fp64 bit17 */
			{38489,37,1}, /* core1 fp64 bit18 */
			{32667,37,1}, /* core1 fp64 bit19 */
			{32666,37,1}, /* core1 fp64 bit20 */
			{32675,37,1}, /* core1 fp64 bit21 */
			{38856,37,1}, /* core1 fp64 bit22 */
			{32672,37,1}, /* core1 fp64 bit23 */
			{32671,37,1}, /* core1 fp64 bit24 */
			{38422,37,1}, /* core1 fp64 bit25 */
			{32665,37,1}, /* core1 fp64 bit26 */
			{32670,37,1}, /* core1 fp64 bit27 */
			{32674,37,1}, /* core1 fp64 bit28 */
			{38855,37,1}, /* core1 fp64 bit29 */
			{32673,37,1}, /* core1 fp64 bit30 */
			{32669,37,1}, /* core1 fp64 bit31 */
			{39065,37,1}, /* core1 fp64 bit32 */
			{38229,37,1}, /* core1 fp64 bit33 */
			{38227,37,1}, /* core1 fp64 bit34 */
			{39064,37,1}, /* core1 fp64 bit35 */
			{38224,37,1}, /* core1 fp64 bit36 */
			{38225,37,1}, /* core1 fp64 bit37 */
			{39069,37,1}, /* core1 fp64 bit38 */
			{39061,37,1}, /* core1 fp64 bit39 */
			{39063,37,1}, /* core1 fp64 bit40 */
			{38222,37,1}, /* core1 fp64 bit41 */
			{39071,37,1}, /* core1 fp64 bit42 */
			{39070,37,1}, /* core1 fp64 bit43 */
			{39060,37,1}, /* core1 fp64 bit44 */
			{38228,37,1}, /* core1 fp64 bit45 */
			{39068,37,1}, /* core1 fp64 bit46 */
			{39045,37,1}, /* core1 fp64 bit47 */
			{39044,37,1}, /* core1 fp64 bit48 */
			{39041,37,1}, /* core1 fp64 bit49 */
			{39037,37,1}, /* core1 fp64 bit50 */
			{29577,37,1}, /* core1 fp64 bit51 */
			{29576,37,1}, /* core1 fp64 bit52 */
			{39039,37,1}, /* core1 fp64 bit53 */
			{39038,37,1}, /* core1 fp64 bit54 */
			{29575,37,1}, /* core1 fp64 bit55 */
			{39036,37,1}, /* core1 fp64 bit56 */
			{39043,37,1}, /* core1 fp64 bit57 */
			{39042,37,1}, /* core1 fp64 bit58 */
			{30046,37,1}, /* core1 fp64 bit59 */
			{39040,37,1}, /* core1 fp64 bit60 */
			{29574,37,1}, /* core1 fp64 bit61 */
			{30045,37,1}, /* core1 fp64 bit62 */
			{39062,37,1}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{38539,37,1}, /* core1 sp_EL0 bit0 */
			{32816,37,1}, /* core1 sp_EL0 bit1 */
			{32808,37,1}, /* core1 sp_EL0 bit2 */
			{38533,37,1}, /* core1 sp_EL0 bit3 */
			{32740,37,1}, /* core1 sp_EL0 bit4 */
			{32807,37,1}, /* core1 sp_EL0 bit5 */
			{38531,37,1}, /* core1 sp_EL0 bit6 */
			{38538,37,1}, /* core1 sp_EL0 bit7 */
			{38540,37,1}, /* core1 sp_EL0 bit8 */
			{38882,37,1}, /* core1 sp_EL0 bit9 */
			{32739,37,1}, /* core1 sp_EL0 bit10 */
			{32806,37,1}, /* core1 sp_EL0 bit11 */
			{32815,37,1}, /* core1 sp_EL0 bit12 */
			{32814,37,1}, /* core1 sp_EL0 bit13 */
			{32805,37,1}, /* core1 sp_EL0 bit14 */
			{32738,37,1}, /* core1 sp_EL0 bit15 */
			{38532,37,1}, /* core1 sp_EL0 bit16 */
			{32737,37,1}, /* core1 sp_EL0 bit17 */
			{38537,37,1}, /* core1 sp_EL0 bit18 */
			{32813,37,1}, /* core1 sp_EL0 bit19 */
			{38884,37,1}, /* core1 sp_EL0 bit20 */
			{38881,37,1}, /* core1 sp_EL0 bit21 */
			{38878,37,1}, /* core1 sp_EL0 bit22 */
			{38448,37,1}, /* core1 sp_EL0 bit23 */
			{38880,37,1}, /* core1 sp_EL0 bit24 */
			{32744,37,1}, /* core1 sp_EL0 bit25 */
			{38877,37,1}, /* core1 sp_EL0 bit26 */
			{32743,37,1}, /* core1 sp_EL0 bit27 */
			{38879,37,1}, /* core1 sp_EL0 bit28 */
			{32742,37,1}, /* core1 sp_EL0 bit29 */
			{32741,37,1}, /* core1 sp_EL0 bit30 */
			{38883,37,1}, /* core1 sp_EL0 bit31 */
			{32202,37,1}, /* core1 sp_EL0 bit32 */
			{32204,37,1}, /* core1 sp_EL0 bit33 */
			{32201,37,1}, /* core1 sp_EL0 bit34 */
			{33365,37,1}, /* core1 sp_EL0 bit35 */
			{32203,37,1}, /* core1 sp_EL0 bit36 */
			{33366,37,1}, /* core1 sp_EL0 bit37 */
			{32388,37,1}, /* core1 sp_EL0 bit38 */
			{32384,37,1}, /* core1 sp_EL0 bit39 */
			{32387,37,1}, /* core1 sp_EL0 bit40 */
			{32383,37,1}, /* core1 sp_EL0 bit41 */
			{38812,37,1}, /* core1 sp_EL0 bit42 */
			{32382,37,1}, /* core1 sp_EL0 bit43 */
			{38811,37,1}, /* core1 sp_EL0 bit44 */
			{32386,37,1}, /* core1 sp_EL0 bit45 */
			{32381,37,1}, /* core1 sp_EL0 bit46 */
			{32212,37,1}, /* core1 sp_EL0 bit47 */
			{32211,37,1}, /* core1 sp_EL0 bit48 */
			{32454,37,1}, /* core1 sp_EL0 bit49 */
			{32218,37,1}, /* core1 sp_EL0 bit50 */
			{32217,37,1}, /* core1 sp_EL0 bit51 */
			{32453,37,1}, /* core1 sp_EL0 bit52 */
			{30043,37,1}, /* core1 sp_EL0 bit53 */
			{32452,37,1}, /* core1 sp_EL0 bit54 */
			{32451,37,1}, /* core1 sp_EL0 bit55 */
			{32220,37,1}, /* core1 sp_EL0 bit56 */
			{32222,37,1}, /* core1 sp_EL0 bit57 */
			{32221,37,1}, /* core1 sp_EL0 bit58 */
			{32219,37,1}, /* core1 sp_EL0 bit59 */
			{30044,37,1}, /* core1 sp_EL0 bit60 */
			{32216,37,1}, /* core1 sp_EL0 bit61 */
			{32215,37,1}, /* core1 sp_EL0 bit62 */
			{32385,37,1}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{38443,37,1}, /* core1 sp_EL1 bit0 */
			{38447,37,1}, /* core1 sp_EL1 bit1 */
			{32812,37,1}, /* core1 sp_EL1 bit2 */
			{32811,37,1}, /* core1 sp_EL1 bit3 */
			{38445,37,1}, /* core1 sp_EL1 bit4 */
			{38442,37,1}, /* core1 sp_EL1 bit5 */
			{38536,37,1}, /* core1 sp_EL1 bit6 */
			{38441,37,1}, /* core1 sp_EL1 bit7 */
			{38444,37,1}, /* core1 sp_EL1 bit8 */
			{32820,37,1}, /* core1 sp_EL1 bit9 */
			{38446,37,1}, /* core1 sp_EL1 bit10 */
			{38440,37,1}, /* core1 sp_EL1 bit11 */
			{38534,37,1}, /* core1 sp_EL1 bit12 */
			{32819,37,1}, /* core1 sp_EL1 bit13 */
			{38535,37,1}, /* core1 sp_EL1 bit14 */
			{32810,37,1}, /* core1 sp_EL1 bit15 */
			{32809,37,1}, /* core1 sp_EL1 bit16 */
			{38529,37,1}, /* core1 sp_EL1 bit17 */
			{38528,37,1}, /* core1 sp_EL1 bit18 */
			{32818,37,1}, /* core1 sp_EL1 bit19 */
			{38876,37,1}, /* core1 sp_EL1 bit20 */
			{32824,37,1}, /* core1 sp_EL1 bit21 */
			{32823,37,1}, /* core1 sp_EL1 bit22 */
			{38874,37,1}, /* core1 sp_EL1 bit23 */
			{38875,37,1}, /* core1 sp_EL1 bit24 */
			{38872,37,1}, /* core1 sp_EL1 bit25 */
			{32822,37,1}, /* core1 sp_EL1 bit26 */
			{32821,37,1}, /* core1 sp_EL1 bit27 */
			{38873,37,1}, /* core1 sp_EL1 bit28 */
			{32817,37,1}, /* core1 sp_EL1 bit29 */
			{38871,37,1}, /* core1 sp_EL1 bit30 */
			{38530,37,1}, /* core1 sp_EL1 bit31 */
			{32376,37,1}, /* core1 sp_EL1 bit32 */
			{32375,37,1}, /* core1 sp_EL1 bit33 */
			{32374,37,1}, /* core1 sp_EL1 bit34 */
			{32208,37,1}, /* core1 sp_EL1 bit35 */
			{30040,37,1}, /* core1 sp_EL1 bit36 */
			{32207,37,1}, /* core1 sp_EL1 bit37 */
			{39083,37,1}, /* core1 sp_EL1 bit38 */
			{39081,37,1}, /* core1 sp_EL1 bit39 */
			{39082,37,1}, /* core1 sp_EL1 bit40 */
			{33364,37,1}, /* core1 sp_EL1 bit41 */
			{38810,37,1}, /* core1 sp_EL1 bit42 */
			{29724,37,1}, /* core1 sp_EL1 bit43 */
			{38809,37,1}, /* core1 sp_EL1 bit44 */
			{39080,37,1}, /* core1 sp_EL1 bit45 */
			{29740,37,1}, /* core1 sp_EL1 bit46 */
			{32214,37,1}, /* core1 sp_EL1 bit47 */
			{32450,37,1}, /* core1 sp_EL1 bit48 */
			{32442,37,1}, /* core1 sp_EL1 bit49 */
			{32441,37,1}, /* core1 sp_EL1 bit50 */
			{32449,37,1}, /* core1 sp_EL1 bit51 */
			{32440,37,1}, /* core1 sp_EL1 bit52 */
			{32224,37,1}, /* core1 sp_EL1 bit53 */
			{32446,37,1}, /* core1 sp_EL1 bit54 */
			{32213,37,1}, /* core1 sp_EL1 bit55 */
			{32445,37,1}, /* core1 sp_EL1 bit56 */
			{32448,37,1}, /* core1 sp_EL1 bit57 */
			{32447,37,1}, /* core1 sp_EL1 bit58 */
			{32223,37,1}, /* core1 sp_EL1 bit59 */
			{32439,37,1}, /* core1 sp_EL1 bit60 */
			{32444,37,1}, /* core1 sp_EL1 bit61 */
			{32443,37,1}, /* core1 sp_EL1 bit62 */
			{32373,37,1}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{38517,37,1}, /* core1 sp_EL2 bit0 */
			{32700,37,1}, /* core1 sp_EL2 bit1 */
			{38516,37,1}, /* core1 sp_EL2 bit2 */
			{32699,37,1}, /* core1 sp_EL2 bit3 */
			{38410,37,1}, /* core1 sp_EL2 bit4 */
			{32732,37,1}, /* core1 sp_EL2 bit5 */
			{32698,37,1}, /* core1 sp_EL2 bit6 */
			{32697,37,1}, /* core1 sp_EL2 bit7 */
			{38519,37,1}, /* core1 sp_EL2 bit8 */
			{32731,37,1}, /* core1 sp_EL2 bit9 */
			{32730,37,1}, /* core1 sp_EL2 bit10 */
			{38523,37,1}, /* core1 sp_EL2 bit11 */
			{38527,37,1}, /* core1 sp_EL2 bit12 */
			{38525,37,1}, /* core1 sp_EL2 bit13 */
			{38521,37,1}, /* core1 sp_EL2 bit14 */
			{38409,37,1}, /* core1 sp_EL2 bit15 */
			{38520,37,1}, /* core1 sp_EL2 bit16 */
			{38524,37,1}, /* core1 sp_EL2 bit17 */
			{38518,37,1}, /* core1 sp_EL2 bit18 */
			{32696,37,1}, /* core1 sp_EL2 bit19 */
			{38412,37,1}, /* core1 sp_EL2 bit20 */
			{32729,37,1}, /* core1 sp_EL2 bit21 */
			{32728,37,1}, /* core1 sp_EL2 bit22 */
			{32727,37,1}, /* core1 sp_EL2 bit23 */
			{38522,37,1}, /* core1 sp_EL2 bit24 */
			{32695,37,1}, /* core1 sp_EL2 bit25 */
			{38526,37,1}, /* core1 sp_EL2 bit26 */
			{38411,37,1}, /* core1 sp_EL2 bit27 */
			{32726,37,1}, /* core1 sp_EL2 bit28 */
			{32725,37,1}, /* core1 sp_EL2 bit29 */
			{32694,37,1}, /* core1 sp_EL2 bit30 */
			{32693,37,1}, /* core1 sp_EL2 bit31 */
			{33368,37,1}, /* core1 sp_EL2 bit32 */
			{32206,37,1}, /* core1 sp_EL2 bit33 */
			{33369,37,1}, /* core1 sp_EL2 bit34 */
			{33367,37,1}, /* core1 sp_EL2 bit35 */
			{32102,37,1}, /* core1 sp_EL2 bit36 */
			{32205,37,1}, /* core1 sp_EL2 bit37 */
			{32106,37,1}, /* core1 sp_EL2 bit38 */
			{38802,37,1}, /* core1 sp_EL2 bit39 */
			{29727,37,1}, /* core1 sp_EL2 bit40 */
			{32396,37,1}, /* core1 sp_EL2 bit41 */
			{38801,37,1}, /* core1 sp_EL2 bit42 */
			{32395,37,1}, /* core1 sp_EL2 bit43 */
			{32394,37,1}, /* core1 sp_EL2 bit44 */
			{32105,37,1}, /* core1 sp_EL2 bit45 */
			{32393,37,1}, /* core1 sp_EL2 bit46 */
			{32210,37,1}, /* core1 sp_EL2 bit47 */
			{32209,37,1}, /* core1 sp_EL2 bit48 */
			{30042,37,1}, /* core1 sp_EL2 bit49 */
			{32434,37,1}, /* core1 sp_EL2 bit50 */
			{32433,37,1}, /* core1 sp_EL2 bit51 */
			{32228,37,1}, /* core1 sp_EL2 bit52 */
			{30049,37,1}, /* core1 sp_EL2 bit53 */
			{30048,37,1}, /* core1 sp_EL2 bit54 */
			{32432,37,1}, /* core1 sp_EL2 bit55 */
			{32230,37,1}, /* core1 sp_EL2 bit56 */
			{32232,37,1}, /* core1 sp_EL2 bit57 */
			{30041,37,1}, /* core1 sp_EL2 bit58 */
			{32229,37,1}, /* core1 sp_EL2 bit59 */
			{32231,37,1}, /* core1 sp_EL2 bit60 */
			{32431,37,1}, /* core1 sp_EL2 bit61 */
			{32227,37,1}, /* core1 sp_EL2 bit62 */
			{32101,37,1}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{32708,37,1}, /* core1 sp_EL3 bit0 */
			{38506,37,1}, /* core1 sp_EL3 bit1 */
			{38498,37,1}, /* core1 sp_EL3 bit2 */
			{32707,37,1}, /* core1 sp_EL3 bit3 */
			{32706,37,1}, /* core1 sp_EL3 bit4 */
			{32705,37,1}, /* core1 sp_EL3 bit5 */
			{38502,37,1}, /* core1 sp_EL3 bit6 */
			{38496,37,1}, /* core1 sp_EL3 bit7 */
			{38495,37,1}, /* core1 sp_EL3 bit8 */
			{38504,37,1}, /* core1 sp_EL3 bit9 */
			{38497,37,1}, /* core1 sp_EL3 bit10 */
			{38418,37,1}, /* core1 sp_EL3 bit11 */
			{38501,37,1}, /* core1 sp_EL3 bit12 */
			{38416,37,1}, /* core1 sp_EL3 bit13 */
			{38500,37,1}, /* core1 sp_EL3 bit14 */
			{38419,37,1}, /* core1 sp_EL3 bit15 */
			{38417,37,1}, /* core1 sp_EL3 bit16 */
			{38503,37,1}, /* core1 sp_EL3 bit17 */
			{38499,37,1}, /* core1 sp_EL3 bit18 */
			{32716,37,1}, /* core1 sp_EL3 bit19 */
			{32724,37,1}, /* core1 sp_EL3 bit20 */
			{32723,37,1}, /* core1 sp_EL3 bit21 */
			{32715,37,1}, /* core1 sp_EL3 bit22 */
			{32720,37,1}, /* core1 sp_EL3 bit23 */
			{38505,37,1}, /* core1 sp_EL3 bit24 */
			{32714,37,1}, /* core1 sp_EL3 bit25 */
			{32722,37,1}, /* core1 sp_EL3 bit26 */
			{32721,37,1}, /* core1 sp_EL3 bit27 */
			{32719,37,1}, /* core1 sp_EL3 bit28 */
			{32718,37,1}, /* core1 sp_EL3 bit29 */
			{32717,37,1}, /* core1 sp_EL3 bit30 */
			{32713,37,1}, /* core1 sp_EL3 bit31 */
			{32380,37,1}, /* core1 sp_EL3 bit32 */
			{32379,37,1}, /* core1 sp_EL3 bit33 */
			{32372,37,1}, /* core1 sp_EL3 bit34 */
			{32371,37,1}, /* core1 sp_EL3 bit35 */
			{32370,37,1}, /* core1 sp_EL3 bit36 */
			{32369,37,1}, /* core1 sp_EL3 bit37 */
			{29739,37,1}, /* core1 sp_EL3 bit38 */
			{38808,37,1}, /* core1 sp_EL3 bit39 */
			{32378,37,1}, /* core1 sp_EL3 bit40 */
			{38807,37,1}, /* core1 sp_EL3 bit41 */
			{38804,37,1}, /* core1 sp_EL3 bit42 */
			{38806,37,1}, /* core1 sp_EL3 bit43 */
			{29738,37,1}, /* core1 sp_EL3 bit44 */
			{38803,37,1}, /* core1 sp_EL3 bit45 */
			{38805,37,1}, /* core1 sp_EL3 bit46 */
			{32344,37,1}, /* core1 sp_EL3 bit47 */
			{32343,37,1}, /* core1 sp_EL3 bit48 */
			{32342,37,1}, /* core1 sp_EL3 bit49 */
			{32236,37,1}, /* core1 sp_EL3 bit50 */
			{32234,37,1}, /* core1 sp_EL3 bit51 */
			{32438,37,1}, /* core1 sp_EL3 bit52 */
			{32235,37,1}, /* core1 sp_EL3 bit53 */
			{32437,37,1}, /* core1 sp_EL3 bit54 */
			{32233,37,1}, /* core1 sp_EL3 bit55 */
			{30047,37,1}, /* core1 sp_EL3 bit56 */
			{30050,37,1}, /* core1 sp_EL3 bit57 */
			{32341,37,1}, /* core1 sp_EL3 bit58 */
			{32436,37,1}, /* core1 sp_EL3 bit59 */
			{32435,37,1}, /* core1 sp_EL3 bit60 */
			{32226,37,1}, /* core1 sp_EL3 bit61 */
			{32225,37,1}, /* core1 sp_EL3 bit62 */
			{32377,37,1}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{32542,37,1}, /* core1 elr_EL1 bit0 */
			{38888,37,1}, /* core1 elr_EL1 bit1 */
			{38892,37,1}, /* core1 elr_EL1 bit2 */
			{38894,37,1}, /* core1 elr_EL1 bit3 */
			{38896,37,1}, /* core1 elr_EL1 bit4 */
			{38543,37,1}, /* core1 elr_EL1 bit5 */
			{38893,37,1}, /* core1 elr_EL1 bit6 */
			{38891,37,1}, /* core1 elr_EL1 bit7 */
			{38895,37,1}, /* core1 elr_EL1 bit8 */
			{38544,37,1}, /* core1 elr_EL1 bit9 */
			{38886,37,1}, /* core1 elr_EL1 bit10 */
			{32541,37,1}, /* core1 elr_EL1 bit11 */
			{38890,37,1}, /* core1 elr_EL1 bit12 */
			{38542,37,1}, /* core1 elr_EL1 bit13 */
			{38885,37,1}, /* core1 elr_EL1 bit14 */
			{32540,37,1}, /* core1 elr_EL1 bit15 */
			{32539,37,1}, /* core1 elr_EL1 bit16 */
			{38887,37,1}, /* core1 elr_EL1 bit17 */
			{38889,37,1}, /* core1 elr_EL1 bit18 */
			{32800,37,1}, /* core1 elr_EL1 bit19 */
			{32804,37,1}, /* core1 elr_EL1 bit20 */
			{32796,37,1}, /* core1 elr_EL1 bit21 */
			{32799,37,1}, /* core1 elr_EL1 bit22 */
			{32798,37,1}, /* core1 elr_EL1 bit23 */
			{32795,37,1}, /* core1 elr_EL1 bit24 */
			{32803,37,1}, /* core1 elr_EL1 bit25 */
			{32794,37,1}, /* core1 elr_EL1 bit26 */
			{32802,37,1}, /* core1 elr_EL1 bit27 */
			{32797,37,1}, /* core1 elr_EL1 bit28 */
			{29781,37,1}, /* core1 elr_EL1 bit29 */
			{32793,37,1}, /* core1 elr_EL1 bit30 */
			{32801,37,1}, /* core1 elr_EL1 bit31 */
			{32392,37,1}, /* core1 elr_EL1 bit32 */
			{32368,37,1}, /* core1 elr_EL1 bit33 */
			{32391,37,1}, /* core1 elr_EL1 bit34 */
			{32390,37,1}, /* core1 elr_EL1 bit35 */
			{32389,37,1}, /* core1 elr_EL1 bit36 */
			{32367,37,1}, /* core1 elr_EL1 bit37 */
			{33346,37,1}, /* core1 elr_EL1 bit38 */
			{32104,37,1}, /* core1 elr_EL1 bit39 */
			{33345,37,1}, /* core1 elr_EL1 bit40 */
			{32400,37,1}, /* core1 elr_EL1 bit41 */
			{32399,37,1}, /* core1 elr_EL1 bit42 */
			{32398,37,1}, /* core1 elr_EL1 bit43 */
			{29737,37,1}, /* core1 elr_EL1 bit44 */
			{32103,37,1}, /* core1 elr_EL1 bit45 */
			{32397,37,1}, /* core1 elr_EL1 bit46 */
			{32346,37,1}, /* core1 elr_EL1 bit47 */
			{33361,37,1}, /* core1 elr_EL1 bit48 */
			{33360,37,1}, /* core1 elr_EL1 bit49 */
			{32238,37,1}, /* core1 elr_EL1 bit50 */
			{33362,37,1}, /* core1 elr_EL1 bit51 */
			{32340,37,1}, /* core1 elr_EL1 bit52 */
			{32350,37,1}, /* core1 elr_EL1 bit53 */
			{32240,37,1}, /* core1 elr_EL1 bit54 */
			{32237,37,1}, /* core1 elr_EL1 bit55 */
			{32349,37,1}, /* core1 elr_EL1 bit56 */
			{32345,37,1}, /* core1 elr_EL1 bit57 */
			{32348,37,1}, /* core1 elr_EL1 bit58 */
			{32239,37,1}, /* core1 elr_EL1 bit59 */
			{32347,37,1}, /* core1 elr_EL1 bit60 */
			{33363,37,1}, /* core1 elr_EL1 bit61 */
			{32339,37,1}, /* core1 elr_EL1 bit62 */
			{33347,37,1}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{38754,37,1}, /* core1 elr_EL2 bit0 */
			{29783,37,1}, /* core1 elr_EL2 bit1 */
			{29782,37,1}, /* core1 elr_EL2 bit2 */
			{38742,37,1}, /* core1 elr_EL2 bit3 */
			{38752,37,1}, /* core1 elr_EL2 bit4 */
			{38740,37,1}, /* core1 elr_EL2 bit5 */
			{38898,37,1}, /* core1 elr_EL2 bit6 */
			{38750,37,1}, /* core1 elr_EL2 bit7 */
			{38545,37,1}, /* core1 elr_EL2 bit8 */
			{38753,37,1}, /* core1 elr_EL2 bit9 */
			{38739,37,1}, /* core1 elr_EL2 bit10 */
			{38897,37,1}, /* core1 elr_EL2 bit11 */
			{38541,37,1}, /* core1 elr_EL2 bit12 */
			{38749,37,1}, /* core1 elr_EL2 bit13 */
			{38741,37,1}, /* core1 elr_EL2 bit14 */
			{38546,37,1}, /* core1 elr_EL2 bit15 */
			{38751,37,1}, /* core1 elr_EL2 bit16 */
			{38744,37,1}, /* core1 elr_EL2 bit17 */
			{38743,37,1}, /* core1 elr_EL2 bit18 */
			{38738,37,1}, /* core1 elr_EL2 bit19 */
			{32538,37,1}, /* core1 elr_EL2 bit20 */
			{38736,37,1}, /* core1 elr_EL2 bit21 */
			{38746,37,1}, /* core1 elr_EL2 bit22 */
			{38737,37,1}, /* core1 elr_EL2 bit23 */
			{32537,37,1}, /* core1 elr_EL2 bit24 */
			{38745,37,1}, /* core1 elr_EL2 bit25 */
			{38735,37,1}, /* core1 elr_EL2 bit26 */
			{29784,37,1}, /* core1 elr_EL2 bit27 */
			{38748,37,1}, /* core1 elr_EL2 bit28 */
			{32536,37,1}, /* core1 elr_EL2 bit29 */
			{32535,37,1}, /* core1 elr_EL2 bit30 */
			{38747,37,1}, /* core1 elr_EL2 bit31 */
			{32362,37,1}, /* core1 elr_EL2 bit32 */
			{32361,37,1}, /* core1 elr_EL2 bit33 */
			{32416,37,1}, /* core1 elr_EL2 bit34 */
			{32415,37,1}, /* core1 elr_EL2 bit35 */
			{33348,37,1}, /* core1 elr_EL2 bit36 */
			{32360,37,1}, /* core1 elr_EL2 bit37 */
			{32414,37,1}, /* core1 elr_EL2 bit38 */
			{32413,37,1}, /* core1 elr_EL2 bit39 */
			{32410,37,1}, /* core1 elr_EL2 bit40 */
			{32264,37,1}, /* core1 elr_EL2 bit41 */
			{32263,37,1}, /* core1 elr_EL2 bit42 */
			{32409,37,1}, /* core1 elr_EL2 bit43 */
			{32412,37,1}, /* core1 elr_EL2 bit44 */
			{32411,37,1}, /* core1 elr_EL2 bit45 */
			{29736,37,1}, /* core1 elr_EL2 bit46 */
			{32358,37,1}, /* core1 elr_EL2 bit47 */
			{32354,37,1}, /* core1 elr_EL2 bit48 */
			{33358,37,1}, /* core1 elr_EL2 bit49 */
			{32244,37,1}, /* core1 elr_EL2 bit50 */
			{32357,37,1}, /* core1 elr_EL2 bit51 */
			{32246,37,1}, /* core1 elr_EL2 bit52 */
			{32353,37,1}, /* core1 elr_EL2 bit53 */
			{32352,37,1}, /* core1 elr_EL2 bit54 */
			{32242,37,1}, /* core1 elr_EL2 bit55 */
			{32243,37,1}, /* core1 elr_EL2 bit56 */
			{32356,37,1}, /* core1 elr_EL2 bit57 */
			{33359,37,1}, /* core1 elr_EL2 bit58 */
			{32241,37,1}, /* core1 elr_EL2 bit59 */
			{32245,37,1}, /* core1 elr_EL2 bit60 */
			{32351,37,1}, /* core1 elr_EL2 bit61 */
			{32355,37,1}, /* core1 elr_EL2 bit62 */
			{32359,37,1}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{33256,37,1}, /* core1 elr_EL3 bit0 */
			{33260,37,1}, /* core1 elr_EL3 bit1 */
			{33259,37,1}, /* core1 elr_EL3 bit2 */
			{29173,37,1}, /* core1 elr_EL3 bit3 */
			{38756,37,1}, /* core1 elr_EL3 bit4 */
			{38870,37,1}, /* core1 elr_EL3 bit5 */
			{29169,37,1}, /* core1 elr_EL3 bit6 */
			{29168,37,1}, /* core1 elr_EL3 bit7 */
			{33255,37,1}, /* core1 elr_EL3 bit8 */
			{29171,37,1}, /* core1 elr_EL3 bit9 */
			{33258,37,1}, /* core1 elr_EL3 bit10 */
			{38755,37,1}, /* core1 elr_EL3 bit11 */
			{33254,37,1}, /* core1 elr_EL3 bit12 */
			{33253,37,1}, /* core1 elr_EL3 bit13 */
			{33257,37,1}, /* core1 elr_EL3 bit14 */
			{38401,37,1}, /* core1 elr_EL3 bit15 */
			{29170,37,1}, /* core1 elr_EL3 bit16 */
			{38869,37,1}, /* core1 elr_EL3 bit17 */
			{38403,37,1}, /* core1 elr_EL3 bit18 */
			{38400,37,1}, /* core1 elr_EL3 bit19 */
			{29179,37,1}, /* core1 elr_EL3 bit20 */
			{29181,37,1}, /* core1 elr_EL3 bit21 */
			{29177,37,1}, /* core1 elr_EL3 bit22 */
			{29180,37,1}, /* core1 elr_EL3 bit23 */
			{38404,37,1}, /* core1 elr_EL3 bit24 */
			{38402,37,1}, /* core1 elr_EL3 bit25 */
			{38405,37,1}, /* core1 elr_EL3 bit26 */
			{29176,37,1}, /* core1 elr_EL3 bit27 */
			{29175,37,1}, /* core1 elr_EL3 bit28 */
			{29178,37,1}, /* core1 elr_EL3 bit29 */
			{29174,37,1}, /* core1 elr_EL3 bit30 */
			{29172,37,1}, /* core1 elr_EL3 bit31 */
			{33349,37,1}, /* core1 elr_EL3 bit32 */
			{32366,37,1}, /* core1 elr_EL3 bit33 */
			{32365,37,1}, /* core1 elr_EL3 bit34 */
			{32100,37,1}, /* core1 elr_EL3 bit35 */
			{32099,37,1}, /* core1 elr_EL3 bit36 */
			{32364,37,1}, /* core1 elr_EL3 bit37 */
			{32408,37,1}, /* core1 elr_EL3 bit38 */
			{29735,37,1}, /* core1 elr_EL3 bit39 */
			{32404,37,1}, /* core1 elr_EL3 bit40 */
			{32403,37,1}, /* core1 elr_EL3 bit41 */
			{32407,37,1}, /* core1 elr_EL3 bit42 */
			{32406,37,1}, /* core1 elr_EL3 bit43 */
			{32402,37,1}, /* core1 elr_EL3 bit44 */
			{32401,37,1}, /* core1 elr_EL3 bit45 */
			{32405,37,1}, /* core1 elr_EL3 bit46 */
			{38198,37,1}, /* core1 elr_EL3 bit47 */
			{38197,37,1}, /* core1 elr_EL3 bit48 */
			{32250,37,1}, /* core1 elr_EL3 bit49 */
			{38196,37,1}, /* core1 elr_EL3 bit50 */
			{33357,37,1}, /* core1 elr_EL3 bit51 */
			{32430,37,1}, /* core1 elr_EL3 bit52 */
			{32248,37,1}, /* core1 elr_EL3 bit53 */
			{33354,37,1}, /* core1 elr_EL3 bit54 */
			{32429,37,1}, /* core1 elr_EL3 bit55 */
			{32096,37,1}, /* core1 elr_EL3 bit56 */
			{33355,37,1}, /* core1 elr_EL3 bit57 */
			{32095,37,1}, /* core1 elr_EL3 bit58 */
			{32247,37,1}, /* core1 elr_EL3 bit59 */
			{32249,37,1}, /* core1 elr_EL3 bit60 */
			{33356,37,1}, /* core1 elr_EL3 bit61 */
			{38195,37,1}, /* core1 elr_EL3 bit62 */
			{32363,37,1}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31360,37,1}, /* core1 raw_pc bit0 */
			{31359,37,1}, /* core1 raw_pc bit1 */
			{36945,37,1}, /* core1 raw_pc bit2 */
			{36947,37,1}, /* core1 raw_pc bit3 */
			{31357,37,1}, /* core1 raw_pc bit4 */
			{31358,37,1}, /* core1 raw_pc bit5 */
			{31356,37,1}, /* core1 raw_pc bit6 */
			{36950,37,1}, /* core1 raw_pc bit7 */
			{36954,37,1}, /* core1 raw_pc bit8 */
			{40774,37,1}, /* core1 raw_pc bit9 */
			{40773,37,1}, /* core1 raw_pc bit10 */
			{36949,37,1}, /* core1 raw_pc bit11 */
			{38665,37,1}, /* core1 raw_pc bit12 */
			{40776,37,1}, /* core1 raw_pc bit13 */
			{42270,37,1}, /* core1 raw_pc bit14 */
			{42269,37,1}, /* core1 raw_pc bit15 */
			{40775,37,1}, /* core1 raw_pc bit16 */
			{42601,37,1}, /* core1 raw_pc bit17 */
			{38657,37,1}, /* core1 raw_pc bit18 */
			{42600,37,1}, /* core1 raw_pc bit19 */
			{42204,37,1}, /* core1 raw_pc bit20 */
			{42268,37,1}, /* core1 raw_pc bit21 */
			{42267,37,1}, /* core1 raw_pc bit22 */
			{38664,37,1}, /* core1 raw_pc bit23 */
			{38662,37,1}, /* core1 raw_pc bit24 */
			{42599,37,1}, /* core1 raw_pc bit25 */
			{38663,37,1}, /* core1 raw_pc bit26 */
			{42203,37,1}, /* core1 raw_pc bit27 */
			{42598,37,1}, /* core1 raw_pc bit28 */
			{36951,37,1}, /* core1 raw_pc bit29 */
			{36955,37,1}, /* core1 raw_pc bit30 */
			{42208,37,1}, /* core1 raw_pc bit31 */
			{42206,37,1}, /* core1 raw_pc bit32 */
			{36896,37,1}, /* core1 raw_pc bit33 */
			{42244,37,1}, /* core1 raw_pc bit34 */
			{42212,37,1}, /* core1 raw_pc bit35 */
			{42205,37,1}, /* core1 raw_pc bit36 */
			{42207,37,1}, /* core1 raw_pc bit37 */
			{42236,37,1}, /* core1 raw_pc bit38 */
			{42243,37,1}, /* core1 raw_pc bit39 */
			{42235,37,1}, /* core1 raw_pc bit40 */
			{42234,37,1}, /* core1 raw_pc bit41 */
			{42211,37,1}, /* core1 raw_pc bit42 */
			{42242,37,1}, /* core1 raw_pc bit43 */
			{42241,37,1}, /* core1 raw_pc bit44 */
			{42233,37,1}, /* core1 raw_pc bit45 */
			{42210,37,1}, /* core1 raw_pc bit46 */
			{42209,37,1}, /* core1 raw_pc bit47 */
			{42246,37,1}, /* core1 raw_pc bit48 */
			{42245,37,1}, /* core1 raw_pc bit49 */
			{    0, 0,2}, /* core1 raw_pc bit50 */
			{    0, 0,2}, /* core1 raw_pc bit51 */
			{    0, 0,2}, /* core1 raw_pc bit52 */
			{    0, 0,2}, /* core1 raw_pc bit53 */
			{    0, 0,2}, /* core1 raw_pc bit54 */
			{    0, 0,2}, /* core1 raw_pc bit55 */
			{    0, 0,2}, /* core1 raw_pc bit56 */
			{    0, 0,2}, /* core1 raw_pc bit57 */
			{    0, 0,2}, /* core1 raw_pc bit58 */
			{    0, 0,2}, /* core1 raw_pc bit59 */
			{    0, 0,2}, /* core1 raw_pc bit60 */
			{    0, 0,2}, /* core1 raw_pc bit61 */
			{    0, 0,2}, /* core1 raw_pc bit62 */
			{    0, 0,2}, /* core1 raw_pc bit63 */
			}},
			.pc_iss = {{
			{41846,37,1}, /* core1 pc_iss bit0 */
			{41845,37,1}, /* core1 pc_iss bit1 */
			{41844,37,1}, /* core1 pc_iss bit2 */
			{36925,37,1}, /* core1 pc_iss bit3 */
			{41843,37,1}, /* core1 pc_iss bit4 */
			{41583,37,1}, /* core1 pc_iss bit5 */
			{36924,37,1}, /* core1 pc_iss bit6 */
			{41582,37,1}, /* core1 pc_iss bit7 */
			{41617,37,1}, /* core1 pc_iss bit8 */
			{38614,37,1}, /* core1 pc_iss bit9 */
			{31173,37,1}, /* core1 pc_iss bit10 */
			{31167,37,1}, /* core1 pc_iss bit11 */
			{31166,37,1}, /* core1 pc_iss bit12 */
			{41621,37,1}, /* core1 pc_iss bit13 */
			{38612,37,1}, /* core1 pc_iss bit14 */
			{41856,37,1}, /* core1 pc_iss bit15 */
			{31172,37,1}, /* core1 pc_iss bit16 */
			{41620,37,1}, /* core1 pc_iss bit17 */
			{31697,37,1}, /* core1 pc_iss bit18 */
			{41616,37,1}, /* core1 pc_iss bit19 */
			{41619,37,1}, /* core1 pc_iss bit20 */
			{41855,37,1}, /* core1 pc_iss bit21 */
			{41854,37,1}, /* core1 pc_iss bit22 */
			{41853,37,1}, /* core1 pc_iss bit23 */
			{41618,37,1}, /* core1 pc_iss bit24 */
			{41848,37,1}, /* core1 pc_iss bit25 */
			{41847,37,1}, /* core1 pc_iss bit26 */
			{41611,37,1}, /* core1 pc_iss bit27 */
			{41610,37,1}, /* core1 pc_iss bit28 */
			{31696,37,1}, /* core1 pc_iss bit29 */
			{41609,37,1}, /* core1 pc_iss bit30 */
			{41608,37,1}, /* core1 pc_iss bit31 */
			{36940,37,1}, /* core1 pc_iss bit32 */
			{41597,37,1}, /* core1 pc_iss bit33 */
			{41596,37,1}, /* core1 pc_iss bit34 */
			{36939,37,1}, /* core1 pc_iss bit35 */
			{36886,37,1}, /* core1 pc_iss bit36 */
			{31193,37,1}, /* core1 pc_iss bit37 */
			{31192,37,1}, /* core1 pc_iss bit38 */
			{36938,37,1}, /* core1 pc_iss bit39 */
			{41593,37,1}, /* core1 pc_iss bit40 */
			{41592,37,1}, /* core1 pc_iss bit41 */
			{41595,37,1}, /* core1 pc_iss bit42 */
			{38617,37,1}, /* core1 pc_iss bit43 */
			{41594,37,1}, /* core1 pc_iss bit44 */
			{38611,37,1}, /* core1 pc_iss bit45 */
			{38616,37,1}, /* core1 pc_iss bit46 */
			{38658,37,1}, /* core1 pc_iss bit47 */
			{38659,37,1}, /* core1 pc_iss bit48 */
			{31163,37,1}, /* core1 pc_iss bit49 */
			{38660,37,1}, /* core1 pc_iss bit50 */
			{42603,37,1}, /* core1 pc_iss bit51 */
			{31162,37,1}, /* core1 pc_iss bit52 */
			{42602,37,1}, /* core1 pc_iss bit53 */
			{38661,37,1}, /* core1 pc_iss bit54 */
			{42202,37,1}, /* core1 pc_iss bit55 */
			{38656,37,1}, /* core1 pc_iss bit56 */
			{42198,37,1}, /* core1 pc_iss bit57 */
			{42197,37,1}, /* core1 pc_iss bit58 */
			{42196,37,1}, /* core1 pc_iss bit59 */
			{42201,37,1}, /* core1 pc_iss bit60 */
			{42200,37,1}, /* core1 pc_iss bit61 */
			{42195,37,1}, /* core1 pc_iss bit62 */
			{42199,37,1}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31361,37,1}, /* core1 full_pc_wr bit0 */
			{    0, 0,2}, /* core1 full_pc_wr bit1 */
			{    0, 0,2}, /* core1 full_pc_wr bit2 */
			{    0, 0,2}, /* core1 full_pc_wr bit3 */
			{    0, 0,2}, /* core1 full_pc_wr bit4 */
			{    0, 0,2}, /* core1 full_pc_wr bit5 */
			{    0, 0,2}, /* core1 full_pc_wr bit6 */
			{    0, 0,2}, /* core1 full_pc_wr bit7 */
			{    0, 0,2}, /* core1 full_pc_wr bit8 */
			{    0, 0,2}, /* core1 full_pc_wr bit9 */
			{    0, 0,2}, /* core1 full_pc_wr bit10 */
			{    0, 0,2}, /* core1 full_pc_wr bit11 */
			{    0, 0,2}, /* core1 full_pc_wr bit12 */
			{    0, 0,2}, /* core1 full_pc_wr bit13 */
			{    0, 0,2}, /* core1 full_pc_wr bit14 */
			{    0, 0,2}, /* core1 full_pc_wr bit15 */
			{    0, 0,2}, /* core1 full_pc_wr bit16 */
			{    0, 0,2}, /* core1 full_pc_wr bit17 */
			{    0, 0,2}, /* core1 full_pc_wr bit18 */
			{    0, 0,2}, /* core1 full_pc_wr bit19 */
			{    0, 0,2}, /* core1 full_pc_wr bit20 */
			{    0, 0,2}, /* core1 full_pc_wr bit21 */
			{    0, 0,2}, /* core1 full_pc_wr bit22 */
			{    0, 0,2}, /* core1 full_pc_wr bit23 */
			{    0, 0,2}, /* core1 full_pc_wr bit24 */
			{    0, 0,2}, /* core1 full_pc_wr bit25 */
			{    0, 0,2}, /* core1 full_pc_wr bit26 */
			{    0, 0,2}, /* core1 full_pc_wr bit27 */
			{    0, 0,2}, /* core1 full_pc_wr bit28 */
			{    0, 0,2}, /* core1 full_pc_wr bit29 */
			{    0, 0,2}, /* core1 full_pc_wr bit30 */
			{    0, 0,2}, /* core1 full_pc_wr bit31 */
			{    0, 0,2}, /* core1 full_pc_wr bit32 */
			{    0, 0,2}, /* core1 full_pc_wr bit33 */
			{    0, 0,2}, /* core1 full_pc_wr bit34 */
			{    0, 0,2}, /* core1 full_pc_wr bit35 */
			{    0, 0,2}, /* core1 full_pc_wr bit36 */
			{    0, 0,2}, /* core1 full_pc_wr bit37 */
			{    0, 0,2}, /* core1 full_pc_wr bit38 */
			{    0, 0,2}, /* core1 full_pc_wr bit39 */
			{    0, 0,2}, /* core1 full_pc_wr bit40 */
			{    0, 0,2}, /* core1 full_pc_wr bit41 */
			{    0, 0,2}, /* core1 full_pc_wr bit42 */
			{    0, 0,2}, /* core1 full_pc_wr bit43 */
			{    0, 0,2}, /* core1 full_pc_wr bit44 */
			{    0, 0,2}, /* core1 full_pc_wr bit45 */
			{    0, 0,2}, /* core1 full_pc_wr bit46 */
			{    0, 0,2}, /* core1 full_pc_wr bit47 */
			{    0, 0,2}, /* core1 full_pc_wr bit48 */
			{    0, 0,2}, /* core1 full_pc_wr bit49 */
			{    0, 0,2}, /* core1 full_pc_wr bit50 */
			{    0, 0,2}, /* core1 full_pc_wr bit51 */
			{    0, 0,2}, /* core1 full_pc_wr bit52 */
			{    0, 0,2}, /* core1 full_pc_wr bit53 */
			{    0, 0,2}, /* core1 full_pc_wr bit54 */
			{    0, 0,2}, /* core1 full_pc_wr bit55 */
			{    0, 0,2}, /* core1 full_pc_wr bit56 */
			{    0, 0,2}, /* core1 full_pc_wr bit57 */
			{    0, 0,2}, /* core1 full_pc_wr bit58 */
			{    0, 0,2}, /* core1 full_pc_wr bit59 */
			{    0, 0,2}, /* core1 full_pc_wr bit60 */
			{    0, 0,2}, /* core1 full_pc_wr bit61 */
			{    0, 0,2}, /* core1 full_pc_wr bit62 */
			{    0, 0,2}, /* core1 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{41585,37,1}, /* core1 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{40768,37,1}, /* core1 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{27703,37,1}, /* core1 return_Stack_pointer bit0 */
			{27701,37,1}, /* core1 return_Stack_pointer bit1 */
			{14039,37,1}, /* core1 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{17696,37,1}, /* core1 return_Stack0 bit0 */
			{17695,37,1}, /* core1 return_Stack0 bit1 */
			{14923,37,1}, /* core1 return_Stack0 bit2 */
			{14929,37,1}, /* core1 return_Stack0 bit3 */
			{14928,37,1}, /* core1 return_Stack0 bit4 */
			{14931,37,1}, /* core1 return_Stack0 bit5 */
			{17596,37,1}, /* core1 return_Stack0 bit6 */
			{17595,37,1}, /* core1 return_Stack0 bit7 */
			{14922,37,1}, /* core1 return_Stack0 bit8 */
			{14919,37,1}, /* core1 return_Stack0 bit9 */
			{14920,37,1}, /* core1 return_Stack0 bit10 */
			{14911,37,1}, /* core1 return_Stack0 bit11 */
			{14921,37,1}, /* core1 return_Stack0 bit12 */
			{14925,37,1}, /* core1 return_Stack0 bit13 */
			{19268,37,1}, /* core1 return_Stack0 bit14 */
			{14924,37,1}, /* core1 return_Stack0 bit15 */
			{19252,37,1}, /* core1 return_Stack0 bit16 */
			{19251,37,1}, /* core1 return_Stack0 bit17 */
			{19266,37,1}, /* core1 return_Stack0 bit18 */
			{19265,37,1}, /* core1 return_Stack0 bit19 */
			{19267,37,1}, /* core1 return_Stack0 bit20 */
			{14930,37,1}, /* core1 return_Stack0 bit21 */
			{14932,37,1}, /* core1 return_Stack0 bit22 */
			{17694,37,1}, /* core1 return_Stack0 bit23 */
			{14994,37,1}, /* core1 return_Stack0 bit24 */
			{19364,37,1}, /* core1 return_Stack0 bit25 */
			{19538,37,1}, /* core1 return_Stack0 bit26 */
			{19537,37,1}, /* core1 return_Stack0 bit27 */
			{19540,37,1}, /* core1 return_Stack0 bit28 */
			{17616,37,1}, /* core1 return_Stack0 bit29 */
			{15000,37,1}, /* core1 return_Stack0 bit30 */
			{19539,37,1}, /* core1 return_Stack0 bit31 */
			{19363,37,1}, /* core1 return_Stack0 bit32 */
			{17615,37,1}, /* core1 return_Stack0 bit33 */
			{17614,37,1}, /* core1 return_Stack0 bit34 */
			{19534,37,1}, /* core1 return_Stack0 bit35 */
			{17620,37,1}, /* core1 return_Stack0 bit36 */
			{17619,37,1}, /* core1 return_Stack0 bit37 */
			{17618,37,1}, /* core1 return_Stack0 bit38 */
			{17688,37,1}, /* core1 return_Stack0 bit39 */
			{19533,37,1}, /* core1 return_Stack0 bit40 */
			{17687,37,1}, /* core1 return_Stack0 bit41 */
			{17617,37,1}, /* core1 return_Stack0 bit42 */
			{14996,37,1}, /* core1 return_Stack0 bit43 */
			{17686,37,1}, /* core1 return_Stack0 bit44 */
			{17685,37,1}, /* core1 return_Stack0 bit45 */
			{14935,37,1}, /* core1 return_Stack0 bit46 */
			{17613,37,1}, /* core1 return_Stack0 bit47 */
			{17693,37,1}, /* core1 return_Stack0 bit48 */
			{    0, 0,2}, /* core1 return_Stack0 bit49 */
			{    0, 0,2}, /* core1 return_Stack0 bit50 */
			{    0, 0,2}, /* core1 return_Stack0 bit51 */
			{    0, 0,2}, /* core1 return_Stack0 bit52 */
			{    0, 0,2}, /* core1 return_Stack0 bit53 */
			{    0, 0,2}, /* core1 return_Stack0 bit54 */
			{    0, 0,2}, /* core1 return_Stack0 bit55 */
			{    0, 0,2}, /* core1 return_Stack0 bit56 */
			{    0, 0,2}, /* core1 return_Stack0 bit57 */
			{    0, 0,2}, /* core1 return_Stack0 bit58 */
			{    0, 0,2}, /* core1 return_Stack0 bit59 */
			{    0, 0,2}, /* core1 return_Stack0 bit60 */
			{    0, 0,2}, /* core1 return_Stack0 bit61 */
			{    0, 0,2}, /* core1 return_Stack0 bit62 */
			{    0, 0,2}, /* core1 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{17692,37,1}, /* core1 return_Stack1 bit0 */
			{24874,37,1}, /* core1 return_Stack1 bit1 */
			{21980,37,1}, /* core1 return_Stack1 bit2 */
			{24873,37,1}, /* core1 return_Stack1 bit3 */
			{24872,37,1}, /* core1 return_Stack1 bit4 */
			{14984,37,1}, /* core1 return_Stack1 bit5 */
			{24871,37,1}, /* core1 return_Stack1 bit6 */
			{19240,37,1}, /* core1 return_Stack1 bit7 */
			{21979,37,1}, /* core1 return_Stack1 bit8 */
			{19238,37,1}, /* core1 return_Stack1 bit9 */
			{19239,37,1}, /* core1 return_Stack1 bit10 */
			{21978,37,1}, /* core1 return_Stack1 bit11 */
			{21977,37,1}, /* core1 return_Stack1 bit12 */
			{14985,37,1}, /* core1 return_Stack1 bit13 */
			{17691,37,1}, /* core1 return_Stack1 bit14 */
			{19237,37,1}, /* core1 return_Stack1 bit15 */
			{17604,37,1}, /* core1 return_Stack1 bit16 */
			{17603,37,1}, /* core1 return_Stack1 bit17 */
			{19522,37,1}, /* core1 return_Stack1 bit18 */
			{17602,37,1}, /* core1 return_Stack1 bit19 */
			{14976,37,1}, /* core1 return_Stack1 bit20 */
			{17601,37,1}, /* core1 return_Stack1 bit21 */
			{19521,37,1}, /* core1 return_Stack1 bit22 */
			{17690,37,1}, /* core1 return_Stack1 bit23 */
			{19498,37,1}, /* core1 return_Stack1 bit24 */
			{17612,37,1}, /* core1 return_Stack1 bit25 */
			{17664,37,1}, /* core1 return_Stack1 bit26 */
			{17611,37,1}, /* core1 return_Stack1 bit27 */
			{19497,37,1}, /* core1 return_Stack1 bit28 */
			{17610,37,1}, /* core1 return_Stack1 bit29 */
			{17663,37,1}, /* core1 return_Stack1 bit30 */
			{14934,37,1}, /* core1 return_Stack1 bit31 */
			{17609,37,1}, /* core1 return_Stack1 bit32 */
			{17662,37,1}, /* core1 return_Stack1 bit33 */
			{19502,37,1}, /* core1 return_Stack1 bit34 */
			{14092,37,1}, /* core1 return_Stack1 bit35 */
			{17624,37,1}, /* core1 return_Stack1 bit36 */
			{17623,37,1}, /* core1 return_Stack1 bit37 */
			{17622,37,1}, /* core1 return_Stack1 bit38 */
			{17676,37,1}, /* core1 return_Stack1 bit39 */
			{17675,37,1}, /* core1 return_Stack1 bit40 */
			{17674,37,1}, /* core1 return_Stack1 bit41 */
			{17673,37,1}, /* core1 return_Stack1 bit42 */
			{17621,37,1}, /* core1 return_Stack1 bit43 */
			{19280,37,1}, /* core1 return_Stack1 bit44 */
			{19279,37,1}, /* core1 return_Stack1 bit45 */
			{17661,37,1}, /* core1 return_Stack1 bit46 */
			{19501,37,1}, /* core1 return_Stack1 bit47 */
			{17689,37,1}, /* core1 return_Stack1 bit48 */
			{    0, 0,2}, /* core1 return_Stack1 bit49 */
			{    0, 0,2}, /* core1 return_Stack1 bit50 */
			{    0, 0,2}, /* core1 return_Stack1 bit51 */
			{    0, 0,2}, /* core1 return_Stack1 bit52 */
			{    0, 0,2}, /* core1 return_Stack1 bit53 */
			{    0, 0,2}, /* core1 return_Stack1 bit54 */
			{    0, 0,2}, /* core1 return_Stack1 bit55 */
			{    0, 0,2}, /* core1 return_Stack1 bit56 */
			{    0, 0,2}, /* core1 return_Stack1 bit57 */
			{    0, 0,2}, /* core1 return_Stack1 bit58 */
			{    0, 0,2}, /* core1 return_Stack1 bit59 */
			{    0, 0,2}, /* core1 return_Stack1 bit60 */
			{    0, 0,2}, /* core1 return_Stack1 bit61 */
			{    0, 0,2}, /* core1 return_Stack1 bit62 */
			{    0, 0,2}, /* core1 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{17700,37,1}, /* core1 return_Stack2 bit0 */
			{17699,37,1}, /* core1 return_Stack2 bit1 */
			{14901,37,1}, /* core1 return_Stack2 bit2 */
			{14933,37,1}, /* core1 return_Stack2 bit3 */
			{19264,37,1}, /* core1 return_Stack2 bit4 */
			{19236,37,1}, /* core1 return_Stack2 bit5 */
			{19263,37,1}, /* core1 return_Stack2 bit6 */
			{14907,37,1}, /* core1 return_Stack2 bit7 */
			{19228,37,1}, /* core1 return_Stack2 bit8 */
			{14902,37,1}, /* core1 return_Stack2 bit9 */
			{19235,37,1}, /* core1 return_Stack2 bit10 */
			{14904,37,1}, /* core1 return_Stack2 bit11 */
			{19227,37,1}, /* core1 return_Stack2 bit12 */
			{14915,37,1}, /* core1 return_Stack2 bit13 */
			{17698,37,1}, /* core1 return_Stack2 bit14 */
			{14905,37,1}, /* core1 return_Stack2 bit15 */
			{14916,37,1}, /* core1 return_Stack2 bit16 */
			{14914,37,1}, /* core1 return_Stack2 bit17 */
			{19276,37,1}, /* core1 return_Stack2 bit18 */
			{19275,37,1}, /* core1 return_Stack2 bit19 */
			{19274,37,1}, /* core1 return_Stack2 bit20 */
			{14981,37,1}, /* core1 return_Stack2 bit21 */
			{19273,37,1}, /* core1 return_Stack2 bit22 */
			{14982,37,1}, /* core1 return_Stack2 bit23 */
			{19362,37,1}, /* core1 return_Stack2 bit24 */
			{19361,37,1}, /* core1 return_Stack2 bit25 */
			{17660,37,1}, /* core1 return_Stack2 bit26 */
			{19492,37,1}, /* core1 return_Stack2 bit27 */
			{17656,37,1}, /* core1 return_Stack2 bit28 */
			{19491,37,1}, /* core1 return_Stack2 bit29 */
			{17655,37,1}, /* core1 return_Stack2 bit30 */
			{17654,37,1}, /* core1 return_Stack2 bit31 */
			{17653,37,1}, /* core1 return_Stack2 bit32 */
			{17659,37,1}, /* core1 return_Stack2 bit33 */
			{14993,37,1}, /* core1 return_Stack2 bit34 */
			{19496,37,1}, /* core1 return_Stack2 bit35 */
			{19494,37,1}, /* core1 return_Stack2 bit36 */
			{14088,37,1}, /* core1 return_Stack2 bit37 */
			{19493,37,1}, /* core1 return_Stack2 bit38 */
			{17672,37,1}, /* core1 return_Stack2 bit39 */
			{19495,37,1}, /* core1 return_Stack2 bit40 */
			{17671,37,1}, /* core1 return_Stack2 bit41 */
			{14091,37,1}, /* core1 return_Stack2 bit42 */
			{17670,37,1}, /* core1 return_Stack2 bit43 */
			{17669,37,1}, /* core1 return_Stack2 bit44 */
			{19859,37,1}, /* core1 return_Stack2 bit45 */
			{17658,37,1}, /* core1 return_Stack2 bit46 */
			{17657,37,1}, /* core1 return_Stack2 bit47 */
			{17697,37,1}, /* core1 return_Stack2 bit48 */
			{    0, 0,2}, /* core1 return_Stack2 bit49 */
			{    0, 0,2}, /* core1 return_Stack2 bit50 */
			{    0, 0,2}, /* core1 return_Stack2 bit51 */
			{    0, 0,2}, /* core1 return_Stack2 bit52 */
			{    0, 0,2}, /* core1 return_Stack2 bit53 */
			{    0, 0,2}, /* core1 return_Stack2 bit54 */
			{    0, 0,2}, /* core1 return_Stack2 bit55 */
			{    0, 0,2}, /* core1 return_Stack2 bit56 */
			{    0, 0,2}, /* core1 return_Stack2 bit57 */
			{    0, 0,2}, /* core1 return_Stack2 bit58 */
			{    0, 0,2}, /* core1 return_Stack2 bit59 */
			{    0, 0,2}, /* core1 return_Stack2 bit60 */
			{    0, 0,2}, /* core1 return_Stack2 bit61 */
			{    0, 0,2}, /* core1 return_Stack2 bit62 */
			{    0, 0,2}, /* core1 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{19520,37,1}, /* core1 return_Stack3 bit0 */
			{27665,37,1}, /* core1 return_Stack3 bit1 */
			{21968,37,1}, /* core1 return_Stack3 bit2 */
			{19248,37,1}, /* core1 return_Stack3 bit3 */
			{19247,37,1}, /* core1 return_Stack3 bit4 */
			{21967,37,1}, /* core1 return_Stack3 bit5 */
			{21966,37,1}, /* core1 return_Stack3 bit6 */
			{27683,37,1}, /* core1 return_Stack3 bit7 */
			{19244,37,1}, /* core1 return_Stack3 bit8 */
			{19246,37,1}, /* core1 return_Stack3 bit9 */
			{21965,37,1}, /* core1 return_Stack3 bit10 */
			{19243,37,1}, /* core1 return_Stack3 bit11 */
			{19245,37,1}, /* core1 return_Stack3 bit12 */
			{27685,37,1}, /* core1 return_Stack3 bit13 */
			{27684,37,1}, /* core1 return_Stack3 bit14 */
			{14913,37,1}, /* core1 return_Stack3 bit15 */
			{21964,37,1}, /* core1 return_Stack3 bit16 */
			{21963,37,1}, /* core1 return_Stack3 bit17 */
			{21962,37,1}, /* core1 return_Stack3 bit18 */
			{21961,37,1}, /* core1 return_Stack3 bit19 */
			{21948,37,1}, /* core1 return_Stack3 bit20 */
			{21947,37,1}, /* core1 return_Stack3 bit21 */
			{19519,37,1}, /* core1 return_Stack3 bit22 */
			{21946,37,1}, /* core1 return_Stack3 bit23 */
			{21984,37,1}, /* core1 return_Stack3 bit24 */
			{21983,37,1}, /* core1 return_Stack3 bit25 */
			{21996,37,1}, /* core1 return_Stack3 bit26 */
			{21982,37,1}, /* core1 return_Stack3 bit27 */
			{21995,37,1}, /* core1 return_Stack3 bit28 */
			{21981,37,1}, /* core1 return_Stack3 bit29 */
			{21994,37,1}, /* core1 return_Stack3 bit30 */
			{27675,37,1}, /* core1 return_Stack3 bit31 */
			{21993,37,1}, /* core1 return_Stack3 bit32 */
			{19512,37,1}, /* core1 return_Stack3 bit33 */
			{27676,37,1}, /* core1 return_Stack3 bit34 */
			{19482,37,1}, /* core1 return_Stack3 bit35 */
			{19486,37,1}, /* core1 return_Stack3 bit36 */
			{19481,37,1}, /* core1 return_Stack3 bit37 */
			{19480,37,1}, /* core1 return_Stack3 bit38 */
			{19485,37,1}, /* core1 return_Stack3 bit39 */
			{27674,37,1}, /* core1 return_Stack3 bit40 */
			{19479,37,1}, /* core1 return_Stack3 bit41 */
			{14093,37,1}, /* core1 return_Stack3 bit42 */
			{19857,37,1}, /* core1 return_Stack3 bit43 */
			{19856,37,1}, /* core1 return_Stack3 bit44 */
			{27664,37,1}, /* core1 return_Stack3 bit45 */
			{19511,37,1}, /* core1 return_Stack3 bit46 */
			{27677,37,1}, /* core1 return_Stack3 bit47 */
			{21945,37,1}, /* core1 return_Stack3 bit48 */
			{    0, 0,2}, /* core1 return_Stack3 bit49 */
			{    0, 0,2}, /* core1 return_Stack3 bit50 */
			{    0, 0,2}, /* core1 return_Stack3 bit51 */
			{    0, 0,2}, /* core1 return_Stack3 bit52 */
			{    0, 0,2}, /* core1 return_Stack3 bit53 */
			{    0, 0,2}, /* core1 return_Stack3 bit54 */
			{    0, 0,2}, /* core1 return_Stack3 bit55 */
			{    0, 0,2}, /* core1 return_Stack3 bit56 */
			{    0, 0,2}, /* core1 return_Stack3 bit57 */
			{    0, 0,2}, /* core1 return_Stack3 bit58 */
			{    0, 0,2}, /* core1 return_Stack3 bit59 */
			{    0, 0,2}, /* core1 return_Stack3 bit60 */
			{    0, 0,2}, /* core1 return_Stack3 bit61 */
			{    0, 0,2}, /* core1 return_Stack3 bit62 */
			{    0, 0,2}, /* core1 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{17704,37,1}, /* core1 return_Stack4 bit0 */
			{17703,37,1}, /* core1 return_Stack4 bit1 */
			{19230,37,1}, /* core1 return_Stack4 bit2 */
			{14986,37,1}, /* core1 return_Stack4 bit3 */
			{14983,37,1}, /* core1 return_Stack4 bit4 */
			{19242,37,1}, /* core1 return_Stack4 bit5 */
			{14987,37,1}, /* core1 return_Stack4 bit6 */
			{19232,37,1}, /* core1 return_Stack4 bit7 */
			{19241,37,1}, /* core1 return_Stack4 bit8 */
			{19229,37,1}, /* core1 return_Stack4 bit9 */
			{14906,37,1}, /* core1 return_Stack4 bit10 */
			{14903,37,1}, /* core1 return_Stack4 bit11 */
			{19231,37,1}, /* core1 return_Stack4 bit12 */
			{19234,37,1}, /* core1 return_Stack4 bit13 */
			{14917,37,1}, /* core1 return_Stack4 bit14 */
			{19233,37,1}, /* core1 return_Stack4 bit15 */
			{17608,37,1}, /* core1 return_Stack4 bit16 */
			{17607,37,1}, /* core1 return_Stack4 bit17 */
			{19278,37,1}, /* core1 return_Stack4 bit18 */
			{15002,37,1}, /* core1 return_Stack4 bit19 */
			{19277,37,1}, /* core1 return_Stack4 bit20 */
			{17606,37,1}, /* core1 return_Stack4 bit21 */
			{17605,37,1}, /* core1 return_Stack4 bit22 */
			{17702,37,1}, /* core1 return_Stack4 bit23 */
			{19360,37,1}, /* core1 return_Stack4 bit24 */
			{19359,37,1}, /* core1 return_Stack4 bit25 */
			{15001,37,1}, /* core1 return_Stack4 bit26 */
			{19536,37,1}, /* core1 return_Stack4 bit27 */
			{17648,37,1}, /* core1 return_Stack4 bit28 */
			{19535,37,1}, /* core1 return_Stack4 bit29 */
			{17647,37,1}, /* core1 return_Stack4 bit30 */
			{17646,37,1}, /* core1 return_Stack4 bit31 */
			{17645,37,1}, /* core1 return_Stack4 bit32 */
			{17652,37,1}, /* core1 return_Stack4 bit33 */
			{17651,37,1}, /* core1 return_Stack4 bit34 */
			{19532,37,1}, /* core1 return_Stack4 bit35 */
			{14087,37,1}, /* core1 return_Stack4 bit36 */
			{19530,37,1}, /* core1 return_Stack4 bit37 */
			{19869,37,1}, /* core1 return_Stack4 bit38 */
			{17708,37,1}, /* core1 return_Stack4 bit39 */
			{19531,37,1}, /* core1 return_Stack4 bit40 */
			{17707,37,1}, /* core1 return_Stack4 bit41 */
			{19529,37,1}, /* core1 return_Stack4 bit42 */
			{19862,37,1}, /* core1 return_Stack4 bit43 */
			{17706,37,1}, /* core1 return_Stack4 bit44 */
			{17705,37,1}, /* core1 return_Stack4 bit45 */
			{17650,37,1}, /* core1 return_Stack4 bit46 */
			{17649,37,1}, /* core1 return_Stack4 bit47 */
			{17701,37,1}, /* core1 return_Stack4 bit48 */
			{    0, 0,2}, /* core1 return_Stack4 bit49 */
			{    0, 0,2}, /* core1 return_Stack4 bit50 */
			{    0, 0,2}, /* core1 return_Stack4 bit51 */
			{    0, 0,2}, /* core1 return_Stack4 bit52 */
			{    0, 0,2}, /* core1 return_Stack4 bit53 */
			{    0, 0,2}, /* core1 return_Stack4 bit54 */
			{    0, 0,2}, /* core1 return_Stack4 bit55 */
			{    0, 0,2}, /* core1 return_Stack4 bit56 */
			{    0, 0,2}, /* core1 return_Stack4 bit57 */
			{    0, 0,2}, /* core1 return_Stack4 bit58 */
			{    0, 0,2}, /* core1 return_Stack4 bit59 */
			{    0, 0,2}, /* core1 return_Stack4 bit60 */
			{    0, 0,2}, /* core1 return_Stack4 bit61 */
			{    0, 0,2}, /* core1 return_Stack4 bit62 */
			{    0, 0,2}, /* core1 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{27686,37,1}, /* core1 return_Stack5 bit0 */
			{14936,37,1}, /* core1 return_Stack5 bit1 */
			{19224,37,1}, /* core1 return_Stack5 bit2 */
			{21976,37,1}, /* core1 return_Stack5 bit3 */
			{19254,37,1}, /* core1 return_Stack5 bit4 */
			{19253,37,1}, /* core1 return_Stack5 bit5 */
			{14918,37,1}, /* core1 return_Stack5 bit6 */
			{21975,37,1}, /* core1 return_Stack5 bit7 */
			{21974,37,1}, /* core1 return_Stack5 bit8 */
			{19226,37,1}, /* core1 return_Stack5 bit9 */
			{21973,37,1}, /* core1 return_Stack5 bit10 */
			{19225,37,1}, /* core1 return_Stack5 bit11 */
			{19223,37,1}, /* core1 return_Stack5 bit12 */
			{14975,37,1}, /* core1 return_Stack5 bit13 */
			{19262,37,1}, /* core1 return_Stack5 bit14 */
			{14910,37,1}, /* core1 return_Stack5 bit15 */
			{19250,37,1}, /* core1 return_Stack5 bit16 */
			{19261,37,1}, /* core1 return_Stack5 bit17 */
			{21952,37,1}, /* core1 return_Stack5 bit18 */
			{21951,37,1}, /* core1 return_Stack5 bit19 */
			{21950,37,1}, /* core1 return_Stack5 bit20 */
			{19249,37,1}, /* core1 return_Stack5 bit21 */
			{21949,37,1}, /* core1 return_Stack5 bit22 */
			{19514,37,1}, /* core1 return_Stack5 bit23 */
			{19488,37,1}, /* core1 return_Stack5 bit24 */
			{19487,37,1}, /* core1 return_Stack5 bit25 */
			{17680,37,1}, /* core1 return_Stack5 bit26 */
			{17679,37,1}, /* core1 return_Stack5 bit27 */
			{17678,37,1}, /* core1 return_Stack5 bit28 */
			{19490,37,1}, /* core1 return_Stack5 bit29 */
			{17677,37,1}, /* core1 return_Stack5 bit30 */
			{19526,37,1}, /* core1 return_Stack5 bit31 */
			{27663,37,1}, /* core1 return_Stack5 bit32 */
			{27668,37,1}, /* core1 return_Stack5 bit33 */
			{19489,37,1}, /* core1 return_Stack5 bit34 */
			{19864,37,1}, /* core1 return_Stack5 bit35 */
			{17712,37,1}, /* core1 return_Stack5 bit36 */
			{17711,37,1}, /* core1 return_Stack5 bit37 */
			{17710,37,1}, /* core1 return_Stack5 bit38 */
			{14094,37,1}, /* core1 return_Stack5 bit39 */
			{17684,37,1}, /* core1 return_Stack5 bit40 */
			{19858,37,1}, /* core1 return_Stack5 bit41 */
			{17683,37,1}, /* core1 return_Stack5 bit42 */
			{17709,37,1}, /* core1 return_Stack5 bit43 */
			{17682,37,1}, /* core1 return_Stack5 bit44 */
			{17681,37,1}, /* core1 return_Stack5 bit45 */
			{27669,37,1}, /* core1 return_Stack5 bit46 */
			{19525,37,1}, /* core1 return_Stack5 bit47 */
			{19513,37,1}, /* core1 return_Stack5 bit48 */
			{    0, 0,2}, /* core1 return_Stack5 bit49 */
			{    0, 0,2}, /* core1 return_Stack5 bit50 */
			{    0, 0,2}, /* core1 return_Stack5 bit51 */
			{    0, 0,2}, /* core1 return_Stack5 bit52 */
			{    0, 0,2}, /* core1 return_Stack5 bit53 */
			{    0, 0,2}, /* core1 return_Stack5 bit54 */
			{    0, 0,2}, /* core1 return_Stack5 bit55 */
			{    0, 0,2}, /* core1 return_Stack5 bit56 */
			{    0, 0,2}, /* core1 return_Stack5 bit57 */
			{    0, 0,2}, /* core1 return_Stack5 bit58 */
			{    0, 0,2}, /* core1 return_Stack5 bit59 */
			{    0, 0,2}, /* core1 return_Stack5 bit60 */
			{    0, 0,2}, /* core1 return_Stack5 bit61 */
			{    0, 0,2}, /* core1 return_Stack5 bit62 */
			{    0, 0,2}, /* core1 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{14977,37,1}, /* core1 return_Stack6 bit0 */
			{14979,37,1}, /* core1 return_Stack6 bit1 */
			{24870,37,1}, /* core1 return_Stack6 bit2 */
			{14927,37,1}, /* core1 return_Stack6 bit3 */
			{17354,37,1}, /* core1 return_Stack6 bit4 */
			{17353,37,1}, /* core1 return_Stack6 bit5 */
			{24869,37,1}, /* core1 return_Stack6 bit6 */
			{19222,37,1}, /* core1 return_Stack6 bit7 */
			{24868,37,1}, /* core1 return_Stack6 bit8 */
			{14908,37,1}, /* core1 return_Stack6 bit9 */
			{19221,37,1}, /* core1 return_Stack6 bit10 */
			{24867,37,1}, /* core1 return_Stack6 bit11 */
			{14909,37,1}, /* core1 return_Stack6 bit12 */
			{14926,37,1}, /* core1 return_Stack6 bit13 */
			{17600,37,1}, /* core1 return_Stack6 bit14 */
			{14912,37,1}, /* core1 return_Stack6 bit15 */
			{19260,37,1}, /* core1 return_Stack6 bit16 */
			{17599,37,1}, /* core1 return_Stack6 bit17 */
			{17598,37,1}, /* core1 return_Stack6 bit18 */
			{19259,37,1}, /* core1 return_Stack6 bit19 */
			{19272,37,1}, /* core1 return_Stack6 bit20 */
			{17597,37,1}, /* core1 return_Stack6 bit21 */
			{19271,37,1}, /* core1 return_Stack6 bit22 */
			{14980,37,1}, /* core1 return_Stack6 bit23 */
			{14991,37,1}, /* core1 return_Stack6 bit24 */
			{17668,37,1}, /* core1 return_Stack6 bit25 */
			{19508,37,1}, /* core1 return_Stack6 bit26 */
			{19504,37,1}, /* core1 return_Stack6 bit27 */
			{19503,37,1}, /* core1 return_Stack6 bit28 */
			{14992,37,1}, /* core1 return_Stack6 bit29 */
			{17667,37,1}, /* core1 return_Stack6 bit30 */
			{17666,37,1}, /* core1 return_Stack6 bit31 */
			{17665,37,1}, /* core1 return_Stack6 bit32 */
			{19500,37,1}, /* core1 return_Stack6 bit33 */
			{14089,37,1}, /* core1 return_Stack6 bit34 */
			{19868,37,1}, /* core1 return_Stack6 bit35 */
			{19476,37,1}, /* core1 return_Stack6 bit36 */
			{19475,37,1}, /* core1 return_Stack6 bit37 */
			{19478,37,1}, /* core1 return_Stack6 bit38 */
			{19524,37,1}, /* core1 return_Stack6 bit39 */
			{19477,37,1}, /* core1 return_Stack6 bit40 */
			{19506,37,1}, /* core1 return_Stack6 bit41 */
			{19865,37,1}, /* core1 return_Stack6 bit42 */
			{19505,37,1}, /* core1 return_Stack6 bit43 */
			{19863,37,1}, /* core1 return_Stack6 bit44 */
			{19523,37,1}, /* core1 return_Stack6 bit45 */
			{19507,37,1}, /* core1 return_Stack6 bit46 */
			{19499,37,1}, /* core1 return_Stack6 bit47 */
			{14978,37,1}, /* core1 return_Stack6 bit48 */
			{    0, 0,2}, /* core1 return_Stack6 bit49 */
			{    0, 0,2}, /* core1 return_Stack6 bit50 */
			{    0, 0,2}, /* core1 return_Stack6 bit51 */
			{    0, 0,2}, /* core1 return_Stack6 bit52 */
			{    0, 0,2}, /* core1 return_Stack6 bit53 */
			{    0, 0,2}, /* core1 return_Stack6 bit54 */
			{    0, 0,2}, /* core1 return_Stack6 bit55 */
			{    0, 0,2}, /* core1 return_Stack6 bit56 */
			{    0, 0,2}, /* core1 return_Stack6 bit57 */
			{    0, 0,2}, /* core1 return_Stack6 bit58 */
			{    0, 0,2}, /* core1 return_Stack6 bit59 */
			{    0, 0,2}, /* core1 return_Stack6 bit60 */
			{    0, 0,2}, /* core1 return_Stack6 bit61 */
			{    0, 0,2}, /* core1 return_Stack6 bit62 */
			{    0, 0,2}, /* core1 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{21956,37,1}, /* core1 return_Stack7 bit0 */
			{21960,37,1}, /* core1 return_Stack7 bit1 */
			{21972,37,1}, /* core1 return_Stack7 bit2 */
			{19256,37,1}, /* core1 return_Stack7 bit3 */
			{19258,37,1}, /* core1 return_Stack7 bit4 */
			{19257,37,1}, /* core1 return_Stack7 bit5 */
			{27678,37,1}, /* core1 return_Stack7 bit6 */
			{27679,37,1}, /* core1 return_Stack7 bit7 */
			{19255,37,1}, /* core1 return_Stack7 bit8 */
			{21971,37,1}, /* core1 return_Stack7 bit9 */
			{21970,37,1}, /* core1 return_Stack7 bit10 */
			{27680,37,1}, /* core1 return_Stack7 bit11 */
			{21969,37,1}, /* core1 return_Stack7 bit12 */
			{21959,37,1}, /* core1 return_Stack7 bit13 */
			{21958,37,1}, /* core1 return_Stack7 bit14 */
			{21957,37,1}, /* core1 return_Stack7 bit15 */
			{27682,37,1}, /* core1 return_Stack7 bit16 */
			{27681,37,1}, /* core1 return_Stack7 bit17 */
			{21955,37,1}, /* core1 return_Stack7 bit18 */
			{21954,37,1}, /* core1 return_Stack7 bit19 */
			{19518,37,1}, /* core1 return_Stack7 bit20 */
			{21953,37,1}, /* core1 return_Stack7 bit21 */
			{19516,37,1}, /* core1 return_Stack7 bit22 */
			{19515,37,1}, /* core1 return_Stack7 bit23 */
			{21992,37,1}, /* core1 return_Stack7 bit24 */
			{19528,37,1}, /* core1 return_Stack7 bit25 */
			{21988,37,1}, /* core1 return_Stack7 bit26 */
			{21991,37,1}, /* core1 return_Stack7 bit27 */
			{21990,37,1}, /* core1 return_Stack7 bit28 */
			{19484,37,1}, /* core1 return_Stack7 bit29 */
			{21989,37,1}, /* core1 return_Stack7 bit30 */
			{21987,37,1}, /* core1 return_Stack7 bit31 */
			{21986,37,1}, /* core1 return_Stack7 bit32 */
			{21985,37,1}, /* core1 return_Stack7 bit33 */
			{19483,37,1}, /* core1 return_Stack7 bit34 */
			{14090,37,1}, /* core1 return_Stack7 bit35 */
			{14097,37,1}, /* core1 return_Stack7 bit36 */
			{19867,37,1}, /* core1 return_Stack7 bit37 */
			{27673,37,1}, /* core1 return_Stack7 bit38 */
			{14095,37,1}, /* core1 return_Stack7 bit39 */
			{19861,37,1}, /* core1 return_Stack7 bit40 */
			{27672,37,1}, /* core1 return_Stack7 bit41 */
			{19866,37,1}, /* core1 return_Stack7 bit42 */
			{14096,37,1}, /* core1 return_Stack7 bit43 */
			{19860,37,1}, /* core1 return_Stack7 bit44 */
			{27671,37,1}, /* core1 return_Stack7 bit45 */
			{27670,37,1}, /* core1 return_Stack7 bit46 */
			{19527,37,1}, /* core1 return_Stack7 bit47 */
			{19517,37,1}, /* core1 return_Stack7 bit48 */
			{    0, 0,2}, /* core1 return_Stack7 bit49 */
			{    0, 0,2}, /* core1 return_Stack7 bit50 */
			{    0, 0,2}, /* core1 return_Stack7 bit51 */
			{    0, 0,2}, /* core1 return_Stack7 bit52 */
			{    0, 0,2}, /* core1 return_Stack7 bit53 */
			{    0, 0,2}, /* core1 return_Stack7 bit54 */
			{    0, 0,2}, /* core1 return_Stack7 bit55 */
			{    0, 0,2}, /* core1 return_Stack7 bit56 */
			{    0, 0,2}, /* core1 return_Stack7 bit57 */
			{    0, 0,2}, /* core1 return_Stack7 bit58 */
			{    0, 0,2}, /* core1 return_Stack7 bit59 */
			{    0, 0,2}, /* core1 return_Stack7 bit60 */
			{    0, 0,2}, /* core1 return_Stack7 bit61 */
			{    0, 0,2}, /* core1 return_Stack7 bit62 */
			{    0, 0,2}, /* core1 return_Stack7 bit63 */
			}},
			.ECC_err0status_v = {{
			{37289,37,1}, /* core1 ECC_err0status_v bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_v bit63 */
			}},
			.ECC_err0status_ue = {{
			{37575,37,1}, /* core1 ECC_err0status_ue bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_ue bit63 */
			}},
			.ECC_err0status_er = {{
			{37576,37,1}, /* core1 ECC_err0status_er bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_er bit63 */
			}},
			.ECC_err0status_of = {{
			{31882,37,1}, /* core1 ECC_err0status_of bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_of bit63 */
			}},
			.ECC_err0status_mv = {{
			{37291,37,1}, /* core1 ECC_err0status_mv bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_mv bit63 */
			}},
			.ECC_err0status_ce = {{
			{29902,37,1}, /* core1 ECC_err0status_ce bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_ce bit63 */
			}},
			.ECC_err0status_de = {{
			{31883,37,1}, /* core1 ECC_err0status_de bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_de bit63 */
			}},
			.ECC_err0status_pn = {{
			{37290,37,1}, /* core1 ECC_err0status_pn bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_pn bit63 */
			}},
			.ECC_err0status_ierr = {{
			{37292,37,1}, /* core1 ECC_err0status_ierr bit0 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit1 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit2 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit3 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_ierr bit63 */
			}},
			.ECC_err0status_serr = {{
			{37570,37,1}, /* core1 ECC_err0status_serr bit0 */
			{37574,37,1}, /* core1 ECC_err0status_serr bit1 */
			{37569,37,1}, /* core1 ECC_err0status_serr bit2 */
			{37573,37,1}, /* core1 ECC_err0status_serr bit3 */
			{31828,37,1}, /* core1 ECC_err0status_serr bit4 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit5 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit6 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit7 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit8 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit9 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit10 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit11 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit12 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit13 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit14 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit15 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit16 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit17 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit18 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit19 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit20 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit21 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit22 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit23 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit24 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit25 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit26 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit27 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit28 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit29 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit30 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit31 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit32 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit33 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit34 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit35 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit36 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit37 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit38 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit39 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit40 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit41 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit42 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit43 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit44 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit45 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit46 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit47 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit48 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit49 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit50 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit51 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit52 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit53 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit54 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit55 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit56 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit57 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit58 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit59 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit60 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit61 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit62 */
			{    0, 0,2}, /* core1 ECC_err0status_serr bit63 */
			}},
			.ECC_err0misc_other_err_cnt_overflow = {{
			{39790,37,1}, /* core1 ECC_err0misc_other_err_cnt_overflow bit0 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit1 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit2 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit3 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit4 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit5 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit6 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit7 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit8 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit9 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit10 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit11 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit12 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit13 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit14 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit15 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit16 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit17 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit18 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit19 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit20 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit21 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit22 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit23 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit24 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit25 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit26 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit27 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit28 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit29 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit30 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit31 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit32 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit33 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit34 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit35 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit36 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit37 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit38 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit39 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit40 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit41 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit42 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit43 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit44 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit45 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit46 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit47 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit48 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit49 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit50 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit51 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit52 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit53 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit54 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit55 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit56 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit57 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit58 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit59 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit60 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit61 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit62 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt_overflow bit63 */
			}},
			.ECC_err0misc_other_err_cnt = {{
			{34012,37,1}, /* core1 ECC_err0misc_other_err_cnt bit0 */
			{29803,37,1}, /* core1 ECC_err0misc_other_err_cnt bit1 */
			{34016,37,1}, /* core1 ECC_err0misc_other_err_cnt bit2 */
			{34015,37,1}, /* core1 ECC_err0misc_other_err_cnt bit3 */
			{34014,37,1}, /* core1 ECC_err0misc_other_err_cnt bit4 */
			{34013,37,1}, /* core1 ECC_err0misc_other_err_cnt bit5 */
			{34011,37,1}, /* core1 ECC_err0misc_other_err_cnt bit6 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit7 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit8 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit9 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit10 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit11 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit12 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit13 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit14 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit15 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit16 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit17 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit18 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit19 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit20 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit21 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit22 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit23 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit24 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit25 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit26 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit27 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit28 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit29 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit30 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit31 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit32 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit33 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit34 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit35 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit36 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit37 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit38 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit39 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit40 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit41 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit42 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit43 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit44 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit45 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit46 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit47 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit48 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit49 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit50 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit51 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit52 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit53 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit54 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit55 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit56 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit57 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit58 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit59 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit60 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit61 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit62 */
			{    0, 0,2}, /* core1 ECC_err0misc_other_err_cnt bit63 */
			}},
			.ECC_err0misc_repeat_err_overflow = {{
			{29804,37,1}, /* core1 ECC_err0misc_repeat_err_overflow bit0 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit1 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit2 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit3 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit4 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit5 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit6 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit7 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit8 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit9 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit10 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit11 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit12 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit13 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit14 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit15 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit16 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit17 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit18 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit19 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit20 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit21 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit22 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit23 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit24 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit25 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit26 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit27 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit28 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit29 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit30 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit31 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit32 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit33 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit34 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit35 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit36 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit37 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit38 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit39 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit40 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit41 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit42 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit43 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit44 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit45 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit46 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit47 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit48 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit49 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit50 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit51 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit52 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit53 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit54 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit55 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit56 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit57 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit58 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit59 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit60 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit61 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit62 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_overflow bit63 */
			}},
			.ECC_err0misc_repeat_err_cnt = {{
			{34010,37,1}, /* core1 ECC_err0misc_repeat_err_cnt bit0 */
			{39789,37,1}, /* core1 ECC_err0misc_repeat_err_cnt bit1 */
			{39788,37,1}, /* core1 ECC_err0misc_repeat_err_cnt bit2 */
			{39787,37,1}, /* core1 ECC_err0misc_repeat_err_cnt bit3 */
			{39786,37,1}, /* core1 ECC_err0misc_repeat_err_cnt bit4 */
			{39785,37,1}, /* core1 ECC_err0misc_repeat_err_cnt bit5 */
			{34009,37,1}, /* core1 ECC_err0misc_repeat_err_cnt bit6 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit7 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit8 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit9 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit10 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit11 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit12 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit13 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit14 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit15 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit16 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit17 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit18 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit19 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit20 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit21 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit22 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit23 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit24 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit25 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit26 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit27 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit28 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit29 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit30 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit31 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit32 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit33 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit34 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit35 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit36 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit37 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit38 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit39 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit40 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit41 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit42 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit43 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit44 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit45 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit46 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit47 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit48 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit49 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit50 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit51 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit52 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit53 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit54 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit55 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit56 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit57 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit58 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit59 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit60 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit61 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit62 */
			{    0, 0,2}, /* core1 ECC_err0misc_repeat_err_cnt bit63 */
			}},
			.ECC_err0misc_way = {{
			{43026,37,1}, /* core1 ECC_err0misc_way bit0 */
			{43025,37,1}, /* core1 ECC_err0misc_way bit1 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit2 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit3 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit4 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit5 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit6 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit7 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit8 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit9 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit10 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit11 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit12 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit13 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit14 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit15 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit16 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit17 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit18 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit19 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit20 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit21 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit22 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit23 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit24 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit25 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit26 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit27 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit28 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit29 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit30 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit31 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit32 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit33 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit34 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit35 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit36 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit37 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit38 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit39 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit40 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit41 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit42 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit43 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit44 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit45 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit46 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit47 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit48 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit49 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit50 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit51 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit52 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit53 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit54 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit55 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit56 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit57 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit58 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit59 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit60 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit61 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit62 */
			{    0, 0,2}, /* core1 ECC_err0misc_way bit63 */
			}},
			.ECC_err0misc_index = {{
			{37296,37,1}, /* core1 ECC_err0misc_index bit0 */
			{37754,37,1}, /* core1 ECC_err0misc_index bit1 */
			{31917,37,1}, /* core1 ECC_err0misc_index bit2 */
			{31916,37,1}, /* core1 ECC_err0misc_index bit3 */
			{43029,37,1}, /* core1 ECC_err0misc_index bit4 */
			{43028,37,1}, /* core1 ECC_err0misc_index bit5 */
			{43027,37,1}, /* core1 ECC_err0misc_index bit6 */
			{37753,37,1}, /* core1 ECC_err0misc_index bit7 */
			{43030,37,1}, /* core1 ECC_err0misc_index bit8 */
			{37295,37,1}, /* core1 ECC_err0misc_index bit9 */
			{37294,37,1}, /* core1 ECC_err0misc_index bit10 */
			{37293,37,1}, /* core1 ECC_err0misc_index bit11 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit12 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit13 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit14 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit15 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit16 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit17 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit18 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit19 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit20 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit21 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit22 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit23 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit24 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit25 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit26 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit27 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit28 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit29 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit30 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit31 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit32 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit33 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit34 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit35 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit36 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit37 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit38 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit39 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit40 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit41 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit42 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit43 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit44 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit45 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit46 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit47 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit48 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit49 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit50 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit51 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit52 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit53 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit54 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit55 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit56 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit57 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit58 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit59 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit60 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit61 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit62 */
			{    0, 0,2}, /* core1 ECC_err0misc_index bit63 */
			}},
			.ECC_err0misc_level_contain_error = {{
			{37571,37,1}, /* core1 ECC_err0misc_level_contain_error bit0 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit1 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit2 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit3 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit4 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit5 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit6 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit7 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit8 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit9 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit10 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit11 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit12 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit13 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit14 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit15 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit16 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit17 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit18 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit19 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit20 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit21 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit22 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit23 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit24 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit25 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit26 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit27 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit28 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit29 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit30 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit31 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit32 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit33 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit34 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit35 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit36 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit37 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit38 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit39 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit40 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit41 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit42 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit43 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit44 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit45 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit46 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit47 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit48 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit49 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit50 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit51 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit52 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit53 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit54 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit55 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit56 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit57 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit58 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit59 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit60 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit61 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit62 */
			{    0, 0,2}, /* core1 ECC_err0misc_level_contain_error bit63 */
			}},
			.ECC_err0misc_indicate_icache = {{
			{37572,37,1}, /* core1 ECC_err0misc_indicate_icache bit0 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit1 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit2 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit3 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit4 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit5 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit6 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit7 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit8 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit9 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit10 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit11 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit12 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit13 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit14 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit15 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit16 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit17 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit18 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit19 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit20 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit21 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit22 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit23 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit24 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit25 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit26 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit27 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit28 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit29 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit30 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit31 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit32 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit33 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit34 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit35 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit36 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit37 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit38 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit39 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit40 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit41 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit42 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit43 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit44 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit45 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit46 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit47 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit48 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit49 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit50 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit51 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit52 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit53 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit54 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit55 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit56 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit57 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit58 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit59 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit60 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit61 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit62 */
			{    0, 0,2}, /* core1 ECC_err0misc_indicate_icache bit63 */
			}},
			.ECC_err0ctrl_fault_handling_interrupt = {{
			{29905,37,1}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit0 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit1 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit2 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit3 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit4 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit5 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit6 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit7 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit8 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit9 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit10 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit11 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit12 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit13 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit14 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit15 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit16 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit17 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit18 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit19 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit20 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit21 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit22 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit23 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit24 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit25 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit26 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit27 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit28 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit29 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit30 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit31 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit32 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit33 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit34 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit35 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit36 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit37 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit38 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit39 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit40 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit41 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit42 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit43 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit44 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit45 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit46 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit47 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit48 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit49 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit50 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit51 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit52 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit53 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit54 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit55 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit56 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit57 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit58 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit59 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit60 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit61 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit62 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_interrupt bit63 */
			}},
			.ECC_err0ctrl_fault_handling_int_enable = {{
			{37512,37,1}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit0 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit1 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit2 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit3 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit4 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit5 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit6 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit7 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit8 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit9 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit10 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit11 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit12 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit13 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit14 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit15 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit16 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit17 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit18 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit19 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit20 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit21 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit22 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit23 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit24 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit25 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit26 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit27 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit28 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit29 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit30 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit31 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit32 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit33 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit34 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit35 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit36 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit37 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit38 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit39 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit40 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit41 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit42 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit43 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit44 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit45 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit46 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit47 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit48 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit49 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit50 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit51 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit52 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit53 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit54 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit55 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit56 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit57 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit58 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit59 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit60 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit61 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit62 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_fault_handling_int_enable bit63 */
			}},
			.ECC_err0ctrl_error_recovery_int_enable = {{
			{37511,37,1}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit0 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit1 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit2 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit3 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit4 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit5 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit6 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit7 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit8 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit9 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit10 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit11 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit12 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit13 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit14 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit15 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit16 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit17 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit18 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit19 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit20 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit21 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit22 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit23 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit24 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit25 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit26 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit27 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit28 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit29 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit30 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit31 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit32 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit33 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit34 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit35 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit36 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit37 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit38 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit39 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit40 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit41 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit42 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit43 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit44 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit45 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit46 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit47 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit48 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit49 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit50 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit51 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit52 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit53 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit54 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit55 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit56 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit57 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit58 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit59 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit60 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit61 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit62 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_recovery_int_enable bit63 */
			}},
			.ECC_err0ctrl_error_detect_correct_enable = {{
			{29904,37,1}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit0 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit1 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit2 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit3 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit4 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit5 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit6 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit7 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit8 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit9 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit10 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit11 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit12 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit13 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit14 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit15 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit16 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit17 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit18 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit19 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit20 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit21 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit22 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit23 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit24 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit25 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit26 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit27 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit28 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit29 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit30 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit31 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit32 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit33 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit34 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit35 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit36 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit37 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit38 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit39 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit40 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit41 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit42 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit43 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit44 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit45 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit46 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit47 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit48 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit49 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit50 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit51 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit52 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit53 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit54 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit55 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit56 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit57 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit58 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit59 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit60 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit61 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit62 */
			{    0, 0,2}, /* core1 ECC_err0ctrl_error_detect_correct_enable bit63 */
			}},
	},
	{		/* core 2 */ 
			.pc = {{
			{  523,38,1}, /* core2 pc bit0 */
			{  240,38,1}, /* core2 pc bit1 */
			{  102,38,1}, /* core2 pc bit2 */
			{  239,38,1}, /* core2 pc bit3 */
			{  495,38,1}, /* core2 pc bit4 */
			{  203,38,1}, /* core2 pc bit5 */
			{  431,38,1}, /* core2 pc bit6 */
			{  224,38,1}, /* core2 pc bit7 */
			{  100,38,1}, /* core2 pc bit8 */
			{  236,38,1}, /* core2 pc bit9 */
			{   96,38,1}, /* core2 pc bit10 */
			{  494,38,1}, /* core2 pc bit11 */
			{  202,38,1}, /* core2 pc bit12 */
			{  543,38,1}, /* core2 pc bit13 */
			{  223,38,1}, /* core2 pc bit14 */
			{  235,38,1}, /* core2 pc bit15 */
			{   94,38,1}, /* core2 pc bit16 */
			{  356,38,1}, /* core2 pc bit17 */
			{  207,38,1}, /* core2 pc bit18 */
			{  539,38,1}, /* core2 pc bit19 */
			{  511,38,1}, /* core2 pc bit20 */
			{   95,38,1}, /* core2 pc bit21 */
			{  522,38,1}, /* core2 pc bit22 */
			{  206,38,1}, /* core2 pc bit23 */
			{  220,38,1}, /* core2 pc bit24 */
			{  234,38,1}, /* core2 pc bit25 */
			{  355,38,1}, /* core2 pc bit26 */
			{  475,38,1}, /* core2 pc bit27 */
			{  538,38,1}, /* core2 pc bit28 */
			{  537,38,1}, /* core2 pc bit29 */
			{  536,38,1}, /* core2 pc bit30 */
			{  112,38,1}, /* core2 pc bit31 */
			{  215,38,1}, /* core2 pc bit32 */
			{  547,38,1}, /* core2 pc bit33 */
			{  230,38,1}, /* core2 pc bit34 */
			{  229,38,1}, /* core2 pc bit35 */
			{  491,38,1}, /* core2 pc bit36 */
			{  546,38,1}, /* core2 pc bit37 */
			{  423,38,1}, /* core2 pc bit38 */
			{  427,38,1}, /* core2 pc bit39 */
			{  211,38,1}, /* core2 pc bit40 */
			{  110,38,1}, /* core2 pc bit41 */
			{  367,38,1}, /* core2 pc bit42 */
			{  214,38,1}, /* core2 pc bit43 */
			{  542,38,1}, /* core2 pc bit44 */
			{  545,38,1}, /* core2 pc bit45 */
			{  426,38,1}, /* core2 pc bit46 */
			{  369,38,1}, /* core2 pc bit47 */
			{  425,38,1}, /* core2 pc bit48 */
			{  368,38,1}, /* core2 pc bit49 */
			{  430,38,1}, /* core2 pc bit50 */
			{  213,38,1}, /* core2 pc bit51 */
			{  212,38,1}, /* core2 pc bit52 */
			{  232,38,1}, /* core2 pc bit53 */
			{  535,38,1}, /* core2 pc bit54 */
			{  422,38,1}, /* core2 pc bit55 */
			{  490,38,1}, /* core2 pc bit56 */
			{  114,38,1}, /* core2 pc bit57 */
			{  415,38,1}, /* core2 pc bit58 */
			{  116,38,1}, /* core2 pc bit59 */
			{  429,38,1}, /* core2 pc bit60 */
			{  421,38,1}, /* core2 pc bit61 */
			{  420,38,1}, /* core2 pc bit62 */
			{  534,38,1}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{33132,39,1}, /* core2 sp32 bit0 */
			{33140,39,1}, /* core2 sp32 bit1 */
			{39344,39,1}, /* core2 sp32 bit2 */
			{39224,39,1}, /* core2 sp32 bit3 */
			{39343,39,1}, /* core2 sp32 bit4 */
			{33200,39,1}, /* core2 sp32 bit5 */
			{33199,39,1}, /* core2 sp32 bit6 */
			{38350,39,1}, /* core2 sp32 bit7 */
			{33128,39,1}, /* core2 sp32 bit8 */
			{33127,39,1}, /* core2 sp32 bit9 */
			{33198,39,1}, /* core2 sp32 bit10 */
			{39350,39,1}, /* core2 sp32 bit11 */
			{39240,39,1}, /* core2 sp32 bit12 */
			{39239,39,1}, /* core2 sp32 bit13 */
			{39342,39,1}, /* core2 sp32 bit14 */
			{39223,39,1}, /* core2 sp32 bit15 */
			{39349,39,1}, /* core2 sp32 bit16 */
			{39242,39,1}, /* core2 sp32 bit17 */
			{33126,39,1}, /* core2 sp32 bit18 */
			{33131,39,1}, /* core2 sp32 bit19 */
			{33125,39,1}, /* core2 sp32 bit20 */
			{33139,39,1}, /* core2 sp32 bit21 */
			{38353,39,1}, /* core2 sp32 bit22 */
			{39341,39,1}, /* core2 sp32 bit23 */
			{33138,39,1}, /* core2 sp32 bit24 */
			{33130,39,1}, /* core2 sp32 bit25 */
			{33197,39,1}, /* core2 sp32 bit26 */
			{33129,39,1}, /* core2 sp32 bit27 */
			{38356,39,1}, /* core2 sp32 bit28 */
			{38352,39,1}, /* core2 sp32 bit29 */
			{39241,39,1}, /* core2 sp32 bit30 */
			{33137,39,1}, /* core2 sp32 bit31 */
			{29541,39,1}, /* core2 sp32 bit32 */
			{29629,39,1}, /* core2 sp32 bit33 */
			{43006,39,1}, /* core2 sp32 bit34 */
			{29540,39,1}, /* core2 sp32 bit35 */
			{29628,39,1}, /* core2 sp32 bit36 */
			{29539,39,1}, /* core2 sp32 bit37 */
			{32952,39,1}, /* core2 sp32 bit38 */
			{29715,39,1}, /* core2 sp32 bit39 */
			{29713,39,1}, /* core2 sp32 bit40 */
			{32951,39,1}, /* core2 sp32 bit41 */
			{32950,39,1}, /* core2 sp32 bit42 */
			{43005,39,1}, /* core2 sp32 bit43 */
			{29712,39,1}, /* core2 sp32 bit44 */
			{29714,39,1}, /* core2 sp32 bit45 */
			{32949,39,1}, /* core2 sp32 bit46 */
			{29315,39,1}, /* core2 sp32 bit47 */
			{29317,39,1}, /* core2 sp32 bit48 */
			{29409,39,1}, /* core2 sp32 bit49 */
			{29316,39,1}, /* core2 sp32 bit50 */
			{29415,39,1}, /* core2 sp32 bit51 */
			{29414,39,1}, /* core2 sp32 bit52 */
			{29407,39,1}, /* core2 sp32 bit53 */
			{29406,39,1}, /* core2 sp32 bit54 */
			{42991,39,1}, /* core2 sp32 bit55 */
			{29411,39,1}, /* core2 sp32 bit56 */
			{29413,39,1}, /* core2 sp32 bit57 */
			{29314,39,1}, /* core2 sp32 bit58 */
			{29410,39,1}, /* core2 sp32 bit59 */
			{29412,39,1}, /* core2 sp32 bit60 */
			{42989,39,1}, /* core2 sp32 bit61 */
			{29408,39,1}, /* core2 sp32 bit62 */
			{29538,39,1}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{39308,39,1}, /* core2 fp32 bit0 */
			{39246,39,1}, /* core2 fp32 bit1 */
			{33160,39,1}, /* core2 fp32 bit2 */
			{33152,39,1}, /* core2 fp32 bit3 */
			{33159,39,1}, /* core2 fp32 bit4 */
			{33151,39,1}, /* core2 fp32 bit5 */
			{39334,39,1}, /* core2 fp32 bit6 */
			{33148,39,1}, /* core2 fp32 bit7 */
			{39332,39,1}, /* core2 fp32 bit8 */
			{32636,39,1}, /* core2 fp32 bit9 */
			{32635,39,1}, /* core2 fp32 bit10 */
			{32634,39,1}, /* core2 fp32 bit11 */
			{38329,39,1}, /* core2 fp32 bit12 */
			{39304,39,1}, /* core2 fp32 bit13 */
			{39333,39,1}, /* core2 fp32 bit14 */
			{39303,39,1}, /* core2 fp32 bit15 */
			{38346,39,1}, /* core2 fp32 bit16 */
			{32633,39,1}, /* core2 fp32 bit17 */
			{33156,39,1}, /* core2 fp32 bit18 */
			{33147,39,1}, /* core2 fp32 bit19 */
			{33155,39,1}, /* core2 fp32 bit20 */
			{33154,39,1}, /* core2 fp32 bit21 */
			{33150,39,1}, /* core2 fp32 bit22 */
			{33158,39,1}, /* core2 fp32 bit23 */
			{33149,39,1}, /* core2 fp32 bit24 */
			{39307,39,1}, /* core2 fp32 bit25 */
			{39331,39,1}, /* core2 fp32 bit26 */
			{39245,39,1}, /* core2 fp32 bit27 */
			{33146,39,1}, /* core2 fp32 bit28 */
			{33153,39,1}, /* core2 fp32 bit29 */
			{33145,39,1}, /* core2 fp32 bit30 */
			{33157,39,1}, /* core2 fp32 bit31 */
			{32928,39,1}, /* core2 fp32 bit32 */
			{29285,39,1}, /* core2 fp32 bit33 */
			{29284,39,1}, /* core2 fp32 bit34 */
			{32927,39,1}, /* core2 fp32 bit35 */
			{43000,39,1}, /* core2 fp32 bit36 */
			{32926,39,1}, /* core2 fp32 bit37 */
			{29295,39,1}, /* core2 fp32 bit38 */
			{29291,39,1}, /* core2 fp32 bit39 */
			{29287,39,1}, /* core2 fp32 bit40 */
			{42999,39,1}, /* core2 fp32 bit41 */
			{38251,39,1}, /* core2 fp32 bit42 */
			{38250,39,1}, /* core2 fp32 bit43 */
			{29294,39,1}, /* core2 fp32 bit44 */
			{29286,39,1}, /* core2 fp32 bit45 */
			{29290,39,1}, /* core2 fp32 bit46 */
			{33012,39,1}, /* core2 fp32 bit47 */
			{33011,39,1}, /* core2 fp32 bit48 */
			{33010,39,1}, /* core2 fp32 bit49 */
			{29443,39,1}, /* core2 fp32 bit50 */
			{33009,39,1}, /* core2 fp32 bit51 */
			{29447,39,1}, /* core2 fp32 bit52 */
			{29442,39,1}, /* core2 fp32 bit53 */
			{34234,39,1}, /* core2 fp32 bit54 */
			{29297,39,1}, /* core2 fp32 bit55 */
			{29446,39,1}, /* core2 fp32 bit56 */
			{29296,39,1}, /* core2 fp32 bit57 */
			{29445,39,1}, /* core2 fp32 bit58 */
			{34235,39,1}, /* core2 fp32 bit59 */
			{29444,39,1}, /* core2 fp32 bit60 */
			{29441,39,1}, /* core2 fp32 bit61 */
			{29440,39,1}, /* core2 fp32 bit62 */
			{32925,39,1}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{32660,39,1}, /* core2 fp64 bit0 */
			{32668,39,1}, /* core2 fp64 bit1 */
			{32659,39,1}, /* core2 fp64 bit2 */
			{32676,39,1}, /* core2 fp64 bit3 */
			{32658,39,1}, /* core2 fp64 bit4 */
			{32657,39,1}, /* core2 fp64 bit5 */
			{32656,39,1}, /* core2 fp64 bit6 */
			{38427,39,1}, /* core2 fp64 bit7 */
			{38488,39,1}, /* core2 fp64 bit8 */
			{32655,39,1}, /* core2 fp64 bit9 */
			{38428,39,1}, /* core2 fp64 bit10 */
			{32654,39,1}, /* core2 fp64 bit11 */
			{38423,39,1}, /* core2 fp64 bit12 */
			{32653,39,1}, /* core2 fp64 bit13 */
			{38490,39,1}, /* core2 fp64 bit14 */
			{38492,39,1}, /* core2 fp64 bit15 */
			{38487,39,1}, /* core2 fp64 bit16 */
			{38491,39,1}, /* core2 fp64 bit17 */
			{38489,39,1}, /* core2 fp64 bit18 */
			{32667,39,1}, /* core2 fp64 bit19 */
			{32666,39,1}, /* core2 fp64 bit20 */
			{32675,39,1}, /* core2 fp64 bit21 */
			{38856,39,1}, /* core2 fp64 bit22 */
			{32672,39,1}, /* core2 fp64 bit23 */
			{32671,39,1}, /* core2 fp64 bit24 */
			{38422,39,1}, /* core2 fp64 bit25 */
			{32665,39,1}, /* core2 fp64 bit26 */
			{32670,39,1}, /* core2 fp64 bit27 */
			{32674,39,1}, /* core2 fp64 bit28 */
			{38855,39,1}, /* core2 fp64 bit29 */
			{32673,39,1}, /* core2 fp64 bit30 */
			{32669,39,1}, /* core2 fp64 bit31 */
			{39065,39,1}, /* core2 fp64 bit32 */
			{38229,39,1}, /* core2 fp64 bit33 */
			{38227,39,1}, /* core2 fp64 bit34 */
			{39064,39,1}, /* core2 fp64 bit35 */
			{38224,39,1}, /* core2 fp64 bit36 */
			{38225,39,1}, /* core2 fp64 bit37 */
			{39069,39,1}, /* core2 fp64 bit38 */
			{39061,39,1}, /* core2 fp64 bit39 */
			{39063,39,1}, /* core2 fp64 bit40 */
			{38222,39,1}, /* core2 fp64 bit41 */
			{39071,39,1}, /* core2 fp64 bit42 */
			{39070,39,1}, /* core2 fp64 bit43 */
			{39060,39,1}, /* core2 fp64 bit44 */
			{38228,39,1}, /* core2 fp64 bit45 */
			{39068,39,1}, /* core2 fp64 bit46 */
			{39045,39,1}, /* core2 fp64 bit47 */
			{39044,39,1}, /* core2 fp64 bit48 */
			{39041,39,1}, /* core2 fp64 bit49 */
			{39037,39,1}, /* core2 fp64 bit50 */
			{29577,39,1}, /* core2 fp64 bit51 */
			{29576,39,1}, /* core2 fp64 bit52 */
			{39039,39,1}, /* core2 fp64 bit53 */
			{39038,39,1}, /* core2 fp64 bit54 */
			{29575,39,1}, /* core2 fp64 bit55 */
			{39036,39,1}, /* core2 fp64 bit56 */
			{39043,39,1}, /* core2 fp64 bit57 */
			{39042,39,1}, /* core2 fp64 bit58 */
			{30046,39,1}, /* core2 fp64 bit59 */
			{39040,39,1}, /* core2 fp64 bit60 */
			{29574,39,1}, /* core2 fp64 bit61 */
			{30045,39,1}, /* core2 fp64 bit62 */
			{39062,39,1}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{38539,39,1}, /* core2 sp_EL0 bit0 */
			{32816,39,1}, /* core2 sp_EL0 bit1 */
			{32808,39,1}, /* core2 sp_EL0 bit2 */
			{38533,39,1}, /* core2 sp_EL0 bit3 */
			{32740,39,1}, /* core2 sp_EL0 bit4 */
			{32807,39,1}, /* core2 sp_EL0 bit5 */
			{38531,39,1}, /* core2 sp_EL0 bit6 */
			{38538,39,1}, /* core2 sp_EL0 bit7 */
			{38540,39,1}, /* core2 sp_EL0 bit8 */
			{38882,39,1}, /* core2 sp_EL0 bit9 */
			{32739,39,1}, /* core2 sp_EL0 bit10 */
			{32806,39,1}, /* core2 sp_EL0 bit11 */
			{32815,39,1}, /* core2 sp_EL0 bit12 */
			{32814,39,1}, /* core2 sp_EL0 bit13 */
			{32805,39,1}, /* core2 sp_EL0 bit14 */
			{32738,39,1}, /* core2 sp_EL0 bit15 */
			{38532,39,1}, /* core2 sp_EL0 bit16 */
			{32737,39,1}, /* core2 sp_EL0 bit17 */
			{38537,39,1}, /* core2 sp_EL0 bit18 */
			{32813,39,1}, /* core2 sp_EL0 bit19 */
			{38884,39,1}, /* core2 sp_EL0 bit20 */
			{38881,39,1}, /* core2 sp_EL0 bit21 */
			{38878,39,1}, /* core2 sp_EL0 bit22 */
			{38448,39,1}, /* core2 sp_EL0 bit23 */
			{38880,39,1}, /* core2 sp_EL0 bit24 */
			{32744,39,1}, /* core2 sp_EL0 bit25 */
			{38877,39,1}, /* core2 sp_EL0 bit26 */
			{32743,39,1}, /* core2 sp_EL0 bit27 */
			{38879,39,1}, /* core2 sp_EL0 bit28 */
			{32742,39,1}, /* core2 sp_EL0 bit29 */
			{32741,39,1}, /* core2 sp_EL0 bit30 */
			{38883,39,1}, /* core2 sp_EL0 bit31 */
			{32202,39,1}, /* core2 sp_EL0 bit32 */
			{32204,39,1}, /* core2 sp_EL0 bit33 */
			{32201,39,1}, /* core2 sp_EL0 bit34 */
			{33365,39,1}, /* core2 sp_EL0 bit35 */
			{32203,39,1}, /* core2 sp_EL0 bit36 */
			{33366,39,1}, /* core2 sp_EL0 bit37 */
			{32388,39,1}, /* core2 sp_EL0 bit38 */
			{32384,39,1}, /* core2 sp_EL0 bit39 */
			{32387,39,1}, /* core2 sp_EL0 bit40 */
			{32383,39,1}, /* core2 sp_EL0 bit41 */
			{38812,39,1}, /* core2 sp_EL0 bit42 */
			{32382,39,1}, /* core2 sp_EL0 bit43 */
			{38811,39,1}, /* core2 sp_EL0 bit44 */
			{32386,39,1}, /* core2 sp_EL0 bit45 */
			{32381,39,1}, /* core2 sp_EL0 bit46 */
			{32212,39,1}, /* core2 sp_EL0 bit47 */
			{32211,39,1}, /* core2 sp_EL0 bit48 */
			{32454,39,1}, /* core2 sp_EL0 bit49 */
			{32218,39,1}, /* core2 sp_EL0 bit50 */
			{32217,39,1}, /* core2 sp_EL0 bit51 */
			{32453,39,1}, /* core2 sp_EL0 bit52 */
			{30043,39,1}, /* core2 sp_EL0 bit53 */
			{32452,39,1}, /* core2 sp_EL0 bit54 */
			{32451,39,1}, /* core2 sp_EL0 bit55 */
			{32220,39,1}, /* core2 sp_EL0 bit56 */
			{32222,39,1}, /* core2 sp_EL0 bit57 */
			{32221,39,1}, /* core2 sp_EL0 bit58 */
			{32219,39,1}, /* core2 sp_EL0 bit59 */
			{30044,39,1}, /* core2 sp_EL0 bit60 */
			{32216,39,1}, /* core2 sp_EL0 bit61 */
			{32215,39,1}, /* core2 sp_EL0 bit62 */
			{32385,39,1}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{38443,39,1}, /* core2 sp_EL1 bit0 */
			{38447,39,1}, /* core2 sp_EL1 bit1 */
			{32812,39,1}, /* core2 sp_EL1 bit2 */
			{32811,39,1}, /* core2 sp_EL1 bit3 */
			{38445,39,1}, /* core2 sp_EL1 bit4 */
			{38442,39,1}, /* core2 sp_EL1 bit5 */
			{38536,39,1}, /* core2 sp_EL1 bit6 */
			{38441,39,1}, /* core2 sp_EL1 bit7 */
			{38444,39,1}, /* core2 sp_EL1 bit8 */
			{32820,39,1}, /* core2 sp_EL1 bit9 */
			{38446,39,1}, /* core2 sp_EL1 bit10 */
			{38440,39,1}, /* core2 sp_EL1 bit11 */
			{38534,39,1}, /* core2 sp_EL1 bit12 */
			{32819,39,1}, /* core2 sp_EL1 bit13 */
			{38535,39,1}, /* core2 sp_EL1 bit14 */
			{32810,39,1}, /* core2 sp_EL1 bit15 */
			{32809,39,1}, /* core2 sp_EL1 bit16 */
			{38529,39,1}, /* core2 sp_EL1 bit17 */
			{38528,39,1}, /* core2 sp_EL1 bit18 */
			{32818,39,1}, /* core2 sp_EL1 bit19 */
			{38876,39,1}, /* core2 sp_EL1 bit20 */
			{32824,39,1}, /* core2 sp_EL1 bit21 */
			{32823,39,1}, /* core2 sp_EL1 bit22 */
			{38874,39,1}, /* core2 sp_EL1 bit23 */
			{38875,39,1}, /* core2 sp_EL1 bit24 */
			{38872,39,1}, /* core2 sp_EL1 bit25 */
			{32822,39,1}, /* core2 sp_EL1 bit26 */
			{32821,39,1}, /* core2 sp_EL1 bit27 */
			{38873,39,1}, /* core2 sp_EL1 bit28 */
			{32817,39,1}, /* core2 sp_EL1 bit29 */
			{38871,39,1}, /* core2 sp_EL1 bit30 */
			{38530,39,1}, /* core2 sp_EL1 bit31 */
			{32376,39,1}, /* core2 sp_EL1 bit32 */
			{32375,39,1}, /* core2 sp_EL1 bit33 */
			{32374,39,1}, /* core2 sp_EL1 bit34 */
			{32208,39,1}, /* core2 sp_EL1 bit35 */
			{30040,39,1}, /* core2 sp_EL1 bit36 */
			{32207,39,1}, /* core2 sp_EL1 bit37 */
			{39083,39,1}, /* core2 sp_EL1 bit38 */
			{39081,39,1}, /* core2 sp_EL1 bit39 */
			{39082,39,1}, /* core2 sp_EL1 bit40 */
			{33364,39,1}, /* core2 sp_EL1 bit41 */
			{38810,39,1}, /* core2 sp_EL1 bit42 */
			{29724,39,1}, /* core2 sp_EL1 bit43 */
			{38809,39,1}, /* core2 sp_EL1 bit44 */
			{39080,39,1}, /* core2 sp_EL1 bit45 */
			{29740,39,1}, /* core2 sp_EL1 bit46 */
			{32214,39,1}, /* core2 sp_EL1 bit47 */
			{32450,39,1}, /* core2 sp_EL1 bit48 */
			{32442,39,1}, /* core2 sp_EL1 bit49 */
			{32441,39,1}, /* core2 sp_EL1 bit50 */
			{32449,39,1}, /* core2 sp_EL1 bit51 */
			{32440,39,1}, /* core2 sp_EL1 bit52 */
			{32224,39,1}, /* core2 sp_EL1 bit53 */
			{32446,39,1}, /* core2 sp_EL1 bit54 */
			{32213,39,1}, /* core2 sp_EL1 bit55 */
			{32445,39,1}, /* core2 sp_EL1 bit56 */
			{32448,39,1}, /* core2 sp_EL1 bit57 */
			{32447,39,1}, /* core2 sp_EL1 bit58 */
			{32223,39,1}, /* core2 sp_EL1 bit59 */
			{32439,39,1}, /* core2 sp_EL1 bit60 */
			{32444,39,1}, /* core2 sp_EL1 bit61 */
			{32443,39,1}, /* core2 sp_EL1 bit62 */
			{32373,39,1}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{38517,39,1}, /* core2 sp_EL2 bit0 */
			{32700,39,1}, /* core2 sp_EL2 bit1 */
			{38516,39,1}, /* core2 sp_EL2 bit2 */
			{32699,39,1}, /* core2 sp_EL2 bit3 */
			{38410,39,1}, /* core2 sp_EL2 bit4 */
			{32732,39,1}, /* core2 sp_EL2 bit5 */
			{32698,39,1}, /* core2 sp_EL2 bit6 */
			{32697,39,1}, /* core2 sp_EL2 bit7 */
			{38519,39,1}, /* core2 sp_EL2 bit8 */
			{32731,39,1}, /* core2 sp_EL2 bit9 */
			{32730,39,1}, /* core2 sp_EL2 bit10 */
			{38523,39,1}, /* core2 sp_EL2 bit11 */
			{38527,39,1}, /* core2 sp_EL2 bit12 */
			{38525,39,1}, /* core2 sp_EL2 bit13 */
			{38521,39,1}, /* core2 sp_EL2 bit14 */
			{38409,39,1}, /* core2 sp_EL2 bit15 */
			{38520,39,1}, /* core2 sp_EL2 bit16 */
			{38524,39,1}, /* core2 sp_EL2 bit17 */
			{38518,39,1}, /* core2 sp_EL2 bit18 */
			{32696,39,1}, /* core2 sp_EL2 bit19 */
			{38412,39,1}, /* core2 sp_EL2 bit20 */
			{32729,39,1}, /* core2 sp_EL2 bit21 */
			{32728,39,1}, /* core2 sp_EL2 bit22 */
			{32727,39,1}, /* core2 sp_EL2 bit23 */
			{38522,39,1}, /* core2 sp_EL2 bit24 */
			{32695,39,1}, /* core2 sp_EL2 bit25 */
			{38526,39,1}, /* core2 sp_EL2 bit26 */
			{38411,39,1}, /* core2 sp_EL2 bit27 */
			{32726,39,1}, /* core2 sp_EL2 bit28 */
			{32725,39,1}, /* core2 sp_EL2 bit29 */
			{32694,39,1}, /* core2 sp_EL2 bit30 */
			{32693,39,1}, /* core2 sp_EL2 bit31 */
			{33368,39,1}, /* core2 sp_EL2 bit32 */
			{32206,39,1}, /* core2 sp_EL2 bit33 */
			{33369,39,1}, /* core2 sp_EL2 bit34 */
			{33367,39,1}, /* core2 sp_EL2 bit35 */
			{32102,39,1}, /* core2 sp_EL2 bit36 */
			{32205,39,1}, /* core2 sp_EL2 bit37 */
			{32106,39,1}, /* core2 sp_EL2 bit38 */
			{38802,39,1}, /* core2 sp_EL2 bit39 */
			{29727,39,1}, /* core2 sp_EL2 bit40 */
			{32396,39,1}, /* core2 sp_EL2 bit41 */
			{38801,39,1}, /* core2 sp_EL2 bit42 */
			{32395,39,1}, /* core2 sp_EL2 bit43 */
			{32394,39,1}, /* core2 sp_EL2 bit44 */
			{32105,39,1}, /* core2 sp_EL2 bit45 */
			{32393,39,1}, /* core2 sp_EL2 bit46 */
			{32210,39,1}, /* core2 sp_EL2 bit47 */
			{32209,39,1}, /* core2 sp_EL2 bit48 */
			{30042,39,1}, /* core2 sp_EL2 bit49 */
			{32434,39,1}, /* core2 sp_EL2 bit50 */
			{32433,39,1}, /* core2 sp_EL2 bit51 */
			{32228,39,1}, /* core2 sp_EL2 bit52 */
			{30049,39,1}, /* core2 sp_EL2 bit53 */
			{30048,39,1}, /* core2 sp_EL2 bit54 */
			{32432,39,1}, /* core2 sp_EL2 bit55 */
			{32230,39,1}, /* core2 sp_EL2 bit56 */
			{32232,39,1}, /* core2 sp_EL2 bit57 */
			{30041,39,1}, /* core2 sp_EL2 bit58 */
			{32229,39,1}, /* core2 sp_EL2 bit59 */
			{32231,39,1}, /* core2 sp_EL2 bit60 */
			{32431,39,1}, /* core2 sp_EL2 bit61 */
			{32227,39,1}, /* core2 sp_EL2 bit62 */
			{32101,39,1}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{32708,39,1}, /* core2 sp_EL3 bit0 */
			{38506,39,1}, /* core2 sp_EL3 bit1 */
			{38498,39,1}, /* core2 sp_EL3 bit2 */
			{32707,39,1}, /* core2 sp_EL3 bit3 */
			{32706,39,1}, /* core2 sp_EL3 bit4 */
			{32705,39,1}, /* core2 sp_EL3 bit5 */
			{38502,39,1}, /* core2 sp_EL3 bit6 */
			{38496,39,1}, /* core2 sp_EL3 bit7 */
			{38495,39,1}, /* core2 sp_EL3 bit8 */
			{38504,39,1}, /* core2 sp_EL3 bit9 */
			{38497,39,1}, /* core2 sp_EL3 bit10 */
			{38418,39,1}, /* core2 sp_EL3 bit11 */
			{38501,39,1}, /* core2 sp_EL3 bit12 */
			{38416,39,1}, /* core2 sp_EL3 bit13 */
			{38500,39,1}, /* core2 sp_EL3 bit14 */
			{38419,39,1}, /* core2 sp_EL3 bit15 */
			{38417,39,1}, /* core2 sp_EL3 bit16 */
			{38503,39,1}, /* core2 sp_EL3 bit17 */
			{38499,39,1}, /* core2 sp_EL3 bit18 */
			{32716,39,1}, /* core2 sp_EL3 bit19 */
			{32724,39,1}, /* core2 sp_EL3 bit20 */
			{32723,39,1}, /* core2 sp_EL3 bit21 */
			{32715,39,1}, /* core2 sp_EL3 bit22 */
			{32720,39,1}, /* core2 sp_EL3 bit23 */
			{38505,39,1}, /* core2 sp_EL3 bit24 */
			{32714,39,1}, /* core2 sp_EL3 bit25 */
			{32722,39,1}, /* core2 sp_EL3 bit26 */
			{32721,39,1}, /* core2 sp_EL3 bit27 */
			{32719,39,1}, /* core2 sp_EL3 bit28 */
			{32718,39,1}, /* core2 sp_EL3 bit29 */
			{32717,39,1}, /* core2 sp_EL3 bit30 */
			{32713,39,1}, /* core2 sp_EL3 bit31 */
			{32380,39,1}, /* core2 sp_EL3 bit32 */
			{32379,39,1}, /* core2 sp_EL3 bit33 */
			{32372,39,1}, /* core2 sp_EL3 bit34 */
			{32371,39,1}, /* core2 sp_EL3 bit35 */
			{32370,39,1}, /* core2 sp_EL3 bit36 */
			{32369,39,1}, /* core2 sp_EL3 bit37 */
			{29739,39,1}, /* core2 sp_EL3 bit38 */
			{38808,39,1}, /* core2 sp_EL3 bit39 */
			{32378,39,1}, /* core2 sp_EL3 bit40 */
			{38807,39,1}, /* core2 sp_EL3 bit41 */
			{38804,39,1}, /* core2 sp_EL3 bit42 */
			{38806,39,1}, /* core2 sp_EL3 bit43 */
			{29738,39,1}, /* core2 sp_EL3 bit44 */
			{38803,39,1}, /* core2 sp_EL3 bit45 */
			{38805,39,1}, /* core2 sp_EL3 bit46 */
			{32344,39,1}, /* core2 sp_EL3 bit47 */
			{32343,39,1}, /* core2 sp_EL3 bit48 */
			{32342,39,1}, /* core2 sp_EL3 bit49 */
			{32236,39,1}, /* core2 sp_EL3 bit50 */
			{32234,39,1}, /* core2 sp_EL3 bit51 */
			{32438,39,1}, /* core2 sp_EL3 bit52 */
			{32235,39,1}, /* core2 sp_EL3 bit53 */
			{32437,39,1}, /* core2 sp_EL3 bit54 */
			{32233,39,1}, /* core2 sp_EL3 bit55 */
			{30047,39,1}, /* core2 sp_EL3 bit56 */
			{30050,39,1}, /* core2 sp_EL3 bit57 */
			{32341,39,1}, /* core2 sp_EL3 bit58 */
			{32436,39,1}, /* core2 sp_EL3 bit59 */
			{32435,39,1}, /* core2 sp_EL3 bit60 */
			{32226,39,1}, /* core2 sp_EL3 bit61 */
			{32225,39,1}, /* core2 sp_EL3 bit62 */
			{32377,39,1}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{32542,39,1}, /* core2 elr_EL1 bit0 */
			{38888,39,1}, /* core2 elr_EL1 bit1 */
			{38892,39,1}, /* core2 elr_EL1 bit2 */
			{38894,39,1}, /* core2 elr_EL1 bit3 */
			{38896,39,1}, /* core2 elr_EL1 bit4 */
			{38543,39,1}, /* core2 elr_EL1 bit5 */
			{38893,39,1}, /* core2 elr_EL1 bit6 */
			{38891,39,1}, /* core2 elr_EL1 bit7 */
			{38895,39,1}, /* core2 elr_EL1 bit8 */
			{38544,39,1}, /* core2 elr_EL1 bit9 */
			{38886,39,1}, /* core2 elr_EL1 bit10 */
			{32541,39,1}, /* core2 elr_EL1 bit11 */
			{38890,39,1}, /* core2 elr_EL1 bit12 */
			{38542,39,1}, /* core2 elr_EL1 bit13 */
			{38885,39,1}, /* core2 elr_EL1 bit14 */
			{32540,39,1}, /* core2 elr_EL1 bit15 */
			{32539,39,1}, /* core2 elr_EL1 bit16 */
			{38887,39,1}, /* core2 elr_EL1 bit17 */
			{38889,39,1}, /* core2 elr_EL1 bit18 */
			{32800,39,1}, /* core2 elr_EL1 bit19 */
			{32804,39,1}, /* core2 elr_EL1 bit20 */
			{32796,39,1}, /* core2 elr_EL1 bit21 */
			{32799,39,1}, /* core2 elr_EL1 bit22 */
			{32798,39,1}, /* core2 elr_EL1 bit23 */
			{32795,39,1}, /* core2 elr_EL1 bit24 */
			{32803,39,1}, /* core2 elr_EL1 bit25 */
			{32794,39,1}, /* core2 elr_EL1 bit26 */
			{32802,39,1}, /* core2 elr_EL1 bit27 */
			{32797,39,1}, /* core2 elr_EL1 bit28 */
			{29781,39,1}, /* core2 elr_EL1 bit29 */
			{32793,39,1}, /* core2 elr_EL1 bit30 */
			{32801,39,1}, /* core2 elr_EL1 bit31 */
			{32392,39,1}, /* core2 elr_EL1 bit32 */
			{32368,39,1}, /* core2 elr_EL1 bit33 */
			{32391,39,1}, /* core2 elr_EL1 bit34 */
			{32390,39,1}, /* core2 elr_EL1 bit35 */
			{32389,39,1}, /* core2 elr_EL1 bit36 */
			{32367,39,1}, /* core2 elr_EL1 bit37 */
			{33346,39,1}, /* core2 elr_EL1 bit38 */
			{32104,39,1}, /* core2 elr_EL1 bit39 */
			{33345,39,1}, /* core2 elr_EL1 bit40 */
			{32400,39,1}, /* core2 elr_EL1 bit41 */
			{32399,39,1}, /* core2 elr_EL1 bit42 */
			{32398,39,1}, /* core2 elr_EL1 bit43 */
			{29737,39,1}, /* core2 elr_EL1 bit44 */
			{32103,39,1}, /* core2 elr_EL1 bit45 */
			{32397,39,1}, /* core2 elr_EL1 bit46 */
			{32346,39,1}, /* core2 elr_EL1 bit47 */
			{33361,39,1}, /* core2 elr_EL1 bit48 */
			{33360,39,1}, /* core2 elr_EL1 bit49 */
			{32238,39,1}, /* core2 elr_EL1 bit50 */
			{33362,39,1}, /* core2 elr_EL1 bit51 */
			{32340,39,1}, /* core2 elr_EL1 bit52 */
			{32350,39,1}, /* core2 elr_EL1 bit53 */
			{32240,39,1}, /* core2 elr_EL1 bit54 */
			{32237,39,1}, /* core2 elr_EL1 bit55 */
			{32349,39,1}, /* core2 elr_EL1 bit56 */
			{32345,39,1}, /* core2 elr_EL1 bit57 */
			{32348,39,1}, /* core2 elr_EL1 bit58 */
			{32239,39,1}, /* core2 elr_EL1 bit59 */
			{32347,39,1}, /* core2 elr_EL1 bit60 */
			{33363,39,1}, /* core2 elr_EL1 bit61 */
			{32339,39,1}, /* core2 elr_EL1 bit62 */
			{33347,39,1}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{38754,39,1}, /* core2 elr_EL2 bit0 */
			{29783,39,1}, /* core2 elr_EL2 bit1 */
			{29782,39,1}, /* core2 elr_EL2 bit2 */
			{38742,39,1}, /* core2 elr_EL2 bit3 */
			{38752,39,1}, /* core2 elr_EL2 bit4 */
			{38740,39,1}, /* core2 elr_EL2 bit5 */
			{38898,39,1}, /* core2 elr_EL2 bit6 */
			{38750,39,1}, /* core2 elr_EL2 bit7 */
			{38545,39,1}, /* core2 elr_EL2 bit8 */
			{38753,39,1}, /* core2 elr_EL2 bit9 */
			{38739,39,1}, /* core2 elr_EL2 bit10 */
			{38897,39,1}, /* core2 elr_EL2 bit11 */
			{38541,39,1}, /* core2 elr_EL2 bit12 */
			{38749,39,1}, /* core2 elr_EL2 bit13 */
			{38741,39,1}, /* core2 elr_EL2 bit14 */
			{38546,39,1}, /* core2 elr_EL2 bit15 */
			{38751,39,1}, /* core2 elr_EL2 bit16 */
			{38744,39,1}, /* core2 elr_EL2 bit17 */
			{38743,39,1}, /* core2 elr_EL2 bit18 */
			{38738,39,1}, /* core2 elr_EL2 bit19 */
			{32538,39,1}, /* core2 elr_EL2 bit20 */
			{38736,39,1}, /* core2 elr_EL2 bit21 */
			{38746,39,1}, /* core2 elr_EL2 bit22 */
			{38737,39,1}, /* core2 elr_EL2 bit23 */
			{32537,39,1}, /* core2 elr_EL2 bit24 */
			{38745,39,1}, /* core2 elr_EL2 bit25 */
			{38735,39,1}, /* core2 elr_EL2 bit26 */
			{29784,39,1}, /* core2 elr_EL2 bit27 */
			{38748,39,1}, /* core2 elr_EL2 bit28 */
			{32536,39,1}, /* core2 elr_EL2 bit29 */
			{32535,39,1}, /* core2 elr_EL2 bit30 */
			{38747,39,1}, /* core2 elr_EL2 bit31 */
			{32362,39,1}, /* core2 elr_EL2 bit32 */
			{32361,39,1}, /* core2 elr_EL2 bit33 */
			{32416,39,1}, /* core2 elr_EL2 bit34 */
			{32415,39,1}, /* core2 elr_EL2 bit35 */
			{33348,39,1}, /* core2 elr_EL2 bit36 */
			{32360,39,1}, /* core2 elr_EL2 bit37 */
			{32414,39,1}, /* core2 elr_EL2 bit38 */
			{32413,39,1}, /* core2 elr_EL2 bit39 */
			{32410,39,1}, /* core2 elr_EL2 bit40 */
			{32264,39,1}, /* core2 elr_EL2 bit41 */
			{32263,39,1}, /* core2 elr_EL2 bit42 */
			{32409,39,1}, /* core2 elr_EL2 bit43 */
			{32412,39,1}, /* core2 elr_EL2 bit44 */
			{32411,39,1}, /* core2 elr_EL2 bit45 */
			{29736,39,1}, /* core2 elr_EL2 bit46 */
			{32358,39,1}, /* core2 elr_EL2 bit47 */
			{32354,39,1}, /* core2 elr_EL2 bit48 */
			{33358,39,1}, /* core2 elr_EL2 bit49 */
			{32244,39,1}, /* core2 elr_EL2 bit50 */
			{32357,39,1}, /* core2 elr_EL2 bit51 */
			{32246,39,1}, /* core2 elr_EL2 bit52 */
			{32353,39,1}, /* core2 elr_EL2 bit53 */
			{32352,39,1}, /* core2 elr_EL2 bit54 */
			{32242,39,1}, /* core2 elr_EL2 bit55 */
			{32243,39,1}, /* core2 elr_EL2 bit56 */
			{32356,39,1}, /* core2 elr_EL2 bit57 */
			{33359,39,1}, /* core2 elr_EL2 bit58 */
			{32241,39,1}, /* core2 elr_EL2 bit59 */
			{32245,39,1}, /* core2 elr_EL2 bit60 */
			{32351,39,1}, /* core2 elr_EL2 bit61 */
			{32355,39,1}, /* core2 elr_EL2 bit62 */
			{32359,39,1}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{33256,39,1}, /* core2 elr_EL3 bit0 */
			{33260,39,1}, /* core2 elr_EL3 bit1 */
			{33259,39,1}, /* core2 elr_EL3 bit2 */
			{29173,39,1}, /* core2 elr_EL3 bit3 */
			{38756,39,1}, /* core2 elr_EL3 bit4 */
			{38870,39,1}, /* core2 elr_EL3 bit5 */
			{29169,39,1}, /* core2 elr_EL3 bit6 */
			{29168,39,1}, /* core2 elr_EL3 bit7 */
			{33255,39,1}, /* core2 elr_EL3 bit8 */
			{29171,39,1}, /* core2 elr_EL3 bit9 */
			{33258,39,1}, /* core2 elr_EL3 bit10 */
			{38755,39,1}, /* core2 elr_EL3 bit11 */
			{33254,39,1}, /* core2 elr_EL3 bit12 */
			{33253,39,1}, /* core2 elr_EL3 bit13 */
			{33257,39,1}, /* core2 elr_EL3 bit14 */
			{38401,39,1}, /* core2 elr_EL3 bit15 */
			{29170,39,1}, /* core2 elr_EL3 bit16 */
			{38869,39,1}, /* core2 elr_EL3 bit17 */
			{38403,39,1}, /* core2 elr_EL3 bit18 */
			{38400,39,1}, /* core2 elr_EL3 bit19 */
			{29179,39,1}, /* core2 elr_EL3 bit20 */
			{29181,39,1}, /* core2 elr_EL3 bit21 */
			{29177,39,1}, /* core2 elr_EL3 bit22 */
			{29180,39,1}, /* core2 elr_EL3 bit23 */
			{38404,39,1}, /* core2 elr_EL3 bit24 */
			{38402,39,1}, /* core2 elr_EL3 bit25 */
			{38405,39,1}, /* core2 elr_EL3 bit26 */
			{29176,39,1}, /* core2 elr_EL3 bit27 */
			{29175,39,1}, /* core2 elr_EL3 bit28 */
			{29178,39,1}, /* core2 elr_EL3 bit29 */
			{29174,39,1}, /* core2 elr_EL3 bit30 */
			{29172,39,1}, /* core2 elr_EL3 bit31 */
			{33349,39,1}, /* core2 elr_EL3 bit32 */
			{32366,39,1}, /* core2 elr_EL3 bit33 */
			{32365,39,1}, /* core2 elr_EL3 bit34 */
			{32100,39,1}, /* core2 elr_EL3 bit35 */
			{32099,39,1}, /* core2 elr_EL3 bit36 */
			{32364,39,1}, /* core2 elr_EL3 bit37 */
			{32408,39,1}, /* core2 elr_EL3 bit38 */
			{29735,39,1}, /* core2 elr_EL3 bit39 */
			{32404,39,1}, /* core2 elr_EL3 bit40 */
			{32403,39,1}, /* core2 elr_EL3 bit41 */
			{32407,39,1}, /* core2 elr_EL3 bit42 */
			{32406,39,1}, /* core2 elr_EL3 bit43 */
			{32402,39,1}, /* core2 elr_EL3 bit44 */
			{32401,39,1}, /* core2 elr_EL3 bit45 */
			{32405,39,1}, /* core2 elr_EL3 bit46 */
			{38198,39,1}, /* core2 elr_EL3 bit47 */
			{38197,39,1}, /* core2 elr_EL3 bit48 */
			{32250,39,1}, /* core2 elr_EL3 bit49 */
			{38196,39,1}, /* core2 elr_EL3 bit50 */
			{33357,39,1}, /* core2 elr_EL3 bit51 */
			{32430,39,1}, /* core2 elr_EL3 bit52 */
			{32248,39,1}, /* core2 elr_EL3 bit53 */
			{33354,39,1}, /* core2 elr_EL3 bit54 */
			{32429,39,1}, /* core2 elr_EL3 bit55 */
			{32096,39,1}, /* core2 elr_EL3 bit56 */
			{33355,39,1}, /* core2 elr_EL3 bit57 */
			{32095,39,1}, /* core2 elr_EL3 bit58 */
			{32247,39,1}, /* core2 elr_EL3 bit59 */
			{32249,39,1}, /* core2 elr_EL3 bit60 */
			{33356,39,1}, /* core2 elr_EL3 bit61 */
			{38195,39,1}, /* core2 elr_EL3 bit62 */
			{32363,39,1}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31360,39,1}, /* core2 raw_pc bit0 */
			{31359,39,1}, /* core2 raw_pc bit1 */
			{36945,39,1}, /* core2 raw_pc bit2 */
			{36947,39,1}, /* core2 raw_pc bit3 */
			{31357,39,1}, /* core2 raw_pc bit4 */
			{31358,39,1}, /* core2 raw_pc bit5 */
			{31356,39,1}, /* core2 raw_pc bit6 */
			{36950,39,1}, /* core2 raw_pc bit7 */
			{36954,39,1}, /* core2 raw_pc bit8 */
			{40774,39,1}, /* core2 raw_pc bit9 */
			{40773,39,1}, /* core2 raw_pc bit10 */
			{36949,39,1}, /* core2 raw_pc bit11 */
			{38665,39,1}, /* core2 raw_pc bit12 */
			{40776,39,1}, /* core2 raw_pc bit13 */
			{42270,39,1}, /* core2 raw_pc bit14 */
			{42269,39,1}, /* core2 raw_pc bit15 */
			{40775,39,1}, /* core2 raw_pc bit16 */
			{42601,39,1}, /* core2 raw_pc bit17 */
			{38657,39,1}, /* core2 raw_pc bit18 */
			{42600,39,1}, /* core2 raw_pc bit19 */
			{42204,39,1}, /* core2 raw_pc bit20 */
			{42268,39,1}, /* core2 raw_pc bit21 */
			{42267,39,1}, /* core2 raw_pc bit22 */
			{38664,39,1}, /* core2 raw_pc bit23 */
			{38662,39,1}, /* core2 raw_pc bit24 */
			{42599,39,1}, /* core2 raw_pc bit25 */
			{38663,39,1}, /* core2 raw_pc bit26 */
			{42203,39,1}, /* core2 raw_pc bit27 */
			{42598,39,1}, /* core2 raw_pc bit28 */
			{36951,39,1}, /* core2 raw_pc bit29 */
			{36955,39,1}, /* core2 raw_pc bit30 */
			{42208,39,1}, /* core2 raw_pc bit31 */
			{42206,39,1}, /* core2 raw_pc bit32 */
			{36896,39,1}, /* core2 raw_pc bit33 */
			{42244,39,1}, /* core2 raw_pc bit34 */
			{42212,39,1}, /* core2 raw_pc bit35 */
			{42205,39,1}, /* core2 raw_pc bit36 */
			{42207,39,1}, /* core2 raw_pc bit37 */
			{42236,39,1}, /* core2 raw_pc bit38 */
			{42243,39,1}, /* core2 raw_pc bit39 */
			{42235,39,1}, /* core2 raw_pc bit40 */
			{42234,39,1}, /* core2 raw_pc bit41 */
			{42211,39,1}, /* core2 raw_pc bit42 */
			{42242,39,1}, /* core2 raw_pc bit43 */
			{42241,39,1}, /* core2 raw_pc bit44 */
			{42233,39,1}, /* core2 raw_pc bit45 */
			{42210,39,1}, /* core2 raw_pc bit46 */
			{42209,39,1}, /* core2 raw_pc bit47 */
			{42246,39,1}, /* core2 raw_pc bit48 */
			{42245,39,1}, /* core2 raw_pc bit49 */
			{    0, 0,2}, /* core2 raw_pc bit50 */
			{    0, 0,2}, /* core2 raw_pc bit51 */
			{    0, 0,2}, /* core2 raw_pc bit52 */
			{    0, 0,2}, /* core2 raw_pc bit53 */
			{    0, 0,2}, /* core2 raw_pc bit54 */
			{    0, 0,2}, /* core2 raw_pc bit55 */
			{    0, 0,2}, /* core2 raw_pc bit56 */
			{    0, 0,2}, /* core2 raw_pc bit57 */
			{    0, 0,2}, /* core2 raw_pc bit58 */
			{    0, 0,2}, /* core2 raw_pc bit59 */
			{    0, 0,2}, /* core2 raw_pc bit60 */
			{    0, 0,2}, /* core2 raw_pc bit61 */
			{    0, 0,2}, /* core2 raw_pc bit62 */
			{    0, 0,2}, /* core2 raw_pc bit63 */
			}},
			.pc_iss = {{
			{41846,39,1}, /* core2 pc_iss bit0 */
			{41845,39,1}, /* core2 pc_iss bit1 */
			{41844,39,1}, /* core2 pc_iss bit2 */
			{36925,39,1}, /* core2 pc_iss bit3 */
			{41843,39,1}, /* core2 pc_iss bit4 */
			{41583,39,1}, /* core2 pc_iss bit5 */
			{36924,39,1}, /* core2 pc_iss bit6 */
			{41582,39,1}, /* core2 pc_iss bit7 */
			{41617,39,1}, /* core2 pc_iss bit8 */
			{38614,39,1}, /* core2 pc_iss bit9 */
			{31173,39,1}, /* core2 pc_iss bit10 */
			{31167,39,1}, /* core2 pc_iss bit11 */
			{31166,39,1}, /* core2 pc_iss bit12 */
			{41621,39,1}, /* core2 pc_iss bit13 */
			{38612,39,1}, /* core2 pc_iss bit14 */
			{41856,39,1}, /* core2 pc_iss bit15 */
			{31172,39,1}, /* core2 pc_iss bit16 */
			{41620,39,1}, /* core2 pc_iss bit17 */
			{31697,39,1}, /* core2 pc_iss bit18 */
			{41616,39,1}, /* core2 pc_iss bit19 */
			{41619,39,1}, /* core2 pc_iss bit20 */
			{41855,39,1}, /* core2 pc_iss bit21 */
			{41854,39,1}, /* core2 pc_iss bit22 */
			{41853,39,1}, /* core2 pc_iss bit23 */
			{41618,39,1}, /* core2 pc_iss bit24 */
			{41848,39,1}, /* core2 pc_iss bit25 */
			{41847,39,1}, /* core2 pc_iss bit26 */
			{41611,39,1}, /* core2 pc_iss bit27 */
			{41610,39,1}, /* core2 pc_iss bit28 */
			{31696,39,1}, /* core2 pc_iss bit29 */
			{41609,39,1}, /* core2 pc_iss bit30 */
			{41608,39,1}, /* core2 pc_iss bit31 */
			{36940,39,1}, /* core2 pc_iss bit32 */
			{41597,39,1}, /* core2 pc_iss bit33 */
			{41596,39,1}, /* core2 pc_iss bit34 */
			{36939,39,1}, /* core2 pc_iss bit35 */
			{36886,39,1}, /* core2 pc_iss bit36 */
			{31193,39,1}, /* core2 pc_iss bit37 */
			{31192,39,1}, /* core2 pc_iss bit38 */
			{36938,39,1}, /* core2 pc_iss bit39 */
			{41593,39,1}, /* core2 pc_iss bit40 */
			{41592,39,1}, /* core2 pc_iss bit41 */
			{41595,39,1}, /* core2 pc_iss bit42 */
			{38617,39,1}, /* core2 pc_iss bit43 */
			{41594,39,1}, /* core2 pc_iss bit44 */
			{38611,39,1}, /* core2 pc_iss bit45 */
			{38616,39,1}, /* core2 pc_iss bit46 */
			{38658,39,1}, /* core2 pc_iss bit47 */
			{38659,39,1}, /* core2 pc_iss bit48 */
			{31163,39,1}, /* core2 pc_iss bit49 */
			{38660,39,1}, /* core2 pc_iss bit50 */
			{42603,39,1}, /* core2 pc_iss bit51 */
			{31162,39,1}, /* core2 pc_iss bit52 */
			{42602,39,1}, /* core2 pc_iss bit53 */
			{38661,39,1}, /* core2 pc_iss bit54 */
			{42202,39,1}, /* core2 pc_iss bit55 */
			{38656,39,1}, /* core2 pc_iss bit56 */
			{42198,39,1}, /* core2 pc_iss bit57 */
			{42197,39,1}, /* core2 pc_iss bit58 */
			{42196,39,1}, /* core2 pc_iss bit59 */
			{42201,39,1}, /* core2 pc_iss bit60 */
			{42200,39,1}, /* core2 pc_iss bit61 */
			{42195,39,1}, /* core2 pc_iss bit62 */
			{42199,39,1}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31361,39,1}, /* core2 full_pc_wr bit0 */
			{    0, 0,2}, /* core2 full_pc_wr bit1 */
			{    0, 0,2}, /* core2 full_pc_wr bit2 */
			{    0, 0,2}, /* core2 full_pc_wr bit3 */
			{    0, 0,2}, /* core2 full_pc_wr bit4 */
			{    0, 0,2}, /* core2 full_pc_wr bit5 */
			{    0, 0,2}, /* core2 full_pc_wr bit6 */
			{    0, 0,2}, /* core2 full_pc_wr bit7 */
			{    0, 0,2}, /* core2 full_pc_wr bit8 */
			{    0, 0,2}, /* core2 full_pc_wr bit9 */
			{    0, 0,2}, /* core2 full_pc_wr bit10 */
			{    0, 0,2}, /* core2 full_pc_wr bit11 */
			{    0, 0,2}, /* core2 full_pc_wr bit12 */
			{    0, 0,2}, /* core2 full_pc_wr bit13 */
			{    0, 0,2}, /* core2 full_pc_wr bit14 */
			{    0, 0,2}, /* core2 full_pc_wr bit15 */
			{    0, 0,2}, /* core2 full_pc_wr bit16 */
			{    0, 0,2}, /* core2 full_pc_wr bit17 */
			{    0, 0,2}, /* core2 full_pc_wr bit18 */
			{    0, 0,2}, /* core2 full_pc_wr bit19 */
			{    0, 0,2}, /* core2 full_pc_wr bit20 */
			{    0, 0,2}, /* core2 full_pc_wr bit21 */
			{    0, 0,2}, /* core2 full_pc_wr bit22 */
			{    0, 0,2}, /* core2 full_pc_wr bit23 */
			{    0, 0,2}, /* core2 full_pc_wr bit24 */
			{    0, 0,2}, /* core2 full_pc_wr bit25 */
			{    0, 0,2}, /* core2 full_pc_wr bit26 */
			{    0, 0,2}, /* core2 full_pc_wr bit27 */
			{    0, 0,2}, /* core2 full_pc_wr bit28 */
			{    0, 0,2}, /* core2 full_pc_wr bit29 */
			{    0, 0,2}, /* core2 full_pc_wr bit30 */
			{    0, 0,2}, /* core2 full_pc_wr bit31 */
			{    0, 0,2}, /* core2 full_pc_wr bit32 */
			{    0, 0,2}, /* core2 full_pc_wr bit33 */
			{    0, 0,2}, /* core2 full_pc_wr bit34 */
			{    0, 0,2}, /* core2 full_pc_wr bit35 */
			{    0, 0,2}, /* core2 full_pc_wr bit36 */
			{    0, 0,2}, /* core2 full_pc_wr bit37 */
			{    0, 0,2}, /* core2 full_pc_wr bit38 */
			{    0, 0,2}, /* core2 full_pc_wr bit39 */
			{    0, 0,2}, /* core2 full_pc_wr bit40 */
			{    0, 0,2}, /* core2 full_pc_wr bit41 */
			{    0, 0,2}, /* core2 full_pc_wr bit42 */
			{    0, 0,2}, /* core2 full_pc_wr bit43 */
			{    0, 0,2}, /* core2 full_pc_wr bit44 */
			{    0, 0,2}, /* core2 full_pc_wr bit45 */
			{    0, 0,2}, /* core2 full_pc_wr bit46 */
			{    0, 0,2}, /* core2 full_pc_wr bit47 */
			{    0, 0,2}, /* core2 full_pc_wr bit48 */
			{    0, 0,2}, /* core2 full_pc_wr bit49 */
			{    0, 0,2}, /* core2 full_pc_wr bit50 */
			{    0, 0,2}, /* core2 full_pc_wr bit51 */
			{    0, 0,2}, /* core2 full_pc_wr bit52 */
			{    0, 0,2}, /* core2 full_pc_wr bit53 */
			{    0, 0,2}, /* core2 full_pc_wr bit54 */
			{    0, 0,2}, /* core2 full_pc_wr bit55 */
			{    0, 0,2}, /* core2 full_pc_wr bit56 */
			{    0, 0,2}, /* core2 full_pc_wr bit57 */
			{    0, 0,2}, /* core2 full_pc_wr bit58 */
			{    0, 0,2}, /* core2 full_pc_wr bit59 */
			{    0, 0,2}, /* core2 full_pc_wr bit60 */
			{    0, 0,2}, /* core2 full_pc_wr bit61 */
			{    0, 0,2}, /* core2 full_pc_wr bit62 */
			{    0, 0,2}, /* core2 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{41585,39,1}, /* core2 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{40768,39,1}, /* core2 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{27703,39,1}, /* core2 return_Stack_pointer bit0 */
			{27701,39,1}, /* core2 return_Stack_pointer bit1 */
			{14039,39,1}, /* core2 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{17696,39,1}, /* core2 return_Stack0 bit0 */
			{17695,39,1}, /* core2 return_Stack0 bit1 */
			{14923,39,1}, /* core2 return_Stack0 bit2 */
			{14929,39,1}, /* core2 return_Stack0 bit3 */
			{14928,39,1}, /* core2 return_Stack0 bit4 */
			{14931,39,1}, /* core2 return_Stack0 bit5 */
			{17596,39,1}, /* core2 return_Stack0 bit6 */
			{17595,39,1}, /* core2 return_Stack0 bit7 */
			{14922,39,1}, /* core2 return_Stack0 bit8 */
			{14919,39,1}, /* core2 return_Stack0 bit9 */
			{14920,39,1}, /* core2 return_Stack0 bit10 */
			{14911,39,1}, /* core2 return_Stack0 bit11 */
			{14921,39,1}, /* core2 return_Stack0 bit12 */
			{14925,39,1}, /* core2 return_Stack0 bit13 */
			{19268,39,1}, /* core2 return_Stack0 bit14 */
			{14924,39,1}, /* core2 return_Stack0 bit15 */
			{19252,39,1}, /* core2 return_Stack0 bit16 */
			{19251,39,1}, /* core2 return_Stack0 bit17 */
			{19266,39,1}, /* core2 return_Stack0 bit18 */
			{19265,39,1}, /* core2 return_Stack0 bit19 */
			{19267,39,1}, /* core2 return_Stack0 bit20 */
			{14930,39,1}, /* core2 return_Stack0 bit21 */
			{14932,39,1}, /* core2 return_Stack0 bit22 */
			{17694,39,1}, /* core2 return_Stack0 bit23 */
			{14994,39,1}, /* core2 return_Stack0 bit24 */
			{19364,39,1}, /* core2 return_Stack0 bit25 */
			{19538,39,1}, /* core2 return_Stack0 bit26 */
			{19537,39,1}, /* core2 return_Stack0 bit27 */
			{19540,39,1}, /* core2 return_Stack0 bit28 */
			{17616,39,1}, /* core2 return_Stack0 bit29 */
			{15000,39,1}, /* core2 return_Stack0 bit30 */
			{19539,39,1}, /* core2 return_Stack0 bit31 */
			{19363,39,1}, /* core2 return_Stack0 bit32 */
			{17615,39,1}, /* core2 return_Stack0 bit33 */
			{17614,39,1}, /* core2 return_Stack0 bit34 */
			{19534,39,1}, /* core2 return_Stack0 bit35 */
			{17620,39,1}, /* core2 return_Stack0 bit36 */
			{17619,39,1}, /* core2 return_Stack0 bit37 */
			{17618,39,1}, /* core2 return_Stack0 bit38 */
			{17688,39,1}, /* core2 return_Stack0 bit39 */
			{19533,39,1}, /* core2 return_Stack0 bit40 */
			{17687,39,1}, /* core2 return_Stack0 bit41 */
			{17617,39,1}, /* core2 return_Stack0 bit42 */
			{14996,39,1}, /* core2 return_Stack0 bit43 */
			{17686,39,1}, /* core2 return_Stack0 bit44 */
			{17685,39,1}, /* core2 return_Stack0 bit45 */
			{14935,39,1}, /* core2 return_Stack0 bit46 */
			{17613,39,1}, /* core2 return_Stack0 bit47 */
			{17693,39,1}, /* core2 return_Stack0 bit48 */
			{    0, 0,2}, /* core2 return_Stack0 bit49 */
			{    0, 0,2}, /* core2 return_Stack0 bit50 */
			{    0, 0,2}, /* core2 return_Stack0 bit51 */
			{    0, 0,2}, /* core2 return_Stack0 bit52 */
			{    0, 0,2}, /* core2 return_Stack0 bit53 */
			{    0, 0,2}, /* core2 return_Stack0 bit54 */
			{    0, 0,2}, /* core2 return_Stack0 bit55 */
			{    0, 0,2}, /* core2 return_Stack0 bit56 */
			{    0, 0,2}, /* core2 return_Stack0 bit57 */
			{    0, 0,2}, /* core2 return_Stack0 bit58 */
			{    0, 0,2}, /* core2 return_Stack0 bit59 */
			{    0, 0,2}, /* core2 return_Stack0 bit60 */
			{    0, 0,2}, /* core2 return_Stack0 bit61 */
			{    0, 0,2}, /* core2 return_Stack0 bit62 */
			{    0, 0,2}, /* core2 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{17692,39,1}, /* core2 return_Stack1 bit0 */
			{24874,39,1}, /* core2 return_Stack1 bit1 */
			{21980,39,1}, /* core2 return_Stack1 bit2 */
			{24873,39,1}, /* core2 return_Stack1 bit3 */
			{24872,39,1}, /* core2 return_Stack1 bit4 */
			{14984,39,1}, /* core2 return_Stack1 bit5 */
			{24871,39,1}, /* core2 return_Stack1 bit6 */
			{19240,39,1}, /* core2 return_Stack1 bit7 */
			{21979,39,1}, /* core2 return_Stack1 bit8 */
			{19238,39,1}, /* core2 return_Stack1 bit9 */
			{19239,39,1}, /* core2 return_Stack1 bit10 */
			{21978,39,1}, /* core2 return_Stack1 bit11 */
			{21977,39,1}, /* core2 return_Stack1 bit12 */
			{14985,39,1}, /* core2 return_Stack1 bit13 */
			{17691,39,1}, /* core2 return_Stack1 bit14 */
			{19237,39,1}, /* core2 return_Stack1 bit15 */
			{17604,39,1}, /* core2 return_Stack1 bit16 */
			{17603,39,1}, /* core2 return_Stack1 bit17 */
			{19522,39,1}, /* core2 return_Stack1 bit18 */
			{17602,39,1}, /* core2 return_Stack1 bit19 */
			{14976,39,1}, /* core2 return_Stack1 bit20 */
			{17601,39,1}, /* core2 return_Stack1 bit21 */
			{19521,39,1}, /* core2 return_Stack1 bit22 */
			{17690,39,1}, /* core2 return_Stack1 bit23 */
			{19498,39,1}, /* core2 return_Stack1 bit24 */
			{17612,39,1}, /* core2 return_Stack1 bit25 */
			{17664,39,1}, /* core2 return_Stack1 bit26 */
			{17611,39,1}, /* core2 return_Stack1 bit27 */
			{19497,39,1}, /* core2 return_Stack1 bit28 */
			{17610,39,1}, /* core2 return_Stack1 bit29 */
			{17663,39,1}, /* core2 return_Stack1 bit30 */
			{14934,39,1}, /* core2 return_Stack1 bit31 */
			{17609,39,1}, /* core2 return_Stack1 bit32 */
			{17662,39,1}, /* core2 return_Stack1 bit33 */
			{19502,39,1}, /* core2 return_Stack1 bit34 */
			{14092,39,1}, /* core2 return_Stack1 bit35 */
			{17624,39,1}, /* core2 return_Stack1 bit36 */
			{17623,39,1}, /* core2 return_Stack1 bit37 */
			{17622,39,1}, /* core2 return_Stack1 bit38 */
			{17676,39,1}, /* core2 return_Stack1 bit39 */
			{17675,39,1}, /* core2 return_Stack1 bit40 */
			{17674,39,1}, /* core2 return_Stack1 bit41 */
			{17673,39,1}, /* core2 return_Stack1 bit42 */
			{17621,39,1}, /* core2 return_Stack1 bit43 */
			{19280,39,1}, /* core2 return_Stack1 bit44 */
			{19279,39,1}, /* core2 return_Stack1 bit45 */
			{17661,39,1}, /* core2 return_Stack1 bit46 */
			{19501,39,1}, /* core2 return_Stack1 bit47 */
			{17689,39,1}, /* core2 return_Stack1 bit48 */
			{    0, 0,2}, /* core2 return_Stack1 bit49 */
			{    0, 0,2}, /* core2 return_Stack1 bit50 */
			{    0, 0,2}, /* core2 return_Stack1 bit51 */
			{    0, 0,2}, /* core2 return_Stack1 bit52 */
			{    0, 0,2}, /* core2 return_Stack1 bit53 */
			{    0, 0,2}, /* core2 return_Stack1 bit54 */
			{    0, 0,2}, /* core2 return_Stack1 bit55 */
			{    0, 0,2}, /* core2 return_Stack1 bit56 */
			{    0, 0,2}, /* core2 return_Stack1 bit57 */
			{    0, 0,2}, /* core2 return_Stack1 bit58 */
			{    0, 0,2}, /* core2 return_Stack1 bit59 */
			{    0, 0,2}, /* core2 return_Stack1 bit60 */
			{    0, 0,2}, /* core2 return_Stack1 bit61 */
			{    0, 0,2}, /* core2 return_Stack1 bit62 */
			{    0, 0,2}, /* core2 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{17700,39,1}, /* core2 return_Stack2 bit0 */
			{17699,39,1}, /* core2 return_Stack2 bit1 */
			{14901,39,1}, /* core2 return_Stack2 bit2 */
			{14933,39,1}, /* core2 return_Stack2 bit3 */
			{19264,39,1}, /* core2 return_Stack2 bit4 */
			{19236,39,1}, /* core2 return_Stack2 bit5 */
			{19263,39,1}, /* core2 return_Stack2 bit6 */
			{14907,39,1}, /* core2 return_Stack2 bit7 */
			{19228,39,1}, /* core2 return_Stack2 bit8 */
			{14902,39,1}, /* core2 return_Stack2 bit9 */
			{19235,39,1}, /* core2 return_Stack2 bit10 */
			{14904,39,1}, /* core2 return_Stack2 bit11 */
			{19227,39,1}, /* core2 return_Stack2 bit12 */
			{14915,39,1}, /* core2 return_Stack2 bit13 */
			{17698,39,1}, /* core2 return_Stack2 bit14 */
			{14905,39,1}, /* core2 return_Stack2 bit15 */
			{14916,39,1}, /* core2 return_Stack2 bit16 */
			{14914,39,1}, /* core2 return_Stack2 bit17 */
			{19276,39,1}, /* core2 return_Stack2 bit18 */
			{19275,39,1}, /* core2 return_Stack2 bit19 */
			{19274,39,1}, /* core2 return_Stack2 bit20 */
			{14981,39,1}, /* core2 return_Stack2 bit21 */
			{19273,39,1}, /* core2 return_Stack2 bit22 */
			{14982,39,1}, /* core2 return_Stack2 bit23 */
			{19362,39,1}, /* core2 return_Stack2 bit24 */
			{19361,39,1}, /* core2 return_Stack2 bit25 */
			{17660,39,1}, /* core2 return_Stack2 bit26 */
			{19492,39,1}, /* core2 return_Stack2 bit27 */
			{17656,39,1}, /* core2 return_Stack2 bit28 */
			{19491,39,1}, /* core2 return_Stack2 bit29 */
			{17655,39,1}, /* core2 return_Stack2 bit30 */
			{17654,39,1}, /* core2 return_Stack2 bit31 */
			{17653,39,1}, /* core2 return_Stack2 bit32 */
			{17659,39,1}, /* core2 return_Stack2 bit33 */
			{14993,39,1}, /* core2 return_Stack2 bit34 */
			{19496,39,1}, /* core2 return_Stack2 bit35 */
			{19494,39,1}, /* core2 return_Stack2 bit36 */
			{14088,39,1}, /* core2 return_Stack2 bit37 */
			{19493,39,1}, /* core2 return_Stack2 bit38 */
			{17672,39,1}, /* core2 return_Stack2 bit39 */
			{19495,39,1}, /* core2 return_Stack2 bit40 */
			{17671,39,1}, /* core2 return_Stack2 bit41 */
			{14091,39,1}, /* core2 return_Stack2 bit42 */
			{17670,39,1}, /* core2 return_Stack2 bit43 */
			{17669,39,1}, /* core2 return_Stack2 bit44 */
			{19859,39,1}, /* core2 return_Stack2 bit45 */
			{17658,39,1}, /* core2 return_Stack2 bit46 */
			{17657,39,1}, /* core2 return_Stack2 bit47 */
			{17697,39,1}, /* core2 return_Stack2 bit48 */
			{    0, 0,2}, /* core2 return_Stack2 bit49 */
			{    0, 0,2}, /* core2 return_Stack2 bit50 */
			{    0, 0,2}, /* core2 return_Stack2 bit51 */
			{    0, 0,2}, /* core2 return_Stack2 bit52 */
			{    0, 0,2}, /* core2 return_Stack2 bit53 */
			{    0, 0,2}, /* core2 return_Stack2 bit54 */
			{    0, 0,2}, /* core2 return_Stack2 bit55 */
			{    0, 0,2}, /* core2 return_Stack2 bit56 */
			{    0, 0,2}, /* core2 return_Stack2 bit57 */
			{    0, 0,2}, /* core2 return_Stack2 bit58 */
			{    0, 0,2}, /* core2 return_Stack2 bit59 */
			{    0, 0,2}, /* core2 return_Stack2 bit60 */
			{    0, 0,2}, /* core2 return_Stack2 bit61 */
			{    0, 0,2}, /* core2 return_Stack2 bit62 */
			{    0, 0,2}, /* core2 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{19520,39,1}, /* core2 return_Stack3 bit0 */
			{27665,39,1}, /* core2 return_Stack3 bit1 */
			{21968,39,1}, /* core2 return_Stack3 bit2 */
			{19248,39,1}, /* core2 return_Stack3 bit3 */
			{19247,39,1}, /* core2 return_Stack3 bit4 */
			{21967,39,1}, /* core2 return_Stack3 bit5 */
			{21966,39,1}, /* core2 return_Stack3 bit6 */
			{27683,39,1}, /* core2 return_Stack3 bit7 */
			{19244,39,1}, /* core2 return_Stack3 bit8 */
			{19246,39,1}, /* core2 return_Stack3 bit9 */
			{21965,39,1}, /* core2 return_Stack3 bit10 */
			{19243,39,1}, /* core2 return_Stack3 bit11 */
			{19245,39,1}, /* core2 return_Stack3 bit12 */
			{27685,39,1}, /* core2 return_Stack3 bit13 */
			{27684,39,1}, /* core2 return_Stack3 bit14 */
			{14913,39,1}, /* core2 return_Stack3 bit15 */
			{21964,39,1}, /* core2 return_Stack3 bit16 */
			{21963,39,1}, /* core2 return_Stack3 bit17 */
			{21962,39,1}, /* core2 return_Stack3 bit18 */
			{21961,39,1}, /* core2 return_Stack3 bit19 */
			{21948,39,1}, /* core2 return_Stack3 bit20 */
			{21947,39,1}, /* core2 return_Stack3 bit21 */
			{19519,39,1}, /* core2 return_Stack3 bit22 */
			{21946,39,1}, /* core2 return_Stack3 bit23 */
			{21984,39,1}, /* core2 return_Stack3 bit24 */
			{21983,39,1}, /* core2 return_Stack3 bit25 */
			{21996,39,1}, /* core2 return_Stack3 bit26 */
			{21982,39,1}, /* core2 return_Stack3 bit27 */
			{21995,39,1}, /* core2 return_Stack3 bit28 */
			{21981,39,1}, /* core2 return_Stack3 bit29 */
			{21994,39,1}, /* core2 return_Stack3 bit30 */
			{27675,39,1}, /* core2 return_Stack3 bit31 */
			{21993,39,1}, /* core2 return_Stack3 bit32 */
			{19512,39,1}, /* core2 return_Stack3 bit33 */
			{27676,39,1}, /* core2 return_Stack3 bit34 */
			{19482,39,1}, /* core2 return_Stack3 bit35 */
			{19486,39,1}, /* core2 return_Stack3 bit36 */
			{19481,39,1}, /* core2 return_Stack3 bit37 */
			{19480,39,1}, /* core2 return_Stack3 bit38 */
			{19485,39,1}, /* core2 return_Stack3 bit39 */
			{27674,39,1}, /* core2 return_Stack3 bit40 */
			{19479,39,1}, /* core2 return_Stack3 bit41 */
			{14093,39,1}, /* core2 return_Stack3 bit42 */
			{19857,39,1}, /* core2 return_Stack3 bit43 */
			{19856,39,1}, /* core2 return_Stack3 bit44 */
			{27664,39,1}, /* core2 return_Stack3 bit45 */
			{19511,39,1}, /* core2 return_Stack3 bit46 */
			{27677,39,1}, /* core2 return_Stack3 bit47 */
			{21945,39,1}, /* core2 return_Stack3 bit48 */
			{    0, 0,2}, /* core2 return_Stack3 bit49 */
			{    0, 0,2}, /* core2 return_Stack3 bit50 */
			{    0, 0,2}, /* core2 return_Stack3 bit51 */
			{    0, 0,2}, /* core2 return_Stack3 bit52 */
			{    0, 0,2}, /* core2 return_Stack3 bit53 */
			{    0, 0,2}, /* core2 return_Stack3 bit54 */
			{    0, 0,2}, /* core2 return_Stack3 bit55 */
			{    0, 0,2}, /* core2 return_Stack3 bit56 */
			{    0, 0,2}, /* core2 return_Stack3 bit57 */
			{    0, 0,2}, /* core2 return_Stack3 bit58 */
			{    0, 0,2}, /* core2 return_Stack3 bit59 */
			{    0, 0,2}, /* core2 return_Stack3 bit60 */
			{    0, 0,2}, /* core2 return_Stack3 bit61 */
			{    0, 0,2}, /* core2 return_Stack3 bit62 */
			{    0, 0,2}, /* core2 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{17704,39,1}, /* core2 return_Stack4 bit0 */
			{17703,39,1}, /* core2 return_Stack4 bit1 */
			{19230,39,1}, /* core2 return_Stack4 bit2 */
			{14986,39,1}, /* core2 return_Stack4 bit3 */
			{14983,39,1}, /* core2 return_Stack4 bit4 */
			{19242,39,1}, /* core2 return_Stack4 bit5 */
			{14987,39,1}, /* core2 return_Stack4 bit6 */
			{19232,39,1}, /* core2 return_Stack4 bit7 */
			{19241,39,1}, /* core2 return_Stack4 bit8 */
			{19229,39,1}, /* core2 return_Stack4 bit9 */
			{14906,39,1}, /* core2 return_Stack4 bit10 */
			{14903,39,1}, /* core2 return_Stack4 bit11 */
			{19231,39,1}, /* core2 return_Stack4 bit12 */
			{19234,39,1}, /* core2 return_Stack4 bit13 */
			{14917,39,1}, /* core2 return_Stack4 bit14 */
			{19233,39,1}, /* core2 return_Stack4 bit15 */
			{17608,39,1}, /* core2 return_Stack4 bit16 */
			{17607,39,1}, /* core2 return_Stack4 bit17 */
			{19278,39,1}, /* core2 return_Stack4 bit18 */
			{15002,39,1}, /* core2 return_Stack4 bit19 */
			{19277,39,1}, /* core2 return_Stack4 bit20 */
			{17606,39,1}, /* core2 return_Stack4 bit21 */
			{17605,39,1}, /* core2 return_Stack4 bit22 */
			{17702,39,1}, /* core2 return_Stack4 bit23 */
			{19360,39,1}, /* core2 return_Stack4 bit24 */
			{19359,39,1}, /* core2 return_Stack4 bit25 */
			{15001,39,1}, /* core2 return_Stack4 bit26 */
			{19536,39,1}, /* core2 return_Stack4 bit27 */
			{17648,39,1}, /* core2 return_Stack4 bit28 */
			{19535,39,1}, /* core2 return_Stack4 bit29 */
			{17647,39,1}, /* core2 return_Stack4 bit30 */
			{17646,39,1}, /* core2 return_Stack4 bit31 */
			{17645,39,1}, /* core2 return_Stack4 bit32 */
			{17652,39,1}, /* core2 return_Stack4 bit33 */
			{17651,39,1}, /* core2 return_Stack4 bit34 */
			{19532,39,1}, /* core2 return_Stack4 bit35 */
			{14087,39,1}, /* core2 return_Stack4 bit36 */
			{19530,39,1}, /* core2 return_Stack4 bit37 */
			{19869,39,1}, /* core2 return_Stack4 bit38 */
			{17708,39,1}, /* core2 return_Stack4 bit39 */
			{19531,39,1}, /* core2 return_Stack4 bit40 */
			{17707,39,1}, /* core2 return_Stack4 bit41 */
			{19529,39,1}, /* core2 return_Stack4 bit42 */
			{19862,39,1}, /* core2 return_Stack4 bit43 */
			{17706,39,1}, /* core2 return_Stack4 bit44 */
			{17705,39,1}, /* core2 return_Stack4 bit45 */
			{17650,39,1}, /* core2 return_Stack4 bit46 */
			{17649,39,1}, /* core2 return_Stack4 bit47 */
			{17701,39,1}, /* core2 return_Stack4 bit48 */
			{    0, 0,2}, /* core2 return_Stack4 bit49 */
			{    0, 0,2}, /* core2 return_Stack4 bit50 */
			{    0, 0,2}, /* core2 return_Stack4 bit51 */
			{    0, 0,2}, /* core2 return_Stack4 bit52 */
			{    0, 0,2}, /* core2 return_Stack4 bit53 */
			{    0, 0,2}, /* core2 return_Stack4 bit54 */
			{    0, 0,2}, /* core2 return_Stack4 bit55 */
			{    0, 0,2}, /* core2 return_Stack4 bit56 */
			{    0, 0,2}, /* core2 return_Stack4 bit57 */
			{    0, 0,2}, /* core2 return_Stack4 bit58 */
			{    0, 0,2}, /* core2 return_Stack4 bit59 */
			{    0, 0,2}, /* core2 return_Stack4 bit60 */
			{    0, 0,2}, /* core2 return_Stack4 bit61 */
			{    0, 0,2}, /* core2 return_Stack4 bit62 */
			{    0, 0,2}, /* core2 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{27686,39,1}, /* core2 return_Stack5 bit0 */
			{14936,39,1}, /* core2 return_Stack5 bit1 */
			{19224,39,1}, /* core2 return_Stack5 bit2 */
			{21976,39,1}, /* core2 return_Stack5 bit3 */
			{19254,39,1}, /* core2 return_Stack5 bit4 */
			{19253,39,1}, /* core2 return_Stack5 bit5 */
			{14918,39,1}, /* core2 return_Stack5 bit6 */
			{21975,39,1}, /* core2 return_Stack5 bit7 */
			{21974,39,1}, /* core2 return_Stack5 bit8 */
			{19226,39,1}, /* core2 return_Stack5 bit9 */
			{21973,39,1}, /* core2 return_Stack5 bit10 */
			{19225,39,1}, /* core2 return_Stack5 bit11 */
			{19223,39,1}, /* core2 return_Stack5 bit12 */
			{14975,39,1}, /* core2 return_Stack5 bit13 */
			{19262,39,1}, /* core2 return_Stack5 bit14 */
			{14910,39,1}, /* core2 return_Stack5 bit15 */
			{19250,39,1}, /* core2 return_Stack5 bit16 */
			{19261,39,1}, /* core2 return_Stack5 bit17 */
			{21952,39,1}, /* core2 return_Stack5 bit18 */
			{21951,39,1}, /* core2 return_Stack5 bit19 */
			{21950,39,1}, /* core2 return_Stack5 bit20 */
			{19249,39,1}, /* core2 return_Stack5 bit21 */
			{21949,39,1}, /* core2 return_Stack5 bit22 */
			{19514,39,1}, /* core2 return_Stack5 bit23 */
			{19488,39,1}, /* core2 return_Stack5 bit24 */
			{19487,39,1}, /* core2 return_Stack5 bit25 */
			{17680,39,1}, /* core2 return_Stack5 bit26 */
			{17679,39,1}, /* core2 return_Stack5 bit27 */
			{17678,39,1}, /* core2 return_Stack5 bit28 */
			{19490,39,1}, /* core2 return_Stack5 bit29 */
			{17677,39,1}, /* core2 return_Stack5 bit30 */
			{19526,39,1}, /* core2 return_Stack5 bit31 */
			{27663,39,1}, /* core2 return_Stack5 bit32 */
			{27668,39,1}, /* core2 return_Stack5 bit33 */
			{19489,39,1}, /* core2 return_Stack5 bit34 */
			{19864,39,1}, /* core2 return_Stack5 bit35 */
			{17712,39,1}, /* core2 return_Stack5 bit36 */
			{17711,39,1}, /* core2 return_Stack5 bit37 */
			{17710,39,1}, /* core2 return_Stack5 bit38 */
			{14094,39,1}, /* core2 return_Stack5 bit39 */
			{17684,39,1}, /* core2 return_Stack5 bit40 */
			{19858,39,1}, /* core2 return_Stack5 bit41 */
			{17683,39,1}, /* core2 return_Stack5 bit42 */
			{17709,39,1}, /* core2 return_Stack5 bit43 */
			{17682,39,1}, /* core2 return_Stack5 bit44 */
			{17681,39,1}, /* core2 return_Stack5 bit45 */
			{27669,39,1}, /* core2 return_Stack5 bit46 */
			{19525,39,1}, /* core2 return_Stack5 bit47 */
			{19513,39,1}, /* core2 return_Stack5 bit48 */
			{    0, 0,2}, /* core2 return_Stack5 bit49 */
			{    0, 0,2}, /* core2 return_Stack5 bit50 */
			{    0, 0,2}, /* core2 return_Stack5 bit51 */
			{    0, 0,2}, /* core2 return_Stack5 bit52 */
			{    0, 0,2}, /* core2 return_Stack5 bit53 */
			{    0, 0,2}, /* core2 return_Stack5 bit54 */
			{    0, 0,2}, /* core2 return_Stack5 bit55 */
			{    0, 0,2}, /* core2 return_Stack5 bit56 */
			{    0, 0,2}, /* core2 return_Stack5 bit57 */
			{    0, 0,2}, /* core2 return_Stack5 bit58 */
			{    0, 0,2}, /* core2 return_Stack5 bit59 */
			{    0, 0,2}, /* core2 return_Stack5 bit60 */
			{    0, 0,2}, /* core2 return_Stack5 bit61 */
			{    0, 0,2}, /* core2 return_Stack5 bit62 */
			{    0, 0,2}, /* core2 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{14977,39,1}, /* core2 return_Stack6 bit0 */
			{14979,39,1}, /* core2 return_Stack6 bit1 */
			{24870,39,1}, /* core2 return_Stack6 bit2 */
			{14927,39,1}, /* core2 return_Stack6 bit3 */
			{17354,39,1}, /* core2 return_Stack6 bit4 */
			{17353,39,1}, /* core2 return_Stack6 bit5 */
			{24869,39,1}, /* core2 return_Stack6 bit6 */
			{19222,39,1}, /* core2 return_Stack6 bit7 */
			{24868,39,1}, /* core2 return_Stack6 bit8 */
			{14908,39,1}, /* core2 return_Stack6 bit9 */
			{19221,39,1}, /* core2 return_Stack6 bit10 */
			{24867,39,1}, /* core2 return_Stack6 bit11 */
			{14909,39,1}, /* core2 return_Stack6 bit12 */
			{14926,39,1}, /* core2 return_Stack6 bit13 */
			{17600,39,1}, /* core2 return_Stack6 bit14 */
			{14912,39,1}, /* core2 return_Stack6 bit15 */
			{19260,39,1}, /* core2 return_Stack6 bit16 */
			{17599,39,1}, /* core2 return_Stack6 bit17 */
			{17598,39,1}, /* core2 return_Stack6 bit18 */
			{19259,39,1}, /* core2 return_Stack6 bit19 */
			{19272,39,1}, /* core2 return_Stack6 bit20 */
			{17597,39,1}, /* core2 return_Stack6 bit21 */
			{19271,39,1}, /* core2 return_Stack6 bit22 */
			{14980,39,1}, /* core2 return_Stack6 bit23 */
			{14991,39,1}, /* core2 return_Stack6 bit24 */
			{17668,39,1}, /* core2 return_Stack6 bit25 */
			{19508,39,1}, /* core2 return_Stack6 bit26 */
			{19504,39,1}, /* core2 return_Stack6 bit27 */
			{19503,39,1}, /* core2 return_Stack6 bit28 */
			{14992,39,1}, /* core2 return_Stack6 bit29 */
			{17667,39,1}, /* core2 return_Stack6 bit30 */
			{17666,39,1}, /* core2 return_Stack6 bit31 */
			{17665,39,1}, /* core2 return_Stack6 bit32 */
			{19500,39,1}, /* core2 return_Stack6 bit33 */
			{14089,39,1}, /* core2 return_Stack6 bit34 */
			{19868,39,1}, /* core2 return_Stack6 bit35 */
			{19476,39,1}, /* core2 return_Stack6 bit36 */
			{19475,39,1}, /* core2 return_Stack6 bit37 */
			{19478,39,1}, /* core2 return_Stack6 bit38 */
			{19524,39,1}, /* core2 return_Stack6 bit39 */
			{19477,39,1}, /* core2 return_Stack6 bit40 */
			{19506,39,1}, /* core2 return_Stack6 bit41 */
			{19865,39,1}, /* core2 return_Stack6 bit42 */
			{19505,39,1}, /* core2 return_Stack6 bit43 */
			{19863,39,1}, /* core2 return_Stack6 bit44 */
			{19523,39,1}, /* core2 return_Stack6 bit45 */
			{19507,39,1}, /* core2 return_Stack6 bit46 */
			{19499,39,1}, /* core2 return_Stack6 bit47 */
			{14978,39,1}, /* core2 return_Stack6 bit48 */
			{    0, 0,2}, /* core2 return_Stack6 bit49 */
			{    0, 0,2}, /* core2 return_Stack6 bit50 */
			{    0, 0,2}, /* core2 return_Stack6 bit51 */
			{    0, 0,2}, /* core2 return_Stack6 bit52 */
			{    0, 0,2}, /* core2 return_Stack6 bit53 */
			{    0, 0,2}, /* core2 return_Stack6 bit54 */
			{    0, 0,2}, /* core2 return_Stack6 bit55 */
			{    0, 0,2}, /* core2 return_Stack6 bit56 */
			{    0, 0,2}, /* core2 return_Stack6 bit57 */
			{    0, 0,2}, /* core2 return_Stack6 bit58 */
			{    0, 0,2}, /* core2 return_Stack6 bit59 */
			{    0, 0,2}, /* core2 return_Stack6 bit60 */
			{    0, 0,2}, /* core2 return_Stack6 bit61 */
			{    0, 0,2}, /* core2 return_Stack6 bit62 */
			{    0, 0,2}, /* core2 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{21956,39,1}, /* core2 return_Stack7 bit0 */
			{21960,39,1}, /* core2 return_Stack7 bit1 */
			{21972,39,1}, /* core2 return_Stack7 bit2 */
			{19256,39,1}, /* core2 return_Stack7 bit3 */
			{19258,39,1}, /* core2 return_Stack7 bit4 */
			{19257,39,1}, /* core2 return_Stack7 bit5 */
			{27678,39,1}, /* core2 return_Stack7 bit6 */
			{27679,39,1}, /* core2 return_Stack7 bit7 */
			{19255,39,1}, /* core2 return_Stack7 bit8 */
			{21971,39,1}, /* core2 return_Stack7 bit9 */
			{21970,39,1}, /* core2 return_Stack7 bit10 */
			{27680,39,1}, /* core2 return_Stack7 bit11 */
			{21969,39,1}, /* core2 return_Stack7 bit12 */
			{21959,39,1}, /* core2 return_Stack7 bit13 */
			{21958,39,1}, /* core2 return_Stack7 bit14 */
			{21957,39,1}, /* core2 return_Stack7 bit15 */
			{27682,39,1}, /* core2 return_Stack7 bit16 */
			{27681,39,1}, /* core2 return_Stack7 bit17 */
			{21955,39,1}, /* core2 return_Stack7 bit18 */
			{21954,39,1}, /* core2 return_Stack7 bit19 */
			{19518,39,1}, /* core2 return_Stack7 bit20 */
			{21953,39,1}, /* core2 return_Stack7 bit21 */
			{19516,39,1}, /* core2 return_Stack7 bit22 */
			{19515,39,1}, /* core2 return_Stack7 bit23 */
			{21992,39,1}, /* core2 return_Stack7 bit24 */
			{19528,39,1}, /* core2 return_Stack7 bit25 */
			{21988,39,1}, /* core2 return_Stack7 bit26 */
			{21991,39,1}, /* core2 return_Stack7 bit27 */
			{21990,39,1}, /* core2 return_Stack7 bit28 */
			{19484,39,1}, /* core2 return_Stack7 bit29 */
			{21989,39,1}, /* core2 return_Stack7 bit30 */
			{21987,39,1}, /* core2 return_Stack7 bit31 */
			{21986,39,1}, /* core2 return_Stack7 bit32 */
			{21985,39,1}, /* core2 return_Stack7 bit33 */
			{19483,39,1}, /* core2 return_Stack7 bit34 */
			{14090,39,1}, /* core2 return_Stack7 bit35 */
			{14097,39,1}, /* core2 return_Stack7 bit36 */
			{19867,39,1}, /* core2 return_Stack7 bit37 */
			{27673,39,1}, /* core2 return_Stack7 bit38 */
			{14095,39,1}, /* core2 return_Stack7 bit39 */
			{19861,39,1}, /* core2 return_Stack7 bit40 */
			{27672,39,1}, /* core2 return_Stack7 bit41 */
			{19866,39,1}, /* core2 return_Stack7 bit42 */
			{14096,39,1}, /* core2 return_Stack7 bit43 */
			{19860,39,1}, /* core2 return_Stack7 bit44 */
			{27671,39,1}, /* core2 return_Stack7 bit45 */
			{27670,39,1}, /* core2 return_Stack7 bit46 */
			{19527,39,1}, /* core2 return_Stack7 bit47 */
			{19517,39,1}, /* core2 return_Stack7 bit48 */
			{    0, 0,2}, /* core2 return_Stack7 bit49 */
			{    0, 0,2}, /* core2 return_Stack7 bit50 */
			{    0, 0,2}, /* core2 return_Stack7 bit51 */
			{    0, 0,2}, /* core2 return_Stack7 bit52 */
			{    0, 0,2}, /* core2 return_Stack7 bit53 */
			{    0, 0,2}, /* core2 return_Stack7 bit54 */
			{    0, 0,2}, /* core2 return_Stack7 bit55 */
			{    0, 0,2}, /* core2 return_Stack7 bit56 */
			{    0, 0,2}, /* core2 return_Stack7 bit57 */
			{    0, 0,2}, /* core2 return_Stack7 bit58 */
			{    0, 0,2}, /* core2 return_Stack7 bit59 */
			{    0, 0,2}, /* core2 return_Stack7 bit60 */
			{    0, 0,2}, /* core2 return_Stack7 bit61 */
			{    0, 0,2}, /* core2 return_Stack7 bit62 */
			{    0, 0,2}, /* core2 return_Stack7 bit63 */
			}},
			.ECC_err0status_v = {{
			{37289,39,1}, /* core2 ECC_err0status_v bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_v bit63 */
			}},
			.ECC_err0status_ue = {{
			{37575,39,1}, /* core2 ECC_err0status_ue bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_ue bit63 */
			}},
			.ECC_err0status_er = {{
			{37576,39,1}, /* core2 ECC_err0status_er bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_er bit63 */
			}},
			.ECC_err0status_of = {{
			{31882,39,1}, /* core2 ECC_err0status_of bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_of bit63 */
			}},
			.ECC_err0status_mv = {{
			{37291,39,1}, /* core2 ECC_err0status_mv bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_mv bit63 */
			}},
			.ECC_err0status_ce = {{
			{29902,39,1}, /* core2 ECC_err0status_ce bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_ce bit63 */
			}},
			.ECC_err0status_de = {{
			{31883,39,1}, /* core2 ECC_err0status_de bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_de bit63 */
			}},
			.ECC_err0status_pn = {{
			{37290,39,1}, /* core2 ECC_err0status_pn bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_pn bit63 */
			}},
			.ECC_err0status_ierr = {{
			{37292,39,1}, /* core2 ECC_err0status_ierr bit0 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit1 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit2 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit3 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_ierr bit63 */
			}},
			.ECC_err0status_serr = {{
			{37570,39,1}, /* core2 ECC_err0status_serr bit0 */
			{37574,39,1}, /* core2 ECC_err0status_serr bit1 */
			{37569,39,1}, /* core2 ECC_err0status_serr bit2 */
			{37573,39,1}, /* core2 ECC_err0status_serr bit3 */
			{31828,39,1}, /* core2 ECC_err0status_serr bit4 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit5 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit6 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit7 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit8 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit9 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit10 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit11 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit12 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit13 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit14 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit15 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit16 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit17 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit18 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit19 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit20 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit21 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit22 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit23 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit24 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit25 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit26 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit27 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit28 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit29 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit30 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit31 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit32 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit33 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit34 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit35 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit36 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit37 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit38 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit39 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit40 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit41 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit42 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit43 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit44 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit45 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit46 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit47 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit48 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit49 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit50 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit51 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit52 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit53 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit54 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit55 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit56 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit57 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit58 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit59 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit60 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit61 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit62 */
			{    0, 0,2}, /* core2 ECC_err0status_serr bit63 */
			}},
			.ECC_err0misc_other_err_cnt_overflow = {{
			{39790,39,1}, /* core2 ECC_err0misc_other_err_cnt_overflow bit0 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit1 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit2 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit3 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit4 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit5 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit6 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit7 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit8 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit9 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit10 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit11 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit12 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit13 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit14 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit15 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit16 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit17 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit18 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit19 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit20 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit21 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit22 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit23 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit24 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit25 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit26 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit27 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit28 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit29 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit30 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit31 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit32 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit33 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit34 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit35 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit36 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit37 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit38 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit39 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit40 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit41 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit42 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit43 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit44 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit45 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit46 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit47 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit48 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit49 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit50 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit51 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit52 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit53 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit54 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit55 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit56 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit57 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit58 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit59 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit60 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit61 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit62 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt_overflow bit63 */
			}},
			.ECC_err0misc_other_err_cnt = {{
			{34012,39,1}, /* core2 ECC_err0misc_other_err_cnt bit0 */
			{29803,39,1}, /* core2 ECC_err0misc_other_err_cnt bit1 */
			{34016,39,1}, /* core2 ECC_err0misc_other_err_cnt bit2 */
			{34015,39,1}, /* core2 ECC_err0misc_other_err_cnt bit3 */
			{34014,39,1}, /* core2 ECC_err0misc_other_err_cnt bit4 */
			{34013,39,1}, /* core2 ECC_err0misc_other_err_cnt bit5 */
			{34011,39,1}, /* core2 ECC_err0misc_other_err_cnt bit6 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit7 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit8 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit9 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit10 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit11 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit12 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit13 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit14 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit15 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit16 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit17 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit18 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit19 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit20 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit21 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit22 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit23 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit24 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit25 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit26 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit27 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit28 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit29 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit30 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit31 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit32 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit33 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit34 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit35 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit36 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit37 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit38 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit39 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit40 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit41 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit42 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit43 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit44 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit45 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit46 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit47 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit48 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit49 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit50 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit51 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit52 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit53 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit54 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit55 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit56 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit57 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit58 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit59 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit60 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit61 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit62 */
			{    0, 0,2}, /* core2 ECC_err0misc_other_err_cnt bit63 */
			}},
			.ECC_err0misc_repeat_err_overflow = {{
			{29804,39,1}, /* core2 ECC_err0misc_repeat_err_overflow bit0 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit1 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit2 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit3 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit4 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit5 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit6 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit7 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit8 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit9 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit10 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit11 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit12 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit13 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit14 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit15 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit16 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit17 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit18 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit19 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit20 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit21 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit22 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit23 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit24 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit25 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit26 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit27 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit28 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit29 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit30 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit31 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit32 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit33 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit34 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit35 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit36 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit37 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit38 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit39 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit40 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit41 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit42 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit43 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit44 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit45 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit46 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit47 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit48 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit49 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit50 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit51 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit52 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit53 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit54 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit55 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit56 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit57 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit58 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit59 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit60 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit61 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit62 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_overflow bit63 */
			}},
			.ECC_err0misc_repeat_err_cnt = {{
			{34010,39,1}, /* core2 ECC_err0misc_repeat_err_cnt bit0 */
			{39789,39,1}, /* core2 ECC_err0misc_repeat_err_cnt bit1 */
			{39788,39,1}, /* core2 ECC_err0misc_repeat_err_cnt bit2 */
			{39787,39,1}, /* core2 ECC_err0misc_repeat_err_cnt bit3 */
			{39786,39,1}, /* core2 ECC_err0misc_repeat_err_cnt bit4 */
			{39785,39,1}, /* core2 ECC_err0misc_repeat_err_cnt bit5 */
			{34009,39,1}, /* core2 ECC_err0misc_repeat_err_cnt bit6 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit7 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit8 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit9 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit10 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit11 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit12 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit13 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit14 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit15 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit16 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit17 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit18 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit19 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit20 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit21 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit22 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit23 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit24 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit25 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit26 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit27 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit28 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit29 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit30 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit31 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit32 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit33 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit34 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit35 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit36 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit37 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit38 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit39 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit40 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit41 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit42 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit43 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit44 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit45 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit46 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit47 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit48 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit49 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit50 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit51 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit52 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit53 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit54 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit55 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit56 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit57 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit58 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit59 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit60 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit61 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit62 */
			{    0, 0,2}, /* core2 ECC_err0misc_repeat_err_cnt bit63 */
			}},
			.ECC_err0misc_way = {{
			{43026,39,1}, /* core2 ECC_err0misc_way bit0 */
			{43025,39,1}, /* core2 ECC_err0misc_way bit1 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit2 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit3 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit4 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit5 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit6 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit7 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit8 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit9 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit10 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit11 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit12 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit13 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit14 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit15 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit16 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit17 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit18 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit19 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit20 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit21 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit22 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit23 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit24 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit25 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit26 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit27 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit28 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit29 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit30 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit31 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit32 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit33 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit34 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit35 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit36 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit37 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit38 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit39 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit40 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit41 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit42 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit43 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit44 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit45 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit46 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit47 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit48 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit49 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit50 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit51 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit52 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit53 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit54 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit55 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit56 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit57 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit58 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit59 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit60 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit61 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit62 */
			{    0, 0,2}, /* core2 ECC_err0misc_way bit63 */
			}},
			.ECC_err0misc_index = {{
			{37296,39,1}, /* core2 ECC_err0misc_index bit0 */
			{37754,39,1}, /* core2 ECC_err0misc_index bit1 */
			{31917,39,1}, /* core2 ECC_err0misc_index bit2 */
			{31916,39,1}, /* core2 ECC_err0misc_index bit3 */
			{43029,39,1}, /* core2 ECC_err0misc_index bit4 */
			{43028,39,1}, /* core2 ECC_err0misc_index bit5 */
			{43027,39,1}, /* core2 ECC_err0misc_index bit6 */
			{37753,39,1}, /* core2 ECC_err0misc_index bit7 */
			{43030,39,1}, /* core2 ECC_err0misc_index bit8 */
			{37295,39,1}, /* core2 ECC_err0misc_index bit9 */
			{37294,39,1}, /* core2 ECC_err0misc_index bit10 */
			{37293,39,1}, /* core2 ECC_err0misc_index bit11 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit12 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit13 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit14 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit15 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit16 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit17 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit18 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit19 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit20 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit21 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit22 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit23 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit24 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit25 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit26 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit27 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit28 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit29 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit30 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit31 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit32 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit33 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit34 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit35 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit36 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit37 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit38 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit39 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit40 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit41 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit42 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit43 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit44 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit45 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit46 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit47 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit48 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit49 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit50 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit51 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit52 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit53 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit54 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit55 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit56 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit57 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit58 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit59 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit60 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit61 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit62 */
			{    0, 0,2}, /* core2 ECC_err0misc_index bit63 */
			}},
			.ECC_err0misc_level_contain_error = {{
			{37571,39,1}, /* core2 ECC_err0misc_level_contain_error bit0 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit1 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit2 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit3 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit4 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit5 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit6 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit7 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit8 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit9 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit10 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit11 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit12 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit13 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit14 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit15 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit16 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit17 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit18 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit19 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit20 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit21 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit22 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit23 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit24 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit25 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit26 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit27 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit28 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit29 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit30 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit31 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit32 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit33 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit34 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit35 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit36 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit37 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit38 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit39 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit40 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit41 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit42 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit43 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit44 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit45 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit46 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit47 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit48 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit49 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit50 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit51 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit52 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit53 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit54 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit55 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit56 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit57 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit58 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit59 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit60 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit61 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit62 */
			{    0, 0,2}, /* core2 ECC_err0misc_level_contain_error bit63 */
			}},
			.ECC_err0misc_indicate_icache = {{
			{37572,39,1}, /* core2 ECC_err0misc_indicate_icache bit0 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit1 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit2 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit3 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit4 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit5 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit6 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit7 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit8 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit9 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit10 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit11 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit12 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit13 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit14 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit15 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit16 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit17 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit18 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit19 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit20 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit21 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit22 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit23 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit24 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit25 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit26 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit27 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit28 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit29 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit30 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit31 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit32 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit33 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit34 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit35 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit36 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit37 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit38 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit39 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit40 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit41 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit42 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit43 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit44 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit45 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit46 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit47 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit48 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit49 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit50 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit51 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit52 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit53 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit54 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit55 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit56 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit57 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit58 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit59 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit60 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit61 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit62 */
			{    0, 0,2}, /* core2 ECC_err0misc_indicate_icache bit63 */
			}},
			.ECC_err0ctrl_fault_handling_interrupt = {{
			{29905,39,1}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit0 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit1 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit2 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit3 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit4 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit5 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit6 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit7 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit8 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit9 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit10 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit11 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit12 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit13 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit14 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit15 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit16 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit17 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit18 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit19 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit20 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit21 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit22 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit23 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit24 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit25 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit26 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit27 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit28 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit29 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit30 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit31 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit32 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit33 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit34 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit35 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit36 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit37 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit38 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit39 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit40 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit41 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit42 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit43 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit44 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit45 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit46 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit47 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit48 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit49 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit50 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit51 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit52 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit53 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit54 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit55 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit56 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit57 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit58 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit59 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit60 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit61 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit62 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_interrupt bit63 */
			}},
			.ECC_err0ctrl_fault_handling_int_enable = {{
			{37512,39,1}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit0 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit1 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit2 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit3 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit4 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit5 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit6 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit7 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit8 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit9 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit10 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit11 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit12 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit13 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit14 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit15 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit16 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit17 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit18 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit19 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit20 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit21 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit22 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit23 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit24 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit25 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit26 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit27 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit28 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit29 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit30 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit31 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit32 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit33 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit34 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit35 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit36 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit37 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit38 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit39 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit40 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit41 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit42 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit43 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit44 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit45 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit46 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit47 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit48 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit49 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit50 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit51 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit52 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit53 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit54 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit55 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit56 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit57 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit58 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit59 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit60 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit61 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit62 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_fault_handling_int_enable bit63 */
			}},
			.ECC_err0ctrl_error_recovery_int_enable = {{
			{37511,39,1}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit0 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit1 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit2 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit3 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit4 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit5 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit6 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit7 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit8 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit9 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit10 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit11 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit12 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit13 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit14 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit15 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit16 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit17 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit18 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit19 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit20 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit21 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit22 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit23 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit24 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit25 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit26 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit27 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit28 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit29 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit30 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit31 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit32 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit33 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit34 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit35 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit36 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit37 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit38 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit39 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit40 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit41 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit42 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit43 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit44 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit45 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit46 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit47 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit48 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit49 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit50 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit51 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit52 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit53 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit54 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit55 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit56 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit57 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit58 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit59 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit60 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit61 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit62 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_recovery_int_enable bit63 */
			}},
			.ECC_err0ctrl_error_detect_correct_enable = {{
			{29904,39,1}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit0 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit1 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit2 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit3 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit4 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit5 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit6 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit7 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit8 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit9 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit10 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit11 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit12 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit13 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit14 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit15 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit16 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit17 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit18 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit19 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit20 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit21 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit22 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit23 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit24 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit25 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit26 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit27 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit28 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit29 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit30 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit31 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit32 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit33 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit34 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit35 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit36 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit37 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit38 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit39 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit40 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit41 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit42 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit43 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit44 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit45 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit46 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit47 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit48 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit49 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit50 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit51 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit52 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit53 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit54 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit55 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit56 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit57 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit58 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit59 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit60 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit61 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit62 */
			{    0, 0,2}, /* core2 ECC_err0ctrl_error_detect_correct_enable bit63 */
			}},
	},
	{		/* core 3 */ 
			.pc = {{
			{  523,40,1}, /* core3 pc bit0 */
			{  240,40,1}, /* core3 pc bit1 */
			{  102,40,1}, /* core3 pc bit2 */
			{  239,40,1}, /* core3 pc bit3 */
			{  495,40,1}, /* core3 pc bit4 */
			{  203,40,1}, /* core3 pc bit5 */
			{  431,40,1}, /* core3 pc bit6 */
			{  224,40,1}, /* core3 pc bit7 */
			{  100,40,1}, /* core3 pc bit8 */
			{  236,40,1}, /* core3 pc bit9 */
			{   96,40,1}, /* core3 pc bit10 */
			{  494,40,1}, /* core3 pc bit11 */
			{  202,40,1}, /* core3 pc bit12 */
			{  543,40,1}, /* core3 pc bit13 */
			{  223,40,1}, /* core3 pc bit14 */
			{  235,40,1}, /* core3 pc bit15 */
			{   94,40,1}, /* core3 pc bit16 */
			{  356,40,1}, /* core3 pc bit17 */
			{  207,40,1}, /* core3 pc bit18 */
			{  539,40,1}, /* core3 pc bit19 */
			{  511,40,1}, /* core3 pc bit20 */
			{   95,40,1}, /* core3 pc bit21 */
			{  522,40,1}, /* core3 pc bit22 */
			{  206,40,1}, /* core3 pc bit23 */
			{  220,40,1}, /* core3 pc bit24 */
			{  234,40,1}, /* core3 pc bit25 */
			{  355,40,1}, /* core3 pc bit26 */
			{  475,40,1}, /* core3 pc bit27 */
			{  538,40,1}, /* core3 pc bit28 */
			{  537,40,1}, /* core3 pc bit29 */
			{  536,40,1}, /* core3 pc bit30 */
			{  112,40,1}, /* core3 pc bit31 */
			{  215,40,1}, /* core3 pc bit32 */
			{  547,40,1}, /* core3 pc bit33 */
			{  230,40,1}, /* core3 pc bit34 */
			{  229,40,1}, /* core3 pc bit35 */
			{  491,40,1}, /* core3 pc bit36 */
			{  546,40,1}, /* core3 pc bit37 */
			{  423,40,1}, /* core3 pc bit38 */
			{  427,40,1}, /* core3 pc bit39 */
			{  211,40,1}, /* core3 pc bit40 */
			{  110,40,1}, /* core3 pc bit41 */
			{  367,40,1}, /* core3 pc bit42 */
			{  214,40,1}, /* core3 pc bit43 */
			{  542,40,1}, /* core3 pc bit44 */
			{  545,40,1}, /* core3 pc bit45 */
			{  426,40,1}, /* core3 pc bit46 */
			{  369,40,1}, /* core3 pc bit47 */
			{  425,40,1}, /* core3 pc bit48 */
			{  368,40,1}, /* core3 pc bit49 */
			{  430,40,1}, /* core3 pc bit50 */
			{  213,40,1}, /* core3 pc bit51 */
			{  212,40,1}, /* core3 pc bit52 */
			{  232,40,1}, /* core3 pc bit53 */
			{  535,40,1}, /* core3 pc bit54 */
			{  422,40,1}, /* core3 pc bit55 */
			{  490,40,1}, /* core3 pc bit56 */
			{  114,40,1}, /* core3 pc bit57 */
			{  415,40,1}, /* core3 pc bit58 */
			{  116,40,1}, /* core3 pc bit59 */
			{  429,40,1}, /* core3 pc bit60 */
			{  421,40,1}, /* core3 pc bit61 */
			{  420,40,1}, /* core3 pc bit62 */
			{  534,40,1}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{33132,41,1}, /* core3 sp32 bit0 */
			{33140,41,1}, /* core3 sp32 bit1 */
			{39344,41,1}, /* core3 sp32 bit2 */
			{39224,41,1}, /* core3 sp32 bit3 */
			{39343,41,1}, /* core3 sp32 bit4 */
			{33200,41,1}, /* core3 sp32 bit5 */
			{33199,41,1}, /* core3 sp32 bit6 */
			{38350,41,1}, /* core3 sp32 bit7 */
			{33128,41,1}, /* core3 sp32 bit8 */
			{33127,41,1}, /* core3 sp32 bit9 */
			{33198,41,1}, /* core3 sp32 bit10 */
			{39350,41,1}, /* core3 sp32 bit11 */
			{39240,41,1}, /* core3 sp32 bit12 */
			{39239,41,1}, /* core3 sp32 bit13 */
			{39342,41,1}, /* core3 sp32 bit14 */
			{39223,41,1}, /* core3 sp32 bit15 */
			{39349,41,1}, /* core3 sp32 bit16 */
			{39242,41,1}, /* core3 sp32 bit17 */
			{33126,41,1}, /* core3 sp32 bit18 */
			{33131,41,1}, /* core3 sp32 bit19 */
			{33125,41,1}, /* core3 sp32 bit20 */
			{33139,41,1}, /* core3 sp32 bit21 */
			{38353,41,1}, /* core3 sp32 bit22 */
			{39341,41,1}, /* core3 sp32 bit23 */
			{33138,41,1}, /* core3 sp32 bit24 */
			{33130,41,1}, /* core3 sp32 bit25 */
			{33197,41,1}, /* core3 sp32 bit26 */
			{33129,41,1}, /* core3 sp32 bit27 */
			{38356,41,1}, /* core3 sp32 bit28 */
			{38352,41,1}, /* core3 sp32 bit29 */
			{39241,41,1}, /* core3 sp32 bit30 */
			{33137,41,1}, /* core3 sp32 bit31 */
			{29541,41,1}, /* core3 sp32 bit32 */
			{29629,41,1}, /* core3 sp32 bit33 */
			{43006,41,1}, /* core3 sp32 bit34 */
			{29540,41,1}, /* core3 sp32 bit35 */
			{29628,41,1}, /* core3 sp32 bit36 */
			{29539,41,1}, /* core3 sp32 bit37 */
			{32952,41,1}, /* core3 sp32 bit38 */
			{29715,41,1}, /* core3 sp32 bit39 */
			{29713,41,1}, /* core3 sp32 bit40 */
			{32951,41,1}, /* core3 sp32 bit41 */
			{32950,41,1}, /* core3 sp32 bit42 */
			{43005,41,1}, /* core3 sp32 bit43 */
			{29712,41,1}, /* core3 sp32 bit44 */
			{29714,41,1}, /* core3 sp32 bit45 */
			{32949,41,1}, /* core3 sp32 bit46 */
			{29315,41,1}, /* core3 sp32 bit47 */
			{29317,41,1}, /* core3 sp32 bit48 */
			{29409,41,1}, /* core3 sp32 bit49 */
			{29316,41,1}, /* core3 sp32 bit50 */
			{29415,41,1}, /* core3 sp32 bit51 */
			{29414,41,1}, /* core3 sp32 bit52 */
			{29407,41,1}, /* core3 sp32 bit53 */
			{29406,41,1}, /* core3 sp32 bit54 */
			{42991,41,1}, /* core3 sp32 bit55 */
			{29411,41,1}, /* core3 sp32 bit56 */
			{29413,41,1}, /* core3 sp32 bit57 */
			{29314,41,1}, /* core3 sp32 bit58 */
			{29410,41,1}, /* core3 sp32 bit59 */
			{29412,41,1}, /* core3 sp32 bit60 */
			{42989,41,1}, /* core3 sp32 bit61 */
			{29408,41,1}, /* core3 sp32 bit62 */
			{29538,41,1}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{39308,41,1}, /* core3 fp32 bit0 */
			{39246,41,1}, /* core3 fp32 bit1 */
			{33160,41,1}, /* core3 fp32 bit2 */
			{33152,41,1}, /* core3 fp32 bit3 */
			{33159,41,1}, /* core3 fp32 bit4 */
			{33151,41,1}, /* core3 fp32 bit5 */
			{39334,41,1}, /* core3 fp32 bit6 */
			{33148,41,1}, /* core3 fp32 bit7 */
			{39332,41,1}, /* core3 fp32 bit8 */
			{32636,41,1}, /* core3 fp32 bit9 */
			{32635,41,1}, /* core3 fp32 bit10 */
			{32634,41,1}, /* core3 fp32 bit11 */
			{38329,41,1}, /* core3 fp32 bit12 */
			{39304,41,1}, /* core3 fp32 bit13 */
			{39333,41,1}, /* core3 fp32 bit14 */
			{39303,41,1}, /* core3 fp32 bit15 */
			{38346,41,1}, /* core3 fp32 bit16 */
			{32633,41,1}, /* core3 fp32 bit17 */
			{33156,41,1}, /* core3 fp32 bit18 */
			{33147,41,1}, /* core3 fp32 bit19 */
			{33155,41,1}, /* core3 fp32 bit20 */
			{33154,41,1}, /* core3 fp32 bit21 */
			{33150,41,1}, /* core3 fp32 bit22 */
			{33158,41,1}, /* core3 fp32 bit23 */
			{33149,41,1}, /* core3 fp32 bit24 */
			{39307,41,1}, /* core3 fp32 bit25 */
			{39331,41,1}, /* core3 fp32 bit26 */
			{39245,41,1}, /* core3 fp32 bit27 */
			{33146,41,1}, /* core3 fp32 bit28 */
			{33153,41,1}, /* core3 fp32 bit29 */
			{33145,41,1}, /* core3 fp32 bit30 */
			{33157,41,1}, /* core3 fp32 bit31 */
			{32928,41,1}, /* core3 fp32 bit32 */
			{29285,41,1}, /* core3 fp32 bit33 */
			{29284,41,1}, /* core3 fp32 bit34 */
			{32927,41,1}, /* core3 fp32 bit35 */
			{43000,41,1}, /* core3 fp32 bit36 */
			{32926,41,1}, /* core3 fp32 bit37 */
			{29295,41,1}, /* core3 fp32 bit38 */
			{29291,41,1}, /* core3 fp32 bit39 */
			{29287,41,1}, /* core3 fp32 bit40 */
			{42999,41,1}, /* core3 fp32 bit41 */
			{38251,41,1}, /* core3 fp32 bit42 */
			{38250,41,1}, /* core3 fp32 bit43 */
			{29294,41,1}, /* core3 fp32 bit44 */
			{29286,41,1}, /* core3 fp32 bit45 */
			{29290,41,1}, /* core3 fp32 bit46 */
			{33012,41,1}, /* core3 fp32 bit47 */
			{33011,41,1}, /* core3 fp32 bit48 */
			{33010,41,1}, /* core3 fp32 bit49 */
			{29443,41,1}, /* core3 fp32 bit50 */
			{33009,41,1}, /* core3 fp32 bit51 */
			{29447,41,1}, /* core3 fp32 bit52 */
			{29442,41,1}, /* core3 fp32 bit53 */
			{34234,41,1}, /* core3 fp32 bit54 */
			{29297,41,1}, /* core3 fp32 bit55 */
			{29446,41,1}, /* core3 fp32 bit56 */
			{29296,41,1}, /* core3 fp32 bit57 */
			{29445,41,1}, /* core3 fp32 bit58 */
			{34235,41,1}, /* core3 fp32 bit59 */
			{29444,41,1}, /* core3 fp32 bit60 */
			{29441,41,1}, /* core3 fp32 bit61 */
			{29440,41,1}, /* core3 fp32 bit62 */
			{32925,41,1}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{32660,41,1}, /* core3 fp64 bit0 */
			{32668,41,1}, /* core3 fp64 bit1 */
			{32659,41,1}, /* core3 fp64 bit2 */
			{32676,41,1}, /* core3 fp64 bit3 */
			{32658,41,1}, /* core3 fp64 bit4 */
			{32657,41,1}, /* core3 fp64 bit5 */
			{32656,41,1}, /* core3 fp64 bit6 */
			{38427,41,1}, /* core3 fp64 bit7 */
			{38488,41,1}, /* core3 fp64 bit8 */
			{32655,41,1}, /* core3 fp64 bit9 */
			{38428,41,1}, /* core3 fp64 bit10 */
			{32654,41,1}, /* core3 fp64 bit11 */
			{38423,41,1}, /* core3 fp64 bit12 */
			{32653,41,1}, /* core3 fp64 bit13 */
			{38490,41,1}, /* core3 fp64 bit14 */
			{38492,41,1}, /* core3 fp64 bit15 */
			{38487,41,1}, /* core3 fp64 bit16 */
			{38491,41,1}, /* core3 fp64 bit17 */
			{38489,41,1}, /* core3 fp64 bit18 */
			{32667,41,1}, /* core3 fp64 bit19 */
			{32666,41,1}, /* core3 fp64 bit20 */
			{32675,41,1}, /* core3 fp64 bit21 */
			{38856,41,1}, /* core3 fp64 bit22 */
			{32672,41,1}, /* core3 fp64 bit23 */
			{32671,41,1}, /* core3 fp64 bit24 */
			{38422,41,1}, /* core3 fp64 bit25 */
			{32665,41,1}, /* core3 fp64 bit26 */
			{32670,41,1}, /* core3 fp64 bit27 */
			{32674,41,1}, /* core3 fp64 bit28 */
			{38855,41,1}, /* core3 fp64 bit29 */
			{32673,41,1}, /* core3 fp64 bit30 */
			{32669,41,1}, /* core3 fp64 bit31 */
			{39065,41,1}, /* core3 fp64 bit32 */
			{38229,41,1}, /* core3 fp64 bit33 */
			{38227,41,1}, /* core3 fp64 bit34 */
			{39064,41,1}, /* core3 fp64 bit35 */
			{38224,41,1}, /* core3 fp64 bit36 */
			{38225,41,1}, /* core3 fp64 bit37 */
			{39069,41,1}, /* core3 fp64 bit38 */
			{39061,41,1}, /* core3 fp64 bit39 */
			{39063,41,1}, /* core3 fp64 bit40 */
			{38222,41,1}, /* core3 fp64 bit41 */
			{39071,41,1}, /* core3 fp64 bit42 */
			{39070,41,1}, /* core3 fp64 bit43 */
			{39060,41,1}, /* core3 fp64 bit44 */
			{38228,41,1}, /* core3 fp64 bit45 */
			{39068,41,1}, /* core3 fp64 bit46 */
			{39045,41,1}, /* core3 fp64 bit47 */
			{39044,41,1}, /* core3 fp64 bit48 */
			{39041,41,1}, /* core3 fp64 bit49 */
			{39037,41,1}, /* core3 fp64 bit50 */
			{29577,41,1}, /* core3 fp64 bit51 */
			{29576,41,1}, /* core3 fp64 bit52 */
			{39039,41,1}, /* core3 fp64 bit53 */
			{39038,41,1}, /* core3 fp64 bit54 */
			{29575,41,1}, /* core3 fp64 bit55 */
			{39036,41,1}, /* core3 fp64 bit56 */
			{39043,41,1}, /* core3 fp64 bit57 */
			{39042,41,1}, /* core3 fp64 bit58 */
			{30046,41,1}, /* core3 fp64 bit59 */
			{39040,41,1}, /* core3 fp64 bit60 */
			{29574,41,1}, /* core3 fp64 bit61 */
			{30045,41,1}, /* core3 fp64 bit62 */
			{39062,41,1}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{38539,41,1}, /* core3 sp_EL0 bit0 */
			{32816,41,1}, /* core3 sp_EL0 bit1 */
			{32808,41,1}, /* core3 sp_EL0 bit2 */
			{38533,41,1}, /* core3 sp_EL0 bit3 */
			{32740,41,1}, /* core3 sp_EL0 bit4 */
			{32807,41,1}, /* core3 sp_EL0 bit5 */
			{38531,41,1}, /* core3 sp_EL0 bit6 */
			{38538,41,1}, /* core3 sp_EL0 bit7 */
			{38540,41,1}, /* core3 sp_EL0 bit8 */
			{38882,41,1}, /* core3 sp_EL0 bit9 */
			{32739,41,1}, /* core3 sp_EL0 bit10 */
			{32806,41,1}, /* core3 sp_EL0 bit11 */
			{32815,41,1}, /* core3 sp_EL0 bit12 */
			{32814,41,1}, /* core3 sp_EL0 bit13 */
			{32805,41,1}, /* core3 sp_EL0 bit14 */
			{32738,41,1}, /* core3 sp_EL0 bit15 */
			{38532,41,1}, /* core3 sp_EL0 bit16 */
			{32737,41,1}, /* core3 sp_EL0 bit17 */
			{38537,41,1}, /* core3 sp_EL0 bit18 */
			{32813,41,1}, /* core3 sp_EL0 bit19 */
			{38884,41,1}, /* core3 sp_EL0 bit20 */
			{38881,41,1}, /* core3 sp_EL0 bit21 */
			{38878,41,1}, /* core3 sp_EL0 bit22 */
			{38448,41,1}, /* core3 sp_EL0 bit23 */
			{38880,41,1}, /* core3 sp_EL0 bit24 */
			{32744,41,1}, /* core3 sp_EL0 bit25 */
			{38877,41,1}, /* core3 sp_EL0 bit26 */
			{32743,41,1}, /* core3 sp_EL0 bit27 */
			{38879,41,1}, /* core3 sp_EL0 bit28 */
			{32742,41,1}, /* core3 sp_EL0 bit29 */
			{32741,41,1}, /* core3 sp_EL0 bit30 */
			{38883,41,1}, /* core3 sp_EL0 bit31 */
			{32202,41,1}, /* core3 sp_EL0 bit32 */
			{32204,41,1}, /* core3 sp_EL0 bit33 */
			{32201,41,1}, /* core3 sp_EL0 bit34 */
			{33365,41,1}, /* core3 sp_EL0 bit35 */
			{32203,41,1}, /* core3 sp_EL0 bit36 */
			{33366,41,1}, /* core3 sp_EL0 bit37 */
			{32388,41,1}, /* core3 sp_EL0 bit38 */
			{32384,41,1}, /* core3 sp_EL0 bit39 */
			{32387,41,1}, /* core3 sp_EL0 bit40 */
			{32383,41,1}, /* core3 sp_EL0 bit41 */
			{38812,41,1}, /* core3 sp_EL0 bit42 */
			{32382,41,1}, /* core3 sp_EL0 bit43 */
			{38811,41,1}, /* core3 sp_EL0 bit44 */
			{32386,41,1}, /* core3 sp_EL0 bit45 */
			{32381,41,1}, /* core3 sp_EL0 bit46 */
			{32212,41,1}, /* core3 sp_EL0 bit47 */
			{32211,41,1}, /* core3 sp_EL0 bit48 */
			{32454,41,1}, /* core3 sp_EL0 bit49 */
			{32218,41,1}, /* core3 sp_EL0 bit50 */
			{32217,41,1}, /* core3 sp_EL0 bit51 */
			{32453,41,1}, /* core3 sp_EL0 bit52 */
			{30043,41,1}, /* core3 sp_EL0 bit53 */
			{32452,41,1}, /* core3 sp_EL0 bit54 */
			{32451,41,1}, /* core3 sp_EL0 bit55 */
			{32220,41,1}, /* core3 sp_EL0 bit56 */
			{32222,41,1}, /* core3 sp_EL0 bit57 */
			{32221,41,1}, /* core3 sp_EL0 bit58 */
			{32219,41,1}, /* core3 sp_EL0 bit59 */
			{30044,41,1}, /* core3 sp_EL0 bit60 */
			{32216,41,1}, /* core3 sp_EL0 bit61 */
			{32215,41,1}, /* core3 sp_EL0 bit62 */
			{32385,41,1}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{38443,41,1}, /* core3 sp_EL1 bit0 */
			{38447,41,1}, /* core3 sp_EL1 bit1 */
			{32812,41,1}, /* core3 sp_EL1 bit2 */
			{32811,41,1}, /* core3 sp_EL1 bit3 */
			{38445,41,1}, /* core3 sp_EL1 bit4 */
			{38442,41,1}, /* core3 sp_EL1 bit5 */
			{38536,41,1}, /* core3 sp_EL1 bit6 */
			{38441,41,1}, /* core3 sp_EL1 bit7 */
			{38444,41,1}, /* core3 sp_EL1 bit8 */
			{32820,41,1}, /* core3 sp_EL1 bit9 */
			{38446,41,1}, /* core3 sp_EL1 bit10 */
			{38440,41,1}, /* core3 sp_EL1 bit11 */
			{38534,41,1}, /* core3 sp_EL1 bit12 */
			{32819,41,1}, /* core3 sp_EL1 bit13 */
			{38535,41,1}, /* core3 sp_EL1 bit14 */
			{32810,41,1}, /* core3 sp_EL1 bit15 */
			{32809,41,1}, /* core3 sp_EL1 bit16 */
			{38529,41,1}, /* core3 sp_EL1 bit17 */
			{38528,41,1}, /* core3 sp_EL1 bit18 */
			{32818,41,1}, /* core3 sp_EL1 bit19 */
			{38876,41,1}, /* core3 sp_EL1 bit20 */
			{32824,41,1}, /* core3 sp_EL1 bit21 */
			{32823,41,1}, /* core3 sp_EL1 bit22 */
			{38874,41,1}, /* core3 sp_EL1 bit23 */
			{38875,41,1}, /* core3 sp_EL1 bit24 */
			{38872,41,1}, /* core3 sp_EL1 bit25 */
			{32822,41,1}, /* core3 sp_EL1 bit26 */
			{32821,41,1}, /* core3 sp_EL1 bit27 */
			{38873,41,1}, /* core3 sp_EL1 bit28 */
			{32817,41,1}, /* core3 sp_EL1 bit29 */
			{38871,41,1}, /* core3 sp_EL1 bit30 */
			{38530,41,1}, /* core3 sp_EL1 bit31 */
			{32376,41,1}, /* core3 sp_EL1 bit32 */
			{32375,41,1}, /* core3 sp_EL1 bit33 */
			{32374,41,1}, /* core3 sp_EL1 bit34 */
			{32208,41,1}, /* core3 sp_EL1 bit35 */
			{30040,41,1}, /* core3 sp_EL1 bit36 */
			{32207,41,1}, /* core3 sp_EL1 bit37 */
			{39083,41,1}, /* core3 sp_EL1 bit38 */
			{39081,41,1}, /* core3 sp_EL1 bit39 */
			{39082,41,1}, /* core3 sp_EL1 bit40 */
			{33364,41,1}, /* core3 sp_EL1 bit41 */
			{38810,41,1}, /* core3 sp_EL1 bit42 */
			{29724,41,1}, /* core3 sp_EL1 bit43 */
			{38809,41,1}, /* core3 sp_EL1 bit44 */
			{39080,41,1}, /* core3 sp_EL1 bit45 */
			{29740,41,1}, /* core3 sp_EL1 bit46 */
			{32214,41,1}, /* core3 sp_EL1 bit47 */
			{32450,41,1}, /* core3 sp_EL1 bit48 */
			{32442,41,1}, /* core3 sp_EL1 bit49 */
			{32441,41,1}, /* core3 sp_EL1 bit50 */
			{32449,41,1}, /* core3 sp_EL1 bit51 */
			{32440,41,1}, /* core3 sp_EL1 bit52 */
			{32224,41,1}, /* core3 sp_EL1 bit53 */
			{32446,41,1}, /* core3 sp_EL1 bit54 */
			{32213,41,1}, /* core3 sp_EL1 bit55 */
			{32445,41,1}, /* core3 sp_EL1 bit56 */
			{32448,41,1}, /* core3 sp_EL1 bit57 */
			{32447,41,1}, /* core3 sp_EL1 bit58 */
			{32223,41,1}, /* core3 sp_EL1 bit59 */
			{32439,41,1}, /* core3 sp_EL1 bit60 */
			{32444,41,1}, /* core3 sp_EL1 bit61 */
			{32443,41,1}, /* core3 sp_EL1 bit62 */
			{32373,41,1}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{38517,41,1}, /* core3 sp_EL2 bit0 */
			{32700,41,1}, /* core3 sp_EL2 bit1 */
			{38516,41,1}, /* core3 sp_EL2 bit2 */
			{32699,41,1}, /* core3 sp_EL2 bit3 */
			{38410,41,1}, /* core3 sp_EL2 bit4 */
			{32732,41,1}, /* core3 sp_EL2 bit5 */
			{32698,41,1}, /* core3 sp_EL2 bit6 */
			{32697,41,1}, /* core3 sp_EL2 bit7 */
			{38519,41,1}, /* core3 sp_EL2 bit8 */
			{32731,41,1}, /* core3 sp_EL2 bit9 */
			{32730,41,1}, /* core3 sp_EL2 bit10 */
			{38523,41,1}, /* core3 sp_EL2 bit11 */
			{38527,41,1}, /* core3 sp_EL2 bit12 */
			{38525,41,1}, /* core3 sp_EL2 bit13 */
			{38521,41,1}, /* core3 sp_EL2 bit14 */
			{38409,41,1}, /* core3 sp_EL2 bit15 */
			{38520,41,1}, /* core3 sp_EL2 bit16 */
			{38524,41,1}, /* core3 sp_EL2 bit17 */
			{38518,41,1}, /* core3 sp_EL2 bit18 */
			{32696,41,1}, /* core3 sp_EL2 bit19 */
			{38412,41,1}, /* core3 sp_EL2 bit20 */
			{32729,41,1}, /* core3 sp_EL2 bit21 */
			{32728,41,1}, /* core3 sp_EL2 bit22 */
			{32727,41,1}, /* core3 sp_EL2 bit23 */
			{38522,41,1}, /* core3 sp_EL2 bit24 */
			{32695,41,1}, /* core3 sp_EL2 bit25 */
			{38526,41,1}, /* core3 sp_EL2 bit26 */
			{38411,41,1}, /* core3 sp_EL2 bit27 */
			{32726,41,1}, /* core3 sp_EL2 bit28 */
			{32725,41,1}, /* core3 sp_EL2 bit29 */
			{32694,41,1}, /* core3 sp_EL2 bit30 */
			{32693,41,1}, /* core3 sp_EL2 bit31 */
			{33368,41,1}, /* core3 sp_EL2 bit32 */
			{32206,41,1}, /* core3 sp_EL2 bit33 */
			{33369,41,1}, /* core3 sp_EL2 bit34 */
			{33367,41,1}, /* core3 sp_EL2 bit35 */
			{32102,41,1}, /* core3 sp_EL2 bit36 */
			{32205,41,1}, /* core3 sp_EL2 bit37 */
			{32106,41,1}, /* core3 sp_EL2 bit38 */
			{38802,41,1}, /* core3 sp_EL2 bit39 */
			{29727,41,1}, /* core3 sp_EL2 bit40 */
			{32396,41,1}, /* core3 sp_EL2 bit41 */
			{38801,41,1}, /* core3 sp_EL2 bit42 */
			{32395,41,1}, /* core3 sp_EL2 bit43 */
			{32394,41,1}, /* core3 sp_EL2 bit44 */
			{32105,41,1}, /* core3 sp_EL2 bit45 */
			{32393,41,1}, /* core3 sp_EL2 bit46 */
			{32210,41,1}, /* core3 sp_EL2 bit47 */
			{32209,41,1}, /* core3 sp_EL2 bit48 */
			{30042,41,1}, /* core3 sp_EL2 bit49 */
			{32434,41,1}, /* core3 sp_EL2 bit50 */
			{32433,41,1}, /* core3 sp_EL2 bit51 */
			{32228,41,1}, /* core3 sp_EL2 bit52 */
			{30049,41,1}, /* core3 sp_EL2 bit53 */
			{30048,41,1}, /* core3 sp_EL2 bit54 */
			{32432,41,1}, /* core3 sp_EL2 bit55 */
			{32230,41,1}, /* core3 sp_EL2 bit56 */
			{32232,41,1}, /* core3 sp_EL2 bit57 */
			{30041,41,1}, /* core3 sp_EL2 bit58 */
			{32229,41,1}, /* core3 sp_EL2 bit59 */
			{32231,41,1}, /* core3 sp_EL2 bit60 */
			{32431,41,1}, /* core3 sp_EL2 bit61 */
			{32227,41,1}, /* core3 sp_EL2 bit62 */
			{32101,41,1}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{32708,41,1}, /* core3 sp_EL3 bit0 */
			{38506,41,1}, /* core3 sp_EL3 bit1 */
			{38498,41,1}, /* core3 sp_EL3 bit2 */
			{32707,41,1}, /* core3 sp_EL3 bit3 */
			{32706,41,1}, /* core3 sp_EL3 bit4 */
			{32705,41,1}, /* core3 sp_EL3 bit5 */
			{38502,41,1}, /* core3 sp_EL3 bit6 */
			{38496,41,1}, /* core3 sp_EL3 bit7 */
			{38495,41,1}, /* core3 sp_EL3 bit8 */
			{38504,41,1}, /* core3 sp_EL3 bit9 */
			{38497,41,1}, /* core3 sp_EL3 bit10 */
			{38418,41,1}, /* core3 sp_EL3 bit11 */
			{38501,41,1}, /* core3 sp_EL3 bit12 */
			{38416,41,1}, /* core3 sp_EL3 bit13 */
			{38500,41,1}, /* core3 sp_EL3 bit14 */
			{38419,41,1}, /* core3 sp_EL3 bit15 */
			{38417,41,1}, /* core3 sp_EL3 bit16 */
			{38503,41,1}, /* core3 sp_EL3 bit17 */
			{38499,41,1}, /* core3 sp_EL3 bit18 */
			{32716,41,1}, /* core3 sp_EL3 bit19 */
			{32724,41,1}, /* core3 sp_EL3 bit20 */
			{32723,41,1}, /* core3 sp_EL3 bit21 */
			{32715,41,1}, /* core3 sp_EL3 bit22 */
			{32720,41,1}, /* core3 sp_EL3 bit23 */
			{38505,41,1}, /* core3 sp_EL3 bit24 */
			{32714,41,1}, /* core3 sp_EL3 bit25 */
			{32722,41,1}, /* core3 sp_EL3 bit26 */
			{32721,41,1}, /* core3 sp_EL3 bit27 */
			{32719,41,1}, /* core3 sp_EL3 bit28 */
			{32718,41,1}, /* core3 sp_EL3 bit29 */
			{32717,41,1}, /* core3 sp_EL3 bit30 */
			{32713,41,1}, /* core3 sp_EL3 bit31 */
			{32380,41,1}, /* core3 sp_EL3 bit32 */
			{32379,41,1}, /* core3 sp_EL3 bit33 */
			{32372,41,1}, /* core3 sp_EL3 bit34 */
			{32371,41,1}, /* core3 sp_EL3 bit35 */
			{32370,41,1}, /* core3 sp_EL3 bit36 */
			{32369,41,1}, /* core3 sp_EL3 bit37 */
			{29739,41,1}, /* core3 sp_EL3 bit38 */
			{38808,41,1}, /* core3 sp_EL3 bit39 */
			{32378,41,1}, /* core3 sp_EL3 bit40 */
			{38807,41,1}, /* core3 sp_EL3 bit41 */
			{38804,41,1}, /* core3 sp_EL3 bit42 */
			{38806,41,1}, /* core3 sp_EL3 bit43 */
			{29738,41,1}, /* core3 sp_EL3 bit44 */
			{38803,41,1}, /* core3 sp_EL3 bit45 */
			{38805,41,1}, /* core3 sp_EL3 bit46 */
			{32344,41,1}, /* core3 sp_EL3 bit47 */
			{32343,41,1}, /* core3 sp_EL3 bit48 */
			{32342,41,1}, /* core3 sp_EL3 bit49 */
			{32236,41,1}, /* core3 sp_EL3 bit50 */
			{32234,41,1}, /* core3 sp_EL3 bit51 */
			{32438,41,1}, /* core3 sp_EL3 bit52 */
			{32235,41,1}, /* core3 sp_EL3 bit53 */
			{32437,41,1}, /* core3 sp_EL3 bit54 */
			{32233,41,1}, /* core3 sp_EL3 bit55 */
			{30047,41,1}, /* core3 sp_EL3 bit56 */
			{30050,41,1}, /* core3 sp_EL3 bit57 */
			{32341,41,1}, /* core3 sp_EL3 bit58 */
			{32436,41,1}, /* core3 sp_EL3 bit59 */
			{32435,41,1}, /* core3 sp_EL3 bit60 */
			{32226,41,1}, /* core3 sp_EL3 bit61 */
			{32225,41,1}, /* core3 sp_EL3 bit62 */
			{32377,41,1}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{32542,41,1}, /* core3 elr_EL1 bit0 */
			{38888,41,1}, /* core3 elr_EL1 bit1 */
			{38892,41,1}, /* core3 elr_EL1 bit2 */
			{38894,41,1}, /* core3 elr_EL1 bit3 */
			{38896,41,1}, /* core3 elr_EL1 bit4 */
			{38543,41,1}, /* core3 elr_EL1 bit5 */
			{38893,41,1}, /* core3 elr_EL1 bit6 */
			{38891,41,1}, /* core3 elr_EL1 bit7 */
			{38895,41,1}, /* core3 elr_EL1 bit8 */
			{38544,41,1}, /* core3 elr_EL1 bit9 */
			{38886,41,1}, /* core3 elr_EL1 bit10 */
			{32541,41,1}, /* core3 elr_EL1 bit11 */
			{38890,41,1}, /* core3 elr_EL1 bit12 */
			{38542,41,1}, /* core3 elr_EL1 bit13 */
			{38885,41,1}, /* core3 elr_EL1 bit14 */
			{32540,41,1}, /* core3 elr_EL1 bit15 */
			{32539,41,1}, /* core3 elr_EL1 bit16 */
			{38887,41,1}, /* core3 elr_EL1 bit17 */
			{38889,41,1}, /* core3 elr_EL1 bit18 */
			{32800,41,1}, /* core3 elr_EL1 bit19 */
			{32804,41,1}, /* core3 elr_EL1 bit20 */
			{32796,41,1}, /* core3 elr_EL1 bit21 */
			{32799,41,1}, /* core3 elr_EL1 bit22 */
			{32798,41,1}, /* core3 elr_EL1 bit23 */
			{32795,41,1}, /* core3 elr_EL1 bit24 */
			{32803,41,1}, /* core3 elr_EL1 bit25 */
			{32794,41,1}, /* core3 elr_EL1 bit26 */
			{32802,41,1}, /* core3 elr_EL1 bit27 */
			{32797,41,1}, /* core3 elr_EL1 bit28 */
			{29781,41,1}, /* core3 elr_EL1 bit29 */
			{32793,41,1}, /* core3 elr_EL1 bit30 */
			{32801,41,1}, /* core3 elr_EL1 bit31 */
			{32392,41,1}, /* core3 elr_EL1 bit32 */
			{32368,41,1}, /* core3 elr_EL1 bit33 */
			{32391,41,1}, /* core3 elr_EL1 bit34 */
			{32390,41,1}, /* core3 elr_EL1 bit35 */
			{32389,41,1}, /* core3 elr_EL1 bit36 */
			{32367,41,1}, /* core3 elr_EL1 bit37 */
			{33346,41,1}, /* core3 elr_EL1 bit38 */
			{32104,41,1}, /* core3 elr_EL1 bit39 */
			{33345,41,1}, /* core3 elr_EL1 bit40 */
			{32400,41,1}, /* core3 elr_EL1 bit41 */
			{32399,41,1}, /* core3 elr_EL1 bit42 */
			{32398,41,1}, /* core3 elr_EL1 bit43 */
			{29737,41,1}, /* core3 elr_EL1 bit44 */
			{32103,41,1}, /* core3 elr_EL1 bit45 */
			{32397,41,1}, /* core3 elr_EL1 bit46 */
			{32346,41,1}, /* core3 elr_EL1 bit47 */
			{33361,41,1}, /* core3 elr_EL1 bit48 */
			{33360,41,1}, /* core3 elr_EL1 bit49 */
			{32238,41,1}, /* core3 elr_EL1 bit50 */
			{33362,41,1}, /* core3 elr_EL1 bit51 */
			{32340,41,1}, /* core3 elr_EL1 bit52 */
			{32350,41,1}, /* core3 elr_EL1 bit53 */
			{32240,41,1}, /* core3 elr_EL1 bit54 */
			{32237,41,1}, /* core3 elr_EL1 bit55 */
			{32349,41,1}, /* core3 elr_EL1 bit56 */
			{32345,41,1}, /* core3 elr_EL1 bit57 */
			{32348,41,1}, /* core3 elr_EL1 bit58 */
			{32239,41,1}, /* core3 elr_EL1 bit59 */
			{32347,41,1}, /* core3 elr_EL1 bit60 */
			{33363,41,1}, /* core3 elr_EL1 bit61 */
			{32339,41,1}, /* core3 elr_EL1 bit62 */
			{33347,41,1}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{38754,41,1}, /* core3 elr_EL2 bit0 */
			{29783,41,1}, /* core3 elr_EL2 bit1 */
			{29782,41,1}, /* core3 elr_EL2 bit2 */
			{38742,41,1}, /* core3 elr_EL2 bit3 */
			{38752,41,1}, /* core3 elr_EL2 bit4 */
			{38740,41,1}, /* core3 elr_EL2 bit5 */
			{38898,41,1}, /* core3 elr_EL2 bit6 */
			{38750,41,1}, /* core3 elr_EL2 bit7 */
			{38545,41,1}, /* core3 elr_EL2 bit8 */
			{38753,41,1}, /* core3 elr_EL2 bit9 */
			{38739,41,1}, /* core3 elr_EL2 bit10 */
			{38897,41,1}, /* core3 elr_EL2 bit11 */
			{38541,41,1}, /* core3 elr_EL2 bit12 */
			{38749,41,1}, /* core3 elr_EL2 bit13 */
			{38741,41,1}, /* core3 elr_EL2 bit14 */
			{38546,41,1}, /* core3 elr_EL2 bit15 */
			{38751,41,1}, /* core3 elr_EL2 bit16 */
			{38744,41,1}, /* core3 elr_EL2 bit17 */
			{38743,41,1}, /* core3 elr_EL2 bit18 */
			{38738,41,1}, /* core3 elr_EL2 bit19 */
			{32538,41,1}, /* core3 elr_EL2 bit20 */
			{38736,41,1}, /* core3 elr_EL2 bit21 */
			{38746,41,1}, /* core3 elr_EL2 bit22 */
			{38737,41,1}, /* core3 elr_EL2 bit23 */
			{32537,41,1}, /* core3 elr_EL2 bit24 */
			{38745,41,1}, /* core3 elr_EL2 bit25 */
			{38735,41,1}, /* core3 elr_EL2 bit26 */
			{29784,41,1}, /* core3 elr_EL2 bit27 */
			{38748,41,1}, /* core3 elr_EL2 bit28 */
			{32536,41,1}, /* core3 elr_EL2 bit29 */
			{32535,41,1}, /* core3 elr_EL2 bit30 */
			{38747,41,1}, /* core3 elr_EL2 bit31 */
			{32362,41,1}, /* core3 elr_EL2 bit32 */
			{32361,41,1}, /* core3 elr_EL2 bit33 */
			{32416,41,1}, /* core3 elr_EL2 bit34 */
			{32415,41,1}, /* core3 elr_EL2 bit35 */
			{33348,41,1}, /* core3 elr_EL2 bit36 */
			{32360,41,1}, /* core3 elr_EL2 bit37 */
			{32414,41,1}, /* core3 elr_EL2 bit38 */
			{32413,41,1}, /* core3 elr_EL2 bit39 */
			{32410,41,1}, /* core3 elr_EL2 bit40 */
			{32264,41,1}, /* core3 elr_EL2 bit41 */
			{32263,41,1}, /* core3 elr_EL2 bit42 */
			{32409,41,1}, /* core3 elr_EL2 bit43 */
			{32412,41,1}, /* core3 elr_EL2 bit44 */
			{32411,41,1}, /* core3 elr_EL2 bit45 */
			{29736,41,1}, /* core3 elr_EL2 bit46 */
			{32358,41,1}, /* core3 elr_EL2 bit47 */
			{32354,41,1}, /* core3 elr_EL2 bit48 */
			{33358,41,1}, /* core3 elr_EL2 bit49 */
			{32244,41,1}, /* core3 elr_EL2 bit50 */
			{32357,41,1}, /* core3 elr_EL2 bit51 */
			{32246,41,1}, /* core3 elr_EL2 bit52 */
			{32353,41,1}, /* core3 elr_EL2 bit53 */
			{32352,41,1}, /* core3 elr_EL2 bit54 */
			{32242,41,1}, /* core3 elr_EL2 bit55 */
			{32243,41,1}, /* core3 elr_EL2 bit56 */
			{32356,41,1}, /* core3 elr_EL2 bit57 */
			{33359,41,1}, /* core3 elr_EL2 bit58 */
			{32241,41,1}, /* core3 elr_EL2 bit59 */
			{32245,41,1}, /* core3 elr_EL2 bit60 */
			{32351,41,1}, /* core3 elr_EL2 bit61 */
			{32355,41,1}, /* core3 elr_EL2 bit62 */
			{32359,41,1}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{33256,41,1}, /* core3 elr_EL3 bit0 */
			{33260,41,1}, /* core3 elr_EL3 bit1 */
			{33259,41,1}, /* core3 elr_EL3 bit2 */
			{29173,41,1}, /* core3 elr_EL3 bit3 */
			{38756,41,1}, /* core3 elr_EL3 bit4 */
			{38870,41,1}, /* core3 elr_EL3 bit5 */
			{29169,41,1}, /* core3 elr_EL3 bit6 */
			{29168,41,1}, /* core3 elr_EL3 bit7 */
			{33255,41,1}, /* core3 elr_EL3 bit8 */
			{29171,41,1}, /* core3 elr_EL3 bit9 */
			{33258,41,1}, /* core3 elr_EL3 bit10 */
			{38755,41,1}, /* core3 elr_EL3 bit11 */
			{33254,41,1}, /* core3 elr_EL3 bit12 */
			{33253,41,1}, /* core3 elr_EL3 bit13 */
			{33257,41,1}, /* core3 elr_EL3 bit14 */
			{38401,41,1}, /* core3 elr_EL3 bit15 */
			{29170,41,1}, /* core3 elr_EL3 bit16 */
			{38869,41,1}, /* core3 elr_EL3 bit17 */
			{38403,41,1}, /* core3 elr_EL3 bit18 */
			{38400,41,1}, /* core3 elr_EL3 bit19 */
			{29179,41,1}, /* core3 elr_EL3 bit20 */
			{29181,41,1}, /* core3 elr_EL3 bit21 */
			{29177,41,1}, /* core3 elr_EL3 bit22 */
			{29180,41,1}, /* core3 elr_EL3 bit23 */
			{38404,41,1}, /* core3 elr_EL3 bit24 */
			{38402,41,1}, /* core3 elr_EL3 bit25 */
			{38405,41,1}, /* core3 elr_EL3 bit26 */
			{29176,41,1}, /* core3 elr_EL3 bit27 */
			{29175,41,1}, /* core3 elr_EL3 bit28 */
			{29178,41,1}, /* core3 elr_EL3 bit29 */
			{29174,41,1}, /* core3 elr_EL3 bit30 */
			{29172,41,1}, /* core3 elr_EL3 bit31 */
			{33349,41,1}, /* core3 elr_EL3 bit32 */
			{32366,41,1}, /* core3 elr_EL3 bit33 */
			{32365,41,1}, /* core3 elr_EL3 bit34 */
			{32100,41,1}, /* core3 elr_EL3 bit35 */
			{32099,41,1}, /* core3 elr_EL3 bit36 */
			{32364,41,1}, /* core3 elr_EL3 bit37 */
			{32408,41,1}, /* core3 elr_EL3 bit38 */
			{29735,41,1}, /* core3 elr_EL3 bit39 */
			{32404,41,1}, /* core3 elr_EL3 bit40 */
			{32403,41,1}, /* core3 elr_EL3 bit41 */
			{32407,41,1}, /* core3 elr_EL3 bit42 */
			{32406,41,1}, /* core3 elr_EL3 bit43 */
			{32402,41,1}, /* core3 elr_EL3 bit44 */
			{32401,41,1}, /* core3 elr_EL3 bit45 */
			{32405,41,1}, /* core3 elr_EL3 bit46 */
			{38198,41,1}, /* core3 elr_EL3 bit47 */
			{38197,41,1}, /* core3 elr_EL3 bit48 */
			{32250,41,1}, /* core3 elr_EL3 bit49 */
			{38196,41,1}, /* core3 elr_EL3 bit50 */
			{33357,41,1}, /* core3 elr_EL3 bit51 */
			{32430,41,1}, /* core3 elr_EL3 bit52 */
			{32248,41,1}, /* core3 elr_EL3 bit53 */
			{33354,41,1}, /* core3 elr_EL3 bit54 */
			{32429,41,1}, /* core3 elr_EL3 bit55 */
			{32096,41,1}, /* core3 elr_EL3 bit56 */
			{33355,41,1}, /* core3 elr_EL3 bit57 */
			{32095,41,1}, /* core3 elr_EL3 bit58 */
			{32247,41,1}, /* core3 elr_EL3 bit59 */
			{32249,41,1}, /* core3 elr_EL3 bit60 */
			{33356,41,1}, /* core3 elr_EL3 bit61 */
			{38195,41,1}, /* core3 elr_EL3 bit62 */
			{32363,41,1}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{31360,41,1}, /* core3 raw_pc bit0 */
			{31359,41,1}, /* core3 raw_pc bit1 */
			{36945,41,1}, /* core3 raw_pc bit2 */
			{36947,41,1}, /* core3 raw_pc bit3 */
			{31357,41,1}, /* core3 raw_pc bit4 */
			{31358,41,1}, /* core3 raw_pc bit5 */
			{31356,41,1}, /* core3 raw_pc bit6 */
			{36950,41,1}, /* core3 raw_pc bit7 */
			{36954,41,1}, /* core3 raw_pc bit8 */
			{40774,41,1}, /* core3 raw_pc bit9 */
			{40773,41,1}, /* core3 raw_pc bit10 */
			{36949,41,1}, /* core3 raw_pc bit11 */
			{38665,41,1}, /* core3 raw_pc bit12 */
			{40776,41,1}, /* core3 raw_pc bit13 */
			{42270,41,1}, /* core3 raw_pc bit14 */
			{42269,41,1}, /* core3 raw_pc bit15 */
			{40775,41,1}, /* core3 raw_pc bit16 */
			{42601,41,1}, /* core3 raw_pc bit17 */
			{38657,41,1}, /* core3 raw_pc bit18 */
			{42600,41,1}, /* core3 raw_pc bit19 */
			{42204,41,1}, /* core3 raw_pc bit20 */
			{42268,41,1}, /* core3 raw_pc bit21 */
			{42267,41,1}, /* core3 raw_pc bit22 */
			{38664,41,1}, /* core3 raw_pc bit23 */
			{38662,41,1}, /* core3 raw_pc bit24 */
			{42599,41,1}, /* core3 raw_pc bit25 */
			{38663,41,1}, /* core3 raw_pc bit26 */
			{42203,41,1}, /* core3 raw_pc bit27 */
			{42598,41,1}, /* core3 raw_pc bit28 */
			{36951,41,1}, /* core3 raw_pc bit29 */
			{36955,41,1}, /* core3 raw_pc bit30 */
			{42208,41,1}, /* core3 raw_pc bit31 */
			{42206,41,1}, /* core3 raw_pc bit32 */
			{36896,41,1}, /* core3 raw_pc bit33 */
			{42244,41,1}, /* core3 raw_pc bit34 */
			{42212,41,1}, /* core3 raw_pc bit35 */
			{42205,41,1}, /* core3 raw_pc bit36 */
			{42207,41,1}, /* core3 raw_pc bit37 */
			{42236,41,1}, /* core3 raw_pc bit38 */
			{42243,41,1}, /* core3 raw_pc bit39 */
			{42235,41,1}, /* core3 raw_pc bit40 */
			{42234,41,1}, /* core3 raw_pc bit41 */
			{42211,41,1}, /* core3 raw_pc bit42 */
			{42242,41,1}, /* core3 raw_pc bit43 */
			{42241,41,1}, /* core3 raw_pc bit44 */
			{42233,41,1}, /* core3 raw_pc bit45 */
			{42210,41,1}, /* core3 raw_pc bit46 */
			{42209,41,1}, /* core3 raw_pc bit47 */
			{42246,41,1}, /* core3 raw_pc bit48 */
			{42245,41,1}, /* core3 raw_pc bit49 */
			{    0, 0,2}, /* core3 raw_pc bit50 */
			{    0, 0,2}, /* core3 raw_pc bit51 */
			{    0, 0,2}, /* core3 raw_pc bit52 */
			{    0, 0,2}, /* core3 raw_pc bit53 */
			{    0, 0,2}, /* core3 raw_pc bit54 */
			{    0, 0,2}, /* core3 raw_pc bit55 */
			{    0, 0,2}, /* core3 raw_pc bit56 */
			{    0, 0,2}, /* core3 raw_pc bit57 */
			{    0, 0,2}, /* core3 raw_pc bit58 */
			{    0, 0,2}, /* core3 raw_pc bit59 */
			{    0, 0,2}, /* core3 raw_pc bit60 */
			{    0, 0,2}, /* core3 raw_pc bit61 */
			{    0, 0,2}, /* core3 raw_pc bit62 */
			{    0, 0,2}, /* core3 raw_pc bit63 */
			}},
			.pc_iss = {{
			{41846,41,1}, /* core3 pc_iss bit0 */
			{41845,41,1}, /* core3 pc_iss bit1 */
			{41844,41,1}, /* core3 pc_iss bit2 */
			{36925,41,1}, /* core3 pc_iss bit3 */
			{41843,41,1}, /* core3 pc_iss bit4 */
			{41583,41,1}, /* core3 pc_iss bit5 */
			{36924,41,1}, /* core3 pc_iss bit6 */
			{41582,41,1}, /* core3 pc_iss bit7 */
			{41617,41,1}, /* core3 pc_iss bit8 */
			{38614,41,1}, /* core3 pc_iss bit9 */
			{31173,41,1}, /* core3 pc_iss bit10 */
			{31167,41,1}, /* core3 pc_iss bit11 */
			{31166,41,1}, /* core3 pc_iss bit12 */
			{41621,41,1}, /* core3 pc_iss bit13 */
			{38612,41,1}, /* core3 pc_iss bit14 */
			{41856,41,1}, /* core3 pc_iss bit15 */
			{31172,41,1}, /* core3 pc_iss bit16 */
			{41620,41,1}, /* core3 pc_iss bit17 */
			{31697,41,1}, /* core3 pc_iss bit18 */
			{41616,41,1}, /* core3 pc_iss bit19 */
			{41619,41,1}, /* core3 pc_iss bit20 */
			{41855,41,1}, /* core3 pc_iss bit21 */
			{41854,41,1}, /* core3 pc_iss bit22 */
			{41853,41,1}, /* core3 pc_iss bit23 */
			{41618,41,1}, /* core3 pc_iss bit24 */
			{41848,41,1}, /* core3 pc_iss bit25 */
			{41847,41,1}, /* core3 pc_iss bit26 */
			{41611,41,1}, /* core3 pc_iss bit27 */
			{41610,41,1}, /* core3 pc_iss bit28 */
			{31696,41,1}, /* core3 pc_iss bit29 */
			{41609,41,1}, /* core3 pc_iss bit30 */
			{41608,41,1}, /* core3 pc_iss bit31 */
			{36940,41,1}, /* core3 pc_iss bit32 */
			{41597,41,1}, /* core3 pc_iss bit33 */
			{41596,41,1}, /* core3 pc_iss bit34 */
			{36939,41,1}, /* core3 pc_iss bit35 */
			{36886,41,1}, /* core3 pc_iss bit36 */
			{31193,41,1}, /* core3 pc_iss bit37 */
			{31192,41,1}, /* core3 pc_iss bit38 */
			{36938,41,1}, /* core3 pc_iss bit39 */
			{41593,41,1}, /* core3 pc_iss bit40 */
			{41592,41,1}, /* core3 pc_iss bit41 */
			{41595,41,1}, /* core3 pc_iss bit42 */
			{38617,41,1}, /* core3 pc_iss bit43 */
			{41594,41,1}, /* core3 pc_iss bit44 */
			{38611,41,1}, /* core3 pc_iss bit45 */
			{38616,41,1}, /* core3 pc_iss bit46 */
			{38658,41,1}, /* core3 pc_iss bit47 */
			{38659,41,1}, /* core3 pc_iss bit48 */
			{31163,41,1}, /* core3 pc_iss bit49 */
			{38660,41,1}, /* core3 pc_iss bit50 */
			{42603,41,1}, /* core3 pc_iss bit51 */
			{31162,41,1}, /* core3 pc_iss bit52 */
			{42602,41,1}, /* core3 pc_iss bit53 */
			{38661,41,1}, /* core3 pc_iss bit54 */
			{42202,41,1}, /* core3 pc_iss bit55 */
			{38656,41,1}, /* core3 pc_iss bit56 */
			{42198,41,1}, /* core3 pc_iss bit57 */
			{42197,41,1}, /* core3 pc_iss bit58 */
			{42196,41,1}, /* core3 pc_iss bit59 */
			{42201,41,1}, /* core3 pc_iss bit60 */
			{42200,41,1}, /* core3 pc_iss bit61 */
			{42195,41,1}, /* core3 pc_iss bit62 */
			{42199,41,1}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{31361,41,1}, /* core3 full_pc_wr bit0 */
			{    0, 0,2}, /* core3 full_pc_wr bit1 */
			{    0, 0,2}, /* core3 full_pc_wr bit2 */
			{    0, 0,2}, /* core3 full_pc_wr bit3 */
			{    0, 0,2}, /* core3 full_pc_wr bit4 */
			{    0, 0,2}, /* core3 full_pc_wr bit5 */
			{    0, 0,2}, /* core3 full_pc_wr bit6 */
			{    0, 0,2}, /* core3 full_pc_wr bit7 */
			{    0, 0,2}, /* core3 full_pc_wr bit8 */
			{    0, 0,2}, /* core3 full_pc_wr bit9 */
			{    0, 0,2}, /* core3 full_pc_wr bit10 */
			{    0, 0,2}, /* core3 full_pc_wr bit11 */
			{    0, 0,2}, /* core3 full_pc_wr bit12 */
			{    0, 0,2}, /* core3 full_pc_wr bit13 */
			{    0, 0,2}, /* core3 full_pc_wr bit14 */
			{    0, 0,2}, /* core3 full_pc_wr bit15 */
			{    0, 0,2}, /* core3 full_pc_wr bit16 */
			{    0, 0,2}, /* core3 full_pc_wr bit17 */
			{    0, 0,2}, /* core3 full_pc_wr bit18 */
			{    0, 0,2}, /* core3 full_pc_wr bit19 */
			{    0, 0,2}, /* core3 full_pc_wr bit20 */
			{    0, 0,2}, /* core3 full_pc_wr bit21 */
			{    0, 0,2}, /* core3 full_pc_wr bit22 */
			{    0, 0,2}, /* core3 full_pc_wr bit23 */
			{    0, 0,2}, /* core3 full_pc_wr bit24 */
			{    0, 0,2}, /* core3 full_pc_wr bit25 */
			{    0, 0,2}, /* core3 full_pc_wr bit26 */
			{    0, 0,2}, /* core3 full_pc_wr bit27 */
			{    0, 0,2}, /* core3 full_pc_wr bit28 */
			{    0, 0,2}, /* core3 full_pc_wr bit29 */
			{    0, 0,2}, /* core3 full_pc_wr bit30 */
			{    0, 0,2}, /* core3 full_pc_wr bit31 */
			{    0, 0,2}, /* core3 full_pc_wr bit32 */
			{    0, 0,2}, /* core3 full_pc_wr bit33 */
			{    0, 0,2}, /* core3 full_pc_wr bit34 */
			{    0, 0,2}, /* core3 full_pc_wr bit35 */
			{    0, 0,2}, /* core3 full_pc_wr bit36 */
			{    0, 0,2}, /* core3 full_pc_wr bit37 */
			{    0, 0,2}, /* core3 full_pc_wr bit38 */
			{    0, 0,2}, /* core3 full_pc_wr bit39 */
			{    0, 0,2}, /* core3 full_pc_wr bit40 */
			{    0, 0,2}, /* core3 full_pc_wr bit41 */
			{    0, 0,2}, /* core3 full_pc_wr bit42 */
			{    0, 0,2}, /* core3 full_pc_wr bit43 */
			{    0, 0,2}, /* core3 full_pc_wr bit44 */
			{    0, 0,2}, /* core3 full_pc_wr bit45 */
			{    0, 0,2}, /* core3 full_pc_wr bit46 */
			{    0, 0,2}, /* core3 full_pc_wr bit47 */
			{    0, 0,2}, /* core3 full_pc_wr bit48 */
			{    0, 0,2}, /* core3 full_pc_wr bit49 */
			{    0, 0,2}, /* core3 full_pc_wr bit50 */
			{    0, 0,2}, /* core3 full_pc_wr bit51 */
			{    0, 0,2}, /* core3 full_pc_wr bit52 */
			{    0, 0,2}, /* core3 full_pc_wr bit53 */
			{    0, 0,2}, /* core3 full_pc_wr bit54 */
			{    0, 0,2}, /* core3 full_pc_wr bit55 */
			{    0, 0,2}, /* core3 full_pc_wr bit56 */
			{    0, 0,2}, /* core3 full_pc_wr bit57 */
			{    0, 0,2}, /* core3 full_pc_wr bit58 */
			{    0, 0,2}, /* core3 full_pc_wr bit59 */
			{    0, 0,2}, /* core3 full_pc_wr bit60 */
			{    0, 0,2}, /* core3 full_pc_wr bit61 */
			{    0, 0,2}, /* core3 full_pc_wr bit62 */
			{    0, 0,2}, /* core3 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{41585,41,1}, /* core3 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{40768,41,1}, /* core3 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{27703,41,1}, /* core3 return_Stack_pointer bit0 */
			{27701,41,1}, /* core3 return_Stack_pointer bit1 */
			{14039,41,1}, /* core3 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{17696,41,1}, /* core3 return_Stack0 bit0 */
			{17695,41,1}, /* core3 return_Stack0 bit1 */
			{14923,41,1}, /* core3 return_Stack0 bit2 */
			{14929,41,1}, /* core3 return_Stack0 bit3 */
			{14928,41,1}, /* core3 return_Stack0 bit4 */
			{14931,41,1}, /* core3 return_Stack0 bit5 */
			{17596,41,1}, /* core3 return_Stack0 bit6 */
			{17595,41,1}, /* core3 return_Stack0 bit7 */
			{14922,41,1}, /* core3 return_Stack0 bit8 */
			{14919,41,1}, /* core3 return_Stack0 bit9 */
			{14920,41,1}, /* core3 return_Stack0 bit10 */
			{14911,41,1}, /* core3 return_Stack0 bit11 */
			{14921,41,1}, /* core3 return_Stack0 bit12 */
			{14925,41,1}, /* core3 return_Stack0 bit13 */
			{19268,41,1}, /* core3 return_Stack0 bit14 */
			{14924,41,1}, /* core3 return_Stack0 bit15 */
			{19252,41,1}, /* core3 return_Stack0 bit16 */
			{19251,41,1}, /* core3 return_Stack0 bit17 */
			{19266,41,1}, /* core3 return_Stack0 bit18 */
			{19265,41,1}, /* core3 return_Stack0 bit19 */
			{19267,41,1}, /* core3 return_Stack0 bit20 */
			{14930,41,1}, /* core3 return_Stack0 bit21 */
			{14932,41,1}, /* core3 return_Stack0 bit22 */
			{17694,41,1}, /* core3 return_Stack0 bit23 */
			{14994,41,1}, /* core3 return_Stack0 bit24 */
			{19364,41,1}, /* core3 return_Stack0 bit25 */
			{19538,41,1}, /* core3 return_Stack0 bit26 */
			{19537,41,1}, /* core3 return_Stack0 bit27 */
			{19540,41,1}, /* core3 return_Stack0 bit28 */
			{17616,41,1}, /* core3 return_Stack0 bit29 */
			{15000,41,1}, /* core3 return_Stack0 bit30 */
			{19539,41,1}, /* core3 return_Stack0 bit31 */
			{19363,41,1}, /* core3 return_Stack0 bit32 */
			{17615,41,1}, /* core3 return_Stack0 bit33 */
			{17614,41,1}, /* core3 return_Stack0 bit34 */
			{19534,41,1}, /* core3 return_Stack0 bit35 */
			{17620,41,1}, /* core3 return_Stack0 bit36 */
			{17619,41,1}, /* core3 return_Stack0 bit37 */
			{17618,41,1}, /* core3 return_Stack0 bit38 */
			{17688,41,1}, /* core3 return_Stack0 bit39 */
			{19533,41,1}, /* core3 return_Stack0 bit40 */
			{17687,41,1}, /* core3 return_Stack0 bit41 */
			{17617,41,1}, /* core3 return_Stack0 bit42 */
			{14996,41,1}, /* core3 return_Stack0 bit43 */
			{17686,41,1}, /* core3 return_Stack0 bit44 */
			{17685,41,1}, /* core3 return_Stack0 bit45 */
			{14935,41,1}, /* core3 return_Stack0 bit46 */
			{17613,41,1}, /* core3 return_Stack0 bit47 */
			{17693,41,1}, /* core3 return_Stack0 bit48 */
			{    0, 0,2}, /* core3 return_Stack0 bit49 */
			{    0, 0,2}, /* core3 return_Stack0 bit50 */
			{    0, 0,2}, /* core3 return_Stack0 bit51 */
			{    0, 0,2}, /* core3 return_Stack0 bit52 */
			{    0, 0,2}, /* core3 return_Stack0 bit53 */
			{    0, 0,2}, /* core3 return_Stack0 bit54 */
			{    0, 0,2}, /* core3 return_Stack0 bit55 */
			{    0, 0,2}, /* core3 return_Stack0 bit56 */
			{    0, 0,2}, /* core3 return_Stack0 bit57 */
			{    0, 0,2}, /* core3 return_Stack0 bit58 */
			{    0, 0,2}, /* core3 return_Stack0 bit59 */
			{    0, 0,2}, /* core3 return_Stack0 bit60 */
			{    0, 0,2}, /* core3 return_Stack0 bit61 */
			{    0, 0,2}, /* core3 return_Stack0 bit62 */
			{    0, 0,2}, /* core3 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{17692,41,1}, /* core3 return_Stack1 bit0 */
			{24874,41,1}, /* core3 return_Stack1 bit1 */
			{21980,41,1}, /* core3 return_Stack1 bit2 */
			{24873,41,1}, /* core3 return_Stack1 bit3 */
			{24872,41,1}, /* core3 return_Stack1 bit4 */
			{14984,41,1}, /* core3 return_Stack1 bit5 */
			{24871,41,1}, /* core3 return_Stack1 bit6 */
			{19240,41,1}, /* core3 return_Stack1 bit7 */
			{21979,41,1}, /* core3 return_Stack1 bit8 */
			{19238,41,1}, /* core3 return_Stack1 bit9 */
			{19239,41,1}, /* core3 return_Stack1 bit10 */
			{21978,41,1}, /* core3 return_Stack1 bit11 */
			{21977,41,1}, /* core3 return_Stack1 bit12 */
			{14985,41,1}, /* core3 return_Stack1 bit13 */
			{17691,41,1}, /* core3 return_Stack1 bit14 */
			{19237,41,1}, /* core3 return_Stack1 bit15 */
			{17604,41,1}, /* core3 return_Stack1 bit16 */
			{17603,41,1}, /* core3 return_Stack1 bit17 */
			{19522,41,1}, /* core3 return_Stack1 bit18 */
			{17602,41,1}, /* core3 return_Stack1 bit19 */
			{14976,41,1}, /* core3 return_Stack1 bit20 */
			{17601,41,1}, /* core3 return_Stack1 bit21 */
			{19521,41,1}, /* core3 return_Stack1 bit22 */
			{17690,41,1}, /* core3 return_Stack1 bit23 */
			{19498,41,1}, /* core3 return_Stack1 bit24 */
			{17612,41,1}, /* core3 return_Stack1 bit25 */
			{17664,41,1}, /* core3 return_Stack1 bit26 */
			{17611,41,1}, /* core3 return_Stack1 bit27 */
			{19497,41,1}, /* core3 return_Stack1 bit28 */
			{17610,41,1}, /* core3 return_Stack1 bit29 */
			{17663,41,1}, /* core3 return_Stack1 bit30 */
			{14934,41,1}, /* core3 return_Stack1 bit31 */
			{17609,41,1}, /* core3 return_Stack1 bit32 */
			{17662,41,1}, /* core3 return_Stack1 bit33 */
			{19502,41,1}, /* core3 return_Stack1 bit34 */
			{14092,41,1}, /* core3 return_Stack1 bit35 */
			{17624,41,1}, /* core3 return_Stack1 bit36 */
			{17623,41,1}, /* core3 return_Stack1 bit37 */
			{17622,41,1}, /* core3 return_Stack1 bit38 */
			{17676,41,1}, /* core3 return_Stack1 bit39 */
			{17675,41,1}, /* core3 return_Stack1 bit40 */
			{17674,41,1}, /* core3 return_Stack1 bit41 */
			{17673,41,1}, /* core3 return_Stack1 bit42 */
			{17621,41,1}, /* core3 return_Stack1 bit43 */
			{19280,41,1}, /* core3 return_Stack1 bit44 */
			{19279,41,1}, /* core3 return_Stack1 bit45 */
			{17661,41,1}, /* core3 return_Stack1 bit46 */
			{19501,41,1}, /* core3 return_Stack1 bit47 */
			{17689,41,1}, /* core3 return_Stack1 bit48 */
			{    0, 0,2}, /* core3 return_Stack1 bit49 */
			{    0, 0,2}, /* core3 return_Stack1 bit50 */
			{    0, 0,2}, /* core3 return_Stack1 bit51 */
			{    0, 0,2}, /* core3 return_Stack1 bit52 */
			{    0, 0,2}, /* core3 return_Stack1 bit53 */
			{    0, 0,2}, /* core3 return_Stack1 bit54 */
			{    0, 0,2}, /* core3 return_Stack1 bit55 */
			{    0, 0,2}, /* core3 return_Stack1 bit56 */
			{    0, 0,2}, /* core3 return_Stack1 bit57 */
			{    0, 0,2}, /* core3 return_Stack1 bit58 */
			{    0, 0,2}, /* core3 return_Stack1 bit59 */
			{    0, 0,2}, /* core3 return_Stack1 bit60 */
			{    0, 0,2}, /* core3 return_Stack1 bit61 */
			{    0, 0,2}, /* core3 return_Stack1 bit62 */
			{    0, 0,2}, /* core3 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{17700,41,1}, /* core3 return_Stack2 bit0 */
			{17699,41,1}, /* core3 return_Stack2 bit1 */
			{14901,41,1}, /* core3 return_Stack2 bit2 */
			{14933,41,1}, /* core3 return_Stack2 bit3 */
			{19264,41,1}, /* core3 return_Stack2 bit4 */
			{19236,41,1}, /* core3 return_Stack2 bit5 */
			{19263,41,1}, /* core3 return_Stack2 bit6 */
			{14907,41,1}, /* core3 return_Stack2 bit7 */
			{19228,41,1}, /* core3 return_Stack2 bit8 */
			{14902,41,1}, /* core3 return_Stack2 bit9 */
			{19235,41,1}, /* core3 return_Stack2 bit10 */
			{14904,41,1}, /* core3 return_Stack2 bit11 */
			{19227,41,1}, /* core3 return_Stack2 bit12 */
			{14915,41,1}, /* core3 return_Stack2 bit13 */
			{17698,41,1}, /* core3 return_Stack2 bit14 */
			{14905,41,1}, /* core3 return_Stack2 bit15 */
			{14916,41,1}, /* core3 return_Stack2 bit16 */
			{14914,41,1}, /* core3 return_Stack2 bit17 */
			{19276,41,1}, /* core3 return_Stack2 bit18 */
			{19275,41,1}, /* core3 return_Stack2 bit19 */
			{19274,41,1}, /* core3 return_Stack2 bit20 */
			{14981,41,1}, /* core3 return_Stack2 bit21 */
			{19273,41,1}, /* core3 return_Stack2 bit22 */
			{14982,41,1}, /* core3 return_Stack2 bit23 */
			{19362,41,1}, /* core3 return_Stack2 bit24 */
			{19361,41,1}, /* core3 return_Stack2 bit25 */
			{17660,41,1}, /* core3 return_Stack2 bit26 */
			{19492,41,1}, /* core3 return_Stack2 bit27 */
			{17656,41,1}, /* core3 return_Stack2 bit28 */
			{19491,41,1}, /* core3 return_Stack2 bit29 */
			{17655,41,1}, /* core3 return_Stack2 bit30 */
			{17654,41,1}, /* core3 return_Stack2 bit31 */
			{17653,41,1}, /* core3 return_Stack2 bit32 */
			{17659,41,1}, /* core3 return_Stack2 bit33 */
			{14993,41,1}, /* core3 return_Stack2 bit34 */
			{19496,41,1}, /* core3 return_Stack2 bit35 */
			{19494,41,1}, /* core3 return_Stack2 bit36 */
			{14088,41,1}, /* core3 return_Stack2 bit37 */
			{19493,41,1}, /* core3 return_Stack2 bit38 */
			{17672,41,1}, /* core3 return_Stack2 bit39 */
			{19495,41,1}, /* core3 return_Stack2 bit40 */
			{17671,41,1}, /* core3 return_Stack2 bit41 */
			{14091,41,1}, /* core3 return_Stack2 bit42 */
			{17670,41,1}, /* core3 return_Stack2 bit43 */
			{17669,41,1}, /* core3 return_Stack2 bit44 */
			{19859,41,1}, /* core3 return_Stack2 bit45 */
			{17658,41,1}, /* core3 return_Stack2 bit46 */
			{17657,41,1}, /* core3 return_Stack2 bit47 */
			{17697,41,1}, /* core3 return_Stack2 bit48 */
			{    0, 0,2}, /* core3 return_Stack2 bit49 */
			{    0, 0,2}, /* core3 return_Stack2 bit50 */
			{    0, 0,2}, /* core3 return_Stack2 bit51 */
			{    0, 0,2}, /* core3 return_Stack2 bit52 */
			{    0, 0,2}, /* core3 return_Stack2 bit53 */
			{    0, 0,2}, /* core3 return_Stack2 bit54 */
			{    0, 0,2}, /* core3 return_Stack2 bit55 */
			{    0, 0,2}, /* core3 return_Stack2 bit56 */
			{    0, 0,2}, /* core3 return_Stack2 bit57 */
			{    0, 0,2}, /* core3 return_Stack2 bit58 */
			{    0, 0,2}, /* core3 return_Stack2 bit59 */
			{    0, 0,2}, /* core3 return_Stack2 bit60 */
			{    0, 0,2}, /* core3 return_Stack2 bit61 */
			{    0, 0,2}, /* core3 return_Stack2 bit62 */
			{    0, 0,2}, /* core3 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{19520,41,1}, /* core3 return_Stack3 bit0 */
			{27665,41,1}, /* core3 return_Stack3 bit1 */
			{21968,41,1}, /* core3 return_Stack3 bit2 */
			{19248,41,1}, /* core3 return_Stack3 bit3 */
			{19247,41,1}, /* core3 return_Stack3 bit4 */
			{21967,41,1}, /* core3 return_Stack3 bit5 */
			{21966,41,1}, /* core3 return_Stack3 bit6 */
			{27683,41,1}, /* core3 return_Stack3 bit7 */
			{19244,41,1}, /* core3 return_Stack3 bit8 */
			{19246,41,1}, /* core3 return_Stack3 bit9 */
			{21965,41,1}, /* core3 return_Stack3 bit10 */
			{19243,41,1}, /* core3 return_Stack3 bit11 */
			{19245,41,1}, /* core3 return_Stack3 bit12 */
			{27685,41,1}, /* core3 return_Stack3 bit13 */
			{27684,41,1}, /* core3 return_Stack3 bit14 */
			{14913,41,1}, /* core3 return_Stack3 bit15 */
			{21964,41,1}, /* core3 return_Stack3 bit16 */
			{21963,41,1}, /* core3 return_Stack3 bit17 */
			{21962,41,1}, /* core3 return_Stack3 bit18 */
			{21961,41,1}, /* core3 return_Stack3 bit19 */
			{21948,41,1}, /* core3 return_Stack3 bit20 */
			{21947,41,1}, /* core3 return_Stack3 bit21 */
			{19519,41,1}, /* core3 return_Stack3 bit22 */
			{21946,41,1}, /* core3 return_Stack3 bit23 */
			{21984,41,1}, /* core3 return_Stack3 bit24 */
			{21983,41,1}, /* core3 return_Stack3 bit25 */
			{21996,41,1}, /* core3 return_Stack3 bit26 */
			{21982,41,1}, /* core3 return_Stack3 bit27 */
			{21995,41,1}, /* core3 return_Stack3 bit28 */
			{21981,41,1}, /* core3 return_Stack3 bit29 */
			{21994,41,1}, /* core3 return_Stack3 bit30 */
			{27675,41,1}, /* core3 return_Stack3 bit31 */
			{21993,41,1}, /* core3 return_Stack3 bit32 */
			{19512,41,1}, /* core3 return_Stack3 bit33 */
			{27676,41,1}, /* core3 return_Stack3 bit34 */
			{19482,41,1}, /* core3 return_Stack3 bit35 */
			{19486,41,1}, /* core3 return_Stack3 bit36 */
			{19481,41,1}, /* core3 return_Stack3 bit37 */
			{19480,41,1}, /* core3 return_Stack3 bit38 */
			{19485,41,1}, /* core3 return_Stack3 bit39 */
			{27674,41,1}, /* core3 return_Stack3 bit40 */
			{19479,41,1}, /* core3 return_Stack3 bit41 */
			{14093,41,1}, /* core3 return_Stack3 bit42 */
			{19857,41,1}, /* core3 return_Stack3 bit43 */
			{19856,41,1}, /* core3 return_Stack3 bit44 */
			{27664,41,1}, /* core3 return_Stack3 bit45 */
			{19511,41,1}, /* core3 return_Stack3 bit46 */
			{27677,41,1}, /* core3 return_Stack3 bit47 */
			{21945,41,1}, /* core3 return_Stack3 bit48 */
			{    0, 0,2}, /* core3 return_Stack3 bit49 */
			{    0, 0,2}, /* core3 return_Stack3 bit50 */
			{    0, 0,2}, /* core3 return_Stack3 bit51 */
			{    0, 0,2}, /* core3 return_Stack3 bit52 */
			{    0, 0,2}, /* core3 return_Stack3 bit53 */
			{    0, 0,2}, /* core3 return_Stack3 bit54 */
			{    0, 0,2}, /* core3 return_Stack3 bit55 */
			{    0, 0,2}, /* core3 return_Stack3 bit56 */
			{    0, 0,2}, /* core3 return_Stack3 bit57 */
			{    0, 0,2}, /* core3 return_Stack3 bit58 */
			{    0, 0,2}, /* core3 return_Stack3 bit59 */
			{    0, 0,2}, /* core3 return_Stack3 bit60 */
			{    0, 0,2}, /* core3 return_Stack3 bit61 */
			{    0, 0,2}, /* core3 return_Stack3 bit62 */
			{    0, 0,2}, /* core3 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{17704,41,1}, /* core3 return_Stack4 bit0 */
			{17703,41,1}, /* core3 return_Stack4 bit1 */
			{19230,41,1}, /* core3 return_Stack4 bit2 */
			{14986,41,1}, /* core3 return_Stack4 bit3 */
			{14983,41,1}, /* core3 return_Stack4 bit4 */
			{19242,41,1}, /* core3 return_Stack4 bit5 */
			{14987,41,1}, /* core3 return_Stack4 bit6 */
			{19232,41,1}, /* core3 return_Stack4 bit7 */
			{19241,41,1}, /* core3 return_Stack4 bit8 */
			{19229,41,1}, /* core3 return_Stack4 bit9 */
			{14906,41,1}, /* core3 return_Stack4 bit10 */
			{14903,41,1}, /* core3 return_Stack4 bit11 */
			{19231,41,1}, /* core3 return_Stack4 bit12 */
			{19234,41,1}, /* core3 return_Stack4 bit13 */
			{14917,41,1}, /* core3 return_Stack4 bit14 */
			{19233,41,1}, /* core3 return_Stack4 bit15 */
			{17608,41,1}, /* core3 return_Stack4 bit16 */
			{17607,41,1}, /* core3 return_Stack4 bit17 */
			{19278,41,1}, /* core3 return_Stack4 bit18 */
			{15002,41,1}, /* core3 return_Stack4 bit19 */
			{19277,41,1}, /* core3 return_Stack4 bit20 */
			{17606,41,1}, /* core3 return_Stack4 bit21 */
			{17605,41,1}, /* core3 return_Stack4 bit22 */
			{17702,41,1}, /* core3 return_Stack4 bit23 */
			{19360,41,1}, /* core3 return_Stack4 bit24 */
			{19359,41,1}, /* core3 return_Stack4 bit25 */
			{15001,41,1}, /* core3 return_Stack4 bit26 */
			{19536,41,1}, /* core3 return_Stack4 bit27 */
			{17648,41,1}, /* core3 return_Stack4 bit28 */
			{19535,41,1}, /* core3 return_Stack4 bit29 */
			{17647,41,1}, /* core3 return_Stack4 bit30 */
			{17646,41,1}, /* core3 return_Stack4 bit31 */
			{17645,41,1}, /* core3 return_Stack4 bit32 */
			{17652,41,1}, /* core3 return_Stack4 bit33 */
			{17651,41,1}, /* core3 return_Stack4 bit34 */
			{19532,41,1}, /* core3 return_Stack4 bit35 */
			{14087,41,1}, /* core3 return_Stack4 bit36 */
			{19530,41,1}, /* core3 return_Stack4 bit37 */
			{19869,41,1}, /* core3 return_Stack4 bit38 */
			{17708,41,1}, /* core3 return_Stack4 bit39 */
			{19531,41,1}, /* core3 return_Stack4 bit40 */
			{17707,41,1}, /* core3 return_Stack4 bit41 */
			{19529,41,1}, /* core3 return_Stack4 bit42 */
			{19862,41,1}, /* core3 return_Stack4 bit43 */
			{17706,41,1}, /* core3 return_Stack4 bit44 */
			{17705,41,1}, /* core3 return_Stack4 bit45 */
			{17650,41,1}, /* core3 return_Stack4 bit46 */
			{17649,41,1}, /* core3 return_Stack4 bit47 */
			{17701,41,1}, /* core3 return_Stack4 bit48 */
			{    0, 0,2}, /* core3 return_Stack4 bit49 */
			{    0, 0,2}, /* core3 return_Stack4 bit50 */
			{    0, 0,2}, /* core3 return_Stack4 bit51 */
			{    0, 0,2}, /* core3 return_Stack4 bit52 */
			{    0, 0,2}, /* core3 return_Stack4 bit53 */
			{    0, 0,2}, /* core3 return_Stack4 bit54 */
			{    0, 0,2}, /* core3 return_Stack4 bit55 */
			{    0, 0,2}, /* core3 return_Stack4 bit56 */
			{    0, 0,2}, /* core3 return_Stack4 bit57 */
			{    0, 0,2}, /* core3 return_Stack4 bit58 */
			{    0, 0,2}, /* core3 return_Stack4 bit59 */
			{    0, 0,2}, /* core3 return_Stack4 bit60 */
			{    0, 0,2}, /* core3 return_Stack4 bit61 */
			{    0, 0,2}, /* core3 return_Stack4 bit62 */
			{    0, 0,2}, /* core3 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{27686,41,1}, /* core3 return_Stack5 bit0 */
			{14936,41,1}, /* core3 return_Stack5 bit1 */
			{19224,41,1}, /* core3 return_Stack5 bit2 */
			{21976,41,1}, /* core3 return_Stack5 bit3 */
			{19254,41,1}, /* core3 return_Stack5 bit4 */
			{19253,41,1}, /* core3 return_Stack5 bit5 */
			{14918,41,1}, /* core3 return_Stack5 bit6 */
			{21975,41,1}, /* core3 return_Stack5 bit7 */
			{21974,41,1}, /* core3 return_Stack5 bit8 */
			{19226,41,1}, /* core3 return_Stack5 bit9 */
			{21973,41,1}, /* core3 return_Stack5 bit10 */
			{19225,41,1}, /* core3 return_Stack5 bit11 */
			{19223,41,1}, /* core3 return_Stack5 bit12 */
			{14975,41,1}, /* core3 return_Stack5 bit13 */
			{19262,41,1}, /* core3 return_Stack5 bit14 */
			{14910,41,1}, /* core3 return_Stack5 bit15 */
			{19250,41,1}, /* core3 return_Stack5 bit16 */
			{19261,41,1}, /* core3 return_Stack5 bit17 */
			{21952,41,1}, /* core3 return_Stack5 bit18 */
			{21951,41,1}, /* core3 return_Stack5 bit19 */
			{21950,41,1}, /* core3 return_Stack5 bit20 */
			{19249,41,1}, /* core3 return_Stack5 bit21 */
			{21949,41,1}, /* core3 return_Stack5 bit22 */
			{19514,41,1}, /* core3 return_Stack5 bit23 */
			{19488,41,1}, /* core3 return_Stack5 bit24 */
			{19487,41,1}, /* core3 return_Stack5 bit25 */
			{17680,41,1}, /* core3 return_Stack5 bit26 */
			{17679,41,1}, /* core3 return_Stack5 bit27 */
			{17678,41,1}, /* core3 return_Stack5 bit28 */
			{19490,41,1}, /* core3 return_Stack5 bit29 */
			{17677,41,1}, /* core3 return_Stack5 bit30 */
			{19526,41,1}, /* core3 return_Stack5 bit31 */
			{27663,41,1}, /* core3 return_Stack5 bit32 */
			{27668,41,1}, /* core3 return_Stack5 bit33 */
			{19489,41,1}, /* core3 return_Stack5 bit34 */
			{19864,41,1}, /* core3 return_Stack5 bit35 */
			{17712,41,1}, /* core3 return_Stack5 bit36 */
			{17711,41,1}, /* core3 return_Stack5 bit37 */
			{17710,41,1}, /* core3 return_Stack5 bit38 */
			{14094,41,1}, /* core3 return_Stack5 bit39 */
			{17684,41,1}, /* core3 return_Stack5 bit40 */
			{19858,41,1}, /* core3 return_Stack5 bit41 */
			{17683,41,1}, /* core3 return_Stack5 bit42 */
			{17709,41,1}, /* core3 return_Stack5 bit43 */
			{17682,41,1}, /* core3 return_Stack5 bit44 */
			{17681,41,1}, /* core3 return_Stack5 bit45 */
			{27669,41,1}, /* core3 return_Stack5 bit46 */
			{19525,41,1}, /* core3 return_Stack5 bit47 */
			{19513,41,1}, /* core3 return_Stack5 bit48 */
			{    0, 0,2}, /* core3 return_Stack5 bit49 */
			{    0, 0,2}, /* core3 return_Stack5 bit50 */
			{    0, 0,2}, /* core3 return_Stack5 bit51 */
			{    0, 0,2}, /* core3 return_Stack5 bit52 */
			{    0, 0,2}, /* core3 return_Stack5 bit53 */
			{    0, 0,2}, /* core3 return_Stack5 bit54 */
			{    0, 0,2}, /* core3 return_Stack5 bit55 */
			{    0, 0,2}, /* core3 return_Stack5 bit56 */
			{    0, 0,2}, /* core3 return_Stack5 bit57 */
			{    0, 0,2}, /* core3 return_Stack5 bit58 */
			{    0, 0,2}, /* core3 return_Stack5 bit59 */
			{    0, 0,2}, /* core3 return_Stack5 bit60 */
			{    0, 0,2}, /* core3 return_Stack5 bit61 */
			{    0, 0,2}, /* core3 return_Stack5 bit62 */
			{    0, 0,2}, /* core3 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{14977,41,1}, /* core3 return_Stack6 bit0 */
			{14979,41,1}, /* core3 return_Stack6 bit1 */
			{24870,41,1}, /* core3 return_Stack6 bit2 */
			{14927,41,1}, /* core3 return_Stack6 bit3 */
			{17354,41,1}, /* core3 return_Stack6 bit4 */
			{17353,41,1}, /* core3 return_Stack6 bit5 */
			{24869,41,1}, /* core3 return_Stack6 bit6 */
			{19222,41,1}, /* core3 return_Stack6 bit7 */
			{24868,41,1}, /* core3 return_Stack6 bit8 */
			{14908,41,1}, /* core3 return_Stack6 bit9 */
			{19221,41,1}, /* core3 return_Stack6 bit10 */
			{24867,41,1}, /* core3 return_Stack6 bit11 */
			{14909,41,1}, /* core3 return_Stack6 bit12 */
			{14926,41,1}, /* core3 return_Stack6 bit13 */
			{17600,41,1}, /* core3 return_Stack6 bit14 */
			{14912,41,1}, /* core3 return_Stack6 bit15 */
			{19260,41,1}, /* core3 return_Stack6 bit16 */
			{17599,41,1}, /* core3 return_Stack6 bit17 */
			{17598,41,1}, /* core3 return_Stack6 bit18 */
			{19259,41,1}, /* core3 return_Stack6 bit19 */
			{19272,41,1}, /* core3 return_Stack6 bit20 */
			{17597,41,1}, /* core3 return_Stack6 bit21 */
			{19271,41,1}, /* core3 return_Stack6 bit22 */
			{14980,41,1}, /* core3 return_Stack6 bit23 */
			{14991,41,1}, /* core3 return_Stack6 bit24 */
			{17668,41,1}, /* core3 return_Stack6 bit25 */
			{19508,41,1}, /* core3 return_Stack6 bit26 */
			{19504,41,1}, /* core3 return_Stack6 bit27 */
			{19503,41,1}, /* core3 return_Stack6 bit28 */
			{14992,41,1}, /* core3 return_Stack6 bit29 */
			{17667,41,1}, /* core3 return_Stack6 bit30 */
			{17666,41,1}, /* core3 return_Stack6 bit31 */
			{17665,41,1}, /* core3 return_Stack6 bit32 */
			{19500,41,1}, /* core3 return_Stack6 bit33 */
			{14089,41,1}, /* core3 return_Stack6 bit34 */
			{19868,41,1}, /* core3 return_Stack6 bit35 */
			{19476,41,1}, /* core3 return_Stack6 bit36 */
			{19475,41,1}, /* core3 return_Stack6 bit37 */
			{19478,41,1}, /* core3 return_Stack6 bit38 */
			{19524,41,1}, /* core3 return_Stack6 bit39 */
			{19477,41,1}, /* core3 return_Stack6 bit40 */
			{19506,41,1}, /* core3 return_Stack6 bit41 */
			{19865,41,1}, /* core3 return_Stack6 bit42 */
			{19505,41,1}, /* core3 return_Stack6 bit43 */
			{19863,41,1}, /* core3 return_Stack6 bit44 */
			{19523,41,1}, /* core3 return_Stack6 bit45 */
			{19507,41,1}, /* core3 return_Stack6 bit46 */
			{19499,41,1}, /* core3 return_Stack6 bit47 */
			{14978,41,1}, /* core3 return_Stack6 bit48 */
			{    0, 0,2}, /* core3 return_Stack6 bit49 */
			{    0, 0,2}, /* core3 return_Stack6 bit50 */
			{    0, 0,2}, /* core3 return_Stack6 bit51 */
			{    0, 0,2}, /* core3 return_Stack6 bit52 */
			{    0, 0,2}, /* core3 return_Stack6 bit53 */
			{    0, 0,2}, /* core3 return_Stack6 bit54 */
			{    0, 0,2}, /* core3 return_Stack6 bit55 */
			{    0, 0,2}, /* core3 return_Stack6 bit56 */
			{    0, 0,2}, /* core3 return_Stack6 bit57 */
			{    0, 0,2}, /* core3 return_Stack6 bit58 */
			{    0, 0,2}, /* core3 return_Stack6 bit59 */
			{    0, 0,2}, /* core3 return_Stack6 bit60 */
			{    0, 0,2}, /* core3 return_Stack6 bit61 */
			{    0, 0,2}, /* core3 return_Stack6 bit62 */
			{    0, 0,2}, /* core3 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{21956,41,1}, /* core3 return_Stack7 bit0 */
			{21960,41,1}, /* core3 return_Stack7 bit1 */
			{21972,41,1}, /* core3 return_Stack7 bit2 */
			{19256,41,1}, /* core3 return_Stack7 bit3 */
			{19258,41,1}, /* core3 return_Stack7 bit4 */
			{19257,41,1}, /* core3 return_Stack7 bit5 */
			{27678,41,1}, /* core3 return_Stack7 bit6 */
			{27679,41,1}, /* core3 return_Stack7 bit7 */
			{19255,41,1}, /* core3 return_Stack7 bit8 */
			{21971,41,1}, /* core3 return_Stack7 bit9 */
			{21970,41,1}, /* core3 return_Stack7 bit10 */
			{27680,41,1}, /* core3 return_Stack7 bit11 */
			{21969,41,1}, /* core3 return_Stack7 bit12 */
			{21959,41,1}, /* core3 return_Stack7 bit13 */
			{21958,41,1}, /* core3 return_Stack7 bit14 */
			{21957,41,1}, /* core3 return_Stack7 bit15 */
			{27682,41,1}, /* core3 return_Stack7 bit16 */
			{27681,41,1}, /* core3 return_Stack7 bit17 */
			{21955,41,1}, /* core3 return_Stack7 bit18 */
			{21954,41,1}, /* core3 return_Stack7 bit19 */
			{19518,41,1}, /* core3 return_Stack7 bit20 */
			{21953,41,1}, /* core3 return_Stack7 bit21 */
			{19516,41,1}, /* core3 return_Stack7 bit22 */
			{19515,41,1}, /* core3 return_Stack7 bit23 */
			{21992,41,1}, /* core3 return_Stack7 bit24 */
			{19528,41,1}, /* core3 return_Stack7 bit25 */
			{21988,41,1}, /* core3 return_Stack7 bit26 */
			{21991,41,1}, /* core3 return_Stack7 bit27 */
			{21990,41,1}, /* core3 return_Stack7 bit28 */
			{19484,41,1}, /* core3 return_Stack7 bit29 */
			{21989,41,1}, /* core3 return_Stack7 bit30 */
			{21987,41,1}, /* core3 return_Stack7 bit31 */
			{21986,41,1}, /* core3 return_Stack7 bit32 */
			{21985,41,1}, /* core3 return_Stack7 bit33 */
			{19483,41,1}, /* core3 return_Stack7 bit34 */
			{14090,41,1}, /* core3 return_Stack7 bit35 */
			{14097,41,1}, /* core3 return_Stack7 bit36 */
			{19867,41,1}, /* core3 return_Stack7 bit37 */
			{27673,41,1}, /* core3 return_Stack7 bit38 */
			{14095,41,1}, /* core3 return_Stack7 bit39 */
			{19861,41,1}, /* core3 return_Stack7 bit40 */
			{27672,41,1}, /* core3 return_Stack7 bit41 */
			{19866,41,1}, /* core3 return_Stack7 bit42 */
			{14096,41,1}, /* core3 return_Stack7 bit43 */
			{19860,41,1}, /* core3 return_Stack7 bit44 */
			{27671,41,1}, /* core3 return_Stack7 bit45 */
			{27670,41,1}, /* core3 return_Stack7 bit46 */
			{19527,41,1}, /* core3 return_Stack7 bit47 */
			{19517,41,1}, /* core3 return_Stack7 bit48 */
			{    0, 0,2}, /* core3 return_Stack7 bit49 */
			{    0, 0,2}, /* core3 return_Stack7 bit50 */
			{    0, 0,2}, /* core3 return_Stack7 bit51 */
			{    0, 0,2}, /* core3 return_Stack7 bit52 */
			{    0, 0,2}, /* core3 return_Stack7 bit53 */
			{    0, 0,2}, /* core3 return_Stack7 bit54 */
			{    0, 0,2}, /* core3 return_Stack7 bit55 */
			{    0, 0,2}, /* core3 return_Stack7 bit56 */
			{    0, 0,2}, /* core3 return_Stack7 bit57 */
			{    0, 0,2}, /* core3 return_Stack7 bit58 */
			{    0, 0,2}, /* core3 return_Stack7 bit59 */
			{    0, 0,2}, /* core3 return_Stack7 bit60 */
			{    0, 0,2}, /* core3 return_Stack7 bit61 */
			{    0, 0,2}, /* core3 return_Stack7 bit62 */
			{    0, 0,2}, /* core3 return_Stack7 bit63 */
			}},
			.ECC_err0status_v = {{
			{37289,41,1}, /* core3 ECC_err0status_v bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_v bit63 */
			}},
			.ECC_err0status_ue = {{
			{37575,41,1}, /* core3 ECC_err0status_ue bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_ue bit63 */
			}},
			.ECC_err0status_er = {{
			{37576,41,1}, /* core3 ECC_err0status_er bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_er bit63 */
			}},
			.ECC_err0status_of = {{
			{31882,41,1}, /* core3 ECC_err0status_of bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_of bit63 */
			}},
			.ECC_err0status_mv = {{
			{37291,41,1}, /* core3 ECC_err0status_mv bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_mv bit63 */
			}},
			.ECC_err0status_ce = {{
			{29902,41,1}, /* core3 ECC_err0status_ce bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_ce bit63 */
			}},
			.ECC_err0status_de = {{
			{31883,41,1}, /* core3 ECC_err0status_de bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_de bit63 */
			}},
			.ECC_err0status_pn = {{
			{37290,41,1}, /* core3 ECC_err0status_pn bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_pn bit63 */
			}},
			.ECC_err0status_ierr = {{
			{37292,41,1}, /* core3 ECC_err0status_ierr bit0 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit1 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit2 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit3 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_ierr bit63 */
			}},
			.ECC_err0status_serr = {{
			{37570,41,1}, /* core3 ECC_err0status_serr bit0 */
			{37574,41,1}, /* core3 ECC_err0status_serr bit1 */
			{37569,41,1}, /* core3 ECC_err0status_serr bit2 */
			{37573,41,1}, /* core3 ECC_err0status_serr bit3 */
			{31828,41,1}, /* core3 ECC_err0status_serr bit4 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit5 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit6 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit7 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit8 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit9 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit10 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit11 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit12 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit13 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit14 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit15 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit16 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit17 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit18 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit19 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit20 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit21 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit22 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit23 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit24 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit25 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit26 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit27 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit28 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit29 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit30 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit31 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit32 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit33 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit34 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit35 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit36 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit37 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit38 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit39 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit40 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit41 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit42 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit43 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit44 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit45 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit46 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit47 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit48 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit49 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit50 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit51 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit52 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit53 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit54 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit55 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit56 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit57 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit58 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit59 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit60 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit61 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit62 */
			{    0, 0,2}, /* core3 ECC_err0status_serr bit63 */
			}},
			.ECC_err0misc_other_err_cnt_overflow = {{
			{39790,41,1}, /* core3 ECC_err0misc_other_err_cnt_overflow bit0 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit1 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit2 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit3 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit4 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit5 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit6 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit7 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit8 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit9 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit10 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit11 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit12 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit13 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit14 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit15 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit16 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit17 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit18 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit19 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit20 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit21 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit22 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit23 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit24 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit25 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit26 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit27 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit28 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit29 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit30 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit31 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit32 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit33 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit34 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit35 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit36 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit37 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit38 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit39 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit40 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit41 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit42 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit43 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit44 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit45 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit46 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit47 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit48 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit49 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit50 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit51 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit52 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit53 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit54 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit55 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit56 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit57 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit58 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit59 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit60 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit61 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit62 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt_overflow bit63 */
			}},
			.ECC_err0misc_other_err_cnt = {{
			{34012,41,1}, /* core3 ECC_err0misc_other_err_cnt bit0 */
			{29803,41,1}, /* core3 ECC_err0misc_other_err_cnt bit1 */
			{34016,41,1}, /* core3 ECC_err0misc_other_err_cnt bit2 */
			{34015,41,1}, /* core3 ECC_err0misc_other_err_cnt bit3 */
			{34014,41,1}, /* core3 ECC_err0misc_other_err_cnt bit4 */
			{34013,41,1}, /* core3 ECC_err0misc_other_err_cnt bit5 */
			{34011,41,1}, /* core3 ECC_err0misc_other_err_cnt bit6 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit7 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit8 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit9 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit10 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit11 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit12 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit13 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit14 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit15 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit16 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit17 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit18 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit19 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit20 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit21 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit22 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit23 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit24 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit25 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit26 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit27 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit28 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit29 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit30 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit31 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit32 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit33 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit34 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit35 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit36 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit37 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit38 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit39 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit40 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit41 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit42 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit43 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit44 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit45 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit46 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit47 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit48 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit49 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit50 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit51 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit52 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit53 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit54 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit55 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit56 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit57 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit58 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit59 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit60 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit61 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit62 */
			{    0, 0,2}, /* core3 ECC_err0misc_other_err_cnt bit63 */
			}},
			.ECC_err0misc_repeat_err_overflow = {{
			{29804,41,1}, /* core3 ECC_err0misc_repeat_err_overflow bit0 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit1 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit2 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit3 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit4 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit5 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit6 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit7 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit8 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit9 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit10 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit11 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit12 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit13 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit14 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit15 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit16 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit17 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit18 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit19 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit20 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit21 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit22 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit23 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit24 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit25 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit26 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit27 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit28 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit29 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit30 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit31 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit32 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit33 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit34 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit35 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit36 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit37 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit38 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit39 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit40 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit41 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit42 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit43 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit44 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit45 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit46 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit47 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit48 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit49 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit50 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit51 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit52 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit53 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit54 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit55 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit56 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit57 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit58 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit59 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit60 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit61 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit62 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_overflow bit63 */
			}},
			.ECC_err0misc_repeat_err_cnt = {{
			{34010,41,1}, /* core3 ECC_err0misc_repeat_err_cnt bit0 */
			{39789,41,1}, /* core3 ECC_err0misc_repeat_err_cnt bit1 */
			{39788,41,1}, /* core3 ECC_err0misc_repeat_err_cnt bit2 */
			{39787,41,1}, /* core3 ECC_err0misc_repeat_err_cnt bit3 */
			{39786,41,1}, /* core3 ECC_err0misc_repeat_err_cnt bit4 */
			{39785,41,1}, /* core3 ECC_err0misc_repeat_err_cnt bit5 */
			{34009,41,1}, /* core3 ECC_err0misc_repeat_err_cnt bit6 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit7 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit8 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit9 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit10 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit11 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit12 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit13 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit14 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit15 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit16 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit17 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit18 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit19 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit20 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit21 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit22 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit23 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit24 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit25 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit26 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit27 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit28 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit29 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit30 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit31 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit32 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit33 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit34 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit35 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit36 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit37 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit38 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit39 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit40 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit41 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit42 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit43 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit44 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit45 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit46 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit47 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit48 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit49 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit50 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit51 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit52 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit53 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit54 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit55 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit56 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit57 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit58 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit59 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit60 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit61 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit62 */
			{    0, 0,2}, /* core3 ECC_err0misc_repeat_err_cnt bit63 */
			}},
			.ECC_err0misc_way = {{
			{43026,41,1}, /* core3 ECC_err0misc_way bit0 */
			{43025,41,1}, /* core3 ECC_err0misc_way bit1 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit2 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit3 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit4 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit5 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit6 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit7 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit8 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit9 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit10 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit11 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit12 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit13 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit14 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit15 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit16 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit17 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit18 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit19 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit20 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit21 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit22 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit23 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit24 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit25 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit26 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit27 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit28 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit29 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit30 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit31 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit32 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit33 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit34 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit35 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit36 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit37 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit38 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit39 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit40 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit41 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit42 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit43 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit44 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit45 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit46 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit47 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit48 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit49 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit50 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit51 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit52 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit53 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit54 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit55 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit56 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit57 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit58 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit59 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit60 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit61 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit62 */
			{    0, 0,2}, /* core3 ECC_err0misc_way bit63 */
			}},
			.ECC_err0misc_index = {{
			{37296,41,1}, /* core3 ECC_err0misc_index bit0 */
			{37754,41,1}, /* core3 ECC_err0misc_index bit1 */
			{31917,41,1}, /* core3 ECC_err0misc_index bit2 */
			{31916,41,1}, /* core3 ECC_err0misc_index bit3 */
			{43029,41,1}, /* core3 ECC_err0misc_index bit4 */
			{43028,41,1}, /* core3 ECC_err0misc_index bit5 */
			{43027,41,1}, /* core3 ECC_err0misc_index bit6 */
			{37753,41,1}, /* core3 ECC_err0misc_index bit7 */
			{43030,41,1}, /* core3 ECC_err0misc_index bit8 */
			{37295,41,1}, /* core3 ECC_err0misc_index bit9 */
			{37294,41,1}, /* core3 ECC_err0misc_index bit10 */
			{37293,41,1}, /* core3 ECC_err0misc_index bit11 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit12 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit13 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit14 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit15 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit16 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit17 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit18 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit19 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit20 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit21 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit22 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit23 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit24 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit25 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit26 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit27 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit28 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit29 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit30 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit31 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit32 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit33 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit34 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit35 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit36 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit37 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit38 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit39 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit40 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit41 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit42 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit43 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit44 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit45 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit46 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit47 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit48 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit49 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit50 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit51 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit52 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit53 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit54 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit55 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit56 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit57 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit58 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit59 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit60 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit61 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit62 */
			{    0, 0,2}, /* core3 ECC_err0misc_index bit63 */
			}},
			.ECC_err0misc_level_contain_error = {{
			{37571,41,1}, /* core3 ECC_err0misc_level_contain_error bit0 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit1 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit2 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit3 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit4 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit5 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit6 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit7 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit8 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit9 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit10 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit11 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit12 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit13 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit14 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit15 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit16 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit17 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit18 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit19 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit20 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit21 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit22 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit23 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit24 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit25 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit26 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit27 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit28 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit29 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit30 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit31 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit32 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit33 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit34 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit35 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit36 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit37 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit38 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit39 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit40 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit41 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit42 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit43 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit44 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit45 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit46 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit47 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit48 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit49 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit50 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit51 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit52 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit53 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit54 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit55 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit56 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit57 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit58 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit59 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit60 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit61 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit62 */
			{    0, 0,2}, /* core3 ECC_err0misc_level_contain_error bit63 */
			}},
			.ECC_err0misc_indicate_icache = {{
			{37572,41,1}, /* core3 ECC_err0misc_indicate_icache bit0 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit1 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit2 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit3 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit4 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit5 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit6 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit7 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit8 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit9 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit10 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit11 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit12 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit13 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit14 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit15 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit16 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit17 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit18 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit19 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit20 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit21 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit22 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit23 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit24 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit25 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit26 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit27 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit28 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit29 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit30 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit31 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit32 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit33 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit34 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit35 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit36 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit37 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit38 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit39 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit40 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit41 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit42 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit43 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit44 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit45 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit46 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit47 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit48 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit49 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit50 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit51 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit52 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit53 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit54 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit55 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit56 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit57 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit58 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit59 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit60 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit61 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit62 */
			{    0, 0,2}, /* core3 ECC_err0misc_indicate_icache bit63 */
			}},
			.ECC_err0ctrl_fault_handling_interrupt = {{
			{29905,41,1}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit0 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit1 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit2 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit3 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit4 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit5 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit6 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit7 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit8 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit9 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit10 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit11 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit12 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit13 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit14 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit15 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit16 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit17 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit18 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit19 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit20 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit21 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit22 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit23 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit24 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit25 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit26 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit27 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit28 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit29 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit30 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit31 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit32 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit33 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit34 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit35 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit36 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit37 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit38 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit39 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit40 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit41 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit42 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit43 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit44 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit45 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit46 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit47 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit48 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit49 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit50 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit51 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit52 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit53 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit54 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit55 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit56 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit57 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit58 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit59 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit60 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit61 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit62 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_interrupt bit63 */
			}},
			.ECC_err0ctrl_fault_handling_int_enable = {{
			{37512,41,1}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit0 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit1 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit2 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit3 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit4 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit5 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit6 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit7 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit8 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit9 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit10 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit11 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit12 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit13 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit14 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit15 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit16 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit17 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit18 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit19 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit20 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit21 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit22 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit23 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit24 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit25 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit26 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit27 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit28 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit29 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit30 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit31 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit32 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit33 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit34 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit35 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit36 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit37 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit38 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit39 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit40 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit41 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit42 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit43 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit44 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit45 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit46 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit47 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit48 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit49 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit50 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit51 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit52 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit53 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit54 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit55 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit56 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit57 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit58 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit59 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit60 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit61 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit62 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_fault_handling_int_enable bit63 */
			}},
			.ECC_err0ctrl_error_recovery_int_enable = {{
			{37511,41,1}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit0 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit1 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit2 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit3 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit4 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit5 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit6 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit7 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit8 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit9 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit10 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit11 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit12 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit13 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit14 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit15 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit16 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit17 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit18 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit19 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit20 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit21 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit22 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit23 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit24 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit25 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit26 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit27 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit28 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit29 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit30 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit31 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit32 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit33 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit34 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit35 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit36 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit37 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit38 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit39 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit40 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit41 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit42 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit43 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit44 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit45 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit46 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit47 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit48 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit49 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit50 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit51 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit52 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit53 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit54 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit55 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit56 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit57 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit58 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit59 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit60 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit61 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit62 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_recovery_int_enable bit63 */
			}},
			.ECC_err0ctrl_error_detect_correct_enable = {{
			{29904,41,1}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit0 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit1 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit2 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit3 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit4 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit5 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit6 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit7 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit8 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit9 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit10 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit11 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit12 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit13 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit14 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit15 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit16 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit17 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit18 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit19 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit20 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit21 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit22 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit23 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit24 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit25 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit26 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit27 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit28 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit29 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit30 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit31 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit32 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit33 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit34 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit35 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit36 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit37 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit38 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit39 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit40 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit41 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit42 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit43 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit44 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit45 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit46 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit47 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit48 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit49 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit50 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit51 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit52 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit53 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit54 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit55 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit56 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit57 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit58 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit59 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit60 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit61 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit62 */
			{    0, 0,2}, /* core3 ECC_err0ctrl_error_detect_correct_enable bit63 */
			}},
	},
}; 

struct big_core_spec big_core[] = {
	{		/* core 4 */ 
			.i0_pc = {{
			{  516,46,0}, /* core4 i0_pc bit0 */
			{  451,46,0}, /* core4 i0_pc bit1 */
			{  466,46,0}, /* core4 i0_pc bit2 */
			{  369,46,0}, /* core4 i0_pc bit3 */
			{  505,46,0}, /* core4 i0_pc bit4 */
			{  591,46,0}, /* core4 i0_pc bit5 */
			{  392,46,0}, /* core4 i0_pc bit6 */
			{  471,46,0}, /* core4 i0_pc bit7 */
			{  776,46,0}, /* core4 i0_pc bit8 */
			{  690,46,0}, /* core4 i0_pc bit9 */
			{  652,46,0}, /* core4 i0_pc bit10 */
			{  622,46,0}, /* core4 i0_pc bit11 */
			{  773,46,0}, /* core4 i0_pc bit12 */
			{  767,46,0}, /* core4 i0_pc bit13 */
			{  774,46,0}, /* core4 i0_pc bit14 */
			{  758,46,0}, /* core4 i0_pc bit15 */
			{  603,46,0}, /* core4 i0_pc bit16 */
			{  597,46,0}, /* core4 i0_pc bit17 */
			{  817,46,0}, /* core4 i0_pc bit18 */
			{  619,46,0}, /* core4 i0_pc bit19 */
			{  625,46,0}, /* core4 i0_pc bit20 */
			{  752,46,0}, /* core4 i0_pc bit21 */
			{  497,46,0}, /* core4 i0_pc bit22 */
			{  507,46,0}, /* core4 i0_pc bit23 */
			{  611,46,0}, /* core4 i0_pc bit24 */
			{  623,46,0}, /* core4 i0_pc bit25 */
			{  519,46,0}, /* core4 i0_pc bit26 */
			{  677,46,0}, /* core4 i0_pc bit27 */
			{  783,46,0}, /* core4 i0_pc bit28 */
			{  789,46,0}, /* core4 i0_pc bit29 */
			{  822,46,0}, /* core4 i0_pc bit30 */
			{  651,46,0}, /* core4 i0_pc bit31 */
			{  691,46,0}, /* core4 i0_pc bit32 */
			{  456,46,0}, /* core4 i0_pc bit33 */
			{  468,46,0}, /* core4 i0_pc bit34 */
			{  467,46,0}, /* core4 i0_pc bit35 */
			{  701,46,0}, /* core4 i0_pc bit36 */
			{  588,46,0}, /* core4 i0_pc bit37 */
			{  464,46,0}, /* core4 i0_pc bit38 */
			{  470,46,0}, /* core4 i0_pc bit39 */
			{  777,46,0}, /* core4 i0_pc bit40 */
			{  700,46,0}, /* core4 i0_pc bit41 */
			{  458,46,0}, /* core4 i0_pc bit42 */
			{  613,46,0}, /* core4 i0_pc bit43 */
			{  364,46,0}, /* core4 i0_pc bit44 */
			{  769,46,0}, /* core4 i0_pc bit45 */
			{  748,46,0}, /* core4 i0_pc bit46 */
			{  757,46,0}, /* core4 i0_pc bit47 */
			{  641,46,0}, /* core4 i0_pc bit48 */
			{  593,46,0}, /* core4 i0_pc bit49 */
			{  437,46,0}, /* core4 i0_pc bit50 */
			{  761,46,0}, /* core4 i0_pc bit51 */
			{  610,46,0}, /* core4 i0_pc bit52 */
			{  608,46,0}, /* core4 i0_pc bit53 */
			{  514,46,0}, /* core4 i0_pc bit54 */
			{  521,46,0}, /* core4 i0_pc bit55 */
			{  614,46,0}, /* core4 i0_pc bit56 */
			{  616,46,0}, /* core4 i0_pc bit57 */
			{  511,46,0}, /* core4 i0_pc bit58 */
			{  675,46,0}, /* core4 i0_pc bit59 */
			{  794,46,0}, /* core4 i0_pc bit60 */
			{  790,46,0}, /* core4 i0_pc bit61 */
			{  824,46,0}, /* core4 i0_pc bit62 */
			{  454,46,0}, /* core4 i0_pc bit63 */
			}},
			.sram_wr_ptr_0 = {{
			{25630,46,0}, /* core4 sram_wr_ptr_0 bit0 */
			{25632,46,0}, /* core4 sram_wr_ptr_0 bit1 */
			{25620,46,0}, /* core4 sram_wr_ptr_0 bit2 */
			{25625,46,0}, /* core4 sram_wr_ptr_0 bit3 */
			{25619,46,0}, /* core4 sram_wr_ptr_0 bit4 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit5 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit6 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit7 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit8 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit9 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit10 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit11 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit12 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit13 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit14 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit15 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit16 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit17 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit18 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit19 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit20 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit21 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit22 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit23 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit24 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit25 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit26 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit27 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit28 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit29 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit30 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit31 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit32 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit33 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit34 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit35 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit36 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit37 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit38 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit39 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit40 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit41 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit42 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit43 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit44 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit45 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit46 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit47 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit48 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit49 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit50 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit51 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit52 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit53 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit54 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit55 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit56 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit57 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit58 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit59 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit60 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit61 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit62 */
			{    0, 0,2}, /* core4 sram_wr_ptr_0 bit63 */
			}},
	},
	{		/* core 5 */ 
			.i0_pc = {{
			{  516,52,0}, /* core5 i0_pc bit0 */
			{  451,52,0}, /* core5 i0_pc bit1 */
			{  466,52,0}, /* core5 i0_pc bit2 */
			{  369,52,0}, /* core5 i0_pc bit3 */
			{  505,52,0}, /* core5 i0_pc bit4 */
			{  591,52,0}, /* core5 i0_pc bit5 */
			{  392,52,0}, /* core5 i0_pc bit6 */
			{  471,52,0}, /* core5 i0_pc bit7 */
			{  776,52,0}, /* core5 i0_pc bit8 */
			{  690,52,0}, /* core5 i0_pc bit9 */
			{  652,52,0}, /* core5 i0_pc bit10 */
			{  622,52,0}, /* core5 i0_pc bit11 */
			{  773,52,0}, /* core5 i0_pc bit12 */
			{  767,52,0}, /* core5 i0_pc bit13 */
			{  774,52,0}, /* core5 i0_pc bit14 */
			{  758,52,0}, /* core5 i0_pc bit15 */
			{  603,52,0}, /* core5 i0_pc bit16 */
			{  597,52,0}, /* core5 i0_pc bit17 */
			{  817,52,0}, /* core5 i0_pc bit18 */
			{  619,52,0}, /* core5 i0_pc bit19 */
			{  625,52,0}, /* core5 i0_pc bit20 */
			{  752,52,0}, /* core5 i0_pc bit21 */
			{  497,52,0}, /* core5 i0_pc bit22 */
			{  507,52,0}, /* core5 i0_pc bit23 */
			{  611,52,0}, /* core5 i0_pc bit24 */
			{  623,52,0}, /* core5 i0_pc bit25 */
			{  519,52,0}, /* core5 i0_pc bit26 */
			{  677,52,0}, /* core5 i0_pc bit27 */
			{  783,52,0}, /* core5 i0_pc bit28 */
			{  789,52,0}, /* core5 i0_pc bit29 */
			{  822,52,0}, /* core5 i0_pc bit30 */
			{  651,52,0}, /* core5 i0_pc bit31 */
			{  691,52,0}, /* core5 i0_pc bit32 */
			{  456,52,0}, /* core5 i0_pc bit33 */
			{  468,52,0}, /* core5 i0_pc bit34 */
			{  467,52,0}, /* core5 i0_pc bit35 */
			{  701,52,0}, /* core5 i0_pc bit36 */
			{  588,52,0}, /* core5 i0_pc bit37 */
			{  464,52,0}, /* core5 i0_pc bit38 */
			{  470,52,0}, /* core5 i0_pc bit39 */
			{  777,52,0}, /* core5 i0_pc bit40 */
			{  700,52,0}, /* core5 i0_pc bit41 */
			{  458,52,0}, /* core5 i0_pc bit42 */
			{  613,52,0}, /* core5 i0_pc bit43 */
			{  364,52,0}, /* core5 i0_pc bit44 */
			{  769,52,0}, /* core5 i0_pc bit45 */
			{  748,52,0}, /* core5 i0_pc bit46 */
			{  757,52,0}, /* core5 i0_pc bit47 */
			{  641,52,0}, /* core5 i0_pc bit48 */
			{  593,52,0}, /* core5 i0_pc bit49 */
			{  437,52,0}, /* core5 i0_pc bit50 */
			{  761,52,0}, /* core5 i0_pc bit51 */
			{  610,52,0}, /* core5 i0_pc bit52 */
			{  608,52,0}, /* core5 i0_pc bit53 */
			{  514,52,0}, /* core5 i0_pc bit54 */
			{  521,52,0}, /* core5 i0_pc bit55 */
			{  614,52,0}, /* core5 i0_pc bit56 */
			{  616,52,0}, /* core5 i0_pc bit57 */
			{  511,52,0}, /* core5 i0_pc bit58 */
			{  675,52,0}, /* core5 i0_pc bit59 */
			{  794,52,0}, /* core5 i0_pc bit60 */
			{  790,52,0}, /* core5 i0_pc bit61 */
			{  824,52,0}, /* core5 i0_pc bit62 */
			{  454,52,0}, /* core5 i0_pc bit63 */
			}},
			.sram_wr_ptr_0 = {{
			{25630,52,0}, /* core5 sram_wr_ptr_0 bit0 */
			{25632,52,0}, /* core5 sram_wr_ptr_0 bit1 */
			{25620,52,0}, /* core5 sram_wr_ptr_0 bit2 */
			{25625,52,0}, /* core5 sram_wr_ptr_0 bit3 */
			{25619,52,0}, /* core5 sram_wr_ptr_0 bit4 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit5 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit6 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit7 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit8 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit9 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit10 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit11 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit12 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit13 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit14 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit15 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit16 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit17 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit18 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit19 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit20 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit21 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit22 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit23 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit24 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit25 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit26 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit27 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit28 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit29 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit30 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit31 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit32 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit33 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit34 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit35 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit36 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit37 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit38 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit39 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit40 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit41 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit42 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit43 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit44 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit45 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit46 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit47 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit48 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit49 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit50 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit51 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit52 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit53 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit54 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit55 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit56 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit57 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit58 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit59 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit60 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit61 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit62 */
			{    0, 0,2}, /* core5 sram_wr_ptr_0 bit63 */
			}},
	},
	{		/* core 6 */ 
			.i0_pc = {{
			{  516,58,0}, /* core6 i0_pc bit0 */
			{  451,58,0}, /* core6 i0_pc bit1 */
			{  466,58,0}, /* core6 i0_pc bit2 */
			{  369,58,0}, /* core6 i0_pc bit3 */
			{  505,58,0}, /* core6 i0_pc bit4 */
			{  591,58,0}, /* core6 i0_pc bit5 */
			{  392,58,0}, /* core6 i0_pc bit6 */
			{  471,58,0}, /* core6 i0_pc bit7 */
			{  776,58,0}, /* core6 i0_pc bit8 */
			{  690,58,0}, /* core6 i0_pc bit9 */
			{  652,58,0}, /* core6 i0_pc bit10 */
			{  622,58,0}, /* core6 i0_pc bit11 */
			{  773,58,0}, /* core6 i0_pc bit12 */
			{  767,58,0}, /* core6 i0_pc bit13 */
			{  774,58,0}, /* core6 i0_pc bit14 */
			{  758,58,0}, /* core6 i0_pc bit15 */
			{  603,58,0}, /* core6 i0_pc bit16 */
			{  597,58,0}, /* core6 i0_pc bit17 */
			{  817,58,0}, /* core6 i0_pc bit18 */
			{  619,58,0}, /* core6 i0_pc bit19 */
			{  625,58,0}, /* core6 i0_pc bit20 */
			{  752,58,0}, /* core6 i0_pc bit21 */
			{  497,58,0}, /* core6 i0_pc bit22 */
			{  507,58,0}, /* core6 i0_pc bit23 */
			{  611,58,0}, /* core6 i0_pc bit24 */
			{  623,58,0}, /* core6 i0_pc bit25 */
			{  519,58,0}, /* core6 i0_pc bit26 */
			{  677,58,0}, /* core6 i0_pc bit27 */
			{  783,58,0}, /* core6 i0_pc bit28 */
			{  789,58,0}, /* core6 i0_pc bit29 */
			{  822,58,0}, /* core6 i0_pc bit30 */
			{  651,58,0}, /* core6 i0_pc bit31 */
			{  691,58,0}, /* core6 i0_pc bit32 */
			{  456,58,0}, /* core6 i0_pc bit33 */
			{  468,58,0}, /* core6 i0_pc bit34 */
			{  467,58,0}, /* core6 i0_pc bit35 */
			{  701,58,0}, /* core6 i0_pc bit36 */
			{  588,58,0}, /* core6 i0_pc bit37 */
			{  464,58,0}, /* core6 i0_pc bit38 */
			{  470,58,0}, /* core6 i0_pc bit39 */
			{  777,58,0}, /* core6 i0_pc bit40 */
			{  700,58,0}, /* core6 i0_pc bit41 */
			{  458,58,0}, /* core6 i0_pc bit42 */
			{  613,58,0}, /* core6 i0_pc bit43 */
			{  364,58,0}, /* core6 i0_pc bit44 */
			{  769,58,0}, /* core6 i0_pc bit45 */
			{  748,58,0}, /* core6 i0_pc bit46 */
			{  757,58,0}, /* core6 i0_pc bit47 */
			{  641,58,0}, /* core6 i0_pc bit48 */
			{  593,58,0}, /* core6 i0_pc bit49 */
			{  437,58,0}, /* core6 i0_pc bit50 */
			{  761,58,0}, /* core6 i0_pc bit51 */
			{  610,58,0}, /* core6 i0_pc bit52 */
			{  608,58,0}, /* core6 i0_pc bit53 */
			{  514,58,0}, /* core6 i0_pc bit54 */
			{  521,58,0}, /* core6 i0_pc bit55 */
			{  614,58,0}, /* core6 i0_pc bit56 */
			{  616,58,0}, /* core6 i0_pc bit57 */
			{  511,58,0}, /* core6 i0_pc bit58 */
			{  675,58,0}, /* core6 i0_pc bit59 */
			{  794,58,0}, /* core6 i0_pc bit60 */
			{  790,58,0}, /* core6 i0_pc bit61 */
			{  824,58,0}, /* core6 i0_pc bit62 */
			{  454,58,0}, /* core6 i0_pc bit63 */
			}},
			.sram_wr_ptr_0 = {{
			{25630,58,0}, /* core6 sram_wr_ptr_0 bit0 */
			{25632,58,0}, /* core6 sram_wr_ptr_0 bit1 */
			{25620,58,0}, /* core6 sram_wr_ptr_0 bit2 */
			{25625,58,0}, /* core6 sram_wr_ptr_0 bit3 */
			{25619,58,0}, /* core6 sram_wr_ptr_0 bit4 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit5 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit6 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit7 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit8 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit9 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit10 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit11 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit12 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit13 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit14 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit15 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit16 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit17 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit18 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit19 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit20 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit21 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit22 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit23 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit24 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit25 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit26 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit27 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit28 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit29 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit30 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit31 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit32 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit33 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit34 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit35 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit36 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit37 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit38 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit39 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit40 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit41 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit42 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit43 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit44 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit45 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit46 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit47 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit48 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit49 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit50 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit51 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit52 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit53 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit54 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit55 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit56 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit57 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit58 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit59 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit60 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit61 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit62 */
			{    0, 0,2}, /* core6 sram_wr_ptr_0 bit63 */
			}},
	},
	{		/* core 7 */ 
			.i0_pc = {{
			{  516,59,0}, /* core7 i0_pc bit0 */
			{  451,59,0}, /* core7 i0_pc bit1 */
			{  466,59,0}, /* core7 i0_pc bit2 */
			{  369,59,0}, /* core7 i0_pc bit3 */
			{  505,59,0}, /* core7 i0_pc bit4 */
			{  591,59,0}, /* core7 i0_pc bit5 */
			{  392,59,0}, /* core7 i0_pc bit6 */
			{  471,59,0}, /* core7 i0_pc bit7 */
			{  776,59,0}, /* core7 i0_pc bit8 */
			{  690,59,0}, /* core7 i0_pc bit9 */
			{  652,59,0}, /* core7 i0_pc bit10 */
			{  622,59,0}, /* core7 i0_pc bit11 */
			{  773,59,0}, /* core7 i0_pc bit12 */
			{  767,59,0}, /* core7 i0_pc bit13 */
			{  774,59,0}, /* core7 i0_pc bit14 */
			{  758,59,0}, /* core7 i0_pc bit15 */
			{  603,59,0}, /* core7 i0_pc bit16 */
			{  597,59,0}, /* core7 i0_pc bit17 */
			{  817,59,0}, /* core7 i0_pc bit18 */
			{  619,59,0}, /* core7 i0_pc bit19 */
			{  625,59,0}, /* core7 i0_pc bit20 */
			{  752,59,0}, /* core7 i0_pc bit21 */
			{  497,59,0}, /* core7 i0_pc bit22 */
			{  507,59,0}, /* core7 i0_pc bit23 */
			{  611,59,0}, /* core7 i0_pc bit24 */
			{  623,59,0}, /* core7 i0_pc bit25 */
			{  519,59,0}, /* core7 i0_pc bit26 */
			{  677,59,0}, /* core7 i0_pc bit27 */
			{  783,59,0}, /* core7 i0_pc bit28 */
			{  789,59,0}, /* core7 i0_pc bit29 */
			{  822,59,0}, /* core7 i0_pc bit30 */
			{  651,59,0}, /* core7 i0_pc bit31 */
			{  691,59,0}, /* core7 i0_pc bit32 */
			{  456,59,0}, /* core7 i0_pc bit33 */
			{  468,59,0}, /* core7 i0_pc bit34 */
			{  467,59,0}, /* core7 i0_pc bit35 */
			{  701,59,0}, /* core7 i0_pc bit36 */
			{  588,59,0}, /* core7 i0_pc bit37 */
			{  464,59,0}, /* core7 i0_pc bit38 */
			{  470,59,0}, /* core7 i0_pc bit39 */
			{  777,59,0}, /* core7 i0_pc bit40 */
			{  700,59,0}, /* core7 i0_pc bit41 */
			{  458,59,0}, /* core7 i0_pc bit42 */
			{  613,59,0}, /* core7 i0_pc bit43 */
			{  364,59,0}, /* core7 i0_pc bit44 */
			{  769,59,0}, /* core7 i0_pc bit45 */
			{  748,59,0}, /* core7 i0_pc bit46 */
			{  757,59,0}, /* core7 i0_pc bit47 */
			{  641,59,0}, /* core7 i0_pc bit48 */
			{  593,59,0}, /* core7 i0_pc bit49 */
			{  437,59,0}, /* core7 i0_pc bit50 */
			{  761,59,0}, /* core7 i0_pc bit51 */
			{  610,59,0}, /* core7 i0_pc bit52 */
			{  608,59,0}, /* core7 i0_pc bit53 */
			{  514,59,0}, /* core7 i0_pc bit54 */
			{  521,59,0}, /* core7 i0_pc bit55 */
			{  614,59,0}, /* core7 i0_pc bit56 */
			{  616,59,0}, /* core7 i0_pc bit57 */
			{  511,59,0}, /* core7 i0_pc bit58 */
			{  675,59,0}, /* core7 i0_pc bit59 */
			{  794,59,0}, /* core7 i0_pc bit60 */
			{  790,59,0}, /* core7 i0_pc bit61 */
			{  824,59,0}, /* core7 i0_pc bit62 */
			{  454,59,0}, /* core7 i0_pc bit63 */
			}},
			.sram_wr_ptr_0 = {{
			{25630,59,0}, /* core7 sram_wr_ptr_0 bit0 */
			{25632,59,0}, /* core7 sram_wr_ptr_0 bit1 */
			{25620,59,0}, /* core7 sram_wr_ptr_0 bit2 */
			{25625,59,0}, /* core7 sram_wr_ptr_0 bit3 */
			{25619,59,0}, /* core7 sram_wr_ptr_0 bit4 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit5 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit6 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit7 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit8 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit9 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit10 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit11 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit12 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit13 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit14 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit15 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit16 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit17 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit18 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit19 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit20 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit21 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit22 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit23 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit24 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit25 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit26 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit27 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit28 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit29 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit30 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit31 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit32 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit33 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit34 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit35 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit36 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit37 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit38 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit39 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit40 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit41 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit42 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit43 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit44 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit45 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit46 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit47 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit48 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit49 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit50 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit51 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit52 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit53 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit54 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit55 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit56 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit57 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit58 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit59 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit60 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit61 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit62 */
			{    0, 0,2}, /* core7 sram_wr_ptr_0 bit63 */
			}},
	},
}; 
