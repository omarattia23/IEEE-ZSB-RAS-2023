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
#define Timer0_mode                 CTC_mode 
#define Timer0_Prescaler_Value      External_clock_on_FallingEdge
#define Preload_Value               192
#define Compare_Match_Value         0
#endif

