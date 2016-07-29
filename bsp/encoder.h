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
 
#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <stdint.h>

#define ENCODER_VAL_MAX 8191
#define ENCODER_VAL_MOD 8192
#define ENCODER_DIFF_MAX 7500
#define ENCODER_RATE_BUF_SIZE 6
#define ENCODER_INIT_FRAME_COUNT 50

typedef struct Encoder
{
	uint16_t value;
	uint16_t last_value;
	int32_t diff;
	uint16_t bias;
	int32_t round;
	int32_t scale;
	float angle;
	int32_t rate_raw;
	int32_t rate_buf[ENCODER_RATE_BUF_SIZE];
	uint32_t rate_cnt;
	int32_t rate;
	uint32_t init_frame_count;
}Encoder;

void Encoder_Process(Encoder* encoder, uint16_t value);

#endif
