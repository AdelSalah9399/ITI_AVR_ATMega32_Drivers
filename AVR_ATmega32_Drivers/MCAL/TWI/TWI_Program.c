/*
 * TWI_Program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"

#include "TWI_Config.h"
#include "TWI_Interface.h"
#include "TWI_Private.h"
#include "TWI_Register.h"

#include <util/delay.h>
#include "../DIO/DIO_Interface.h"
/*pass 0 to this function if the master will not be address (will never be slave)*/
void TWI_VoidMasterInit(u8 Slave_Address)
{
	/*set SCL frequency to 400kbps*/
			/*set TWBR=2;*/
	TWBR=2;
			/*write 00 on bit0&1 in TWSR*/
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	/*initialize the address*/
	if(Slave_Address!=0)
	{
		TWAR = (Slave_Address<<1);
	}

	/*Enable TWI*/
	SET_BIT(TWCR,TWEN);

}
void TWI_VoidSlaveInit(u8 Slave_Address)
{
	/*initialize the address*/
	TWAR = (Slave_Address<<1);

	/*Enable TWI*/
	SET_BIT(TWCR,TWEN);
}

TWI_ErrState TWI_SendStartCondition(void)
{
	/*send start condition*/
	SET_BIT(TWCR,TWSTA);

	/*Clear the flag to perform the operation*/
	SET_BIT(TWCR,TWINT);
	//////////////////////////////////////////////////////////////////////////////Checking part
	/*wait until the int flag raised again (so the operation done)*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*check the operation number*/
	if((TWSR & 0xF8)!=START_ACK)
	{
		return Start_ConErr;
	}
	return TWI_NoErr;
	//////////////////////////////////////////////////////////////////////////////
}
TWI_ErrState TWI_SendRepeatedStart(void)
{
	/*send start condition*/
	SET_BIT(TWCR,TWSTA);

	/*Clear the flag to perform the operation*/
	SET_BIT(TWCR,TWINT);
	//////////////////////////////////////////////////////////////////////////////Checking part
	/*wait until the int flag raised again (so the operation done)*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*check the operation number*/
	if((TWSR & 0xF8)!=REP_START_ACK)
	{
		return RepStart_ConErr;
	}
	return TWI_NoErr;
	//////////////////////////////////////////////////////////////////////////////
}

/*Address packge cases*/
TWI_ErrState TWI_SendSlaveAdd_Write(u8 Slave_Address)
{
	/*FIRTS clear start condition flag*/
	CLR_BIT(TWCR,TWSTA);
	/*Write slave address on the 7 MSB in TWDR register AND make the LSB bit 0 ->WRITE =0*/
	TWDR=(Slave_Address<<1);
	CLR_BIT(TWDR,0);
	/*Clear the flag to perform the operation*/
	SET_BIT(TWCR,TWINT);
	//////////////////////////////////////////////////////////////////////////////Checking part
	/*wait until the int flag raised again (so the operation done)*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*check the operation number*/
	if((TWSR & 0xF8)!=SLAVE_ADD_WR_ACK)
	{
		return SlaveAdd_WR_Err;
	}
	return TWI_NoErr;
	//////////////////////////////////////////////////////////////////////////////


}
TWI_ErrState TWI_SendSlaveAdd_Read(u8 Slave_Address)
{
	/*FIRTS clear start condition flag*/
	CLR_BIT(TWCR,TWSTA);
	/*Write slave address on the 7 MSB in TWDR register AND make the LSB bit 0 ->READ =1*/
	TWDR=(Slave_Address<<1);
	SET_BIT(TWDR,0);
	/*Clear the flag to perform the operation*/
	SET_BIT(TWCR,TWINT);
	//////////////////////////////////////////////////////////////////////////////Checking part
	/*wait until the int flag raised again (so the operation done)*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*check the operation number*/
	if((TWSR & 0xF8)!=SLAVE_ADD_RD_ACK)
	{
		return SlaveAdd_RD_Err;
	}
	return TWI_NoErr;
	//////////////////////////////////////////////////////////////////////////////
}

/*Data cases*/
TWI_ErrState TWI_MasterWriteData(u8 DataByte)
{
	/*write the data on TWDR*/
	TWDR=DataByte;

	/*Clear the flag to perform the operation*/
	SET_BIT(TWCR,TWINT);

	//////////////////////////////////////////////////////////////////////////////Checking part
	/*wait until the int flag raised again (so the operation done)*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*check the operation number*/
	if((TWSR & 0xF8)!= MASTER_WR_BYTE_ACK)
	{
//		DIO_ErrStateSetPinDirection(Groub_D,PIN0,DIO_OUTPUT);
//		DIO_ErrStateSetPinValue(Groub_D,PIN0,DIO_HIGH);
		return MasterData_WR_Err;
	}
	return TWI_NoErr;
	//////////////////////////////////////////////////////////////////////////////
}
TWI_ErrState TWI_MasterReadData(u8* DataByte)
{
	/*ENABLE Master ACK*/
	SET_BIT(TWCR,TWEA);
	/*Clear the flag to perform the operation*/
	SET_BIT(TWCR,TWINT);
	//////////////////////////////////////////////////////////////////////////////Checking part
	/*wait until the int flag raised again (so the operation done)*/
	while(GET_BIT(TWCR,TWINT)==0);

	/*check the operation number*/
	if((TWSR & 0xF8)!=MASTER_WR_BYTE_ACK)
	{
		return MasterData_RD_Err;
	}
//////////////////////////////////////////////////////////////////////////////
	/*read the recived data*/
		*DataByte=TWDR;
		return TWI_NoErr;
}

void TWI_SendStopCondition(void)
{
	/*send stop condition*/
	SET_BIT(TWCR,TWSTO);

	/*Clear the flag to perform the operation*/
	SET_BIT(TWCR,TWINT);
}
