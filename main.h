#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024

int _putchar(char c);
int _printf(const char *format, ...);
int print_integers(va_list digits);

#endif
