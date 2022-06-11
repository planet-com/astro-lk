LOCAL_PATH := $(call my-dir)
LK_ROOT_DIR := $$(pwd)
LK_CROSS_COMPILE := $(LK_ROOT_DIR)/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.9.1/bin/arm-linux-androideabi-

ifeq ($(strip $(MTK_LK_VERSION)),lk)

ifdef LK_PROJECT
    LK_DIR := $(LOCAL_PATH)

  ifeq ($(wildcard $(TARGET_PREBUILT_LK)),)

    ifeq ($(LK_CROSS_COMPILE),)
    ifeq ($(TARGET_ARCH), arm)
      LK_CROSS_COMPILE := $(LK_ROOT_DIR)/$(TARGET_TOOLS_PREFIX)
    else ifeq ($(TARGET_2ND_ARCH), arm)
      LK_CROSS_COMPILE := $(LK_ROOT_DIR)/$($(TARGET_2ND_ARCH_VAR_PREFIX)TARGET_TOOLS_PREFIX)
    endif
    endif

    LK_MAKE_DEPENDENCIES := $(shell find $(LK_DIR) -name .git -prune -o -type f | sort)
    LK_MAKE_DEPENDENCIES := $(filter-out %/.git %/.gitignore %/.gitattributes,$(LK_MAKE_DEPENDENCIES))

    LK_MODE :=
    include $(LOCAL_PATH)/build_lk.mk

    ifeq (yes,$(BOARD_BUILD_SBOOT_DIS))
      LK_MODE := _DEF_UNLOCK
      include $(LOCAL_PATH)/build_lk.mk
    endif

    ifeq (yes,$(BOARD_BUILD_ENHANCE_MENU))
      LK_MODE := _ENHANCE_MENU
      include $(LOCAL_PATH)/build_lk.mk
    endif

    ifeq (yes,$(BOARD_DEEP_GPT_UPDATE))
      LK_MODE := _DEEP_GPT_UPDATE
      include $(LOCAL_PATH)/build_lk.mk
    endif

    LK_MODE := _FES
    include $(LOCAL_PATH)/build_lk.mk

.PHONY: lk check-lk-config check-mtk-config
droid lk: check-lk-config
check-mtk-config: check-lk-config
check-lk-config:
ifneq (yes,$(strip $(DISABLE_MTK_CONFIG_CHECK)))
	python device/mediatek/build/build/tools/check_kernel_config.py -c $(MTK_TARGET_PROJECT_FOLDER)/ProjectConfig.mk -l $(LK_DIR)/project/$(LK_PROJECT).mk -p $(MTK_PROJECT_NAME)
else
	-python device/mediatek/build/build/tools/check_kernel_config.py -c $(MTK_TARGET_PROJECT_FOLDER)/ProjectConfig.mk -l $(LK_DIR)/project/$(LK_PROJECT).mk -p $(MTK_PROJECT_NAME)
endif

  else

    INSTALLED_LK_TARGET := $(PRODUCT_OUT)/lk.img
    INSTALLED_LOGO_TARGET := $(PRODUCT_OUT)/logo.bin


$(INSTALLED_LK_TARGET): $(TARGET_PREBUILT_LK) $(MTK_LK_DTB_TARGET)
	$(hide) mkdir -p $(dir $@)
	$(hide) cat $^ > $@

$(INSTALLED_LOGO_TARGET): $(dir $(TARGET_PREBUILT_LK))$(notdir $(INSTALLED_LOGO_TARGET))
	$(hide) mkdir -p $(dir $@)
	$(hide) cp -f $< $@

.PHONY: lk
droidcore lk: $(INSTALLED_LK_TARGET) $(INSTALLED_LOGO_TARGET)

  endif#TARGET_PREBUILT_LK

endif#LK_PROJECT

endif#MTK_LK_VERSION
