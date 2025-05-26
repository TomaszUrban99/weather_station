#include "clock.h"

void clock_init(){

	/* No crystal on board - HSI as clock source */
	RCC->CR |= RCC_CR_HSION;

	/* Wait until clock source is stable */
	while ( !(RCC->CR & RCC_CR_HSIRDY)){}

	/* Later stages */
	SystemCoreClockUpdate();

	/* When the Ethernet is in use AHB frequency must be at least 25 MHz */
}
