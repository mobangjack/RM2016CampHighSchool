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
 
#ifndef __RAMP_H__
#define __RAMP_H__

#ifdef __cpluplus
extern "C" {
#endif

#include <stdint.h>
	
typedef struct Ramp
{
	uint32_t count;
	uint32_t scale;
	void (*Init)(struct Ramp* ramp, uint32_t scale);
	float (*Calc)(struct Ramp* ramp);
	void (*SetCounter)(struct Ramp* ramp, uint32_t count);
	void (*ResetCounter)(struct Ramp* ramp);
	void (*SetScale)(struct Ramp* ramp, uint32_t scale);
	uint8_t (*IsOverFlow)(struct Ramp* ramp);
}Ramp;

void Ramp_Init(Ramp* ramp, uint32_t scale);
float Ramp_Calc(Ramp* ramp);
void Ramp_SetCounter(Ramp* ramp, uint32_t count);
void Ramp_ResetCounter(Ramp* ramp);
void Ramp_SetScale(Ramp* ramp, uint32_t scale);
uint8_t Ramp_IsOverFlow(Ramp* ramp);

#define RAMP_DEFAULT { \
	.count = 0, \
	.scale = 0, \
	.output = 0, \
	.Init = &Ramp_Init, \
	.Calc = &Ramp_Calc, \
	.SetCounter = &Ramp_SetCounter \
	.ResetCounter = &Ramp_ResetCounter, \
	.SetScale = &Ramp_SetScale, \
	.IsOverFlow = Ramp_IsOverFlow \
} \
	
#ifdef __cpluplus
}
#endif

#endif

