/**
 * @file main.c
 *
 * @brief Main function
 */

#include <stdio.h>

#include "mcu_adapter.h"
#include "button_adapter.h"
#include "leds_adapter.h"

#include "usart.h"

/*****************************************
 * Private Constant Definitions
 *****************************************/

#define SENDING_RATE_MS 200

/*****************************************
 * Private Variables
 *****************************************/

static bool sending = false;

static uint32_t sending_timer = 0;
static uint16_t counter = 0;

/*****************************************
 * Main Function
 *****************************************/

int main(void) {
    mcu_adapter_init();
    button_adapter_init();
    leds_adapter_init();

    MX_USART2_UART_Init();
    uint8_t str[50];

    for (;;) {
        if (button_adapter_is_pressed()) {
            sending = !sending;
        }

        if (sending) {
            if (get_timer_ms(sending_timer) > SENDING_RATE_MS) {
                reset_timer_ms(sending_timer);
                leds_adapter_control(LED_NUCLEO, LED_ADAPTER_ACTION_TOGGLE);

                sprintf((char*) str, "Msg: %04d\r\n", counter);
                HAL_UART_Transmit(&huart2, str, 11, 50);

                counter++;
            }
        } else {
            leds_adapter_control(LED_NUCLEO, LED_ADAPTER_ACTION_OFF);
            counter = 0;
        }
    }
}
