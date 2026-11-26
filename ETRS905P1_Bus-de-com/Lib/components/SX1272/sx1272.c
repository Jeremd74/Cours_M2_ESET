#include "sx1272.h"

/*------------------Déclaration des fonctions------------------*/

void SX1272_WriteReg(uint8_t regAddr, uint8_t regData) {
    SPI1_ResetSS();
    SPI1_transmitReceive(regAddr | 0x80);
    SPI1_transmitReceive(regData);
    SPI1_SetSS();
}

uint8_t SX1272_ReadReg(uint8_t regAddr) {
    SPI1_ResetSS();
    SPI1_transmitReceive(regAddr);
    uint8_t l_ui8_retData = SPI1_transmitReceive(regAddr);
    SPI1_SetSS();
    return l_ui8_retData;
}