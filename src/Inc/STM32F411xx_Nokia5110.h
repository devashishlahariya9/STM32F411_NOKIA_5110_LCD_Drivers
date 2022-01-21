/*
 * STM32F411xx_Nokia5110.h
 *
 * Created on: Nov 19, 2021
 * Author: Devashish Lahariya
*/

#ifndef STM32F411XX_NOKIA5110_H_
#define STM32F411XX_NOKIA5110_H_

#include "STM32F411xx_GPIO.h"
#include "STM32F411xx_SPI1.h"

void lcd_init(uint8_t _dc, uint8_t _ce, uint8_t _rst);
void lcd_setCursor(uint8_t _x, uint8_t _y);
void lcd_setContrast(uint8_t _contrast);

void lcd_printString(char *ptr);
void lcd_printNumber(int _num);
void lcd_printFloat(double _num);
void lcd_printBitmap(char* _bitmap, uint8_t _bufferSize);

void lcd_clear(void);
void lcd_display(void);

#endif /* STM32F411XX_NOKIA5110_H_ */
