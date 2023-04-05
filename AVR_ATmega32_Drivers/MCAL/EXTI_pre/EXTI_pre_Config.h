/*
 * EXTI_pre_Config.h
 *
 *  Created on: Mar 31, 2023
 *      Author: Adel
 */

#ifndef MCAL_EXTI_PRE_EXTI_PRE_CONFIG_H_
#define MCAL_EXTI_PRE_EXTI_PRE_CONFIG_H_

/*choose one sense:
 * 				1- Falling_Edge
 * 	            2- Rissing_Edge
 *              3- ON_change
 *              4- Low_Level
 *									 */
#define INT0_Sense          ON_change
#define INT1_Sense          Falling_Edge
#define INT2_Sense          Falling_Edge

/*PIE Enable for INTx :
 * 				1- Enable
 * 				2- Disable
 * */
#define INT0_PIE_STATE       Enable
#define INT1_PIE_STATE       Disable
#define INT2_PIE_STATE       Disable


#endif /* MCAL_EXTI_PRE_EXTI_PRE_CONFIG_H_ */
