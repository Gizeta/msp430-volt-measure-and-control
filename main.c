#include <msp430.h>
#include "adc10.h"
#include "clock.h"
#include "lcd1602.h"
#include "util.h"

int main(void) {
	uchar display[6];

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    Clock1MHZ_Init();
    ADC10_Init();
    LCD1602_Init();
    P2DIR|=BIT0+BIT1;P2OUT&=~BIT0;P2OUT|=BIT1;
    __enable_interrupt();

    ADC10_Enable();

    while(1)
    {
    	NumberToString(display, ADC_Convert(3.56f));
    	LCD1602_Show(0, 0, display);
    	__delay_cycles(50000);
    }

	return 0;
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{

}
