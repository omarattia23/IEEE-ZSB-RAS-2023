/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 15/08/2023      *******************/
/**************** SWC     : Timer       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef Timer_config_h
#define Timer_config_h
/* Select Mode
Timer_mode:
    1- Normal_mode
    2- Phase_Correct_mode
    3- CTC_mode
    4- FAST_PWM_mode
*/
#define Timer0_mode                 FAST_PWM_mode 
#define Timer0_Prescaler_Value      CLK_8
#define Preload_Value               192
#define Compare_Match_Value         0
/* define modes of fast PWM Mode */
/* define modes of fast PWM Mode */
/*
select inverting mode:
    Fast_PWM_inverting    
    Fast_PWM_NON-inverting
*/
#define inverting_mode               Fast_PWM_NON_inverting
#endif

