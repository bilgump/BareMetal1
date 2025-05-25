#include "buttonFSM.h"
#include "scheduler.h"
#include "main.h"
#include "task_blink.h"

//STATIC VARIABLES
static bstate_te state = IDLE;
static bool evPress, evRelease;
static uint32_t tPress;				//Tick when button wents down
static bool blinkOn = false;

//FORWARD DECLARATIONS
static void buttonLogic(bstate_te btnState);

/*------------------------------- STATIC FUNCTIONS ------------------------------------ */
static void buttonLogic(bstate_te btnState)
{
	if(buttonPressed())	//Rising edge - short/long press detection decision making
		tPress = HAL_GetTick();

	//Falling edge - Evaluate Duration
	if(buttonReleased()){
		uint32_t dt = HAL_GetTick() - tPress;

		if(dt < 2000){ // press < 2s - short press
			blinkOn = !blinkOn;
			if(blinkOn)
				taskBlinkInit();
			else
				taskBlinkDeInit();
		}
		else { // press > 2s
			//enterBatteryLogging(); //Standby routine
		}
	}
}


/*------------------------------- PUBLIC FUNCTIONS ------------------------------------ */
void taskButtonInit(void)
{
	static sched_task_t t = {.periodMS = 10, .cb = buttonPoll, .taskID = TASK_BUTTON};
	schedulerAdd(&t);
}

void buttonPoll(void)
{
    bool level = HAL_GPIO_ReadPin(Button_K0_GPIO_Port, Button_K0_Pin);
    evPress = evRelease = false;

    switch(state)
    {
        case IDLE:
            if(level){
                state = MAYBE_PRESSED;
                buttonLogic(state);
            }
            break;

        case MAYBE_PRESSED:
            state = level ? PRESSED : IDLE;
            if(state == PRESSED)
            	evPress = true;
            buttonLogic(state);
            break;

        case PRESSED:
            if(!level){
                state = MAYBE_RELEASED;
                buttonLogic(state);
            }
            break;

        case MAYBE_RELEASED:
            state = level ? PRESSED : IDLE;
            if(state == IDLE)
            	evRelease = true;
            buttonLogic(state);
            break;
    }
}


bool buttonPressed(void)
{
	bool f = evPress;
	evPress = false;
	return f;
}

bool buttonReleased(void)
{
	bool f = evRelease;
	evRelease = false;
	return f;
}





