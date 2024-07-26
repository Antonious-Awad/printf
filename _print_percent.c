#include "main.h"

/**
 * _print_percent - prints the percentage sign .
 * @argPtr: variadic function pointer
 *
 * Return: return value of _putchar (i.e 1 or -1).
 */

int _print_percent(va_list __attribute__((unused)) argPtr)
{
	char c = '%';

	return (_putchar(c));
}
