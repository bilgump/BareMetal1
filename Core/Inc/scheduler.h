#pragma once

#include <stdint.h>

/*------------------------------ DEFINES ------------------------------*/
#define MAX_TASKS			8

typedef void (*task_cb_t)(void);

typedef struct {
	uint32_t periodMS;
	uint32_t lastMS;
	task_cb_t cb;
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
 *
 * */
void schedulerAdd(sched_task_t *task);


