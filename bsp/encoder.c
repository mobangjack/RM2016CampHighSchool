/**
 * Copyright (c) 2011-2016, Mobangjack Äª°ï½Ü (mobangjack@foxmail.com).
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

void Encoder_Process(Encoder* encoder, uint16_t value)
{
	uint8_t i = 0;
	int sum = 0;
	if(encoder->init_frame_count < ENCODER_INIT_FRAME_COUNT)
	{
		encoder->init_frame_count++;
		encoder->bias = value;
	}
	encoder->last_value = encoder->value;
	encoder->value = value;
	encoder->diff = encoder->value - encoder->last_value;
	if(encoder->diff > ENCODER_DIFF_MAX)
	{
		encoder->rate_raw = encoder->diff - ENCODER_VAL_MOD;
		encoder->round--;
	}
	else if(encoder->diff < -ENCODER_DIFF_MAX)
	{
		encoder->rate_raw = encoder->diff + ENCODER_VAL_MOD;
		encoder->round++;
	}
	else
	{
		encoder->rate_raw = encoder->diff;
	}
	encoder->scale = encoder->value + encoder->round * ENCODER_VAL_MOD;
	encoder->angle = (encoder->value - encoder->bias) * 360.f/ENCODER_VAL_MOD + encoder->round * 360;
	encoder->rate_buf[encoder->rate_cnt++] = encoder->rate_raw;
	if(encoder->rate_cnt == ENCODER_RATE_BUF_SIZE)
	{
		encoder->rate_cnt = 0;
	}
	for(i = 0; i < ENCODER_RATE_BUF_SIZE; i++)
	{
		sum+=encoder->rate_buf[i];
	}
	encoder->rate = sum / ENCODER_RATE_BUF_SIZE;
}

