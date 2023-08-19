################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../2-Hal/3-Motor/Motor_programe.c 

OBJS += \
./2-Hal/3-Motor/Motor_programe.o 

C_DEPS += \
./2-Hal/3-Motor/Motor_programe.d 


# Each subdirectory must supply rules for building sources it contributes
2-Hal/3-Motor/%.o: ../2-Hal/3-Motor/%.c 2-Hal/3-Motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


