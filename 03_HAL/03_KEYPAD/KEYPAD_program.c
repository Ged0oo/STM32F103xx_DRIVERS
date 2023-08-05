/* 
 * File:   TEMPLATE_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on MAY 5, 2023, 8:41 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "KEYPAD_interface.h"


static const uint8 btn_values[4][4] =
{
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'#', '0', '=', '+'}
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

	if(NULL == _keypad_obj)
	{
		return;
	}
	else
	{
		for(rows_counter=0 ; rows_counter<ECU_KEYPAD_ROWS ; rows_counter++)
		{
			_keypad_obj->row_pin[rows_counter].GPIO_PinMode = GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_10MHZ;
			_keypad_obj->row_pin[rows_counter].GPIO_Logic = GPIO_LOW;
			MGPIO_voidInitPortPin(&(_keypad_obj->row_pin[rows_counter]));
		}
		for(columns_counter=0 ; columns_counter<ECU_KEYPAD_COLUMNS ; columns_counter++)
		{
			_keypad_obj->column_pin[columns_counter].GPIO_PinMode = GPIO_PIN_INPUT_PULLUP_DOWN_MODE;
			_keypad_obj->column_pin[columns_counter].GPIO_Logic = GPIO_LOW;
			MGPIO_voidInitPortPin(&(_keypad_obj->column_pin[columns_counter]));
		}
	}
}



void keypad_get_value(ST_Keypad_t *_keypad_obj, uint8 *value)
{
	uint8 l_rows_counter = 0;
	uint8 l_columns_counter = 0;
	uint8 l_counter = 0;
	uint8 column_logic = 0;
	if(NULL == _keypad_obj)
	{
		return;
	}
	else
	{
		for(l_rows_counter=0 ; l_rows_counter<ECU_KEYPAD_ROWS ; l_rows_counter++)
		{
			for(l_counter=0 ; l_counter<ECU_KEYPAD_ROWS ; l_counter++)
			{
				GPIO_voidWritePortPin(&(_keypad_obj->row_pin[l_counter]), GPIO_LOW);
			}

			GPIO_voidWritePortPin(&(_keypad_obj->row_pin[l_rows_counter]), GPIO_HIGH);
			//__delay_ms(10);
			for(uint32 i=0 ; i<5500 ; i++);
			for(l_columns_counter=0 ; l_columns_counter<ECU_KEYPAD_COLUMNS ; l_columns_counter++)
			{
				column_logic = GPIO_u8ReadPortPin(&(_keypad_obj->column_pin[l_rows_counter]));
				if(GPIO_HIGH == column_logic)
				{
					*value = btn_values[l_rows_counter][l_columns_counter];
				}
			}
		}

	}
}
