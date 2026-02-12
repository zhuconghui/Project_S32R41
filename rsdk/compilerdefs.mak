#do not use directly, meant to be included in a Makefile
#
# Following variables represent inputs (error is fired if they are not set a-priori):
#  PLATFORM (one of S32R45, S32R41, SAF85XX, SAF86XX)
#  TARGET (a53 for S32R45, m7 for S32R41, SAF8XXX)
#  COMPILER (one of gcc, diab)
#  OS: one of "sa" (for stand-alone, or no OS) or "linux"
#
# Following variables also represent inputs - defined with ?= so that can be overwritten from invocation command line:
#  EXE_PATH: system root path for finding the toolchain executables
#  TOOL_PATH: root path for constructing command-line toolchain arguments (can be different than EXE_PATH)
#  DS_BINPATH (cross-compiler-bin Design Studio folder)
#  CPU_TOOLCHAIN_BINPATH (cross-compiler-bin folder)
#  DIAB_BINPATH (win32-bin WindRiver compiler folder)
#  LAX_TOOLCHAIN_PATH (cross-compiler-LAX DS folder)
#
# Following variables represent outputs (later on, add to them using +=):
#  ARTIFACT_SUFFIX
#  CC, CFLAGS (gets a #define for PLATFORM), OPT_CFLAGS, DBG_CFLAGS - limitation: not used by any of LAX makefiles
#  AR, ARFLAGS - limitation: not used by any of LAX makefiles
#  SPTASM, SPTPREPROC, SPTPREPROCFLAGS, SPTASMFLAGS (gets a symbol for PLATFORM), SPTOPT_ASMFLAGS, SPTDBG_ASMFLAGS - SPT kernel build specific



#helper functions

#invoke with one param: name of linker command file
define LNK_FILECMD
$(if $(filter $(COMPILER),gcc), \
  -T $(1), \
  $(if $(filter $(COMPILER),diab), \
    $(1), \
    ERROR: LNK_FILECMD NOT DEFINED for this COMPILER \
  )\
)
endef

#invoke with one param: name of map file
define LNK_MAPCMD
$(if $(filter $(COMPILER),gcc), \
  -Xlinker -Map=$(1), \
  $(if $(filter $(COMPILER),diab), \
    -m6 -@O=$(1), \
    ERROR: LNK_FILECMD NOT DEFINED for this COMPILER \
  )\
)
endef

EXE_PATH ?= /c/
TOOL_PATH ?= C:

CFLAGS += -D$(PLATFORM) -std=c99 -Wall -fmessage-length=0 -ffunction-sections -fdata-sections -fvisibility=hidden -fsigned-char \
          -Werror=missing-prototypes -Werror=missing-declarations -Werror=implicit-function-declaration -fstrict-volatile-bitfields
OPT_CFLAGS := -O3 
DBG_CFLAGS := -O0 -g3

SPTPREPROCFLAGS := -D$(PLATFORM)
SPTASMFLAGS := --defsym $(PLATFORM)=1
SPTOPT_ASMFLAGS :=
SPTDBG_ASMFLAGS :=

ifndef PLATFORM
$(error Invoke $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST)) with PLATFORM = S32R45 or S32R41 or SAF85XX or SAF86XX)
endif

ifndef TARGET
$(error Invoke $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST)) with TARGET = a53 for S32R45 and m7 for S32R41 and SAF85XX and SAF86XX)
endif

ifndef COMPILER
$(error Invoke $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST)) with COMPILER=gcc or diab or linaro)
endif

ifndef OSENV
$(info Building with OSENV=sa)
OSENV := sa
ifeq ($(PLATFORM),S32R45)
$(info OSENV alternatives are: sa, linux)
endif
ifeq ($(PLATFORM),$(filter $(PLATFORM),S32R41 SAF85XX SAF86XX))
$(info OSENV alternatives are: sa)
endif
endif

ifeq ($(PLATFORM), $(filter $(PLATFORM), S32R45 S32R41 SAF85XX SAF86XX)) #any of S32R41/SAF85X/S32R45  
    DS_BINPATH ?= /NXP/S32DS.3.5/S32DS/build_tools/
endif

ifneq ($(filter %Microsoft MINGW% MSYS% %Cygwin, $(shell uname -a)), )
	BBE32_TOOLCHAIN_PATH := $(EXE_PATH)$(DS_BINPATH)/BBE32/tools/RI-2021.7-win32/XtensaTools/bin/
else
	BBE32_TOOLCHAIN_PATH := $(EXE_PATH)$(DS_BINPATH)/BBE32/tools/RI-2021.7-linux/XtensaTools/bin/
endif


