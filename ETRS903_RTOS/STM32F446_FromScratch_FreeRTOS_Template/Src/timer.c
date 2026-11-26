#include <stdint.h>
#include "stm32f446xx.h"
#include "timer.h"


uint32_t SystemCoreClock = 16000000;
uint32_t ticks = 0;

void TIM2TICK_Init(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 |= TIM_CR1_CEN;
	TIM2->ARR = 999;
	TIM2->PSC = 15;
	TIM2->CNT = 0;
	TIM2->DIER 	|= TIM_DIER_UIE;
	TIM2->SR	&= ~TIM_SR_UIF;
	NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2TICK_Delay(uint32_t Delay)
{
	  uint32_t tickstart = TIM2TICK_Get();

	  while((TIM2TICK_Get() - tickstart) < Delay);
}

uint32_t TIM2TICK_Get(void){
	return ticks;
}


