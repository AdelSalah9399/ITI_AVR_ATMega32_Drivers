/*
 * WDT.Program.c
 *
 *  Created on: Apr 6, 2023
 *      Author: Adel
 */
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"
#include "WDT_Register.h"
#include "WDT.Private.h"


void WDT_ENABLE(void)
{
	SET_BIT(WDTCR,WDE);
}
void WDT_DIABLE(void)
{
	/*write on on WDE & WDTOE ((in the same time))*/
	WDTCR = (1<<WDE) | (1<<WDTOE) ;
	/* then clear the WDE ((within 4 CLK cycles)) so use WDTCR=0 directly to be very fast */
	WDTCR =0X00; // this took 1 CLK cycle
}
WDTErrState WDT_ErrStateSLEEP(SleepTimes_5vVcc SleepValue)
{
	if(SleepValue<8)
	{
		WDTCR &= 0b11111000;
		WDTCR |= SleepValue;
	}
	else
	{
		return ErrSleepValue;
	}
	return NOErr;
}


