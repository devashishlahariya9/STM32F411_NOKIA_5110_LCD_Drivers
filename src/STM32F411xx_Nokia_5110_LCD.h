/*
 * STM32F411xx_Nokia_5110_LCD.h
 *
 * Created on: 31-Aug-2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_NOKIA_5110_LCD_H_
#define STM32F411XX_NOKIA_5110_LCD_H_

#include <stdlib.h>
#include <stdio.h>
#include "STM32F411xx.h"
#include "STM32F411xx_SPI1.h"

class Nokia_LCD
{
private:
	void FPU_init();
	void delay_ms(int del);
	void reset_lcd();
	void datawrt(unsigned char data);
	void command(unsigned char data);
	void lcd_dataWrite(unsigned char data);
public:
	void setCursor(short int x, short int y);
	void print(char *ptr);
	void print(int num);
	void print(double num);
	void clear();
	void display();
	void print_bitmap(char b0, char b1, char b2, char b3, char b4, char b5, char b6, char b7);
	void init();
};

#endif
