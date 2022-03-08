#include "main.h"

u8 key;
u8 color = 0;
	    
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
}

void LEDcontrol(void)
{
	key=KEY_Scan(0);	//�õ���ֵ
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
	if(color == 0)				//���
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_5); 			
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		GPIO_SetBits(GPIOA,GPIO_Pin_7); 
	}
	else if(color == 1)		//�̵�
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_5); 
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7); 			
	}
	else if(color == 2)		//����
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
