#ifndef __MAX30100_H__
#define __MAX30100_H__


#include "stdint.h"

void MAX30100_Reset(void);
void MAX30100_CleanFIFO(void);
void MAX30100_INTERRUPT_ENABLE(void);
void MAX30100_SPO2CFG(void);
void MAX30100_SPO2MODECFG(void);
void MAX30100_LEDCURRENT(void);
void MAX30100_Init(void);
void MAX30100_ReadFIFO(uint16_t* ir, uint16_t* red);

#endif /* __MAX30100_H__ */