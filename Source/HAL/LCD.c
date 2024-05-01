#include "../../Headers/HAL/LCD.h"

/*---------------------------Static Helper Functions----------------------------*/
static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8_t _data_command);
static Std_ReturnType lcd_send_8_bits(const chr_lcd_8bit_t *lcd, uint8_t _data_command);

static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd);
static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd, uint8_t row, uint8_t coulmn);

static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd);
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd, uint8_t row, uint8_t coulmn);

/*---------------------------Implementations of the Functions----------------------------*/

Std_ReturnType lcd_4bit_intialize(const chr_lcd_4bit_t *lcd){
    Std_ReturnType ret = E_OK;    //test
    uint8_t l_counter =0;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        gpio_digital_port_init(lcd->lcd_rs.port , lcd->lcd_rs.pin , lcd->lcd_rs.direction);
        gpio_digital_port_init(lcd->lcd_en.port , lcd->lcd_en.pin , lcd->lcd_en.direction);
        for(; l_counter<4; l_counter++){
            gpio_digital_port_init(lcd->lcd_data[l_counter].port , lcd->lcd_data[l_counter].pin , lcd->lcd_data[l_counter].direction);
        }
        delay_ms(20);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        delay_ms(5);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        delay_us(150);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);

        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd, 0x80);
    }
    return ret;
}


Std_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd, uint8_t command){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
        /* Set RS pin to low for command --> RS = 0 */
        gpio_digital_port_write(lcd->lcd_rs.port , lcd->lcd_rs.pin , LOW);
        /* Send the Command through the (4-Pins" Data lines */
        ret &= lcd_4bit_send_enable_signal(lcd);
        /* Send the Command through the (4-Pins" Data lines */
        ret &= lcd_send_4bits(lcd, command);
        /* Send the Enable Signal on the "E" Pin */
        ret &= lcd_4bit_send_enable_signal(lcd);
    }
    return ret;
}



Std_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd, uint8_t data){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /**< Set RS pin to high for data --> RS = 1 */
        gpio_digital_port_write(lcd->lcd_rs.port , lcd->lcd_rs.pin , HIGH);
        /** Set RW pin to low for write  --> RW = 0 *//////
        /* Send the data through the 4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, data >> 4);
        /* Send the Enable Signal  */
        ret = lcd_4bit_send_enable_signal(lcd);
        /* Send the data through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, data);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);

    }
    return ret;
}


Std_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd,uint8_t row, uint8_t column, uint8_t data){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bit_set_cursor(lcd, row, column);
        ret = lcd_4bit_send_char_data(lcd, data);
    }
    return ret;
}


Std_ReturnType lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8_t *str){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd || str==NULL){
        ret = E_NOT_OK;
    }
    else{
        uint8_t Local_u8Counter = 0;
        while(str[Local_u8Counter]!='\0')
        {
           lcd_4bit_send_char_data(lcd ,str[Local_u8Counter]);
            Local_u8Counter++;
        }

    }
    return ret;
}


Std_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8_t row, uint8_t column, uint8_t *str){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd || str==NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bit_set_cursor(lcd, row, column);
        while(*str){
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}


Std_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8_t row, uint8_t column, const uint8_t _chr[], uint8_t mem_pos){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{

    }
    return ret;
}



Std_ReturnType lcd_8bit_intialize(const chr_lcd_8bit_t *lcd){
    Std_ReturnType ret = E_OK;
    uint8_t l_counter =0;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        gpio_digital_port_init(lcd->lcd_rs.port , lcd->lcd_rs.pin , lcd->lcd_rs.direction);
        gpio_digital_port_init(lcd->lcd_en.port , lcd->lcd_en.pin , lcd->lcd_en.direction);
        for(; l_counter<8; l_counter++){
            gpio_digital_port_init(lcd->lcd_data[l_counter].port , lcd->lcd_data[l_counter].pin , lcd->lcd_data[l_counter].direction );
        }
        delay_ms(20);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        delay_ms(5);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        delay_us(150);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);

        ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd, 0x80);
    }
    return ret;
}


Std_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t *lcd, uint8_t command){
    Std_ReturnType ret = E_OK;
    uint8_t l_counter =0 ;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
        /* Set RS pin to low for command --> RS = 0 */
        gpio_digital_port_write(lcd->lcd_rs.port , lcd->lcd_rs.pin , LOW);
        /* Send the Command through the "8-Pins" Data lines */
        ret = lcd_send_8_bits(lcd, command);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_8bit_send_enable_signal(lcd);
    }
    return ret;
}


Std_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd, uint8_t data){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{

        /* Set RS pin to low for command --> RS = 1 */
        gpio_digital_port_write(lcd->lcd_rs.port , lcd->lcd_rs.pin , HIGH);
        /* Send the Command through the "8-Pins" Data lines */
        ret = lcd_send_8_bits(lcd, data);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_8bit_send_enable_signal(lcd);

    }
    return ret;
}


