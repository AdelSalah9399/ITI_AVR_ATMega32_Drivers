/*
 * ADC_Program.c
 *
 *  Created on: Apr 3, 2023
 *      Author: Adel
 */
#include"../../common/STD_TYPE.h"
#include"../../common/BIT_MATH.h"
#include"ADC_Register.h"
#include"ADC_Config.h"

static u8* ADC_Reading=NULL;
static void (*pvNotificationFunc)(void)=NULL;
static u8 ADC_BusyState=IDLE;

void ADC_Initia()
{
	/*VOLTAGE REFERENCE INITIALIZATION*/
#if ADC_VoltRef==VR_Aref
	CLR_BIT(ADMUX,Vref0_pin);
	CLR_BIT(ADMUX,Vref1_pin);
#elif  ADC_VoltRef==VR_intVCC5v
	SET_BIT(ADMUX,Vref0_pin);
	CLR_BIT(ADMUX,Vref1_pin);
#elif  ADC_VoltRef==VR_int2_56v
	SET_BIT(ADMUX,Vref0_pin);
	SET_BIT(ADMUX,Vref1_pin);
#else
#warning "WRONG VOLTAGE REFERANCE INITIALIZATION"
#endif
	/*LEFT ADJUST *RESOLUTION* INITIALIZATION*/
#if ADC_Resolution==L_ADJ_8Bits_
	SET_BIT(ADMUX,LeftAD_pin);
#elif ADC_Resolution==L_ADJ_10Bits_
	CLR_BIT(ADMUX,LeftAD_pin);
#else
#warning "WRONG RESOLUTION INITIALIZATION"
#endif
	/*PRESCAL VALUE INITIALIZATION*/
	/*----------------------------BY USING BIT MASKING instead of set & clr-----------------------------*/
#if ADC_PreScal_Value==ADC_prescalDIV_2_
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_prescalDIV_2_;
#elif  ADC_PreScal_Value==ADC_prescalDIV_4_
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_prescalDIV_4_;
	CLR_BIT(ADMUX,Vref1_pin);
#elif  ADC_PreScal_Value==ADC_prescalDIV_8_
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_prescalDIV_8_;
#elif ADC_PreScal_Value==ADC_prescalDIV_16_
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_prescalDIV_16_;
#elif  ADC_PreScal_Value==ADC_prescalDIV_32_
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_prescalDIV_32_;
	CLR_BIT(ADMUX,Vref1_pin);
#elif  ADC_PreScal_Value==ADC_prescalDIV_64_
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_prescalDIV_64_;
#elif  ADC_PreScal_Value==ADC_prescalDIV_128_
	ADCSRA &= 0b11111000;
	ADCSRA |= ADC_prescalDIV_128_;
#else
#warning "WRONG PRESCAL CONFIGRATION"
#endif
}

void ADC_GlobalENABLE()
{	/*ENABLE/DISABLE THE ADC*/
#if ADC_EnableDisable == ADC_ENABLE
	SET_BIT(ADCSRA,ADC_EN);
#elif ADC_EnableDisable == ADC_DISABLE
	CLR_BIT(ADCSRA,ADC_EN);
#else
#error"WORNG ENABLE/DISABLE CONFIGRATION"
#endif
}

void ADC_PIE_INT_ENABLE()
{
#if ADC_INT_ENDIS == ADC_PIE_ENABLE
	SET_BIT(ADCSRA,ADC_INT_EN);
#elif ADC_INT_ENDIS == ADC_PIE_DISABLE
	CLR_BIT(ADCSRA,ADC_INT_EN);
#else
#error"WORNG PIE ENABLE/DISABLE CONFIGRATION"
#endif
}

void ADC_AutoTriggerInterruptEnable()
{
#if ADC_TrigEnDis == ADC_INT_AutoTrig_ENABLE
	SET_BIT(ADCSRA,ADC_EN);
#elif ADC_TrigEnDis == ADC_INT_AutoTrig_DISABLE
	CLR_BIT(ADCSRA,ADC_EN);
#else
#error"WORNG TRIGGER ENABLE/DISABLE CONFIGRATION"
#endif
}

ADC_ErrState ADC_StartConvenSynch(u8 Channel,u8* ADC_pu8Reading)
{
	if(ADC_BusyState==IDLE)
	{
		u32 Local_counter;
		/*clear MUX bits then use BIT MASKING*/
		ADMUX &= 0b11100000;
		ADMUX |= Channel;

		/*start conversion*/
		SET_BIT(ADCSRA,SC_StartConv);

		/* POLLING (busy waiting) until the conversion flag is set or counter time out*/
		while(((GET_BIT(ADCSRA,ADC_INTflag))==0)&&(Local_counter!=ADC_u32TIMEOUT))
		{
			Local_counter++;
		}
		if(Local_counter==ADC_u32TIMEOUT)	return TimeOutErr;
		else
		{
			/*Clear the flag because you work as polling not INT the flag will not be ZERO automatic you must force it*/
			SET_BIT(ADCSRA,ADC_INTflag);

			/*return the reading */
			*ADC_pu8Reading=ADCH;
		}
		return ADC_Conv_NoErr;
	}
	else
	{
		return ADC_Err;
	}
}

ADC_ErrState ADC_StartConvenAsynch(u8 Channel,u8* Copy_Reading, void (*Copy_pvNotificationFunc)(void))
{
	if(ADC_BusyState==IDLE)
	{
		/*I copied the local variables address to the global pointers SO i can use the pointers in the ISR easly*/
		/*intialize the reading value globally*/
		ADC_Reading=Copy_Reading;

		/*intialize the callback function globally*/
		pvNotificationFunc=Copy_pvNotificationFunc;

		if((pvNotificationFunc==NULL)||(ADC_Reading==NULL))
		{
			return ADC_PtrNullErr;
		}
		else
		{
			ADC_BusyState=BUSY;
			/*clear MUX bits then use BIT MASKING*/
			ADMUX &= 0b11100000;
			ADMUX |= Channel;

			/*start conversion*/
			SET_BIT(ADCSRA,SC_StartConv);

			/*enable ADC interrupt*/
			SET_BIT(ADCSRA,ADC_EN);
		}
		return ADC_NOERR;
	}
	else
	{
		return ADC_Err;
	}
}

u16 DAC_GetAnalogOfDigitalValue(u16 Digital_Input,u16 Resolution)
{
	u16 DAC_Analog;
	if( Resolution==8)
	{DAC_Analog = (u16)((u32)Digital_Input*ADC_VoltRef)/256UL;}
	else if( Resolution==10)
	{DAC_Analog = (u16)((u32)Digital_Input*ADC_VoltRef)/1024UL;}
	return DAC_Analog;
}


void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/*read ADC value and put in in the global variable*/
	*ADC_Reading=ADCH;

	ADC_BusyState=IDLE;

	/*call the ISR implementation from the APP layer*/
	pvNotificationFunc();
	/*disable the ADC PIE*/
	CLR_BIT(ADCSRA,ADC_EN);
	/*WE DONT NEED TO CLEAR THE FLAG INSIDE THE ISR IT CLEARED AUTOMATIC IN AVR*/

}


