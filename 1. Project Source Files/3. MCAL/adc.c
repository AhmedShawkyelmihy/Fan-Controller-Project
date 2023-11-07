/*
 ============================================================================
 Name        : adc.c
 Author      : Ahmed Shawky
 Description : Source File for ADC Driver
 Date        : 30/08/2023
 ============================================================================
 */

/****************************************************************************
 * 								  Includes								    *
 ****************************************************************************/
#include "adc.h"

/****************************************************************************
 * 							Functions Definitions						    *
 ****************************************************************************/

/* Inputs:
 * 	1. Pointer to the configuration structure with type ADC_ConfigType.
 *
 * Return Value: void.
 *
 * Description:
 * 	Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	switch(Config_Ptr->ref_volt)
	{
	case AREF :
		ADMUX = ( ADMUX & 0x3F ) | ( AREF << 6) ;
		break;
	case AVCC :
		ADMUX = ( ADMUX & 0x3F ) | ( AVCC << 6) ;
		break;
	case INTERNAL_VOLTAGE :
		ADMUX = ( ADMUX & 0x3F ) | ( INTERNAL_VOLTAGE << 6) ;
		break;
	}

	ADCSRA |= (1<<ADEN) ;

	switch(Config_Ptr->prescaler)
	{
	case F_CPU_2 :
		ADCSRA = ( ADCSRA & 0xF8 ) | F_CPU_2 ;
		break;
	case F_CPU_4 :
		ADCSRA = ( ADCSRA & 0xF8 ) | F_CPU_4 ;
		break;
	case F_CPU_8 :
		ADCSRA = ( ADCSRA & 0xF8 ) | F_CPU_8 ;
		break;
	case F_CPU_16 :
		ADCSRA = ( ADCSRA & 0xF8 ) | F_CPU_16 ;
		break;
	case F_CPU_32 :
		ADCSRA = ( ADCSRA & 0xF8 ) | F_CPU_32 ;
		break;
	case F_CPU_64 :
		ADCSRA = ( ADCSRA & 0xF8 ) | F_CPU_64 ;
		break;
	case F_CPU_128 :
		ADCSRA = ( ADCSRA & 0xF8 ) | F_CPU_128 ;
		break;
	}
}

/* Inputs:
 * 	1. ADC Channel Number.
 *
 * Return Value: ADC register value.
 *
 * Description:
 * 	Function responsible for read analog data from a certain ADC channel
 * 	and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num)
{
	if((channel_num >= 0) && (channel_num <= 7))
	{
		ADMUX = ( ADMUX & 0xE0 ) | ( channel_num & 0x07 ) ;
		ADCSRA |= (1<<ADSC) ;
		while(!(ADCSRA & (1<<ADIF)));
		ADCSRA |= (1<<ADIF);
	}

	return ADC ;
}


