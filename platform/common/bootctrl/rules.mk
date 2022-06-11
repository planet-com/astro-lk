LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform
INCLUDES += -Iplatform/common/avb/

##############################################################################
# Check build type. (End)
##############################################################################

ifeq ($(MTK_AB_OTA_UPDATER),yes)
OBJS += $(LOCAL_DIR)/bootctrl_api.o
else
OBJS += $(LOCAL_DIR)/bootctrl_dummy_api.o
endif

