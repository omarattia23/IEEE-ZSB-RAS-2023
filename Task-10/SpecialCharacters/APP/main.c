#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include <string.h>
#include <util/delay.h>

u8 Character1[8] = {0x0e, 0x0e, 0x04, 0x04, 0x1f, 0x04, 0x0a, 0x0a};
u8 Character2[8] = {0b00011111, 0b00001110, 0b00011111, 0b00000100, 0b00001110, 0b00011111, 0b00000100, 0b00000100};
u8 Character3[8] = {0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00};
u8 Character4[8] = {0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18};
u8 Character5[8] = {0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00};
u8 Character6[8] = {0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00};
u8 Character7[8] = {0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04};

int main()
{
	DIO_voidInit();	 /* Initialize DIO */
	LCD_voideInit(); /* Initialize LCD */

	const char *sentence = "Special Char";
	u8 count; // variable to hold the count

	// Calculate the starting position for the sentence
	int sentenceLength = strlen(sentence);
	int startingPosition = (16 - sentenceLength) / 2;

	// Display the sentence in the middle of the LCD
	LCD_String_Position(0, startingPosition, sentence);

	// Example button states (modify based on your setup)
	u8 button1_state = DIO_u8_LOW;
	u8 button2_state = DIO_u8_LOW;
	u8 button3_state = DIO_u8_LOW;
	u8 button4_state = DIO_u8_LOW;
	u8 button5_state = DIO_u8_LOW;
	u8 button6_state = DIO_u8_LOW;
	u8 button7_state = DIO_u8_LOW;

	// Example button special character mappings
	u8 *button1_special_char = Character1;
	u8 *button2_special_char = Character2;
	u8 *button3_special_char = Character3;
	u8 *button4_special_char = Character4;
	u8 *button5_special_char = Character5;
	u8 *button6_special_char = Character6;
	u8 *button7_special_char = Character7;

	while (1)
	{
		// Read the button states (modify based on your setup)
		button1_state = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN0,&button1_state);
		button2_state = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN1,&button2_state);
		button3_state = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN2,&button3_state);
		button4_state = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN3,&button4_state);
		button5_state = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN4,&button5_state);
		button6_state = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN5,&button6_state);
		button7_state = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN6,&button7_state);

		// Button 1
		if (button1_state == DIO_u8_HIGH)
		{
			LCD_voidSendSpecialCharacters(0, button1_special_char, LCD_u8_LINE2, count + 0, 0x40);
			_delay_ms(20);
		}

		// Button 2
		else if (button2_state == DIO_u8_HIGH)
		{
			LCD_voidSendSpecialCharacters(1, button2_special_char, LCD_u8_LINE2, count + 1, 0x50);
			_delay_ms(20);
		}

		// Button 3
		else if (button3_state == DIO_u8_HIGH)
		{
			LCD_voidSendSpecialCharacters(2, button3_special_char, LCD_u8_LINE2, count + 2, 0x58);
			_delay_ms(20);
		}
		// Button 4
		else if (button4_state == DIO_u8_HIGH)
		{
			LCD_voidSendSpecialCharacters(2, button4_special_char, LCD_u8_LINE2, count + 6, 0x60);
			_delay_ms(20);
		}
		// Button 5
		else if (button5_state == DIO_u8_HIGH)
		{
			LCD_voidSendSpecialCharacters(2, button5_special_char, LCD_u8_LINE2, count + 8, 0x68);
			_delay_ms(20);
		}
		// Button 6
		else if (button6_state == DIO_u8_HIGH)
		{
			LCD_voidSendSpecialCharacters(2, button6_special_char, LCD_u8_LINE2, count + 10, 0x70);
			_delay_ms(20);
		}
		// Button 7
		else if (button7_state == DIO_u8_HIGH)
		{
			LCD_voidSendSpecialCharacters(2, button7_special_char, LCD_u8_LINE2, count + 12, 0x78);
			_delay_ms(20);
		}
	}
}
