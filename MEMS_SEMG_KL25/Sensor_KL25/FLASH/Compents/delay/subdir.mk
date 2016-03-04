################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Compents/delay/delay.c" \

C_SRCS += \
../Compents/delay/delay.c \

OBJS += \
./Compents/delay/delay.o \

C_DEPS += \
./Compents/delay/delay.d \

OBJS_QUOTED += \
"./Compents/delay/delay.o" \

C_DEPS_QUOTED += \
"./Compents/delay/delay.d" \

OBJS_OS_FORMAT += \
./Compents/delay/delay.o \


# Each subdirectory must supply rules for building sources it contributes
Compents/delay/delay.o: ../Compents/delay/delay.c
	@echo 'Building file: $<'
	@echo 'Executing target #31 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Compents/delay/delay.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Compents/delay/delay.o"
	@echo 'Finished building: $<'
	@echo ' '


