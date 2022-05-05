###########################################################################
# Makefile for nv-kernel.o
###########################################################################

NV_MODULE_LOGGING_NAME ?= nvidia

VERSION_MK_DIR = ../../

include ../../utils.mk

include srcs.mk

# The source files for nv-kernel.o are all SRCS and SRCS_CXX defined in srcs.mk,
# and the NVIDIA ID string
ALL_SRCS = $(SRCS) $(SRCS_CXX)
ALL_SRCS += $(NVIDSTRING)

SRC_COMMON = ../common

CFLAGS += -include $(SRC_COMMON)/sdk/nvidia/inc/cpuopsys.h

CFLAGS += -I kernel/inc
CFLAGS += -I interface
CFLAGS += -I $(SRC_COMMON)/sdk/nvidia/inc
CFLAGS += -I arch/nvalloc/common/inc
CFLAGS += -I arch/nvalloc/common/inc/deprecated
CFLAGS += -I arch/nvalloc/unix/include
CFLAGS += -I inc
CFLAGS += -I inc/os
CFLAGS += -I $(SRC_COMMON)/shared/inc
CFLAGS += -I $(SRC_COMMON)/inc

CFLAGS += -I $(SRC_COMMON)/inc/swref/published

CFLAGS += -I generated
CFLAGS += -I $(SRC_COMMON)/amaplib/include
CFLAGS += -I $(SRC_COMMON)/dram_hal/include
CFLAGS += -I $(SRC_COMMON)/nvswitch/kernel/inc
CFLAGS += -I $(SRC_COMMON)/nvswitch/interface
CFLAGS += -I $(SRC_COMMON)/nvswitch/common/inc/
CFLAGS += -I $(SRC_COMMON)/inc/displayport
CFLAGS += -I $(SRC_COMMON)/nvlink/interface/
CFLAGS += -I src/mm/uvm/interface
CFLAGS += -I $(SRC_COMMON)/cyclestats
CFLAGS += -I inc/libraries
CFLAGS += -I src/libraries
CFLAGS += -I inc/kernel
CFLAGS += -I inc/physical

# XXX TODO: review which of these we need for the build

CFLAGS += -Werror-implicit-function-declaration
CFLAGS += -Wwrite-strings
#CFLAGS += -Werror
#CFLAGS += -Wformat
#CFLAGS += -Wreturn-type
#CFLAGS += -Wswitch
#CFLAGS += -Wno-multichar
#CFLAGS += -Wno-unused-local-typedefs
#CFLAGS += -Wchar-subscripts
#CFLAGS += -Wparentheses
#CFLAGS += -Wpointer-arith
#CFLAGS += -Wstack-usage=3584
#CFLAGS += -Wformat-overflow=1
#CFLAGS += -Wformat-truncation=0
CFLAGS += -fno-common
CFLAGS += -ffreestanding

ifeq ($(TARGET_ARCH),x86_64)
  CFLAGS += -msoft-float
  CFLAGS += -mno-red-zone
  CFLAGS += -mcmodel=kernel
  CFLAGS += -mno-mmx
  CFLAGS += -mno-sse
  CFLAGS += -mno-sse2
  CFLAGS += -mno-3dnow
  CFLAGS += -mindirect-branch=thunk-extern
  CFLAGS += -mindirect-branch-register
endif

ifeq ($(TARGET_ARCH),aarch64)
  CFLAGS += -mgeneral-regs-only
  CFLAGS += -march=armv8-a
  CFLAGS += -mstrict-align
endif

#CFLAGS += -ffunction-sections
#CFLAGS += -fdata-sections
#CFLAGS += -DDEVELOP
CFLAGS += -fno-pic

CFLAGS += -DGL_EXPERT
CFLAGS += -DNVPMAPI
CFLAGS += -DNVCONFIG_PROFILE=unix_global_internal_profile
CFLAGS += -D_LANGUAGE_C
CFLAGS += -D__NO_CTYPE
CFLAGS += -DNVRM
CFLAGS += -DLOCK_VAL_ENABLED=0
CFLAGS += -DPORT_ATOMIC_64_BIT_SUPPORTED=1
CFLAGS += -DPORT_IS_KERNEL_BUILD=1
CFLAGS += -DPORT_IS_CHECKED_BUILD=1
CFLAGS += -DPORT_MODULE_atomic=1
CFLAGS += -DPORT_MODULE_core=1
CFLAGS += -DPORT_MODULE_cpu=1
CFLAGS += -DPORT_MODULE_crypto=1
CFLAGS += -DPORT_MODULE_debug=1
CFLAGS += -DPORT_MODULE_memory=1
CFLAGS += -DPORT_MODULE_safe=1
CFLAGS += -DPORT_MODULE_string=1
CFLAGS += -DPORT_MODULE_sync=1
CFLAGS += -DPORT_MODULE_thread=1
CFLAGS += -DPORT_MODULE_util=1
CFLAGS += -DPORT_MODULE_example=0
CFLAGS += -DPORT_MODULE_mmio=0
CFLAGS += -DPORT_MODULE_time=0
CFLAGS += -DRS_STANDALONE=0
CFLAGS += -DRS_STANDALONE_TEST=0
CFLAGS += -DRS_COMPATABILITY_MODE=1
CFLAGS += -DRS_PROVIDES_API_STATE=0
CFLAGS += -DNV_CONTAINERS_NO_TEMPLATES

CFLAGS += -DNV_PRINTF_STRINGS_ALLOWED=1
CFLAGS += -DNV_ASSERT_FAILED_USES_STRINGS=1
CFLAGS += -DPORT_ASSERT_FAILED_USES_STRINGS=1

ifeq ($(DEBUG),1)
  CFLAGS += -gsplit-dwarf
endif

OBJS = $(call BUILD_OBJECT_LIST,$(ALL_SRCS))

# Define how to generate the NVIDIA ID string
$(eval $(call GENERATE_NVIDSTRING, \
  NVRM_ID, \
  UNIX Kernel Module, $(OBJS)))

# Define how to build each object file from the corresponding source file.
$(foreach src, $(ALL_SRCS), $(eval $(call DEFINE_OBJECT_RULE,TARGET,$(src))))

NV_KERNEL_O = $(OUTPUTDIR)/nv-kernel.o

.PNONY: all clean
all: $(NV_KERNEL_O)

$(NV_KERNEL_O): $(OBJS)
	$(call quiet_cmd,LD) -r -o $(NV_KERNEL_O) $(OBJS)
	$(call quiet_cmd,OBJCOPY) \
	  --localize-symbol=memset \
	  --localize-symbol=memcpy \
	  $@

clean:
	$(RM) -rf $(OUTPUTDIR)
