/* 
 * File:   LED_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on April 21, 2023, 8:41 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "LED_config.h"


void LED_vInit(LED_ConfigType *LED_obj)
{
	if(NULL == LED_obj)
	{
		return;
	}
	else
	{
		GPIO_voidInitPortPin(LED_obj->GPIO_portX , LED_obj->GPIO_pinX , GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_2MHZ);
		LED_vSetState(LED_obj , LED_obj->LED_state);
	}
}


void LED_vSetState(LED_ConfigType *LED_obj, tLED_State Copy_xState)
{
	if(NULL == LED_obj)
	{
		return;
	}
	else
	{
		GPIO_voidWritePortPin(LED_obj->GPIO_portX , LED_obj->GPIO_pinX , Copy_xState);
	}
}


void LED_vToggle(LED_ConfigType *LED_obj)
{
	if(NULL == LED_obj)
	{
		return;
	}
	else
	{
		LED_obj->LED_state ^= 1;
	}
}


tLED_State LED_xGetState(LED_ConfigType *LED_obj)
{
	if(NULL == LED_obj)
	{
		return;
	}
	else
	{
		return LED_obj->LED_state;
	}		
}



