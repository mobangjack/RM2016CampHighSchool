/**
 * Copyright (c) 2011-2016, Mobangjack Ī��� (mobangjack@foxmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include "main.h"

//INPUT_B---PB4(TIM3_CH1)
//INPUT_A---PB5(TIM3_CH2)

void QuadEncoder_Config(void)
{
    GPIO_InitTypeDef gpio;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	gpio.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_4;
    gpio.GPIO_Speed = GPIO_Speed_100MHz;
	gpio.GPIO_Mode = GPIO_Mode_AF;
	gpio.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB,&gpio);
	
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource5,GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource4,GPIO_AF_TIM3);
	
    TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Falling, TIM_ICPolarity_Falling);
    TIM_Cmd(TIM3,ENABLE);
	
	QUAD_ENCODER_START();
	
}

