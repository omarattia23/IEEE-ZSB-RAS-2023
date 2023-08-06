/* Lib */
#include "../LIB/BIT_Math.h"
#include "../LIB/STD_TYPES.h"
/* MCAL */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
/* HAL */
#include "../HAL/1-LCD/LCD_interface.h"
#define F_CPU 1000000UL
#include <util/delay.h>
u16 Local_u16_digitalValue, Local_u16_analogValue;
/***************************************************************************/
int main()
{
    /***************************************************************************/
    DIO_voidInit();
    LCD_voideInit();
    ADC_VoidInit();
    LCD_voidSendString("Hi,Omar");
    while (1)
    {
        ADC_u8GetDigitalValue(ADC_u8_Channel0, &Local_u16_digitalValue);
        Local_u16_analogValue = (Local_u16_digitalValue * 5000UL) / 1024;
        LCD_voidClearScreen();
        LCD_voidSendChar(Local_u16_analogValue);
        if (Local_u16_analogValue < 3000)
        {
            LCD_voidClearScreen();
            LCD_voidSendString("High");
        }
        else
        {
            LCD_voidClearScreen();
            LCD_voidSendString("Low");
        }
    }
    return 0;
}
