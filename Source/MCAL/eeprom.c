
# include "../../Headers/MCAL/eeprom.h"

# include "../../Headers/MCAL/SysTick.h"
char EEPROM_Init(){
	
		SYSCTL_RCGCEEPROM_R = SYSCTL_RCGCEEPROM_R0;
		//delay
		delay_ms(1);
		//* ---------busy wait until working bit in EEDONE is clear ------*/
		while ( (EEPROM_EEDONE_R & 0x01) !=0);      
		//----------check if ERETRY or PRETRY is set----------/
		if( (EEPROM_EESUPP_R & EEPROM_EESUPP_PRETRY) !=0 || (EEPROM_EESUPP_R & EEPROM_EESUPP_ERETRY) !=0){ 
			return EEPROM_ERROR;
		}
		//----------Reset the EEPROM module------/
		SYSCTL_SREEPROM_R = SYSCTL_SREEPROM_R0;	
		
		//delay
		delay_ms(1);
		SYSCTL_SREEPROM_R = ~SYSCTL_SREEPROM_R0;
		delay_ms(1);
		//* ---------busy wait until working bit in EEDONE is clear ------*/
		while ( (EEPROM_EEDONE_R & 0x01) !=0);      
		//----------check if ERETRY or PRETRY is set----------/
		if( (EEPROM_EESUPP_R & EEPROM_EESUPP_PRETRY) !=0 || (EEPROM_EESUPP_R & EEPROM_EESUPP_ERETRY) !=0){ 
			return EEPROM_ERROR;
		}
		
		return EEPROM_OK;
}


void EEPROM_write_word(int data,char block , char offset){
	EEPROM_EEBLOCK_R = block;
	EEPROM_EEOFFSET_R = offset;
	EEPROM_EERDWR_R = data;
}


void EEPROM_write_data(int *data,char block , char offset , int count){
	
	while ( (EEPROM_EEDONE_R & 0x01) !=0);
	
	EEPROM_EEBLOCK_R = block;
	
	EEPROM_EEOFFSET_R = offset;
	while ( (EEPROM_EEDONE_R & 0x01) !=0);
	
	while(count){
		EEPROM_EERDWR_R = *data;
		delay_ms(1);
		count--;
		data++;
		EEPROM_EEOFFSET_R++;
		EEPROM_EEOFFSET_R %=16;
		
		while ( (EEPROM_EEDONE_R & 0x01) !=0);
		if( count && (EEPROM_EEOFFSET_R == 0) ){
				EEPROM_EEBLOCK_R++;
		} 
	}
}

void EEPROM_read_word(int *data,char block , char offset){
	EEPROM_EEBLOCK_R = block;
	EEPROM_EEOFFSET_R = offset;
	while ( (EEPROM_EEDONE_R & 0x01) !=0);
	*data = EEPROM_EERDWR_R ;
	while ( (EEPROM_EEDONE_R & 0x01) !=0);
}

void EEPROM_read_data(int *data,char block , char offset , int count){
	
	while ( (EEPROM_EEDONE_R & 0x01) !=0);
	
	EEPROM_EEBLOCK_R = block;
	
	EEPROM_EEOFFSET_R = offset;
	while ( (EEPROM_EEDONE_R & 0x01) !=0);
	
	while(count){
		*data = EEPROM_EERDWR_R ;
		count--;
		data++;
		EEPROM_EEOFFSET_R++;
		EEPROM_EEOFFSET_R %=16;
		
		while ( (EEPROM_EEDONE_R & 0x01) !=0);
		if( count && (EEPROM_EEOFFSET_R == 0) ){
				EEPROM_EEBLOCK_R++;
		}
		while ( (EEPROM_EEDONE_R & 0x01) !=0);		
	}
}