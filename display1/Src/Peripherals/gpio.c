#include "gpio.h"

void gpio_init(){

	/* Enable clock access to GPIOA */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/* Enable clock access to GPIOB */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	/* Set output mode */
	GPIOB->MODER &= ~GPIO_MODER_MODER0_Msk;
	GPIOB->MODER |= (1UL << GPIO_MODER_MODER0_Pos);
}

void gpio_toggle(){

	/* Toggle GPIOB0 */
	GPIOB->ODR ^= GPIO_ODR_OD0;
}

