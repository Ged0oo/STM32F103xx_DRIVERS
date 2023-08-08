/* 
 * File:   SYSTICK_private.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on August 8, 2023, 8:41 PM
 */


#ifndef __SYSTICK_PRIVATE_H__
#define __SYSTICK_PRIVATE_H__


#define 		SYSTICK_BASE_ADDRESS			  	(0xE000E010)
#define 		SYSTICK    				         	((SysTick_TypeDef *)	SYSTICK_BASE_ADDRESS	)

#define 		STK_CTRL_ENABLE_POS					(0)
#define 		STK_CTRL_TICKINT_POS				(1)
#define 		STK_CTRL_SOURCE_POS					(2)
#define 		STK_CTRL_COUNTFLAG_POS				(16)


typedef struct
{
  volatile uint32 CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile uint32 LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  volatile uint32 VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  volatile uint32 CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_TypeDef;


/* Helper Macros */
#define STK_BUSY_WAIT_FLAG()						while((GET_BIT(SYSTICK->CTRL, STK_CTRL_COUNTFLAG_POS))== 0)


/*Systick Exception macros*/
#define STK_ENABLE_EXCEPTION()	             		SYSTICK->CTRL  |=  (1 << STK_CTRL_TICKINT_POS)
#define STK_DISABLE_EXCEPTION()            			SYSTICK->CTRL  &= ~(1 << STK_CTRL_TICKINT_POS)


/*Systick counter state macros*/
#define STK_START_COUNTER()               		 	SYSTICK->CTRL  |=  (1 << STK_CTRL_ENABLE_POS)
#define STK_STOP_COUNTER()                 			SYSTICK->CTRL  &= ~(1 << STK_CTRL_ENABLE_POS)


/* Syctick registers reset macro*/
#define STK_CLEAR_REGISTERS()                       SYSTICK->LOAD = 0;\
													SYSTICK->VAL  = 0

/* Systick update load register Value macro*/
#define STK_UPDATE_LOAD_REGISTER(STK_TICKS)      	SYSTICK->LOAD = STK_TICKS


#endif  __SYSTICK_PRIVATE_H__
