/***************************************************************/
/**************** Name    : Omar Attia    *********************/
/**************** Date    : June 7th 2023 ********************/
/**************** SWC     : KPD           *******************/
/**************** Version : 1.0           ******************/
/**********************************************************/
#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/***************************************************************************/
/*MCAL*/
#include "../../1-MCAL/DIO/DIO_interface.h"
/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"
/***************************************************************************/
const u8 KPD_Au8keys[4][4] = KPD_KEYS;
/***************************************************************************/
const u8 KPD_Au8RowsPins[4] = {
    KPD_u8_R1_PIN,
    KPD_u8_R2_PIN,
    KPD_u8_R3_PIN,
    KPD_u8_R4_PIN,
};
/***************************************************************************/
const u8 KPD_Au8ColumnsPins[4] = {
    KPD_u8_C1_PIN,
    KPD_u8_C2_PIN,
    KPD_u8_C3_PIN,
    KPD_u8_C4_PIN,
};
/***************************************************************************/
u8 KPD_u8getKeystate(u8 *copy_pu8Returnedkey)
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    u8 Local_u8RowsCounter, Local_u8ColumnsCounter, Local_u8PinValue, Local_u8Flag = 0;

    if (copy_pu8Returnedkey != NULL)
    {
        *copy_pu8Returnedkey = KPD_u8_KEY_NOT_PRESSED;
        /* Activate each row ==> for loop on the pins of the rows */
        for (Local_u8RowsCounter = 0; Local_u8RowsCounter <= 3; Local_u8RowsCounter++)
        {
            DIO_voidSetPinValue(KPD_u8_PORT1, KPD_Au8RowsPins[Local_u8RowsCounter], DIO_u8_LOW);

            /* Delay to stabilize the row activation */
            _delay_ms(1);

            /* Check which i/p pin has zero */
            for (Local_u8ColumnsCounter = 0; Local_u8ColumnsCounter <= 3; Local_u8ColumnsCounter++)
            {
                DIO_u8GetPinValue(KPD_u8_PORT2, KPD_Au8ColumnsPins[Local_u8ColumnsCounter], &Local_u8PinValue);

                if (Local_u8PinValue == DIO_u8_LOW) /* Switch is Pressed */
                {
                    /* Debouncing */
                    _delay_ms(20);

                    DIO_u8GetPinValue(KPD_u8_PORT2, KPD_Au8ColumnsPins[Local_u8ColumnsCounter], &Local_u8PinValue);

                    /* Check if the pin is still equal to LOW */
                    while (Local_u8PinValue == DIO_u8_LOW)
                    {
                        DIO_u8GetPinValue(KPD_u8_PORT2, KPD_Au8ColumnsPins[Local_u8ColumnsCounter], &Local_u8PinValue);
                    }

                    *copy_pu8Returnedkey = KPD_Au8keys[Local_u8RowsCounter][Local_u8ColumnsCounter];
                    Local_u8Flag = 1;
                    break;
                }
            }

            /* Deactivate Row */
            DIO_voidSetPinValue(KPD_u8_PORT1, KPD_Au8RowsPins[Local_u8RowsCounter], DIO_u8_HIGH);

            if (Local_u8Flag == 1)
            {
                break;
            }
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK;
    }
    return Local_u8ErrorState;
}

u8 KPD_enuInit(void)
{
    DIO_voidSetPinDirection(KPD_u8_PORT1, KPD_u8_R1_PIN, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(KPD_u8_PORT1, KPD_u8_R2_PIN, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(KPD_u8_PORT1, KPD_u8_R3_PIN, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(KPD_u8_PORT1, KPD_u8_R4_PIN, DIO_u8_OUTPUT);

    DIO_voidSetPinDirection(KPD_u8_PORT2, KPD_u8_C1_PIN, DIO_u8_INPUT);
    DIO_voidSetPinDirection(KPD_u8_PORT2, KPD_u8_C2_PIN, DIO_u8_INPUT);
    DIO_voidSetPinDirection(KPD_u8_PORT2, KPD_u8_C3_PIN, DIO_u8_INPUT);
    DIO_voidSetPinDirection(KPD_u8_PORT2, KPD_u8_C4_PIN, DIO_u8_INPUT);

    DIO_u8SetPortValue(KPD_u8_PORT1, DIO_u8_HIGH);
    DIO_u8SetPortValue(KPD_u8_PORT2, DIO_u8_HIGH);

    return STD_TYPES_OK;
}
