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
 
#include "fifo.h"

FIFO* FIFO_Create(uint32_t len)
{
	FIFO* fifo = (FIFO*)malloc(sizeof(FIFO));
	if(fifo == NULL) return NULL;
	fifo->buf = (uint8_t*)malloc(len);
	if(fifo->buf == NULL)
	{
		free(fifo);
		fifo = NULL;
		return NULL;
	}
	fifo->len = len;
	fifo->rpt = 0;
	fifo->wpt = 0;
	fifo->Push = &FIFO_Push;
	fifo->Pop = &FIFO_Pop;
	fifo->IsFull = &FIFO_IsFull;
	fifo->IsEmpty = &FIFO_IsEmpty;
	fifo->GetUsedSpace = &FIFO_GetUsedSpace;
	fifo->GetFreeSpace = &FIFO_GetFreeSpace;
	return fifo;
}

uint8_t FIFO_Push(FIFO* fifo, uint8_t ele)
{
	if(FIFO_IsFull(fifo))
	{
		return 0;
	}
	if(fifo->wpt == fifo->len)
	{
		uint32_t i = fifo->rpt;
		for(; i < fifo->len; i++)
		{
			fifo->buf[i-fifo->rpt] = fifo->buf[i];
		}
		fifo->wpt = fifo->len - fifo->rpt;
		fifo->rpt = 0;
	}
	fifo->buf[fifo->wpt++] = ele;
	return 1;
}

uint8_t FIFO_Pop(FIFO* fifo, uint8_t* ele)
{
	if(FIFO_IsEmpty(fifo))
	{
		return 0;
	}
	*ele = fifo->buf[fifo->rpt++];
	return 1;
}

uint8_t FIFO_IsFull(FIFO* fifo)
{
	return fifo->rpt == 0 && fifo->wpt == fifo->len;
}

uint8_t FIFO_IsEmpty(FIFO* fifo)
{
	return fifo->rpt == fifo->wpt;
}

uint32_t FIFO_GetUsedSpace(FIFO* fifo)
{
	return fifo->wpt - fifo->rpt;
}

uint32_t FIFO_GetFreeSpace(FIFO* fifo)
{
	return fifo->len - fifo->wpt + fifo->rpt;
}

void FIFO_Destroy(FIFO* fifo)
{
	free(fifo);
	fifo = NULL;
}

