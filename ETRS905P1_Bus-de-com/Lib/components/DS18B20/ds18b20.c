#include "ds18b20.h"

/*------------------Déclaration des fonctions------------------*/

float DS18B20_GetTemperature(ONEWIRE_PINOUT* oneWire_Pinout) {
    ONEWIRE_Reset(oneWire_Pinout);
    ONEWIRE_WriteByte(oneWire_Pinout, 0xCC);
    ONEWIRE_WriteByte(oneWire_Pinout, 0x44);
    delay_ms(10);
    ONEWIRE_Reset(oneWire_Pinout);
    ONEWIRE_WriteByte(oneWire_Pinout, 0xCC);
    ONEWIRE_WriteByte(oneWire_Pinout, 0xBE);

    uint16_t l_ui16_result = ONEWIRE_ReadByte(oneWire_Pinout);
    l_ui16_result = l_ui16_result << 8;
    l_ui16_result = ONEWIRE_ReadByte(oneWire_Pinout);
    return l_ui16_result;
}