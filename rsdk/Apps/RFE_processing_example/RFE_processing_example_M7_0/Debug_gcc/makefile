################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/spt/subdir.mk
-include src/rfe/subdir.mk
-include src/rSDKTools/subdir.mk
-include src/platform_setup/subdir.mk
-include src/ipcf/os/subdir.mk
-include src/ipcf/hw/subdir.mk
-include src/ipcf/common/subdir.mk
-include src/dsp/subdir.mk
-include src/csi2/subdir.mk
-include src/Startup_Code/subdir.mk
-include src/RTD/subdir.mk
-include src/subdir.mk
-include os/subdir.mk
-include cfg/src/subdir.mk
-include cfg/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
../bin/RFE_processing_example_gcc_S32R41_M7_0_debug.siz \


# All Target
all:
	$(MAKE) --no-print-directory pre-build
	$(MAKE) --no-print-directory main-build

# Main-build Target
main-build: ../bin/RFE_processing_example_gcc_S32R41_M7_0_debug.elf secondary-outputs

# Tool invocations
../bin/RFE_processing_example_gcc_S32R41_M7_0_debug.elf: $(OBJS) D:/workspaceS32DS.3.5/rsdk/Apps/RFE_processing_example/RFE_processing_example_M7_0/Project_Settings/Linker_Files/s32r41_m7_0_gcc.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "../bin/RFE_processing_example_gcc_S32R41_M7_0_debug.elf" "@RFE_processing_example_gcc_S32R41_M7_0_debug.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

../bin/RFE_processing_example_gcc_S32R41_M7_0_debug.siz: ../bin/RFE_processing_example_gcc_S32R41_M7_0_debug.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley ../bin/RFE_processing_example_gcc_S32R41_M7_0_debug.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

pre-build:
	-mkdir -p ../bin
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build pre-build

-include ../makefile.targets
