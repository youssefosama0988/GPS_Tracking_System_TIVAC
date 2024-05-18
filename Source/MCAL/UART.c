/**************************************************************************************************************************************************
*
*Module: UART
*
*File Name: UART.c
*
*Author: Mohamed Sameh & Toqa Gamal
*
****************************************************************************************************************************************************/

/*****  include some files  ******/
#include "tm4c123gh6pm.h"
#include "../../Headers/MCAL/UART.h"
# include "../../Headers/Services/Bit-utilies.h"

void UART0SendString(const char *str) {
    while (*str) {
        while ((UART0_FR_R & UART_FR_TXFF) != 0);  // Wait until the transmitter is not full
        UART0_DR_R = *str;  // Transmit the character
        str++;
    }
}

void UART0SendFloat(float num) {
		
    int i;
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%f", num);

   for( i=0 ; buffer[i] != '\0'; i++) {
        while((UART0_FR_R & UART_FR_TXFF)==UART_FR_TXFF); // Wait until the transmitter is not full
        UART0_DR_R = buffer[i]; // Transmit the character
    }
}
// some comments to help you in having some generic code 
// you can have a enum that conation the name of the port ang having it as an integer 

/************ Initialize the UART0  ***********/

//void UART0_Ini(void)
//{
// SYSCTL_RCGCUART_R|=0X01;                             //  set pin 0 to provide clock
// SYSCTL_RCGCGPIO_R|=0x01;                            // PORT A activation 
// while((SYSCTL_PRGPIO_R&0X01)==0){};    	        //  wait for GPIO getting ready  
// GPIO_PORTA_LOCK_R=GPIO_LOCK_KEY;                  // 2) unlock GPIO Port A
// GPIO_PORTA_CR_R=0XFF;                            // allow changes to PA4-0

//       /**Disable UART0 in Initialization ************/
//		CLR_BIT(UART0_CTL_R,0);                          //disable UART to configure baud rate 
//		UART0_IBRD_R= 104 ;                        // integer reg to store integer value of baudrate 
//		UART0_FBRD_R= 11 ;                        // float reg to store the fraction of baudrate 
//		UART0_LCRH_R=0x00000070;                 // 8bit, no parity bits,one stop, fifo  
//		UART0_CTL_R |= 0x00000301;   		    // enable UART,TX,RX  


//          /*********   digital enable , analog disable , PCTL   **************/

//    GPIO_PORTA_CR_R=0XFF;
//    GPIO_PORTA_AFSEL_R|=0X03;
//    GPIO_PORTA_PCTL_R=(GPIO_PORTA_PCTL_R & 0xFFFFFF00)+0X11;
//    GPIO_PORTA_DEN_R=0X02;


//}

// /**********   function to recieve byte UART0**/
// char CharIn0 (void)
//{
//    while( (UART0_FR_R & 0X10) != 0){}         // check until RXFE = 0 
//        return (UART0_DR_R & 0XFF);           //  return the value
//} 

///**********   function to send byte UART0**/
//void CharOut0 (char data)
//{
//     while((UART0_FR_R&0X20)!= 0){}           // check until TXFF = 0  
//        UART0_DR_R=data;
//}



////=============================================================================================================================================================/
///***********  Initialize the UART2  **********/

//void UART2_Ini(void)
//{
//	SET_BIT(SYSCTL_RCGCUART_R,2);    				  // set pin 2 to provide clock 
//	SET_BIT(SYSCTL_RCGCGPIO_R,3) ;                   //PORT D Activation   
//	while((SYSCTL_PRGPIO_R & (0x01<<3)) == 0){}  	// wait for GPIO portD getting ready 
//	  GPIO_PORTD_LOCK_R |= GPIO_LOCK_KEY;          // 2) unlock GPIO Port F
//	  GPIO_PORTD_CR_R |= 0xFF;                    // allow changes to PF4-0 
//                  
////Disable UART2 in Initialization
//		CLR_BIT(UART2_CTL_R,0);                    // disable UART2 to configure baud rate 
//		    UART2_IBRD_R=104;                       // integer reg to store integer value of baudrate 
//		    UART2_FBRD_R=11 ;                      // float reg to store the fraction of baudrate 
//		    UART2_LCRH_R=0x00000070;              // 8bit, no parity bits,one stop, fifo  
//		    UART2_CTL_R |= 0x00000301;   	     // enable UART,TX,RX  
//		
//		/*********   digital enable , analog disable , PCTL   **************/

