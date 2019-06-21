#include "build/temp/_test_tp3.c"
#include "mock_sapi_i2c.h"
#include "tp3.h"
#include "unity.h"




void test_inicializa_leds(void){

 uint16_t puerto_virtual = 0xffff;

 leds_inicia(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(9), UNITY_DISPLAY_STYLE_INT);

}



void test_inicializa_rtc(void){



 static uint8_t val;

 uint8_t expectedStateOk = 1;

 uint8_t expectedStateFail = 0;





 i2cInit_CMockExpectAndReturn(19, I2C0, 100000, 1);

 val = rtc_inicia();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateOk)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);





 i2cInit_CMockExpectAndReturn(24, I2C0, 100000, 0);

 val = rtc_inicia();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateFail)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_INT);



}



void test_visualiza_inicio_rtc(void){



 uint16_t puerto_virtual = 0x0000;

 static uint8_t val;





 i2cInit_CMockExpectAndReturn(36, I2C0, 100000, 1);

 val = rtc_inicia();

 visualizar_inicio(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0001)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);





 i2cInit_CMockExpectAndReturn(42, I2C0, 100000, 0);

 val = rtc_inicia();

 visualizar_inicio(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0002)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

}



void test_lectura_rtc(void){



 static uint8_t val;

 uint8_t expectedStateOk = 1;

 uint8_t expectedStateFail = 0;



    static uint8_t dataToReadBuffer;

    static uint8_t receiveDataBuffer;







 i2cRead_CMockExpectAndReturn(59, I2C0, 0b1101000, &dataToReadBuffer, 1, (1), &receiveDataBuffer, 1, (1), 1);

 val = rtc_lectura();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateOk)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);





 i2cRead_CMockExpectAndReturn(64, I2C0, 0b1101000, &dataToReadBuffer, 1, (1), &receiveDataBuffer, 1, (1), 0);

 val = rtc_lectura();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateFail)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);



}



void test_visualiza_lectura_rtc(void){



 uint16_t puerto_virtual = 0x0000;

 static uint8_t val;



 static uint8_t dataToReadBuffer;

    static uint8_t receiveDataBuffer;





 i2cRead_CMockExpectAndReturn(79, I2C0, 0b1101000, &dataToReadBuffer, 1, (1), &receiveDataBuffer, 1, (1), 1);

 val = rtc_lectura();

 visualizar_lectura(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0004)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);





 i2cRead_CMockExpectAndReturn(85, I2C0, 0b1101000, &dataToReadBuffer, 1, (1), &receiveDataBuffer, 1, (1), 0);

 val = rtc_lectura();

 visualizar_lectura(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0004)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);



}
