#include "main.h"


int main(void)
{
//	SystemInit();
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
	}
} 



