#include "stdint.h"
#include <stdbool.h>
//#include <string.h>
//#include "sapi.h"

#define	CONECTA		1
#define	NO_CONECTA	2

void leds_inicia(uint16_t * puerto);
bool rtc_inicia(uint8_t estado);