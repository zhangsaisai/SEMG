################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(I2C)/I2c.c" \
"../project/hal_dev_mma8451.c" \
"../project/hal_i2c.c" \

C_SRCS += \
$(I2C_ESCAPED)/I2c.c \
../project/hal_dev_mma8451.c \
../project/hal_i2c.c \

OBJS += \
./project/I2c.o \
./project/hal_dev_mma8451.o \
./project/hal_i2c.o \

C_DEPS += \
./project/I2c.d \
./project/hal_dev_mma8451.d \
./project/hal_i2c.d \

OBJS_QUOTED += \
"./project/I2c.o" \
"./project/hal_dev_mma8451.o" \
"./project/hal_i2c.o" \

C_DEPS_QUOTED += \
"./project/I2c.d" \
"./project/hal_dev_mma8451.d" \
"./project/hal_i2c.d" \

OBJS_OS_FORMAT += \
./project/I2c.o \
./project/hal_dev_mma8451.o \
./project/hal_i2c.o \


# Each subdirectory must supply rules for building sources it contributes
project/I2c.o: $(I2C_ESCAPED)/I2c.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"project/I2c.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"project/I2c.d" -o"project/I2c.o"
	@echo 'Finished building: $<'
	@echo ' '

project/hal_dev_mma8451.o: ../project/hal_dev_mma8451.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"project/hal_dev_mma8451.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"project/hal_dev_mma8451.o"
	@echo 'Finished building: $<'
	@echo ' '

project/hal_i2c.o: ../project/hal_i2c.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"project/hal_i2c.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"project/hal_i2c.o"
	@echo 'Finished building: $<'
	@echo ' '


