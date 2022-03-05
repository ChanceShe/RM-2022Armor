#ifndef __KEY_H
#define __KEY_H	 
#include "main.h"

#define KEY  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//读取按键0

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数					    
#endif
