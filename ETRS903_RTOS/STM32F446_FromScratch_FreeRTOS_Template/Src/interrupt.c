
#include <stdint.h>
#include "stm32f446xx.h"
#include "interrupt.h"

#include <stdint.h>
#include "interrupt.h"
#include "stm32f446xx.h"
//#include "FreeRTOS.h"

extern uint32_t ticks;

void TIM2_IRQHandler(void){
	ticks++;
	TIM2->SR &= ~TIM_SR_UIF;
}


//////////////// HOW TO SETUP INTERUPT ? ///////////
// 1. Activate the NVIC IT :  NVIC_EnableIRQ().
// 2. Define the Event that generate IT : GPIO Rising Edge, Timer Update, USART RX not empty...
// 3. Write the corresponding ISR (Interrupt Sub-Routine) code. Do not forget to reset IT Flag.

///////////////         EXTI             //////////
// When using EXTI, to define the Event that generate IT (2), we need :
// a. Enable SYSCFG peripheral clock.
// b. Select the right PORT connected to EXTIx : SYSCFR->EXTICR.
// c. Unmask IT on EXTIx : EXTI->IMR.
// d. Select Rising or falling trigger edge :  EXTI->RTSR or EXTI->FTSR.

