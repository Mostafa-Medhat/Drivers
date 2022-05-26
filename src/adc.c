/*
 * adc.c
 *
 *  Created on: May 19, 2022
 *      Author: Mn3n3
 */

#include "stm32f4xx.h"
#include "adc.h"
#include "gpio.h"


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

	if(USE_POLLING==1){
		ADC1->CR1 &=~(1<<5);// no interrupt
	}
	else {
		ADC1->CR1 |=(1<<5); 	 // with interrupt
	}


}

void ADC_StartConv(unsigned char ChannelNum){
	/*initializing the channel pin as analog pin,Assuming PORT A*/
	GPIO_Init(GPIOA,ChannelNum,ANALOG_MODE,NO_PULLUP_NO_PULLDOWN,RCC_GPIOA);

	/* Start conversion of regular channels */
	  ADC1->CR2 |= ADC_CR2_SWSTART;
}




#if (USE_POLLING==1)
void ADC_GetConversionState(unsigned char* ConversionStatePtr)
{

	*ConversionStatePtr=(ADC1->SR & ADC_SR_EOC);
}
#endif


unsigned char ADC_ReadData(unsigned short int* DataPtr){

	if((ADC1->SR & ADC_SR_EOC) == ADC_SR_EOC){// if the conversion is finished
	    /* Read analog data and clear EOC flag */
		*DataPtr = ADC1->DR;
	    /* Start conversion of regular channels */
	    ADC1->CR2 |= ADC_CR2_SWSTART;
	    return 0;
	  }
	  else {
	    /* Regular conversion is not done */
		  return 1;
	  }
}

