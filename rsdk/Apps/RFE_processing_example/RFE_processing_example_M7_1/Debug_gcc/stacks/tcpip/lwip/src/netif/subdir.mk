################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stacks/tcpip/lwip/src/netif/bridgeif.c \
../stacks/tcpip/lwip/src/netif/bridgeif_fdb.c \
../stacks/tcpip/lwip/src/netif/ethernet.c \
../stacks/tcpip/lwip/src/netif/lowpan6.c \
../stacks/tcpip/lwip/src/netif/lowpan6_ble.c \
../stacks/tcpip/lwip/src/netif/lowpan6_common.c \
../stacks/tcpip/lwip/src/netif/zepif.c 

OBJS += \
./stacks/tcpip/lwip/src/netif/bridgeif.o \
./stacks/tcpip/lwip/src/netif/bridgeif_fdb.o \
./stacks/tcpip/lwip/src/netif/ethernet.o \
./stacks/tcpip/lwip/src/netif/lowpan6.o \
./stacks/tcpip/lwip/src/netif/lowpan6_ble.o \
./stacks/tcpip/lwip/src/netif/lowpan6_common.o \
./stacks/tcpip/lwip/src/netif/zepif.o 

C_DEPS += \
./stacks/tcpip/lwip/src/netif/bridgeif.d \
./stacks/tcpip/lwip/src/netif/bridgeif_fdb.d \
./stacks/tcpip/lwip/src/netif/ethernet.d \
./stacks/tcpip/lwip/src/netif/lowpan6.d \
./stacks/tcpip/lwip/src/netif/lowpan6_ble.d \
./stacks/tcpip/lwip/src/netif/lowpan6_common.d \
./stacks/tcpip/lwip/src/netif/zepif.d 


# Each subdirectory must supply rules for building sources it contributes
stacks/tcpip/lwip/src/netif/%.o: ../stacks/tcpip/lwip/src/netif/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@stacks/tcpip/lwip/src/netif/bridgeif.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


