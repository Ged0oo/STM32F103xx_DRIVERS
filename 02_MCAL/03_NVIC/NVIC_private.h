/* 
 * File:   NVIC_PRIVATE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on July 2, 2023, 2:04 PM
 */


#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__


#define 		NVIC_BASE_ADDRESS 				   (0xE000E100)
#define 		NVIC                			   ((NVIC_TypeDef*)NVIC_BASE_ADDRESS)
#define 		NVIC_IS_VALID_IRQN(Number)		   (Number <= NVIC_N_IRQNS)


typedef struct
{
	volatile uint32 ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
	uint32 RESERVED0[24U];
	
	volatile uint32 ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
	uint32 RSERVED1[24U];
	
	volatile uint32 ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
	uint32 RESERVED2[24U];
	
	volatile uint32 ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
	uint32 RESERVED3[24U];
	
	volatile uint32 IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
	uint32 RESERVED4[56U];
	
	volatile uint8  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
	uint32 RESERVED5[644U];
	
	volatile  uint32 STIR;                  /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}NVIC_TypeDef;


#endif
