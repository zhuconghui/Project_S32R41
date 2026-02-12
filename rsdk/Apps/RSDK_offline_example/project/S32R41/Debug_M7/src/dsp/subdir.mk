################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/DSP/DSP_host_driver/src/CDD_Dsphd.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/DSP/DSP_common/src/crc8.c 

OBJS += \
./src/dsp/CDD_Dsphd.o \
./src/dsp/crc8.o 

C_DEPS += \
./src/dsp/CDD_Dsphd.d \
./src/dsp/crc8.d 


# Each subdirectory must supply rules for building sources it contributes
src/dsp/CDD_Dsphd.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/DSP/DSP_host_driver/src/CDD_Dsphd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/dsp/CDD_Dsphd.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dsp/crc8.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/DSP/DSP_common/src/crc8.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/dsp/crc8.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


