#include "spi.h"

/*------------------Déclaration des fonctions------------------*/

uint8_t SPI1_transmitReceive(uint8_t spiData) {
    SPI1->DR = spiData;
    while((SPI1->SR) & SPI_SR_TXE == 0);
    while((SPI1->SR) & SPI_SR_RXNE == 0);
    return SPI1->SR;
}

void SPI1_ResetSS(void) {
    GPIO_ResetPin(GPIOB, 6);
}

void SPI1_SetSS(void) {
    GPIO_SetPin(GPIOB, 6);
}