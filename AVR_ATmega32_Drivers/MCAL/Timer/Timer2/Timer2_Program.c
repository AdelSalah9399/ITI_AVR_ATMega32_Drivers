/*
 * Timer_Program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */
#include"../../DIO/DIO_Interface.h"
#include "Timer2_Register.h"
#include"Timer2_Private.h"
#include"Timer2_Config.h"

void (*ptr2func)(void)=NULL;



void Timer2ModeSetting()
{
#if TIMER2_OnOff == ON
	#if TIMER2_MODE==Normal_Mode
		CLR_BIT(TCCR2,PIN3);
		CLR_BIT(TCCR2,PIN6);
	#elif TIMER2_MODE==CTC_Mode
		CLR_BIT(TCCR2,PIN3);
		SET_BIT(TCCR2,PIN6);
	#elif TIMER2_MODE==PWM_Mode
		CLR_BIT(TCCR2,PIN6);
		SET_BIT(TCCR2,PIN3);
	#elif TIMER2_MODE==Fast_PWM_Mode
		SET_BIT(TCCR2,PIN6);
		SET_BIT(TCCR2,PIN3);
	#else
		#error "WRONG MODE CONFIGRATION"
	#endif
#else
#error"Timer is OFF"

#endif
}
void T2NormalModePreScalling()
{
#if TIMER2_OnOff == ON
	#if T2_NM_Presaclling_Value==NO_PreScalling
		SET_BIT(TCCR2,PIN0);
		CLR_BIT(TCCR2,PIN1);
		CLR_BIT(TCCR2,PIN2);
	#elif T2_NM_Presaclling_Value==_8_PreScalling
		CLR_BIT(TCCR2,PIN0);
		SET_BIT(TCCR2,PIN1);
		CLR_BIT(TCCR2,PIN2);
	#elif T2_NM_Presaclling_Value==_32_PreScalling
		SET_BIT(TCCR2,PIN0);
		SET_BIT(TCCR2,PIN1);
		CLR_BIT(TCCR2,PIN2);
	#elif T2_NM_Presaclling_Value==_64_PreScalling
		CLR_BIT(TCCR2,PIN0);
		CLR_BIT(TCCR2,PIN1);
		SET_BIT(TCCR2,PIN2);
	#elif T2_NM_Presaclling_Value==_128_PreScalling
		SET_BIT(TCCR2,PIN0);
		CLR_BIT(TCCR2,PIN1);
		SET_BIT(TCCR2,PIN2);
	#elif T2_NM_Presaclling_Value==_256_PreScalling
		CLR_BIT(TCCR2,PIN0);
		SET_BIT(TCCR2,PIN1);
		SET_BIT(TCCR2,PIN2);
	#elif T2_NM_Presaclling_Value==_1024_PreScalling
		SET_BIT(TCCR2,PIN0);
		SET_BIT(TCCR2,PIN1);
		SET_BIT(TCCR2,PIN2);
	#else
		#error "WRONG MODE CONFIGRATION"
	#endif
#else
#error"Timer is OFF"

#endif
}
void CTC_OC2Pin_Func()
{
#if CTC_OC2_mode == Normal_port
	CLR_BIT(TCCR2,PIN4);
	CLR_BIT(TCCR2,PIN5);
#elif CTC_OC2_mode == Toggle_OC2
	SET_BIT(TCCR2,PIN4);
	CLR_BIT(TCCR2,PIN5);
#elif CTC_OC2_mode == Clear_OC2
	CLR_BIT(TCCR2,PIN4);
	SET_BIT(TCCR2,PIN5);
#elif CTC_OC2_mode == Set_OC2
	SET_BIT(TCCR2,PIN4);
	SET_BIT(TCCR2,PIN5);
#else
	#error"WRONG OC2 CONFIGRATION"
#endif
}
void Timer2NM_PIE_INTEnable()
{
#if T2_NormalMode_OverFlow_INT_PIE==ENABLE
	SET_BIT(TIMSK,PIN6);
#elif T2_NormalMode_OverFlow_INT_PIE==DISABLE
	CLR_BIT(TIMSK,PIN6);
#else
	#error "WRONG CONFIGRATION"
#endif
}
void Timer2CTC_PIE_INTEnable()
{
#if T2_CTC_INT==ENABLE
	SET_BIT(TIMSK,PIN7);
#elif CTC_INT==DISABLE
	T2_CTC_INT(TIMSK,PIN7);
#else
	#error "WRONG CONFIGRATION"
#endif
}
void Timer2_PreloadValue()
{
	TCNT2=T2_PreloadValue ;
}
void OCR2_TimeOverFlow()
{
	OCR2=OC2_timeOverFlow ;
}



/************************************************CALLBACK MECHANISM*****************************************************/

void SetCallBack(void (*APPfunc)(void))
{
	if(APPfunc!=NULL)
	{
		ptr2func=APPfunc;
	}
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
	if(ptr2func!=NULL)
	{
		ptr2func();
	}
}







