#include "main.h"

/**
 * _print_percent - prints the percentage sign .
 * @argPtr: variadic function pointer
 * @f: flag ptr
 *
 * Return: return value of _putchar (i.e 1 or -1).
 */

int _print_percent(va_list __attribute__((unused)) argPtr, flag *f)
{
	char c = '%';

	int count = 0, padding;

	padding = f->width - 1;
	if (!f->isLeft)
		count += _print_padding(padding);

	count += _putchar(c);

	if (f->isLeft)
		count += _print_padding(padding);
	return (count);
}
