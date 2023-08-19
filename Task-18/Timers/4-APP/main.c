/* Lib */
#include "../0-LIB/BIT_Math.h"
#include "../0-LIB/STD_TYPES.h"
/***************************************************************************/
/* MCAL */
#include "../1-MCAL/DIO/DIO_interface.h"
#include "../1-MCAL/GI/GI_interface.h"
#include "../1-MCAL/Timer/Timer_interface.h"
/***************************************************************************/
/* HAL */
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../2-HAL/1-LCD/LCD_interface.h"
/***************************************************************************/

int main()
{
    DIO_voidInit();
    Timers_voidTimer1Init();
    /* Supper Loop */
    while (1)
    {
        Timers_voidSetServoAngle(45); // other stuff
    }
    return 0;
}
