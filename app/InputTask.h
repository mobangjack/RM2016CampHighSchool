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
 
#ifndef __INPUT_TASK_H__
#define __INPUT_TASK_H__

#include <stdint.h>

#define ON 1
#define OFF 0

#define INPUT_CM_SPEED_COEFF 0.45f
#define INPUT_GM_SPEED_COEFF 0.01f
#define INPUT_LR_SPEED_DIR_COEFF -1
#define INPUT_FB_SPEED_DIR_COEFF -1
#define INPUT_RT_SPEED_DIR_COEFF 1
#define INPUT_ARM_SPEED_DIR_COEFF 1
#define INPUT_WRIST_SPEED_DIR_COEFF 1
#define INPUT_CLAW_SPEED_DIR_COEFF 1

#define SWITCH_ACTION_3TO1 (1<<2 | 3)
#define SWITCH_ACTION_1TO3 (3<<2 | 1)
#define SWITCH_ACTION_3TO2 (2<<2 | 3)
#define SWITCH_ACTION_2TO3 (3<<2 | 2)
#define SWITCH_ACTION_NONE 0

typedef enum
{
	WORKING_STATE_MOVING = 0x00,
	WORKING_STATE_GRABBING = 0x01,
}WorkingState;

typedef struct
{
	float fb;
	float lr;
	float rt;
}CMSpeedRef;

typedef struct
{
	float arm;
	float wrist;
	float claw;
}GMSpeedRef;

typedef uint8_t SwitchAction;

typedef uint8_t FuncState;

void InputTask(void);

extern WorkingState workingState;
extern CMSpeedRef CMSpeed;
extern GMSpeedRef GMSpeed;
extern SwitchAction S1Action;
extern SwitchAction S2Action;
extern FuncState fanState;
extern FuncState airState;
extern FuncState binState;

#endif
