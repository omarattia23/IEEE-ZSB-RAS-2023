/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 31/07/2023      *******************/
/**************** SWC     : EXTI       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef EXTI_private.h
#define EXTI_private.h
/* Define for EXTI Registers */
#define EXTI_u8_MCUCR       *((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR      *((volatile u8 *)0x54)
#define EXTI_u8_GICR        *((volatile u8 *)0x5B)
#define EXTI_u8_GIFR        *((volatile u8 *)0x5A)
#define EXTI_u8_SREG        *((volatile u8 *)0x5f)

#define EXTI_u8_ISC0 0
#define EXTI_u8_ISC1 1
#define EXTI_u8_ISC2 2


#endif
