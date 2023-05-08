
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Lcd_Interface.h"

/*---------------------------------------counters to solve the second line BUG---------------------*/
u8 counter=0;
u8 counter2=0;

void Lcd_VoidSendCommand(u8 Copy_Command, Lcd_Info * Lcd)
{
	/*RS->LOW*/
	DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_LOW);
	/*RW-> LOW*/
	DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_LOW) ;
	/*Group = COmmand */
	DIO_ErrStateSetGroubValue(Lcd->Data_Group , Copy_Command) ;
	/*Enable*/
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_HIGH) ;
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_LOW) ;
	_delay_ms(1);
}
void Lcd_VoidSendChar(u8 Copy_Char, Lcd_Info * Lcd)
{	if(counter<16)
	{
	/*RS->High*/
	DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_HIGH);
	/*RW-> LOW*/
	DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_LOW) ;
	/*Group = COmmand */
	DIO_ErrStateSetGroubValue(Lcd->Data_Group , Copy_Char) ;
	/*Enable*/
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_HIGH) ;
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_LOW) ;
	_delay_ms(1);
	counter++ ;
	}
	else if(counter>=16)
	{
		Lcd_VoidSendCommand((LCD_SetAddressDDRAM + LCD_SecondLine + counter2),Lcd);
		counter2++;
		/*RS->High*/
		DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_HIGH);
		/*RW-> LOW*/
		DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_LOW) ;
		/*Group = COmmand */
		DIO_ErrStateSetGroubValue(Lcd->Data_Group , Copy_Char) ;
		/*Enable*/
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_HIGH) ;
		_delay_ms(1);
		DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_LOW) ;
		_delay_ms(1);
	}
}

void Lcd_VoidInit(Lcd_Info * Lcd)
{
	/*Set Directions*/
	DIO_ErrStateSetPinDirection(Lcd->RS_Group,Lcd->RS_Pin,DIO_OUTPUT);
	DIO_ErrStateSetPinDirection(Lcd->RW_Group,Lcd->RW_Pin,DIO_OUTPUT);
	DIO_ErrStateSetPinDirection(Lcd->E_Group,Lcd->E_Pin,DIO_OUTPUT);
	DIO_ErrStateSetGroubDirection(Lcd->Data_Group,MAX_RANG);
	/*Wait More than 30 ms */
	_delay_ms(40);
	/*Sent Function Set*/
	Lcd_VoidSendCommand(LCD_Set8Bit2Line5x8,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(1);
	/*Sent Display on/off*/
	Lcd_VoidSendCommand(LCD_CursorON,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(1);
	/*Sent Clear*/
	Lcd_VoidSendCommand(LCD_ClearDisplay,Lcd) ;
	/*wait more than 39us*/
	_delay_ms(2);

}
/*THE STRING ARRAY SIZE MUST BE NUMBER OF ELEMENTS +1*/
void Lcd_VoidSendString(u8 *Address_String ,Lcd_Info * Lcd)
{
	/*Counter For Loop */
	u8 Local_Counter = 0 ;
	/*Loop*/
	while (Address_String[Local_Counter]!='\0')
	{
		/*Send Char */
		Lcd_VoidSendChar(Address_String[Local_Counter],Lcd) ;
		/*Increment Counter */
		Local_Counter++;
	}
}

LCD_ErrState Lcd_VoidGoXY(Lcd_Info * Lcd ,u8 Copy_XLocation ,u8 Copy_YLocation )
{
	u8 Local_Address = 0 ;
	if (Copy_XLocation == 0)
	{
		Local_Address = Copy_YLocation ;
	}
	else if (Copy_XLocation == 1)
	{
		Local_Address = Copy_YLocation + LCD_SecondLine ;
	}
	else
	{
		return ErrLocation_X;
	}
	Lcd_VoidSendCommand(LCD_SetAddressDDRAM + Local_Address,Lcd);
	return NoErr_LCD;
}


void Lcd_VoidSendNum(u8 Copy_Num, Lcd_Info * Lcd)
{
	u8 arr[10];
	u8 counter=0;

	while(Copy_Num!=0)
	{
		for(u8 i=0;i<10;i++)
		{
			arr[i]=(Copy_Num%10);
			Copy_Num/=10;
			if(Copy_Num==0) break;
			counter++;
		}
	}
	for(s8 i=counter;i>=0;i--)    //IMPORTANT i MUST  BE S8 to avoid infinity loop
	{
		Lcd_VoidSendChar(arr[i]+'0',Lcd);
	}
}

void Lcd_VoidSendSpecChar(Lcd_Info * Lcd,u8 SpecAddCGran,u8* Ch)
{
	Lcd_VoidSendCommand(LCD_SetAddressCGRAM+(SpecAddCGran*8),Lcd);

	for(u8 i=0;i<8;i++)
	{
		Lcd_VoidSendChar(Ch[i],Lcd);
	}
	//Lcd_VoidGoXY(Lcd,Copy_XLocation,Copy_YLocation);
	Lcd_VoidSendCommand(LCD_SetAddressDDRAM,Lcd);
	Lcd_VoidSendChar(SpecAddCGran,Lcd);
}


void Lcd_VoidSendNumForTimers(u8 Copy_Num, Lcd_Info * Lcd)
{
	/*Numbers must be from 0:9*/
	/*RS->High*/
	DIO_ErrStateSetPinValue(Lcd->RS_Group , Lcd->RS_Pin , DIO_HIGH);
	/*RW-> LOW*/
	DIO_ErrStateSetPinValue(Lcd->RW_Group , Lcd-> RW_Pin , DIO_LOW) ;
	/*Group = COmmand */
	DIO_ErrStateSetGroubValue(Lcd->Data_Group , Copy_Num) ;
	/*Enable*/
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_HIGH) ;
	_delay_ms(1);
	DIO_ErrStateSetPinValue(Lcd->E_Group , Lcd-> E_Pin , DIO_LOW) ;
	_delay_ms(1);
	counter++ ;
}

