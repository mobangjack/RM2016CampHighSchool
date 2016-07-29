#ifndef __USART3_H__
#define __USART3_H__

#include <stdint.h>

#define USART3_TX_FIFO_SIZE 128u

void USART3_Config(void);

void USART3_Print(uint8_t ch);
void USART3_PrintBlock(uint8_t* pdata, uint8_t len);

#endif
