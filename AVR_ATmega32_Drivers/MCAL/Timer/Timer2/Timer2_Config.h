/*
 * Timer2_Config.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER2_TIMER2_CONFIG_H_
#define MCAL_TIMER_TIMER2_TIMER2_CONFIG_H_

/*Timer Mode*/
#define TIMER2_MODE       					Fast_PWM_Mode


#define FastPWM_InvOrNon					SetOnComp_Inv

/*TIMER ON/OFF*/
#define TIMER2_OnOff			 			ON

/*Clock-NORMAL MODE- Prescaling options*/
#define T2_NM_Presaclling_Value 			_8_PreScalling  //8clock

/***Clock-NORMAL MODE- PreLoad VALUE*/
#define T2_PreloadValue 					192            //192clock

/*TIMER INTERRUPT ENABLE*/
#define T2_NormalMode_OverFlow_INT_PIE 		ENABLE
#define T2_CTC_INT 							ENABLE


/************************************Macros for the ISR*****************************8*/
/***Clock NUMBER OF COUNTES VALUE*/
#define T2_NumOfCount   					4000
/***Clock NUMBER OF COUNTES VALUE*/
#define OC2_timeOverFlow   					5

/*CTC-OC2 MODE*/
#define CTC_OC2_mode 						Normal_port


#endif /* MCAL_TIMER_TIMER2_TIMER2_CONFIG_H_ */
