################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspaceS32DS.3.5/rsdk/CSI2/CSI2_driver/src/low_level/CDD_Csi2.c \
D:/workspaceS32DS.3.5/rsdk/CSI2/CSI2_driver/src/low_level/Csi2_Irq.c \
D:/workspaceS32DS.3.5/rsdk/CSI2/CSI2_driver/src/low_level/Csi2_Irq_Handlers.c 

OBJS += \
./src/csi2/CDD_Csi2.o \
./src/csi2/Csi2_Irq.o \
./src/csi2/Csi2_Irq_Handlers.o 

C_DEPS += \
./src/csi2/CDD_Csi2.d \
./src/csi2/Csi2_Irq.d \
./src/csi2/Csi2_Irq_Handlers.d 


# Each subdirectory must supply rules for building sources it contributes
src/csi2/CDD_Csi2.o: D:/workspaceS32DS.3.5/rsdk/CSI2/CSI2_driver/src/low_level/CDD_Csi2.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/csi2/CDD_Csi2.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/csi2/Csi2_Irq.o: D:/workspaceS32DS.3.5/rsdk/CSI2/CSI2_driver/src/low_level/Csi2_Irq.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/csi2/Csi2_Irq.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/csi2/Csi2_Irq_Handlers.o: D:/workspaceS32DS.3.5/rsdk/CSI2/CSI2_driver/src/low_level/Csi2_Irq_Handlers.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/csi2/Csi2_Irq_Handlers.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


