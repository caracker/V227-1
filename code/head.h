#ifndef __HEAD_H
#define __HEAD_H	

//*************************************************//
//�����Ķ��壬�޸ı�������ͬ���޸�head_extern.h
//***********************************************//

BYTE	Sys_Flag;
BIT		f_work		:	Sys_Flag.0;		//���ػ�
BIT		f_charging	:	Sys_Flag.1;		//���
bit     f_key_scan	:	Sys_Flag.2;		//����ɨ��
bit     f_heating   :	Sys_Flag.3;		//����
bit     f_low  		:	Sys_Flag.4;		//�͵�ѹ
byte motor_state;		//��﹤��ģʽ0~7
byte count;//T16����
byte S1_count,s2_count;//��������
word motor_time,motor_time2;
WORD sleep_time;
word led_time;
word hot_time;
byte hot_mode;

#endif