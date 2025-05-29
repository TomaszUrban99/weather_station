#include "spi.h"

void init_dma_spi(struct spi *self){

	/* Enable clock access to DMA2 */
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

	/* Enable DMA2 Stream 3 */
	NVIC_SetPriority(DMA2_Stream3_IRQn,15);
	NVIC_EnableIRQ(DMA2_Stream3_IRQn);

	/* Enable interrupt for DMA2 stream 2 */
	NVIC_SetPriority(DMA2_Stream2_IRQn,15);
	NVIC_EnableIRQ(DMA2_Stream2_IRQn);
}

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
	GPIOA->MODER &= ~(3UL << (self->_cs_portnumber * 2UL));
	GPIOA->MODER |= (GENERAL_PURPOSE_OUTPUT << (self->_cs_portnumber * 2UL));

	GPIOA->OSPEEDR &= ~(3UL << (self->_cs_portnumber * 2UL));
	GPIOA->OSPEEDR |= (VERY_FAST_OUTPUT << (self->_cs_portnumber * 2UL));

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

	/* Configure CPOL and CPHA */
	self->_spi->CR1 &= ~SPI_CR1_CPOL;
	self->_spi->CR1 &= ~SPI_CR1_CPHA;

	/* Data frame format */
	self->_spi->CR1 &= ~SPI_CR1_DFF; /* Set 8-bit format */

	/* MSB first */
	self->_spi->CR1 &= ~SPI_CR1_LSBFIRST; /* MSB first */

	/* NSS should be software managed */
	self->_spi->CR1 |= SPI_CR1_SSI | SPI_CR1_SSM;

	/* Set CS */
	GPIOE->BSRR |= (1U << self->_cs_portnumber);

	while(!(GPIOE->ODR & (1U << self->_cs_portnumber))){}

	/* Enable SPI */
	self->_spi->CR1 |= SPI_CR1_SPE;

	/* Init DMA2 */
	init_dma_spi(self);
}

void init_dma_tx_spi(struct spi *self){

	/* Disable DMA stream */
	self->_dma_stream_tx->CR &= ~DMA_SxCR_EN;

	/* Wait until DMA stream enable bit is 0 */
	while((self->_dma_stream_tx->CR & DMA_SxCR_EN)){}

	/* Clear all interrupt flags related to DMA stream */
	self->_dma->LIFCR |=  (0xFU << TX_SPI1_DMA2_STREAM_NUMBER * 8U);

	/* Set peripheral address */
	self->_dma_stream_tx->PAR = (uint32_t)(& self->_spi->DR);

	/* Set source memory address */
	self->_dma_stream_tx->M0AR = (uint32_t)(self->_dma_tx_buffer);

	/* Set number of transfers */
	self->_dma_stream_tx->NDTR = (uint16_t) SPI1_TX_BUFFER_LENGTH;

	/* Select channel */
	self->_dma_stream_tx->CR &= ~DMA_SxCR_CHSEL_Msk;
	self->_dma_stream_tx->CR |= (3U << DMA_SxCR_CHSEL_Pos); /* Select channel 3 */

	/* Enable memory address increment */
	self->_dma_stream_tx->CR |= DMA_SxCR_MINC;

	/* Set transfer direction MEMORY TO PERIPHERAL */
	self->_dma_stream_tx->CR &= ~DMA_SxCR_DIR_Msk;
	self->_dma_stream_tx->CR |= (1U << DMA_SxCR_DIR_Pos);

	/* Enable transfer complete interrupt */
	self->_dma_stream_tx->CR |= DMA_SxCR_TCIE;

	/* Enable DMA stream */
	self->_dma_stream_tx->CR |= DMA_SxCR_EN;

}

void init_dma_rx_spi(struct spi *self){

	/* Disable DMA stream */
	self->_dma_stream_rx->CR &= ~DMA_SxCR_EN;

	/* Wait until DMA stream enable bit is 0 */
	while((self->_dma_stream_rx->CR & DMA_SxCR_EN)){}

	/* Clear all interrupts related to stream */
	self->_dma->LIFCR |= (0xFU << RX_SPI1_DMA2_STREAM_NUMBER * 8U);

	/* Set peripheral address */
	self->_dma_stream_rx->PAR = (uint32_t)(&(self->_spi->DR));

	/* Set memory address */
	self->_dma_stream_rx->M0AR = (uint32_t)(self->_dma_stream_rx);

	/* Set number of transfers */
	self->_dma_stream_rx->NDTR = (uint16_t) SPI1_RX_BUFFER_LENGTH;

	/* Select channel (3) */
	self->_dma_stream_rx->CR &= ~DMA_SxCR_CHSEL_Msk;
	self->_dma_stream_rx->CR |= (3U << DMA_SxCR_CHSEL_Pos); /* Select channel 3 */

	/* Enable memory address increment */
	self->_dma_stream_rx     ->CR |= DMA_SxCR_MINC;

	/* Enable transfer complete interrupt */
	self->_dma_stream_rx->CR |= DMA_SxCR_TCIE;

	/* Set direction - peripheral to memory */
	self->_dma_stream_rx->CR &= ~DMA_SxCR_DIR_Msk;

	/* Enable DMA stream */
	self->_dma_stream_rx->CR |= DMA_SxCR_EN;
}


