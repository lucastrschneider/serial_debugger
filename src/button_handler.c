/**
 * @file button_handler.c
 *
 * @brief Button handler initialization and read.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 * @author Lucas Schneider <lucas.schneider@thunderatz.org>
 *
 * @date 01/2020
 */

#include "button_handler.h"
#include "mcu_adapter.h"

/*****************************************
 * Private Constants
 *****************************************/

#define DEBOUNCE_DELAY_MS 5

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void button_handler_init(button_handler_t* p_button) {
    (void) p_button;
}

bool button_handler_get_state(button_handler_t* p_button) {
    return (HAL_GPIO_ReadPin(p_button->port, p_button->pin) == p_button->pressed_state);
}

bool button_handler_get_state_debounced(button_handler_t* p_button) {
    uint32_t debounce_timer;
    bool button_state = (HAL_GPIO_ReadPin(p_button->port, p_button->pin) == p_button->pressed_state);

    reset_timer_ms(debounce_timer);

    while (get_timer_ms(debounce_timer) < DEBOUNCE_DELAY_MS) {
        bool actual_state = (HAL_GPIO_ReadPin(p_button->port, p_button->pin) == p_button->pressed_state);

        if (button_state != actual_state) {
            button_state = actual_state;
            reset_timer_ms(debounce_timer);
        }
    }

    return button_state;
}
