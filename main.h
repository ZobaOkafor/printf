#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* for flags */
#define MINUS 1
#define PLUS 2
#define HASH 8
#define SPACE 16
#define ZERO 4

/* for sizes */
#define S_SHORT 1
#define S_LONG 2


/**
 * struct fmt - struct op
 * @fmt: the format
 * @fn: the function
 *
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - struct op
 * @fmt: the format
 * @fmt_t: the function
 *
 */
typedef struct fmt fmt_t;


int _putchar(char c);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int handles_print(const char *fmt, int *ind, va_list members, char buffer[], 
int flags, int width, int precision, int size);



/* Prototypes to print numbers */
int print_int(va_list args, char buffer[],
        int flags, int width, int precision, int size);
int print_binary(va_list args, char buffer[],
        int flags, int width, int precision, int size);
int unsigned_int(va_list args, char buffer[], int flags,
                int width, int precision, int size);
int _octal(va_list args, char buffer[], int flags, int width,
                int precision, int size);
int _hexadecimal(va_list args, char buffer[], int flags,
                int width, int precision, int size);
int hexa_upper(va_list args, char buffer[], int flags,
                int width, int precision, int size);
int hexa(va_list args, char map_to[], char buffer[], int flags,
        char flag_ch, int width, int precision, int size);



/* for util */
int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);



/* Prototypes for width handler */
int handles_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c);
int write_unsgned(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size);
int write_pointers(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);



/* Prototypes to print characters and strings */
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size);
int print_reverse(va_list args, char buffer[],
        int flags, int width, int precision, int size);
int print_rot13string(va_list args, char buffer[],
        int flags, int width, int precision, int size);



/* Prototype to print memory address */
int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size);



/* Prototype to print non printable characters */
int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size);



/* Prototypes to handle other specifiers */
int fetch_flags(const char *format, int *i);
int fetch_precision(const char *format, int *i, va_list members);
int fetch_size(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list members);

#endif
