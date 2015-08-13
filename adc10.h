#ifndef ADC10_H_
#define ADC10_H_

#define ADC_INCH  INCH_5
#define ADC_CHSEL P1SEL
#define ADC_IN    BIT5 + BIT4

void ADC10_Init(void);
void ADC10_Enable(void);
void ADC10_Disable(void);

#endif
