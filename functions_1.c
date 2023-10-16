#include "main.h"

/**
 * unsigned_int - Function that prints unsigned numbers
 * @args: list of arguments
 * @buffer: buffer to handle prints
 * @flags: active flags calculation
 * @width: to get width
 * @precision: to get precision
 * @size: size specifiers
 *
 * Return: number of characters printed
 */

int unsigned_int(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgned(0, i, buffer, flags, width, precision, size));
}

/**
 * _octal - Function that prints unsigned numbers in octal notation
 * @args: list of arguments
 * @buffer: buffer to handle prints
 * @flags: active flags calculation
 * @width: to get width
 * @precision: to get precision
 * @size: size specifiers
 *
 * Return: number of characters printed
 */

int _octal(va_list args, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int num_t = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & HASH && num_t != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgned(0, i, buffer, flags, width, precision, size));
}

/**
 * _hexadecimal - Function that prints unsigned numbers
 * in hexadecimal notation
 * @args: list of arguments
 * @buffer: buffer to handle prints
 * @flags: active flags calculation
 * @width: to get width
 * @precision: to get precision
 * @size: size specifiers
 *
 * Return: number of characters printed
 */

int _hexadecimal(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	return (hexa(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * hexa_upper - Function that prints unsigned numbers
 * in upper hexadecimal notation
 * @args: list of arguments
 * @buffer: buffer to handle prints
 * @flags: active flags calculation
 * @width: to get width
 * @precision: to get precision
 * @size: size specifiers
 *
 * Return: number of characters printed
 */

int hexa_upper(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	return (hexa(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * hexa - Function that prints unsigned numbers in
 * upper  or lower hexadecimal notation
 * @args: list of arguments
 * @map_to: array of values to map numbers to
 * @buffer: buffer to handle prints
 * @flags: active flags calculation
 * @flag_ch: calculates active flags
 * @width: to get width
 * @precision: to get precision
 * @size: size specifiers
 *
 * Return: number of characters printed
 */

int hexa(va_list args, char map_to[], char buffer[], int flags,
	char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int num_t = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & HASH && num_t != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsgned(0, i, buffer, flags, width, precision, size));
}
