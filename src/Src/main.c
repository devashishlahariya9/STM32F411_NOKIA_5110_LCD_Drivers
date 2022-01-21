#include "STM32F411xx_Nokia5110.h"

#define LCD_CE	6
#define LCD_DC	8
#define LCD_RST	9

int main(void)
{
	lcd_init(LCD_DC, LCD_CE, LCD_RST);

	lcd_setContrast(50);

	lcd_setCursor(0, 0);
	lcd_printString("Hello, World!!");
	lcd_setCursor(0, 1);
	lcd_printFloat(3.14);
	lcd_setCursor(0, 2);
	lcd_printNumber(16000000);

	lcd_display();

	while(1)
	{

	}
	return 0;
}
