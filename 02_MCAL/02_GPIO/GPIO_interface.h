/* 
 * File:   GPIO_INTERFACE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */


#ifndef __GPIO_INTERFACE_H__
#define __GPIO_INTERFACE_H__

#include "GPIO_private.h"
#include "GPIO_config.h"

/*GPIO INPUT MODE CONFEGURATIONS */
#define 		GPIO_PIN_INPUT_ANALOG_MODE                 (0x0)
#define 		GPIO_PIN_INPUT_FLOATING_MODE               (0x4)
#define 		GPIO_PIN_INPUT_PULLUP_DOWN_MODE            (0x8)


/*GPIO CONFEGURATIONS FOR SPEED 50 MHZ*/
#define 		GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_50MHZ            		(0x3)
#define 		GPIO_PIN_OUTPUT_OPENDRAIN_MODE_50MHZ              			   		(0x7)
#define 		GPIO_PIN_ALTERANTIVE_FUNCTION_OUTPUT_PUSHPULL_MODE_50MHZ           	(0xB)
#define 		GPIO_PIN_ALTERANTIVE_FUNCTION_OUTPUT_OPENDRAIN_MODE_50MHZ          	(0xF)


/*GPIO CONFEGURATIONS FOR SPEED 10 MHZ*/
#define 		GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_10MHZ            		(0x1)
#define 		GPIO_PIN_OUTPUT_OPENDRAIN_MODE_10MHZ              			   		(0x5)
#define 		GPIO_PIN_ALTERANTIVE_FUNCTION_OUTPUT_PUSHPULL_MODE_10MHZ           	(0x9)
#define 		GPIO_PIN_ALTERANTIVE_FUNCTION_OUTPUT_OPENDRAIN_MODE_10MHZ          	(0xD)


/*GPIO CONFEGURATIONS FOR SPEED 2 MHZ*/
#define 		GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_2MHZ            		(0x2)
#define 		GPIO_PIN_OUTPUT_OPENDRAIN_MODE_2MHZ              			   		(0x6)
#define 		GPIO_PIN_ALTERANTIVE_FUNCTION_OUTPUT_PUSHPULL_MODE_2HZ           	(0xA)
#define 		GPIO_PIN_ALTERANTIVE_FUNCTION_OUTPUT_OPENDRAIN_MODE_2MHZ          	(0xE)


/*GPIO PIN NUMBERING */
#define 		GPIO_PIN_0				(0)
#define 		GPIO_PIN_1              (1)
#define 		GPIO_PIN_2              (2)
#define 		GPIO_PIN_3              (3)
#define 		GPIO_PIN_4              (4)
#define 		GPIO_PIN_5              (5)
#define 		GPIO_PIN_6              (6)
#define 		GPIO_PIN_7              (7)
#define 		GPIO_PIN_8              (8)
#define 		GPIO_PIN_9              (9)
#define 		GPIO_PIN_10             (10)
#define 		GPIO_PIN_11             (11)
#define 		GPIO_PIN_12             (12)
#define 		GPIO_PIN_13             (13)
#define 		GPIO_PIN_14             (14)
#define 		GPIO_PIN_15             (15)

/* GPIO DIRECTION CONFEGURATIONS */
#define 		GPIO_OUT				(GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_10MHZ)
#define 		GPIO_IN                 (GPIO_PIN_INPUT_PULLUP_DOWN_MODE)

/* GPIO LEVEL CONFEGURATIONS */
#define 		GPIO_HIGH               (1)
#define 		GPIO_LOW                (0)

/* GPIO LOCK CONFEGURATIONS */
#define 		GPIO_LCK                (1)
#define 		GPIO_UNLCK              (0)


/* GPIO STRUCT CONFEGURATIONS */
typedef struct
{
	GPIO_t *GPIOx;
	uint8 GPIO_PinNumber;
	uint8 GPIO_PinMode;
	uint8 GPIO_Logic;
}GPIO_ConfigType;


/* GPIO APIs PROTOTYPES */
void GPIO_voidInitPortPin(GPIO_ConfigType *_gpio);

void GPIO_voidWritePortPin(GPIO_ConfigType *_gpio , uint8 Copy_u8Val);
uint8 GPIO_u8ReadPortPin(GPIO_ConfigType *_gpio);

void GPIO_voidLockPin(GPIO_ConfigType *_gpio , uint8 Copy_u8LockState);
uint8 GPIO_u8ReadLockPinState(GPIO_ConfigType *_gpio);


#endif
