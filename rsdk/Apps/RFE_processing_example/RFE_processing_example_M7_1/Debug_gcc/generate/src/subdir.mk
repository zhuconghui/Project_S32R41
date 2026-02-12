################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../generate/src/CDD_Uart_PBcfg.c \
../generate/src/Clock_Ip_Cfg.c \
../generate/src/Clock_Ip_PBcfg.c \
../generate/src/Dio_Cfg.c \
../generate/src/Eth_43_GMAC_Ipw_PBcfg.c \
../generate/src/Eth_43_GMAC_PBcfg.c \
../generate/src/Ftm_Gpt_Ip_PBcfg.c \
../generate/src/Gmac_Ip_Cfg.c \
../generate/src/Gmac_Ip_PBcfg.c \
../generate/src/Gpt_Cfg.c \
../generate/src/Gpt_Ipw_PBcfg.c \
../generate/src/Gpt_PBcfg.c \
../generate/src/IntCtrl_Ip_Cfg.c \
../generate/src/Linflexd_Uart_Ip_PBcfg.c \
../generate/src/Mcu_Cfg.c \
../generate/src/Mcu_PBcfg.c \
../generate/src/Mpu_M7_Ip_Cfg.c \
../generate/src/OsIf_Cfg.c \
../generate/src/Pit_Ip_PBcfg.c \
../generate/src/Platform_Cfg.c \
../generate/src/Platform_Ipw_Cfg.c \
../generate/src/Port_Cfg.c \
../generate/src/Port_PBcfg.c \
../generate/src/Power_Ip_Cfg.c \
../generate/src/Power_Ip_PBcfg.c \
../generate/src/Ram_Ip_Cfg.c \
../generate/src/Ram_Ip_PBcfg.c \
../generate/src/Siul2_Port_Ip_PBcfg.c \
../generate/src/Spi_Ip_PBcfg.c \
../generate/src/Spi_Ipw_PBcfg.c \
../generate/src/Spi_PBcfg.c \
../generate/src/Stm_Ip_PBcfg.c \
../generate/src/Uart_Ipw_PBcfg.c \
../generate/src/netifcfg.c 

OBJS += \
./generate/src/CDD_Uart_PBcfg.o \
./generate/src/Clock_Ip_Cfg.o \
./generate/src/Clock_Ip_PBcfg.o \
./generate/src/Dio_Cfg.o \
./generate/src/Eth_43_GMAC_Ipw_PBcfg.o \
./generate/src/Eth_43_GMAC_PBcfg.o \
./generate/src/Ftm_Gpt_Ip_PBcfg.o \
./generate/src/Gmac_Ip_Cfg.o \
./generate/src/Gmac_Ip_PBcfg.o \
./generate/src/Gpt_Cfg.o \
./generate/src/Gpt_Ipw_PBcfg.o \
./generate/src/Gpt_PBcfg.o \
./generate/src/IntCtrl_Ip_Cfg.o \
./generate/src/Linflexd_Uart_Ip_PBcfg.o \
./generate/src/Mcu_Cfg.o \
./generate/src/Mcu_PBcfg.o \
./generate/src/Mpu_M7_Ip_Cfg.o \
./generate/src/OsIf_Cfg.o \
./generate/src/Pit_Ip_PBcfg.o \
./generate/src/Platform_Cfg.o \
./generate/src/Platform_Ipw_Cfg.o \
./generate/src/Port_Cfg.o \
./generate/src/Port_PBcfg.o \
./generate/src/Power_Ip_Cfg.o \
./generate/src/Power_Ip_PBcfg.o \
./generate/src/Ram_Ip_Cfg.o \
./generate/src/Ram_Ip_PBcfg.o \
./generate/src/Siul2_Port_Ip_PBcfg.o \
./generate/src/Spi_Ip_PBcfg.o \
./generate/src/Spi_Ipw_PBcfg.o \
./generate/src/Spi_PBcfg.o \
./generate/src/Stm_Ip_PBcfg.o \
./generate/src/Uart_Ipw_PBcfg.o \
./generate/src/netifcfg.o 

C_DEPS += \
./generate/src/CDD_Uart_PBcfg.d \
./generate/src/Clock_Ip_Cfg.d \
./generate/src/Clock_Ip_PBcfg.d \
./generate/src/Dio_Cfg.d \
./generate/src/Eth_43_GMAC_Ipw_PBcfg.d \
./generate/src/Eth_43_GMAC_PBcfg.d \
./generate/src/Ftm_Gpt_Ip_PBcfg.d \
./generate/src/Gmac_Ip_Cfg.d \
./generate/src/Gmac_Ip_PBcfg.d \
./generate/src/Gpt_Cfg.d \
./generate/src/Gpt_Ipw_PBcfg.d \
./generate/src/Gpt_PBcfg.d \
./generate/src/IntCtrl_Ip_Cfg.d \
./generate/src/Linflexd_Uart_Ip_PBcfg.d \
./generate/src/Mcu_Cfg.d \
./generate/src/Mcu_PBcfg.d \
./generate/src/Mpu_M7_Ip_Cfg.d \
./generate/src/OsIf_Cfg.d \
./generate/src/Pit_Ip_PBcfg.d \
./generate/src/Platform_Cfg.d \
./generate/src/Platform_Ipw_Cfg.d \
./generate/src/Port_Cfg.d \
./generate/src/Port_PBcfg.d \
./generate/src/Power_Ip_Cfg.d \
./generate/src/Power_Ip_PBcfg.d \
./generate/src/Ram_Ip_Cfg.d \
./generate/src/Ram_Ip_PBcfg.d \
./generate/src/Siul2_Port_Ip_PBcfg.d \
./generate/src/Spi_Ip_PBcfg.d \
./generate/src/Spi_Ipw_PBcfg.d \
./generate/src/Spi_PBcfg.d \
./generate/src/Stm_Ip_PBcfg.d \
./generate/src/Uart_Ipw_PBcfg.d \
./generate/src/netifcfg.d 


# Each subdirectory must supply rules for building sources it contributes
generate/src/%.o: ../generate/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@generate/src/CDD_Uart_PBcfg.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


