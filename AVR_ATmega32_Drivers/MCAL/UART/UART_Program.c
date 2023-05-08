/*
 * UART_Program.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Adel
 */
#include"../../common/BIT_MATH.h"
#include"../../common/STD_TYPE.h"
#include"../DIO/DIO_Interface.h"
#include"UART_Register.h"
#include"UART_Config.h"
#include"UART_Private.h"



void UART_INIT(void)
{
#if RX_ENABLE==Enable
	SET_BIT(UCSRB,RXEN);
#elif RX_ENABLE==Disable
	CLR_BIT(UCSRB,RXEN);
#else
#error "WRONG RX CONFIG"
#endif

#if TX_ENABLE==Enable
	SET_BIT(UCSRB,TXEN);
#elif TX_ENABLE==Disable
	CLR_BIT(UCSRB,TXEN);
#else
#error "WRONG TX CONFIG"
#endif

	/************NOTE IT REVERSED***********/
#if UCSRC_OR_UBBRH_SEL==SEL_UCSRC
	CLR_BIT(UCSRC,URSEL);
#elif UCSRC_OR_UBBRH_SEL==SEL_UBBRH
	SET_BIT(UCSRC,URSEL);
#else
#error "WRONG UCSRC_SEL CONFIG"
#endif

#if RX_INTF_EN==Enable
	SET_BIT(UCSRB,RXCIE);
#elif RX_INTF_EN==Disable
	CLR_BIT(UCSRB,RXCIE);
#else
#error "WRONG CONFIG"
#endif
//
#if TX_INTF_EN==Enable
	SET_BIT(UCSRB,TXCIE);
#elif TX_INTF_EN==Disable
	CLR_BIT(UCSRB,TXCIE);
#else
#error "WRONG CONFIG"
#endif
//
#if DataEmpty_INTF_EN==Enable
	SET_BIT(UCSRB,UDRIE);
#elif DataEmpty_INTF_EN==Disable
	CLR_BIT(UCSRB,UDRIE);
#else
#error "WRONG CONFIG"
#endif
//
#if SYNCH_OR_ASYNCH_SEL==SEL_SYNCH
	SET_BIT(UCSRC,UMSEL);
#elif SYNCH_OR_ASYNCH_SEL==SEL_ASYNCH
	CLR_BIT(UCSRC,UMSEL);
#else
#error "WRONG SYNCH MODE CONFIG"
#endif
//
#if Parity_Mode==NO_PARITY
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);
#elif Parity_Mode==EVEN_PARITY
	CLR_BIT(UCSRC,UPM0);
	SET_BIT(UCSRC,UPM1);
#elif Parity_Mode==ODD_PARITY
	SET_BIT(UCSRC,UPM0);
	SET_BIT(UCSRC,UPM1);
#else
#error "WRONG PARITY CONFIG"
#endif
//
#if STOP_BitsNum==_1_bit
	CLR_BIT(UCSRC,USBS);
#elif STOP_BitsNum==_2_bit
	SET_BIT(UCSRC,USBS);
#else
#error "WRONG SYNCH MODE CONFIG"
#endif

//#if DATA_SIZE==Data_5_Bit
//	CLR_BIT(UCSRC,UCSZ0);
//	CLR_BIT(UCSRC,UCSZ1);
//	CLR_BIT(UCSRB,UCSZ2);
//#elif DATA_SIZE==Data_6_Bit
//	SET_BIT(UCSRC,UCSZ0);
//	CLR_BIT(UCSRC,UCSZ1);
//	CLR_BIT(UCSRB,UCSZ2);
//#elif DATA_SIZE==Data_7_Bit
//	CLR_BIT(UCSRC,UCSZ0);
//	SET_BIT(UCSRC,UCSZ1);
//	CLR_BIT(UCSRB,UCSZ2);
//#elif DATA_SIZE==Data_8_Bit
//	SET_BIT(UCSRC,UCSZ0);
//	SET_BIT(UCSRC,UCSZ1);
//	CLR_BIT(UCSRB,UCSZ2);
//#elif DATA_SIZE==Data_9_Bit
//	SET_BIT(UCSRC,UCSZ0);
//	SET_BIT(UCSRC,UCSZ1);
//	SET_BIT(UCSRB,UCSZ2);
//#else
//#error "WRONG DATA NUMBER CONFIG"
//#endif


UBRRL=Baud_Value;
}




void UART_SEND(u8 T_Data)
{
	while(GET_BIT(UCSRA,UDRE)==0);//**Wait** until UDR is EMPTY and ready to and ready to recive new data
	UDR=T_Data;
	while(GET_BIT(UCSRA,TXC)==0);//**Wait** until TRANSMITION complete DONE
	SET_BIT(UCSRA,TXC);			//Clear flag
}
u8 UART_RECEIVE(void)
{
	while(GET_BIT(UCSRA,RXC)==0);//**Wait** until RECIEVE complete DONE
	return UDR;
}
