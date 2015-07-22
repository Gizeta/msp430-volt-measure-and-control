#include <msp430.h>
#include "adc10.h"

void ADC10_Init(void)
{
	ADC10CTL0 = ADC10SHT_2 + MSC + ADC10ON + ADC10IE;
	ADC10CTL1 = ADC_INCH + CONSEQ_2;
	ADC10AE0  |= ADC_IN;
	ADC_CHSEL |= ADC_IN;
}

void ADC10_Enable(void)
{
	ADC10CTL0 |= ENC + ADC10SC;
}

void ADC10_Disable(void)
{
	ADC10CTL0 &= ~ENC;
}
