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

static volatile float ZGyroModuleAngle = 0;

void Can1Task(void)
{      
	switch(can1RxMsg.StdId)
	{
		case ZGYRO_FEEDBACK_CAN_MSG_ID:
		{
			ZGyroModuleAngle = -0.01f*((int32_t)(can1RxMsg.Data[0]<<24)|(int32_t)(can1RxMsg.Data[1]<<16) | (int32_t)(can1RxMsg.Data[2]<<8) | (int32_t)(can1RxMsg.Data[3])); 
		}break;
		default:
		{
		}
	}
}

float GetZGyroModuleAngle(void)
{
	return ZGyroModuleAngle;
}

