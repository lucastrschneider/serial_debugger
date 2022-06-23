/**
 * @file button_adapter.c
 *
 * @brief Button adapter initialization and control.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 01/2020
 */

#include "button_adapter.h"

#include "button_handler.h"

/*****************************************
 * Private Variables
 *****************************************/

static button_handler_t m_button = {
    .port = GPIOC,
    .pin = GPIO_PIN_13,
    .pressed_state = GPIO_PIN_RESET,
};

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void button_adapter_init(void) {
    MX_GPIO_Init();

    button_handler_init(&m_button);
}

bool button_adapter_is_pressed() {
    if (button_handler_get_state(&m_button)) {
        if (button_handler_get_state_debounced(&m_button)) {
            while (button_handler_get_state_debounced(&m_button))
                ;

            return true;
        }
    }

    return false;
}
