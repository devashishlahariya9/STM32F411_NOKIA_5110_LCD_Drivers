#include <stdint.h>

#define F_CPU 16000000UL

typedef struct RCC_POINTERS
{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t RESERVED1;
	uint32_t RESERVED2;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED3;
	uint32_t RESERVED4;
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t RESERVED5;
	uint32_t RESERVED6;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED7;
	uint32_t RESERVED8;
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t RESERVED9;
	uint32_t RESERVED10;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RESERVED11;
	uint32_t RESERVED12;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RESERVED13;
	uint32_t RESERVED14;
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
	uint32_t RESERVED15;
	uint32_t DCKCFGR;
}RCC_PERIPHERALS;

typedef struct GPIO_POINTERS
{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
}GPIO_PERIPHERALS;

typedef struct SPI1_POINTERS
{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SR;
	uint32_t DR;
	uint32_t CRCPR;
	uint32_t RXCRCR;
	uint32_t TXCRCR;
	uint32_t I2SCFGR;
	uint32_t I2SPR;
}SPI1_PERIPHERALS;

typedef struct FPU_POINTERS
{
	uint32_t CPACR;
	uint32_t FPCCR;
	uint32_t FPCAR;
	uint32_t FPSCR;
	uint32_t FPDSCR;
}FPU_PERIPHERALS;

FPU_PERIPHERALS* FPU = (FPU_PERIPHERALS*)0xE000ED88;
RCC_PERIPHERALS* RCC = (RCC_PERIPHERALS*)0x40023800;
GPIO_PERIPHERALS* GPIOA = (GPIO_PERIPHERALS*)0x40020000;
GPIO_PERIPHERALS* GPIOB = (GPIO_PERIPHERALS*)0x40020400;
GPIO_PERIPHERALS* GPIOC = (GPIO_PERIPHERALS*)0x40020800;
GPIO_PERIPHERALS* GPIOD = (GPIO_PERIPHERALS*)0x40020C00;
GPIO_PERIPHERALS* GPIOE = (GPIO_PERIPHERALS*)0x40021000;
SPI1_PERIPHERALS* SPI1 = (SPI1_PERIPHERALS*)0x40013000;

void FPU_init()
{
	FPU -> CPACR = (0xF << 20);
	while(!(FPU -> CPACR & (0xF << 20)));
}

void delay_ms(int del)
{
	for(int i=0; i<(del*1600); i++);
}
