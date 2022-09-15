/**
 *@brief    INT_interface.h
 *@author   Belkasy
 *@date     12 Sep 2022
*/
#ifndef _INT_INTERFACE_H_
#define _INT_INTERFACE_H_

/*
************************************************************
!-                 Importand defines 
************************************************************
*/
#define EXT_INT_0   0
#define EXT_INT_1   1
#define EXT_INT_2   2

#define INT_LOW_LEVEL            0
#define INT_LOGICAL_CHANGE       1
#define INT_FALLING_EDGE         2
#define INT_RASING_EDGE          3

/*
************************************************************
!-                 Importand config 
************************************************************
*/
#define INT0_SENSE_CONTROL INT_RASING_EDGE
#define INT1_SENSE_CONTROL INT_FALLING_EDGE
#define INT2_SENSE_CONTROL INT_RASING_EDGE

/*
************************************************************
!-                 Function Prototypes 
************************************************************
*/

void INT0_voidEnable(void);
void INT0_voidDisable(void);
void INT0_voidCallBack(void (*Function_voidCallback)(void));


void INT1_voidEnable(void);
void INT1_voidDisable(void);
void INT1_voidCallBack(void (*Function_voidCallback)(void));


void INT2_voidEnable(void);
void INT2_voidDisable(void);
void INT2_voidCallBack(void (*Function_voidCallback)(void));


/*
************************************************************
!-                       PINs 
************************************************************
*/
/* MCUCR Reg */
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

/* MCUCSR Reg */
#define ISC2   6

/* GICR Reg */
#define INT1   7
#define INT0   6
#define INT2   5

/*
************************************************************
!-                       Vector Int 
************************************************************
*/
#define ISR_INT0    __vector_1
#define ISR_INT1    __vector_2
#define ISR_INT2    __vector_3

#define ISR(INT_VECTOR) void INT_VECTOR (void) __attribute__ ((signal,used));\
                        void INT_VECTOR (void)      
#endif /** @endif _INT_INTERFACE_H_ */