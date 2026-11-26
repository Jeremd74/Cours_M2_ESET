#ifndef __onewire_h__
#define __onewire_h__

/*------------------Include des librairies------------------*/
#include "gpio.h"
#include "timer.h"
#include <stdint.h>

/*------------------Définition des structures------------------*/
/* La broche doit être configurée en sortie OPEN-DRAIN avec une
 * résistance de pull-up de 4,7 kOhm vers 3,3 V. */
typedef struct{
  GPIO_TypeDef* port;   /* GPIOA, GPIOB, ... */
  uint16_t      pin;    /* numéro de broche 0..15 */
} ONEWIRE_PINOUT;

/*------------------Définition des fonctions------------------*/

/**
 * @brief Impulsion de reset + détection de présence
 * @return 1 si un esclave a répondu (présence), 0 sinon
 */
uint8_t ONEWIRE_Reset(ONEWIRE_PINOUT* oneWire_Pinout);

/**
 * @brief Écrit un bit à 0
 */
void ONEWIRE_Write0(ONEWIRE_PINOUT* oneWire_Pinout);

/**
 * @brief Écrit un bit à 1
 */
void ONEWIRE_Write1(ONEWIRE_PINOUT* oneWire_Pinout);

/**
 * @brief Lit un bit
 * @return valeur du bit (0 ou 1)
 */
uint8_t ONEWIRE_ReadBit(ONEWIRE_PINOUT* oneWire_Pinout);

/**
 * @brief Écrit un octet, LSB en premier
 */
void ONEWIRE_WriteByte(ONEWIRE_PINOUT* oneWire_Pinout, uint8_t data);

/**
 * @brief Lit un octet, LSB en premier
 */
uint8_t ONEWIRE_ReadByte(ONEWIRE_PINOUT* oneWire_Pinout);

#endif
