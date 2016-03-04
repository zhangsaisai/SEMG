################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(CPU)/arm_cm0.c" \
"$(CPU)/nmi_isr_handler.c" \
"$(CPU)/start.c" \
"$(CPU)/sysinit.c" \
"$(CPU)/vectors.c" \

C_SRCS += \
$(CPU_ESCAPED)/arm_cm0.c \
$(CPU_ESCAPED)/nmi_isr_handler.c \
$(CPU_ESCAPED)/start.c \
$(CPU_ESCAPED)/sysinit.c \
$(CPU_ESCAPED)/vectors.c \

S_SRCS += \
$(CPU_ESCAPED)/cw_crt0.s \

S_SRCS_QUOTED += \
"$(CPU)/cw_crt0.s" \

S_DEPS_QUOTED += \
"./cpu/cw_crt0.d" \

OBJS += \
./cpu/arm_cm0.o \
./cpu/cw_crt0.o \
./cpu/nmi_isr_handler.o \
./cpu/start.o \
./cpu/sysinit.o \
./cpu/vectors.o \

C_DEPS += \
./cpu/arm_cm0.d \
./cpu/nmi_isr_handler.d \
./cpu/start.d \
./cpu/sysinit.d \
./cpu/vectors.d \

S_DEPS += \
./cpu/cw_crt0.d \

OBJS_QUOTED += \
"./cpu/arm_cm0.o" \
"./cpu/cw_crt0.o" \
"./cpu/nmi_isr_handler.o" \
"./cpu/start.o" \
"./cpu/sysinit.o" \
"./cpu/vectors.o" \

C_DEPS_QUOTED += \
"./cpu/arm_cm0.d" \
"./cpu/nmi_isr_handler.d" \
"./cpu/start.d" \
"./cpu/sysinit.d" \
"./cpu/vectors.d" \

OBJS_OS_FORMAT += \
./cpu/arm_cm0.o \
./cpu/cw_crt0.o \
./cpu/nmi_isr_handler.o \
./cpu/start.o \
./cpu/sysinit.o \
./cpu/vectors.o \


# Each subdirectory must supply rules for building sources it contributes
cpu/arm_cm0.o: $(CPU_ESCAPED)/arm_cm0.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"cpu/arm_cm0.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"cpu/arm_cm0.d" -o"cpu/arm_cm0.o"
	@echo 'Finished building: $<'
	@echo ' '

cpu/cw_crt0.o: $(CPU_ESCAPED)/cw_crt0.s
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC Assembler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"cpu/cw_crt0.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"cpu/cw_crt0.d" -o"cpu/cw_crt0.o"
	@echo 'Finished building: $<'
	@echo ' '

cpu/nmi_isr_handler.o: $(CPU_ESCAPED)/nmi_isr_handler.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"cpu/nmi_isr_handler.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"cpu/nmi_isr_handler.d" -o"cpu/nmi_isr_handler.o"
	@echo 'Finished building: $<'
	@echo ' '

cpu/start.o: $(CPU_ESCAPED)/start.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"cpu/start.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"cpu/start.d" -o"cpu/start.o"
	@echo 'Finished building: $<'
	@echo ' '

cpu/sysinit.o: $(CPU_ESCAPED)/sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"cpu/sysinit.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"cpu/sysinit.d" -o"cpu/sysinit.o"
	@echo 'Finished building: $<'
	@echo ' '

cpu/vectors.o: $(CPU_ESCAPED)/vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"cpu/vectors.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"cpu/vectors.d" -o"cpu/vectors.o"
	@echo 'Finished building: $<'
	@echo ' '


