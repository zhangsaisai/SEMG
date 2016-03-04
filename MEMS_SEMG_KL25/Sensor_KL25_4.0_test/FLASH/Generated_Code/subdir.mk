################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/MPU6050_DRDY.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/PTD0_50HZ.c" \
"../Generated_Code/SysTick.c" \
"../Generated_Code/USB_LDD.c" \
"../Generated_Code/Vectors.c" \
"../Generated_Code/usb_class.c" \
"../Generated_Code/usb_dci.c" \
"../Generated_Code/usb_device.c" \
"../Generated_Code/usb_driver.c" \
"../Generated_Code/usb_framework.c" \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/MPU6050_DRDY.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PTD0_50HZ.c \
../Generated_Code/SysTick.c \
../Generated_Code/USB_LDD.c \
../Generated_Code/Vectors.c \
../Generated_Code/usb_class.c \
../Generated_Code/usb_dci.c \
../Generated_Code/usb_device.c \
../Generated_Code/usb_driver.c \
../Generated_Code/usb_framework.c \

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/MPU6050_DRDY.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PTD0_50HZ.o \
./Generated_Code/SysTick.o \
./Generated_Code/USB_LDD.o \
./Generated_Code/Vectors.o \
./Generated_Code/usb_class.o \
./Generated_Code/usb_dci.o \
./Generated_Code/usb_device.o \
./Generated_Code/usb_driver.o \
./Generated_Code/usb_framework.o \

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/MPU6050_DRDY.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PTD0_50HZ.d \
./Generated_Code/SysTick.d \
./Generated_Code/USB_LDD.d \
./Generated_Code/Vectors.d \
./Generated_Code/usb_class.d \
./Generated_Code/usb_dci.d \
./Generated_Code/usb_device.d \
./Generated_Code/usb_driver.d \
./Generated_Code/usb_framework.d \

OBJS_QUOTED += \
"./Generated_Code/Cpu.o" \
"./Generated_Code/MPU6050_DRDY.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/PTD0_50HZ.o" \
"./Generated_Code/SysTick.o" \
"./Generated_Code/USB_LDD.o" \
"./Generated_Code/Vectors.o" \
"./Generated_Code/usb_class.o" \
"./Generated_Code/usb_dci.o" \
"./Generated_Code/usb_device.o" \
"./Generated_Code/usb_driver.o" \
"./Generated_Code/usb_framework.o" \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu.d" \
"./Generated_Code/MPU6050_DRDY.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/PTD0_50HZ.d" \
"./Generated_Code/SysTick.d" \
"./Generated_Code/USB_LDD.d" \
"./Generated_Code/Vectors.d" \
"./Generated_Code/usb_class.d" \
"./Generated_Code/usb_dci.d" \
"./Generated_Code/usb_device.d" \
"./Generated_Code/usb_driver.d" \
"./Generated_Code/usb_framework.d" \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu.o \
./Generated_Code/MPU6050_DRDY.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PTD0_50HZ.o \
./Generated_Code/SysTick.o \
./Generated_Code/USB_LDD.o \
./Generated_Code/Vectors.o \
./Generated_Code/usb_class.o \
./Generated_Code/usb_dci.o \
./Generated_Code/usb_device.o \
./Generated_Code/usb_driver.o \
./Generated_Code/usb_framework.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/MPU6050_DRDY.o: ../Generated_Code/MPU6050_DRDY.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/MPU6050_DRDY.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/MPU6050_DRDY.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PTD0_50HZ.o: ../Generated_Code/PTD0_50HZ.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PTD0_50HZ.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PTD0_50HZ.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SysTick.o: ../Generated_Code/SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SysTick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SysTick.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/USB_LDD.o: ../Generated_Code/USB_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/USB_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/USB_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/usb_class.o: ../Generated_Code/usb_class.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/usb_class.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/usb_class.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/usb_dci.o: ../Generated_Code/usb_dci.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/usb_dci.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/usb_dci.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/usb_device.o: ../Generated_Code/usb_device.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/usb_device.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/usb_device.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/usb_driver.o: ../Generated_Code/usb_driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/usb_driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/usb_driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/usb_framework.o: ../Generated_Code/usb_framework.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/usb_framework.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/usb_framework.o"
	@echo 'Finished building: $<'
	@echo ' '


