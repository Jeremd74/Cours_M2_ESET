#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "util.h"
#include "FreeRTOS.h"
#include "task.h"


#define PRIO_LOW	1
#define PRIO_MEDIUM	2
#define PRIO_HIGH	3


int main(void)
{
	GPIO_Init();
	USART2_Init();
	TIM2TICK_Init();
	vTraceEnable(TRC_START);	// Start Recording
	vTaskStartScheduler(); 		// Start FreeRTOS

	while(1){
	}
}
