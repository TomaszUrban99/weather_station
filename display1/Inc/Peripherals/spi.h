/*
 * spi.h
 *
 *  Created on: May 26, 2025
 *      Author: tomasz
 */

#ifndef PERIPHERALS_SPI_H_
#define PERIPHERALS_SPI_H_

#include "gpio.h"
#include "stm32f429xx.h"

/* SPI1 (STM32F429ZI)
 *
 *	Ports:
 *		- port A
 *		- port B
 *
 * 	Pins:
 *	- SPI1 MOSI: 	B5
 *	- SPI1 MISO: 	B4
 *	- SPI1 SCK: 	B3
 *	- SPI1 CS: 		A4
 *
 *	Alternate functions code: AF5
 */

#define SPI1_MOSI_PIN				5
#define SPI1_MISO_PIN				4
#define SPI1_SCK_PIN				3
#define SPI1_CS_PIN			    4

#define SPI1_ALTERNATE_FUNCTION_CODE		5 	/* For chosen pins AF5 */
/* #define SPI1_CS_MS_PIN */

#define BR_PRESC_4							1

struct spi {

	SPI_TypeDef *_spi;

};

/*!
 * 	\brief Initialize SPI pins
 */
void init_pins_spi(struct spi *self);

/*!
 * 	\brief Initialize SPI master
 */
void init_master_spi(struct spi *self);


#endif /* PERIPHERALS_SPI_H_ */
