#include "main.h"

void TIM4_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  tim;
    NVIC_InitTypeDef         nvic;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
    
    nvic.NVIC_IRQChannel = TIM4_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 0;
    nvic.NVIC_IRQChannelSubPriority = 2;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic);

    tim.TIM_Prescaler = 84-1;        //84M internal clock
    tim.TIM_CounterMode = TIM_CounterMode_Up;
    tim.TIM_ClockDivision = TIM_CKD_DIV1;
    tim.TIM_Period = 1000-1;  //1ms,1000Hz
    TIM_TimeBaseInit(TIM4,&tim);
		
		TIM_Cmd(TIM4, ENABLE);	 //使能定时器6
//    TIM_ITConfig(TIM4, TIM_IT_Update,ENABLE);
//    TIM_ClearFlag(TIM4, TIM_FLAG_Update);
}
