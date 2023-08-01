/***************************************************************/
/**************** Name    : Omar Attia     ********************/
/**************** Date    : 31/07/2023      *******************/
/**************** SWC     : GI       ******************/
/**************** Version : 1.0            *****************/
/**********************************************************/
/*lib layer*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_Math.h"
/* MCAL */
#include "GI_config.h"
#include "GI_private.h"
#include "GI_interface.h"
void GI_voidEnable(void)
{
    SET_BIT(SREG, control_EXTI_Bit);
}
void GI_voidDisable(void)
{
    CLR_BIT(SREG, control_EXTI_Bit);
}
