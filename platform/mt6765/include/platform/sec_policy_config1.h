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

#ifndef _SEC_POLICY_CONFIG1_H_
#define _SEC_POLICY_CONFIG1_H_

/* sboot: disable, lock_state: lock */

/* download policy */
/* 0: permit download, 1: forbid download */
#define DL_DEFAULT_POLICY_1         1
#define DL_PL_POLICY_1              1
#define DL_LK_POLICY_1              1
#define DL_LOGO_POLICY_1            1
#define DL_BOOT_POLICY_1            1
#define DL_RECOVERY_POLICY_1        1
#define DL_SYSTEM_POLICY_1          1
#define DL_TEE1_POLICY_1            1
#define DL_TEE2_POLICY_1            1
#define DL_SCP1_POLICY_1            1
#define DL_SCP2_POLICY_1            1
#define DL_OEMKEYSTORE_POLICY_1     1
#define DL_KEYSTORE_POLICY_1        1
#define DL_USERDATA_POLICY_1        1
#define DL_MD1IMG_POLICY_1          1
#define DL_MD1DSP_POLICY_1          1
#define DL_MD1ARM7_POLICY_1         1
#define DL_MD3IMG_POLICY_1          1
#define DL_DTBO_POLICY_1            1

/* verify policy */
/* 0: skip verify, 1: need verify */
#define VERIFY_DEFAULT_POLICY_1     0
#define VERIFY_PL_POLICY_1          0
#define VERIFY_LK_POLICY_1          0
#define VERIFY_LOGO_POLICY_1        0
#define VERIFY_BOOT_POLICY_1        0
#define VERIFY_RECOVERY_POLICY_1    0
#define VERIFY_SYSTEM_POLICY_1      0
#define VERIFY_TEE1_POLICY_1        0
#define VERIFY_TEE2_POLICY_1        0
#define VERIFY_SCP1_POLICY_1        0
#define VERIFY_SCP2_POLICY_1        0
#define VERIFY_OEMKEYSTORE_POLICY_1 0
#define VERIFY_KEYSTORE_POLICY_1    0
#define VERIFY_USERDATA_POLICY_1    0
#define VERIFY_MD1IMG_POLICY_1      0
#define VERIFY_MD1DSP_POLICY_1      0
#define VERIFY_MD1ARM7_POLICY_1     0
#define VERIFY_MD3IMG_POLICY_1      0
#define VERIFY_DTBO_POLICY_1        0

/* bind to hash policy */
/* 0: skip bind, 1: bind to hash */
#define BIND_DEFAULT_POLICY_1       0
#define BIND_PL_POLICY_1            0
#define BIND_LK_POLICY_1            0
#define BIND_LOGO_POLICY_1          0
#define BIND_BOOT_POLICY_1          0
#define BIND_RECOVERY_POLICY_1      0
#define BIND_SYSTEM_POLICY_1        0
#define BIND_TEE1_POLICY_1          0
#define BIND_TEE2_POLICY_1          0
#define BIND_SCP1_POLICY_1          0
#define BIND_SCP2_POLICY_1          0
#define BIND_OEMKEYSTORE_POLICY_1   0
#define BIND_KEYSTORE_POLICY_1      0
#define BIND_USERDATA_POLICY_1      0
#define BIND_MD1IMG_POLICY_1        0
#define BIND_MD1DSP_POLICY_1        0
#define BIND_MD1ARM7_POLICY_1       0
#define BIND_MD3IMG_POLICY_1        0
#define BIND_DTBO_POLICY_1          0

