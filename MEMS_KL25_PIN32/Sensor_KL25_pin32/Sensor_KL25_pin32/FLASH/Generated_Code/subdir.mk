################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/MPU6050_DRDY.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/SCL_G.c" \
"../Generated_Code/SCL_M.c" \
"../Generated_Code/SDA_G.c" \
"../Generated_Code/SDA_M.c" \
"../Generated_Code/SS_SPI0.c" \
"../Generated_Code/SysTick.c" \
"../Generated_Code/Times.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/MPU6050_DRDY.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SCL_G.c \
../Generated_Code/SCL_M.c \
../Generated_Code/SDA_G.c \
../Generated_Code/SDA_M.c \
../Generated_Code/SS_SPI0.c \
../Generated_Code/SysTick.c \
../Generated_Code/Times.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/MPU6050_DRDY.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SCL_G.o \
./Generated_Code/SCL_M.o \
./Generated_Code/SDA_G.o \
./Generated_Code/SDA_M.o \
./Generated_Code/SS_SPI0.o \
./Generated_Code/SysTick.o \
./Generated_Code/Times.o \
./Generated_Code/Vectors.o \

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/MPU6050_DRDY.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SCL_G.d \
./Generated_Code/SCL_M.d \
./Generated_Code/SDA_G.d \
./Generated_Code/SDA_M.d \
./Generated_Code/SS_SPI0.d \
./Generated_Code/SysTick.d \
./Generated_Code/Times.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/Cpu.o" \
"./Generated_Code/MPU6050_DRDY.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/SCL_G.o" \
"./Generated_Code/SCL_M.o" \
"./Generated_Code/SDA_G.o" \
"./Generated_Code/SDA_M.o" \
"./Generated_Code/SS_SPI0.o" \
"./Generated_Code/SysTick.o" \
"./Generated_Code/Times.o" \
"./Generated_Code/Vectors.o" \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu.d" \
"./Generated_Code/MPU6050_DRDY.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/SCL_G.d" \
"./Generated_Code/SCL_M.d" \
"./Generated_Code/SDA_G.d" \
"./Generated_Code/SDA_M.d" \
"./Generated_Code/SS_SPI0.d" \
"./Generated_Code/SysTick.d" \
"./Generated_Code/Times.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu.o \
./Generated_Code/MPU6050_DRDY.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SCL_G.o \
./Generated_Code/SCL_M.o \
./Generated_Code/SDA_G.o \
./Generated_Code/SDA_M.o \
./Generated_Code/SS_SPI0.o \
./Generated_Code/SysTick.o \
./Generated_Code/Times.o \
./Generated_Code/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/MPU6050_DRDY.o: ../Generated_Code/MPU6050_DRDY.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/MPU6050_DRDY.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/MPU6050_DRDY.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SCL_G.o: ../Generated_Code/SCL_G.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SCL_G.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SCL_G.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SCL_M.o: ../Generated_Code/SCL_M.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SCL_M.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SCL_M.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SDA_G.o: ../Generated_Code/SDA_G.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SDA_G.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SDA_G.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SDA_M.o: ../Generated_Code/SDA_M.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SDA_M.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SDA_M.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SS_SPI0.o: ../Generated_Code/SS_SPI0.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SS_SPI0.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SS_SPI0.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SysTick.o: ../Generated_Code/SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SysTick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SysTick.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Times.o: ../Generated_Code/Times.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Times.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Times.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


