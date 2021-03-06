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
 
#ifndef __CAN2_TASK_H__
#define __CAN2_TASK_H__

#include "encoder.h"

void Can2Task(void);

extern Encoder CM1Encoder;
extern Encoder CM2Encoder;
extern Encoder CM3Encoder;
extern Encoder CM4Encoder;
extern Encoder GMYEncoder;
extern Encoder GMPEncoder;

#endif
