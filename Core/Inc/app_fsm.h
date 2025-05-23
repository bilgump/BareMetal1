#pragma once


/*------------------------------ FUNCTIONS ------------------------------*/
/*
 * @brief ISR hooks this on PE3 rising
 *
 * */
void fsmEventButton(void);

/*
 * @brief Called from super loop
 *
 * */
void fsmRun(void);
