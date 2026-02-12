RSDK_ROOTPATH = ../..

#set dummy values for TARGET, COMPILER, OSENV, to avoid errors in compilerdefs.mak
ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R45))
TARGET ?= a53
else ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R41 SAF85XX SAF86XX))
TARGET ?= m7
endif
COMPILER ?= gcc
OSENV ?= sa
-include $(RSDK_ROOTPATH)/compilerdefs.mak

define set_bbe_tools_env
$(if $(filter $(PLATFORM), S32R45), \
	$(eval XTENSA_CORE := spt_v3_130717), \
	$(if $(filter $(PLATFORM), S32R41), \
		$(eval XTENSA_CORE := spt_bbe32_vfpu_gold_r1p3), \
		$(if $(filter $(PLATFORM), SAF85XX), \
			$(eval XTENSA_CORE := spt_bbe32_vfpu_gold_r1p3), \
			$(if $(filter $(PLATFORM), SAF86XX), \
				$(eval XTENSA_CORE := bbe32_saf86xx_pre3F) \
			) \
		) \
	) \
) \

$(eval XTENSA_SYSTEM := $(EXE_PATH)$(DS_BINPATH)/BBE32/builds/RI-2021.7-win32/$(XTENSA_CORE)/config)

export XTENSA_SYSTEM
export XTENSA_CORE

endef


ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R41))
IPCF_PATH ?= $(EXE_PATH)$(DS_BINPATH)/../software/PlatformSDK_S32R/IPCF_S32R41/src
else ifeq ($(PLATFORM), $(filter $(PLATFORM), SAF85XX))
IPCF_PATH ?= $(EXE_PATH)$(DS_BINPATH)/../software/PlatformSDK_S32R/IPCF_SAF85XX/src
else ifeq ($(PLATFORM), $(filter $(PLATFORM), SAF86XX))
IPCF_PATH ?= $(EXE_PATH)$(DS_BINPATH)/../software/PlatformSDK_S32R/IPCF_SAF86XX/src
endif

MODULE_ROOTPATH = .
TRACE_PATH = ../../Tools/Trace

BINDIR := $(MODULE_ROOTPATH)/bin
OBJDIR := ./obj
DBGOBJDIR := ./obj_dbg
PREPROCDIR := ./preproc_only

LIB_PREFIX := librsdk_DSP_dispatcher
LIB_SUFIX := $(PLATFORM)

