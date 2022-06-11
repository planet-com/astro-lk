LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)
INCLUDES += -I$(LOCAL_DIR)/libavb
INCLUDES += -I$(LOCAL_DIR)/libavb_user
INCLUDES += -Iplatform/$(PLATFORM)/include/platform

MODULES += $(LOCAL_DIR)/avb_hal
MODULES += $(LOCAL_DIR)/libavb
MODULES += $(LOCAL_DIR)/libavb_user

