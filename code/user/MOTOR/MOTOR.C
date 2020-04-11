
#include	"motor.h"
#include "../../head_extern.h"
#include	"../key/key.h"
/*	输出频率 = Y ÷ [256 × S1 × (S2+1) ]
*	输出空占比 = ( K＋1 ) ÷ 256×100%
*	Y = tm2c[7:4] : Timer2 所选择的时钟源频率
*	K = tm2b[7:0] : 上限寄存器设定的值(十进制)
*	S1 = tm2s[6:5] : 预分频器设定值 (1, 4, 16, 64)
*	S2 = tm2s[4:0] : 分频器值 (十进制，1 ~ 31)
*/


void motor_init(void)
{ 
//	tm2ct=0;
//	tm2b = 127;			 //上限寄存器    k=127
//	tm2c = 0b_0001_00_1_0;	 // 系统时钟, 输出 = PA4, PWM 模式
//	tm2s = 0b_0010_0111;	 // 8位pwm:256, 预分频 = 1, 分频 = 2   S1=1  S2=1
//	motor_off;
	$ motor_pin out,low;

}
byte motor_state_temp;
void motor_mode1(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
//		tm2s = 0b_0010_0111;//245hz
//		tm2b = 127;	
//		motor_on;
		motor_time2=0;
	}
	if(motor_time2<33)
	{
		motor_pin=1;
	}
	else if(motor_time2<64)
	{
		motor_pin=0;
	}
	else
	{
		motor_time2=0;
	}
}
void motor_mode2(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
//		tm2s = 0b_0010_0111;//245hz
//		tm2b = 191;	
//		motor_on;
		motor_time2=0;
	}
	if(motor_time2<49)
	{
		motor_pin=1;
	}
	else if(motor_time2<64)
	{
		motor_pin=0;
	}
	else
	{
		motor_time2=0;
	}
}
byte step;
void motor_mode3(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
//		tm2s = 0b_0010_0111;//245hz
//		tm2b = 255;	
//		motor_on;
	}
	motor_pin=1;
}
void motor_mode4(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
	//	tm2s = 0b_0010_0111;//245hz
	//	tm2b = 255;	
	//	motor_on;
		motor_time=0;
	}
	if(motor_time<20)
	{
	//	motor_on;
		motor_pin=1;
	}
	else if(motor_time<40)
	{
	//	motor_off;
		motor_pin=0;
	}
	else
	{
		motor_time=0;
	}
}
//无极升速
void motor_mode5(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
//		tm2s = 0b_0010_0111;//245hz
//		tm2b = 153;	
//		motor_on;
		motor_time=0;
		step=38;
//		tm2b=step;
		motor_time2=0;
	}
	
	if(motor_time>=8)
	{
		motor_time=0;
		step++;
		if(step>61) step=38;
	}


	if(motor_time2<step)
	{
		motor_pin=1;
	}
	else if(motor_time2<64)
	{
		motor_pin=0;
	}
	else
	{
		motor_time2=0;
	}
}
void motor_mode6(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
		tm2s = 0b_0010_0111;//245hz
//		tm2b = 255;	
//		motor_on;
		motor_time=0;
		step=0;
	}
	if(step<3)
	{
		if(motor_time<20)
		{
		//	motor_on;
			motor_pin=1;
		}
		else if(motor_time<40)
		{
		//	motor_off;
			motor_pin=0;
		}
		else
		{
			motor_time=0;
			step++;
		}
	}
	else
	{
		if(motor_time<100)
		{
//			motor_on;
			motor_pin=1;
		}
		else if(motor_time<125)
		{
//			motor_off;
			motor_pin=0;
		}
		else
		{
			motor_time=0;
			step++;
			if(step>4)
			{
				step=0;
			}
		}
	}	
}
void motor_mode7(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
//		tm2s = 0b_0010_0111;//245hz
//		tm2b = 255;	
//		motor_on;
		motor_time=0;
		step=0;
	}
	if(step<9)
	{
		if(motor_time<20)
		{
//			motor_on;
			motor_pin=1;
		}
		else if(motor_time<40)
		{
//			motor_off;
			motor_pin=0;
		}
		else
		{
			motor_time=0;
			step++;
		}
	}
	else
	{
		if(motor_time<150)
		{
//			motor_on;
			motor_pin=1;
		}
		else if(motor_time<175)
		{
//			motor_off;
			motor_pin=0;
		}
		else
		{
			motor_time=0;
			step=0;
		}
	}	
}
byte pwm;
void motor_mode8(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
//		tm2s = 0b_0010_0111;//245hz
//		tm2b = 255;	
		pwm=255;
//		motor_on;
		motor_time=0;
		step=0;
		motor_pin=1;
	}
	if(step<1)
	{
		if(motor_time<100)
		{
	//		motor_on;
			motor_pin=1;
		}
		else
		{
			motor_time=0;
			step++;
			motor_time2=0;
			pwm=64;
		}
	} 
	else if(step<2)
	{
		if(motor_time>=5)
		{
			motor_time=0;
			pwm--;
			if(pwm<24) 
			{
				pwm=64;
				step++;
				motor_time=0;
				motor_time2=0;
			}
		}

		if(motor_time2<pwm)
		{
			motor_pin=1;
		}
		else if(motor_time2<64)
		{
			motor_pin=0;
		}
		else
		{
			motor_time2=0;
		}
		/*
		if(motor_time2>51)
		{
			motor_time2=0;
			pwm--;
			if(pwm<102)
			{
				step++;
				pwm=191;
				motor_time=0;
			}
			tm2b = pwm;
		}*/
	}
	else
	{
		if(motor_time>100)
		{
	//		tm2b = 255;	
	//		pwm=255;
			motor_time=0;
			step=0;

		}
		else
		{
			motor_mode2();
		}
	}
}
void motor_mode9(void)
{
	if(motor_state != motor_state_temp)
	{
		motor_state_temp=motor_state;
//		tm2s = 0b_0010_0111;//245hz
//		tm2b = 255;	
//		pwm=255;
//		motor_on;
		motor_time=0;
		step=0;
	}
	if(step<1)
	{
		if(motor_time<20)
		{
//			motor_on;
			motor_pin=1;
		}
		else
		{
			motor_time=0;
			step++;
			motor_time2=0;
			pwm=64;
		}
	} 
	else 
	{
		
		if(motor_time>=5)
		{
			motor_time=0;
			pwm--;
			if(pwm<24) 
			{
				pwm=64;
				step=0;
				motor_time=0;
				motor_time2=0;
			}
		}
		if(motor_time2<pwm)
		{
			motor_pin=1;
		}
		else if(motor_time2<64)
		{
			motor_pin=0;
		}
		else
		{
			motor_time2=0;
		}
	}
}
void motor_even(void)
{
	if(f_work && !f_charging)
	{
		switch(motor_state)
		{
			case 0:			
			//	motor_off;	
				motor_pin=0;
				break;
			case 1:
				motor_mode1();
				break;
			case 2:
				motor_mode2();
				break;
			case 3:
				motor_mode3();	
				break;
			case 4:
				motor_mode4();
				break;
			case 5:
				motor_mode5();
				break;
			case 6:
				motor_mode6();
				break;
			case 7:
				motor_mode7();
				break;
			case 8:
				motor_mode8();
				break;
			case 9:
				motor_mode9();
				break;
			default :
				motor_state=0;
				break;
		}
	}
	else
	{
	//	motor_off;
		motor_pin=0;
	}

}