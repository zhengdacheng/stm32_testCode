#include "led.h"
#include "delay.h"
#include "lcd.h"
#include "usart.h"
#include "adc.h"
#include "dac.h"
#include "key.h"

int main(void)
{
	u16 adcx;
	float temp;
 	u8 t=0;	 
	u16 dacval=0;
	u8 key;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	KEY_Init();			  //初始化按键程序
 	LED_Init();			     //LED端口初始化
	LCD_Init();			 	 //LCD初始化
 	Adc_Init();		  		//ADC初始化
	Dac1_Init();				//DAC初始化

	
		//显示提示信息
	POINT_COLOR=RED;//设置字体为蓝色
	LCD_ShowString(0, 56, 300, 24, 24,"组员:郑达成,宋俊康,方楷生");
	 //显示ADC值
  LCD_ShowString(0,84,300,24,24,"ADC的电压值:0.000V");
  //显示提示信息											      
	LCD_ShowString(0,112,300,24,24,"DAC的值:");	      
	LCD_ShowString(0,140,300,24,24,"DAC的电压值:0.000V"); 
	
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);//初始值为0	    	      
	while(1)
	{
		t++;
		key=KEY_Scan(0);			  
		if(key==WKUP_PRES)
		{		 
			if(dacval<4000)dacval+=200;
		 DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//设置DAC值	
		}else if(key==KEY1_PRES)	
		{
			if(dacval>200)dacval-=200;
			else dacval=0;
		  DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//设置DAC值
		}	 
	 if(t==10||key==KEY1_PRES||key==WKUP_PRES) //WKUP/KEY1按下了,或者定时时间到了
		{	
			//把数字设置为蓝色
			POINT_COLOR=BLUE;
			adcx=DAC_GetDataOutputValue(DAC_Channel_1);//读取前面设置DAC的值
			LCD_ShowxNum(96,112,adcx,4,24,0);     	//显示DAC寄存器值
			temp=(float)adcx*(3.3/4096);			//得到DAC电压值
			adcx=temp;
 			LCD_ShowxNum(144,140,temp,1,24,0);     	//显示电压值整数部分
 			temp-=adcx;
			temp*=1000;
			LCD_ShowxNum(168,140,temp,3,24,0X80); 	//显示电压值的小数部分
 			adcx=Get_Adc_Average(ADC_Channel_1,10);		//得到ADC转换值	  
			temp=(float)adcx*(3.3/4096);			//得到ADC电压值
			adcx=temp;
 			LCD_ShowxNum(144,84,temp,1,24,0);     	//显示电压值整数部分
 			temp-=adcx;
			temp*=1000;
			LCD_ShowxNum(168,84,temp,3,24,0X80); 	//显示电压值的小数部分
			LED1=!LED1;	   
			t=0;
		}	    
		delay_ms(10);	

	}
}
