#include "main.h"

u8 key;
u8 color = 0;
u32 system_time = 0;
int main(void)
{ 
	delay_init();		  //初始化延时函数
	LED_Init();		        //初始化LED端口
	KEY_Init();
	Init_HX711pin();
	
	Get_Maopi();				//称毛皮重量
	delay_ms(1000);
	delay_ms(1000);
	Get_Maopi();				//重新获取毛皮重量
	while(1)
	{
//		system_time++;
//		if(system_time%10 == 0)
//		{
//			Get_Maopi();
//		}
		Get_Weight();
//		if(Weight_Shiwu - last_Weight_Shiwu >= 80)
//		{
//			LEDflash();
//			delay_ms(30);
//		}
		last_Weight_Shiwu = Weight_Shiwu;
		
		
		key=KEY_Scan(0);	//得到键值
		if(key)
		{
			if(color < 2)
			{
				color++;
			}
			else
			{
				color = 0;
			}
		}
		if(color == 0)				//红灯
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_5); 			
			GPIO_ResetBits(GPIOA,GPIO_Pin_6);
			GPIO_SetBits(GPIOA,GPIO_Pin_7); 
		}
		else if(color == 1)		//绿灯
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_5); 
			GPIO_SetBits(GPIOA,GPIO_Pin_6);
			GPIO_ResetBits(GPIOA,GPIO_Pin_7); 			
		}
		else if(color == 2)		//蓝灯
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_5);
			GPIO_ResetBits(GPIOA,GPIO_Pin_6); 
			GPIO_ResetBits(GPIOA,GPIO_Pin_7); 			
		}
	}
} 


	

