#include "stm32f10x.h"
#include "delay.h"
#include "led.h"

int main(void)
{
	led_init();	
	delay_init();
	
	while(1){
		
		GPIOB->ODR&=~(1<<5);
		delay_ms(500);
		GPIOB->ODR|=1<<5;		
		
		GPIOE->ODR&=~(1<<5);
		delay_ms(500);
		GPIOE->ODR|=1<<5;
	
	}

}
