################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Compents/hal_iic/hal_iic.c" \

C_SRCS += \
../Compents/hal_iic/hal_iic.c \

OBJS += \
./Compents/hal_iic/hal_iic.o \

C_DEPS += \
./Compents/hal_iic/hal_iic.d \

OBJS_QUOTED += \
"./Compents/hal_iic/hal_iic.o" \

C_DEPS_QUOTED += \
"./Compents/hal_iic/hal_iic.d" \

OBJS_OS_FORMAT += \
./Compents/hal_iic/hal_iic.o \


# Each subdirectory must supply rules for building sources it contributes
Compents/hal_iic/hal_iic.o: ../Compents/hal_iic/hal_iic.c
	@echo 'Building file: $<'
	@echo 'Executing target #27 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Compents/hal_iic/hal_iic.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Compents/hal_iic/hal_iic.o"
	@echo 'Finished building: $<'
	@echo ' '


