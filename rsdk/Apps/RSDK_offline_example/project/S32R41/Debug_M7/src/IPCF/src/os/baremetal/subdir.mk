################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/os/baremetal/ipc-os-baremetal.c 

OBJS += \
./src/IPCF/src/os/baremetal/ipc-os-baremetal.o 

C_DEPS += \
./src/IPCF/src/os/baremetal/ipc-os-baremetal.d 


# Each subdirectory must supply rules for building sources it contributes
src/IPCF/src/os/baremetal/ipc-os-baremetal.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/os/baremetal/ipc-os-baremetal.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/IPCF/src/os/baremetal/ipc-os-baremetal.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


