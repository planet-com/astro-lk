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

#define ENABLE_RETURN_STACK
#define RETURN_STACK_NO_BIG
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
	struct reg_collector mp0_L3_parity_err;
	struct reg_collector mp0_L3_parity_index;
	struct reg_collector mp0_L3_parity_bank;
	struct reg_collector mp0_L3_parity_err_count;
	struct reg_collector mp0_L3_parity_sap;
	struct reg_collector L2_parity_err;
	struct reg_collector L2_parity_err_count;
	struct reg_collector L2_parity_index;
	struct reg_collector L2_parity_way;
	struct reg_collector L2_parity_banks;
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
};

struct big_core_spec {
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
	struct reg_collector edpcsr;
	struct reg_collector spmc_power_state;
	struct reg_collector i0_valid;
	struct reg_collector i1_valid;
	struct reg_collector i2_valid;
	struct reg_collector i0_pc;
	struct reg_collector i1_pc;
	struct reg_collector i2_pc;
	struct reg_collector last_branch;
	struct reg_collector sram_wr_ptr_0;
	struct reg_collector sram_wr_ptr_1;
	struct reg_collector sram_wr_ptr_2;
	struct reg_collector mp0_L3_parity_err;
	struct reg_collector mp0_L3_parity_index;
	struct reg_collector mp0_L3_parity_bank;
	struct reg_collector mp0_L3_parity_err_count;
	struct reg_collector mp0_L3_parity_sap;
	struct reg_collector L2_parity_err;
	struct reg_collector L2_parity_err_count;
	struct reg_collector L2_parity_index;
	struct reg_collector L2_parity_way;
	struct reg_collector L2_parity_banks;
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
	struct reg_collector mp0_L3_parity_err;
	struct reg_collector mp0_L3_parity_index;
	struct reg_collector mp0_L3_parity_bank;
	struct reg_collector mp0_L3_parity_err_count;
	struct reg_collector mp0_L3_parity_sap;
	struct reg_collector L2_parity_err;
	struct reg_collector L2_parity_err_count;
	struct reg_collector L2_parity_index;
	struct reg_collector L2_parity_way;
	struct reg_collector L2_parity_banks;
	struct reg_collector dfd_v35_enable;
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
			.M0_AR_Pending_Counter = {{
			{12504,10,1}, /* core0 M0_AR_Pending_Counter bit0 */
			{12508,10,1}, /* core0 M0_AR_Pending_Counter bit1 */
			{12498,10,1}, /* core0 M0_AR_Pending_Counter bit2 */
			{12500,10,1}, /* core0 M0_AR_Pending_Counter bit3 */
			{12506,10,1}, /* core0 M0_AR_Pending_Counter bit4 */
			{12496,10,1}, /* core0 M0_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit63 */
			}},
			.M1_AR_Pending_Counter = {{
			{12596,10,1}, /* core0 M1_AR_Pending_Counter bit0 */
			{12584,10,1}, /* core0 M1_AR_Pending_Counter bit1 */
			{12586,10,1}, /* core0 M1_AR_Pending_Counter bit2 */
			{12592,10,1}, /* core0 M1_AR_Pending_Counter bit3 */
			{12598,10,1}, /* core0 M1_AR_Pending_Counter bit4 */
			{12594,10,1}, /* core0 M1_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit63 */
			}},
			.M2_AR_Pending_Counter = {{
			{12530,10,1}, /* core0 M2_AR_Pending_Counter bit0 */
			{12536,10,1}, /* core0 M2_AR_Pending_Counter bit1 */
			{12520,10,1}, /* core0 M2_AR_Pending_Counter bit2 */
			{12526,10,1}, /* core0 M2_AR_Pending_Counter bit3 */
			{12522,10,1}, /* core0 M2_AR_Pending_Counter bit4 */
			{12538,10,1}, /* core0 M2_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit63 */
			}},
			.M0_AW_Pending_Counter = {{
			{12480,10,1}, /* core0 M0_AW_Pending_Counter bit0 */
			{12478,10,1}, /* core0 M0_AW_Pending_Counter bit1 */
			{12484,10,1}, /* core0 M0_AW_Pending_Counter bit2 */
			{12476,10,1}, /* core0 M0_AW_Pending_Counter bit3 */
			{12482,10,1}, /* core0 M0_AW_Pending_Counter bit4 */
			{12488,10,1}, /* core0 M0_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit63 */
			}},
			.M1_AR_Pending_Counter = {{
			{12614,10,1}, /* core0 M1_AR_Pending_Counter bit0 */
			{12610,10,1}, /* core0 M1_AR_Pending_Counter bit1 */
			{12612,10,1}, /* core0 M1_AR_Pending_Counter bit2 */
			{12602,10,1}, /* core0 M1_AR_Pending_Counter bit3 */
			{12600,10,1}, /* core0 M1_AR_Pending_Counter bit4 */
			{12604,10,1}, /* core0 M1_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit63 */
			}},
			.M2_AW_Pending_Counter = {{
			{12582,10,1}, /* core0 M2_AW_Pending_Counter bit0 */
			{12590,10,1}, /* core0 M2_AW_Pending_Counter bit1 */
			{12588,10,1}, /* core0 M2_AW_Pending_Counter bit2 */
			{12578,10,1}, /* core0 M2_AW_Pending_Counter bit3 */
			{12574,10,1}, /* core0 M2_AW_Pending_Counter bit4 */
			{12576,10,1}, /* core0 M2_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit63 */
			}},
			.S4_AR_Pending_Counter = {{
			{12410,10,1}, /* core0 S4_AR_Pending_Counter bit0 */
			{12412,10,1}, /* core0 S4_AR_Pending_Counter bit1 */
			{12408,10,1}, /* core0 S4_AR_Pending_Counter bit2 */
			{12406,10,1}, /* core0 S4_AR_Pending_Counter bit3 */
			{12414,10,1}, /* core0 S4_AR_Pending_Counter bit4 */
			{12404,10,1}, /* core0 S4_AR_Pending_Counter bit5 */
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
			{12398,10,1}, /* core0 S4_AW_Pending_Counter bit0 */
			{12434,10,1}, /* core0 S4_AW_Pending_Counter bit1 */
			{12396,10,1}, /* core0 S4_AW_Pending_Counter bit2 */
			{12432,10,1}, /* core0 S4_AW_Pending_Counter bit3 */
			{12400,10,1}, /* core0 S4_AW_Pending_Counter bit4 */
			{12402,10,1}, /* core0 S4_AW_Pending_Counter bit5 */
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
			{12442,10,1}, /* core0 S3_AR_Pending_Counter bit0 */
			{12364,10,1}, /* core0 S3_AR_Pending_Counter bit1 */
			{12362,10,1}, /* core0 S3_AR_Pending_Counter bit2 */
			{12440,10,1}, /* core0 S3_AR_Pending_Counter bit3 */
			{12360,10,1}, /* core0 S3_AR_Pending_Counter bit4 */
			{12438,10,1}, /* core0 S3_AR_Pending_Counter bit5 */
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
			{12380,10,1}, /* core0 S3_AW_Pending_Counter bit0 */
			{12386,10,1}, /* core0 S3_AW_Pending_Counter bit1 */
			{12376,10,1}, /* core0 S3_AW_Pending_Counter bit2 */
			{12372,10,1}, /* core0 S3_AW_Pending_Counter bit3 */
			{12370,10,1}, /* core0 S3_AW_Pending_Counter bit4 */
			{12388,10,1}, /* core0 S3_AW_Pending_Counter bit5 */
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
			.mp0_L3_parity_err = {{
			{ 2114, 4,0}, /* core0 mp0_L3_parity_err bit0 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit1 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit2 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit3 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit4 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit5 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit6 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit63 */
			}},
			.mp0_L3_parity_err_count = {{
			{ 2128, 4,0}, /* core0 mp0_L3_parity_err_count bit0 */
			{ 2118, 4,0}, /* core0 mp0_L3_parity_err_count bit1 */
			{ 2110, 4,0}, /* core0 mp0_L3_parity_err_count bit2 */
			{ 2120, 4,0}, /* core0 mp0_L3_parity_err_count bit3 */
			{ 2116, 4,0}, /* core0 mp0_L3_parity_err_count bit4 */
			{ 2112, 4,0}, /* core0 mp0_L3_parity_err_count bit5 */
			{ 2122, 4,0}, /* core0 mp0_L3_parity_err_count bit6 */
			{ 2126, 4,0}, /* core0 mp0_L3_parity_err_count bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit63 */
			}},
			.mp0_L3_parity_sap = {{
			{ 2124, 4,0}, /* core0 mp0_L3_parity_sap bit0 */
			{ 2130, 4,0}, /* core0 mp0_L3_parity_sap bit1 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit2 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit3 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit4 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit5 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit6 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit63 */
			}},
			.mp0_L3_parity_index = {{
			{ 2106, 4,0}, /* core0 mp0_L3_parity_index bit0 */
			{ 2100, 4,0}, /* core0 mp0_L3_parity_index bit1 */
			{ 2514, 4,0}, /* core0 mp0_L3_parity_index bit2 */
			{ 2526, 4,0}, /* core0 mp0_L3_parity_index bit3 */
			{ 2104, 4,0}, /* core0 mp0_L3_parity_index bit4 */
			{ 2542, 4,0}, /* core0 mp0_L3_parity_index bit5 */
			{ 2064, 4,0}, /* core0 mp0_L3_parity_index bit6 */
			{ 2072, 4,0}, /* core0 mp0_L3_parity_index bit7 */
			{ 2102, 4,0}, /* core0 mp0_L3_parity_index bit8 */
			{ 2074, 4,0}, /* core0 mp0_L3_parity_index bit9 */
			{ 2062, 4,0}, /* core0 mp0_L3_parity_index bit10 */
			{ 2068, 4,0}, /* core0 mp0_L3_parity_index bit11 */
			{ 2536, 4,0}, /* core0 mp0_L3_parity_index bit12 */
			{ 2544, 4,0}, /* core0 mp0_L3_parity_index bit13 */
			{ 2098, 4,0}, /* core0 mp0_L3_parity_index bit14 */
			{ 2528, 4,0}, /* core0 mp0_L3_parity_index bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit63 */
			}},
			.mp0_L3_parity_bank = {{
			{ 2096, 4,0}, /* core0 mp0_L3_parity_bank bit0 */
			{ 2516, 4,0}, /* core0 mp0_L3_parity_bank bit1 */
			{ 2066, 4,0}, /* core0 mp0_L3_parity_bank bit2 */
			{ 2530, 4,0}, /* core0 mp0_L3_parity_bank bit3 */
			{ 2058, 4,0}, /* core0 mp0_L3_parity_bank bit4 */
			{ 2060, 4,0}, /* core0 mp0_L3_parity_bank bit5 */
			{ 2520, 4,0}, /* core0 mp0_L3_parity_bank bit6 */
			{ 2070, 4,0}, /* core0 mp0_L3_parity_bank bit7 */
			{ 2548, 4,0}, /* core0 mp0_L3_parity_bank bit8 */
			{ 2524, 4,0}, /* core0 mp0_L3_parity_bank bit9 */
			{ 2538, 4,0}, /* core0 mp0_L3_parity_bank bit10 */
			{ 2540, 4,0}, /* core0 mp0_L3_parity_bank bit11 */
			{ 2518, 4,0}, /* core0 mp0_L3_parity_bank bit12 */
			{ 2522, 4,0}, /* core0 mp0_L3_parity_bank bit13 */
			{ 2546, 4,0}, /* core0 mp0_L3_parity_bank bit14 */
			{ 2512, 4,0}, /* core0 mp0_L3_parity_bank bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit63 */
			}},
			.dfd_v35_enable = {{
			{ 3042, 9,0}, /* core0 dfd_v35_enable bit0 */
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
	},
}; 

struct little_core_spec little_core[] = {
	{		/* core 0 */ 
			.pc = {{
			{ 2530,34,1}, /* core0 pc bit0 */
			{ 2528,34,1}, /* core0 pc bit1 */
			{ 2526,34,1}, /* core0 pc bit2 */
			{ 2524,34,1}, /* core0 pc bit3 */
			{ 2594,34,1}, /* core0 pc bit4 */
			{ 2592,34,1}, /* core0 pc bit5 */
			{ 2590,34,1}, /* core0 pc bit6 */
			{ 2588,34,1}, /* core0 pc bit7 */
			{ 2578,34,1}, /* core0 pc bit8 */
			{ 2458,34,1}, /* core0 pc bit9 */
			{ 2456,34,1}, /* core0 pc bit10 */
			{ 2576,34,1}, /* core0 pc bit11 */
			{ 2574,34,1}, /* core0 pc bit12 */
			{ 2572,34,1}, /* core0 pc bit13 */
			{ 2454,34,1}, /* core0 pc bit14 */
			{ 2452,34,1}, /* core0 pc bit15 */
			{ 2306,34,1}, /* core0 pc bit16 */
			{ 2474,34,1}, /* core0 pc bit17 */
			{ 2304,34,1}, /* core0 pc bit18 */
			{ 2472,34,1}, /* core0 pc bit19 */
			{ 2302,34,1}, /* core0 pc bit20 */
			{ 2300,34,1}, /* core0 pc bit21 */
			{ 2470,34,1}, /* core0 pc bit22 */
			{ 2314,34,1}, /* core0 pc bit23 */
			{ 2312,34,1}, /* core0 pc bit24 */
			{ 2310,34,1}, /* core0 pc bit25 */
			{ 2468,34,1}, /* core0 pc bit26 */
			{ 2522,34,1}, /* core0 pc bit27 */
			{ 2308,34,1}, /* core0 pc bit28 */
			{ 2464,34,1}, /* core0 pc bit29 */
			{ 2684,34,1}, /* core0 pc bit30 */
			{ 2520,34,1}, /* core0 pc bit31 */
			{ 2518,34,1}, /* core0 pc bit32 */
			{ 2516,34,1}, /* core0 pc bit33 */
			{ 2562,34,1}, /* core0 pc bit34 */
			{ 2560,34,1}, /* core0 pc bit35 */
			{ 2558,34,1}, /* core0 pc bit36 */
			{ 2556,34,1}, /* core0 pc bit37 */
			{ 2586,34,1}, /* core0 pc bit38 */
			{ 2584,34,1}, /* core0 pc bit39 */
			{ 2582,34,1}, /* core0 pc bit40 */
			{ 2580,34,1}, /* core0 pc bit41 */
			{ 2570,34,1}, /* core0 pc bit42 */
			{ 2568,34,1}, /* core0 pc bit43 */
			{ 2566,34,1}, /* core0 pc bit44 */
			{ 2564,34,1}, /* core0 pc bit45 */
			{ 2626,34,1}, /* core0 pc bit46 */
			{ 2624,34,1}, /* core0 pc bit47 */
			{ 2622,34,1}, /* core0 pc bit48 */
			{ 2620,34,1}, /* core0 pc bit49 */
			{ 2658,34,1}, /* core0 pc bit50 */
			{ 2656,34,1}, /* core0 pc bit51 */
			{ 2654,34,1}, /* core0 pc bit52 */
			{ 2652,34,1}, /* core0 pc bit53 */
			{ 2290,34,1}, /* core0 pc bit54 */
			{ 2288,34,1}, /* core0 pc bit55 */
			{ 2286,34,1}, /* core0 pc bit56 */
			{ 2284,34,1}, /* core0 pc bit57 */
			{ 2132,34,1}, /* core0 pc bit58 */
			{ 2130,34,1}, /* core0 pc bit59 */
			{ 2128,34,1}, /* core0 pc bit60 */
			{ 2126,34,1}, /* core0 pc bit61 */
			{ 2116,34,1}, /* core0 pc bit62 */
			{  670,34,1}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{ 7110,38,0}, /* core0 sp32 bit0 */
			{15738,38,0}, /* core0 sp32 bit1 */
			{15732,38,0}, /* core0 sp32 bit2 */
			{ 7088,38,0}, /* core0 sp32 bit3 */
			{15730,38,0}, /* core0 sp32 bit4 */
			{15740,38,0}, /* core0 sp32 bit5 */
			{15716,38,0}, /* core0 sp32 bit6 */
			{15714,38,0}, /* core0 sp32 bit7 */
			{15724,38,0}, /* core0 sp32 bit8 */
			{15682,38,0}, /* core0 sp32 bit9 */
			{15692,38,0}, /* core0 sp32 bit10 */
			{15722,38,0}, /* core0 sp32 bit11 */
			{15712,38,0}, /* core0 sp32 bit12 */
			{15710,38,0}, /* core0 sp32 bit13 */
			{15690,38,0}, /* core0 sp32 bit14 */
			{22706,38,0}, /* core0 sp32 bit15 */
			{22704,38,0}, /* core0 sp32 bit16 */
			{22702,38,0}, /* core0 sp32 bit17 */
			{22700,38,0}, /* core0 sp32 bit18 */
			{15720,38,0}, /* core0 sp32 bit19 */
			{15718,38,0}, /* core0 sp32 bit20 */
			{15736,38,0}, /* core0 sp32 bit21 */
			{15728,38,0}, /* core0 sp32 bit22 */
			{15726,38,0}, /* core0 sp32 bit23 */
			{15734,38,0}, /* core0 sp32 bit24 */
			{15924,38,0}, /* core0 sp32 bit25 */
			{15922,38,0}, /* core0 sp32 bit26 */
			{15920,38,0}, /* core0 sp32 bit27 */
			{15918,38,0}, /* core0 sp32 bit28 */
			{15688,38,0}, /* core0 sp32 bit29 */
			{15686,38,0}, /* core0 sp32 bit30 */
			{15684,38,0}, /* core0 sp32 bit31 */
			{15864,38,0}, /* core0 sp32 bit32 */
			{15862,38,0}, /* core0 sp32 bit33 */
			{15856,38,0}, /* core0 sp32 bit34 */
			{15868,38,0}, /* core0 sp32 bit35 */
			{15852,38,0}, /* core0 sp32 bit36 */
			{15866,38,0}, /* core0 sp32 bit37 */
			{ 6780,38,0}, /* core0 sp32 bit38 */
			{15850,38,0}, /* core0 sp32 bit39 */
			{15854,38,0}, /* core0 sp32 bit40 */
			{15848,38,0}, /* core0 sp32 bit41 */
			{15846,38,0}, /* core0 sp32 bit42 */
			{15844,38,0}, /* core0 sp32 bit43 */
			{15842,38,0}, /* core0 sp32 bit44 */
			{15860,38,0}, /* core0 sp32 bit45 */
			{15858,38,0}, /* core0 sp32 bit46 */
			{15872,38,0}, /* core0 sp32 bit47 */
			{15876,38,0}, /* core0 sp32 bit48 */
			{22370,38,0}, /* core0 sp32 bit49 */
			{22368,38,0}, /* core0 sp32 bit50 */
			{22366,38,0}, /* core0 sp32 bit51 */
			{22364,38,0}, /* core0 sp32 bit52 */
			{22354,38,0}, /* core0 sp32 bit53 */
			{22352,38,0}, /* core0 sp32 bit54 */
			{22350,38,0}, /* core0 sp32 bit55 */
			{22348,38,0}, /* core0 sp32 bit56 */
			{22362,38,0}, /* core0 sp32 bit57 */
			{22360,38,0}, /* core0 sp32 bit58 */
			{22358,38,0}, /* core0 sp32 bit59 */
			{22356,38,0}, /* core0 sp32 bit60 */
			{15870,38,0}, /* core0 sp32 bit61 */
			{15874,38,0}, /* core0 sp32 bit62 */
			{ 6776,38,0}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7124,38,0}, /* core0 fp32 bit0 */
			{ 7120,38,0}, /* core0 fp32 bit1 */
			{16530,38,0}, /* core0 fp32 bit2 */
			{16884,38,0}, /* core0 fp32 bit3 */
			{16880,38,0}, /* core0 fp32 bit4 */
			{16878,38,0}, /* core0 fp32 bit5 */
			{16876,38,0}, /* core0 fp32 bit6 */
			{16882,38,0}, /* core0 fp32 bit7 */
			{16874,38,0}, /* core0 fp32 bit8 */
			{16796,38,0}, /* core0 fp32 bit9 */
			{16794,38,0}, /* core0 fp32 bit10 */
			{ 7118,38,0}, /* core0 fp32 bit11 */
			{16548,38,0}, /* core0 fp32 bit12 */
			{16892,38,0}, /* core0 fp32 bit13 */
			{16792,38,0}, /* core0 fp32 bit14 */
			{16784,38,0}, /* core0 fp32 bit15 */
			{16886,38,0}, /* core0 fp32 bit16 */
			{16890,38,0}, /* core0 fp32 bit17 */
			{ 7116,38,0}, /* core0 fp32 bit18 */
			{ 7082,38,0}, /* core0 fp32 bit19 */
			{16546,38,0}, /* core0 fp32 bit20 */
			{16888,38,0}, /* core0 fp32 bit21 */
			{16532,38,0}, /* core0 fp32 bit22 */
			{ 7084,38,0}, /* core0 fp32 bit23 */
			{ 7114,38,0}, /* core0 fp32 bit24 */
			{ 6906,38,0}, /* core0 fp32 bit25 */
			{16782,38,0}, /* core0 fp32 bit26 */
			{16790,38,0}, /* core0 fp32 bit27 */
			{16788,38,0}, /* core0 fp32 bit28 */
			{ 6902,38,0}, /* core0 fp32 bit29 */
			{16786,38,0}, /* core0 fp32 bit30 */
			{ 6904,38,0}, /* core0 fp32 bit31 */
			{ 6830,38,0}, /* core0 fp32 bit32 */
			{ 6822,38,0}, /* core0 fp32 bit33 */
			{ 6824,38,0}, /* core0 fp32 bit34 */
			{ 6886,38,0}, /* core0 fp32 bit35 */
			{ 6884,38,0}, /* core0 fp32 bit36 */
			{ 6826,38,0}, /* core0 fp32 bit37 */
			{16624,38,0}, /* core0 fp32 bit38 */
			{16622,38,0}, /* core0 fp32 bit39 */
			{16632,38,0}, /* core0 fp32 bit40 */
			{16628,38,0}, /* core0 fp32 bit41 */
			{ 6820,38,0}, /* core0 fp32 bit42 */
			{16630,38,0}, /* core0 fp32 bit43 */
			{16626,38,0}, /* core0 fp32 bit44 */
			{16656,38,0}, /* core0 fp32 bit45 */
			{16648,38,0}, /* core0 fp32 bit46 */
			{16636,38,0}, /* core0 fp32 bit47 */
			{16634,38,0}, /* core0 fp32 bit48 */
			{22546,38,0}, /* core0 fp32 bit49 */
			{ 6818,38,0}, /* core0 fp32 bit50 */
			{22554,38,0}, /* core0 fp32 bit51 */
			{22552,38,0}, /* core0 fp32 bit52 */
			{22544,38,0}, /* core0 fp32 bit53 */
			{22542,38,0}, /* core0 fp32 bit54 */
			{22540,38,0}, /* core0 fp32 bit55 */
			{22550,38,0}, /* core0 fp32 bit56 */
			{22562,38,0}, /* core0 fp32 bit57 */
			{22560,38,0}, /* core0 fp32 bit58 */
			{22548,38,0}, /* core0 fp32 bit59 */
			{16646,38,0}, /* core0 fp32 bit60 */
			{16654,38,0}, /* core0 fp32 bit61 */
			{22558,38,0}, /* core0 fp32 bit62 */
			{22556,38,0}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{14752,38,0}, /* core0 fp64 bit0 */
			{ 6972,38,0}, /* core0 fp64 bit1 */
			{14750,38,0}, /* core0 fp64 bit2 */
			{15068,38,0}, /* core0 fp64 bit3 */
			{15066,38,0}, /* core0 fp64 bit4 */
			{15080,38,0}, /* core0 fp64 bit5 */
			{15078,38,0}, /* core0 fp64 bit6 */
			{15076,38,0}, /* core0 fp64 bit7 */
			{15074,38,0}, /* core0 fp64 bit8 */
			{15020,38,0}, /* core0 fp64 bit9 */
			{14798,38,0}, /* core0 fp64 bit10 */
			{15060,38,0}, /* core0 fp64 bit11 */
			{15058,38,0}, /* core0 fp64 bit12 */
			{15072,38,0}, /* core0 fp64 bit13 */
			{15018,38,0}, /* core0 fp64 bit14 */
			{14804,38,0}, /* core0 fp64 bit15 */
			{15070,38,0}, /* core0 fp64 bit16 */
			{15084,38,0}, /* core0 fp64 bit17 */
			{14748,38,0}, /* core0 fp64 bit18 */
			{15082,38,0}, /* core0 fp64 bit19 */
			{15064,38,0}, /* core0 fp64 bit20 */
			{14746,38,0}, /* core0 fp64 bit21 */
			{15062,38,0}, /* core0 fp64 bit22 */
			{ 7066,38,0}, /* core0 fp64 bit23 */
			{14756,38,0}, /* core0 fp64 bit24 */
			{14754,38,0}, /* core0 fp64 bit25 */
			{ 6946,38,0}, /* core0 fp64 bit26 */
			{14808,38,0}, /* core0 fp64 bit27 */
			{14806,38,0}, /* core0 fp64 bit28 */
			{14802,38,0}, /* core0 fp64 bit29 */
			{ 6970,38,0}, /* core0 fp64 bit30 */
			{14800,38,0}, /* core0 fp64 bit31 */
			{14888,38,0}, /* core0 fp64 bit32 */
			{14884,38,0}, /* core0 fp64 bit33 */
			{14886,38,0}, /* core0 fp64 bit34 */
			{ 6708,38,0}, /* core0 fp64 bit35 */
			{14892,38,0}, /* core0 fp64 bit36 */
			{14882,38,0}, /* core0 fp64 bit37 */
			{ 6700,38,0}, /* core0 fp64 bit38 */
			{14890,38,0}, /* core0 fp64 bit39 */
			{14896,38,0}, /* core0 fp64 bit40 */
			{14894,38,0}, /* core0 fp64 bit41 */
			{14900,38,0}, /* core0 fp64 bit42 */
			{14904,38,0}, /* core0 fp64 bit43 */
			{14902,38,0}, /* core0 fp64 bit44 */
			{14912,38,0}, /* core0 fp64 bit45 */
			{14898,38,0}, /* core0 fp64 bit46 */
			{14910,38,0}, /* core0 fp64 bit47 */
			{14916,38,0}, /* core0 fp64 bit48 */
			{14914,38,0}, /* core0 fp64 bit49 */
			{21972,38,0}, /* core0 fp64 bit50 */
			{21980,38,0}, /* core0 fp64 bit51 */
			{21970,38,0}, /* core0 fp64 bit52 */
			{21978,38,0}, /* core0 fp64 bit53 */
			{21968,38,0}, /* core0 fp64 bit54 */
			{21966,38,0}, /* core0 fp64 bit55 */
			{21988,38,0}, /* core0 fp64 bit56 */
			{21986,38,0}, /* core0 fp64 bit57 */
			{21976,38,0}, /* core0 fp64 bit58 */
			{21984,38,0}, /* core0 fp64 bit59 */
			{14920,38,0}, /* core0 fp64 bit60 */
			{21982,38,0}, /* core0 fp64 bit61 */
			{21974,38,0}, /* core0 fp64 bit62 */
			{14918,38,0}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 6982,38,0}, /* core0 sp_EL0 bit0 */
			{ 6974,38,0}, /* core0 sp_EL0 bit1 */
			{14710,38,0}, /* core0 sp_EL0 bit2 */
			{14720,38,0}, /* core0 sp_EL0 bit3 */
			{14718,38,0}, /* core0 sp_EL0 bit4 */
			{15108,38,0}, /* core0 sp_EL0 bit5 */
			{15106,38,0}, /* core0 sp_EL0 bit6 */
			{ 7046,38,0}, /* core0 sp_EL0 bit7 */
			{15112,38,0}, /* core0 sp_EL0 bit8 */
			{14772,38,0}, /* core0 sp_EL0 bit9 */
			{14770,38,0}, /* core0 sp_EL0 bit10 */
			{14708,38,0}, /* core0 sp_EL0 bit11 */
			{14706,38,0}, /* core0 sp_EL0 bit12 */
			{15032,38,0}, /* core0 sp_EL0 bit13 */
			{15030,38,0}, /* core0 sp_EL0 bit14 */
			{14776,38,0}, /* core0 sp_EL0 bit15 */
			{15036,38,0}, /* core0 sp_EL0 bit16 */
			{15110,38,0}, /* core0 sp_EL0 bit17 */
			{15034,38,0}, /* core0 sp_EL0 bit18 */
			{ 7050,38,0}, /* core0 sp_EL0 bit19 */
			{14716,38,0}, /* core0 sp_EL0 bit20 */
			{ 7048,38,0}, /* core0 sp_EL0 bit21 */
			{14712,38,0}, /* core0 sp_EL0 bit22 */
			{14714,38,0}, /* core0 sp_EL0 bit23 */
			{14760,38,0}, /* core0 sp_EL0 bit24 */
			{14758,38,0}, /* core0 sp_EL0 bit25 */
			{14780,38,0}, /* core0 sp_EL0 bit26 */
			{14778,38,0}, /* core0 sp_EL0 bit27 */
			{15008,38,0}, /* core0 sp_EL0 bit28 */
			{14774,38,0}, /* core0 sp_EL0 bit29 */
			{15006,38,0}, /* core0 sp_EL0 bit30 */
			{ 7018,38,0}, /* core0 sp_EL0 bit31 */
			{14820,38,0}, /* core0 sp_EL0 bit32 */
			{14818,38,0}, /* core0 sp_EL0 bit33 */
			{14844,38,0}, /* core0 sp_EL0 bit34 */
			{14812,38,0}, /* core0 sp_EL0 bit35 */
			{14810,38,0}, /* core0 sp_EL0 bit36 */
			{14816,38,0}, /* core0 sp_EL0 bit37 */
			{14814,38,0}, /* core0 sp_EL0 bit38 */
			{ 6836,38,0}, /* core0 sp_EL0 bit39 */
			{14842,38,0}, /* core0 sp_EL0 bit40 */
			{14836,38,0}, /* core0 sp_EL0 bit41 */
			{14840,38,0}, /* core0 sp_EL0 bit42 */
			{14838,38,0}, /* core0 sp_EL0 bit43 */
			{14828,38,0}, /* core0 sp_EL0 bit44 */
			{14834,38,0}, /* core0 sp_EL0 bit45 */
			{21900,38,0}, /* core0 sp_EL0 bit46 */
			{14832,38,0}, /* core0 sp_EL0 bit47 */
			{21898,38,0}, /* core0 sp_EL0 bit48 */
			{21896,38,0}, /* core0 sp_EL0 bit49 */
			{14830,38,0}, /* core0 sp_EL0 bit50 */
			{21894,38,0}, /* core0 sp_EL0 bit51 */
			{21892,38,0}, /* core0 sp_EL0 bit52 */
			{21884,38,0}, /* core0 sp_EL0 bit53 */
			{21890,38,0}, /* core0 sp_EL0 bit54 */
			{21888,38,0}, /* core0 sp_EL0 bit55 */
			{21886,38,0}, /* core0 sp_EL0 bit56 */
			{14824,38,0}, /* core0 sp_EL0 bit57 */
			{21882,38,0}, /* core0 sp_EL0 bit58 */
			{14822,38,0}, /* core0 sp_EL0 bit59 */
			{21880,38,0}, /* core0 sp_EL0 bit60 */
			{ 6838,38,0}, /* core0 sp_EL0 bit61 */
			{21878,38,0}, /* core0 sp_EL0 bit62 */
			{14826,38,0}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6988,38,0}, /* core0 sp_EL1 bit0 */
			{ 6998,38,0}, /* core0 sp_EL1 bit1 */
			{14740,38,0}, /* core0 sp_EL1 bit2 */
			{14738,38,0}, /* core0 sp_EL1 bit3 */
			{15096,38,0}, /* core0 sp_EL1 bit4 */
			{15094,38,0}, /* core0 sp_EL1 bit5 */
			{15088,38,0}, /* core0 sp_EL1 bit6 */
			{15116,38,0}, /* core0 sp_EL1 bit7 */
			{15086,38,0}, /* core0 sp_EL1 bit8 */
			{15014,38,0}, /* core0 sp_EL1 bit9 */
			{15002,38,0}, /* core0 sp_EL1 bit10 */
			{15114,38,0}, /* core0 sp_EL1 bit11 */
			{15120,38,0}, /* core0 sp_EL1 bit12 */
			{15118,38,0}, /* core0 sp_EL1 bit13 */
			{21844,38,0}, /* core0 sp_EL1 bit14 */
			{15000,38,0}, /* core0 sp_EL1 bit15 */
			{21842,38,0}, /* core0 sp_EL1 bit16 */
			{15128,38,0}, /* core0 sp_EL1 bit17 */
			{21840,38,0}, /* core0 sp_EL1 bit18 */
			{15126,38,0}, /* core0 sp_EL1 bit19 */
			{21838,38,0}, /* core0 sp_EL1 bit20 */
			{ 7064,38,0}, /* core0 sp_EL1 bit21 */
			{ 7056,38,0}, /* core0 sp_EL1 bit22 */
			{ 7062,38,0}, /* core0 sp_EL1 bit23 */
			{ 6994,38,0}, /* core0 sp_EL1 bit24 */
			{14992,38,0}, /* core0 sp_EL1 bit25 */
			{14990,38,0}, /* core0 sp_EL1 bit26 */
			{14996,38,0}, /* core0 sp_EL1 bit27 */
			{14994,38,0}, /* core0 sp_EL1 bit28 */
			{14998,38,0}, /* core0 sp_EL1 bit29 */
			{15016,38,0}, /* core0 sp_EL1 bit30 */
			{15004,38,0}, /* core0 sp_EL1 bit31 */
			{ 6864,38,0}, /* core0 sp_EL1 bit32 */
			{14876,38,0}, /* core0 sp_EL1 bit33 */
			{14940,38,0}, /* core0 sp_EL1 bit34 */
			{14874,38,0}, /* core0 sp_EL1 bit35 */
			{14880,38,0}, /* core0 sp_EL1 bit36 */
			{14878,38,0}, /* core0 sp_EL1 bit37 */
			{14948,38,0}, /* core0 sp_EL1 bit38 */
			{14946,38,0}, /* core0 sp_EL1 bit39 */
			{14938,38,0}, /* core0 sp_EL1 bit40 */
			{14944,38,0}, /* core0 sp_EL1 bit41 */
			{14942,38,0}, /* core0 sp_EL1 bit42 */
			{14936,38,0}, /* core0 sp_EL1 bit43 */
			{14934,38,0}, /* core0 sp_EL1 bit44 */
			{14932,38,0}, /* core0 sp_EL1 bit45 */
			{ 6868,38,0}, /* core0 sp_EL1 bit46 */
			{14930,38,0}, /* core0 sp_EL1 bit47 */
			{22116,38,0}, /* core0 sp_EL1 bit48 */
			{22114,38,0}, /* core0 sp_EL1 bit49 */
			{22108,38,0}, /* core0 sp_EL1 bit50 */
			{22106,38,0}, /* core0 sp_EL1 bit51 */
			{22104,38,0}, /* core0 sp_EL1 bit52 */
			{22102,38,0}, /* core0 sp_EL1 bit53 */
			{22124,38,0}, /* core0 sp_EL1 bit54 */
			{22122,38,0}, /* core0 sp_EL1 bit55 */
			{22120,38,0}, /* core0 sp_EL1 bit56 */
			{22118,38,0}, /* core0 sp_EL1 bit57 */
			{22100,38,0}, /* core0 sp_EL1 bit58 */
			{22098,38,0}, /* core0 sp_EL1 bit59 */
			{22096,38,0}, /* core0 sp_EL1 bit60 */
			{22094,38,0}, /* core0 sp_EL1 bit61 */
			{22112,38,0}, /* core0 sp_EL1 bit62 */
			{22110,38,0}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 6986,38,0}, /* core0 sp_EL2 bit0 */
			{ 7000,38,0}, /* core0 sp_EL2 bit1 */
			{14736,38,0}, /* core0 sp_EL2 bit2 */
			{14734,38,0}, /* core0 sp_EL2 bit3 */
			{15132,38,0}, /* core0 sp_EL2 bit4 */
			{15130,38,0}, /* core0 sp_EL2 bit5 */
			{15092,38,0}, /* core0 sp_EL2 bit6 */
			{14704,38,0}, /* core0 sp_EL2 bit7 */
			{15090,38,0}, /* core0 sp_EL2 bit8 */
			{15012,38,0}, /* core0 sp_EL2 bit9 */
			{15010,38,0}, /* core0 sp_EL2 bit10 */
			{14702,38,0}, /* core0 sp_EL2 bit11 */
			{15124,38,0}, /* core0 sp_EL2 bit12 */
			{15122,38,0}, /* core0 sp_EL2 bit13 */
			{21852,38,0}, /* core0 sp_EL2 bit14 */
			{ 7012,38,0}, /* core0 sp_EL2 bit15 */
			{21850,38,0}, /* core0 sp_EL2 bit16 */
			{15136,38,0}, /* core0 sp_EL2 bit17 */
			{21848,38,0}, /* core0 sp_EL2 bit18 */
			{15134,38,0}, /* core0 sp_EL2 bit19 */
			{21846,38,0}, /* core0 sp_EL2 bit20 */
			{ 7060,38,0}, /* core0 sp_EL2 bit21 */
			{ 7058,38,0}, /* core0 sp_EL2 bit22 */
			{ 7052,38,0}, /* core0 sp_EL2 bit23 */
			{14764,38,0}, /* core0 sp_EL2 bit24 */
			{14762,38,0}, /* core0 sp_EL2 bit25 */
			{14988,38,0}, /* core0 sp_EL2 bit26 */
			{14986,38,0}, /* core0 sp_EL2 bit27 */
			{ 7016,38,0}, /* core0 sp_EL2 bit28 */
			{ 7014,38,0}, /* core0 sp_EL2 bit29 */
			{ 7008,38,0}, /* core0 sp_EL2 bit30 */
			{ 7010,38,0}, /* core0 sp_EL2 bit31 */
			{ 6860,38,0}, /* core0 sp_EL2 bit32 */
			{14868,38,0}, /* core0 sp_EL2 bit33 */
			{14964,38,0}, /* core0 sp_EL2 bit34 */
			{14866,38,0}, /* core0 sp_EL2 bit35 */
			{14864,38,0}, /* core0 sp_EL2 bit36 */
			{14862,38,0}, /* core0 sp_EL2 bit37 */
			{14872,38,0}, /* core0 sp_EL2 bit38 */
			{14870,38,0}, /* core0 sp_EL2 bit39 */
			{14962,38,0}, /* core0 sp_EL2 bit40 */
			{14952,38,0}, /* core0 sp_EL2 bit41 */
			{14950,38,0}, /* core0 sp_EL2 bit42 */
			{14960,38,0}, /* core0 sp_EL2 bit43 */
			{14958,38,0}, /* core0 sp_EL2 bit44 */
			{14956,38,0}, /* core0 sp_EL2 bit45 */
			{ 6858,38,0}, /* core0 sp_EL2 bit46 */
			{14954,38,0}, /* core0 sp_EL2 bit47 */
			{22148,38,0}, /* core0 sp_EL2 bit48 */
			{22146,38,0}, /* core0 sp_EL2 bit49 */
			{22140,38,0}, /* core0 sp_EL2 bit50 */
			{22138,38,0}, /* core0 sp_EL2 bit51 */
			{22136,38,0}, /* core0 sp_EL2 bit52 */
			{22134,38,0}, /* core0 sp_EL2 bit53 */
			{22132,38,0}, /* core0 sp_EL2 bit54 */
			{22130,38,0}, /* core0 sp_EL2 bit55 */
			{22128,38,0}, /* core0 sp_EL2 bit56 */
			{22126,38,0}, /* core0 sp_EL2 bit57 */
			{22156,38,0}, /* core0 sp_EL2 bit58 */
			{22154,38,0}, /* core0 sp_EL2 bit59 */
			{22152,38,0}, /* core0 sp_EL2 bit60 */
			{22150,38,0}, /* core0 sp_EL2 bit61 */
			{22144,38,0}, /* core0 sp_EL2 bit62 */
			{22142,38,0}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6984,38,0}, /* core0 sp_EL3 bit0 */
			{ 6996,38,0}, /* core0 sp_EL3 bit1 */
			{14732,38,0}, /* core0 sp_EL3 bit2 */
			{14388,38,0}, /* core0 sp_EL3 bit3 */
			{15104,38,0}, /* core0 sp_EL3 bit4 */
			{15102,38,0}, /* core0 sp_EL3 bit5 */
			{14730,38,0}, /* core0 sp_EL3 bit6 */
			{14768,38,0}, /* core0 sp_EL3 bit7 */
			{15100,38,0}, /* core0 sp_EL3 bit8 */
			{14766,38,0}, /* core0 sp_EL3 bit9 */
			{14332,38,0}, /* core0 sp_EL3 bit10 */
			{14700,38,0}, /* core0 sp_EL3 bit11 */
			{14698,38,0}, /* core0 sp_EL3 bit12 */
			{14696,38,0}, /* core0 sp_EL3 bit13 */
			{14694,38,0}, /* core0 sp_EL3 bit14 */
			{14338,38,0}, /* core0 sp_EL3 bit15 */
			{14394,38,0}, /* core0 sp_EL3 bit16 */
			{15098,38,0}, /* core0 sp_EL3 bit17 */
			{14402,38,0}, /* core0 sp_EL3 bit18 */
			{ 7054,38,0}, /* core0 sp_EL3 bit19 */
			{14392,38,0}, /* core0 sp_EL3 bit20 */
			{14400,38,0}, /* core0 sp_EL3 bit21 */
			{14390,38,0}, /* core0 sp_EL3 bit22 */
			{14398,38,0}, /* core0 sp_EL3 bit23 */
			{14396,38,0}, /* core0 sp_EL3 bit24 */
			{14326,38,0}, /* core0 sp_EL3 bit25 */
			{14324,38,0}, /* core0 sp_EL3 bit26 */
			{14330,38,0}, /* core0 sp_EL3 bit27 */
			{14328,38,0}, /* core0 sp_EL3 bit28 */
			{14336,38,0}, /* core0 sp_EL3 bit29 */
			{ 7020,38,0}, /* core0 sp_EL3 bit30 */
			{14334,38,0}, /* core0 sp_EL3 bit31 */
			{14310,38,0}, /* core0 sp_EL3 bit32 */
			{14306,38,0}, /* core0 sp_EL3 bit33 */
			{14270,38,0}, /* core0 sp_EL3 bit34 */
			{14308,38,0}, /* core0 sp_EL3 bit35 */
			{14304,38,0}, /* core0 sp_EL3 bit36 */
			{14302,38,0}, /* core0 sp_EL3 bit37 */
			{14314,38,0}, /* core0 sp_EL3 bit38 */
			{14300,38,0}, /* core0 sp_EL3 bit39 */
			{14266,38,0}, /* core0 sp_EL3 bit40 */
			{14264,38,0}, /* core0 sp_EL3 bit41 */
			{14268,38,0}, /* core0 sp_EL3 bit42 */
			{14262,38,0}, /* core0 sp_EL3 bit43 */
			{14260,38,0}, /* core0 sp_EL3 bit44 */
			{14258,38,0}, /* core0 sp_EL3 bit45 */
			{14312,38,0}, /* core0 sp_EL3 bit46 */
			{14256,38,0}, /* core0 sp_EL3 bit47 */
			{22188,38,0}, /* core0 sp_EL3 bit48 */
			{22186,38,0}, /* core0 sp_EL3 bit49 */
			{22184,38,0}, /* core0 sp_EL3 bit50 */
			{22182,38,0}, /* core0 sp_EL3 bit51 */
			{22172,38,0}, /* core0 sp_EL3 bit52 */
			{22170,38,0}, /* core0 sp_EL3 bit53 */
			{22168,38,0}, /* core0 sp_EL3 bit54 */
			{22166,38,0}, /* core0 sp_EL3 bit55 */
			{22180,38,0}, /* core0 sp_EL3 bit56 */
			{22178,38,0}, /* core0 sp_EL3 bit57 */
			{22176,38,0}, /* core0 sp_EL3 bit58 */
			{22174,38,0}, /* core0 sp_EL3 bit59 */
			{22164,38,0}, /* core0 sp_EL3 bit60 */
			{22162,38,0}, /* core0 sp_EL3 bit61 */
			{22160,38,0}, /* core0 sp_EL3 bit62 */
			{22158,38,0}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{21836,38,0}, /* core0 elr_EL1 bit0 */
			{21552,38,0}, /* core0 elr_EL1 bit1 */
			{21606,38,0}, /* core0 elr_EL1 bit2 */
			{21604,38,0}, /* core0 elr_EL1 bit3 */
			{21602,38,0}, /* core0 elr_EL1 bit4 */
			{21600,38,0}, /* core0 elr_EL1 bit5 */
			{21598,38,0}, /* core0 elr_EL1 bit6 */
			{21596,38,0}, /* core0 elr_EL1 bit7 */
			{21594,38,0}, /* core0 elr_EL1 bit8 */
			{21834,38,0}, /* core0 elr_EL1 bit9 */
			{21592,38,0}, /* core0 elr_EL1 bit10 */
			{21614,38,0}, /* core0 elr_EL1 bit11 */
			{21612,38,0}, /* core0 elr_EL1 bit12 */
			{21610,38,0}, /* core0 elr_EL1 bit13 */
			{21832,38,0}, /* core0 elr_EL1 bit14 */
			{14362,38,0}, /* core0 elr_EL1 bit15 */
			{21830,38,0}, /* core0 elr_EL1 bit16 */
			{21608,38,0}, /* core0 elr_EL1 bit17 */
			{21582,38,0}, /* core0 elr_EL1 bit18 */
			{21580,38,0}, /* core0 elr_EL1 bit19 */
			{21558,38,0}, /* core0 elr_EL1 bit20 */
			{14414,38,0}, /* core0 elr_EL1 bit21 */
			{21578,38,0}, /* core0 elr_EL1 bit22 */
			{21556,38,0}, /* core0 elr_EL1 bit23 */
			{21576,38,0}, /* core0 elr_EL1 bit24 */
			{21542,38,0}, /* core0 elr_EL1 bit25 */
			{21554,38,0}, /* core0 elr_EL1 bit26 */
			{21540,38,0}, /* core0 elr_EL1 bit27 */
			{21538,38,0}, /* core0 elr_EL1 bit28 */
			{14360,38,0}, /* core0 elr_EL1 bit29 */
			{21536,38,0}, /* core0 elr_EL1 bit30 */
			{14412,38,0}, /* core0 elr_EL1 bit31 */
			{21478,38,0}, /* core0 elr_EL1 bit32 */
			{21486,38,0}, /* core0 elr_EL1 bit33 */
			{21484,38,0}, /* core0 elr_EL1 bit34 */
			{21476,38,0}, /* core0 elr_EL1 bit35 */
			{21474,38,0}, /* core0 elr_EL1 bit36 */
			{21472,38,0}, /* core0 elr_EL1 bit37 */
			{14322,38,0}, /* core0 elr_EL1 bit38 */
			{14320,38,0}, /* core0 elr_EL1 bit39 */
			{21482,38,0}, /* core0 elr_EL1 bit40 */
			{21480,38,0}, /* core0 elr_EL1 bit41 */
			{21494,38,0}, /* core0 elr_EL1 bit42 */
			{21492,38,0}, /* core0 elr_EL1 bit43 */
			{21490,38,0}, /* core0 elr_EL1 bit44 */
			{21488,38,0}, /* core0 elr_EL1 bit45 */
			{21502,38,0}, /* core0 elr_EL1 bit46 */
			{21500,38,0}, /* core0 elr_EL1 bit47 */
			{21498,38,0}, /* core0 elr_EL1 bit48 */
			{21496,38,0}, /* core0 elr_EL1 bit49 */
			{21510,38,0}, /* core0 elr_EL1 bit50 */
			{21508,38,0}, /* core0 elr_EL1 bit51 */
			{21506,38,0}, /* core0 elr_EL1 bit52 */
			{21504,38,0}, /* core0 elr_EL1 bit53 */
			{21518,38,0}, /* core0 elr_EL1 bit54 */
			{21516,38,0}, /* core0 elr_EL1 bit55 */
			{21514,38,0}, /* core0 elr_EL1 bit56 */
			{21512,38,0}, /* core0 elr_EL1 bit57 */
			{21526,38,0}, /* core0 elr_EL1 bit58 */
			{21524,38,0}, /* core0 elr_EL1 bit59 */
			{21522,38,0}, /* core0 elr_EL1 bit60 */
			{21520,38,0}, /* core0 elr_EL1 bit61 */
			{14318,38,0}, /* core0 elr_EL1 bit62 */
			{14316,38,0}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{21590,38,0}, /* core0 elr_EL2 bit0 */
			{21588,38,0}, /* core0 elr_EL2 bit1 */
			{21586,38,0}, /* core0 elr_EL2 bit2 */
			{21584,38,0}, /* core0 elr_EL2 bit3 */
			{21638,38,0}, /* core0 elr_EL2 bit4 */
			{21636,38,0}, /* core0 elr_EL2 bit5 */
			{21634,38,0}, /* core0 elr_EL2 bit6 */
			{21632,38,0}, /* core0 elr_EL2 bit7 */
			{21550,38,0}, /* core0 elr_EL2 bit8 */
			{21548,38,0}, /* core0 elr_EL2 bit9 */
			{21546,38,0}, /* core0 elr_EL2 bit10 */
			{21544,38,0}, /* core0 elr_EL2 bit11 */
			{21574,38,0}, /* core0 elr_EL2 bit12 */
			{21572,38,0}, /* core0 elr_EL2 bit13 */
			{21570,38,0}, /* core0 elr_EL2 bit14 */
			{14358,38,0}, /* core0 elr_EL2 bit15 */
			{21568,38,0}, /* core0 elr_EL2 bit16 */
			{21622,38,0}, /* core0 elr_EL2 bit17 */
			{21620,38,0}, /* core0 elr_EL2 bit18 */
			{21618,38,0}, /* core0 elr_EL2 bit19 */
			{21616,38,0}, /* core0 elr_EL2 bit20 */
			{14418,38,0}, /* core0 elr_EL2 bit21 */
			{21566,38,0}, /* core0 elr_EL2 bit22 */
			{21564,38,0}, /* core0 elr_EL2 bit23 */
			{21562,38,0}, /* core0 elr_EL2 bit24 */
			{21560,38,0}, /* core0 elr_EL2 bit25 */
			{21534,38,0}, /* core0 elr_EL2 bit26 */
			{21532,38,0}, /* core0 elr_EL2 bit27 */
			{21530,38,0}, /* core0 elr_EL2 bit28 */
			{14356,38,0}, /* core0 elr_EL2 bit29 */
			{21528,38,0}, /* core0 elr_EL2 bit30 */
			{14416,38,0}, /* core0 elr_EL2 bit31 */
			{21462,38,0}, /* core0 elr_EL2 bit32 */
			{21460,38,0}, /* core0 elr_EL2 bit33 */
			{21458,38,0}, /* core0 elr_EL2 bit34 */
			{21456,38,0}, /* core0 elr_EL2 bit35 */
			{21454,38,0}, /* core0 elr_EL2 bit36 */
			{21452,38,0}, /* core0 elr_EL2 bit37 */
			{21450,38,0}, /* core0 elr_EL2 bit38 */
			{21448,38,0}, /* core0 elr_EL2 bit39 */
			{21438,38,0}, /* core0 elr_EL2 bit40 */
			{21436,38,0}, /* core0 elr_EL2 bit41 */
			{21434,38,0}, /* core0 elr_EL2 bit42 */
			{21432,38,0}, /* core0 elr_EL2 bit43 */
			{21446,38,0}, /* core0 elr_EL2 bit44 */
			{21444,38,0}, /* core0 elr_EL2 bit45 */
			{21442,38,0}, /* core0 elr_EL2 bit46 */
			{21440,38,0}, /* core0 elr_EL2 bit47 */
			{21470,38,0}, /* core0 elr_EL2 bit48 */
			{21468,38,0}, /* core0 elr_EL2 bit49 */
			{21466,38,0}, /* core0 elr_EL2 bit50 */
			{21464,38,0}, /* core0 elr_EL2 bit51 */
			{21430,38,0}, /* core0 elr_EL2 bit52 */
			{21428,38,0}, /* core0 elr_EL2 bit53 */
			{21426,38,0}, /* core0 elr_EL2 bit54 */
			{21424,38,0}, /* core0 elr_EL2 bit55 */
			{21422,38,0}, /* core0 elr_EL2 bit56 */
			{21420,38,0}, /* core0 elr_EL2 bit57 */
			{21418,38,0}, /* core0 elr_EL2 bit58 */
			{21416,38,0}, /* core0 elr_EL2 bit59 */
			{21414,38,0}, /* core0 elr_EL2 bit60 */
			{21412,38,0}, /* core0 elr_EL2 bit61 */
			{21410,38,0}, /* core0 elr_EL2 bit62 */
			{21408,38,0}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 6990,38,0}, /* core0 elr_EL3 bit0 */
			{ 7002,38,0}, /* core0 elr_EL3 bit1 */
			{14404,38,0}, /* core0 elr_EL3 bit2 */
			{14382,38,0}, /* core0 elr_EL3 bit3 */
			{14386,38,0}, /* core0 elr_EL3 bit4 */
			{14380,38,0}, /* core0 elr_EL3 bit5 */
			{14378,38,0}, /* core0 elr_EL3 bit6 */
			{14376,38,0}, /* core0 elr_EL3 bit7 */
			{14370,38,0}, /* core0 elr_EL3 bit8 */
			{14366,38,0}, /* core0 elr_EL3 bit9 */
			{14344,38,0}, /* core0 elr_EL3 bit10 */
			{14384,38,0}, /* core0 elr_EL3 bit11 */
			{14374,38,0}, /* core0 elr_EL3 bit12 */
			{14372,38,0}, /* core0 elr_EL3 bit13 */
			{14410,38,0}, /* core0 elr_EL3 bit14 */
			{14352,38,0}, /* core0 elr_EL3 bit15 */
			{21630,38,0}, /* core0 elr_EL3 bit16 */
			{21628,38,0}, /* core0 elr_EL3 bit17 */
			{14408,38,0}, /* core0 elr_EL3 bit18 */
			{14406,38,0}, /* core0 elr_EL3 bit19 */
			{21626,38,0}, /* core0 elr_EL3 bit20 */
			{ 6992,38,0}, /* core0 elr_EL3 bit21 */
			{21624,38,0}, /* core0 elr_EL3 bit22 */
			{14368,38,0}, /* core0 elr_EL3 bit23 */
			{14364,38,0}, /* core0 elr_EL3 bit24 */
			{14342,38,0}, /* core0 elr_EL3 bit25 */
			{14350,38,0}, /* core0 elr_EL3 bit26 */
			{14348,38,0}, /* core0 elr_EL3 bit27 */
			{14340,38,0}, /* core0 elr_EL3 bit28 */
			{14354,38,0}, /* core0 elr_EL3 bit29 */
			{ 7004,38,0}, /* core0 elr_EL3 bit30 */
			{14346,38,0}, /* core0 elr_EL3 bit31 */
			{14298,38,0}, /* core0 elr_EL3 bit32 */
			{14296,38,0}, /* core0 elr_EL3 bit33 */
			{14290,38,0}, /* core0 elr_EL3 bit34 */
			{14294,38,0}, /* core0 elr_EL3 bit35 */
			{14288,38,0}, /* core0 elr_EL3 bit36 */
			{14292,38,0}, /* core0 elr_EL3 bit37 */
			{ 6854,38,0}, /* core0 elr_EL3 bit38 */
			{14282,38,0}, /* core0 elr_EL3 bit39 */
			{14286,38,0}, /* core0 elr_EL3 bit40 */
			{14254,38,0}, /* core0 elr_EL3 bit41 */
			{14284,38,0}, /* core0 elr_EL3 bit42 */
			{14252,38,0}, /* core0 elr_EL3 bit43 */
			{14278,38,0}, /* core0 elr_EL3 bit44 */
			{14274,38,0}, /* core0 elr_EL3 bit45 */
			{ 6856,38,0}, /* core0 elr_EL3 bit46 */
			{14272,38,0}, /* core0 elr_EL3 bit47 */
			{14276,38,0}, /* core0 elr_EL3 bit48 */
			{21406,38,0}, /* core0 elr_EL3 bit49 */
			{14250,38,0}, /* core0 elr_EL3 bit50 */
			{21398,38,0}, /* core0 elr_EL3 bit51 */
			{21396,38,0}, /* core0 elr_EL3 bit52 */
			{21394,38,0}, /* core0 elr_EL3 bit53 */
			{21392,38,0}, /* core0 elr_EL3 bit54 */
			{21390,38,0}, /* core0 elr_EL3 bit55 */
			{21388,38,0}, /* core0 elr_EL3 bit56 */
			{21386,38,0}, /* core0 elr_EL3 bit57 */
			{21404,38,0}, /* core0 elr_EL3 bit58 */
			{21384,38,0}, /* core0 elr_EL3 bit59 */
			{14280,38,0}, /* core0 elr_EL3 bit60 */
			{14248,38,0}, /* core0 elr_EL3 bit61 */
			{21402,38,0}, /* core0 elr_EL3 bit62 */
			{21400,38,0}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{20350,38,0}, /* core0 raw_pc bit0 */
			{19196,37,0}, /* core0 raw_pc bit1 */
			{19194,37,0}, /* core0 raw_pc bit2 */
			{19192,37,0}, /* core0 raw_pc bit3 */
			{19190,37,0}, /* core0 raw_pc bit4 */
			{20348,38,0}, /* core0 raw_pc bit5 */
			{20346,38,0}, /* core0 raw_pc bit6 */
			{19180,37,0}, /* core0 raw_pc bit7 */
			{19178,37,0}, /* core0 raw_pc bit8 */
			{19176,37,0}, /* core0 raw_pc bit9 */
			{19174,37,0}, /* core0 raw_pc bit10 */
			{19154,37,0}, /* core0 raw_pc bit11 */
			{19152,37,0}, /* core0 raw_pc bit12 */
			{19150,37,0}, /* core0 raw_pc bit13 */
			{19148,37,0}, /* core0 raw_pc bit14 */
			{19168,37,0}, /* core0 raw_pc bit15 */
			{19166,37,0}, /* core0 raw_pc bit16 */
			{19164,37,0}, /* core0 raw_pc bit17 */
			{19162,37,0}, /* core0 raw_pc bit18 */
			{19170,37,0}, /* core0 raw_pc bit19 */
			{19160,37,0}, /* core0 raw_pc bit20 */
			{19158,37,0}, /* core0 raw_pc bit21 */
			{19156,37,0}, /* core0 raw_pc bit22 */
			{19138,37,0}, /* core0 raw_pc bit23 */
			{19136,37,0}, /* core0 raw_pc bit24 */
			{19134,37,0}, /* core0 raw_pc bit25 */
			{19132,37,0}, /* core0 raw_pc bit26 */
			{19146,37,0}, /* core0 raw_pc bit27 */
			{19144,37,0}, /* core0 raw_pc bit28 */
			{19142,37,0}, /* core0 raw_pc bit29 */
			{19140,37,0}, /* core0 raw_pc bit30 */
			{18854,37,0}, /* core0 raw_pc bit31 */
			{18852,37,0}, /* core0 raw_pc bit32 */
			{18850,37,0}, /* core0 raw_pc bit33 */
			{18848,37,0}, /* core0 raw_pc bit34 */
			{18862,37,0}, /* core0 raw_pc bit35 */
			{18860,37,0}, /* core0 raw_pc bit36 */
			{18858,37,0}, /* core0 raw_pc bit37 */
			{18856,37,0}, /* core0 raw_pc bit38 */
			{18846,37,0}, /* core0 raw_pc bit39 */
			{18844,37,0}, /* core0 raw_pc bit40 */
			{18842,37,0}, /* core0 raw_pc bit41 */
			{18840,37,0}, /* core0 raw_pc bit42 */
			{18838,37,0}, /* core0 raw_pc bit43 */
			{18836,37,0}, /* core0 raw_pc bit44 */
			{18834,37,0}, /* core0 raw_pc bit45 */
			{18832,37,0}, /* core0 raw_pc bit46 */
			{11668,38,0}, /* core0 raw_pc bit47 */
			{20380,38,0}, /* core0 raw_pc bit48 */
			{20378,38,0}, /* core0 raw_pc bit49 */
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
			{12108,38,0}, /* core0 pc_iss bit0 */
			{12106,38,0}, /* core0 pc_iss bit1 */
			{12102,38,0}, /* core0 pc_iss bit2 */
			{20292,38,0}, /* core0 pc_iss bit3 */
			{20290,38,0}, /* core0 pc_iss bit4 */
			{20288,38,0}, /* core0 pc_iss bit5 */
			{20286,38,0}, /* core0 pc_iss bit6 */
			{12104,38,0}, /* core0 pc_iss bit7 */
			{20296,38,0}, /* core0 pc_iss bit8 */
			{20294,38,0}, /* core0 pc_iss bit9 */
			{20474,38,0}, /* core0 pc_iss bit10 */
			{20284,38,0}, /* core0 pc_iss bit11 */
			{20304,38,0}, /* core0 pc_iss bit12 */
			{20282,38,0}, /* core0 pc_iss bit13 */
			{20300,38,0}, /* core0 pc_iss bit14 */
			{20298,38,0}, /* core0 pc_iss bit15 */
			{20302,38,0}, /* core0 pc_iss bit16 */
			{20308,38,0}, /* core0 pc_iss bit17 */
			{20306,38,0}, /* core0 pc_iss bit18 */
			{20312,38,0}, /* core0 pc_iss bit19 */
			{20310,38,0}, /* core0 pc_iss bit20 */
			{20316,38,0}, /* core0 pc_iss bit21 */
			{20314,38,0}, /* core0 pc_iss bit22 */
			{20480,38,0}, /* core0 pc_iss bit23 */
			{20476,38,0}, /* core0 pc_iss bit24 */
			{20478,38,0}, /* core0 pc_iss bit25 */
			{20484,38,0}, /* core0 pc_iss bit26 */
			{20482,38,0}, /* core0 pc_iss bit27 */
			{20472,38,0}, /* core0 pc_iss bit28 */
			{20470,38,0}, /* core0 pc_iss bit29 */
			{20488,38,0}, /* core0 pc_iss bit30 */
			{20486,38,0}, /* core0 pc_iss bit31 */
			{19454,37,0}, /* core0 pc_iss bit32 */
			{20456,38,0}, /* core0 pc_iss bit33 */
			{20454,38,0}, /* core0 pc_iss bit34 */
			{20448,38,0}, /* core0 pc_iss bit35 */
			{20452,38,0}, /* core0 pc_iss bit36 */
			{20446,38,0}, /* core0 pc_iss bit37 */
			{20444,38,0}, /* core0 pc_iss bit38 */
			{20450,38,0}, /* core0 pc_iss bit39 */
			{20460,38,0}, /* core0 pc_iss bit40 */
			{20458,38,0}, /* core0 pc_iss bit41 */
			{20442,38,0}, /* core0 pc_iss bit42 */
			{20464,38,0}, /* core0 pc_iss bit43 */
			{20462,38,0}, /* core0 pc_iss bit44 */
			{19188,37,0}, /* core0 pc_iss bit45 */
			{19186,37,0}, /* core0 pc_iss bit46 */
			{19184,37,0}, /* core0 pc_iss bit47 */
			{19182,37,0}, /* core0 pc_iss bit48 */
			{19484,37,0}, /* core0 pc_iss bit49 */
			{19482,37,0}, /* core0 pc_iss bit50 */
			{19480,37,0}, /* core0 pc_iss bit51 */
			{19478,37,0}, /* core0 pc_iss bit52 */
			{19476,37,0}, /* core0 pc_iss bit53 */
			{19474,37,0}, /* core0 pc_iss bit54 */
			{19472,37,0}, /* core0 pc_iss bit55 */
			{19470,37,0}, /* core0 pc_iss bit56 */
			{19468,37,0}, /* core0 pc_iss bit57 */
			{19466,37,0}, /* core0 pc_iss bit58 */
			{19464,37,0}, /* core0 pc_iss bit59 */
			{19462,37,0}, /* core0 pc_iss bit60 */
			{19460,37,0}, /* core0 pc_iss bit61 */
			{19458,37,0}, /* core0 pc_iss bit62 */
			{19456,37,0}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{20352,38,0}, /* core0 full_pc_wr bit0 */
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
			{19404,37,0}, /* core0 full_pc_ex1 bit0 */
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
			{20280,38,0}, /* core0 full_pc_ex2 bit0 */
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
			{ 3944,39,0}, /* core0 return_Stack_pointer bit0 */
			{ 3948,39,0}, /* core0 return_Stack_pointer bit1 */
			{ 3942,39,0}, /* core0 return_Stack_pointer bit2 */
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
			{19558,39,0}, /* core0 return_Stack0 bit0 */
			{19550,39,0}, /* core0 return_Stack0 bit1 */
			{19548,39,0}, /* core0 return_Stack0 bit2 */
			{19546,39,0}, /* core0 return_Stack0 bit3 */
			{19544,39,0}, /* core0 return_Stack0 bit4 */
			{ 9376,39,0}, /* core0 return_Stack0 bit5 */
			{19502,39,0}, /* core0 return_Stack0 bit6 */
			{19500,39,0}, /* core0 return_Stack0 bit7 */
			{19498,39,0}, /* core0 return_Stack0 bit8 */
			{19496,39,0}, /* core0 return_Stack0 bit9 */
			{19478,39,0}, /* core0 return_Stack0 bit10 */
			{ 9374,39,0}, /* core0 return_Stack0 bit11 */
			{19476,39,0}, /* core0 return_Stack0 bit12 */
			{19474,39,0}, /* core0 return_Stack0 bit13 */
			{19472,39,0}, /* core0 return_Stack0 bit14 */
			{19470,39,0}, /* core0 return_Stack0 bit15 */
			{19468,39,0}, /* core0 return_Stack0 bit16 */
			{19466,39,0}, /* core0 return_Stack0 bit17 */
			{19464,39,0}, /* core0 return_Stack0 bit18 */
			{19486,39,0}, /* core0 return_Stack0 bit19 */
			{19484,39,0}, /* core0 return_Stack0 bit20 */
			{19482,39,0}, /* core0 return_Stack0 bit21 */
			{19480,39,0}, /* core0 return_Stack0 bit22 */
			{ 9384,39,0}, /* core0 return_Stack0 bit23 */
			{ 9382,39,0}, /* core0 return_Stack0 bit24 */
			{19556,39,0}, /* core0 return_Stack0 bit25 */
			{ 3830,39,0}, /* core0 return_Stack0 bit26 */
			{19554,39,0}, /* core0 return_Stack0 bit27 */
			{19552,39,0}, /* core0 return_Stack0 bit28 */
			{19542,39,0}, /* core0 return_Stack0 bit29 */
			{19540,39,0}, /* core0 return_Stack0 bit30 */
			{19538,39,0}, /* core0 return_Stack0 bit31 */
			{19536,39,0}, /* core0 return_Stack0 bit32 */
			{19534,39,0}, /* core0 return_Stack0 bit33 */
			{19532,39,0}, /* core0 return_Stack0 bit34 */
			{19530,39,0}, /* core0 return_Stack0 bit35 */
			{19528,39,0}, /* core0 return_Stack0 bit36 */
			{19526,39,0}, /* core0 return_Stack0 bit37 */
			{19524,39,0}, /* core0 return_Stack0 bit38 */
			{19522,39,0}, /* core0 return_Stack0 bit39 */
			{19520,39,0}, /* core0 return_Stack0 bit40 */
			{19518,39,0}, /* core0 return_Stack0 bit41 */
			{19516,39,0}, /* core0 return_Stack0 bit42 */
			{19514,39,0}, /* core0 return_Stack0 bit43 */
			{19512,39,0}, /* core0 return_Stack0 bit44 */
			{19510,39,0}, /* core0 return_Stack0 bit45 */
			{19508,39,0}, /* core0 return_Stack0 bit46 */
			{19506,39,0}, /* core0 return_Stack0 bit47 */
			{19504,39,0}, /* core0 return_Stack0 bit48 */
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
			{19566,39,0}, /* core0 return_Stack1 bit0 */
			{19574,39,0}, /* core0 return_Stack1 bit1 */
			{19572,39,0}, /* core0 return_Stack1 bit2 */
			{19570,39,0}, /* core0 return_Stack1 bit3 */
			{19568,39,0}, /* core0 return_Stack1 bit4 */
			{ 9380,39,0}, /* core0 return_Stack1 bit5 */
			{19494,39,0}, /* core0 return_Stack1 bit6 */
			{19492,39,0}, /* core0 return_Stack1 bit7 */
			{19490,39,0}, /* core0 return_Stack1 bit8 */
			{19488,39,0}, /* core0 return_Stack1 bit9 */
			{19462,39,0}, /* core0 return_Stack1 bit10 */
			{ 9378,39,0}, /* core0 return_Stack1 bit11 */
			{19460,39,0}, /* core0 return_Stack1 bit12 */
			{19458,39,0}, /* core0 return_Stack1 bit13 */
			{19456,39,0}, /* core0 return_Stack1 bit14 */
			{19204,39,0}, /* core0 return_Stack1 bit15 */
			{19202,39,0}, /* core0 return_Stack1 bit16 */
			{19200,39,0}, /* core0 return_Stack1 bit17 */
			{19198,39,0}, /* core0 return_Stack1 bit18 */
			{19188,39,0}, /* core0 return_Stack1 bit19 */
			{19186,39,0}, /* core0 return_Stack1 bit20 */
			{19184,39,0}, /* core0 return_Stack1 bit21 */
			{19182,39,0}, /* core0 return_Stack1 bit22 */
			{ 9388,39,0}, /* core0 return_Stack1 bit23 */
			{ 9386,39,0}, /* core0 return_Stack1 bit24 */
			{19564,39,0}, /* core0 return_Stack1 bit25 */
			{ 3828,39,0}, /* core0 return_Stack1 bit26 */
			{19562,39,0}, /* core0 return_Stack1 bit27 */
			{19560,39,0}, /* core0 return_Stack1 bit28 */
			{19164,39,0}, /* core0 return_Stack1 bit29 */
			{19162,39,0}, /* core0 return_Stack1 bit30 */
			{19160,39,0}, /* core0 return_Stack1 bit31 */
			{19158,39,0}, /* core0 return_Stack1 bit32 */
			{19124,39,0}, /* core0 return_Stack1 bit33 */
			{19122,39,0}, /* core0 return_Stack1 bit34 */
			{19120,39,0}, /* core0 return_Stack1 bit35 */
			{19118,39,0}, /* core0 return_Stack1 bit36 */
			{19116,39,0}, /* core0 return_Stack1 bit37 */
			{19114,39,0}, /* core0 return_Stack1 bit38 */
			{19112,39,0}, /* core0 return_Stack1 bit39 */
			{19110,39,0}, /* core0 return_Stack1 bit40 */
			{19076,39,0}, /* core0 return_Stack1 bit41 */
			{19074,39,0}, /* core0 return_Stack1 bit42 */
			{19072,39,0}, /* core0 return_Stack1 bit43 */
			{19070,39,0}, /* core0 return_Stack1 bit44 */
			{19068,39,0}, /* core0 return_Stack1 bit45 */
			{19066,39,0}, /* core0 return_Stack1 bit46 */
			{19064,39,0}, /* core0 return_Stack1 bit47 */
			{19062,39,0}, /* core0 return_Stack1 bit48 */
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
			{19372,39,0}, /* core0 return_Stack2 bit0 */
			{19370,39,0}, /* core0 return_Stack2 bit1 */
			{19368,39,0}, /* core0 return_Stack2 bit2 */
			{19366,39,0}, /* core0 return_Stack2 bit3 */
			{19060,39,0}, /* core0 return_Stack2 bit4 */
			{19058,39,0}, /* core0 return_Stack2 bit5 */
			{19056,39,0}, /* core0 return_Stack2 bit6 */
			{19054,39,0}, /* core0 return_Stack2 bit7 */
			{19196,39,0}, /* core0 return_Stack2 bit8 */
			{19194,39,0}, /* core0 return_Stack2 bit9 */
			{19192,39,0}, /* core0 return_Stack2 bit10 */
			{19190,39,0}, /* core0 return_Stack2 bit11 */
			{19260,39,0}, /* core0 return_Stack2 bit12 */
			{19258,39,0}, /* core0 return_Stack2 bit13 */
			{19256,39,0}, /* core0 return_Stack2 bit14 */
			{19254,39,0}, /* core0 return_Stack2 bit15 */
			{19244,39,0}, /* core0 return_Stack2 bit16 */
			{19242,39,0}, /* core0 return_Stack2 bit17 */
			{19240,39,0}, /* core0 return_Stack2 bit18 */
			{19238,39,0}, /* core0 return_Stack2 bit19 */
			{19308,39,0}, /* core0 return_Stack2 bit20 */
			{19306,39,0}, /* core0 return_Stack2 bit21 */
			{19304,39,0}, /* core0 return_Stack2 bit22 */
			{19302,39,0}, /* core0 return_Stack2 bit23 */
			{19340,39,0}, /* core0 return_Stack2 bit24 */
			{19338,39,0}, /* core0 return_Stack2 bit25 */
			{19336,39,0}, /* core0 return_Stack2 bit26 */
			{19334,39,0}, /* core0 return_Stack2 bit27 */
			{19404,39,0}, /* core0 return_Stack2 bit28 */
			{19402,39,0}, /* core0 return_Stack2 bit29 */
			{19400,39,0}, /* core0 return_Stack2 bit30 */
			{19398,39,0}, /* core0 return_Stack2 bit31 */
			{19140,39,0}, /* core0 return_Stack2 bit32 */
			{19138,39,0}, /* core0 return_Stack2 bit33 */
			{19136,39,0}, /* core0 return_Stack2 bit34 */
			{19134,39,0}, /* core0 return_Stack2 bit35 */
			{19420,39,0}, /* core0 return_Stack2 bit36 */
			{19418,39,0}, /* core0 return_Stack2 bit37 */
			{19416,39,0}, /* core0 return_Stack2 bit38 */
			{19414,39,0}, /* core0 return_Stack2 bit39 */
			{19100,39,0}, /* core0 return_Stack2 bit40 */
			{19098,39,0}, /* core0 return_Stack2 bit41 */
			{19096,39,0}, /* core0 return_Stack2 bit42 */
			{19094,39,0}, /* core0 return_Stack2 bit43 */
			{19044,39,0}, /* core0 return_Stack2 bit44 */
			{19042,39,0}, /* core0 return_Stack2 bit45 */
			{19040,39,0}, /* core0 return_Stack2 bit46 */
			{19038,39,0}, /* core0 return_Stack2 bit47 */
			{ 3838,39,0}, /* core0 return_Stack2 bit48 */
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
			{19380,39,0}, /* core0 return_Stack3 bit0 */
			{19378,39,0}, /* core0 return_Stack3 bit1 */
			{19376,39,0}, /* core0 return_Stack3 bit2 */
			{19374,39,0}, /* core0 return_Stack3 bit3 */
			{19180,39,0}, /* core0 return_Stack3 bit4 */
			{19178,39,0}, /* core0 return_Stack3 bit5 */
			{ 3836,39,0}, /* core0 return_Stack3 bit6 */
			{19176,39,0}, /* core0 return_Stack3 bit7 */
			{19174,39,0}, /* core0 return_Stack3 bit8 */
			{19276,39,0}, /* core0 return_Stack3 bit9 */
			{19274,39,0}, /* core0 return_Stack3 bit10 */
			{19272,39,0}, /* core0 return_Stack3 bit11 */
			{19270,39,0}, /* core0 return_Stack3 bit12 */
			{19252,39,0}, /* core0 return_Stack3 bit13 */
			{19250,39,0}, /* core0 return_Stack3 bit14 */
			{19248,39,0}, /* core0 return_Stack3 bit15 */
			{19246,39,0}, /* core0 return_Stack3 bit16 */
			{19268,39,0}, /* core0 return_Stack3 bit17 */
			{19266,39,0}, /* core0 return_Stack3 bit18 */
			{19264,39,0}, /* core0 return_Stack3 bit19 */
			{19262,39,0}, /* core0 return_Stack3 bit20 */
			{19324,39,0}, /* core0 return_Stack3 bit21 */
			{19322,39,0}, /* core0 return_Stack3 bit22 */
			{19320,39,0}, /* core0 return_Stack3 bit23 */
			{19318,39,0}, /* core0 return_Stack3 bit24 */
			{19356,39,0}, /* core0 return_Stack3 bit25 */
			{19354,39,0}, /* core0 return_Stack3 bit26 */
			{19352,39,0}, /* core0 return_Stack3 bit27 */
			{19350,39,0}, /* core0 return_Stack3 bit28 */
			{19412,39,0}, /* core0 return_Stack3 bit29 */
			{19410,39,0}, /* core0 return_Stack3 bit30 */
			{19408,39,0}, /* core0 return_Stack3 bit31 */
			{19406,39,0}, /* core0 return_Stack3 bit32 */
			{19436,39,0}, /* core0 return_Stack3 bit33 */
			{19434,39,0}, /* core0 return_Stack3 bit34 */
			{19432,39,0}, /* core0 return_Stack3 bit35 */
			{19430,39,0}, /* core0 return_Stack3 bit36 */
			{19428,39,0}, /* core0 return_Stack3 bit37 */
			{19426,39,0}, /* core0 return_Stack3 bit38 */
			{19424,39,0}, /* core0 return_Stack3 bit39 */
			{19422,39,0}, /* core0 return_Stack3 bit40 */
			{19084,39,0}, /* core0 return_Stack3 bit41 */
			{19082,39,0}, /* core0 return_Stack3 bit42 */
			{19080,39,0}, /* core0 return_Stack3 bit43 */
			{19078,39,0}, /* core0 return_Stack3 bit44 */
			{19036,39,0}, /* core0 return_Stack3 bit45 */
			{19034,39,0}, /* core0 return_Stack3 bit46 */
			{19032,39,0}, /* core0 return_Stack3 bit47 */
			{19030,39,0}, /* core0 return_Stack3 bit48 */
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
			{19388,39,0}, /* core0 return_Stack4 bit0 */
			{19386,39,0}, /* core0 return_Stack4 bit1 */
			{19384,39,0}, /* core0 return_Stack4 bit2 */
			{19382,39,0}, /* core0 return_Stack4 bit3 */
			{19052,39,0}, /* core0 return_Stack4 bit4 */
			{19050,39,0}, /* core0 return_Stack4 bit5 */
			{19048,39,0}, /* core0 return_Stack4 bit6 */
			{19046,39,0}, /* core0 return_Stack4 bit7 */
			{19292,39,0}, /* core0 return_Stack4 bit8 */
			{19290,39,0}, /* core0 return_Stack4 bit9 */
			{19288,39,0}, /* core0 return_Stack4 bit10 */
			{19286,39,0}, /* core0 return_Stack4 bit11 */
			{19236,39,0}, /* core0 return_Stack4 bit12 */
			{19234,39,0}, /* core0 return_Stack4 bit13 */
			{19232,39,0}, /* core0 return_Stack4 bit14 */
			{19230,39,0}, /* core0 return_Stack4 bit15 */
			{19228,39,0}, /* core0 return_Stack4 bit16 */
			{19226,39,0}, /* core0 return_Stack4 bit17 */
			{19224,39,0}, /* core0 return_Stack4 bit18 */
			{19222,39,0}, /* core0 return_Stack4 bit19 */
			{19316,39,0}, /* core0 return_Stack4 bit20 */
			{19314,39,0}, /* core0 return_Stack4 bit21 */
			{19312,39,0}, /* core0 return_Stack4 bit22 */
			{19310,39,0}, /* core0 return_Stack4 bit23 */
			{19332,39,0}, /* core0 return_Stack4 bit24 */
			{19330,39,0}, /* core0 return_Stack4 bit25 */
			{19328,39,0}, /* core0 return_Stack4 bit26 */
			{19326,39,0}, /* core0 return_Stack4 bit27 */
			{19396,39,0}, /* core0 return_Stack4 bit28 */
			{19394,39,0}, /* core0 return_Stack4 bit29 */
			{19392,39,0}, /* core0 return_Stack4 bit30 */
			{19390,39,0}, /* core0 return_Stack4 bit31 */
			{19452,39,0}, /* core0 return_Stack4 bit32 */
			{19450,39,0}, /* core0 return_Stack4 bit33 */
			{19448,39,0}, /* core0 return_Stack4 bit34 */
			{19446,39,0}, /* core0 return_Stack4 bit35 */
			{19444,39,0}, /* core0 return_Stack4 bit36 */
			{19442,39,0}, /* core0 return_Stack4 bit37 */
			{19440,39,0}, /* core0 return_Stack4 bit38 */
			{19438,39,0}, /* core0 return_Stack4 bit39 */
			{19108,39,0}, /* core0 return_Stack4 bit40 */
			{19106,39,0}, /* core0 return_Stack4 bit41 */
			{19104,39,0}, /* core0 return_Stack4 bit42 */
			{19102,39,0}, /* core0 return_Stack4 bit43 */
			{19028,39,0}, /* core0 return_Stack4 bit44 */
			{19026,39,0}, /* core0 return_Stack4 bit45 */
			{19024,39,0}, /* core0 return_Stack4 bit46 */
			{19022,39,0}, /* core0 return_Stack4 bit47 */
			{ 3832,39,0}, /* core0 return_Stack4 bit48 */
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
			{19364,39,0}, /* core0 return_Stack5 bit0 */
			{19362,39,0}, /* core0 return_Stack5 bit1 */
			{19360,39,0}, /* core0 return_Stack5 bit2 */
			{19358,39,0}, /* core0 return_Stack5 bit3 */
			{19172,39,0}, /* core0 return_Stack5 bit4 */
			{19170,39,0}, /* core0 return_Stack5 bit5 */
			{19168,39,0}, /* core0 return_Stack5 bit6 */
			{19166,39,0}, /* core0 return_Stack5 bit7 */
			{19284,39,0}, /* core0 return_Stack5 bit8 */
			{19282,39,0}, /* core0 return_Stack5 bit9 */
			{19280,39,0}, /* core0 return_Stack5 bit10 */
			{19278,39,0}, /* core0 return_Stack5 bit11 */
			{19212,39,0}, /* core0 return_Stack5 bit12 */
			{19210,39,0}, /* core0 return_Stack5 bit13 */
			{19208,39,0}, /* core0 return_Stack5 bit14 */
			{19206,39,0}, /* core0 return_Stack5 bit15 */
			{19220,39,0}, /* core0 return_Stack5 bit16 */
			{19218,39,0}, /* core0 return_Stack5 bit17 */
			{19216,39,0}, /* core0 return_Stack5 bit18 */
			{19214,39,0}, /* core0 return_Stack5 bit19 */
			{19300,39,0}, /* core0 return_Stack5 bit20 */
			{19298,39,0}, /* core0 return_Stack5 bit21 */
			{19296,39,0}, /* core0 return_Stack5 bit22 */
			{19294,39,0}, /* core0 return_Stack5 bit23 */
			{19348,39,0}, /* core0 return_Stack5 bit24 */
			{19346,39,0}, /* core0 return_Stack5 bit25 */
			{19344,39,0}, /* core0 return_Stack5 bit26 */
			{19342,39,0}, /* core0 return_Stack5 bit27 */
			{19156,39,0}, /* core0 return_Stack5 bit28 */
			{19154,39,0}, /* core0 return_Stack5 bit29 */
			{19152,39,0}, /* core0 return_Stack5 bit30 */
			{19150,39,0}, /* core0 return_Stack5 bit31 */
			{19132,39,0}, /* core0 return_Stack5 bit32 */
			{19130,39,0}, /* core0 return_Stack5 bit33 */
			{19128,39,0}, /* core0 return_Stack5 bit34 */
			{19126,39,0}, /* core0 return_Stack5 bit35 */
			{19148,39,0}, /* core0 return_Stack5 bit36 */
			{19146,39,0}, /* core0 return_Stack5 bit37 */
			{19144,39,0}, /* core0 return_Stack5 bit38 */
			{19142,39,0}, /* core0 return_Stack5 bit39 */
			{19092,39,0}, /* core0 return_Stack5 bit40 */
			{19090,39,0}, /* core0 return_Stack5 bit41 */
			{19088,39,0}, /* core0 return_Stack5 bit42 */
			{19086,39,0}, /* core0 return_Stack5 bit43 */
			{19020,39,0}, /* core0 return_Stack5 bit44 */
			{19018,39,0}, /* core0 return_Stack5 bit45 */
			{19016,39,0}, /* core0 return_Stack5 bit46 */
			{19014,39,0}, /* core0 return_Stack5 bit47 */
			{ 3834,39,0}, /* core0 return_Stack5 bit48 */
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
			{18762,39,0}, /* core0 return_Stack6 bit0 */
			{18760,39,0}, /* core0 return_Stack6 bit1 */
			{18758,39,0}, /* core0 return_Stack6 bit2 */
			{18756,39,0}, /* core0 return_Stack6 bit3 */
			{18738,39,0}, /* core0 return_Stack6 bit4 */
			{18858,39,0}, /* core0 return_Stack6 bit5 */
			{18736,39,0}, /* core0 return_Stack6 bit6 */
			{18856,39,0}, /* core0 return_Stack6 bit7 */
			{18734,39,0}, /* core0 return_Stack6 bit8 */
			{18732,39,0}, /* core0 return_Stack6 bit9 */
			{ 3824,39,0}, /* core0 return_Stack6 bit10 */
			{18854,39,0}, /* core0 return_Stack6 bit11 */
			{18852,39,0}, /* core0 return_Stack6 bit12 */
			{18818,39,0}, /* core0 return_Stack6 bit13 */
			{18816,39,0}, /* core0 return_Stack6 bit14 */
			{18814,39,0}, /* core0 return_Stack6 bit15 */
			{18812,39,0}, /* core0 return_Stack6 bit16 */
			{18826,39,0}, /* core0 return_Stack6 bit17 */
			{18824,39,0}, /* core0 return_Stack6 bit18 */
			{18822,39,0}, /* core0 return_Stack6 bit19 */
			{18820,39,0}, /* core0 return_Stack6 bit20 */
			{18794,39,0}, /* core0 return_Stack6 bit21 */
			{18792,39,0}, /* core0 return_Stack6 bit22 */
			{18790,39,0}, /* core0 return_Stack6 bit23 */
			{18788,39,0}, /* core0 return_Stack6 bit24 */
			{18786,39,0}, /* core0 return_Stack6 bit25 */
			{18784,39,0}, /* core0 return_Stack6 bit26 */
			{18782,39,0}, /* core0 return_Stack6 bit27 */
			{18780,39,0}, /* core0 return_Stack6 bit28 */
			{18746,39,0}, /* core0 return_Stack6 bit29 */
			{18744,39,0}, /* core0 return_Stack6 bit30 */
			{18742,39,0}, /* core0 return_Stack6 bit31 */
			{18740,39,0}, /* core0 return_Stack6 bit32 */
			{18986,39,0}, /* core0 return_Stack6 bit33 */
			{18984,39,0}, /* core0 return_Stack6 bit34 */
			{18982,39,0}, /* core0 return_Stack6 bit35 */
			{18980,39,0}, /* core0 return_Stack6 bit36 */
			{18978,39,0}, /* core0 return_Stack6 bit37 */
			{18976,39,0}, /* core0 return_Stack6 bit38 */
			{18974,39,0}, /* core0 return_Stack6 bit39 */
			{18972,39,0}, /* core0 return_Stack6 bit40 */
			{18946,39,0}, /* core0 return_Stack6 bit41 */
			{18944,39,0}, /* core0 return_Stack6 bit42 */
			{18942,39,0}, /* core0 return_Stack6 bit43 */
			{18940,39,0}, /* core0 return_Stack6 bit44 */
			{18730,39,0}, /* core0 return_Stack6 bit45 */
			{18728,39,0}, /* core0 return_Stack6 bit46 */
			{18726,39,0}, /* core0 return_Stack6 bit47 */
			{18724,39,0}, /* core0 return_Stack6 bit48 */
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
			{18770,39,0}, /* core0 return_Stack7 bit0 */
			{18768,39,0}, /* core0 return_Stack7 bit1 */
			{18766,39,0}, /* core0 return_Stack7 bit2 */
			{18764,39,0}, /* core0 return_Stack7 bit3 */
			{18810,39,0}, /* core0 return_Stack7 bit4 */
			{18850,39,0}, /* core0 return_Stack7 bit5 */
			{18808,39,0}, /* core0 return_Stack7 bit6 */
			{18848,39,0}, /* core0 return_Stack7 bit7 */
			{18806,39,0}, /* core0 return_Stack7 bit8 */
			{18804,39,0}, /* core0 return_Stack7 bit9 */
			{ 3826,39,0}, /* core0 return_Stack7 bit10 */
			{18846,39,0}, /* core0 return_Stack7 bit11 */
			{18844,39,0}, /* core0 return_Stack7 bit12 */
			{18834,39,0}, /* core0 return_Stack7 bit13 */
			{18832,39,0}, /* core0 return_Stack7 bit14 */
			{18830,39,0}, /* core0 return_Stack7 bit15 */
			{18828,39,0}, /* core0 return_Stack7 bit16 */
			{18842,39,0}, /* core0 return_Stack7 bit17 */
			{18840,39,0}, /* core0 return_Stack7 bit18 */
			{18838,39,0}, /* core0 return_Stack7 bit19 */
			{18836,39,0}, /* core0 return_Stack7 bit20 */
			{18802,39,0}, /* core0 return_Stack7 bit21 */
			{18800,39,0}, /* core0 return_Stack7 bit22 */
			{18798,39,0}, /* core0 return_Stack7 bit23 */
			{18796,39,0}, /* core0 return_Stack7 bit24 */
			{18778,39,0}, /* core0 return_Stack7 bit25 */
			{18776,39,0}, /* core0 return_Stack7 bit26 */
			{18774,39,0}, /* core0 return_Stack7 bit27 */
			{18772,39,0}, /* core0 return_Stack7 bit28 */
			{18754,39,0}, /* core0 return_Stack7 bit29 */
			{18752,39,0}, /* core0 return_Stack7 bit30 */
			{18750,39,0}, /* core0 return_Stack7 bit31 */
			{18748,39,0}, /* core0 return_Stack7 bit32 */
			{18970,39,0}, /* core0 return_Stack7 bit33 */
			{18968,39,0}, /* core0 return_Stack7 bit34 */
			{18966,39,0}, /* core0 return_Stack7 bit35 */
			{18964,39,0}, /* core0 return_Stack7 bit36 */
			{18962,39,0}, /* core0 return_Stack7 bit37 */
			{18960,39,0}, /* core0 return_Stack7 bit38 */
			{18958,39,0}, /* core0 return_Stack7 bit39 */
			{18956,39,0}, /* core0 return_Stack7 bit40 */
			{18954,39,0}, /* core0 return_Stack7 bit41 */
			{18952,39,0}, /* core0 return_Stack7 bit42 */
			{18950,39,0}, /* core0 return_Stack7 bit43 */
			{18948,39,0}, /* core0 return_Stack7 bit44 */
			{18722,39,0}, /* core0 return_Stack7 bit45 */
			{18720,39,0}, /* core0 return_Stack7 bit46 */
			{18718,39,0}, /* core0 return_Stack7 bit47 */
			{18716,39,0}, /* core0 return_Stack7 bit48 */
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
	},
	{		/* core 1 */ 
			.pc = {{
			{ 2530,41,1}, /* core1 pc bit0 */
			{ 2528,41,1}, /* core1 pc bit1 */
			{ 2526,41,1}, /* core1 pc bit2 */
			{ 2524,41,1}, /* core1 pc bit3 */
			{ 2594,41,1}, /* core1 pc bit4 */
			{ 2592,41,1}, /* core1 pc bit5 */
			{ 2590,41,1}, /* core1 pc bit6 */
			{ 2588,41,1}, /* core1 pc bit7 */
			{ 2578,41,1}, /* core1 pc bit8 */
			{ 2458,41,1}, /* core1 pc bit9 */
			{ 2456,41,1}, /* core1 pc bit10 */
			{ 2576,41,1}, /* core1 pc bit11 */
			{ 2574,41,1}, /* core1 pc bit12 */
			{ 2572,41,1}, /* core1 pc bit13 */
			{ 2454,41,1}, /* core1 pc bit14 */
			{ 2452,41,1}, /* core1 pc bit15 */
			{ 2306,41,1}, /* core1 pc bit16 */
			{ 2474,41,1}, /* core1 pc bit17 */
			{ 2304,41,1}, /* core1 pc bit18 */
			{ 2472,41,1}, /* core1 pc bit19 */
			{ 2302,41,1}, /* core1 pc bit20 */
			{ 2300,41,1}, /* core1 pc bit21 */
			{ 2470,41,1}, /* core1 pc bit22 */
			{ 2314,41,1}, /* core1 pc bit23 */
			{ 2312,41,1}, /* core1 pc bit24 */
			{ 2310,41,1}, /* core1 pc bit25 */
			{ 2468,41,1}, /* core1 pc bit26 */
			{ 2522,41,1}, /* core1 pc bit27 */
			{ 2308,41,1}, /* core1 pc bit28 */
			{ 2464,41,1}, /* core1 pc bit29 */
			{ 2684,41,1}, /* core1 pc bit30 */
			{ 2520,41,1}, /* core1 pc bit31 */
			{ 2518,41,1}, /* core1 pc bit32 */
			{ 2516,41,1}, /* core1 pc bit33 */
			{ 2562,41,1}, /* core1 pc bit34 */
			{ 2560,41,1}, /* core1 pc bit35 */
			{ 2558,41,1}, /* core1 pc bit36 */
			{ 2556,41,1}, /* core1 pc bit37 */
			{ 2586,41,1}, /* core1 pc bit38 */
			{ 2584,41,1}, /* core1 pc bit39 */
			{ 2582,41,1}, /* core1 pc bit40 */
			{ 2580,41,1}, /* core1 pc bit41 */
			{ 2570,41,1}, /* core1 pc bit42 */
			{ 2568,41,1}, /* core1 pc bit43 */
			{ 2566,41,1}, /* core1 pc bit44 */
			{ 2564,41,1}, /* core1 pc bit45 */
			{ 2626,41,1}, /* core1 pc bit46 */
			{ 2624,41,1}, /* core1 pc bit47 */
			{ 2622,41,1}, /* core1 pc bit48 */
			{ 2620,41,1}, /* core1 pc bit49 */
			{ 2658,41,1}, /* core1 pc bit50 */
			{ 2656,41,1}, /* core1 pc bit51 */
			{ 2654,41,1}, /* core1 pc bit52 */
			{ 2652,41,1}, /* core1 pc bit53 */
			{ 2290,41,1}, /* core1 pc bit54 */
			{ 2288,41,1}, /* core1 pc bit55 */
			{ 2286,41,1}, /* core1 pc bit56 */
			{ 2284,41,1}, /* core1 pc bit57 */
			{ 2132,41,1}, /* core1 pc bit58 */
			{ 2130,41,1}, /* core1 pc bit59 */
			{ 2128,41,1}, /* core1 pc bit60 */
			{ 2126,41,1}, /* core1 pc bit61 */
			{ 2116,41,1}, /* core1 pc bit62 */
			{  670,41,1}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{ 7110,45,0}, /* core1 sp32 bit0 */
			{15738,45,0}, /* core1 sp32 bit1 */
			{15732,45,0}, /* core1 sp32 bit2 */
			{ 7088,45,0}, /* core1 sp32 bit3 */
			{15730,45,0}, /* core1 sp32 bit4 */
			{15740,45,0}, /* core1 sp32 bit5 */
			{15716,45,0}, /* core1 sp32 bit6 */
			{15714,45,0}, /* core1 sp32 bit7 */
			{15724,45,0}, /* core1 sp32 bit8 */
			{15682,45,0}, /* core1 sp32 bit9 */
			{15692,45,0}, /* core1 sp32 bit10 */
			{15722,45,0}, /* core1 sp32 bit11 */
			{15712,45,0}, /* core1 sp32 bit12 */
			{15710,45,0}, /* core1 sp32 bit13 */
			{15690,45,0}, /* core1 sp32 bit14 */
			{22706,45,0}, /* core1 sp32 bit15 */
			{22704,45,0}, /* core1 sp32 bit16 */
			{22702,45,0}, /* core1 sp32 bit17 */
			{22700,45,0}, /* core1 sp32 bit18 */
			{15720,45,0}, /* core1 sp32 bit19 */
			{15718,45,0}, /* core1 sp32 bit20 */
			{15736,45,0}, /* core1 sp32 bit21 */
			{15728,45,0}, /* core1 sp32 bit22 */
			{15726,45,0}, /* core1 sp32 bit23 */
			{15734,45,0}, /* core1 sp32 bit24 */
			{15924,45,0}, /* core1 sp32 bit25 */
			{15922,45,0}, /* core1 sp32 bit26 */
			{15920,45,0}, /* core1 sp32 bit27 */
			{15918,45,0}, /* core1 sp32 bit28 */
			{15688,45,0}, /* core1 sp32 bit29 */
			{15686,45,0}, /* core1 sp32 bit30 */
			{15684,45,0}, /* core1 sp32 bit31 */
			{15864,45,0}, /* core1 sp32 bit32 */
			{15862,45,0}, /* core1 sp32 bit33 */
			{15856,45,0}, /* core1 sp32 bit34 */
			{15868,45,0}, /* core1 sp32 bit35 */
			{15852,45,0}, /* core1 sp32 bit36 */
			{15866,45,0}, /* core1 sp32 bit37 */
			{ 6780,45,0}, /* core1 sp32 bit38 */
			{15850,45,0}, /* core1 sp32 bit39 */
			{15854,45,0}, /* core1 sp32 bit40 */
			{15848,45,0}, /* core1 sp32 bit41 */
			{15846,45,0}, /* core1 sp32 bit42 */
			{15844,45,0}, /* core1 sp32 bit43 */
			{15842,45,0}, /* core1 sp32 bit44 */
			{15860,45,0}, /* core1 sp32 bit45 */
			{15858,45,0}, /* core1 sp32 bit46 */
			{15872,45,0}, /* core1 sp32 bit47 */
			{15876,45,0}, /* core1 sp32 bit48 */
			{22370,45,0}, /* core1 sp32 bit49 */
			{22368,45,0}, /* core1 sp32 bit50 */
			{22366,45,0}, /* core1 sp32 bit51 */
			{22364,45,0}, /* core1 sp32 bit52 */
			{22354,45,0}, /* core1 sp32 bit53 */
			{22352,45,0}, /* core1 sp32 bit54 */
			{22350,45,0}, /* core1 sp32 bit55 */
			{22348,45,0}, /* core1 sp32 bit56 */
			{22362,45,0}, /* core1 sp32 bit57 */
			{22360,45,0}, /* core1 sp32 bit58 */
			{22358,45,0}, /* core1 sp32 bit59 */
			{22356,45,0}, /* core1 sp32 bit60 */
			{15870,45,0}, /* core1 sp32 bit61 */
			{15874,45,0}, /* core1 sp32 bit62 */
			{ 6776,45,0}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7124,45,0}, /* core1 fp32 bit0 */
			{ 7120,45,0}, /* core1 fp32 bit1 */
			{16530,45,0}, /* core1 fp32 bit2 */
			{16884,45,0}, /* core1 fp32 bit3 */
			{16880,45,0}, /* core1 fp32 bit4 */
			{16878,45,0}, /* core1 fp32 bit5 */
			{16876,45,0}, /* core1 fp32 bit6 */
			{16882,45,0}, /* core1 fp32 bit7 */
			{16874,45,0}, /* core1 fp32 bit8 */
			{16796,45,0}, /* core1 fp32 bit9 */
			{16794,45,0}, /* core1 fp32 bit10 */
			{ 7118,45,0}, /* core1 fp32 bit11 */
			{16548,45,0}, /* core1 fp32 bit12 */
			{16892,45,0}, /* core1 fp32 bit13 */
			{16792,45,0}, /* core1 fp32 bit14 */
			{16784,45,0}, /* core1 fp32 bit15 */
			{16886,45,0}, /* core1 fp32 bit16 */
			{16890,45,0}, /* core1 fp32 bit17 */
			{ 7116,45,0}, /* core1 fp32 bit18 */
			{ 7082,45,0}, /* core1 fp32 bit19 */
			{16546,45,0}, /* core1 fp32 bit20 */
			{16888,45,0}, /* core1 fp32 bit21 */
			{16532,45,0}, /* core1 fp32 bit22 */
			{ 7084,45,0}, /* core1 fp32 bit23 */
			{ 7114,45,0}, /* core1 fp32 bit24 */
			{ 6906,45,0}, /* core1 fp32 bit25 */
			{16782,45,0}, /* core1 fp32 bit26 */
			{16790,45,0}, /* core1 fp32 bit27 */
			{16788,45,0}, /* core1 fp32 bit28 */
			{ 6902,45,0}, /* core1 fp32 bit29 */
			{16786,45,0}, /* core1 fp32 bit30 */
			{ 6904,45,0}, /* core1 fp32 bit31 */
			{ 6830,45,0}, /* core1 fp32 bit32 */
			{ 6822,45,0}, /* core1 fp32 bit33 */
			{ 6824,45,0}, /* core1 fp32 bit34 */
			{ 6886,45,0}, /* core1 fp32 bit35 */
			{ 6884,45,0}, /* core1 fp32 bit36 */
			{ 6826,45,0}, /* core1 fp32 bit37 */
			{16624,45,0}, /* core1 fp32 bit38 */
			{16622,45,0}, /* core1 fp32 bit39 */
			{16632,45,0}, /* core1 fp32 bit40 */
			{16628,45,0}, /* core1 fp32 bit41 */
			{ 6820,45,0}, /* core1 fp32 bit42 */
			{16630,45,0}, /* core1 fp32 bit43 */
			{16626,45,0}, /* core1 fp32 bit44 */
			{16656,45,0}, /* core1 fp32 bit45 */
			{16648,45,0}, /* core1 fp32 bit46 */
			{16636,45,0}, /* core1 fp32 bit47 */
			{16634,45,0}, /* core1 fp32 bit48 */
			{22546,45,0}, /* core1 fp32 bit49 */
			{ 6818,45,0}, /* core1 fp32 bit50 */
			{22554,45,0}, /* core1 fp32 bit51 */
			{22552,45,0}, /* core1 fp32 bit52 */
			{22544,45,0}, /* core1 fp32 bit53 */
			{22542,45,0}, /* core1 fp32 bit54 */
			{22540,45,0}, /* core1 fp32 bit55 */
			{22550,45,0}, /* core1 fp32 bit56 */
			{22562,45,0}, /* core1 fp32 bit57 */
			{22560,45,0}, /* core1 fp32 bit58 */
			{22548,45,0}, /* core1 fp32 bit59 */
			{16646,45,0}, /* core1 fp32 bit60 */
			{16654,45,0}, /* core1 fp32 bit61 */
			{22558,45,0}, /* core1 fp32 bit62 */
			{22556,45,0}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{14752,45,0}, /* core1 fp64 bit0 */
			{ 6972,45,0}, /* core1 fp64 bit1 */
			{14750,45,0}, /* core1 fp64 bit2 */
			{15068,45,0}, /* core1 fp64 bit3 */
			{15066,45,0}, /* core1 fp64 bit4 */
			{15080,45,0}, /* core1 fp64 bit5 */
			{15078,45,0}, /* core1 fp64 bit6 */
			{15076,45,0}, /* core1 fp64 bit7 */
			{15074,45,0}, /* core1 fp64 bit8 */
			{15020,45,0}, /* core1 fp64 bit9 */
			{14798,45,0}, /* core1 fp64 bit10 */
			{15060,45,0}, /* core1 fp64 bit11 */
			{15058,45,0}, /* core1 fp64 bit12 */
			{15072,45,0}, /* core1 fp64 bit13 */
			{15018,45,0}, /* core1 fp64 bit14 */
			{14804,45,0}, /* core1 fp64 bit15 */
			{15070,45,0}, /* core1 fp64 bit16 */
			{15084,45,0}, /* core1 fp64 bit17 */
			{14748,45,0}, /* core1 fp64 bit18 */
			{15082,45,0}, /* core1 fp64 bit19 */
			{15064,45,0}, /* core1 fp64 bit20 */
			{14746,45,0}, /* core1 fp64 bit21 */
			{15062,45,0}, /* core1 fp64 bit22 */
			{ 7066,45,0}, /* core1 fp64 bit23 */
			{14756,45,0}, /* core1 fp64 bit24 */
			{14754,45,0}, /* core1 fp64 bit25 */
			{ 6946,45,0}, /* core1 fp64 bit26 */
			{14808,45,0}, /* core1 fp64 bit27 */
			{14806,45,0}, /* core1 fp64 bit28 */
			{14802,45,0}, /* core1 fp64 bit29 */
			{ 6970,45,0}, /* core1 fp64 bit30 */
			{14800,45,0}, /* core1 fp64 bit31 */
			{14888,45,0}, /* core1 fp64 bit32 */
			{14884,45,0}, /* core1 fp64 bit33 */
			{14886,45,0}, /* core1 fp64 bit34 */
			{ 6708,45,0}, /* core1 fp64 bit35 */
			{14892,45,0}, /* core1 fp64 bit36 */
			{14882,45,0}, /* core1 fp64 bit37 */
			{ 6700,45,0}, /* core1 fp64 bit38 */
			{14890,45,0}, /* core1 fp64 bit39 */
			{14896,45,0}, /* core1 fp64 bit40 */
			{14894,45,0}, /* core1 fp64 bit41 */
			{14900,45,0}, /* core1 fp64 bit42 */
			{14904,45,0}, /* core1 fp64 bit43 */
			{14902,45,0}, /* core1 fp64 bit44 */
			{14912,45,0}, /* core1 fp64 bit45 */
			{14898,45,0}, /* core1 fp64 bit46 */
			{14910,45,0}, /* core1 fp64 bit47 */
			{14916,45,0}, /* core1 fp64 bit48 */
			{14914,45,0}, /* core1 fp64 bit49 */
			{21972,45,0}, /* core1 fp64 bit50 */
			{21980,45,0}, /* core1 fp64 bit51 */
			{21970,45,0}, /* core1 fp64 bit52 */
			{21978,45,0}, /* core1 fp64 bit53 */
			{21968,45,0}, /* core1 fp64 bit54 */
			{21966,45,0}, /* core1 fp64 bit55 */
			{21988,45,0}, /* core1 fp64 bit56 */
			{21986,45,0}, /* core1 fp64 bit57 */
			{21976,45,0}, /* core1 fp64 bit58 */
			{21984,45,0}, /* core1 fp64 bit59 */
			{14920,45,0}, /* core1 fp64 bit60 */
			{21982,45,0}, /* core1 fp64 bit61 */
			{21974,45,0}, /* core1 fp64 bit62 */
			{14918,45,0}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 6982,45,0}, /* core1 sp_EL0 bit0 */
			{ 6974,45,0}, /* core1 sp_EL0 bit1 */
			{14710,45,0}, /* core1 sp_EL0 bit2 */
			{14720,45,0}, /* core1 sp_EL0 bit3 */
			{14718,45,0}, /* core1 sp_EL0 bit4 */
			{15108,45,0}, /* core1 sp_EL0 bit5 */
			{15106,45,0}, /* core1 sp_EL0 bit6 */
			{ 7046,45,0}, /* core1 sp_EL0 bit7 */
			{15112,45,0}, /* core1 sp_EL0 bit8 */
			{14772,45,0}, /* core1 sp_EL0 bit9 */
			{14770,45,0}, /* core1 sp_EL0 bit10 */
			{14708,45,0}, /* core1 sp_EL0 bit11 */
			{14706,45,0}, /* core1 sp_EL0 bit12 */
			{15032,45,0}, /* core1 sp_EL0 bit13 */
			{15030,45,0}, /* core1 sp_EL0 bit14 */
			{14776,45,0}, /* core1 sp_EL0 bit15 */
			{15036,45,0}, /* core1 sp_EL0 bit16 */
			{15110,45,0}, /* core1 sp_EL0 bit17 */
			{15034,45,0}, /* core1 sp_EL0 bit18 */
			{ 7050,45,0}, /* core1 sp_EL0 bit19 */
			{14716,45,0}, /* core1 sp_EL0 bit20 */
			{ 7048,45,0}, /* core1 sp_EL0 bit21 */
			{14712,45,0}, /* core1 sp_EL0 bit22 */
			{14714,45,0}, /* core1 sp_EL0 bit23 */
			{14760,45,0}, /* core1 sp_EL0 bit24 */
			{14758,45,0}, /* core1 sp_EL0 bit25 */
			{14780,45,0}, /* core1 sp_EL0 bit26 */
			{14778,45,0}, /* core1 sp_EL0 bit27 */
			{15008,45,0}, /* core1 sp_EL0 bit28 */
			{14774,45,0}, /* core1 sp_EL0 bit29 */
			{15006,45,0}, /* core1 sp_EL0 bit30 */
			{ 7018,45,0}, /* core1 sp_EL0 bit31 */
			{14820,45,0}, /* core1 sp_EL0 bit32 */
			{14818,45,0}, /* core1 sp_EL0 bit33 */
			{14844,45,0}, /* core1 sp_EL0 bit34 */
			{14812,45,0}, /* core1 sp_EL0 bit35 */
			{14810,45,0}, /* core1 sp_EL0 bit36 */
			{14816,45,0}, /* core1 sp_EL0 bit37 */
			{14814,45,0}, /* core1 sp_EL0 bit38 */
			{ 6836,45,0}, /* core1 sp_EL0 bit39 */
			{14842,45,0}, /* core1 sp_EL0 bit40 */
			{14836,45,0}, /* core1 sp_EL0 bit41 */
			{14840,45,0}, /* core1 sp_EL0 bit42 */
			{14838,45,0}, /* core1 sp_EL0 bit43 */
			{14828,45,0}, /* core1 sp_EL0 bit44 */
			{14834,45,0}, /* core1 sp_EL0 bit45 */
			{21900,45,0}, /* core1 sp_EL0 bit46 */
			{14832,45,0}, /* core1 sp_EL0 bit47 */
			{21898,45,0}, /* core1 sp_EL0 bit48 */
			{21896,45,0}, /* core1 sp_EL0 bit49 */
			{14830,45,0}, /* core1 sp_EL0 bit50 */
			{21894,45,0}, /* core1 sp_EL0 bit51 */
			{21892,45,0}, /* core1 sp_EL0 bit52 */
			{21884,45,0}, /* core1 sp_EL0 bit53 */
			{21890,45,0}, /* core1 sp_EL0 bit54 */
			{21888,45,0}, /* core1 sp_EL0 bit55 */
			{21886,45,0}, /* core1 sp_EL0 bit56 */
			{14824,45,0}, /* core1 sp_EL0 bit57 */
			{21882,45,0}, /* core1 sp_EL0 bit58 */
			{14822,45,0}, /* core1 sp_EL0 bit59 */
			{21880,45,0}, /* core1 sp_EL0 bit60 */
			{ 6838,45,0}, /* core1 sp_EL0 bit61 */
			{21878,45,0}, /* core1 sp_EL0 bit62 */
			{14826,45,0}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6988,45,0}, /* core1 sp_EL1 bit0 */
			{ 6998,45,0}, /* core1 sp_EL1 bit1 */
			{14740,45,0}, /* core1 sp_EL1 bit2 */
			{14738,45,0}, /* core1 sp_EL1 bit3 */
			{15096,45,0}, /* core1 sp_EL1 bit4 */
			{15094,45,0}, /* core1 sp_EL1 bit5 */
			{15088,45,0}, /* core1 sp_EL1 bit6 */
			{15116,45,0}, /* core1 sp_EL1 bit7 */
			{15086,45,0}, /* core1 sp_EL1 bit8 */
			{15014,45,0}, /* core1 sp_EL1 bit9 */
			{15002,45,0}, /* core1 sp_EL1 bit10 */
			{15114,45,0}, /* core1 sp_EL1 bit11 */
			{15120,45,0}, /* core1 sp_EL1 bit12 */
			{15118,45,0}, /* core1 sp_EL1 bit13 */
			{21844,45,0}, /* core1 sp_EL1 bit14 */
			{15000,45,0}, /* core1 sp_EL1 bit15 */
			{21842,45,0}, /* core1 sp_EL1 bit16 */
			{15128,45,0}, /* core1 sp_EL1 bit17 */
			{21840,45,0}, /* core1 sp_EL1 bit18 */
			{15126,45,0}, /* core1 sp_EL1 bit19 */
			{21838,45,0}, /* core1 sp_EL1 bit20 */
			{ 7064,45,0}, /* core1 sp_EL1 bit21 */
			{ 7056,45,0}, /* core1 sp_EL1 bit22 */
			{ 7062,45,0}, /* core1 sp_EL1 bit23 */
			{ 6994,45,0}, /* core1 sp_EL1 bit24 */
			{14992,45,0}, /* core1 sp_EL1 bit25 */
			{14990,45,0}, /* core1 sp_EL1 bit26 */
			{14996,45,0}, /* core1 sp_EL1 bit27 */
			{14994,45,0}, /* core1 sp_EL1 bit28 */
			{14998,45,0}, /* core1 sp_EL1 bit29 */
			{15016,45,0}, /* core1 sp_EL1 bit30 */
			{15004,45,0}, /* core1 sp_EL1 bit31 */
			{ 6864,45,0}, /* core1 sp_EL1 bit32 */
			{14876,45,0}, /* core1 sp_EL1 bit33 */
			{14940,45,0}, /* core1 sp_EL1 bit34 */
			{14874,45,0}, /* core1 sp_EL1 bit35 */
			{14880,45,0}, /* core1 sp_EL1 bit36 */
			{14878,45,0}, /* core1 sp_EL1 bit37 */
			{14948,45,0}, /* core1 sp_EL1 bit38 */
			{14946,45,0}, /* core1 sp_EL1 bit39 */
			{14938,45,0}, /* core1 sp_EL1 bit40 */
			{14944,45,0}, /* core1 sp_EL1 bit41 */
			{14942,45,0}, /* core1 sp_EL1 bit42 */
			{14936,45,0}, /* core1 sp_EL1 bit43 */
			{14934,45,0}, /* core1 sp_EL1 bit44 */
			{14932,45,0}, /* core1 sp_EL1 bit45 */
			{ 6868,45,0}, /* core1 sp_EL1 bit46 */
			{14930,45,0}, /* core1 sp_EL1 bit47 */
			{22116,45,0}, /* core1 sp_EL1 bit48 */
			{22114,45,0}, /* core1 sp_EL1 bit49 */
			{22108,45,0}, /* core1 sp_EL1 bit50 */
			{22106,45,0}, /* core1 sp_EL1 bit51 */
			{22104,45,0}, /* core1 sp_EL1 bit52 */
			{22102,45,0}, /* core1 sp_EL1 bit53 */
			{22124,45,0}, /* core1 sp_EL1 bit54 */
			{22122,45,0}, /* core1 sp_EL1 bit55 */
			{22120,45,0}, /* core1 sp_EL1 bit56 */
			{22118,45,0}, /* core1 sp_EL1 bit57 */
			{22100,45,0}, /* core1 sp_EL1 bit58 */
			{22098,45,0}, /* core1 sp_EL1 bit59 */
			{22096,45,0}, /* core1 sp_EL1 bit60 */
			{22094,45,0}, /* core1 sp_EL1 bit61 */
			{22112,45,0}, /* core1 sp_EL1 bit62 */
			{22110,45,0}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 6986,45,0}, /* core1 sp_EL2 bit0 */
			{ 7000,45,0}, /* core1 sp_EL2 bit1 */
			{14736,45,0}, /* core1 sp_EL2 bit2 */
			{14734,45,0}, /* core1 sp_EL2 bit3 */
			{15132,45,0}, /* core1 sp_EL2 bit4 */
			{15130,45,0}, /* core1 sp_EL2 bit5 */
			{15092,45,0}, /* core1 sp_EL2 bit6 */
			{14704,45,0}, /* core1 sp_EL2 bit7 */
			{15090,45,0}, /* core1 sp_EL2 bit8 */
			{15012,45,0}, /* core1 sp_EL2 bit9 */
			{15010,45,0}, /* core1 sp_EL2 bit10 */
			{14702,45,0}, /* core1 sp_EL2 bit11 */
			{15124,45,0}, /* core1 sp_EL2 bit12 */
			{15122,45,0}, /* core1 sp_EL2 bit13 */
			{21852,45,0}, /* core1 sp_EL2 bit14 */
			{ 7012,45,0}, /* core1 sp_EL2 bit15 */
			{21850,45,0}, /* core1 sp_EL2 bit16 */
			{15136,45,0}, /* core1 sp_EL2 bit17 */
			{21848,45,0}, /* core1 sp_EL2 bit18 */
			{15134,45,0}, /* core1 sp_EL2 bit19 */
			{21846,45,0}, /* core1 sp_EL2 bit20 */
			{ 7060,45,0}, /* core1 sp_EL2 bit21 */
			{ 7058,45,0}, /* core1 sp_EL2 bit22 */
			{ 7052,45,0}, /* core1 sp_EL2 bit23 */
			{14764,45,0}, /* core1 sp_EL2 bit24 */
			{14762,45,0}, /* core1 sp_EL2 bit25 */
			{14988,45,0}, /* core1 sp_EL2 bit26 */
			{14986,45,0}, /* core1 sp_EL2 bit27 */
			{ 7016,45,0}, /* core1 sp_EL2 bit28 */
			{ 7014,45,0}, /* core1 sp_EL2 bit29 */
			{ 7008,45,0}, /* core1 sp_EL2 bit30 */
			{ 7010,45,0}, /* core1 sp_EL2 bit31 */
			{ 6860,45,0}, /* core1 sp_EL2 bit32 */
			{14868,45,0}, /* core1 sp_EL2 bit33 */
			{14964,45,0}, /* core1 sp_EL2 bit34 */
			{14866,45,0}, /* core1 sp_EL2 bit35 */
			{14864,45,0}, /* core1 sp_EL2 bit36 */
			{14862,45,0}, /* core1 sp_EL2 bit37 */
			{14872,45,0}, /* core1 sp_EL2 bit38 */
			{14870,45,0}, /* core1 sp_EL2 bit39 */
			{14962,45,0}, /* core1 sp_EL2 bit40 */
			{14952,45,0}, /* core1 sp_EL2 bit41 */
			{14950,45,0}, /* core1 sp_EL2 bit42 */
			{14960,45,0}, /* core1 sp_EL2 bit43 */
			{14958,45,0}, /* core1 sp_EL2 bit44 */
			{14956,45,0}, /* core1 sp_EL2 bit45 */
			{ 6858,45,0}, /* core1 sp_EL2 bit46 */
			{14954,45,0}, /* core1 sp_EL2 bit47 */
			{22148,45,0}, /* core1 sp_EL2 bit48 */
			{22146,45,0}, /* core1 sp_EL2 bit49 */
			{22140,45,0}, /* core1 sp_EL2 bit50 */
			{22138,45,0}, /* core1 sp_EL2 bit51 */
			{22136,45,0}, /* core1 sp_EL2 bit52 */
			{22134,45,0}, /* core1 sp_EL2 bit53 */
			{22132,45,0}, /* core1 sp_EL2 bit54 */
			{22130,45,0}, /* core1 sp_EL2 bit55 */
			{22128,45,0}, /* core1 sp_EL2 bit56 */
			{22126,45,0}, /* core1 sp_EL2 bit57 */
			{22156,45,0}, /* core1 sp_EL2 bit58 */
			{22154,45,0}, /* core1 sp_EL2 bit59 */
			{22152,45,0}, /* core1 sp_EL2 bit60 */
			{22150,45,0}, /* core1 sp_EL2 bit61 */
			{22144,45,0}, /* core1 sp_EL2 bit62 */
			{22142,45,0}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6984,45,0}, /* core1 sp_EL3 bit0 */
			{ 6996,45,0}, /* core1 sp_EL3 bit1 */
			{14732,45,0}, /* core1 sp_EL3 bit2 */
			{14388,45,0}, /* core1 sp_EL3 bit3 */
			{15104,45,0}, /* core1 sp_EL3 bit4 */
			{15102,45,0}, /* core1 sp_EL3 bit5 */
			{14730,45,0}, /* core1 sp_EL3 bit6 */
			{14768,45,0}, /* core1 sp_EL3 bit7 */
			{15100,45,0}, /* core1 sp_EL3 bit8 */
			{14766,45,0}, /* core1 sp_EL3 bit9 */
			{14332,45,0}, /* core1 sp_EL3 bit10 */
			{14700,45,0}, /* core1 sp_EL3 bit11 */
			{14698,45,0}, /* core1 sp_EL3 bit12 */
			{14696,45,0}, /* core1 sp_EL3 bit13 */
			{14694,45,0}, /* core1 sp_EL3 bit14 */
			{14338,45,0}, /* core1 sp_EL3 bit15 */
			{14394,45,0}, /* core1 sp_EL3 bit16 */
			{15098,45,0}, /* core1 sp_EL3 bit17 */
			{14402,45,0}, /* core1 sp_EL3 bit18 */
			{ 7054,45,0}, /* core1 sp_EL3 bit19 */
			{14392,45,0}, /* core1 sp_EL3 bit20 */
			{14400,45,0}, /* core1 sp_EL3 bit21 */
			{14390,45,0}, /* core1 sp_EL3 bit22 */
			{14398,45,0}, /* core1 sp_EL3 bit23 */
			{14396,45,0}, /* core1 sp_EL3 bit24 */
			{14326,45,0}, /* core1 sp_EL3 bit25 */
			{14324,45,0}, /* core1 sp_EL3 bit26 */
			{14330,45,0}, /* core1 sp_EL3 bit27 */
			{14328,45,0}, /* core1 sp_EL3 bit28 */
			{14336,45,0}, /* core1 sp_EL3 bit29 */
			{ 7020,45,0}, /* core1 sp_EL3 bit30 */
			{14334,45,0}, /* core1 sp_EL3 bit31 */
			{14310,45,0}, /* core1 sp_EL3 bit32 */
			{14306,45,0}, /* core1 sp_EL3 bit33 */
			{14270,45,0}, /* core1 sp_EL3 bit34 */
			{14308,45,0}, /* core1 sp_EL3 bit35 */
			{14304,45,0}, /* core1 sp_EL3 bit36 */
			{14302,45,0}, /* core1 sp_EL3 bit37 */
			{14314,45,0}, /* core1 sp_EL3 bit38 */
			{14300,45,0}, /* core1 sp_EL3 bit39 */
			{14266,45,0}, /* core1 sp_EL3 bit40 */
			{14264,45,0}, /* core1 sp_EL3 bit41 */
			{14268,45,0}, /* core1 sp_EL3 bit42 */
			{14262,45,0}, /* core1 sp_EL3 bit43 */
			{14260,45,0}, /* core1 sp_EL3 bit44 */
			{14258,45,0}, /* core1 sp_EL3 bit45 */
			{14312,45,0}, /* core1 sp_EL3 bit46 */
			{14256,45,0}, /* core1 sp_EL3 bit47 */
			{22188,45,0}, /* core1 sp_EL3 bit48 */
			{22186,45,0}, /* core1 sp_EL3 bit49 */
			{22184,45,0}, /* core1 sp_EL3 bit50 */
			{22182,45,0}, /* core1 sp_EL3 bit51 */
			{22172,45,0}, /* core1 sp_EL3 bit52 */
			{22170,45,0}, /* core1 sp_EL3 bit53 */
			{22168,45,0}, /* core1 sp_EL3 bit54 */
			{22166,45,0}, /* core1 sp_EL3 bit55 */
			{22180,45,0}, /* core1 sp_EL3 bit56 */
			{22178,45,0}, /* core1 sp_EL3 bit57 */
			{22176,45,0}, /* core1 sp_EL3 bit58 */
			{22174,45,0}, /* core1 sp_EL3 bit59 */
			{22164,45,0}, /* core1 sp_EL3 bit60 */
			{22162,45,0}, /* core1 sp_EL3 bit61 */
			{22160,45,0}, /* core1 sp_EL3 bit62 */
			{22158,45,0}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{21836,45,0}, /* core1 elr_EL1 bit0 */
			{21552,45,0}, /* core1 elr_EL1 bit1 */
			{21606,45,0}, /* core1 elr_EL1 bit2 */
			{21604,45,0}, /* core1 elr_EL1 bit3 */
			{21602,45,0}, /* core1 elr_EL1 bit4 */
			{21600,45,0}, /* core1 elr_EL1 bit5 */
			{21598,45,0}, /* core1 elr_EL1 bit6 */
			{21596,45,0}, /* core1 elr_EL1 bit7 */
			{21594,45,0}, /* core1 elr_EL1 bit8 */
			{21834,45,0}, /* core1 elr_EL1 bit9 */
			{21592,45,0}, /* core1 elr_EL1 bit10 */
			{21614,45,0}, /* core1 elr_EL1 bit11 */
			{21612,45,0}, /* core1 elr_EL1 bit12 */
			{21610,45,0}, /* core1 elr_EL1 bit13 */
			{21832,45,0}, /* core1 elr_EL1 bit14 */
			{14362,45,0}, /* core1 elr_EL1 bit15 */
			{21830,45,0}, /* core1 elr_EL1 bit16 */
			{21608,45,0}, /* core1 elr_EL1 bit17 */
			{21582,45,0}, /* core1 elr_EL1 bit18 */
			{21580,45,0}, /* core1 elr_EL1 bit19 */
			{21558,45,0}, /* core1 elr_EL1 bit20 */
			{14414,45,0}, /* core1 elr_EL1 bit21 */
			{21578,45,0}, /* core1 elr_EL1 bit22 */
			{21556,45,0}, /* core1 elr_EL1 bit23 */
			{21576,45,0}, /* core1 elr_EL1 bit24 */
			{21542,45,0}, /* core1 elr_EL1 bit25 */
			{21554,45,0}, /* core1 elr_EL1 bit26 */
			{21540,45,0}, /* core1 elr_EL1 bit27 */
			{21538,45,0}, /* core1 elr_EL1 bit28 */
			{14360,45,0}, /* core1 elr_EL1 bit29 */
			{21536,45,0}, /* core1 elr_EL1 bit30 */
			{14412,45,0}, /* core1 elr_EL1 bit31 */
			{21478,45,0}, /* core1 elr_EL1 bit32 */
			{21486,45,0}, /* core1 elr_EL1 bit33 */
			{21484,45,0}, /* core1 elr_EL1 bit34 */
			{21476,45,0}, /* core1 elr_EL1 bit35 */
			{21474,45,0}, /* core1 elr_EL1 bit36 */
			{21472,45,0}, /* core1 elr_EL1 bit37 */
			{14322,45,0}, /* core1 elr_EL1 bit38 */
			{14320,45,0}, /* core1 elr_EL1 bit39 */
			{21482,45,0}, /* core1 elr_EL1 bit40 */
			{21480,45,0}, /* core1 elr_EL1 bit41 */
			{21494,45,0}, /* core1 elr_EL1 bit42 */
			{21492,45,0}, /* core1 elr_EL1 bit43 */
			{21490,45,0}, /* core1 elr_EL1 bit44 */
			{21488,45,0}, /* core1 elr_EL1 bit45 */
			{21502,45,0}, /* core1 elr_EL1 bit46 */
			{21500,45,0}, /* core1 elr_EL1 bit47 */
			{21498,45,0}, /* core1 elr_EL1 bit48 */
			{21496,45,0}, /* core1 elr_EL1 bit49 */
			{21510,45,0}, /* core1 elr_EL1 bit50 */
			{21508,45,0}, /* core1 elr_EL1 bit51 */
			{21506,45,0}, /* core1 elr_EL1 bit52 */
			{21504,45,0}, /* core1 elr_EL1 bit53 */
			{21518,45,0}, /* core1 elr_EL1 bit54 */
			{21516,45,0}, /* core1 elr_EL1 bit55 */
			{21514,45,0}, /* core1 elr_EL1 bit56 */
			{21512,45,0}, /* core1 elr_EL1 bit57 */
			{21526,45,0}, /* core1 elr_EL1 bit58 */
			{21524,45,0}, /* core1 elr_EL1 bit59 */
			{21522,45,0}, /* core1 elr_EL1 bit60 */
			{21520,45,0}, /* core1 elr_EL1 bit61 */
			{14318,45,0}, /* core1 elr_EL1 bit62 */
			{14316,45,0}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{21590,45,0}, /* core1 elr_EL2 bit0 */
			{21588,45,0}, /* core1 elr_EL2 bit1 */
			{21586,45,0}, /* core1 elr_EL2 bit2 */
			{21584,45,0}, /* core1 elr_EL2 bit3 */
			{21638,45,0}, /* core1 elr_EL2 bit4 */
			{21636,45,0}, /* core1 elr_EL2 bit5 */
			{21634,45,0}, /* core1 elr_EL2 bit6 */
			{21632,45,0}, /* core1 elr_EL2 bit7 */
			{21550,45,0}, /* core1 elr_EL2 bit8 */
			{21548,45,0}, /* core1 elr_EL2 bit9 */
			{21546,45,0}, /* core1 elr_EL2 bit10 */
			{21544,45,0}, /* core1 elr_EL2 bit11 */
			{21574,45,0}, /* core1 elr_EL2 bit12 */
			{21572,45,0}, /* core1 elr_EL2 bit13 */
			{21570,45,0}, /* core1 elr_EL2 bit14 */
			{14358,45,0}, /* core1 elr_EL2 bit15 */
			{21568,45,0}, /* core1 elr_EL2 bit16 */
			{21622,45,0}, /* core1 elr_EL2 bit17 */
			{21620,45,0}, /* core1 elr_EL2 bit18 */
			{21618,45,0}, /* core1 elr_EL2 bit19 */
			{21616,45,0}, /* core1 elr_EL2 bit20 */
			{14418,45,0}, /* core1 elr_EL2 bit21 */
			{21566,45,0}, /* core1 elr_EL2 bit22 */
			{21564,45,0}, /* core1 elr_EL2 bit23 */
			{21562,45,0}, /* core1 elr_EL2 bit24 */
			{21560,45,0}, /* core1 elr_EL2 bit25 */
			{21534,45,0}, /* core1 elr_EL2 bit26 */
			{21532,45,0}, /* core1 elr_EL2 bit27 */
			{21530,45,0}, /* core1 elr_EL2 bit28 */
			{14356,45,0}, /* core1 elr_EL2 bit29 */
			{21528,45,0}, /* core1 elr_EL2 bit30 */
			{14416,45,0}, /* core1 elr_EL2 bit31 */
			{21462,45,0}, /* core1 elr_EL2 bit32 */
			{21460,45,0}, /* core1 elr_EL2 bit33 */
			{21458,45,0}, /* core1 elr_EL2 bit34 */
			{21456,45,0}, /* core1 elr_EL2 bit35 */
			{21454,45,0}, /* core1 elr_EL2 bit36 */
			{21452,45,0}, /* core1 elr_EL2 bit37 */
			{21450,45,0}, /* core1 elr_EL2 bit38 */
			{21448,45,0}, /* core1 elr_EL2 bit39 */
			{21438,45,0}, /* core1 elr_EL2 bit40 */
			{21436,45,0}, /* core1 elr_EL2 bit41 */
			{21434,45,0}, /* core1 elr_EL2 bit42 */
			{21432,45,0}, /* core1 elr_EL2 bit43 */
			{21446,45,0}, /* core1 elr_EL2 bit44 */
			{21444,45,0}, /* core1 elr_EL2 bit45 */
			{21442,45,0}, /* core1 elr_EL2 bit46 */
			{21440,45,0}, /* core1 elr_EL2 bit47 */
			{21470,45,0}, /* core1 elr_EL2 bit48 */
			{21468,45,0}, /* core1 elr_EL2 bit49 */
			{21466,45,0}, /* core1 elr_EL2 bit50 */
			{21464,45,0}, /* core1 elr_EL2 bit51 */
			{21430,45,0}, /* core1 elr_EL2 bit52 */
			{21428,45,0}, /* core1 elr_EL2 bit53 */
			{21426,45,0}, /* core1 elr_EL2 bit54 */
			{21424,45,0}, /* core1 elr_EL2 bit55 */
			{21422,45,0}, /* core1 elr_EL2 bit56 */
			{21420,45,0}, /* core1 elr_EL2 bit57 */
			{21418,45,0}, /* core1 elr_EL2 bit58 */
			{21416,45,0}, /* core1 elr_EL2 bit59 */
			{21414,45,0}, /* core1 elr_EL2 bit60 */
			{21412,45,0}, /* core1 elr_EL2 bit61 */
			{21410,45,0}, /* core1 elr_EL2 bit62 */
			{21408,45,0}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 6990,45,0}, /* core1 elr_EL3 bit0 */
			{ 7002,45,0}, /* core1 elr_EL3 bit1 */
			{14404,45,0}, /* core1 elr_EL3 bit2 */
			{14382,45,0}, /* core1 elr_EL3 bit3 */
			{14386,45,0}, /* core1 elr_EL3 bit4 */
			{14380,45,0}, /* core1 elr_EL3 bit5 */
			{14378,45,0}, /* core1 elr_EL3 bit6 */
			{14376,45,0}, /* core1 elr_EL3 bit7 */
			{14370,45,0}, /* core1 elr_EL3 bit8 */
			{14366,45,0}, /* core1 elr_EL3 bit9 */
			{14344,45,0}, /* core1 elr_EL3 bit10 */
			{14384,45,0}, /* core1 elr_EL3 bit11 */
			{14374,45,0}, /* core1 elr_EL3 bit12 */
			{14372,45,0}, /* core1 elr_EL3 bit13 */
			{14410,45,0}, /* core1 elr_EL3 bit14 */
			{14352,45,0}, /* core1 elr_EL3 bit15 */
			{21630,45,0}, /* core1 elr_EL3 bit16 */
			{21628,45,0}, /* core1 elr_EL3 bit17 */
			{14408,45,0}, /* core1 elr_EL3 bit18 */
			{14406,45,0}, /* core1 elr_EL3 bit19 */
			{21626,45,0}, /* core1 elr_EL3 bit20 */
			{ 6992,45,0}, /* core1 elr_EL3 bit21 */
			{21624,45,0}, /* core1 elr_EL3 bit22 */
			{14368,45,0}, /* core1 elr_EL3 bit23 */
			{14364,45,0}, /* core1 elr_EL3 bit24 */
			{14342,45,0}, /* core1 elr_EL3 bit25 */
			{14350,45,0}, /* core1 elr_EL3 bit26 */
			{14348,45,0}, /* core1 elr_EL3 bit27 */
			{14340,45,0}, /* core1 elr_EL3 bit28 */
			{14354,45,0}, /* core1 elr_EL3 bit29 */
			{ 7004,45,0}, /* core1 elr_EL3 bit30 */
			{14346,45,0}, /* core1 elr_EL3 bit31 */
			{14298,45,0}, /* core1 elr_EL3 bit32 */
			{14296,45,0}, /* core1 elr_EL3 bit33 */
			{14290,45,0}, /* core1 elr_EL3 bit34 */
			{14294,45,0}, /* core1 elr_EL3 bit35 */
			{14288,45,0}, /* core1 elr_EL3 bit36 */
			{14292,45,0}, /* core1 elr_EL3 bit37 */
			{ 6854,45,0}, /* core1 elr_EL3 bit38 */
			{14282,45,0}, /* core1 elr_EL3 bit39 */
			{14286,45,0}, /* core1 elr_EL3 bit40 */
			{14254,45,0}, /* core1 elr_EL3 bit41 */
			{14284,45,0}, /* core1 elr_EL3 bit42 */
			{14252,45,0}, /* core1 elr_EL3 bit43 */
			{14278,45,0}, /* core1 elr_EL3 bit44 */
			{14274,45,0}, /* core1 elr_EL3 bit45 */
			{ 6856,45,0}, /* core1 elr_EL3 bit46 */
			{14272,45,0}, /* core1 elr_EL3 bit47 */
			{14276,45,0}, /* core1 elr_EL3 bit48 */
			{21406,45,0}, /* core1 elr_EL3 bit49 */
			{14250,45,0}, /* core1 elr_EL3 bit50 */
			{21398,45,0}, /* core1 elr_EL3 bit51 */
			{21396,45,0}, /* core1 elr_EL3 bit52 */
			{21394,45,0}, /* core1 elr_EL3 bit53 */
			{21392,45,0}, /* core1 elr_EL3 bit54 */
			{21390,45,0}, /* core1 elr_EL3 bit55 */
			{21388,45,0}, /* core1 elr_EL3 bit56 */
			{21386,45,0}, /* core1 elr_EL3 bit57 */
			{21404,45,0}, /* core1 elr_EL3 bit58 */
			{21384,45,0}, /* core1 elr_EL3 bit59 */
			{14280,45,0}, /* core1 elr_EL3 bit60 */
			{14248,45,0}, /* core1 elr_EL3 bit61 */
			{21402,45,0}, /* core1 elr_EL3 bit62 */
			{21400,45,0}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{20350,45,0}, /* core1 raw_pc bit0 */
			{19196,44,0}, /* core1 raw_pc bit1 */
			{19194,44,0}, /* core1 raw_pc bit2 */
			{19192,44,0}, /* core1 raw_pc bit3 */
			{19190,44,0}, /* core1 raw_pc bit4 */
			{20348,45,0}, /* core1 raw_pc bit5 */
			{20346,45,0}, /* core1 raw_pc bit6 */
			{19180,44,0}, /* core1 raw_pc bit7 */
			{19178,44,0}, /* core1 raw_pc bit8 */
			{19176,44,0}, /* core1 raw_pc bit9 */
			{19174,44,0}, /* core1 raw_pc bit10 */
			{19154,44,0}, /* core1 raw_pc bit11 */
			{19152,44,0}, /* core1 raw_pc bit12 */
			{19150,44,0}, /* core1 raw_pc bit13 */
			{19148,44,0}, /* core1 raw_pc bit14 */
			{19168,44,0}, /* core1 raw_pc bit15 */
			{19166,44,0}, /* core1 raw_pc bit16 */
			{19164,44,0}, /* core1 raw_pc bit17 */
			{19162,44,0}, /* core1 raw_pc bit18 */
			{19170,44,0}, /* core1 raw_pc bit19 */
			{19160,44,0}, /* core1 raw_pc bit20 */
			{19158,44,0}, /* core1 raw_pc bit21 */
			{19156,44,0}, /* core1 raw_pc bit22 */
			{19138,44,0}, /* core1 raw_pc bit23 */
			{19136,44,0}, /* core1 raw_pc bit24 */
			{19134,44,0}, /* core1 raw_pc bit25 */
			{19132,44,0}, /* core1 raw_pc bit26 */
			{19146,44,0}, /* core1 raw_pc bit27 */
			{19144,44,0}, /* core1 raw_pc bit28 */
			{19142,44,0}, /* core1 raw_pc bit29 */
			{19140,44,0}, /* core1 raw_pc bit30 */
			{18854,44,0}, /* core1 raw_pc bit31 */
			{18852,44,0}, /* core1 raw_pc bit32 */
			{18850,44,0}, /* core1 raw_pc bit33 */
			{18848,44,0}, /* core1 raw_pc bit34 */
			{18862,44,0}, /* core1 raw_pc bit35 */
			{18860,44,0}, /* core1 raw_pc bit36 */
			{18858,44,0}, /* core1 raw_pc bit37 */
			{18856,44,0}, /* core1 raw_pc bit38 */
			{18846,44,0}, /* core1 raw_pc bit39 */
			{18844,44,0}, /* core1 raw_pc bit40 */
			{18842,44,0}, /* core1 raw_pc bit41 */
			{18840,44,0}, /* core1 raw_pc bit42 */
			{18838,44,0}, /* core1 raw_pc bit43 */
			{18836,44,0}, /* core1 raw_pc bit44 */
			{18834,44,0}, /* core1 raw_pc bit45 */
			{18832,44,0}, /* core1 raw_pc bit46 */
			{11668,45,0}, /* core1 raw_pc bit47 */
			{20380,45,0}, /* core1 raw_pc bit48 */
			{20378,45,0}, /* core1 raw_pc bit49 */
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
			{12108,45,0}, /* core1 pc_iss bit0 */
			{12106,45,0}, /* core1 pc_iss bit1 */
			{12102,45,0}, /* core1 pc_iss bit2 */
			{20292,45,0}, /* core1 pc_iss bit3 */
			{20290,45,0}, /* core1 pc_iss bit4 */
			{20288,45,0}, /* core1 pc_iss bit5 */
			{20286,45,0}, /* core1 pc_iss bit6 */
			{12104,45,0}, /* core1 pc_iss bit7 */
			{20296,45,0}, /* core1 pc_iss bit8 */
			{20294,45,0}, /* core1 pc_iss bit9 */
			{20474,45,0}, /* core1 pc_iss bit10 */
			{20284,45,0}, /* core1 pc_iss bit11 */
			{20304,45,0}, /* core1 pc_iss bit12 */
			{20282,45,0}, /* core1 pc_iss bit13 */
			{20300,45,0}, /* core1 pc_iss bit14 */
			{20298,45,0}, /* core1 pc_iss bit15 */
			{20302,45,0}, /* core1 pc_iss bit16 */
			{20308,45,0}, /* core1 pc_iss bit17 */
			{20306,45,0}, /* core1 pc_iss bit18 */
			{20312,45,0}, /* core1 pc_iss bit19 */
			{20310,45,0}, /* core1 pc_iss bit20 */
			{20316,45,0}, /* core1 pc_iss bit21 */
			{20314,45,0}, /* core1 pc_iss bit22 */
			{20480,45,0}, /* core1 pc_iss bit23 */
			{20476,45,0}, /* core1 pc_iss bit24 */
			{20478,45,0}, /* core1 pc_iss bit25 */
			{20484,45,0}, /* core1 pc_iss bit26 */
			{20482,45,0}, /* core1 pc_iss bit27 */
			{20472,45,0}, /* core1 pc_iss bit28 */
			{20470,45,0}, /* core1 pc_iss bit29 */
			{20488,45,0}, /* core1 pc_iss bit30 */
			{20486,45,0}, /* core1 pc_iss bit31 */
			{19454,44,0}, /* core1 pc_iss bit32 */
			{20456,45,0}, /* core1 pc_iss bit33 */
			{20454,45,0}, /* core1 pc_iss bit34 */
			{20448,45,0}, /* core1 pc_iss bit35 */
			{20452,45,0}, /* core1 pc_iss bit36 */
			{20446,45,0}, /* core1 pc_iss bit37 */
			{20444,45,0}, /* core1 pc_iss bit38 */
			{20450,45,0}, /* core1 pc_iss bit39 */
			{20460,45,0}, /* core1 pc_iss bit40 */
			{20458,45,0}, /* core1 pc_iss bit41 */
			{20442,45,0}, /* core1 pc_iss bit42 */
			{20464,45,0}, /* core1 pc_iss bit43 */
			{20462,45,0}, /* core1 pc_iss bit44 */
			{19188,44,0}, /* core1 pc_iss bit45 */
			{19186,44,0}, /* core1 pc_iss bit46 */
			{19184,44,0}, /* core1 pc_iss bit47 */
			{19182,44,0}, /* core1 pc_iss bit48 */
			{19484,44,0}, /* core1 pc_iss bit49 */
			{19482,44,0}, /* core1 pc_iss bit50 */
			{19480,44,0}, /* core1 pc_iss bit51 */
			{19478,44,0}, /* core1 pc_iss bit52 */
			{19476,44,0}, /* core1 pc_iss bit53 */
			{19474,44,0}, /* core1 pc_iss bit54 */
			{19472,44,0}, /* core1 pc_iss bit55 */
			{19470,44,0}, /* core1 pc_iss bit56 */
			{19468,44,0}, /* core1 pc_iss bit57 */
			{19466,44,0}, /* core1 pc_iss bit58 */
			{19464,44,0}, /* core1 pc_iss bit59 */
			{19462,44,0}, /* core1 pc_iss bit60 */
			{19460,44,0}, /* core1 pc_iss bit61 */
			{19458,44,0}, /* core1 pc_iss bit62 */
			{19456,44,0}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{20352,45,0}, /* core1 full_pc_wr bit0 */
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
			{19404,44,0}, /* core1 full_pc_ex1 bit0 */
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
			{20280,45,0}, /* core1 full_pc_ex2 bit0 */
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
			{ 3944,46,0}, /* core1 return_Stack_pointer bit0 */
			{ 3948,46,0}, /* core1 return_Stack_pointer bit1 */
			{ 3942,46,0}, /* core1 return_Stack_pointer bit2 */
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
			{19558,46,0}, /* core1 return_Stack0 bit0 */
			{19550,46,0}, /* core1 return_Stack0 bit1 */
			{19548,46,0}, /* core1 return_Stack0 bit2 */
			{19546,46,0}, /* core1 return_Stack0 bit3 */
			{19544,46,0}, /* core1 return_Stack0 bit4 */
			{ 9376,46,0}, /* core1 return_Stack0 bit5 */
			{19502,46,0}, /* core1 return_Stack0 bit6 */
			{19500,46,0}, /* core1 return_Stack0 bit7 */
			{19498,46,0}, /* core1 return_Stack0 bit8 */
			{19496,46,0}, /* core1 return_Stack0 bit9 */
			{19478,46,0}, /* core1 return_Stack0 bit10 */
			{ 9374,46,0}, /* core1 return_Stack0 bit11 */
			{19476,46,0}, /* core1 return_Stack0 bit12 */
			{19474,46,0}, /* core1 return_Stack0 bit13 */
			{19472,46,0}, /* core1 return_Stack0 bit14 */
			{19470,46,0}, /* core1 return_Stack0 bit15 */
			{19468,46,0}, /* core1 return_Stack0 bit16 */
			{19466,46,0}, /* core1 return_Stack0 bit17 */
			{19464,46,0}, /* core1 return_Stack0 bit18 */
			{19486,46,0}, /* core1 return_Stack0 bit19 */
			{19484,46,0}, /* core1 return_Stack0 bit20 */
			{19482,46,0}, /* core1 return_Stack0 bit21 */
			{19480,46,0}, /* core1 return_Stack0 bit22 */
			{ 9384,46,0}, /* core1 return_Stack0 bit23 */
			{ 9382,46,0}, /* core1 return_Stack0 bit24 */
			{19556,46,0}, /* core1 return_Stack0 bit25 */
			{ 3830,46,0}, /* core1 return_Stack0 bit26 */
			{19554,46,0}, /* core1 return_Stack0 bit27 */
			{19552,46,0}, /* core1 return_Stack0 bit28 */
			{19542,46,0}, /* core1 return_Stack0 bit29 */
			{19540,46,0}, /* core1 return_Stack0 bit30 */
			{19538,46,0}, /* core1 return_Stack0 bit31 */
			{19536,46,0}, /* core1 return_Stack0 bit32 */
			{19534,46,0}, /* core1 return_Stack0 bit33 */
			{19532,46,0}, /* core1 return_Stack0 bit34 */
			{19530,46,0}, /* core1 return_Stack0 bit35 */
			{19528,46,0}, /* core1 return_Stack0 bit36 */
			{19526,46,0}, /* core1 return_Stack0 bit37 */
			{19524,46,0}, /* core1 return_Stack0 bit38 */
			{19522,46,0}, /* core1 return_Stack0 bit39 */
			{19520,46,0}, /* core1 return_Stack0 bit40 */
			{19518,46,0}, /* core1 return_Stack0 bit41 */
			{19516,46,0}, /* core1 return_Stack0 bit42 */
			{19514,46,0}, /* core1 return_Stack0 bit43 */
			{19512,46,0}, /* core1 return_Stack0 bit44 */
			{19510,46,0}, /* core1 return_Stack0 bit45 */
			{19508,46,0}, /* core1 return_Stack0 bit46 */
			{19506,46,0}, /* core1 return_Stack0 bit47 */
			{19504,46,0}, /* core1 return_Stack0 bit48 */
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
			{19566,46,0}, /* core1 return_Stack1 bit0 */
			{19574,46,0}, /* core1 return_Stack1 bit1 */
			{19572,46,0}, /* core1 return_Stack1 bit2 */
			{19570,46,0}, /* core1 return_Stack1 bit3 */
			{19568,46,0}, /* core1 return_Stack1 bit4 */
			{ 9380,46,0}, /* core1 return_Stack1 bit5 */
			{19494,46,0}, /* core1 return_Stack1 bit6 */
			{19492,46,0}, /* core1 return_Stack1 bit7 */
			{19490,46,0}, /* core1 return_Stack1 bit8 */
			{19488,46,0}, /* core1 return_Stack1 bit9 */
			{19462,46,0}, /* core1 return_Stack1 bit10 */
			{ 9378,46,0}, /* core1 return_Stack1 bit11 */
			{19460,46,0}, /* core1 return_Stack1 bit12 */
			{19458,46,0}, /* core1 return_Stack1 bit13 */
			{19456,46,0}, /* core1 return_Stack1 bit14 */
			{19204,46,0}, /* core1 return_Stack1 bit15 */
			{19202,46,0}, /* core1 return_Stack1 bit16 */
			{19200,46,0}, /* core1 return_Stack1 bit17 */
			{19198,46,0}, /* core1 return_Stack1 bit18 */
			{19188,46,0}, /* core1 return_Stack1 bit19 */
			{19186,46,0}, /* core1 return_Stack1 bit20 */
			{19184,46,0}, /* core1 return_Stack1 bit21 */
			{19182,46,0}, /* core1 return_Stack1 bit22 */
			{ 9388,46,0}, /* core1 return_Stack1 bit23 */
			{ 9386,46,0}, /* core1 return_Stack1 bit24 */
			{19564,46,0}, /* core1 return_Stack1 bit25 */
			{ 3828,46,0}, /* core1 return_Stack1 bit26 */
			{19562,46,0}, /* core1 return_Stack1 bit27 */
			{19560,46,0}, /* core1 return_Stack1 bit28 */
			{19164,46,0}, /* core1 return_Stack1 bit29 */
			{19162,46,0}, /* core1 return_Stack1 bit30 */
			{19160,46,0}, /* core1 return_Stack1 bit31 */
			{19158,46,0}, /* core1 return_Stack1 bit32 */
			{19124,46,0}, /* core1 return_Stack1 bit33 */
			{19122,46,0}, /* core1 return_Stack1 bit34 */
			{19120,46,0}, /* core1 return_Stack1 bit35 */
			{19118,46,0}, /* core1 return_Stack1 bit36 */
			{19116,46,0}, /* core1 return_Stack1 bit37 */
			{19114,46,0}, /* core1 return_Stack1 bit38 */
			{19112,46,0}, /* core1 return_Stack1 bit39 */
			{19110,46,0}, /* core1 return_Stack1 bit40 */
			{19076,46,0}, /* core1 return_Stack1 bit41 */
			{19074,46,0}, /* core1 return_Stack1 bit42 */
			{19072,46,0}, /* core1 return_Stack1 bit43 */
			{19070,46,0}, /* core1 return_Stack1 bit44 */
			{19068,46,0}, /* core1 return_Stack1 bit45 */
			{19066,46,0}, /* core1 return_Stack1 bit46 */
			{19064,46,0}, /* core1 return_Stack1 bit47 */
			{19062,46,0}, /* core1 return_Stack1 bit48 */
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
			{19372,46,0}, /* core1 return_Stack2 bit0 */
			{19370,46,0}, /* core1 return_Stack2 bit1 */
			{19368,46,0}, /* core1 return_Stack2 bit2 */
			{19366,46,0}, /* core1 return_Stack2 bit3 */
			{19060,46,0}, /* core1 return_Stack2 bit4 */
			{19058,46,0}, /* core1 return_Stack2 bit5 */
			{19056,46,0}, /* core1 return_Stack2 bit6 */
			{19054,46,0}, /* core1 return_Stack2 bit7 */
			{19196,46,0}, /* core1 return_Stack2 bit8 */
			{19194,46,0}, /* core1 return_Stack2 bit9 */
			{19192,46,0}, /* core1 return_Stack2 bit10 */
			{19190,46,0}, /* core1 return_Stack2 bit11 */
			{19260,46,0}, /* core1 return_Stack2 bit12 */
			{19258,46,0}, /* core1 return_Stack2 bit13 */
			{19256,46,0}, /* core1 return_Stack2 bit14 */
			{19254,46,0}, /* core1 return_Stack2 bit15 */
			{19244,46,0}, /* core1 return_Stack2 bit16 */
			{19242,46,0}, /* core1 return_Stack2 bit17 */
			{19240,46,0}, /* core1 return_Stack2 bit18 */
			{19238,46,0}, /* core1 return_Stack2 bit19 */
			{19308,46,0}, /* core1 return_Stack2 bit20 */
			{19306,46,0}, /* core1 return_Stack2 bit21 */
			{19304,46,0}, /* core1 return_Stack2 bit22 */
			{19302,46,0}, /* core1 return_Stack2 bit23 */
			{19340,46,0}, /* core1 return_Stack2 bit24 */
			{19338,46,0}, /* core1 return_Stack2 bit25 */
			{19336,46,0}, /* core1 return_Stack2 bit26 */
			{19334,46,0}, /* core1 return_Stack2 bit27 */
			{19404,46,0}, /* core1 return_Stack2 bit28 */
			{19402,46,0}, /* core1 return_Stack2 bit29 */
			{19400,46,0}, /* core1 return_Stack2 bit30 */
			{19398,46,0}, /* core1 return_Stack2 bit31 */
			{19140,46,0}, /* core1 return_Stack2 bit32 */
			{19138,46,0}, /* core1 return_Stack2 bit33 */
			{19136,46,0}, /* core1 return_Stack2 bit34 */
			{19134,46,0}, /* core1 return_Stack2 bit35 */
			{19420,46,0}, /* core1 return_Stack2 bit36 */
			{19418,46,0}, /* core1 return_Stack2 bit37 */
			{19416,46,0}, /* core1 return_Stack2 bit38 */
			{19414,46,0}, /* core1 return_Stack2 bit39 */
			{19100,46,0}, /* core1 return_Stack2 bit40 */
			{19098,46,0}, /* core1 return_Stack2 bit41 */
			{19096,46,0}, /* core1 return_Stack2 bit42 */
			{19094,46,0}, /* core1 return_Stack2 bit43 */
			{19044,46,0}, /* core1 return_Stack2 bit44 */
			{19042,46,0}, /* core1 return_Stack2 bit45 */
			{19040,46,0}, /* core1 return_Stack2 bit46 */
			{19038,46,0}, /* core1 return_Stack2 bit47 */
			{ 3838,46,0}, /* core1 return_Stack2 bit48 */
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
			{19380,46,0}, /* core1 return_Stack3 bit0 */
			{19378,46,0}, /* core1 return_Stack3 bit1 */
			{19376,46,0}, /* core1 return_Stack3 bit2 */
			{19374,46,0}, /* core1 return_Stack3 bit3 */
			{19180,46,0}, /* core1 return_Stack3 bit4 */
			{19178,46,0}, /* core1 return_Stack3 bit5 */
			{ 3836,46,0}, /* core1 return_Stack3 bit6 */
			{19176,46,0}, /* core1 return_Stack3 bit7 */
			{19174,46,0}, /* core1 return_Stack3 bit8 */
			{19276,46,0}, /* core1 return_Stack3 bit9 */
			{19274,46,0}, /* core1 return_Stack3 bit10 */
			{19272,46,0}, /* core1 return_Stack3 bit11 */
			{19270,46,0}, /* core1 return_Stack3 bit12 */
			{19252,46,0}, /* core1 return_Stack3 bit13 */
			{19250,46,0}, /* core1 return_Stack3 bit14 */
			{19248,46,0}, /* core1 return_Stack3 bit15 */
			{19246,46,0}, /* core1 return_Stack3 bit16 */
			{19268,46,0}, /* core1 return_Stack3 bit17 */
			{19266,46,0}, /* core1 return_Stack3 bit18 */
			{19264,46,0}, /* core1 return_Stack3 bit19 */
			{19262,46,0}, /* core1 return_Stack3 bit20 */
			{19324,46,0}, /* core1 return_Stack3 bit21 */
			{19322,46,0}, /* core1 return_Stack3 bit22 */
			{19320,46,0}, /* core1 return_Stack3 bit23 */
			{19318,46,0}, /* core1 return_Stack3 bit24 */
			{19356,46,0}, /* core1 return_Stack3 bit25 */
			{19354,46,0}, /* core1 return_Stack3 bit26 */
			{19352,46,0}, /* core1 return_Stack3 bit27 */
			{19350,46,0}, /* core1 return_Stack3 bit28 */
			{19412,46,0}, /* core1 return_Stack3 bit29 */
			{19410,46,0}, /* core1 return_Stack3 bit30 */
			{19408,46,0}, /* core1 return_Stack3 bit31 */
			{19406,46,0}, /* core1 return_Stack3 bit32 */
			{19436,46,0}, /* core1 return_Stack3 bit33 */
			{19434,46,0}, /* core1 return_Stack3 bit34 */
			{19432,46,0}, /* core1 return_Stack3 bit35 */
			{19430,46,0}, /* core1 return_Stack3 bit36 */
			{19428,46,0}, /* core1 return_Stack3 bit37 */
			{19426,46,0}, /* core1 return_Stack3 bit38 */
			{19424,46,0}, /* core1 return_Stack3 bit39 */
			{19422,46,0}, /* core1 return_Stack3 bit40 */
			{19084,46,0}, /* core1 return_Stack3 bit41 */
			{19082,46,0}, /* core1 return_Stack3 bit42 */
			{19080,46,0}, /* core1 return_Stack3 bit43 */
			{19078,46,0}, /* core1 return_Stack3 bit44 */
			{19036,46,0}, /* core1 return_Stack3 bit45 */
			{19034,46,0}, /* core1 return_Stack3 bit46 */
			{19032,46,0}, /* core1 return_Stack3 bit47 */
			{19030,46,0}, /* core1 return_Stack3 bit48 */
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
			{19388,46,0}, /* core1 return_Stack4 bit0 */
			{19386,46,0}, /* core1 return_Stack4 bit1 */
			{19384,46,0}, /* core1 return_Stack4 bit2 */
			{19382,46,0}, /* core1 return_Stack4 bit3 */
			{19052,46,0}, /* core1 return_Stack4 bit4 */
			{19050,46,0}, /* core1 return_Stack4 bit5 */
			{19048,46,0}, /* core1 return_Stack4 bit6 */
			{19046,46,0}, /* core1 return_Stack4 bit7 */
			{19292,46,0}, /* core1 return_Stack4 bit8 */
			{19290,46,0}, /* core1 return_Stack4 bit9 */
			{19288,46,0}, /* core1 return_Stack4 bit10 */
			{19286,46,0}, /* core1 return_Stack4 bit11 */
			{19236,46,0}, /* core1 return_Stack4 bit12 */
			{19234,46,0}, /* core1 return_Stack4 bit13 */
			{19232,46,0}, /* core1 return_Stack4 bit14 */
			{19230,46,0}, /* core1 return_Stack4 bit15 */
			{19228,46,0}, /* core1 return_Stack4 bit16 */
			{19226,46,0}, /* core1 return_Stack4 bit17 */
			{19224,46,0}, /* core1 return_Stack4 bit18 */
			{19222,46,0}, /* core1 return_Stack4 bit19 */
			{19316,46,0}, /* core1 return_Stack4 bit20 */
			{19314,46,0}, /* core1 return_Stack4 bit21 */
			{19312,46,0}, /* core1 return_Stack4 bit22 */
			{19310,46,0}, /* core1 return_Stack4 bit23 */
			{19332,46,0}, /* core1 return_Stack4 bit24 */
			{19330,46,0}, /* core1 return_Stack4 bit25 */
			{19328,46,0}, /* core1 return_Stack4 bit26 */
			{19326,46,0}, /* core1 return_Stack4 bit27 */
			{19396,46,0}, /* core1 return_Stack4 bit28 */
			{19394,46,0}, /* core1 return_Stack4 bit29 */
			{19392,46,0}, /* core1 return_Stack4 bit30 */
			{19390,46,0}, /* core1 return_Stack4 bit31 */
			{19452,46,0}, /* core1 return_Stack4 bit32 */
			{19450,46,0}, /* core1 return_Stack4 bit33 */
			{19448,46,0}, /* core1 return_Stack4 bit34 */
			{19446,46,0}, /* core1 return_Stack4 bit35 */
			{19444,46,0}, /* core1 return_Stack4 bit36 */
			{19442,46,0}, /* core1 return_Stack4 bit37 */
			{19440,46,0}, /* core1 return_Stack4 bit38 */
			{19438,46,0}, /* core1 return_Stack4 bit39 */
			{19108,46,0}, /* core1 return_Stack4 bit40 */
			{19106,46,0}, /* core1 return_Stack4 bit41 */
			{19104,46,0}, /* core1 return_Stack4 bit42 */
			{19102,46,0}, /* core1 return_Stack4 bit43 */
			{19028,46,0}, /* core1 return_Stack4 bit44 */
			{19026,46,0}, /* core1 return_Stack4 bit45 */
			{19024,46,0}, /* core1 return_Stack4 bit46 */
			{19022,46,0}, /* core1 return_Stack4 bit47 */
			{ 3832,46,0}, /* core1 return_Stack4 bit48 */
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
			{19364,46,0}, /* core1 return_Stack5 bit0 */
			{19362,46,0}, /* core1 return_Stack5 bit1 */
			{19360,46,0}, /* core1 return_Stack5 bit2 */
			{19358,46,0}, /* core1 return_Stack5 bit3 */
			{19172,46,0}, /* core1 return_Stack5 bit4 */
			{19170,46,0}, /* core1 return_Stack5 bit5 */
			{19168,46,0}, /* core1 return_Stack5 bit6 */
			{19166,46,0}, /* core1 return_Stack5 bit7 */
			{19284,46,0}, /* core1 return_Stack5 bit8 */
			{19282,46,0}, /* core1 return_Stack5 bit9 */
			{19280,46,0}, /* core1 return_Stack5 bit10 */
			{19278,46,0}, /* core1 return_Stack5 bit11 */
			{19212,46,0}, /* core1 return_Stack5 bit12 */
			{19210,46,0}, /* core1 return_Stack5 bit13 */
			{19208,46,0}, /* core1 return_Stack5 bit14 */
			{19206,46,0}, /* core1 return_Stack5 bit15 */
			{19220,46,0}, /* core1 return_Stack5 bit16 */
			{19218,46,0}, /* core1 return_Stack5 bit17 */
			{19216,46,0}, /* core1 return_Stack5 bit18 */
			{19214,46,0}, /* core1 return_Stack5 bit19 */
			{19300,46,0}, /* core1 return_Stack5 bit20 */
			{19298,46,0}, /* core1 return_Stack5 bit21 */
			{19296,46,0}, /* core1 return_Stack5 bit22 */
			{19294,46,0}, /* core1 return_Stack5 bit23 */
			{19348,46,0}, /* core1 return_Stack5 bit24 */
			{19346,46,0}, /* core1 return_Stack5 bit25 */
			{19344,46,0}, /* core1 return_Stack5 bit26 */
			{19342,46,0}, /* core1 return_Stack5 bit27 */
			{19156,46,0}, /* core1 return_Stack5 bit28 */
			{19154,46,0}, /* core1 return_Stack5 bit29 */
			{19152,46,0}, /* core1 return_Stack5 bit30 */
			{19150,46,0}, /* core1 return_Stack5 bit31 */
			{19132,46,0}, /* core1 return_Stack5 bit32 */
			{19130,46,0}, /* core1 return_Stack5 bit33 */
			{19128,46,0}, /* core1 return_Stack5 bit34 */
			{19126,46,0}, /* core1 return_Stack5 bit35 */
			{19148,46,0}, /* core1 return_Stack5 bit36 */
			{19146,46,0}, /* core1 return_Stack5 bit37 */
			{19144,46,0}, /* core1 return_Stack5 bit38 */
			{19142,46,0}, /* core1 return_Stack5 bit39 */
			{19092,46,0}, /* core1 return_Stack5 bit40 */
			{19090,46,0}, /* core1 return_Stack5 bit41 */
			{19088,46,0}, /* core1 return_Stack5 bit42 */
			{19086,46,0}, /* core1 return_Stack5 bit43 */
			{19020,46,0}, /* core1 return_Stack5 bit44 */
			{19018,46,0}, /* core1 return_Stack5 bit45 */
			{19016,46,0}, /* core1 return_Stack5 bit46 */
			{19014,46,0}, /* core1 return_Stack5 bit47 */
			{ 3834,46,0}, /* core1 return_Stack5 bit48 */
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
			{18762,46,0}, /* core1 return_Stack6 bit0 */
			{18760,46,0}, /* core1 return_Stack6 bit1 */
			{18758,46,0}, /* core1 return_Stack6 bit2 */
			{18756,46,0}, /* core1 return_Stack6 bit3 */
			{18738,46,0}, /* core1 return_Stack6 bit4 */
			{18858,46,0}, /* core1 return_Stack6 bit5 */
			{18736,46,0}, /* core1 return_Stack6 bit6 */
			{18856,46,0}, /* core1 return_Stack6 bit7 */
			{18734,46,0}, /* core1 return_Stack6 bit8 */
			{18732,46,0}, /* core1 return_Stack6 bit9 */
			{ 3824,46,0}, /* core1 return_Stack6 bit10 */
			{18854,46,0}, /* core1 return_Stack6 bit11 */
			{18852,46,0}, /* core1 return_Stack6 bit12 */
			{18818,46,0}, /* core1 return_Stack6 bit13 */
			{18816,46,0}, /* core1 return_Stack6 bit14 */
			{18814,46,0}, /* core1 return_Stack6 bit15 */
			{18812,46,0}, /* core1 return_Stack6 bit16 */
			{18826,46,0}, /* core1 return_Stack6 bit17 */
			{18824,46,0}, /* core1 return_Stack6 bit18 */
			{18822,46,0}, /* core1 return_Stack6 bit19 */
			{18820,46,0}, /* core1 return_Stack6 bit20 */
			{18794,46,0}, /* core1 return_Stack6 bit21 */
			{18792,46,0}, /* core1 return_Stack6 bit22 */
			{18790,46,0}, /* core1 return_Stack6 bit23 */
			{18788,46,0}, /* core1 return_Stack6 bit24 */
			{18786,46,0}, /* core1 return_Stack6 bit25 */
			{18784,46,0}, /* core1 return_Stack6 bit26 */
			{18782,46,0}, /* core1 return_Stack6 bit27 */
			{18780,46,0}, /* core1 return_Stack6 bit28 */
			{18746,46,0}, /* core1 return_Stack6 bit29 */
			{18744,46,0}, /* core1 return_Stack6 bit30 */
			{18742,46,0}, /* core1 return_Stack6 bit31 */
			{18740,46,0}, /* core1 return_Stack6 bit32 */
			{18986,46,0}, /* core1 return_Stack6 bit33 */
			{18984,46,0}, /* core1 return_Stack6 bit34 */
			{18982,46,0}, /* core1 return_Stack6 bit35 */
			{18980,46,0}, /* core1 return_Stack6 bit36 */
			{18978,46,0}, /* core1 return_Stack6 bit37 */
			{18976,46,0}, /* core1 return_Stack6 bit38 */
			{18974,46,0}, /* core1 return_Stack6 bit39 */
			{18972,46,0}, /* core1 return_Stack6 bit40 */
			{18946,46,0}, /* core1 return_Stack6 bit41 */
			{18944,46,0}, /* core1 return_Stack6 bit42 */
			{18942,46,0}, /* core1 return_Stack6 bit43 */
			{18940,46,0}, /* core1 return_Stack6 bit44 */
			{18730,46,0}, /* core1 return_Stack6 bit45 */
			{18728,46,0}, /* core1 return_Stack6 bit46 */
			{18726,46,0}, /* core1 return_Stack6 bit47 */
			{18724,46,0}, /* core1 return_Stack6 bit48 */
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
			{18770,46,0}, /* core1 return_Stack7 bit0 */
			{18768,46,0}, /* core1 return_Stack7 bit1 */
			{18766,46,0}, /* core1 return_Stack7 bit2 */
			{18764,46,0}, /* core1 return_Stack7 bit3 */
			{18810,46,0}, /* core1 return_Stack7 bit4 */
			{18850,46,0}, /* core1 return_Stack7 bit5 */
			{18808,46,0}, /* core1 return_Stack7 bit6 */
			{18848,46,0}, /* core1 return_Stack7 bit7 */
			{18806,46,0}, /* core1 return_Stack7 bit8 */
			{18804,46,0}, /* core1 return_Stack7 bit9 */
			{ 3826,46,0}, /* core1 return_Stack7 bit10 */
			{18846,46,0}, /* core1 return_Stack7 bit11 */
			{18844,46,0}, /* core1 return_Stack7 bit12 */
			{18834,46,0}, /* core1 return_Stack7 bit13 */
			{18832,46,0}, /* core1 return_Stack7 bit14 */
			{18830,46,0}, /* core1 return_Stack7 bit15 */
			{18828,46,0}, /* core1 return_Stack7 bit16 */
			{18842,46,0}, /* core1 return_Stack7 bit17 */
			{18840,46,0}, /* core1 return_Stack7 bit18 */
			{18838,46,0}, /* core1 return_Stack7 bit19 */
			{18836,46,0}, /* core1 return_Stack7 bit20 */
			{18802,46,0}, /* core1 return_Stack7 bit21 */
			{18800,46,0}, /* core1 return_Stack7 bit22 */
			{18798,46,0}, /* core1 return_Stack7 bit23 */
			{18796,46,0}, /* core1 return_Stack7 bit24 */
			{18778,46,0}, /* core1 return_Stack7 bit25 */
			{18776,46,0}, /* core1 return_Stack7 bit26 */
			{18774,46,0}, /* core1 return_Stack7 bit27 */
			{18772,46,0}, /* core1 return_Stack7 bit28 */
			{18754,46,0}, /* core1 return_Stack7 bit29 */
			{18752,46,0}, /* core1 return_Stack7 bit30 */
			{18750,46,0}, /* core1 return_Stack7 bit31 */
			{18748,46,0}, /* core1 return_Stack7 bit32 */
			{18970,46,0}, /* core1 return_Stack7 bit33 */
			{18968,46,0}, /* core1 return_Stack7 bit34 */
			{18966,46,0}, /* core1 return_Stack7 bit35 */
			{18964,46,0}, /* core1 return_Stack7 bit36 */
			{18962,46,0}, /* core1 return_Stack7 bit37 */
			{18960,46,0}, /* core1 return_Stack7 bit38 */
			{18958,46,0}, /* core1 return_Stack7 bit39 */
			{18956,46,0}, /* core1 return_Stack7 bit40 */
			{18954,46,0}, /* core1 return_Stack7 bit41 */
			{18952,46,0}, /* core1 return_Stack7 bit42 */
			{18950,46,0}, /* core1 return_Stack7 bit43 */
			{18948,46,0}, /* core1 return_Stack7 bit44 */
			{18722,46,0}, /* core1 return_Stack7 bit45 */
			{18720,46,0}, /* core1 return_Stack7 bit46 */
			{18718,46,0}, /* core1 return_Stack7 bit47 */
			{18716,46,0}, /* core1 return_Stack7 bit48 */
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
	},
	{		/* core 2 */ 
			.pc = {{
			{ 2530,48,1}, /* core2 pc bit0 */
			{ 2528,48,1}, /* core2 pc bit1 */
			{ 2526,48,1}, /* core2 pc bit2 */
			{ 2524,48,1}, /* core2 pc bit3 */
			{ 2594,48,1}, /* core2 pc bit4 */
			{ 2592,48,1}, /* core2 pc bit5 */
			{ 2590,48,1}, /* core2 pc bit6 */
			{ 2588,48,1}, /* core2 pc bit7 */
			{ 2578,48,1}, /* core2 pc bit8 */
			{ 2458,48,1}, /* core2 pc bit9 */
			{ 2456,48,1}, /* core2 pc bit10 */
			{ 2576,48,1}, /* core2 pc bit11 */
			{ 2574,48,1}, /* core2 pc bit12 */
			{ 2572,48,1}, /* core2 pc bit13 */
			{ 2454,48,1}, /* core2 pc bit14 */
			{ 2452,48,1}, /* core2 pc bit15 */
			{ 2306,48,1}, /* core2 pc bit16 */
			{ 2474,48,1}, /* core2 pc bit17 */
			{ 2304,48,1}, /* core2 pc bit18 */
			{ 2472,48,1}, /* core2 pc bit19 */
			{ 2302,48,1}, /* core2 pc bit20 */
			{ 2300,48,1}, /* core2 pc bit21 */
			{ 2470,48,1}, /* core2 pc bit22 */
			{ 2314,48,1}, /* core2 pc bit23 */
			{ 2312,48,1}, /* core2 pc bit24 */
			{ 2310,48,1}, /* core2 pc bit25 */
			{ 2468,48,1}, /* core2 pc bit26 */
			{ 2522,48,1}, /* core2 pc bit27 */
			{ 2308,48,1}, /* core2 pc bit28 */
			{ 2464,48,1}, /* core2 pc bit29 */
			{ 2684,48,1}, /* core2 pc bit30 */
			{ 2520,48,1}, /* core2 pc bit31 */
			{ 2518,48,1}, /* core2 pc bit32 */
			{ 2516,48,1}, /* core2 pc bit33 */
			{ 2562,48,1}, /* core2 pc bit34 */
			{ 2560,48,1}, /* core2 pc bit35 */
			{ 2558,48,1}, /* core2 pc bit36 */
			{ 2556,48,1}, /* core2 pc bit37 */
			{ 2586,48,1}, /* core2 pc bit38 */
			{ 2584,48,1}, /* core2 pc bit39 */
			{ 2582,48,1}, /* core2 pc bit40 */
			{ 2580,48,1}, /* core2 pc bit41 */
			{ 2570,48,1}, /* core2 pc bit42 */
			{ 2568,48,1}, /* core2 pc bit43 */
			{ 2566,48,1}, /* core2 pc bit44 */
			{ 2564,48,1}, /* core2 pc bit45 */
			{ 2626,48,1}, /* core2 pc bit46 */
			{ 2624,48,1}, /* core2 pc bit47 */
			{ 2622,48,1}, /* core2 pc bit48 */
			{ 2620,48,1}, /* core2 pc bit49 */
			{ 2658,48,1}, /* core2 pc bit50 */
			{ 2656,48,1}, /* core2 pc bit51 */
			{ 2654,48,1}, /* core2 pc bit52 */
			{ 2652,48,1}, /* core2 pc bit53 */
			{ 2290,48,1}, /* core2 pc bit54 */
			{ 2288,48,1}, /* core2 pc bit55 */
			{ 2286,48,1}, /* core2 pc bit56 */
			{ 2284,48,1}, /* core2 pc bit57 */
			{ 2132,48,1}, /* core2 pc bit58 */
			{ 2130,48,1}, /* core2 pc bit59 */
			{ 2128,48,1}, /* core2 pc bit60 */
			{ 2126,48,1}, /* core2 pc bit61 */
			{ 2116,48,1}, /* core2 pc bit62 */
			{  670,48,1}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{ 7110,52,0}, /* core2 sp32 bit0 */
			{15738,52,0}, /* core2 sp32 bit1 */
			{15732,52,0}, /* core2 sp32 bit2 */
			{ 7088,52,0}, /* core2 sp32 bit3 */
			{15730,52,0}, /* core2 sp32 bit4 */
			{15740,52,0}, /* core2 sp32 bit5 */
			{15716,52,0}, /* core2 sp32 bit6 */
			{15714,52,0}, /* core2 sp32 bit7 */
			{15724,52,0}, /* core2 sp32 bit8 */
			{15682,52,0}, /* core2 sp32 bit9 */
			{15692,52,0}, /* core2 sp32 bit10 */
			{15722,52,0}, /* core2 sp32 bit11 */
			{15712,52,0}, /* core2 sp32 bit12 */
			{15710,52,0}, /* core2 sp32 bit13 */
			{15690,52,0}, /* core2 sp32 bit14 */
			{22706,52,0}, /* core2 sp32 bit15 */
			{22704,52,0}, /* core2 sp32 bit16 */
			{22702,52,0}, /* core2 sp32 bit17 */
			{22700,52,0}, /* core2 sp32 bit18 */
			{15720,52,0}, /* core2 sp32 bit19 */
			{15718,52,0}, /* core2 sp32 bit20 */
			{15736,52,0}, /* core2 sp32 bit21 */
			{15728,52,0}, /* core2 sp32 bit22 */
			{15726,52,0}, /* core2 sp32 bit23 */
			{15734,52,0}, /* core2 sp32 bit24 */
			{15924,52,0}, /* core2 sp32 bit25 */
			{15922,52,0}, /* core2 sp32 bit26 */
			{15920,52,0}, /* core2 sp32 bit27 */
			{15918,52,0}, /* core2 sp32 bit28 */
			{15688,52,0}, /* core2 sp32 bit29 */
			{15686,52,0}, /* core2 sp32 bit30 */
			{15684,52,0}, /* core2 sp32 bit31 */
			{15864,52,0}, /* core2 sp32 bit32 */
			{15862,52,0}, /* core2 sp32 bit33 */
			{15856,52,0}, /* core2 sp32 bit34 */
			{15868,52,0}, /* core2 sp32 bit35 */
			{15852,52,0}, /* core2 sp32 bit36 */
			{15866,52,0}, /* core2 sp32 bit37 */
			{ 6780,52,0}, /* core2 sp32 bit38 */
			{15850,52,0}, /* core2 sp32 bit39 */
			{15854,52,0}, /* core2 sp32 bit40 */
			{15848,52,0}, /* core2 sp32 bit41 */
			{15846,52,0}, /* core2 sp32 bit42 */
			{15844,52,0}, /* core2 sp32 bit43 */
			{15842,52,0}, /* core2 sp32 bit44 */
			{15860,52,0}, /* core2 sp32 bit45 */
			{15858,52,0}, /* core2 sp32 bit46 */
			{15872,52,0}, /* core2 sp32 bit47 */
			{15876,52,0}, /* core2 sp32 bit48 */
			{22370,52,0}, /* core2 sp32 bit49 */
			{22368,52,0}, /* core2 sp32 bit50 */
			{22366,52,0}, /* core2 sp32 bit51 */
			{22364,52,0}, /* core2 sp32 bit52 */
			{22354,52,0}, /* core2 sp32 bit53 */
			{22352,52,0}, /* core2 sp32 bit54 */
			{22350,52,0}, /* core2 sp32 bit55 */
			{22348,52,0}, /* core2 sp32 bit56 */
			{22362,52,0}, /* core2 sp32 bit57 */
			{22360,52,0}, /* core2 sp32 bit58 */
			{22358,52,0}, /* core2 sp32 bit59 */
			{22356,52,0}, /* core2 sp32 bit60 */
			{15870,52,0}, /* core2 sp32 bit61 */
			{15874,52,0}, /* core2 sp32 bit62 */
			{ 6776,52,0}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7124,52,0}, /* core2 fp32 bit0 */
			{ 7120,52,0}, /* core2 fp32 bit1 */
			{16530,52,0}, /* core2 fp32 bit2 */
			{16884,52,0}, /* core2 fp32 bit3 */
			{16880,52,0}, /* core2 fp32 bit4 */
			{16878,52,0}, /* core2 fp32 bit5 */
			{16876,52,0}, /* core2 fp32 bit6 */
			{16882,52,0}, /* core2 fp32 bit7 */
			{16874,52,0}, /* core2 fp32 bit8 */
			{16796,52,0}, /* core2 fp32 bit9 */
			{16794,52,0}, /* core2 fp32 bit10 */
			{ 7118,52,0}, /* core2 fp32 bit11 */
			{16548,52,0}, /* core2 fp32 bit12 */
			{16892,52,0}, /* core2 fp32 bit13 */
			{16792,52,0}, /* core2 fp32 bit14 */
			{16784,52,0}, /* core2 fp32 bit15 */
			{16886,52,0}, /* core2 fp32 bit16 */
			{16890,52,0}, /* core2 fp32 bit17 */
			{ 7116,52,0}, /* core2 fp32 bit18 */
			{ 7082,52,0}, /* core2 fp32 bit19 */
			{16546,52,0}, /* core2 fp32 bit20 */
			{16888,52,0}, /* core2 fp32 bit21 */
			{16532,52,0}, /* core2 fp32 bit22 */
			{ 7084,52,0}, /* core2 fp32 bit23 */
			{ 7114,52,0}, /* core2 fp32 bit24 */
			{ 6906,52,0}, /* core2 fp32 bit25 */
			{16782,52,0}, /* core2 fp32 bit26 */
			{16790,52,0}, /* core2 fp32 bit27 */
			{16788,52,0}, /* core2 fp32 bit28 */
			{ 6902,52,0}, /* core2 fp32 bit29 */
			{16786,52,0}, /* core2 fp32 bit30 */
			{ 6904,52,0}, /* core2 fp32 bit31 */
			{ 6830,52,0}, /* core2 fp32 bit32 */
			{ 6822,52,0}, /* core2 fp32 bit33 */
			{ 6824,52,0}, /* core2 fp32 bit34 */
			{ 6886,52,0}, /* core2 fp32 bit35 */
			{ 6884,52,0}, /* core2 fp32 bit36 */
			{ 6826,52,0}, /* core2 fp32 bit37 */
			{16624,52,0}, /* core2 fp32 bit38 */
			{16622,52,0}, /* core2 fp32 bit39 */
			{16632,52,0}, /* core2 fp32 bit40 */
			{16628,52,0}, /* core2 fp32 bit41 */
			{ 6820,52,0}, /* core2 fp32 bit42 */
			{16630,52,0}, /* core2 fp32 bit43 */
			{16626,52,0}, /* core2 fp32 bit44 */
			{16656,52,0}, /* core2 fp32 bit45 */
			{16648,52,0}, /* core2 fp32 bit46 */
			{16636,52,0}, /* core2 fp32 bit47 */
			{16634,52,0}, /* core2 fp32 bit48 */
			{22546,52,0}, /* core2 fp32 bit49 */
			{ 6818,52,0}, /* core2 fp32 bit50 */
			{22554,52,0}, /* core2 fp32 bit51 */
			{22552,52,0}, /* core2 fp32 bit52 */
			{22544,52,0}, /* core2 fp32 bit53 */
			{22542,52,0}, /* core2 fp32 bit54 */
			{22540,52,0}, /* core2 fp32 bit55 */
			{22550,52,0}, /* core2 fp32 bit56 */
			{22562,52,0}, /* core2 fp32 bit57 */
			{22560,52,0}, /* core2 fp32 bit58 */
			{22548,52,0}, /* core2 fp32 bit59 */
			{16646,52,0}, /* core2 fp32 bit60 */
			{16654,52,0}, /* core2 fp32 bit61 */
			{22558,52,0}, /* core2 fp32 bit62 */
			{22556,52,0}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{14752,52,0}, /* core2 fp64 bit0 */
			{ 6972,52,0}, /* core2 fp64 bit1 */
			{14750,52,0}, /* core2 fp64 bit2 */
			{15068,52,0}, /* core2 fp64 bit3 */
			{15066,52,0}, /* core2 fp64 bit4 */
			{15080,52,0}, /* core2 fp64 bit5 */
			{15078,52,0}, /* core2 fp64 bit6 */
			{15076,52,0}, /* core2 fp64 bit7 */
			{15074,52,0}, /* core2 fp64 bit8 */
			{15020,52,0}, /* core2 fp64 bit9 */
			{14798,52,0}, /* core2 fp64 bit10 */
			{15060,52,0}, /* core2 fp64 bit11 */
			{15058,52,0}, /* core2 fp64 bit12 */
			{15072,52,0}, /* core2 fp64 bit13 */
			{15018,52,0}, /* core2 fp64 bit14 */
			{14804,52,0}, /* core2 fp64 bit15 */
			{15070,52,0}, /* core2 fp64 bit16 */
			{15084,52,0}, /* core2 fp64 bit17 */
			{14748,52,0}, /* core2 fp64 bit18 */
			{15082,52,0}, /* core2 fp64 bit19 */
			{15064,52,0}, /* core2 fp64 bit20 */
			{14746,52,0}, /* core2 fp64 bit21 */
			{15062,52,0}, /* core2 fp64 bit22 */
			{ 7066,52,0}, /* core2 fp64 bit23 */
			{14756,52,0}, /* core2 fp64 bit24 */
			{14754,52,0}, /* core2 fp64 bit25 */
			{ 6946,52,0}, /* core2 fp64 bit26 */
			{14808,52,0}, /* core2 fp64 bit27 */
			{14806,52,0}, /* core2 fp64 bit28 */
			{14802,52,0}, /* core2 fp64 bit29 */
			{ 6970,52,0}, /* core2 fp64 bit30 */
			{14800,52,0}, /* core2 fp64 bit31 */
			{14888,52,0}, /* core2 fp64 bit32 */
			{14884,52,0}, /* core2 fp64 bit33 */
			{14886,52,0}, /* core2 fp64 bit34 */
			{ 6708,52,0}, /* core2 fp64 bit35 */
			{14892,52,0}, /* core2 fp64 bit36 */
			{14882,52,0}, /* core2 fp64 bit37 */
			{ 6700,52,0}, /* core2 fp64 bit38 */
			{14890,52,0}, /* core2 fp64 bit39 */
			{14896,52,0}, /* core2 fp64 bit40 */
			{14894,52,0}, /* core2 fp64 bit41 */
			{14900,52,0}, /* core2 fp64 bit42 */
			{14904,52,0}, /* core2 fp64 bit43 */
			{14902,52,0}, /* core2 fp64 bit44 */
			{14912,52,0}, /* core2 fp64 bit45 */
			{14898,52,0}, /* core2 fp64 bit46 */
			{14910,52,0}, /* core2 fp64 bit47 */
			{14916,52,0}, /* core2 fp64 bit48 */
			{14914,52,0}, /* core2 fp64 bit49 */
			{21972,52,0}, /* core2 fp64 bit50 */
			{21980,52,0}, /* core2 fp64 bit51 */
			{21970,52,0}, /* core2 fp64 bit52 */
			{21978,52,0}, /* core2 fp64 bit53 */
			{21968,52,0}, /* core2 fp64 bit54 */
			{21966,52,0}, /* core2 fp64 bit55 */
			{21988,52,0}, /* core2 fp64 bit56 */
			{21986,52,0}, /* core2 fp64 bit57 */
			{21976,52,0}, /* core2 fp64 bit58 */
			{21984,52,0}, /* core2 fp64 bit59 */
			{14920,52,0}, /* core2 fp64 bit60 */
			{21982,52,0}, /* core2 fp64 bit61 */
			{21974,52,0}, /* core2 fp64 bit62 */
			{14918,52,0}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 6982,52,0}, /* core2 sp_EL0 bit0 */
			{ 6974,52,0}, /* core2 sp_EL0 bit1 */
			{14710,52,0}, /* core2 sp_EL0 bit2 */
			{14720,52,0}, /* core2 sp_EL0 bit3 */
			{14718,52,0}, /* core2 sp_EL0 bit4 */
			{15108,52,0}, /* core2 sp_EL0 bit5 */
			{15106,52,0}, /* core2 sp_EL0 bit6 */
			{ 7046,52,0}, /* core2 sp_EL0 bit7 */
			{15112,52,0}, /* core2 sp_EL0 bit8 */
			{14772,52,0}, /* core2 sp_EL0 bit9 */
			{14770,52,0}, /* core2 sp_EL0 bit10 */
			{14708,52,0}, /* core2 sp_EL0 bit11 */
			{14706,52,0}, /* core2 sp_EL0 bit12 */
			{15032,52,0}, /* core2 sp_EL0 bit13 */
			{15030,52,0}, /* core2 sp_EL0 bit14 */
			{14776,52,0}, /* core2 sp_EL0 bit15 */
			{15036,52,0}, /* core2 sp_EL0 bit16 */
			{15110,52,0}, /* core2 sp_EL0 bit17 */
			{15034,52,0}, /* core2 sp_EL0 bit18 */
			{ 7050,52,0}, /* core2 sp_EL0 bit19 */
			{14716,52,0}, /* core2 sp_EL0 bit20 */
			{ 7048,52,0}, /* core2 sp_EL0 bit21 */
			{14712,52,0}, /* core2 sp_EL0 bit22 */
			{14714,52,0}, /* core2 sp_EL0 bit23 */
			{14760,52,0}, /* core2 sp_EL0 bit24 */
			{14758,52,0}, /* core2 sp_EL0 bit25 */
			{14780,52,0}, /* core2 sp_EL0 bit26 */
			{14778,52,0}, /* core2 sp_EL0 bit27 */
			{15008,52,0}, /* core2 sp_EL0 bit28 */
			{14774,52,0}, /* core2 sp_EL0 bit29 */
			{15006,52,0}, /* core2 sp_EL0 bit30 */
			{ 7018,52,0}, /* core2 sp_EL0 bit31 */
			{14820,52,0}, /* core2 sp_EL0 bit32 */
			{14818,52,0}, /* core2 sp_EL0 bit33 */
			{14844,52,0}, /* core2 sp_EL0 bit34 */
			{14812,52,0}, /* core2 sp_EL0 bit35 */
			{14810,52,0}, /* core2 sp_EL0 bit36 */
			{14816,52,0}, /* core2 sp_EL0 bit37 */
			{14814,52,0}, /* core2 sp_EL0 bit38 */
			{ 6836,52,0}, /* core2 sp_EL0 bit39 */
			{14842,52,0}, /* core2 sp_EL0 bit40 */
			{14836,52,0}, /* core2 sp_EL0 bit41 */
			{14840,52,0}, /* core2 sp_EL0 bit42 */
			{14838,52,0}, /* core2 sp_EL0 bit43 */
			{14828,52,0}, /* core2 sp_EL0 bit44 */
			{14834,52,0}, /* core2 sp_EL0 bit45 */
			{21900,52,0}, /* core2 sp_EL0 bit46 */
			{14832,52,0}, /* core2 sp_EL0 bit47 */
			{21898,52,0}, /* core2 sp_EL0 bit48 */
			{21896,52,0}, /* core2 sp_EL0 bit49 */
			{14830,52,0}, /* core2 sp_EL0 bit50 */
			{21894,52,0}, /* core2 sp_EL0 bit51 */
			{21892,52,0}, /* core2 sp_EL0 bit52 */
			{21884,52,0}, /* core2 sp_EL0 bit53 */
			{21890,52,0}, /* core2 sp_EL0 bit54 */
			{21888,52,0}, /* core2 sp_EL0 bit55 */
			{21886,52,0}, /* core2 sp_EL0 bit56 */
			{14824,52,0}, /* core2 sp_EL0 bit57 */
			{21882,52,0}, /* core2 sp_EL0 bit58 */
			{14822,52,0}, /* core2 sp_EL0 bit59 */
			{21880,52,0}, /* core2 sp_EL0 bit60 */
			{ 6838,52,0}, /* core2 sp_EL0 bit61 */
			{21878,52,0}, /* core2 sp_EL0 bit62 */
			{14826,52,0}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6988,52,0}, /* core2 sp_EL1 bit0 */
			{ 6998,52,0}, /* core2 sp_EL1 bit1 */
			{14740,52,0}, /* core2 sp_EL1 bit2 */
			{14738,52,0}, /* core2 sp_EL1 bit3 */
			{15096,52,0}, /* core2 sp_EL1 bit4 */
			{15094,52,0}, /* core2 sp_EL1 bit5 */
			{15088,52,0}, /* core2 sp_EL1 bit6 */
			{15116,52,0}, /* core2 sp_EL1 bit7 */
			{15086,52,0}, /* core2 sp_EL1 bit8 */
			{15014,52,0}, /* core2 sp_EL1 bit9 */
			{15002,52,0}, /* core2 sp_EL1 bit10 */
			{15114,52,0}, /* core2 sp_EL1 bit11 */
			{15120,52,0}, /* core2 sp_EL1 bit12 */
			{15118,52,0}, /* core2 sp_EL1 bit13 */
			{21844,52,0}, /* core2 sp_EL1 bit14 */
			{15000,52,0}, /* core2 sp_EL1 bit15 */
			{21842,52,0}, /* core2 sp_EL1 bit16 */
			{15128,52,0}, /* core2 sp_EL1 bit17 */
			{21840,52,0}, /* core2 sp_EL1 bit18 */
			{15126,52,0}, /* core2 sp_EL1 bit19 */
			{21838,52,0}, /* core2 sp_EL1 bit20 */
			{ 7064,52,0}, /* core2 sp_EL1 bit21 */
			{ 7056,52,0}, /* core2 sp_EL1 bit22 */
			{ 7062,52,0}, /* core2 sp_EL1 bit23 */
			{ 6994,52,0}, /* core2 sp_EL1 bit24 */
			{14992,52,0}, /* core2 sp_EL1 bit25 */
			{14990,52,0}, /* core2 sp_EL1 bit26 */
			{14996,52,0}, /* core2 sp_EL1 bit27 */
			{14994,52,0}, /* core2 sp_EL1 bit28 */
			{14998,52,0}, /* core2 sp_EL1 bit29 */
			{15016,52,0}, /* core2 sp_EL1 bit30 */
			{15004,52,0}, /* core2 sp_EL1 bit31 */
			{ 6864,52,0}, /* core2 sp_EL1 bit32 */
			{14876,52,0}, /* core2 sp_EL1 bit33 */
			{14940,52,0}, /* core2 sp_EL1 bit34 */
			{14874,52,0}, /* core2 sp_EL1 bit35 */
			{14880,52,0}, /* core2 sp_EL1 bit36 */
			{14878,52,0}, /* core2 sp_EL1 bit37 */
			{14948,52,0}, /* core2 sp_EL1 bit38 */
			{14946,52,0}, /* core2 sp_EL1 bit39 */
			{14938,52,0}, /* core2 sp_EL1 bit40 */
			{14944,52,0}, /* core2 sp_EL1 bit41 */
			{14942,52,0}, /* core2 sp_EL1 bit42 */
			{14936,52,0}, /* core2 sp_EL1 bit43 */
			{14934,52,0}, /* core2 sp_EL1 bit44 */
			{14932,52,0}, /* core2 sp_EL1 bit45 */
			{ 6868,52,0}, /* core2 sp_EL1 bit46 */
			{14930,52,0}, /* core2 sp_EL1 bit47 */
			{22116,52,0}, /* core2 sp_EL1 bit48 */
			{22114,52,0}, /* core2 sp_EL1 bit49 */
			{22108,52,0}, /* core2 sp_EL1 bit50 */
			{22106,52,0}, /* core2 sp_EL1 bit51 */
			{22104,52,0}, /* core2 sp_EL1 bit52 */
			{22102,52,0}, /* core2 sp_EL1 bit53 */
			{22124,52,0}, /* core2 sp_EL1 bit54 */
			{22122,52,0}, /* core2 sp_EL1 bit55 */
			{22120,52,0}, /* core2 sp_EL1 bit56 */
			{22118,52,0}, /* core2 sp_EL1 bit57 */
			{22100,52,0}, /* core2 sp_EL1 bit58 */
			{22098,52,0}, /* core2 sp_EL1 bit59 */
			{22096,52,0}, /* core2 sp_EL1 bit60 */
			{22094,52,0}, /* core2 sp_EL1 bit61 */
			{22112,52,0}, /* core2 sp_EL1 bit62 */
			{22110,52,0}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 6986,52,0}, /* core2 sp_EL2 bit0 */
			{ 7000,52,0}, /* core2 sp_EL2 bit1 */
			{14736,52,0}, /* core2 sp_EL2 bit2 */
			{14734,52,0}, /* core2 sp_EL2 bit3 */
			{15132,52,0}, /* core2 sp_EL2 bit4 */
			{15130,52,0}, /* core2 sp_EL2 bit5 */
			{15092,52,0}, /* core2 sp_EL2 bit6 */
			{14704,52,0}, /* core2 sp_EL2 bit7 */
			{15090,52,0}, /* core2 sp_EL2 bit8 */
			{15012,52,0}, /* core2 sp_EL2 bit9 */
			{15010,52,0}, /* core2 sp_EL2 bit10 */
			{14702,52,0}, /* core2 sp_EL2 bit11 */
			{15124,52,0}, /* core2 sp_EL2 bit12 */
			{15122,52,0}, /* core2 sp_EL2 bit13 */
			{21852,52,0}, /* core2 sp_EL2 bit14 */
			{ 7012,52,0}, /* core2 sp_EL2 bit15 */
			{21850,52,0}, /* core2 sp_EL2 bit16 */
			{15136,52,0}, /* core2 sp_EL2 bit17 */
			{21848,52,0}, /* core2 sp_EL2 bit18 */
			{15134,52,0}, /* core2 sp_EL2 bit19 */
			{21846,52,0}, /* core2 sp_EL2 bit20 */
			{ 7060,52,0}, /* core2 sp_EL2 bit21 */
			{ 7058,52,0}, /* core2 sp_EL2 bit22 */
			{ 7052,52,0}, /* core2 sp_EL2 bit23 */
			{14764,52,0}, /* core2 sp_EL2 bit24 */
			{14762,52,0}, /* core2 sp_EL2 bit25 */
			{14988,52,0}, /* core2 sp_EL2 bit26 */
			{14986,52,0}, /* core2 sp_EL2 bit27 */
			{ 7016,52,0}, /* core2 sp_EL2 bit28 */
			{ 7014,52,0}, /* core2 sp_EL2 bit29 */
			{ 7008,52,0}, /* core2 sp_EL2 bit30 */
			{ 7010,52,0}, /* core2 sp_EL2 bit31 */
			{ 6860,52,0}, /* core2 sp_EL2 bit32 */
			{14868,52,0}, /* core2 sp_EL2 bit33 */
			{14964,52,0}, /* core2 sp_EL2 bit34 */
			{14866,52,0}, /* core2 sp_EL2 bit35 */
			{14864,52,0}, /* core2 sp_EL2 bit36 */
			{14862,52,0}, /* core2 sp_EL2 bit37 */
			{14872,52,0}, /* core2 sp_EL2 bit38 */
			{14870,52,0}, /* core2 sp_EL2 bit39 */
			{14962,52,0}, /* core2 sp_EL2 bit40 */
			{14952,52,0}, /* core2 sp_EL2 bit41 */
			{14950,52,0}, /* core2 sp_EL2 bit42 */
			{14960,52,0}, /* core2 sp_EL2 bit43 */
			{14958,52,0}, /* core2 sp_EL2 bit44 */
			{14956,52,0}, /* core2 sp_EL2 bit45 */
			{ 6858,52,0}, /* core2 sp_EL2 bit46 */
			{14954,52,0}, /* core2 sp_EL2 bit47 */
			{22148,52,0}, /* core2 sp_EL2 bit48 */
			{22146,52,0}, /* core2 sp_EL2 bit49 */
			{22140,52,0}, /* core2 sp_EL2 bit50 */
			{22138,52,0}, /* core2 sp_EL2 bit51 */
			{22136,52,0}, /* core2 sp_EL2 bit52 */
			{22134,52,0}, /* core2 sp_EL2 bit53 */
			{22132,52,0}, /* core2 sp_EL2 bit54 */
			{22130,52,0}, /* core2 sp_EL2 bit55 */
			{22128,52,0}, /* core2 sp_EL2 bit56 */
			{22126,52,0}, /* core2 sp_EL2 bit57 */
			{22156,52,0}, /* core2 sp_EL2 bit58 */
			{22154,52,0}, /* core2 sp_EL2 bit59 */
			{22152,52,0}, /* core2 sp_EL2 bit60 */
			{22150,52,0}, /* core2 sp_EL2 bit61 */
			{22144,52,0}, /* core2 sp_EL2 bit62 */
			{22142,52,0}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6984,52,0}, /* core2 sp_EL3 bit0 */
			{ 6996,52,0}, /* core2 sp_EL3 bit1 */
			{14732,52,0}, /* core2 sp_EL3 bit2 */
			{14388,52,0}, /* core2 sp_EL3 bit3 */
			{15104,52,0}, /* core2 sp_EL3 bit4 */
			{15102,52,0}, /* core2 sp_EL3 bit5 */
			{14730,52,0}, /* core2 sp_EL3 bit6 */
			{14768,52,0}, /* core2 sp_EL3 bit7 */
			{15100,52,0}, /* core2 sp_EL3 bit8 */
			{14766,52,0}, /* core2 sp_EL3 bit9 */
			{14332,52,0}, /* core2 sp_EL3 bit10 */
			{14700,52,0}, /* core2 sp_EL3 bit11 */
			{14698,52,0}, /* core2 sp_EL3 bit12 */
			{14696,52,0}, /* core2 sp_EL3 bit13 */
			{14694,52,0}, /* core2 sp_EL3 bit14 */
			{14338,52,0}, /* core2 sp_EL3 bit15 */
			{14394,52,0}, /* core2 sp_EL3 bit16 */
			{15098,52,0}, /* core2 sp_EL3 bit17 */
			{14402,52,0}, /* core2 sp_EL3 bit18 */
			{ 7054,52,0}, /* core2 sp_EL3 bit19 */
			{14392,52,0}, /* core2 sp_EL3 bit20 */
			{14400,52,0}, /* core2 sp_EL3 bit21 */
			{14390,52,0}, /* core2 sp_EL3 bit22 */
			{14398,52,0}, /* core2 sp_EL3 bit23 */
			{14396,52,0}, /* core2 sp_EL3 bit24 */
			{14326,52,0}, /* core2 sp_EL3 bit25 */
			{14324,52,0}, /* core2 sp_EL3 bit26 */
			{14330,52,0}, /* core2 sp_EL3 bit27 */
			{14328,52,0}, /* core2 sp_EL3 bit28 */
			{14336,52,0}, /* core2 sp_EL3 bit29 */
			{ 7020,52,0}, /* core2 sp_EL3 bit30 */
			{14334,52,0}, /* core2 sp_EL3 bit31 */
			{14310,52,0}, /* core2 sp_EL3 bit32 */
			{14306,52,0}, /* core2 sp_EL3 bit33 */
			{14270,52,0}, /* core2 sp_EL3 bit34 */
			{14308,52,0}, /* core2 sp_EL3 bit35 */
			{14304,52,0}, /* core2 sp_EL3 bit36 */
			{14302,52,0}, /* core2 sp_EL3 bit37 */
			{14314,52,0}, /* core2 sp_EL3 bit38 */
			{14300,52,0}, /* core2 sp_EL3 bit39 */
			{14266,52,0}, /* core2 sp_EL3 bit40 */
			{14264,52,0}, /* core2 sp_EL3 bit41 */
			{14268,52,0}, /* core2 sp_EL3 bit42 */
			{14262,52,0}, /* core2 sp_EL3 bit43 */
			{14260,52,0}, /* core2 sp_EL3 bit44 */
			{14258,52,0}, /* core2 sp_EL3 bit45 */
			{14312,52,0}, /* core2 sp_EL3 bit46 */
			{14256,52,0}, /* core2 sp_EL3 bit47 */
			{22188,52,0}, /* core2 sp_EL3 bit48 */
			{22186,52,0}, /* core2 sp_EL3 bit49 */
			{22184,52,0}, /* core2 sp_EL3 bit50 */
			{22182,52,0}, /* core2 sp_EL3 bit51 */
			{22172,52,0}, /* core2 sp_EL3 bit52 */
			{22170,52,0}, /* core2 sp_EL3 bit53 */
			{22168,52,0}, /* core2 sp_EL3 bit54 */
			{22166,52,0}, /* core2 sp_EL3 bit55 */
			{22180,52,0}, /* core2 sp_EL3 bit56 */
			{22178,52,0}, /* core2 sp_EL3 bit57 */
			{22176,52,0}, /* core2 sp_EL3 bit58 */
			{22174,52,0}, /* core2 sp_EL3 bit59 */
			{22164,52,0}, /* core2 sp_EL3 bit60 */
			{22162,52,0}, /* core2 sp_EL3 bit61 */
			{22160,52,0}, /* core2 sp_EL3 bit62 */
			{22158,52,0}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{21836,52,0}, /* core2 elr_EL1 bit0 */
			{21552,52,0}, /* core2 elr_EL1 bit1 */
			{21606,52,0}, /* core2 elr_EL1 bit2 */
			{21604,52,0}, /* core2 elr_EL1 bit3 */
			{21602,52,0}, /* core2 elr_EL1 bit4 */
			{21600,52,0}, /* core2 elr_EL1 bit5 */
			{21598,52,0}, /* core2 elr_EL1 bit6 */
			{21596,52,0}, /* core2 elr_EL1 bit7 */
			{21594,52,0}, /* core2 elr_EL1 bit8 */
			{21834,52,0}, /* core2 elr_EL1 bit9 */
			{21592,52,0}, /* core2 elr_EL1 bit10 */
			{21614,52,0}, /* core2 elr_EL1 bit11 */
			{21612,52,0}, /* core2 elr_EL1 bit12 */
			{21610,52,0}, /* core2 elr_EL1 bit13 */
			{21832,52,0}, /* core2 elr_EL1 bit14 */
			{14362,52,0}, /* core2 elr_EL1 bit15 */
			{21830,52,0}, /* core2 elr_EL1 bit16 */
			{21608,52,0}, /* core2 elr_EL1 bit17 */
			{21582,52,0}, /* core2 elr_EL1 bit18 */
			{21580,52,0}, /* core2 elr_EL1 bit19 */
			{21558,52,0}, /* core2 elr_EL1 bit20 */
			{14414,52,0}, /* core2 elr_EL1 bit21 */
			{21578,52,0}, /* core2 elr_EL1 bit22 */
			{21556,52,0}, /* core2 elr_EL1 bit23 */
			{21576,52,0}, /* core2 elr_EL1 bit24 */
			{21542,52,0}, /* core2 elr_EL1 bit25 */
			{21554,52,0}, /* core2 elr_EL1 bit26 */
			{21540,52,0}, /* core2 elr_EL1 bit27 */
			{21538,52,0}, /* core2 elr_EL1 bit28 */
			{14360,52,0}, /* core2 elr_EL1 bit29 */
			{21536,52,0}, /* core2 elr_EL1 bit30 */
			{14412,52,0}, /* core2 elr_EL1 bit31 */
			{21478,52,0}, /* core2 elr_EL1 bit32 */
			{21486,52,0}, /* core2 elr_EL1 bit33 */
			{21484,52,0}, /* core2 elr_EL1 bit34 */
			{21476,52,0}, /* core2 elr_EL1 bit35 */
			{21474,52,0}, /* core2 elr_EL1 bit36 */
			{21472,52,0}, /* core2 elr_EL1 bit37 */
			{14322,52,0}, /* core2 elr_EL1 bit38 */
			{14320,52,0}, /* core2 elr_EL1 bit39 */
			{21482,52,0}, /* core2 elr_EL1 bit40 */
			{21480,52,0}, /* core2 elr_EL1 bit41 */
			{21494,52,0}, /* core2 elr_EL1 bit42 */
			{21492,52,0}, /* core2 elr_EL1 bit43 */
			{21490,52,0}, /* core2 elr_EL1 bit44 */
			{21488,52,0}, /* core2 elr_EL1 bit45 */
			{21502,52,0}, /* core2 elr_EL1 bit46 */
			{21500,52,0}, /* core2 elr_EL1 bit47 */
			{21498,52,0}, /* core2 elr_EL1 bit48 */
			{21496,52,0}, /* core2 elr_EL1 bit49 */
			{21510,52,0}, /* core2 elr_EL1 bit50 */
			{21508,52,0}, /* core2 elr_EL1 bit51 */
			{21506,52,0}, /* core2 elr_EL1 bit52 */
			{21504,52,0}, /* core2 elr_EL1 bit53 */
			{21518,52,0}, /* core2 elr_EL1 bit54 */
			{21516,52,0}, /* core2 elr_EL1 bit55 */
			{21514,52,0}, /* core2 elr_EL1 bit56 */
			{21512,52,0}, /* core2 elr_EL1 bit57 */
			{21526,52,0}, /* core2 elr_EL1 bit58 */
			{21524,52,0}, /* core2 elr_EL1 bit59 */
			{21522,52,0}, /* core2 elr_EL1 bit60 */
			{21520,52,0}, /* core2 elr_EL1 bit61 */
			{14318,52,0}, /* core2 elr_EL1 bit62 */
			{14316,52,0}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{21590,52,0}, /* core2 elr_EL2 bit0 */
			{21588,52,0}, /* core2 elr_EL2 bit1 */
			{21586,52,0}, /* core2 elr_EL2 bit2 */
			{21584,52,0}, /* core2 elr_EL2 bit3 */
			{21638,52,0}, /* core2 elr_EL2 bit4 */
			{21636,52,0}, /* core2 elr_EL2 bit5 */
			{21634,52,0}, /* core2 elr_EL2 bit6 */
			{21632,52,0}, /* core2 elr_EL2 bit7 */
			{21550,52,0}, /* core2 elr_EL2 bit8 */
			{21548,52,0}, /* core2 elr_EL2 bit9 */
			{21546,52,0}, /* core2 elr_EL2 bit10 */
			{21544,52,0}, /* core2 elr_EL2 bit11 */
			{21574,52,0}, /* core2 elr_EL2 bit12 */
			{21572,52,0}, /* core2 elr_EL2 bit13 */
			{21570,52,0}, /* core2 elr_EL2 bit14 */
			{14358,52,0}, /* core2 elr_EL2 bit15 */
			{21568,52,0}, /* core2 elr_EL2 bit16 */
			{21622,52,0}, /* core2 elr_EL2 bit17 */
			{21620,52,0}, /* core2 elr_EL2 bit18 */
			{21618,52,0}, /* core2 elr_EL2 bit19 */
			{21616,52,0}, /* core2 elr_EL2 bit20 */
			{14418,52,0}, /* core2 elr_EL2 bit21 */
			{21566,52,0}, /* core2 elr_EL2 bit22 */
			{21564,52,0}, /* core2 elr_EL2 bit23 */
			{21562,52,0}, /* core2 elr_EL2 bit24 */
			{21560,52,0}, /* core2 elr_EL2 bit25 */
			{21534,52,0}, /* core2 elr_EL2 bit26 */
			{21532,52,0}, /* core2 elr_EL2 bit27 */
			{21530,52,0}, /* core2 elr_EL2 bit28 */
			{14356,52,0}, /* core2 elr_EL2 bit29 */
			{21528,52,0}, /* core2 elr_EL2 bit30 */
			{14416,52,0}, /* core2 elr_EL2 bit31 */
			{21462,52,0}, /* core2 elr_EL2 bit32 */
			{21460,52,0}, /* core2 elr_EL2 bit33 */
			{21458,52,0}, /* core2 elr_EL2 bit34 */
			{21456,52,0}, /* core2 elr_EL2 bit35 */
			{21454,52,0}, /* core2 elr_EL2 bit36 */
			{21452,52,0}, /* core2 elr_EL2 bit37 */
			{21450,52,0}, /* core2 elr_EL2 bit38 */
			{21448,52,0}, /* core2 elr_EL2 bit39 */
			{21438,52,0}, /* core2 elr_EL2 bit40 */
			{21436,52,0}, /* core2 elr_EL2 bit41 */
			{21434,52,0}, /* core2 elr_EL2 bit42 */
			{21432,52,0}, /* core2 elr_EL2 bit43 */
			{21446,52,0}, /* core2 elr_EL2 bit44 */
			{21444,52,0}, /* core2 elr_EL2 bit45 */
			{21442,52,0}, /* core2 elr_EL2 bit46 */
			{21440,52,0}, /* core2 elr_EL2 bit47 */
			{21470,52,0}, /* core2 elr_EL2 bit48 */
			{21468,52,0}, /* core2 elr_EL2 bit49 */
			{21466,52,0}, /* core2 elr_EL2 bit50 */
			{21464,52,0}, /* core2 elr_EL2 bit51 */
			{21430,52,0}, /* core2 elr_EL2 bit52 */
			{21428,52,0}, /* core2 elr_EL2 bit53 */
			{21426,52,0}, /* core2 elr_EL2 bit54 */
			{21424,52,0}, /* core2 elr_EL2 bit55 */
			{21422,52,0}, /* core2 elr_EL2 bit56 */
			{21420,52,0}, /* core2 elr_EL2 bit57 */
			{21418,52,0}, /* core2 elr_EL2 bit58 */
			{21416,52,0}, /* core2 elr_EL2 bit59 */
			{21414,52,0}, /* core2 elr_EL2 bit60 */
			{21412,52,0}, /* core2 elr_EL2 bit61 */
			{21410,52,0}, /* core2 elr_EL2 bit62 */
			{21408,52,0}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 6990,52,0}, /* core2 elr_EL3 bit0 */
			{ 7002,52,0}, /* core2 elr_EL3 bit1 */
			{14404,52,0}, /* core2 elr_EL3 bit2 */
			{14382,52,0}, /* core2 elr_EL3 bit3 */
			{14386,52,0}, /* core2 elr_EL3 bit4 */
			{14380,52,0}, /* core2 elr_EL3 bit5 */
			{14378,52,0}, /* core2 elr_EL3 bit6 */
			{14376,52,0}, /* core2 elr_EL3 bit7 */
			{14370,52,0}, /* core2 elr_EL3 bit8 */
			{14366,52,0}, /* core2 elr_EL3 bit9 */
			{14344,52,0}, /* core2 elr_EL3 bit10 */
			{14384,52,0}, /* core2 elr_EL3 bit11 */
			{14374,52,0}, /* core2 elr_EL3 bit12 */
			{14372,52,0}, /* core2 elr_EL3 bit13 */
			{14410,52,0}, /* core2 elr_EL3 bit14 */
			{14352,52,0}, /* core2 elr_EL3 bit15 */
			{21630,52,0}, /* core2 elr_EL3 bit16 */
			{21628,52,0}, /* core2 elr_EL3 bit17 */
			{14408,52,0}, /* core2 elr_EL3 bit18 */
			{14406,52,0}, /* core2 elr_EL3 bit19 */
			{21626,52,0}, /* core2 elr_EL3 bit20 */
			{ 6992,52,0}, /* core2 elr_EL3 bit21 */
			{21624,52,0}, /* core2 elr_EL3 bit22 */
			{14368,52,0}, /* core2 elr_EL3 bit23 */
			{14364,52,0}, /* core2 elr_EL3 bit24 */
			{14342,52,0}, /* core2 elr_EL3 bit25 */
			{14350,52,0}, /* core2 elr_EL3 bit26 */
			{14348,52,0}, /* core2 elr_EL3 bit27 */
			{14340,52,0}, /* core2 elr_EL3 bit28 */
			{14354,52,0}, /* core2 elr_EL3 bit29 */
			{ 7004,52,0}, /* core2 elr_EL3 bit30 */
			{14346,52,0}, /* core2 elr_EL3 bit31 */
			{14298,52,0}, /* core2 elr_EL3 bit32 */
			{14296,52,0}, /* core2 elr_EL3 bit33 */
			{14290,52,0}, /* core2 elr_EL3 bit34 */
			{14294,52,0}, /* core2 elr_EL3 bit35 */
			{14288,52,0}, /* core2 elr_EL3 bit36 */
			{14292,52,0}, /* core2 elr_EL3 bit37 */
			{ 6854,52,0}, /* core2 elr_EL3 bit38 */
			{14282,52,0}, /* core2 elr_EL3 bit39 */
			{14286,52,0}, /* core2 elr_EL3 bit40 */
			{14254,52,0}, /* core2 elr_EL3 bit41 */
			{14284,52,0}, /* core2 elr_EL3 bit42 */
			{14252,52,0}, /* core2 elr_EL3 bit43 */
			{14278,52,0}, /* core2 elr_EL3 bit44 */
			{14274,52,0}, /* core2 elr_EL3 bit45 */
			{ 6856,52,0}, /* core2 elr_EL3 bit46 */
			{14272,52,0}, /* core2 elr_EL3 bit47 */
			{14276,52,0}, /* core2 elr_EL3 bit48 */
			{21406,52,0}, /* core2 elr_EL3 bit49 */
			{14250,52,0}, /* core2 elr_EL3 bit50 */
			{21398,52,0}, /* core2 elr_EL3 bit51 */
			{21396,52,0}, /* core2 elr_EL3 bit52 */
			{21394,52,0}, /* core2 elr_EL3 bit53 */
			{21392,52,0}, /* core2 elr_EL3 bit54 */
			{21390,52,0}, /* core2 elr_EL3 bit55 */
			{21388,52,0}, /* core2 elr_EL3 bit56 */
			{21386,52,0}, /* core2 elr_EL3 bit57 */
			{21404,52,0}, /* core2 elr_EL3 bit58 */
			{21384,52,0}, /* core2 elr_EL3 bit59 */
			{14280,52,0}, /* core2 elr_EL3 bit60 */
			{14248,52,0}, /* core2 elr_EL3 bit61 */
			{21402,52,0}, /* core2 elr_EL3 bit62 */
			{21400,52,0}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{20350,52,0}, /* core2 raw_pc bit0 */
			{19196,51,0}, /* core2 raw_pc bit1 */
			{19194,51,0}, /* core2 raw_pc bit2 */
			{19192,51,0}, /* core2 raw_pc bit3 */
			{19190,51,0}, /* core2 raw_pc bit4 */
			{20348,52,0}, /* core2 raw_pc bit5 */
			{20346,52,0}, /* core2 raw_pc bit6 */
			{19180,51,0}, /* core2 raw_pc bit7 */
			{19178,51,0}, /* core2 raw_pc bit8 */
			{19176,51,0}, /* core2 raw_pc bit9 */
			{19174,51,0}, /* core2 raw_pc bit10 */
			{19154,51,0}, /* core2 raw_pc bit11 */
			{19152,51,0}, /* core2 raw_pc bit12 */
			{19150,51,0}, /* core2 raw_pc bit13 */
			{19148,51,0}, /* core2 raw_pc bit14 */
			{19168,51,0}, /* core2 raw_pc bit15 */
			{19166,51,0}, /* core2 raw_pc bit16 */
			{19164,51,0}, /* core2 raw_pc bit17 */
			{19162,51,0}, /* core2 raw_pc bit18 */
			{19170,51,0}, /* core2 raw_pc bit19 */
			{19160,51,0}, /* core2 raw_pc bit20 */
			{19158,51,0}, /* core2 raw_pc bit21 */
			{19156,51,0}, /* core2 raw_pc bit22 */
			{19138,51,0}, /* core2 raw_pc bit23 */
			{19136,51,0}, /* core2 raw_pc bit24 */
			{19134,51,0}, /* core2 raw_pc bit25 */
			{19132,51,0}, /* core2 raw_pc bit26 */
			{19146,51,0}, /* core2 raw_pc bit27 */
			{19144,51,0}, /* core2 raw_pc bit28 */
			{19142,51,0}, /* core2 raw_pc bit29 */
			{19140,51,0}, /* core2 raw_pc bit30 */
			{18854,51,0}, /* core2 raw_pc bit31 */
			{18852,51,0}, /* core2 raw_pc bit32 */
			{18850,51,0}, /* core2 raw_pc bit33 */
			{18848,51,0}, /* core2 raw_pc bit34 */
			{18862,51,0}, /* core2 raw_pc bit35 */
			{18860,51,0}, /* core2 raw_pc bit36 */
			{18858,51,0}, /* core2 raw_pc bit37 */
			{18856,51,0}, /* core2 raw_pc bit38 */
			{18846,51,0}, /* core2 raw_pc bit39 */
			{18844,51,0}, /* core2 raw_pc bit40 */
			{18842,51,0}, /* core2 raw_pc bit41 */
			{18840,51,0}, /* core2 raw_pc bit42 */
			{18838,51,0}, /* core2 raw_pc bit43 */
			{18836,51,0}, /* core2 raw_pc bit44 */
			{18834,51,0}, /* core2 raw_pc bit45 */
			{18832,51,0}, /* core2 raw_pc bit46 */
			{11668,52,0}, /* core2 raw_pc bit47 */
			{20380,52,0}, /* core2 raw_pc bit48 */
			{20378,52,0}, /* core2 raw_pc bit49 */
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
			{12108,52,0}, /* core2 pc_iss bit0 */
			{12106,52,0}, /* core2 pc_iss bit1 */
			{12102,52,0}, /* core2 pc_iss bit2 */
			{20292,52,0}, /* core2 pc_iss bit3 */
			{20290,52,0}, /* core2 pc_iss bit4 */
			{20288,52,0}, /* core2 pc_iss bit5 */
			{20286,52,0}, /* core2 pc_iss bit6 */
			{12104,52,0}, /* core2 pc_iss bit7 */
			{20296,52,0}, /* core2 pc_iss bit8 */
			{20294,52,0}, /* core2 pc_iss bit9 */
			{20474,52,0}, /* core2 pc_iss bit10 */
			{20284,52,0}, /* core2 pc_iss bit11 */
			{20304,52,0}, /* core2 pc_iss bit12 */
			{20282,52,0}, /* core2 pc_iss bit13 */
			{20300,52,0}, /* core2 pc_iss bit14 */
			{20298,52,0}, /* core2 pc_iss bit15 */
			{20302,52,0}, /* core2 pc_iss bit16 */
			{20308,52,0}, /* core2 pc_iss bit17 */
			{20306,52,0}, /* core2 pc_iss bit18 */
			{20312,52,0}, /* core2 pc_iss bit19 */
			{20310,52,0}, /* core2 pc_iss bit20 */
			{20316,52,0}, /* core2 pc_iss bit21 */
			{20314,52,0}, /* core2 pc_iss bit22 */
			{20480,52,0}, /* core2 pc_iss bit23 */
			{20476,52,0}, /* core2 pc_iss bit24 */
			{20478,52,0}, /* core2 pc_iss bit25 */
			{20484,52,0}, /* core2 pc_iss bit26 */
			{20482,52,0}, /* core2 pc_iss bit27 */
			{20472,52,0}, /* core2 pc_iss bit28 */
			{20470,52,0}, /* core2 pc_iss bit29 */
			{20488,52,0}, /* core2 pc_iss bit30 */
			{20486,52,0}, /* core2 pc_iss bit31 */
			{19454,51,0}, /* core2 pc_iss bit32 */
			{20456,52,0}, /* core2 pc_iss bit33 */
			{20454,52,0}, /* core2 pc_iss bit34 */
			{20448,52,0}, /* core2 pc_iss bit35 */
			{20452,52,0}, /* core2 pc_iss bit36 */
			{20446,52,0}, /* core2 pc_iss bit37 */
			{20444,52,0}, /* core2 pc_iss bit38 */
			{20450,52,0}, /* core2 pc_iss bit39 */
			{20460,52,0}, /* core2 pc_iss bit40 */
			{20458,52,0}, /* core2 pc_iss bit41 */
			{20442,52,0}, /* core2 pc_iss bit42 */
			{20464,52,0}, /* core2 pc_iss bit43 */
			{20462,52,0}, /* core2 pc_iss bit44 */
			{19188,51,0}, /* core2 pc_iss bit45 */
			{19186,51,0}, /* core2 pc_iss bit46 */
			{19184,51,0}, /* core2 pc_iss bit47 */
			{19182,51,0}, /* core2 pc_iss bit48 */
			{19484,51,0}, /* core2 pc_iss bit49 */
			{19482,51,0}, /* core2 pc_iss bit50 */
			{19480,51,0}, /* core2 pc_iss bit51 */
			{19478,51,0}, /* core2 pc_iss bit52 */
			{19476,51,0}, /* core2 pc_iss bit53 */
			{19474,51,0}, /* core2 pc_iss bit54 */
			{19472,51,0}, /* core2 pc_iss bit55 */
			{19470,51,0}, /* core2 pc_iss bit56 */
			{19468,51,0}, /* core2 pc_iss bit57 */
			{19466,51,0}, /* core2 pc_iss bit58 */
			{19464,51,0}, /* core2 pc_iss bit59 */
			{19462,51,0}, /* core2 pc_iss bit60 */
			{19460,51,0}, /* core2 pc_iss bit61 */
			{19458,51,0}, /* core2 pc_iss bit62 */
			{19456,51,0}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{20352,52,0}, /* core2 full_pc_wr bit0 */
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
			{19404,51,0}, /* core2 full_pc_ex1 bit0 */
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
			{20280,52,0}, /* core2 full_pc_ex2 bit0 */
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
			{ 3944,53,0}, /* core2 return_Stack_pointer bit0 */
			{ 3948,53,0}, /* core2 return_Stack_pointer bit1 */
			{ 3942,53,0}, /* core2 return_Stack_pointer bit2 */
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
			{19558,53,0}, /* core2 return_Stack0 bit0 */
			{19550,53,0}, /* core2 return_Stack0 bit1 */
			{19548,53,0}, /* core2 return_Stack0 bit2 */
			{19546,53,0}, /* core2 return_Stack0 bit3 */
			{19544,53,0}, /* core2 return_Stack0 bit4 */
			{ 9376,53,0}, /* core2 return_Stack0 bit5 */
			{19502,53,0}, /* core2 return_Stack0 bit6 */
			{19500,53,0}, /* core2 return_Stack0 bit7 */
			{19498,53,0}, /* core2 return_Stack0 bit8 */
			{19496,53,0}, /* core2 return_Stack0 bit9 */
			{19478,53,0}, /* core2 return_Stack0 bit10 */
			{ 9374,53,0}, /* core2 return_Stack0 bit11 */
			{19476,53,0}, /* core2 return_Stack0 bit12 */
			{19474,53,0}, /* core2 return_Stack0 bit13 */
			{19472,53,0}, /* core2 return_Stack0 bit14 */
			{19470,53,0}, /* core2 return_Stack0 bit15 */
			{19468,53,0}, /* core2 return_Stack0 bit16 */
			{19466,53,0}, /* core2 return_Stack0 bit17 */
			{19464,53,0}, /* core2 return_Stack0 bit18 */
			{19486,53,0}, /* core2 return_Stack0 bit19 */
			{19484,53,0}, /* core2 return_Stack0 bit20 */
			{19482,53,0}, /* core2 return_Stack0 bit21 */
			{19480,53,0}, /* core2 return_Stack0 bit22 */
			{ 9384,53,0}, /* core2 return_Stack0 bit23 */
			{ 9382,53,0}, /* core2 return_Stack0 bit24 */
			{19556,53,0}, /* core2 return_Stack0 bit25 */
			{ 3830,53,0}, /* core2 return_Stack0 bit26 */
			{19554,53,0}, /* core2 return_Stack0 bit27 */
			{19552,53,0}, /* core2 return_Stack0 bit28 */
			{19542,53,0}, /* core2 return_Stack0 bit29 */
			{19540,53,0}, /* core2 return_Stack0 bit30 */
			{19538,53,0}, /* core2 return_Stack0 bit31 */
			{19536,53,0}, /* core2 return_Stack0 bit32 */
			{19534,53,0}, /* core2 return_Stack0 bit33 */
			{19532,53,0}, /* core2 return_Stack0 bit34 */
			{19530,53,0}, /* core2 return_Stack0 bit35 */
			{19528,53,0}, /* core2 return_Stack0 bit36 */
			{19526,53,0}, /* core2 return_Stack0 bit37 */
			{19524,53,0}, /* core2 return_Stack0 bit38 */
			{19522,53,0}, /* core2 return_Stack0 bit39 */
			{19520,53,0}, /* core2 return_Stack0 bit40 */
			{19518,53,0}, /* core2 return_Stack0 bit41 */
			{19516,53,0}, /* core2 return_Stack0 bit42 */
			{19514,53,0}, /* core2 return_Stack0 bit43 */
			{19512,53,0}, /* core2 return_Stack0 bit44 */
			{19510,53,0}, /* core2 return_Stack0 bit45 */
			{19508,53,0}, /* core2 return_Stack0 bit46 */
			{19506,53,0}, /* core2 return_Stack0 bit47 */
			{19504,53,0}, /* core2 return_Stack0 bit48 */
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
			{19566,53,0}, /* core2 return_Stack1 bit0 */
			{19574,53,0}, /* core2 return_Stack1 bit1 */
			{19572,53,0}, /* core2 return_Stack1 bit2 */
			{19570,53,0}, /* core2 return_Stack1 bit3 */
			{19568,53,0}, /* core2 return_Stack1 bit4 */
			{ 9380,53,0}, /* core2 return_Stack1 bit5 */
			{19494,53,0}, /* core2 return_Stack1 bit6 */
			{19492,53,0}, /* core2 return_Stack1 bit7 */
			{19490,53,0}, /* core2 return_Stack1 bit8 */
			{19488,53,0}, /* core2 return_Stack1 bit9 */
			{19462,53,0}, /* core2 return_Stack1 bit10 */
			{ 9378,53,0}, /* core2 return_Stack1 bit11 */
			{19460,53,0}, /* core2 return_Stack1 bit12 */
			{19458,53,0}, /* core2 return_Stack1 bit13 */
			{19456,53,0}, /* core2 return_Stack1 bit14 */
			{19204,53,0}, /* core2 return_Stack1 bit15 */
			{19202,53,0}, /* core2 return_Stack1 bit16 */
			{19200,53,0}, /* core2 return_Stack1 bit17 */
			{19198,53,0}, /* core2 return_Stack1 bit18 */
			{19188,53,0}, /* core2 return_Stack1 bit19 */
			{19186,53,0}, /* core2 return_Stack1 bit20 */
			{19184,53,0}, /* core2 return_Stack1 bit21 */
			{19182,53,0}, /* core2 return_Stack1 bit22 */
			{ 9388,53,0}, /* core2 return_Stack1 bit23 */
			{ 9386,53,0}, /* core2 return_Stack1 bit24 */
			{19564,53,0}, /* core2 return_Stack1 bit25 */
			{ 3828,53,0}, /* core2 return_Stack1 bit26 */
			{19562,53,0}, /* core2 return_Stack1 bit27 */
			{19560,53,0}, /* core2 return_Stack1 bit28 */
			{19164,53,0}, /* core2 return_Stack1 bit29 */
			{19162,53,0}, /* core2 return_Stack1 bit30 */
			{19160,53,0}, /* core2 return_Stack1 bit31 */
			{19158,53,0}, /* core2 return_Stack1 bit32 */
			{19124,53,0}, /* core2 return_Stack1 bit33 */
			{19122,53,0}, /* core2 return_Stack1 bit34 */
			{19120,53,0}, /* core2 return_Stack1 bit35 */
			{19118,53,0}, /* core2 return_Stack1 bit36 */
			{19116,53,0}, /* core2 return_Stack1 bit37 */
			{19114,53,0}, /* core2 return_Stack1 bit38 */
			{19112,53,0}, /* core2 return_Stack1 bit39 */
			{19110,53,0}, /* core2 return_Stack1 bit40 */
			{19076,53,0}, /* core2 return_Stack1 bit41 */
			{19074,53,0}, /* core2 return_Stack1 bit42 */
			{19072,53,0}, /* core2 return_Stack1 bit43 */
			{19070,53,0}, /* core2 return_Stack1 bit44 */
			{19068,53,0}, /* core2 return_Stack1 bit45 */
			{19066,53,0}, /* core2 return_Stack1 bit46 */
			{19064,53,0}, /* core2 return_Stack1 bit47 */
			{19062,53,0}, /* core2 return_Stack1 bit48 */
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
			{19372,53,0}, /* core2 return_Stack2 bit0 */
			{19370,53,0}, /* core2 return_Stack2 bit1 */
			{19368,53,0}, /* core2 return_Stack2 bit2 */
			{19366,53,0}, /* core2 return_Stack2 bit3 */
			{19060,53,0}, /* core2 return_Stack2 bit4 */
			{19058,53,0}, /* core2 return_Stack2 bit5 */
			{19056,53,0}, /* core2 return_Stack2 bit6 */
			{19054,53,0}, /* core2 return_Stack2 bit7 */
			{19196,53,0}, /* core2 return_Stack2 bit8 */
			{19194,53,0}, /* core2 return_Stack2 bit9 */
			{19192,53,0}, /* core2 return_Stack2 bit10 */
			{19190,53,0}, /* core2 return_Stack2 bit11 */
			{19260,53,0}, /* core2 return_Stack2 bit12 */
			{19258,53,0}, /* core2 return_Stack2 bit13 */
			{19256,53,0}, /* core2 return_Stack2 bit14 */
			{19254,53,0}, /* core2 return_Stack2 bit15 */
			{19244,53,0}, /* core2 return_Stack2 bit16 */
			{19242,53,0}, /* core2 return_Stack2 bit17 */
			{19240,53,0}, /* core2 return_Stack2 bit18 */
			{19238,53,0}, /* core2 return_Stack2 bit19 */
			{19308,53,0}, /* core2 return_Stack2 bit20 */
			{19306,53,0}, /* core2 return_Stack2 bit21 */
			{19304,53,0}, /* core2 return_Stack2 bit22 */
			{19302,53,0}, /* core2 return_Stack2 bit23 */
			{19340,53,0}, /* core2 return_Stack2 bit24 */
			{19338,53,0}, /* core2 return_Stack2 bit25 */
			{19336,53,0}, /* core2 return_Stack2 bit26 */
			{19334,53,0}, /* core2 return_Stack2 bit27 */
			{19404,53,0}, /* core2 return_Stack2 bit28 */
			{19402,53,0}, /* core2 return_Stack2 bit29 */
			{19400,53,0}, /* core2 return_Stack2 bit30 */
			{19398,53,0}, /* core2 return_Stack2 bit31 */
			{19140,53,0}, /* core2 return_Stack2 bit32 */
			{19138,53,0}, /* core2 return_Stack2 bit33 */
			{19136,53,0}, /* core2 return_Stack2 bit34 */
			{19134,53,0}, /* core2 return_Stack2 bit35 */
			{19420,53,0}, /* core2 return_Stack2 bit36 */
			{19418,53,0}, /* core2 return_Stack2 bit37 */
			{19416,53,0}, /* core2 return_Stack2 bit38 */
			{19414,53,0}, /* core2 return_Stack2 bit39 */
			{19100,53,0}, /* core2 return_Stack2 bit40 */
			{19098,53,0}, /* core2 return_Stack2 bit41 */
			{19096,53,0}, /* core2 return_Stack2 bit42 */
			{19094,53,0}, /* core2 return_Stack2 bit43 */
			{19044,53,0}, /* core2 return_Stack2 bit44 */
			{19042,53,0}, /* core2 return_Stack2 bit45 */
			{19040,53,0}, /* core2 return_Stack2 bit46 */
			{19038,53,0}, /* core2 return_Stack2 bit47 */
			{ 3838,53,0}, /* core2 return_Stack2 bit48 */
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
			{19380,53,0}, /* core2 return_Stack3 bit0 */
			{19378,53,0}, /* core2 return_Stack3 bit1 */
			{19376,53,0}, /* core2 return_Stack3 bit2 */
			{19374,53,0}, /* core2 return_Stack3 bit3 */
			{19180,53,0}, /* core2 return_Stack3 bit4 */
			{19178,53,0}, /* core2 return_Stack3 bit5 */
			{ 3836,53,0}, /* core2 return_Stack3 bit6 */
			{19176,53,0}, /* core2 return_Stack3 bit7 */
			{19174,53,0}, /* core2 return_Stack3 bit8 */
			{19276,53,0}, /* core2 return_Stack3 bit9 */
			{19274,53,0}, /* core2 return_Stack3 bit10 */
			{19272,53,0}, /* core2 return_Stack3 bit11 */
			{19270,53,0}, /* core2 return_Stack3 bit12 */
			{19252,53,0}, /* core2 return_Stack3 bit13 */
			{19250,53,0}, /* core2 return_Stack3 bit14 */
			{19248,53,0}, /* core2 return_Stack3 bit15 */
			{19246,53,0}, /* core2 return_Stack3 bit16 */
			{19268,53,0}, /* core2 return_Stack3 bit17 */
			{19266,53,0}, /* core2 return_Stack3 bit18 */
			{19264,53,0}, /* core2 return_Stack3 bit19 */
			{19262,53,0}, /* core2 return_Stack3 bit20 */
			{19324,53,0}, /* core2 return_Stack3 bit21 */
			{19322,53,0}, /* core2 return_Stack3 bit22 */
			{19320,53,0}, /* core2 return_Stack3 bit23 */
			{19318,53,0}, /* core2 return_Stack3 bit24 */
			{19356,53,0}, /* core2 return_Stack3 bit25 */
			{19354,53,0}, /* core2 return_Stack3 bit26 */
			{19352,53,0}, /* core2 return_Stack3 bit27 */
			{19350,53,0}, /* core2 return_Stack3 bit28 */
			{19412,53,0}, /* core2 return_Stack3 bit29 */
			{19410,53,0}, /* core2 return_Stack3 bit30 */
			{19408,53,0}, /* core2 return_Stack3 bit31 */
			{19406,53,0}, /* core2 return_Stack3 bit32 */
			{19436,53,0}, /* core2 return_Stack3 bit33 */
			{19434,53,0}, /* core2 return_Stack3 bit34 */
			{19432,53,0}, /* core2 return_Stack3 bit35 */
			{19430,53,0}, /* core2 return_Stack3 bit36 */
			{19428,53,0}, /* core2 return_Stack3 bit37 */
			{19426,53,0}, /* core2 return_Stack3 bit38 */
			{19424,53,0}, /* core2 return_Stack3 bit39 */
			{19422,53,0}, /* core2 return_Stack3 bit40 */
			{19084,53,0}, /* core2 return_Stack3 bit41 */
			{19082,53,0}, /* core2 return_Stack3 bit42 */
			{19080,53,0}, /* core2 return_Stack3 bit43 */
			{19078,53,0}, /* core2 return_Stack3 bit44 */
			{19036,53,0}, /* core2 return_Stack3 bit45 */
			{19034,53,0}, /* core2 return_Stack3 bit46 */
			{19032,53,0}, /* core2 return_Stack3 bit47 */
			{19030,53,0}, /* core2 return_Stack3 bit48 */
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
			{19388,53,0}, /* core2 return_Stack4 bit0 */
			{19386,53,0}, /* core2 return_Stack4 bit1 */
			{19384,53,0}, /* core2 return_Stack4 bit2 */
			{19382,53,0}, /* core2 return_Stack4 bit3 */
			{19052,53,0}, /* core2 return_Stack4 bit4 */
			{19050,53,0}, /* core2 return_Stack4 bit5 */
			{19048,53,0}, /* core2 return_Stack4 bit6 */
			{19046,53,0}, /* core2 return_Stack4 bit7 */
			{19292,53,0}, /* core2 return_Stack4 bit8 */
			{19290,53,0}, /* core2 return_Stack4 bit9 */
			{19288,53,0}, /* core2 return_Stack4 bit10 */
			{19286,53,0}, /* core2 return_Stack4 bit11 */
			{19236,53,0}, /* core2 return_Stack4 bit12 */
			{19234,53,0}, /* core2 return_Stack4 bit13 */
			{19232,53,0}, /* core2 return_Stack4 bit14 */
			{19230,53,0}, /* core2 return_Stack4 bit15 */
			{19228,53,0}, /* core2 return_Stack4 bit16 */
			{19226,53,0}, /* core2 return_Stack4 bit17 */
			{19224,53,0}, /* core2 return_Stack4 bit18 */
			{19222,53,0}, /* core2 return_Stack4 bit19 */
			{19316,53,0}, /* core2 return_Stack4 bit20 */
			{19314,53,0}, /* core2 return_Stack4 bit21 */
			{19312,53,0}, /* core2 return_Stack4 bit22 */
			{19310,53,0}, /* core2 return_Stack4 bit23 */
			{19332,53,0}, /* core2 return_Stack4 bit24 */
			{19330,53,0}, /* core2 return_Stack4 bit25 */
			{19328,53,0}, /* core2 return_Stack4 bit26 */
			{19326,53,0}, /* core2 return_Stack4 bit27 */
			{19396,53,0}, /* core2 return_Stack4 bit28 */
			{19394,53,0}, /* core2 return_Stack4 bit29 */
			{19392,53,0}, /* core2 return_Stack4 bit30 */
			{19390,53,0}, /* core2 return_Stack4 bit31 */
			{19452,53,0}, /* core2 return_Stack4 bit32 */
			{19450,53,0}, /* core2 return_Stack4 bit33 */
			{19448,53,0}, /* core2 return_Stack4 bit34 */
			{19446,53,0}, /* core2 return_Stack4 bit35 */
			{19444,53,0}, /* core2 return_Stack4 bit36 */
			{19442,53,0}, /* core2 return_Stack4 bit37 */
			{19440,53,0}, /* core2 return_Stack4 bit38 */
			{19438,53,0}, /* core2 return_Stack4 bit39 */
			{19108,53,0}, /* core2 return_Stack4 bit40 */
			{19106,53,0}, /* core2 return_Stack4 bit41 */
			{19104,53,0}, /* core2 return_Stack4 bit42 */
			{19102,53,0}, /* core2 return_Stack4 bit43 */
			{19028,53,0}, /* core2 return_Stack4 bit44 */
			{19026,53,0}, /* core2 return_Stack4 bit45 */
			{19024,53,0}, /* core2 return_Stack4 bit46 */
			{19022,53,0}, /* core2 return_Stack4 bit47 */
			{ 3832,53,0}, /* core2 return_Stack4 bit48 */
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
			{19364,53,0}, /* core2 return_Stack5 bit0 */
			{19362,53,0}, /* core2 return_Stack5 bit1 */
			{19360,53,0}, /* core2 return_Stack5 bit2 */
			{19358,53,0}, /* core2 return_Stack5 bit3 */
			{19172,53,0}, /* core2 return_Stack5 bit4 */
			{19170,53,0}, /* core2 return_Stack5 bit5 */
			{19168,53,0}, /* core2 return_Stack5 bit6 */
			{19166,53,0}, /* core2 return_Stack5 bit7 */
			{19284,53,0}, /* core2 return_Stack5 bit8 */
			{19282,53,0}, /* core2 return_Stack5 bit9 */
			{19280,53,0}, /* core2 return_Stack5 bit10 */
			{19278,53,0}, /* core2 return_Stack5 bit11 */
			{19212,53,0}, /* core2 return_Stack5 bit12 */
			{19210,53,0}, /* core2 return_Stack5 bit13 */
			{19208,53,0}, /* core2 return_Stack5 bit14 */
			{19206,53,0}, /* core2 return_Stack5 bit15 */
			{19220,53,0}, /* core2 return_Stack5 bit16 */
			{19218,53,0}, /* core2 return_Stack5 bit17 */
			{19216,53,0}, /* core2 return_Stack5 bit18 */
			{19214,53,0}, /* core2 return_Stack5 bit19 */
			{19300,53,0}, /* core2 return_Stack5 bit20 */
			{19298,53,0}, /* core2 return_Stack5 bit21 */
			{19296,53,0}, /* core2 return_Stack5 bit22 */
			{19294,53,0}, /* core2 return_Stack5 bit23 */
			{19348,53,0}, /* core2 return_Stack5 bit24 */
			{19346,53,0}, /* core2 return_Stack5 bit25 */
			{19344,53,0}, /* core2 return_Stack5 bit26 */
			{19342,53,0}, /* core2 return_Stack5 bit27 */
			{19156,53,0}, /* core2 return_Stack5 bit28 */
			{19154,53,0}, /* core2 return_Stack5 bit29 */
			{19152,53,0}, /* core2 return_Stack5 bit30 */
			{19150,53,0}, /* core2 return_Stack5 bit31 */
			{19132,53,0}, /* core2 return_Stack5 bit32 */
			{19130,53,0}, /* core2 return_Stack5 bit33 */
			{19128,53,0}, /* core2 return_Stack5 bit34 */
			{19126,53,0}, /* core2 return_Stack5 bit35 */
			{19148,53,0}, /* core2 return_Stack5 bit36 */
			{19146,53,0}, /* core2 return_Stack5 bit37 */
			{19144,53,0}, /* core2 return_Stack5 bit38 */
			{19142,53,0}, /* core2 return_Stack5 bit39 */
			{19092,53,0}, /* core2 return_Stack5 bit40 */
			{19090,53,0}, /* core2 return_Stack5 bit41 */
			{19088,53,0}, /* core2 return_Stack5 bit42 */
			{19086,53,0}, /* core2 return_Stack5 bit43 */
			{19020,53,0}, /* core2 return_Stack5 bit44 */
			{19018,53,0}, /* core2 return_Stack5 bit45 */
			{19016,53,0}, /* core2 return_Stack5 bit46 */
			{19014,53,0}, /* core2 return_Stack5 bit47 */
			{ 3834,53,0}, /* core2 return_Stack5 bit48 */
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
			{18762,53,0}, /* core2 return_Stack6 bit0 */
			{18760,53,0}, /* core2 return_Stack6 bit1 */
			{18758,53,0}, /* core2 return_Stack6 bit2 */
			{18756,53,0}, /* core2 return_Stack6 bit3 */
			{18738,53,0}, /* core2 return_Stack6 bit4 */
			{18858,53,0}, /* core2 return_Stack6 bit5 */
			{18736,53,0}, /* core2 return_Stack6 bit6 */
			{18856,53,0}, /* core2 return_Stack6 bit7 */
			{18734,53,0}, /* core2 return_Stack6 bit8 */
			{18732,53,0}, /* core2 return_Stack6 bit9 */
			{ 3824,53,0}, /* core2 return_Stack6 bit10 */
			{18854,53,0}, /* core2 return_Stack6 bit11 */
			{18852,53,0}, /* core2 return_Stack6 bit12 */
			{18818,53,0}, /* core2 return_Stack6 bit13 */
			{18816,53,0}, /* core2 return_Stack6 bit14 */
			{18814,53,0}, /* core2 return_Stack6 bit15 */
			{18812,53,0}, /* core2 return_Stack6 bit16 */
			{18826,53,0}, /* core2 return_Stack6 bit17 */
			{18824,53,0}, /* core2 return_Stack6 bit18 */
			{18822,53,0}, /* core2 return_Stack6 bit19 */
			{18820,53,0}, /* core2 return_Stack6 bit20 */
			{18794,53,0}, /* core2 return_Stack6 bit21 */
			{18792,53,0}, /* core2 return_Stack6 bit22 */
			{18790,53,0}, /* core2 return_Stack6 bit23 */
			{18788,53,0}, /* core2 return_Stack6 bit24 */
			{18786,53,0}, /* core2 return_Stack6 bit25 */
			{18784,53,0}, /* core2 return_Stack6 bit26 */
			{18782,53,0}, /* core2 return_Stack6 bit27 */
			{18780,53,0}, /* core2 return_Stack6 bit28 */
			{18746,53,0}, /* core2 return_Stack6 bit29 */
			{18744,53,0}, /* core2 return_Stack6 bit30 */
			{18742,53,0}, /* core2 return_Stack6 bit31 */
			{18740,53,0}, /* core2 return_Stack6 bit32 */
			{18986,53,0}, /* core2 return_Stack6 bit33 */
			{18984,53,0}, /* core2 return_Stack6 bit34 */
			{18982,53,0}, /* core2 return_Stack6 bit35 */
			{18980,53,0}, /* core2 return_Stack6 bit36 */
			{18978,53,0}, /* core2 return_Stack6 bit37 */
			{18976,53,0}, /* core2 return_Stack6 bit38 */
			{18974,53,0}, /* core2 return_Stack6 bit39 */
			{18972,53,0}, /* core2 return_Stack6 bit40 */
			{18946,53,0}, /* core2 return_Stack6 bit41 */
			{18944,53,0}, /* core2 return_Stack6 bit42 */
			{18942,53,0}, /* core2 return_Stack6 bit43 */
			{18940,53,0}, /* core2 return_Stack6 bit44 */
			{18730,53,0}, /* core2 return_Stack6 bit45 */
			{18728,53,0}, /* core2 return_Stack6 bit46 */
			{18726,53,0}, /* core2 return_Stack6 bit47 */
			{18724,53,0}, /* core2 return_Stack6 bit48 */
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
			{18770,53,0}, /* core2 return_Stack7 bit0 */
			{18768,53,0}, /* core2 return_Stack7 bit1 */
			{18766,53,0}, /* core2 return_Stack7 bit2 */
			{18764,53,0}, /* core2 return_Stack7 bit3 */
			{18810,53,0}, /* core2 return_Stack7 bit4 */
			{18850,53,0}, /* core2 return_Stack7 bit5 */
			{18808,53,0}, /* core2 return_Stack7 bit6 */
			{18848,53,0}, /* core2 return_Stack7 bit7 */
			{18806,53,0}, /* core2 return_Stack7 bit8 */
			{18804,53,0}, /* core2 return_Stack7 bit9 */
			{ 3826,53,0}, /* core2 return_Stack7 bit10 */
			{18846,53,0}, /* core2 return_Stack7 bit11 */
			{18844,53,0}, /* core2 return_Stack7 bit12 */
			{18834,53,0}, /* core2 return_Stack7 bit13 */
			{18832,53,0}, /* core2 return_Stack7 bit14 */
			{18830,53,0}, /* core2 return_Stack7 bit15 */
			{18828,53,0}, /* core2 return_Stack7 bit16 */
			{18842,53,0}, /* core2 return_Stack7 bit17 */
			{18840,53,0}, /* core2 return_Stack7 bit18 */
			{18838,53,0}, /* core2 return_Stack7 bit19 */
			{18836,53,0}, /* core2 return_Stack7 bit20 */
			{18802,53,0}, /* core2 return_Stack7 bit21 */
			{18800,53,0}, /* core2 return_Stack7 bit22 */
			{18798,53,0}, /* core2 return_Stack7 bit23 */
			{18796,53,0}, /* core2 return_Stack7 bit24 */
			{18778,53,0}, /* core2 return_Stack7 bit25 */
			{18776,53,0}, /* core2 return_Stack7 bit26 */
			{18774,53,0}, /* core2 return_Stack7 bit27 */
			{18772,53,0}, /* core2 return_Stack7 bit28 */
			{18754,53,0}, /* core2 return_Stack7 bit29 */
			{18752,53,0}, /* core2 return_Stack7 bit30 */
			{18750,53,0}, /* core2 return_Stack7 bit31 */
			{18748,53,0}, /* core2 return_Stack7 bit32 */
			{18970,53,0}, /* core2 return_Stack7 bit33 */
			{18968,53,0}, /* core2 return_Stack7 bit34 */
			{18966,53,0}, /* core2 return_Stack7 bit35 */
			{18964,53,0}, /* core2 return_Stack7 bit36 */
			{18962,53,0}, /* core2 return_Stack7 bit37 */
			{18960,53,0}, /* core2 return_Stack7 bit38 */
			{18958,53,0}, /* core2 return_Stack7 bit39 */
			{18956,53,0}, /* core2 return_Stack7 bit40 */
			{18954,53,0}, /* core2 return_Stack7 bit41 */
			{18952,53,0}, /* core2 return_Stack7 bit42 */
			{18950,53,0}, /* core2 return_Stack7 bit43 */
			{18948,53,0}, /* core2 return_Stack7 bit44 */
			{18722,53,0}, /* core2 return_Stack7 bit45 */
			{18720,53,0}, /* core2 return_Stack7 bit46 */
			{18718,53,0}, /* core2 return_Stack7 bit47 */
			{18716,53,0}, /* core2 return_Stack7 bit48 */
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
	},
	{		/* core 3 */ 
			.pc = {{
			{ 2530,55,1}, /* core3 pc bit0 */
			{ 2528,55,1}, /* core3 pc bit1 */
			{ 2526,55,1}, /* core3 pc bit2 */
			{ 2524,55,1}, /* core3 pc bit3 */
			{ 2594,55,1}, /* core3 pc bit4 */
			{ 2592,55,1}, /* core3 pc bit5 */
			{ 2590,55,1}, /* core3 pc bit6 */
			{ 2588,55,1}, /* core3 pc bit7 */
			{ 2578,55,1}, /* core3 pc bit8 */
			{ 2458,55,1}, /* core3 pc bit9 */
			{ 2456,55,1}, /* core3 pc bit10 */
			{ 2576,55,1}, /* core3 pc bit11 */
			{ 2574,55,1}, /* core3 pc bit12 */
			{ 2572,55,1}, /* core3 pc bit13 */
			{ 2454,55,1}, /* core3 pc bit14 */
			{ 2452,55,1}, /* core3 pc bit15 */
			{ 2306,55,1}, /* core3 pc bit16 */
			{ 2474,55,1}, /* core3 pc bit17 */
			{ 2304,55,1}, /* core3 pc bit18 */
			{ 2472,55,1}, /* core3 pc bit19 */
			{ 2302,55,1}, /* core3 pc bit20 */
			{ 2300,55,1}, /* core3 pc bit21 */
			{ 2470,55,1}, /* core3 pc bit22 */
			{ 2314,55,1}, /* core3 pc bit23 */
			{ 2312,55,1}, /* core3 pc bit24 */
			{ 2310,55,1}, /* core3 pc bit25 */
			{ 2468,55,1}, /* core3 pc bit26 */
			{ 2522,55,1}, /* core3 pc bit27 */
			{ 2308,55,1}, /* core3 pc bit28 */
			{ 2464,55,1}, /* core3 pc bit29 */
			{ 2684,55,1}, /* core3 pc bit30 */
			{ 2520,55,1}, /* core3 pc bit31 */
			{ 2518,55,1}, /* core3 pc bit32 */
			{ 2516,55,1}, /* core3 pc bit33 */
			{ 2562,55,1}, /* core3 pc bit34 */
			{ 2560,55,1}, /* core3 pc bit35 */
			{ 2558,55,1}, /* core3 pc bit36 */
			{ 2556,55,1}, /* core3 pc bit37 */
			{ 2586,55,1}, /* core3 pc bit38 */
			{ 2584,55,1}, /* core3 pc bit39 */
			{ 2582,55,1}, /* core3 pc bit40 */
			{ 2580,55,1}, /* core3 pc bit41 */
			{ 2570,55,1}, /* core3 pc bit42 */
			{ 2568,55,1}, /* core3 pc bit43 */
			{ 2566,55,1}, /* core3 pc bit44 */
			{ 2564,55,1}, /* core3 pc bit45 */
			{ 2626,55,1}, /* core3 pc bit46 */
			{ 2624,55,1}, /* core3 pc bit47 */
			{ 2622,55,1}, /* core3 pc bit48 */
			{ 2620,55,1}, /* core3 pc bit49 */
			{ 2658,55,1}, /* core3 pc bit50 */
			{ 2656,55,1}, /* core3 pc bit51 */
			{ 2654,55,1}, /* core3 pc bit52 */
			{ 2652,55,1}, /* core3 pc bit53 */
			{ 2290,55,1}, /* core3 pc bit54 */
			{ 2288,55,1}, /* core3 pc bit55 */
			{ 2286,55,1}, /* core3 pc bit56 */
			{ 2284,55,1}, /* core3 pc bit57 */
			{ 2132,55,1}, /* core3 pc bit58 */
			{ 2130,55,1}, /* core3 pc bit59 */
			{ 2128,55,1}, /* core3 pc bit60 */
			{ 2126,55,1}, /* core3 pc bit61 */
			{ 2116,55,1}, /* core3 pc bit62 */
			{  670,55,1}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{ 7110,59,0}, /* core3 sp32 bit0 */
			{15738,59,0}, /* core3 sp32 bit1 */
			{15732,59,0}, /* core3 sp32 bit2 */
			{ 7088,59,0}, /* core3 sp32 bit3 */
			{15730,59,0}, /* core3 sp32 bit4 */
			{15740,59,0}, /* core3 sp32 bit5 */
			{15716,59,0}, /* core3 sp32 bit6 */
			{15714,59,0}, /* core3 sp32 bit7 */
			{15724,59,0}, /* core3 sp32 bit8 */
			{15682,59,0}, /* core3 sp32 bit9 */
			{15692,59,0}, /* core3 sp32 bit10 */
			{15722,59,0}, /* core3 sp32 bit11 */
			{15712,59,0}, /* core3 sp32 bit12 */
			{15710,59,0}, /* core3 sp32 bit13 */
			{15690,59,0}, /* core3 sp32 bit14 */
			{22706,59,0}, /* core3 sp32 bit15 */
			{22704,59,0}, /* core3 sp32 bit16 */
			{22702,59,0}, /* core3 sp32 bit17 */
			{22700,59,0}, /* core3 sp32 bit18 */
			{15720,59,0}, /* core3 sp32 bit19 */
			{15718,59,0}, /* core3 sp32 bit20 */
			{15736,59,0}, /* core3 sp32 bit21 */
			{15728,59,0}, /* core3 sp32 bit22 */
			{15726,59,0}, /* core3 sp32 bit23 */
			{15734,59,0}, /* core3 sp32 bit24 */
			{15924,59,0}, /* core3 sp32 bit25 */
			{15922,59,0}, /* core3 sp32 bit26 */
			{15920,59,0}, /* core3 sp32 bit27 */
			{15918,59,0}, /* core3 sp32 bit28 */
			{15688,59,0}, /* core3 sp32 bit29 */
			{15686,59,0}, /* core3 sp32 bit30 */
			{15684,59,0}, /* core3 sp32 bit31 */
			{15864,59,0}, /* core3 sp32 bit32 */
			{15862,59,0}, /* core3 sp32 bit33 */
			{15856,59,0}, /* core3 sp32 bit34 */
			{15868,59,0}, /* core3 sp32 bit35 */
			{15852,59,0}, /* core3 sp32 bit36 */
			{15866,59,0}, /* core3 sp32 bit37 */
			{ 6780,59,0}, /* core3 sp32 bit38 */
			{15850,59,0}, /* core3 sp32 bit39 */
			{15854,59,0}, /* core3 sp32 bit40 */
			{15848,59,0}, /* core3 sp32 bit41 */
			{15846,59,0}, /* core3 sp32 bit42 */
			{15844,59,0}, /* core3 sp32 bit43 */
			{15842,59,0}, /* core3 sp32 bit44 */
			{15860,59,0}, /* core3 sp32 bit45 */
			{15858,59,0}, /* core3 sp32 bit46 */
			{15872,59,0}, /* core3 sp32 bit47 */
			{15876,59,0}, /* core3 sp32 bit48 */
			{22370,59,0}, /* core3 sp32 bit49 */
			{22368,59,0}, /* core3 sp32 bit50 */
			{22366,59,0}, /* core3 sp32 bit51 */
			{22364,59,0}, /* core3 sp32 bit52 */
			{22354,59,0}, /* core3 sp32 bit53 */
			{22352,59,0}, /* core3 sp32 bit54 */
			{22350,59,0}, /* core3 sp32 bit55 */
			{22348,59,0}, /* core3 sp32 bit56 */
			{22362,59,0}, /* core3 sp32 bit57 */
			{22360,59,0}, /* core3 sp32 bit58 */
			{22358,59,0}, /* core3 sp32 bit59 */
			{22356,59,0}, /* core3 sp32 bit60 */
			{15870,59,0}, /* core3 sp32 bit61 */
			{15874,59,0}, /* core3 sp32 bit62 */
			{ 6776,59,0}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{ 7124,59,0}, /* core3 fp32 bit0 */
			{ 7120,59,0}, /* core3 fp32 bit1 */
			{16530,59,0}, /* core3 fp32 bit2 */
			{16884,59,0}, /* core3 fp32 bit3 */
			{16880,59,0}, /* core3 fp32 bit4 */
			{16878,59,0}, /* core3 fp32 bit5 */
			{16876,59,0}, /* core3 fp32 bit6 */
			{16882,59,0}, /* core3 fp32 bit7 */
			{16874,59,0}, /* core3 fp32 bit8 */
			{16796,59,0}, /* core3 fp32 bit9 */
			{16794,59,0}, /* core3 fp32 bit10 */
			{ 7118,59,0}, /* core3 fp32 bit11 */
			{16548,59,0}, /* core3 fp32 bit12 */
			{16892,59,0}, /* core3 fp32 bit13 */
			{16792,59,0}, /* core3 fp32 bit14 */
			{16784,59,0}, /* core3 fp32 bit15 */
			{16886,59,0}, /* core3 fp32 bit16 */
			{16890,59,0}, /* core3 fp32 bit17 */
			{ 7116,59,0}, /* core3 fp32 bit18 */
			{ 7082,59,0}, /* core3 fp32 bit19 */
			{16546,59,0}, /* core3 fp32 bit20 */
			{16888,59,0}, /* core3 fp32 bit21 */
			{16532,59,0}, /* core3 fp32 bit22 */
			{ 7084,59,0}, /* core3 fp32 bit23 */
			{ 7114,59,0}, /* core3 fp32 bit24 */
			{ 6906,59,0}, /* core3 fp32 bit25 */
			{16782,59,0}, /* core3 fp32 bit26 */
			{16790,59,0}, /* core3 fp32 bit27 */
			{16788,59,0}, /* core3 fp32 bit28 */
			{ 6902,59,0}, /* core3 fp32 bit29 */
			{16786,59,0}, /* core3 fp32 bit30 */
			{ 6904,59,0}, /* core3 fp32 bit31 */
			{ 6830,59,0}, /* core3 fp32 bit32 */
			{ 6822,59,0}, /* core3 fp32 bit33 */
			{ 6824,59,0}, /* core3 fp32 bit34 */
			{ 6886,59,0}, /* core3 fp32 bit35 */
			{ 6884,59,0}, /* core3 fp32 bit36 */
			{ 6826,59,0}, /* core3 fp32 bit37 */
			{16624,59,0}, /* core3 fp32 bit38 */
			{16622,59,0}, /* core3 fp32 bit39 */
			{16632,59,0}, /* core3 fp32 bit40 */
			{16628,59,0}, /* core3 fp32 bit41 */
			{ 6820,59,0}, /* core3 fp32 bit42 */
			{16630,59,0}, /* core3 fp32 bit43 */
			{16626,59,0}, /* core3 fp32 bit44 */
			{16656,59,0}, /* core3 fp32 bit45 */
			{16648,59,0}, /* core3 fp32 bit46 */
			{16636,59,0}, /* core3 fp32 bit47 */
			{16634,59,0}, /* core3 fp32 bit48 */
			{22546,59,0}, /* core3 fp32 bit49 */
			{ 6818,59,0}, /* core3 fp32 bit50 */
			{22554,59,0}, /* core3 fp32 bit51 */
			{22552,59,0}, /* core3 fp32 bit52 */
			{22544,59,0}, /* core3 fp32 bit53 */
			{22542,59,0}, /* core3 fp32 bit54 */
			{22540,59,0}, /* core3 fp32 bit55 */
			{22550,59,0}, /* core3 fp32 bit56 */
			{22562,59,0}, /* core3 fp32 bit57 */
			{22560,59,0}, /* core3 fp32 bit58 */
			{22548,59,0}, /* core3 fp32 bit59 */
			{16646,59,0}, /* core3 fp32 bit60 */
			{16654,59,0}, /* core3 fp32 bit61 */
			{22558,59,0}, /* core3 fp32 bit62 */
			{22556,59,0}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{14752,59,0}, /* core3 fp64 bit0 */
			{ 6972,59,0}, /* core3 fp64 bit1 */
			{14750,59,0}, /* core3 fp64 bit2 */
			{15068,59,0}, /* core3 fp64 bit3 */
			{15066,59,0}, /* core3 fp64 bit4 */
			{15080,59,0}, /* core3 fp64 bit5 */
			{15078,59,0}, /* core3 fp64 bit6 */
			{15076,59,0}, /* core3 fp64 bit7 */
			{15074,59,0}, /* core3 fp64 bit8 */
			{15020,59,0}, /* core3 fp64 bit9 */
			{14798,59,0}, /* core3 fp64 bit10 */
			{15060,59,0}, /* core3 fp64 bit11 */
			{15058,59,0}, /* core3 fp64 bit12 */
			{15072,59,0}, /* core3 fp64 bit13 */
			{15018,59,0}, /* core3 fp64 bit14 */
			{14804,59,0}, /* core3 fp64 bit15 */
			{15070,59,0}, /* core3 fp64 bit16 */
			{15084,59,0}, /* core3 fp64 bit17 */
			{14748,59,0}, /* core3 fp64 bit18 */
			{15082,59,0}, /* core3 fp64 bit19 */
			{15064,59,0}, /* core3 fp64 bit20 */
			{14746,59,0}, /* core3 fp64 bit21 */
			{15062,59,0}, /* core3 fp64 bit22 */
			{ 7066,59,0}, /* core3 fp64 bit23 */
			{14756,59,0}, /* core3 fp64 bit24 */
			{14754,59,0}, /* core3 fp64 bit25 */
			{ 6946,59,0}, /* core3 fp64 bit26 */
			{14808,59,0}, /* core3 fp64 bit27 */
			{14806,59,0}, /* core3 fp64 bit28 */
			{14802,59,0}, /* core3 fp64 bit29 */
			{ 6970,59,0}, /* core3 fp64 bit30 */
			{14800,59,0}, /* core3 fp64 bit31 */
			{14888,59,0}, /* core3 fp64 bit32 */
			{14884,59,0}, /* core3 fp64 bit33 */
			{14886,59,0}, /* core3 fp64 bit34 */
			{ 6708,59,0}, /* core3 fp64 bit35 */
			{14892,59,0}, /* core3 fp64 bit36 */
			{14882,59,0}, /* core3 fp64 bit37 */
			{ 6700,59,0}, /* core3 fp64 bit38 */
			{14890,59,0}, /* core3 fp64 bit39 */
			{14896,59,0}, /* core3 fp64 bit40 */
			{14894,59,0}, /* core3 fp64 bit41 */
			{14900,59,0}, /* core3 fp64 bit42 */
			{14904,59,0}, /* core3 fp64 bit43 */
			{14902,59,0}, /* core3 fp64 bit44 */
			{14912,59,0}, /* core3 fp64 bit45 */
			{14898,59,0}, /* core3 fp64 bit46 */
			{14910,59,0}, /* core3 fp64 bit47 */
			{14916,59,0}, /* core3 fp64 bit48 */
			{14914,59,0}, /* core3 fp64 bit49 */
			{21972,59,0}, /* core3 fp64 bit50 */
			{21980,59,0}, /* core3 fp64 bit51 */
			{21970,59,0}, /* core3 fp64 bit52 */
			{21978,59,0}, /* core3 fp64 bit53 */
			{21968,59,0}, /* core3 fp64 bit54 */
			{21966,59,0}, /* core3 fp64 bit55 */
			{21988,59,0}, /* core3 fp64 bit56 */
			{21986,59,0}, /* core3 fp64 bit57 */
			{21976,59,0}, /* core3 fp64 bit58 */
			{21984,59,0}, /* core3 fp64 bit59 */
			{14920,59,0}, /* core3 fp64 bit60 */
			{21982,59,0}, /* core3 fp64 bit61 */
			{21974,59,0}, /* core3 fp64 bit62 */
			{14918,59,0}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{ 6982,59,0}, /* core3 sp_EL0 bit0 */
			{ 6974,59,0}, /* core3 sp_EL0 bit1 */
			{14710,59,0}, /* core3 sp_EL0 bit2 */
			{14720,59,0}, /* core3 sp_EL0 bit3 */
			{14718,59,0}, /* core3 sp_EL0 bit4 */
			{15108,59,0}, /* core3 sp_EL0 bit5 */
			{15106,59,0}, /* core3 sp_EL0 bit6 */
			{ 7046,59,0}, /* core3 sp_EL0 bit7 */
			{15112,59,0}, /* core3 sp_EL0 bit8 */
			{14772,59,0}, /* core3 sp_EL0 bit9 */
			{14770,59,0}, /* core3 sp_EL0 bit10 */
			{14708,59,0}, /* core3 sp_EL0 bit11 */
			{14706,59,0}, /* core3 sp_EL0 bit12 */
			{15032,59,0}, /* core3 sp_EL0 bit13 */
			{15030,59,0}, /* core3 sp_EL0 bit14 */
			{14776,59,0}, /* core3 sp_EL0 bit15 */
			{15036,59,0}, /* core3 sp_EL0 bit16 */
			{15110,59,0}, /* core3 sp_EL0 bit17 */
			{15034,59,0}, /* core3 sp_EL0 bit18 */
			{ 7050,59,0}, /* core3 sp_EL0 bit19 */
			{14716,59,0}, /* core3 sp_EL0 bit20 */
			{ 7048,59,0}, /* core3 sp_EL0 bit21 */
			{14712,59,0}, /* core3 sp_EL0 bit22 */
			{14714,59,0}, /* core3 sp_EL0 bit23 */
			{14760,59,0}, /* core3 sp_EL0 bit24 */
			{14758,59,0}, /* core3 sp_EL0 bit25 */
			{14780,59,0}, /* core3 sp_EL0 bit26 */
			{14778,59,0}, /* core3 sp_EL0 bit27 */
			{15008,59,0}, /* core3 sp_EL0 bit28 */
			{14774,59,0}, /* core3 sp_EL0 bit29 */
			{15006,59,0}, /* core3 sp_EL0 bit30 */
			{ 7018,59,0}, /* core3 sp_EL0 bit31 */
			{14820,59,0}, /* core3 sp_EL0 bit32 */
			{14818,59,0}, /* core3 sp_EL0 bit33 */
			{14844,59,0}, /* core3 sp_EL0 bit34 */
			{14812,59,0}, /* core3 sp_EL0 bit35 */
			{14810,59,0}, /* core3 sp_EL0 bit36 */
			{14816,59,0}, /* core3 sp_EL0 bit37 */
			{14814,59,0}, /* core3 sp_EL0 bit38 */
			{ 6836,59,0}, /* core3 sp_EL0 bit39 */
			{14842,59,0}, /* core3 sp_EL0 bit40 */
			{14836,59,0}, /* core3 sp_EL0 bit41 */
			{14840,59,0}, /* core3 sp_EL0 bit42 */
			{14838,59,0}, /* core3 sp_EL0 bit43 */
			{14828,59,0}, /* core3 sp_EL0 bit44 */
			{14834,59,0}, /* core3 sp_EL0 bit45 */
			{21900,59,0}, /* core3 sp_EL0 bit46 */
			{14832,59,0}, /* core3 sp_EL0 bit47 */
			{21898,59,0}, /* core3 sp_EL0 bit48 */
			{21896,59,0}, /* core3 sp_EL0 bit49 */
			{14830,59,0}, /* core3 sp_EL0 bit50 */
			{21894,59,0}, /* core3 sp_EL0 bit51 */
			{21892,59,0}, /* core3 sp_EL0 bit52 */
			{21884,59,0}, /* core3 sp_EL0 bit53 */
			{21890,59,0}, /* core3 sp_EL0 bit54 */
			{21888,59,0}, /* core3 sp_EL0 bit55 */
			{21886,59,0}, /* core3 sp_EL0 bit56 */
			{14824,59,0}, /* core3 sp_EL0 bit57 */
			{21882,59,0}, /* core3 sp_EL0 bit58 */
			{14822,59,0}, /* core3 sp_EL0 bit59 */
			{21880,59,0}, /* core3 sp_EL0 bit60 */
			{ 6838,59,0}, /* core3 sp_EL0 bit61 */
			{21878,59,0}, /* core3 sp_EL0 bit62 */
			{14826,59,0}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{ 6988,59,0}, /* core3 sp_EL1 bit0 */
			{ 6998,59,0}, /* core3 sp_EL1 bit1 */
			{14740,59,0}, /* core3 sp_EL1 bit2 */
			{14738,59,0}, /* core3 sp_EL1 bit3 */
			{15096,59,0}, /* core3 sp_EL1 bit4 */
			{15094,59,0}, /* core3 sp_EL1 bit5 */
			{15088,59,0}, /* core3 sp_EL1 bit6 */
			{15116,59,0}, /* core3 sp_EL1 bit7 */
			{15086,59,0}, /* core3 sp_EL1 bit8 */
			{15014,59,0}, /* core3 sp_EL1 bit9 */
			{15002,59,0}, /* core3 sp_EL1 bit10 */
			{15114,59,0}, /* core3 sp_EL1 bit11 */
			{15120,59,0}, /* core3 sp_EL1 bit12 */
			{15118,59,0}, /* core3 sp_EL1 bit13 */
			{21844,59,0}, /* core3 sp_EL1 bit14 */
			{15000,59,0}, /* core3 sp_EL1 bit15 */
			{21842,59,0}, /* core3 sp_EL1 bit16 */
			{15128,59,0}, /* core3 sp_EL1 bit17 */
			{21840,59,0}, /* core3 sp_EL1 bit18 */
			{15126,59,0}, /* core3 sp_EL1 bit19 */
			{21838,59,0}, /* core3 sp_EL1 bit20 */
			{ 7064,59,0}, /* core3 sp_EL1 bit21 */
			{ 7056,59,0}, /* core3 sp_EL1 bit22 */
			{ 7062,59,0}, /* core3 sp_EL1 bit23 */
			{ 6994,59,0}, /* core3 sp_EL1 bit24 */
			{14992,59,0}, /* core3 sp_EL1 bit25 */
			{14990,59,0}, /* core3 sp_EL1 bit26 */
			{14996,59,0}, /* core3 sp_EL1 bit27 */
			{14994,59,0}, /* core3 sp_EL1 bit28 */
			{14998,59,0}, /* core3 sp_EL1 bit29 */
			{15016,59,0}, /* core3 sp_EL1 bit30 */
			{15004,59,0}, /* core3 sp_EL1 bit31 */
			{ 6864,59,0}, /* core3 sp_EL1 bit32 */
			{14876,59,0}, /* core3 sp_EL1 bit33 */
			{14940,59,0}, /* core3 sp_EL1 bit34 */
			{14874,59,0}, /* core3 sp_EL1 bit35 */
			{14880,59,0}, /* core3 sp_EL1 bit36 */
			{14878,59,0}, /* core3 sp_EL1 bit37 */
			{14948,59,0}, /* core3 sp_EL1 bit38 */
			{14946,59,0}, /* core3 sp_EL1 bit39 */
			{14938,59,0}, /* core3 sp_EL1 bit40 */
			{14944,59,0}, /* core3 sp_EL1 bit41 */
			{14942,59,0}, /* core3 sp_EL1 bit42 */
			{14936,59,0}, /* core3 sp_EL1 bit43 */
			{14934,59,0}, /* core3 sp_EL1 bit44 */
			{14932,59,0}, /* core3 sp_EL1 bit45 */
			{ 6868,59,0}, /* core3 sp_EL1 bit46 */
			{14930,59,0}, /* core3 sp_EL1 bit47 */
			{22116,59,0}, /* core3 sp_EL1 bit48 */
			{22114,59,0}, /* core3 sp_EL1 bit49 */
			{22108,59,0}, /* core3 sp_EL1 bit50 */
			{22106,59,0}, /* core3 sp_EL1 bit51 */
			{22104,59,0}, /* core3 sp_EL1 bit52 */
			{22102,59,0}, /* core3 sp_EL1 bit53 */
			{22124,59,0}, /* core3 sp_EL1 bit54 */
			{22122,59,0}, /* core3 sp_EL1 bit55 */
			{22120,59,0}, /* core3 sp_EL1 bit56 */
			{22118,59,0}, /* core3 sp_EL1 bit57 */
			{22100,59,0}, /* core3 sp_EL1 bit58 */
			{22098,59,0}, /* core3 sp_EL1 bit59 */
			{22096,59,0}, /* core3 sp_EL1 bit60 */
			{22094,59,0}, /* core3 sp_EL1 bit61 */
			{22112,59,0}, /* core3 sp_EL1 bit62 */
			{22110,59,0}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{ 6986,59,0}, /* core3 sp_EL2 bit0 */
			{ 7000,59,0}, /* core3 sp_EL2 bit1 */
			{14736,59,0}, /* core3 sp_EL2 bit2 */
			{14734,59,0}, /* core3 sp_EL2 bit3 */
			{15132,59,0}, /* core3 sp_EL2 bit4 */
			{15130,59,0}, /* core3 sp_EL2 bit5 */
			{15092,59,0}, /* core3 sp_EL2 bit6 */
			{14704,59,0}, /* core3 sp_EL2 bit7 */
			{15090,59,0}, /* core3 sp_EL2 bit8 */
			{15012,59,0}, /* core3 sp_EL2 bit9 */
			{15010,59,0}, /* core3 sp_EL2 bit10 */
			{14702,59,0}, /* core3 sp_EL2 bit11 */
			{15124,59,0}, /* core3 sp_EL2 bit12 */
			{15122,59,0}, /* core3 sp_EL2 bit13 */
			{21852,59,0}, /* core3 sp_EL2 bit14 */
			{ 7012,59,0}, /* core3 sp_EL2 bit15 */
			{21850,59,0}, /* core3 sp_EL2 bit16 */
			{15136,59,0}, /* core3 sp_EL2 bit17 */
			{21848,59,0}, /* core3 sp_EL2 bit18 */
			{15134,59,0}, /* core3 sp_EL2 bit19 */
			{21846,59,0}, /* core3 sp_EL2 bit20 */
			{ 7060,59,0}, /* core3 sp_EL2 bit21 */
			{ 7058,59,0}, /* core3 sp_EL2 bit22 */
			{ 7052,59,0}, /* core3 sp_EL2 bit23 */
			{14764,59,0}, /* core3 sp_EL2 bit24 */
			{14762,59,0}, /* core3 sp_EL2 bit25 */
			{14988,59,0}, /* core3 sp_EL2 bit26 */
			{14986,59,0}, /* core3 sp_EL2 bit27 */
			{ 7016,59,0}, /* core3 sp_EL2 bit28 */
			{ 7014,59,0}, /* core3 sp_EL2 bit29 */
			{ 7008,59,0}, /* core3 sp_EL2 bit30 */
			{ 7010,59,0}, /* core3 sp_EL2 bit31 */
			{ 6860,59,0}, /* core3 sp_EL2 bit32 */
			{14868,59,0}, /* core3 sp_EL2 bit33 */
			{14964,59,0}, /* core3 sp_EL2 bit34 */
			{14866,59,0}, /* core3 sp_EL2 bit35 */
			{14864,59,0}, /* core3 sp_EL2 bit36 */
			{14862,59,0}, /* core3 sp_EL2 bit37 */
			{14872,59,0}, /* core3 sp_EL2 bit38 */
			{14870,59,0}, /* core3 sp_EL2 bit39 */
			{14962,59,0}, /* core3 sp_EL2 bit40 */
			{14952,59,0}, /* core3 sp_EL2 bit41 */
			{14950,59,0}, /* core3 sp_EL2 bit42 */
			{14960,59,0}, /* core3 sp_EL2 bit43 */
			{14958,59,0}, /* core3 sp_EL2 bit44 */
			{14956,59,0}, /* core3 sp_EL2 bit45 */
			{ 6858,59,0}, /* core3 sp_EL2 bit46 */
			{14954,59,0}, /* core3 sp_EL2 bit47 */
			{22148,59,0}, /* core3 sp_EL2 bit48 */
			{22146,59,0}, /* core3 sp_EL2 bit49 */
			{22140,59,0}, /* core3 sp_EL2 bit50 */
			{22138,59,0}, /* core3 sp_EL2 bit51 */
			{22136,59,0}, /* core3 sp_EL2 bit52 */
			{22134,59,0}, /* core3 sp_EL2 bit53 */
			{22132,59,0}, /* core3 sp_EL2 bit54 */
			{22130,59,0}, /* core3 sp_EL2 bit55 */
			{22128,59,0}, /* core3 sp_EL2 bit56 */
			{22126,59,0}, /* core3 sp_EL2 bit57 */
			{22156,59,0}, /* core3 sp_EL2 bit58 */
			{22154,59,0}, /* core3 sp_EL2 bit59 */
			{22152,59,0}, /* core3 sp_EL2 bit60 */
			{22150,59,0}, /* core3 sp_EL2 bit61 */
			{22144,59,0}, /* core3 sp_EL2 bit62 */
			{22142,59,0}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{ 6984,59,0}, /* core3 sp_EL3 bit0 */
			{ 6996,59,0}, /* core3 sp_EL3 bit1 */
			{14732,59,0}, /* core3 sp_EL3 bit2 */
			{14388,59,0}, /* core3 sp_EL3 bit3 */
			{15104,59,0}, /* core3 sp_EL3 bit4 */
			{15102,59,0}, /* core3 sp_EL3 bit5 */
			{14730,59,0}, /* core3 sp_EL3 bit6 */
			{14768,59,0}, /* core3 sp_EL3 bit7 */
			{15100,59,0}, /* core3 sp_EL3 bit8 */
			{14766,59,0}, /* core3 sp_EL3 bit9 */
			{14332,59,0}, /* core3 sp_EL3 bit10 */
			{14700,59,0}, /* core3 sp_EL3 bit11 */
			{14698,59,0}, /* core3 sp_EL3 bit12 */
			{14696,59,0}, /* core3 sp_EL3 bit13 */
			{14694,59,0}, /* core3 sp_EL3 bit14 */
			{14338,59,0}, /* core3 sp_EL3 bit15 */
			{14394,59,0}, /* core3 sp_EL3 bit16 */
			{15098,59,0}, /* core3 sp_EL3 bit17 */
			{14402,59,0}, /* core3 sp_EL3 bit18 */
			{ 7054,59,0}, /* core3 sp_EL3 bit19 */
			{14392,59,0}, /* core3 sp_EL3 bit20 */
			{14400,59,0}, /* core3 sp_EL3 bit21 */
			{14390,59,0}, /* core3 sp_EL3 bit22 */
			{14398,59,0}, /* core3 sp_EL3 bit23 */
			{14396,59,0}, /* core3 sp_EL3 bit24 */
			{14326,59,0}, /* core3 sp_EL3 bit25 */
			{14324,59,0}, /* core3 sp_EL3 bit26 */
			{14330,59,0}, /* core3 sp_EL3 bit27 */
			{14328,59,0}, /* core3 sp_EL3 bit28 */
			{14336,59,0}, /* core3 sp_EL3 bit29 */
			{ 7020,59,0}, /* core3 sp_EL3 bit30 */
			{14334,59,0}, /* core3 sp_EL3 bit31 */
			{14310,59,0}, /* core3 sp_EL3 bit32 */
			{14306,59,0}, /* core3 sp_EL3 bit33 */
			{14270,59,0}, /* core3 sp_EL3 bit34 */
			{14308,59,0}, /* core3 sp_EL3 bit35 */
			{14304,59,0}, /* core3 sp_EL3 bit36 */
			{14302,59,0}, /* core3 sp_EL3 bit37 */
			{14314,59,0}, /* core3 sp_EL3 bit38 */
			{14300,59,0}, /* core3 sp_EL3 bit39 */
			{14266,59,0}, /* core3 sp_EL3 bit40 */
			{14264,59,0}, /* core3 sp_EL3 bit41 */
			{14268,59,0}, /* core3 sp_EL3 bit42 */
			{14262,59,0}, /* core3 sp_EL3 bit43 */
			{14260,59,0}, /* core3 sp_EL3 bit44 */
			{14258,59,0}, /* core3 sp_EL3 bit45 */
			{14312,59,0}, /* core3 sp_EL3 bit46 */
			{14256,59,0}, /* core3 sp_EL3 bit47 */
			{22188,59,0}, /* core3 sp_EL3 bit48 */
			{22186,59,0}, /* core3 sp_EL3 bit49 */
			{22184,59,0}, /* core3 sp_EL3 bit50 */
			{22182,59,0}, /* core3 sp_EL3 bit51 */
			{22172,59,0}, /* core3 sp_EL3 bit52 */
			{22170,59,0}, /* core3 sp_EL3 bit53 */
			{22168,59,0}, /* core3 sp_EL3 bit54 */
			{22166,59,0}, /* core3 sp_EL3 bit55 */
			{22180,59,0}, /* core3 sp_EL3 bit56 */
			{22178,59,0}, /* core3 sp_EL3 bit57 */
			{22176,59,0}, /* core3 sp_EL3 bit58 */
			{22174,59,0}, /* core3 sp_EL3 bit59 */
			{22164,59,0}, /* core3 sp_EL3 bit60 */
			{22162,59,0}, /* core3 sp_EL3 bit61 */
			{22160,59,0}, /* core3 sp_EL3 bit62 */
			{22158,59,0}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{21836,59,0}, /* core3 elr_EL1 bit0 */
			{21552,59,0}, /* core3 elr_EL1 bit1 */
			{21606,59,0}, /* core3 elr_EL1 bit2 */
			{21604,59,0}, /* core3 elr_EL1 bit3 */
			{21602,59,0}, /* core3 elr_EL1 bit4 */
			{21600,59,0}, /* core3 elr_EL1 bit5 */
			{21598,59,0}, /* core3 elr_EL1 bit6 */
			{21596,59,0}, /* core3 elr_EL1 bit7 */
			{21594,59,0}, /* core3 elr_EL1 bit8 */
			{21834,59,0}, /* core3 elr_EL1 bit9 */
			{21592,59,0}, /* core3 elr_EL1 bit10 */
			{21614,59,0}, /* core3 elr_EL1 bit11 */
			{21612,59,0}, /* core3 elr_EL1 bit12 */
			{21610,59,0}, /* core3 elr_EL1 bit13 */
			{21832,59,0}, /* core3 elr_EL1 bit14 */
			{14362,59,0}, /* core3 elr_EL1 bit15 */
			{21830,59,0}, /* core3 elr_EL1 bit16 */
			{21608,59,0}, /* core3 elr_EL1 bit17 */
			{21582,59,0}, /* core3 elr_EL1 bit18 */
			{21580,59,0}, /* core3 elr_EL1 bit19 */
			{21558,59,0}, /* core3 elr_EL1 bit20 */
			{14414,59,0}, /* core3 elr_EL1 bit21 */
			{21578,59,0}, /* core3 elr_EL1 bit22 */
			{21556,59,0}, /* core3 elr_EL1 bit23 */
			{21576,59,0}, /* core3 elr_EL1 bit24 */
			{21542,59,0}, /* core3 elr_EL1 bit25 */
			{21554,59,0}, /* core3 elr_EL1 bit26 */
			{21540,59,0}, /* core3 elr_EL1 bit27 */
			{21538,59,0}, /* core3 elr_EL1 bit28 */
			{14360,59,0}, /* core3 elr_EL1 bit29 */
			{21536,59,0}, /* core3 elr_EL1 bit30 */
			{14412,59,0}, /* core3 elr_EL1 bit31 */
			{21478,59,0}, /* core3 elr_EL1 bit32 */
			{21486,59,0}, /* core3 elr_EL1 bit33 */
			{21484,59,0}, /* core3 elr_EL1 bit34 */
			{21476,59,0}, /* core3 elr_EL1 bit35 */
			{21474,59,0}, /* core3 elr_EL1 bit36 */
			{21472,59,0}, /* core3 elr_EL1 bit37 */
			{14322,59,0}, /* core3 elr_EL1 bit38 */
			{14320,59,0}, /* core3 elr_EL1 bit39 */
			{21482,59,0}, /* core3 elr_EL1 bit40 */
			{21480,59,0}, /* core3 elr_EL1 bit41 */
			{21494,59,0}, /* core3 elr_EL1 bit42 */
			{21492,59,0}, /* core3 elr_EL1 bit43 */
			{21490,59,0}, /* core3 elr_EL1 bit44 */
			{21488,59,0}, /* core3 elr_EL1 bit45 */
			{21502,59,0}, /* core3 elr_EL1 bit46 */
			{21500,59,0}, /* core3 elr_EL1 bit47 */
			{21498,59,0}, /* core3 elr_EL1 bit48 */
			{21496,59,0}, /* core3 elr_EL1 bit49 */
			{21510,59,0}, /* core3 elr_EL1 bit50 */
			{21508,59,0}, /* core3 elr_EL1 bit51 */
			{21506,59,0}, /* core3 elr_EL1 bit52 */
			{21504,59,0}, /* core3 elr_EL1 bit53 */
			{21518,59,0}, /* core3 elr_EL1 bit54 */
			{21516,59,0}, /* core3 elr_EL1 bit55 */
			{21514,59,0}, /* core3 elr_EL1 bit56 */
			{21512,59,0}, /* core3 elr_EL1 bit57 */
			{21526,59,0}, /* core3 elr_EL1 bit58 */
			{21524,59,0}, /* core3 elr_EL1 bit59 */
			{21522,59,0}, /* core3 elr_EL1 bit60 */
			{21520,59,0}, /* core3 elr_EL1 bit61 */
			{14318,59,0}, /* core3 elr_EL1 bit62 */
			{14316,59,0}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{21590,59,0}, /* core3 elr_EL2 bit0 */
			{21588,59,0}, /* core3 elr_EL2 bit1 */
			{21586,59,0}, /* core3 elr_EL2 bit2 */
			{21584,59,0}, /* core3 elr_EL2 bit3 */
			{21638,59,0}, /* core3 elr_EL2 bit4 */
			{21636,59,0}, /* core3 elr_EL2 bit5 */
			{21634,59,0}, /* core3 elr_EL2 bit6 */
			{21632,59,0}, /* core3 elr_EL2 bit7 */
			{21550,59,0}, /* core3 elr_EL2 bit8 */
			{21548,59,0}, /* core3 elr_EL2 bit9 */
			{21546,59,0}, /* core3 elr_EL2 bit10 */
			{21544,59,0}, /* core3 elr_EL2 bit11 */
			{21574,59,0}, /* core3 elr_EL2 bit12 */
			{21572,59,0}, /* core3 elr_EL2 bit13 */
			{21570,59,0}, /* core3 elr_EL2 bit14 */
			{14358,59,0}, /* core3 elr_EL2 bit15 */
			{21568,59,0}, /* core3 elr_EL2 bit16 */
			{21622,59,0}, /* core3 elr_EL2 bit17 */
			{21620,59,0}, /* core3 elr_EL2 bit18 */
			{21618,59,0}, /* core3 elr_EL2 bit19 */
			{21616,59,0}, /* core3 elr_EL2 bit20 */
			{14418,59,0}, /* core3 elr_EL2 bit21 */
			{21566,59,0}, /* core3 elr_EL2 bit22 */
			{21564,59,0}, /* core3 elr_EL2 bit23 */
			{21562,59,0}, /* core3 elr_EL2 bit24 */
			{21560,59,0}, /* core3 elr_EL2 bit25 */
			{21534,59,0}, /* core3 elr_EL2 bit26 */
			{21532,59,0}, /* core3 elr_EL2 bit27 */
			{21530,59,0}, /* core3 elr_EL2 bit28 */
			{14356,59,0}, /* core3 elr_EL2 bit29 */
			{21528,59,0}, /* core3 elr_EL2 bit30 */
			{14416,59,0}, /* core3 elr_EL2 bit31 */
			{21462,59,0}, /* core3 elr_EL2 bit32 */
			{21460,59,0}, /* core3 elr_EL2 bit33 */
			{21458,59,0}, /* core3 elr_EL2 bit34 */
			{21456,59,0}, /* core3 elr_EL2 bit35 */
			{21454,59,0}, /* core3 elr_EL2 bit36 */
			{21452,59,0}, /* core3 elr_EL2 bit37 */
			{21450,59,0}, /* core3 elr_EL2 bit38 */
			{21448,59,0}, /* core3 elr_EL2 bit39 */
			{21438,59,0}, /* core3 elr_EL2 bit40 */
			{21436,59,0}, /* core3 elr_EL2 bit41 */
			{21434,59,0}, /* core3 elr_EL2 bit42 */
			{21432,59,0}, /* core3 elr_EL2 bit43 */
			{21446,59,0}, /* core3 elr_EL2 bit44 */
			{21444,59,0}, /* core3 elr_EL2 bit45 */
			{21442,59,0}, /* core3 elr_EL2 bit46 */
			{21440,59,0}, /* core3 elr_EL2 bit47 */
			{21470,59,0}, /* core3 elr_EL2 bit48 */
			{21468,59,0}, /* core3 elr_EL2 bit49 */
			{21466,59,0}, /* core3 elr_EL2 bit50 */
			{21464,59,0}, /* core3 elr_EL2 bit51 */
			{21430,59,0}, /* core3 elr_EL2 bit52 */
			{21428,59,0}, /* core3 elr_EL2 bit53 */
			{21426,59,0}, /* core3 elr_EL2 bit54 */
			{21424,59,0}, /* core3 elr_EL2 bit55 */
			{21422,59,0}, /* core3 elr_EL2 bit56 */
			{21420,59,0}, /* core3 elr_EL2 bit57 */
			{21418,59,0}, /* core3 elr_EL2 bit58 */
			{21416,59,0}, /* core3 elr_EL2 bit59 */
			{21414,59,0}, /* core3 elr_EL2 bit60 */
			{21412,59,0}, /* core3 elr_EL2 bit61 */
			{21410,59,0}, /* core3 elr_EL2 bit62 */
			{21408,59,0}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{ 6990,59,0}, /* core3 elr_EL3 bit0 */
			{ 7002,59,0}, /* core3 elr_EL3 bit1 */
			{14404,59,0}, /* core3 elr_EL3 bit2 */
			{14382,59,0}, /* core3 elr_EL3 bit3 */
			{14386,59,0}, /* core3 elr_EL3 bit4 */
			{14380,59,0}, /* core3 elr_EL3 bit5 */
			{14378,59,0}, /* core3 elr_EL3 bit6 */
			{14376,59,0}, /* core3 elr_EL3 bit7 */
			{14370,59,0}, /* core3 elr_EL3 bit8 */
			{14366,59,0}, /* core3 elr_EL3 bit9 */
			{14344,59,0}, /* core3 elr_EL3 bit10 */
			{14384,59,0}, /* core3 elr_EL3 bit11 */
			{14374,59,0}, /* core3 elr_EL3 bit12 */
			{14372,59,0}, /* core3 elr_EL3 bit13 */
			{14410,59,0}, /* core3 elr_EL3 bit14 */
			{14352,59,0}, /* core3 elr_EL3 bit15 */
			{21630,59,0}, /* core3 elr_EL3 bit16 */
			{21628,59,0}, /* core3 elr_EL3 bit17 */
			{14408,59,0}, /* core3 elr_EL3 bit18 */
			{14406,59,0}, /* core3 elr_EL3 bit19 */
			{21626,59,0}, /* core3 elr_EL3 bit20 */
			{ 6992,59,0}, /* core3 elr_EL3 bit21 */
			{21624,59,0}, /* core3 elr_EL3 bit22 */
			{14368,59,0}, /* core3 elr_EL3 bit23 */
			{14364,59,0}, /* core3 elr_EL3 bit24 */
			{14342,59,0}, /* core3 elr_EL3 bit25 */
			{14350,59,0}, /* core3 elr_EL3 bit26 */
			{14348,59,0}, /* core3 elr_EL3 bit27 */
			{14340,59,0}, /* core3 elr_EL3 bit28 */
			{14354,59,0}, /* core3 elr_EL3 bit29 */
			{ 7004,59,0}, /* core3 elr_EL3 bit30 */
			{14346,59,0}, /* core3 elr_EL3 bit31 */
			{14298,59,0}, /* core3 elr_EL3 bit32 */
			{14296,59,0}, /* core3 elr_EL3 bit33 */
			{14290,59,0}, /* core3 elr_EL3 bit34 */
			{14294,59,0}, /* core3 elr_EL3 bit35 */
			{14288,59,0}, /* core3 elr_EL3 bit36 */
			{14292,59,0}, /* core3 elr_EL3 bit37 */
			{ 6854,59,0}, /* core3 elr_EL3 bit38 */
			{14282,59,0}, /* core3 elr_EL3 bit39 */
			{14286,59,0}, /* core3 elr_EL3 bit40 */
			{14254,59,0}, /* core3 elr_EL3 bit41 */
			{14284,59,0}, /* core3 elr_EL3 bit42 */
			{14252,59,0}, /* core3 elr_EL3 bit43 */
			{14278,59,0}, /* core3 elr_EL3 bit44 */
			{14274,59,0}, /* core3 elr_EL3 bit45 */
			{ 6856,59,0}, /* core3 elr_EL3 bit46 */
			{14272,59,0}, /* core3 elr_EL3 bit47 */
			{14276,59,0}, /* core3 elr_EL3 bit48 */
			{21406,59,0}, /* core3 elr_EL3 bit49 */
			{14250,59,0}, /* core3 elr_EL3 bit50 */
			{21398,59,0}, /* core3 elr_EL3 bit51 */
			{21396,59,0}, /* core3 elr_EL3 bit52 */
			{21394,59,0}, /* core3 elr_EL3 bit53 */
			{21392,59,0}, /* core3 elr_EL3 bit54 */
			{21390,59,0}, /* core3 elr_EL3 bit55 */
			{21388,59,0}, /* core3 elr_EL3 bit56 */
			{21386,59,0}, /* core3 elr_EL3 bit57 */
			{21404,59,0}, /* core3 elr_EL3 bit58 */
			{21384,59,0}, /* core3 elr_EL3 bit59 */
			{14280,59,0}, /* core3 elr_EL3 bit60 */
			{14248,59,0}, /* core3 elr_EL3 bit61 */
			{21402,59,0}, /* core3 elr_EL3 bit62 */
			{21400,59,0}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{20350,59,0}, /* core3 raw_pc bit0 */
			{19196,58,0}, /* core3 raw_pc bit1 */
			{19194,58,0}, /* core3 raw_pc bit2 */
			{19192,58,0}, /* core3 raw_pc bit3 */
			{19190,58,0}, /* core3 raw_pc bit4 */
			{20348,59,0}, /* core3 raw_pc bit5 */
			{20346,59,0}, /* core3 raw_pc bit6 */
			{19180,58,0}, /* core3 raw_pc bit7 */
			{19178,58,0}, /* core3 raw_pc bit8 */
			{19176,58,0}, /* core3 raw_pc bit9 */
			{19174,58,0}, /* core3 raw_pc bit10 */
			{19154,58,0}, /* core3 raw_pc bit11 */
			{19152,58,0}, /* core3 raw_pc bit12 */
			{19150,58,0}, /* core3 raw_pc bit13 */
			{19148,58,0}, /* core3 raw_pc bit14 */
			{19168,58,0}, /* core3 raw_pc bit15 */
			{19166,58,0}, /* core3 raw_pc bit16 */
			{19164,58,0}, /* core3 raw_pc bit17 */
			{19162,58,0}, /* core3 raw_pc bit18 */
			{19170,58,0}, /* core3 raw_pc bit19 */
			{19160,58,0}, /* core3 raw_pc bit20 */
			{19158,58,0}, /* core3 raw_pc bit21 */
			{19156,58,0}, /* core3 raw_pc bit22 */
			{19138,58,0}, /* core3 raw_pc bit23 */
			{19136,58,0}, /* core3 raw_pc bit24 */
			{19134,58,0}, /* core3 raw_pc bit25 */
			{19132,58,0}, /* core3 raw_pc bit26 */
			{19146,58,0}, /* core3 raw_pc bit27 */
			{19144,58,0}, /* core3 raw_pc bit28 */
			{19142,58,0}, /* core3 raw_pc bit29 */
			{19140,58,0}, /* core3 raw_pc bit30 */
			{18854,58,0}, /* core3 raw_pc bit31 */
			{18852,58,0}, /* core3 raw_pc bit32 */
			{18850,58,0}, /* core3 raw_pc bit33 */
			{18848,58,0}, /* core3 raw_pc bit34 */
			{18862,58,0}, /* core3 raw_pc bit35 */
			{18860,58,0}, /* core3 raw_pc bit36 */
			{18858,58,0}, /* core3 raw_pc bit37 */
			{18856,58,0}, /* core3 raw_pc bit38 */
			{18846,58,0}, /* core3 raw_pc bit39 */
			{18844,58,0}, /* core3 raw_pc bit40 */
			{18842,58,0}, /* core3 raw_pc bit41 */
			{18840,58,0}, /* core3 raw_pc bit42 */
			{18838,58,0}, /* core3 raw_pc bit43 */
			{18836,58,0}, /* core3 raw_pc bit44 */
			{18834,58,0}, /* core3 raw_pc bit45 */
			{18832,58,0}, /* core3 raw_pc bit46 */
			{11668,59,0}, /* core3 raw_pc bit47 */
			{20380,59,0}, /* core3 raw_pc bit48 */
			{20378,59,0}, /* core3 raw_pc bit49 */
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
			{12108,59,0}, /* core3 pc_iss bit0 */
			{12106,59,0}, /* core3 pc_iss bit1 */
			{12102,59,0}, /* core3 pc_iss bit2 */
			{20292,59,0}, /* core3 pc_iss bit3 */
			{20290,59,0}, /* core3 pc_iss bit4 */
			{20288,59,0}, /* core3 pc_iss bit5 */
			{20286,59,0}, /* core3 pc_iss bit6 */
			{12104,59,0}, /* core3 pc_iss bit7 */
			{20296,59,0}, /* core3 pc_iss bit8 */
			{20294,59,0}, /* core3 pc_iss bit9 */
			{20474,59,0}, /* core3 pc_iss bit10 */
			{20284,59,0}, /* core3 pc_iss bit11 */
			{20304,59,0}, /* core3 pc_iss bit12 */
			{20282,59,0}, /* core3 pc_iss bit13 */
			{20300,59,0}, /* core3 pc_iss bit14 */
			{20298,59,0}, /* core3 pc_iss bit15 */
			{20302,59,0}, /* core3 pc_iss bit16 */
			{20308,59,0}, /* core3 pc_iss bit17 */
			{20306,59,0}, /* core3 pc_iss bit18 */
			{20312,59,0}, /* core3 pc_iss bit19 */
			{20310,59,0}, /* core3 pc_iss bit20 */
			{20316,59,0}, /* core3 pc_iss bit21 */
			{20314,59,0}, /* core3 pc_iss bit22 */
			{20480,59,0}, /* core3 pc_iss bit23 */
			{20476,59,0}, /* core3 pc_iss bit24 */
			{20478,59,0}, /* core3 pc_iss bit25 */
			{20484,59,0}, /* core3 pc_iss bit26 */
			{20482,59,0}, /* core3 pc_iss bit27 */
			{20472,59,0}, /* core3 pc_iss bit28 */
			{20470,59,0}, /* core3 pc_iss bit29 */
			{20488,59,0}, /* core3 pc_iss bit30 */
			{20486,59,0}, /* core3 pc_iss bit31 */
			{19454,58,0}, /* core3 pc_iss bit32 */
			{20456,59,0}, /* core3 pc_iss bit33 */
			{20454,59,0}, /* core3 pc_iss bit34 */
			{20448,59,0}, /* core3 pc_iss bit35 */
			{20452,59,0}, /* core3 pc_iss bit36 */
			{20446,59,0}, /* core3 pc_iss bit37 */
			{20444,59,0}, /* core3 pc_iss bit38 */
			{20450,59,0}, /* core3 pc_iss bit39 */
			{20460,59,0}, /* core3 pc_iss bit40 */
			{20458,59,0}, /* core3 pc_iss bit41 */
			{20442,59,0}, /* core3 pc_iss bit42 */
			{20464,59,0}, /* core3 pc_iss bit43 */
			{20462,59,0}, /* core3 pc_iss bit44 */
			{19188,58,0}, /* core3 pc_iss bit45 */
			{19186,58,0}, /* core3 pc_iss bit46 */
			{19184,58,0}, /* core3 pc_iss bit47 */
			{19182,58,0}, /* core3 pc_iss bit48 */
			{19484,58,0}, /* core3 pc_iss bit49 */
			{19482,58,0}, /* core3 pc_iss bit50 */
			{19480,58,0}, /* core3 pc_iss bit51 */
			{19478,58,0}, /* core3 pc_iss bit52 */
			{19476,58,0}, /* core3 pc_iss bit53 */
			{19474,58,0}, /* core3 pc_iss bit54 */
			{19472,58,0}, /* core3 pc_iss bit55 */
			{19470,58,0}, /* core3 pc_iss bit56 */
			{19468,58,0}, /* core3 pc_iss bit57 */
			{19466,58,0}, /* core3 pc_iss bit58 */
			{19464,58,0}, /* core3 pc_iss bit59 */
			{19462,58,0}, /* core3 pc_iss bit60 */
			{19460,58,0}, /* core3 pc_iss bit61 */
			{19458,58,0}, /* core3 pc_iss bit62 */
			{19456,58,0}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{20352,59,0}, /* core3 full_pc_wr bit0 */
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
			{19404,58,0}, /* core3 full_pc_ex1 bit0 */
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
			{20280,59,0}, /* core3 full_pc_ex2 bit0 */
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
			{ 3944,60,0}, /* core3 return_Stack_pointer bit0 */
			{ 3948,60,0}, /* core3 return_Stack_pointer bit1 */
			{ 3942,60,0}, /* core3 return_Stack_pointer bit2 */
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
			{19558,60,0}, /* core3 return_Stack0 bit0 */
			{19550,60,0}, /* core3 return_Stack0 bit1 */
			{19548,60,0}, /* core3 return_Stack0 bit2 */
			{19546,60,0}, /* core3 return_Stack0 bit3 */
			{19544,60,0}, /* core3 return_Stack0 bit4 */
			{ 9376,60,0}, /* core3 return_Stack0 bit5 */
			{19502,60,0}, /* core3 return_Stack0 bit6 */
			{19500,60,0}, /* core3 return_Stack0 bit7 */
			{19498,60,0}, /* core3 return_Stack0 bit8 */
			{19496,60,0}, /* core3 return_Stack0 bit9 */
			{19478,60,0}, /* core3 return_Stack0 bit10 */
			{ 9374,60,0}, /* core3 return_Stack0 bit11 */
			{19476,60,0}, /* core3 return_Stack0 bit12 */
			{19474,60,0}, /* core3 return_Stack0 bit13 */
			{19472,60,0}, /* core3 return_Stack0 bit14 */
			{19470,60,0}, /* core3 return_Stack0 bit15 */
			{19468,60,0}, /* core3 return_Stack0 bit16 */
			{19466,60,0}, /* core3 return_Stack0 bit17 */
			{19464,60,0}, /* core3 return_Stack0 bit18 */
			{19486,60,0}, /* core3 return_Stack0 bit19 */
			{19484,60,0}, /* core3 return_Stack0 bit20 */
			{19482,60,0}, /* core3 return_Stack0 bit21 */
			{19480,60,0}, /* core3 return_Stack0 bit22 */
			{ 9384,60,0}, /* core3 return_Stack0 bit23 */
			{ 9382,60,0}, /* core3 return_Stack0 bit24 */
			{19556,60,0}, /* core3 return_Stack0 bit25 */
			{ 3830,60,0}, /* core3 return_Stack0 bit26 */
			{19554,60,0}, /* core3 return_Stack0 bit27 */
			{19552,60,0}, /* core3 return_Stack0 bit28 */
			{19542,60,0}, /* core3 return_Stack0 bit29 */
			{19540,60,0}, /* core3 return_Stack0 bit30 */
			{19538,60,0}, /* core3 return_Stack0 bit31 */
			{19536,60,0}, /* core3 return_Stack0 bit32 */
			{19534,60,0}, /* core3 return_Stack0 bit33 */
			{19532,60,0}, /* core3 return_Stack0 bit34 */
			{19530,60,0}, /* core3 return_Stack0 bit35 */
			{19528,60,0}, /* core3 return_Stack0 bit36 */
			{19526,60,0}, /* core3 return_Stack0 bit37 */
			{19524,60,0}, /* core3 return_Stack0 bit38 */
			{19522,60,0}, /* core3 return_Stack0 bit39 */
			{19520,60,0}, /* core3 return_Stack0 bit40 */
			{19518,60,0}, /* core3 return_Stack0 bit41 */
			{19516,60,0}, /* core3 return_Stack0 bit42 */
			{19514,60,0}, /* core3 return_Stack0 bit43 */
			{19512,60,0}, /* core3 return_Stack0 bit44 */
			{19510,60,0}, /* core3 return_Stack0 bit45 */
			{19508,60,0}, /* core3 return_Stack0 bit46 */
			{19506,60,0}, /* core3 return_Stack0 bit47 */
			{19504,60,0}, /* core3 return_Stack0 bit48 */
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
			{19566,60,0}, /* core3 return_Stack1 bit0 */
			{19574,60,0}, /* core3 return_Stack1 bit1 */
			{19572,60,0}, /* core3 return_Stack1 bit2 */
			{19570,60,0}, /* core3 return_Stack1 bit3 */
			{19568,60,0}, /* core3 return_Stack1 bit4 */
			{ 9380,60,0}, /* core3 return_Stack1 bit5 */
			{19494,60,0}, /* core3 return_Stack1 bit6 */
			{19492,60,0}, /* core3 return_Stack1 bit7 */
			{19490,60,0}, /* core3 return_Stack1 bit8 */
			{19488,60,0}, /* core3 return_Stack1 bit9 */
			{19462,60,0}, /* core3 return_Stack1 bit10 */
			{ 9378,60,0}, /* core3 return_Stack1 bit11 */
			{19460,60,0}, /* core3 return_Stack1 bit12 */
			{19458,60,0}, /* core3 return_Stack1 bit13 */
			{19456,60,0}, /* core3 return_Stack1 bit14 */
			{19204,60,0}, /* core3 return_Stack1 bit15 */
			{19202,60,0}, /* core3 return_Stack1 bit16 */
			{19200,60,0}, /* core3 return_Stack1 bit17 */
			{19198,60,0}, /* core3 return_Stack1 bit18 */
			{19188,60,0}, /* core3 return_Stack1 bit19 */
			{19186,60,0}, /* core3 return_Stack1 bit20 */
			{19184,60,0}, /* core3 return_Stack1 bit21 */
			{19182,60,0}, /* core3 return_Stack1 bit22 */
			{ 9388,60,0}, /* core3 return_Stack1 bit23 */
			{ 9386,60,0}, /* core3 return_Stack1 bit24 */
			{19564,60,0}, /* core3 return_Stack1 bit25 */
			{ 3828,60,0}, /* core3 return_Stack1 bit26 */
			{19562,60,0}, /* core3 return_Stack1 bit27 */
			{19560,60,0}, /* core3 return_Stack1 bit28 */
			{19164,60,0}, /* core3 return_Stack1 bit29 */
			{19162,60,0}, /* core3 return_Stack1 bit30 */
			{19160,60,0}, /* core3 return_Stack1 bit31 */
			{19158,60,0}, /* core3 return_Stack1 bit32 */
			{19124,60,0}, /* core3 return_Stack1 bit33 */
			{19122,60,0}, /* core3 return_Stack1 bit34 */
			{19120,60,0}, /* core3 return_Stack1 bit35 */
			{19118,60,0}, /* core3 return_Stack1 bit36 */
			{19116,60,0}, /* core3 return_Stack1 bit37 */
			{19114,60,0}, /* core3 return_Stack1 bit38 */
			{19112,60,0}, /* core3 return_Stack1 bit39 */
			{19110,60,0}, /* core3 return_Stack1 bit40 */
			{19076,60,0}, /* core3 return_Stack1 bit41 */
			{19074,60,0}, /* core3 return_Stack1 bit42 */
			{19072,60,0}, /* core3 return_Stack1 bit43 */
			{19070,60,0}, /* core3 return_Stack1 bit44 */
			{19068,60,0}, /* core3 return_Stack1 bit45 */
			{19066,60,0}, /* core3 return_Stack1 bit46 */
			{19064,60,0}, /* core3 return_Stack1 bit47 */
			{19062,60,0}, /* core3 return_Stack1 bit48 */
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
			{19372,60,0}, /* core3 return_Stack2 bit0 */
			{19370,60,0}, /* core3 return_Stack2 bit1 */
			{19368,60,0}, /* core3 return_Stack2 bit2 */
			{19366,60,0}, /* core3 return_Stack2 bit3 */
			{19060,60,0}, /* core3 return_Stack2 bit4 */
			{19058,60,0}, /* core3 return_Stack2 bit5 */
			{19056,60,0}, /* core3 return_Stack2 bit6 */
			{19054,60,0}, /* core3 return_Stack2 bit7 */
			{19196,60,0}, /* core3 return_Stack2 bit8 */
			{19194,60,0}, /* core3 return_Stack2 bit9 */
			{19192,60,0}, /* core3 return_Stack2 bit10 */
			{19190,60,0}, /* core3 return_Stack2 bit11 */
			{19260,60,0}, /* core3 return_Stack2 bit12 */
			{19258,60,0}, /* core3 return_Stack2 bit13 */
			{19256,60,0}, /* core3 return_Stack2 bit14 */
			{19254,60,0}, /* core3 return_Stack2 bit15 */
			{19244,60,0}, /* core3 return_Stack2 bit16 */
			{19242,60,0}, /* core3 return_Stack2 bit17 */
			{19240,60,0}, /* core3 return_Stack2 bit18 */
			{19238,60,0}, /* core3 return_Stack2 bit19 */
			{19308,60,0}, /* core3 return_Stack2 bit20 */
			{19306,60,0}, /* core3 return_Stack2 bit21 */
			{19304,60,0}, /* core3 return_Stack2 bit22 */
			{19302,60,0}, /* core3 return_Stack2 bit23 */
			{19340,60,0}, /* core3 return_Stack2 bit24 */
			{19338,60,0}, /* core3 return_Stack2 bit25 */
			{19336,60,0}, /* core3 return_Stack2 bit26 */
			{19334,60,0}, /* core3 return_Stack2 bit27 */
			{19404,60,0}, /* core3 return_Stack2 bit28 */
			{19402,60,0}, /* core3 return_Stack2 bit29 */
			{19400,60,0}, /* core3 return_Stack2 bit30 */
			{19398,60,0}, /* core3 return_Stack2 bit31 */
			{19140,60,0}, /* core3 return_Stack2 bit32 */
			{19138,60,0}, /* core3 return_Stack2 bit33 */
			{19136,60,0}, /* core3 return_Stack2 bit34 */
			{19134,60,0}, /* core3 return_Stack2 bit35 */
			{19420,60,0}, /* core3 return_Stack2 bit36 */
			{19418,60,0}, /* core3 return_Stack2 bit37 */
			{19416,60,0}, /* core3 return_Stack2 bit38 */
			{19414,60,0}, /* core3 return_Stack2 bit39 */
			{19100,60,0}, /* core3 return_Stack2 bit40 */
			{19098,60,0}, /* core3 return_Stack2 bit41 */
			{19096,60,0}, /* core3 return_Stack2 bit42 */
			{19094,60,0}, /* core3 return_Stack2 bit43 */
			{19044,60,0}, /* core3 return_Stack2 bit44 */
			{19042,60,0}, /* core3 return_Stack2 bit45 */
			{19040,60,0}, /* core3 return_Stack2 bit46 */
			{19038,60,0}, /* core3 return_Stack2 bit47 */
			{ 3838,60,0}, /* core3 return_Stack2 bit48 */
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
			{19380,60,0}, /* core3 return_Stack3 bit0 */
			{19378,60,0}, /* core3 return_Stack3 bit1 */
			{19376,60,0}, /* core3 return_Stack3 bit2 */
			{19374,60,0}, /* core3 return_Stack3 bit3 */
			{19180,60,0}, /* core3 return_Stack3 bit4 */
			{19178,60,0}, /* core3 return_Stack3 bit5 */
			{ 3836,60,0}, /* core3 return_Stack3 bit6 */
			{19176,60,0}, /* core3 return_Stack3 bit7 */
			{19174,60,0}, /* core3 return_Stack3 bit8 */
			{19276,60,0}, /* core3 return_Stack3 bit9 */
			{19274,60,0}, /* core3 return_Stack3 bit10 */
			{19272,60,0}, /* core3 return_Stack3 bit11 */
			{19270,60,0}, /* core3 return_Stack3 bit12 */
			{19252,60,0}, /* core3 return_Stack3 bit13 */
			{19250,60,0}, /* core3 return_Stack3 bit14 */
			{19248,60,0}, /* core3 return_Stack3 bit15 */
			{19246,60,0}, /* core3 return_Stack3 bit16 */
			{19268,60,0}, /* core3 return_Stack3 bit17 */
			{19266,60,0}, /* core3 return_Stack3 bit18 */
			{19264,60,0}, /* core3 return_Stack3 bit19 */
			{19262,60,0}, /* core3 return_Stack3 bit20 */
			{19324,60,0}, /* core3 return_Stack3 bit21 */
			{19322,60,0}, /* core3 return_Stack3 bit22 */
			{19320,60,0}, /* core3 return_Stack3 bit23 */
			{19318,60,0}, /* core3 return_Stack3 bit24 */
			{19356,60,0}, /* core3 return_Stack3 bit25 */
			{19354,60,0}, /* core3 return_Stack3 bit26 */
			{19352,60,0}, /* core3 return_Stack3 bit27 */
			{19350,60,0}, /* core3 return_Stack3 bit28 */
			{19412,60,0}, /* core3 return_Stack3 bit29 */
			{19410,60,0}, /* core3 return_Stack3 bit30 */
			{19408,60,0}, /* core3 return_Stack3 bit31 */
			{19406,60,0}, /* core3 return_Stack3 bit32 */
			{19436,60,0}, /* core3 return_Stack3 bit33 */
			{19434,60,0}, /* core3 return_Stack3 bit34 */
			{19432,60,0}, /* core3 return_Stack3 bit35 */
			{19430,60,0}, /* core3 return_Stack3 bit36 */
			{19428,60,0}, /* core3 return_Stack3 bit37 */
			{19426,60,0}, /* core3 return_Stack3 bit38 */
			{19424,60,0}, /* core3 return_Stack3 bit39 */
			{19422,60,0}, /* core3 return_Stack3 bit40 */
			{19084,60,0}, /* core3 return_Stack3 bit41 */
			{19082,60,0}, /* core3 return_Stack3 bit42 */
			{19080,60,0}, /* core3 return_Stack3 bit43 */
			{19078,60,0}, /* core3 return_Stack3 bit44 */
			{19036,60,0}, /* core3 return_Stack3 bit45 */
			{19034,60,0}, /* core3 return_Stack3 bit46 */
			{19032,60,0}, /* core3 return_Stack3 bit47 */
			{19030,60,0}, /* core3 return_Stack3 bit48 */
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
			{19388,60,0}, /* core3 return_Stack4 bit0 */
			{19386,60,0}, /* core3 return_Stack4 bit1 */
			{19384,60,0}, /* core3 return_Stack4 bit2 */
			{19382,60,0}, /* core3 return_Stack4 bit3 */
			{19052,60,0}, /* core3 return_Stack4 bit4 */
			{19050,60,0}, /* core3 return_Stack4 bit5 */
			{19048,60,0}, /* core3 return_Stack4 bit6 */
			{19046,60,0}, /* core3 return_Stack4 bit7 */
			{19292,60,0}, /* core3 return_Stack4 bit8 */
			{19290,60,0}, /* core3 return_Stack4 bit9 */
			{19288,60,0}, /* core3 return_Stack4 bit10 */
			{19286,60,0}, /* core3 return_Stack4 bit11 */
			{19236,60,0}, /* core3 return_Stack4 bit12 */
			{19234,60,0}, /* core3 return_Stack4 bit13 */
			{19232,60,0}, /* core3 return_Stack4 bit14 */
			{19230,60,0}, /* core3 return_Stack4 bit15 */
			{19228,60,0}, /* core3 return_Stack4 bit16 */
			{19226,60,0}, /* core3 return_Stack4 bit17 */
			{19224,60,0}, /* core3 return_Stack4 bit18 */
			{19222,60,0}, /* core3 return_Stack4 bit19 */
			{19316,60,0}, /* core3 return_Stack4 bit20 */
			{19314,60,0}, /* core3 return_Stack4 bit21 */
			{19312,60,0}, /* core3 return_Stack4 bit22 */
			{19310,60,0}, /* core3 return_Stack4 bit23 */
			{19332,60,0}, /* core3 return_Stack4 bit24 */
			{19330,60,0}, /* core3 return_Stack4 bit25 */
			{19328,60,0}, /* core3 return_Stack4 bit26 */
			{19326,60,0}, /* core3 return_Stack4 bit27 */
			{19396,60,0}, /* core3 return_Stack4 bit28 */
			{19394,60,0}, /* core3 return_Stack4 bit29 */
			{19392,60,0}, /* core3 return_Stack4 bit30 */
			{19390,60,0}, /* core3 return_Stack4 bit31 */
			{19452,60,0}, /* core3 return_Stack4 bit32 */
			{19450,60,0}, /* core3 return_Stack4 bit33 */
			{19448,60,0}, /* core3 return_Stack4 bit34 */
			{19446,60,0}, /* core3 return_Stack4 bit35 */
			{19444,60,0}, /* core3 return_Stack4 bit36 */
			{19442,60,0}, /* core3 return_Stack4 bit37 */
			{19440,60,0}, /* core3 return_Stack4 bit38 */
			{19438,60,0}, /* core3 return_Stack4 bit39 */
			{19108,60,0}, /* core3 return_Stack4 bit40 */
			{19106,60,0}, /* core3 return_Stack4 bit41 */
			{19104,60,0}, /* core3 return_Stack4 bit42 */
			{19102,60,0}, /* core3 return_Stack4 bit43 */
			{19028,60,0}, /* core3 return_Stack4 bit44 */
			{19026,60,0}, /* core3 return_Stack4 bit45 */
			{19024,60,0}, /* core3 return_Stack4 bit46 */
			{19022,60,0}, /* core3 return_Stack4 bit47 */
			{ 3832,60,0}, /* core3 return_Stack4 bit48 */
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
			{19364,60,0}, /* core3 return_Stack5 bit0 */
			{19362,60,0}, /* core3 return_Stack5 bit1 */
			{19360,60,0}, /* core3 return_Stack5 bit2 */
			{19358,60,0}, /* core3 return_Stack5 bit3 */
			{19172,60,0}, /* core3 return_Stack5 bit4 */
			{19170,60,0}, /* core3 return_Stack5 bit5 */
			{19168,60,0}, /* core3 return_Stack5 bit6 */
			{19166,60,0}, /* core3 return_Stack5 bit7 */
			{19284,60,0}, /* core3 return_Stack5 bit8 */
			{19282,60,0}, /* core3 return_Stack5 bit9 */
			{19280,60,0}, /* core3 return_Stack5 bit10 */
			{19278,60,0}, /* core3 return_Stack5 bit11 */
			{19212,60,0}, /* core3 return_Stack5 bit12 */
			{19210,60,0}, /* core3 return_Stack5 bit13 */
			{19208,60,0}, /* core3 return_Stack5 bit14 */
			{19206,60,0}, /* core3 return_Stack5 bit15 */
			{19220,60,0}, /* core3 return_Stack5 bit16 */
			{19218,60,0}, /* core3 return_Stack5 bit17 */
			{19216,60,0}, /* core3 return_Stack5 bit18 */
			{19214,60,0}, /* core3 return_Stack5 bit19 */
			{19300,60,0}, /* core3 return_Stack5 bit20 */
			{19298,60,0}, /* core3 return_Stack5 bit21 */
			{19296,60,0}, /* core3 return_Stack5 bit22 */
			{19294,60,0}, /* core3 return_Stack5 bit23 */
			{19348,60,0}, /* core3 return_Stack5 bit24 */
			{19346,60,0}, /* core3 return_Stack5 bit25 */
			{19344,60,0}, /* core3 return_Stack5 bit26 */
			{19342,60,0}, /* core3 return_Stack5 bit27 */
			{19156,60,0}, /* core3 return_Stack5 bit28 */
			{19154,60,0}, /* core3 return_Stack5 bit29 */
			{19152,60,0}, /* core3 return_Stack5 bit30 */
			{19150,60,0}, /* core3 return_Stack5 bit31 */
			{19132,60,0}, /* core3 return_Stack5 bit32 */
			{19130,60,0}, /* core3 return_Stack5 bit33 */
			{19128,60,0}, /* core3 return_Stack5 bit34 */
			{19126,60,0}, /* core3 return_Stack5 bit35 */
			{19148,60,0}, /* core3 return_Stack5 bit36 */
			{19146,60,0}, /* core3 return_Stack5 bit37 */
			{19144,60,0}, /* core3 return_Stack5 bit38 */
			{19142,60,0}, /* core3 return_Stack5 bit39 */
			{19092,60,0}, /* core3 return_Stack5 bit40 */
			{19090,60,0}, /* core3 return_Stack5 bit41 */
			{19088,60,0}, /* core3 return_Stack5 bit42 */
			{19086,60,0}, /* core3 return_Stack5 bit43 */
			{19020,60,0}, /* core3 return_Stack5 bit44 */
			{19018,60,0}, /* core3 return_Stack5 bit45 */
			{19016,60,0}, /* core3 return_Stack5 bit46 */
			{19014,60,0}, /* core3 return_Stack5 bit47 */
			{ 3834,60,0}, /* core3 return_Stack5 bit48 */
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
			{18762,60,0}, /* core3 return_Stack6 bit0 */
			{18760,60,0}, /* core3 return_Stack6 bit1 */
			{18758,60,0}, /* core3 return_Stack6 bit2 */
			{18756,60,0}, /* core3 return_Stack6 bit3 */
			{18738,60,0}, /* core3 return_Stack6 bit4 */
			{18858,60,0}, /* core3 return_Stack6 bit5 */
			{18736,60,0}, /* core3 return_Stack6 bit6 */
			{18856,60,0}, /* core3 return_Stack6 bit7 */
			{18734,60,0}, /* core3 return_Stack6 bit8 */
			{18732,60,0}, /* core3 return_Stack6 bit9 */
			{ 3824,60,0}, /* core3 return_Stack6 bit10 */
			{18854,60,0}, /* core3 return_Stack6 bit11 */
			{18852,60,0}, /* core3 return_Stack6 bit12 */
			{18818,60,0}, /* core3 return_Stack6 bit13 */
			{18816,60,0}, /* core3 return_Stack6 bit14 */
			{18814,60,0}, /* core3 return_Stack6 bit15 */
			{18812,60,0}, /* core3 return_Stack6 bit16 */
			{18826,60,0}, /* core3 return_Stack6 bit17 */
			{18824,60,0}, /* core3 return_Stack6 bit18 */
			{18822,60,0}, /* core3 return_Stack6 bit19 */
			{18820,60,0}, /* core3 return_Stack6 bit20 */
			{18794,60,0}, /* core3 return_Stack6 bit21 */
			{18792,60,0}, /* core3 return_Stack6 bit22 */
			{18790,60,0}, /* core3 return_Stack6 bit23 */
			{18788,60,0}, /* core3 return_Stack6 bit24 */
			{18786,60,0}, /* core3 return_Stack6 bit25 */
			{18784,60,0}, /* core3 return_Stack6 bit26 */
			{18782,60,0}, /* core3 return_Stack6 bit27 */
			{18780,60,0}, /* core3 return_Stack6 bit28 */
			{18746,60,0}, /* core3 return_Stack6 bit29 */
			{18744,60,0}, /* core3 return_Stack6 bit30 */
			{18742,60,0}, /* core3 return_Stack6 bit31 */
			{18740,60,0}, /* core3 return_Stack6 bit32 */
			{18986,60,0}, /* core3 return_Stack6 bit33 */
			{18984,60,0}, /* core3 return_Stack6 bit34 */
			{18982,60,0}, /* core3 return_Stack6 bit35 */
			{18980,60,0}, /* core3 return_Stack6 bit36 */
			{18978,60,0}, /* core3 return_Stack6 bit37 */
			{18976,60,0}, /* core3 return_Stack6 bit38 */
			{18974,60,0}, /* core3 return_Stack6 bit39 */
			{18972,60,0}, /* core3 return_Stack6 bit40 */
			{18946,60,0}, /* core3 return_Stack6 bit41 */
			{18944,60,0}, /* core3 return_Stack6 bit42 */
			{18942,60,0}, /* core3 return_Stack6 bit43 */
			{18940,60,0}, /* core3 return_Stack6 bit44 */
			{18730,60,0}, /* core3 return_Stack6 bit45 */
			{18728,60,0}, /* core3 return_Stack6 bit46 */
			{18726,60,0}, /* core3 return_Stack6 bit47 */
			{18724,60,0}, /* core3 return_Stack6 bit48 */
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
			{18770,60,0}, /* core3 return_Stack7 bit0 */
			{18768,60,0}, /* core3 return_Stack7 bit1 */
			{18766,60,0}, /* core3 return_Stack7 bit2 */
			{18764,60,0}, /* core3 return_Stack7 bit3 */
			{18810,60,0}, /* core3 return_Stack7 bit4 */
			{18850,60,0}, /* core3 return_Stack7 bit5 */
			{18808,60,0}, /* core3 return_Stack7 bit6 */
			{18848,60,0}, /* core3 return_Stack7 bit7 */
			{18806,60,0}, /* core3 return_Stack7 bit8 */
			{18804,60,0}, /* core3 return_Stack7 bit9 */
			{ 3826,60,0}, /* core3 return_Stack7 bit10 */
			{18846,60,0}, /* core3 return_Stack7 bit11 */
			{18844,60,0}, /* core3 return_Stack7 bit12 */
			{18834,60,0}, /* core3 return_Stack7 bit13 */
			{18832,60,0}, /* core3 return_Stack7 bit14 */
			{18830,60,0}, /* core3 return_Stack7 bit15 */
			{18828,60,0}, /* core3 return_Stack7 bit16 */
			{18842,60,0}, /* core3 return_Stack7 bit17 */
			{18840,60,0}, /* core3 return_Stack7 bit18 */
			{18838,60,0}, /* core3 return_Stack7 bit19 */
			{18836,60,0}, /* core3 return_Stack7 bit20 */
			{18802,60,0}, /* core3 return_Stack7 bit21 */
			{18800,60,0}, /* core3 return_Stack7 bit22 */
			{18798,60,0}, /* core3 return_Stack7 bit23 */
			{18796,60,0}, /* core3 return_Stack7 bit24 */
			{18778,60,0}, /* core3 return_Stack7 bit25 */
			{18776,60,0}, /* core3 return_Stack7 bit26 */
			{18774,60,0}, /* core3 return_Stack7 bit27 */
			{18772,60,0}, /* core3 return_Stack7 bit28 */
			{18754,60,0}, /* core3 return_Stack7 bit29 */
			{18752,60,0}, /* core3 return_Stack7 bit30 */
			{18750,60,0}, /* core3 return_Stack7 bit31 */
			{18748,60,0}, /* core3 return_Stack7 bit32 */
			{18970,60,0}, /* core3 return_Stack7 bit33 */
			{18968,60,0}, /* core3 return_Stack7 bit34 */
			{18966,60,0}, /* core3 return_Stack7 bit35 */
			{18964,60,0}, /* core3 return_Stack7 bit36 */
			{18962,60,0}, /* core3 return_Stack7 bit37 */
			{18960,60,0}, /* core3 return_Stack7 bit38 */
			{18958,60,0}, /* core3 return_Stack7 bit39 */
			{18956,60,0}, /* core3 return_Stack7 bit40 */
			{18954,60,0}, /* core3 return_Stack7 bit41 */
			{18952,60,0}, /* core3 return_Stack7 bit42 */
			{18950,60,0}, /* core3 return_Stack7 bit43 */
			{18948,60,0}, /* core3 return_Stack7 bit44 */
			{18722,60,0}, /* core3 return_Stack7 bit45 */
			{18720,60,0}, /* core3 return_Stack7 bit46 */
			{18718,60,0}, /* core3 return_Stack7 bit47 */
			{18716,60,0}, /* core3 return_Stack7 bit48 */
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
	},
}; 

struct big_core_spec big_core[] = {
	{		/* core 4 */ 
	},
	{		/* core 5 */ 
	},
	{		/* core 6 */ 
	},
	{		/* core 7 */ 
	},
}; 
