#include "MAX30100.h"
#include "i2c.h"
#include "gpio.h"
#include <stdio.h>
#include "usart.h"

#define MAX30100_ADDR (0x57 << 1)


uint8_t data[2];

int _write(int file, char *ptr, int len){
    HAL_UART_Transmit(&huart4, (uint8_t*)ptr, len, HAL_MAX_DELAY);
    return len;
}


// ===== Escrita em registrador =====
void MAX30100_Write(uint8_t reg, uint8_t value)
{
    uint8_t data[2] = {reg, value};
    HAL_I2C_Master_Transmit(&hi2c1, MAX30100_ADDR, data, 2, HAL_MAX_DELAY);
}

// ===== Leitura de registrador =====
uint8_t MAX30100_Read(uint8_t reg)
{
    uint8_t value;
    HAL_I2C_Master_Transmit(&hi2c1, MAX30100_ADDR, &reg, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(&hi2c1, MAX30100_ADDR, &value, 1, HAL_MAX_DELAY);
    return value;
}

void MAX30100_Reset(void) {
    // Reset
    MAX30100_Write(0x06, 0x40);
    HAL_Delay(100);
}
void MAX30100_CleanFIFO(void) {
    // Limpar FIFO
    MAX30100_Write(0x02, 0x00);
    MAX30100_Write(0x03, 0x00);
    MAX30100_Write(0x04, 0x00);
}

/*
Bit	Nome	        Função
7	A_FULL_EN	    FIFO quase cheio
6	TEMP_RDY_EN	    Temperatura pronta
5	HR_RDY_EN	    Dados de batimento prontos
4	SPO2_RDY_EN	    Dados de SpO2 prontos
3	—	            não usado
2	—	            não usado
1	—	            não usado
0	—	            não usado
*/

void MAX30100_INTERRUPT_ENABLE(void) {
    data[0] = 0x01; // INT_ENABLE
    data[1] = 0x20; // habilita interrupções úteis
    HAL_I2C_Master_Transmit(&hi2c1, 0x57 , data, 2, HAL_MAX_DELAY);
}
void MAX30100_SPO2CFG(void) {
    MAX30100_Write(0x07, 0x47);
}
void MAX30100_SPO2MODECFG(void) {
    MAX30100_Write(0x09, 0x03);
}

void MAX30100_LEDCURRENT(void) {
    // IR = ~27mA | RED = ~7mA
    MAX30100_Write(0x09, 0x24);
}


void MAX30100_Init(void) { 
    MAX30100_Reset();
    MAX30100_CleanFIFO();
    MAX30100_SPO2CFG();
    MAX30100_SPO2MODECFG();
    MAX30100_LEDCURRENT();
}


void MAX30100_ReadFIFO(uint16_t *ir, uint16_t *red)
{
    uint8_t reg = 0x05;
    uint8_t buffer[4];

    HAL_I2C_Master_Transmit(&hi2c1, MAX30100_ADDR, &reg, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(&hi2c1, 0xAF, buffer, 4, HAL_MAX_DELAY);

    *ir  = (buffer[0] << 8) | buffer[1];
    *red = (buffer[2] << 8) | buffer[3];
}