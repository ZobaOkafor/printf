#include "main.h"

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

	if (num == 0)
	{
		putchar('0');
		count++;
	}

	if (num < 0)
	{
		putchar('-');
		num = -num;
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
		putchar(buffer[--1]);
	}

	return (count);
}


/**
 * _printf - Variadic function to handle printing of %d and %i
 * in our custom _printf function
 * @format: pointer to the first parameter
 *
 * Return: total count
 */


int _printf(const char *format, ...)
{
	int i;
	int total_count;

	va_list digits;

	va_start(digits, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
				break;

			if (format[i] == 'd' || format[i] == 'i')
				total_count += print_integers(va_digits, int);
		
			else
			{
				putchar('%');
				putchar(format[i]);
				total_count += 1;
			}
		}
		
		else
		{
			total_count++;
			putchar(format[i]);
		}
	}

	va_end(digits);

	return (total_count);
}		
