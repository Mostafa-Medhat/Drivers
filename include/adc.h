/*
 * adc.h
 *
 *  Created on: May 19, 2022
 *      Author: Mn3n3
 */

#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_

#include "gpio.h"

#define USE_POLLING 1

#define ADC_MAXIMUM_VALUE	4095.0f

#define ADC_CHANNEL_PIN_ID	PIN0_ID

extern volatile unsigned short int adc_value;
extern volatile char Vref_voltage;



typedef enum {bit12,bit10,bit8,bit6}Resolution;
typedef enum  {SINGLE , CONTINUOUS}Conversion_mode;

typedef struct myStruct {

	 Resolution resolution;
	 Conversion_mode conversionMode;
	 int Vref;
} ADCConfigType;



void ADC_Init(ADCConfigType* );
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
void ADC_StartConv(unsigned char ChannelNum);
unsigned char ADC_ReadData(volatile unsigned short int* );


//void ADC_GetConversionState(unsigned char* );


#endif /* INCLUDE_ADC_H_ */