SRCDIR := $(MODULE_ROOTPATH)/src

ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R41 SAF85XX SAF86XX))
SOURCES  := $(wildcard $(SRCDIR)/*.c) $(TRACE_PATH)/src/trace.c $(TRACE_PATH)/src/timer_platform.c $(TRACE_PATH)/src/trace_internals.c
else
SOURCES  := $(wildcard $(SRCDIR)/*.c)
endif

STRIPPED_SOURCES := $(notdir $(SOURCES))
OBJECTS  := $(addprefix $(OBJDIR)/,$(STRIPPED_SOURCES:%.c=%.o))
vpath %.c $(sort $(dir $(SOURCES)))
SOURCE_PATHS = $(sort $(dir $(SOURCES)))

DBGSOURCES := $(SOURCES)
PREPROCS   := $(addprefix $(PREPROCDIR)/,$(STRIPPED_SOURCES:%.c=%.ppc))

STRIPPED_DBGSOURCES := $(notdir $(DBGSOURCES))
DBGOBJECTS  := $(addprefix $(DBGOBJDIR)/,$(STRIPPED_DBGSOURCES:%.c=%.o))
vpath %.c $(sort $(dir $(DBGSOURCES)))

SRCDIR_COMMON := $(MODULE_ROOTPATH)/../DSP_common/src
SOURCES_COMMON  := $(wildcard $(SRCDIR_COMMON)/*.c)
OBJECTS_COMMON  := $(SOURCES_COMMON:$(SRCDIR_COMMON)/%.c=$(OBJDIR)/%.o)
DBGOBJECTS_COMMON  := $(SOURCES_COMMON:$(SRCDIR_COMMON)/%.c=$(DBGOBJDIR)/%.o)

LIB := $(BINDIR)/$(LIB_PREFIX)_$(LIB_SUFIX).a
DBGLIB := $(BINDIR)/$(LIB_PREFIX)_$(LIB_SUFIX)_debug.a

RSDK_API_INCDIR := $(RSDK_ROOTPATH)/api
INTERNAL_INCDIR := $(MODULE_ROOTPATH)/src
LIB_API_INCDIR := $(MODULE_ROOTPATH)/api
DSP_COMMON_INCDIR := $(MODULE_ROOTPATH)/../DSP_common/include

ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R41 SAF85XX SAF86XX))
IPCF_INCDIR := $(IPCF_PATH)/common
endif

PLATFORM_INCDIR := $(MODULE_ROOTPATH)/../../platform_setup/include/ARM/$(PLATFORM)

ALL_INCDIRS := $(LIB_API_INCDIR) $(INTERNAL_INCDIR) $(RSDK_API_INCDIR) $(DSP_COMMON_INCDIR) $(MODULE_ROOTPATH)/../DSP_host_driver/include $(PLATFORM_INCDIR) $(TRACE_PATH)/include $(TRACE_PATH)/api

ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R41 SAF85XX SAF86XX))
ALL_INCDIRS += $(IPCF_INCDIR)
endif

ALL_H := $(wildcard $(addsuffix /*.h,$(ALL_INCDIRS)))

CCDEFINES += -D$(PLATFORM)
DBGDEFINES := -DTRACE_ENABLE

ifeq ($(PLATFORM),S32R41)
CCDEFINES += -Ds32r41 -DUSING_OS_XOS -DCPU_BBE32 -DCPU_TYPE=CPU_TYPE_32 -DDISABLE_MCAL_INTERMODULE_ASR_CHECK -DIPCF_USED_IN_LIB
else ifeq ($(PLATFORM),SAF85XX)
CCDEFINES += -Dsaf85xx -DUSING_OS_XOS -DCPU_BBE32 -DCPU_TYPE=CPU_TYPE_32 -DDISABLE_MCAL_INTERMODULE_ASR_CHECK -DIPCF_USED_IN_LIB
else ifeq ($(PLATFORM),SAF86XX)
CCDEFINES += -DUSING_OS_XOS -DDISABLE_MCAL_INTERMODULE_ASR_CHECK -DIPCF_USED_IN_LIB -DCPU_BBE32
endif

BBE32_CFLAGS := -std=c99 -Wall -Wextra -Wconversion -c -fmessage-length=0 -Wcast-align -Wmissing-prototypes -Wmissing-declarations \
			   -Wimplicit-function-declaration -Wpointer-arith -Wunused
BBE32_OPT_CFLAGS := -O3 -safety
BBE32_DBG_CFLAGS := -O0 -g -safety $(DBGDEFINES)


CCINCLUDES := $(addprefix -I,$(ALL_INCDIRS))
CFLGS = $(BBE32_CFLAGS) $(CCDEFINES) $(CCINCLUDES)

.PHONY: all release debug module clean cleantmp cleanall cleanalltmp clean_module preproc setbbeenv

print-%:
	@echo $* = $($*)

all: release debug

setbbeenv:
	$(call set_bbe_tools_env)

release: setbbeenv $(OBJDIR) $(BINDIR) $(LIB)
	@echo Building $(LIB) $(TARGET) release

debug: setbbeenv $(DBGOBJDIR) $(BINDIR) $(DBGLIB)
	@echo Building $(DBGLIB) $(TARGET) debug

preproc: setbbeenv $(PREPROCDIR) $(PREPROCS)
	@echo Generating preproc files for target $(TARGET) in $(PREPROCDIR)

cleanalltmp: cleantmp

cleantmp:
	if [ -d "./$(OBJDIR)" ];then     \
		rm -f $(OBJDIR)/*.*;\
		rmdir $(OBJDIR);\
	fi
	if [ -d "./$(DBGOBJDIR)" ];then     \
		rm -f $(DBGOBJDIR)/*.*;\
		rmdir $(DBGOBJDIR);\
	fi
	if [ -d "./$(PREPROCDIR)" ];then     \
		rm -f $(PREPROCDIR)/*.*;\
		rmdir $(PREPROCDIR);\
	fi

cleanall: clean

clean: cleantmp
	if [ -d "./$(BINDIR)" ];then     \
		rm -f $(LIB) $(DBGLIB);\
	fi

$(BINDIR):
	if [ ! -d "./$(BINDIR)" ];then     \
			mkdir $(BINDIR);           \
	fi

$(OBJDIR):
	if [ ! -d "./$(OBJDIR)" ];then     \
			mkdir $(OBJDIR);           \
	fi

$(DBGOBJDIR):
	if [ ! -d "./$(DBGOBJDIR)" ];then     \
			mkdir $(DBGOBJDIR);           \
	fi

$(PREPROCDIR):
	if [ ! -d "./$(PREPROCDIR)" ];then     \
			mkdir $(PREPROCDIR);           \
	fi

$(LIB) : $(OBJECTS) $(OBJECTS_COMMON)
	@$(BBE32AR) $(ARFLAGS) -r $@ $^

$(DBGLIB) : $(DBGOBJECTS) $(DBGOBJECTS_COMMON)
	@$(BBE32AR) $(ARFLAGS) -r $@ $^

$(OBJECTS): $(OBJDIR)/%.o : %.c $(ALL_H)
	$(BBE32CC) $(CFLGS) $(BBE32_OPT_CFLAGS) $< -o $@

$(DBGOBJECTS): $(DBGOBJDIR)/%.o : %.c $(ALL_H)
	$(BBE32CC) $(CFLGS) $(BBE32_DBG_CFLAGS) $< -o $@

$(OBJECTS_COMMON): $(OBJDIR)/%.o : $(SRCDIR_COMMON)/%.c
	$(BBE32CC) $(CFLGS) $(BBE32_OPT_CFLAGS) $< -o $@

$(DBGOBJECTS_COMMON): $(DBGOBJDIR)/%.o : $(SRCDIR_COMMON)/%.c
	$(BBE32CC) $(CFLGS) $(BBE32_DBG_CFLAGS) $< -o $@

$(PREPROCS): $(PREPROCDIR)/%.ppc : %.c $(ALL_H)
	$(BBE32CC) $(CFLGS) $(OPT_CFLAGS) $< -E > $@
