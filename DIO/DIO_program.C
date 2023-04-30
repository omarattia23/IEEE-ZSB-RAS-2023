/************************************************/
/************* Name    : Omar Attia  ***********/
/************* Date    : 30/4/2023  ***********/
/************* SWC     : DIO      ************/
/************* Version : 1.0    *************/
/*******************************************/
/* Lib Layer */
#include "STD_TYPES.h"
#include "BIT_MAth.h"
/* MCAL */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

u8 DIO_setPinDirectoin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    if((Copy_u8PortID >= DIO_u8_PORTA)&&(Copy_u8PinID <= DIO_u8_PORTD)&&(Copy_u8PinID >= DIO_u8_PIN0)&&(Copy_u8PinID <= DIO_u8_PIN7)&&(Copy_u8PinDirection == DIO_u8_OUTPUT) || (Copy_u8PinDirection) == DIO_u8_INPUT )
    {
        switch(Copy_u8PortID)
        {
            case DIO_u8_PORTA:
                switch(Copy_u8PinDirection)
                {
                    case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinID);break;
                    case DIO_u8_OUTPUT:CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinID);break;
                }
                break;
                
            case DIO_u8_PORTB:
                switch(Copy_u8PinDirection)
                {
                    case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinID);break;
                    case DIO_u8_OUTPUT:CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinID);break;
                }
                break;
            case DIO_u8_PORTC:
                switch(Copy_u8PinDirection)
                {
                    case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinID);break;
                    case DIO_u8_OUTPUT:CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinID);break;
                }
                break;
            case DIO_u8_PORTD:
                switch(Copy_u8PinDirection)
                {
                    case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinID);break;
                    case DIO_u8_OUTPUT:CLR_BIT(DIO_u8_DDRA_REG,Copy_u8PinID);break;
                }
                break;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    return Local_u8ErrorState;
}
u8 DIO_setPinvALUE(u8 Copy_u8PortID, u8 Copy_PinId, u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_PinID, u8 * Copy_pu8ReturnedPinValue);
u8 DIO_u8SetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDirection);
u8 DIO_u8SetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue);
u8 DIO_u8GetPortValue(u8 Copy_u8PortID, u8 * Copy_pu8ReturnedPortValue);
