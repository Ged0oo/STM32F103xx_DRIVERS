/* 
 * File:   RCC_PROGRAM.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */
 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


static void RCC_voidSetClksState(Copy_u8ClkStates) ; 
static void RCC_voidSetPllInput(Copy_u8PllIn) ; 
static void RCC_voidSetPllMulFactor(Copy_u8Pllmulfactor) ; 


void RCC_voidInitSystemClk(RCC_ClksState_t Copy_u8ClkStates , RCC_SystemClk_t Copy_u8SystemClk ,RCC_PllInput_t Copy_u8PllIn ,RCC_PllMulFactor_t Copy_u8Pllmulfactor)
{
	RCC_voidSetClksState(Copy_u8ClkStates) ; 
	RCC_voidSetPllInput(Copy_u8PllIn) ; 
	RCC_voidSetPllMulFactor(Copy_u8Pllmulfactor) ; 
	RCC_voidSetSystemClk(Copy_u8SystemClk) ; 
}
 
 
void  RCC_voidSetClksState(tRCC_ClksState Copy_u8ClkStates) 
{	
	MAN_BIT(RCC_CR   ,  RCC_CR_PLLON_PIN   ,   GET_BIT(Copy_u8ClkStates, PLLON_BIT_ID)       ) ;
    if(	GET_BIT(Copy_u8ClkStates,PLLON_BIT_ID) == HIGH) 
	{ 
		while(GET_BIT(RCC_CR,RCC_CR_PLL_RDY_PIN) != HIGH) ;
	}
		
	MAN_BIT( RCC_CR , RCC_CR_HSION_PIN , GET_BIT(Copy_u8ClkStates , HSION_BIT_ID) );
	if(	GET_BIT(Copy_u8ClkStates,HSION_BIT_ID) == HIGH)
	{
		while(GET_BIT(RCC_CR,RCC_CR_HSIRDY_PIN) != HIGH) ;
	}
		
	
	MAN_BIT(RCC_CR , RCC_CR_HSEON_PIN , GET_BIT(Copy_u8ClkStates , HSEON_BIT_ID));
	if(	GET_BIT(Copy_u8ClkStates,HSEON_BIT_ID) == HIGH)
	{
		while(GET_BIT(RCC_CR , RCC_CR_HSERDY_PIN) != HIGH) ;
	}
		
	
	MAN_BIT(RCC_CR , RCC_CR_HSEBPY_PIN , GET_BIT(Copy_u8ClkStates , HSEBPY_BIT_ID)) ;
}


static void  RCC_voidSetPllInput(tRCC_PllInput Copy_u8PllIn)  
{
	if(Copy_u8PllIn != RCC_PLL_NOT_USED )
	{
      MAN_BIT(RCC_CFGR , RCC_CFGR_PLLSRC_PIN   , GET_BIT(Copy_u8PllIn , PLLSRC_BIT_ID  )) ;
      MAN_BIT(RCC_CFGR , RCC_CFGR_PLLXTPRE_PIN , GET_BIT(Copy_u8PllIn , PLLXTPRE_BIT_ID)) ;
	}
}


static void  RCC_voidSetPllMulFactor(tRCC_PllMulFactor Copy_u8Pllmulfactor) 
{
	if(Copy_u8Pllmulfactor != PLL_IN_X_1 )
	{
      u8 current_pll_state = GET_BIT(RCC_CR , RCC_CR_PLLON_PIN) ; 
      CLR_BIT(RCC_CR      , RCC_CR_PLLON_PIN) ; 
      MAN_NIBBLE(RCC_CFGR , RCC_CFGR_PLLMULL_START_PIN , Copy_u8Pllmulfactor) ;
      MAN_BIT(RCC_CR      , RCC_CR_PLLON_PIN           , current_pll_state) ;
	}
}


static void  RCC_voidSetSystemClk(tRCC_SystemClk Copy_u8SystemClk) 
{
    MAN_BIT(RCC_CFGR , RCC_CFGR_SW_PIN_0 , GET_BIT(Copy_u8SystemClk , SW_BIT_0_ID)) ;	
    MAN_BIT(RCC_CFGR , RCC_CFGR_SW_PIN_1 , GET_BIT(Copy_u8SystemClk , SW_BIT_1_ID)) ;	
}
