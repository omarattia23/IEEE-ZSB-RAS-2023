################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/IEEE/Embedded/IEEE-ZSB-RAS-2023/Task-8/2-\ HAL/1-\ LCD/LCD_program.c 

OBJS += \
./2-\ HAL/1-\ LCD/LCD_program.o 

C_DEPS += \
./2-\ HAL/1-\ LCD/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
2-\ HAL/1-\ LCD/LCD_program.o: D:/IEEE/Embedded/IEEE-ZSB-RAS-2023/Task-8/2-\ HAL/1-\ LCD/LCD_program.c 2-\ HAL/1-\ LCD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"2- HAL/1- LCD/LCD_program.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


