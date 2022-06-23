
/**
 * @file mcu_adapter.c
 *
 * @brief MCU related.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 * @author Daniel Nery <daniel.nery@thunderatz.org>
 *
 * @date 11/2019
 */

#include <stdint.h>

#include "mcu_adapter.h"
#include "gpio.h"

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void mcu_adapter_init(void) {
    HAL_Init();
    MX_GPIO_Init();

    SystemClock_Config();
}

void mcu_adapter_sleep_ms(uint32_t ms) {
    HAL_Delay(ms);
}

uint32_t mcu_adapter_get_tick_ms(void) {
    return HAL_GetTick();
}
