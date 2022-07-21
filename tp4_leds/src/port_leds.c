/**************************************************************************************************
 ** (c) Copyright 2019: Ezequiel Acerbo <acerboezequiel@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/

#include "port_leds.h"
#include "errores.h"

/** @file dir_puerto_leds.c
 ** @brief Definición de la biblioteca de leds de puerto GPIO
 **
 ** Libreria para el registro del los errores del sistema.
 **
 **| REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 **|-----|------------|-----------------|---------------------------------------------------------|
 **|   1 | 2022.07.19 | Ezequiel Acerbo | Version inicial de biblioteca de leds de puerot GPIO    |
 */

static uint16_t *dir_puerto_leds;

// Esta funcion enmascara los leds del puerto GPIO
uint16_t mascara_leds(int pos) {
    return (BIT_ALTO << (pos - CORECT_POSITION));
}

void inicializar_leds(uint16_t *leds_virtuales) {
    dir_puerto_leds = leds_virtuales;
    apagar_puerto_led();
}

void prender_led(int pos) {
    if (pos <= 0 || pos > NUM_LEDS)     {
        Alerta("Numero de led invalido");
    }
    else {
        *dir_puerto_leds |= mascara_leds(pos);
    }
}

void apagar_led(int pos) {
    if (pos > NUM_LEDS || pos <= 0) {
        Alerta("Numero de led invalido");
    }
    else {
        *dir_puerto_leds &= ~mascara_leds(pos);
    }
}

void prender_puerto_led(void) {
    *dir_puerto_leds = PORT_ALTO;
}

void apagar_puerto_led(void) {
    *dir_puerto_leds = PORT_BAJO;
}

int consultar_led(int pos) {
    if (pos > NUM_LEDS || pos <= 0) {
        Alerta("Numero de led invalido");
    }
    else {
        uint8_t estado_led = 0;
        estado_led = (mascara_leds(pos) & *dir_puerto_leds) >> (pos - CORECT_POSITION);
        return estado_led;
    }
}

/* Fin del documento port_leds.c*/