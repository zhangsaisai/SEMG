################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Compents/hmc5883/hmc5883.c" \
"../Compents/hmc5883/myiic_m.c" \

C_SRCS += \
../Compents/hmc5883/hmc5883.c \
../Compents/hmc5883/myiic_m.c \

OBJS += \
./Compents/hmc5883/hmc5883.o \
./Compents/hmc5883/myiic_m.o \

C_DEPS += \
./Compents/hmc5883/hmc5883.d \
./Compents/hmc5883/myiic_m.d \

OBJS_QUOTED += \
"./Compents/hmc5883/hmc5883.o" \
"./Compents/hmc5883/myiic_m.o" \

C_DEPS_QUOTED += \
"./Compents/hmc5883/hmc5883.d" \
"./Compents/hmc5883/myiic_m.d" \

OBJS_OS_FORMAT += \
./Compents/hmc5883/hmc5883.o \
./Compents/hmc5883/myiic_m.o \


# Each subdirectory must supply rules for building sources it contributes
Compents/hmc5883/hmc5883.o: ../Compents/hmc5883/hmc5883.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Compents/hmc5883/hmc5883.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Compents/hmc5883/hmc5883.o"
	@echo 'Finished building: $<'
	@echo ' '

Compents/hmc5883/myiic_m.o: ../Compents/hmc5883/myiic_m.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Compents/hmc5883/myiic_m.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Compents/hmc5883/myiic_m.o"
	@echo 'Finished building: $<'
	@echo ' '


