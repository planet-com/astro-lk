LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -Iplatform/$(PLATFORM)/include/platform
INCLUDES += -Iplatform/common/bootctrl

OBJS += $(LOCAL_DIR)/avb_cmdline.o
OBJS += $(LOCAL_DIR)/dm_verity.o

OBJS += $(LOCAL_DIR)/load_vfy_boot.o

ifeq ($(PRELOAD_PARTITION_SUPPORT), yes)
DEFINES += PRELOAD_PARTITION_SUPPORT
OBJS += $(LOCAL_DIR)/preload_partition.o
endif

OBJS += $(LOCAL_DIR)/avb_persist.o

