#include "unity.h"
#include "tp3.h"
#include <stdbool.h>
#include "mock_sapi_i2c.h"

void test_inicializa_leds(void){
	uint16_t puerto_virtual = 0xffff;
	leds_inicia(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

void test_inicializa_rtc(void){
	
	static uint8_t val;
	uint8_t expectedStateOk = 1;
	uint8_t expectedStateFail = 0;
	
	// Si la comunicacion inicia correctamente
	i2cInit_ExpectAndReturn(I2C0, I2C_RATE,1);
	val = rtc_inicia();
	TEST_ASSERT_EQUAL(expectedStateOk, val);
	
	// Si la comunicacion no inicia
	i2cInit_ExpectAndReturn(I2C0, I2C_RATE,0);
	val = rtc_inicia();
	TEST_ASSERT_EQUAL(expectedStateFail, val);

}

void test_visualiza_inicio_rtc(void){
	
	uint16_t puerto_virtual = 0x0000;
	static uint8_t val;
	
	// Hago que la conexión sea exitosa y enciende led 1
	i2cInit_ExpectAndReturn(I2C0, I2C_RATE,1);
	val = rtc_inicia();
	visualizar_inicio(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0001, puerto_virtual);
	
	// Hago que la conexión sea erronea y enciende led 2
	i2cInit_ExpectAndReturn(I2C0, I2C_RATE,0);
	val = rtc_inicia();
	visualizar_inicio(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0002, puerto_virtual);
}

void test_lectura_rtc(void){
	
	static uint8_t val;
	uint8_t expectedStateOk = 1;
	uint8_t expectedStateFail = 0;

    static uint8_t dataToReadBuffer;
    static uint8_t receiveDataBuffer;
	//dataToReadBuffer = 0x00; 
	
	// Hago que la lectura sea exitosa
	i2cRead_ExpectAndReturn( I2C0, I2C_ADDRESS, &dataToReadBuffer,1,TRUE,&receiveDataBuffer,1,TRUE, 1);
	val = rtc_lectura();
	TEST_ASSERT_EQUAL(expectedStateOk, val);
	
	// Hago que la lectura sea erronea
	i2cRead_ExpectAndReturn( I2C0, I2C_ADDRESS, &dataToReadBuffer,1,TRUE,&receiveDataBuffer,1,TRUE, 0);
	val = rtc_lectura();
	TEST_ASSERT_EQUAL(expectedStateFail, val);
	
}

void test_visualiza_lectura_rtc(void){

	uint16_t puerto_virtual = 0x0000;
	static uint8_t val;
	
	static uint8_t dataToReadBuffer;
    static uint8_t receiveDataBuffer;
	
	// Hago que la lectura sea exitosa y enciende led 4
	i2cRead_ExpectAndReturn( I2C0, I2C_ADDRESS, &dataToReadBuffer,1,TRUE,&receiveDataBuffer,1,TRUE, 1);
	val = rtc_lectura(); // Ejecuto la lectura.
	visualizar_lectura(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0004, puerto_virtual);

	// Hago que la lectura sea erronea y enciende led 4
	i2cRead_ExpectAndReturn( I2C0, I2C_ADDRESS, &dataToReadBuffer,1,TRUE,&receiveDataBuffer,1,TRUE, 0);
	val = rtc_lectura(); // Ejecuto la lectura.
	visualizar_lectura(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0004, puerto_virtual);

}





