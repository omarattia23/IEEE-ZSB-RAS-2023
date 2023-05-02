/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MACH */
#include "DIO_INTERFACE.h"
int main(){
    /* Configue PC7 output */
    DIO_voidInit();
    while(1){
        /* Turn on Led */
        DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_HIGH);
        _delay_ms(500);
        DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_LOW);
        _delay_ms(500);
    }
    return 0;
}
