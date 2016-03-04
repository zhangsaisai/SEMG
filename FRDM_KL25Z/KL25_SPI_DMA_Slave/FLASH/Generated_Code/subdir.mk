################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/Cpu.c" \
"../Generated_Code/DMAT_S_SPI_RX.c" \
"../Generated_Code/DMAT_S_SPI_TX.c" \
"../Generated_Code/DMA_CTRL.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/SS_SPI1.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/DMAT_S_SPI_RX.c \
../Generated_Code/DMAT_S_SPI_TX.c \
../Generated_Code/DMA_CTRL.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SS_SPI1.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/DMAT_S_SPI_RX.o \
./Generated_Code/DMAT_S_SPI_TX.o \
./Generated_Code/DMA_CTRL.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SS_SPI1.o \
./Generated_Code/Vectors.o \

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/DMAT_S_SPI_RX.d \
./Generated_Code/DMAT_S_SPI_TX.d \
./Generated_Code/DMA_CTRL.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SS_SPI1.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/Cpu.o" \
"./Generated_Code/DMAT_S_SPI_RX.o" \
"./Generated_Code/DMAT_S_SPI_TX.o" \
"./Generated_Code/DMA_CTRL.o" \
"./Generated_Code/PE_LDD.o" \
"./Generated_Code/SS_SPI1.o" \
"./Generated_Code/Vectors.o" \

C_DEPS_QUOTED += \
"./Generated_Code/Cpu.d" \
"./Generated_Code/DMAT_S_SPI_RX.d" \
"./Generated_Code/DMAT_S_SPI_TX.d" \
"./Generated_Code/DMA_CTRL.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/SS_SPI1.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/Cpu.o \
./Generated_Code/DMAT_S_SPI_RX.o \
./Generated_Code/DMAT_S_SPI_TX.o \
./Generated_Code/DMA_CTRL.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SS_SPI1.o \
./Generated_Code/Vectors.o \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/Cpu.o: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Cpu.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DMAT_S_SPI_RX.o: ../Generated_Code/DMAT_S_SPI_RX.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/DMAT_S_SPI_RX.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/DMAT_S_SPI_RX.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DMAT_S_SPI_TX.o: ../Generated_Code/DMAT_S_SPI_TX.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/DMAT_S_SPI_TX.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/DMAT_S_SPI_TX.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/DMA_CTRL.o: ../Generated_Code/DMA_CTRL.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/DMA_CTRL.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/DMA_CTRL.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD.o: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/PE_LDD.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SS_SPI1.o: ../Generated_Code/SS_SPI1.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SS_SPI1.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/SS_SPI1.o"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors.o: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Generated_Code/Vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


