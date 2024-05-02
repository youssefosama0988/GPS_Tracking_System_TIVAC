/*
    Created by: George Joseph Basilious

*/
#ifndef GPIO_H
#define GPIO_H

#include <stdio.h>
#include "../Services/TM4C123.h"
#include "../Services/types.h"
#include "../Services/bit_utilities.h"
#include "SysTick.h"


typedef enum{
    LOW=0,
    HIGH
}logic_t;

typedef enum{
    INPUT=0,
    OUTPUT
}direction_t;

typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum{
    PORTA_INDEX=0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
    PORTF_INDEX
}port_index_t;


void gpio_digital_port_init(port_index_t port, pin_index_t pin, direction_t direction);
void gpio_digital_port_write(port_index_t port, pin_index_t pin, logic_t data);
uint8_t gpio_digital_read(port_index_t port, pin_index_t pin);
void gpio_digital_toggle(port_index_t port, pin_index_t pin);


#endif
