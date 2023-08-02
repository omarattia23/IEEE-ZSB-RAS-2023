/************************************************/
/************* Name    : Omar Attia  ***********/
/************* Date    : 5/5/2023  ***********/
/************* SWC     : LCD      ************/
/************* Version : 1.0    *************/
/*******************************************/
/* Lib*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
#define F_CPU 1000000UL
#include <util/delay.h>

/*MCAL*/

#include "../../MCAL/DIO/DIO_interface.h"

/*HAL*/
#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"

void LCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
	/* Rs = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN0, DIO_u8_LOW);

	/*Rw = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN1, DIO_u8_LOW);

	/*Write Command*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd);

	/*E = 1*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_HIGH);
	_delay_us(1);

	/*E = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_LOW);
#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
	// code to send a command at 4 bits Mode

	/* Rs = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN0, DIO_u8_LOW);

	/*Rw = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN1, DIO_u8_LOW);

	/*Write Command*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd);

	/*E = 1*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_HIGH);
	_delay_us(1);

	/*E = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_LOW);

	// Write the rest of the command
	DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, Copy_u8Cmnd << 4);
	/*E = 1*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_HIGH);
	_delay_us(1);

	/*E = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_LOW);
#endif
}

void LCD_voidSendChar(u8 Copy_u8Char)
{

#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
	/* Rs = 1*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN0, DIO_u8_HIGH);

	/*Rw = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN1, DIO_u8_LOW);

	/*Write Command*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char);

	/*E = 1*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_HIGH);
	_delay_us(1);

	/*E = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_LOW);

#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
	/* Rs = 1*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN0, DIO_u8_HIGH);

	/*Rw = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN1, DIO_u8_LOW);

	/*Write Command*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char);

	/*E = 1*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_HIGH);
	_delay_us(1);

	/*E = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_LOW);
	// Write the rest of the command
	DIO_u8SetPortValue(LCD_u8_CONTROL_PORT, Copy_u8Char << 4);
	/*E = 1*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_HIGH);
	_delay_us(1);

	/*E = 0*/
	DIO_voidSetPinValue(LCD_u8_CONTROL_PORT, DIO_u8_PIN2, DIO_u8_LOW);

#endif
}
void LCD_voideInit(void)
{
#if LCD_u8_MODE == LCD_u8_MODE_8BIT
	_delay_ms(35);
	// Function set cmd
	LCD_voidSendCmnd(0b00111000); // set for 8bits
	_delay_us(40);
	LCD_voidSendCmnd(0b00001111); // display ON/OFF command
	_delay_us(40);
	LCD_voidSendCmnd(0x01); // clear 8 bits
	_delay_ms(5);
	LCD_voidSendCmnd(0b00000110); // set mood for 8 bits

#elif (LCD_u8_MODE == LCD_u8_MODE_4BIT)
	_delay_ms(35);
	// Function set cmd
	LCD_voidSendCmnd(0b00100010); // set for 8bits
	_delay_us(40);
	LCD_voidSendCmnd(0b00001111); // display ON/OFF command
	_delay_us(40);
	LCD_voidSendCmnd(0x01); // clear 8 bits
	_delay_ms(5);
	LCD_voidSendCmnd(0b00000110); // set mood for 8 bits

#endif
}

u8 LCD_u8GoToXY(u8 COPY_u8LineNum, u8 Copy_u8location)
{
	u8 local_u8Errorstate = STD_TYPES_OK;
	if (COPY_u8LineNum <= 39)
	{
		switch (COPY_u8LineNum)
		{
		case LCD_u8_LINE1:
			LCD_voidSendCmnd(0x80 + Copy_u8location);
			break;
		case LCD_u8_LINE2:
			LCD_voidSendCmnd(0xC0 + Copy_u8location);
			break;
		default:
			local_u8Errorstate = STD_TYPES_OK;
		}
	}
	else
	{
		local_u8Errorstate = STD_TYPES_OK;
	}
	return local_u8Errorstate;
}
void LCD_voidClearScreen()
{
	LCD_voidSendCmnd(0x01);
	_delay_ms(2);
	LCD_voidSendCmnd(0x80);
}
void LCD_voidSendString(const char *str)
{
	u8 i = 0;
	while (str[i] != '\0')
	{
		LCD_voidSendChar(str[i]);
		i++;
	}
}
void LCD_String_Position(char line, char pos, char *str)
{
    // Ensure the line and position values are within valid ranges
    if (line >= 0 && line <= 1 && pos >= 0 && pos <= 15)
    {
        // Calculate the starting DDRAM address for the specified line and position
        u8 line_offset = (line == 0) ? 0x00 : 0x40;
        u8 ddr_addr = (pos & 0x0F) | line_offset | 0x80;

        // Set the DDRAM address to move the cursor to the desired position
        LCD_voidSendCmnd(ddr_addr);

        // Internal counter to keep track of characters printed
        u8 counter = 0;
		
        // Print the string until null terminator is encountered or the line is full
        for (u8 i = 0; str[i] != '\0' && counter < 16; i++)
        {
            LCD_voidSendChar(str[i]);
            counter++; // Increment the internal counter for each character printed
        }

        // If the string is shorter than 16 characters, pad the remaining characters with spaces
        while (counter < 16)
        {
            LCD_voidSendChar(' ');
            counter++;
        }

        // Move to the second line if there are remaining characters to be displayed
        if (line == 0 && str[counter] != '\0')
        {
            LCD_voidSendCmnd(0xC0); // Move the cursor to the beginning of the second line
            counter = 0;

            // Print the rest of the string on the second line
            for (u8 i = 16; str[i] != '\0' && counter < 16; i++)
            {
                LCD_voidSendChar(str[i]);
                counter++; // Increment the internal counter for each character printed on the second line
            }
        }
    }
}


void LCD_voidSendSpecialCharacters(u8 Copy_CharNum, u8 *Copy_u8P_Ptr, u8 Copy_u8LineNum, u8 Copy_u8Location, u8 Copy_u8SpecialCharStartBit)
{
	LCD_voidSendCmnd(Copy_u8SpecialCharStartBit);
	for (int i = 0; i < 8; i++)
	{
		LCD_voidSendChar(Copy_u8P_Ptr[i]);
	}
	LCD_u8GoToXY(Copy_u8LineNum, Copy_u8Location);
	LCD_voidSendChar(Copy_CharNum);

	if (Copy_u8Location > 15)
	{
		LCD_voidClearScreen();
		LCD_u8GoToXY(0, 0);
		LCD_voidSendChar(Copy_CharNum);
	}
}
void LCD_voidClearSecondLine()
{
	LCD_u8GoToXY(LCD_u8_LINE2, 0); // Move cursor to the start of the second line
	// Send a string of spaces to clear the second line
	for (int i = 0; i < 16; i++)
	{
		LCD_voidSendChar(' ');
	}
	LCD_u8GoToXY(LCD_u8_LINE2, 3); // Move cursor to the start of the second line
}
