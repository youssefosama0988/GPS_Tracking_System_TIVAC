/*
    Created by: George Joseph Basilious

*/
#include "../../Headers/MCAL/GPIO.h"

void gpio_digital_port_init(port_index_t port, pin_index_t pin, direction_t direction){
	switch(port){
		case PORTA_INDEX:
			SYSCTL_RCGCGPIO_R |= 0x01;
			while((SYSCTL_PRGPIO_R&0x01) == 0);
			GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;	
			SET_BIT(GPIO_PORTA_CR_R,pin);
			CLEAR_BIT(GPIO_PORTA_AMSEL_R,pin);
			GPIO_PORTA_PCTL_R &= ~( 0xF << (pin*4));
			CLEAR_BIT(GPIO_PORTA_AFSEL_R,pin);
			if (direction == OUTPUT){
				SET_BIT(GPIO_PORTA_DIR_R,pin);
			}else if(direction == INPUT){
				CLEAR_BIT(GPIO_PORTA_DIR_R,pin);
				SET_BIT(GPIO_PORTA_PUR_R,pin);
			}
			SET_BIT(GPIO_PORTA_DEN_R,pin);
		
			break;
		case PORTB_INDEX:
			SYSCTL_RCGCGPIO_R |= 0x02;
			while((SYSCTL_PRGPIO_R&0x02) == 0);
			GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;	
			SET_BIT(GPIO_PORTB_CR_R,pin);
			CLEAR_BIT(GPIO_PORTB_AMSEL_R,pin);
			GPIO_PORTB_PCTL_R &= ~( 0xF << (pin*4));
			CLEAR_BIT(GPIO_PORTB_AFSEL_R,pin);
			if (direction == OUTPUT){
				SET_BIT(GPIO_PORTB_DIR_R,pin);
			}else if(direction == INPUT){
				CLEAR_BIT(GPIO_PORTB_DIR_R,pin);
				SET_BIT(GPIO_PORTB_PUR_R,pin);
			}
			SET_BIT(GPIO_PORTB_DEN_R,pin);
		
			break;
		case PORTC_INDEX:
				SYSCTL_RCGCGPIO_R |= 0x04;
				while((SYSCTL_PRGPIO_R&0x04) == 0);
				GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;	
				SET_BIT(GPIO_PORTC_CR_R,pin);
				CLEAR_BIT(GPIO_PORTC_AMSEL_R,pin);
				GPIO_PORTC_PCTL_R &= ~( 0xF << (pin*4));
				CLEAR_BIT(GPIO_PORTC_AFSEL_R,pin);
				if (direction == OUTPUT){
					SET_BIT(GPIO_PORTC_DIR_R,pin);
				}else if(direction == INPUT){
					CLEAR_BIT(GPIO_PORTC_DIR_R,pin);
					SET_BIT(GPIO_PORTC_PUR_R,pin);
				}
				SET_BIT(GPIO_PORTC_DEN_R,pin);
		
			break;
		case PORTD_INDEX:
				SYSCTL_RCGCGPIO_R |= 0x08;
				while((SYSCTL_PRGPIO_R&0x08) == 0);
				GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;	
				SET_BIT(GPIO_PORTD_CR_R,pin);
				CLEAR_BIT(GPIO_PORTD_AMSEL_R,pin);
				GPIO_PORTD_PCTL_R &= ~( 0xF << (pin*4));
				CLEAR_BIT(GPIO_PORTD_AFSEL_R,pin);
				if (direction == OUTPUT){
					SET_BIT(GPIO_PORTD_DIR_R,pin);
				}else if(direction == INPUT){
					CLEAR_BIT(GPIO_PORTD_DIR_R,pin);
					SET_BIT(GPIO_PORTD_PUR_R,pin);
				}
				SET_BIT(GPIO_PORTD_DEN_R,pin);
		
			break;
		case PORTE_INDEX:
				SYSCTL_RCGCGPIO_R |= 0x10;
				while((SYSCTL_PRGPIO_R&0x10) == 0);
				GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;	
				SET_BIT(GPIO_PORTE_CR_R,pin);
				CLEAR_BIT(GPIO_PORTE_AMSEL_R,pin);
				GPIO_PORTE_PCTL_R &= ~( 0xF << (pin*4));
				CLEAR_BIT(GPIO_PORTE_AFSEL_R,pin);
				if (direction == OUTPUT){
					SET_BIT(GPIO_PORTE_DIR_R,pin);
				}else if(direction == INPUT){
					CLEAR_BIT(GPIO_PORTE_DIR_R,pin);
					SET_BIT(GPIO_PORTE_PUR_R,pin);
				}
				SET_BIT(GPIO_PORTE_DEN_R,pin);
			break;
		case PORTF_INDEX:
				SYSCTL_RCGCGPIO_R |= 0x20;
				while((SYSCTL_PRGPIO_R&0x20) == 0);
				GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;	
				SET_BIT(GPIO_PORTF_CR_R,pin);
				CLEAR_BIT(GPIO_PORTF_AMSEL_R,pin);
				GPIO_PORTF_PCTL_R &= ~( 0xF << (pin*4));
				CLEAR_BIT(GPIO_PORTF_AFSEL_R,pin);
				if (direction == OUTPUT){
					SET_BIT(GPIO_PORTF_DIR_R,pin);
				}else if(direction == INPUT){
					CLEAR_BIT(GPIO_PORTF_DIR_R,pin);
					SET_BIT(GPIO_PORTF_PUR_R,pin);
				}
				SET_BIT(GPIO_PORTF_DEN_R,pin);
			break;
		
	}
	
}




