#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init(GPIO_TypeDef * GPIOx, char pin, GPIO_PinDirection dir,char mode ,char enable_pin)
{
	//Enable clock to GBIOx
	RCC->AHB1ENR |= (1u<<enable_pin);

	if(dir==PIN_OUTPUT)
	{
		GPIOx->MODER |= (1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));

		if(mode==PUSH_PULL)
		{
			GPIOx->OTYPER&=~(1u<<(pin));
		}
		else if(mode==OPEN_DRAIN)
		{
			GPIOx->OTYPER|=(1u<<(pin));
		}
	}
	else if (dir==PIN_INPUT)
	{
		GPIOx->MODER &=~(1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));

		if(mode==NO_PULLUP_NO_PULLDOWN)
		{
			GPIOx->PUPDR &=~(1u<<(2*pin));
			GPIOx->PUPDR &=~(1u<<(2*pin+1));
		}
		else if (mode==PULL_UP)
		{
			GPIOx->PUPDR |=(1u<<(2*pin));
			GPIOx->PUPDR &=~(1u<<(2*pin+1));
		}
		else if (mode==PULL_DOWN)
		{
			GPIOx->PUPDR &=~(1u<<(2*pin));
			GPIOx->PUPDR |=(1u<<(2*pin+1));
		}
	}
	else if(dir == ALTERNATE_FUNCTION_MODE)
	{
		GPIOx->MODER &=~(1u<<(2*pin));
		GPIOx->MODER |=(1u<<(2*pin+1));
	}
	else if (dir == ANALOG_MODE)
	{
		GPIOx->MODER |=(1u<<(2*pin));
		GPIOx->MODER |=(1u<<(2*pin+1));

		if(mode==NO_PULLUP_NO_PULLDOWN)
		{
			GPIOx->PUPDR &=~(1u<<(2*pin));
			GPIOx->PUPDR &=~(1u<<(2*pin+1));
		}
		else if (mode==PULL_UP)
		{
			GPIOx->PUPDR |=(1u<<(2*pin));
			GPIOx->PUPDR &=~(1u<<(2*pin+1));
		}
		else if (mode==PULL_DOWN)
		{
			GPIOx->PUPDR &=~(1u<<(2*pin));
			GPIOx->PUPDR |=(1u<<(2*pin+1));
		}

	}

}

char GPIO_WritePin(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if (GPIOx->MODER & (1u<<(2*pin)))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 0;
	}
	else
	{
		return 1;
	}
}

void GPIO_WritePort(GPIO_TypeDef * GPIOx, char value)
{

		GPIOx->ODR=value;
}

char GPIO_ReadPin(GPIO_TypeDef * GPIOx, char pin)
 {
	if (!(GPIOx->MODER & (1u<<(2*pin))))
	{
		if (GPIOx->IDR & (1u << pin))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
