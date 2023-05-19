#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include <string.h>
#include <util/delay.h>

// u8 Character1[8] = { 0x01, 0x03, 0x07, 0x0D, 0x0F, 0x02, 0x05, 0x0A };
// u8 Character2[8] = { 0x10, 0x18, 0x1C, 0x16, 0x1E, 0x08, 0x14, 0x0A };
// u8 Character3[8] = { 0x01, 0x03, 0x07, 0x0D, 0x0F, 0x05, 0x08, 0x04 };
// u8 Character4[8] = { 0x10, 0x18, 0x1C, 0x16, 0x1E, 0x14, 0x02, 0x04 };
// u8 Character5[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18 };
// u8 Character6[8] = { 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00 };
// u8 Character7[8] = { 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00 };
// u8 Character8[8] = {0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00};
u8 Character1[8] = {0x0e, 0x0e, 0x04, 0x04, 0x1f, 0x04, 0x0a, 0x0a};
u8 Character2[8] = {0b00011111, 0b00001110, 0b00011111, 0b00000100, 0b00001110, 0b00011111, 0b00000100, 0b00000100};
u8 Character3[8] = {0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00};
u8 Character4[8] = {0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18};
u8 Character5[8] = {0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00};
u8 Character6[8] = {0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00};
u8 Character7[8] = {0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04};


const u8 SpecialChar3[8] = {
// Define the pattern for Special Character 3 here
		};

int main() {
	DIO_voidInit();

	LCD_voideInit();

	const char *sentence = "Speacial Char";
	u8 count; // variable to hold the count

	// Calculate the starting position for the sentence
	int sentenceLength = strlen(sentence);
	int startingPosition = (16 - sentenceLength) / 2;

	// Display the sentence in the middle of the LCD
	LCD_String_Position(0, startingPosition, sentence, &count);

	u8 button1_pin = DIO_u8_PIN0;
	u8 button2_pin = DIO_u8_PIN1;
	u8 button3_pin = DIO_u8_PIN2;
	u8 button4_pin = DIO_u8_PIN3;
	u8 button5_pin = DIO_u8_PIN4;
	u8 button6_pin = DIO_u8_PIN5;
	u8 button7_pin = DIO_u8_PIN6;

	// Example button states (modify based on your setup)
	u8 button1_state;
	u8 button2_state;
	u8 button3_state;
	u8 button4_state;
	u8 button5_state;
	u8 button6_state;
	u8 button7_state;

	// Example button special character mappings
	u8 *button1_special_char = Character1;
	u8 *button2_special_char = Character2;
	u8 *button3_special_char = Character3;
	u8 *button4_special_char = Character4;
	u8 *button5_special_char = Character5;
	u8 *button6_special_char = Character6;
	u8 *button7_special_char = Character7;

	while (1) {
		// Read the button states (modify based on your setup)
		button1_state = DIO_u8GetPinValue(DIO_u8_PORTB, button1_pin,
				&button1_state);
		button2_state = DIO_u8GetPinValue(DIO_u8_PORTB, button2_pin,
				&button2_state);
		button3_state = DIO_u8GetPinValue(DIO_u8_PORTB, button3_pin,
				&button3_state);
		button4_state = DIO_u8GetPinValue(DIO_u8_PORTB, button4_pin,
				&button3_state);
		button5_state = DIO_u8GetPinValue(DIO_u8_PORTB, button5_pin,
				&button3_state);
		button6_state = DIO_u8GetPinValue(DIO_u8_PORTB, button6_pin,
				&button3_state);
		button7_state = DIO_u8GetPinValue(DIO_u8_PORTB, button7_pin,
				&button3_state);

		// Button 1
		if (button1_state) {
			LCD_voidSendSpecialCharacters(0, button1_special_char, LCD_u8_LINE2,
					count + 0, 0b01000000);
		}

		// Button 2
		if (button2_state) {
			LCD_voidSendSpecialCharacters(1, button2_special_char, LCD_u8_LINE2,
					count + 2, 0x48);
					// Add a small delay to avoid unnecessary processing
		_delay_ms(1000);
		}

		// Button 3
		if (button3_state) {
			LCD_voidSendSpecialCharacters(2, button3_special_char, LCD_u8_LINE2,
					count + 4, 0x50);
					// Add a small delay to avoid unnecessary processing
		_delay_ms(1000);
		}
		// Button 4
		if (button4_state) {
			LCD_voidSendSpecialCharacters(2, button4_special_char, LCD_u8_LINE2,
					count + 6, 0x50);
					// Add a small delay to avoid unnecessary processing
		_delay_ms(1000);
		}
		// Button 5
		if (button5_state) {
			LCD_voidSendSpecialCharacters(2, button5_special_char, LCD_u8_LINE2,
					count + 8, 0x50);
					// Add a small delay to avoid unnecessary processing
		_delay_ms(1000);
		}
		// Button 6
		if (button6_state) {
			LCD_voidSendSpecialCharacters(2, button6_special_char, LCD_u8_LINE2,
					count + 10, 0x50);
					// Add a small delay to avoid unnecessary processing
		_delay_ms(1000);
		}
		// Button 7
		if (button7_state) {
			LCD_voidSendSpecialCharacters(2, button7_special_char, LCD_u8_LINE2,
					count + 12, 0x50);
		}

		// Add a small delay to avoid unnecessary processing
		_delay_ms(1000);
	}
}
