################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(RTC)/rtc.c" \

C_SRCS += \
$(RTC_ESCAPED)/rtc.c \

OBJS += \
./drivers/rtc/rtc.o \

C_DEPS += \
./drivers/rtc/rtc.d \

OBJS_QUOTED += \
"./drivers/rtc/rtc.o" \

C_DEPS_QUOTED += \
"./drivers/rtc/rtc.d" \

OBJS_OS_FORMAT += \
./drivers/rtc/rtc.o \


# Each subdirectory must supply rules for building sources it contributes
drivers/rtc/rtc.o: $(RTC_ESCAPED)/rtc.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"drivers/rtc/rtc.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"drivers/rtc/rtc.d" -o"drivers/rtc/rtc.o"
	@echo 'Finished building: $<'
	@echo ' '


