#include "ds18b20.h"

/*------------------Déclaration des fonctions------------------*/

float DS18B20_GetTemperature(ONEWIRE_PINOUT* oneWire_Pinout) {
    /* 1) Lancement de la conversion */
    if(!ONEWIRE_Reset(oneWire_Pinout)) return DS18B20_ERROR_TEMP;
    ONEWIRE_WriteByte(oneWire_Pinout, DS18B20_CMD_SKIP_ROM);
    ONEWIRE_WriteByte(oneWire_Pinout, DS18B20_CMD_CONVERT_T);
    delay_ms(750);                      /* temps de conversion max en 12 bits */

    /* 2) Lecture du scratchpad */
    if(!ONEWIRE_Reset(oneWire_Pinout)) return DS18B20_ERROR_TEMP;
    ONEWIRE_WriteByte(oneWire_Pinout, DS18B20_CMD_SKIP_ROM);
    ONEWIRE_WriteByte(oneWire_Pinout, DS18B20_CMD_READ_SCRATCHPAD);

    uint8_t l_ui8_lsb = ONEWIRE_ReadByte(oneWire_Pinout);   /* octet 0 : LSB */
    uint8_t l_ui8_msb = ONEWIRE_ReadByte(oneWire_Pinout);   /* octet 1 : MSB */
    ONEWIRE_Reset(oneWire_Pinout);      /* on arrête la lecture du scratchpad */

    /* Valeur signée en complément à 2, résolution 1/16 °C */
    int16_t l_i16_raw = (int16_t)(((uint16_t)l_ui8_msb << 8) | l_ui8_lsb);
    return (float)l_i16_raw * 0.0625f;
}
