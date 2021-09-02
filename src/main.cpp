#include "STM32F411xx_Nokia5110.h"

Nokia5110 lcd(7, 8);	//DC, RST

int main(void)
{
	lcd.init();			//Initialize The LCD

	lcd.setCursor(0, 0);
	lcd.print("Devashish :)");

	lcd.display();		//This function has to be called after you are done setting up the print statements

	while(1)
	{

	}

	return 0;
}
