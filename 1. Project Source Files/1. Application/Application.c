/*
 ============================================================================
 Name        : Application.c
 Author      : Ahmed Shawky
 Description : System control fan speed based on the room temperature
 Date        : 02/09/2023
 ============================================================================
 */

#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "adc.h"

void Display_Temperature(uint8 temp);

int main()
{
	/* Initialize LCD driver */
	LCD_init();

	/* Initialize Motor driver */
	DcMotor_Init();

	ADC_ConfigType ADC_ConfigStruct ;
	ADC_ConfigStruct.ref_volt = INTERNAL_VOLTAGE ;
	ADC_ConfigStruct.prescaler = F_CPU_8 ;

	/* Initialize ADC driver */
	ADC_init(&ADC_ConfigStruct) ;

	uint8 temp = 0 ;

	while(1)
	{
		/* Get the temperature value */
		temp = LM35_GetTemperature();

		/* Control the duty cycle of the output PWM signal (Fan Speed) based on the temperature value */
		if(temp >= 120)
		{
			/* Rotates the motor with 100% from its speed */
			LCD_displayStringRowColumn(0, 4, "FAN is ON ");
			Display_Temperature(temp);
			DcMotor_Rotate(MOTOR_CW, 100);
		}
		else if(temp >= 90)
		{
			/* Rotates the motor with 75% from its speed */
			LCD_displayStringRowColumn(0, 4, "FAN is ON ");
			Display_Temperature(temp);
			DcMotor_Rotate(MOTOR_CW, 75);
		}
		else if(temp >= 60)
		{
			/* Rotates the motor with 50% from its speed */
			LCD_displayStringRowColumn(0, 4, "FAN is ON ");
			Display_Temperature(temp);
			DcMotor_Rotate(MOTOR_CW, 50);
		}
		else if(temp >= 30)
		{
			/* Rotates the motor with 25% from its speed */
			LCD_displayStringRowColumn(0, 4, "FAN is ON ");
			Display_Temperature(temp);
			DcMotor_Rotate(MOTOR_CW, 25);
		}
		else
		{
			/* Stop the motor */
			LCD_displayStringRowColumn(0, 4, "FAN is OFF");
			Display_Temperature(temp);
			DcMotor_Rotate(MOTOR_OFF, 0);
		}
	}

	return 0 ;
}

void Display_Temperature(uint8 temp)
{
	LCD_displayStringRowColumn(1, 4, "Temp = ");
	if(temp >= 100)
	{
		LCD_integerToString(temp);
		LCD_displayString(" C");
	}
	else
	{
		LCD_integerToString(temp);
		LCD_displayString(" C ");
	}
}
