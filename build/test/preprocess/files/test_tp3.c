#include "build/temp/_test_tp3.c"
#include "tp3.h"
#include "unity.h"


void test_inicializa_leds(void){

 uint16_t puerto_virtual = 0xffff;

 leds_create(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(7), UNITY_DISPLAY_STYLE_INT);



}
