#include "STD_TYPES.h"
#include "BIT_Math.h"

#include "DIO_interface.h"
#include  "LCD_interface.h"

int main()
{
	DIO_voidInit();

	LCD_voideInit();

	LCD_u8GoToXY(LCD_u8_LINE1,5);


	LCD_voidSendChar('m');
	LCD_voidSendChar('i');
	LCD_voidSendChar('n');
	LCD_voidSendChar('a');

	while(1);

}
