/* Lib */
#include "../0-LIB/BIT_Math.h"
#include "../0-LIB/STD_TYPES.h"
/***************************************************************************/
/* MCAL */
#include "../1-MCAL/DIO/DIO_interface.h"
// #include "../1-MCAL/Timer/Timer_interface.h"
// #include "../1-MCAL/GI/GI_interface.h"
// #include "../1-MCAL/ADC/ADC_interface.h"
/***************************************************************************/
/* HAL */
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../2-HAL/1-LCD/LCD_interface.h"
// #include "../2-HAL/2-Keypad/KPD_interface.h"
// #include "../2-HAL/5-servo_motor/servo_motor_interface.h"
/***************************************************************************/
// u8 flag = 0;
// u8 flag1 = 1;
// u8 flag2 = 0;
// u8 flag3 = 0;
// /***************************************************************************/
// void correctpassword()
// {
//     LCD_voidClearScreen();
//     LCD_String_Position(LCD_u8_LINE1, 0, "Welcome to Motor Dashboard");
//     _delay_ms(3000);
//     LCD_voidClearScreen();
//     LCD_String_Position(LCD_u8_LINE1, 0, "1-DC Motor3-Exit2-Stepper Motor");
// }
// /***************************************************************************/
// void wrongpassword()
// {
//     // Display "Access Denied" message
//     LCD_voidClearScreen();
//     const char *denied = "Access Denied";
//     int deined_pos = (16 - strlen(denied)) / 2;
//     LCD_String_Position(LCD_u8_LINE1, deined_pos, denied);
//     // LCD_voidSendString();
//     flag++;
//     // Delay to display the result for some time
//     _delay_ms(2000); // 2-second delay
//     // Clear the second line
//     LCD_voidClearSecondLine();
// }
// /***************************************************************************/
// void DCmotor_options()
// {
//     LCD_voidClearScreen();
//     LCD_String_Position(LCD_u8_LINE1, 0, "1-RotateCW3-Back2-RotateCCW");
// }
// /***************************************************************************/
// void DCMotor()
// {
//     u8 options;
//     flag1 = 0;
//     flag2 = 1;
//     flag3 = 0;
//     DCmotor_options();
//     while (flag2)
//     {
//         KPD_u8getKeystate(&options);
//         if (options != KPD_u8_KEY_NOT_PRESSED)
//         {
//             switch (options)
//             {
//             case '1':
//                 motor_rotate_cw(); // Implement this function
//                 break;
//             case '2':
//                 motor_rotate_ccw(); // Implement this function
//                 break;
//             case '3':              // back to
//                 stopDCmotor();     // stop the motor running
//                 correctpassword(); // get back to welcome motor
//                 flag2 = 0;
//                 flag1 = 1;
//                 flag3 = 0;
//                 break;
//             }
//         }
//     }
// }
// /***************************************************************************/
// void stepperMotor()
// {
//     u8 stepperOptions;
//     flag1 = 0;
//     flag2 = 0;
//     flag3 = 1;
//     LCD_voidClearScreen();
//     LCD_String_Position(LCD_u8_LINE1, 0, "1-Rotate CW     2-Rotate CCW");
//     while (flag3)
//     {
//         KPD_u8getKeystate(&stepperOptions);
//         if (stepperOptions != KPD_u8_KEY_NOT_PRESSED)
//         {
//             switch (stepperOptions)
//             {
//             case '1':
//                 StepperMotor_move(0, 120); // Implement this function
//                 break;
//             case '2':
//                 motor_rotate_ccw(1, 120); // Implement this function
//                 break;
//             }
//         }
//     }
// }

// /* Toggle Application */
// void Toggle_App(void)
// {
//     DIO_voidSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_OUTPUT);
//     DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_HIGH);
//     u8 Local_u8Key;
//     u8 password[4] = {'1', '2', '3', '4'};
//     u8 input[4] = {0}; // Initialize the input array with zeros
//     u8 inputIndex = 0; // Initialize the input index to keep track of the current position
//     /***************************************************************************/

//     /***********************************************************************/
//     const char *sentence = "Pass word:";

//     // Calculate the starting position for the sentence
//     LCD_voidClearScreen();
//     int sentenceLength = strlen(sentence);
//     int startingPosition = (16 - sentenceLength) / 2;

//     // Display the sentence in the middle of the LCD
//     LCD_String_Position(LCD_u8_LINE1, startingPosition, sentence);
//     // Clear the second line
//     LCD_voidClearSecondLine();
//     LCD_u8GoToXY(LCD_u8_LINE2, 6);

//     /***********************************************************************/
//     while (flag < 3)
//     {
//         KPD_u8getKeystate(&Local_u8Key);
//         /*if there are no switches pressed
//          No displaying on LCD*/
//         if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
//         {
//             // Store the entered key in the input array
//             input[inputIndex] = Local_u8Key;
//             inputIndex++;
//             // Display the entered key on the LCD
//             LCD_voidSendChar('*');
//             // Check if the input is complete
//             if (inputIndex == 4)
//             {
//                 int isPasswordCorrect = 1;
//                 // compare the entered password with the actual password
//                 for (int i = 0; i < 4; i++)
//                 {
//                     if (input[i] != password[i])
//                     {
//                         isPasswordCorrect = 0;
//                         break;
//                     }
//                 }
//                 // Check if the password is correct
//                 if (isPasswordCorrect)
//                 {
//                     flag = 3;

//                     correctpassword();
//                     while (flag1)
//                     {
//                         KPD_u8getKeystate(&Local_u8Key);
//                         if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
//                         {
//                             switch (Local_u8Key)
//                             {
//                             case '1': // DC motor choise
//                                 DCMotor();
//                                 break;
//                             case '2': // stepper motor
//                                 stepperMotor();
//                                 break;
//                             case '3':                  // stepper motor
//                                 LCD_voidClearScreen(); // clear the screen
//                                 LCD_voidSendString("Exit the system");
//                                 break;
//                             }
//                         }
//                     }
//                 }
//                 else
//                 {
//                     wrongpassword();
//                 }

//                 // Reset the input array and index
//                 for (int i = 0; i < 4; i++)
//                 {
//                     input[i] = 0;
//                 }
//                 inputIndex = 0;
//             }
//         }
//     }
// }

int main()
{
    // u16 Local_u16DigitalValue;
    DIO_voidInit(); /* Initialize DIO */
    LCD_VoidInit(); /* Initialize LCD */
    LCD_voidClearScreen();
    LCD_u8GoToXY(0,0);
    LCD_voidSendString("Test");
    
    // KPD_enuInit();  /* Initialize KPD */
    // ADC_VoidInit();
    // Timers_voidTimer1Init();
    
    // Toggle_App();

    /* Supper Loop */
    while (1)
    {
        //        void Toggle_App(void); // Toggle Security System
        // ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_Channel0, &Local_u16DigitalValue);
        // Servo_void_SetServoAngle(Local_u16DigitalValue);
    }
    return 0;
}
