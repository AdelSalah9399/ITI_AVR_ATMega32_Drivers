/*
 * ADC_Interface.h
 *
 *  Created on: Apr 3, 2023
 *      Author: Adel
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

void ADC_Initia();
void ADC_GlobalENABLE();
void ADC_PIE_INT_ENABLE();
void ADC_AutoTriggerInterruptEnable();


ADC_ErrState ADC_StartConvenSynch(u8 Channel,u8* ADC_Reading);
ADC_ErrState ADC_StartConvenAsynch(u8 Channel,u8* Copy_Reading, void (*Copy_pvNotificationFunc)(void));

u16 DAC_GetAnalogOfDigitalValue(u16 Digital_Input,u16 Resolution);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
