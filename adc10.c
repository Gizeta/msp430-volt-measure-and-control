#include <msp430.h>
#include "adc10.h"
#include "common.h"

uint ADC_Value[6] = {0, 0, 0, 0, 0, 0};

void ADC10_Init(void)
{
	ADC10CTL0 = ADC10SHT_2 + MSC + ADC10ON + ADC10IE;
	ADC10CTL1 = ADC_INCH + CONSEQ_1;
	ADC10AE0 |= ADC_IN;
	ADC_CHSEL|= ADC_IN;
	ADC10DTC0 = ADC10CT;
	ADC10DTC1 = 6;
	ADC10SA   = (int)ADC_Value;
}

void ADC10_Enable(void)
{
	ADC10CTL0 |= ENC + ADC10SC;
}

void ADC10_Disable(void)
{
	ADC10CTL0 &= ~ENC;
}
