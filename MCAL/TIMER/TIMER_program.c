/**
 *@brief    
 *@name     TIMER_program.c
 *@author   Belkasy
 *@date     13 Sep 2022
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/registers.h"
#include "TIMER_interface.h"


/*
************************************************************
!-                     Program Body 
************************************************************
*/
void TIMER0_voidInit(void)
{
#if     TIMER0_MODE == TIMER_MODE_NORMAL
    /* Set mode to be TIMER_MODE_NORMAL */
    BIT_CLR(TCCR0,WGM01);
    BIT_CLR(TCCR0,WGM00);
    /* OC0 MC Pin Configuration to disconected TABLE 39 */
    BIT_CLR(TCCR0,COM01);
    BIT_CLR(TCCR0,COM00);
    /* reset value */
    TCNT0 = 0x00;
#elif   TIMER0_MODE == TIMER_MODE_CTC
    /* Set mode to be TIMER_MODE_CTC */
    BIT_SET(TCCR0,WGM01);
    BIT_CLR(TCCR0,WGM00);
    /* OC0 MC Pin Configuration to disconected TABLE 39 */
    BIT_CLR(TCCR0,COM01);
    BIT_CLR(TCCR0,COM00);
#elif   TIMER0_MODE == TIMER_MODE_FAST_PWM 
     /* Set mode to be TIMER_MODE_FAST_PWM */
    BIT_SET(TCCR0,WGM01);
    BIT_SET(TCCR0,WGM00);;
    /* OC0 MC Pin Configuration to disconected TABLE 40 */
    BIT_CLR(TCCR0,COM01);
    BIT_CLR(TCCR0,COM00);
#elif   TIMER0_MODE == TIMER_MODE_PWM_PHASE_CORREC
    /* Set mode to be TIMER_MODE_PWM_PHASE_CORREC */
    BIT_CLR(TCCR0,WGM01);
    BIT_SET(TCCR0,WGM00);
    /* OC0 MC Pin Configuration to disconected TABLE 41 */
    BIT_CLR(TCCR0,COM01);
    BIT_CLR(TCCR0,COM00);
#else // Error Handling
#endif /* TIMER0_MODE */ 
    

}/** @end TIMER0_voidInit() */

void TIMER0_voidDelaySync_ms(f32 Copy_f32Delay_ms)
{
    
    u8 Local_u8IntialValue = 0;
    u32 Local_u8NumOverFlows = 0;

    f32 Local_f32Delay = Copy_f32Delay_ms * 0.001f;

    TIMER_calcTimerIntialValue(TIMER0_ID, Local_f32Delay, &Local_u8IntialValue, &Local_u8NumOverFlows);

    TIMER0_voidSetTimerValue(Local_u8IntialValue);

    TIMER0_voidStartTimer();

    for(register u32 i=0; i<Local_u8NumOverFlows; ++i)
    {
        while(!(BIT_GET(TIFR,OVF0)));
        BIT_SET(TIFR,OVF0); // to clear the flag set 1
    }

    TIMER0_voidStopTimer();
}

void TIMER0_voidDelaySync_us(f32 Copy_f32Delay_us)
{
    u8 Local_u8IntialValue = 0;
    u32 Local_u8NumOverFlows = 0;

    f32 Local_f32Delay = Copy_f32Delay_us * 0.000001f;

    TIMER_calcTimerIntialValue(TIMER0_ID, Local_f32Delay, &Local_u8IntialValue, &Local_u8NumOverFlows);

    TIMER0_voidSetTimerValue(Local_u8IntialValue);

    TIMER0_voidStartTimer();

    for(register u32 i=0; i<Local_u8NumOverFlows; ++i)
    {
        while(!(BIT_GET(TIFR,OVF0)));
        BIT_SET(TIFR,OVF0); // to clear the flag set 1
    }
    
    TIMER0_voidStopTimer();
}

static void TIMER0_voidStartTimer(void)
{
    /* Set Prescaler value to timer 0 */
    TCCR0 &= ~(0b111);
    TCCR0 |=  (TIMER0_PRESCALER);
}/** @end TIMER0_voidStartTimer() */

static void TIMER0_voidStopTimer(void)
{
    /*Set TCCR0 0,1,2 to 0b000*/
    TCCR0 &= ~(0b111);
    TCCR0 |=  (TIMER_PRESCALER_STOP);
}/** @end TIMER0_voidStopTimer() */

static void TIMER0_voidGetTimerState(void)
{

}/** @end TIMER0_voidGetTimerState() */

