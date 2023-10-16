#include "main.h"
#include <stdio.h>

/**
 * print_integers - Function that prints negative or positive integers
 * @num: numbers
 *
 * Return: count
 */

int print_integers(int num)
{
	char buffer[20];
	int count = 0;
	int i = 0;

	if (num < 0)
	{
		putchar('-');
		num = -num;
		count++;
	}

	if (num == 0)
	{
		putchar('0');
		count++;
	}

	while (num > 0)
	{
		buffer[i++] = '0' + (num % 10);
		num /= 10;
		count++;
	}

	while (i > 0)
	{
		putchar(buffer[--i]);
	}

	return (count);
}
