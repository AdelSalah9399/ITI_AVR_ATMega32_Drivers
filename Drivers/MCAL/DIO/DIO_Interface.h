/*
 * DIO_Interface.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Adel
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "../../common/STD_TYPE.h"
#include "../../common/BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_private.h"



ErrState DIO_ErrStateSetPinDirection(DIO_Groub_Num GroupNum ,DIO_Pins_Num PinNum ,DDR_Types Direction); 	//config DDR
ErrState DIO_ErrStateSetPinValue(DIO_Groub_Num GroupNum ,DIO_Pins_Num PinNum ,DIO_PIN_STATE ValueState);		//write on pin
ErrState DIO_ErrStateReadPinValue(DIO_Groub_Num GroupNum ,DIO_Pins_Num PinNum ,u8* Result);		            //read from pin

ErrState DIO_ErrStateSetGroubDirection(DIO_Groub_Num GroupNum ,DDR_Types Direction);			    	//config all groub DDR
ErrState DIO_ErrStateSetGroubValue(DIO_Groub_Num GroupNum ,u8 ValueState);								//write on all groub
ErrState DIO_ErrStateReadGroubValue(DIO_Groub_Num GroupNum ,u8* Result);	 				    		//read from all groub

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
