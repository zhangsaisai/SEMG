################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(RCM)/rcm.c" \

C_SRCS += \
$(RCM_ESCAPED)/rcm.c \

OBJS += \
./drivers/rcm/rcm.o \

C_DEPS += \
./drivers/rcm/rcm.d \

OBJS_QUOTED += \
"./drivers/rcm/rcm.o" \

C_DEPS_QUOTED += \
"./drivers/rcm/rcm.d" \

OBJS_OS_FORMAT += \
./drivers/rcm/rcm.o \


# Each subdirectory must supply rules for building sources it contributes
drivers/rcm/rcm.o: $(RCM_ESCAPED)/rcm.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"drivers/rcm/rcm.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"drivers/rcm/rcm.d" -o"drivers/rcm/rcm.o"
	@echo 'Finished building: $<'
	@echo ' '


