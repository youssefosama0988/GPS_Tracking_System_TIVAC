#include "../Services/types.h" 
#include "../Services/TM4C123.h"
#include "../Services/bit_utilities.h"
#define STK_CLOCK_FREQUENCY        16000000


void STK_voidGetCurrentValue(uint32_t *copy_uint32_tCurrVal);
uint8_t STK_voidSetReloadValue(uint32_t copy_uint32_tTicks);
void STK_voidDisable(void);
void delay_s(unsigned int time);
void delay_ms(unsigned int ticks);
void delay_us(unsigned int ticks);