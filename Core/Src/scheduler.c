#include "stm32f4xx.h"
#include "scheduler.h"

static sched_task_t *tasks[MAX_TASKS];
static uint8_t count = 0;

void schedulerAdd(sched_task_t *task)
{
	if(count < MAX_TASKS)
		tasks[count++] = task;
}

void schedulerRun(void)
{
	uint32_t now = HAL_GetTick();

	for(uint8_t i = 0; i < count; ++i){
		if((now - tasks[i]->lastMS) >= tasks[i]->periodMS){
			tasks[i]->lastMS = now;
			tasks[i]->cb();
		}
	}
}
