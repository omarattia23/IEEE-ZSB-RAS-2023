/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 31/07/2023      *******************/
/**************** SWC     : EXTI       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
/*lib layer*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
/* MCAL */
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
// void EXTI_voidEXTI0Enable(void)
// {
//     /* Enable Global Interrupt */
//     SET_BIT(EXTI_u8_SREG, 7);
//     /* 1- Select Edge Source ==> falling edge*/
//     SET_BIT(EXTI_u8_MCUCR, ISC11);
//     CLR_BIT(EXTI_u8_MCUCR, ISC10);
//     /* 2- Enable EXTI0 ==> PIE*/
//     SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN0);
// }
u8 EXTI_voidEnable(u8 Copy_u8EXTIIndex, u8 Copy_u8EdgeIndex)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    switch (Copy_u8EXTIIndex)
    {
    case EXTI_u8_IN0:
        switch (Copy_u8EdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR, 1);
            SET_BIT(EXTI_u8_MCUCR, 0);
            /* Enable EXTI0 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN0);
            break;
        case EXTI_u8_FLOATING_EDGE:
            SET_BIT(EXTI_u8_MCUCR, 1);
            CLR_BIT(EXTI_u8_MCUCR, 0);
            /* Enable EXTI0 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN0);
            break;
        case EXTI_u8_ANY_LOGICAL_CHANGE:
            CLR_BIT(EXTI_u8_MCUCR, 1);
            SET_BIT(EXTI_u8_MCUCR, 0);
            /* Enable EXTI0 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN0);
            break;
        case EXTI_u8_LOW_LEVEL:
            CLR_BIT(EXTI_u8_MCUCR, 1);
            CLR_BIT(EXTI_u8_MCUCR, 0);
            /* Enable EXTI0 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN0);
            break;
        default:
            Local_u8ErrorState = STD_TYPES_NOK;
        }
        break;
    /*****************************************************************/
    case EXTI_u8_IN1:
        switch (Copy_u8EdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR, 3);
            SET_BIT(EXTI_u8_MCUCR, 2);
            /* Enable EXTI1 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN1);
            break;
        case EXTI_u8_FLOATING_EDGE:
            SET_BIT(EXTI_u8_MCUCR, 3);
            CLR_BIT(EXTI_u8_MCUCR, 2);
            /* Enable EXTI1 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN1);
            break;
        case EXTI_u8_ANY_LOGICAL_CHANGE:
            CLR_BIT(EXTI_u8_MCUCR, 3);
            SET_BIT(EXTI_u8_MCUCR, 2);
            /* Enable EXTI1 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN1);
            break;
        case EXTI_u8_LOW_LEVEL:
            CLR_BIT(EXTI_u8_MCUCR, 3);
            CLR_BIT(EXTI_u8_MCUCR, 2);
            /* Enable EXTI1 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN1);
            break;
        default:
            Local_u8ErrorState = STD_TYPES_NOK;
        }
        break;
    /*****************************************************************/
    case EXTI_u8_IN2:
        switch (Copy_u8EdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_u8_MCUCSR, 6);
            /* Enable EXTI2 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN2);
            break;
        case EXTI_u8_FLOATING_EDGE:
            CLR_BIT(EXTI_u8_MCUCSR, 6);
            /* Enable EXTI2 */
            SET_BIT(EXTI_u8_GICR, EXTI_u8_PIN2);
            break;
        default:
            Local_u8ErrorState = STD_TYPES_NOK;
        }
        break;
    }
    return Local_u8ErrorState;
}
u8 EXTI_voidDisable(u8 Copy_u8EXTIIndex)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    switch (Copy_u8EXTIIndex)
    {
    case EXTI_u8_IN0:
        CLR_BIT(EXTI_u8_GICR, EXTI_u8_PIN0);
        break;
    case EXTI_u8_IN1:
        CLR_BIT(EXTI_u8_GICR, EXTI_u8_PIN1);
        break;
    case EXTI_u8_IN2:
        CLR_BIT(EXTI_u8_GICR, EXTI_u8_PIN2);
        break;
    default:
        Local_u8ErrorState = STD_TYPES_NOK;
    }

    return Local_u8ErrorState;
}
/***************************************************************************/
// /* Prototype fo ISR of EXTI0 */
// void __vector__1(void) __attribute__((signal));
// void __vector__1(void)
// {
//     static u8 logcal_u8_flag = 0;
//     if (logcal_u8_flag == 0)
//     {
//         DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_OUTPUT);
//         DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_HIGH);
//         logcal_u8_flag = 1;
//     }
//     else
//     {
//         DIO_voidSetPinDirection(DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_OUTPUT);
//         DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN6, DIO_u8_LOW);
//         logcal_u8_flag = 0;
//     }
// }
/***************************************************************************/
/* Prototype fo ISR of EXTI0 */
void __vector__1(void) __attribute__((signal));
void __vector__1(void)
{
    Tog_App();
}