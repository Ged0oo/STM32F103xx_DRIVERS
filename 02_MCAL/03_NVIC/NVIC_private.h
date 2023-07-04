/* 
 * File:   NVIC_PRIVATE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on July 2, 2023, 2:04 PM
 */

#ifndef __NVIC_PRIVATE_H__
#define __NVIC_PRIVATE_H__

#define 		NVIC_BASE_ADDRESS 				(0xE000E100)
#define 		NVIC                			((NVIC_TypeDef*)NVIC_BASE_ADDRESS)
#define 		NVIC_IS_VALID_IRQN(Number)		(Number <= NVIC_N_IRQNS)

#define 		SCB_BASE_ADDRESS 			   	 (0xE000ED00)
#define 		SCB_AIRCR_VECTKEY         	     ((uint32)0x05FA0000)
#define 		SCB         				     ((SCB_TypeDef *)SCB_BASE_ADDRESS )

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
	

typedef struct
{
  volatile uint32 CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  volatile uint32 ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  volatile uint32 VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  volatile uint32 AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  volatile uint32 SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  volatile uint32 CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  volatile uint32 SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  volatile uint32 SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  volatile uint32 CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  volatile uint32 HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  volatile uint32 DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  volatile uint32 MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  volatile uint32 BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  volatile uint32 AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  volatile uint32 PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  volatile uint32 DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  volatile uint32 ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  volatile uint32 MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  volatile uint32 ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
  volatile uint32 RESERVED0[5U];
  volatile uint32 CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
} SCB_TypeDef;


	
#endif  