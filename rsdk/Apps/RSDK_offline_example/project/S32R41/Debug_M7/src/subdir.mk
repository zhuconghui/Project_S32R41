################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/app_cond_flag_sa.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/app_mem_mgr_sa.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/cache.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/platform_setup/src/ARM/cache_m7_stub.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/debug_tools.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/RSDK_offline_example/src/core0/heap_size.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/RSDK_offline_example/src/core0/main_m7.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/RSDK_offline_example/src/core0/radar_functions_core0.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/common/src/radar_functions_helpers.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/DSP_Dispatcher_example/src/host_integration/rsdk_dsp_dispatcher_func_list_host.c \
D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/rsdk_heap.c 

OBJS += \
./src/app_cond_flag_sa.o \
./src/app_mem_mgr_sa.o \
./src/cache.o \
./src/cache_m7_stub.o \
./src/debug_tools.o \
./src/heap_size.o \
./src/main_m7.o \
./src/radar_functions_core0.o \
./src/radar_functions_helpers.o \
./src/rsdk_dsp_dispatcher_func_list_host.o \
./src/rsdk_heap.o 

C_DEPS += \
./src/app_cond_flag_sa.d \
./src/app_mem_mgr_sa.d \
./src/cache.d \
./src/cache_m7_stub.d \
./src/debug_tools.d \
./src/heap_size.d \
./src/main_m7.d \
./src/radar_functions_core0.d \
./src/radar_functions_helpers.d \
./src/rsdk_dsp_dispatcher_func_list_host.d \
./src/rsdk_heap.d 


# Each subdirectory must supply rules for building sources it contributes
src/app_cond_flag_sa.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/app_cond_flag_sa.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/app_cond_flag_sa.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/app_mem_mgr_sa.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/app_mem_mgr_sa.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/app_mem_mgr_sa.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cache.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/cache.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/cache.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cache_m7_stub.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/platform_setup/src/ARM/cache_m7_stub.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/cache_m7_stub.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/debug_tools.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/debug_tools.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/debug_tools.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/heap_size.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/RSDK_offline_example/src/core0/heap_size.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/heap_size.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main_m7.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/RSDK_offline_example/src/core0/main_m7.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/main_m7.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/radar_functions_core0.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/RSDK_offline_example/src/core0/radar_functions_core0.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/radar_functions_core0.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/radar_functions_helpers.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/common/src/radar_functions_helpers.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/radar_functions_helpers.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rsdk_dsp_dispatcher_func_list_host.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Apps/DSP_Dispatcher_example/src/host_integration/rsdk_dsp_dispatcher_func_list_host.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rsdk_dsp_dispatcher_func_list_host.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rsdk_heap.o: D:/NXP/RSDK_S32R41_0_8_10/rsdk/Tools/Debug_tools/rsdk_heap.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rsdk_heap.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


