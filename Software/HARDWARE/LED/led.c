#include "main.h"

u8 key;
u8 color = 0;
	    
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
}

void LEDcontrol(void)
{
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
void LEDoff(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_5); 			
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	GPIO_ResetBits(GPIOA,GPIO_Pin_7); 
}
