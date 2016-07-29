#ifndef __USART1_H__
#define __USART1_H__

#include "dbus.h"

#define RC_FRAME_LEN 18u
#define USART1_DMA_RX_BUF_SIZE 36u

void USART1_Config(void);

extern DBUS dbus;

#endif
