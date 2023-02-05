/*******************************************************************
 *  Model:-File Source for LM35 Sensor
 *
 *  File Name:lm.c
 *
 *  Created on:4/10/2022
 *
 *  Author: Mohammed Sayed Shaaban
 ********************************************************************/

#include "lm.h"
#include "adc.h"
/*
 * Function Name : LM35_GetTemperature
 *
 * Description :
 *
 * get the temperature using the digit value from the ADC
 */
uint8 LM35_GetTemperature(void){

	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read  ADC channel(digital value)  */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;        /*the required temperature*/
}

