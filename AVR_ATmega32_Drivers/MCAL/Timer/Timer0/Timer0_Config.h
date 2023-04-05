/*
 * Timer2_Config.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */

#ifndef MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_

/*Timer Mode*/
#define TIMER0_MODE Normal_Mode

/*TIMER ON/OFF*/
#define TIMER0_OnOff ON

/*Clock-NORMAL MODE- Prescaling options*/
#define T0_NM_Presaclling_Value _8_PreScalling

/*Clock-NORMAL MODE- PreLoad VALUE*/
#define T0_PreloadValue 244
/*Clock NUMBER OF COUNTES VALUE*/
#define T0_NumOfCount   1954

/*CTC-OC2 MODE*/
#define CTC_OC0_mode Normal_port

/*TIMER INTERRUPT ENABLE*/
#define T0_NormalMode_OverFlow_INT_PIE ENABLE
#define T0_CTC_INT ENABLE


/*TIMER FLAGES ENABLE*/
/*
#define NormalMode_FLAG_INT xx
#define CTC_FLAG_INT xx
*/




#endif /* MCAL_TIMER_TIMER0_TIMER0_CONFIG_H_ */
