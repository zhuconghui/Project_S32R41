# E.g. make release PLATFORM=S32R41
 
#set dummy values for TARGET, COMPILER, OSENV, to avoid errors in compilerdefs.mak
ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R41))
TARGET ?= a53
else ifeq ($(PLATFORM),SAF85XX)
TARGET ?= m7
endif
COMPILER ?= gcc
OSENV ?= sa

RSDK_PATH ?= ./../../..
-include $(RSDK_PATH)/compilerdefs.mak

XTENSA_CORE ?= spt_bbe32_vfpu_gold_r1p3
XTENSA_SYSTEM ?= $(EXE_PATH)$(DS_BINPATH)/BBE32/builds/RI-2021.7-win32/$(XTENSA_CORE)/config

export XTENSA_SYSTEM
export XTENSA_CORE


MODULE_ROOTPATH = ./..

BINDIR := $(MODULE_ROOTPATH)/bin
OBJDIR := $(MODULE_ROOTPATH)/obj
DBGOBJDIR  := $(MODULE_ROOTPATH)/obj_dbg
PREPROCDIR := $(MODULE_ROOTPATH)/preproc_only

LIB_PREFIX := librsdk_DSP_lal

SRCDIR     := $(MODULE_ROOTPATH)/source
	
SOURCES    := $(wildcard $(SRCDIR)/*.c)
OBJECTS    := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DBGOBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(DBGOBJDIR)/%.o)
PREPROCS   := $(SOURCES:$(SRCDIR)/%.c=$(PREPROCDIR)/%.ppc)

LIB    := $(BINDIR)/$(LIB_PREFIX).a
DBGLIB := $(BINDIR)/$(LIB_PREFIX)_debug.a

LIB_API_INCDIR := $(MODULE_ROOTPATH)/api
ALL_INCDIRS := $(LIB_API_INCDIR)
ALL_INCDIRS += $(MODULE_ROOTPATH)/include

ALL_H := $(wildcard $(addsuffix /*.h,$(ALL_INCDIRS)))

#DBGDEFINES := 
CCDEFINES += -D$(PLATFORM) 

BBE32_CFLAGS := -std=c99 -Wall -Wextra -Wconversion -c -fmessage-length=0 -Wcast-align -Wmissing-prototypes -Wmissing-declarations \
			   -Wimplicit-function-declaration -Wpointer-arith -Wunused -fno-unsafe-math-optimizations
BBE32_OPT_CFLAGS := -O3 -safety
BBE32_DBG_CFLAGS := -O0 -g -v -safety


CCINCLUDES := $(addprefix -I,$(ALL_INCDIRS))
CFLGS = $(BBE32_CFLAGS) $(CCDEFINES) $(CCINCLUDES)

.PHONY: all release debug module clean cleantmp cleanall cleanalltmp clean_module preproc

print-%:
	@echo $* = $($*)

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

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(BBE32CC) $(CFLGS) $(BBE32_OPT_CFLAGS) $< -o $@

$(DBGOBJECTS): $(DBGOBJDIR)/%.o : $(SRCDIR)/%.c
	$(BBE32CC) $(CFLGS) $(BBE32_DBG_CFLAGS) $< -o $@

$(PREPROCS): $(PREPROCDIR)/%.ppc : $(SRCDIR)/%.c $(ALL_H)
	$(BBE32CC) $(CFLGS) $(OPT_CFLAGS) $< -E > $@
	