#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>

void LedsInit(uint16_t * direccion);

void LedTurnOn(uint8_t led);

void LedTurnOff(uint8_t led);

#endif