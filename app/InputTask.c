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

WorkingState workingState = WORKING_STATE_MOVING;
CMSpeedRef CMSpeed = {0};
GMSpeedRef GMSpeed = {0};
SwitchAction S1Action = SWITCH_ACTION_NONE;
SwitchAction S2Action = SWITCH_ACTION_NONE;
FuncState fanState = OFF;
FuncState airState = OFF;
FuncState binState = OFF;

void GetWorkingState(void)
{
	if(dbus.rc.s2 == SW_UP)
		workingState = WORKING_STATE_GRABBING;
	else
		workingState = WORKING_STATE_MOVING;
}

void GetCMSpeed(void)
{
	if(workingState == WORKING_STATE_MOVING)
	{
		CMSpeed.lr = (dbus.rc.ch0 - CH_MID) * INPUT_CM_SPEED_COEFF * INPUT_LR_SPEED_DIR_COEFF;
		CMSpeed.fb = (dbus.rc.ch1 - CH_MID) * INPUT_CM_SPEED_COEFF * INPUT_FB_SPEED_DIR_COEFF;
		CMSpeed.rt = (dbus.rc.ch2 - CH_MID) * INPUT_CM_SPEED_COEFF * INPUT_RT_SPEED_DIR_COEFF;
	}
	else
	{
		CMSpeed.rt = (dbus.rc.ch0 - CH_MID) * INPUT_CM_SPEED_COEFF * INPUT_RT_SPEED_DIR_COEFF;
		CMSpeed.fb = CMSpeed.lr = 0;
	}
}

void GetGMSpeed(void)
{
	if(workingState == WORKING_STATE_GRABBING)
	{
		GMSpeed.arm   = (dbus.rc.ch1 - CH_MID) * INPUT_GM_SPEED_COEFF * INPUT_ARM_SPEED_DIR_COEFF;
		GMSpeed.wrist = (dbus.rc.ch3 - CH_MID) * INPUT_GM_SPEED_COEFF * INPUT_WRIST_SPEED_DIR_COEFF;
		GMSpeed.claw  = (dbus.rc.ch2 - CH_MID) * INPUT_GM_SPEED_COEFF * INPUT_CLAW_SPEED_DIR_COEFF;
	}
	else
	{
		GMSpeed.arm = GMSpeed.wrist = GMSpeed.claw = 0;
	}
}

SwitchAction ActionSM(uint8_t thisState, uint8_t lastState)
{
	return ((thisState << 2) | lastState);
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
	if(workingState == WORKING_STATE_MOVING)
	{
		fanState = OFF;
	}
	else
	{
		fanState = (S1Action == SWITCH_ACTION_3TO1) ? (!fanState) : fanState;
	}
}

void GetAirState()
{
	if(workingState == WORKING_STATE_MOVING)
	{
		airState = OFF;
	}
	else
	{
		airState = (S1Action == SWITCH_ACTION_3TO2) ? (!airState) : airState;
	}
}

void GetBinState(void)
{
	if(workingState == WORKING_STATE_MOVING)
	{
		binState = OFF;
	}
	else
	{
		binState = (S2Action == SWITCH_ACTION_3TO2) ? (!binState) : binState;
	}
}

void InputTask(void)
{
	GetSwitchAction();
	GetWorkingState();
	GetCMSpeed();
	GetFanState();
	GetAirState();
	GetBinState();
}
