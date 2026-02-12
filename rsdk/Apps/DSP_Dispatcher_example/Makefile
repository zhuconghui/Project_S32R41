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

#path relative to make folder:
APP_ROOTPATH = .

BINDIR := $(APP_ROOTPATH)/bin
OBJDIR := ./obj
DBGOBJDIR := ./obj_dbg

ELF_NAME := DSP_Dispatcher_Example_$(PLATFORM)
ELF_DBG := $(BINDIR)/$(ELF_NAME)_debug.elf
ELF := $(BINDIR)/$(ELF_NAME).elf
LNK_MAP_DBG := $(BINDIR)/$(ELF_NAME)_debug.map
LNK_MAP := $(BINDIR)/$(ELF_NAME).map

ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R41))
IPCF_PATH ?= $(EXE_PATH)$(DS_BINPATH)/../software/PlatformSDK_S32R/IPCF_S32R41/src
IPCF_SOURCES := $(IPCF_PATH)/hw/s32r41
else ifeq ($(PLATFORM), $(filter $(PLATFORM), SAF85XX))
IPCF_PATH ?= $(EXE_PATH)$(DS_BINPATH)/../software/PlatformSDK_S32R/IPCF_SAF85XX/src
IPCF_SOURCES := $(IPCF_PATH)/hw/saf85xx
else ifeq ($(PLATFORM), $(filter $(PLATFORM), SAF86XX))
IPCF_PATH ?= $(EXE_PATH)$(DS_BINPATH)/../software/PlatformSDK_S32R/IPCF_SAF86XX/src
IPCF_SOURCES := $(IPCF_PATH)/hw/saf86xx
endif

SRCDIR				:= $(APP_ROOTPATH)/src
ifneq ($(PLATFORM), S32R45)
IPCF_SOURCES 		+= $(IPCF_PATH)/os/xos $(IPCF_PATH)/common $(APP_ROOTPATH)/../../platform_setup/config/IPCF/DSP/$(PLATFORM)
SRCDIR              += $(IPCF_SOURCES)
ifneq ($(PLATFORM), SAF86XX)
SRCDIR		  		+= $(APP_ROOTPATH)/../../DSP/DSP_lal/DSP_lal_demos/vectorAdd/source
endif
endif

SOURCES		  		:= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
ifneq ($(PLATFORM), SAF86XX)
SOURCES := $(filter-out ./src/app_csi2_tx_dma.c, $(SOURCES))
endif
STRIPPED_SOURCES 	:= $(notdir $(SOURCES))
OBJECTS		 		:= $(STRIPPED_SOURCES:%.c=$(OBJDIR)/%.o)
OBJECTS_DBG			:= $(STRIPPED_SOURCES:%.c=$(DBGOBJDIR)/%.o)

vpath %.c $(sort $(dir $(SOURCES)))

POSTBLD_IMG_SCRIPT := ../../Tools/Build/dsp_hex_file_gen.sh
POSTBLD_IMG_PATH := $(APP_ROOTPATH)/src/host_integration

LSP_DIR := $(APP_ROOTPATH)/src/linker/$(PLATFORM)/min-rt-local-rsdk

RSDK_API_INCDIR := $(RSDK_ROOTPATH)/api
ifeq ($(PLATFORM), S32R45)
INTERNAL_INCDIR := $(APP_ROOTPATH)/src $(APP_ROOTPATH)/src/host_integration
else
IPCF_INCDIR := $(IPCF_PATH)/common $(IPCF_PATH)/os $(IPCF_PATH)/hw $(APP_ROOTPATH)/../../platform_setup/config/IPCF/DSP/$(PLATFORM)
ifeq ($(PLATFORM),S32R41)
IPCF_INCDIR += $(IPCF_PATH)/hw/s32r41
else ifeq ($(PLATFORM),SAF85XX)
IPCF_INCDIR += $(IPCF_PATH)/hw/saf85xx
else ifeq ($(PLATFORM),SAF86XX)
IPCF_INCDIR += $(IPCF_PATH)/hw/saf86xx
endif
ifeq ($(PLATFORM),SAF86XX)
INTERNAL_INCDIR := $(APP_ROOTPATH)/src $(APP_ROOTPATH)/src/host_integration
else
INTERNAL_INCDIR := $(APP_ROOTPATH)/src $(APP_ROOTPATH)/src/host_integration $(APP_ROOTPATH)/../../DSP/DSP_lal/DSP_lal_demos/vectorAdd/include
endif
endif

LIBS_BIN_DBG := rsdk_DSP_radar_bb_algos_$(PLATFORM)_debug rsdk_DSP_dispatcher_$(PLATFORM)_debug
LIBS_BIN := rsdk_DSP_radar_bb_algos_$(PLATFORM) rsdk_DSP_dispatcher_$(PLATFORM)
LIBS_INCDIR := ../../DSP/DSP_radar_bb_algos ../../DSP/DSP_dispatcher

ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R41 SAF85XX))
LIBS_BIN_DBG += rsdk_DSP_lal_debug
LIBS_BIN +=  rsdk_DSP_lal
LIBS_INCDIR +=  ../../DSP/DSP_lal
endif

LIB_XOS := xos
LIB_XOS_OPT := xos-opt
LIBS_APIDIR := $(addsuffix /api,$(LIBS_INCDIR))
LIBS_INCLUD := $(addsuffix /include,$(LIBS_INCDIR))
LIBS_BINDIR := $(addsuffix /bin,$(LIBS_INCDIR))

ALL_INCDIRS := $(INTERNAL_INCDIR) $(LIBS_APIDIR) $(LIBS_INCLUD) $(RSDK_API_INCDIR)

