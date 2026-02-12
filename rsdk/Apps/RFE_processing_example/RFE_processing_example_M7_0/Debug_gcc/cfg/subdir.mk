################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspaceS32DS.3.5/rsdk/platform_setup/config/IPCF/M7/S32R41/ipcf_Ip_Cfg.c 

OBJS += \
./cfg/ipcf_Ip_Cfg.o 

C_DEPS += \
./cfg/ipcf_Ip_Cfg.d 


# Each subdirectory must supply rules for building sources it contributes
cfg/ipcf_Ip_Cfg.o: D:/workspaceS32DS.3.5/rsdk/platform_setup/config/IPCF/M7/S32R41/ipcf_Ip_Cfg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@cfg/ipcf_Ip_Cfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


