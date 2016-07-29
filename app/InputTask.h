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

#define INPUT_CM_SPEED_COEFF 0.45f

#define INPUT_SPEED_LR_DIR_COEFF -1
#define INPUT_SPEED_FB_DIR_COEFF -1
#define INPUT_SPEED_RT_DIR_COEFF 1

typedef enum InputMode
{
	INPUT_MODE_STOP  = 0x00,
	INPUT_MODE_LOCAL = 0x01,
	INPUT_MODE_RELAY = 0x02,
}InputMode;

typedef struct CMSpeedRef
{
	float fb;
	float lr;
	float rt;
}CMSpeedRef;

typedef enum SwitchAction
{
	SWITCH_ACTION_NOP  = 0x00,
	SWITCH_ACTION_3TO1 = 0x01,
	SWITCH_ACTION_1TO3 = 0x02,
	SWITCH_ACTION_3TO2 = 0x04,
	SWITCH_ACTION_2TO3 = 0x08,
}SwitchAction;

typedef enum FuncState
{
	OFF = 0,
	ON = !OFF,
}FuncState;

void InputTask(void);

extern InputMode inputMode;
extern CMSpeedRef CMSpeed;
extern SwitchAction S1Action;
extern SwitchAction S2Action;
extern FuncState fanState;
extern FuncState clawState;

#endif
