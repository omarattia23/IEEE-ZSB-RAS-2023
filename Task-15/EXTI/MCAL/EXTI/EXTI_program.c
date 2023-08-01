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
/* Global Pointer to a function */
static void (*EXTI_pfEXTI[3])(void) = {NULL};

u8 EXTI_u8Set_CallBack(void (*lpf)(void), u8 Copy_u8EXTI_Index) // *lpf is the local pointer to the function
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    if ((Copy_u8EXTI_Index <= EXTI_u8_IN2) && (lpf != NULL))
        EXTI_pfEXTI[Copy_u8EXTI_Index] = lpf;
    else
        Local_u8ErrorState = STD_TYPES_NOK;
    return Local_u8ErrorState;
}
/* Prototype fo ISR of EXTI0 */
void __vector__1(void) __attribute__((signal));
void __vector__1(void) // ISR(EXTI0)
{
    if (EXTI_pfEXTI[EXTI_u8_IN0 != NULL]) // to make sure that pointer is got a new address, and avoid a garbage value.
        EXTI_pfEXTI[0]();
}
/* Prototype fo ISR of EXTI1 */
void __vector__2(void) __attribute__((signal));
void __vector__2(void) // ISR(EXTI1)
{
    if (EXTI_pfEXTI[EXTI_u8_IN1 != NULL]) // to make sure that pointer is got a new address, and avoid a garbage value.
        EXTI_pfEXTI[1]();
}
/* Prototype fo ISR of EXTI2 */
void __vector__3(void) __attribute__((signal));
void __vector__3(void) // ISR(EXTI2)
{
    if (EXTI_pfEXTI[EXTI_u8_IN2 != NULL]) // to make sure that pointer is got a new address, and avoid a garbage value.
        EXTI_pfEXTI[2]();
}
