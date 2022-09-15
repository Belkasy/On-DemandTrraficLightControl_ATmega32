/**
 *@brief    LED_program.c
 *@author   Belkasy
 *@date     13 Sep 2022
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/registers.h"


#include "..\..\MCAL\DIO\DIO_interface.h"
#include "..\..\MCAL\TIMER\TIMER_interface.h"


#include "LED_interface.h"


/*
************************************************************
!-                     Program Body 
************************************************************
*/

void LED_voidInit(u8 Copy_u8Port_ID, u8 Copy_u8PinID)
{
    DIO_voidSetPinDirection(Copy_u8Port_ID, Copy_u8PinID, OUTPUT);
}/** @end LED_voidInit() */

void LED_voidON(u8 Copy_u8Port_ID, u8 Copy_u8PinID)
{
    DIO_voidSetPinValue(Copy_u8Port_ID, Copy_u8PinID, HIGH);
}/** @end LED_voidON() */

void LED_voidOFF(u8 Copy_u8Port_ID, u8 Copy_u8PinID)
{
    DIO_voidSetPinValue(Copy_u8Port_ID, Copy_u8PinID, LOW);
}/** @end LED_voidOFF() */

void LED_voidToggle(u8 Copy_u8Port_ID, u8 Copy_u8PinID)
{
    DIO_voidTogglePinValue(Copy_u8Port_ID, Copy_u8PinID);
}/** @end LED_voidToggle() */

u8 LED_voidIsON(u8 Copy_u8Port_ID, u8 Copy_u8PinID)
{
	u8 Local_u8Value;
	DIO_voidGetPinValue(Copy_u8Port_ID, Copy_u8PinID, &Local_u8Value);
	return Local_u8Value;
	
}

void LED_voidFlash(u8 Copy_u8Port_ID, u8 Copy_u8PinID, f32 Copy_f32Delay_ms, u32 Copy_u32NumFlash)
{
	if ( Copy_u32NumFlash<2 )
	{
		DIO_voidSetPinValue(Copy_u8Port_ID, Copy_u8PinID, HIGH);
		TIMER0_voidDelaySync_ms(Copy_f32Delay_ms);
		DIO_voidSetPinValue(Copy_u8Port_ID, Copy_u8PinID, LOW);
	}
	else 
	{
		for (int i = 0; i < Copy_u32NumFlash; i++)
		{
			DIO_voidSetPinValue(Copy_u8Port_ID, Copy_u8PinID, HIGH);
			TIMER0_voidDelaySync_ms(Copy_f32Delay_ms);
			DIO_voidSetPinValue(Copy_u8Port_ID, Copy_u8PinID, LOW);
			TIMER0_voidDelaySync_ms(Copy_f32Delay_ms);
		}
	}
	
}
