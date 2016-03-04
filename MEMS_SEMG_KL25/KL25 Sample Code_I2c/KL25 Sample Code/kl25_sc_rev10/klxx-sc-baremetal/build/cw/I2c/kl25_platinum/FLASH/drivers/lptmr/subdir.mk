################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(LPTMR)/lptmr.c" \

C_SRCS += \
$(LPTMR_ESCAPED)/lptmr.c \

OBJS += \
./drivers/lptmr/lptmr.o \

C_DEPS += \
./drivers/lptmr/lptmr.d \

OBJS_QUOTED += \
"./drivers/lptmr/lptmr.o" \

C_DEPS_QUOTED += \
"./drivers/lptmr/lptmr.d" \

OBJS_OS_FORMAT += \
./drivers/lptmr/lptmr.o \


# Each subdirectory must supply rules for building sources it contributes
drivers/lptmr/lptmr.o: $(LPTMR_ESCAPED)/lptmr.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"drivers/lptmr/lptmr.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"drivers/lptmr/lptmr.d" -o"drivers/lptmr/lptmr.o"
	@echo 'Finished building: $<'
	@echo ' '


