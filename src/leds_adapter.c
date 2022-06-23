/**
 * @file led_adapter.c
 *
 * @brief Led adapter control and initialization.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 * @author Felipe Bagni <felipe.bagni@thunderatz.org>
 * @author Daniel Nery <daniel.nery@thunderatz.org>
 *
 * @date 09/2019
 */

#include "leds_adapter.h"

/*****************************************
 * Private Variables
 *****************************************/

static led_handler_t m_leds[] = {
    {
        /* LED_SHILED */
        .port = GPIOA,
        .pin = GPIO_PIN_5,
    }
};

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void leds_adapter_init(void) {
    led_handler_init(&m_leds[LED_NUCLEO]);
}

void leds_adapter_control(led_adapter_color_t led_color, led_adapter_action_t action) {
    switch (action) {
        case LED_ADAPTER_ACTION_TOGGLE: {
            led_handler_control(&m_leds[led_color], LED_HANDLER_GPIO_ACTION_TOGGLE);
            break;
        }

        case LED_ADAPTER_ACTION_ON: {
            led_handler_control(&m_leds[led_color], LED_HANDLER_GPIO_ACTION_SET);
            break;
        }

        case LED_ADAPTER_ACTION_OFF: {
            led_handler_control(&m_leds[led_color], LED_HANDLER_GPIO_ACTION_RESET);
            break;
        }
    }
}
