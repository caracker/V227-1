#ifndef __head_extern_H
#define __head_extern_H	

//*************************************************//
//变量的定义，修改变量必须同步修改head_extern.h
//***********************************************//

extern  BYTE	Sys_Flag;
BIT		f_work		:	Sys_Flag.0;		//开关机
BIT		f_charging	:	Sys_Flag.1;		//充电
bit     f_key_scan	:	Sys_Flag.2;		//按键扫描
bit     f_heating   :	Sys_Flag.3;		//充满
bit     f_low  		:	Sys_Flag.4;		//低电压
extern  BYTE motor_state;		//马达工作模式0~7
extern  BYTE count;//T16计数
extern  BYTE S1_count,s2_count;//按键计数
extern word motor_time,motor_time2;
extern byte pwm_num;
extern WORD sleep_time;
extern bit pwm_bit;
extern  BYTE rate;
extern  BYTE pwm_duty,pwm_cnt;
extern word led_time;
extern word hot_time;;
//extern  BYTE pwm_speed;   
//extern  BYTE  pwm_hz; 
extern byte hot_mode;
#endif