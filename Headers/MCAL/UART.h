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

//char CharIn0(void); //to receive data

void charOut0 (char data); //to transmit the data

void UART0_outString(char *gps_READING);

void UART0SendString(const char *str);
void UART0SendFloat(float num);

float stringToFloat(const char *str);

///******** UART2 **********/
void UART2_Ini(void);  //initialization for UART2


char charIn2 (void);//to Receive the data

//void CharOut2(char data); //to transmit the data

#endif