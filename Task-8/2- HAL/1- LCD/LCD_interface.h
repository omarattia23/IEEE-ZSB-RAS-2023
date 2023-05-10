/****************************************/
/******* Name : Mina gerges*************/
/********Date : 5/5/2023 **************/
/********SWC  : LCD ******************/
/********Version : 1.0 **************/
/***********************************/


#include "STD_TYPES.h"
#include "BIT_Math.h"

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H
#define LCD_u8_LINE1    1
#define LCD_u8_LINE2    2

void LCD_voideInit(void);
void LCD_voidSendCmnd(u8 Copy_u8Cmnd);
void LCD_voidSendChar(u8 Copy_u8Char);
u8 LCD_u8GoToXY(u8 Copy_u8lineNum,u8 Copy_u8Location);

#endif