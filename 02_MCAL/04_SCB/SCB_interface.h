/* 
 * File:   SCB_INTERFACE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on July 5, 2023, 8:41 PM
 */


#ifndef __SCB_INTERFACE_H__
#define __SCB_INTERFACE_H__


/*!<
 The table below gives the allowed values of the pre-emption priority and subpriority according
 to the Priority Grouping configuration performed by SCB_PriorityGroupConfig function
  ========================================================================================================================================
    SCB_PriorityGroup    | SCB_IRQChannelPreemptionPriority | SCB_IRQChannelSubPriority  | Description
  ========================================================================================================================================
   SCB_PRIORITY_GROUP_0  |              0-15   			    |             0				 |   0 bits for pre-emption priority
                         |           						|           				 |   4 bits for subpriority
  --------------------------------------------------------------------------------------------------------
   SCB_PRIORITY_GROUP_1  |    		    0-7   				|        	 0-1  			 |   1 bits for pre-emption priority
                         |           						|           				 |   3 bits for subpriority
  --------------------------------------------------------------------------------------------------------
   SCB_PRIORITY_GROUP_2  |    		    0-3    				|        	 0-3  			 |   2 bits for pre-emption priority
                         |           						|           				 |   2 bits for subpriority
  --------------------------------------------------------------------------------------------------------
   SCB_PRIORITY_GROUP_3  |    		    0-1    	     		|          	 0-7		     |   3 bits for pre-emption priority
                         |           						|           				 |   1 bits for subpriority
  --------------------------------------------------------------------------------------------------------
   SCB_PRIORITY_GROUP_4  |    			 0      			|    		 0-15      		 |   4 bits for pre-emption priority
                         |           						|           				 |   0 bits for subpriority
  ========================================================================================================================================
 */
 
 
/*Group priority options*/
#define 		SCP_PRIORITY_GROUP_0               ((uint32)0x7)
#define 		SCP_PRIORITY_GROUP_1			   ((uint32)0x6)
#define 		SCP_PRIORITY_GROUP_2			   ((uint32)0x5)
#define 		SCP_PRIORITY_GROUP_3			   ((uint32)0x4)
#define 		SCP_PRIORITY_GROUP_4               ((uint32)0x3)


void SCB_vSetPriorityGroup(uint32 Copy_u32PriorityGroup);
uint32 SCB_vGetPriorityGroup(void);

				   
#endif  __SCB_INTERFACE_H__