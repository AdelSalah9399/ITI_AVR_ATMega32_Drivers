/*
 * Timer_Interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_
#define MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_


void Timer2Init();
void CTC_OC2Pin_Func();
void Timer2_OF_PIE_INTEnable();
void Timer2_CMPMatch_PIE_INTEnable();
void Timer2_PreloadValue();
void OCR2_CompValue(u8 compvalue);
//void T2PreScalling();
void FastPWM_INV_NonInv();
void SetCallBack(void (*APPfunc)(void));


#endif /* MCAL_TIMER_TIMER2_TIMER2_INTERFACE_H_ */
