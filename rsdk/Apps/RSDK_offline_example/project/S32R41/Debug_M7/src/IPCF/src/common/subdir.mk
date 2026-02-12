################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/common/ipc-queue.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/common/ipc-shm.c \
D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/common/ipc-util.c 

OBJS += \
./src/IPCF/src/common/ipc-queue.o \
./src/IPCF/src/common/ipc-shm.o \
./src/IPCF/src/common/ipc-util.o 

C_DEPS += \
./src/IPCF/src/common/ipc-queue.d \
./src/IPCF/src/common/ipc-shm.d \
./src/IPCF/src/common/ipc-util.d 


# Each subdirectory must supply rules for building sources it contributes
src/IPCF/src/common/ipc-queue.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/common/ipc-queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/IPCF/src/common/ipc-queue.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/IPCF/src/common/ipc-shm.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/common/ipc-shm.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/IPCF/src/common/ipc-shm.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/IPCF/src/common/ipc-util.o: D:/NXP/S32DS.3.5/S32DS/software/PlatformSDK_S32R/IPCF_S32R41/src/common/ipc-util.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/IPCF/src/common/ipc-util.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


