################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(COMMON)/alloc.c" \
"$(COMMON)/assert.c" \
"$(COMMON)/io.c" \
"$(COMMON)/memtest.c" \
"$(COMMON)/printf.c" \
"$(COMMON)/queue.c" \
"$(COMMON)/startup.c" \
"$(COMMON)/stdlib.c" \
"$(COMMON)/uif.c" \

C_SRCS += \
$(COMMON_ESCAPED)/alloc.c \
$(COMMON_ESCAPED)/assert.c \
$(COMMON_ESCAPED)/io.c \
$(COMMON_ESCAPED)/memtest.c \
$(COMMON_ESCAPED)/printf.c \
$(COMMON_ESCAPED)/queue.c \
$(COMMON_ESCAPED)/startup.c \
$(COMMON_ESCAPED)/stdlib.c \
$(COMMON_ESCAPED)/uif.c \

OBJS += \
./common/alloc.o \
./common/assert.o \
./common/io.o \
./common/memtest.o \
./common/printf.o \
./common/queue.o \
./common/startup.o \
./common/stdlib.o \
./common/uif.o \

C_DEPS += \
./common/alloc.d \
./common/assert.d \
./common/io.d \
./common/memtest.d \
./common/printf.d \
./common/queue.d \
./common/startup.d \
./common/stdlib.d \
./common/uif.d \

OBJS_QUOTED += \
"./common/alloc.o" \
"./common/assert.o" \
"./common/io.o" \
"./common/memtest.o" \
"./common/printf.o" \
"./common/queue.o" \
"./common/startup.o" \
"./common/stdlib.o" \
"./common/uif.o" \

C_DEPS_QUOTED += \
"./common/alloc.d" \
"./common/assert.d" \
"./common/io.d" \
"./common/memtest.d" \
"./common/printf.d" \
"./common/queue.d" \
"./common/startup.d" \
"./common/stdlib.d" \
"./common/uif.d" \

OBJS_OS_FORMAT += \
./common/alloc.o \
./common/assert.o \
./common/io.o \
./common/memtest.o \
./common/printf.o \
./common/queue.o \
./common/startup.o \
./common/stdlib.o \
./common/uif.o \


# Each subdirectory must supply rules for building sources it contributes
common/alloc.o: $(COMMON_ESCAPED)/alloc.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/alloc.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/alloc.d" -o"common/alloc.o"
	@echo 'Finished building: $<'
	@echo ' '

common/assert.o: $(COMMON_ESCAPED)/assert.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/assert.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/assert.d" -o"common/assert.o"
	@echo 'Finished building: $<'
	@echo ' '

common/io.o: $(COMMON_ESCAPED)/io.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/io.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/io.d" -o"common/io.o"
	@echo 'Finished building: $<'
	@echo ' '

common/memtest.o: $(COMMON_ESCAPED)/memtest.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/memtest.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/memtest.d" -o"common/memtest.o"
	@echo 'Finished building: $<'
	@echo ' '

common/printf.o: $(COMMON_ESCAPED)/printf.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/printf.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/printf.d" -o"common/printf.o"
	@echo 'Finished building: $<'
	@echo ' '

common/queue.o: $(COMMON_ESCAPED)/queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/queue.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/queue.d" -o"common/queue.o"
	@echo 'Finished building: $<'
	@echo ' '

common/startup.o: $(COMMON_ESCAPED)/startup.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/startup.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/startup.d" -o"common/startup.o"
	@echo 'Finished building: $<'
	@echo ' '

common/stdlib.o: $(COMMON_ESCAPED)/stdlib.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/stdlib.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/stdlib.d" -o"common/stdlib.o"
	@echo 'Finished building: $<'
	@echo ' '

common/uif.o: $(COMMON_ESCAPED)/uif.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"common/uif.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"common/uif.d" -o"common/uif.o"
	@echo 'Finished building: $<'
	@echo ' '


