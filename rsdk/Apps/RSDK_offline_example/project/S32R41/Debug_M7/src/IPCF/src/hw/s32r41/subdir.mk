################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/hw/s32r41/ipc-hw-s32r41.c 

OBJS += \
./src/IPCF/src/hw/s32r41/ipc-hw-s32r41.o 

C_DEPS += \
./src/IPCF/src/hw/s32r41/ipc-hw-s32r41.d 


# Each subdirectory must supply rules for building sources it contributes
src/IPCF/src/hw/s32r41/ipc-hw-s32r41.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/hw/s32r41/ipc-hw-s32r41.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/IPCF/src/hw/s32r41/ipc-hw-s32r41.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


