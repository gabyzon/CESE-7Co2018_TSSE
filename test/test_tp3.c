#include "unity.h"
#include "tp3.h"

void test_inicializa_leds(void){
	uint16_t puerto_virtual = 0xffff;
	leds_create(&puerto_virtual);
	TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
	
}

