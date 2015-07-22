#ifndef LCD1602_H_
#define LCD1602_H_

#include "common.h"

#define LCD_EN_PORT   P1OUT
#define LCD_EN_DIR    P1DIR
#define LCD_RS_PORT   P1OUT
#define LCD_RS_DIR    P1DIR
#define LCD_DATA_PORT P1OUT
#define LCD_DATA_DIR  P1DIR
#define LCD_RS        BIT6
#define LCD_EN        BIT7
#define LCD_DATA      BIT3 | BIT2 | BIT1 | BIT0

void LCD1602_WriteShortCmd(uchar cmd);
void LCD1602_WriteCmd(uchar cmd);
void LCD1602_WriteData(uchar data);
void LCD1602_Init(void);
void LCD1602_Show(uchar x, uchar y, uchar *str);
void LCD1602_Clear(void);

#endif
