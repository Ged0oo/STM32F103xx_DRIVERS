/* 
 * File:   RCC_private.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include "BIT_MATH.h"
#include "STD_TYPES.h"


/* Registers definitions */
#define 		RCC_BASE_ADDRESS        0x40021000
#define 		RCC              		((volatile RCC_t*)RCC_BASE_ADDRESS)


typedef struct
{
	uint32 CR;
	uint32 CFGR;
	uint32 CIR;
	uint32 APB2RSTR;
	uint32 APB1RSTR;
	uint32 AHBENR;
	uint32 APB2ENR;
	uint32 APB1ENR;
	uint32 BDCR;
	uint32 CSR;
}RCC_t;



#endif







