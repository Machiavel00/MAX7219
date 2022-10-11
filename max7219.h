/*
 * max7219.h
 *
 *  Created on: Oct 11, 2022
 *      Author: mathi
 */

#ifndef MAX7219_MAX7219_H_
#define MAX7219_MAX7219_H_

#include "stm32l1xx_hal.h"

HAL_StatusTypeDef max7219_init(SPI_HandleTypeDef * _hspi, GPIO_TypeDef  * _spi_ncs_port, uint16_t _spi_ncs_pin);
HAL_StatusTypeDef max7219_transmit(uint8_t _address, uint8_t _data);

#endif /* MAX7219_MAX7219_H_ */
