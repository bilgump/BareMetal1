/*
 * flash_w25q16.h
 *
 *  Created on: May 25, 2025
 *      Author: Bilgehan
 */

#ifndef FLASH_SPI_FLASH_W25Q16_H_
#define FLASH_SPI_FLASH_W25Q16_H_

#include <stdbool.h>
#include "stm32f4xx_hal.h"

#define FLASH_CS_PORT		GPIOB
#define FLASH_CS_PIN		GPIO_PIN_0
#define CS_LOW()			HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_RESET)
#define CS_HIGH()			HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_SET)


bool W25Q16_Init(SPI_HandleTypeDef *hspii);

bool W25Q16_readID(uint16_t *id);

bool W25Q16_Read(uint32_t addr, uint8_t *dst, size_t len);

bool W25Q16_PageProgram(uint32_t addr, const uint8_t *src, size_t len); //<256 B

bool W25Q16_Erase4K(uint32_t addr); //sector

#endif /* FLASH_SPI_FLASH_W25Q16_H_ */
