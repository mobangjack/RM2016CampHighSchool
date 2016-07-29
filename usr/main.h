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
 
#ifndef __MAIN_H__
#define __MAIN_H__

#include "stm32f4xx.h"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#include "bsp.h"
#include "can1.h"
#include "can2.h"
#include "cbus.h"
#include "crc8.h"
#include "crc16.h"
#include "crc32.h"
#include "dbus.h"
#include "delay.h"
#include "encoder.h"
#include "fifo.h"
#include "led.h"
#include "motor.h"
#include "pid.h"
#include "pwm.h"
#include "QuadEncoder.h"
#include "ramp.h"
#include "timer.h"
#include "usart1.h"
#include "usart3.h"

#include "Can1Task.h"
#include "Can2Task.h"
#include "InputTask.h"
#include "OutputTask.h"
#include "RelayTask.h"

#endif 
