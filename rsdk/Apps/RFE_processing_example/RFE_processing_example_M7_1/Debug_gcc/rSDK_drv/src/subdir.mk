################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/M7/interrupts_cm7.c \
D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/lin.c \
../rSDK_drv/src/rfeHwConfig.c \
../rSDK_drv/src/rfeHwGpio.c \
../rSDK_drv/src/rfeHwLink.c \
../rSDK_drv/src/rfeHwSpi.c \
../rSDK_drv/src/rfeHwStm.c \
D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/M7/rsdk_system_timer_cm7.c 

OBJS += \
./rSDK_drv/src/interrupts_cm7.o \
./rSDK_drv/src/lin.o \
./rSDK_drv/src/rfeHwConfig.o \
./rSDK_drv/src/rfeHwGpio.o \
./rSDK_drv/src/rfeHwLink.o \
./rSDK_drv/src/rfeHwSpi.o \
./rSDK_drv/src/rfeHwStm.o \
./rSDK_drv/src/rsdk_system_timer_cm7.o 

C_DEPS += \
./rSDK_drv/src/interrupts_cm7.d \
./rSDK_drv/src/lin.d \
./rSDK_drv/src/rfeHwConfig.d \
./rSDK_drv/src/rfeHwGpio.d \
./rSDK_drv/src/rfeHwLink.d \
./rSDK_drv/src/rfeHwSpi.d \
./rSDK_drv/src/rfeHwStm.d \
./rSDK_drv/src/rsdk_system_timer_cm7.d 


# Each subdirectory must supply rules for building sources it contributes
rSDK_drv/src/interrupts_cm7.o: D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/M7/interrupts_cm7.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@rSDK_drv/src/interrupts_cm7.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rSDK_drv/src/lin.o: D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/lin.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@rSDK_drv/src/lin.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rSDK_drv/src/%.o: ../rSDK_drv/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@rSDK_drv/src/rfeHwConfig.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rSDK_drv/src/rsdk_system_timer_cm7.o: D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/M7/rsdk_system_timer_cm7.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@rSDK_drv/src/rsdk_system_timer_cm7.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


