/* Lib */
#include "../LIB/BIT_Math.h"
#include "../LIB/STD_TYPES.h"
/***************************************************************************/
/* MCAL */
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
/***************************************************************************/
/* HAL */
#include "../HAL/1-LCD/LCD_interface.h"
#define F_CPU 1000000UL
#include <util/delay.h>
static u16 App_u16_digitalValue = 0xffff;
static u16 App_u16_analogValue;
/***************************************************************************/
void App_void_ADC_CallBack(u16 Copy_u16ADCValue)
{
    ADC_u8GetADC_DigitalValue(&Copy_u16ADCValue);
}
/***************************************************************************/
int main()
{
    DIO_voidInit();
    LCD_voideInit();
    GI_voidEnable();
    ADC_VoidInit();
    while (1)
    {
        // LCD_voidSendString("Test0");
        ADC_u8GetDigitalValue_A_Synch(ADC_u8_Channel0, &App_void_ADC_CallBack);
        // LCD_voidSendString("Test1");
        // if (App_u16_digitalValue != 0xffff)
        // {
        App_u16_analogValue = (App_u16_digitalValue * 5000UL) / 1024;
        LCD_voidClearScreen();
        LCD_voidSendString(App_u16_analogValue);
        _delay_ms(100);
        // App_u16_digitalValue = 0xffff;
        // }
    }
    return 0;
}
