#ifndef __LED_H
#define __LED_H	 
#include "main.h"

#define LED0 PBout(5)// PB5
#define LED1 PEout(5)// PE5	

void LED_Init(void);//??ʼ??
void LEDcontrol(void);
void LEDoff(void);

#endif
