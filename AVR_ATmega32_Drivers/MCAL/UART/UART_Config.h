/*
 * UART_Config.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Adel
 */

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_




#define UCSRC_OR_UBBRH_SEL			SEL_UCSRC
//									SEL_UBBRH

#define RX_ENABLE					Enable
//									Enable
#define TX_ENABLE					Enable
//									Disable

#define RX_INTF_EN					Disable
//									Enable
#define TX_INTF_EN					Disable
//									Enable
#define DataEmpty_INTF_EN			Disable
//									Enable


#define SYNCH_OR_ASYNCH_SEL			SEL_ASYNCH
//									SEL_SYNCH
#define Parity_Mode					NO_PARITY
//									EVEN_PARITY
//									ODD_PARITY
#define STOP_BitsNum				_1_bit
//									_2_bit
#define DATA_SIZE					Data_8_Bit
//									Data_6_Bit
//									Data_7_Bit
//									Data_5_Bit
//									Data_9_Bit

#define Baud_Value					51

//#define Transmit_9Bits			Disable
//#define Resive_9Bits				Disable
//#define Doubl_Rate_Speed			Enable
//#define Multi_Process_Comm		Disable

#endif /* MCAL_UART_UART_CONFIG_H_ */
