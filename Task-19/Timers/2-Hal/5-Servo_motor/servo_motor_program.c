/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 21/08/2023      *******************/
/**************** SWC     : servo_motor       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
/*lib layer*/
#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_Math.h"
/* MCAL */
#include "servo_motor_config.h"
#include "servo_motor_private.h"
#include "servo_motor_interface.h"
#include "../../1-MCAL/Timer/Timer_interface.h"
void Servo_void_SetServoAngle(u8 copy_u8_angle)
{
    u8 OCR_u8Value = ((1000 / 1023) * copy_u8_angle) + 999;
    Timers_voidTimer1SetCompareMatchValue(OCR_u8Value);
}
