/**
 *@brief    DIO_interface.h
 *@author   Belkasy
 *@date     12 Sep 2022
*/
#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

/*
************************************************************
!-                 Importand Paramerers 
************************************************************
*/
#define PORTA_ID  0
#define PORTB_ID  1
#define PORTC_ID  2
#define PORTD_ID  3

/*
************************************************************
!-                 Function Prototypes 
************************************************************
*/

void DIO_voidInit(void);
void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection);
void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue);
void DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Address_u8PinValue);
void DIO_voidTogglePinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);

#endif /** @endif _DIO_INTERFACE_H_ */