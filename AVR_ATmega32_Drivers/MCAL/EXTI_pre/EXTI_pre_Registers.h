/*
 * EXTI_pre_Registers.h
 *
 *  Created on: Mar 31, 2023
 *      Author: Adel
 */

#ifndef MCAL_EXTI_PRE_EXTI_PRE_REGISTERS_H_
#define MCAL_EXTI_PRE_EXTI_PRE_REGISTERS_H_

/*Trigger type for INT0 & INT1*/
#define MCUCR  (*(volatile u8*)(0X55))
/*Trigger type for INT2 */
#define MCUCSR (*(volatile u8*)(0X54))
/*ENABLE for PIE*/
#define GICR   (*(volatile u8*)(0x5B))
/*Flag register*/
#define GIFR   (*(volatile u8*)(0x5A))
/*ENABLE for GIE*/
#define SREG   (*(volatile u8*)(0x5F))

#define NULL (void*)0
#endif /* MCAL_EXTI_PRE_EXTI_PRE_REGISTERS_H_ */
