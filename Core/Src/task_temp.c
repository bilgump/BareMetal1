#include "task_temp.h"
#include "scheduler.h"

extern uint16_t adcBuf[64];
volatile float temperature = 0;

/* ---------- normal scheduler task: safe to printf ----------------------*/
static void tempPrintTask(void)
{
    printf("T = %.1f °C\r\n", temperature);
}

void tempCB(void)
{
	uint32_t sum = 0;
	for(uint8_t i = 0; i < sizeof(adcBuf) / 2; ++i)
		sum += adcBuf[i];
	uint16_t avg = sum / sizeof(adcBuf) / 2;

	/* Convert to °C  (datasheet formula) */
	float V25 = 0.76f;          // V at 25 °C
	float AvgSlope = 0.0025f;   // V/°C
	float Vsense = (avg * 3.3f) / 4095.0f;
	float vTemp  = ((V25 - Vsense) / AvgSlope) + 25.0f;
	//printf("Temperature = %1.f C\r\n", vTemp);
	/* Set a watch-expression on tempC in debugger */
}

void taskTempInit(void)
{
	static sched_task_t t = {.periodMS = 1000, .cb = tempCB};
	schedulerAdd(&t);
	static sched_task_t t2 = {.periodMS = 1000, .cb = tempPrintTask};
	schedulerAdd(&t2);
}
