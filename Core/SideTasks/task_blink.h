#pragma once

/*
 * @brief Initializes and adds to scheduler
 *
 */
void taskBlinkInit(void);

/*
 * @brief ISR triggers TIM2 callback, hence this one
 *
 */
void blinkCB(void);

