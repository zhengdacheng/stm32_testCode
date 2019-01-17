#include "beep.h"
#include "stm32f10x.h"

void beep_init(void){
	RCC->APB2ENR=1<<3;
	GPIOB->CRH&=0XFFFFFFF0;
	GPIOB->CRH|=0X00000003;
	GPIOB->ODR =~(1<<8);
	
}
