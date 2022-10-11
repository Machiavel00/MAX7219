/*
 * max7219.h
 *
 *  Created on: Oct 11, 2022
 *      Author: mathi
 */

#ifndef MAX7219_MAX7219_H_
#define MAX7219_MAX7219_H_



#include "stm32l1xx_hal.h"



#define MAX_DIGITS_COUNT	8

/**
 * @brief MAX7219 registers
 */
#define DIGIT_0_REG_BASE		((uint8_t)0x01)
#define DIGIT_1_REG_BASE		((uint8_t)0x02)
#define DIGIT_2_REG_BASE		((uint8_t)0x03)
#define DIGIT_3_REG_BASE		((uint8_t)0x04)
#define DIGIT_4_REG_BASE		((uint8_t)0x05)
#define DIGIT_5_REG_BASE		((uint8_t)0x06)
#define DIGIT_6_REG_BASE		((uint8_t)0x07)
#define DIGIT_7_REG_BASE		((uint8_t)0x08)
#define DECODE_MODE_REG_BASE	((uint8_t)0x09)
#define INTENSITY_REG_BASE		((uint8_t)0x0A)
#define SCAN_LIMIT_REGG_BASE	((uint8_t)0x0B)
#define SHUTDOWN_REG_BASE		((uint8_t)0x0C)
#define DISPLAY_TEST_REG_BASE	((uint8_t)0x0F)

/**
 * @brief MAX7219 registers definitions
 */
#define SHUTDOWN_REG_SHUTDOWN_MODE		((uint8_t)0x00)
#define SHUTDOWN_REG_NORMAL_MODE		((uint8_t)0x01)

/**
 * @brief Digits values
 */
#define DIGIT_OFF	((uint8_t)0b00000000)
#define DIGIT_ON	((uint8_t)0b11111111)



HAL_StatusTypeDef max7219_init(SPI_HandleTypeDef * _hspi, GPIO_TypeDef  * _spi_ncs_port, uint16_t _spi_ncs_pin, uint8_t _digits_count);
HAL_StatusTypeDef max7219_display_no_decode(uint8_t _digit_index, uint8_t _digit_value);



#endif /* MAX7219_MAX7219_H_ */
