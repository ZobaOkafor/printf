#include "main.h"
#include <stdarg.h>


/**
 * _printf - Variadic function to handle printing of %d and %i
 * in our custom _printf function
 * @format: pointer to the first parameter
 *
 * Return: total count
 */

int _printf(const char *format, ...)
{
	int total_count = 0;
	va_list digits;
	va_list copy;

	va_start(digits, format);
	va_copy(copy, digits);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			total_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			switch (*format)
			{
				case 'd':
				case 'i':
					total_count += print_integers(copy);
					break;
				case '%':
					_putchar('%');
					total_count += 1;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					total_count += 2;
					break;
			}
		}
		format++;
	}
		va_end(digits);

		return (total_count);
}
