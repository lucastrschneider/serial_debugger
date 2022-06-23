/**
 * @file button_adapter.h
 *
 * @brief Button adapter initialization and read.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 01/2020
 */

#ifndef __BUTTON_ADAPTER_H__
#define __BUTTON_ADAPTER_H__

#include <stdbool.h>

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief Initializes the button adapter.
 */
void button_adapter_init(void);

/**
 * @brief Checks it the button was pressed and, if true, blocks until it is released.
 *
 * @note First, the GPIO pin is checked, and, if it is pressed, we start the debouncing
 *       routine, otherwise, we just return false immediately.
 *       The debouncing routine checks to see if the button state changed in a period of time,
 *       and if it has, it waits until the signal is stable.
 *       We countinue to check the state of the pin until it is released.
 *
 * @return True if pressed, false otherwise.
 */
bool button_adapter_is_pressed(void);

#endif // __BUTTON_ADAPTER_H__
