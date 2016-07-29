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

PID CM1SpeedPID = CM_SPEED_PID_DEFAULT;
PID CM2SpeedPID = CM_SPEED_PID_DEFAULT;
PID CM3SpeedPID = CM_SPEED_PID_DEFAULT;
PID CM4SpeedPID = CM_SPEED_PID_DEFAULT;

void InputModeCtrl(void)
{
	
}

void CMCtrlLoop(void)
{
	static const float conv = 0.15f;
	
	CM1SpeedPID.ref = -CMSpeed.fb*conv + CMSpeed.lr*conv + CMSpeed.rt*conv;
	CM2SpeedPID.ref =  CMSpeed.fb*conv + CMSpeed.lr*conv + CMSpeed.rt*conv;
	CM3SpeedPID.ref =  CMSpeed.fb*conv - CMSpeed.lr*conv + CMSpeed.rt*conv;
	CM4SpeedPID.ref = -CMSpeed.fb*conv - CMSpeed.lr*conv + CMSpeed.rt*conv;
	
	CM1SpeedPID.fdb = CM1Encoder.rate;
	CM2SpeedPID.fdb = CM2Encoder.rate;
	CM3SpeedPID.fdb = CM3Encoder.rate;
	CM4SpeedPID.fdb = CM4Encoder.rate;
	
	CM1SpeedPID.Calc(&CM1SpeedPID);
	CM2SpeedPID.Calc(&CM2SpeedPID);
	CM3SpeedPID.Calc(&CM3SpeedPID);
	CM4SpeedPID.Calc(&CM4SpeedPID);
	
	SetCMSpeed(CAN2, CM1SpeedPID.output, CM2SpeedPID.output, CM3SpeedPID.output, CM4SpeedPID.output);
}

void FanStateCtrl(void)
{
	if(fanState == ON)
		SET_FAN_SPEED(1600);
	else
		SET_FAN_SPEED(1000);
}

void ClawStateCtrl(void)
{
	if(clawState == ON)
		SET_CLAW_SPEED(1600);
	else
		SET_CLAW_SPEED(1000);
}

static uint32_t ms_tick = 0;
void OutputTask(void)
{
	ms_tick++;
	
	CMCtrlLoop();
	if(ms_tick % 2 == 0)
	{
		FanStateCtrl();
		ClawStateCtrl();
	}
}


