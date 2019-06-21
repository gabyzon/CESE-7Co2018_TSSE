#include "stdint.h"
#include <stdbool.h>
#include <string.h>
#include "sapi_i2c.h"

#define I2C_RATE         100000
#define I2C_ADDRESS      0b1101000

void leds_inicia(uint16_t * puerto);
uint8_t rtc_inicia(void);
void visualizar_inicio(uint16_t * puerto);
uint8_t rtc_lectura(void);
void visualizar_lectura(uint16_t * puerto);