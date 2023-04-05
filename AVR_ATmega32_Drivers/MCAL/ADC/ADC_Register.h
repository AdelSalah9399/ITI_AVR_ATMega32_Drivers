/*
 * ADC_Register.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Adel
 */

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_

#define ADMUX	(*(volatile u8*)(0x27))
#define Vref0_pin     		6
#define Vref1_pin     		7
#define LeftAD_pin	  		5


#define ADCSRA	(*(volatile u8*)(0x26))
#define ADC_EN				7
#define SC_StartConv		6
#define AutoTrig_EN			5
#define ADC_INTflag			4
#define ADC_INT_EN			3



#define ADCH	(*(volatile u8*)(0x25))
#define ADCL	(*(volatile u8*)(0x24))

#define SFIOR	(*(volatile u8*)(0x50))


#endif /* MCAL_ADC_ADC_REGISTER_H_ */
