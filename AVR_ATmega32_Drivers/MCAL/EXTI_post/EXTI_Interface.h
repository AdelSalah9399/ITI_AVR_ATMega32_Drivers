/*
 * EXTI_Interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Adel
 */

#ifndef MCAL_EXTI_POST_EXTI_INTERFACE_H_
#define MCAL_EXTI_POST_EXTI_INTERFACE_H_
#include"EXTI_Private.h"

/*******************************************************************************************************************************************
 *function action: this function is initialization for the INT0 & INT1 & INT2                                                               *
 *you must choose the *sense option* from this list :                                                                                       *
 *	1- Falling_Edge                                                                                                                         *
 *  2- Rissing_Edge                      NOTE that for >>INT2<< there is only 1- Falling_Edge                                               *
 *  3- ON_change                                                              2- Rissing_Edge                                               *
 *  4- Low_Level                                                                                                                            *
 * 	you must choose the *INTx* from this list :                                                                                             *
 * 	1-INT0                                                                                                                                  *
 * 	2-INT1                                                                                                                                  *
 * 	3-INT3                                                                                                                                  *
 *you must choose the *PIE state* from this list :                                                                                          *
 * 	1-Enable                                                                                                                                *
 * 	2-Disable                                                                                                                               *
 * 	                                                                                                                                        *
 *input : INTx  +  sense type  +  PIE option                                                                                                *
 *output: make the pin INTx ready for receving the interrupt                                                                                *
 * *******************************************************************************************************************************************/
EXTI_Errs EXTI_INTx_InitiaTriggerOptions(INT_Num INT,TRIG_INFO Trig_Type,PIE_EN PIE);


/*******************************************************************************************************************************************
 *function action: this function Enable and Disable the PIE for IN			                                                               *
 * 	1-INT0                                                                                                                                  *
 * 	2-INT1                                                                                                                                  *
 * 	3-INT3                                                                                                                                  *
 *you must choose the *PIE state* from this list :                                                                                          *
 * 	1-Enable                                                                                                                                *
 * 	2-Disable                                                                                                                               *
 * 	                                                                                                                                        *
 *input : INTx  +  PIE option                                          				                                                        *
 *output: Enable and Disable the PIE                                                                                                        *
 * *******************************************************************************************************************************************/
void EXTI_Enable_GIE ();
void EXTI_Disable_GIE();
EXTI_Errs EXTI_INTx_PIESetRest(INT_Num INT,PIE_EN PIE);


EXTI_Errs EXTI_ClearFlag(INT_Num INT);


EXTI_Errs EXTI_INT0_Set_CallBack(void(*INTx)(void));
EXTI_Errs EXTI_INT1_Set_CallBack(void(*INTx)(void));
EXTI_Errs EXTI_INT2_Set_CallBack(void(*INTx)(void));

#endif /* MCAL_EXTI_POST_EXTI_INTERFACE_H_ */
