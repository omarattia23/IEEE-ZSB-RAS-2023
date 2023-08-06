/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 05/08/2023     *******************/
/**************** SWC     : ADC            ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
#ifndef ADC_interface_h
#define ADC_interface_h

#define ADC_u8_Channel0     0
#define ADC_u8_Channel1     1
#define ADC_u8_Channel2     2
#define ADC_u8_Channel3     3
#define ADC_u8_Channel4     4
#define ADC_u8_Channel5     5
#define ADC_u8_Channel6     6
#define ADC_u8_Channel7     7

void ADC_VoidInit(void);
u8 ADC_u8GetDigitalValue(u8 Copy_u8ChannelNum,u16 *Copy_pu16DigitalValue);
#endif
