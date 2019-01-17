#include "led.h"
#include "delay.h"
#include "lcd.h"
#include "usart.h"
#include "adc.h"

int main(void)
{
	u16 adcx;
	float temp; 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();			 	
 	Adc_Init();		  		//ADC��ʼ��

	POINT_COLOR=RED;//��������Ϊ��ɫ 
	LCD_ShowString(0, 56, 300, 24, 24,"��Ա:֣���,�ο���,������");
	//��ʾ��ʾ��Ϣ
	POINT_COLOR=BLUE;//��������Ϊ��ɫ
	 //��ʾADCֵ�͵�ѹֵ
  LCD_ShowString(0,84,300,24,24,"ADC��ֵ:");
  LCD_ShowString(0,110,300,24,24,"��ѹֵ:0.000");	       
	while(1)
	{
		POINT_COLOR=RED;
		adcx=Get_Adc_Average(ADC_Channel_1,10);
    LCD_ShowxNum(96,84,adcx,4,24,0);//��ʾADC��ֵ
    temp=(float)adcx*(3.3/4096);
    adcx=temp;
    LCD_ShowxNum(84,110,adcx,1,24,0);//��ʾ��ѹֵ
    temp-=adcx;
    temp*=1000;
    LCD_ShowxNum(108,110,temp,3,24,0X80);
		LCD_ShowString(144,110,300,24,24,"V");	
    LED0=!LED0;
		delay_ms(250);	
	}
}