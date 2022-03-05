#include "main.h"

u8 key;
u8 color = 0;
u32 system_time = 0;
int main(void)
{ 
	delay_init();		  //��ʼ����ʱ����
	LED_Init();		        //��ʼ��LED�˿�
	KEY_Init();
	Init_HX711pin();
	
	Get_Maopi();				//��ëƤ����
	delay_ms(1000);
	delay_ms(1000);
	Get_Maopi();				//���»�ȡëƤ����
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


	

