/*
 * WDT_Register.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Adel
 */

#ifndef MCAL_WATCHDOGTIMER_WDT_REGISTER_H_
#define MCAL_WATCHDOGTIMER_WDT_REGISTER_H_

#define WDTCR (*(volatile u8*)(0x41))
#define WDE      3
#define WDTOE    4
/*WDT prescaller pins 0:2 will be handle with BIT MASK*/
/*
	sleep_16_3m  =0
	sleep_32_5ms =1
	sleep_65ms   =2
	sleep_0_13s  =3
	sleep_0_26s  =4
	sleep_0_52s  =5
	sleep_1s  	 =6
	sleep_2_1s   =7
*/



#endif /* MCAL_WATCHDOGTIMER_WDT_REGISTER_H_ */
