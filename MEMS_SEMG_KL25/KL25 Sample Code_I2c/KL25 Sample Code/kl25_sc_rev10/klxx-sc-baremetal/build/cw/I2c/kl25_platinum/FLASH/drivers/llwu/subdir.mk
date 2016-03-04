################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(LLWU)/llwu.c" \

C_SRCS += \
$(LLWU_ESCAPED)/llwu.c \

OBJS += \
./drivers/llwu/llwu.o \

C_DEPS += \
./drivers/llwu/llwu.d \

OBJS_QUOTED += \
"./drivers/llwu/llwu.o" \

C_DEPS_QUOTED += \
"./drivers/llwu/llwu.d" \

OBJS_OS_FORMAT += \
./drivers/llwu/llwu.o \


# Each subdirectory must supply rules for building sources it contributes
drivers/llwu/llwu.o: $(LLWU_ESCAPED)/llwu.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"drivers/llwu/llwu.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"drivers/llwu/llwu.d" -o"drivers/llwu/llwu.o"
	@echo 'Finished building: $<'
	@echo ' '


