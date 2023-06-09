/*
 * DIO_register.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Adel
 */

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

#define NULL (void*)0

/*Direction Register*/
#define DDRA   (*(volatile u8*)(0x3A))
#define DDRB   (*(volatile u8*)(0x37))
#define DDRC   (*(volatile u8*)(0x34))
#define DDRD   (*(volatile u8*)(0x31))
/*Output Register  (high/low)*/
#define PORTA  (*(volatile u8*)(0x3B))
#define PORTB  (*(volatile u8*)(0x38))
#define PORTC  (*(volatile u8*)(0x35))
#define PORTD  (*(volatile u8*)(0x32))
/*Input Register  (read)*/
#define PINA   (*(volatile u8*)(0x39))
#define PINB   (*(volatile u8*)(0x36))
#define PINC   (*(volatile u8*)(0x33))
#define PIND   (*(volatile u8*)(0x30))


#endif /* MCAL_DIO_DIO_REGISTER_H_ */
