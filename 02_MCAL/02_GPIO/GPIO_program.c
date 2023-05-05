/* 
 * File:   GPIO_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

static void GPIO_voidConfgPin_Mode(GPIO_t *GPIOx , uint8 Copy_u8Pin , uint8 Copy_u8Mode);


void GPIO_voidInitPortPin(GPIO_ConfigType *_gpio)
{
	uint8 Copy_u8Pin  = _gpio->GPIO_PinNumber;
	uint8 Copy_u8Mode = _gpio->GPIO_PinMode;
	if(Copy_u8Pin > 15)
	{
		return;
	}
	GPIO_voidConfgPin_Mode(_gpio->GPIOx , Copy_u8Pin , Copy_u8Mode);
	GPIO_voidWritePortPin(_gpio , _gpio->GPIO_Logic);
}


static void GPIO_voidConfgPin_Mode(GPIO_t *GPIOx , uint8 Copy_u8Pin , uint8 Copy_u8Mode)
{
	if(Copy_u8Pin > 15)
	{
		return;
	}

	if (Copy_u8Pin <= 7)
	{
		/* clear bits */
		GPIOx->CRL &= ~(0xF << Copy_u8Pin*4); /* multiplied *4 because every pin uses 4 bits*/
		
		/*Assign needed mode*/
		GPIOx->CRL |= (Copy_u8Mode << Copy_u8Pin*4);
	}
	else if(Copy_u8Pin <= 15)
	{
		//return pin index to be from p0 to p7
		Copy_u8Pin = Copy_u8Pin - 8;
		
		/*clear bits*/
		GPIOx->CRH &= ~(0xF << Copy_u8Pin*4);
		
		/*Assign needed mode*/
		GPIOx->CRH |= (Copy_u8Mode << Copy_u8Pin*4);
	}
}



void GPIO_voidWritePortPin(GPIO_ConfigType *_gpio , uint8 Copy_u8Val)
{
	if(_gpio->GPIO_PinNumber > 15)
	{
		return;
	}

	if(Copy_u8Val == GPIO_HIGH)
	{
		_gpio->GPIOx->BSRR = 1 << (_gpio->GPIO_PinNumber);
	}
	else
	{
		_gpio->GPIOx->BRR  = 1 << (_gpio->GPIO_PinNumber);
	}
}


uint8 GPIO_u8ReadPortPin(GPIO_ConfigType *_gpio)
{
	if(_gpio->GPIO_PinNumber > 15)
	{
		return 0;
	}

	return GET_BIT(_gpio->GPIOx->IDR , _gpio->GPIO_PinNumber);
}

