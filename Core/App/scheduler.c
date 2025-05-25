#include "stm32f4xx.h"
#include "scheduler.h"

static sched_task_t *tasks[MAX_TASKS] = {0}; //initializes all to NULL

//Adds a task to scheduler
void schedulerAdd(sched_task_t *task)
{
	for(uint8_t i = 0; i < MAX_TASKS; ++i){
		if(tasks[i] && tasks[i]->taskID == task->taskID)
			return;	//if exists, do nothing
	}

	for(uint8_t i = 0; i < MAX_TASKS; ++i){
		if(tasks[i] == NULL){ //free slot
			tasks[i] = task;
			task->lastMS = HAL_GetTick();
			return;
		}
	}
}

//Remove a task by ID
void schedulerRemove(sched_task_id_te taskID)
{
	for(uint8_t i = 0; i < MAX_TASKS; ++i){
		if(tasks[i] && tasks[i]->taskID == taskID){
			tasks[i] = NULL;		//Delete/Remove task
			return;
		}
	}
}

//Run created and ready tasks
void schedulerRun(void)
{
	uint32_t now = HAL_GetTick();

	for(uint8_t i = 0; i < MAX_TASKS; ++i){
		if(tasks[i] && (now - tasks[i]->lastMS) >= tasks[i]->periodMS){
			tasks[i]->lastMS = now;
			tasks[i]->cb();
		}
	}
}
