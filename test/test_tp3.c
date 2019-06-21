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
	
	uint8_t val;
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
	uint8_t val;
	
	// Hago que la conexión sea exitosa y encienda el led 2
	i2cInit_ExpectAndReturn(I2C0, I2C_RATE,1);
	val = rtc_inicia();
	visualizar_inicio(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0001, puerto_virtual);
	
	
}







