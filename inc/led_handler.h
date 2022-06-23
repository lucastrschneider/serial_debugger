/**
 * @file led_handler.h
 *
 * @brief Led handler control and initialization.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 * @author Daniel Nery <daniel.nery@thunderatz.org>
 *
 * @date 07/2019
 */

#ifndef __LED_HANDLER_H__
#define __LED_HANDLER_H__

#include <stdint.h>

#include "gpio.h"

/*****************************************
 * Public Types
 *****************************************/

/**
 * @brief GPIO type.
 */
typedef struct led_handler {
    GPIO_TypeDef* port;
    uint16_t      pin;
} led_handler_t;

/**
 * @brief Possible actions for the gpio.
 */
typedef enum led_handler_gpio_action {
    LED_HANDLER_GPIO_ACTION_SET,
    LED_HANDLER_GPIO_ACTION_RESET,
    LED_HANDLER_GPIO_ACTION_TOGGLE,
} led_handler_gpio_action_t;

/*****************************************
 * Public Functions Prototypes
 *****************************************/

/**
 * @brief Initializes the led handler.
 *
 * @param p_gpio Pointer to led gpio handler.
 */
void led_handler_init(led_handler_t* p_gpio);

/**
 * @brief Initializes the led handler.
 *
 * @param p_gpio Pointer to led gpio handler.
 * @param action Led gpio action.
 */
void led_handler_control(led_handler_t* p_gpio, led_handler_gpio_action_t action);

#endif // __LED_HANDLER_H__
