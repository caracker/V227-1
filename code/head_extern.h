#ifndef __head_extern_H
#define __head_extern_H	

//*************************************************//
//�����Ķ��壬�޸ı�������ͬ���޸�head_extern.h
//***********************************************//

extern  BYTE	Sys_Flag;
BIT		f_work		:	Sys_Flag.0;		//���ػ�
BIT		f_charging	:	Sys_Flag.1;		//���
bit     f_key_scan	:	Sys_Flag.2;		//����ɨ��
bit     f_heating   :	Sys_Flag.3;		//����
bit     f_low  		:	Sys_Flag.4;		//�͵�ѹ
extern  BYTE motor_state;		//��﹤��ģʽ0~7
extern  BYTE count;//T16����
extern  BYTE S1_count,s2_count;//��������
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