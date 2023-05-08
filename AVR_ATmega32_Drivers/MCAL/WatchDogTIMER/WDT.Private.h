/*
 * WDT.Private.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Adel
 */

#ifndef MCAL_WATCHDOGTIMER_WDT_PRIVATE_H_
#define MCAL_WATCHDOGTIMER_WDT_PRIVATE_H_



typedef enum
{	NOErr,
	ErrSleepValue
}WDTErrState;

typedef enum
{
	sleep_16_3ms,
	sleep_32_5ms,
	sleep_65ms,
	sleep_0_13s,
	sleep_0_26s,
	sleep_0_52s,
	sleep_1s,
	sleep_2_1s
}SleepTimes_5vVcc;



#endif /* MCAL_WATCHDOGTIMER_WDT_PRIVATE_H_ */
