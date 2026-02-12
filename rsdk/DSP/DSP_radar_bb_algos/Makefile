RSDK_ROOTPATH = ../..
 
#set dummy values for TARGET, COMPILER, OSENV, to avoid errors in compilerdefs.mak
ifeq ($(PLATFORM),S32R45)
TARGET ?= a53
else ifeq ($(PLATFORM), $(filter $(PLATFORM), SAF85XX S32R41 SAF86XX))
TARGET ?= m7
endif
COMPILER ?= gcc
OSENV ?= sa
-include $(RSDK_ROOTPATH)/compilerdefs.mak

ifeq ($(PLATFORM), S32R45)
	XTENSA_CORE ?= spt_v3_130717
else ifeq ($(PLATFORM), $(filter $(PLATFORM), SAF85XX S32R41))
	XTENSA_CORE ?= spt_bbe32_vfpu_gold_r1p3
else
	XTENSA_CORE ?= bbe32_saf86xx_pre3F
endif


XTENSA_SYSTEM ?= $(EXE_PATH)$(DS_BINPATH)/BBE32/builds/RI-2021.7-win32/$(XTENSA_CORE)/config

export XTENSA_SYSTEM
export XTENSA_CORE


MODULE_ROOTPATH = .

BINDIR := $(MODULE_ROOTPATH)/bin
OBJDIR := ./obj
DBGOBJDIR := ./obj_dbg
PREPROCDIR := ./preproc_only

LIB_PREFIX := librsdk_DSP_radar_bb_algos
LIB_SUFIX := $(PLATFORM)
#RSDK_API_INCDIR := $(RSDK_ROOTPATH)/api
#INTERNALINCDIR := $(MODULE_ROOTPATH)/include

ifeq ($(PLATFORM), S32R45)
SRCDIR += $(MODULE_ROOTPATH)/src/S32R45
else ifeq ($(PLATFORM), $(filter $(PLATFORM), SAF85XX S32R41))
SRCDIR += $(MODULE_ROOTPATH)/src/S32R41_SAF8NXX/S32R41_SAF85XX
SRCDIR += $(MODULE_ROOTPATH)/src/S32R41_SAF8NXX/common
else ifeq ($(PLATFORM), SAF86XX)
SRCDIR += $(MODULE_ROOTPATH)/src/S32R41_SAF8NXX/common
SRCDIR += $(MODULE_ROOTPATH)/src/S32R41_SAF8NXX/SAF86XX
endif
SOURCES := $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c)) 
STRIPPED_SOURCES := $(notdir $(SOURCES))
OBJECTS  := $(STRIPPED_SOURCES:%.c=$(OBJDIR)/%.o)
DBGOBJECTS := $(STRIPPED_SOURCES:%.c=$(DBGOBJDIR)/%.o)
PREPROCS  := $(STRIPPED_SOURCES:%.c=$(PREPROCDIR)/%.ppc)

vpath %.c $(sort $(dir $(SOURCES)))

LIB := $(BINDIR)/$(LIB_PREFIX)_$(LIB_SUFIX).a
DBGLIB := $(BINDIR)/$(LIB_PREFIX)_$(LIB_SUFIX)_debug.a

LIB_API_INCDIR := $(MODULE_ROOTPATH)/api  ../../api
ALL_INCDIRS := $(LIB_API_INCDIR) $(MODULE_ROOTPATH)/inc $(MODULE_ROOTPATH)/../DSP_common/include

ALL_H := $(wildcard $(addsuffix /*.h,$(ALL_INCDIRS)))

#DBGDEFINES := 
CCDEFINES += -D$(PLATFORM) 

BBE32_CFLAGS := -std=c99 -Wall -Wextra -Wconversion -c -fmessage-length=0 -Wcast-align -Wmissing-prototypes -Wmissing-declarations \
			   -Wimplicit-function-declaration -Wpointer-arith -Wunused
BBE32_OPT_CFLAGS := -O3 -safety
ifeq ($(PLATFORM), SAF86XX)
BBE32_DBG_CFLAGS := -Os -g -safety
else
BBE32_DBG_CFLAGS := -O0 -g -safety
endif

CCINCLUDES := $(addprefix -I,$(ALL_INCDIRS))
CFLGS = $(BBE32_CFLAGS) $(CCDEFINES) $(CCINCLUDES)

.PHONY: all release debug module clean cleantmp cleanall cleanalltmp clean_module preproc

all: release debug

release: $(OBJDIR) $(BINDIR) $(LIB)
	@echo Building $(LIB) $(TARGET) release

debug: $(DBGOBJDIR) $(BINDIR) $(DBGLIB)
	@echo Building $(BINDIR)/$(LIB) $(TARGET) debug

preproc: $(PREPROCDIR) $(PREPROCS)
	@echo Generating preproc files for target $(TARGET) in $(PREPROCDIR)

cleanalltmp: cleantmp

cleantmp:
	if [ -d "./$(OBJDIR)" ];then     \
		rm -rf $(OBJDIR);\
	fi
	if [ -d "./$(DBGOBJDIR)" ];then     \
		rm -rf $(DBGOBJDIR);\
	fi
	if [ -d "./$(PREPROCDIR)" ];then     \
		rm -rf $(PREPROCDIR);\
	fi

cleanall: clean

clean: cleantmp
	if [ -d "./$(BINDIR)" ];then     \
		rm -f $(LIB) $(DBGLIB);		 \
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

$(LIB) : $(OBJECTS)
	@$(BBE32AR) $(ARFLAGS) -r $@ $^

$(DBGLIB) : $(DBGOBJECTS)
	@$(BBE32AR) $(ARFLAGS) -r $@ $^

$(OBJECTS): $(OBJDIR)/%.o : %.c
	$(BBE32CC) $(CFLGS) $(BBE32_OPT_CFLAGS) $< -o $@

$(DBGOBJECTS): $(DBGOBJDIR)/%.o : %.c
	$(BBE32CC) $(CFLGS) $(BBE32_DBG_CFLAGS) $< -o $@

$(PREPROCS): $(PREPROCDIR)/%.ppc : %.c $(ALL_H)
	$(BBE32CC) $(CFLGS) $(OPT_CFLAGS) $< -E > $@
