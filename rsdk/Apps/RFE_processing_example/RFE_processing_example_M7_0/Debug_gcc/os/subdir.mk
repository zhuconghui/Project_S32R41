################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_error.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_hw_core.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_isr.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_mem.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_multicore.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_platform_interrupt.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_resource.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_scheduler.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_setup.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_stack.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_task.c 

OBJS += \
./os/Os_error.o \
./os/Os_hw_core.o \
./os/Os_isr.o \
./os/Os_mem.o \
./os/Os_multicore.o \
./os/Os_platform_interrupt.o \
./os/Os_resource.o \
./os/Os_scheduler.o \
./os/Os_setup.o \
./os/Os_stack.o \
./os/Os_task.o 

C_DEPS += \
./os/Os_error.d \
./os/Os_hw_core.d \
./os/Os_isr.d \
./os/Os_mem.d \
./os/Os_multicore.d \
./os/Os_platform_interrupt.d \
./os/Os_resource.d \
./os/Os_scheduler.d \
./os/Os_setup.d \
./os/Os_stack.d \
./os/Os_task.d 


# Each subdirectory must supply rules for building sources it contributes
os/Os_error.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_error.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_error.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_hw_core.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_hw_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_hw_core.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_isr.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_isr.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_isr.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_mem.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_mem.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_mem.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_multicore.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_multicore.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_multicore.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_platform_interrupt.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_platform_interrupt.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_platform_interrupt.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_resource.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_resource.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_resource.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_scheduler.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_scheduler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_scheduler.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_setup.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_setup.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_setup.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_stack.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_stack.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_stack.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

os/Os_task.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_task.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@os/Os_task.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


