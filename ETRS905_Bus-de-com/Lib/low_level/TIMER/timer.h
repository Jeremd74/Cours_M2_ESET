#ifndef __timer_h__
#define __timer_h__

/*------------------Include des librairies------------------*/
#include "stm32f4xx.h"
#include <stdint.h>

/*------------------Configuration------------------*/
/* Fréquence d'horloge de TIM2 en MHz (APB1 Timer clock).
 * Nucleo-F446RE configurée par CubeMX : SYSCLK 84 MHz, APB1 /2 -> TIM2 = 84 MHz */
#define TIMER_CLK_MHZ 84U

/*------------------Définition des fonctions------------------*/
/**
 * @brief Configure TIM2 en compteur libre 32 bits à 1 MHz (1 tick = 1 µs).
 *        À appeler une fois au démarrage.
 */
void TIMER_Init(void);

/**
 * @brief Attente active en microsecondes
 */
void delay_us(uint32_t Time_us);

/**
 * @brief Attente active en millisecondes
 */
void delay_ms(uint32_t Time_ms);

#endif
