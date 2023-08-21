/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 15/08/2023      *******************/
/**************** SWC     : Timer       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef Timer_private_h
#define Timer_private_h

/* Timer Registers */
#define REGISTER_u8(reg) *((volatile u8 *)(reg))
#define REGISTER_u16(reg) *((volatile u16 *)(reg))
/* Timer0 Regisers */
#define TIMERS_u8_OCR0_REG              REGISTER_u8(0x5C)
#define TIMERS_u8_TIMSK_REG             REGISTER_u8(0x59)
#define TIMERS_u8_TIFR_REG              REGISTER_u8(0x58)
#define TIMERS_u8_SPMCR_REG             REGISTER_u8(0x57)
#define TIMERS_u8_TWCR_REG              REGISTER_u8(0x56)
#define TIMERS_u8_MCUSR_REG             REGISTER_u8(0x55)
#define TIMERS_u8_MCUCSR_REG            REGISTER_u8(0x54)
#define TIMERS_u8_TCCR0_REG             REGISTER_u8(0x53)
#define TIMERS_u8_TCNT0_REG             REGISTER_u8(0x52)
/* Timer0 Regisers */
#define TIMERS_u8_TCCR1A_REG            REGISTER_u8(0x4F)
#define TIMERS_u8_TCCR1B_REG            REGISTER_u8(0x4E)

#define TIMERS_u8_TCNT1H_REG            REGISTER_u8(0x4D)
#define TIMERS_u8_TCNT1L_REG            REGISTER_u8(0x4C)
#define TIMERS_u16_TCNT1_REG            REGISTER_u16(0x4C)

#define TIMERS_u8_OCR1AH_REG            REGISTER_u8(0x4B)
#define TIMERS_u8_OCR1AL_REG            REGISTER_u8(0x4A)
#define TIMERS_u16_OCR1A_REG            REGISTER_u16(0x4A)

#define TIMERS_u8_OCR1BH_REG            REGISTER_u8(0x49)
#define TIMERS_u8_OCR1BL_REG            REGISTER_u8(0x48)
#define TIMERS_u16_OCR1B_REG            REGISTER_u16(0x48)

#define TIMERS_u8_ICR1H_REG             REGISTER_u8(0x47)
#define TIMERS_u8_ICR1L_REG             REGISTER_u8(0x46)
#define TIMERS_u16_ICR1_REG             REGISTER_u16(0x46)

/* Timer1 Modes */
#define Normal_mode                                     0
#define PWM_Phase_Correct_8_bit_mode                    1
#define PWM_Phase_Correct_9_bit_mode                    2
#define PWM_Phase_Correct_10_bit_mode                   3
#define CTC_OCR1A_mode                                  4
#define FAST_PWM_8_bit_mode                             5
#define FAST_PWM_9_bit_mode                             6
#define FAST_PWM_10_bit_mode                            7
#define PWM_Phase_and_Frequency_Correct_ICR1            8
#define PWM_Phase_and_Frequency_Correct_OCR1A           9
#define PWM_Phase_Correct_ICR1                          10
#define PWM_Phase_Correct_OCR1A                         11
#define CTC_ICR1_mode                                   12
#define RESERVED_mode                                   13
#define FAST_PWM_ICR1_mode                              14
#define FAST_PWM_OCR1A_mode                             15
/* OCR1 OPTIONS */
#define OCR1A_Inverting_Mode                            0
#define OCR1A_NonInverting_Mode                         1
#define OCR1B_Inverting_Mode                            2
#define OCR1B_NonInverting_Mode                         3



/* Timer1 Modes */
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
