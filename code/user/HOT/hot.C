#include	"hot.h"
#include "../../head_extern.h"

void hot_init(void)
{
//	$ hot_pwm out,low;
	tm2ct=0;
	tm2b = 127;			 //上限寄存器    k=127
	tm2c = 0b_0010_10_1_0;	 // 系统时钟, 输出 = PA4, PWM 模式
	tm2s = 0b_0001_0011;	 // 8位pwm:256, 预分频 = 1, 分频 = 2   S1=1  S2=1
	hot_off;
//	while(1)
	{}
}
void hot_even(void)
{
	if(f_heating && !f_charging)
	{
	//	hot_pwm=1;
		switch(hot_mode)
		{
			case 1:
				tm2b = 217;	
				break;
			case 2:
				tm2b = 235;	
				break;
			case 3:
				tm2b = 253;	
				break;
		}
		hot_on;
	}
	else
	{
//		hot_pwm=0;
		hot_off;
	}

}