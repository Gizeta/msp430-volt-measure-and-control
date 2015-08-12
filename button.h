#ifndef BUTTON_H_
#define BUTTON_H_

#define BUTTON_PORT P2OUT
#define BUTTON_DIR  P2DIR
#define BUTTON_REN  P2REN
#define BUTTON_IES  P2IES
#define BUTTON_IE   P2IE
#define BUTTON_1    BIT0
#define BUTTON_2    BIT1

extern float DA_Output;

void Button_Init(void);

#endif
