/* 
 * File:   LCD_INTERFACE.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo 
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on MAY 5, 2023, 8:41 PM
 */


#ifndef __LCD_INTERFACE_H__
#define __LCD_INTERFACE_H__


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "LCD_config.h"
#include "GPIO_interface.h"


#define 			_LCD_CLEAR                      					0X01
#define 			_LCD_RETURN_HOME                					0x02
#define 			_LCD_ENTRY_MODE_DEC_SHIFT_OFF   					0x04
#define 			_LCD_ENTRY_MODE_DEC_SHIFT_ON    					0x05
#define 			_LCD_ENTRY_MODE_INC_SHIFT_OFF   					0x06
#define 			_LCD_ENTRY_MODE_INC_SHIFT_ON    					0x07
#define 			_LCD_CURSOR_MOVE_SHIFT_LEFT     					0x10
#define 			_LCD_CURSOR_MOVE_SHIFT_RIGHT    					0x14
#define 			_LCD_DISPLAY_SHIFT_LEFT         					0x18
#define 			_LCD_DISPLAY_SHIFT_RIGHT        					0x1C
#define 			_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 			0x0C
#define 			_LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  			0x0D
#define 			_LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  			0x0E
#define 			_LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   			0x0F
#define 			_LCD_DISPLAY_OFF_CURSOR_OFF              			0x08
#define 			_LCD_8BIT_MODE_2_LINE           					0x38
#define 			_LCD_4BIT_MODE_2_LINE           					0x28

#define 			_LCD_CGRAM_START                					0x40
#define 			_LCD_DDRAM_START                					0x80

#define 			ROW1 												1
#define 			ROW2 												2
#define 			ROW3 												3
#define 			ROW4 												4


typedef struct
{
	GPIO_ConfigType lcd_rs;
	GPIO_ConfigType lcd_en;
    GPIO_ConfigType lcd_data[4];
}chr_lcd_4bit_t;


void lcd_4bit_intialize(chr_lcd_4bit_t *lcd);

void lcd_4bit_send_command(chr_lcd_4bit_t *lcd, uint8 command);
void lcd_4bit_send_custom_char(chr_lcd_4bit_t *lcd, uint8 row, uint8 column, uint8 _chr[], uint8 mem_pos);

void lcd_4bit_send_char_data(chr_lcd_4bit_t *lcd, uint8 data);
void lcd_4bit_send_char_data_pos(chr_lcd_4bit_t *lcd,uint8 row, uint8 column, uint8 data);

void lcd_4bit_send_string(chr_lcd_4bit_t *lcd, uint8 *str);
void lcd_4bit_send_string_pos(chr_lcd_4bit_t *lcd, uint8 row, uint8 column, uint8 *str);

void LCD_Clear(void);
void LCD_WriteNumber_Position(uint32 Number, uint8 row, uint8 column);



#endif
