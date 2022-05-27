/*
 * delay.c
 *
 *  Created on: May 27, 2022
 *      Author: mohab
 */

#include"delay.h"

void delayInit()
{
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000000);
}
void delay_us(uint32_t us_value)
{
	time_us = us_value;
	while(time_us);

}

void delay_ms(uint32_t ms_value)
{
	time_ms = ms_value;
	while(time_ms--)
		delay_us(1000);

}


SysTick_Handler()
{
	if(time_us)
	{
		time_us--;
	}
}
