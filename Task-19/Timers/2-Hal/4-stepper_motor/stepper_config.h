/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : June 26th 2023 *******************/
/**************** SWC     : Stepper_Motor  ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef stepper_config_H
#define stepper_config_H

#define stepper_motor_port DIO_u8_PORTD

#define stepper_motor_blue          DIO_u8_PIN0
#define stepper_motor_pink          DIO_u8_PIN1
#define stepper_motor_yellow        DIO_u8_PIN3
#define stepper_motor_orange        DIO_u8_PIN4

#define STEPS_PER_REVOLUTION 2048

#endif
