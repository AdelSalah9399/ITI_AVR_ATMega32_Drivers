/*
 * TWI_Private.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */

#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

typedef enum
{	TWI_NoErr,
	Start_ConErr,
	RepStart_ConErr,
	SlaveAdd_WR_Err,
	SlaveAdd_RD_Err,
	MasterData_WR_Err,
	MasterData_RD_Err

}TWI_ErrState;


#define START_ACK			         0x08
#define REP_START_ACK                0x10
#define SLAVE_ADD_WR_ACK             0x18
#define SLAVE_ADD_RD_ACK             0x40
#define MASTER_WR_BYTE_ACK           0x28
#define MASTER_RD_BYTE_ACK           0x50
#define MASTER_RD_BYTE_NACK          0x58
#define SLAVE_ADD_RCVD_RD_REQ        0xA8
#define SLAVE_ADD_RCVD_WR_REQ        0x60
#define SLAVE_DATA_RCVD              0x80
#define SLAVE_BYTE_TRANSMIIT         0xB8


#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
