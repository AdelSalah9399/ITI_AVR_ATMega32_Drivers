/*
 * Timer_Program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: Adel
 */
#include"../../DIO/DIO_Interface.h"
#include "Timer0_Config.h"
#include "Timer0_Private.h"
#include "Timer0_Register.h"


void Timer0ModeSetting()
{
#if TIMER0_OnOff == ON
	#if TIMER0_MODE==Normal_Mode
		CLR_BIT(TCCR0,PIN3);
		CLR_BIT(TCCR0,PIN6);
	#elif TIMER0_MODE==CTC_Mode
		CLR_BIT(TCCR0,PIN3);
		SET_BIT(TCCR0,PIN6);
	#elif TIMER0_MODE==PWM_Mode
		CLR_BIT(TCCR0,PIN6);
		SET_BIT(TCCR0,PIN3);
	#elif TIMER0_MODE==PWM_Mode
		SET_BIT(TCCR0,PIN6);
		SET_BIT(TCCR0,PIN3);
	#else
		#error "WRONG MODE CONFIGRATION"
	#endif
#else
#error"Timer is OFF"

#endif
}
void T0NormalModePreScalling()
{
#if TIMER0_OnOff == ON
	#if T0_NM_Presaclling_Value==NO_PreScalling
		SET_BIT(TCCR0,PIN0);
		CLR_BIT(TCCR0,PIN1);
		CLR_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_8_PreScalling
		CLR_BIT(TCCR0,PIN0);
		SET_BIT(TCCR0,PIN1);
		CLR_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_32_PreScalling
		SET_BIT(TCCR0,PIN0);
		SET_BIT(TCCR0,PIN1);
		CLR_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_64_PreScalling
		CLR_BIT(TCCR0,PIN0);
		CLR_BIT(TCCR0,PIN1);
		SET_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_128_PreScalling
		SET_BIT(TCCR0,PIN0);
		CLR_BIT(TCCR0,PIN1);
		SET_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_256_PreScalling
		CLR_BIT(TCCR0,PIN0);
		SET_BIT(TCCR0,PIN1);
		SET_BIT(TCCR0,PIN2);
	#elif T0_NM_Presaclling_Value==_1024_PreScalling
		SET_BIT(TCCR0,PIN0);
		SET_BIT(TCCR0,PIN1);
		SET_BIT(TCCR0,PIN2);
	#else
		#error "WRONG MODE CONFIGRATION"
	#endif
#else
#error"Timer is OFF"

#endif
}
void CTC_OC0Pin_Func()
{
#if CTC_OC0_mode == Normal_port
	CLR_BIT(TCCR0,PIN4);
	CLR_BIT(TCCR0,PIN5);
#elif CTC_OC0_mode == Toggle_OC2
	SET_BIT(TCCR0,PIN4);
	CLR_BIT(TCCR0,PIN5);
#elif CTC_OC0_mode == Clear_OC2
	CLR_BIT(TCCR0,PIN4);
	SET_BIT(TCCR0,PIN5);
#elif CTC_OC0_mode == Set_OC2
	SET_BIT(TCCR0,PIN4);
	SET_BIT(TCCR0,PIN5);
#else
	#error"WRONG OC2 CONFIGRATION"
#endif
}
void Timer0NM_PIE_INTEnable()
{
#if T0_NormalMode_OverFlow_INT_PIE==ENABLE
	SET_BIT(TIMSK,PIN0);
#elif T0_NormalMode_OverFlow_INT_PIE==DISABLE
	CLR_BIT(TIMSK,PIN0);
#else
	#error "WRONG CONFIGRATION"
#endif
}
void Timer0CTC_PIE_INTEnable()
{
#if T0_CTC_INT==ENABLE
	SET_BIT(TIMSK,PIN1);
#elif T0_CTC_INT==DISABLE
	CLR_BIT(TIMSK,PIN1);
#else
	#error "WRONG CONFIGRATION"
#endif
}

void Timer0_PreloadValue()
{
	TCNT0=T0_PreloadValue ;
}
