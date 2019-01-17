#include "led.h"
#include "stm32f10x.h"
void init_led(){
	GPIO_InitTypeDef My_Struct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);
	My_Struct.GPIO_Mode=GPIO_Mode_Out_PP;
	My_Struct.GPIO_Speed=GPIO_Speed_50MHz;
	My_Struct.GPIO_Pin=GPIO_Pin_5;
//	设置GPIOB输出高电平
	GPIO_Init(GPIOB,&My_Struct);
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
//		设置GPIOE输出高电平
	GPIO_Init(GPIOE,&My_Struct);
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
	
	
}
