/* 
 * File:   DC_MOTOR_INTERFACE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on April 25, 2023, 8:41 PM
 */


#ifndef __DC_MOTOR_INTERFACE_H__
#define __DC_MOTOR_INTERFACE_H__




#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"


#define 			DC_MOTOR_ON_STATUS  		0x01U
#define 			DC_MOTOR_OFF_STATUS 		0x00U

#define 			DC_MOTOR_PIN1 				0x00U
#define 			DC_MOTOR_PIN2 				0x01U


typedef struct
{
	GPIO_t* Pin_1_GPIO_portX;
	uint8 Pin_1_GPIO_pinX;
	GPIO_t* Pin_2_GPIO_portX;
	uint8 Pin_2_GPIO_pinX;
}dc_motor_t;


void dc_motor_initialize(const dc_motor_t *_dc_motor);
void dc_motor_move_right(const dc_motor_t *_dc_motor);
void dc_motor_move_left(const dc_motor_t *_dc_motor);
void dc_motor_stop(const dc_motor_t *_dc_motor);





#endif
