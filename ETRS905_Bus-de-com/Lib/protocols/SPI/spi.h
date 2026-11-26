#define __spi_h__
#ifdef __spi_h__

/*------------------Include des librairies------------------*/
#include "gpio.h"
#include "timer.h"
#include <stdint.h>

/*------------------Définition des structures------------------*/


/*------------------Définition des fonctions------------------*/

/**
 * @brief 
 * 
 * @param spiData 
 * @return uint8_t 
 */
uint8_t SPI1_transmitReceive(uint8_t spiData);

/**
 * @brief 
 * 
 */
void SPI1_ResetSS(void);

/**
 * @brief 
 * 
 */
void SPI1_SetSS(void);

#endif