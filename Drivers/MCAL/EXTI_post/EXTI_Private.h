/*
 * EXTI_Private.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Adel
 */

#ifndef MCAL_EXTI_POST_EXTI_PRIVATE_H_
#define MCAL_EXTI_POST_EXTI_PRIVATE_H_
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


typedef enum
{	EXTI_NoErr,
	TrigErr,
	ErrINTnum,
	INVALID_INT,
	ErrPIE,
	nullptr
}EXTI_Errs;

typedef enum
{
	INT0,
	INT1,
	INT2
}INT_Num;

typedef enum
{	 Low_Level,
	 ON_change,
	 Falling_Edge,
	 Rising_Edge
}TRIG_INFO;

typedef enum
{	Disable,
	Enable
}PIE_EN;
#endif /* MCAL_EXTI_POST_EXTI_PRIVATE_H_ */
