/*
 * On-DemandTrraficLightControl.c
 *
 * Created: 9/14/2022 6:23:26 PM
 * Author : Belkasy
 */ 

#include "APP\application.h"

void main (void)
{
	ODT_voidSysInit();
	while(1)
	{
		ODT_voidSysUpdate();
	}
}
