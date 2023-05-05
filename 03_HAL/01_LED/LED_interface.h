/* 
 * File:   LED_INTERFACE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on April 21, 2023, 8:41 PM
 */


#ifndef __LED_CONFIG_H__
#define __LED_CONFIG_H__


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LED_config.h"
#include "GPIO_interface.h"


typedef enum
{
	LED_OFF = 0,
	LED_ON  = 1
}tLED_State;


typedef struct
{
	GPIO_t* GPIO_portX;
	uint8 GPIO_pinX;
	tLED_State LED_state;
}LED_ConfigType;



void LED_vInit(LED_ConfigType *LED_obj);
void LED_vSetState(LED_ConfigType *LED_obj, tLED_State Copy_xState);
void LED_vToggle(LED_ConfigType *LED_obj);
tLED_State LED_xGetState(LED_ConfigType *LED_obj);





#endif
