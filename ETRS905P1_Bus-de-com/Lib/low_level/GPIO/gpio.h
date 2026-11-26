#ifndef __gpio_h__
#define __gpio_h__

/*------------------Include des librairies------------------*/
#include "stm32f4xx.h"   /* Définit GPIO_TypeDef, GPIOA, ... */
#include <stdint.h>

/*------------------Définition des fonctions------------------*/
/* Remarque : "pin" est le NUMÉRO de la broche (0..15), pas le masque GPIO_PIN_x */

/**
 * @brief Lit l'état d'une broche
 * @param GPIO port (GPIOA, GPIOB, ...)
 * @param pin  numéro de broche (0..15)
 * @return 1 si niveau haut, 0 sinon
 */
uint16_t GPIO_ReadPin(GPIO_TypeDef* GPIO, uint16_t pin);

/**
 * @brief Met la broche au niveau bas
 */
void GPIO_ResetPin(GPIO_TypeDef* GPIO, uint16_t pin);

/**
 * @brief Met la broche au niveau haut (relâchée si open-drain)
 */
void GPIO_SetPin(GPIO_TypeDef* GPIO, uint16_t pin);

#endif
