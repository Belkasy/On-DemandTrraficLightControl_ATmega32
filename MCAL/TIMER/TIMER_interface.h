/**
 *@brief    TIMER_interface.h
 *@author   Belkasy
 *@date     12 Sep 2022
*/
#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

/*
************************************************************
!-                 Important Paramerers 
************************************************************
*/
#define TIMER0_ID                          0
#define TIMER1_ID                          1
#define TIMER2_ID                          2

#define TIMER_MODE_NORMAL                  0
#define TIMER_MODE_CTC                     1
#define TIMER_MODE_FAST_PWM                2
#define TIMER_MODE_PWM_PHASE_CORRECT       3

#define TIMER_PRESCALER_STOP    (0b000) 
#define TIMER_PRESCALER_1       (0b001) 
#define TIMER_PRESCALER_8       (0b010)
#define TIMER_PRESCALER_64      (0b011)
#define TIMER_PRESCALER_256     (0b100)
#define TIMER_PRESCALER_1024    (0b101)
#define TIMER_CLk_FALING_T0     (0b110)
#define TIMER_CLK_RISING_T0     (0b111)

/*
************************************************************
!-                 TIMER Configs 
************************************************************
*/  
#define F_CPU                     8000000

#define TIMER0_MODE               TIMER_MODE_NORMAL
#define TIMER0_PRESCALER          TIMER_PRESCALER_8
#define TIMER0_PRESCALER_NUM      8


#define TIMER1_MODE               TIMER_MODE_NORMAL
#define TIMER1_PRESCALER          (0b001U)
#define TIMER1_PRESCALER_NUM      (128U)


#define TIMER2_MODE               TIMER_MODE_NORMAL
#define TIMER2_PRESCALER          (0b001U)
#define TIMER2_PRESCALER_NUM      (128U)


/*
************************************************************
!-                 Function Prototypes 
************************************************************
*/
void TIMER0_voidInit(void);
void TIMER0_voidDelaySync_ms(f32 Copy_f32Delay_ms);
void TIMER0_voidDelaySync_us(f32 Copy_f32Delay_us);
static void TIMER0_voidStartTimer(void);
static void TIMER0_voidStopTimer(void);
static void TIMER0_voidGetTimerState(void);
static void TIMER0_voidSetTimerValue(u8 Copy_u8Value);
static void TIMER0_voidGetTimerValue(u8 *Address_u8Value);
static void TIMER_voidCalculateOCR(u8 Copy_u8TimerID, u8 Copy_u8DutyCycle, u8 *Address_u8OCR);
static void TIMER_calcTimerIntialValue(u8 Copy_u8TimerID, f32 Copy_f32Delay, 
                                        u8 *Address_u8IntialValue, u32 *Address_u32NumOverFlow);
void TIMER1_voidInit(void);
void TIMER2_voidInit(void);

static u32 Ceil(f32 Copy_f32Value);

/*
************************************************************
!-                 Important Pins 
************************************************************
*/
/** @defgroup TIMER TCCRO PINS */
#define FOC0        7
#define WGM00       6
#define COM01       5
#define COM00       4
#define WGM01       3
#define CS02        2
#define CS01        1
#define CS00        0

/** @defgroup TIMER TIFR PINS */
#define OCF0        1
#define OVF0        0


#endif /** @endif _TIMER_INTERFACE_H_ */