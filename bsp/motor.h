#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <stdint.h>
#include "stm32f4xx.h"

#define CHASSIS_MOTOR_CAN_TX_MSG_ID 0x200
#define GIMBALS_MOTOR_CAN_TX_MSG_ID 0x1ff

#define MOTOR1_FEEDBACK_CAN_MSG_ID  0x201
#define MOTOR2_FEEDBACK_CAN_MSG_ID  0x202 
#define MOTOR3_FEEDBACK_CAN_MSG_ID  0x203
#define MOTOR4_FEEDBACK_CAN_MSG_ID  0x204
#define MOTOR5_FEEDBACK_CAN_MSG_ID  0x205
#define MOTOR6_FEEDBACK_CAN_MSG_ID  0x206

void SetCMSpeed(CAN_TypeDef *CANx, int16_t c201, int16_t c202, int16_t c203, int16_t c204);
void SetGMSpeed(CAN_TypeDef *CANx, int16_t c205, int16_t c206);

#endif
