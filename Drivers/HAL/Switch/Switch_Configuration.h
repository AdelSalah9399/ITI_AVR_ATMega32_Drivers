/*
 * Switch_Configuration.h
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#ifndef HAL_SWITCH_SWITCH_CONFIGURATION_H_
#define HAL_SWITCH_SWITCH_CONFIGURATION_H_

#include "Switch_Private.h"

typedef struct
{
	DIO_Groub_Num  			SW_Group ;
	DIO_Pins_Num    		SW_Pin ;
	SwitchConnectionType   	ConnectionType ;
}Switch_Info ;


#endif /* HAL_SWITCH_SWITCH_CONFIGURATION_H_ */
