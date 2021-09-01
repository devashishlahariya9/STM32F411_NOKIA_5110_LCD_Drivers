#include "STM32F411xx_Nokia_5110_LCD.h"

Nokia_LCD lcd;

int main()
{
	lcd.init();			//Initialize the LCD

	lcd.setCursor(0, 0);
	lcd.print("Hello World!!");

	lcd.display();		//This function has to be called in order for the LCD to work properly.

	while(1)
	{

	}
	return 0;
}
