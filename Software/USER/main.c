#include "main.h"


int main(void)
{
	delay_init();		  //��ʼ����ʱ����
	
	Init_HX711pin();
	Get_Maopi();				//��ëƤ����
	delay_ms(1000);
	delay_ms(1000);
	Get_Maopi();				//���»�ȡëƤ����

	TIM4_Configuration();
	LED_Init();		        //��ʼ��LED�˿�
	KEY_Init();

	while(1)
	{		
	}
} 



