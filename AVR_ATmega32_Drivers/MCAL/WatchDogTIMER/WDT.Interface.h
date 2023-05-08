/*
 * WDT.Interface.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Adel
 */

#ifndef MCAL_WATCHDOGTIMER_WDT_INTERFACE_H_
#define MCAL_WATCHDOGTIMER_WDT_INTERFACE_H_





void WDT_ENABLE(void);
void WDT_DIABLE(void);
WDTErrState WDT_ErrStateSLEEP(SleepTimes_5vVcc SleepValue);


#endif /* MCAL_WATCHDOGTIMER_WDT_INTERFACE_H_ */
