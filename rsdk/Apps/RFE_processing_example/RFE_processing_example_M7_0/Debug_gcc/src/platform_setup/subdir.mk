################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/M7/interrupts_cm7.c \
D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/S32R41/platform_setup_rtd.c 

OBJS += \
./src/platform_setup/interrupts_cm7.o \
./src/platform_setup/platform_setup_rtd.o 

C_DEPS += \
./src/platform_setup/interrupts_cm7.d \
./src/platform_setup/platform_setup_rtd.d 


# Each subdirectory must supply rules for building sources it contributes
src/platform_setup/interrupts_cm7.o: D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/M7/interrupts_cm7.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/platform_setup/interrupts_cm7.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/platform_setup/platform_setup_rtd.o: D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/S32R41/platform_setup_rtd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/platform_setup/platform_setup_rtd.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


