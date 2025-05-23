#pragma once

extern volatile float temperature;

/*
 * @brief Initializes and adds to scheduler
 *
 */
void taskTempInit(void);

/*
 * @brief Calculates and prints the internal temperature
 *
 */
void tempCB(void);
