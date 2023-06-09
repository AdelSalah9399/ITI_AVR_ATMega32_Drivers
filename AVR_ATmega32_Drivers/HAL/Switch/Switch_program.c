/*
 * Switch_program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */
#include "../Switch/Switch_Interface.h"

SwitchErrState  SW_SwitchErrStateGetState(Switch_Info * Switch ,SwitchState * Result)
{


	if(Switch->ConnectionType==InternalPullUp)
	{
		DIO_ErrStateSetPinDirection(Switch->SW_Group,Switch->SW_Pin,DIO_INPUT);
		DIO_ErrStateSetPinValue(Switch->SW_Group,Switch->SW_Pin,DIO_HIGH);
		DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,Result);
	}
	else if(Switch->ConnectionType==ExternalPullUp)
	{
		DIO_ErrStateSetPinDirection(Switch->SW_Group,Switch->SW_Pin,DIO_INPUT);
		DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,Result);
	}
	else if(Switch->ConnectionType==ExternalPullDown)
	{
		DIO_ErrStateSetPinDirection(Switch->SW_Group,Switch->SW_Pin,DIO_INPUT);
		DIO_ErrStateReadPinValue(Switch->SW_Group,Switch->SW_Pin,Result);
	}
	else
	{
		return Switch_Connection_Error;
	}
	return NoERR ;

}
