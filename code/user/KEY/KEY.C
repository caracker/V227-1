#include	"KEY.h"
#include "../../head_extern.h"
#include	"../motor/motor.h"
extern byte motor_state_temp;
extern byte hot_mode_temp;
void key_init(void)
{
	$ s1 IN,pull;
	$ s2 IN,pull;
	$ power_in in,nopull;
}
void check_charging(void)
{
	if(power_in)
	{
		f_charging=1;
		f_work=0;
		f_heating=0;
		motor_state=0;
		motor_state_temp=100;
		S1_count=0;
		s2_count=0;
		motor_time=0;
		sleep_time=0;
		led_time=0;
		hot_time=0;
		f_low=0;
	}
	else
	{
		f_charging=0;	
	}
	
}
void key_scan(void)
{
	if(f_key_scan && !f_charging)
	{
		f_key_scan=0;
		s1_even();
		s2_even();
	}
}

void s1_even(void)
{
	if(s1==0)
	{
		if(S1_count<250)	S1_count++;
		if(S1_count>100&&S1_count<210) //长按
		{
			S1_count=220;
			if(f_work)
			{
				f_work=0;
				f_heating=0;
				motor_state=0;
			}
			else
			{
				f_work=1;
				motor_state=1;

			}
			motor_state_temp=100;
		}
	}
	else
	{	
		if(s1_count>2&&s1_count<200)
		{
			if(f_work) 
			{
				if(motor_state<9)motor_state++;
				else
				{
					motor_state=1;
				}	
				motor_state_temp=100;
			}		
		}
		S1_count=0;
	}
}
void s2_even(void)
{
	if(s2==0)
	{
		if(S2_count<250)	S2_count++;
		if(S2_count>100&&S2_count<210) //长按
		{
			S2_count=220;
			if(f_heating)
			{
				f_heating=0;
				hot_time=0;
			}
			else
			{
				f_heating=1;
				hot_time=0;
				hot_mode=1;

			}

		}
	}
	else
	{	
		if(s2_count>2&&s2_count<200)
		{
			if(f_heating)
			{
				hot_mode++;
				if(hot_mode>3)hot_mode=1;
			}
		}
		s2_count=0;
	}
}