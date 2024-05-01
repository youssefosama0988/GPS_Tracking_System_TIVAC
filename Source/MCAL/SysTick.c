#include "../../Headers/MCAL/SysTick.h"
void STK_voidGetCurrentValue(uint32_t *CurrentVal){    
*CurrentVal =NVIC_ST_CURRENT_R ;
}
uint8_t STK_voidSetReloadValue(uint32_t ReloadVal){  
	
	SET_BIT(NVIC_ST_RELOAD_R , ReloadVal );
		return NVIC_ST_RELOAD_R;
}
void STK_Disable(void){                             
CLEAR_BIT(NVIC_ST_CTRL_R,0);
NVIC_ST_RELOAD_R =0;
NVIC_ST_CURRENT_R=0;
}
void delay_s(unsigned int ticks){
  NVIC_ST_CTRL_R = 0;             		
  NVIC_ST_RELOAD_R = 16000000 - 1; 		
  NVIC_ST_CURRENT_R = 0;           		
  NVIC_ST_CTRL_R = 0x00000005;     		
	while(ticks > 0)
	{
		if((NVIC_ST_CTRL_R & 0x10000) != 0) {
      ticks--;
		}
	}
	  NVIC_ST_CTRL_R = 0;             
}
void delay_ms(unsigned int ticks){
   NVIC_ST_CTRL_R = 0;             		
  NVIC_ST_RELOAD_R = 16000 - 1; 		  
  NVIC_ST_CURRENT_R = 0;           		
  NVIC_ST_CTRL_R = 0x00000005;     		
	while(ticks > 0)
	{
		if((NVIC_ST_CTRL_R & 0x10000) != 0) {
      ticks--;
	}
	  NVIC_ST_CTRL_R = 0;             
}
	
}
void delay_us(unsigned int ticks){
  NVIC_ST_CTRL_R = 0;             		//disable systick during initialization
  NVIC_ST_RELOAD_R = 16 - 1; 		      //Loading the number of ticks
  NVIC_ST_CURRENT_R = 0;           		//Clearing current register
  NVIC_ST_CTRL_R = 0x00000005;     		//Enabling Systick
	while(ticks > 0)
	{
		if((NVIC_ST_CTRL_R & 0x10000) != 0) {
      ticks--;
	}
	  NVIC_ST_CTRL_R = 0;             
	}
}
	

