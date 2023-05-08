/*
 * Lcd_Interface.h
 *
 *  Created on: Mar 25, 2023
 *      Author: hisha
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "../../common/STD_TYPE.h"
#include "LCD_Register.h"
#include "Lcd_Privet.h"

void Lcd_VoidSendChar(u8 Copy_Char, Lcd_Info * Lcd);
void Lcd_VoidSendCommand(u8 Copy_Command, Lcd_Info * Lcd);


void Lcd_VoidInit(Lcd_Info * Lcd);


void Lcd_VoidSendString(u8 *Address_String ,Lcd_Info * Lcd);
void Lcd_VoidSendNum(u8 Copy_Num, Lcd_Info * Lcd);
void Lcd_VoidSendSpecChar(Lcd_Info * Lcd,u8 SpecAddCGran,u8* Ch);


LCD_ErrState Lcd_VoidGoXY(Lcd_Info * Lcd ,u8 Copy_XLocation ,u8 Copy_YLocation );

void Lcd_VoidSendNumForTimers(u8 Copy_Num, Lcd_Info * Lcd);


#endif /* HAL_LCD_LCD_INTERFACE_H_*/
