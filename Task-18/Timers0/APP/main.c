/* Lib */
#include "../LIB/BIT_Math.h"
#include "../LIB/STD_TYPES.h"
/***************************************************************************/
/* MCAL */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/Timer/Timer_interface.h"
/***************************************************************************/
/* HAL */
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../HAL/1-LCD/LCD_interface.h"
/***************************************************************************/
//void App_voidToggleLED(void);

int main()
{
    u8 Local_u8CompareMatchValue = 0;
    DIO_voidInit();
    // LCD_voideInit();
    // GI_voidEnable();
    // Timers_u8Timer0CTCSetCallBack(&App_voidToggleLED);
    /* Start Timer */
    Timers_voidTimer0Init();
    // LCD_voidSendString("Counter: ");

    /* Supper Loop */
    while (1)
    {
        Timers_voidTimer0SetCompareMatchValue(Local_u8CompareMatchValue);
        Local_u8CompareMatchValue++;
        _delay_ms(50);
    }
    return 0;
}
//void App_voidToggleLED(void)
//{
//    static u8 counter = 0;
//    counter++;
//    LCD_u8GoToXY(LCD_u8_LINE1, 9);
//    LCD_void_SendNum(counter);
//}
