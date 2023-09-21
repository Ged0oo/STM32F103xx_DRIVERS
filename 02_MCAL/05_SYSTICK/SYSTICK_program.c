/* 
 * File:   SYSTICK_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on August 8, 2023, 8:41 PM
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

static volatile uint8 STK_u8IntervalMode;

#define STK_SET_INTERVAL_MODE(MODE)                          STK_u8IntervalMode = MODE
#define STK_GET_INTERVAL_MODE()                             (STK_u8IntervalMode & 1)

static void (*SysTick_CallBack) (void);


void STK_vInit(uint8 Copy_xClockSource)
{
	/* Select Systick Clock Source */
	switch(Copy_xClockSource)
	{
		case STK_CLK_SRC_AHB_DIVIDED_BY_8:
			SET_BIT(SYSTICK->CTRL , STK_CTRL_SOURCE_POS);
			break;

		case STK_CLK_SRC_AHB:
			CLEAR_BIT(SYSTICK->CTRL , STK_CTRL_SOURCE_POS);
			break;

		default :
			break;
	}

	/* Disable Systick Exception */
	STK_DISABLE_EXCEPTION();
}


void STK_vSetBusyWait(uint32 Copy_u32Ticks, uint32 Copy_u32TicksTybe)
{
	/* Assign Ticks to Load Register */
	STK_UPDATE_LOAD_REGISTER(Copy_u32Ticks * Copy_u32TicksTybe);

	/* Start Timer */
	STK_START_COUNTER();

	/* Wait Until Busy Wait Flag is Raised */
	STK_BUSY_WAIT_FLAG();

	/* Stop Timer */
	STK_STOP_COUNTER();

	/* Clear Systick Registers */
	STK_CLEAR_REGISTERS();
}


void STK_vSetIntervalSingle(uint32 Copy_u32Ticks, uint32 Copy_u32TicksTybe, void (*Copy_vpFuncPtr)(void))
{
	/*Assign Ticks to Load Register*/
	STK_UPDATE_LOAD_REGISTER(Copy_u32Ticks * Copy_u32TicksTybe );

	/*Assign the Function to the Callback Function */
	SysTick_CallBack = Copy_vpFuncPtr;

	/* Set Mode to Single */
	STK_SET_INTERVAL_MODE(STK_SINGLE_INTERVAL_MODE);

	/*Enable Systick Exception*/
	STK_ENABLE_EXCEPTION();

	/*Start the Counter*/
	STK_START_COUNTER();
}


void STK_vSetIntervalPeriodic(uint32 Copy_u32Ticks ,uint32 Copy_u32TicksTybe , void (* Copy_vpFuncPtr) (void))
{
	/*Assign Ticks to Load Register*/
	STK_UPDATE_LOAD_REGISTER(Copy_u32Ticks * Copy_u32TicksTybe );

	/*Assign the Function to the Callback Function */
	SysTick_CallBack = Copy_vpFuncPtr;

	/* Set Mode to Single */
	STK_SET_INTERVAL_MODE(STK_PERIODIC_INTERVAL_MODE);

	/*Enable Systick Exception*/
	STK_ENABLE_EXCEPTION();

	/*Start the Counter*/
	STK_START_COUNTER();
}


void STK_vStopInterval(void)
{
	/*Disable Systick Exception*/
	STK_DISABLE_EXCEPTION();

	/*Stop the Counter*/
	STK_STOP_COUNTER();

	/*Clear Systick Registers*/
	STK_CLEAR_REGISTERS();
}


uint32 STK_u32GetRemainingTime(uint32 Copy_u32TicksTybe)
{
	return ((SYSTICK->VAL)*Copy_u32TicksTybe);
}


uint32 STK_u32GetElapsedTime(uint32 Copy_u32TicksTybe)
{
	return (((SYSTICK->LOAD) - (SYSTICK->VAL)) * Copy_u32TicksTybe);
}


void SysTick_Handler(void)
{
	uint8 Local_u8Temporary = 0;
	if(STK_GET_INTERVAL_MODE() == STK_SINGLE_INTERVAL_MODE)
	{
		/*Disable Systick Exception*/
		STK_DISABLE_EXCEPTION();

		/*Stop the Counter*/
		STK_STOP_COUNTER();

		/*Clear Systick Registers*/
		STK_CLEAR_REGISTERS();
	}

	/*Execute Callback Function*/
	SysTick_CallBack();

	/*Clear Exception Flag*/
	Local_u8Temporary = GET_BIT(SYSTICK->CTRL, STK_CTRL_COUNTFLAG_POS);
}
