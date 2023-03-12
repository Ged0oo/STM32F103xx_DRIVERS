/* 
 * File:   GPIO_PRIVATE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */


#ifndef __GPIO_PRIVATE_H__
#define __GPIO_PRIVATE_H__

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* GPIO PORTS BASE ADRESSES */
#define 		GPIOA_BASE_ADDRESS			0x40010800
#define 		GPIOB_BASE_ADDRESS       	0x40010C00
#define 		GPIOC_BASE_ADDRESS       	0x40011000
#define 		GPIOD_BASE_ADDRESS       	0x40011400
#define 		GPIOE_BASE_ADDRESS       	0x40011800
#define 		GPIOF_BASE_ADDRESS       	0x40011C00
#define 		GPIOG_BASE_ADDRESS       	0x40012000


/* GPIO PORTS REGISTERS */
typedef struct
{
	volatile uint32 CRL;
	volatile uint32 CRH;
	volatile uint32 IDR;
	volatile uint32 ODR;
	volatile uint32 BSRR;
	volatile uint32 BRR;
	volatile uint32 LCKR;
}GPIO_t;


/* GPIO PORTS REGISTERS ADRESSES */
#define 		GPIOA				((GPIO_t *) GPIOA_BASE_ADDRESS )
#define 		GPIOB               ((GPIO_t *) GPIOB_BASE_ADDRESS )
#define 		GPIOC               ((GPIO_t *) GPIOC_BASE_ADDRESS )
#define 		GPIOD               ((GPIO_t *) GPIOD_BASE_ADDRESS )
#define 		GPIOE               ((GPIO_t *) GPIOE_BASE_ADDRESS )


#endif
