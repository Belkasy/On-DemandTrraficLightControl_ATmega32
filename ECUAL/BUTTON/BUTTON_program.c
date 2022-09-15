/**
 *@name    BUTON_program.c
 *@author   Belkasy
 *@date     13 Sep 2022
*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/registers.h"


#include "..\..\MCAL\DIO\DIO_interface.h"
#include "..\..\MCAL\GIE\GIE_interface.h"
#include "..\..\MCAL\INT\INT_interface.h"


#include "BUTTON_interface.h"


/*
************************************************************
!-                     Program Body 
************************************************************
*/
void BUTTON_voidInit(u8 Copy_u8Port_ID, u8 Copy_u8PinID)
{
    DIO_voidSetPinDirection(Copy_u8Port_ID, Copy_u8PinID, INPUT);
}/** @end BUTTON_voidInit() */

void BUTTON_voidGetValue(u8 Copy_u8Port_ID, u8 Copy_u8PinID, u8 *Address_u8Value)
{
    DIO_voidGetPinValue(Copy_u8PinID, Copy_u8PinID, Address_u8Value);  
}/** @end BUTTON_voidgetValue() */

void BUTTON_voidINT0(u8 Copy_u8Port_ID, u8 Copy_u8PinID, void (*Function_voidCallback)(void))
{
    INT0_voidCallBack(Function_voidCallback);
	INT0_voidEnable();
	GIE_voidEnable();
}/** @end BUTTON_voidINT0() */

void BUTTON_voidINT1(u8 Copy_u8Port_ID, u8 Copy_u8PinID, void (*Function_voidCallback)(void))
{
    INT1_voidCallBack(Function_voidCallback);
	INT1_voidEnable();
	GIE_voidEnable();
}/** @end BUTTON_voidINT1() */

void BUTTON_voidINT2(u8 Copy_u8Port_ID, u8 Copy_u8PinID, void (*Function_voidCallback)(void))
{
    INT2_voidCallBack(Function_voidCallback);
	INT2_voidEnable();
	GIE_voidEnable();
}/** @end BUTTON_voidINT2() */