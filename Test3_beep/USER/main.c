#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "beep.h"
#include "led.h"


int main(void)
{

	delay_init();
	led_init();
	beep_init();

	while(1){
		PBout(5)=1;
		PBout(8)=0;
		delay_ms(300);
		PBout(5)=0;
		PBout(8)=1;
		delay_ms(300);
		
	}
}

