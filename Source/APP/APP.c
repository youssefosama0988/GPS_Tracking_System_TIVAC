#include "../../Headers/MCAL/GPIO.h"
#include "../../Headers/MCAL/UART.h"
#include "../../Headers/HAL/GPS_module.h"
#include "../../Headers/HAL/GPS_mohamed.h"
#include "../../Headers/HAL/LCD.h"
#include "../../Headers/HAL/LED.h"
#include "../../Headers/HAL/LCD.h"
#include "../../Headers/Services/TM4C123.h"

#include "../../../LCD_.h"

double tot_distance=0;
double speed=0;

// points coordinates
double lat1=0;
double long1=0;
extern float currentLat;
extern float currentLong;
extern int Read_Done;
extern float  currLatitdegree ,currLongdgree,currLatitradian,currLongradian,total_distance,previous_longit,previous_latit,directed_currLatit,directed_currLong;

 
int main(){
	chr_lcd_8bit_t LCD;
	LCD.lcd_en.direction = OUTPUT;
	LCD.lcd_en.port = PORTB_INDEX;
	LCD.lcd_en.pin = PIN4;
	LCD.lcd_rs.direction = OUTPUT;
	LCD.lcd_rs.port = PORTB_INDEX;
	LCD.lcd_rs.pin = PIN0;

	LCD.lcd_data[0].direction = OUTPUT;
	LCD.lcd_data[0].port = PORTD_INDEX;
	LCD.lcd_data[0].pin = PIN0;

	LCD.lcd_data[1].direction = OUTPUT;
	LCD.lcd_data[1].port = PORTD_INDEX;
	LCD.lcd_data[1].pin = PIN1;
	
	LCD.lcd_data[2].direction = OUTPUT;
	LCD.lcd_data[2].port = PORTD_INDEX;
	LCD.lcd_data[2].pin = PIN2;

	LCD.lcd_data[3].direction = OUTPUT;
	LCD.lcd_data[3].port = PORTD_INDEX;
	LCD.lcd_data[3].pin = PIN3;

	LCD.lcd_data[4].direction = OUTPUT;
	LCD.lcd_data[4].port = PORTE_INDEX;
	LCD.lcd_data[4].pin = PIN1;

	LCD.lcd_data[5].direction = OUTPUT;
	LCD.lcd_data[5].port = PORTE_INDEX;
	LCD.lcd_data[5].pin = PIN2;

	LCD.lcd_data[6].direction = OUTPUT;
	LCD.lcd_data[6].port = PORTE_INDEX;
	LCD.lcd_data[6].pin = PIN3;

	LCD.lcd_data[7].direction = OUTPUT;
	LCD.lcd_data[7].port = PORTE_INDEX;
	LCD.lcd_data[7].pin = PIN4;

	
	Std_ReturnType ret =  lcd_8bit_intialize(&LCD);
	//ret = lcd_8bit_send_string_pos(&LCD,1,0, "GPS-Track");
	
	UART2_Ini();
	UART0_Ini();
	RGB_Init();
  GPS_read();
	GPS_format();
	lat1 = to_degree(currentLat);
  long1 = to_degree(currentLong);
	

	while (1){
		char distancee [12];
    
		//ret = convert_uint32_to_string(currentLat , distance);
		ret = lcd_8bit_send_string_pos(&LCD, 1,1,"Distace Walked :");
		ret = convert_uint32_to_string(tot_distance , distancee);
		ret = lcd_8bit_send_string_pos(&LCD, 2,2,distancee);
		delay_ms(1200);
		if (tot_distance >= 100){LEDs_output(GREEN_LED);}
		else {LEDs_output(RED_LED);}
		
		
    GPS_read();
    GPS_format();
			
				currentLat = to_degree(currentLat);
        currentLong = to_degree(currentLong);
			
				UART0SendFloat(currentLat);	
				UART0SendString(",");
				UART0SendFloat(currentLong);	
				UART0SendString("\n");
				tot_distance += distance(lat1 , long1 , currentLat , currentLong);
		 }
		  				
	}