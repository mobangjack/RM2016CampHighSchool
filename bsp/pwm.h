#ifndef __PWM_H__
#define __PWM_H__

#define PWM1 TIM5->CCR1
#define PWM2 TIM5->CCR2
#define PWM3 TIM5->CCR3

#define SET_FAN_SPEED(speed) (PWM1=speed)
#define SET_AIR_SPEED(speed) (PWM2=speed)
#define SET_BIN_SPEED(speed) (PWM3=speed)

#define FAN_ON()  SET_FAN_SPEED(1600)
#define FAN_OFF() SET_FAN_SPEED(1000)
#define AIR_ON()  SET_AIR_SPEED(1600)
#define AIR_OFF() SET_AIR_SPEED(1000)
#define BIN_ON()  SET_BIN_SPEED(1600)
#define BIN_OFF() SET_BIN_SPEED(1000)

void PWM_Config(void);

#endif

