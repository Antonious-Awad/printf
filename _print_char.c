#include "main.h"

/**
 * _print_char - prints a character
 * @argPtr: argument pointer
 * Return: 1 (success)
 */

int _print_char(va_list argPtr)
{
	char c;

	c = va_arg(argPtr, int);
	_putchar(c);
	return (1);
}
