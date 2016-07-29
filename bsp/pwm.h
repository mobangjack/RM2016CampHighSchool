#ifndef __PWM_H__
#define __PWM_H__

#define PWM1 TIM5->CCR1
#define PWM2 TIM5->CCR2
#define PWM3 TIM5->CCR3

#define SET_FAN_SPEED(speed) (PWM1=speed)
#define SET_CLAW_SPEED(speed) (PWM2=speed)

void PWM_Config(void);

#endif

