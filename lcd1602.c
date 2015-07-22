#include <msp430.h>
#include "common.h"
#include "lcd1602.h"

void LCD1602_WriteShortCmd(uchar cmd)
{
	LCD_RS_PORT   &= ~LCD_RS;
	LCD_EN_PORT   |= LCD_EN;
	LCD_DATA_PORT &= 0xF0;
	LCD_DATA_PORT |= cmd & 0xF;
	__delay_cycles(500);
	LCD_EN_PORT &= ~LCD_EN;
}

void LCD1602_WriteCmd(uchar cmd)
{
	LCD_RS_PORT   &= ~LCD_RS;
	LCD_EN_PORT   |= LCD_EN;
	LCD_DATA_PORT &= 0xF0;
	LCD_DATA_PORT |= (cmd & 0xF0) >> 4;
	__delay_cycles(500);
	LCD_EN_PORT &= ~LCD_EN;
	__delay_cycles(500);

	LCD_EN_PORT   |= LCD_EN;
	LCD_DATA_PORT &= 0xF0;
	LCD_DATA_PORT |= cmd & 0xF;
	__delay_cycles(500);
	LCD_EN_PORT &= ~LCD_EN;
}

void LCD1602_WriteData(uchar data)
{
	LCD_RS_PORT   |= LCD_RS;
	LCD_EN_PORT   |= LCD_EN;
	LCD_DATA_PORT &= 0xF0;
	LCD_DATA_PORT |= (data & 0xF0) >> 4;
	__delay_cycles(500);
	LCD_EN_PORT   &= ~LCD_EN;
	__delay_cycles(500);

	LCD_EN_PORT   |= LCD_EN;
	LCD_DATA_PORT &= 0xF0;
	LCD_DATA_PORT |= data & 0xF;
	__delay_cycles(500);
	LCD_EN_PORT   &= ~LCD_EN;
}

void LCD1602_Init(void)
{
	LCD_DATA_DIR |= LCD_DATA;
	LCD_EN_DIR   |= LCD_EN;
	LCD_RS_DIR   |= LCD_RS;

	LCD1602_WriteShortCmd(0x02);
	__delay_cycles(500);
	LCD1602_WriteCmd(0x28);
	__delay_cycles(500);
	LCD1602_WriteCmd(0x0C);
	__delay_cycles(500);
	LCD1602_WriteCmd(0x06);
	__delay_cycles(500);

	LCD1602_Clear();
}

void LCD1602_Show(uchar x, uchar y, uchar *str)
{
	uchar pos = x;
	if (y > 1 || x > 39) return;
	if (y == 0)
		LCD1602_WriteCmd(0x80 + x);
	else
		LCD1602_WriteCmd(0xC0 + x);
	__delay_cycles(500);

	while(*str != '\0' && pos < 40)
	{
		LCD1602_WriteData(*str++);
		pos++;
		__delay_cycles(500);
	}
}

void LCD1602_Clear(void)
{
	LCD1602_WriteCmd(0x01);
	__delay_cycles(5000);
}
