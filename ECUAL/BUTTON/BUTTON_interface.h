/**
 *@brief    BUTTON_interdface.h
 *@author   Belkasy
 *@date     13 Sep 2022
*/

#ifndef _BUTTON_INTERFACE_H_
#define _BUTTON_INTERFACE_H_

/*
************************************************************
!-                  Functions Prototypes 
************************************************************
*/
void BUTTON_voidInit(u8 Copy_u8Port_ID, u8 Copy_u8PinID);
void BUTTON_voidGetValue(u8 Copy_u8Port_ID, u8 Copy_u8PinID, u8 *Address_u8Value);
void BUTTON_voidINT0(u8 Copy_u8Port_ID, u8 Copy_u8PinID, void (*Function_voidCallback)(void));
void BUTTON_voidINT1(u8 Copy_u8Port_ID, u8 Copy_u8PinID, void (*Function_voidCallback)(void));
void BUTTON_voidINT2(u8 Copy_u8Port_ID, u8 Copy_u8PinID, void (*Function_voidCallback)(void));

#endif /* _BUTTON_INTERFACE_H_ */