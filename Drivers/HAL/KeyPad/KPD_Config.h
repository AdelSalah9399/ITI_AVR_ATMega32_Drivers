/*
 * KPD_Config.h
 *
 *  Created on: Mar 27, 2023
 *      Author: Adel
 */

#ifndef HAL_KEYPAD_KPD_CONFIG_H_
#define HAL_KEYPAD_KPD_CONFIG_H_

typedef struct
{	/*Rows*/
	DIO_Groub_Num	R0_groub_num;
	DIO_Pins_Num 	R0_pin_num;
	DIO_Groub_Num	R1_groub_num;
	DIO_Pins_Num 	R1_pin_num;
	DIO_Groub_Num	R2_groub_num;
	DIO_Pins_Num 	R2_pin_num;
	DIO_Groub_Num	R3_groub_num;
	DIO_Pins_Num 	R3_pin_num;
	/*Coloums*/
	DIO_Groub_Num	C0_groub_num;
	DIO_Pins_Num 	C0_pin_num;
	DIO_Groub_Num	C1_groub_num;
	DIO_Pins_Num 	C1_pin_num;
	DIO_Groub_Num	C2_groub_num;
	DIO_Pins_Num 	C2_pin_num;
	DIO_Groub_Num	C3_groub_num;
	DIO_Pins_Num 	C3_pin_num;
}KPD_INFO;


#endif /* HAL_KEYPAD_KPD_CONFIG_H_ */
