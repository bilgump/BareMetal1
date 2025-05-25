#include "flash_w25q16.h"

static SPI_HandleTypeDef *hspi;

//FORWARD DECLARATIONS
static bool writeEnable(void);
static bool txrx(const uint8_t *tx, uint8_t *rx, size_t n);

/*------------------------------- STATIC FUNCTIONS ------------------------------------ */
static bool txrx(const uint8_t *tx, uint8_t *rx, size_t n)
{
	if(HAL_SPI_TransmitReceive(hspi, (uint8_t *)tx, rx, n, HAL_MAX_DELAY) != HAL_OK)
		return false;

	return true;
}

static bool writeEnable(void)
{
	uint8_t cmd = 0x06;

	CS_LOW();
	if(HAL_SPI_Transmit(hspi, &cmd, 1, HAL_MAX_DELAY) != HAL_OK)
		return false;

	CS_HIGH();

	return true;
}

/*------------------------------- PUBLIC FUNCTIONS ------------------------------------ */
bool W25Q16_Init(SPI_HandleTypeDef *hspii)
{
	hspi = hspii;
	uint16_t id = 0;
	return W25Q16_readID(&id) == 0xEF14;	//// EFh = Winbond, 14h = 16 Mbit
}

bool W25Q16_readID(uint16_t *id)
{
	uint8_t cmd[2] = {0x90, 0};	//Manufacturer/Device ID
	uint8_t rx[2] = {0};

	CS_LOW();

	if(!txrx(cmd, rx, 2))
		return false;
	if(!txrx(cmd, rx, 2))
		return false;

	CS_HIGH();

	*id = (rx[0] << 8) | rx[1];

	return true;
}

bool W25Q16_Read(uint32_t addr, uint8_t *dst, size_t len)
{
	uint8_t hAddr[4] = {0x03, addr >> 16, addr >> 8, addr};

	CS_LOW();
	if(HAL_SPI_Transmit(hspi, hAddr, 4, HAL_MAX_DELAY) != HAL_OK)
		return false;
	if(HAL_SPI_Receive(hspi, dst, len, HAL_MAX_DELAY) != HAL_OK)
		return false;
	CS_HIGH();

	return true;
}

bool W25Q16_PageProgram(uint32_t addr, const uint8_t *src, size_t len)
{
	if(len > 256)
		return false;

	if(!writeEnable())
		return false;

	uint8_t hdr[4] = {0x02, addr >> 16, addr >> 8, addr};
	CS_LOW();

	if(HAL_SPI_Transmit(hspi, hdr, 4, HAL_MAX_DELAY) != HAL_OK)
		return false;

	if(HAL_SPI_Transmit(hspi, src, len, HAL_MAX_DELAY) != HAL_OK)
		return false;

	CS_HIGH();

	return true;
}

bool W25Q16_Erase4K(uint32_t addr)
{
	if(!writeEnable())
		return false;

	uint8_t hadr[4] = {0x20, addr >> 16, addr >> 8, addr};
	CS_LOW();

	if(HAL_SPI_Transmit(hspi, hadr, 4, HAL_MAX_DELAY) != HAL_OK)
		return false;

	CS_HIGH();

	return true;
}

















