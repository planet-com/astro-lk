LOCAL_DIR := $(GET_LOCAL_DIR)
TARGET := k80_bsp
MODULES += app/mt_boot \
           dev/lcm
MTK_EMMC_SUPPORT = yes
DEFINES += MTK_NEW_COMBO_EMMC_SUPPORT
MTK_KERNEL_POWER_OFF_CHARGING = yes
MTK_LCM_PHYSICAL_ROTATION = 0
CUSTOM_LK_LCM = "otm9608_qhd_dsi_vdo"
MTK_SECURITY_SW_SUPPORT = yes
MTK_SEC_FASTBOOT_UNLOCK_SUPPORT = yes
MTK_VERIFIED_BOOT_SUPPORT = yes
BOOT_LOGO := qhd
#DEFINES += WITH_DEBUG_DCC=1
DEFINES += WITH_DEBUG_UART=1
#DEFINES += WITH_DEBUG_FBCON=1
#DEFINES += MACH_FPGA=y
#DEFINES += MACH_FPGA_NO_DISPLAY
TRUSTONIC_TEE_SUPPORT=no
MTK_GOOGLE_TRUSTY_SUPPORT=no
MTK_DM_VERITY_OFF = no
MTK_AB_OTA_UPDATER = yes
MTK_USERIMAGES_USE_F2FS = yes
