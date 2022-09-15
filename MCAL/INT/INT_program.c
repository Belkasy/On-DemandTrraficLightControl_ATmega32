/**
 *@brief    Interrupts Mangment 
 *@name     INT_program.c
 *@author   Belkasy
 *@date     12 Sep 2022
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/registers.h"
#include "INT_interface.h"


/*
************************************************************
!-                     Program Body 
************************************************************
*/
void (*Static_voidINT0CallBack)(void) = NULL;
void static (*Static_voidINT1CallBack)(void) = NULL;
void static (*Static_voidINT2CallBack)(void) = NULL;

void INT0_voidEnable (void)
{
#if     INT0_SENSE_CONTROL == INT_LOW_LEVEL
    BIT_CLR(MCUCR,ISC01);
    BIT_CLR(MCUCR,ISC00);
#elif   INT0_SENSE_CONTROL == INT_LOGICAL_CHANGE
    BIT_CLR(MCUCR,ISC01);
    BIT_SET(MCUCR,ISC00);
#elif   INT0_SENSE_CONTROL == INT_FALLING_EDGE
    BIT_SET(MCUCR,ISC01);
    BIT_CLR(MCUCR,ISC00);
#elif   INT0_SENSE_CONTROL == INT_RASING_EDGE
    BIT_SET(MCUCR,ISC01);
    BIT_SET(MCUCR,ISC00);
#else
#endif
    BIT_SET(GICR,INT0);

}/** @end INT0_voidEnable() */

void INT1_voidEnable (void)
{
#if     INT1_SENSE_CONTROL == INT_LOW_LEVEL
    BIT_CLR(MCUCR,ISC11);
    BIT_CLR(MCUCR,ISC10);
#elif   INT1_SENSE_CONTROL == INT_LOGICAL_CHANGE
    BIT_CLR(MCUCR,ISC11);
    BIT_SET(MCUCR,ISC10);
#elif   INT1_SENSE_CONTROL == INT_FALLING_EDGE
    BIT_SET(MCUCR,ISC11);
    BIT_CLR(MCUCR,ISC10);
#elif   INT1_SENSE_CONTROL == INT_RASING_EDGE
    BIT_SET(MCUCR,ISC11);
    BIT_SET(MCUCR,ISC10);
#else
#endif

    BIT_SET(GICR,INT1);
}/** @end INT1_voidEnable() */

void INT2_voidEnable (void)
{
#if     INT2_SENSE_CONTROL == INT_FALLING_EDGE
    BIT_CLR(MCUCSR,ISC2);
#elif   INT2_SENSE_CONTROL == INT_RASING_EDGE
    BIT_SET(MCUCSR,ISC2);
#else
#endif

        BIT_SET(GICR,INT2);
}/** @end INT2_voidEnable() */

void INT0_voidDisable(void)
{
    BIT_CLR(GICR,INT0);

}/** @end INT0_voidDisable() */

void INT1_voidDisable(void)
{
    BIT_CLR(GICR,INT1);

}/** @end INT2_voidDisable() */

void INT2_voidDisable(void)
{
    BIT_CLR(GICR,INT2);
}/** @end INT2_voidDisable() */

void INT0_voidCallBack(void (*Function_voidCallback)(void))
{
    if (Function_voidCallback != NULL)
    {
        Static_voidINT0CallBack = Function_voidCallback;
    }
    else;
}

void INT1_voidCallBack(void (*Function_voidCallback)(void))
{
    if (Function_voidCallback != NULL)
    {
        Static_voidINT1CallBack = Function_voidCallback;
    }
    else;
}

void INT2_voidCallBack(void (*Function_voidCallback)(void))
{
    if (Function_voidCallback != NULL)
    {
        Static_voidINT2CallBack = Function_voidCallback;
    }
    else;
}


ISR(ISR_INT0)
{
    if (Static_voidINT0CallBack != NULL)
    {
        Static_voidINT0CallBack();
    }else;
}

ISR(ISR_INT1)
{
    if (Static_voidINT1CallBack != NULL)
    {
        Static_voidINT1CallBack();
    }else;
}

ISR(ISR_INT2)
{
    if (Static_voidINT2CallBack != NULL)
    {
        Static_voidINT2CallBack();
    }else;}