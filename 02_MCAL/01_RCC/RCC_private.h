/* 
 * File:   RCC_PRIVATE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */ 
 
 
#ifndef __TEMPLATE_PRIVATE_H__
#define __TEMPLATE_PRIVATE_H__
				   

#define  	RCC_BASE_ADDRESS     		(0x40021000) 
#define  	RCC_CR_OFFSET	     		(0x000) 
#define  	RCC_CFGRR_OFFSET	     	(0x004) 
#define  	RCC_CIR_OFFSET	     		(0x008) 
#define  	RCC_APB2RSTR_OFFSET	     	(0x00C) 
#define  	RCC_APB1RSTR_OFFSET	     	(0x010) 
#define  	RCC_AHBENR_OFFSET	     	(0x014) 
#define  	RCC_APB2ENR_OFFSET	     	(0x018) 
#define  	RCC_APB1ENR_OFFSET	     	(0x01C) 
#define  	RCC_BDCR_OFFSET	     		(0x020) 
#define  	RCC_CSR_OFFSET	     		(0x024) 
#define  	RCC_AHBSTR_OFFSET	     	(0x028) 
#define  	RCC_CFGR2_OFFSET	     	(0x02C)  


#define  	RCC_CR              		*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET )) 
#define  	RCC_CFGRR              		*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))
#define  	RCC_CIR              		*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))
#define  	RCC_APB2RSTR              	*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))				   
#define  	RCC_APB1RSTR              	*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))				   
#define  	RCC_AHBENR              	*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET )) 
#define  	RCC_APB2ENR              	*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))
#define  	RCC_APB1ENR              	*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))
#define  	RCC_BDCR              		*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))
#define  	RCC_CSR              		*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))
#define  	RCC_AHBSTR            	  	*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))
#define  	RCC_CFGR2              		*((volatile u32 *)( RCC_BASE_ADDRESS + RCC_CR_OFFSET ))

#define 	RCC_CR_PLL3RDY_PIN            29 
#define 	RCC_CR_PLL3ON_PIN             28
#define 	RCC_CR_PLL2RDY_PIN            27 
#define 	RCC_CR_PLL2ON_PIN             26
#define 	RCC_CR_PLLRDY_PIN             25 
#define 	RCC_CR_PLLON_PIN              24
#define 	RCC_CR_CSSON_PIN              19
#define 	RCC_CR_HSEBPY_PIN             18
#define 	RCC_CR_HSERDY_PIN             17
#define 	RCC_CR_HSEON_PIN              16
#define 	RCC_CR_HSICAL_START_PIN       8 
#define 	RCC_CR_HSITRIM_START_PIN      3
#define 	RCC_CR_HSIRDY_PIN             1
#define 	RCC_CR_HSION_PIN			  0
				   
				   				  
#define 	RCC_CFGR_MCO_START_PIN        24
#define 	RCC_CFGR_OTGFSPRE_PIN         22
#define 	RCC_CFGR_PLLMULL_START_PIN    18
#define 	RCC_CFGR_PLLXTPRE_PIN         17 
#define 	RCC_CFGR_PLLSRC_PIN           16 
#define 	RCC_CFGR_ADCPRE_PIN           14
#define 	RCC_CFGR_PPRE2_START_PIN      11
#define 	RCC_CFGR_PPRE1_START_PIN      8
#define 	RCC_CFGR_HPRE_START_PIN       4
#define 	RCC_CFGR_SWS_PIN_1            3
#define 	RCC_CFGR_SWS_PIN_0            2
#define 	RCC_CFGR_SW_PIN_1             1
#define 	RCC_CFGR_SW_PIN_0             0 
				   
				   
#define 	PLLON_BIT_ID  				  3
#define 	HSION_BIT_ID  				  2
#define 	HSEON_BIT_ID  				  1
#define 	HSEBPY_BIT_ID 				  0

#define 	TRIM_STEP     				  40 

#define 	PLLSRC_BIT_ID                0 
#define 	PLLXTPRE_BIT_ID              1

#define 	SW_BIT_0_ID                  0 
#define 	SW_BIT_1_ID                  1

#define 	PRE1_BIT_0_ID                0
#define 	PRE1_BIT_1_ID                1
#define 	PRE1_BIT_2_ID                2

#define 	PRE2_BIT_0_ID                0
#define 	PRE2_BIT_1_ID                1
#define 	PRE2_BIT_2_ID                2				   
				   
#endif  __TEMPLATE_PRIVATE_H__
