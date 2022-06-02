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


//	ADC1->SQR1 &=~ (15<<20);
//
//	ADC1->SQR3 &=~ (31<<0);
//
//	ADC1->SMPR2 |= 7 << 0;


	if(USE_POLLING==1)
	{
		ADC1->CR1 &=~(1<<5);// no interrupt
	}
	else
	{
		ADC1->CR1 |=(1<<5); 	 // with interrupt
		NVIC->ISER[0]|=(1u<<(18));
	}

}

void ADC_StartConv(unsigned char ChannelNum)
{
//	  ADC1->SQR3 |=(uint32_t)ChannelNum << (5 * (1 - 1));

	/* Start conversion of regular channels */
	  ADC1->CR2 |= ADC_CR2_SWSTART;
}



#if(USE_POLLING==LOGIC_HIGH)
void ADC_GetConversionState(unsigned char* ConversionStatePtr)
{
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

