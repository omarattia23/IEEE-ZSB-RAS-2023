#include "../MCAL/DIO/DIO_interface.h"
#include  "../HAL/LCD/LCD_interface.h"

int main()
{
	DIO_voidInit();

	LCD_voideInit();

	LCD_u8GoToXY(LCD_u8_LINE1,5);


	LCD_voidSendChar('O');
	LCD_voidSendChar('m');
	LCD_voidSendChar('a');
	LCD_voidSendChar('r');

	while(1);

}
