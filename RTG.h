/*
 * RTG.h
 *
 *
 *
 */
#ifndef INC_RTG_H_
#define INC_RTG_H_
#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>

extern UART_HandleTypeDef huart3;	//Change to match your UART number

#define UART_1 &huart3				//Change to match your UART number

void rtg_main();

#endif /* INC_RTG_H_ */
