#include "gpio.h"

/*------------------Déclaration des fonctions------------------*/

uint16_t GPIO_ReadPin(GPIO_typeDef* GPIO, uint16_t pin){
    if(GPIO->IDR & (1<<pin)) return 1;
    else return 0;
}

void GPIO_ResetPin(GPIO_typeDef* GPIO, uint16_t pin){
    GPIO->ODR &= ~(1<<pin);
}

void GPIO_SetPin(GPIO_typeDef* GPIO, uint16_t pin){
    GPIO->ODR |= (1<<pin);
}