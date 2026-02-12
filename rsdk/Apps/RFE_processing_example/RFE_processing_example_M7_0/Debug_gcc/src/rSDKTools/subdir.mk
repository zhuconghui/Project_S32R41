################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/app_cond_flag_sa.c \
D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/app_mem_mgr_sa.c \
D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/cache.c \
D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/cache_m7_stub.c \
D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/debug_tools.c \
D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/rsdk_heap.c 

OBJS += \
./src/rSDKTools/app_cond_flag_sa.o \
./src/rSDKTools/app_mem_mgr_sa.o \
./src/rSDKTools/cache.o \
./src/rSDKTools/cache_m7_stub.o \
./src/rSDKTools/debug_tools.o \
./src/rSDKTools/rsdk_heap.o 

C_DEPS += \
./src/rSDKTools/app_cond_flag_sa.d \
./src/rSDKTools/app_mem_mgr_sa.d \
./src/rSDKTools/cache.d \
./src/rSDKTools/cache_m7_stub.d \
./src/rSDKTools/debug_tools.d \
./src/rSDKTools/rsdk_heap.d 


# Each subdirectory must supply rules for building sources it contributes
src/rSDKTools/app_cond_flag_sa.o: D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/app_cond_flag_sa.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rSDKTools/app_cond_flag_sa.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rSDKTools/app_mem_mgr_sa.o: D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/app_mem_mgr_sa.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rSDKTools/app_mem_mgr_sa.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rSDKTools/cache.o: D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/cache.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rSDKTools/cache.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rSDKTools/cache_m7_stub.o: D:/workspaceS32DS.3.5/rsdk/platform_setup/src/ARM/cache_m7_stub.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rSDKTools/cache_m7_stub.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rSDKTools/debug_tools.o: D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/debug_tools.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rSDKTools/debug_tools.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rSDKTools/rsdk_heap.o: D:/workspaceS32DS.3.5/rsdk/Tools/Debug_tools/rsdk_heap.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rSDKTools/rsdk_heap.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


