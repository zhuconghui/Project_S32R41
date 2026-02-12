################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspaceS32DS.3.5/rsdk/DSP/DSP_host_driver/src/CDD_Dsphd.c \
D:/workspaceS32DS.3.5/rsdk/DSP/DSP_common/src/crc8.c \
D:/workspaceS32DS.3.5/rsdk/Apps/DSP_Dispatcher_example/src/host_integration/rsdk_dsp_dispatcher_func_list_host.c 

OBJS += \
./src/dsp/CDD_Dsphd.o \
./src/dsp/crc8.o \
./src/dsp/rsdk_dsp_dispatcher_func_list_host.o 

C_DEPS += \
./src/dsp/CDD_Dsphd.d \
./src/dsp/crc8.d \
./src/dsp/rsdk_dsp_dispatcher_func_list_host.d 


# Each subdirectory must supply rules for building sources it contributes
src/dsp/CDD_Dsphd.o: D:/workspaceS32DS.3.5/rsdk/DSP/DSP_host_driver/src/CDD_Dsphd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/dsp/CDD_Dsphd.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dsp/crc8.o: D:/workspaceS32DS.3.5/rsdk/DSP/DSP_common/src/crc8.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/dsp/crc8.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dsp/rsdk_dsp_dispatcher_func_list_host.o: D:/workspaceS32DS.3.5/rsdk/Apps/DSP_Dispatcher_example/src/host_integration/rsdk_dsp_dispatcher_func_list_host.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/dsp/rsdk_dsp_dispatcher_func_list_host.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


