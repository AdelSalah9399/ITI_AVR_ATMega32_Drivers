/*
 * EXTI_pre_Interface.h
 *
 *  Created on: Mar 31, 2023
 *      Author: Adel
 */

#ifndef MCAL_EXTI_PRE_EXTI_PRE_INTERFACE_H_
#define MCAL_EXTI_PRE_EXTI_PRE_INTERFACE_H_


void EXTI_INT0_InitiaTriggerPIEoptions(void);
void EXTI_INT1_InitiaTriggerPIEoptions(void);
void EXTI_INT2_InitiaTriggerPIEoptions(void);


void EXTIpre_INT0_Set_CallBack(void(*INTx)(void));
void EXTIpre_INT1_Set_CallBack(void(*INTx)(void));
void EXTIpre_INT2_Set_CallBack(void(*INTx)(void));

void EXTIpre_Enable_GIE ();
void EXTIpre_Disable_GIE();
#endif /* MCAL_EXTI_PRE_EXTI_PRE_INTERFACE_H_ */
