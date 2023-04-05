/*
 * Led_Program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: hisha
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "Led_Interface.h"
LedErrState	Led_LedErrStateTurnOn(Led_Info *Led)
{
			if(Led->ConnectionType==Source_Connection)
			{
				DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_OUTPUT);
				DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_LOW);
			}
			else if (Led->ConnectionType==Sink_Connection)
			{
				DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_OUTPUT);
				DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_HIGH);
			}
			else
			{
				return ErrConnectionType ;
			}
			return LED_NoErr ;
}


LedErrState	Led_LedErrStateTurnOff(Led_Info *Led)
{
	if(Led->Led_Pin>=PIN0 && Led->Led_Pin<=PIN7)
		{
			if(Led->Led_Group>=Groub_A && Led->Led_Group<=Groub_D)
			{
				if(Led->ConnectionType==Source_Connection)
				{
					DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_OUTPUT);
					DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_HIGH);
				}
				else if (Led->ConnectionType==Sink_Connection)
				{
					DIO_ErrStateSetPinDirection(Led->Led_Group,Led->Led_Pin,DIO_OUTPUT);
					DIO_ErrStateSetPinValue(Led->Led_Group,Led->Led_Pin,DIO_LOW);
				}
				else
				{
					return ErrConnectionType ;
				}
			}
			else
			{
				return LED_GroubErr ;
			}
		}
		else
		{
			return ErrPin_Num ;
		}
		return LED_NoErr ;
}
