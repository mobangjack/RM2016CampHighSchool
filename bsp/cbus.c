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
 
#include "cbus.h"

void CBUS_Push(Msg* msg, uint8_t* dst)
{
	uint8_t i = 0;
	dst[0] = CBUS_MSG_HEADER;
	dst[1] = msg->id;
	for(i = 0; i < CBUS_MSG_DATA_LEN; i++)
	{
		dst[2+i] = msg->data[i];
	}
	CRC16Append(dst, CBUS_SIZE(), CBUS_MSG_INIT_CRC16);
}

uint8_t CBUS_Pop(Msg* msg,uint8_t* src)
{
	if(src[0] != CBUS_MSG_HEADER) return 0;
	if(!CRC16Check(src, CBUS_SIZE(), CBUS_MSG_INIT_CRC16)) return 0;
	//msg = (Msg*)(src+1);
	return 1;
}
