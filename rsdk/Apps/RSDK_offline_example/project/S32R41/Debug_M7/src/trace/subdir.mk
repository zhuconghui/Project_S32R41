################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Trace/src/sa_arm_counter.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Trace/src/timer_platform.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Trace/src/trace.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Trace/src/trace_internals.c 

OBJS += \
./src/trace/sa_arm_counter.o \
./src/trace/timer_platform.o \
./src/trace/trace.o \
./src/trace/trace_internals.o 

C_DEPS += \
./src/trace/sa_arm_counter.d \
./src/trace/timer_platform.d \
./src/trace/trace.d \
./src/trace/trace_internals.d 


# Each subdirectory must supply rules for building sources it contributes
src/trace/sa_arm_counter.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Trace/src/sa_arm_counter.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/trace/sa_arm_counter.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/trace/timer_platform.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Trace/src/timer_platform.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/trace/timer_platform.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/trace/trace.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Trace/src/trace.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/trace/trace.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/trace/trace_internals.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Trace/src/trace_internals.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/trace/trace_internals.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


