/* 
 * File:   TEMPLATE_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on MAY 5, 2023, 8:41 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"


static const uint8 btn_values[4][4] =
{
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};


ST_Keypad_t keypad_1 =
{
		.row_pin[0].GPIOx = ROW_PORT,
		.row_pin[0].GPIO_PinNumber = ROW_PIN_0,

		.row_pin[1].GPIOx = ROW_PORT,
		.row_pin[1].GPIO_PinNumber = ROW_PIN_1,

		.row_pin[2].GPIOx = ROW_PORT,
		.row_pin[2].GPIO_PinNumber = ROW_PIN_2,

		.row_pin[3].GPIOx = ROW_PORT,
		.row_pin[3].GPIO_PinNumber = ROW_PIN_3,

		.column_pin[0].GPIOx = COLUMN_PORT,
		.column_pin[0].GPIO_PinNumber = COLUMN_PIN_0,

		.column_pin[1].GPIOx = COLUMN_PORT,
		.column_pin[1].GPIO_PinNumber = COLUMN_PIN_1,

		.column_pin[2].GPIOx = COLUMN_PORT,
		.column_pin[2].GPIO_PinNumber = COLUMN_PIN_2,

		.column_pin[3].GPIOx = COLUMN_PORT,
		.column_pin[3].GPIO_PinNumber = COLUMN_PIN_3
};



void keypad_initialize(ST_Keypad_t *_keypad_obj)
{
    uint8 rows_counter = 0;
    uint8 columns_counter = 0;

	if(NULL == _keypad_obj) return;
	else
	{
		for(rows_counter=0 ; rows_counter<KEYPAD_ROWS ; rows_counter++)
		{
			_keypad_obj->row_pin[rows_counter].GPIO_PinMode = GPIO_OUT;
			_keypad_obj->row_pin[rows_counter].GPIO_Logic = GPIO_LOW;
			MGPIO_voidInitPortPin(&(_keypad_obj->row_pin[rows_counter]));
		}
		for(columns_counter=0 ; columns_counter<KEYPAD_COLUMNS ; columns_counter++)
		{
			_keypad_obj->column_pin[columns_counter].GPIO_PinMode = GPIO_IN;
			MGPIO_voidInitPortPin(&(_keypad_obj->column_pin[columns_counter]));
		}
	}
}


char read_keypad (ST_Keypad_t *_keypad_obj)
{
	uint8 value = NOTPRESSED;
	for(uint8 rows_counter=0 ; rows_counter<KEYPAD_ROWS ; rows_counter++)
	{
		for(uint8 counter=0 ; counter<KEYPAD_ROWS ; counter++)
		{
			MGPIO_voidWritePortPin(&(_keypad_obj->row_pin[counter]), GPIO_HIGH);
		}

		MGPIO_voidWritePortPin(&(_keypad_obj->row_pin[rows_counter]), GPIO_LOW);

		for(uint8 columns_counter=0 ; columns_counter<KEYPAD_COLUMNS ; columns_counter++)
		{
			if( GPIO_LOW == MGPIO_u8ReadPortPin(&(_keypad_obj->column_pin[columns_counter])))
			{
				while (GPIO_LOW == MGPIO_u8ReadPortPin(&(_keypad_obj->column_pin[columns_counter])));
				value = btn_values[rows_counter][columns_counter];
			}
		}
	}
	return value;
}
