/*
 * delay.h
 *
 *  Created on: May 27, 2022
 *      Author: mohab
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_
#include"stm32f4xx.h"

__IO time_us, time_ms;

void delayInit(void);
void delay_us(uint32_t);
void delay_ms(uint32_t);
#endif /* INC_DELAY_H_ */
