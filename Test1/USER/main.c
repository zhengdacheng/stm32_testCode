#include "led.h"
#include "delay.h"


int main (void) {
		init_led();
    delay_init();
    while(1)
    {
//			����GPIOB�˿�����ߵ�ƽ
        GPIO_ResetBits(GPIOB,GPIO_Pin_5);
				delay_ms(300); //��ʱ 300ms
				GPIO_SetBits(GPIOB,GPIO_Pin_5);
//			����GPIOE�˿�����͵�ƽ
        GPIO_ResetBits(GPIOE,GPIO_Pin_5);
				delay_ms(300); //��ʱ 300ms
				GPIO_SetBits(GPIOE,GPIO_Pin_5);
        
    }

}




