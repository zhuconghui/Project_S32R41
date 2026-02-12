################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/CDD_Spt.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Hw_Check.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Hw_Ctrl.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Internals.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Irq.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Irq_Config.c 

OBJS += \
./src/spt/CDD_Spt.o \
./src/spt/Spt_Hw_Check.o \
./src/spt/Spt_Hw_Ctrl.o \
./src/spt/Spt_Internals.o \
./src/spt/Spt_Irq.o \
./src/spt/Spt_Irq_Config.o 

C_DEPS += \
./src/spt/CDD_Spt.d \
./src/spt/Spt_Hw_Check.d \
./src/spt/Spt_Hw_Ctrl.d \
./src/spt/Spt_Internals.d \
./src/spt/Spt_Irq.d \
./src/spt/Spt_Irq_Config.d 


# Each subdirectory must supply rules for building sources it contributes
src/spt/CDD_Spt.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/CDD_Spt.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/spt/CDD_Spt.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/spt/Spt_Hw_Check.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Hw_Check.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/spt/Spt_Hw_Check.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/spt/Spt_Hw_Ctrl.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Hw_Ctrl.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/spt/Spt_Hw_Ctrl.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/spt/Spt_Internals.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Internals.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/spt/Spt_Internals.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/spt/Spt_Irq.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Irq.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/spt/Spt_Irq.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/spt/Spt_Irq_Config.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/SPT/SPT_driver/src/common/Spt_Irq_Config.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/spt/Spt_Irq_Config.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


