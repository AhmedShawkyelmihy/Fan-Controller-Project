/*
 ============================================================================
 Name        : lm35_sensor.h
 Author      : Ahmed Shawky
 Description : Header File for LM35 Temperature Sensor Driver
 Date        : 30/08/2023
 ============================================================================
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

/****************************************************************************
 * 								  Includes								    *
 ****************************************************************************/
#include "std_types.h"
#include "adc.h"

/****************************************************************************
 * 								 Definitions								*
 ****************************************************************************/

#define SENSOR_MAX_TEMP_VALUE 		150
#define	SENSOR_MAX_VOLT_VALUE 		1.5

#define ADC0 			    		0
#define ADC1 			     		1
#define ADC2 			     		2
#define ADC3 			     		3
#define ADC4 			     		4
#define ADC5 			     		5
#define ADC6 			     		6
#define ADC7 			     		7

#define SENSOR_CHANNEL_ID			(ADC2)

/****************************************************************************
 * 							Functions Prototypes						    *
 ****************************************************************************/

/* Inputs: void.
 *
 * Return Value: Temperature value from the LM35 sensor.
 *
 * Description:
 *	Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemperature(void);



#endif /* LM35_SENSOR_H_ */
