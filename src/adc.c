/*
 * adc.c
 *
 *  Created on: May 19, 2022
 *      Author: Mn3n3
 */

#include "stm32f4xx.h"
#include "adc.h"
#include "gpio.h"

volatile unsigned short int adc_value=0;
volatile char Vref_voltage=0;


void ADC_Init(ADCConfigType* ConfigParamPtr){

	/* Enable ADC1 clock */
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

	/* Enable ADC */
	ADC1->CR2 |= ADC_CR2_ADON;

	/* ADC scaler PCLK2 divided by 2 */
	ADC->CCR &= ~ADC_CCR_ADCPRE;

	/* Select ADC1 Resolution */
	ADC1->CR1 =(ADC1->CR1&0xFCFFFFFF) |((ConfigParamPtr->resolution & 0x03)<<24);

	/* Select Right alignment */
	ADC1->CR2 &= ~ADC_CR2_ALIGN;

	/*Select ADC1 conversion mode*/
	ADC1->CR2=(ADC1->CR2 & 0xFFFFFFFD)|((ConfigParamPtr->conversionMode & 0x01)<<1);


	if(USE_POLLING==1)
	{
		ADC1->CR1 &=~(1<<5);// no interrupt
	}
	else
	{
		ADC1->CR1 |=(1<<5); 	 // with interrupt
		NVIC->ISER[0]|=(1u<<(18));	// Enable ADC interrupt from Vector Table
	}

	Vref_voltage=ConfigParamPtr->Vref;
}

void ADC_StartConv(unsigned char ChannelNum)
{
	/*
	 * Assign channel pin number to be the first sequence
	 */
	ADC1->SQR3=((ChannelNum &0x0F)<<0);

	/* Start conversion of regular channels */
	  ADC1->CR2 |= ADC_CR2_SWSTART;
}



#if(USE_POLLING==LOGIC_HIGH)
void ADC_GetConversionState(unsigned char* ConversionStatePtr)
{
	/*
	 * if Conversion is completed, assign 1 to ConversionState through its pointer
	 * else, assign 0 to it.
	 */
	if(ADC1->SR & ADC_SR_EOC)
	{
	*ConversionStatePtr= LOGIC_HIGH;
	}
	else
	{
	*ConversionStatePtr=LOGIC_LOW;
	}
}


unsigned char ADC_ReadData(volatile unsigned short int* DataPtr)
{

	unsigned char EOC_flag;

	/*
	 * Get conversion status .. then check whether it's completed or not
	 */
	ADC_GetConversionState(&EOC_flag);
	if(EOC_flag)
	{
		// if the conversion is finished
	    /* Read analog data and clear EOC flag */
		*DataPtr = ADC1->DR;
	    return 0;
	}
	else
	{
	    /* Regular conversion is not done */
		  return 1;
	}
}
#endif

