################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_API/src/CDD/CDD_Rfe.c \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_API/src/CDD/CDD_Rfe_Irq.c \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/src/rfe_blob_access.c \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_API/src/low_level/rfe_cmd_client.c \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_API/src/low_level/rfe_low_level.c \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/src/rfe_min_max_blob.c \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/src/rfe_register_dump.c 

OBJS += \
./src/rfe/CDD_Rfe.o \
./src/rfe/CDD_Rfe_Irq.o \
./src/rfe/rfe_blob_access.o \
./src/rfe/rfe_cmd_client.o \
./src/rfe/rfe_low_level.o \
./src/rfe/rfe_min_max_blob.o \
./src/rfe/rfe_register_dump.o 

C_DEPS += \
./src/rfe/CDD_Rfe.d \
./src/rfe/CDD_Rfe_Irq.d \
./src/rfe/rfe_blob_access.d \
./src/rfe/rfe_cmd_client.d \
./src/rfe/rfe_low_level.d \
./src/rfe/rfe_min_max_blob.d \
./src/rfe/rfe_register_dump.d 


# Each subdirectory must supply rules for building sources it contributes
src/rfe/CDD_Rfe.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_API/src/CDD/CDD_Rfe.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe/CDD_Rfe.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rfe/CDD_Rfe_Irq.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_API/src/CDD/CDD_Rfe_Irq.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe/CDD_Rfe_Irq.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rfe/rfe_blob_access.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/src/rfe_blob_access.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe/rfe_blob_access.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rfe/rfe_cmd_client.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_API/src/low_level/rfe_cmd_client.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe/rfe_cmd_client.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rfe/rfe_low_level.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_API/src/low_level/rfe_low_level.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe/rfe_low_level.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rfe/rfe_min_max_blob.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/src/rfe_min_max_blob.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe/rfe_min_max_blob.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rfe/rfe_register_dump.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/src/rfe_register_dump.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe/rfe_register_dump.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


