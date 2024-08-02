#include "main.h"

/**
 * _print_char - prints a character
 * @argPtr: argument pointer
 * @f: flag ptr
 * Return: 1 (success)
 */

int _print_char(va_list argPtr, flag *f)
{
	char c;
	int count = 0, padding;

	c = va_arg(argPtr, int);

	padding = f->width - 1;

	if (!f->isLeft)
		count += _print_padding(padding);

	count += _putchar(c);

	if (f->isLeft)
		count += _print_padding(padding);

	return (count);
}
