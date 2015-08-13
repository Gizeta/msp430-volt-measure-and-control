#include <msp430.h>
#include "common.h"
#include "util.h"

#define MAX 3.555f

float ADC_Convert(uint value)
{
	return value * MAX / 1024;
}

void NumberToString(uchar *str, float number)
{
	int num = (int)((number + 0.0005) * 1000);
	str[5] = '\0';
	str[4] = num % 10 + '0';
	num /= 10;
	str[3] = num % 10 + '0';
	num /= 10;
	str[2] = num % 10 + '0';
	str[1] = '.';
	str[0] = num / 10 + '0';
}
