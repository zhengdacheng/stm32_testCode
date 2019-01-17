#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "rtc.h"

int main(void)
{
    u8 t=0;
    u8 x=0;
    u8 lcd_id[12];			//���LCD ID�ַ���
    delay_init();	    	 //��ʱ������ʼ��
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
    uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
    LED_Init();			     //LED�˿ڳ�ʼ��
    LCD_Init();
    RTC_Init();
    POINT_COLOR=RED;
    sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id���顣
    while(1)
    {
        switch(x)
        {
        case 0:
            LCD_Clear(WHITE);
            break;
        case 1:
            LCD_Clear(BLACK);
            break;
        case 2:
            LCD_Clear(BLUE);
            break;
        case 3:
            LCD_Clear(RED);
            break;
        case 4:
            LCD_Clear(MAGENTA);
            break;
        case 5:
            LCD_Clear(GREEN);
            break;
        case 6:
            LCD_Clear(CYAN);
            break;
        case 7:
            LCD_Clear(YELLOW);
            break;
        case 8:
            LCD_Clear(BRRED);
            break;
        case 9:
            LCD_Clear(GRAY);
            break;
        case 10:
            LCD_Clear(LGRAY);
            break;
        case 11:
            LCD_Clear(BROWN);
            break;
        }
        POINT_COLOR=RED;
        LCD_ShowString(0, 56, 300, 24, 24,"��Ա:֣���,�ο���,������");
        LCD_ShowString(0, 80, 240, 24, 24,"������ѧϰstm32");
        LCD_ShowString(0, 104, 240, 24, 24,"ʱ��:");
        //��ʾʱ��
        LCD_ShowString(0,130,300,24,24,"    -  -  ");
        LCD_ShowString(0,178,300,24,24,"  :  :  ");

        if(t!=calendar.sec)
        {
            t=calendar.sec;
            LCD_ShowNum(0,130,calendar.w_year,4,24);
            LCD_ShowNum(56,130,calendar.w_month,2,24);
            LCD_ShowNum(100,130,calendar.w_date,2,24);
            switch(calendar.week)
            {
            case 0:
                LCD_ShowString(0,154,200,24,24,"Sunday   ");
                break;
            case 1:
                LCD_ShowString(0,154,200,24,24,"Monday   ");
                break;
            case 2:
                LCD_ShowString(0,154,200,24,24,"Tuesday  ");
                break;
            case 3:
                LCD_ShowString(0,154,200,24,24,"Wednesday");
                break;
            case 4:
                LCD_ShowString(0,154,200,24,24,"Thursday ");
                break;
            case 5:
                LCD_ShowString(0,154,200,24,24,"Friday   ");
                break;
            case 6:
                LCD_ShowString(0,154,200,24,24,"Saturday ");
                break;
            }
            LCD_ShowNum(0,178,calendar.hour,2,24);
            LCD_ShowNum(34,178,calendar.min,2,24);
            LCD_ShowNum(70,178,calendar.sec,2,24);
        }
        x++;
        if(x==12)x=0;
        LED0=!LED0;
        delay_ms(1000);
    }
}
