LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += -I$(LOCAL_DIR)/include
INCLUDES += -I$(LOCAL_DIR)/sysdeps/include

OBJS += \
	$(LOCAL_DIR)/sysdeps/libufdt_sysdeps_vendor.o \
	$(LOCAL_DIR)/ufdt_convert.o \
	$(LOCAL_DIR)/ufdt_node.o \
	$(LOCAL_DIR)/ufdt_node_pool.o \
	$(LOCAL_DIR)/ufdt_overlay.o \
	$(LOCAL_DIR)/ufdt_prop_dict.o
