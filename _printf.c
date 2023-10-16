#include "main.h"
#include <stdarg.h>

int print_integers(int num);

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
			switch (format[i])
			{
				case 'd':
				case 'i':
					count = print_integers(va_arg(digits, int));
					break;
				case '%':
					putchar('%');
					count = 1;
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count = 2;
					break;
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


int print_integers(int num);
{
	return (0);
}
