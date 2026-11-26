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

static TaskHandle_t task1_Handle = NULL;
static TaskHandle_t task2_Handle = NULL;

static void task1_Handler(void *pvParameters)
{
	(void) pvParameters;

    for (;;)
    {
        GPIOA->ODR ^= (1U << 5);
        vTaskDelay(pdMS_TO_TICKS(1000));
		printf("Hello\r\n");
    }
}

static void task2_Handler(void *pvParameters)
{
	(void) pvParameters;

    for (;;)
    {
    		TIM2_ms(100);
		printf("TEST\r\n");
    }
}
int main(void)
{
	FPU_Init();
	GPIO_Init();
	USART2_Init();
	TIM2_Init();


	xTaskCreate(task1_Handler, "Task1", 256, NULL, 2, &task1_Handle);
	xTaskCreate(task2_Handler, "Task2", 256, NULL, 2, &task2_Handle);

	vTaskStartScheduler();

	while(1){
		/*
		TIM2_ms(1000);
		GPIOA->ODR ^= 1<<5;
		printf("Hello\r\n");*/
	}
}
