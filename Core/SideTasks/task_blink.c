#include "main.h"
#include "task_blink.h"
#include "scheduler.h"

void blinkCB(void)
{
	HAL_GPIO_TogglePin(GPIOA, LED_1_Pin);
}

void taskBlinkInit(void)
{
	static sched_task_t t = {.periodMS = 500, .cb = blinkCB};
	schedulerAdd(&t);
}
