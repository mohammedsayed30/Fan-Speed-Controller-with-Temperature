################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD.c \
../adc.c \
../app.c \
../dc_motor.c \
../gpio.c \
../lm.c \
../pwm.c 

OBJS += \
./LCD.o \
./adc.o \
./app.o \
./dc_motor.o \
./gpio.o \
./lm.o \
./pwm.o 

C_DEPS += \
./LCD.d \
./adc.d \
./app.d \
./dc_motor.d \
./gpio.d \
./lm.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


