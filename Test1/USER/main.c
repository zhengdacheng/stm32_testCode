#include "led.h"
#include "delay.h"


int main (void) {
		init_led();
    delay_init();
    while(1)
    {
//			设置GPIOB端口输出高电平
        GPIO_ResetBits(GPIOB,GPIO_Pin_5);
				delay_ms(300); //延时 300ms
				GPIO_SetBits(GPIOB,GPIO_Pin_5);
//			设置GPIOE端口输出低电平
        GPIO_ResetBits(GPIOE,GPIO_Pin_5);
				delay_ms(300); //延时 300ms
				GPIO_SetBits(GPIOE,GPIO_Pin_5);
        
    }

}




