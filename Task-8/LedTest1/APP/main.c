#include "../MCAL/DIO/DIO_interface.h"
#define CPU 1000000
void delay(int time)
{
	int cylces = (time * CPU) / 1000;
	for (int x = 0; x < cylces; x++)
		__asm("NOP");
}
int main()
{
	DIO_voidInit();
	while (1)
	{
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_HIGH);
		delay(1000);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, DIO_u8_LOW);
		delay(1000);
	}
	return 0;
}
