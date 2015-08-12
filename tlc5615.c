#include <msp430.h>
#include "common.h"
#include "tlc5615.h"

float DA_Output = 0.5;

void TLC5615_Init(void)
{
	TLC5615_DIR |= TLC5615_DIN + TLC5615_SCLK + TLC5615_CS;
}

void TLC5615_Convert(uint data)
{
	uchar i;
	data <<= 6;
	TLC5615_PORT &= ~TLC5615_CS;
	TLC5615_PORT &= ~TLC5615_SCLK;

	for(i = 0; i < 12; i++)
	{
		if ((data & 0x8000) == 0)
		{
			TLC5615_PORT &= ~TLC5615_DIN;
		}
		else
		{
			TLC5615_PORT |= TLC5615_DIN;
		}
		TLC5615_PORT |= TLC5615_SCLK;
		data <<= 1;
		TLC5615_PORT &= ~TLC5615_SCLK;
	}

	TLC5615_PORT |= TLC5615_CS;
}