static void TIMER0_voidSetTimerValue(u8 Copy_u8Value)
{
    TCNT0 = Copy_u8Value;
}/** @end TIMER0_voidSetTimerValue() */

static void TIMER0_voidGetTimerValue(u8 *Address_u8Value)
{
    *Address_u8Value = TCNT0;
}/** @end TIMER0_voidGetTimerValue() */

static void TIMER_voidCalculateOCR(u8 Copy_u8TimerID, u8 Copy_u8DutyCycle, u8 *Address_u8OCR)
{
    
#if TIMER0_MODE == TIMER_MODE_FAST_PWM                  /* NON_ INVERING FAST PWM */
    switch (Copy_u8TimerID)
    {
        case TIMER0_ID: *Address_u8OCR = ((Copy_u8DutyCycle*0xFF)/100)-1;   break;
        case TIMER1_ID: *Address_u8OCR = ((Copy_u8DutyCycle*0xFFFF)/100)-1; break;
        case TIMER2_ID: *Address_u8OCR = ((Copy_u8DutyCycle*0xFF)/100)-1;   break;
        default:
            break;
    }
#elif TIMER0_MODE == TIMER_MODE_PWM_PHASE_CORRECT       /* NON_ INVERING PWM PHASE CORRECT */
    switch (Copy_u8TimerID)
    {
        case TIMER0_ID: *Address_u8OCR = ((Copy_u8DutyCycle*0xFF)/100)-1;   break;
        case TIMER1_ID: *Address_u8OCR = ((Copy_u8DutyCycle*0xFFFF)/100)-1; break;
        case TIMER2_ID: *Address_u8OCR = ((Copy_u8DutyCycle*0xFF)/100)-1;   break;
        default:
            break;
    }
#else //Error handling
#endif
}/** @end TIMER_voidCalculateOCR() */

static void TIMER_calcTimerIntialValue(u8 Copy_u8TimerID,
                                        f32 Copy_f32Delay,
                                        u8 *Address_u8IntialValue,
                                        u32 *Address_u32NumOverFlow)
{
    f32 Local_f32Ttick = 0.0;
    f32 Local_f32Tmaxdelay = 0.0;
    switch (Copy_u8TimerID)
    {
        case TIMER0_ID:
            Local_f32Ttick     = ((f32)TIMER0_PRESCALER_NUM / F_CPU);
            Local_f32Tmaxdelay = ((f32)Local_f32Ttick * 0xFF);
            break;
        case TIMER1_ID:
            Local_f32Ttick     = ((f32)TIMER1_PRESCALER_NUM / F_CPU);
            Local_f32Tmaxdelay = ((f32)Local_f32Ttick * 0xFFFF);
            break;
        case TIMER2_ID:
            Local_f32Ttick     = ((f32)TIMER2_PRESCALER_NUM / F_CPU);
            Local_f32Tmaxdelay = ((f32)Local_f32Ttick * 0xFF);
            break;
        default:
            break;
    }

    if (Copy_f32Delay < Local_f32Tmaxdelay)
    {
        *Address_u8IntialValue = (Local_f32Tmaxdelay-Copy_f32Delay)/Local_f32Ttick;
    }
    else if (Copy_f32Delay == Local_f32Tmaxdelay)
    {
        *Address_u8IntialValue = 0x00;
    }
    else if (Copy_f32Delay > Local_f32Tmaxdelay)
    {
        f32 Local_f32Noverflow = (f32)Copy_f32Delay/Local_f32Tmaxdelay;
        *Address_u32NumOverFlow = Ceil(Local_f32Noverflow); // Celi last line
        switch (Copy_u8TimerID)
        {
            case TIMER0_ID:
                *Address_u8IntialValue = 0xFF-((Copy_f32Delay/Local_f32Ttick)/(*Address_u32NumOverFlow));
                break;
            case TIMER1_ID:
                *Address_u8IntialValue = 0xFFFF-((Copy_f32Delay/Local_f32Ttick)/(*Address_u32NumOverFlow));
                break;
            case TIMER2_ID:
                *Address_u8IntialValue = 0xFF-((Copy_f32Delay/Local_f32Ttick)/(*Address_u32NumOverFlow));
                break;
            default:
                break;
        }
    }
    else 
    {
        /* Error state */
    }
}/** @end TIMER0_calcTimerIntialValue() */

static u32 Ceil(f32 Copy_f32Value)
{
        /* Ceil NoverFlow to int */
        u32 Local_u32Value = (u32)Copy_f32Value;
        if (Copy_f32Value == (f32)Local_u32Value) {Local_u32Value +=0;}
        else                                      {Local_u32Value +=1;}
        return Local_u32Value;
}
