#include "beep.h"
#include "stm32f10x.h"

void beep_init(void){
	GPIO_InitTypeDef My_BeepStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	My_BeepStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	My_BeepStruct.GPIO_Pin=GPIO_Pin_8;
	My_BeepStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&My_BeepStruct);
//	默认初始化为低电平
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
}
