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
 * _printf - Variadic function to handle printing of %d and %i
 * in our custom _printf function
 * @format: pointer to the first parameter
 *
 * Return: total count
 */


int _printf(const char *format, ...)
{
	int i;
	int count = 0;
	int total_count = 0;

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
				count = print_integers(va_arg(digits, int));
			else if (format[i] == '%')
			{
				putchar('%');
				count = 1;
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				count = 2;
			}
		total_count += count;
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
