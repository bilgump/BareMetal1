#pragma once

/*
 * @brief Initializes and adds to scheduler
 *
 */
void taskBlinkInit(void);

/*
 * @brief Removes the blink task from scheduler
 *
 */
void taskBlinkDeInit(void);

/*
 * @brief ISR triggers TIM2 callback, hence this one
 *
 */
void blinkCB(void);

