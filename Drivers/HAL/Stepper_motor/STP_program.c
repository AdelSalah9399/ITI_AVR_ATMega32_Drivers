/*
 * STP_program.c
 *
 *  Created on: Mar 29, 2023
 *      Author: Adel
 */
#include <util/delay.h>
#include "../../common/STD_TYPE.h"
#include "../../common/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "STP_Interface.h"
#include "STP_Config.h"

STPErrState ErrStateStpInitia(STP_INFO* STP)
{	ErrState Err;
	u8 flag=0;
	Err=DIO_ErrStateSetPinDirection(STP->Orange_Groub,STP->Orange_Pin,DIO_OUTPUT);
	if(Err!=NoErr) flag=1;
	Err=DIO_ErrStateSetPinDirection(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_OUTPUT);
	if(Err!=NoErr) flag=1;
	Err=DIO_ErrStateSetPinDirection(STP->Yellow_Groub,STP->Yellow_Pin,DIO_OUTPUT);
	if(Err!=NoErr) flag=1;
	Err=DIO_ErrStateSetPinDirection(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_OUTPUT);
	if(Err!=NoErr) flag=1;
	if(flag==1)
	{
		return STP_InitiaErr;
	}
	else
	{
		return STP_InitiaNOErr;
	}
}

STPErrState ErrStateStpRun(STP_INFO* STP,u8 Degree)
{	u16 Num_Of_Steps;
	u16 Num_Of_Iterations;
	u8 local_counter;
	if(STP->Step_type == FullStep)
	{
		if(STP->Rotate_direc == CW)
		{
			Num_Of_Steps	  = (Degree/DegreeforfullStep)+1;
			Num_Of_Iterations = Num_Of_Steps/FullStep;
			for(local_counter=0;local_counter<Num_Of_Iterations;local_counter++)
			{
			StpFullStepCW(STP);
			}
		}
		else if(STP->Rotate_direc == CCW)
		{
			Num_Of_Steps	  = (Degree/DegreeforfullStep)+1;
			Num_Of_Iterations = Num_Of_Steps/FullStep;
			for(local_counter=0;local_counter<Num_Of_Iterations;local_counter++)
			{
			StpFullStepCCW(STP);
			}
		}
		else
		{
			return STP_RotateDirectionErr;
		}
	}
	else if(STP->Step_type == HalfStep)
	{
		if(STP->Rotate_direc == CW)
		{
			Num_Of_Steps	  = (Degree/DegreeforfullStep)+1;
			Num_Of_Iterations = Num_Of_Steps/FullStep;
			for(local_counter=0;local_counter<Num_Of_Iterations;local_counter++)
			{
			StpHalfStepCW(STP);
			}
		}
		else if(STP->Rotate_direc == CCW)
		{
			Num_Of_Steps	  = (Degree/DegreeforfullStep)+1;
			Num_Of_Iterations = Num_Of_Steps/FullStep;
			for(local_counter=0;local_counter<Num_Of_Iterations;local_counter++)
			{
			StpHalfStepCCW(STP);
			}

		}
		else
		{
			return STP_RotateDirectionErr;
		}
	}
	else
	{
		return ErrStep;
	}
	return STP_NOErr;
}


static void StpFullStepCW   (STP_INFO* STP)
{
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_LOW);
	_delay_ms(2);
}
static void StpFullStepCCW  (STP_INFO* STP)
{
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_LOW);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
}
static void StpHalfStepCCW   (STP_INFO* STP)
{
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_LOW);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_LOW);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_LOW);
	_delay_ms(2);
}
static void StpHalfStepCW  (STP_INFO* STP)
{
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_LOW);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_LOW);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_LOW);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
	DIO_ErrStateSetPinValue(STP->Blue_Groub  ,STP->Blue_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Pink_Groub  ,STP->Pink_Pin  ,DIO_LOW);
	DIO_ErrStateSetPinValue(STP->Yellow_Groub,STP->Yellow_Pin,DIO_HIGH);
	DIO_ErrStateSetPinValue(STP->Orange_Groub,STP->Orange_Pin,DIO_HIGH);
	_delay_ms(2);
}
