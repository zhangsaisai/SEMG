################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(PMC)/pmc.c" \

C_SRCS += \
$(PMC_ESCAPED)/pmc.c \

OBJS += \
./drivers/pmc/pmc.o \

C_DEPS += \
./drivers/pmc/pmc.d \

OBJS_QUOTED += \
"./drivers/pmc/pmc.o" \

C_DEPS_QUOTED += \
"./drivers/pmc/pmc.d" \

OBJS_OS_FORMAT += \
./drivers/pmc/pmc.o \


# Each subdirectory must supply rules for building sources it contributes
drivers/pmc/pmc.o: $(PMC_ESCAPED)/pmc.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"drivers/pmc/pmc.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"drivers/pmc/pmc.d" -o"drivers/pmc/pmc.o"
	@echo 'Finished building: $<'
	@echo ' '


