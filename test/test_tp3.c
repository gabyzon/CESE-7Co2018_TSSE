#include "unity.h"
#include "tp3.h"
//#include "mock_sapi.h"

void test_inicializa_leds(void){
	uint16_t puerto_virtual = 0xffff;
	leds_inicia(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

void test_inicializa_rtc(void){
	uint16_t puerto_virtual = 0x0000;
	bool value=0;
	
	value = rtc_inicia(CONECTA);
	TEST_ASSERT_EQUAL(1, value);
	
	value = rtc_inicia(NO_CONECTA);
	TEST_ASSERT_EQUAL(0, value);
}
