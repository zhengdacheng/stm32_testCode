#include "led.h"
#include "delay.h"
#include "lcd.h"
#include "usart.h"
#include "adc.h"

int main(void)
{
	u16 adcx;
	float temp; 
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			     //LED端口初始化
	LCD_Init();			 	
 	Adc_Init();		  		//ADC初始化

	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(0, 56, 300, 24, 24,"组员:郑达成,宋俊康,方楷生");
	//显示提示信息
	POINT_COLOR=BLUE;//设置字体为蓝色
	 //显示ADC值和电压值
  LCD_ShowString(0,84,300,24,24,"ADC的值:");
  LCD_ShowString(0,110,300,24,24,"电压值:0.000");	       
	while(1)
	{
		POINT_COLOR=RED;
		adcx=Get_Adc_Average(ADC_Channel_1,10);
    LCD_ShowxNum(96,84,adcx,4,24,0);//显示ADC的值
    temp=(float)adcx*(3.3/4096);
    adcx=temp;
    LCD_ShowxNum(84,110,adcx,1,24,0);//显示电压值
    temp-=adcx;
    temp*=1000;
    LCD_ShowxNum(108,110,temp,3,24,0X80);
		LCD_ShowString(144,110,300,24,24,"V");	
    LED0=!LED0;
		delay_ms(250);	
	}
}
