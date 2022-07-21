#include "build/test/mocks/mock_errores.h"
#include "src/port_leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"












static uint16_t leds_virtuales;



void setUp(void)

{

    inicializar_leds(&leds_virtuales);

}





void test_inicializar_puerto_leds_y_apagar_todos()

{

    uint16_t leds_virtuales = 0xffff;

    inicializar_leds(&leds_virtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_led_especifico()

{

    prender_led(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 0)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_led_especifico()

{

    prender_led(3);

    apagar_led(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_varios_leds_a_la_vez()

{

    prender_led(3);

    prender_led(4);

    prender_led(3);

    apagar_led(4);

    apagar_led(4);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 2)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_todo_el_puerto_de_leds()

{

    prender_puerto_led();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xffff)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todo_el_puerto_de_leds()

{

    apagar_puerto_led();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((leds_virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_HEX16);

}





void test_revisar_parametro_invalido_superior_led_prendido()

{

    RegistrarMensaje_CMockExpect(81, ALERTA, "prender_led", 0, "Numero de led invalido");

    RegistrarMensaje_CMockIgnoreArg_linea(82);

    RegistrarMensaje_CMockIgnoreArg_funcion(83);

    prender_led(17);

}





void test_revisar_parametro_invalido_superior_led_apagado()

{

    RegistrarMensaje_CMockExpect(90, ALERTA, "apagar_led", 0, "Numero de led invalido");

    RegistrarMensaje_CMockIgnoreArg_linea(91);

    RegistrarMensaje_CMockIgnoreArg_funcion(92);

    apagar_led(17);

}





void test_revisar_parametro_invalido_inferior_led_prendido()

{

    RegistrarMensaje_CMockExpect(99, ALERTA, "prender_led", 0, "Numero de led invalido");

    RegistrarMensaje_CMockIgnoreArg_linea(100);

    RegistrarMensaje_CMockIgnoreArg_funcion(101);

    prender_led(0);

}





void test_revisar_parametro_invalido_inferior_led_apagado()

{

    RegistrarMensaje_CMockExpect(108, ALERTA, "apagar_led", 0, "Numero de led invalido");

    RegistrarMensaje_CMockIgnoreArg_linea(109);

    RegistrarMensaje_CMockIgnoreArg_funcion(110);

    apagar_led(0);

}





void test_leer_estado_prendido_de_un_led()

{

    apagar_puerto_led();

    prender_led(9);

    uint8_t estado_led = consultar_led(9);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((estado_led)), (

   ((void *)0)

   ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_HEX16);

}





void test_leer_estado_apagado_de_un_led()

{

    prender_puerto_led();

    apagar_led(11);

    uint8_t estado_led = consultar_led(11);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((estado_led)), (

   ((void *)0)

   ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_HEX16);

}
