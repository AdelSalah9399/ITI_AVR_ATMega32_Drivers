/*
 * STP_Private.h
 *
 *  Created on: Mar 29, 2023
 *      Author: Adel
 */

#ifndef HAL_STEPPER_MOTOR_STP_PRIVATE_H_
#define HAL_STEPPER_MOTOR_STP_PRIVATE_H_

typedef enum
{
	STP_InitiaNOErr,
	STP_NOErr,
	STP_InitiaErr,
	ErrStep,
	STP_RotateDirectionErr
}STPErrState;

typedef enum
{
	FullStep=4,
	HalfStep=8
}StepType;

typedef enum
{
	CW,
	CCW
}RotateDirec;

typedef struct
{
	DIO_Groub_Num  Blue_Groub;
	DIO_Pins_Num   Blue_Pin;
	DIO_Groub_Num  Pink_Groub;
	DIO_Pins_Num   Pink_Pin;
	DIO_Groub_Num  Yellow_Groub;
	DIO_Pins_Num   Yellow_Pin;
	DIO_Groub_Num  Orange_Groub;
	DIO_Pins_Num   Orange_Pin;
	StepType	   Step_type;
	RotateDirec	   Rotate_direc;
}STP_INFO;


#endif /* HAL_STEPPER_MOTOR_STP_PRIVATE_H_ */
