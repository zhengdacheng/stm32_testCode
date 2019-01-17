#ifndef __KEY_H
#define __KEY_H
#include "stm32f10x.h"
#define KEY0_PRES 1
#define KEY1_PRES 2
#define KEY2_PRES 3
#define WKUP_PRES 4
#define KEY0 	GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define KEY1 	GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define KEY2 	GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)
#define WK_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
void key_init(void);
u8 Scan_key(u8 mode);
#endif
