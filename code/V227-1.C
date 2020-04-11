#include	"extern.h"
#include	"./user/TIM16/TIM16.h"
#include	"./user/key/key.h"
#include	"./user/led/led.h"
#include	"./user/motor/motor.h"
#include	"./user/STOPSYS/STOPSYS.h"
#include	"./user/hot/hot.h"
#include	"./user/comparator/comparator.h"
#include 	"head.h"
//.Writer     Limit   $ + 5
extern byte motor_state_temp;
extern byte hot_mode_temp;
void data_init(void)
{
	f_work=0;
	f_charging=0;	
	f_key_scan=0;
	f_heating=0;
	f_low=0;
	motor_state=0;
	motor_state_temp=100;
	count=39;
	S1_count=0;
	s2_count=0;
	motor_time=0;
	sleep_time=0;
	led_time=0;
	hot_time=0;
}
void	FPPA0 (void)
{

	.ADJUST_IC	SYSCLK=IHRC/8, IHRC=16MHz, VDD=4.2V;
	T16_init();
	key_init();
	motor_init();
	led_init();
	hot_init();
	stopsys_init();
	data_init();
	comparator_init();
	while (1)
	{
		check_charging();
		key_scan();
		motor_even();
		hot_even();
		led_even();
		check_power_even();
		stopsys_even();
 	}
}

void	Interrupt (void)
{
	pushaf;

	if (Intrq.T16)
	{	
		Intrq.T16	=	0;
		if(led_time<65000)	led_time++;
		if(motor_time2<65000)motor_time2++;
		if (--count == 0)					
		{
			count= 156;          // 256 uS * 39 = 9,984 uS ¨P 10 mS
	 		f_key_scan=1;
			if(motor_time<65000)motor_time++;
			if(f_heating)
			{
				hot_time++;
				if(hot_time>60000)
				{
					f_heating=0;	
				}
			}
			else
			{
				hot_time=0;
			}
			if(!f_work && !f_heating && !f_charging )
			{
				sleep_time++;
			}
			else
			{
				sleep_time=0;
			}
		}
	}

	popaf;
}

