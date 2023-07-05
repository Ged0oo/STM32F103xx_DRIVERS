/* 
 * File:   SCB_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on July 5, 2023, 8:41 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"



/*!< static global variable indicats the current Priority Group !>*/
static uint32 Static_u32CurrentPriorityGroup;



void SCB_vSetPriorityGroup(uint32 Copy_u32PriorityGroup)
{
	Static_u32CurrentPriorityGroup  = SCB->AIRCR;

	Static_u32CurrentPriorityGroup &= ~(
										(0xFFFFUL << SCP_AIRCR_VECTKEY_POS) |
										(7UL << SCP_AIRCR_PRI_GROUB_POS)
										);

	/* Assign the desired group to the global priority group value*/
	Static_u32CurrentPriorityGroup |= (SCB_AIRCR_VECTKEY<<SCP_AIRCR_VECTKEY_POS)|
									 (Copy_u32PriorityGroup<<SCP_AIRCR_PRI_GROUB_POS);


	SCB->AIRCR = Static_u32CurrentPriorityGroup;
}


uint32 SCB_vGetPriorityGroup(void)
{
	return( ( (SCB->AIRCR) & (7UL<<SCP_AIRCR_PRI_GROUB_POS) ) >> SCP_AIRCR_PRI_GROUB_POS);
}