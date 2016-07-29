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
 
 /***************************************/
 /***** Uniform Serial Control Bus ******/
 /***************************************/
 
#ifndef __CBUS_H__
#define __CBUS_H__

#ifdef __cpluplus
extern "C" {
#endif

#include <stdint.h>
#include "crc16.h"
	
#define CBUS_MSG_HEADER 0xaa
#define CBUS_MSG_DATA_LEN 8
#define CBUS_MSG_INIT_CRC16 0x6999
	
#pragma pack(1)
typedef struct Msg
{
	uint8_t id;
	uint16_t data[CBUS_MSG_DATA_LEN];
}Msg;

#pragma pack(1)
typedef struct CBUS
{
	uint8_t header;
	uint8_t ch0;
	uint8_t ch1;
	uint8_t ch2;
	uint8_t ch3;
	uint8_t s1;
	uint16_t crc16;
}CBUS;

#define CBUS_SIZE() sizeof(CBUS)

#ifdef __cpluplus
}
#endif
	
#endif
