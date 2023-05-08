/*
 * TWI_Register.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */

#ifndef MCAL_TWI_TWI_REGISTER_H_
#define MCAL_TWI_TWI_REGISTER_H_

#define TWBR (*(volatile u8*)(0x20))		/*bit rate register*/

#define TWCR (*(volatile u8*)(0x56))		/*control register*/
#define TWINT	7				/*int flag*/
#define TWEA	6				/*enable ack*/
#define TWSTA	5				/*start condition*/
#define TWSTO	4				/*stop condition*/
#define TWWC	3				/*write collosion flag*/
#define TWEN	2				/*TWI ENABLE*/
#define TWIE	0				/*int enable*/

#define TWSR (*(volatile u8*)(0x21))		/*state register*/
#define TWPS0	0				/*prescale bit0	*/
#define TWPS1	1				/*prescale bit1*/

#define TWDR (*(volatile u8*)(0x23))		/*data register*/

#define TWAR (*(volatile u8*)(0x22))		/*slave adderss register*/
/*7 BITS FROM 1 TO 7*/
#define TWGCE	0				/*general call enable*/


#endif /* MCAL_TWI_TWI_REGISTER_H_ */