void gpio_digital_port_write(port_index_t port, pin_index_t pin, logic_t data){
	switch(port){
		case PORTA_INDEX:
				if(data == HIGH){
					SET_BIT(GPIO_PORTA_DATA_R, pin);
				}else if(data == LOW){
					CLEAR_BIT(GPIO_PORTA_DATA_R, pin);
				}
			break;
		case PORTB_INDEX:
				if(data == HIGH){
					SET_BIT(GPIO_PORTB_DATA_R, pin);
				}else if(data == LOW){
					CLEAR_BIT(GPIO_PORTB_DATA_R, pin);
				}
			break;
		case PORTC_INDEX:
				if(data == HIGH){
					SET_BIT(GPIO_PORTC_DATA_R, pin);
				}else if(data == LOW){
					CLEAR_BIT(GPIO_PORTC_DATA_R, pin);
				}
			break;
		case PORTD_INDEX:
				if(data == HIGH){
					SET_BIT(GPIO_PORTD_DATA_R, pin);
				}else if(data == LOW){
					CLEAR_BIT(GPIO_PORTD_DATA_R, pin);
				}
			break;
		case PORTE_INDEX:
				if(data == HIGH){
					SET_BIT(GPIO_PORTE_DATA_R, pin);
				}else if(data == LOW){
					CLEAR_BIT(GPIO_PORTE_DATA_R, pin);
				}
			break;
		case PORTF_INDEX:
				if(data == HIGH){
					SET_BIT(GPIO_PORTF_DATA_R, pin);
				}else if(data == LOW){
					CLEAR_BIT(GPIO_PORTF_DATA_R, pin);
				}
			break;
		
	}
}
	
uint8_t gpio_digital_read(port_index_t port, pin_index_t pin){
	uint8_t value = 0;
	switch(port){
		case PORTA_INDEX:
			value = READ_BIT(GPIO_PORTA_DATA_R, pin);
			break;
		case PORTB_INDEX:
			value = READ_BIT(GPIO_PORTB_DATA_R, pin);
			break;
		case PORTC_INDEX:
			value = READ_BIT(GPIO_PORTC_DATA_R, pin);
			break;
		case PORTD_INDEX:
			value = READ_BIT(GPIO_PORTD_DATA_R, pin);
			break;
		case PORTE_INDEX:
			value = READ_BIT(GPIO_PORTE_DATA_R, pin);
			break;
		case PORTF_INDEX:
			value = READ_BIT(GPIO_PORTF_DATA_R, pin);
			break;
	}
	return value;
}



void gpio_digital_toggle(port_index_t port, pin_index_t pin){
	switch(port){
		case PORTA_INDEX:
				TOGGLE_BIT(GPIO_PORTA_DATA_R, pin);
			break;
		case PORTB_INDEX:
				TOGGLE_BIT(GPIO_PORTB_DATA_R, pin);
			break;
		case PORTC_INDEX:
				TOGGLE_BIT(GPIO_PORTC_DATA_R, pin);
			break;
		case PORTD_INDEX:
				TOGGLE_BIT(GPIO_PORTD_DATA_R, pin);
			break;
		case PORTE_INDEX:
				TOGGLE_BIT(GPIO_PORTE_DATA_R, pin);
			break;
		case PORTF_INDEX:
				TOGGLE_BIT(GPIO_PORTF_DATA_R, pin);
			break;
		
	}
}
