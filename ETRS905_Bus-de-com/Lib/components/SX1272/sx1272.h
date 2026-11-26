#define __sx1272_h__
#ifdef __sx1272_h__

/*------------------Include des librairies------------------*/
#include "spi.h"
#include <stdint.h>

/*------------------Définition des structures------------------*/


/*------------------Définition des fonctions------------------*/

/**
 * @brief 
 * 
 * @param regAddr 
 * @param regData 
 */
void SX1272_WriteReg(uint8_t regAddr, uint8_t regData);

/**
 * @brief 
 * 
 * @param regAddr 
 * @return uint8_t 
 */
uint8_t SX1272_ReadReg(uint8_t regAddr);
#endif