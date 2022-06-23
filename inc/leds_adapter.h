/**
 * @file led_adapter.h
 *
 * @brief Led adapter control and initialization.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 * @author Felipe Bagni <felipe.bagni@thunderatz.org>
 * @author Daniel Nery <daniel.nery@thunderatz.org>
 *
 * @date 07/2019
 */

#ifndef __LEDS_ADAPTER_H__
#define __LEDS_ADAPTER_H__

#include "led_handler.h"

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief Led colors.
 */
typedef enum led_adapter_color {
    LED_NUCLEO = 0,
} led_adapter_color_t;

/**
 * @brief Led actions.
 */
typedef enum led_adapter_action {
    LED_ADAPTER_ACTION_ON,
    LED_ADAPTER_ACTION_OFF,
    LED_ADAPTER_ACTION_TOGGLE,
} led_adapter_action_t;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief Initializes the led.
 */
void leds_adapter_init(void);

/**
 * @brief Controls the state of the led.
 *
 * @param led_color Color of the led to be controlled.
 * @param action State of the led.
 */
void leds_adapter_control(led_adapter_color_t led_color, led_adapter_action_t action);

#endif // __LEDS_ADAPTER_H__
