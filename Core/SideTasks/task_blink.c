#include "main.h"
#include "task_blink.h"
#include "scheduler.h"

static sched_task_t t = {
    .periodMS = 500,
    .cb       = blinkCB,
    .taskID   = TASK_BLINK        // ← give it a real ID
};

void blinkCB(void)
{
	HAL_GPIO_TogglePin(GPIOA, LED_1_Pin);
}

void taskBlinkInit(void)
{
	schedulerAdd(&t);
}

void taskBlinkDeInit(void)
{
	schedulerRemove(TASK_BLINK);
}
