#include "build/temp/_test_tp3.c"
#include "tp3.h"
#include "unity.h"




void test_inicializa_leds(void){

 uint16_t puerto_virtual = 0xffff;

 leds_inicia(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(8), UNITY_DISPLAY_STYLE_INT);

}



void test_inicializa_rtc(void){

 uint16_t puerto_virtual = 0x0000;

 

_Bool 

     value=0;



 value = rtc_inicia(1);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((value)), (

((void *)0)

), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT);



 value = rtc_inicia(2);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((value)), (

((void *)0)

), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}
