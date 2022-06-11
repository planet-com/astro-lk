LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += \
	-I$(LK_TOP_DIR)/include \
	-I$(LK_TOP_DIR)/platform/$(PLATFORM)/include \
	-I$(LK_TOP_DIR)/platform/common/include

OBJS += \
	$(LOCAL_DIR)/boot_menu.o
