/*
 * EXTI_pre_Program.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Adel
 */

#include"../../common/BIT_MATH.h"
#include"../../common/STD_TYPE.h"
#include"EXTI_pre_Private.h"
#include"EXTI_pre_Registers.h"
#include"EXTI_pre_Config.h"
#include"../DIO/DIO_Interface.h"
/*global ptr to function*/
void(*EXTIpre_INTx_ptfv[3])(void)={NULL};


void EXTI_INT0_InitiaTriggerPIEoptions(void)
{
	/*Trigger modes*/
#if(INT0_Sense==Low_Level)
	CLR_BIT(MCUCR,INT0_Trig_Bit0);
	CLR_BIT(MCUCR,INT0_Trig_Bit1);
#elif(INT0_Sense==ON_change)
	SET_BIT(MCUCR,INT0_Trig_Bit0);
	CLR_BIT(MCUCR,INT0_Trig_Bit1);
#elif(INT0_Sense==Falling_Edge)
	CLR_BIT(MCUCR,INT0_Trig_Bit0);
	SET_BIT(MCUCR,INT0_Trig_Bit1);
#elif(INT0_Sense==Rissing_Edge)
	SET_BIT(MCUCR,INT0_Trig_Bit0);
	SET_BIT(MCUCR,INT0_Trig_Bit1);
#else
#error "WRONG SENSE OR TRIGGER CONFIG OPTION"
#endif

	/*PIE ENABLE-or-DISABLE for INT0*/
#if(INT0_PIE_STATE==Enable)
	SET_BIT(GICR,INT0_PIE_Bit);
#elif(INT0_PIE_STATE==Disable)
	CLR_BIT(GICR,INT0_PIE_Bit);
#else
#error "WRONG INT0 CONFIG OPTION"
#endif
}


void EXTI_INT1_InitiaTriggerPIEoptions(void)
{
	/*Trigger modes*/
#if(INT1_Sense==Low_Level)
	CLR_BIT(MCUCR,INT1_Trig_Bit0);
	CLR_BIT(MCUCR,INT1_Trig_Bit1);
#elif(INT1_Sense==ON_change)
	SET_BIT(MCUCR,INT1_Trig_Bit0);
	CLR_BIT(MCUCR,INT1_Trig_Bit1);
#elif(INT1_Sense==Falling_Edge)
	CLR_BIT(MCUCR,INT1_Trig_Bit0);
	SET_BIT(MCUCR,INT1_Trig_Bit1);
#elif(INT1_Sense==Rissing_Edge)
	SET_BIT(MCUCR,INT1_Trig_Bit0);
	SET_BIT(MCUCR,INT1_Trig_Bit1);
#else
#error "WRONG SENSE OR TRIGGER CONFIG OPTION"
#endif

	/*PIE ENABLE-or-DISABLE for INT1*/
#if(INT1_PIE_STATE==Enable)
	SET_BIT(GICR,INT1_PIE_Bit);
#elif(INT1_PIE_STATE==Disable)
	CLR_BIT(GICR,INT1_PIE_Bit);
#else
#error "WRONG INT0 CONFIG OPTION"
#endif
}


void EXTI_INT2_InitiaTriggerPIEoptions(void)
{
	/*Trigger modes*/
#if(INT2_Sense==Falling_Edge)
	CLR_BIT(MCUCSR,INT2_Trig_Bit);
#elif(INT2_Sense==Rissing_Edge)
	SET_BIT(MCUCSR,INT2_Trig_Bit);
#else
#error "WRONG SENSE OR TRIGGER CONFIG OPTION"
#endif

	/*PIE ENABLE-or-DISABLE for INT0*/
#if(INT2_PIE_STATE==Enable)
	SET_BIT(GICR,INT2_PIE_Bit);
#elif(INT2_PIE_STATE==Disable)
	CLR_BIT(GICR,INT2_PIE_Bit);
#else
#error "WRONG INT0 CONFIG OPTION"
#endif
}



void EXTIpre_INT0_Set_CallBack(void(*INTx)(void))
{
	if(EXTIpre_INTx_ptfv[0]!=NULL)
	{
		EXTIpre_INTx_ptfv[0]=INTx;
	}

}

void EXTIpre_INT1_Set_CallBack(void(*INTx)(void))
{
	if(EXTIpre_INTx_ptfv[1]!=NULL)
	{
		EXTIpre_INTx_ptfv[1]=INTx;
	}
}

void EXTIpre_INT2_Set_CallBack(void(*INTx)(void))
{
	if(EXTIpre_INTx_ptfv[2]!=NULL)
	{
		EXTIpre_INTx_ptfv[2]=INTx;
	}
}

/*ISR OF INT0*/
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	if(EXTIpre_INTx_ptfv[0]!=NULL){
	EXTIpre_INTx_ptfv[0]();
	}
	else
	{
		/*DO nothing*/
	}
}
/*ISR OF INT1*/
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	if(EXTIpre_INTx_ptfv[1]!=NULL){
	EXTIpre_INTx_ptfv[1]();
	}
	else
	{
		/*DO nothing*/
	}
}
/*ISR OF INT2*/
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(EXTIpre_INTx_ptfv[2]!=NULL){
	EXTIpre_INTx_ptfv[2]();
	}
	else
	{
		/*DO nothing*/
	}
}

void EXTIpre_Enable_GIE ()
{
	SET_BIT(SREG,PIN7);
}
void EXTIpre_Disable_GIE()
{
	CLR_BIT(SREG,PIN7);
}
