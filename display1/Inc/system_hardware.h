/*
 * system_hardware.h
 *
 *  Created on: May 26, 2025
 *      Author: tomasz
 */

#ifndef SYSTEM_HARDWARE_H_
#define SYSTEM_HARDWARE_H_

#include "stm32f429xx.h"
#include "clock.h"
#include "gpio.h"

/*!
 * 	\brief Core peripherals initialization
 *
 * 	- SysTick configuration
 */
void core_init();

/*!
 * 	\brief System initialization
 *
 * 	- clock initialization - clock_init()
 * 	- core initialization - core_init()
 * 	- general purpose initialization - gpio_init()
 */
void hardware_init();



#endif /* SYSTEM_HARDWARE_H_ */
