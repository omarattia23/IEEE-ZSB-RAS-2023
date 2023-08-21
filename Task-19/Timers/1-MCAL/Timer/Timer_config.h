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
#define Timer_Prescaler_Value       CLK_8
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
/*
Select Timer1 mode:
    Normal_mode                           
    PWM_Phase_Correct_8_bit_mode          
    PWM_Phase_Correct_9_bit_mode          
    PWM_Phase_Correct_10_bit_mode         
    CTC_OCR1A_mode                        
    FAST_PWM_8_bit_mode                   
    FAST_PWM_9_bit_mode                   
    FAST_PWM_10_bit_mode                  
    PWM_Phase_and_Frequency_Correct_ICR1  
    PWM_Phase_and_Frequency_Correct_OCR1A 
    PWM_Phase_Correct_ICR1                
    PWM_Phase_Correct_OCR1A               
    CTC_ICR1_mode                         
    RESERVED_mode                         
    FAST_PWM_ICR1_mode                    
    FAST_PWM_OCR1A_mode                   
*/
#define Timer1_mode          FAST_PWM_ICR1_mode
/*
Select OCR1 mode
OCR1A_Inverting_Mode      
OCR1A_NonInverting_Mode   
OCR1B_Inverting_Mode      
OCR1B_NonInverting_Mode   
*/
#define OCR1_MODE OCR1A_NonInverting_Mode

#define ICR1_TOP_Value          19999
#define Servo_motor_angle_0     999
// #define Servo_motor_angle_90
#endif

