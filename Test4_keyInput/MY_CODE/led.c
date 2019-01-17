#include "led.h"
#include "stm32f10x.h" 


void led_init(void){
  GPIO_InitTypeDef MyInStruct;    
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);
//	配置pb5端口
	MyInStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	MyInStruct.GPIO_Speed=GPIO_Speed_50MHz;
	MyInStruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Init(GPIOB,&MyInStruct);
//	默认初始化为高电平
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
//	配置pe5端口
	MyInStruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Init(GPIOE,&MyInStruct);
//	默认初始化为高电平
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}
