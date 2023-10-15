#include "main.h"
/**
 * _printf - prints to the stdout
 * @param *format - the format string to be printed
 * ... - variadic function
 * Return: on error, -1, and charac_print, on success
 */
int _printf(const char *format, ...)
{
	int charac_print = 0;
	va_list list_args;

	if (format == NULL)
		return (-1);

	va_start(list_args, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
			charac_print++;
		else
		{
			format++;

			if (format == '\0')
				break;

			if (*format == '%')
				write(1, format, 1);
				charac_print++;
			else if (*format == 'c')
				char c = va_arg(list_args, int);

				write(1, &c, 1);
				charac_print++;
			else if (*format == 's')
				char *str = va_arg(list_args, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				charac_print += str_len;
		}
		format++;
	}
	va_end(list_args);
	return (charac_print);
}
