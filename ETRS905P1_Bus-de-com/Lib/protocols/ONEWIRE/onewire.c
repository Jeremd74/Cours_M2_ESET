#include "onewire.h"

/*------------------Déclaration des fonctions------------------*/

uint8_t ONEWIRE_Reset(ONEWIRE_PINOUT* oneWire_Pinout) {
  GPIO_SetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(480);
  GPIO_ResetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(70);

  if(GPIO_ReadPin(oneWire_Pinout->port, oneWire_Pinout->pin)){
    delay_µs(410);
    return 0;
  }
  else {
    delay_µs(410);
    return 1;
  }
}

void ONEWIRE_Write0(ONEWIRE_PINOUT* oneWire_Pinout) {
  GPIO_SetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(60);
  GPIO_ResetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(10);
}

void ONEWIRE_Write1(ONEWIRE_PINOUT* oneWire_Pinout) {
  GPIO_SetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(6);
  GPIO_ResetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(64);
}

uint8_t ONEWIRE_ReadBit(ONEWIRE_PINOUT* oneWire_Pinout) {
  GPIO_SetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(6);
  GPIO_ResetPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(9);

  uint8_t l_ui8_valRet = GPIO_ReadPin(oneWire_Pinout->port, oneWire_Pinout->pin);
  delay_µs(55);
  if(l_ui8_valRet) return 0;
  else return 1;
}

void ONEWIRE_WriteByte(ONEWIRE_PINOUT* oneWire_Pinout, uint8_t data) {
  for(uint8_t i = 0; i < 8; i++){
    if(data && (1<<i)) ONEWIRE_Write1(oneWire_Pinout);
    else ONEWIRE_Write0(oneWire_Pinout);
  }
}

uint8_t ONEWIRE_ReadByte(ONEWIRE_PINOUT* oneWire_Pinout) {
  uint8_t l_ui8_valRet = 0; 
  for(uint8_t i = 0; i < 8; i++){
    if(ONEWIRE_ReadBit(oneWire_Pinout)) l_ui8_valRet &= (1<<i);
  }
  return l_ui8_valRet;
}