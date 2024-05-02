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

// some comments to help you in having some generic code 
// you can have a enum that conation the name of the port ang having it as an integer 

/************ Initialize the UART0  ***********/

void UART0_Ini(void)
{
 SYSCTL_RCGCUART_R|=0X01;                             //  set pin 0 to provide clock
 SYSCTL_RCGCGPIO_R|=0x01;                            // PORT A activation 
 while((SYSCTL_PRGPIO_R&0X01)==0){};    	        //  wait for GPIO getting ready  
 GPIO_PORTA_LOCK_R=GPIO_LOCK_KEY;                  // 2) unlock GPIO Port A
 GPIO_PORTA_CR_R=0XFF;                            // allow changes to PA4-0

       /**Disable UART0 in Initialization ************/
		CLEAR_BIT(UART0_CTL_R,0);                          //disable UART to configure baud rate 
		UART0_IBRD_R= 104 ;                        // integer reg to store integer value of baudrate 
		UART0_FBRD_R= 11 ;                        // float reg to store the fraction of baudrate 
		UART0_LCRH_R=0x00000070;                 // 8bit, no parity bits,one stop, fifo  
		UART0_CTL_R |= 0x00000301;   		    // enable UART,TX,RX  


          /*********   digital enable , analog disable , PCTL   **************/

    GPIO_PORTA_CR_R=0XFF;
    GPIO_PORTA_AFSEL_R|=0X03;
    GPIO_PORTA_PCTL_R=(GPIO_PORTA_PCTL_R & 0xFFFFFF00)+0X11;
    GPIO_PORTA_DEN_R=0X02;


}

 /**********   function to recieve byte UART0**/
 char CharIn0 (void)
{
    while( (UART0_FR_R & 0X10) != 0){}         // check until RXFE = 0 
        return (UART0_DR_R & 0XFF);           //  return the value
} 

/**********   function to send byte UART0**/
void CharOut0 (char data)
{
     while((UART0_FR_R&0X20)!= 0){}           // check until TXFF = 0  
        UART0_DR_R=data;
}



//=============================================================================================================================================================/
/***********  Initialize the UART2  **********/

void UART2_Ini(void)
{
	SET_BIT(SYSCTL_RCGCUART_R,2);    				  // set pin 2 to provide clock 
	SET_BIT(SYSCTL_RCGCGPIO_R,3) ;                   //PORT D Activation   
	while((SYSCTL_PRGPIO_R & (0x01<<3)) == 0){}  	// wait for GPIO portD getting ready 
	  GPIO_PORTD_LOCK_R |= GPIO_LOCK_KEY;          // 2) unlock GPIO Port F
	  GPIO_PORTD_CR_R |= 0xFF;                    // allow changes to PF4-0 
                  
//Disable UART2 in Initialization
		CLEAR_BIT(UART2_CTL_R,0);                    // disable UART2 to configure baud rate 
		    UART2_IBRD_R=104;                       // integer reg to store integer value of baudrate 
		    UART2_FBRD_R=11 ;                      // float reg to store the fraction of baudrate 
		    UART2_LCRH_R=0x00000070;              // 8bit, no parity bits,one stop, fifo  
		    UART2_CTL_R |= 0x00000301;   	     // enable UART,TX,RX  
		
		/*********   digital enable , analog disable , PCTL   **************/

		SET_BIT(GPIO_PORTD_DEN_R,6);
		SET_BIT(GPIO_PORTD_DEN_R,7);
		
		SET_BIT(GPIO_PORTD_AFSEL_R,6);
		SET_BIT(GPIO_PORTD_AFSEL_R,7);
		
		CLEAR_BIT(GPIO_PORTD_AMSEL_R,6);
		CLEAR_BIT(GPIO_PORTD_AMSEL_R,7);
		
		GPIO_PORTD_PCTL_R |= 0x11000000;
}

 /**********   function to recieve byte UART2 ******/
char charIn2 (void)
{
		while ( (UART2_FR_R&0X10) !=0){};      // check until RXFE = 0  
		return (uint8_t)UART2_DR_R&0xFF;         //  return the value    
		
}

/**********   function to send byte UART2  ********/
void charOut2 (char data)
{
	while ( (UART2_FR_R&0X20) !=0){};	     // check until TXFF = 0  
	    UART2_DR_R=data;
}
