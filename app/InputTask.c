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
 
#include "main.h"

InputMode inputMode = INPUT_MODE_STOP;
CMSpeedRef CMSpeed = {0, 0, 0};
SwitchAction S1Action = SWITCH_ACTION_NOP;
SwitchAction S2Action = SWITCH_ACTION_NOP;
FuncState fanState = OFF;
FuncState clawState = OFF;

void GetInputMode()
{
	if(dbus.rc.s2 == SW_MD)
		inputMode = INPUT_MODE_LOCAL;
	else if(dbus.rc.s2 == SW_UP)
		inputMode = INPUT_MODE_RELAY;
	else
		inputMode = INPUT_MODE_STOP;
}

void GetCMSpeed()
{
	CMSpeed.lr = (dbus.rc.ch0 - CH_MID) * INPUT_CM_SPEED_COEFF * INPUT_SPEED_LR_DIR_COEFF;
	CMSpeed.fb = (dbus.rc.ch1 - CH_MID) * INPUT_CM_SPEED_COEFF * INPUT_SPEED_FB_DIR_COEFF;
	CMSpeed.rt = (dbus.rc.ch2 - CH_MID) * INPUT_CM_SPEED_COEFF * INPUT_SPEED_RT_DIR_COEFF;
}

SwitchAction ActionSM(uint8_t thisState, uint8_t lastState)
{
	switch(lastState)
	{
		case SW_MD:
			if(thisState == SW_MD)
				return SWITCH_ACTION_NOP;
			if(thisState == SW_UP)
				return SWITCH_ACTION_3TO1;
			if(thisState == SW_DN)
				return SWITCH_ACTION_3TO2;
			return SWITCH_ACTION_NOP;
		case SW_UP:
			if(thisState == SW_MD)
				return SWITCH_ACTION_1TO3;
			if(thisState == SW_UP)
				return SWITCH_ACTION_NOP;
			if(thisState == SW_DN)
				return SWITCH_ACTION_NOP;
			return SWITCH_ACTION_NOP;
		case SW_DN:
			if(thisState == SW_MD)
				return SWITCH_ACTION_2TO3;
			if(thisState == SW_UP)
				return SWITCH_ACTION_NOP;
			if(thisState == SW_DN)
				return SWITCH_ACTION_NOP;
			return SWITCH_ACTION_NOP;
		default:
			return SWITCH_ACTION_NOP;
	}
}

void GetSwitchAction()
{
	static uint8_t last_s1 = 10;
	static uint8_t last_s2 = 10;
	uint8_t this_s1 = dbus.rc.s1;
	uint8_t this_s2 = dbus.rc.s2;
	S1Action = ActionSM(this_s1, last_s1);
	S2Action = ActionSM(this_s2, last_s2);
	last_s1 = this_s1;
	last_s2 = this_s2;
}

void GetFanState()
{
	fanState = (S1Action == SWITCH_ACTION_3TO1) ? (!fanState) : fanState;
}

void GetClawState()
{
	clawState = (S1Action == SWITCH_ACTION_3TO2) ? (!clawState) : clawState;
}

void InputTask(void)
{
	GetInputMode();
	GetCMSpeed();
	GetSwitchAction();
	GetFanState();
	GetClawState();
}
