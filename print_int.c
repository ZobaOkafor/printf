#include "main.h"
#include <stdio.h>

/**
 * print_integers - Function that prints negative or positive integers
 * @digits: lis of arguments
 *
 * Return: count
 */

int print_integers(va_list digits)
{
	int count = 0;
	int div = 1;
	int num = va_arg(digits, int);

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	if(num == 0)
	{
		_putchar('0');
		count++;
	}

	while (num / div > 9)
	{
		div *= 10;
	}

	while (div > 0)
	{
		_putchar('0' + num / div);
		num %= div;
		div /= 10;
		count++;
	}

	return (count);
}
