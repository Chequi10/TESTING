/**************************************************************************************************
 ** (c) Copyright 2019: Ezequiel Acerbo <acerboezequiel@gmail.com>
 ** ALL RIGHTS RESERVED, DON'T USE OR PUBLISH THIS FILE WITHOUT AUTORIZATION
 *************************************************************************************************/


#include "unity.h"
#include "port_leds.h"
#include "mock_errores.h"


/** @file test_tp4_leds.c
 ** @brief Archivo de pruebas Ceedling para la biblioteca de leds de puerot GPIO
 **
 ** Libreria para el registro del los errores del sistema.
 **
 **| REV | YYYY.MM.DD | Autor           | Descripción de los cambios                               |
 **|-----|------------|-----------------|----------------------------------------------------------|
 **|   1 | 2022.07.19 | Ezequiel Acerbo | Version inicial de archivo de pruebas biblioteca de leds |
   |     |            |                 | de puerot GPIO                                           |
 */

static uint16_t leds_virtuales; 

void setUp(void)
{
    inicializar_leds(&leds_virtuales);
}

// Apagar todos los leds al inicializar el puerto de leds
void test_inicializar_puerto_leds_y_apagar_todos()
{
    uint16_t leds_virtuales = 0xffff; 
    inicializar_leds(&leds_virtuales);
    TEST_ASSERT_EQUAL_HEX16(0, leds_virtuales);
}

// Prender un led específico
void test_prender_led_especifico()
{
    prender_led(1);
    TEST_ASSERT_EQUAL_HEX16(1 << 0, leds_virtuales);
}

// Apagar un led específico
void test_apagar_led_especifico()
{
    prender_led(3);
    apagar_led(3);
    TEST_ASSERT_EQUAL_HEX16(0, leds_virtuales);
}

// Apagar y prender varios leds a ala vez
void test_prender_y_apagar_varios_leds_a_la_vez()
{
    prender_led(3);
    prender_led(4);
    prender_led(3);
    apagar_led(4);
    apagar_led(4);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, leds_virtuales);
}

// Prender todo el puerto de leds 
void test_prender_todo_el_puerto_de_leds()
{
    prender_puerto_led();
    TEST_ASSERT_EQUAL_HEX16(0xffff, leds_virtuales);
}

// Apagar todo el puerto de leds 
void test_apagar_todo_el_puerto_de_leds()
{
    apagar_puerto_led();
    TEST_ASSERT_EQUAL_HEX16(0, leds_virtuales);
}

// Revisar los parámetros de las funciones (fuera de rango superior)
void test_revisar_parametro_invalido_superior_led_prendido()
{
    RegistrarMensaje_Expect(ALERTA, "prender_led", 0, "Numero de led invalido");
    RegistrarMensaje_IgnoreArg_linea();
    RegistrarMensaje_IgnoreArg_funcion();
    prender_led(17);
}

// Revisar los parámetros de las funciones (fuera de rango superior)
void test_revisar_parametro_invalido_superior_led_apagado()
{
    RegistrarMensaje_Expect(ALERTA, "apagar_led", 0, "Numero de led invalido");
    RegistrarMensaje_IgnoreArg_linea();
    RegistrarMensaje_IgnoreArg_funcion();
    apagar_led(17);
}

// Revisar los parámetros de las funciones (fuera de rango inferior)
void test_revisar_parametro_invalido_inferior_led_prendido()
{
    RegistrarMensaje_Expect(ALERTA, "prender_led", 0, "Numero de led invalido");
    RegistrarMensaje_IgnoreArg_linea();
    RegistrarMensaje_IgnoreArg_funcion();
    prender_led(0);
}

// Revisar los parámetros de las funciones (fuera de rango inferior)
void test_revisar_parametro_invalido_inferior_led_apagado()
{
    RegistrarMensaje_Expect(ALERTA, "apagar_led", 0, "Numero de led invalido");
    RegistrarMensaje_IgnoreArg_linea();
    RegistrarMensaje_IgnoreArg_funcion();
    apagar_led(0);
}

// Leer el estado de un led específico (cuando está prendido)
void test_leer_estado_prendido_de_un_led()
{
    apagar_puerto_led();
    prender_led(9);
    uint8_t estado_led = consultar_led(9);
    TEST_ASSERT_EQUAL_HEX16(1, estado_led);
}

// Leer el estado de un led específico (cuando está apagado)
void test_leer_estado_apagado_de_un_led()
{
    prender_puerto_led();
    apagar_led(11);
    uint8_t estado_led = consultar_led(11);
    TEST_ASSERT_EQUAL_HEX16(0, estado_led);
}

/* Fin del documento test_tp4_leds.c*/