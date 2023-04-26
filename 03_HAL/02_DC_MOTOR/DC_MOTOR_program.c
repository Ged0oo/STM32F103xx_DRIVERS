/* 
 * File:   DC_MOTOR_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on April 25, 2023, 8:41 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DC_MOTOR_interface.h"



void dc_motor_initialize(const dc_motor_t *_dc_motor)
{
    if(NULL == _dc_motor)
	{
        return;
    }
    else
	{    
    	GPIO_voidInitPortPin(_dc_motor->Pin_1_GPIO_portX , _dc_motor->Pin_1_GPIO_pinX , GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_10MHZ );
    	GPIO_voidInitPortPin(_dc_motor->Pin_2_GPIO_portX , _dc_motor->Pin_2_GPIO_pinX , GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_10MHZ );
    }
}


void dc_motor_move_right(const dc_motor_t *_dc_motor)
{
    if(NULL == _dc_motor)
	{
        return;
    }
    else
	{
		GPIO_voidWritePortPin(_dc_motor->Pin_1_GPIO_portX , _dc_motor->Pin_1_GPIO_pinX , GPIO_HIGH);
		GPIO_voidWritePortPin(_dc_motor->Pin_2_GPIO_portX , _dc_motor->Pin_2_GPIO_pinX , GPIO_LOW );
	}
}


void dc_motor_move_left(const dc_motor_t *_dc_motor)
{
    if(NULL == _dc_motor)
	{
        return;
    }
    else
	{
    	GPIO_voidWritePortPin(_dc_motor->Pin_1_GPIO_portX , _dc_motor->Pin_1_GPIO_pinX , GPIO_LOW );
    	GPIO_voidWritePortPin(_dc_motor->Pin_2_GPIO_portX , _dc_motor->Pin_2_GPIO_pinX , GPIO_HIGH);
	}
}


void dc_motor_stop(const dc_motor_t *_dc_motor)
{
    if(NULL == _dc_motor)
	{
        return;
    }
    else
	{
    	GPIO_voidWritePortPin(_dc_motor->Pin_1_GPIO_portX , _dc_motor->Pin_1_GPIO_pinX , GPIO_LOW );
    	GPIO_voidWritePortPin(_dc_motor->Pin_2_GPIO_portX , _dc_motor->Pin_2_GPIO_pinX , GPIO_LOW );
	}
}


