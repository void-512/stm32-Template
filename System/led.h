#ifndef __LED_H__
#define __LED_H__

#include "stm32f10x.h" 

#define GREEN 1
#define RED 2

void led_init(void);
void led_on(uint16_t color);
void led_off(uint16_t color);

#endif
