/*
 * UART_Interface.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Adel
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_


void UART_INIT(void);
void UART_SEND(u8 T_Data);
u8 UART_RECEIVE(void);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
