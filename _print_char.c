#include "main.h"

/**
* _print_char - prints a charachter
* @argPtr: argument pointer
* Return: 1 (success)
 */

int _print_char(va_list argPtr)
{
	char c;

	c = va_arg(argptr, int);
	_putchar(c)
	return (1);
}
