#define __gpio_h__
#ifdef __gpio_h__

/*------------------Include des librairies------------------*/
#include <stdint.h>

/*------------------Définition des structures------------------*/


/*------------------Définition des fonctions------------------*/
/**
 * @brief 
 * 
 * @param GPIO 
 * @param pin 
 * @return uint16_t 
 */
uint16_t GPIO_ReadPin(GPIO_typeDef* GPIO, uint16_t pin);

/**
 * @brief 
 * 
 * @param GPIO 
 * @param pin 
 */
void GPIO_ResetPin(GPIO_typeDef* GPIO, uint16_t pin);

/**
 * @brief 
 * 
 * @param GPIO 
 * @param pin 
 */
void GPIO_SetPin(GPIO_typeDef* GPIO, uint16_t pin);

#endif