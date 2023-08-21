/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : June 24th 2023 *******************/
/**************** SWC     : DC_Motor       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/***************************************************************************/
/*MCAL*/
#include "../../1-MCAL/DIO/DIO_interface.h"
/* HAL */
#include "Motor_interface.h"
#include "Motor_config.h"
#include "Motor_private.h"
/***************************************************************************/
void motor_rotate_cw()
{
    // Set the directions
    DIO_voidSetPinDirection(motor_port, motor_u8_pin1, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(motor_port, motor_u8_pin2, DIO_u8_OUTPUT);

    // Set one pin high and the other low to rotate the motor clockwise (CW)
    DIO_voidSetPinValue(motor_port, motor_u8_pin1, DIO_u8_HIGH);
    DIO_voidSetPinValue(motor_port, motor_u8_pin2, DIO_u8_LOW);
}

void motor_rotate_ccw()
{
    // Set the directions
    DIO_voidSetPinDirection(motor_port, motor_u8_pin1, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(motor_port, motor_u8_pin2, DIO_u8_OUTPUT);

    // Set one pin high and the other low to rotate the motor counterclockwise (CCW)
    DIO_voidSetPinValue(motor_port, motor_u8_pin1, DIO_u8_LOW);
    DIO_voidSetPinValue(motor_port, motor_u8_pin2, DIO_u8_HIGH);
}
void stopDCmotor(){
	DIO_voidSetPinValue(motor_port, motor_u8_pin1, DIO_u8_LOW);
	DIO_voidSetPinValue(motor_port, motor_u8_pin2, DIO_u8_LOW);
}
