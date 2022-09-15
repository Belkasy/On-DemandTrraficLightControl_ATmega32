/**
 * @file    application.c
 * @author: Belkasy
 * @date    15 Sep 2022
 **/
/*
 --------------------------------------------------------------------------------------------------------------------------------------------------
!-              HEADERS INCLUDED
 --------------------------------------------------------------------------------------------------------------------------------------------------
*/

/** @defgroup Horizontal Layer*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/registers.h"
#include <avr/wdt.h>

#include "..\MCAL\DIO\DIO_interface.h"
#include "..\MCAL\GIE\GIE_interface.h"
#include "..\MCAL\INT\INT_interface.h"
#include "..\MCAL\TIMER\TIMER_interface.h"

#include "..\ECUAL\LED\LED_interface.h"
#include "..\ECUAL\BUTTON\BUTTON_interface.h"

#include "application.h"

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
!-                GLOBAL VARIABLES
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static u8 Global_Car_G=0,   Global_Pedestrian_G=0;
static u8 Global_Car_Y=0,   Global_Pedestrian_Y=0;
static u8 Global_Car_R=0,   Global_Pedestrian_R=0;

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void ODT_voidSysInit(void)
{
    voidSysLedInit();
    voidSysButtonInit();
    TIMER0_voidInit();
}/** @end OTF_voidSysInit */

void ODT_voidSysUpdate(void)
{
    voidClrLeds();
    PAS_R_ON;
    CAR_G_ON;

    DELAY_5s;
    CAR_G_OFF;


    /** @def: Flashing Mechanism */
    Global_Car_Y = HIGH;
    for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
    {
        CAR_Y_ON;
        DELAY_500ms;
        CAR_Y_OFF;
        DELAY_500ms;
    }
    Global_Car_Y = LOW;

    CAR_R_ON;
    DELAY_5s;
    CAR_R_OFF;


    /** @def: Flashing Mechanism */
    Global_Car_Y = HIGH;
    for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
    {
        CAR_Y_ON;
        DELAY_500ms;
        CAR_Y_OFF;
        DELAY_500ms;
    }
    Global_Car_Y = LOW;
	
}/** @end OTF_voidSysUpdate */

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS IMPLEMENTATION
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void voidPassengerEventHandle(void)
{
    if( (Global_Car_R) )
    {
        PAS_G_ON;
		PAS_R_OFF;
        CAR_R_ON;
		
        DELAY_5s;
    }
    else if( (Global_Car_G) || (Global_Car_Y) )
    {
        PAS_R_ON;
		
        if( (Global_Car_Y) )
        {
			Global_Car_Y = HIGH;
            for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
            {
                CAR_Y_ON;
                DELAY_500ms;
                CAR_Y_OFF;
                DELAY_500ms;
            }
			Global_Car_Y = LOW;
        }
        else
        { DELAY_5s; }
        CAR_Y_OFF;
        PAS_R_OFF;
        CAR_G_OFF;
        /** @def: Flashing Mechanism */
        for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
        {
            CAR_Y_ON;
            PAS_Y_ON;
            DELAY_500ms;
            CAR_Y_OFF;
            PAS_Y_OFF;
            DELAY_500ms;
        }
        CAR_R_ON;
        PAS_G_ON;
        DELAY_5s;
    }
    else {;}
    /** @def: General after state proceducre */
    CAR_R_OFF;
    /** @def: Flashing Mechanism */
    for(u8 L_u8Iterator = 0; (L_u8Iterator < 5); ++L_u8Iterator)
    {
        CAR_Y_ON;
        PAS_Y_ON;
        DELAY_500ms;
        CAR_Y_OFF;
        PAS_Y_OFF;
        DELAY_500ms;
    }
    PAS_G_OFF;
    PAS_R_ON;
    CAR_G_ON;
    DELAY_5s;
    PAS_R_OFF;

	INT0_voidDisable();
    /** @def: RESET The Micro Controller assembly instruction */
    RESET_MCU;
}/** @end voidPassengerEventHandle */

static void voidSysLedInit(void)
{
    /** @defgroup Intialize Car Traffic Leds */
    LED_voidInit(PORTA_ID, PIN0);
    LED_voidInit(PORTA_ID, PIN1);
    LED_voidInit(PORTA_ID, PIN2);
    /** @defgroup Intialize pedestrian leds*/
	LED_voidInit(PORTB_ID, PIN0);
	LED_voidInit(PORTB_ID, PIN1);
	LED_voidInit(PORTB_ID, PIN2);
}/** @end voidSysLedInit */

static void voidSysButtonInit(void)
{
    BUTTON_voidInit(PORTD_ID, PIN2);
    voidSysInterruptInit();
}/** @end voidSysButtonInit */

static void voidSysInterruptInit(void)
{
    INT0_voidCallBack(&voidPassengerEventHandle); //Pedestrian Mode
	INT0_voidEnable();
	GIE_voidEnable();
}/** @end voidSysInterruptInit */

static void voidClrLeds(void)
{
    CAR_G_OFF;
    CAR_Y_OFF;
    CAR_R_OFF;
    PAS_G_OFF;
    PAS_Y_OFF;
    PAS_R_OFF;
}/** @end voidClrLeds*/