ifneq ($(PLATFORM),S32R45)
ALL_INCDIRS += $(IPCF_INCDIR)
endif

ALL_H := $(wildcard $(addsuffix /*.h,$(ALL_INCDIRS))) $(wildcard $(addsuffix /*.inc,$(INTERNAL_INCDIR)))

DBGDEFINES := -DBBE32_DEBUG
CCDEFINES += -D$(PLATFORM)

BBE32_CFLAGS := -std=c99 -Wall -Wextra -Wconversion -c -fmessage-length=0 -Wcast-align -Wmissing-prototypes -Wmissing-declarations \
			   -Wimplicit-function-declaration -Wpointer-arith -Wunused
BBE32_OPT_CFLAGS := -O3 -safety
BBE32_DBG_CFLAGS := -O0 -g -safety

CCINCLUDES := $(addprefix -I,$(ALL_INCDIRS))
CFLGS = $(BBE32_CFLAGS) $(CCDEFINES) $(CCINCLUDES)

ifeq ($(PLATFORM),S32R41)
CFLGS += -Ds32r41 -DUSING_OS_XOS -DDISABLE_MCAL_INTERMODULE_ASR_CHECK -DIPCF_USING_STANDARD_LIBS -DCPU_BBE32 -DCPU_TYPE=CPU_TYPE_32 -DIPCF_TYPES
else ifeq ($(PLATFORM),SAF85XX)
CFLGS += -Dsaf85xx -DUSING_OS_XOS -DDISABLE_MCAL_INTERMODULE_ASR_CHECK -DIPCF_USING_STANDARD_LIBS -DCPU_BBE32 -DCPU_TYPE=CPU_TYPE_32 -DIPCF_TYPES
else ifeq ($(PLATFORM),SAF86XX)
CFLGS += -Dsaf86xx -DUSING_OS_XOS -DDISABLE_MCAL_INTERMODULE_ASR_CHECK -DIPCF_USING_STANDARD_LIBS -DCPU_BBE32 -DCPU_TYPE=CPU_TYPE_32 -DIPCF_TYPES
endif

LDFLAGS_DBG := -v $(addprefix -L,$(LIBS_BINDIR)) -mlsp=$(LSP_DIR) -Wl,-Map,$(LNK_MAP_DBG) $(addprefix -l,$(LIBS_BIN_DBG)) -l$(LIB_XOS)
LDFLAGS := -v $(addprefix -L,$(LIBS_BINDIR)) -mlsp=$(LSP_DIR) -Wl,-Map,$(LNK_MAP) $(addprefix -l,$(LIBS_BIN)) -l$(LIB_XOS_OPT)

.PHONY: all debug release clean cleantmp

all: release debug

release: $(OBJDIR) $(BINDIR) $(ELF)
	@echo Building $(ELF)

debug: $(DBGOBJDIR) $(BINDIR) $(ELF_DBG)
	@echo Building $(ELF_DBG)

cleantmp:
	if [ -d "./$(OBJDIR)" ];then     \
		rm -f $(OBJDIR)/*.*;\
		rmdir $(OBJDIR);\
	fi
	if [ -d "./$(DBGOBJDIR)" ];then     \
		rm -f $(DBGOBJDIR)/*.*;\
		rmdir $(DBGOBJDIR);\
	fi

clean: cleantmp
	if [ -d "./$(BINDIR)" ];then     \
		rm -f $(ELF) $(ELF_DBG) $(LNK_MAP) $(LNK_MAP_DBG);\
	fi
	if [ -d "./$(POSTBLD_IMG_PATH)" ];then\
		rm -f $(POSTBLD_IMG_PATH)/dsp_image_$(PLATFORM)_debug.c $(POSTBLD_IMG_PATH)/dsp_image_$(PLATFORM)_release.c;\
	fi

#print-<variable> target used for debug
print-%:
	@echo $* = $($*)

$(BINDIR):
	if [ ! -d "./$(BINDIR)" ];then     \
			mkdir -p $(BINDIR);           \
	fi

$(OBJDIR): $(BINDIR)
	if [ ! -d "./$(OBJDIR)" ];then     \
			mkdir -p $(OBJDIR);           \
	fi

$(DBGOBJDIR): $(BINDIR)
	if [ ! -d "./$(DBGOBJDIR)" ];then     \
			mkdir -p $(DBGOBJDIR);           \
	fi

$(OBJECTS): $(OBJDIR)/%.o : %.c
	$(BBE32CC) $(CFLGS) $(BBE32_OPT_CFLAGS) $< -o $@

$(OBJECTS_DBG): $(DBGOBJDIR)/%.o : %.c
	$(BBE32CC) $(CFLGS) $(BBE32_DBG_CFLAGS) $(DBGDEFINES) $< -o $@

$(ELF_DBG): $(OBJECTS_DBG)
#Attention: order of linker arguments matters. LDFLAGS must come last.
	$(BBE32LD) -o $@ $^ $(LDFLAGS_DBG)
	$(POSTBLD_IMG_SCRIPT) $(ELF_DBG) $(BBE32_TOOLCHAIN_PATH) dsp_image_$(PLATFORM)_debug.c $(PLATFORM) $(POSTBLD_IMG_PATH)

$(ELF): $(OBJECTS)
#Attention: order of linker arguments matters. LDFLAGS must come last.
	$(BBE32LD) -o $@ $^ $(LDFLAGS)
	$(POSTBLD_IMG_SCRIPT) $(ELF) $(BBE32_TOOLCHAIN_PATH) dsp_image_$(PLATFORM)_release.c $(PLATFORM) $(POSTBLD_IMG_PATH)
