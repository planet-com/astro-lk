LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -I$(LK_TOP_DIR)/platform/$(PLATFORM)/include

CFLAGS += -D$(PLATFORM)

OBJS += \
	$(LOCAL_DIR)/mt_musb.o \
	$(LOCAL_DIR)/mt_musb_qmu.o
