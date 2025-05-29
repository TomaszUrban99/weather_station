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
#define SPI1_CS_PIN			    	4

#define SPI1_ALTERNATE_FUNCTION_CODE		5 	/* For chosen pins AF5 */
/* #define SPI1_CS_MS_PIN */

#define BR_PRESC_4								1

#define TX_SPI1_DMA2_STREAM_NUMBER				3	/* stream number for SPI1 TX */
#define RX_SPI1_DMA2_STREAM_NUMBER				2	/* stream number for SPI1 RX */

#define SPI1_TX_BUFFER_LENGTH					256
#define SPI1_RX_BUFFER_LENGTH					256

struct spi {

	SPI_TypeDef *_spi;

	/************* DMA *************/

	DMA_Stream_TypeDef *_dma_stream_tx;
	DMA_Stream_TypeDef *_dma_stream_rx;

	DMA_TypeDef *_dma;

	uint8_t _cs_portnumber;

	uint8_t _dma_tx_buffer[SPI1_TX_BUFFER_LENGTH]; /* SPI DMA TX buffer */
	uint8_t _dma_rx_buffer[SPI1_RX_BUFFER_LENGTH]; /* SPI DMA RX buffer */

};

/*!
 * 	\brief Init DMA stream for SPI
 */
void init_dma_spi(struct spi *self);

/*!
 * 	\brief Init DMA TX stream for spi
 */
void init_dma_tx_spi(struct spi *self);

/*!
 *  \brief Init DMA RX stream for spi
 */
void init_dma_rx_spi(struct spi *self);

/*!
 * 	\brief Initialize SPI pins
 */
void init_pins_spi(struct spi *self);

/*!
 * 	\brief Initialize SPI master
 */
void init_master_spi(struct spi *self);


#endif /* PERIPHERALS_SPI_H_ */
