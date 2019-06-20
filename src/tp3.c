#include "tp3.h"


void leds_inicia(uint16_t * puerto){
	*puerto = 0x0000;
}


bool rtc_virtual_inicia(uint8_t estado){

	bool val;
	
	// Si hago el que rtc inicie correctamente
	if(estado == CONECTA){
		val = 1;
	}
	
	// Si hago el que rtc no inicie correctamente
	if(estado == NO_CONECTA){
		val = 0;
	}
	return val;
}