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
//void ISR_ADC1(void);
//
//
//int main(void)
//{
//
//	unsigned char temperature;
//
//
//
//	GPIO_Init(GPIOA,ADC_CHANNEL_PIN_ID,ANALOG_MODE,NO_PULLUP_NO_PULLDOWN,RCC_GPIOA);
//	ADCConfigType Config={bit12,continuous};
//	ADC_Init(&Config);
//
//	GPIO_Init(GPIOA,PIN1_ID,PIN_INPUT,PULL_UP,RCC_GPIOA);
//
//	delayInit();
//
//	lcd_init();
//	lcd_dispString("Hello,Mada7oota");
//	lcd_clrScreen();
//	lcd_dispString("Temp =    ");
//	lcd_displayChar(0xDF);
//	lcd_dispString("C");	//Print "Temp =   C" on LCD
//
//	/*
//	 * Get Initial Temperature
//	 */
//	ADC_StartConv(ADC_CHANNEL_PIN_ID);
////	delay_ms(15);
//	temperature=LM35_getTemperature();
//
//	while(1)
//	{
//		if(GPIO_ReadPin(GPIOA,PIN1_ID)==LOGIC_LOW)
//		{
//			delay_ms(5);
//			if(GPIO_ReadPin(GPIOA,PIN1_ID)==LOGIC_LOW)
//			{
//					ADC_StartConv(ADC_CHANNEL_PIN_ID);
//					temperature=LM35_getTemperature();
//			}
//		}
//		lcd_gotoxy(0,7);
//		if(Config.conversionMode==continuous)
//		{
//			temperature=LM35_getTemperature();
//		}
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
//
//void ADC_IRQHandler(void)
//{
//	ISR_ADC1();
//}
//void ISR_ADC1(void)
//{
//	adc_value=ADC1->DR;
//}
//
//
///////////////////////////////// 8 - Bit LCD Code //////////////////////////////
//
////
/////**
////  ******************************************************************************
////  * @file    main.c
////  * @author  Ac6
////  * @version V1.0
////  * @date    01-December-2013
////  * @brief   Default main function.
////  ******************************************************************************
////*/
////
////
////#include "stm32f4xx.h"
////#include "gpio.h"
////#include "lcd.h"
////#include "LCD-4bit.h"
////#include "LCD.h"
////#include "adc.h"
////#include "lm35_sensor.h"
////#include "delay.h"
////
////void ISR_ADC1(void);
////
////
////int main(void)
////{
////
////	unsigned char temperature;
////
////
////
////	GPIO_Init(GPIOA,ADC_CHANNEL_PIN_ID,ANALOG_MODE,NO_PULLUP_NO_PULLDOWN,RCC_GPIOA);
////	ADCConfigType Config={bit12,continuous};
////	ADC_Init(&Config);
////
////	GPIO_Init(GPIOA,PIN1_ID,PIN_INPUT,PULL_UP,RCC_GPIOA);
////
////	delayInit();
////
////	LCD_Init();
////	LCD_DisplayString("Hello,Mada7oota");
////	LCD_ClearScreen();
////	LCD_DisplayString("Temp =    ");
////	LCD_DisplayCharacter(0xDF);
////	LCD_DisplayString("C");	//Print "Temp =   C" on LCD
////
////	/*
////	 * Get Initial Temperature
////	 */
////	ADC_StartConv(ADC_CHANNEL_PIN_ID);
//////	delay_ms(15);
////	temperature=LM35_getTemperature();
////
////	while(1)
////	{
////		if(GPIO_ReadPin(GPIOA,PIN1_ID)==LOGIC_LOW)
////		{
////			delay_ms(5);
////			if(GPIO_ReadPin(GPIOA,PIN1_ID)==LOGIC_LOW)
////			{
////					ADC_StartConv(ADC_CHANNEL_PIN_ID);
////					temperature=LM35_getTemperature();
////			}
////		}
////		LCD_MoveCursor(0,7);
////		if(Config.conversionMode==continuous)
////		{
////			temperature=LM35_getTemperature();
////		}
////		LCD_IntToStr(temperature);
////		if(temperature<100)
////		{
////			LCD_DisplayCharacter(' ');
////			if(temperature<10)
////			{
////				LCD_DisplayCharacter(' ');
////			}
////		}
////	}
////}
////
////void ADC_IRQHandler(void)
////{
////	ISR_ADC1();
////}
////void ISR_ADC1(void)
////{
////	adc_value=ADC1->DR;
////}
////
////
////
////
