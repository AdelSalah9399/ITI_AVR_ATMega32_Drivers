/*
 * ADC_Config.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Adel
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
#include"ADC_Private.h"

#define ADC_VoltRef			    VR_intVCC5v
#define ADC_Resolution	   		L_ADJ_8Bits_
#define ADC_PreScal_Value   	ADC_prescalDIV_128_
#define ADC_RunMode	   			FreeRun_Mode

#define ADC_EnableDisable   	ADC_ENABLE
#define ADC_INT_ENDIS  			ADC_PIE_ENABLE
#define ADC_TrigEnDis  			ADC_INT_AutoTrig_ENABLE

#define ADC_u32TIMEOUT			50000

//#define ADC_ChannelandGain  	ADC2
//#define ADC_INT_TrigSorce   	xx

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
