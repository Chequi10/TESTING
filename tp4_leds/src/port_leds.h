/**************************************************************************************************
 ** (c) Copyright 2019: Ezequiel Acerbo <acerboezequiel@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/


#ifndef _PORT_LEDS_H
#define _PORT_LEDS_H

/** @file dir_puerto_leds.h
 ** @brief Declaraciones de la biblioteca de leds de puerto GPIO
 **
 ** Libreria para el registro del los errores del sistema.
 **
 **| REV | YYYY.MM.DD | Autor           | Descripción de los cambios                              |
 **|-----|------------|-----------------|---------------------------------------------------------|
 **|   1 | 2022.07.19 | Ezequiel Acerbo | Version inicial de biblioteca de leds de puerot GPIO    |
 */

#include <stdint.h>
#define BIT_BAJO            0
#define BIT_ALTO            1
#define  PORT_ALTO          0xffff
#define  PORT_BAJO          0
#define CORECT_POSITION     1
#define NUM_LEDS            16 

/**
 * @brief Configura el puerto de leds, con todos los leds apagados
 * @param dir dirección al GPIO de los leds
 */
void inicializar_leds(uint16_t *dir);

/**
 * @brief apaga un led específico
 * @param pos  posición del puerto a apagar
 */
void apagar_led(int pos);

/**
 * @brief prende un led específico
 * @param pos posición del puerto a encender
 */
void prender_led(int pos);

/**
 * @brief consulta estado de un led específico
 * @param pos posición del puerto a leer
 */
int consultar_led(int pos);

/**
 * @brief apaga todo el puerto de leds
 */
void apagar_puerto_led();

/**
 * @brief prende todo el puerto de leds
 */
void prender_puerto_led();

#endif /*_PORT_LEDS_H*/

/* Fin del documento port_leds.h*/