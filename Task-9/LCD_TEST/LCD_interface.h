/************************************************/
/************* Name    : Omar Attia  ***********/
/************* Date    : 5/5/2023  ***********/
/************* SWC     : DIO      ************/
/************* Version : 1.0    *************/
/*******************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
void LCD_voidInit(void);
void LCD_voidSendCmd(u8 Copy_u8Cmd);
void LCD_voidSendChat(u8 Copy_u8Char);

#endif