################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Compents/calculate/calculate.c" \

C_SRCS += \
../Compents/calculate/calculate.c \

OBJS += \
./Compents/calculate/calculate.o \

C_DEPS += \
./Compents/calculate/calculate.d \

OBJS_QUOTED += \
"./Compents/calculate/calculate.o" \

C_DEPS_QUOTED += \
"./Compents/calculate/calculate.d" \

OBJS_OS_FORMAT += \
./Compents/calculate/calculate.o \


# Each subdirectory must supply rules for building sources it contributes
Compents/calculate/calculate.o: ../Compents/calculate/calculate.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Compents/calculate/calculate.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Compents/calculate/calculate.o"
	@echo 'Finished building: $<'
	@echo ' '


