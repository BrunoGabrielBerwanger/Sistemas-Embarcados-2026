/*
 * max30100.h
 *
 *  Created on: Apr 20, 2026
 *      Author: bruno.berwanger
 */

#ifndef INC_MAX30100_H_
#define INC_MAX30100_H_

#include "i2c.h"
#include "gpio.h"
#include <stdio.h>
#include <stdint.h>


#define MAX30100_I2C_ADDR (0x57 << 1) // HAL usa endereço deslocado

#define REG_INTR_STATUS     0x00
#define REG_INTR_ENABLE     0x01
#define REG_FIFO_WR_PTR     0x02
#define REG_FIFO_RD_PTR     0x04
#define REG_FIFO_DATA       0x05
#define REG_MODE_CONFIG     0x06
#define REG_SPO2_CONFIG     0x07
#define REG_LED_CONFIG      0x09

#define BUFFER_SIZE 8

typedef struct {
    uint16_t ir;
    uint16_t red;
} max30100_data_t;

HAL_StatusTypeDef MAX30100_ReadFIFO(max30100_data_t *data);
void MAX30100_Init(void);

#endif /* INC_MAX30100_H_ */
