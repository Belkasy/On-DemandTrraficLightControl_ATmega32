/**
 *@brief    LED_interdface.h
 *@author   Belkasy
 *@date     13 Sep 2022
*/

#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

/*
************************************************************
!-                  Functions Prototypes 
************************************************************
*/
void LED_voidInit(u8 Copy_u8Port_ID, u8 Copy_u8PinID);
void LED_voidON(u8 Copy_u8Port_ID, u8 Copy_u8PinID);
void LED_voidOFF(u8 Copy_u8Port_ID, u8 Copy_u8PinID);
void LED_voidToggle(u8 Copy_u8Port_ID, u8 Copy_u8PinID);
void LED_voidFlash(u8 Copy_u8Port_ID, u8 Copy_u8PinID, f32 Copy_f32Delay_ms, u32 Copy_u32NumFlash);
u8 LED_voidIsON(u8 Copy_u8Port_ID, u8 Copy_u8PinID);


#endif /* _LED_INTERFACE_H_ */