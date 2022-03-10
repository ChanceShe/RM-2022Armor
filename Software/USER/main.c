#include "main.h"


int main(void)
{
	delay_init();		  //初始化延时函数
	
	Init_HX711pin();
	Get_Maopi();				//称毛皮重量
	delay_ms(1000);
	delay_ms(1000);
	Get_Maopi();				//重新获取毛皮重量

	TIM4_Configuration();
	LED_Init();		        //初始化LED端口
	KEY_Init();

	while(1)
	{		
	}
} 



