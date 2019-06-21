#include "stdint.h"
#include <stdbool.h>
#include <string.h>
#include "sapi_i2c.h"

#define I2C_RATE         100000

void leds_inicia(uint16_t * puerto);
uint8_t rtc_inicia(void);
void visualizar_inicio(uint16_t * puerto);