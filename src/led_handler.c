/**
 * @file led_handler.c
 *
 * @brief GPIO handler control and initialization.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 * @author Daniel Nery <daniel.nery@thunderatz.org>
 *
 * @date 07/2019
 */

#include "led_handler.h"

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void led_handler_init(led_handler_t* p_gpio) {
    led_handler_control(p_gpio, LED_HANDLER_GPIO_ACTION_RESET);
}

void led_handler_control(led_handler_t* p_gpio, led_handler_gpio_action_t action) {
    switch (action) {
        case LED_HANDLER_GPIO_ACTION_TOGGLE: {
            HAL_GPIO_TogglePin(p_gpio->port, p_gpio->pin);
            break;
        }

        case LED_HANDLER_GPIO_ACTION_SET: {
            HAL_GPIO_WritePin(p_gpio->port, p_gpio->pin, GPIO_PIN_SET);
            break;
        }

        case LED_HANDLER_GPIO_ACTION_RESET: {
            HAL_GPIO_WritePin(p_gpio->port, p_gpio->pin, GPIO_PIN_RESET);
            break;
        }
    }
}
