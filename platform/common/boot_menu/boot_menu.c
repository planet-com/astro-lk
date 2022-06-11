/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2019. All rights reserved.
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

*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

/*This file implements MTK boot menu.*/

#include <compiler.h>
#include <debug.h>
#include <err.h>
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mtk_key.h>
#include <platform/mt_gpt.h>
#include <string.h>
#include <sys/types.h>
#include <target/cust_key.h>
#include <video.h>

extern void cmdline_append(const char *append_string);
typedef void (*entry_cb)(void);

struct boot_menu {
	u8 boot_mode;
	const char *item_text;
	entry_cb callback;
};

//register the callback function
void ftrace_cb()
{
	cmdline_append("androidboot.boot_trace=1");
}

void kmemleak_cb()
{
	cmdline_append("kmemleak=on");
}

void initcall_cb()
{
	cmdline_append("initcall_debug=1 log_buf_len=4M");
}

struct boot_menu ui_entry[] = {
	{RECOVERY_BOOT,	"[Recovery    Mode]",            NULL},
	{FASTBOOT,      "[Fastboot    Mode]",            NULL},
	{NORMAL_BOOT,	"[Normal      Boot]",            NULL},
#if !defined(USER_LOAD) || defined(MTK_BUILD_ENHANCE_MENU)
	{NORMAL_BOOT,   "[Normal      Boot +ftrace]",    ftrace_cb},
	{NORMAL_BOOT,   "[Normal      kmemleak on]",     kmemleak_cb},
	{NORMAL_BOOT,   "[Normal      Boot +initcall]",  initcall_cb},
#endif
};

static void update_menu(unsigned int index) {
	#define LEN 100
	const char* title_msg = "Select Boot Mode:\n[VOLUME_UP to select.  VOLUME_DOWN is OK.]\n\n";
	char str_buf[LEN];
	unsigned int i, length;

	video_set_cursor(video_get_rows()/2, 0);
	video_printf(title_msg);

	for (i = 0; i < countof(ui_entry); i++) {
		memset(str_buf, 0, LEN);
		length = strlen(ui_entry[i].item_text);
		snprintf(str_buf, length+1, "%s", ui_entry[i].item_text);
		if (i == index) {
			dprintf(0, "Switch to %s mode.\n", str_buf);
			sprintf(str_buf+length, "     <<==\n");
		} else
			sprintf(str_buf+length, "         \n");
		video_printf(str_buf);
	}
}

void boot_menu_select() {
	//0=recovery mode          1=fastboot      2=normal boot
	//3=normal boot + ftrace   4=kmemleak on   5=Boot + initcall
	unsigned int select = 0;

	video_clean_screen();
	update_menu(0);

	while (1) {
		if (mtk_detect_key(MT65XX_MENU_SELECT_KEY)) { //VOL_UP
			select = (select + 1) % countof(ui_entry);
			update_menu(select);
			mdelay(300);
		} else if (mtk_detect_key(MT65XX_MENU_OK_KEY)) { //VOL_DOWN
			//use for OK;
			break;
		}
	}

	dprintf(0, "Boot mode:%s is selected!\n", ui_entry[select].item_text);
	g_boot_mode = ui_entry[select].boot_mode;

	if (ui_entry[select].callback)
		ui_entry[select].callback();

	video_set_cursor(video_get_rows() / 2 + 8, 0);
	video_clean_screen();

	return;
}
