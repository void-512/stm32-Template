#include "stm32f10x.h"                  // Device header
#include "delay.h"

void delay_us(uint32_t xus) {
	SysTick->LOAD = 72 * xus;
	SysTick->VAL = 0x00;
	SysTick->CTRL = 0x00000005;
	while(!(SysTick->CTRL & 0x00010000));
	SysTick->CTRL = 0x00000004;
}

void delay_ms(uint32_t xms) {
	while(xms--)
		delay_us(1000);
}
