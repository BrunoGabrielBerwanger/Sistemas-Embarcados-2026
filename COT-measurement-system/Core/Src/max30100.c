/*
 * max30100.c
 *
 *  Created on: Apr 20, 2026
 *      Author: bruno.berwanger
 */

#include "max30100.h"



HAL_StatusTypeDef MAX30100_WriteReg(uint8_t reg, uint8_t value)
{
    uint8_t data[2] = {reg, value};
    return HAL_I2C_Master_Transmit(&hi2c1, MAX30100_I2C_ADDR, data, 2, HAL_MAX_DELAY);
}

HAL_StatusTypeDef MAX30100_ReadReg(uint8_t reg, uint8_t *value)
{
    return HAL_I2C_Mem_Read(&hi2c1, MAX30100_I2C_ADDR, reg, 1, value, 1, HAL_MAX_DELAY);
}

HAL_StatusTypeDef MAX30100_ReadMulti(uint8_t reg, uint8_t *buffer, uint8_t len)
{
    return HAL_I2C_Mem_Read(&hi2c1, MAX30100_I2C_ADDR, reg, 1, buffer, len, HAL_MAX_DELAY);
}

void MAX30100_Init(void)
{
    // Reset
	MAX30100_WriteReg(REG_FIFO_WR_PTR, 0x00);
	MAX30100_WriteReg(REG_FIFO_RD_PTR, 0x00);

    MAX30100_WriteReg(REG_MODE_CONFIG, 0x40);
    HAL_Delay(100);

    // Habilitar interrupções (opcional)
    MAX30100_WriteReg(REG_INTR_ENABLE, 0x10); // FIFO ready

    // Configuração SPO2
    // 0x47 = SPO2 mode, 100Hz, 1600us pulse width
    MAX30100_WriteReg(REG_SPO2_CONFIG, 0x47);

    // Configuração LEDs
    // IR = 50mA, RED = 27.1mA (ajuste conforme necessário)
    MAX30100_WriteReg(REG_LED_CONFIG, 0x3F);

    // Modo SPO2 (ativa leitura)
    MAX30100_WriteReg(REG_MODE_CONFIG, 0x03);
}


HAL_StatusTypeDef MAX30100_ReadFIFO(max30100_data_t *data)
{
    uint8_t buffer[4];

    if (HAL_I2C_Mem_Read(&hi2c1, MAX30100_I2C_ADDR, REG_FIFO_DATA, 1, buffer, 4, HAL_MAX_DELAY) != HAL_OK) {
        return HAL_ERROR;
    }

    data->ir  = (buffer[0] << 8) | buffer[1];
    data->red = (buffer[2] << 8) | buffer[3];

    return HAL_OK;
}

