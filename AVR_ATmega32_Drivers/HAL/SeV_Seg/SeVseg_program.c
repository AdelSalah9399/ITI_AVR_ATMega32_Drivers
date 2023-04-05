/*
 * SeVseg_program.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Adel
 */


#include "SeVseg_interface.h"
#include <util/delay.h>

u8 SevSeg_Arr[SevSeg_ArrSize]=
{		Num_0 ,
		Num_1 ,
		Num_2 ,
		Num_3 ,
		Num_4 ,
		Num_5 ,
		Num_6 ,
		Num_7 ,
		Num_8 ,
		Num_9 ,
};
SevErrState    SevSeg_SevErrStateSetNumber(u8 Req_Number , SevSeg_info * SevenSegment1)
{
	if (Req_Number>=min_value && Req_Number<=max_value)
			{
				if(SevenSegment1->SevSeg_Type == common_Cathod)
				{	DIO_ErrStateSetGroubDirection(SevenSegment1->SevSeg_Group ,MAX_RANG);
					DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUTPUT);
					DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_LOW);
					DIO_ErrStateSetGroubValue(SevenSegment1->SevSeg_Group ,SevSeg_Arr[Req_Number]);
				}

				else if(SevenSegment1->SevSeg_Type == common_Anode)
				{	DIO_ErrStateSetGroubDirection(SevenSegment1->SevSeg_Group ,MAX_RANG);
					DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUTPUT);
					DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_HIGH);
					DIO_ErrStateSetGroubValue(SevenSegment1->SevSeg_Group ,SevSeg_Arr[Req_Number]);
				}
				return NoErr_7seg;
			}
	else
	{
		return NumberErr ;
	}
}


SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 start , u8 End )
{	u8 counter;

				if(SevenSegment1->SevSeg_Type == common_Cathod)
				{	DIO_ErrStateSetGroubDirection(SevenSegment1->SevSeg_Group ,MAX_RANG);
					DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUTPUT);
					DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_LOW);
					for(counter=start;counter<=End;counter++)
						{_delay_ms(50);
						DIO_ErrStateSetGroubValue(SevenSegment1->SevSeg_Group ,SevSeg_Arr[counter]);
						_delay_ms(500);
						}
				}

				else if(SevenSegment1->SevSeg_Type == common_Anode)
				{	DIO_ErrStateSetGroubDirection(SevenSegment1->SevSeg_Group ,MAX_RANG);
					DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUTPUT);
					DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_HIGH);
					for(counter=start;counter<=End;counter++)
						{
						DIO_ErrStateSetGroubValue(SevenSegment1->SevSeg_Group ,SevSeg_Arr[counter]);
						_delay_ms(500);
						}
				}
				return NoErr_7seg;
}

SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1)
{
	u8 counter;
			if(SevenSegment1->SevSeg_Type == common_Cathod)
			{	DIO_ErrStateSetGroubDirection(SevenSegment1->SevSeg_Group ,MAX_RANG);
				DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUTPUT);
				DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_LOW);
				for(counter=min_value;counter<=max_value;counter++)
					{	_delay_ms(50);
						DIO_ErrStateSetGroubValue(SevenSegment1->SevSeg_Group ,SevSeg_Arr[counter]);
						_delay_ms(500);
					}
			}

			else if(SevenSegment1->SevSeg_Type == common_Anode)
			{	DIO_ErrStateSetGroubDirection(SevenSegment1->SevSeg_Group ,MAX_RANG);
				DIO_ErrStateSetPinDirection(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_OUTPUT);
				DIO_ErrStateSetPinValue(SevenSegment1->SevSeg_EnablePort,SevenSegment1->SevSeg_EnablePin,DIO_HIGH);
				for(counter=min_value;counter<=max_value;counter++)
					{_delay_ms(50);
					DIO_ErrStateSetGroubValue(SevenSegment1->SevSeg_Group ,SevSeg_Arr[counter]);
					_delay_ms(500);
					}
			}
			return NoErr_7seg;
}

