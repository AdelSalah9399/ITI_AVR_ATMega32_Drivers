/*
 * DIO_private.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Adel
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#define MAX_RANG 0xff
#define MIN_RANG 0x00

typedef enum
{	NoErr,
	GroubErr,
	PinNumErr,
	DirectionErr,
	ValueErr,
	AddressErr
}ErrState;

typedef enum
{	Groub_A,
	Groub_B,
	Groub_C,
	Groub_D
}DIO_Groub_Num;

typedef enum
{	DIO_INPUT,
	DIO_OUTPUT
}DDR_Types;

typedef enum
{	DIO_LOW,
	DIO_HIGH
}DIO_PIN_STATE;

typedef enum
{	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_Pins_Num;


typedef enum
{	Pressed,
	notPressed

}DIO_switch_state;


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
