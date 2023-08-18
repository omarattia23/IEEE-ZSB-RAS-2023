/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 15/08/2023      *******************/
/**************** SWC     : Timer       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
/*lib layer*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
/* MCAL */
#include "Timer_config.h"
#include "Timer_private.h"
#include "Timer_interface.h"
/* Global Pointer to Function of Timer0 OVF*/
static void (*Timers_pfTimer0OVF)(void) = NULL;
static void (*Timers_pfTimer0CTC)(void) = NULL;
void Timers_voidTimer0Init(void)
{
/* Select Mode
Timer0_mode:
    1- Normal_mode
    2- Phase_Correct_mode
    3- CTC_mode
    4- FAST_PWM_mode
*/
#if Timer0_mode == Normal_mode
    CLR_BIT(TIMERS_u8_TCCR0_REG, 6);
    CLR_BIT(TIMERS_u8_TCCR0_REG, 3);
    /* Enable OVF Interrput*/
    SET_BIT(TIMERS_u8_TIMSK_REG, 0);
    /* set PreLoadValue*/
    TIMERS_u8_TCNT0_REG = Preload_Value;

#elif Timer0_mode == Phase_Correct_mode
    SET_BIT(TIMERS_u8_TCCR0_REG, 6);
    CLR_BIT(TIMERS_u8_TCCR0_REG, 3);
#elif Timer0_mode == CTC_mode
    CLR_BIT(TIMERS_u8_TCCR0_REG, 6);
    SET_BIT(TIMERS_u8_TCCR0_REG, 3);
    /* Enable CTC Interrupt */
    SET_BIT(TIMERS_u8_TIMSK_REG, 1);
    /* Compare Match Unit Value */
    TIMERS_u8_OCR0_REG = Compare_Match_Value;

#elif Timer0_mode == FAST_PWM_mode
    SET_BIT(TIMERS_u8_TCCR0_REG, 6);
    SET_BIT(TIMERS_u8_TCCR0_REG, 3);
#if inverting_mode == Fast_PWM_inverting
    SET_BIT(TIMERS_u8_TCCR0_REG, 4);
    SET_BIT(TIMERS_u8_TCCR0_REG, 5);
#elif inverting_mode == Fast_PWM_NON_inverting
    CLR_BIT(TIMERS_u8_TCCR0_REG, 4);
    SET_BIT(TIMERS_u8_TCCR0_REG, 5);
#endif
#endif
    /* Set PreScaler Value */
    TIMERS_u8_TCCR0_REG |= Timer0_Prescaler_Value;
}

void Timers_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value)
{
    TIMERS_u8_OCR0_REG = Copy_u8OCR0Value;
}

u8 Timers_u8Timer0SetCallBack(void (*copy_pf)(void))
{
    if (copy_pf != NULL)
    {
        Timers_pfTimer0OVF = copy_pf;
        return STD_TYPES_OK;
    }
    return STD_TYPES_NOK;
}

u8 Timers_u8Timer0CTCSetCallBack(void (*copy_pf)(void))
{
    if (copy_pf != NULL)
    {
        Timers_pfTimer0CTC = copy_pf;
        return STD_TYPES_OK;
    }
    return STD_TYPES_NOK;
}
/* Prototype for ISR of Timer0 OVF*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    static u16 Local_u16CouterOVF = 0;
    Local_u16CouterOVF++;
    if (Local_u16CouterOVF == 3907)
    {
        /* Update PreLoadValue */
        TIMERS_u8_TCNT0_REG = Preload_Value;
        /* clear the counter */
        Local_u16CouterOVF = 0;
        /* Call Application Function*/
        if (Timers_pfTimer0OVF != NULL)
        {
            Timers_pfTimer0OVF();
        }
    }
}
/* Prototype for ISR of Timer0 CTC */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
#if Compare_Match_Value != 0
    static Local_u16_counterCTC = 0;
    Local_u16_counterCTC++;
    if (Local_u16_counterCTC == 10000)
    {
        /* Clear Counter */
        Local_u16_counterCTC = 0;
        /* Call Back Function */
        if (Timers_pfTimer0CTC != NULL)
        {
            Timers_pfTimer0CTC();
        }
    }
#else
    if (Timers_pfTimer0CTC != NULL)
    {
        Timers_pfTimer0CTC();
    }
#endif
}
