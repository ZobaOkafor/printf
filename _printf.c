#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: chars_count
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, chars_count = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list members;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(members, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			chars_count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = fetch_flags(format, &i);
			width = fetch_width(format, &i, members);
			precision = fetch_precision(format, &i, members);
			size = fetch_size(format, &i);
			++i;
			printed = handles_print(format, &i, members, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_count += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(members);

	return (chars_count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
