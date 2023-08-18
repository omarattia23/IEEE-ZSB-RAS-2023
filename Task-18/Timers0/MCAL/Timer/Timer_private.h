/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 15/08/2023      *******************/
/**************** SWC     : Timer       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef Timer_private_h
#define Timer_private_h

/* Timer Registers */
#define REGISTER(reg) *((volatile u8 *)(reg))

#define TIMERS_u8_OCR0_REG              REGISTER(0x5C)
#define TIMERS_u8_TIMSK_REG             REGISTER(0x59)
#define TIMERS_u8_TIFR_REG              REGISTER(0x58)
#define TIMERS_u8_SPMCR_REG             REGISTER(0x57)
#define TIMERS_u8_TWCR_REG              REGISTER(0x56)
#define TIMERS_u8_MCUSR_REG             REGISTER(0x55)
#define TIMERS_u8_MCUCSR_REG            REGISTER(0x54)
#define TIMERS_u8_TCCR0_REG             REGISTER(0x53)
#define TIMERS_u8_TCNT0_REG             REGISTER(0x52)

/* Timer Modes */
#define Normal_mode         0
#define Phase_Correct_mode  1
#define CTC_mode            2
#define FAST_PWM_mode       3

/* Clock Select Options */
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
} Clock_Select;
/* define modes of fast PWM Mode */
#define Fast_PWM_inverting      0
#define Fast_PWM_NON_inverting  1
#endif
