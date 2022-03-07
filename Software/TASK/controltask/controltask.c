#include "main.h"
u32 system_time = 0;
u8 weight[10];

void control_task(void)
{
	system_time++;
	if(system_time>=2000)
	{
		if(system_time%100 == 0)
		{
			Get_Weight();
		}
	}
}
void hitmonitor()
{
	
}
