#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#define F_CPU 1000000UL
#include <util/delay.h>
/***************************************************************************/
/*MCAL*/
#include "../../MCAL/DIO/DIO_interface.h"
/* HAL */
#include "stepper_config.h"
#include "stepper_interface.h"
#include "stepper_private.h"
/***************************************************************************/

// Function to control the stepper motor movement
void StepperMotor_move(u8 direction, u16 angle)
{
    // Set direction pins as OUTPUT
    DIO_voidSetPinDirection(stepper_motor_port, stepper_motor_blue, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(stepper_motor_port, stepper_motor_pink, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(stepper_motor_port, stepper_motor_yellow, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(stepper_motor_port, stepper_motor_orange, DIO_u8_OUTPUT);

    // Calculate the number of steps based on the motor's step angle and microstepping settings
    u16 steps = ((angle * STEPS_PER_REVOLUTION) / 360) / 4;

    if (direction == CW)
    {
        for (u16 i = 0; i < steps; i++)
        {
            // Define the step sequence for clockwise rotation
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_blue, DIO_u8_HIGH);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_pink, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_yellow, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_orange, DIO_u8_LOW);
            // Define the step sequence for clockwise rotation
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_blue, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_pink, DIO_u8_HIGH);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_yellow, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_orange, DIO_u8_LOW);
            // Define the step sequence for clockwise rotation
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_blue, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_pink, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_yellow, DIO_u8_HIGH);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_orange, DIO_u8_LOW);
            // Define the step sequence for clockwise rotation
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_blue, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_pink, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_yellow, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_orange, DIO_u8_HIGH);

            _delay_ms(StepperDelay); // Add a delay to control the motor speed
        }
    }
    else if (direction == CCW)
    {
        for (u16 i = 0; i < steps; i++)
        {
            // Define the step sequence for counterclockwise rotation
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_blue, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_pink, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_yellow, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_orange, DIO_u8_HIGH);
            // Define the step sequence for counterclockwise rotation
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_blue, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_pink, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_yellow, DIO_u8_HIGH);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_orange, DIO_u8_LOW);
            // Define the step sequence for counterclockwise rotation
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_blue, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_pink, DIO_u8_HIGH);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_yellow, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_orange, DIO_u8_LOW);
            // Define the step sequence for counterclockwise rotation
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_blue, DIO_u8_HIGH);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_pink, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_yellow, DIO_u8_LOW);
            DIO_voidSetPinValue(stepper_motor_port, stepper_motor_orange, DIO_u8_LOW);

            _delay_ms(StepperDelay); // Add a delay to control the motor speed
        }
    }
}
