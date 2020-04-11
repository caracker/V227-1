#include	"led.h"
#include "../../head_extern.h"
#include	"../key/key.h"
#include	"../motor/motor.h"
#include	"../led/led.h"
#define led_on	0
#define led_off 1
void led_init(void)
{ 
	$ led_blue out,low;
	led_blue=led_off;
}

void led_even(void)
{
	blue_even();
}
void blue_even(void)
{
	if(f_charging)
	{

		led_blue=led_off;
	}
	else
	{
		if(!f_low)
		{
			if(!s1 ||f_heating)
			{
				if(!s1)
				{
					led_blue=led_on;
					led_time=0;
				}
				else
				{
					if(led_time<48*4)
					{
						led_blue=led_on;
					}
					else if(led_time<80*4)
					{
						led_blue=led_off;
					}
					else
					{
						led_time=0;
					}
				}
			}
			else
			{
				led_blue=led_off;
			}
		}
		else
		{
			if(led_time<781*4)
			{
				led_blue=led_on;
			}
			else if(led_time<1562*4)
			{
				led_blue=led_off;
			}
			else
			{
				led_time=0;
			}	
		}

	}
	
}

