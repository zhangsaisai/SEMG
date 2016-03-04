################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(SMC)/smc.c" \

C_SRCS += \
$(SMC_ESCAPED)/smc.c \

OBJS += \
./drivers/smc/smc.o \

C_DEPS += \
./drivers/smc/smc.d \

OBJS_QUOTED += \
"./drivers/smc/smc.o" \

C_DEPS_QUOTED += \
"./drivers/smc/smc.d" \

OBJS_OS_FORMAT += \
./drivers/smc/smc.o \


# Each subdirectory must supply rules for building sources it contributes
drivers/smc/smc.o: $(SMC_ESCAPED)/smc.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"drivers/smc/smc.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"drivers/smc/smc.d" -o"drivers/smc/smc.o"
	@echo 'Finished building: $<'
	@echo ' '


