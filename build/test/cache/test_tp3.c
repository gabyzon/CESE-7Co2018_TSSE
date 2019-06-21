#include "build/temp/_test_tp3.c"
#include "mock_sapi_i2c.h"
#include "tp3.h"
#include "unity.h"


void test_inicializa_leds(void){

 uint16_t puerto_virtual = 0xffff;

 leds_inicia(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}



void test_inicializa_rtc(void){



 static uint8_t val;

 uint8_t expectedStateOk = 1;

 uint8_t expectedStateFail = 0;





 i2cInit_CMockExpectAndReturn(33, I2C0, 100000, 1);

 val = rtc_inicia();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateOk)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);





 i2cInit_CMockExpectAndReturn(38, I2C0, 100000, 0);

 val = rtc_inicia();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateFail)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);



}



void test_visualiza_inicio_rtc(void){



 uint16_t puerto_virtual = 0x0000;

 static uint8_t val;





 i2cInit_CMockExpectAndReturn(50, I2C0, 100000, 1);

 val = rtc_inicia();

 visualizar_inicio(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0001)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);





 i2cInit_CMockExpectAndReturn(56, I2C0, 100000, 0);

 val = rtc_inicia();

 visualizar_inicio(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0002)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}



void test_lectura_rtc(void){



 static uint8_t val;

 uint8_t expectedStateOk = 1;

 uint8_t expectedStateFail = 0;



    static uint8_t dataToReadBuffer;

    static uint8_t receiveDataBuffer;







 i2cRead_CMockExpectAndReturn(73, I2C0, 0b1101000, &dataToReadBuffer, 1, (1), &receiveDataBuffer, 1, (1), 1);

 val = rtc_lectura();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateOk)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);





 i2cRead_CMockExpectAndReturn(78, I2C0, 0b1101000, &dataToReadBuffer, 1, (1), &receiveDataBuffer, 1, (1), 0);

 val = rtc_lectura();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateFail)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);



}



void test_visualiza_lectura_rtc(void){



 uint16_t puerto_virtual = 0x0000;

 static uint8_t val;



 static uint8_t dataToReadBuffer;

    static uint8_t receiveDataBuffer;





 i2cRead_CMockExpectAndReturn(93, I2C0, 0b1101000, &dataToReadBuffer, 1, (1), &receiveDataBuffer, 1, (1), 1);

 val = rtc_lectura();

 visualizar_lectura(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0004)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);





 i2cRead_CMockExpectAndReturn(99, I2C0, 0b1101000, &dataToReadBuffer, 1, (1), &receiveDataBuffer, 1, (1), 0);

 val = rtc_lectura();

 visualizar_lectura(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0008)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_INT);



}



void test_escritura_rtc(void){



 static uint8_t val;

 uint8_t expectedStateOk = 1;

 uint8_t expectedStateFail = 0;

 static uint8_t transmitDataBuffer[2];





 i2cWrite_CMockExpectAndReturn(114, I2C0, 0b1101000, transmitDataBuffer, 2, (1), 1);

 val = rtc_escritura();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateOk)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);





 i2cWrite_CMockExpectAndReturn(119, I2C0, 0b1101000, transmitDataBuffer, 2, (1), 0);

 val = rtc_escritura();

 UnityAssertEqualNumber((UNITY_INT)((expectedStateFail)), (UNITY_INT)((val)), (

((void *)0)

), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_INT);

}



void test_visualiza_escritura_rtc(void){



 uint16_t puerto_virtual = 0x0000;

 static uint8_t val;



 static uint8_t transmitDataBuffer[2];





 i2cWrite_CMockExpectAndReturn(132, I2C0, 0b1101000, transmitDataBuffer, 2, (1), 1);

 val = rtc_escritura();

 visualizar_escritura(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0010)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(135), UNITY_DISPLAY_STYLE_INT);





 i2cWrite_CMockExpectAndReturn(138, I2C0, 0b1101000, transmitDataBuffer, 2, (1), 0);

 val = rtc_escritura();

 visualizar_escritura(&puerto_virtual);

 UnityAssertEqualNumber((UNITY_INT)((0x0020)), (UNITY_INT)((puerto_virtual)), (

((void *)0)

), (UNITY_UINT)(141), UNITY_DISPLAY_STYLE_INT);



}
