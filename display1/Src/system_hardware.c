#include "system_hardware.h"

void core_init(){

	/* Enable SysTick interrupt */
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	SysTick->LOAD = (SystemCoreClock & 0x00FFFFFF) - 1;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void hardware_init(){

	/* Clock init - initialize clocking - header file clock.h */
	clock_init();

	/* Core initialization */

	/* Initialize peripherals */
	gpio_init();
}