ifeq ($(PLATFORM),S32R45)
    #guard against unsupported configurations:
    ifneq ($(TARGET), a53) 
        $(error For PLATFORM=S32R45 must define TARGET=a53)  
    endif
    ifneq ($(COMPILER), gcc)
        $(error For PLATFORM=S32R45 must define COMPILER=gcc)
    endif
    ifneq ($(OSENV), $(filter $(OSENV), sa linux ))
        $(error For PLATFORM=S32R45 must define OSENV=sa|linux)
    endif

    #build for A53 core
    ifeq ($(OSENV),sa)
        CPU_TOOLCHAIN_BINPATH ?= $(EXE_PATH)$(DS_BINPATH)/gcc_v10.2/gcc-10.2-arm64-eabi/bin/aarch64-none-elf-
    else ifeq ($(OSENV), linux)
        UNAME_A := $(shell uname -a)
        ifneq ($(filter %Microsoft MINGW% MSYS% %Cygwin, $(UNAME_A)), )
            CPU_TOOLCHAIN_BINPATH ?= $(EXE_PATH)$(DS_BINPATH)/gcc_v10.2/gcc-10.2-arm64-linux/bin/aarch64-linux-gnu-
        else
            CPU_TOOLCHAIN_BINPATH ?= /mnt/disk1/kit/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
        endif
    else
        $(error Unsupported OSENV for PLATFORM=S32R45)
    endif
    SPTASMFLAGS += -a64 -I$(TOOL_PATH)$(DS_BINPATH)/SPT3/inc
    SPTASM := $(EXE_PATH)$(DS_BINPATH)/SPT3/bin/as-spt.exe
    SPTPREPROC := $(EXE_PATH)$(DS_BINPATH)/gcc_v10.2/gcc-10.2-arm64-linux/bin/aarch64-linux-gnu-cpp.exe
endif

ifeq ($(PLATFORM),S32R41)
    #guard against unsupported configurations:
    ifneq ($(TARGET), a53)
        ifneq ($(TARGET), m7)
            $(error For PLATFORM=S32R41 must define TARGET=a53 or m7)
        endif
    endif
    ifneq ($(COMPILER), gcc)
        $(error For PLATFORM=S32R41 must define COMPILER=gcc)
    endif
    ifneq ($(OSENV), $(filter $(OSENV), sa))
        $(error For PLATFORM=S32R41 must define OSENV=sa)
    endif

    #build for A53 core
    ifeq ($(OSENV),sa)
        ifeq ($(TARGET), a53)
            CPU_TOOLCHAIN_BINPATH ?= $(EXE_PATH)$(DS_BINPATH)/gcc_v9.2/gcc-9.2-arm64-eabi/bin/aarch64-none-elf-
        else
            CPU_TOOLCHAIN_BINPATH ?= $(EXE_PATH)$(DS_BINPATH)/gcc_v9.2/gcc-9.2-arm32-eabi/bin/arm-none-eabi-
            SYSROOT_NO_LIB ?= $(EXE_PATH)$(DS_BINPATH)/gcc_v9.2/gcc-9.2-arm32-eabi/arm-none-eabi/
        endif
    else
        $(error Unsupported OSENV for PLATFORM=S32R41)
    endif
    SPTASMFLAGS += -I$(TOOL_PATH)$(DS_BINPATH)/SPT3.5/inc
    SPTASM := $(EXE_PATH)$(DS_BINPATH)/SPT3.5/bin/as-spt.exe
    SPTPREPROC := $(EXE_PATH)$(DS_BINPATH)/gcc_v9.2/gcc-9.2-arm32-eabi/bin/arm-none-eabi-cpp.exe
endif

ifeq ($(PLATFORM),$(filter $(PLATFORM), SAF85XX SAF86XX))
    #guard against unsupported configurations:
    $(info Target is: $(TARGET))
    ifneq ($(TARGET),m7)
        $(error For PLATFORM = SAF85XX or SAF86XX must define TARGET=m7)
    endif
    ifneq ($(COMPILER), $(filter $(COMPILER), gcc ghs))
        $(error For PLATFORM=SAF85XX or SAF86XX must define COMPILER=gcc or ghs)
    endif
    ifneq ($(OSENV), $(filter $(OSENV), sa))
        $(error For PLATFORM=SAF85XX or SAF86XX must define OSENV=sa)
    endif

    #build for M7 core
    ifeq ($(OSENV),sa)
        CPU_TOOLCHAIN_BINPATH ?= $(EXE_PATH)$(DS_BINPATH)/gcc_v9.2/gcc-9.2-arm32-eabi/bin/arm-none-eabi-
    else
        $(error Unsupported OSENV for PLATFORM=SAF85XX or SAF86XX)
    endif
    SPTASMFLAGS += -I$(TOOL_PATH)$(DS_BINPATH)/SPT3.4/inc
    SPTASM := $(EXE_PATH)$(DS_BINPATH)/SPT3.4/bin/as-spt.exe
    SPTPREPROC := $(EXE_PATH)$(DS_BINPATH)/gcc_v9.2/gcc-9.2-arm32-eabi/bin/arm-none-eabi-cpp.exe
