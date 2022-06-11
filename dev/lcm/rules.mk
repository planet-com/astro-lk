#
# Makefile for misc devices that really don't fit anywhere else.
#
LOCAL_DIR := $(GET_LOCAL_DIR)

LCM_DEFINES := $(shell echo $(CUSTOM_LK_LCM) | tr a-z A-Z)
DEFINES += $(foreach LCM,$(LCM_DEFINES),$(LCM))
DEFINES += MTK_LCM_PHYSICAL_ROTATION=\"$(MTK_LCM_PHYSICAL_ROTATION)\"
DEFINES += LCM_WIDTH=\"$(LCM_WIDTH)\"
DEFINES += LCM_HEIGHT=\"$(LCM_HEIGHT)\"

ifeq ($(PLATFORM), $(filter $(PLATFORM), mt6757 mt6763 mt6771 mt6765 mt6762 mt6779 mt6768 mt6785 mt6885 mt6873 mt6853 mt6833))
DEFINES += LCM_SET_DISPLAY_ON_DELAY=y
endif

LCM_LISTS := $(subst ",,$(CUSTOM_LK_LCM))

CUSTOM_ALPHA := k6885v1_64_alpha
CUSTOM_ALPHA_1 := k6873v1_64_alpha
CUSTOM_ALPHA_2 := k6853v1_64_alpha
ifneq (,$(findstring $(CUSTOM_ALPHA),$(CUSTOM_LK_LCM)))
OBJS += $(foreach LCM,$(LCM_LISTS),$(LOCAL_DIR)/$(CUSTOM_ALPHA)/$(subst $(CUSTOM_ALPHA)_,,$(LCM))/$(addsuffix .o, $(subst $(CUSTOM_ALPHA)_,,$(LCM))))
else ifneq (,$(findstring $(CUSTOM_ALPHA_1),$(CUSTOM_LK_LCM)))
OBJS += $(foreach LCM,$(LCM_LISTS),$(LOCAL_DIR)/$(CUSTOM_ALPHA_1)/$(subst $(CUSTOM_ALPHA_1)_,,$(LCM))/$(addsuffix .o, $(subst $(CUSTOM_ALPHA_1)_,,$(LCM))))
else ifneq (,$(findstring $(CUSTOM_ALPHA_2),$(CUSTOM_LK_LCM)))
OBJS += $(foreach LCM,$(LCM_LISTS),$(LOCAL_DIR)/$(CUSTOM_ALPHA_2)/$(subst $(CUSTOM_ALPHA_2)_,,$(LCM))/$(addsuffix .o, $(subst $(CUSTOM_ALPHA_2)_,,$(LCM))))
else
OBJS += $(foreach LCM,$(LCM_LISTS),$(LOCAL_DIR)/$(LCM)/$(addsuffix .o, $(LCM)))
endif

OBJS += $(LOCAL_DIR)/mt65xx_lcm_list.o \
		$(LOCAL_DIR)/lcm_common.o \
		$(LOCAL_DIR)/lcm_gpio.o \
		$(LOCAL_DIR)/lcm_i2c.o \
		$(LOCAL_DIR)/lcm_util.o \
		$(LOCAL_DIR)/lcm_pmic.o

INCLUDES += -I$(LOCAL_DIR)/inc

