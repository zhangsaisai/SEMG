################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Compents/mpu6050/mpu6050.c" \
"../Compents/mpu6050/myiic_g.c" \

C_SRCS += \
../Compents/mpu6050/mpu6050.c \
../Compents/mpu6050/myiic_g.c \

OBJS += \
./Compents/mpu6050/mpu6050.o \
./Compents/mpu6050/myiic_g.o \

C_DEPS += \
./Compents/mpu6050/mpu6050.d \
./Compents/mpu6050/myiic_g.d \

OBJS_QUOTED += \
"./Compents/mpu6050/mpu6050.o" \
"./Compents/mpu6050/myiic_g.o" \

C_DEPS_QUOTED += \
"./Compents/mpu6050/mpu6050.d" \
"./Compents/mpu6050/myiic_g.d" \

OBJS_OS_FORMAT += \
./Compents/mpu6050/mpu6050.o \
./Compents/mpu6050/myiic_g.o \


# Each subdirectory must supply rules for building sources it contributes
Compents/mpu6050/mpu6050.o: ../Compents/mpu6050/mpu6050.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Compents/mpu6050/mpu6050.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Compents/mpu6050/mpu6050.o"
	@echo 'Finished building: $<'
	@echo ' '

Compents/mpu6050/myiic_g.o: ../Compents/mpu6050/myiic_g.c
	@echo 'Building file: $<'
	@echo 'Executing target #27 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Compents/mpu6050/myiic_g.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Compents/mpu6050/myiic_g.o"
	@echo 'Finished building: $<'
	@echo ' '


