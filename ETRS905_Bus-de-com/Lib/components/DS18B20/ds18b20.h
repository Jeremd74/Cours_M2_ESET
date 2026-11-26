#ifndef __ds18b20_h__
#define __ds18b20_h__

/*------------------Include des librairies------------------*/
#include "onewire.h"   /* fournit ONEWIRE_PINOUT */
#include <stdint.h>

/*------------------Définitions------------------*/
#define DS18B20_CMD_SKIP_ROM        0xCC
#define DS18B20_CMD_CONVERT_T       0x44
#define DS18B20_CMD_READ_SCRATCHPAD 0xBE

/* Valeur renvoyée si la sonde ne répond pas */
#define DS18B20_ERROR_TEMP          (-1000.0f)

/*------------------Définition des fonctions------------------*/

/**
 * @brief Lance une conversion (12 bits, ~750 ms) et lit la température.
 *        Une seule sonde sur le bus (commande SKIP ROM).
 * @param oneWire_Pinout broche du bus 1-Wire
 * @return température en °C, ou DS18B20_ERROR_TEMP si pas de présence
 */
float DS18B20_GetTemperature(ONEWIRE_PINOUT* oneWire_Pinout);

#endif
