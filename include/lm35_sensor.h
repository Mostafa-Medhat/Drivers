 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Mostafa Medhat
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

#define UNCOMPLETED_CONVERSION		200

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
unsigned char LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
