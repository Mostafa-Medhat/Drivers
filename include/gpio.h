/*
 * gpio.h
 *
 */

#include "stm32f4xx.h"

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

/*
 **************************************************************************
 * 							DEFINITIONS 								  *
 **************************************************************************
 */

#define RCC_GPIOA				0
#define RCC_GPIOB				1
#define RCC_GPIOC				2
#define RCC_GPIOD				3
#define RCC_GPIOE				4
#define RCC_GPIOH				7

#define PIN0_ID                 0
#define PIN1_ID                 1
#define PIN2_ID                 2
#define PIN3_ID                 3
#define PIN4_ID                 4
#define PIN5_ID                 5
#define PIN6_ID                 6
#define PIN7_ID                 7
#define PIN8_ID                 8
#define PIN9_ID                 9
#define PIN10_ID                10
#define PIN11_ID                11
#define PIN12_ID                12
#define PIN13_ID                13
#define PIN14_ID                14
#define PIN15_ID                15

#define PUSH_PULL				0
#define OPEN_DRAIN				1

#define NO_PULLUP_NO_PULLDOWN	0
#define PULL_UP					1
#define PULL_DOWN				2

#define LOGIC_LOW				0
#define LOGIC_HIGH				1


/*
 **************************************************************************
 * 							TYPES DECLARATION							  *
 **************************************************************************
 */

typedef enum
{
	PIN_INPUT=0, PIN_OUTPUT,ALTERNATE_FUNCTION_MODE, ANALOG_MODE
}GPIO_PinDirection;





/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void GPIO_Init(GPIO_TypeDef * GPIOx, char pin, GPIO_PinDirection dir,char mode ,char enable_pin);
char GPIO_WritePin(GPIO_TypeDef * GPIOx, char pin, char state);
void GPIO_WritePort(GPIO_TypeDef * GPIOx, char value);
char GPIO_ReadPin(GPIO_TypeDef * GPIOx, char pin);


#endif /* INCLUDE_GPIO_H_ */
