################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/USB/usb_init.c" \
"../Sources/USB/usb_mems.c" \

C_SRCS += \
../Sources/USB/usb_init.c \
../Sources/USB/usb_mems.c \

OBJS += \
./Sources/USB/usb_init.o \
./Sources/USB/usb_mems.o \

C_DEPS += \
./Sources/USB/usb_init.d \
./Sources/USB/usb_mems.d \

OBJS_QUOTED += \
"./Sources/USB/usb_init.o" \
"./Sources/USB/usb_mems.o" \

C_DEPS_QUOTED += \
"./Sources/USB/usb_init.d" \
"./Sources/USB/usb_mems.d" \

OBJS_OS_FORMAT += \
./Sources/USB/usb_init.o \
./Sources/USB/usb_mems.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/USB/usb_init.o: ../Sources/USB/usb_init.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/USB/usb_init.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/USB/usb_init.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/USB/usb_mems.o: ../Sources/USB/usb_mems.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/USB/usb_mems.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/USB/usb_mems.o"
	@echo 'Finished building: $<'
	@echo ' '


