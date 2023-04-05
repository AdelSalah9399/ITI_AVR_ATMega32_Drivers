/*
 * EXTI_pre_Private.h
 *
 *  Created on: Mar 31, 2023
 *      Author: Adel
 */

#ifndef MCAL_EXTI_PRE_EXTI_PRE_PRIVATE_H_
#define MCAL_EXTI_PRE_EXTI_PRE_PRIVATE_H_

/*sense types*/
#define Falling_Edge 1
#define Rissing_Edge 2
#define ON_change 	 3
#define Low_Level	 4
/*PIE types*/
#define Enable       1
#define Disable      2

/*SREG Bits*/
#define GIE_EN_Bit 7
/*GIFR Bits*/
#define INT0_Flag_Bit 6
#define INT1_Flag_Bit 7
#define INT2_Flag_Bit 5
/*GICR Bits*/
#define INT0_PIE_Bit 6
#define INT1_PIE_Bit 7
#define INT2_PIE_Bit 5
/*MCUCSR Bits*/
#define INT2_Trig_Bit 6
/*MCUCR Bits*/
#define INT0_Trig_Bit0 0
#define INT0_Trig_Bit1 1
#define INT1_Trig_Bit0 2
#define INT1_Trig_Bit1 3


#endif /* MCAL_EXTI_PRE_EXTI_PRE_PRIVATE_H_ */
