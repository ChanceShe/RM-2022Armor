#ifndef __KEY_H
#define __KEY_H	 
#include "main.h"

#define KEY  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//��ȡ����0

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8);  	//����ɨ�躯��					    
#endif
