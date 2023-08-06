/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 05/08/2023     *******************/
/**************** SWC     : ADC            ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef ADC_config_h
#define ADC_config_h
/*
voltage reference options:
    1-AFEF
    2-AVCC
    3-reserved
    4-Internal_Voltage_Ref
*/
#define Voltage_Ref_ADMUX AVCC
/*
Adjecter options:
    1- Right_adj
    2- Left_adj
*/
#define Adjecter Right_adj
/*
Conversion options:
    1- Starting_Conversion
    2- Free_Running _onversion
    3- EXTI_Conversion
*/
#define Conversion_options Starting_Conversion

/*
CLK Options
    1- CLK_2MKHz
    2- CLK_4MKHz
    3- CLK_8MKHz
    4- CLK_16MKHz
    5- CLK_32MKHz
    6- CLK_64MKH
    7- CLK_128MKHz
*/
#define CLK_options CLK_8MKHz

#endif
