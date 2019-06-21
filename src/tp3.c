#include "tp3.h"

uint8_t val_init;
uint8_t read;
uint8_t write;


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

uint8_t rtc_escritura(void){
	
    uint8_t transmitDataBuffer[2];

    /*  La lectura se efectua en tres pasos
     *  1. Cargo en buffer[0] la dirección del registro a 
     *  2. Cargo en el buffer[1] la información a escribir
     *  3. Grabo en el registro buffer[0] la información de buffer[1]       
	 */
	transmitDataBuffer[0] = 0x00;
	transmitDataBuffer[1] = 8;
    write = i2cWrite(I2C0, I2C_ADDRESS, transmitDataBuffer, 2, TRUE);	

	return write;
}

void visualizar_escritura(uint16_t * puerto){
	
	// Si la lectura es exitosa enciende el quinto led
	if(write==1){
		*puerto=0x0010;
	}
	// Si la conexión tiene error enciende el sexto led
	if(write==0){
		*puerto=0x0020;
	}
	
}


