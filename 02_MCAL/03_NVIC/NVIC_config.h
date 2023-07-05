/* 
 * File:   NVIC_CONFIG.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on July 2, 2023, 2:04 PM
 */


#ifndef __NVIC_CONFIG_H__
#define __NVIC_CONFIG_H__


#define 		NVIC_N_IRQNS					   (59)
#define 		NVIC_PRIORITY_BITS				   (4U)


/*Group priority options*/
#define NVIC_PRIORITY_GROUP_0              ((uint32)0x300)
#define NVIC_PRIORITY_GROUP_1			   ((uint32)0x400)
#define NVIC_PRIORITY_GROUP_2			   ((uint32)0x500)
#define NVIC_PRIORITY_GROUP_3			   ((uint32)0x600)
#define NVIC_PRIORITY_GROUP_4              ((uint32)0x700)



/*
 * The table below gives the allowed values of the pre-emption priority and subpriority according
 to the Priority Grouping configuration performed by NVIC_PriorityGroupConfig function
  ============================================================================================================================
    NVIC_PriorityGroup    | NVIC_IRQChannelPreemptionPriority | NVIC_IRQChannelSubPriority  | Description
  ============================================================================================================================
   NVIC_PRIORITY_GROUP_0  |                0-15               |            0                |   0 bits for pre-emption priority
                          |                                   |                             |   4 bits for subpriority
  ----------------------------------------------------------------------------------------------------------------------------
   NVIC_PRIORITY_GROUP_1  |                0-7                |            0-1              |   1 bits for pre-emption priority
                          |                                   |                             |   3 bits for subpriority
  ----------------------------------------------------------------------------------------------------------------------------
   NVIC_PRIORITY_GROUP_2  |                0-3                |            0-3              |   2 bits for pre-emption priority
                          |                                   |                             |   2 bits for subpriority
  ----------------------------------------------------------------------------------------------------------------------------
   NVIC_PRIORITY_GROUP_3  |                0-1                |            0-7              |   3 bits for pre-emption priority
                          |                                   |                             |   1 bits for subpriority
  ----------------------------------------------------------------------------------------------------------------------------
   NVIC_PRIORITY_GROUP_4  |                0                  |            0-15             |   4 bits for pre-emption priority
                          |                                   |                             |   0 bits for subpriority
  ============================================================================================================================
 */
 

#endif  
