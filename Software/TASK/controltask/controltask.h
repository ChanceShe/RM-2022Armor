#ifndef __CONTROLTASK_H__
#define __CONTROLTASK_H__
#include "main.h"

extern u32 system_time;
extern u16 weight[10];
extern u8 pointer;
extern u8 hitflag ;
extern u8 hitcount;
extern u8 ledoff_time;
void control_task(void);
void hitmonitor(void);
#endif
