/*
 * STP_Interface.h
 *
 *  Created on: Mar 29, 2023
 *      Author: Adel
 */

#ifndef HAL_STEPPER_MOTOR_STP_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STP_INTERFACE_H_
#include "STP_Config.h"
#include "STP_Private.h"

STPErrState ErrStateStpInitia(STP_INFO* STP);

STPErrState ErrStateStpRun(STP_INFO* STP,u8 Degree);

static void StpFullStepCW   (STP_INFO* STP);
static void StpFullStepCCW  (STP_INFO* STP);
static void StpHalfStepCW   (STP_INFO* STP);
static void StpHalfStepCCW  (STP_INFO* STP);

#endif /* HAL_STEPPER_MOTOR_STP_INTERFACE_H_ */
