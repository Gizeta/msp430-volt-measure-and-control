#include <msp430.h>
#include "pwm.h"

void PWM_Init(void)
{
	PWM_DIR |= PWM_OUT;
	PWM_SEL |= PWM_OUT;
	TA1CCR0  = 10000;
	TA1CCTL1 = OUTMOD_3;
	TA1CCR1 = 5000;
}

void PWM_Enable(void)
{
	TA1CTL = TASSEL_2 + ID_0 + MC_1;
}

void PWM_Disable(void)
{
	TA1CTL = TASSEL_2 + ID_0 + MC_0;
}
