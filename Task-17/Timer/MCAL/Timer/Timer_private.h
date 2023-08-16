/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 15/08/2023      *******************/
/**************** SWC     : Timer       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef Timer_private_h
#define Timer_private_h
/* Timer Registers */
#define TIMERS_u8_OCR0_REG *((volatile u8 *)0x5C)
#define TIMERS_u8_TIMSK_REG *((volatile u8 *)0x59)
#define TIMERS_u8_TIFR_REG *((volatile u8 *)0x58)
#define TIMERS_u8_SPMCR_REG *((volatile u8 *)0x57)
#define TIMERS_u8_TWCR_REG *((volatile u8 *)0x56)
#define TIMERS_u8_MCUSR_REG *((volatile u8 *)0x55)
#define TIMERS_u8_MCUCSR_REG *((volatile u8 *)0x54)
#define TIMERS_u8_TCCR0_REG *((volatile u8 *)0x53)
#define TIMERS_u8_TCNT0_REG *((volatile u8 *)0x52)
/*
Timer0_mode:
    1- Normal_mode
    2- Phase_Correct_mode
    3- CTC_mode
    4- FAST_PWM_mode
*/
typedef enum
{
    Normal_mode,
    Phase_Correct_mod,
    CTC_mode,
    FAST_PWM_mode
} timers_mode;
/*
clock_select:
    0- No_clock_source
    1- CLK_NO_Prescaling
    2- CLK_8
    3- CLK_64
    4- CLK_256
    5- CLK_1024
    6- External_clock_on_FallingEdge
    7- External_clock_on_RisingEdge
*/
typedef enum
{
    No_clock_source,
    CLK_NO_Prescaling,
    CLK_8,
    CLK_64,
    CLK_256,
    CLK_1024,
    External_clock_on_FallingEdge,
    External_clock_on_RisingEdge
} ClockSelect;
#endif
