/*
 ============================================================================
 Name        : lm35_sensor.c
 Author      : Ahmed Shawky
 Description : Source File for LM35 Temperature Sensor Driver
 Date        : 30/08/2023
 ============================================================================
 */

/****************************************************************************
 * 								  Includes								    *
 ****************************************************************************/
#include "lm35_sensor.h"

/****************************************************************************
 * 							Functions Definitions						    *
 ****************************************************************************/

/* Inputs: void.
 *
 * Return Value: Temperature value from the LM35 sensor.
 *
 * Description:
 *	Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemperature(void)
{
	uint8 temp_value = 0 ;

	uint16 adc_value = ADC_readChannel(SENSOR_CHANNEL_ID) ;

	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMP_VALUE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value ;
}


