/*
 * SeVseg_private.h
 *
 *  Created on: Mar 24, 2023
 *      Author: Adel
 */

#ifndef _SEG_SEVSEG_PRIVATE_H_
#define _SEG_SEVSEG_PRIVATE_H_


#define SevSeg_ArrSize  10
/*Cathod -> Led On if write One*/
#define Num_0      0x3F
#define Num_1      0x06
#define Num_2      0x5B
#define Num_3      0x4F
#define Num_4      0x66
#define Num_5      0x6D
#define Num_6      0x7D
#define Num_7      0x07
#define Num_8      0x7F
#define Num_9      0x6F

#define max_value 9
#define min_value 0

typedef enum
{
	NumberErr,
	NoErr_7seg
}SevErrState;

typedef enum
{	port_Disable,
	port_Enable
}PORT;

typedef enum
{	pin_Disable,
	pin_Enable
}PIN;

typedef enum
{	common_Cathod,
	common_Anode
}Segmant_Type;

typedef enum
{	GroubA,
	GroubB,
	GroubC,
	GroubD
}Groubs;



#endif /* _SEG_SEVSEG_PRIVATE_H_ */
