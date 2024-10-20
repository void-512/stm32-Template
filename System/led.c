#include "led.h"

void led_init(void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

void led_on(uint16_t color) {
	if (color == GREEN)
		GPIO_SetBits(GPIOB, GPIO_Pin_5);
	else if (color == RED)
		GPIO_SetBits(GPIOE, GPIO_Pin_5);
	else 
		return;
}

void led_off(uint16_t color) {
	if (color == GREEN)
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);
	else if (color == RED)
		GPIO_ResetBits(GPIOE, GPIO_Pin_5);
	else 
		return;
}
