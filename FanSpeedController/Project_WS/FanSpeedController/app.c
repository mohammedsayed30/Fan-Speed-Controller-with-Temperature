 /********************************************************************
 *
 * Module: Fan_Controller Design
 *
 * File Name: app.c
 *
 * Description: Source file for the application layer for Fan Design
 *
 * Created on:- 5/10/2022
 *
 * Author: Mohammed Sayed Shaaban
 *
 *********************************************************************/
#include "dc_motor.h"         /*to use the dc_motor Driver*/
#include "LCD.h"              /*to use the LCD Driver*/
#include "lm.h"               /*to use the LM35 Driver*/
#include "adc.h"              /*to i can create object to structure ADC_configType*/


int main(void)
{
	ADC_ConfigType ADC_Config;       /*Structure hold the configuration of ADC*/
	ADC_Config.ref_volt=INTERNAL_AREF;       /*reference voltage(2.56) */
	ADC_Config.prescalar=8;         /*prescaler*/
	ADC_init(&ADC_Config);         /*to initialize the ADC*/
	LCD_init();                   /*to initialize the LCD*/
	DcMotor_init();               /*to configure the DC_Motor*/
	uint8 tem;                    /* to hold the value of temperature*/
	LCD_displayStringRowColumn(1,5,"Temp =    C");
	while(1){
	    tem = LM35_GetTemperature();   /*get the temperature using the ADC*/
	    if(tem<100){                   /*to remove the final digit if tem <100*/
	    	LCD_moveCursor(1,13);
	    	LCD_displayCharacter(' ');      /*to remove the final digit if tem <100*/
	    }
	    if(tem<10){
	    	LCD_moveCursor(1,12);
	    	LCD_displayCharacter(' ');
	    }
	    LCD_moveCursor(1,11);          /*to Display the Temperature after (=)*/
	    LCD_intgerToString(tem);      /*to display the the temperature*/
	    if(tem<30){
	    	DcMotor_Rotate(stop,0);      /*to stop the DC Motor*/
	    	LCD_displayStringRowColumn(0,5,"FAN is OFF"); /*to display this message*/

	    }
	    else if(tem>=30 && tem<60){
	    	DcMotor_Rotate(clock_wise,25);      /*to rotate the DC Motor with 25% of maximum speed */
	    	LCD_displayStringRowColumn(0,5,"FAN is ON"); /*to display this message*/
	    	LCD_displayCharacter(' ');            /*to remove the (F) Character*/

	    }
	    else if(tem>=60 && tem<90){
	    	DcMotor_Rotate(clock_wise,50);      /*to rotate the DC Motor with 50% of maximum speed */
	    	LCD_displayStringRowColumn(0,5,"FAN is ON"); /*to display this message*/
	    	LCD_displayCharacter(' ');                  /*to remove the (F) Character*/

	    }
	    else if(tem>=90 && tem<120){
	    	DcMotor_Rotate(clock_wise,75);      /*to rotate the DC Motor with 75% of maximum speed */
	    	LCD_displayStringRowColumn(0,5,"FAN is ON"); /*to display this message*/
	    	LCD_displayCharacter(' ');             /*to remove the (F) Character*/
	    }
	    else if(tem>=120){
	    	DcMotor_Rotate(clock_wise,100);      /*to rotate the DC Motor with 100% of maximum speed */
	    	LCD_displayStringRowColumn(0,5,"FAN is ON"); /*to display this message*/
	    	LCD_displayCharacter(' ');                 /*to remove the (F) Character*/
	    }


	}
	return 0;
}




