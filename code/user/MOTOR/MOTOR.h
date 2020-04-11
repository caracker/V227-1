void motor_init(void);
void motor_even(void);
void pwm_init(void);
//#define motor_on 	tm2c = 0b_0001_10_1_0;	 // 系统时钟, 输出 = P3, PWM 模式
//#define motor_off 	tm2c = 0b_0001_00_1_0;	 // 系统时钟, 输出 = PA3, PWM 模式
#define motor_pin   PA.3