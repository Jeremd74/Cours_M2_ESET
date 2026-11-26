#define __ds18b20_h__
#ifdef __ds18b20_h__

/*------------------Include des librairies------------------*/
#include "onewire.h"
#include <stdint.h>

/*------------------Définition des structures------------------*/
typedef struct{
  GPIO_Typedef* port;
  uint16_t      pin;
} ONEWIRE_PINOUT;

/*------------------Définition des fonctions------------------*/

/**
 * @brief 
 * 
 * @param oneWire_Pinout 
 * @return float 
 */
float DS18B20_GetTemperature(ONEWIRE_PINOUT* oneWire_Pinout);

#endif