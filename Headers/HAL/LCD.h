
#ifndef LCD_H
#define LCD_H
#include "../MCAL/GPIO.h"



/* ----------------- Macro Declarations -----------------*/
#define _LCD_CLEAR                      		 0X01
#define _LCD_RETURN_HOME               			 0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   		 0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON   			 0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   		 0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON   			 0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     		 0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT             0x14
#define _LCD_DISPLAY_SHIFT_LEFT                  0x18
#define _LCD_DISPLAY_SHIFT_RIGHT                 0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE          			 0x38
#define _LCD_4BIT_MODE_2_LINE           		 0x28

#define _LCD_CGRAM_START              			 0x40
#define _LCD_DDRAM_START                         0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4


/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/

typedef struct{
	uint8_t port   		: 3;  //a:f 3bit
	uint8_t pin    		: 3;  //pin >>0:7 3bit
    uint8_t direction   : 1;  //input , output >>0,1 1bit
    uint8_t logic 		: 1;  // high , low>>1,0
}pin_config_t;

typedef struct{
    pin_config_t lcd_rs;       //0>>command ,1>>write data
    pin_config_t lcd_en;       // 1>>enable
    pin_config_t lcd_data[4];  // 4 pins for data
}chr_lcd_4bit_t;


typedef struct{
    pin_config_t lcd_rs;
    pin_config_t lcd_Rw;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];   //8 pins for data
}chr_lcd_8bit_t;



/*-------------------- LCD Initialize ----------------------

chr_lcd_4bit_t lcd1 =
{
    .lcd_en.direction = OUTPUT,
    .lcd_en.port = PORTB_INDEX,
    .lcd_en.pin = PIN1,
    .lcd_en.logic = LOW,
    .lcd_rs.direction = OUTPUT,
    .lcd_rs.port = PORTB_INDEX,
    .lcd_rs.pin = PIN0,
    .lcd_rs.logic = LOW,
    .lcd_data[0].direction = OUTPUT,
    .lcd_data[0].port = PORTB_INDEX,
    .lcd_data[0].pin = PIN2,
    .lcd_data[0].logic = LOW,
    .lcd_data[1].direction = OUTPUT,
    .lcd_data[1].port = PORTB_INDEX,
    .lcd_data[1].pin = PIN3,
    .lcd_data[1].logic = LOW,
    .lcd_data[2].direction = OUTPUT,
    .lcd_data[2].port = PORTB_INDEX,
    .lcd_data[2].pin = PIN4,
    .lcd_data[2].logic = LOW,
    .lcd_data[3].direction = OUTPUT,
    .lcd_data[3].port = PORTB_INDEX,
    .lcd_data[3].pin = PIN5,
    .lcd_data[3].logic = LOW
};

*/


/* ----------------- Software Interfaces Declarations -----------------*/

/** @return Status of the function
 *          (E_OK)     : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType lcd_4bit_intialize(const chr_lcd_4bit_t *lcd);
Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd, uint8_t command);
Std_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd, uint8_t data);
Std_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd,uint8_t row, uint8_t column, uint8_t data);
Std_ReturnType lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8_t *str);
Std_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8_t row, uint8_t column, uint8_t *str);
Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8_t row, uint8_t column, const uint8_t _chr[], uint8_t mem_pos);
//static Std_ReturnType lcd_send_4bits(const chr_lcd_8bit_t *lcd, uint8_t _data_command);


Std_ReturnType lcd_8bit_intialize(const chr_lcd_8bit_t *lcd);
Std_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t *lcd, uint8_t command);
Std_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd, uint8_t data);
Std_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit_t *lcd,uint8_t row, uint8_t column, uint8_t data);
Std_ReturnType lcd_8bit_send_string(const chr_lcd_8bit_t *lcd, uint8_t *str);
Std_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd, uint8_t row, uint8_t column, uint8_t *str);
Std_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd, uint8_t row, uint8_t column,const uint8_t _chr[], uint8_t mem_pos);


Std_ReturnType convert_uint8_to_string (uint8_t value, uint8_t *str);
Std_ReturnType convert_uint16_to_string(uint8_t value, uint8_t *str);
Std_ReturnType convert_uint32_to_string(float value, uint8_t *str);


#endif
