/*
 * EXTI_Program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: Adel
 */


#include"../../MCAL/DIO/DIO_Interface.h"
#include "../EXTI_post/EXTI_Private.h"
#include "../EXTI_post/EXTI_Register.h"


/*Global ptr to function to hold the function address*/
void(*EXTI_INTx_ptfv[3])(void)={NULL};

EXTI_Errs EXTI_ClearFlag(INT_Num INT)
{
	if(INT>=0 && INT<=2)
	{
		switch(INT)
		{	/*clear the flag by giving it value 1*/
		case INT0 : SET_BIT(GIFR,INT0_Flag_Bit);   break;
		case INT1 : SET_BIT(GIFR,INT1_Flag_Bit);   break;
		case INT2 : SET_BIT(GIFR,INT2_Flag_Bit);   break;
		}
		return EXTI_NoErr;
	}
	else
	{
		return ErrINTnum;
	}
}
EXTI_Errs EXTI_INTx_InitiaTriggerOptions(INT_Num INT,TRIG_INFO Trig_Type,PIE_EN PIE)
{	if(INT==INT0)
	{
		switch(Trig_Type)
		{
		 case Low_Level   : CLR_BIT(MCUCR,INT0_Trig_Bit1); CLR_BIT(MCUCR,INT0_Trig_Bit0); break;
		 case ON_change   : CLR_BIT(MCUCR,INT0_Trig_Bit1); SET_BIT(MCUCR,INT0_Trig_Bit0); break;
		 case Falling_Edge: SET_BIT(MCUCR,INT0_Trig_Bit1); CLR_BIT(MCUCR,INT0_Trig_Bit0); break;
		 case Rising_Edge : SET_BIT(MCUCR,INT0_Trig_Bit1); SET_BIT(MCUCR,INT0_Trig_Bit0); break;
		 default : return TrigErr;
		}
	}
	else if(INT==INT1)
	{
		switch(Trig_Type)
		{
		 case Low_Level   : CLR_BIT(MCUCR,INT1_Trig_Bit1); CLR_BIT(MCUCR,INT1_Trig_Bit0);  break;
		 case ON_change   : CLR_BIT(MCUCR,INT1_Trig_Bit1); SET_BIT(MCUCR,INT1_Trig_Bit0);  break;
		 case Falling_Edge: SET_BIT(MCUCR,INT1_Trig_Bit1); CLR_BIT(MCUCR,INT1_Trig_Bit0);  break;
		 case Rising_Edge : SET_BIT(MCUCR,INT1_Trig_Bit1); SET_BIT(MCUCR,INT1_Trig_Bit0);  break;
		 default : return TrigErr;
		}
		if(PIE==Enable)
		{
			SET_BIT(GICR,INT0_PIE_Bit);
		}
		else return ErrPIE ;
	}
	else if(INT==INT2)
	{
		switch(Trig_Type)
		{
		case Falling_Edge: CLR_BIT(MCUCSR,INT2_Trig_Bit);  break;
		case Rising_Edge : SET_BIT(MCUCSR,INT2_Trig_Bit);  break;
		default : return TrigErr;
		}
		if(PIE==Enable)
		{
			SET_BIT(GICR,INT0_PIE_Bit);
		}
		else return ErrPIE ;
	}
	else
	{
		return INVALID_INT;
	}
	return EXTI_NoErr;
}
EXTI_Errs EXTI_INTx_PIESetRest(INT_Num INT,PIE_EN PIE)
{
	if(PIE==Enable)
	{
		switch(INT)
		{
		case INT0 :SET_BIT(GICR,INT0_PIE_Bit); break;
		case INT1 :SET_BIT(GICR,INT1_PIE_Bit); break;
		case INT2 :SET_BIT(GICR,INT2_PIE_Bit); break;
		}
	}
	else if(PIE==Disable)
	{
		switch(INT)
		{
		case INT0 :CLR_BIT(GICR,INT0_PIE_Bit); break;
		case INT1 :CLR_BIT(GICR,INT1_PIE_Bit); break;
		case INT2 :CLR_BIT(GICR,INT2_PIE_Bit); break;
		}
	}
	else return ErrPIE ;
	return EXTI_NoErr;
}


EXTI_Errs EXTI_INT0_Set_CallBack(void(*INTx)(void))
{
	if(EXTI_INTx_ptfv[0]!=NULL)
	{
		EXTI_INTx_ptfv[0]=INTx;
	}
	else return nullptr ;
	return EXTI_NoErr;
}

EXTI_Errs EXTI_INT1_Set_CallBack(void(*INTx)(void))
{
	if(EXTI_INTx_ptfv[1]!=NULL)
	{
		EXTI_INTx_ptfv[1]=INTx;
	}
	else return nullptr ;
	return EXTI_NoErr;
}

EXTI_Errs EXTI_INT2_Set_CallBack(void(*INTx)(void))
{
	if(EXTI_INTx_ptfv[2]!=NULL)
	{
		EXTI_INTx_ptfv[2]=INTx;
	}
	else return nullptr ;
	return EXTI_NoErr;
}


void EXTI_Enable_GIE()
{
	SET_BIT(SREG,PIN7);
}
void EXTI_Disable_GIE()
{
	CLR_BIT(SREG,PIN7);
}


/*ISR OF INT0*/
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_INTx_ptfv[0]!=NULL){
	EXTI_INTx_ptfv[0]();
	}
	else
	{
		/*DO nothing*/
	}
}
/*ISR OF INT1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_INTx_ptfv[1]!=NULL){
	EXTI_INTx_ptfv[1]();
	}
	else
	{
		/*DO nothing*/
	}
}
/*ISR OF INT2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_INTx_ptfv[2]!=NULL){
	EXTI_INTx_ptfv[2]();
	}
	else
	{
		/*DO nothing*/
	}
}