endif

ARFLAGS :=
LAX_TOOLCHAIN_PATH ?= $(EXE_PATH)/NXP/S32DS.3.5/S32DS/build_tools/LAX

ifeq ($(OSENV),sa) #build for stand-alone (bare metal) environment
    CC := $(CPU_TOOLCHAIN_BINPATH)gcc
    LD := $(CPU_TOOLCHAIN_BINPATH)gcc
    AR := $(CPU_TOOLCHAIN_BINPATH)ar
    ASM := $(CPU_TOOLCHAIN_BINPATH)gcc
    ifneq ($(filter %Microsoft MINGW% MSYS% %Cygwin, $(shell uname -a)), )
        CC := $(CC).exe
        LD := $(LD).exe
        AR := $(AR).exe
        ASM := $(ASM).exe
    endif
    ifeq ($(TARGET), a53)
        # A53
        CFLAGS += -march=armv8-a -mcpu=cortex-a53 -mtune=cortex-a53 -mstrict-align
    else
        # if not A53, assume M7
        CFLAGS += -mcpu=cortex-m7 --sysroot="$(SYSROOT_NO_LIB)newlib"
    endif
else ifeq ($(OSENV), linux) #build for linux user space
    KERNEL_DIR ?= /mnt/disk1/repos/fsl-auto-yocto-bsp/build_s32r45xsim/tmp/work/s32r45xsim-fsl-linux/linux-s32/4.19-r0/build
    # the below flags are necessary for WCS report; please don't remove it at least for releases
    CFLAGS += -fstack-usage -fdump-rtl-dfinish -D_GNU_SOURCE
    
    UNAME_A := $(shell uname -a)
    ifneq ($(filter %Microsoft MINGW% MSYS% %Cygwin, $(UNAME_A)),)
        CC := $(CPU_TOOLCHAIN_BINPATH)gcc.exe
        CPP := $(CPU_TOOLCHAIN_BINPATH)g++.exe
        LD := $(CPU_TOOLCHAIN_BINPATH)gcc.exe
        LDPP := $(CPU_TOOLCHAIN_BINPATH)g++.exe
        ASM := $(CPU_TOOLCHAIN_BINPATH)gcc.exe
        ASMPP := $(CPU_TOOLCHAIN_BINPATH)g++.exe
        AR := $(CPU_TOOLCHAIN_BINPATH)ar.exe
    else
        CC := $(CPU_TOOLCHAIN_BINPATH)gcc
        CPP := $(CPU_TOOLCHAIN_BINPATH)g++        
        LD := $(CPU_TOOLCHAIN_BINPATH)gcc
        LDPP := $(CPU_TOOLCHAIN_BINPATH)g++
        ASM := $(CPU_TOOLCHAIN_BINPATH)gcc
        ASMPP := $(CPU_TOOLCHAIN_BINPATH)g++
        AR := $(CPU_TOOLCHAIN_BINPATH)ar
    endif

    export CPU_TOOLCHAIN_BINPATH
    export CC
else
    $(error Unsupported OSENV)
endif

ifneq ($(filter %Microsoft MINGW% MSYS% %Cygwin, $(shell uname -a)), )
    LAXAR := $(LAX_TOOLCHAIN_PATH)/bin/it3a-ar.exe
    LAXCC := $(LAX_TOOLCHAIN_PATH)/bin/laxcc.exe
    BBE32CC := $(BBE32_TOOLCHAIN_PATH)/xt-clang.exe
    BBE32AR := $(BBE32_TOOLCHAIN_PATH)/xt-ar.exe
    BBE32LD := $(BBE32_TOOLCHAIN_PATH)/xt-clang.exe
else
    LAXAR := $(LAX_TOOLCHAIN_PATH)/bin/it3a-ar
    LAXCC := $(LAX_TOOLCHAIN_PATH)/bin/laxcc
    BBE32CC := $(BBE32_TOOLCHAIN_PATH)/xt-clang
    BBE32AR := $(BBE32_TOOLCHAIN_PATH)/xt-ar
    BBE32LD := $(BBE32_TOOLCHAIN_PATH)/xt-clang
endif

export LAX_TOOLCHAIN_PATH
export LAXAR
export LAXCC

ARTIFACT_SUFFIX := $(OSENV)_$(COMPILER)_$(PLATFORM)_$(TARGET)

export DS_BINPATH
