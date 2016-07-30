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
 
#ifndef __CRC8_H__
#define __CRC8_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

	extern const uint8_t CRC8Table[256];
	extern const uint8_t INIT_CRC8;

	extern uint8_t CRC8Calc(uint8_t* msg, uint32_t len, uint8_t crc8);
	extern uint8_t CRC8Check(uint8_t* msg, uint32_t len, uint8_t crc8);
	extern uint8_t CRC8Append(uint8_t* msg, uint32_t len, uint8_t crc8);

#ifdef __cplusplus
}
#endif

#endif
