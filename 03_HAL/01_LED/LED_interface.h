/* 
 * File:   TEMPLATE.INTERFACE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on April 21, 2023, 8:41 PM
 */


#ifndef __LED_CONFIG_H__
#define __LED_CONFIG_H__



typedef enum
{
	LED_OFF = 0,
	LED_ON  = 1
}tLED_State;


typedef struct
{
	GPIO_t GPIO_portX;
	uint8 GPIO_pinX;
	tLED_State LED_state;
}LED_ConfigType

void LED_vInit(const LED_ConfigType *LED_obj);
void LED_vSetState(const LED_ConfigType *LED_obj, tLED_State Copy_xState);
void LED_vToggle(const LED_ConfigType *LED_obj);
tLED_State LED_xGetState(const LED_ConfigType *LED_obj);





#endif  __LED_CONFIG_H__