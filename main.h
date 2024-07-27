#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

/**
 * struct format_specifier - defines a format specifier along
 * with its corresponding conversion function
 * @specifier: specifier string
 * @conversion_func: function that converts the specifier
 */

typedef struct format_specifier
{
	char *specifier;
	int (*conversion_func)(va_list);
} fs;

int _putchar(char);
int _print_str(va_list);
int _strlen(char *);
int _print_percent(va_list);
int _printf(const char *format, ...);
int _print_char(va_list argPtr);
int _print_int(va_list argPtr);

#endif
