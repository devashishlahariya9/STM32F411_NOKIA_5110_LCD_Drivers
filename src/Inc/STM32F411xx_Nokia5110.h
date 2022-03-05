/*
 * STM32F411xx_Nokia5110.h
 *
 * Created on: Nov 19, 2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_NOKIA5110_H_
#define STM32F411XX_NOKIA5110_H_

#include "STM32F411xx_GPIO.h"
#include "STM32F411xx_SPI.h"

typedef struct
{
	SPI_PERIPHERALS_t* SPI;
	GPIO_PERIPHERALS_t* RST_GPIO;
	uint8_t RST;
	GPIO_PERIPHERALS_t* DC_GPIO;
	uint8_t DC;
	GPIO_PERIPHERALS_t* CE_GPIO;
	uint8_t CE;
}NOKIA;

void NOKIA_Init(NOKIA* nokia_handler, SPI_PERIPHERALS_t* SPI, void(*remap_func)(void), GPIO_PERIPHERALS_t* CE_GPIO, uint8_t CE, GPIO_PERIPHERALS_t* DC_GPIO, uint8_t DC, GPIO_PERIPHERALS_t* RST_GPIO, uint8_t RST);
void NOKIA_SetCursor(NOKIA* nokia_handler, uint8_t _x, uint8_t _y);
void NOKIA_SetContrast(NOKIA* nokia_handler, uint8_t _contrast);

void NOKIA_PrintString(NOKIA* nokia_handler, char *ptr);
void NOKIA_PrintNumber(NOKIA* nokia_handler, int _num);
void NOKIA_PrintFloat(NOKIA* nokia_handler, double _num);
void NOKIA_PrintBitmap(NOKIA* nokia_handler, char* _bitmap, uint8_t _bufferSize);

void NOKIA_Clear(NOKIA* nokia_handler);
void NOKIA_Display(NOKIA* nokia_handler);

#endif /* STM32F411XX_NOKIA5110_H_ */
