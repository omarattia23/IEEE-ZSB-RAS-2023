#include "STD_TYPES.h"
#include "BIT_Math.h"

#include "DIO_interface.h"

void delay(void)
	{
		for(int x=0;x<500;x++)
			for(int y=0;y<500;y++)
				__asm("NOP");
	}
int main()

{

	DIO_voidInit();
			while(1)
			{

				DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
				delay();
				DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);

				delay();

			}
		return 0;

}
