/*
 * STM32F411xx_SPI1.h
 *
 * Created on: Sep 1, 2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_SPI1_H_
#define STM32F411XX_SPI1_H_

#include "STM32F411xx.h"

uint8_t SS;

enum SPI_MODES
{
	SPI_MODE_0,		//CLK is Active HIGH & Data is Captured On Leading Edge
	SPI_MODE_1,		//CLK is Active HIGH & Data is Captured On Trailing Edge
	SPI_MODE_2,		//CLK is Active LOW & Data is Captured On Leading Edge
	SPI_MODE_3		//CLK is Active LOW & Data is Captured On Trailing Edge
};

enum SPI_SPEEDS
{
	CLK_DIV_BY_2,
	CLK_DIV_BY_4,
	CLK_DIV_BY_8,
	CLK_DIV_BY_16,
	CLK_DIV_BY_32,
	CLK_DIV_BY_64,
	CLK_DIV_BY_128,
	CLK_DIV_BY_256
};

class SPI_1
{
public:
	SPI_1(uint8_t ss, uint8_t spi_mode, uint8_t spi_speed)
	{
		RCC -> AHB1ENR |= (1 << 1);   //Enable GPIOB Clock
		RCC -> APB2ENR |= (1 << 12);  //Enable SPI1 Clock

		SS = ss;
		SPI1 -> CR1 |= (spi_mode << 0);
		SPI1 -> CR1 |= (spi_speed << 3);
	}
	void init();
	void beginTransmission();
	void write(unsigned char data);
	void endTransmission();
	char read();
};

void SPI_1 :: init()
{
	GPIOB -> PUPDR |= (1 << 6) | (1 << 8) | (1 << 10);  //Pull All Pins High
	GPIOB -> ODR |= (1 << SS);   //Pull SS HIGH

	GPIOB -> MODER |= (1 << (SS*2));     //Set PB6(SS) As GPIO Output

	GPIOB -> MODER |= (1 << 7) | (1 << 9) | (1 << 11);  //Set GPIOB3, GPIOB4 & GPIOB5 To Alternate Function Mode
	GPIOB -> AFRL |= (5 << 12) | (5 << 16) | (5 << 20);  //Set Pins As AFIO

	SPI1 -> CR1 |= (1 << 9);  //Enable SSM Bit
	SPI1 -> CR1 |= (1 << 8);  //Enable SSI Bit
	SPI1 -> CR1 |= (1 << 3);  //Set Speed To 4MHz
	SPI1 -> CR1 |= (1 << 2);  //Set To Master Mode
	SPI1 -> CR1 |= (1 << 6);  //Enable SPI1
}

void SPI_1 :: beginTransmission()
{
	while(!(SPI1 -> SR & (1 << 1)));
	GPIOB -> ODR &= ~(1 << SS);  //Pull SS LOW
}

void SPI_1 :: write(unsigned char data)
{
	while(!(SPI1 -> SR & (1 << 1)));
	SPI1 -> DR = data;  //Send Data
}

void SPI_1 :: endTransmission()
{
	while(!(SPI1 -> SR & (1 << 1)));
	GPIOB -> ODR |= (1 << SS);  //Pull SS HIGH
}

char SPI_1 :: read()
{
	while(!(SPI1 -> SR & (1 << 0)));

	return SPI1 -> DR;
}

#endif
