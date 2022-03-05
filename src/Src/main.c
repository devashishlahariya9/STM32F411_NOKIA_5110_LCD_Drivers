#include "STM32F411xx_Nokia5110.h"

#define NOKIA_CE	6
#define NOKIA_DC	8
#define NOKIA_RST	9

NOKIA nokia5110;

int main(void)
{
	GPIOB_CLK_ENABLE();

	NOKIA_Init(&nokia5110, SPI1, SPI1_USE_GPIOB, GPIOB, NOKIA_CE, GPIOB, NOKIA_DC, GPIOB, NOKIA_RST);

	NOKIA_SetContrast(&nokia5110, 40);

	NOKIA_SetCursor(&nokia5110, 0, 0);
	NOKIA_PrintString(&nokia5110, "Hello, World!!");
	NOKIA_SetCursor(&nokia5110, 0, 1);
	NOKIA_PrintFloat(&nokia5110, 3.14);
	NOKIA_SetCursor(&nokia5110, 0, 2);
	NOKIA_PrintNumber(&nokia5110, 16000000);

	NOKIA_Display(&nokia5110);

	while(1)
	{

	}
	return 0;
}
