#include "usually.h"
#include "timer.h"
#include "usart.h"

uint16_t TIM_Count;	//��ʱ������

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
** ��������: TIMER_Init
** ��������: ��ʱ��2��ʼ������
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��6��20��
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void Init_TIMER(void)
{
	TIM_TimeBaseInitTypeDef	 TIM_BaseInitStructure;			//����һ����ʱ���ṹ�����

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);   	//ʹ�ܶ�ʱ��2����Ҫ����

	TIM_DeInit( TIM2);                              		//��IM2��ʱ����ʼ��λ��λֵ

	TIM_InternalClockConfig(TIM2); 							//���� TIM2 �ڲ�ʱ��
	   
	TIM_BaseInitStructure.TIM_Period = 1000; 				//�����Զ����ؼĴ���ֵΪ���ֵ	0~65535֮��  1000000/1000=1000us=1ms													
															//TIM_Period��TIM1_ARR��=1000�����������ϼ�����1000����������¼���
															//����ֵ���� Ҳ���� 1MS���������¼�һ��
	TIM_BaseInitStructure.TIM_Prescaler = 71;  				//�Զ���Ԥ��Ƶϵ�����ṩ����ʱ����ʱ��	0~65535֮��
															//����Ԥ��Ƶ����Ƶϵ��71����APB2=72M, TIM1_CLK=72/72=1MHz 
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ʱ�ӷָ�Ϊ0
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   
															//TIM���ϼ���ģʽ ��0��ʼ���ϼ�����������1000����������¼�
//	TIM_BaseInitStructure.TIM_RepetitionCounter = 0; 		//�˲���ֻ�ʺ���TIM1��TIM8
	TIM_TimeBaseInit(TIM2, &TIM_BaseInitStructure); 		//����ָ��������ʼ��TIMʱ������Ĵ���
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update); 					//���жϣ�����һ�����жϺ����������ж� 
      
    TIM_ARRPreloadConfig(TIM2, DISABLE);					//��ֹARR Ԥװ�ػ�����

	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); 				//ʹ��TIM2�ж�Դ 
	TIM_Cmd(TIM2, ENABLE); 									//TIM2�ܿ��أ����� 
}
/*****************************************************************************
** ��������: TIM2_IRQHandler
** ��������: ��ʱ��2�жϴ�����
				1ms���жϸ���
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��6��20��
*****************************************************************************/ 
void TIM2_IRQHandler(void)
{
	static uint16_t count=0;
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 		//�ж��жϱ�־λ�Ƿ�Ϊ1��Ϊ1���ж���Ӧ����0��û��
    {
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);       	//����жϹ���λ
		count++;
		TIM_Count--;										//��ʱ��ʱ������1
		if(count==500)										//������500MS��1MS*500
		{
			LED2 =~LED2;									//��0.5���������˸
			count=0;	    								//��������
		}			
	}
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
** ��������: TIM_Delay
** ��������: ���ö�ʱ����ʱ			
** ���������� 		��ʱʱ��T = time*1(MS) 
** ��  ����: Dream
** �ա�  ��: 2011��6��20��
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void TIM_Delay(uint16_t time)  //��ʱ����
{ 
	TIM_Count = time;
	while(TIM_Count);
}


/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
** ��������: Delay_Ms_Ms
** ��������: ��ʱ1MS (��ͨ���������ж�����׼ȷ��)			
** ����������time (ms) ע��time<65535
** ��  ����: Dream
** �ա�  ��: 2011��6��20��
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void Delay_Ms(uint16_t time)  //��ʱ����
{ 
	uint16_t i,j;
	for(i=0;i<time;i++)
  		for(j=0;j<10260;j++);
}
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
** ��������: Delay_Ms_Us
** ��������: ��ʱ1us (��ͨ���������ж�����׼ȷ��)
** ����������time (us) ע��time<65535				 
** ��  ����: Dream
** �ա�  ��: 2011��6��20��
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void Delay_Us(uint16_t time)  //��ʱ����
{ 
	uint16_t i,j;
	for(i=0;i<time;i++)
  		for(j=0;j<9;j++);
}
