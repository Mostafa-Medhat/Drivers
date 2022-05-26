/*
 * adc.h
 *
 *  Created on: May 19, 2022
 *      Author: Mn3n3
 */

#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_

#define USE_POLLING 1




typedef enum {bit12,bit10,bit8,bit6}Resolution;
typedef enum  {single , continuous}Conversion_mode;

typedef struct myStruct {

	 Resolution resolution;
	 Conversion_mode conversionMode;
	 int Vref;
} ADCConfigType;



void ADC_Init(ADCConfigType* );
void ADC_StartConv(unsigned char );
unsigned char ADC_ReadData(unsigned short int* );


//void ADC_GetConversionState(unsigned char* );


#endif /* INCLUDE_ADC_H_ */
