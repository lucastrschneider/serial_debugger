/**
 * @file button_handler.h
 *
 * @brief Button handler initialization and read.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 01/2020
 */

#ifndef __BUTTON_HANDLER_H__
#define __BUTTON_HANDLER_H__

#include <stdbool.h>

#include "gpio.h"

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief Button handler structure.
 */
typedef struct button_handler {
    GPIO_TypeDef* port;
    uint16_t      pin;
    GPIO_PinState pressed_state;
} button_handler_t;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief Initializes the button handler.
 *
 * @param p_button Pointer to button handler to be Initialized.
 */
void button_handler_init(button_handler_t* p_button);

/**
 * @brief Provides the state of the chosen button.
 *
 * @param p_button Pointer to button handler to be analysed.
 *
 * @return State of the chosen button.
 */
bool button_handler_get_state(button_handler_t* p_button);

/**
 * @brief Debounces the input and provides the state of the chosen button.
 *
 * @note This function takes at least DEBOUNCE_DELAY_MS to finish, because it
 *       waits until the signal is stable.
 *
 * @param p_button Pointer to button handler to be analysed.
 *
 * @return State of the chosen button.
 */
bool button_handler_get_state_debounced(button_handler_t* p_button);

#endif // __BUTTON_HANDLER_H__
