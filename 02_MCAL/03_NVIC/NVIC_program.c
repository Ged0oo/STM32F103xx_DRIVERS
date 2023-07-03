/* 
 * File:   NVIC_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on July 2, 2023, 2:04 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/*!< static global variable indicats the current Priority Group !>*/
static uint32 Static_u32CurrentPriorityGroup; 


void NVIC_xEnableInterrupt(IRQnum_t Copy_xIntIndex)
{
	if(Copy_xIntIndex >= 0)
	{
		NVIC->ISER[(Copy_xIntIndex/32)] = (1 << (Copy_xIntIndex % 32));
	}
}


void NVIC_xDisableInterrupt(IRQnum_t Copy_xIntIndex)
{
	if(Copy_xIntIndex >= 0)
	{
		NVIC->ICER[(Copy_xIntIndex/32)] = (1 << (Copy_xIntIndex % 32));
	}
}


void NVIC_xSetPendingFlag(IRQnum_t Copy_xIntIndex)
{
	if(Copy_xIntIndex >= 0)
	{
		NVIC->ISPR[(Copy_xIntIndex/32)] = (1 << (Copy_xIntIndex % 32));
	}
}


void NVIC_xClearPendingFlag(IRQnum_t Copy_xIntIndex)
{
	if(Copy_xIntIndex >= 0)
	{
		NVIC->ICPR[(Copy_xIntIndex/32)] = (1 << (Copy_xIntIndex % 32));
	}
}


void NVIC_xReadIntState(IRQnum_t Copy_xIntIndex, uint8 *pu8IntState)
{
	if(Copy_xIntIndex >= 0)
	{
		*pu8IntState = GET_BIT (NVIC->IABR[Copy_xIntIndex/32], (Copy_xIntIndex%32));
	}
}


IRQnum_t NVIC_xCheck_CurrentInt(void)
{
	/* Check for all maskable interrupts */	
	IRQnum_t LOC_u8Index = 0;
	uint8 LOC_u8State = 0;
	
	/*Check for all maskable interrupts if there is active one or not*/
	for(LOC_u8Index = 0 ; LOC_u8Index <= NVIC_N_IRQNS ; LOC_u8Index++)
	{
		LOC_u8State = GET_BIT(NVIC->IABR[LOC_u8Index/32], LOC_u8Index%32);
		
		/*If there is an active flag break the loop*/
		if(LOC_u8State == 1)break;
		else /*No Action*/
	}
	return LOC_u8Index;
}


void NVIC_vPriorityGroupInit(uint32 Copy_u32PriorityGroup)
{
	/* Assign the desired group to the global priority group value*/
	Static_u32CurrentPriorityGroup = SCB_AIRCR_VECTKEY | Copy_u32PriorityGroup;
	SCB->AIRCR = Static_u32CurrentPriorityGroup;
}


void NVIC_xSetpriority(IRQnum_t Copy_xIntIndex , uint8 Copy_u8GroupPriority , uint8 Copy_u8SubPriority)
{
	if((Copy_xIntIndex >= 0) && (Copy_xIntIndex <= NVIC_N_IRQNS))
	{
		
	}
}





