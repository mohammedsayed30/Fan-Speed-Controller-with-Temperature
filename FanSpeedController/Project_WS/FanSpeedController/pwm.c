 /********************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the AVR_Timer0 pwm driver
 *
 * Created on:- 5/10/2022
 *
 * Author: Mohammed Sayed Shaaban
 *
 *********************************************************************/
#include "pwm.h"         /*to use the pwm_signal*/
#include "gpio.h"        /*to use the gpio_driver*/
#include <avr/io.h>      /*to use the registers of AVR*/


/*
 * Description:-
 * setup the the PWM mode with required configuration
 */
void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0=0;           /*init value*/
	OCR0=duty_cycle;      /*compare value*/
	GPIO_setupPinDirection(PWM_PORT_ID ,PWM_PIN_ID,PIN_OUTPUT);  /*set OC0 as ouput pin*/
	/*setup the configuration that response for pwm_Timer0

	 fast pwm mode:

	 * WGM00=1,WGM01=1
	 *
	 * prescalar= 8 ---->(CS01=1,CS00=0,CS02=0)
	 *
	 * Clear OC0 when match occurs (non_inverted mode)-->(COM00=0 & COM01=1)
	 *
	 */
	TCCR0=(1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

