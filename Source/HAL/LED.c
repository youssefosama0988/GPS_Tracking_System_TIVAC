#include "../../Headers/HAL/LED.h"


void RGB_Init(void){ 

	gpio_digital_port_init(PORTF_INDEX , 1, OUTPUT);
	gpio_digital_port_init(PORTF_INDEX , 2, OUTPUT);
	gpio_digital_port_init(PORTF_INDEX , 3, OUTPUT);
}
void Switches_Init(void){
	gpio_digital_port_init(PORTF_INDEX , 0, INPUT);
	gpio_digital_port_init(PORTF_INDEX , 4, INPUT);
	
}
unsigned char SW1_Input(void){
char pressed1 = GPIO_PORTF_DATA_R & 0x10;
return pressed1; 
}
unsigned char SW2_Input(void){
char pressed2 = GPIO_PORTF_DATA_R & 0x01;
return pressed2; 
}
void LEDs_output(unsigned char data){
GPIO_PORTF_DATA_R &= ~0x0E;
GPIO_PORTF_DATA_R |= data;
}