#ifndef _TM4C_H
#define _TM4C_H
#include "../../Headers/MCAL/GPIO.h"
#endif

#ifndef _LED_H
#define _LED_H

// LEDS
#define RED_LED 0x02
#define BLUE_LED 0x04
#define GREEN_LED 0x08
#define RGB_LED 0x0E
#define PF123_mask             0x0E
#define PF04_mask               0x11
#define PF_mask                0x20


unsigned char SW1_Input(void);
unsigned char SW2_Input(void);
void LEDs_output(unsigned char data);
void Switches_Init(void);
void RGB_Init(void);


#endif