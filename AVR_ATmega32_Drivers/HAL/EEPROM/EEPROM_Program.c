/*
 * EEPROM_Program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"
#include "EEPROM_Config.h"
#include "../../MCAL/TWI/TWI_Interface.h"

#include"../../MCAL/DIO/DIO_Interface.h"

EEPROM_ErrState EEPROM_SendDataByte(u16 Address,u8 Data,u8 EEPROM_Num)
{
	if(EEPROM_Num<=1)
	{
	TWI_SendStartCondition();
	TWI_SendSlaveAdd_Write((1010<<3)|(EEPROM_Num<<2)|(Address));
	TWI_MasterWriteData((u8)Address); //send the rest of the location address
	TWI_MasterWriteData(Data);
	TWI_SendStopCondition();

	}
	else
	{
		return EEPROM_NumERR;
	}
	return EPPROM_NOERR;
}
EEPROM_ErrState EEPROM_ReadDataByte(u16 Address,u8* Data,u8 EEPROM_Num)
{
	if(EEPROM_Num<=1)
	{
	TWI_SendStartCondition();
	TWI_SendSlaveAdd_Write((1010<<3)|(EEPROM_Num<<2)|(Address));
	TWI_MasterWriteData((u8)Address); //send the rest of the location address
	/*Repeated start to read the data instead of write on bus*/
	TWI_SendStopCondition();
	TWI_SendSlaveAdd_Read((1010<<3)|(EEPROM_Num<<2)|(Address));
	TWI_MasterReadData(Data);
	TWI_SendStopCondition();
	}
	else
	{
		return EEPROM_NumERR;
	}
	return EPPROM_NOERR;
}

