################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/IEEE/Embedded/IEEE-ZSB-RAS-2023/Task-8/LED/DIO_program.c \
D:/IEEE/Embedded/IEEE-ZSB-RAS-2023/Task-8/LED/main.c 

O_SRCS += \
D:/IEEE/Embedded/IEEE-ZSB-RAS-2023/Task-8/LED/DIO_program.o 

OBJS += \
./LED/DIO_program.o \
./LED/main.o 

C_DEPS += \
./LED/DIO_program.d \
./LED/main.d 


# Each subdirectory must supply rules for building sources it contributes
LED/DIO_program.o: D:/IEEE/Embedded/IEEE-ZSB-RAS-2023/Task-8/LED/DIO_program.c LED/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

LED/main.o: D:/IEEE/Embedded/IEEE-ZSB-RAS-2023/Task-8/LED/main.c LED/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


