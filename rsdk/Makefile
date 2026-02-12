#Run make help for help instructions
#see compilerdefs.mak for paths to compilers

RFEDIR := RFE_abstract
CTEDIR := CTE/CTE_driver
CSI2DIR := CSI2/CSI2_driver
SPTDRVDIR := SPT/SPT_driver/build
SPTKRNDIR := SPT/SPT_kernels
BBE32ALGODIR := DSP/DSP_radar_bb_algos
BBE32DISPDIR := DSP/DSP_dispatcher
BBE32LALDIR := DSP/DSP_lal/build
TRACEDIR := Tools/Trace/build
TFTPCLIENTDIR := Tools/TFTP_client
PPCALGODIR := CPU_algos/PPC_algo
LAXDIR := LAX
CMODELDIR := Tools/C_model

RSDK_OFFLINE_EXAMPLE_DIR := Apps/RSDK_offline_example
MULTIRFEDIR := Apps/RSDK_Multi_RFE_example
BBE32DISPEXDIR := Apps/DSP_Dispatcher_example
CTE2LAXDIR := Apps/CTE_to_LAX_trigger
RFECAPDIR := Apps/RFECapture

EXIT_IF_ERROR ?= || exit 1
pjobs ?= 1

ifdef PLATFORM
  PLATFORMS := $(PLATFORM)
else
  PLATFORMS := S32R45 S32R41 SAF85XX SAF86XX
endif

define set_targets_var
$(if $(filter $(origin TARGET), undefined), \
    $(if $(filter $(1), S32R41 SAF85XX SAF86XX), \
        $(eval TARGETS := m7), \
        $(if $(filter $(1), S32R45), \
            $(eval TARGETS := a53) \
        ), \
    ), \
    $(eval TARGETS := $(TARGET)) \
)
endef

define run_makefiles_apps
$(if $(filter $(1), S32R41), \
    make print_mind_compiler_warns; \
    $(MAKE) -C $(BBE32DISPEXDIR)  $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
) \
$(if $(filter $(1), SAF85XX SAF86XX), \
    make print_mind_compiler_warns; \
) \
$(if $(filter $(1), S32R45), \
    $(MAKE) -C $(BBE32DISPEXDIR)  $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) $(EXIT_IF_ERROR); \
    $(MAKE) -C $(RSDK_OFFLINE_EXAMPLE_DIR) $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) TRACE_ENABLE=on $(EXIT_IF_ERROR); \
    $(MAKE) -C $(MULTIRFEDIR)_S32R45 $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
    $(MAKE) -C $(CTE2LAXDIR) $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
    $(MAKE) -C $(RFECAPDIR) $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
)
endef

#$(if condition,then-part[,else-part])

define run_makefiles_libs
$(if $(filter $(1), S32R41), \
  make print_mind_compiler_warns; \
  $(MAKE) -j$(pjobs) -C $(SPTKRNDIR) $@ PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
  $(MAKE) -j$(pjobs) -C $(BBE32ALGODIR) $@ PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
  $(MAKE) -j$(pjobs) -C $(BBE32DISPDIR) $@ PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
  $(MAKE) -j$(pjobs) -C $(BBE32LALDIR) $@ PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
) \
$(if $(filter $(1), SAF85XX), \
  make print_mind_compiler_warns; \
  $(MAKE) -j$(pjobs) -C $(SPTKRNDIR) $@ PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
  $(MAKE) -j$(pjobs) -C $(BBE32ALGODIR) $@ PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
  $(MAKE) -j$(pjobs) -C $(BBE32DISPDIR) $@ PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
  $(MAKE) -j$(pjobs) -C $(BBE32LALDIR) $@ PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
  $(MAKE) -j$(pjobs) -C $(CMODELDIR) -f Makefile_static_lib; \
) \
$(if $(filter $(1), SAF86XX), \
  make print_mind_compiler_warns; \
  $(MAKE) -j$(pjobs) -C $(BBE32ALGODIR) $@ PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
  $(MAKE) -j$(pjobs) -C $(BBE32DISPDIR) $@ PLATFORM=$(1) TARGET=$(2) $(EXIT_IF_ERROR); \
) \
$(if $(filter $(1), S32R45), \
  $(if $(filter $(4),debug), $(eval whatLaxBuild := development) $(eval whatLaxTarget := all), \
  $(if $(filter $(4),release), $(eval whatLaxBuild := development) $(eval whatLaxTarget := all), \
  $(if $(filter $(4),cleanall), $(eval whatLaxBuild := development) $(eval whatLaxTarget := clean), \
  $(if $(filter $(4),cleanalltmp), $(eval whatLaxBuild := development) $(eval whatLaxTarget := cleantmp) ) \
    ) \
    ) \
    ) \
  make print_mind_compiler_warns; \
  $(MAKE) -f Makefile_oal $@ PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR);\
  $(MAKE) -C $(CTEDIR) $(4) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
  $(MAKE) -C $(CSI2DIR) $@ PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
  $(MAKE) -C $(LAXDIR) $(whatLaxTarget) BUILD=$(whatLaxBuild) OS=linux PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
  $(MAKE) -C $(SPTDRVDIR) $@ PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
  $(MAKE) -C $(SPTKRNDIR) $@ PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
  $(MAKE) -C $(RFEDIR)    $@ PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) OSENV=linux $(EXIT_IF_ERROR); \
  $(MAKE) -C $(BBE32ALGODIR) $@ PLATFORM=$(1) $(EXIT_IF_ERROR); \
  $(MAKE) -C $(BBE32DISPDIR) $@ PLATFORM=$(1) $(EXIT_IF_ERROR); \
  make print_mind_not_compiler_warns; \
  $(MAKE) -C $(TRACEDIR) $(4) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
  $(MAKE) -C $(CMODELDIR) -f Makefile_static_lib ;
)
endef

