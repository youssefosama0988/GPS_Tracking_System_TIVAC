/**************************************************************************************************************************************************
*
*Module: UART
*
*File Name: UART.h
*
*Author: Mohamed Sameh & Toqa Gamal
*
****************************************************************************************************************************************************/

#ifndef UART_H
#define UART_H          
#include <stdint.h>
#include "../Services/TM4C123.h"
#include "../MCAL/GPIO.h"


/******** UART0 **********/
void UART0_Ini(void); //initialization for UART0

char CharIn0(void); //to receive data

void CharOut0(char data); //to transmit the data

/******** UART2 **********/
void UART2_Ini(void);  //initialization for UART2

char charIn2(void); //to Receive the data

void CharOut2(char data); //to transmit the data

#endif
