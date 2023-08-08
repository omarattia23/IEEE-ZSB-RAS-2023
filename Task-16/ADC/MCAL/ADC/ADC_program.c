/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 05/08/2023     *******************/
/**************** SWC     : ADC            ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
/*lib layer*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
/* MCAL */
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"
/**********************************************************************/
static void (*ADC_pfNotification)(u16) = NULL;
// ADC Busy Flag
static u8 ADC_u8BusyFlag = 0;
/**********************************************************************/
void ADC_VoidInit(void)
{
    /*
    TODO: 1- Select Vref = AVCC
    TODO: 2- Right Adjuster
    TODO: 3- Select CLk/8 for 1MKHS
    TODO: 4- Enable ADC
    */
#if Voltage_Ref_ADMUX == AFEF
    CLR_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_REFS1_BIT);
    CLR_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_REFS0_BIT);

#elif Voltage_Ref_ADMUX == AVCC
    CLR_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_REFS1_BIT);
    SET_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_REFS0_BIT);
#elif Voltage_Ref_ADMUX == reserved
    SET_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_REFS1_BIT);
    CLR_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_REFS0_BIT);
#elif Voltage_Ref_ADMUX == Internal_Voltage_Ref
    SET_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_REFS1_BIT);
    SET_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_REFS0_BIT);
#endif
/*************************** Adjecter control ***************************/
#if Adjecter == Right_adj
    CLR_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_ADLAR_BIT);
#elif Adjecter == Left_adj
    SET_BIT(ADC_u8_ADMUX_REG, ADMUX_REG_ADLAR_BIT);
#endif
/*********************** conversion mode control ***********************/
#if Conversion_options == Starting_Conversion
    SET_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADEN_BIT);
#elif Conversion_options == Free_Running _onversion
    CLR_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADEN_BIT);

    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
#elif Conversion_options == EXTI_Conversion
    CLR_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADEN_BIT);

    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
#endif
/*************************** division Factor ***************************/
#if CLK_options == CLK_2MKHz
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
#elif CLK_options == CLK_4MKHz
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
#elif CLK_options == CLK_8MKHz
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
#elif CLK_options == CLK_16MKHz
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
#elif CLK_options == CLK_32MKHz
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
#elif CLK_options == CLK_64MKH
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    CLR_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
#elif CLK_options == CLK_128MKHz
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS2_BIT);
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS1_BIT);
    SET_BIT(ADC_u8_SFIOR_REG, SFIOR_REG_ADPS0_BIT);
#endif
    /***************************** Enable ADC *****************************/
    SET_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADEN_BIT);
}

/**********************************************************************/
u8 ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNum, u16 *Copy_pu16DigitalValue)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    u32 Local_u32TimeOutCounter = 0;
    if ((Copy_u8ChannelNum < 32) && (Copy_pu16DigitalValue != NULL) && (ADC_u8BusyFlag == 0))
    {
        // Clear the channel selection bits and set the new channel number
        ADC_u8_ADMUX_REG &= 0xE0;
        ADC_u8_ADMUX_REG |= (Copy_u8ChannelNum & 0x1F);
        /* Start Conversion */
        SET_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADSC_BIT);
        /* wait flag = 1 */
        while ((GET_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADIF_BIT) == 0) && (Local_u32TimeOutCounter < ADC_u32_TimeOut_MaxValue))
        {
            Local_u32TimeOutCounter++;
        }
        /*
        ************************** Clear Flag **********************
        ! flag is cleared automatically when it is at EXTI
        % In our situation, we have to clear the flag by ourselves
        ************************************************************
        */
        if (GET_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADIF_BIT) != 0) //(Local_u32TimeOutCounter < ADC_u32_TimeOut_MaxValue)
        {
            // Clear conversion complete flag
            SET_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADIF_BIT);
            // clear busy flag
            ADC_u8BusyFlag = 1;
            /* Read Digital Value */
            *Copy_pu16DigitalValue = ADC_u16_ADC_REG;
        }
        else
        {
            Local_u8ErrorState = STD_TYPES_NOK;
        }
    }
    else
        Local_u8ErrorState = STD_TYPES_NOK;
    return Local_u8ErrorState;
}
u8 ADC_u8GetDigitalValue_A_Synch(u8 Copy_u8ChannelNum, void(*Copy_pfNotificiation(u16)))
{
    u8 local_u8ErrorState = STD_TYPES_OK;
    if ((Copy_u8ChannelNum < 32) && (Copy_pfNotificiation != NULL) && (ADC_u8BusyFlag == 0))
    {
        // Set Flag to make ADC is Busy
        ADC_u8BusyFlag = 1;
        // Update Golable Pointer To A Function
        ADC_pfNotification = Copy_pfNotificiation;
        // Enable ADC Interrupt
        SET_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADIE_BIT);
        // Clear the channel selection bits and set the new channel number
        ADC_u8_ADMUX_REG &= 0xE0;
        ADC_u8_ADMUX_REG |= (Copy_u8ChannelNum & 0x1F);
        /* Start Conversion */
        SET_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADSC_BIT);
    }
    else
    {
        local_u8ErrorState = STD_TYPES_NOK;
    }
    return local_u8ErrorState;
}
u8 ADC_u8GetADC_DigitalValue(u16 *Copy_pu16DigitalValue)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    if (Copy_pu16DigitalValue != NULL)
    {
        // Read ADC Register
        *Copy_pu16DigitalValue = ADC_u16_ADC_REG;
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    return Local_u8ErrorState;
}

// Prototype for ADC ISR
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    if (ADC_pfNotification != NULL)
    {
        // Clear ADC Flag
        ADC_u8BusyFlag = 0;
        // Clear PIE of ADC
        CLR_BIT(ADC_u8_ADCSRA_REG, ADCSRA_REG_ADIE_BIT);
        // Call Notification Function
        ADC_pfNotification(ADC_u16_ADC_REG);
    }
}
