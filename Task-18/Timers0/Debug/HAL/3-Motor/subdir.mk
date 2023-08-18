################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/3-Motor/Motor_programe.c 

OBJS += \
./HAL/3-Motor/Motor_programe.o 

C_DEPS += \
./HAL/3-Motor/Motor_programe.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/3-Motor/%.o: ../HAL/3-Motor/%.c HAL/3-Motor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


