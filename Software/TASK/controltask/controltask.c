#include "main.h"
u32 system_time = 0;
u16 weight[10] = {0};
u8 pointer = 0;
u8 hitflag = 0;
u16 hitcount = 0;
int ledoff_time=0;

void control_task(void)
{
	system_time++;
	if(system_time%100 == 0)
	{
		Get_Weight();
	}
	hitmonitor();
	if(ledoff_time)
	{
		LEDoff();
		ledoff_time--;
	}
	else
	{
		LEDcontrol();
	}
}
void hitmonitor()
{
	switch(hitflag)
	{
		case 0:
		{
			if(Weight_Shiwu != weight[pointer])
			{
				if((Weight_Shiwu - weight[pointer] >= 200)&&(Weight_Shiwu - weight[pointer] <= 2000))
					hitflag = 1;
				else
					weight[pointer] = Weight_Shiwu;
			}
		}
		break;
		case 1:
		{
			if(Weight_Shiwu > weight[pointer])
			{
				pointer++;
				weight[pointer] = Weight_Shiwu;
				if(pointer >=9)
				{
					pointer = 0;
					hitflag = 0;
				}
			}
			else if(Weight_Shiwu < weight[pointer])
			{
				if((weight[pointer] - Weight_Shiwu >= 50)&&pointer>=1&&pointer<=2000)
				{
					hitcount++ ;
					ledoff_time = 100;
					pointer = 0;
					hitflag = 0;
				}
				else
				{
					pointer = 0;
					hitflag = 0;
				}
			}
		}
		break;
	}
}
