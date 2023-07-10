#include "../MCAL/DIO/DIO_interface.h"
/* HAL */
#include "../HAL/1-LCD/LCD_interface.h"
#include "../HAL/2-Keypad/KPD_interface.h"
#define F_CPU 8000000UL
int main()
{
	u8 Local_u8Key;
	DIO_voidInit();
	/* Initialize LCD */
	LCD_voideInit();
	while (1)
	{
		KPD_u8getKeystate(&Local_u8Key);
		/*if there are no switches pressed
		 No displaying on LCD*/
		if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
		{

			LCD_voidSendChar(Local_u8Key);

		}
	}
	return 0;
}
