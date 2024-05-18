#include "tm4c123gh6pm.h"
#define EEPROM_ERROR   0x00
#define EEPROM_OK   	 0x01

char EEPROM_Init();
void EEPROM_write_word(int data,char block , char offset);
void EEPROM_write_data(int *data,char block , char offset , int count);
void EEPROM_read_word(int *data,char block , char offset);
void EEPROM_read_data(int *data,char block , char offset , int count);