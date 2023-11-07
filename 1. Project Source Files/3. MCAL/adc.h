/*
 ============================================================================
 Name        : adc.h
 Author      : Ahmed Shawky
 Description : Header File for ADC Driver
 Date        : 30/08/2023
 ============================================================================
 */

#ifndef ADC_H_
#define ADC_H_

/****************************************************************************
 * 								  Includes								    *
 ****************************************************************************/
#include <avr/io.h>
#include "std_types.h"
#include "common_macros.h"

/****************************************************************************
 * 								 Definitions								*
 ****************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

#define ADC0 			     0
#define ADC1 			     1
#define ADC2 			     2
#define ADC3 			     3
#define ADC4 			     4
#define ADC5 			     5
#define ADC6 			     6
#define ADC7 			     7

/****************************************************************************
 * 					          Types Declaration						        *
 ****************************************************************************/
typedef enum
{
	AREF,
	AVCC,
	INTERNAL_VOLTAGE = 0x03

}ADC_ReferenceVolatge;

typedef enum
{
	F_CPU_2 = 0x01 ,
	F_CPU_4,
	F_CPU_8,
	F_CPU_16,
	F_CPU_32,
	F_CPU_64,
	F_CPU_128

}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;

/****************************************************************************
 * 							Functions Prototypes						    *
 ****************************************************************************/

/* Inputs:
 * 	1. Pointer to the configuration structure with type ADC_ConfigType.
 *
 * Return Value: void.
 *
 * Description:
 * 	Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/* Inputs:
 * 	1. ADC Channel Number.
 *
 * Return Value: ADC register value.
 *
 * Description:
 * 	Function responsible for read analog data from a certain ADC channel
 * 	and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
