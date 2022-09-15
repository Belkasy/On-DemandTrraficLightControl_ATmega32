/**
 *@brief    Gineral Interrupt Enable/Disable
 *@name     GIE_program.c
 *@author   Belkasy
 *@date     12 Sep 2022
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/registers.h"
#include "GIE_interface.h"


/*
************************************************************
!-                     Program Body 
************************************************************
*/
void GIE_voidEnable(void)
{
    BIT_SET(SREG,I);
}/** @end GIE_voidENable*/


void GIE_voidDisable(void)
{
    BIT_CLR(SREG,I);

}/** @end GIE_voidDisable*/