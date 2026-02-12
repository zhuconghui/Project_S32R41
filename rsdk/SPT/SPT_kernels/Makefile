#SPT does not use a host compiler, nor does it care about platform targets, fake them!
COMPILER ?= gcc
ifeq ($(PLATFORM),S32R45)
TARGET ?= a53
else ifeq ($(PLATFORM), $(filter $(PLATFORM), SAF85XX S32R41))
TARGET ?= m7
else
TARGET ?= z7
endif
include ../../compilerdefs.mak

OBJDIR := ./obj$(ARTIFACT_SUFFIX)
DBGOBJDIR := ./obj$(ARTIFACT_SUFFIX)_dbg

BINDIR := ./bin
INTERNALINCDIR := ./include
ifeq ($(PLATFORM),S32R45)
    SRCDIR := ./src/SPT3/31 ./src/SPT3/31/extras
else ifeq ($(PLATFORM),S32R41)
    SRCDIR := ./src/SPT3/34_35/4ch ./src/SPT3/34_35/8ch ./src/SPT3/34_35/common
else ifeq ($(PLATFORM),SAF85XX)
    SRCDIR := ./src/SPT3/34_35/4ch ./src/SPT3/34_35/common
endif
SOURCES := $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.pspt))
STRIPPED_SOURCES := $(notdir $(SOURCES))
#some kernels do not apply to S32R45 platform
#ifeq ($(PLATFORM),S32R45)
#    STRIPPED_SOURCES := $(filter-out doppler_512smp_128crp_4ch_thread.pspt,$(STRIPPED_SOURCES))
#endif
OBJECTS  := $(STRIPPED_SOURCES:%.pspt=%.ospt)
DBGOBJECTS  := $(OBJECTS)
LIB_PREFIX := librsdk_SPT_kernels
LIB_SUFIX := $(COMPILER)_$(PLATFORM)

LIB := $(BINDIR)/$(LIB_PREFIX)_$(LIB_SUFIX).a
DBGLIB := $(BINDIR)/$(LIB_PREFIX)_offline_$(LIB_SUFIX).a

APIINCDIR := ./api
ALL_INCLUDES := $(INTERNALINCDIR) $(APIINCDIR)

ALL_H := $(wildcard $(addsuffix /*.h,$(ALL_INCLUDES)))
ALL_INC := $(wildcard $(addsuffix /*.inc,$(ALL_INCLUDES)))
SPTASMFLAGS +=  $(addprefix -I,$(ALL_INCLUDES))
SPTDBG_ASMFLAGS += --defsym ENABLE_SW_EVT_WAIT=1
SPTOPT_ASMFLAGS += --defsym ENABLE_CHIRP_ACQ_WAIT=1

#OPT_PREPROCDEFINES := -UENABLE_SW_EVT_WAIT -DENABLE_CHIRP_ACQ_WAIT
#DBG_PREPROCDEFINES := -DENABLE_SW_EVT_WAIT -UENABLE_CHIRP_ACQ_WAIT
PREPROCINCLUDES := $(addprefix -I,$(ALL_INCLUDES))

vpath %.pspt $(sort $(dir $(SOURCES)))

.PHONY: all release debug clean cleantmp cleanall cleanalltmp

all: release debug

release: $(OBJDIR) $(BINDIR) $(LIB)
	@echo Building $(BINDIR)/$(LIB) $(TARGET) release

debug: $(DBGOBJDIR) $(BINDIR) $(DBGLIB)
	@echo Building $(BINDIR)/$(LIB) $(TARGET) debug

cleanalltmp: cleantmp


cleantmp:
	if [ -d "./$(OBJDIR)" ];then     \
		rm -rf $(OBJDIR);\
	fi
	if [ -d "./$(DBGOBJDIR)" ];then     \
		rm -rf $(DBGOBJDIR);\
	fi

cleanall: clean


clean: cleantmp
	if [ -d "./$(BINDIR)" ];then    \
		rm -f $(LIB) $(DBGLIB);\
	fi

$(BINDIR):
	if [ ! -d "./$(BINDIR)" ];then     \
			mkdir -p $(BINDIR);           \
	fi

$(OBJDIR):
	if [ ! -d "./$(OBJDIR)" ];then     \
			mkdir -p $(OBJDIR);           \
	fi

$(DBGOBJDIR):
	if [ ! -d "./$(DBGOBJDIR)" ];then     \
			mkdir -p $(DBGOBJDIR);           \
	fi

.NOTPARALLEL:
$(LIB) : $(addprefix $(OBJDIR)/,$(OBJECTS))
	@$(AR) $(ARFLAGS) -r $@ $^

$(DBGLIB) : $(addprefix $(DBGOBJDIR)/,$(DBGOBJECTS))
	@$(AR) $(ARFLAGS) -r $@ $^

$(OBJDIR)/%.ospt : %.pspt
	@echo 'Invoking: SPT Preprocessor and SPT Assembler'
	$(SPTPREPROC) $(SPTPREPROCFLAGS) $(OPT_PREPROCDEFINES) $(PREPROCINCLUDES) -o $(OBJDIR)/$(basename $(notdir $<)).spt -std=c99 $< && \
	$(SPTASM) $(SPTASMFLAGS) $(SPTOPT_ASMFLAGS) $(OBJDIR)/$(basename $(notdir $<)).spt -o $@

$(DBGOBJDIR)/%.ospt : %.pspt
	@echo 'Invoking: SPT Preprocessor and SPT Assembler'
	$(SPTPREPROC) $(SPTPREPROCFLAGS) $(DBG_PREPROCDEFINES) $(PREPROCINCLUDES) -o $(DBGOBJDIR)/$(basename $(notdir $<)).spt -std=c99 $< && \
	$(SPTASM) $(SPTASMFLAGS) $(SPTDBG_ASMFLAGS) $(DBGOBJDIR)/$(basename $(notdir $<)).spt -o $@
