################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include stacks/tcpip/lwip/src/netif/ppp/polarssl/subdir.mk
-include stacks/tcpip/lwip/src/netif/ppp/subdir.mk
-include stacks/tcpip/lwip/src/netif/subdir.mk
-include stacks/tcpip/lwip/src/core/ipv6/subdir.mk
-include stacks/tcpip/lwip/src/core/ipv4/subdir.mk
-include stacks/tcpip/lwip/src/core/subdir.mk
-include stacks/tcpip/lwip/src/apps/tftp/subdir.mk
-include stacks/tcpip/lwip/src/apps/sntp/subdir.mk
-include stacks/tcpip/lwip/src/apps/snmp/subdir.mk
-include stacks/tcpip/lwip/src/apps/netbiosns/subdir.mk
-include stacks/tcpip/lwip/src/apps/mqtt/subdir.mk
-include stacks/tcpip/lwip/src/apps/mdns/subdir.mk
-include stacks/tcpip/lwip/src/apps/lwiperf/subdir.mk
-include stacks/tcpip/lwip/src/apps/http/subdir.mk
-include stacks/tcpip/lwip/src/api/subdir.mk
-include stacks/tcpip/code/ports/osif/rtd/subdir.mk
-include stacks/tcpip/code/ports/netif/gmacif/rtd/subdir.mk
-include stacks/tcpip/code/ports/OS/baremetal/subdir.mk
-include stacks/tcpip/code/apps/udpecho_raw/subdir.mk
-include stacks/tcpip/code/apps/udpecho/subdir.mk
-include stacks/tcpip/code/apps/tcpecho_raw/subdir.mk
-include stacks/tcpip/code/apps/tcpecho/subdir.mk
-include stacks/tcpip/code/apps/socket_examples/subdir.mk
-include stacks/tcpip/code/apps/snmp_private_mib/subdir.mk
-include stacks/tcpip/code/apps/shell/subdir.mk
-include stacks/tcpip/code/apps/rtp/subdir.mk
-include stacks/tcpip/code/apps/netio/subdir.mk
-include stacks/tcpip/code/apps/netif_shutdown/subdir.mk
-include stacks/tcpip/code/apps/httpserver/subdir.mk
-include stacks/tcpip/code/apps/chargen/subdir.mk
-include src/subdir.mk
-include rSDK_drv/src/subdir.mk
-include generate/src/subdir.mk
-include board/subdir.mk
-include RTD/src/subdir.mk
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
../bin/RFE_processing_example_gcc_S32R41_M7_1_debug.siz \


# All Target
all:
	$(MAKE) --no-print-directory pre-build
	$(MAKE) --no-print-directory main-build

# Main-build Target
main-build: ../bin/RFE_processing_example_gcc_S32R41_M7_1_debug.elf secondary-outputs

# Tool invocations
../bin/RFE_processing_example_gcc_S32R41_M7_1_debug.elf: $(OBJS) D:/workspaceS32DS.3.5/rsdk/Apps/RFE_processing_example/RFE_processing_example_M7_1/Project_Settings/Linker_Files/s32r41_m7_1_gcc.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "../bin/RFE_processing_example_gcc_S32R41_M7_1_debug.elf" "@RFE_processing_example_gcc_S32R41_M7_1_debug.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

../bin/RFE_processing_example_gcc_S32R41_M7_1_debug.siz: ../bin/RFE_processing_example_gcc_S32R41_M7_1_debug.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley ../bin/RFE_processing_example_gcc_S32R41_M7_1_debug.elf
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
