#pragma once

#include <stdint.h>

/*------------------------------ DEFINES ------------------------------*/
#define MAX_TASKS			8

typedef void (*task_cb_t)(void);

typedef enum {
	PLACEHOLDER,	//To not to mix up with empty tasks
	TASK_NONE,		//Deleted task
	TASK_BLINK,
	TASK_FLASH,
	TASK_TEMP,
	TASK_BUTTON
}sched_task_id_te;

typedef struct {
	uint32_t periodMS;
	uint32_t lastMS;
	task_cb_t cb;
	sched_task_id_te taskID;
}sched_task_t;


/*------------------------------ FUNCTIONS ------------------------------*/
/*
 * @brief will be called from super loop.
 * Schedules tasks
 *
 * */
void schedulerRun(void);

/*
 * @brief will be called once per task
 * @param to be added
 *
 * */
void schedulerAdd(sched_task_t *task);

/*
 * @brief Removes the specified task with the given task ID
 * @param taskID to be removed
 *
 * */
void schedulerRemove(sched_task_id_te taskID);