//		SET_BIT(GPIO_PORTD_DEN_R,6);
//		SET_BIT(GPIO_PORTD_DEN_R,7);
//		
//		SET_BIT(GPIO_PORTD_AFSEL_R,6);
//		SET_BIT(GPIO_PORTD_AFSEL_R,7);
//		
//		CLR_BIT(GPIO_PORTD_AMSEL_R,6);
//		CLR_BIT(GPIO_PORTD_AMSEL_R,7);
//		
//		GPIO_PORTD_PCTL_R |= 0x11000000;
//}

// /**********   function to recieve byte UART2 ******/
//char charIn2 (void)
//{
//		while ( (UART2_FR_R&0X10) !=0){};      // check until RXFE = 0  
//		return (uint8_t)UART2_DR_R&0xFF;         //  return the value    
//		
//}

///**********   function to send byte UART2  ********/
//void charOut2 (char data)
//{
//	while ( (UART2_FR_R&0X20) !=0){};	     // check until TXFF = 0  
//	    UART2_DR_R=data;
//}
void UART2_Ini(void){
	SYSCTL_RCGCUART_R |=0X4;    //  Activate UART 2    
  SYSCTL_RCGCGPIO_R|=0x8;     //  Activate PORTD        
  UART2_CTL_R &= ~0X4;            
	UART2_IBRD_R=0x68 ;                       
  UART2_FBRD_R=0xB;                    
  UART2_LCRH_R=0x00000070;               
	UART2_CTL_R |= 0x00000301;   	 // enable UART,TX,RX  
	GPIO_PORTD_AFSEL_R|=0xC0;
	GPIO_PORTD_PCTL_R |= (GPIO_PORTD_PCTL_R&0X00FFFFFF)+0x11000000;
	GPIO_PORTD_DEN_R|=0xC0;     // FD6,ppD7   
	GPIO_PORTD_AMSEL_R&=~0xC0;		
} 

void UART0_Ini(void){
	SYSCTL_RCGCUART_R |=0X0001;    //  Activate UART 0     
  SYSCTL_RCGCGPIO_R|=0x0001;     //  Activate PORTA    
  UART0_CTL_R &= ~0x0001;             
	UART0_IBRD_R=0x68 ;                       
  UART0_FBRD_R=0xB;                    
  UART0_LCRH_R=0x00000070;               
	UART0_CTL_R |= 0x00000301;     // enable UART,TX,RX  
	GPIO_PORTA_AFSEL_R|=0x03;
	GPIO_PORTA_PCTL_R |= (GPIO_PORTA_PCTL_R&0XFFFFFF00)+0x00000011;
	GPIO_PORTA_DEN_R|=0x03;    // PA0,PA1   
	GPIO_PORTA_AMSEL_R&=~0x03;		
}


char charIn2 (void)
{
		while ( (UART2_FR_R&0X10) !=0){};      
		return (char)UART2_DR_R;          
		
} 

void charOut0 (char data)                
  {
	while ((UART0_FR_R&0X20)!=0){};	     
	        UART0_DR_R=data;
  }
	
	
  




void UART0_outString(char *gps_READING){   
  int  i = 0;   
	while(*(gps_READING)!='\0'){
		
		 charOut0(*(gps_READING));
			 gps_READING++;
		 }
}
	



float stringToFloat(const char *str) {
    float result = 0.0;
    float fraction = 0.0;
    int sign = 1;
    int decimalPoint = 0;
    
  
    if (*str == '-') {
        sign = -1;
        str++;
    }

    
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            if (decimalPoint) {
                fraction = fraction * 10.0f + (*str - '0');
                decimalPoint *= 10;
            } else {
                result = result * 10.0f + (*str - '0');
            }
        } else if (*str == '.') {
            decimalPoint = 1;
        } else {
            // Invalid character
            printf("Invalid character '%c' found in input.\n", *str);
            return 0.0;
        }
        str++;
    }
    
   
    result += fraction / decimalPoint;
    
   return result * sign;
}
