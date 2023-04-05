/*
 * SeVseg_interface.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Adel
 */

#ifndef _SEVSEG_INTERFACE_H_
#define _SEVSEG_INTERFACE_H_

#include "SeVseg_private.h"
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SeVseg_config.h"


SevErrState    SevSeg_SevErrStateSetNumber(u8 Number , SevSeg_info * SevenSegment1);

SevErrState    SevSeg_SevErrStateDisplayRange(SevSeg_info * SevenSegment1 , u8 start , u8 End );

SevErrState    SevSeg_SevErrStateDisplayMax(SevSeg_info * SevenSegment1);
#endif /* _SEVSEG_INTERFACE_H_ */
