#include "key.h"
#include "stm32f10x.h"
#include "delay.h"

void key_init(void){
//	初始化四个key的IO口
	GPIO_InitTypeDef My_KeyStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOA,ENABLE);
	My_KeyStruct.GPIO_Mode=GPIO_Mode_IPD;
	My_KeyStruct.GPIO_Speed=GPIO_Speed_50MHz;
	My_KeyStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_Init(GPIOA,&My_KeyStruct);
	My_KeyStruct.GPIO_Mode=GPIO_Mode_IPU;
	My_KeyStruct.GPIO_Pin=GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_Init(GPIOE,&My_KeyStruct);

}
//#define KEY0 	GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
//#define KEY1 	GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
//#define KEY2 	GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)
//#define WK_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
u8 Scan_key(u8 mode){	
	static u8 key_up=1;//按键按、松开标志
  if(mode)key_up=1;  //支持连按 
	if(key_up&&(KEY0==0|KEY1==0|KEY2==0|WK_UP==1)){
		delay_ms(10);
		key_up=0;
		if(KEY0==0)return KEY0_PRES;
		if(KEY1==0)return KEY1_PRES;			
		if(KEY2==0)return KEY2_PRES;
	  if(WK_UP==1)return WKUP_PRES;	
	}else if(KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1;
	return 0;
}
