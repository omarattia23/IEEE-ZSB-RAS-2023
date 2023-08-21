/************************************************/
/************* Name    : Omar Attia  ***********/
/************* Date    : 5/5/2023  ***********/
/************* SWC     : LCD      ************/
/************* Version : 1.0    *************/
/*******************************************/


#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_Math.h"

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#define LCD_u8_LINE1    0
#define LCD_u8_LINE2    1


void LCD_VoidInit(void);
void LCD_voidSendCmnd(u8 Copy_u8Cmnd);
void LCD_voidSendChar(u8 Copy_u8Char);
u8 LCD_u8GoToXY(u8 Copy_u8lineNum,u8 Copy_u8Location);

void LCD_voidClearScreen();
void LCD_voidClearSecondLine();
void LCD_voidSendString(const char *str);
void LCD_String_Position(char line, char pos, char *str);
void LCD_voidSendSpecialCharacters(u8 Copy_CharNum, u8 *Copy_u8P_Ptr, u8 Copy_u8LineNum, u8 Copy_u8Location, u8 Copy_u8SpecialCharStartBit);
void LCD_void_SendNum(u32 Copy_u32_Num);

#endif
