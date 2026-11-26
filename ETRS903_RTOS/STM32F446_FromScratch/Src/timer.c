#include <stdint.h>
#include "stm32f446xx.h"
#include "timer.h"

uint32_t SystemCoreClock = 16000000;
uint32_t ticks = 0;

//////////////////////////////////////////////
////////////// SYSTICK TIMER /////////////////
//////////////////////////////////////////////

void SYSTICK_Init(void){
	SysTick_Config(SystemCoreClock / 1000);
}

/**
 * Millisecond delays with Systick Timer, blocking function
 * @param delay : milliseconds to wait
 */
void SYSTICK_Delay(uint32_t Delay)
{
	uint32_t tickstart = SYSTICK_Get();

	while((SYSTICK_Get() - tickstart) < Delay);
}

uint32_t SYSTICK_Get(void){
	return ticks;
}

//////////////////////////////////////////////
////////////// DW TIMER //////////////////////
//////////////////////////////////////////////

void DWT_Init(void)
{
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	//    DWT->LAR = 0xC5ACCE55;  // For Cortex M7
	DWT->CYCCNT = 0;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

/**
 * Microsecond delays with DW Timer, blocking function
 * @param _us : microseconds to wait
 */
void DWT_Delay(uint32_t _us)
{
	uint32_t startTick  = DWT->CYCCNT;
	uint32_t targetTick = DWT->CYCCNT + _us * (SystemCoreClock/1000000);

	// No overflow
	if (targetTick > startTick)
		while (DWT->CYCCNT < targetTick);

	// With overflow
	else
		while (DWT->CYCCNT > startTick || DWT->CYCCNT < targetTick);

}

//////////////////////////////////////////////
////////////// Timer 2  //////////////////////
//////////////////////////////////////////////

volatile uint32_t g_ms_ticks = 0;

void TIM2_Init(void){
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    TIM2->CR1  = 0;       /* Arrête TIM2 pendant la configuration */
    TIM2->DIER = 0;
    TIM2->PSC  = 1599U;//84U * 1000U - 1U;   /* 84 MHz / (8399 + 1) = 10 kHz */
    TIM2->ARR  = 9U;      /* 10 kHz / (9 + 1) = 1 kHz, donc 1 ms */
    TIM2->CNT  = 0;

    TIM2->EGR = TIM_EGR_UG; /* Applique PSC et ARR */
    TIM2->SR  = 0;          /* Efface les indicateurs en attente */

    NVIC_SetPriority(TIM2_IRQn, 2);
    NVIC_EnableIRQ(TIM2_IRQn);

    TIM2->DIER |= TIM_DIER_UIE; /* Interruption à chaque mise à jour */
    TIM2->CR1  |= TIM_CR1_CEN;  /* Démarre TIM2 */
}

void TIM2_ms(uint32_t Time_ms){
    uint32_t start = g_ms_ticks;

    while ((uint32_t)(g_ms_ticks - start) < Time_ms);
}

uint32_t TIM2_Get(void){
	return g_ms_ticks;
}
// Get MCO HSE to PA8 (D7)
// the MCO1PRE[2:0] and MCO1[1:0]

