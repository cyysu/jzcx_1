#include "user_sys_config.h"



/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
** ��������: Init_NVIC
** ��������: ϵͳ�ж�����
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��5��14��
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void Init_NVIC(void)
{ 	
  	NVIC_InitTypeDef NVIC_InitStructure;			//����һ��NVIC������ṹ�����

	#ifdef  VECT_TAB_RAM  							//���������ַѡ��

	  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);  	//��0x20000000��ַ��Ϊ���������ַ(RAM)
	#else  

	  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0); //��0x08000000��ַ��Ϊ���������ַ(FLASH)  
	#endif

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//�����ж��� Ϊ2 

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			//���ô���1Ϊ�ж�Դ
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; 	//����ռ�����ȼ�Ϊ2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		  	//���ø����ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			  	//ʹ�ܴ���1�ж�
	NVIC_Init(&NVIC_InitStructure);							  	//���ݲ�����ʼ���жϼĴ���
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); 		//�����ж���Ϊ0

	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; 		//�ж��¼�ΪTIM2
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ�0 						
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;      //��Ӧ���ȼ�1 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;         //�����ж� 
	NVIC_Init(&NVIC_InitStructure);                         //����ָ��������ʼ���жϼĴ���
	
}
