#ifndef PWM_H_
#define PWM_H_

#define PWM_PORT P2OUT
#define PWM_DIR  P2DIR
#define PWM_SEL  P2SEL
#define PWM_OUT  BIT2

void PWM_Init(void);
void PWM_Enable(void);
void PWM_Disable(void);

#endif
