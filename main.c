/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "gpio.h"
#include "adc.h"

#define LOGIC_LOW	0
#define LOGIC_HIGH	1
int main(void)
{
	unsigned short int data=0;
	char flag;

	GPIO_Init(GPIOB,PIN0_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
	GPIO_Init(GPIOB,PIN1_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
	GPIO_Init(GPIOB,PIN2_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
	GPIO_Init(GPIOB,PIN3_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
	GPIO_Init(GPIOB,PIN4_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
	GPIO_Init(GPIOB,PIN5_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
	GPIO_Init(GPIOB,PIN6_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
	GPIO_Init(GPIOB,PIN7_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);


	GPIO_Init(GPIOA,PIN0_ID,ANALOG_MODE,NO_PULLUP_NO_PULLDOWN,RCC_GPIOA);
	ADCConfigType Config={bit12,single,5};
	ADC_Init(&Config);
	ADC_StartConv(PIN0_ID);

	while(1)
	{
		flag=ADC_ReadData(&data);
		if(flag==LOGIC_LOW)
		{
			GPIO_WritePort(GPIOB,data);
		}
	}

}
