#define __onewire_h__
#ifdef __onewire_h__

/*------------------Include des librairies------------------*/
#include "gpio.h"
#include "timer.h"
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
 * @return uint8_t 
 */
uint8_t ONEWIRE_Reset(ONEWIRE_PINOUT* oneWire_Pinout);

/**
 * @brief 
 * 
 * @param oneWire_Pinout 
 */
void ONEWIRE_Write0(ONEWIRE_PINOUT* oneWire_Pinout);

/**
 * @brief 
 * 
 * @param oneWire_Pinout 
 */
void ONEWIRE_Write1(ONEWIRE_PINOUT* oneWire_Pinout);

/**
 * @brief 
 * 
 * @param oneWire_Pinout 
 * @return uint8_t 
 */
uint8_t ONEWIRE_ReadBit(ONEWIRE_PINOUT* oneWire_Pinout);

/**
 * @brief 
 * 
 * @param oneWire_Pinout 
 * @param data 
 */
void ONEWIRE_WriteByte(ONEWIRE_PINOUT* oneWire_Pinout, uint8_t data);

/**
 * @brief 
 * 
 */
uint8_t ONEWIRE_ReadByte(ONEWIRE_PINOUT* oneWire_Pinout);

#endif