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
 
#include "ramp.h"

void Ramp_Init(Ramp* ramp, uint32_t scale)
{
	ramp->scale = scale;
}

float Ramp_Calc(Ramp* ramp)
{
	if(ramp->count < ramp->scale)
	{
		ramp->count++;
		return (float)ramp->count / (float)ramp->scale;
	}
	else
		return 1.f;
}

void Ramp_SetCounter(Ramp* ramp, uint32_t count)
{
	ramp->count = count;
}

void Ramp_ResetCounter(Ramp* ramp)
{
	ramp->count = 0;
}

void Ramp_SetScale(Ramp* ramp, uint32_t scale)
{
	ramp->scale = scale;
}

uint8_t Ramp_IsOverFlow(Ramp* ramp)
{
	return ramp->count >= ramp->scale;
}
