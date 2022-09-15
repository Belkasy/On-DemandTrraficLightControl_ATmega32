/**
 * @file    application.h
 * @author: Belkasy
 * @date    15 Sep 2022
 **/
/** @def Header Guards */
#ifndef APPLICATION_H_
#define APPLICATION_H_

/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    MACROS & ENUMS
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

#define RESET_MCU  wdt_enable(WDTO_15MS); //("JMP 0x000"); //asm("wdr"); while(1);//

#define DELAY_5s			TIMER0_voidDelaySync_ms(5000.0f);
#define DELAY_500ms			TIMER0_voidDelaySync_ms(500.0f);
																						 
#define CAR_G_ON	Global_Car_G = HIGH;	    LED_voidON(PORTA_ID,PIN0);
#define CAR_Y_ON							    LED_voidON(PORTA_ID,PIN1);
#define CAR_R_ON	Global_Car_R = HIGH;		LED_voidON(PORTA_ID,PIN2);
																						 
#define CAR_G_OFF	LED_voidOFF(PORTA_ID,PIN0); Global_Car_G = LOW;
#define CAR_Y_OFF	LED_voidOFF(PORTA_ID,PIN1);
#define CAR_R_OFF	LED_voidOFF(PORTA_ID,PIN2); Global_Car_R = LOW;
																						 
#define PAS_G_ON	Global_Pedestrian_G = HIGH;		LED_voidON(PORTB_ID,PIN0);
#define PAS_Y_ON									LED_voidON(PORTB_ID,PIN1);
#define PAS_R_ON	Global_Pedestrian_R = HIGH;		LED_voidON(PORTB_ID,PIN2);
																						 
#define PAS_G_OFF	LED_voidOFF(PORTB_ID,PIN0); Global_Pedestrian_G = LOW;
#define PAS_Y_OFF	LED_voidOFF(PORTB_ID,PIN1);
#define PAS_R_OFF	LED_voidOFF(PORTB_ID,PIN2); Global_Pedestrian_R = LOW;



/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PUBLIC FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

void ODT_voidSysInit(void);
void ODT_voidSysUpdate(void);


/*
 * --------------------------------------------------------------------------------------------------------------------------------------------------
 * -    PRIVATE FUNCTIONS PROTOTYPE
 * --------------------------------------------------------------------------------------------------------------------------------------------------
*/

static void voidSysLedInit(void);
static void voidSysButtonInit(void);
static void voidSysInterruptInit(void);

static void voidPassengerEventHandle(void);

static void voidClrLeds(void);


#endif /* APPLICATION_H_ */
