#include "unity.h"
#include "tp3.h"
//#include <string.h>

void test_inicializa_leds(void){
	uint16_t puerto_virtual = 0xffff;
	leds_create(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

void test_inicializa_rtc(void){
	uint16_t puerto_virtual = 0x0000;
	bool value=0;
	value = rtc_inicia();
	TEST_ASSERT_EQUAL(1, value);
}

