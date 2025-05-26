/*
 * gpio.h
 *
 *  Created on: May 24, 2025
 *      Author: tomasz
 */

#ifndef PERIPHERALS_GPIO_H_
#define PERIPHERALS_GPIO_H_

#include "stm32f429xx.h"

#define GENERAL_PURPOSE_OUTPUT			1UL
#define ALTERNATE_FUNCTION				2UL

#define VERY_FAST_OUTPUT				3UL

void gpio_init();

void gpio_toggle();

#endif /* PERIPHERALS_GPIO_H_ */
