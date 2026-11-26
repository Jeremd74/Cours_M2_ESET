#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "timer.h"
#include "util.h"


int main(void)
{
	FPU_Init();
	GPIO_Init();
	USART2_Init();
	SYSTICK_Init();
	TIM2_Init();

	while(1){
		TIM2_ms(100);
		//SYSTICK_Delay(100);
		GPIOA->ODR ^= 1<<5;
		printf("Hello\r\n");
	}
}
