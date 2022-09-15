/**
 *@brief    Digital Input Output    
 *@name     DIO_program.c
 *@author   Belkasy
 *@date     12 Sep 2022
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/registers.h"
#include "DIO_interface.h"

/*
************************************************************
!-                     Program Body 
************************************************************
*/
void DIO_voidInit(void)
{

} /** @end DIO_voidInit() */
void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection)
{
    switch (Copy_u8PortID)
    {
    case PORTA_ID:
        if (Copy_u8PinDirection == INPUT)
        {
            BIT_CLR(DDRA, Copy_u8PinID);
        }
        else if (Copy_u8PinDirection == OUTPUT)
        {
            BIT_SET(DDRA, Copy_u8PinID);
        }
        else;
        break;
    case PORTB_ID:
        if (Copy_u8PinDirection == INPUT)
        {
            BIT_CLR(DDRB, Copy_u8PinID);
        }
        else if (Copy_u8PinDirection == OUTPUT)
        {
            BIT_SET(DDRB, Copy_u8PinID);
        }
        else;
        break;
    case PORTC_ID:
        if (Copy_u8PinDirection == INPUT)
        {
            BIT_CLR(DDRC, Copy_u8PinID);
        }
        else if (Copy_u8PinDirection == OUTPUT)
        {
            BIT_SET(DDRC, Copy_u8PinID);
        }
        else;
        break;
    case PORTD_ID:
        if (Copy_u8PinDirection == INPUT)
        {
            BIT_CLR(DDRD, Copy_u8PinID);
        }
        else if (Copy_u8PinDirection == OUTPUT)
        {
            BIT_SET(DDRD, Copy_u8PinID);
        }
        else;
        break;
    
    default:
        /** @todo implement Error handling */
        break;
    }
}/** @end DIO_voidSetPinDirection() */
void DIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue)
{
    switch (Copy_u8PortID)
    {
    case PORTA_ID:
        if (Copy_u8PinValue == LOW)
        {
            BIT_CLR(PORTA, Copy_u8PinID);
        }
        else if (Copy_u8PinValue == HIGH)
        {
            BIT_SET(PORTA, Copy_u8PinID);
        }
        else;
        break;
    case PORTB_ID:
        if (Copy_u8PinValue == LOW)
        {
            BIT_CLR(PORTB, Copy_u8PinID);
        }
        else if (Copy_u8PinValue == HIGH)
        {
            BIT_SET(PORTB, Copy_u8PinID);
        }
        else;
        break;
    case PORTC_ID:
        if (Copy_u8PinValue == LOW)
        {
            BIT_CLR(PORTC, Copy_u8PinID);
        }
        else if (Copy_u8PinValue == HIGH)
        {
            BIT_SET(PORTC, Copy_u8PinID);
        }
        else;
        break;
    case PORTD_ID:
        if (Copy_u8PinValue == LOW)
        {
            BIT_CLR(PORTD, Copy_u8PinID);
        }
        else if (Copy_u8PinValue == HIGH)
        {
            BIT_SET(PORTD, Copy_u8PinID);
        }
        else;
        break;
    
    default:
        /** @todo implement Error handling */
        break;
    }
}
void DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 *Address_u8PinValue)
{
    switch (Copy_u8PortID)
    {
    case PORTA_ID:
        *Address_u8PinValue = BIT_GET(PINA, Copy_u8PinID);
        break;
    case PORTB_ID:
        *Address_u8PinValue = BIT_GET(PINB, Copy_u8PinID);
        break;
    case PORTC_ID:
        *Address_u8PinValue = BIT_GET(PINC, Copy_u8PinID);
        break;
    case PORTD_ID:
        *Address_u8PinValue = BIT_GET(PIND, Copy_u8PinID);
        break;
    default:
        /** @todo implement Error handling */
        break;
    }
}
void DIO_voidTogglePinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
      switch (Copy_u8PortID)
    {
    case PORTA_ID:
        BIT_TOG(PORTA, Copy_u8PinID);
        break;
    case PORTB_ID:
        BIT_TOG(PORTB, Copy_u8PinID);
        break;
    case PORTC_ID:
        BIT_TOG(PORTC, Copy_u8PinID);
        break;
    case PORTD_ID:
        BIT_TOG(PORTD, Copy_u8PinID);
        break;
    default:
        /** @todo implement Error handling */
        break;
    }
}