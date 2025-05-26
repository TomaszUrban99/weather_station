#include "spi.h"

void init_pins_spi(struct spi *self){

	/* Assume that clock access to pins are enabled */

	/******************************* SPI1 ************************************/

	/* MOSI */
	GPIOB->MODER &= ~(3UL << (SPI1_MOSI_PIN * 2UL));
	GPIOB->MODER |= (ALTERNATE_FUNCTION << (SPI1_MOSI_PIN * 2UL));

	/* Set alternate function */
	GPIOB->AFR[0] &= ~(15UL << (SPI1_MOSI_PIN * 4UL));
	GPIOB->AFR[0] |= (SPI1_ALTERNATE_FUNCTION_CODE << (SPI1_MOSI_PIN * 4UL));

	/* MISO */
	GPIOB->MODER &= ~(3UL << (SPI1_MISO_PIN * 2UL));
	GPIOB->MODER |= (ALTERNATE_FUNCTION << (SPI1_MISO_PIN * 4UL));

	/* Set alternate function */
	GPIOB->AFR[0] &= ~(15UL << (SPI1_MISO_PIN * 4UL));
	GPIOB->AFR[0] |= (SPI1_ALTERNATE_FUNCTION_CODE << (SPI1_MISO_PIN * 4UL));

	/* SCK */
	GPIOB->MODER &= ~(3UL << (SPI1_SCK_PIN * 2UL));
	GPIOB->MODER |= (ALTERNATE_FUNCTION << (SPI1_SCK_PIN * 4UL));

	/* Set alternate function */
	GPIOB->AFR[0] &= ~(15UL << (SPI1_SCK_PIN * 4UL));
	GPIOB->AFR[0] |= (SPI1_ALTERNATE_FUNCTION_CODE << (SPI1_SCK_PIN * 4UL));

	/* OSPEED */
	GPIOB->OSPEEDR &= ~(3UL << (SPI1_SCK_PIN * 2UL));
	GPIOB->OSPEEDR &= ~(3UL << (SPI1_MISO_PIN * 2UL));
	GPIOB->OSPEEDR &= ~(3UL << (SPI1_MOSI_PIN * 2UL));

	GPIOB->OSPEEDR |= (3UL << (SPI1_SCK_PIN * 2UL)) | (3UL << (SPI1_MISO_PIN * 2UL)) | (3UL << (SPI1_MOSI_PIN));

	/* Set slave select pins */
	GPIOA->MODER &= ~(3UL << (SPI1_CS_PIN * 2UL));
	GPIOA->MODER |= (GENERAL_PURPOSE_OUTPUT << (SPI1_CS_PIN * 2UL));

	GPIOA->OSPEEDR &= ~(3UL << (SPI1_CS_PIN * 2UL));
	GPIOA->OSPEEDR |= (VERY_FAST_OUTPUT << (SPI1_CS_PIN * 2UL));

	/****************************************************************************/
}

void init_master_spi(struct spi *self){

	/* Enable clock access to SPI1 peripheral */
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

	/* Initialize pins */
	init_pins_spi(self);

	self->_spi->CR1 |= SPI_CR1_MSTR;

	/* Define serial clock baud rate */
	self->_spi->CR1 &= ~(7UL << SPI_CR1_BR_Pos);
	self->_spi->CR1 |= (BR_PRESC_4 << SPI_CR1_BR_Pos);
}
