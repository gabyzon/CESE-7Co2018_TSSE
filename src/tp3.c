#include "tp3.h"

uint8_t val_init;
uint8_t read;


void leds_inicia(uint16_t * puerto){
	*puerto = 0x0000;
}


uint8_t rtc_inicia(void){
	
	// using I2C for communication
	// starting the I2C bus
    
	val_init = i2cInit(I2C0, I2C_RATE);
    // Si init = 1, el RTC se inició correctamente
    // Si init = 0, hubo un error en la iniciación del RTC
	
	return val_init;
}

void visualizar_inicio(uint16_t * puerto){
		
	// Si la conexión es exitosa enciende el primer led
	if(val_init==1){
		*puerto=0x0001;
	}
	// Si la conexión tiene error enciende el segundo led
	if(val_init==0){
		*puerto=0x0002;
	}
	
}

uint8_t rtc_lectura(void){
	
    uint8_t dataToReadBuffer;
    uint8_t receiveDataBuffer;
	
	dataToReadBuffer = 0x00; 
	read = i2cRead( I2C0, I2C_ADDRESS, &dataToReadBuffer,1,TRUE,&receiveDataBuffer,1,TRUE);

	return read;
}

void visualizar_lectura(uint16_t * puerto){
	
	// Si la lectura es exitosa enciende el tercer led
	if(read==1){
		*puerto=0x0004;
	}
	// Si la conexión tiene error enciende el cuarto led
	if(read==0){
		*puerto=0x0008;
	}
	
}
