LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)
INCLUDES += -Iplatform/$(PLATFORM)/include/platform
INCLUDES += -Iplatform/common/include

OBJS += $(LOCAL_DIR)/avb_hal.o

DEFINES += AVB_COMPILATION

