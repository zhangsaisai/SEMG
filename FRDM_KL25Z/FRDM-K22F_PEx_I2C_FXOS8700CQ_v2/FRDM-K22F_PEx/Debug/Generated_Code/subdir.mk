################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/I2C2.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/pin_mux.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/I2C2.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/pin_mux.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/I2C2.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Freescale/KSDK_1.2.0/FRDM-K22F_PEx/Static_Code/System" -I"C:/Freescale/KSDK_1.2.0/FRDM-K22F_PEx/Static_Code/PDD" -I"C:/Freescale/KSDK_1.2.0/FRDM-K22F_PEx/Static_Code/IO_Map" -I"C:\Freescale\KDS_3.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Freescale/KSDK_1.2.0/FRDM-K22F_PEx/Sources" -I"C:/Freescale/KSDK_1.2.0/FRDM-K22F_PEx/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


