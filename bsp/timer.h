#ifndef __TIMER_H__
#define __TIMER_H__

#define MS_TICK() (TIM2->CNT)

void TIM6_Config(void);
void TIM2_Config(void);

void TIM6_Start(void);

#endif
