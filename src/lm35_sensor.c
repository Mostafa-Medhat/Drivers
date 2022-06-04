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
#include "delay.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
unsigned char LM35_getTemperature(void)
{
	unsigned char temp_value = 0;
	unsigned char valid_flag=0;

#if(USE_POLLING==LOGIC_HIGH)

	/* Read ADC channel where the temperature sensor is connected */
	valid_flag = ADC_ReadData(&adc_value);
#endif

#if(USE_POLLING==LOGIC_LOW)
	delay_ms(10);
#endif

	if(!valid_flag)
	{
		/* Calculate the temperature from the ADC value*/
		temp_value = (unsigned char)(((unsigned long)adc_value*SENSOR_MAX_TEMPERATURE*Vref_voltage)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
		return temp_value;
	}
	else
	{
		return 0;
	}
}
