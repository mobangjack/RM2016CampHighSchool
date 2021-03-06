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
 
#ifndef __RELAY_TASK_H__
#define __RELAY_TASK_H__

#include <stdint.h>

#define RELAY_BUF_SIZE 9
#define RELAY_BEADER 0xaa
#define RELAY_INIT_CRC16 0x6789

void RelayTask(void);

extern uint8_t relay_buf[RELAY_BUF_SIZE];

#endif
