/****************************************/
/******* Name : Mina gerges*************/
/********Date : 5/5/2023 **************/
/********SWC  : LCD ******************/
/********Version : 1.0 **************/
/***********************************/
/* Lib*/

#include "STD_TYPES.h"
#include "BIT_Math.h"
#define F_CPU 1000000UL
#include <util/delay.h>


/*MCAL*/

#include "DIO_interface.h"

/*HAL*/
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"

void LCD_voideInit(void)
{
    _delay_ms(35);
    LCD_voidSendCmnd(0b00111000);
    _delay_us(40);
    LCD_voidSendCmnd(0b00001111);
    _delay_us(40);
    LCD_voidSendCmnd(0x01);
    _delay_ms(5);
    LCD_voidSendCmnd(0b00000110);

}

void LCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
    /* Rs = 0*/
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);

    /*Rw = 0*/
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);

    /*Write Command*/
    DIO_u8SetPortValue(DIO_u8_PORTD,Copy_u8Cmnd);

    /*E = 1*/
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
    _delay_us(1);

    /*E = 0*/
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
}

void LCD_voidSendChar(u8 Copy_u8Char)
{
     /* Rs = 1*/
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);

    /*Rw = 0*/
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);

    /*Write Command*/
    DIO_u8SetPortValue(DIO_u8_PORTD,Copy_u8Char);

    /*E = 1*/
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
    _delay_us(1);

    /*E = 0*/
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);

}


u8 LCD_u8GoToXY(u8 COPY_u8LineNum,u8 Copy_u8location)
{
    u8 local_u8Errorstate=STD_TYPES_OK;
    if(COPY_u8LineNum<=39){
    switch(COPY_u8LineNum)
    {
        case LCD_u8_LINE1: LCD_voidSendCmnd(0x80+Copy_u8location);  break;
        case LCD_u8_LINE2: LCD_voidSendCmnd(0xC0+Copy_u8location);  break;
        default :  local_u8Errorstate=STD_TYPES_OK;
    }
}
else { local_u8Errorstate=STD_TYPES_OK;}
return local_u8Errorstate;}


