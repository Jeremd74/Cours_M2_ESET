#include "onewire.h"

/* Convention (sortie open-drain + pull-up) :
 *   GPIO_ResetPin -> le maître tire la ligne à 0
 *   GPIO_SetPin   -> le maître relâche la ligne (la pull-up la remonte à 1) */

/*------------------Déclaration des fonctions------------------*/

uint8_t ONEWIRE_Reset(ONEWIRE_PINOUT* oneWire_Pinout) {
  uint8_t l_ui8_presence;

  GPIO_ResetPin(oneWire_Pinout->port, oneWire_Pinout->pin);  /* reset : 0 pendant 480 µs */
  delay_us(480);
  GPIO_SetPin(oneWire_Pinout->port, oneWire_Pinout->pin);    /* relâche */
  delay_us(70);

  /* L'esclave signale sa présence en tirant la ligne à 0 */
  l_ui8_presence = GPIO_ReadPin(oneWire_Pinout->port, oneWire_Pinout->pin) ? 0 : 1;
  delay_us(410);
  return l_ui8_presence;
}

void ONEWIRE_Write0(ONEWIRE_PINOUT* oneWire_Pinout) {
  GPIO_ResetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_us(60);
  GPIO_SetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_us(10);
}

void ONEWIRE_Write1(ONEWIRE_PINOUT* oneWire_Pinout) {
  GPIO_ResetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_us(6);
  GPIO_SetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_us(64);
}

uint8_t ONEWIRE_ReadBit(ONEWIRE_PINOUT* oneWire_Pinout) {
  uint8_t l_ui8_valRet;

  GPIO_ResetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_us(6);
  GPIO_SetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_us(9);

  l_ui8_valRet = (uint8_t)GPIO_ReadPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_us(55);
  return l_ui8_valRet;
}

void ONEWIRE_WriteByte(ONEWIRE_PINOUT* oneWire_Pinout, uint8_t data) {
  for(uint8_t i = 0; i < 8; i++){
    if(data & (1U << i)) ONEWIRE_Write1(oneWire_Pinout);
    else ONEWIRE_Write0(oneWire_Pinout);
  }
}

uint8_t ONEWIRE_ReadByte(ONEWIRE_PINOUT* oneWire_Pinout) {
  uint8_t l_ui8_valRet = 0;
  for(uint8_t i = 0; i < 8; i++){
    if(ONEWIRE_ReadBit(oneWire_Pinout)) l_ui8_valRet |= (1U << i);
  }
  return l_ui8_valRet;
}
