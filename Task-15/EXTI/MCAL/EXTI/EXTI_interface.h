/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 31/07/2023      *******************/
/**************** SWC     : EXTI       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef EXTI_interface_h
#define EXTI_interface_h
#define EXTI_u8_IN0 0
#define EXTI_u8_IN1 1
#define EXTI_u8_IN2 2
/* Macros for Edge source */
#define EXTI_u8_RAISING_EDGE 0
#define EXTI_u8_FLOATING_EDGE 1
#define EXTI_u8_ANY_LOGICAL_CHANGE 2
#define EXTI_u8_LOW_LEVEL 3
// void EXTI_voidEXTI0Enable(void);
u8 EXTI_voidEnable(u8 Copy_u8EXTIIndex, u8 Copy_u8EdgeIndex);
u8 EXTI_voidDisable(u8 Copy_u8EXTIIndex);
u8 EXTI_u8Set_CallBack(void (*lpf)(void), u8 Copy_u8EXTI_Index);

#endif
