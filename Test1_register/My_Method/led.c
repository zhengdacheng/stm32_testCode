#include "led.h"
#include "stm32f10x.h"

void led_init(void){
	RCC->APB2ENR|=1<<3;
	RCC->APB2ENR|=1<<6;
//	BÅäÖÃ¶Ë¿Ú
	GPIOB->CRL&=0XFF0FFFFF;
	GPIOB->CRL|=0X00300000;
	GPIOB->ODR|=1<<5;
//	EÅäÖÃ¶Ë¿Ú
	//	BÅäÖÃ¶Ë¿Ú
	GPIOE->CRL&=0XFF0FFFFF;
	GPIOE->CRL|=0X00300000;
	GPIOE->ODR|=1<<5;

}
