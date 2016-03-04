################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Compents/function/function.c" \

C_SRCS += \
../Compents/function/function.c \

OBJS += \
./Compents/function/function.o \

C_DEPS += \
./Compents/function/function.d \

OBJS_QUOTED += \
"./Compents/function/function.o" \

C_DEPS_QUOTED += \
"./Compents/function/function.d" \

OBJS_OS_FORMAT += \
./Compents/function/function.o \


# Each subdirectory must supply rules for building sources it contributes
Compents/function/function.o: ../Compents/function/function.c
	@echo 'Building file: $<'
	@echo 'Executing target #28 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Compents/function/function.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Compents/function/function.o"
	@echo 'Finished building: $<'
	@echo ' '


