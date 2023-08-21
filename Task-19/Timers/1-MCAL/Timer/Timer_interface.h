/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 15/08/2023      *******************/
/**************** SWC     : Timer       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef Timer_interface_h
#define Timer_interface_h
void Timers_voidTimer0Init(void);
void Timers_voidTimer1Init(void);
u8 Timers_u8Timer0SetCallBack(void(*copy_pf)(void));
u8 Timers_u8Timer0CTCSetCallBack(void(*copy_pf)(void));
void Timers_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);
void Timers_voidTimer1SetCompareMatchValue(u16 Copy_u16OCR0Value);
#endif
