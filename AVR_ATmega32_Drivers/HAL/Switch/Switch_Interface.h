/*
 * Swtich_Interface.h
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../Switch/Switch_Configuration.h"
#include "../Switch/Switch_Private.h"


SwitchErrState  SW_SwitchErrStateGetState(Switch_Info * Switch ,u8 * Result);

#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
