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
./src/os/Os_error.o \
./src/os/Os_hw_core.o \
./src/os/Os_isr.o \
./src/os/Os_mem.o \
./src/os/Os_multicore.o \
./src/os/Os_platform_interrupt.o \
./src/os/Os_resource.o \
./src/os/Os_scheduler.o \
./src/os/Os_setup.o \
./src/os/Os_stack.o \
./src/os/Os_task.o 

C_DEPS += \
./src/os/Os_error.d \
./src/os/Os_hw_core.d \
./src/os/Os_isr.d \
./src/os/Os_mem.d \
./src/os/Os_multicore.d \
./src/os/Os_platform_interrupt.d \
./src/os/Os_resource.d \
./src/os/Os_scheduler.d \
./src/os/Os_setup.d \
./src/os/Os_stack.d \
./src/os/Os_task.d 


# Each subdirectory must supply rules for building sources it contributes
src/os/Os_error.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_error.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_error.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_hw_core.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_hw_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_hw_core.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_isr.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_isr.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_isr.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_mem.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_mem.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_mem.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_multicore.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_multicore.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_multicore.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_platform_interrupt.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_platform_interrupt.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_platform_interrupt.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_resource.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_resource.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_resource.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_scheduler.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_scheduler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_scheduler.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_setup.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_setup.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_setup.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_stack.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_stack.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_stack.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/os/Os_task.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/RTOS_S32R41/ssc/src/Os_task.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/os/Os_task.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


