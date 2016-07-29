#include "main.h"

/*-----USART3_TX-----PB10-----*/
/*-----USART3_RX-----PB11-----*/

FIFO* usart3_tx_fifo = NULL;

void USART3_Config(void)
{
    USART_InitTypeDef usart3;
    GPIO_InitTypeDef  gpio;
    NVIC_InitTypeDef  nvic;
	
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);

    GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_USART3);
    GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_USART3); 

    gpio.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    gpio.GPIO_Mode = GPIO_Mode_AF;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_Speed = GPIO_Speed_100MHz;
    gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB,&gpio);

    usart3.USART_BaudRate = 115200;          // speed 10byte/ms
    usart3.USART_WordLength = USART_WordLength_8b;
    usart3.USART_StopBits = USART_StopBits_1;
    usart3.USART_Parity = USART_Parity_No;
    usart3.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
    usart3.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART3,&usart3);

    USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
    USART_Cmd(USART3,ENABLE);

    nvic.NVIC_IRQChannel = USART3_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority = 0;
    nvic.NVIC_IRQChannelCmd = ENABLE; 
    NVIC_Init(&nvic);

	usart3_tx_fifo = FIFO_Create(USART3_TX_FIFO_SIZE);
}


void USART3_Print(uint8_t ch)
{    
    FIFO_Push(usart3_tx_fifo, ch);
    USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
}

void USART3_PrintBlock(uint8_t* pdata, uint8_t len)
{
	uint32_t i = 0;
	for(i = 0; i < len; i++)
	{
		FIFO_Push(usart3_tx_fifo, pdata[i]);
	}
    USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
}


int fputc(int ch, FILE *f)
{
    while (USART_GetFlagStatus(USART3,USART_FLAG_TC) == RESET);
    USART_SendData(USART3, (uint8_t)ch);
    return ch;
}

void USART3_IRQHandler(void)
{  
    if(USART_GetITStatus(USART3, USART_IT_TXE) != RESET)
    {   
		while(!FIFO_IsEmpty(usart3_tx_fifo))
		{
			uint8_t tx_data;
			FIFO_Pop(usart3_tx_fifo, &tx_data);
			while (USART_GetFlagStatus(USART3,USART_FLAG_TC) == RESET);
			USART_SendData(USART3, tx_data);
		}
		USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
    }
	else if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {
        uint8_t rx_data = USART_ReceiveData(USART3);
       
    }       
}

