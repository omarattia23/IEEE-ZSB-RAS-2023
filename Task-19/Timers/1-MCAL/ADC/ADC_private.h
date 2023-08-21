/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 05/08/2023     *******************/
/**************** SWC     : ADC            ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef ADC_private_h
#define ADC_private_h
/* ACD port is always at port a in atmega32 */
/* Define ADC Registers */
#define ADC_u8_ADMUX_REG *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG *((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG *((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG *((volatile u8 *)0x24)

#define ADC_u16_ADC_REG *((volatile u16 *)0x24)

#define ADC_u8_SFIOR_REG *((volatile u8 *)0x50)
/******************** Conversion Mode ********************/
#define AFEF 0
#define AVCC 1
#define reserved 2
#define Internal_Voltage_Ref 3
/********************************************************/
#define Right_adj 0
#define Left_adj 1
/******************************************************/
#define Starting_Conversion 0
#define Free_Running _onversion 1
#define EXTI_Conversion 2
/*********************** CLK ***************************/
#define CLK_2MKHz 0
#define CLK_4MKHz 1
#define CLK_8MKHz 2
#define CLK_16MKHz 3
#define CLK_32MKHz 4
#define CLK_64MKH 5
#define CLK_128MKHz 6
/*********************** REG BITS *********************/

/*ADC_u8_ADMUX_REG BITS*/
#define ADMUX_REG_REFS1_BIT 7
#define ADMUX_REG_REFS0_BIT 6
#define ADMUX_REG_ADLAR_BIT 5

/*ADC_u8_ADCSRA_REG BITS*/
#define ADCSRA_REG_ADPS0_BIT 0
#define ADCSRA_REG_ADPS1_BIT 1
#define ADCSRA_REG_ADPS2_BIT 2
#define ADCSRA_REG_ADIE_BIT 3
#define ADCSRA_REG_ADIF_BIT 4
#define ADCSRA_REG_ADATE_BIT 5
#define ADCSRA_REG_ADSC_BIT 6
#define ADCSRA_REG_ADEN_BIT 7
/*ADC_u8_SFIOR_REG BITS*/
#define SFIOR_REG_ADPS2_BIT 7
#define SFIOR_REG_ADPS1_BIT 6
#define SFIOR_REG_ADPS0_BIT 5

#endif
