/*
 * Timer_Interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_
#define MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_


void Timer2ModeSetting();
void T2NormalModePreScalling();
void CTC_OC2Pin_Func();
void Timer2NM_PIE_INTEnable();
void Timer2CTC_PIE_INTEnable();
void Timer2_PreloadValue();
void OCR2_TimeOverFlow();
void SetCallBack(void (*APPfunc)(void));


#endif /* MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_ */
