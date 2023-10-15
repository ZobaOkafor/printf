#include "main.h"
#include <stdarg.h>
#include <stdio.h>


/**
 * print_integers - Function that prints negative or positive integers
 * @num: numbers
 *
 * Return: count
 */

int print_integers(int num)
{
	int count = 0;
	char buffer[20];
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


/**
 * _printf - Variadic function to handle printing of %d & %i
 * in our custom _printf function
 * @format: pointer to the first parameter
 *
 * Return: total count
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int total_count = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
				break;

			if (format[i] == 'd' || format[i] == 'i')
			{
				total_count += print_integers(va_arg(args, int));
			}

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

	va_end(args);

	return (total_count);
}
