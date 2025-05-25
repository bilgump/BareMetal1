/*
 * flash_task.c
 *
 *  Created on: May 25, 2025
 *      Author: Bilgehan
 */

#include "flash_w25q16.h"
#include "scheduler.h"

static uint8_t buf[16] = {0};

static void flashCB(void)
{
	static bool once = false;
	uint8_t counter = 0;
	if(!once){
		uint8_t msg[] = "HelloFlash!";
		if(W25Q16_Erase4K(0))
			counter++;
		if(W25Q16_PageProgram(0, msg, sizeof msg))
			counter++;
		if(counter == 2)
			once = true;
	}
	W25Q16_Read(0, buf, sizeof buf);
}

void task_flash_init(void)
{
	static sched_task_t t = {.periodMS = 2000, .cb = flashCB, .taskID = TASK_FLASH};
	schedulerAdd(&t);
}
