#include "led.h"
#include "usually.h"
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
** ��������: Init_LED
** ��������: LED IO��������
** ������������
** ��  ����: Dream
** �ա�  ��: 2011��6��20��
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void Init_LED(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;					//����һ��GPIO�ṹ�����

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD 
							| RCC_APB2Periph_GPIOE,ENABLE);	//ʹ�ܸ����˿�ʱ�ӣ���Ҫ������
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_12 
	| GPIO_Pin_13; 											//����LED�˿ڹҽӵ�6��12��13�˿�
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	   	//ͨ���������
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	   	//���ö˿��ٶ�Ϊ50M
  	GPIO_Init(GPIOD, &GPIO_InitStructure);				   	//���ݲ�����ʼ��GPIOD�Ĵ���
}

//������LED�ƿ���
//
//
void UltraSonic_LED_ON(uint8_t channel,uint16_t time)
{
}


//������LED�ƿ���
//
//
void UltraSonic_LED_OFF(uint8_t channel)
{
}
