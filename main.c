#include <msp430.h>
#include "adc10.h"
#include "button.h"
#include "clock.h"
#include "common.h"
#include "lcd1602.h"
#include "tlc5615.h"
#include "util.h"

extern float DA_Output;
extern uint ADC_Value[];

void main(void) {
	uchar display[6];

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    Clock1MHZ_Init();
    ADC10_Init();
    LCD1602_Init();
    TLC5615_Init();
    Button_Init();

    __enable_interrupt();

    ADC10_Enable();

    while(1)
    {
    	TLC5615_Convert((uint)(DA_Output * 512 / 3.555f));
    	__delay_cycles(50000);
    	NumberToString(display, ADC_Convert(ADC_Value[0]));
    	LCD1602_Show(0, 0, display);
    	__delay_cycles(50000);
    }
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
	ADC10_Enable();
}

