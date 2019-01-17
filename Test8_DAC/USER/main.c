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
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	KEY_Init();			  //��ʼ����������
 	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();			 	 //LCD��ʼ��
 	Adc_Init();		  		//ADC��ʼ��
	Dac1_Init();				//DAC��ʼ��

	
		//��ʾ��ʾ��Ϣ
	POINT_COLOR=RED;//��������Ϊ��ɫ
	LCD_ShowString(0, 56, 300, 24, 24,"��Ա:֣���,�ο���,������");
	 //��ʾADCֵ
  LCD_ShowString(0,84,300,24,24,"ADC�ĵ�ѹֵ:0.000V");
  //��ʾ��ʾ��Ϣ											      
	LCD_ShowString(0,112,300,24,24,"DAC��ֵ:");	      
	LCD_ShowString(0,140,300,24,24,"DAC�ĵ�ѹֵ:0.000V"); 
	
	DAC_SetChannel1Data(DAC_Align_12b_R, 0);//��ʼֵΪ0	    	      
	while(1)
	{
		t++;
		key=KEY_Scan(0);			  
		if(key==WKUP_PRES)
		{		 
			if(dacval<4000)dacval+=200;
		 DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//����DACֵ	
		}else if(key==KEY1_PRES)	
		{
			if(dacval>200)dacval-=200;
			else dacval=0;
		  DAC_SetChannel1Data(DAC_Align_12b_R, dacval);//����DACֵ
		}	 
	 if(t==10||key==KEY1_PRES||key==WKUP_PRES) //WKUP/KEY1������,���߶�ʱʱ�䵽��
		{	
			//����������Ϊ��ɫ
			POINT_COLOR=BLUE;
			adcx=DAC_GetDataOutputValue(DAC_Channel_1);//��ȡǰ������DAC��ֵ
			LCD_ShowxNum(96,112,adcx,4,24,0);     	//��ʾDAC�Ĵ���ֵ
			temp=(float)adcx*(3.3/4096);			//�õ�DAC��ѹֵ
			adcx=temp;
 			LCD_ShowxNum(144,140,temp,1,24,0);     	//��ʾ��ѹֵ��������
 			temp-=adcx;
			temp*=1000;
			LCD_ShowxNum(168,140,temp,3,24,0X80); 	//��ʾ��ѹֵ��С������
 			adcx=Get_Adc_Average(ADC_Channel_1,10);		//�õ�ADCת��ֵ	  
			temp=(float)adcx*(3.3/4096);			//�õ�ADC��ѹֵ
			adcx=temp;
 			LCD_ShowxNum(144,84,temp,1,24,0);     	//��ʾ��ѹֵ��������
 			temp-=adcx;
			temp*=1000;
			LCD_ShowxNum(168,84,temp,3,24,0X80); 	//��ʾ��ѹֵ��С������
			LED1=!LED1;	   
			t=0;
		}	    
		delay_ms(10);	

	}
}
