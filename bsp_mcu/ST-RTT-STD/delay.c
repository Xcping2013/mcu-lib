#include "delay.h"
#include <rtthread.h>

void delay_us(int us)
{
	rt_uint32_t delta;
	/* �����ʱ������tick�� */
	us = us * (SysTick->LOAD/(1000000/RT_TICK_PER_SECOND));
	/* ��õ�ǰʱ�� */
	delta = SysTick->VAL;
	/* ѭ����õ�ǰʱ�䣬ֱ���ﵽָ����ʱ����˳�ѭ�� */
	while (delta - SysTick->VAL< us);
}

void delay_ms(u16 nms)
{
	rt_thread_delay(nms/10);
}
