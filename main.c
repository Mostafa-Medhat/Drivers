///**
//  ******************************************************************************
//  * @file    main.c
//  * @author  Ac6
//  * @version V1.0
//  * @date    01-December-2013
//  * @brief   Default main function.
//  ******************************************************************************
//*/
//
//
//#include "stm32f4xx.h"
//#include "gpio.h"
//#include "lcd.h"
//#include "LCD-4bit.h"
//#include "adc.h"
//#include "lm35_sensor.h"
//#include "delay.h"
//
//#define LOGIC_LOW	0
//#define LOGIC_HIGH	1
//int main(void)
//{
////	unsigned short int data=0;
////	char flag;
//	unsigned char temperature;
//
////	GPIO_Init(GPIOB,PIN0_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
////	GPIO_Init(GPIOB,PIN1_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
////	GPIO_Init(GPIOB,PIN2_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
////	GPIO_Init(GPIOB,PIN3_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
////	GPIO_Init(GPIOB,PIN4_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
////	GPIO_Init(GPIOB,PIN5_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
////	GPIO_Init(GPIOB,PIN6_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
////	GPIO_Init(GPIOB,PIN7_ID,PIN_OUTPUT,PUSH_PULL,RCC_GPIOB);
//
//
//	GPIO_Init(GPIOA,PIN0_ID,ANALOG_MODE,NO_PULLUP_NO_PULLDOWN,RCC_GPIOA);
//	ADCConfigType Config={bit12,single};
//	ADC_Init(&Config);
//	delayInit();
//	lcd_init();
//	lcd_dispString("Hello,Mada7oota");
////	delay_ms(2000);
//	lcd_clrScreen();
//	lcd_dispString("Temp =    C");	//Print "Temp =   C" on LCD
//	while(1)
//	{
//		lcd_gotoxy(0,7);
//		temperature=LM35_getTemperature();
//		lcd_intgerToString(temperature);
//		if(temperature<100)
//		{
//			lcd_displayChar(' ');
//			if(temperature<10)
//			{
//				lcd_displayChar(' ');
//			}
//		}
//	}
//}