define clean_app
$(if $(filter $(1), S32R41), \
) \
$(if $(filter $(1), SAF85XX SAF86XX), \
) \
$(if $(filter $(1), S32R45), \
    $(MAKE) -C $(BBE32DISPEXDIR)  $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) $(EXIT_IF_ERROR); \
    $(MAKE) -C $(RSDK_OFFLINE_EXAMPLE_DIR) $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
    $(MAKE) -C $(MULTIRFEDIR)_S32R45 $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
    $(MAKE) -C $(CTE2LAXDIR) $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
    $(MAKE) -C $(RFECAPDIR) $(if $(filter $(4),apps),cleanall,$(4)) PLATFORM=$(1) TARGET=$(2) COMPILER=$(3) $(EXIT_IF_ERROR); \
)
endef

define iterate_derivatives
    $(foreach p, $(PLATFORMS), \
        $(call set_targets_var, $(p)) \
        $(foreach t, $(TARGETS), \
            $(foreach c, $(COMPILERS), \
                $(call $(1),$(p),$(t),$(c),$(2)) \
            ) \
        ) \
    )
endef

ifdef COMPILER
  COMPILERS := $(COMPILER)
else
  COMPILERS := gcc diab
endif

.PHONY: all release debug apps cleanall cleanapps cleanalltmp help print_mind_compiler_warns print_mind_not_compiler_warns

all: release debug apps

help:
	@echo ""
	@echo "Call me like:"
	@echo "make OPTIONS apps - build all demos in Apps/ folder (after cleaning their output and tmp directories)"
	@echo "make OPTIONS cleanapps - recursively clean output and tmp directories of all demo apps"
	@echo "(internal use) make OPTIONS all - recursively build all libraries and apps"
	@echo "(internal use) make OPTIONS cleanall - recursively clean output and tmp directories of all libraries and apps"
	@echo "OPTIONS can be (if not specified, all combinations are built):"
	@echo "PLATFORM=S32R45 | S32R41 | SAF85XX | SAF86XX" 
	@echo "(depending on platform) TARGET=a53 | m7" 
	@echo "COMPILER=gcc"
	@echo "Specify compiler paths in cmd line with e.g. DS_BINPATH=\"...\" - see compilerdefs.mak"
	@echo "This makefile is made for use with Windows 10 Ubuntu native support. For other envinronments, like MINGW, use export EXE_PATH="\""C:"

apps: release debug
	@echo "Building Applications"
	$(call iterate_derivatives,run_makefiles_apps)

cleanalltmp:
	@echo "Cleanning temp $@ targets"
	$(call iterate_derivatives,run_makefiles_libs,$@)
	$(call iterate_derivatives,clean_app,"cleantmp")

cleanall: cleanapps
	@echo "Cleanning $@ targets"
	$(call iterate_derivatives,run_makefiles_libs,$@)

cleanapps:
	@echo "Cleanning $@ targets"
	$(call iterate_derivatives,clean_app,"clean")

release debug:
	@echo "Building $@ targets"
	$(call iterate_derivatives,run_makefiles_libs,$@)

#this target just outputs a message in the console (used by release script)
print_mind_compiler_warns:
	$(info mind_compiler_warns)

#this target just outputs a message in the console (used by release script)
print_mind_not_compiler_warns:
	$(info mind_not_compiler_warns)
