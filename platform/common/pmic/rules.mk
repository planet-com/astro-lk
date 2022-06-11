LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -Iplatform/common/include
INCLUDES += -Iplatform/$(PLATFORM)/include

OBJS += $(LOCAL_DIR)/pmic_common.o
