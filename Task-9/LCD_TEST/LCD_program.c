/************************************************/
/************* Name    : Omar Attia  ***********/
/************* Date    : 5/5/2023  ***********/
/************* SWC     : DIO      ************/
/************* Version : 1.0    *************/
/*******************************************/
/* LIB */
#include "STD_TYPES.h"
#include "BITMATH.h"
/* MCAL */
#include "DIO_interface.h"
/* HAL*/
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#define F_CPU 8000000UL
#include <util/delay.h>
void LCD_voidInit(void)
{
    _delay_ms(35);
    // Function Set CMD
    LCD_voidSendCmd(0b00111000);
    _delay_us(40);
    LCD_voidSendCmd(0b00001111);
    _delay_us(40);
    LCD_voidSendCmd(0b00000001);
    _delay_ms(2);
    LCD_voidSendCmd(0b00000110);

}
void LCD_voidSendCmd(u8 Copy_u8Cmd)
{
    // STEP 1: RS = 0
    DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, LCD_u8_PRS_PIN,DIO_u8_Low);
    // RW = 0
    DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN,DIO_u8_Low);
    // Write command
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmd);
    // En = 1
    DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN,DIO_u8_HIGH);
    _delay_us(1);
    // En = 0
    DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN,DIO_u8_Low);

}
void LCD_voidSendChat(u8 Copy_u8Char)
{
    // STEP 1: RS = 0
    DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, LCD_u8_PRS_PIN,DIO_u8_HIGH);
    // RW = 0
    DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, LCD_u8_RW_PIN,DIO_u8_Low);
    // Write Char
    DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
    // En = 1
    DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN,DIO_u8_HIGH);
    _delay_us(1);
    // En = 0
    DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, LCD_u8_EN_PIN,DIO_u8_Low);
}