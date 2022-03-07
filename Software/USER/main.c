#include "main.h"

u32 system_time = 0;
u8 key;
u8 color = 0;
int main(void)
{ 
	delay_init();		  //��ʼ����ʱ����
	TIM4_Configuration();
	LED_Init();		        //��ʼ��LED�˿�
	KEY_Init();
	Init_HX711pin();
	
	Get_Maopi();				//��ëƤ����
	delay_ms(1000);
	delay_ms(1000);
	Get_Maopi();				//���»�ȡëƤ����
	while(1)
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
} 


void control_task(void)
{
	system_time++;
	if(system_time>=2000)
	{
		if(system_time%1 == 0)
		{
			Get_Weight();
		}
	}
}

