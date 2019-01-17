#include "led.h"
#include "stm32f10x.h" 


void led_init(void){
  GPIO_InitTypeDef MyInStruct;    
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);
//	����pb5�˿�
	MyInStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	MyInStruct.GPIO_Speed=GPIO_Speed_50MHz;
	MyInStruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Init(GPIOB,&MyInStruct);
//	Ĭ�ϳ�ʼ��Ϊ�ߵ�ƽ
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
//	����pe5�˿�
	MyInStruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_Init(GPIOE,&MyInStruct);
//	Ĭ�ϳ�ʼ��Ϊ�ߵ�ƽ
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}
