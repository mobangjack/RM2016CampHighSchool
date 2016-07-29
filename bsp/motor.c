#include "main.h"

void SetCMSpeed(CAN_TypeDef *CANx, int16_t c201, int16_t c202, int16_t c203, int16_t c204)
{
	CanTxMsg canTxMsg;
    canTxMsg.StdId = CHASSIS_MOTOR_CAN_TX_MSG_ID;
    canTxMsg.IDE = CAN_Id_Standard;
    canTxMsg.RTR = CAN_RTR_Data;
    canTxMsg.DLC = 0x08;
    
    canTxMsg.Data[0] = (uint8_t)(c201 >> 8);
    canTxMsg.Data[1] = (uint8_t)c201;
    canTxMsg.Data[2] = (uint8_t)(c202 >> 8);
    canTxMsg.Data[3] = (uint8_t)c202;
    canTxMsg.Data[4] = (uint8_t)(c203 >> 8);
    canTxMsg.Data[5] = (uint8_t)c203;
    canTxMsg.Data[6] = (uint8_t)(c204 >> 8);
    canTxMsg.Data[7] = (uint8_t)c204;
    CAN_Transmit(CANx,&canTxMsg);
}

void SetGMSpeed(CAN_TypeDef *CANx, int16_t c205, int16_t c206)
{
	CanTxMsg canTxMsg;
    canTxMsg.StdId = GIMBALS_MOTOR_CAN_TX_MSG_ID;
    canTxMsg.IDE = CAN_Id_Standard;
    canTxMsg.RTR = CAN_RTR_Data;
    canTxMsg.DLC = 0x08;
    
    canTxMsg.Data[0] = (uint8_t)(c205 >> 8);
    canTxMsg.Data[1] = (uint8_t)c205;
    canTxMsg.Data[2] = (uint8_t)(c206 >> 8);
    canTxMsg.Data[3] = (uint8_t)c206;
    canTxMsg.Data[4] = (uint8_t)0x00;
    canTxMsg.Data[5] = (uint8_t)0x00;
    canTxMsg.Data[6] = (uint8_t)0x00;
    canTxMsg.Data[7] = (uint8_t)0x00;
    CAN_Transmit(CANx,&canTxMsg);
}
