/************************************************/
/************* Name    : Omar Attia  ***********/
/************* Date    : 30/4/2023  ***********/
/************* SWC     : DIO      ************/
/************* Version : 1.0    *************/
/*******************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


u8 DIO_setPinDirectoin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection);
u8 DIO_setPinvALUE(u8 Copy_u8PortID, u8 Copy_PinId, u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_PinID, u8 * Copy_pu8ReturnedPinValue);
u8 DIO_u8SetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDirection);
u8 DIO_u8SetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue);
u8 DIO_u8GetPortValue(u8 Copy_u8PortID, u8 * Copy_pu8ReturnedPortValue);


#endif