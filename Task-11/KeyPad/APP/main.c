/* Lib */
#include "../LIB/BIT_Math.h"
#include "../LIB/STD_TYPES.h"
/* MCAL */
#include "../MCAL/DIO/DIO_interface.h"
/* HAL */
#include "../HAL/1-LCD/LCD_interface.h"
#include "../HAL/2-Keypad/KPD_interface.h"

#define F_CPU 1000000UL
#include <util/delay.h>

/***************************************************************************/
int main()
{
    /***************************************************************************/
    u8 Local_u8Key;
    u8 password[4] = {'1', '1', '1', '1'};
    u8 input[4] = {0}; // Initialize the input array with zeros
    u8 inputIndex = 0; // Initialize the input index to keep track of the current position
    /***************************************************************************/
    DIO_voidInit();  /* Initialize DIO */
    LCD_voideInit(); /* Initialize LCD */
    KPD_enuInit();   /* Initialize KPD */
    /***********************************************************************/
    const char *sentence = "Password:";
    u8 count; // variable to hold the count

    // Calculate the starting position for the sentence
    int sentenceLength = strlen(sentence);
    int startingPosition = (16 - sentenceLength) / 2;

    LCD_voidClearScreen();

    // Display the sentence in the middle of the LCD
    LCD_String_Position(0, startingPosition, sentence, &count);
    LCD_u8GoToXY(LCD_u8_LINE2, 3);
    /***********************************************************************/
    while (1)
    {
        KPD_u8getKeystate(&Local_u8Key);
        /*if there are no switches pressed
         No displaying on LCD*/
        if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
        {
            // Store the entered key in the input array
            input[inputIndex] = Local_u8Key;
            inputIndex++;

            // Display the entered key on the LCD
            LCD_voidSendChar('*');

            // Check if the input is complete
            if (inputIndex == 4)
            {
                int isPasswordCorrect = 1;

                for (int i = 0; i < 4; i++)
                {
                    if (input[i] != password[i])
                    {
                        isPasswordCorrect = 0;
                        break;
                    }
                }

                LCD_u8GoToXY(LCD_u8_LINE2, 3);
                // Check if the password is correct
                if (isPasswordCorrect)
                {
                    LCD_voidSendString("Welcome");
                }
                else
                {
                    // Display "Access Denied" message
                    LCD_voidSendString("Access Denied");
                }
                // Delay to display the result for some time
                _delay_ms(2000); // 2-second delay
                // Clear the second line
                LCD_voidClearSecondLine();

                // Reset the input array and index
                for (int i = 0; i < 4; i++)
                {
                    input[i] = 0;
                }
                inputIndex = 0;
            }
            
        }
    }

    return 0;
}
