/*
 * Led_Private.h
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#ifndef HAL_LED_LED_PRIVATE_H_
#define HAL_LED_LED_PRIVATE_H_

typedef enum
{
	ErrConnectionType,
	ErrPin_Num,
	LED_GroubErr,
	LED_NoErr
}LedErrState;

typedef enum {
	Source_Connection ,
	Sink_Connection

}Led_ConnectionType;

#endif /* HAL_LED_LED_PRIVATE_H_ */
