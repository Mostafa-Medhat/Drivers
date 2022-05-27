 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Mostafa Medhat
 *
 *******************************************************************************/

#include "lm35_sensor.h"

#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
unsigned char LM35_getTemperature(void)
{
	unsigned char temp_value = 0;
	unsigned short int adc_value = 0;
	unsigned char EOC_flag=0;

	ADC_StartConv(ADC_CHANNEL_PIN_ID);

	/* Read ADC channel where the temperature sensor is connected */
	EOC_flag = ADC_ReadData(&adc_value);

	if(!EOC_flag)
	{
		/* Calculate the temperature from the ADC value*/
		temp_value = (unsigned char)(((uint32_t)adc_value*SENSOR_MAX_TEMPERATURE*ADC_MAX_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
		return temp_value;
	}
	else
	{
		return UNCOMPLETED_CONVERSION; // return of non completed conversion condition
	}
}

