#include "../../Headers/MCAL/SysTick.h"
# include "../../Headers/Services/Bit-utilies.h"




void delay_ms(int timeInMicroMilli){
	while(timeInMicroMilli){
			NVIC_ST_CTRL_R 		= 0;
			NVIC_ST_RELOAD_R 	= 16000-1; //count 1ms
			NVIC_ST_CURRENT_R = 0x0;
			NVIC_ST_CTRL_R 		= 0x05; 	 //set pin 0(EN) & pin 2(CLK SRC)
			while ( (NVIC_ST_CTRL_R & 0x10000) == 0 );
			timeInMicroMilli--;
	}
}

void delay_us(int timeInMicro){
	while(timeInMicro){
			NVIC_ST_CTRL_R 		= 0;
			NVIC_ST_RELOAD_R 	= 16-1; //count 1us
			NVIC_ST_CURRENT_R = 0x0;
			NVIC_ST_CTRL_R 		= 0x05; 	 //set pin 0(EN) & pin 2(CLK SRC)
			while ( (NVIC_ST_CTRL_R & 0x10000) == 0 );
			timeInMicro--;
	}
}



