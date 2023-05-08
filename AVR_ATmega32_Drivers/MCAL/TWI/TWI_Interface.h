/*
 * TWI_Interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"
#include "TWI_Private.h"

/*pass 0 to this function if the master will not be address (will never be slave)*/
void TWI_VoidMasterInit(u8 Slave_Address);
void TWI_VoidSlaveInit(u8 Slave_Address);

/*start condition cases*/
TWI_ErrState TWI_SendStartCondition(void);
TWI_ErrState TWI_SendRepeatedStart(void);

/*Address packge cases*/
TWI_ErrState TWI_SendSlaveAdd_Write(u8 Slave_Address);
TWI_ErrState TWI_SendSlaveAdd_Read(u8 Slave_Address);

/*Data cases*/
TWI_ErrState TWI_MasterWriteData(u8 DataByte);
TWI_ErrState TWI_MasterReadData(u8* DataByte);

void TWI_SendStopCondition(void);


#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
