/*
 * STM32F411xx_SPI1.h
 *
 * Created on: Sep 1, 2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_SPI1_H_
#define STM32F411XX_SPI1_H_

#include "STM32F411xx.h"

#define SS 6

class SPI_1
{
public:
	void init();
	void beginTransmission();
	void write(unsigned char data);
	void endTransmission();
	char read();
};

void SPI_1 :: init()
{
	RCC -> AHB1ENR |= (1 << 1) | (1 << 3);   //Enable GPIOB And GPIOD Clock
	RCC -> APB2ENR |= (1 << 12);  //Enable SPI1 Clock

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
