/************************************************/
/************* Name    : Omar Attia  ***********/
/************* Date    : 30/4/2023  ***********/
/************* SWC     : DIO      ************/
/************* Version : 1.0    *************/
/*******************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#define DIO_u8_PORTA_REG    *((u8 *)0x3B)
#define DIO_u8_DDRA_REG     *((u8 *)0x3A)
#define DIO_u8_PINA_REG     *((u8 *)0x39)

#define DIO_u8_PORTB_REG    *((u8 *)0x38)
#define DIO_u8_DDRB_REG     *((u8 *)0x37)
#define DIO_u8_PINB_REG     *((u8 *)0x36)

#define DIO_u8_PORTC_REG    *((u8 *)0x35)
#define DIO_u8_DDRC_REG     *((u8 *)0x34)
#define DIO_u8_PINC_REG     *((u8 *)0x33)

#define DIO_u8_PORTD_REG    *((u8 *)0x32)
#define DIO_u8_DDRD_REG     *((u8 *)0x31)
#define DIO_u8_PIND_REG     *((u8 *)0x30)



#endif
