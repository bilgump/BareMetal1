#include "app_fsm.h"
#include "main.h"
#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim2;

typedef enum {
	ST_RUN,
	ST_STOP
}state_te;

static state_te st = ST_RUN;

static void enterStop(void)
{
	HAL_TIM_Base_Stop_IT(&htim2); 	//Pause LED timer
	HAL_SuspendTick();				//stop SysTick so it won't wake us

	//Enter STOP with main regulator ON, wake on any EXTI
	HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);

	//MCU Wakes here
	SystemClock_Config();	//Re-enable PLLS
	HAL_ResumeTick();
	HAL_TIM_Base_Start_IT(&htim2);
	//st = ST_RUN;
}

void fsmEventButton(void)
{
	st = (st == ST_RUN) ? ST_STOP : ST_RUN;
}

void fsmRun(void)
{
	if(st == ST_STOP){
		st = ST_RUN; //Sleep once per press
		enterStop();
	}
}










