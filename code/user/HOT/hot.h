void hot_init(void);
void hot_even(void);
void hot_40pwm(void);
void hot_50pwm(void);
void hot_even(void);

hot_pwm equ pa.4

#define hot_on 		tm2c = 0b_0010_11_1_0;	 // ϵͳʱ��, ��� = P3, PWM ģʽ
#define hot_off 	tm2c = 0b_0010_00_1_0;	 // ϵͳʱ��, ��� = PA3, PWM ģʽ