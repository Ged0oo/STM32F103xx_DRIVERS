/* 
 * File:   LCD_PROGRAM.c
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on MAY 5, 2023, 8:41 PM
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LCD_interface.h"
#include "LCD_config.h"


static void lcd_send_4bits(chr_lcd_4bit_t *lcd, uint8 _data_command);
static void lcd_4bit_send_enable_signal(chr_lcd_4bit_t *lcd);
static void lcd_4bit_set_cursor(chr_lcd_4bit_t *lcd, uint8 row, uint8 coulmn);



chr_lcd_4bit_t lcd_1 =
{
	.lcd_rs.GPIOx = LCD_PORT,
	.lcd_rs.GPIO_PinNumber = LCD_RS_PIN,

	.lcd_rw.GPIOx = LCD_PORT,
	.lcd_rw.GPIO_PinNumber = LCD_RW_PIN,

	.lcd_en.GPIOx = LCD_PORT,
	.lcd_en.GPIO_PinNumber = LCD_EN_PIN,

	.lcd_data[0].GPIOx = LCD_PORT,
	.lcd_data[0].GPIO_PinNumber = LCD_DATA_4,

	.lcd_data[1].GPIOx = LCD_PORT,
	.lcd_data[1].GPIO_PinNumber = LCD_DATA_5,

	.lcd_data[2].GPIOx = LCD_PORT,
	.lcd_data[2].GPIO_PinNumber = LCD_DATA_6,

	.lcd_data[3].GPIOx = LCD_PORT,
	.lcd_data[3].GPIO_PinNumber = LCD_DATA_7
};



void lcd_4bit_intialize(chr_lcd_4bit_t *lcd)
{
	uint8 l_data_pins_counter = 0;
	if(NULL == lcd)
	{
		return;
	}
	else
	{
		lcd->lcd_rs.GPIO_PinMode = GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_2MHZ;
		lcd->lcd_rw.GPIO_PinMode = GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_2MHZ;
		lcd->lcd_en.GPIO_PinMode = GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_2MHZ;

		lcd->lcd_rs.GPIO_Logic = GPIO_LOW;
		lcd->lcd_rw.GPIO_Logic = GPIO_LOW;
		lcd->lcd_en.GPIO_Logic = GPIO_LOW;

		MGPIO_voidInitPortPin(&(lcd->lcd_rs));
		MGPIO_voidInitPortPin(&(lcd->lcd_rw));
		MGPIO_voidInitPortPin(&(lcd->lcd_en));

		for(l_data_pins_counter=0 ; l_data_pins_counter<4 ; l_data_pins_counter++)
		{
			lcd->lcd_data[l_data_pins_counter].GPIO_PinMode = GPIO_PIN_GENERAL_PURPOSE_OUTPUT_PUSHPULL_MODE_2MHZ;
			lcd->lcd_data[l_data_pins_counter].GPIO_Logic = GPIO_LOW;
			MGPIO_voidInitPortPin(&(lcd->lcd_data[l_data_pins_counter]));
		}

		//__delay_ms(20);
		for(uint32 i=0 ; i<11000 ; i++) asm("NOP");
		lcd_4bit_send_command(lcd, 0x33);
		lcd_4bit_send_command(lcd, 0x32);
		lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
		lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
		lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
		lcd_4bit_send_command(lcd, _LCD_DDRAM_START);
		lcd_4bit_send_command(lcd, _LCD_CLEAR);

	}
}

void lcd_4bit_send_command(chr_lcd_4bit_t *lcd, uint8 command)
{
	if(NULL == lcd)
	{
		return;
	}
	else
	{
		MGPIO_voidWritePortPin(&(lcd->lcd_rs), GPIO_LOW);
		MGPIO_voidWritePortPin(&(lcd->lcd_rw), GPIO_LOW);
		lcd_send_4bits(lcd, command >> 4);
		lcd_4bit_send_enable_signal(lcd);
		lcd_send_4bits(lcd, command);
		lcd_4bit_send_enable_signal(lcd);
	}
}


void lcd_4bit_send_custom_char(chr_lcd_4bit_t *lcd, const uint8 _chr[], uint8 row, uint8 column, uint8 mem_pos)
{
	uint8 lcd_counter = 0;
	if(NULL == lcd)
	{
		return;
	}
	else
	{
		lcd_4bit_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*8)));
		for(lcd_counter=0; lcd_counter<=7 ; ++lcd_counter)
		{
			lcd_4bit_send_char_data(lcd, _chr[lcd_counter]);
		}
		lcd_4bit_send_char_data_pos(lcd, row, column, mem_pos);
	}
}

void lcd_4bit_send_char_data(chr_lcd_4bit_t *lcd, uint8 data)
{
	if(NULL == lcd)
	{
		return;
	}
	else
	{
		MGPIO_voidWritePortPin(&(lcd->lcd_rs), GPIO_HIGH);
		MGPIO_voidWritePortPin(&(lcd->lcd_rw), GPIO_LOW);
		lcd_send_4bits(lcd, data >> 4);
		lcd_4bit_send_enable_signal(lcd);
		lcd_send_4bits(lcd, data);
		lcd_4bit_send_enable_signal(lcd);
	}
}


void lcd_4bit_send_char_data_pos(chr_lcd_4bit_t *lcd,uint8 row, uint8 column, uint8 data)
{
	if(NULL == lcd)
	{
		return;
	}
	else
	{
		lcd_4bit_set_cursor(lcd, row, column);
		lcd_4bit_send_char_data(lcd, data);
	}
}



void lcd_4bit_send_string(chr_lcd_4bit_t *lcd, uint8 *str)
{
	if(NULL == lcd)
	{
		return;
	}
	else
	{
		while(*str)
		{
			lcd_4bit_send_char_data(lcd, *str++);
		}
	}
}


void lcd_4bit_send_string_pos(chr_lcd_4bit_t *lcd, uint8 row, uint8 column, uint8 *str)
{
	if(NULL == lcd)
	{
		return;
	}
	else
	{
		lcd_4bit_set_cursor(lcd, row, column);
		while(*str)
		{
			lcd_4bit_send_char_data(lcd, *str++);
		}
	}
}


void LCD_Clear(chr_lcd_4bit_t *lcd)
{
	lcd_4bit_send_command(lcd, _LCD_CLEAR);
}


void LCD_WriteNumber_Position(uint32 Number, uint8 row, uint8 column)
{
	column--;
	uint8 i=0, arr[10], j;
	if(Number==0) lcd_4bit_send_char_data_pos(&lcd_1, row, column, '0');
	else
	{
		while(Number)
		{
			arr[i]= Number%10 +'0';
			Number /= 10;
			i++;
		}
		for(j=i ; j>0 ;j--)
		{
			lcd_4bit_send_char_data_pos(&lcd_1, row, ++column, arr[j-1]);
		}
	}

}


static void lcd_send_4bits(chr_lcd_4bit_t *lcd, uint8 _data_command)
{
	GPIO_voidWritePortPin(&(lcd->lcd_data[0]), (_data_command >> 0) & (uint8)0x01);
	GPIO_voidWritePortPin(&(lcd->lcd_data[1]), (_data_command >> 1) & (uint8)0x01);
	GPIO_voidWritePortPin(&(lcd->lcd_data[2]), (_data_command >> 2) & (uint8)0x01);
	GPIO_voidWritePortPin(&(lcd->lcd_data[3]), (_data_command >> 3) & (uint8)0x01);
}


static void lcd_4bit_send_enable_signal(chr_lcd_4bit_t *lcd)
{
	GPIO_voidWritePortPin(&(lcd->lcd_en), GPIO_HIGH);
	//__delay_us(5);
	for(uint8 i=0 ; i<10 ; i++);
	GPIO_voidWritePortPin(&(lcd->lcd_en), GPIO_LOW);
	for(uint16 i=0 ; i<2000 ; i++);
}


static void lcd_4bit_set_cursor(chr_lcd_4bit_t *lcd, uint8 row, uint8 coulmn)
{
    coulmn--;
    switch(row)
    {
        case ROW1 :
        	lcd_4bit_send_command(lcd, (0x80 + coulmn));
        	break;

        case ROW2 :
        	lcd_4bit_send_command(lcd, (0xc0 + coulmn));
        	break;

        case ROW3 :
        	lcd_4bit_send_command(lcd, (0x94 + coulmn));
        	break;

        case ROW4 :
        	lcd_4bit_send_command(lcd, (0xd4 + coulmn));
        	break;

        default : ;
    }
}
