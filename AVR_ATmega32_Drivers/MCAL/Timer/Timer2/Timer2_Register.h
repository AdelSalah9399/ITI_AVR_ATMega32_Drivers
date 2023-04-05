/*
 * Timer_Register.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_REGISTER_H_
#define MCAL_TIMER_TIMER2_TIMER2_REGISTER_H_


#define TCCR2 (*(volatile u8*)(0x45))
#define TCNT2 (*(volatile u8*)(0x44))
#define OCR2  (*(volatile u8*)(0x43))
#define TIMSK (*(volatile u8*)(0x59))


#endif /* MCAL_TIMER_TIMER2_TIMER2_REGISTER_H_ */
