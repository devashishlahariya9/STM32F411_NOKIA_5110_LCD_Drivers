/*
 * STM32F411xx_SPI1.h
 *
 * Created on: 31-Aug-2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_SPI1_H_
#define STM32F411XX_SPI1_H_

#include "STM32F411xx.h"

class SPI_1
{
public:
	void init();
	void write(unsigned char data);
	char read();
};

#endif
