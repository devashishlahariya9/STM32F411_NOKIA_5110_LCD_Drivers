/*
 * STM32F411XXSPI1.h
 *
 * Created on: 01-Sep-2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_SPI1_H_
#define STM32F411XX_SPI1_H_

#include <STM32F411xx.h>

class STM32F411XX_SPI1
{
public:
	void init();
	void beginTransmission();
	void write(unsigned char data);
	void endTransmission();
	char read();
};

#endif /* STM32F411XX_SPI1_H_ */
