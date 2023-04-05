/*
 * Led_Configuration.h
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#ifndef HAL_LED_LED_CONFIGURATION_H_
#define HAL_LED_LED_CONFIGURATION_H_
#include "Led_Interface.h"

typedef struct
{
	DIO_Groub_Num   	     Led_Group ;
	DIO_Pins_Num       	     Led_Pin ;
Led_ConnectionType    	 ConnectionType ;
}Led_Info;



#endif /* HAL_LED_LED_CONFIGURATION_H_ */
