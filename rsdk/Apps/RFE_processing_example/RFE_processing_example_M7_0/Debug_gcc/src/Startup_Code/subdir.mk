################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/Startup_Code/startup_gcc.s \
../src/Startup_Code/vector_gcc.s 

C_SRCS += \
../src/Startup_Code/core.c \
../src/Startup_Code/exceptions.c \
../src/Startup_Code/nvic.c \
../src/Startup_Code/startup_init.c \
../src/Startup_Code/system.c 

OBJS += \
./src/Startup_Code/core.o \
./src/Startup_Code/exceptions.o \
./src/Startup_Code/nvic.o \
./src/Startup_Code/startup_gcc.o \
./src/Startup_Code/startup_init.o \
./src/Startup_Code/system.o \
./src/Startup_Code/vector_gcc.o 

C_DEPS += \
./src/Startup_Code/core.d \
./src/Startup_Code/exceptions.d \
./src/Startup_Code/nvic.d \
./src/Startup_Code/startup_init.d \
./src/Startup_Code/system.d 


# Each subdirectory must supply rules for building sources it contributes
src/Startup_Code/%.o: ../src/Startup_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/Startup_Code/core.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Startup_Code/%.o: ../src/Startup_Code/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS Assembler'
	arm-none-eabi-gcc "@src/Startup_Code/startup_gcc.args" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


