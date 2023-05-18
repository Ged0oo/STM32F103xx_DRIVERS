/* 
 * File:   RCC_interface.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_config.h"
#include "RCC_private.h"




#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H



/* Buses Names */
#define			RCC_AHB_BUS						0
#define			RCC_APB1_BUS					1
#define			RCC_APB2_BUS					2


/* System CLOCK SOURCE */
#define			RCC_HSI							0
#define			RCC_HSE							1
#define			RCC_PLL							2


/* PLL CLOCK SOURCE */
#define 		PLL_SRC_HSE_NOT_DEVIDED			0
#define			PLL_SRC_HSE_DEVIDED_BY_2		1
#define			PLL_SRC_HSI_DEVIDED_BY_2		2


/* RCC Clock SOURCE */
#define			RCC_DISABLE_PERIPHERAL			0
#define			RCC_ENABLE_PERIPHERAL			1


/* MCO CLOCK SOURCE */
#define			MCO_No_CLK               		0
#define			MCO_SYSCLK 				 		1
#define			MCO_HSI				 	 		2
#define			MCO_HSE					 		3
#define			MCO_PLL					 		4


/* PLL MUL FACTOR */
#define 		PLL_x_2_INPUT_CLOCK            	(0x0)
#define 		PLL_x_3_INPUT_CLOCK            	(0x1)
#define 		PLL_x_4_INPUT_CLOCK            	(0x2)
#define 		PLL_x_5_INPUT_CLOCK            	(0x3)
#define 		PLL_x_6_INPUT_CLOCK            	(0x4)
#define 		PLL_x_7_INPUT_CLOCK            	(0x5)
#define 		PLL_x_8_INPUT_CLOCK           	(0x6)
#define 		PLL_x_9_INPUT_CLOCK            	(0x7)
#define 		PLL_x_10_INPUT_CLOCK            (0x8)
#define 		PLL_x_11_INPUT_CLOCK            (0x9)
#define 		PLL_x_12_INPUT_CLOCK            (0xA)
#define 		PLL_x_13_INPUT_CLOCK            (0xB)
#define 		PLL_x_14_INPUT_CLOCK            (0xC)
#define 		PLL_x_15_INPUT_CLOCK            (0xD)
#define 		PLL_x_16_INPUT_CLOCK            (0xE)
#define 		PLL_x_16_2ND_INPUT_CLOCK        (0xF)


/* AHB PRESCALER */
#define 		AHB_NOT_DEVIDED                 (0x0)
#define 		AHB_DIVIDED_BY_2                (0x8)
#define 		AHB_DIVIDED_BY_4                (0x9)
#define 		AHB_DIVIDED_BY_8                (0xA)
#define 		AHB_DIVIDED_BY_16               (0xB)
#define 		AHB_DIVIDED_BY_64               (0xC)
#define 		AHB_DIVIDED_BY_128              (0xD)
#define 		AHB_DIVIDED_BY_256              (0xE)
#define 		AHB_DIVIDED_BY_512              (0xF)


/* APB1 PRESCALER */
#define 		APB1_NOT_DEVIDED                (0x0)
#define 		APB1_DIVIDED_BY_2               (0x4)
#define 		APB1_DIVIDED_BY_4               (0x5)
#define 		APB1_DIVIDED_BY_8               (0x6)
#define 		APB1_DIVIDED_BY_16              (0x7)


/* APB2 PRESCALER */
#define 		APB2_NOT_DEVIDED                (0x0)
#define 		APB2_DIVIDED_BY_2               (0x4)
#define 		APB2_DIVIDED_BY_4               (0x5)
#define 		APB2_DIVIDED_BY_8               (0x6)
#define 		APB2_DIVIDED_BY_16              (0x7)


/* ADC PRESCALER */
#define 		RCC_ADC_PRESCALER_2				(0x00000000)
#define 		RCC_ADC_PRESCALER_4				(0x00004000)
#define 		RCC_ADC_PRESCALER_6				(0x00008000)
#define 		RCC_ADC_PRESCALER_8				(0x0000C000)


/*PERIPHERALS CLOCK NUMBERS*/
typedef enum
{
	/* RCC AHB PERIPHERALS */
	RCC_DMA1_CLOCK,
	RCC_DMA2_CLOCK,
	RCC_SRAM_CLOCK,
	RCC_FLITF_CLOCK = 4,
	RCC_CRCE_CLOCK  = 6,
	RCC_FSMC_CLOCK  = 8,
	RCC_SDIO_CLOCK  = 10,

	/* RCC APB1ENR PERIPHERALS */
	RCC_TIM2_CLOCK = 0,
	RCC_TIM3_CLOCK,
	RCC_TIM4_CLOCK,
	RCC_TIM5_CLOCK,
	RCC_TIM6_CLOCK,
	RCC_TIM7_CLOCK,
	RCC_TIM12_CLOCK,
	RCC_TIM13_CLOCK,
	RCC_TIM14_CLOCK,
	RCC_WWDGCLOCK = 11,
	RCC_SPI2CLOCK = 14,
	RCC_SPI3CLOCK,
	RCC_USART2_CLOCK = 17,
	RCC_USART3_CLOCK,
	RCC_USART4_CLOCK,
	RCC_USART5_CLOCK,
	RCC_I2C1_CLOCK,
	RCC_I2C2_CLOCK,
	RCC_USB_CLOCK,
	RCC_CAN_CLOCK =25,
	RCC_BKP_CLOCK =27,
	RCC_PWR_CLOCK,
	RCC_DAC_CLOCK,

	/* RCC APB2ENR PERIPHERALS */
	RCC_AFIO_CLOCK  = 0,
	RCC_GPIOA_CLOCK = 2,
	RCC_GPIOB_CLOCK,
	RCC_GPIOC_CLOCK,
	RCC_GPIOD_CLOCK,
	RCC_GPIOE_CLOCK,
	RCC_GPIOF_CLOCK,
	RCC_GPIOG_CLOCK,
	RCC_ADC1_CLOCK = 9,
	RCC_ADC2_CLOCK,
	RCC_TIM1_CLOCK,
	RCC_SPI1_CLOCK,
	RCC_TIM8_CLOCK,
	RCC_USART1_CLOCK,
	RCC_ADC3_CLOCK,
	RCC_TIM9_CLOCK = 19,
	RCC_TIM10_CLOCK,
	RCC_TIM11_CLOCK,
}RCC_Peripheral_t;



/* PRESCALER CONFIGURATION */
typedef struct
{
	uint8 AHB_Prescaler;
	uint8 ABP1_Prescaler;
	uint8 ABP2_Prescaler;
}Buses_Prescaler;


/*PLL CONFIGURATION */
typedef struct
{
	uint8 PLL_Source;
	uint8 PLL_Mul_Factor;
}RCC_PLL_Typedef;


typedef struct
{
	uint8  ClockSource;
	RCC_PLL_Typedef PLL_Config;
	Buses_Prescaler Prescaler;
}RCC_Config_t;




/* prototypes of functions */
void MRCC_voidClockInit(RCC_Config_t *RCC_Config);
void MRCC_voidPeripheralClockEnable(uint8 Copy_u8BusName, RCC_Peripheral_t Copy_u8PeripheralName);
void MRCC_voidPeripheralClockDisable(uint8 Copy_u8BusName, RCC_Peripheral_t Copy_u8PeripheralName);


#endif
