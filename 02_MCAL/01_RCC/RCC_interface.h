/* 
 * File:   RCC_INTERFACE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */



#ifndef __RCC_INTERFACE_H__
#define __RCC_INTERFACE_H__

/* 
 * RCC_ClksState_t Enum to deal with 
 * different clock sources states(PLL , HSI , HSE ) and which passes or not 
 */
typedef enum
{
	RCC_PLL_OFF_HSI_OFF_HSE_OFF_BYPASS_OFF =  0x00,
	RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF  =  0x02,
	RCC_PLL_OFF_HSI_ON_HSE_OFF_BYPASS_OFF  =  0x04,
	RCC_PLL_OFF_HSI_ON_HSE_ON_BYPASS_ON    =  0x07,
	
	RCC_PLL_ON_HSI_OFF_HSE_OFF_BYPASS_OFF  =  0x08,
	RCC_PLL_ON_HSI_OFF_HSE_ON_BYPASS_OFF   =  0x0A,
	RCC_PLL_ON_HSI_ON_HSE_OFF_BYPASS_OFF   =  0x0C,
	RCC_PLL_ON_HSI_ON_HSE_ON_BYPASS_ON     =  0x0F
}RCC_ClksState_t ; 


/* 
 * RCC_SystemClk_t Enum to deal with 
 * System clock which is directly enter to the processor  
 */
typedef enum 
{
    RCC_SYSTCLK_HSI = 0x00 , 
    RCC_SYSTCLK_HSE = 0x01 , 
    RCC_SYSTCLK_PLL = 0x02 
}RCC_SystemClk_t ; 


/* 
 * RCC_PllInput_t is an Enum to deal with
 * pll input states  
 */
typedef enum 
{
    RCC_PLL_IN_HSI_BY_2 = 0x00 , 
    RCC_PLL_IN_HSE      = 0x01 , 
    RCC_PLL_IN_HSE_BY_2 = 0x03 ,
	RCC_PLL_NOT_USED    = 0x04
}RCC_PllInput_t ; 

/* 
 * RCC_PllMulFactor_t is an Enum to deal with 
 * pll multiplaction factor 
 */
typedef enum 
{
    PLL_IN_X_4  = 0x02 , 
    PLL_IN_X_5  = 0x03 , 
    PLL_IN_X_6  = 0x04 , 
    PLL_IN_X_7  = 0x05 , 
    PLL_IN_X_8  = 0x06 , 
    PLL_IN_X_9  = 0x07 , 
    PLL_IN_X_10 = 0x08 , 
    PLL_IN_X_11 = 0x09 , 
    PLL_IN_X_12 = 0x0A , 
    PLL_IN_X_13 = 0x0B , 
    PLL_IN_X_14 = 0x0C , 
    PLL_IN_X_15 = 0x0D , 
    PLL_IN_X_16 = 0x0E
}RCC_PllMulFactor_t ;




/* 
 * function name : RCC_voidInitSystemClk
 * return type   : void 
 * paramters     : 
					1- RCC_ClksState_t    : defines all clock resources states(PLL , HSI , HSE ) and if HSE passes from pins or not 
											{RCC_PLL_OFF_HSI_OFF_HSE_OFF_BYPASS_OFF , RCC_PLL_OFF_HSI_ON_HSE_OFF_BYPASS_OFF ,
											 RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF  , RCC_PLL_OFF_HSI_ON_HSE_ON_BYPASS_ON   ,
											 RCC_PLL_ON_HSI_OFF_HSE_OFF_BYPASS_OFF  , RCC_PLL_ON_HSI_ON_HSE_OFF_BYPASS_OFF  ,
											 RCC_PLL_ON_HSI_OFF_HSE_ON_BYPASS_OFF   , RCC_PLL_ON_HSI_ON_HSE_ON_BYPASS_ON    }
				 
					2- RCC_SystemClk_t    : defines which clock source the system runs on 			   
											{RCC_SYSTCLK_HSI , RCC_SYSTCLK_HSE , RCC_SYSTCLK_PLL } 
									   
					3- RCC_PllInput_t     : defines pll ciruit input 	                   
											{RCC_PLL_IN_HSI_BY_2 , RCC_PLL_IN_HSE , RCC_PLL_IN_HSE_BY_2 , RCC_PLL_NOT_USED }
				 
					4- RCC_PllMulFactor_t : defines pll circuit multiplaction factor 			   
											{PLL_IN_X_1 , PLL_IN_X_2  , PLL_IN_X_3  , PLL_IN_X_4  ,
											PLL_IN_X_5  , PLL_IN_X_6  , PLL_IN_X_7  , PLL_IN_X_8  ,
											PLL_IN_X_9  , PLL_IN_X_10 , PLL_IN_X_11 , PLL_IN_X_12 ,
											PLL_IN_X_13	, PLL_IN_X_14 , PLL_IN_X_15	, PLL_IN_X_16 }		
											
 * Description  : initalize the previous paramters. 		   
 */
void RCC_voidInitSystemClk(RCC_ClksState_t Copy_u8ClkStates , RCC_SystemClk_t Copy_u8SystemClk ,RCC_PllInput_t Copy_u8PllIn ,RCC_PllMulFactor_t Copy_u8Pllmulfactor) ;  



/* 
 * function name : RCC_voidSetClksState
 * return type   : void 
 * paramters     : 
					1- RCC_ClksState_t    : defines all clock resources states(PLL , HSI , HSE ) and if HSE passes from pins or not 
											{RCC_PLL_OFF_HSI_OFF_HSE_OFF_BYPASS_OFF , RCC_PLL_OFF_HSI_ON_HSE_OFF_BYPASS_OFF ,
											 RCC_PLL_OFF_HSI_OFF_HSE_ON_BYPASS_OFF  , RCC_PLL_OFF_HSI_ON_HSE_ON_BYPASS_ON   ,
											 RCC_PLL_ON_HSI_OFF_HSE_OFF_BYPASS_OFF  , RCC_PLL_ON_HSI_ON_HSE_OFF_BYPASS_OFF  ,
											 RCC_PLL_ON_HSI_OFF_HSE_ON_BYPASS_OFF   , RCC_PLL_ON_HSI_ON_HSE_ON_BYPASS_ON    }
											 
 * Description : initalize clocks states. 		   
*/	
void RCC_voidSetClksState(RCC_ClksState_t Copy_u8ClkStates) ;
				   
#endif  __RCC_INTERFACE_H__