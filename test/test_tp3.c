#include "unity.h"
#include "tp3.h"

void test_inicializa_leds(void){
	uint16_t puerto_virtual = 0xffff;
	leds_inicia(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

void test_inicializa_rtc(void){
	uint16_t puerto_virtual = 0x0000;
	bool value=0;
	
	value = rtc_virtual_inicia(CONECTA, &puerto_virtual);
	TEST_ASSERT_EQUAL(1, value);
	
	value = rtc_virtual_inicia(NO_CONECTA, &puerto_virtual);
	TEST_ASSERT_EQUAL(0, value);
}

void test_leds_de_inicio(void){
	uint16_t puerto_virtual = 0x0000;
	bool value=0;
	
	value = rtc_virtual_inicia(CONECTA, &puerto_virtual);
	TEST_ASSERT_EQUAL(0x0001, puerto_virtual);
	
	//value = rtc_virtual_inicia(NO_CONECTA, &puerto_virtual);
	//TEST_ASSERT_EQUAL(0x0002, puerto_virtual);
}