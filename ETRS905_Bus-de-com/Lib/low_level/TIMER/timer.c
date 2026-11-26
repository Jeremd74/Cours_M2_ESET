#include "timer.h"

/*------------------Déclaration des fonctions------------------*/

void TIMER_Init(void){
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;   /* horloge de TIM2 */
  TIM2->CR1  = 0;                       /* timer arrêté */
  TIM2->PSC  = TIMER_CLK_MHZ - 1U;      /* 84 MHz / 84 = 1 MHz */
  TIM2->ARR  = 0xFFFFFFFFU;             /* compteur libre 32 bits */
  TIM2->EGR  = TIM_EGR_UG;              /* charge le prescaler immédiatement */
  TIM2->CNT  = 0;
  TIM2->CR1 |= TIM_CR1_CEN;             /* démarrage */
}

void delay_us(uint32_t Time_us){
  uint32_t start = TIM2->CNT;
  while ((TIM2->CNT - start) < Time_us);   /* gère le débordement du compteur */
}

void delay_ms(uint32_t Time_ms){
  while (Time_ms--) delay_us(1000);
}
