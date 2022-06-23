/**
 * @file main.c
 *
 * @brief Main function
 */

#include "mcu_adapter.h"
#include "button_adapter.h"
#include "leds_adapter.h"

/*****************************************
 * Private Constant Definitions
 *****************************************/

#define LOOP_RATE_MS 100

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    mcu_adapter_init();
    button_adapter_init();
    leds_adapter_init();

    for (;;) {
        if (button_adapter_is_pressed()) {
            leds_adapter_control(LED_NUCLEO, LED_ADAPTER_ACTION_TOGGLE);
        }
    }
}
