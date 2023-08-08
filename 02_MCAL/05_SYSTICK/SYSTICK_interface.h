/* 
 * File:   SYSTICK_interface.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on August 8, 2023, 8:41 PM
 */


#ifndef __SYSTICK_INTERFACE_H__
#define __SYSTICK_INTERFACE_H__



#define 	CPU_CLK     			  		   	(8000000)
#define 	SYSTICK_TIMER_TICK_MS               (100)


/*Systick Ticks Types*/
#define 	SYSTICK_TICKS_US                    (1)
#define 	SYSTICK_TICKS_MS					(1000)
#define 	SYSTICK_TICKS_S						(1000000)


/* Systick Clock Source Options*/
#define		STK_CLK_SRC_AHB_DIVIDED_BY_8        (0)
#define		STK_CLK_SRC_AHB						(1)


/* Systick Interval modes*/
#define STK_SINGLE_INTERVAL_MODE		    0
#define STK_PERIODIC_INTERVAL_MODE	     	1


/*Functions Prototype*/
void STK_vInit(uint8 Copy_xClockSource);
void STK_vSetBusyWait(uint32 Copy_u32Ticks, uint32 Copy_u32TicksTybe);
void STK_vSetIntervalSingle  ( uint32 Copy_u32Ticks, uint32 Copy_u32TicksTybe, void (*Copy_vpFuncPtr)(void));
void STK_vSetIntervalPeriodic(uint32 Copy_u32Ticks ,uint32 Copy_u32TicksTybe , void (* Copy_vpFuncPtr) (void));
void STK_vStopInterval(void);
uint32 STK_u32GetRemainingTime(uint32 Copy_u32TicksTybe);
uint32 STK_u32GetElapsedTime(uint32 Copy_u32TicksTybe);


#endif  __SYSTICK_INTERFACE_H__
