################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(UART)/uart.c" \

C_SRCS += \
$(UART_ESCAPED)/uart.c \

OBJS += \
./drivers/uart/uart.o \

C_DEPS += \
./drivers/uart/uart.d \

OBJS_QUOTED += \
"./drivers/uart/uart.o" \

C_DEPS_QUOTED += \
"./drivers/uart/uart.d" \

OBJS_OS_FORMAT += \
./drivers/uart/uart.o \


# Each subdirectory must supply rules for building sources it contributes
drivers/uart/uart.o: $(UART_ESCAPED)/uart.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"drivers/uart/uart.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"drivers/uart/uart.d" -o"drivers/uart/uart.o"
	@echo 'Finished building: $<'
	@echo ' '


