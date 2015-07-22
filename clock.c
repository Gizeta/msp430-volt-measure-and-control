#include <msp430.h>

#include "clock.h"

void Clock1MHZ_Init(void)
{
	if (CALBC1_1MHZ == 0xFF || CALDCO_1MHZ == 0xFF)
		while(1);

	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL  = CALDCO_1MHZ;
	BCSCTL2 = SELM_0 + DIVM_0;
}
