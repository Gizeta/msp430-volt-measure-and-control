#ifndef TLC5615_H_
#define TLC5615_H_

#include "common.h"

#define TLC5615_PORT P2OUT
#define TLC5615_DIR  P2DIR
#define TLC5615_DIN  BIT3
#define TLC5615_SCLK BIT4
#define TLC5615_CS   BIT5

void TLC5615_Init(void);
void TLC5615_Convert(uint data);

#endif
