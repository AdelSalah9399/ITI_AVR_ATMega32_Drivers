/*
 * Timer_Interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_
#define MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_


void Timer0ModeSetting();
void T0NormalModePreScalling();
void CTC_OC0Pin_Func();
void Timer0NM_PIE_INTEnable();
void Timer0CTC_PIE_INTEnable();
void Timer0_PreloadValue();



#endif /* MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_ */
