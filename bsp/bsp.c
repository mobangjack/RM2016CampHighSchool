#include "main.h"

void BSP_Config(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	PWM_Config();
	Led_Config();
	TIM2_Config();
	TIM6_Config();
	CAN1_Config();           
	CAN2_Config(); 
	USART1_Config();
	USART3_Config();
	QuadEncoder_Config();
	TIM6_Start();
	LED_GREEN_ON();
}

