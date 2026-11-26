#include "timer.h"

/*------------------Déclaration des fonctions------------------*/

void delay_µs(uint32_t Time_µs){
  Tim2->psk = 15;
  Tim2->CNT = 0;
  while (Tim2->CNT <= Time_µs)
}