/* create ap image policy */
#define DEFAULT_SEC_POLICY_1    CREATE_POLICY_ENTRY(BIND_DEFAULT_POLICY_1, VERIFY_DEFAULT_POLICY_1, DL_DEFAULT_POLICY_1)
#define PL_SEC_POLICY_1         CREATE_POLICY_ENTRY(BIND_PL_POLICY_1, VERIFY_PL_POLICY_1, DL_PL_POLICY_1)
#define LK_SEC_POLICY_1         CREATE_POLICY_ENTRY(BIND_LK_POLICY_1, VERIFY_LK_POLICY_1, DL_LK_POLICY_1)
#define LOGO_SEC_POLICY_1       CREATE_POLICY_ENTRY(BIND_LOGO_POLICY_1, VERIFY_LOGO_POLICY_1, DL_LOGO_POLICY_1)
#define BOOT_SEC_POLICY_1       CREATE_POLICY_ENTRY(BIND_BOOT_POLICY_1, VERIFY_BOOT_POLICY_1, DL_BOOT_POLICY_1)
#define RECOVERY_SEC_POLICY_1   CREATE_POLICY_ENTRY(BIND_RECOVERY_POLICY_1, VERIFY_RECOVERY_POLICY_1, DL_RECOVERY_POLICY_1)
#define SYSTEM_SEC_POLICY_1     CREATE_POLICY_ENTRY(BIND_SYSTEM_POLICY_1, VERIFY_SYSTEM_POLICY_1, DL_SYSTEM_POLICY_1)
#define TEE1_SEC_POLICY_1       CREATE_POLICY_ENTRY(BIND_TEE1_POLICY_1, VERIFY_TEE1_POLICY_1, DL_TEE1_POLICY_1)
#define TEE2_SEC_POLICY_1       CREATE_POLICY_ENTRY(BIND_TEE2_POLICY_1, VERIFY_TEE2_POLICY_1, DL_TEE2_POLICY_1)
#define SCP1_SEC_POLICY_1       CREATE_POLICY_ENTRY(BIND_SCP1_POLICY_1, VERIFY_SCP1_POLICY_1, DL_SCP1_POLICY_1)
#define SCP2_SEC_POLICY_1       CREATE_POLICY_ENTRY(BIND_SCP2_POLICY_1, VERIFY_SCP2_POLICY_1, DL_SCP2_POLICY_1)
#define OEMKEYSTORE_SEC_POLICY_1    CREATE_POLICY_ENTRY(BIND_OEMKEYSTORE_POLICY_1, VERIFY_OEMKEYSTORE_POLICY_1, DL_OEMKEYSTORE_POLICY_1)
#define KEYSTORE_SEC_POLICY_1   CREATE_POLICY_ENTRY(BIND_KEYSTORE_POLICY_1, VERIFY_KEYSTORE_POLICY_1, DL_KEYSTORE_POLICY_1)
#define USERDATA_SEC_POLICY_1   CREATE_POLICY_ENTRY(BIND_USERDATA_POLICY_1, VERIFY_USERDATA_POLICY_1, DL_USERDATA_POLICY_1)

/* create md image policy */
#define MD1IMG_SEC_POLICY_1     CREATE_POLICY_ENTRY(BIND_MD1IMG_POLICY_1, VERIFY_MD1IMG_POLICY_1, DL_MD1IMG_POLICY_1)
#define MD1DSP_SEC_POLICY_1     CREATE_POLICY_ENTRY(BIND_MD1DSP_POLICY_1, VERIFY_MD1DSP_POLICY_1, DL_MD1DSP_POLICY_1)
#define MD1ARM7_SEC_POLICY_1    CREATE_POLICY_ENTRY(BIND_MD1ARM7_POLICY_1, VERIFY_MD1ARM7_POLICY_1, DL_MD1ARM7_POLICY_1)
#define MD3IMG_SEC_POLICY_1     CREATE_POLICY_ENTRY(BIND_MD3IMG_POLICY_1, VERIFY_MD3IMG_POLICY_1, DL_MD3IMG_POLICY_1)

#define DTBO_SEC_POLICY_1       CREATE_POLICY_ENTRY(BIND_DTBO_POLICY_1, VERIFY_DTBO_POLICY_1, DL_DTBO_POLICY_1)


/* custom image security policy */
#define  DL_CUST1_POLICY_1          0
#define  VERIFY_CUST1_POLICY_1      0
#define  BIND_CUST1_POLICY_1        0

#define  DL_CUST2_POLICY_1          0
#define  VERIFY_CUST2_POLICY_1      0
#define  BIND_CUST2_POLICY_1        0

/* create custom image policy */
#define  CUST1_SEC_POLICY_1  CREATE_POLICY_ENTRY(BIND_CUST1_POLICY_1, VERIFY_CUST1_POLICY_1, DL_CUST1_POLICY_1)
#define  CUST2_SEC_POLICY_1  CREATE_POLICY_ENTRY(BIND_CUST2_POLICY_1, VERIFY_CUST2_POLICY_1, DL_CUST2_POLICY_1)

#endif