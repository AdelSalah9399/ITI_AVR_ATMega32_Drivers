/*
 * EEPROM_Interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Adel
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_
#include "../../common/BIT_MATH.h"
#include "../../common/STD_TYPE.h"
#include "EEPROM_Private.h"

EEPROM_ErrState EEPROM_SendDataByte(u16 Address,u8 Data,u8 EEPROM_Num);
EEPROM_ErrState EEPROM_ReadDataByte(u16 Address,u8* Data,u8 EEPROM_Num);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