Std_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit_t *lcd,uint8_t row, uint8_t column, uint8_t data){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bit_set_cursor(lcd, row, column);
        ret = lcd_8bit_send_char_data(lcd, data);
    }
    return ret;
}


Std_ReturnType lcd_8bit_send_string(const chr_lcd_8bit_t *lcd, uint8_t *str){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd || str==NULL){
        ret = E_NOT_OK;
    }
    else{
        uint8_t Local_u8Counter = 0;
        while(str[Local_u8Counter]!='\0')
        {
           lcd_8bit_send_char_data(lcd ,str[Local_u8Counter]);
            Local_u8Counter++;
        }
    }
    return ret;
}


Std_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd, uint8_t row, uint8_t column, uint8_t *str){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd || str==NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bit_set_cursor(lcd, row, column);
        ret = lcd_8bit_send_string(lcd, str);
    }
    return ret;
}


Std_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd, uint8_t row, uint8_t column,const uint8_t _chr[], uint8_t mem_pos){
    Std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{

    }
    return ret;
}



Std_ReturnType convert_uint8_to_string (uint8_t value, uint8_t *str);
Std_ReturnType convert_uint16_to_string(uint8_t value, uint8_t *str);
Std_ReturnType convert_uint32_to_string(uint8_t value, uint8_t *str);



static Std_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8_t _data_command){
    Std_ReturnType ret = E_OK;
    //gpio_digital_port_init(lcd->lcd_data[0]->port , lcd->lcd_data[0]->pin, lcd->lcd_data[0]->direction);
    gpio_digital_port_write(lcd->lcd_data[0].port, lcd->lcd_data[0].pin, (_data_command >> 0) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[1].port, lcd->lcd_data[1].pin, (_data_command >> 1) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[2].port, lcd->lcd_data[2].pin, (_data_command >> 2) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[3].port, lcd->lcd_data[3].pin, (_data_command >> 3) & (uint8_t)0x01);

    return ret;
}


static Std_ReturnType lcd_send_8_bits(const chr_lcd_8bit_t *lcd, uint8_t _data_command){
   Std_ReturnType ret = E_OK;
    gpio_digital_port_write(lcd->lcd_data[0].port, lcd->lcd_data[0].pin, (_data_command >> 0) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[1].port, lcd->lcd_data[1].pin, (_data_command >> 1) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[2].port, lcd->lcd_data[2].pin, (_data_command >> 2) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[3].port, lcd->lcd_data[3].pin, (_data_command >> 3) & (uint8_t)0x01);
	  gpio_digital_port_write(lcd->lcd_data[4].port, lcd->lcd_data[4].pin, (_data_command >> 4) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[5].port, lcd->lcd_data[5].pin, (_data_command >> 5) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[6].port, lcd->lcd_data[6].pin, (_data_command >> 6) & (uint8_t)0x01);
    gpio_digital_port_write(lcd->lcd_data[7].port, lcd->lcd_data[7].pin, (_data_command >> 7) & (uint8_t)0x01);

  	return ret;
}






static Std_ReturnType lcd_4bit_send_enable_signal(const chr_lcd_4bit_t *lcd){
    Std_ReturnType ret = E_OK;
    gpio_digital_port_write(lcd->lcd_en.port, lcd->lcd_en.pin, HIGH);
    delay_us(50);
    gpio_digital_port_write(lcd->lcd_en.port, lcd->lcd_en.pin, LOW);
    return ret;
}


static Std_ReturnType lcd_8bit_send_enable_signal(const chr_lcd_8bit_t *lcd){
    Std_ReturnType ret = E_OK;
    gpio_digital_port_write(lcd->lcd_en.port, lcd->lcd_en.pin, HIGH);
    delay_us(50);
    gpio_digital_port_write(lcd->lcd_en.port, lcd->lcd_en.pin, LOW);
    return ret;
}

/**
 *
 * @param lcd Pointer to the LCD configuration parameters defined by the user
 * @param row Which row you need to print your character
 * @param coulmn Which column you need to print your character
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static Std_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd, uint8_t row, uint8_t coulmn){
    Std_ReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_8bit_send_command(lcd, (0x80 + coulmn)); break;
        case ROW2 : ret = lcd_8bit_send_command(lcd, (0xc0 + coulmn)); break;
        case ROW3 : ret = lcd_8bit_send_command(lcd, (0x94 + coulmn)); break;
        case ROW4 : ret = lcd_8bit_send_command(lcd, (0xd4 + coulmn)); break;
        default : ;
    }
    return ret;
}

static Std_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd, uint8_t row, uint8_t coulmn){
    Std_ReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_4bit_send_command(lcd, (0x80 + coulmn)); break;
        case ROW2 : ret = lcd_4bit_send_command(lcd, (0xc0 + coulmn)); break;
        case ROW3 : ret = lcd_4bit_send_command(lcd, (0x94 + coulmn)); break;
        case ROW4 : ret = lcd_4bit_send_command(lcd, (0xd4 + coulmn)); break;
        default : ;
    }
    return ret;
} 
 //int main(){}





