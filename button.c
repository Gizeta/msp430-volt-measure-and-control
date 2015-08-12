#include <msp430.h>
#include "button.h"

void Button_Init(void)
{
	BUTTON_DIR  &= ~(BUTTON_1 + BUTTON_2);
	BUTTON_PORT |= BUTTON_1 + BUTTON_2;
	BUTTON_REN  |= BUTTON_1 + BUTTON_2;
	BUTTON_IES  |= BUTTON_1 + BUTTON_2;
	BUTTON_IE   |= BUTTON_1 + BUTTON_2;
	P2IFG       &= ~(BUTTON_1 + BUTTON_2);
}

#pragma vector=PORT2_VECTOR
__interrupt void Port2_ISR(void)
{
	if ((P2IFG & BUTTON_1) != 0)
	{
		DA_Output += 0.05;
		if (DA_Output > 2)
		{
			DA_Output = 2;
		}
	}
	if ((P2IFG & BUTTON_2) != 0)
	{
		DA_Output -= 0.05;
		if (DA_Output < 0)
		{
			DA_Output = 0;
		}
	}
	P2IFG = 0;
}
