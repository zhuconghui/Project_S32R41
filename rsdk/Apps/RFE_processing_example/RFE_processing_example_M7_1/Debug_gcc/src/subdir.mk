################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/src/rfe_crc_computation.c \
D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/example/rfe_ipc_api_shm.c 

OBJS += \
./src/main.o \
./src/rfe_crc_computation.o \
./src/rfe_ipc_api_shm.o 

C_DEPS += \
./src/main.d \
./src/rfe_crc_computation.d \
./src/rfe_ipc_api_shm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rfe_crc_computation.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/src/rfe_crc_computation.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe_crc_computation.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rfe_ipc_api_shm.o: D:/workspaceS32DS.3.5/rsdk/RFE_abstract/RFE_driver2/RF_Common/example/rfe_ipc_api_shm.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rfe_ipc_api_shm.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


