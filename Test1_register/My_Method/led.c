#include "led.h"
#include "stm32f10x.h"

void led_init(void){
	RCC->APB2ENR|=1<<3;
	RCC->APB2ENR|=1<<6;
//	B���ö˿�
	GPIOB->CRL&=0XFF0FFFFF;
	GPIOB->CRL|=0X00300000;
	GPIOB->ODR|=1<<5;
//	E���ö˿�
	//	B���ö˿�
	GPIOE->CRL&=0XFF0FFFFF;
	GPIOE->CRL|=0X00300000;
	GPIOE->ODR|=1<<5;

}
