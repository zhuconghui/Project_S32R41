################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/trace/subdir.mk
-include src/spt/subdir.mk
-include src/platform_setup/subdir.mk
-include src/os/subdir.mk
-include src/dsp/subdir.mk
-include src/cfg/src/subdir.mk
-include src/RTD/subdir.mk
-include src/IPCF/src/os/baremetal/subdir.mk
-include src/IPCF/src/hw/s32r41/subdir.mk
-include src/IPCF/src/common/subdir.mk
-include src/IPCF/config/S32R41/subdir.mk
-include src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
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
../../../bin/rsdk_offline_example_sa_gcc_S32R41_m7_debug.siz \


# All Target
all: ../../../bin/rsdk_offline_example_sa_gcc_S32R41_m7_debug.elf secondary-outputs

# Tool invocations
../../../bin/rsdk_offline_example_sa_gcc_S32R41_m7_debug.elf: $(OBJS) D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/RSDK_offline_example/project/S32R41/Project_Settings/Linker_Files/linker_ram_m7.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "../../../bin/rsdk_offline_example_sa_gcc_S32R41_m7_debug.elf" "@rsdk_offline_example_sa_gcc_S32R41_m7_debug.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

../../../bin/rsdk_offline_example_sa_gcc_S32R41_m7_debug.siz: ../../../bin/rsdk_offline_example_sa_gcc_S32R41_m7_debug.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley ../../../bin/rsdk_offline_example_sa_gcc_S32R41_m7_debug.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
