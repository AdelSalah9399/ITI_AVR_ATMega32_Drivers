/*
 * ADC_Private.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Adel
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/*voltage referance options*/
#define VR_Aref		1
#define VR_intVCC5v	2
#define VR_int2_56v 3
/*Data Register Adjustment*/
#define L_ADJ_8Bits_	1
#define R_ADJ_10Bits_	2
/*ANALOG CHANNELS & GAIN*/
					/*1-Single Ended mode*/
//define by its decimal value because i will use it with BIT MASKING
//#define Single_Mode	40
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
 					/*2-Differential mode*/
//where ADC(+diff pin)(-diff pin)_Gain value
#define FreeRun_Mode	50
#define ADC00_G10	8
#define ADC10_G10	9
#define ADC00_G200  10
#define ADC10_G200	11
#define ADC22_G10	12
#define ADC32_G10	13
#define ADC22_G200	14
#define ADC32_G200	15
#define ADC01_NG	16
#define ADC11_NG	17
#define ADC21_NG	18
#define ADC31_NG	19
#define ADC41_NG	20
#define ADC51_NG	21
#define ADC61_NG	22
#define ADC71_NG	23
#define ADC02_NG	24
#define ADC12_NG	25
#define ADC22_NG	26
#define ADC32_NG	27
#define ADC42_NG	28
#define ADC52_NG	29

/*ADC STATUS*/
#define ADC_ENABLE		1
#define ADC_DISABLE		2
#define ADC_PIE_ENABLE	3
#define ADC_PIE_DISABLE	4


/*ADC INT source & trigger enable*/
#define ADC_INT_AutoTrig_ENABLE		1
#define ADC_INT_AutoTrig_DISABLE	2
#define ADC_FreeRunMode		0
#define ADC_AnalogComapre	1
#define ADC_INT0			2
#define ADC_T0ComMatch		3
#define ADC_T0OverFlow		4
#define ADC_T1ComMatch		5
#define ADC_T1OverFlow		6
#define ADC_CapturEvent		7

/*Prescaling values*/
#define ADC_prescalDIV_2_	1
#define ADC_prescalDIV_4_	2
#define ADC_prescalDIV_8_	3
#define ADC_prescalDIV_16_	4
#define ADC_prescalDIV_32_	5
#define ADC_prescalDIV_64_	6
#define ADC_prescalDIV_128_	7


typedef enum
{
	ADC_NOERR,
	ADC_Conv_NoErr,
	TimeOutErr,
	ADC_PtrNullErr,
	ADC_Err
}ADC_ErrState;

#define IDLE 1
#define BUSY 2
#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
