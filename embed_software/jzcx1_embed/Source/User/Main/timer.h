#ifndef _TIMER_H_
#define _TIMER_H_

#include "stdio.h"
#include "string.h"
#include "stdint.h"

//���庯��ԭ��
void Init_TIMER(void);
void TIM2_IRQHandler(void);
void Delay_Ms(uint16_t time);
void Delay_Us(uint16_t time);  //��ʱ����
void TIM_Delay(uint16_t time);


#endif
