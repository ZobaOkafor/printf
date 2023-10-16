#include "main.h"

/**
 * fetch_size - Function that calculates the size to cast the arguments
 * @format: formatted string to print the arguments
 * @i: list of arguments to be printed
 *
 * Return: precision
 */

int fetch_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
