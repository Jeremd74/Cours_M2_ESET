#include "gpio.h"

/*------------------Déclaration des fonctions------------------*/

uint16_t GPIO_ReadPin(GPIO_TypeDef* GPIO, uint16_t pin){
    if(GPIO->IDR & (1U << pin)) return 1;
    else return 0;
}

void GPIO_ResetPin(GPIO_TypeDef* GPIO, uint16_t pin){
    GPIO->BSRR = (1U << (pin + 16));   /* écriture atomique : bit de reset */
}

void GPIO_SetPin(GPIO_TypeDef* GPIO, uint16_t pin){
    GPIO->BSRR = (1U << pin);          /* écriture atomique : bit de set */
}
