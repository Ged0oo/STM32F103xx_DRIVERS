/* 
 * File:   NVIC_INTERFACE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on July 2, 2023, 2:04 PM
 */


#ifndef __NVIC_INTERFACE_H__
#define __NVIC_INTERFACE_H__
	

/*NVIC interrupt indexes*/
typedef enum
{
	/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
	NonMaskableInt_IRQnumum       = -14,    /*!< 2 Non Maskable Interrupt                             */
	MemoryManagement_IRQnum       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
	BusFault_IRQnum               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
	UsageFault_IRQnum             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
	SVCall_IRQnum                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
	DebugMonitor_IRQnum           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
	PendSV_IRQnum                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
	SysTick_IRQnum                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */
	/******  STM32 specific Interrupt Numbers *********************************************************/
	WWDG_IRQnum                   = 0,      /*!< Window WatchDog Interrupt                            */
	PVD_IRQnum                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
	TAMPER_IRQnum                 = 2,      /*!< Tamper Interrupt                                     */
	RTC_IRQnum                    = 3,      /*!< RTC global Interrupt                                 */
	FLASH_IRQnum                  = 4,      /*!< FLASH global Interrupt                               */
	RCC_IRQnum                    = 5,      /*!< RCC global Interrupt                                 */
	EXTI0_IRQnum                  = 6,      /*!< EXTI Line0 Interrupt                                 */
	EXTI1_IRQnum                  = 7,      /*!< EXTI Line1 Interrupt                                 */
	EXTI2_IRQnum                  = 8,      /*!< EXTI Line2 Interrupt                                 */
	EXTI3_IRQnum                  = 9,      /*!< EXTI Line3 Interrupt                                 */
	EXTI4_IRQnum                  = 10,     /*!< EXTI Line4 Interrupt                                 */
	DMA1_Channel1_IRQnum          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
	DMA1_Channel2_IRQnum          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
	DMA1_Channel3_IRQnum          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
	DMA1_Channel4_IRQnum          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
	DMA1_Channel5_IRQnum          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
	DMA1_Channel6_IRQnum          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
	DMA1_Channel7_IRQnum          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
	ADC1_2_IRQnum                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
	USB_HP_CAN1_TX_IRQnum         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
	USB_LP_CAN1_RX0_IRQnum        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
	CAN1_RX1_IRQnum               = 21,     /*!< CAN1 RX1 Interrupt                                   */
	CAN1_SCE_IRQnum               = 22,     /*!< CAN1 SCE Interrupt                                   */
	EXTI9_5_IRQnum                = 23,     /*!< External Line[9:5] Interrupts                        */
	TIM1_BRK_IRQnum               = 24,     /*!< TIM1 Break Interrupt                                 */
	TIM1_UP_IRQnum                = 25,     /*!< TIM1 Update Interrupt                                */
	TIM1_TRG_COM_IRQnum           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
	TIM1_CC_IRQnum                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
	TIM2_IRQnum                   = 28,     /*!< TIM2 global Interrupt                                */
	TIM3_IRQnum                   = 29,     /*!< TIM3 global Interrupt                                */
	TIM4_IRQnum                   = 30,     /*!< TIM4 global Interrupt                                */
	I2C1_EV_IRQnum                = 31,     /*!< I2C1 Event Interrupt                                 */
	I2C1_ER_IRQnum                = 32,     /*!< I2C1 Error Interrupt                                 */
	I2C2_EV_IRQnum                = 33,     /*!< I2C2 Event Interrupt                                 */
	I2C2_ER_IRQnum                = 34,     /*!< I2C2 Error Interrupt                                 */
	SPI1_IRQnum                   = 35,     /*!< SPI1 global Interrupt                                */
	SPI2_IRQnum                   = 36,     /*!< SPI2 global Interrupt                                */
	USART1_IRQnum                 = 37,     /*!< USART1 global Interrupt                              */
	USART2_IRQnum                 = 38,     /*!< USART2 global Interrupt                              */
	USART3_IRQnum                 = 39,     /*!< USART3 global Interrupt                              */
	EXTI15_10_IRQnum              = 40,     /*!< External Line[15:10] Interrupts                      */
	RTCAlarm_IRQnum               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
	USBWakeUp_IRQnum              = 42      /*!< USB Device WakeUp from suspend EXTI Line Interrupt   */
}IRQnum_t;


/*Group priority options*/
#define NVIC_PRIORITY_GROUP_0              ((uint32)0x300)
#define NVIC_PRIORITY_GROUP_1			   ((uint32)0x400)
#define NVIC_PRIORITY_GROUP_2			   ((uint32)0x500)
#define NVIC_PRIORITY_GROUP_3			   ((uint32)0x600)
#define NVIC_PRIORITY_GROUP_4              ((uint32)0x700)

/*!<
 The table below gives the allowed values of the pre-emption priority and subpriority according
 to the Priority Grouping configuration performed by NVIC_PriorityGroupConfig function
  ========================================================================================================
    NVIC_PriorityGroup   | NVIC_IRQChannelPreemptionPriority | NVIC_IRQChannelSubPriority  | Description
  ========================================================================================================
   NVIC_PRIORITY_GROUP_0  |    0-15   |    0      |   0 bits for pre-emption priority
                          |           |           |   4 bits for subpriority
  --------------------------------------------------------------------------------------------------------
   NVIC_PRIORITY_GROUP_1  |    0-7    |    0-1    |   1 bits for pre-emption priority
                          |           |           |   3 bits for subpriority
  --------------------------------------------------------------------------------------------------------
   NVIC_PRIORITY_GROUP_2  |    0-3    |    0-3    |   2 bits for pre-emption priority
                          |           |           |   2 bits for subpriority
  --------------------------------------------------------------------------------------------------------
   NVIC_PRIORITY_GROUP_3  |    0-1    |    0-7    |   3 bits for pre-emption priority
                          |           |           |   1 bits for subpriority
  --------------------------------------------------------------------------------------------------------
   NVIC_PRIORITY_GROUP_4  |    0      |    0-15   |   4 bits for pre-emption priority
                          |           |           |   0 bits for subpriority
  ========================================================================================================
 */
 
	
void NVIC_xEnableInterrupt(IRQnum_t Copy_xIntIndex);
void NVIC_xDisableInterrupt(IRQnum_t Copy_xIntIndex);

void NVIC_xSetPendingFlag(IRQnum_t Copy_xIntIndex);
void NVIC_xClearPendingFlag(IRQnum_t Copy_xIntIndex);

void NVIC_xReadIntState(IRQnum_t Copy_xIntIndex, uint8 *pu8IntState);
IRQnum_t NVIC_xCheck_CurrentInt(void);

void NVIC_xSetPriority(IRQnum_t Copy_xIntIndex , uint8 Copy_u8GroupPriority , uint8 Copy_u8SubPriority);
void NVIC_vPriorityGroupInit(uint32 Copy_u32PriorityGroup);
	
#endif  