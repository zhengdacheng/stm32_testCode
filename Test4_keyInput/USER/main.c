#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
int main(void)
{
	u8 key=0;
	delay_init();
	led_init();
	beep_init();
	key_init();
	LED0=0;
	while(1){
		//不支持连续按
		key=Scan_key(0);
		if(key){
			switch(key){
				case WKUP_PRES:
					BEEP=!BEEP;
				break;
				case KEY1_PRES:
					LED1=!LED1;
				break;
				case KEY2_PRES:
					LED0=!LED0;
				break;
				case KEY0_PRES:
					LED0=!LED0;
					LED1=!LED1;
				break;	
			}
		}else
				delay_ms(10);
	}
	
}

