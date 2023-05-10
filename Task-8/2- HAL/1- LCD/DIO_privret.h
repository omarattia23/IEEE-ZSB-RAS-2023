/****************************************/
/******* Name : Mina gerges*************/
/********Date : 4/29/2023 *************/
/********SWC  : DIO ******************/
/********Version : 1.0 **************/
/***********************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define DIO_u8_PORTA_REG           *((u8 *)0x3B)
#define DIO_u8_DDRA_REG           *((u8 *)0x3A)
#define DIO_u8_PINA_REG           *((u8 *)0x39)

#define DIO_u8_PORTB_REG           *((u8 *)0x38)
#define DIO_u8_DDRB_REG           *((u8 *)0x37)
#define DIO_u8_PINB_REG           *((u8 *)0x36)

#define DIO_u8_PORTC_REG           *((u8 *)0x35)
#define DIO_u8_DDRC_REG           *((u8 *)0x34)
#define DIO_u8_PINC_REG           *((u8 *)0x33)

#define DIO_u8_PORTD_REG           *((u8 *)0x32)
#define DIO_u8_DDRD_REG           *((u8 *)0x31)
#define DIO_u8_PIND_REG           *((u8 *)0x30)

/*Macros for Pins Direction */
#define DIO_u8_INTIAL_OUTPUT              1
#define DIO_u8_INTIAL_INPUT               0

/*Macros for Pins Values*/
#define DIO_u8_OUTPUT_LOW                 0
#define DIO_u8_OUTPUT_HIGH                1
#define DIO_u8_INPUT_FLOATING              0
#define DIO_u8_INPUT_PULLUP               1

#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)           Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif
