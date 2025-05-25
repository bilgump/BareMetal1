#pragma once
#include <stdbool.h>

typedef enum{
	IDLE,			//first sample, level == 1 	-> next state -> MAYBE_PRESSED
	MAYBE_PRESSED,  //2nd sample, 	level == 1 	-> next state -> PRESSED. else, next state -> IDLE
	PRESSED,		//first sample, level == 0 	-> next state -> MAYBE_RELEASED
	MAYBE_RELEASED	//2nd sample, 	level == 0 	-> next state -> IDLE
}bstate_te;

void  taskButtonInit(void);       // call once
void  buttonPoll(void);           // call every 10 ms
bool  buttonPressed(void);        // one-shot flag
bool  buttonReleased(void);       // one-shot flag
