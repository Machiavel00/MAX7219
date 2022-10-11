/*
 * max7219.c
 *
 *  Created on: Oct 11, 2022
 *      Author: mathi
 */

#include "max7219.h"

/* Static variables used to store MAX7219 related objects */
static SPI_HandleTypeDef * hspi;		// SPI handle to send commands over SPI port
static GPIO_TypeDef  * spi_ncs_port;	// GPIO port of NCS signal
static uint16_t spi_ncs_pin;			// GPIO pin of NCS signal

/**
 * @brief Init function, used to pass hardware handles and constants
 * @param _hspi Pointer to spi handle
 * @param _spi_ncs_port Pointer to NCS pin GPIO port
 * @param _spi_ncs_pin GPIO pin of @defgroup GPIO_pins
 * @retval HAL status, HAL_OK if pass occured, HAL_ERROR otherwise
 *
 */
HAL_StatusTypeDef max7219_init(SPI_HandleTypeDef * _hspi, GPIO_TypeDef  * _spi_ncs_port, uint16_t _spi_ncs_pin){
	// Check if parameters are OK
	if ((_hspi == NULL) || (_spi_ncs_port == NULL)) return HAL_ERROR;

	// Attribute parameters to static variables
	hspi = _hspi;
	spi_ncs_port = _spi_ncs_port;
	spi_ncs_pin = _spi_ncs_pin;

	// Return on success
	return HAL_OK;
}

/*
 * @brief Send data to address
 * @param _address Address on 8 bits
 * @param _data Data on 8 bits
 */
HAL_StatusTypeDef max7219_transmit(uint8_t _address, uint8_t _data){
	uint8_t data[] = {_address, _data};					// SPI transmit buffer
	size_t data_sz = sizeof(data) / sizeof(uint8_t);	// Size of SPI transmit buffer
	HAL_StatusTypeDef max7219_status = HAL_OK;			// Return value

	// Select MAX7219, send data, de-select MAX7219
	HAL_GPIO_WritePin(spi_ncs_port, spi_ncs_pin, GPIO_PIN_RESET);
	max7219_status = HAL_SPI_Transmit(hspi, data, data_sz, 100);
	HAL_GPIO_WritePin(spi_ncs_port, spi_ncs_pin, GPIO_PIN_SET);

	// Return transmit status
	return max7219_status;
}
