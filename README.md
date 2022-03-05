#  STM32F411xx-NOKIA-5110-LCD-Drivers

Drivers for the Nokia 5110 LCD Using SPI Peripheral of the STM32F411E-DISCO Board. Should also work on similar boards. Fully Flexible Bare-Metal Drivers for the Nokia 5110 LCD. Supports INTEGERS, FLOAT, DOUBLE, STRINGS, CHARACTERS, CUSTOM BITMAPS.

# Keywords:
1. SPIx => x = (1, 2, 3)
2. GPIOy => y = (A, B, C, D, E)
3. NOKIA_Init
4. NOKIA_SetCursor
5. NOKIA_SetContrast
6. NOKIA_PrintString
7. NOKIA_PrintNumber
8. NOKIA_PrintFloat
9. NOKIA_PrintBitmap
10. NOKIA_Clear
11. NOKIA_Display

# API Usage:
1. Initialize The **NOKIA** Struct with your preferred name.
2. Call The **NOKIA_Init()** Function and pass all the given arguments.
3. Set The Best Contrast Using The **NOKIA_SetCursor()** Function.
4. That's it! Now you have successfully initialized your LCD. Have Fun Playing Around :)
