/* 
 * File:   TIMERS_PRIVATE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on Augest 18, 2023, 8:41 PM
 */


#ifndef __TIMERS_PRIVATE_H__
#define __TIMERS_PRIVATE_H__

#define 	TIMER1_BASE_ADDRESS            0x40012C00
#define 	TIMER2_BASE_ADDRESS            0x40000000
#define 	TIMER3_BASE_ADDRESS            0x40000400
#define 	TIMER4_BASE_ADDRESS            0x40000800
#define 	TIMER5_BASE_ADDRESS            0x40000C00
#define 	TIMER6_BASE_ADDRESS            0x40001000
#define 	TIMER7_BASE_ADDRESS            0x40001400
#define 	TIMER8_BASE_ADDRESS            0x40013400
#define 	TIMER9_BASE_ADDRESS            0x40014C00
#define 	TIMER10_BASE_ADDRESS           0x40015000
#define 	TIMER11_BASE_ADDRESS           0x40015400
#define 	TIMER12_BASE_ADDRESS           0x40001800
#define 	TIMER13_BASE_ADDRESS           0x40001C00
#define 	TIMER14_BASE_ADDRESS           0x40002000


typedef struct
{
  volatile uint16 CR1;
  uint16  RESERVED0;

  volatile uint16 CR2;
  uint16  RESERVED1;

  volatile uint16 SMCR;
  uint16  RESERVED2;

  volatile uint16 DIER;
  uint16  RESERVED3;

  volatile uint16 SR;
  uint16  RESERVED4;

  volatile uint16 EGR;
  uint16  RESERVED5;

  volatile uint16 CCMR1;
  uint16  RESERVED6;

  volatile uint16 CCMR2;
  uint16  RESERVED7;

  volatile uint16 CCER;
  uint16  RESERVED8;

  volatile uint16 CNT;
  uint16  RESERVED9;

  volatile uint16 PSC;
  uint16  RESERVED10;

  volatile uint16 ARR;
  uint16  RESERVED11;

  volatile uint16 RCR;
  uint16  RESERVED12;

  volatile uint16 CCR1;
  uint16  RESERVED13;

  volatile uint16 CCR2;
  uint16  RESERVED14;

  volatile uint16 CCR3;
  uint16  RESERVED15;

  volatile uint16 CCR4;
  uint16  RESERVED16;

  volatile uint16 BDTR;
  uint16  RESERVED17;

  volatile uint16 DCR;
  uint16  RESERVED18;

  volatile uint16 DMAR;
  uint16  RESERVED19;
} TIM_TypeDef;



#define 	TIMER1           ((TIM_TypeDef*)TIMER1_BASE_ADDRESS)
#define 	TIMER2           ((TIM_TypeDef*)TIMER2_BASE_ADDRESS)
#define 	TIMER3           ((TIM_TypeDef*)TIMER3_BASE_ADDRESS)
#define 	TIMER4           ((TIM_TypeDef*)TIMER4_BASE_ADDRESS)
#define 	TIMER5           ((TIM_TypeDef*)TIMER5_BASE_ADDRESS)
#define 	TIMER6           ((TIM_TypeDef*)TIMER6_BASE_ADDRESS)
#define 	TIMER7           ((TIM_TypeDef*)TIMER7_BASE_ADDRESS)
#define 	TIMER8           ((TIM_TypeDef*)TIMER8_BASE_ADDRESS)
#define 	TIMER9           ((TIM_TypeDef*)TIMER9_BASE_ADDRESS)
#define 	TIMER10          ((TIM_TypeDef*)TIMER10_BASE_ADDRESS)
#define 	TIMER11          ((TIM_TypeDef*)TIMER11_BASE_ADDRESS)
#define 	TIMER12          ((TIM_TypeDef*)TIMER12_BASE_ADDRESS)
#define 	TIMER13          ((TIM_TypeDef*)TIMER13_BASE_ADDRESS)
#define 	TIMER14          ((TIM_TypeDef*)TIMER14_BASE_ADDRESS)


#endif  __TIMERS_PRIVATE_H__
